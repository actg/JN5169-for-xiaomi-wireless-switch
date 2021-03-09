#ifndef __PRIVATE_CUSTOM_H
#define __PRIVATE_CUSTOM_H

#include <jendefs.h>
#include "zcl.h"
#include "zcl_options.h"

/* Command codes */
typedef enum
{
    E_CLD_PRIVATE_CMD_00    = 0x00,
} teCLD_Private_Command;

typedef enum
{
    E_CLD_PRIVATE_ATTR_ID_REPORT_KEY                = 0x0000,
} teCLD_Pivate_ClusterID;

/* Private Cluster */
typedef struct
{
    uint8                       u8CustomKeyReport;
} tsCLD_Private;

/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/

/* Cluster ID's */
#define PRIVATE_CLUSTER_ID_CUSTOM                        0xFE05

/****************************************************************************/
/***        Exported Functions                                            ***/
/****************************************************************************/
PUBLIC  teZCL_Status eCLD_PrivateCreateCustom(
    tsZCL_ClusterInstance                   *psClusterInstance,
    bool_t                                  bIsServer,
    tsZCL_ClusterDefinition                 *psClusterDefinition,
    void                                    *pvEndPointSharedStructPtr,
    uint8                                   *pu8AttributeControlBits);

/****************************************************************************/
/***        External Variables                                            ***/
/****************************************************************************/
extern tsZCL_ClusterDefinition sCLD_PrivateCustom;
extern const tsZCL_AttributeDefinition asCLD_PrivateClusterAttributeDefinitions[];
extern uint8 au8PrivateClusterAttributeControlBits[];

#endif /* __PRIVATE_CUSTOM_H */
