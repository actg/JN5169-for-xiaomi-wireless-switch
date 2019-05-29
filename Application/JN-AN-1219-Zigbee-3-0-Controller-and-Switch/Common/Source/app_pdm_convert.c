/****************************************************************************
 *
 * MODULE:             app_restorepoint
 *
 * COMPONENT:          $RCSfile: app_restorepoint.c,v $
 *
 * VERSION:            $Name:  $
 *
 * REVISION:           $Revision:  $
 *
 * DATED:              $Date:  $
 *
 * STATUS:             $State:  $
 *
 * AUTHOR:             FB
 *
 * DESCRIPTION:        API to handle the restoring of stack Data
 *
 * CHANGE HISTORY:
 *
 ****************************************************************************
 *
 *  (c) Copyright 2017 NXP Semiconductors BV
 *
 ****************************************************************************/
/****************************************************************************/
/***        Include Files                                                 ***/
/****************************************************************************/
#include "app_pdm_convert.h"
#include "dbg.h"
#include "zps_apl_af.h"
#include "zps_apl_zdo.h"
#include "pdm.h"
#include "pdum_gen.h"
#include "string.h"
/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/

#define   PDM_ID_ZPSAPL_AIB            0xf000
#define   PDM_ID_ZPSAPL_AIB_BTBL       0xf001
#define   PDM_ID_ZPSNWK_NIB            0xf100
#define   PDM_ID_ZPSNWK_NT             0xf101
#define   PDM_ID_ZPSNWK_ADMAP64        0xf103	/* may change */
/****************************************************************************/
/***        Type Definitions                                              ***/
/****************************************************************************/
typedef struct
{
    ZPS_tuAddress  uDstAddress;
    uint16  u16ClusterId;
    uint8   u8DstAddrMode;
    uint8   u8SourceEndpoint;
    uint8   u8DestinationEndPoint;
}ZPS_tsAplApsmeBindingTableEntryLegacy;

typedef struct
{
    /* persisted to flash */
    uint64  u64ApsTrustCenterAddress;           /* [I SP001379_sr 17, 344] */
    uint64  u64ApsUseExtendedPanid;
    uint32  u32ApsChannelMask;
    bool_t  bApsDesignatedCoordinator;
    bool_t bApsUseInsecureJoin;
} tsAibPersistLegacy;

typedef struct
{
    zps_tsNwkSlistNode sNode;  /**< Single linked list node */
    uint16 u16Lookup;         /**< Extended address */
    uint16 u16NwkAddr;         /**< Network address */
    uint8  u8TxFailed;         /**< Transmit failed count */
    uint8  u8LinkQuality;      /**< Link Quality indication */
    /*
     * Bitfields are used for syntactic neatness and space saving. May need to assess whether
     * these are suitable for embedded environment
     */
    union
    {
        struct
        {
            unsigned u1Used:1;           /* Overlays: Alternate PAN coordinator */
            unsigned u1DeviceType:1;
            unsigned u1PowerSource:1;
            unsigned u1RxOnWhenIdle:1;
            unsigned u2Relationship:2;   /* Overlays: Reserved */
            unsigned u1SecurityMode:1;
            unsigned u1Authenticated:1;  /* Overlays: Allocate address */
            unsigned u1LinkStatusDone:1; /**< Link status has been processed for this device */
            unsigned u3OutgoingCost:3;     /**< Outgoing cost for sym link = true */
            unsigned u3Age:3;              /**< Router age (in link status periods) */
            unsigned u1ExpectAnnc:1;       /*** Set for newly joined children, cleared on hearing their annce **/
        } bfBitfields;
        uint8 au8Field[2];
    }  uAncAttrs;
} ZPS_tsNwkActvNtEntryLegacy;

typedef struct
{
    uint8  u8UpdateId;                                      /**< nwkUpdateId */
    uint8  u8ActiveKeySeqNumber;                            /**< nwkActiveKeySeqNumber */                    /* [I SP001379_sr 67] */
    uint8  u8VsDepth;                                       /**< Vendor specific - Depth this node is at */
    uint8  u8CapabilityInformation;                         /**< nwkCapabilityInformation */
    uint8  u8VsChannel;                                     /**< Vendor specific - Channel: In Phy also */
    uint16 u16VsPanId;                                      /**< Vendor specific - nwkPANId: In MAC PIB */
    uint16 u16NwkAddr;                                      /**< nwkNetworkAddress: In MAC PIB */
    uint16 u16VsParentAddr;                                 /**< Vendor specific - Parent network address: also in PIB */
    uint64 u64ExtPanId;                                     /**< nwkExtendedPANID */
} ZPS_tsNWkNibPersistLegacy;


typedef union
{
	uint8 au8Buffer[700];
	ZPS_tsAplApsmeBindingTableEntryLegacy   asBindings_R21[16];
	ZPS_tsNwkActvNtEntryLegacy            	asNt_R21[26];
	tsAibPersistLegacy					  	sAibTemp_R21;
	ZPS_tsNWkNibPersistLegacy             	sNibTemp_R21;} uTempData;

/****************************************************************************/
/***        Exported Functions                                            ***/
/****************************************************************************/


/****************************************************************************/
/***        Exported Variables                                            ***/
/****************************************************************************/

 
/****************************************************************************/
/***        Local  functions                                            ***/
/****************************************************************************/
PRIVATE void vR21_ConvertToR22_NT(ZPS_tsNwkActvNtEntry* psNT, uint16 u16Size);
PRIVATE void vR21_ConvertToR22_BindingTable(ZPS_tsAplApsmeBindingTableType* psBindingTable, uint64* psMacTable, uint16 u16Size);
PRIVATE void vR21_ConvertToR22_Aib(ZPS_tsAplAib* psAibPersist);
PRIVATE void vR21_ConvertToR22_Nib( void);PRIVATE uint16 u16GetLookUpValue(uint64* psTable, uint64 u64Addr, uint16 u16Size);
/****************************************************************************
 *
 * NAME: vConvertPdmRecords
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PUBLIC void APP_vConvertR21_PdmToR22_Records(void)
{
	ZPS_tsAplAib *psAib;
	ZPS_tsNwkNibTblSize*    psNwkTblSize;
	ZPS_tsNwkNibTbl* psNwkTables;

	psNwkTblSize = (ZPS_tsNwkNibTblSize*) *(((uint32*)zps_g_pvApl)+1);
	psNwkTables = (ZPS_tsNwkNibTbl*) *(((uint32*)zps_g_pvApl)+2);
	psAib = (ZPS_tsAplAib*) *(((uint32*)zps_g_pvApl)+4);

	/* Important: do the binding table first
	 * this record will shrink and so make room
	 * in the pdm for the NT which will grow */
	vR21_ConvertToR22_BindingTable( psAib->psAplApsmeAibBindingTable,
						  psNwkTables->pu64AddrExtAddrMap,
						  psNwkTblSize->u16MacAddTableSize);
	vR21_ConvertToR22_NT(psNwkTables->psNtActv, (uint16)psNwkTblSize->u8ChildTable);
	vR21_ConvertToR22_Aib( psAib);
	vR21_ConvertToR22_Nib();
}


/****************************************************************************
 *
 * NAME: vConvertNT
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PRIVATE void vR21_ConvertToR22_NT(ZPS_tsNwkActvNtEntry* psNT, uint16 u16Size)
{
	uTempData uData;
	uint16 u16DataBytesRead;
	int i;
	
	memset(&uData, 0, sizeof(uTempData));

	(void) PDM_eReadDataFromRecord( PDM_ID_ZPSNWK_NT,
			                           &uData,
			                           u16Size * sizeof(ZPS_tsNwkActvNtEntryLegacy),
			                           &u16DataBytesRead);

	/* delete old  NT  Record */
	PDM_vDeleteDataRecord( PDM_ID_ZPSNWK_NT);

	for (i=0; i<u16Size; i++)
	{
		psNT[i].u16Lookup          = uData.asNt_R21[i].u16Lookup;
		psNT[i].u16NwkAddr         = uData.asNt_R21[i].u16NwkAddr;
		/* set the age from the legacy bf value */
		psNT[i].u8Age              = (uint8)uData.asNt_R21[i].uAncAttrs.bfBitfields.u3Age;
		psNT[i].u8LinkQuality      = uData.asNt_R21[i].u8LinkQuality;
		/* must be 2G4, there is no r21 sub gig */
		psNT[i].u8MacID            = E_MAC_FREQ_2400;
		psNT[i].u8TxFailed         = uData.asNt_R21[i].u8TxFailed;
		/* new param, any E21/22 zed will establish on next join */
		psNT[i].u8ZedTimeoutindex  = ZED_TIMEOUT_UNDEFINED;
		/* new param, set to default (inly used for sub gig)  */
		psNT[i].i8TXPower          = MAC_TX_POWER_DEFAULT;

		psNT[i].uAncAttrs.au8Field[0] = uData.asNt_R21[i].uAncAttrs.au8Field[0];
		psNT[i].uAncAttrs.au8Field[1]  = uData.asNt_R21[i].uAncAttrs.au8Field[1];
		/* flatten the previous u3Age bf */
		psNT[i].uAncAttrs.bfBitfields.u3Reserve = 0;

	}

    /* save new record */
    (void) PDM_eSaveRecordData( PDM_ID_ZPSNWK_NT,
    		                       psNT,
    		                       u16Size * sizeof(ZPS_tsNwkActvNtEntry) );

}
/****************************************************************************
 *
 * NAME: vConvertBindingTable
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PRIVATE void vR21_ConvertToR22_BindingTable(ZPS_tsAplApsmeBindingTableType* psBindingTable,
								  uint64* psMacTable,
								  uint16 u16Size)
{
	uTempData uData;
	uint16 u16DataBytesRead;
	int i;

	/* test pointers first, binding table may not exist */
	if (psBindingTable != NULL)
	{
		if (psBindingTable->psAplApsmeBindingTable != NULL)
		{

			memset(&uData, 0, sizeof(uTempData));

			(void) PDM_eReadDataFromRecord( PDM_ID_ZPSAPL_AIB_BTBL,
											   &uData,
											   psBindingTable->psAplApsmeBindingTable->u32SizeOfBindingTable * sizeof(ZPS_tsAplApsmeBindingTableEntryLegacy),
											   &u16DataBytesRead);


			/* also need mac table to update the bindings */
			(void) PDM_eReadDataFromRecord( PDM_ID_ZPSNWK_ADMAP64,
											   psMacTable,
											   u16Size * sizeof(uint64),
											   &u16DataBytesRead);


			for (i=0; i<psBindingTable->psAplApsmeBindingTable->u32SizeOfBindingTable; i++)
			{
				psBindingTable->psAplApsmeBindingTable->pvAplApsmeBindingTableEntryForSpSrcAddr[i].u16ClusterId =
													uData.asBindings_R21[i].u16ClusterId;
				psBindingTable->psAplApsmeBindingTable->pvAplApsmeBindingTableEntryForSpSrcAddr[i].u8DestinationEndPoint =
											uData.asBindings_R21[i].u8DestinationEndPoint;
				psBindingTable->psAplApsmeBindingTable->pvAplApsmeBindingTableEntryForSpSrcAddr[i].u8DstAddrMode =
											uData.asBindings_R21[i].u8DstAddrMode;
				psBindingTable->psAplApsmeBindingTable->pvAplApsmeBindingTableEntryForSpSrcAddr[i].u8SourceEndpoint =
													uData.asBindings_R21[i].u8SourceEndpoint;

				if (uData.asBindings_R21[i].u8DstAddrMode == ZPS_E_ADDR_MODE_IEEE)
				{
					/* ieee addressing, need to convert addr to look up, and add to table if required */
					psBindingTable->psAplApsmeBindingTable->pvAplApsmeBindingTableEntryForSpSrcAddr[i].u16AddrOrLkUp =
												u16GetLookUpValue(psMacTable, uData.asBindings_R21[i].uDstAddress.u64Addr, u16Size);
				}
				else
				{
					/* group addressing, address in the look up, so straight coy */
					psBindingTable->psAplApsmeBindingTable->pvAplApsmeBindingTableEntryForSpSrcAddr[i].u16AddrOrLkUp =
												uData.asBindings_R21[i].uDstAddress.u16Addr;
				}
			}

			/* delete old binding record  Record */
			PDM_vDeleteDataRecord( PDM_ID_ZPSAPL_AIB_BTBL);

			/* save new record */
			(void) PDM_eSaveRecordData(  PDM_ID_ZPSAPL_AIB_BTBL,
											psBindingTable->psAplApsmeBindingTable->pvAplApsmeBindingTableEntryForSpSrcAddr,
												psBindingTable->psAplApsmeBindingTable->u32SizeOfBindingTable * sizeof(ZPS_tsAplApsmeBindingTableStoreEntry));

			/* save mac table in anything added */
			(void) PDM_eSaveRecordData(  PDM_ID_ZPSNWK_ADMAP64,
											psMacTable,
											u16Size * sizeof(uint64));

		}
	}

}

/****************************************************************************
 *
 * NAME: u16GetLookUpValue
 *
 * RETURNS: uint16
 * void
 *
 ****************************************************************************/
PRIVATE uint16 u16GetLookUpValue(uint64* psTable, uint64 u64Addr, uint16 u16Size)
{
	int i;
	uint16 u16Free = 0;


	if ( (u64Addr != 0) &&
			(u64Addr != 0xffffffffffffffffUL))
	{
		for (i=0; i<u16Size; i++)
		{
			if (psTable[i] == u64Addr)
			{
				return (uint16)i;
			}
			if ( (i>0) && (u16Free == 0) )
			{
				u16Free = i;
			}
		}
		if (u16Free != 0)
		{
			psTable[u16Free] = u64Addr;
			return u16Free;
		}
	}
	return 0xffff;
}
/****************************************************************************
 *
 * NAME: vConvertAib
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PRIVATE void vR21_ConvertToR22_Aib(ZPS_tsAplAib* psAibPersist)
{
	uTempData uData;
	uint16 u16DataBytesRead;

	memset(&uData, 0, sizeof(uTempData));


	(void) PDM_eReadDataFromRecord(PDM_ID_ZPSAPL_AIB,
								&uData,
								sizeof(tsAibPersistLegacy),
								&u16DataBytesRead);


	psAibPersist->u64ApsTrustCenterAddress   = uData.sAibTemp_R21.u64ApsTrustCenterAddress;
	psAibPersist->u64ApsUseExtendedPanid     = uData.sAibTemp_R21.u64ApsUseExtendedPanid;
	psAibPersist->bApsDesignatedCoordinator  = uData.sAibTemp_R21.bApsDesignatedCoordinator;
	psAibPersist->bApsUseInsecureJoin        = uData.sAibTemp_R21.bApsUseInsecureJoin;
	psAibPersist->bDecryptInstallCode        = FALSE;
	psAibPersist->u8KeyType                  = 0;

	/* delete old record */
	PDM_vDeleteDataRecord( PDM_ID_ZPSAPL_AIB);

    /* save new aib record */
	(void) PDM_eSaveRecordData(  PDM_ID_ZPSAPL_AIB,
									psAibPersist,
									((uint32)&psAibPersist->u8ApsNonMemberRadius) - ((uint32)psAibPersist));
}

/****************************************************************************
 *
 * NAME: vConvertNib
 *
 * RETURNS:
 * void
 *
 ****************************************************************************/
PRIVATE void vR21_ConvertToR22_Nib(void)
{
	uTempData uData;
	uint16 u16DataBytesRead;
	ZPS_tsNWkNibPersist sPersistNew;


	memset(&uData, 0, sizeof(uTempData));
	memset( &sPersistNew, 0, sizeof(ZPS_tsNWkNibPersist));


	(void)PDM_eReadDataFromRecord( PDM_ID_ZPSNWK_NIB,
								       &uData,
								       sizeof(ZPS_tsNWkNibPersistLegacy),
								       &u16DataBytesRead);

	sPersistNew.u16NwkAddr               = uData.sNibTemp_R21.u16NwkAddr;
	sPersistNew.u16VsPanId               = uData.sNibTemp_R21.u16VsPanId;
	sPersistNew.u16VsParentAddr          = uData.sNibTemp_R21.u16VsParentAddr;
	sPersistNew.u64ExtPanId              = uData.sNibTemp_R21.u64ExtPanId;
	sPersistNew.u8ActiveKeySeqNumber     = uData.sNibTemp_R21.u8ActiveKeySeqNumber;
	sPersistNew.u8CapabilityInformation  = uData.sNibTemp_R21.u8CapabilityInformation;
#if (defined ZB_COORD_DEVICE) || (defined ZB_ROUTER_DEVICE)
	/* ZC or ZR, set our capability */
	sPersistNew.u8ParentTimeoutMethod    = PARENT_KEEP_ALIVE_CAPABILITY;
#else
	/* zed, set to undefined, will be set once join a r22 parent */
	sPersistNew.u8ParentTimeoutMethod    = CHILD_KEEP_ALIVE_UNDEFINED;
#endif
	sPersistNew.u8UpdateId               = uData.sNibTemp_R21.u8UpdateId;
	/* set zero, not sub gig so bo aux channel */
	sPersistNew.u8VsAuxChannel           = 0;
	sPersistNew.u8VsChannel              = uData.sNibTemp_R21.u8VsChannel;
	sPersistNew.u8VsDepth                = uData.sNibTemp_R21.u8VsDepth;
	/* default value */
	sPersistNew.u8MacEnhanced           = 0;

	/* de;ete; old Nib  Record */
	PDM_vDeleteDataRecord( PDM_ID_ZPSNWK_NIB);

	/* save new nib record */
	(void)PDM_eSaveRecordData(  PDM_ID_ZPSNWK_NIB,
								    &sPersistNew,
									sizeof(ZPS_tsNWkNibPersist));
}
/****************************************************************************/
/***        END OF FILE                                                   ***/
/****************************************************************************/

