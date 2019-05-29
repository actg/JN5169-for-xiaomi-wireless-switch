/**
 * (C) Jennic Ltd
 *
 * $Id$
 */
package com.jennic.ZPSConfiguration.impl;


import java.math.BigInteger;

import org.eclipse.emf.common.util.URI;
import org.eclipse.emf.ecore.EAttribute;
import org.eclipse.emf.ecore.EClass;
import org.eclipse.emf.ecore.EDataType;
import org.eclipse.emf.ecore.EEnum;
import org.eclipse.emf.ecore.EPackage;
import org.eclipse.emf.ecore.EReference;

import org.eclipse.emf.ecore.impl.EPackageImpl;

import com.jennic.ZPSConfiguration.ActiveEpServer;
import com.jennic.ZPSConfiguration.AlwaysOnNode;
import com.jennic.ZPSConfiguration.BackupBindingCache;
import com.jennic.ZPSConfiguration.BackupDiscoveryCache;
import com.jennic.ZPSConfiguration.BackupGroupCache;
import com.jennic.ZPSConfiguration.BindRequestServer;
import com.jennic.ZPSConfiguration.BindUnbindServer;
import com.jennic.ZPSConfiguration.BindingCache;
import com.jennic.ZPSConfiguration.BindingTable;
import com.jennic.ZPSConfiguration.ChannelMask;
import com.jennic.ZPSConfiguration.ChannelPageList;
import com.jennic.ZPSConfiguration.ChildNodes;
import com.jennic.ZPSConfiguration.Cluster;
import com.jennic.ZPSConfiguration.ComplexDescriptor;
import com.jennic.ZPSConfiguration.Coordinator;
import com.jennic.ZPSConfiguration.DefaultNwkKey;
import com.jennic.ZPSConfiguration.DefaultServer;
import com.jennic.ZPSConfiguration.DeviceAnnceServer;
import com.jennic.ZPSConfiguration.DiscoveryCache;
import com.jennic.ZPSConfiguration.DiscoveryTable;
import com.jennic.ZPSConfiguration.EndDevice;
import com.jennic.ZPSConfiguration.EndDeviceBindServer;
import com.jennic.ZPSConfiguration.EndPoint;
import com.jennic.ZPSConfiguration.ExtendedActiveEpServer;
import com.jennic.ZPSConfiguration.ExtendedSimpleDescServer;
import com.jennic.ZPSConfiguration.FrequencyBands;
import com.jennic.ZPSConfiguration.GreenPowerSecurityTable;
import com.jennic.ZPSConfiguration.GreenPowerTxQueue;
import com.jennic.ZPSConfiguration.GroupTable;
import com.jennic.ZPSConfiguration.IeeeAddrServer;
import com.jennic.ZPSConfiguration.InputCluster;
import com.jennic.ZPSConfiguration.KeyDescriptorTable;
import com.jennic.ZPSConfiguration.MacInterface;
import com.jennic.ZPSConfiguration.MacInterfaceList;
import com.jennic.ZPSConfiguration.MatchDescServer;
import com.jennic.ZPSConfiguration.MgmtBindServer;
import com.jennic.ZPSConfiguration.MgmtLeaveServer;
import com.jennic.ZPSConfiguration.MgmtLqiServer;
import com.jennic.ZPSConfiguration.MgmtMibIeeeServer;
import com.jennic.ZPSConfiguration.MgmtNWKEnhanceUpdateServer;
import com.jennic.ZPSConfiguration.MgmtNWKUpdateServer;
import com.jennic.ZPSConfiguration.MgmtRtgServer;
import com.jennic.ZPSConfiguration.NamedObject;
import com.jennic.ZPSConfiguration.NetworkSelectionTypes;
import com.jennic.ZPSConfiguration.Node;
import com.jennic.ZPSConfiguration.NodeDescServer;
import com.jennic.ZPSConfiguration.NodeDescriptor;
import com.jennic.ZPSConfiguration.NodeLogicalType;
import com.jennic.ZPSConfiguration.NodePowerDescriptor;
import com.jennic.ZPSConfiguration.NotImplemented;
import com.jennic.ZPSConfiguration.NwkAddrServer;
import com.jennic.ZPSConfiguration.NwkKey;
import com.jennic.ZPSConfiguration.OutputCluster;
import com.jennic.ZPSConfiguration.PDUManager;
import com.jennic.ZPSConfiguration.ParentAnnceServer;
import com.jennic.ZPSConfiguration.PermitJoiningServer;
import com.jennic.ZPSConfiguration.PowerDescServer;
import com.jennic.ZPSConfiguration.PowerModes;
import com.jennic.ZPSConfiguration.PowerSources;
import com.jennic.ZPSConfiguration.PreConfiguredNwkKey;
import com.jennic.ZPSConfiguration.PreconfiguredKey;
import com.jennic.ZPSConfiguration.PreconfiguredTCLinkKey;
import com.jennic.ZPSConfiguration.PrimaryBindingCache;
import com.jennic.ZPSConfiguration.PrimaryDiscoveryCache;
import com.jennic.ZPSConfiguration.PrimaryGroupCache;
import com.jennic.ZPSConfiguration.Profile;
import com.jennic.ZPSConfiguration.RadioType;
import com.jennic.ZPSConfiguration.Router;
import com.jennic.ZPSConfiguration.SimpleDescServer;
import com.jennic.ZPSConfiguration.SystemServerDiscoveryServer;
import com.jennic.ZPSConfiguration.TCKey;
import com.jennic.ZPSConfiguration.TrustCenter;
import com.jennic.ZPSConfiguration.UserDescriptor;
import com.jennic.ZPSConfiguration.ZDOClientServer;
import com.jennic.ZPSConfiguration.ZDOCommonServers;
import com.jennic.ZPSConfiguration.ZDOCoordRouterOnlyServers;
import com.jennic.ZPSConfiguration.ZDOServersCoordinator;
import com.jennic.ZPSConfiguration.ZDOServersEndDevice;
import com.jennic.ZPSConfiguration.ZDOServersRouter;
import com.jennic.ZPSConfiguration.ZPSConfigurationFactory;
import com.jennic.ZPSConfiguration.ZPSConfigurationPackage;
import com.jennic.ZPSConfiguration.ZdoClient;
import com.jennic.ZPSConfiguration.ZigbeeWirelessNetwork;

/**
 * <!-- begin-user-doc -->
 * An implementation of the model <b>Package</b>.
 * <!-- end-user-doc -->
 * @generated
 */
public class ZPSConfigurationPackageImpl extends EPackageImpl implements ZPSConfigurationPackage {
	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public static final String copyright = "(C) NXP B.V";

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	private EClass profileEClass = null;

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	private EClass clusterEClass = null;

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	private EClass nodeEClass = null;

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	private EClass coordinatorEClass = null;

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	private EClass routerEClass = null;

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	private EClass endDeviceEClass = null;

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	private EClass endPointEClass = null;

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	private EClass primaryDiscoveryCacheEClass = null;

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	private EClass backupDiscoveryCacheEClass = null;

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	private EClass discoveryTableEClass = null;

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	private EClass bindingTableEClass = null;

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	private EClass groupTableEClass = null;

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	private EClass zigbeeWirelessNetworkEClass = null;

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	private EClass primaryBindingCacheEClass = null;

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	private EClass backupBindingCacheEClass = null;

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	private EClass primaryGroupCacheEClass = null;

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	private EClass backupGroupCacheEClass = null;

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	private EClass inputClusterEClass = null;

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	private EClass outputClusterEClass = null;

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	private EClass alwaysOnNodeEClass = null;

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	private EClass complexDescriptorEClass = null;

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	private EClass userDescriptorEClass = null;

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	private EClass trustCenterEClass = null;

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	private EClass discoveryCacheEClass = null;

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	private EClass bindingCacheEClass = null;

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	private EClass namedObjectEClass = null;

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	private EClass childNodesEClass = null;

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	private EClass apduEClass = null;

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	private EClass pduManagerEClass = null;

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	private EClass channelMaskEClass = null;

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	private EClass zdoClientServerEClass = null;

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	private EClass zdoServersCoordinatorEClass = null;

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	private EClass endDeviceBindServerEClass = null;

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	private EClass zdoServersRouterEClass = null;

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	private EClass zdoServersEndDeviceEClass = null;

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	private EClass defaultServerEClass = null;

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	private EClass deviceAnnceServerEClass = null;

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	private EClass activeEpServerEClass = null;

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	private EClass nwkAddrServerEClass = null;

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	private EClass ieeeAddrServerEClass = null;

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	private EClass matchDescServerEClass = null;

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	private EClass nodeDescServerEClass = null;

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	private EClass permitJoiningServerEClass = null;

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	private EClass powerDescServerEClass = null;

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	private EClass simpleDescServerEClass = null;

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	private EClass systemServerDiscoveryServerEClass = null;

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	private EClass mgmtLqiServerEClass = null;

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	private EClass mgmtRtgServerEClass = null;

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	private EClass mgmtLeaveServerEClass = null;

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	private EClass nodeDescriptorEClass = null;

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	private EClass nodePowerDescriptorEClass = null;

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	private EClass bindUnbindServerEClass = null;

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	private EClass mgmtBindServerEClass = null;

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	private EClass extendedActiveEpServerEClass = null;

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	private EClass extendedSimpleDescServerEClass = null;

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	private EClass zdoClientEClass = null;

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	private EClass mgmtNWKUpdateServerEClass = null;

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	private EClass zdoCommonServersEClass = null;

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	private EClass notImplementedEClass = null;

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	private EClass keyDescriptorTableEClass = null;

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	private EClass preconfiguredKeyEClass = null;

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	private EClass zdoCoordRouterOnlyServersEClass = null;

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	private EClass preConfiguredNwkKeyEClass = null;

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	private EClass defaultNwkKeyEClass = null;

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	private EClass nwkKeyEClass = null;

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	private EClass preconfiguredTCLinkKeyEClass = null;

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	private EClass tcKeyEClass = null;

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	private EClass bindRequestServerEClass = null;

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	private EClass greenPowerSecurityTableEClass = null;

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	private EClass greenPowerTxQueueEClass = null;

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	private EClass mgmtMibIeeeServerEClass = null;

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	private EClass mgmtNWKEnhanceUpdateServerEClass = null;

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	private EClass macInterfaceListEClass = null;

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	private EClass macInterfaceEClass = null;

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	private EClass parentAnnceServerEClass = null;

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	private EEnum nodeLogicalTypeEEnum = null;

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	private EEnum frequencyBandsEEnum = null;

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	private EEnum powerSourcesEEnum = null;

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	private EEnum powerModesEEnum = null;

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	private EEnum networkSelectionTypesEEnum = null;

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	private EEnum radioTypeEEnum = null;

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	private EDataType euShortEDataType = null;

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	private EDataType eExtPANIdEDataType = null;

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	private EDataType ePermitJoiningEDataType = null;

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	private EDataType eSecKeyEDataType = null;

	/**
	 * Creates an instance of the model <b>Package</b>, registered with
	 * {@link org.eclipse.emf.ecore.EPackage.Registry EPackage.Registry} by the package
	 * package URI value.
	 * <p>Note: the correct way to create the package is via the static
	 * factory method {@link #init init()}, which also performs
	 * initialization of the package, or returns the registered package,
	 * if one already exists.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see org.eclipse.emf.ecore.EPackage.Registry
	 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#eNS_URI
	 * @see #init()
	 * @generated
	 */
	private ZPSConfigurationPackageImpl() {
		super(eNS_URI, ZPSConfigurationFactory.eINSTANCE);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	private static boolean isInited = false;

	/**
	 * Creates, registers, and initializes the <b>Package</b> for this model, and for any others upon which it depends.
	 * 
	 * <p>This method is used to initialize {@link ZPSConfigurationPackage#eINSTANCE} when that field is accessed.
	 * Clients should not invoke it directly. Instead, they should simply access that field to obtain the package.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #eNS_URI
	 * @see #createPackageContents()
	 * @see #initializePackageContents()
	 * @generated
	 */
	public static ZPSConfigurationPackage init() {
		if (isInited) return (ZPSConfigurationPackage)EPackage.Registry.INSTANCE.getEPackage(ZPSConfigurationPackage.eNS_URI);

		// Obtain or create and register package
		ZPSConfigurationPackageImpl theZPSConfigurationPackage = (ZPSConfigurationPackageImpl)(EPackage.Registry.INSTANCE.get(eNS_URI) instanceof ZPSConfigurationPackageImpl ? EPackage.Registry.INSTANCE.get(eNS_URI) : new ZPSConfigurationPackageImpl());

		isInited = true;

		// Create package meta-data objects
		theZPSConfigurationPackage.createPackageContents();

		// Initialize created meta-data
		theZPSConfigurationPackage.initializePackageContents();

		// Mark meta-data to indicate it can't be changed
		theZPSConfigurationPackage.freeze();

  
		// Update the registry and return the package
		EPackage.Registry.INSTANCE.put(ZPSConfigurationPackage.eNS_URI, theZPSConfigurationPackage);
		return theZPSConfigurationPackage;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EClass getProfile() {
		return profileEClass;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EAttribute getProfile_Id() {
		return (EAttribute)profileEClass.getEStructuralFeatures().get(0);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EReference getProfile_Clusters() {
		return (EReference)profileEClass.getEStructuralFeatures().get(1);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EClass getCluster() {
		return clusterEClass;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EAttribute getCluster_Id() {
		return (EAttribute)clusterEClass.getEStructuralFeatures().get(0);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EClass getNode() {
		return nodeEClass;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EReference getNode_Endpoints() {
		return (EReference)nodeEClass.getEStructuralFeatures().get(0);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EReference getNode_BindingTable() {
		return (EReference)nodeEClass.getEStructuralFeatures().get(6);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EReference getNode_UserDescriptor() {
		return (EReference)nodeEClass.getEStructuralFeatures().get(5);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EReference getNode_PDUConfiguration() {
		return (EReference)nodeEClass.getEStructuralFeatures().get(1);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EReference getNode_GroupTable() {
		return (EReference)nodeEClass.getEStructuralFeatures().get(7);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EAttribute getNode_MaxNumSimultaneousApsdeAckReq() {
		return (EAttribute)nodeEClass.getEStructuralFeatures().get(20);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EReference getNode_ChannelMask() {
		return (EReference)nodeEClass.getEStructuralFeatures().get(2);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EAttribute getNode_DiscoveryNeighbourTableSize() {
		return (EAttribute)nodeEClass.getEStructuralFeatures().get(11);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EAttribute getNode_ActiveNeighbourTableSize() {
		return (EAttribute)nodeEClass.getEStructuralFeatures().get(12);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EAttribute getNode_RouteDiscoveryTableSize() {
		return (EAttribute)nodeEClass.getEStructuralFeatures().get(13);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EAttribute getNode_RoutingTableSize() {
		return (EAttribute)nodeEClass.getEStructuralFeatures().get(14);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EAttribute getNode_BroadcastTransactionTableSize() {
		return (EAttribute)nodeEClass.getEStructuralFeatures().get(15);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EAttribute getNode_RouteRecordTableSize() {
		return (EAttribute)nodeEClass.getEStructuralFeatures().get(16);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EAttribute getNode_AddressMapTableSize() {
		return (EAttribute)nodeEClass.getEStructuralFeatures().get(17);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EAttribute getNode_SecurityMaterialSets() {
		return (EAttribute)nodeEClass.getEStructuralFeatures().get(18);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EReference getNode_NodeDescriptor() {
		return (EReference)nodeEClass.getEStructuralFeatures().get(3);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EReference getNode_NodePowerDescriptor() {
		return (EReference)nodeEClass.getEStructuralFeatures().get(4);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EAttribute getNode_MaxNumSimultaneousApsdeReq() {
		return (EAttribute)nodeEClass.getEStructuralFeatures().get(19);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EAttribute getNode_MACMutexName() {
		return (EAttribute)nodeEClass.getEStructuralFeatures().get(21);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EAttribute getNode_ZPSMutexName() {
		return (EAttribute)nodeEClass.getEStructuralFeatures().get(22);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EAttribute getNode_FragmentationMaxNumSimulRx() {
		return (EAttribute)nodeEClass.getEStructuralFeatures().get(23);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EAttribute getNode_FragmentationMaxNumSimulTx() {
		return (EAttribute)nodeEClass.getEStructuralFeatures().get(24);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EAttribute getNode_DefaultEventMessageName() {
		return (EAttribute)nodeEClass.getEStructuralFeatures().get(25);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EAttribute getNode_MACDcfmIndMessage() {
		return (EAttribute)nodeEClass.getEStructuralFeatures().get(26);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EAttribute getNode_MACTimeEventMessage() {
		return (EAttribute)nodeEClass.getEStructuralFeatures().get(27);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EAttribute getNode_ApsNonMemberRadius() {
		return (EAttribute)nodeEClass.getEStructuralFeatures().get(28);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EAttribute getNode_ApsDesignatedCoordinator() {
		return (EAttribute)nodeEClass.getEStructuralFeatures().get(29);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EAttribute getNode_ApsUseInsecureJoin() {
		return (EAttribute)nodeEClass.getEStructuralFeatures().get(30);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EAttribute getNode_ApsMaxWindowSize() {
		return (EAttribute)nodeEClass.getEStructuralFeatures().get(31);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EAttribute getNode_ApsInterframeDelay() {
		return (EAttribute)nodeEClass.getEStructuralFeatures().get(32);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EAttribute getNode_ApsSecurityTimeoutPeriod() {
		return (EAttribute)nodeEClass.getEStructuralFeatures().get(34);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EReference getNode_KeyDescriptorTable() {
		return (EReference)nodeEClass.getEStructuralFeatures().get(8);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EAttribute getNode_ApsUseExtPANId() {
		return (EAttribute)nodeEClass.getEStructuralFeatures().get(35);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EReference getNode_InitialNetworkKey() {
		return (EReference)nodeEClass.getEStructuralFeatures().get(36);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EAttribute getNode_SecurityEnabled() {
		return (EAttribute)nodeEClass.getEStructuralFeatures().get(37);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EAttribute getNode_MACMlmeDcfmIndMessage() {
		return (EAttribute)nodeEClass.getEStructuralFeatures().get(38);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EAttribute getNode_MACMcpsDcfmIndMessage() {
		return (EAttribute)nodeEClass.getEStructuralFeatures().get(39);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EAttribute getNode_APSPersistenceTime() {
		return (EAttribute)nodeEClass.getEStructuralFeatures().get(40);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EAttribute getNode_NumAPSMESimulCommands() {
		return (EAttribute)nodeEClass.getEStructuralFeatures().get(41);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EAttribute getNode_StackProfile() {
		return (EAttribute)nodeEClass.getEStructuralFeatures().get(42);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EAttribute getNode_InterPAN() {
		return (EAttribute)nodeEClass.getEStructuralFeatures().get(43);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EAttribute getNode_GreenPowerSupport() {
		return (EAttribute)nodeEClass.getEStructuralFeatures().get(44);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EAttribute getNode_NwkFcSaveCountBitShift() {
		return (EAttribute)nodeEClass.getEStructuralFeatures().get(45);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EAttribute getNode_ApsFcSaveCountBitShift() {
		return (EAttribute)nodeEClass.getEStructuralFeatures().get(46);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EAttribute getNode_MacTableSize() {
		return (EAttribute)nodeEClass.getEStructuralFeatures().get(47);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EAttribute getNode_DefaultCallbackName() {
		return (EAttribute)nodeEClass.getEStructuralFeatures().get(48);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EReference getNode_MacInterfaceList() {
		return (EReference)nodeEClass.getEStructuralFeatures().get(49);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EReference getNode_GreenPowerTxQueue() {
		return (EReference)nodeEClass.getEStructuralFeatures().get(9);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EReference getNode_GreenPowerSecurityTable() {
		return (EReference)nodeEClass.getEStructuralFeatures().get(10);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EAttribute getNode_APSDuplicateTableSize() {
		return (EAttribute)nodeEClass.getEStructuralFeatures().get(33);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EClass getCoordinator() {
		return coordinatorEClass;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EReference getCoordinator_ZDOServers() {
		return (EReference)coordinatorEClass.getEStructuralFeatures().get(0);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EClass getRouter() {
		return routerEClass;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EReference getRouter_ZDOServers() {
		return (EReference)routerEClass.getEStructuralFeatures().get(0);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EClass getEndDevice() {
		return endDeviceEClass;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EReference getEndDevice_ZDOServers() {
		return (EReference)endDeviceEClass.getEStructuralFeatures().get(0);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EAttribute getEndDevice_NumPollFailuresBeforeRejoin() {
		return (EAttribute)endDeviceEClass.getEStructuralFeatures().get(1);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EAttribute getEndDevice_Sleeping() {
		return (EAttribute)endDeviceEClass.getEStructuralFeatures().get(2);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EAttribute getEndDevice_FragmentedTxPollPeriod() {
		return (EAttribute)endDeviceEClass.getEStructuralFeatures().get(3);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EAttribute getEndDevice_FragmentedRxPollPeriod() {
		return (EAttribute)endDeviceEClass.getEStructuralFeatures().get(4);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EAttribute getEndDevice_APSPollPeriod() {
		return (EAttribute)endDeviceEClass.getEStructuralFeatures().get(5);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EClass getEndPoint() {
		return endPointEClass;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EReference getEndPoint_InputClusters() {
		return (EReference)endPointEClass.getEStructuralFeatures().get(0);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EReference getEndPoint_OutputClusters() {
		return (EReference)endPointEClass.getEStructuralFeatures().get(1);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EAttribute getEndPoint_Id() {
		return (EAttribute)endPointEClass.getEStructuralFeatures().get(2);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EAttribute getEndPoint_Enabled() {
		return (EAttribute)endPointEClass.getEStructuralFeatures().get(3);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EAttribute getEndPoint_ApplicationDeviceId() {
		return (EAttribute)endPointEClass.getEStructuralFeatures().get(4);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EAttribute getEndPoint_ApplicationDeviceVersion() {
		return (EAttribute)endPointEClass.getEStructuralFeatures().get(5);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EReference getEndPoint_Profile() {
		return (EReference)endPointEClass.getEStructuralFeatures().get(6);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EAttribute getEndPoint_Message() {
		return (EAttribute)endPointEClass.getEStructuralFeatures().get(7);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EReference getEndPoint_Node() {
		return (EReference)endPointEClass.getEStructuralFeatures().get(8);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EAttribute getEndPoint_Name() {
		return (EAttribute)endPointEClass.getEStructuralFeatures().get(9);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EClass getPrimaryDiscoveryCache() {
		return primaryDiscoveryCacheEClass;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EAttribute getPrimaryDiscoveryCache_Size() {
		return (EAttribute)primaryDiscoveryCacheEClass.getEStructuralFeatures().get(0);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EClass getBackupDiscoveryCache() {
		return backupDiscoveryCacheEClass;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EAttribute getBackupDiscoveryCache_Size() {
		return (EAttribute)backupDiscoveryCacheEClass.getEStructuralFeatures().get(0);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EClass getDiscoveryTable() {
		return discoveryTableEClass;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EAttribute getDiscoveryTable_Size() {
		return (EAttribute)discoveryTableEClass.getEStructuralFeatures().get(0);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EClass getBindingTable() {
		return bindingTableEClass;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EAttribute getBindingTable_Size() {
		return (EAttribute)bindingTableEClass.getEStructuralFeatures().get(0);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EClass getGroupTable() {
		return groupTableEClass;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EAttribute getGroupTable_Size() {
		return (EAttribute)groupTableEClass.getEStructuralFeatures().get(0);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EClass getZigbeeWirelessNetwork() {
		return zigbeeWirelessNetworkEClass;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EReference getZigbeeWirelessNetwork_Profiles() {
		return (EReference)zigbeeWirelessNetworkEClass.getEStructuralFeatures().get(0);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EReference getZigbeeWirelessNetwork_Coordinator() {
		return (EReference)zigbeeWirelessNetworkEClass.getEStructuralFeatures().get(1);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EReference getZigbeeWirelessNetwork_ChildNodes() {
		return (EReference)zigbeeWirelessNetworkEClass.getEStructuralFeatures().get(2);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EAttribute getZigbeeWirelessNetwork_DefaultExtendedPANId() {
		return (EAttribute)zigbeeWirelessNetworkEClass.getEStructuralFeatures().get(3);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EAttribute getZigbeeWirelessNetwork_MaxNumberNodes() {
		return (EAttribute)zigbeeWirelessNetworkEClass.getEStructuralFeatures().get(4);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EAttribute getZigbeeWirelessNetwork_Version() {
		return (EAttribute)zigbeeWirelessNetworkEClass.getEStructuralFeatures().get(5);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EAttribute getZigbeeWirelessNetwork_DefaultSecurityEnabled() {
		return (EAttribute)zigbeeWirelessNetworkEClass.getEStructuralFeatures().get(6);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EClass getPrimaryBindingCache() {
		return primaryBindingCacheEClass;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EAttribute getPrimaryBindingCache_TableSize() {
		return (EAttribute)primaryBindingCacheEClass.getEStructuralFeatures().get(0);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EAttribute getPrimaryBindingCache_NumTables() {
		return (EAttribute)primaryBindingCacheEClass.getEStructuralFeatures().get(1);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EClass getBackupBindingCache() {
		return backupBindingCacheEClass;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EAttribute getBackupBindingCache_TableSize() {
		return (EAttribute)backupBindingCacheEClass.getEStructuralFeatures().get(0);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EAttribute getBackupBindingCache_NumTables() {
		return (EAttribute)backupBindingCacheEClass.getEStructuralFeatures().get(1);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EClass getPrimaryGroupCache() {
		return primaryGroupCacheEClass;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EAttribute getPrimaryGroupCache_Size() {
		return (EAttribute)primaryGroupCacheEClass.getEStructuralFeatures().get(0);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EClass getBackupGroupCache() {
		return backupGroupCacheEClass;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EAttribute getBackupGroupCache_Size() {
		return (EAttribute)backupGroupCacheEClass.getEStructuralFeatures().get(0);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EClass getInputCluster() {
		return inputClusterEClass;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EReference getInputCluster_Cluster() {
		return (EReference)inputClusterEClass.getEStructuralFeatures().get(0);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EReference getInputCluster_RxAPDU() {
		return (EReference)inputClusterEClass.getEStructuralFeatures().get(1);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EReference getInputCluster_EndPoint() {
		return (EReference)inputClusterEClass.getEStructuralFeatures().get(2);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EAttribute getInputCluster_Discoverable() {
		return (EAttribute)inputClusterEClass.getEStructuralFeatures().get(3);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EClass getOutputCluster() {
		return outputClusterEClass;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EReference getOutputCluster_Cluster() {
		return (EReference)outputClusterEClass.getEStructuralFeatures().get(0);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EReference getOutputCluster_EndPoint() {
		return (EReference)outputClusterEClass.getEStructuralFeatures().get(1);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EReference getOutputCluster_TxAPDUs() {
		return (EReference)outputClusterEClass.getEStructuralFeatures().get(2);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EAttribute getOutputCluster_Discoverable() {
		return (EAttribute)outputClusterEClass.getEStructuralFeatures().get(3);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EClass getAlwaysOnNode() {
		return alwaysOnNodeEClass;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EReference getAlwaysOnNode_TrustCenter() {
		return (EReference)alwaysOnNodeEClass.getEStructuralFeatures().get(0);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EAttribute getAlwaysOnNode_PermitJoiningTime() {
		return (EAttribute)alwaysOnNodeEClass.getEStructuralFeatures().get(1);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EAttribute getAlwaysOnNode_ChildTableSize() {
		return (EAttribute)alwaysOnNodeEClass.getEStructuralFeatures().get(2);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EClass getComplexDescriptor() {
		return complexDescriptorEClass;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EClass getUserDescriptor() {
		return userDescriptorEClass;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EAttribute getUserDescriptor_UserDescription() {
		return (EAttribute)userDescriptorEClass.getEStructuralFeatures().get(0);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EClass getTrustCenter() {
		return trustCenterEClass;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EAttribute getTrustCenter_DeviceTableSize() {
		return (EAttribute)trustCenterEClass.getEStructuralFeatures().get(0);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EReference getTrustCenter_Keys() {
		return (EReference)trustCenterEClass.getEStructuralFeatures().get(1);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EClass getDiscoveryCache() {
		return discoveryCacheEClass;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EClass getBindingCache() {
		return bindingCacheEClass;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EClass getNamedObject() {
		return namedObjectEClass;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EAttribute getNamedObject_Name() {
		return (EAttribute)namedObjectEClass.getEStructuralFeatures().get(0);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EClass getChildNodes() {
		return childNodesEClass;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EAttribute getChildNodes_ScanDuration() {
		return (EAttribute)childNodesEClass.getEStructuralFeatures().get(0);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EAttribute getChildNodes_NetworkSelection() {
		return (EAttribute)childNodesEClass.getEStructuralFeatures().get(1);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EClass getAPDU() {
		return apduEClass;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EAttribute getAPDU_Id() {
		return (EAttribute)apduEClass.getEStructuralFeatures().get(0);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EAttribute getAPDU_Name() {
		return (EAttribute)apduEClass.getEStructuralFeatures().get(1);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EAttribute getAPDU_Size() {
		return (EAttribute)apduEClass.getEStructuralFeatures().get(2);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EAttribute getAPDU_Instances() {
		return (EAttribute)apduEClass.getEStructuralFeatures().get(3);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EReference getAPDU_PDUConfig() {
		return (EReference)apduEClass.getEStructuralFeatures().get(4);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EClass getPDUManager() {
		return pduManagerEClass;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EReference getPDUManager_APDUs() {
		return (EReference)pduManagerEClass.getEStructuralFeatures().get(0);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EReference getPDUManager_ContainerNode() {
		return (EReference)pduManagerEClass.getEStructuralFeatures().get(1);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EAttribute getPDUManager_NumNPDUs() {
		return (EAttribute)pduManagerEClass.getEStructuralFeatures().get(2);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EAttribute getPDUManager_PDUMMutexName() {
		return (EAttribute)pduManagerEClass.getEStructuralFeatures().get(3);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EClass getChannelMask() {
		return channelMaskEClass;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EAttribute getChannelMask_Channel11() {
		return (EAttribute)channelMaskEClass.getEStructuralFeatures().get(0);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EAttribute getChannelMask_Channel12() {
		return (EAttribute)channelMaskEClass.getEStructuralFeatures().get(1);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EAttribute getChannelMask_Channel13() {
		return (EAttribute)channelMaskEClass.getEStructuralFeatures().get(2);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EAttribute getChannelMask_Channel14() {
		return (EAttribute)channelMaskEClass.getEStructuralFeatures().get(3);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EAttribute getChannelMask_Channel15() {
		return (EAttribute)channelMaskEClass.getEStructuralFeatures().get(4);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EAttribute getChannelMask_Channel16() {
		return (EAttribute)channelMaskEClass.getEStructuralFeatures().get(5);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EAttribute getChannelMask_Channel17() {
		return (EAttribute)channelMaskEClass.getEStructuralFeatures().get(6);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EAttribute getChannelMask_Channel18() {
		return (EAttribute)channelMaskEClass.getEStructuralFeatures().get(7);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EAttribute getChannelMask_Channel19() {
		return (EAttribute)channelMaskEClass.getEStructuralFeatures().get(8);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EAttribute getChannelMask_Channel20() {
		return (EAttribute)channelMaskEClass.getEStructuralFeatures().get(9);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EAttribute getChannelMask_Channel21() {
		return (EAttribute)channelMaskEClass.getEStructuralFeatures().get(10);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EAttribute getChannelMask_Channel22() {
		return (EAttribute)channelMaskEClass.getEStructuralFeatures().get(11);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EAttribute getChannelMask_Channel23() {
		return (EAttribute)channelMaskEClass.getEStructuralFeatures().get(12);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EAttribute getChannelMask_Channel24() {
		return (EAttribute)channelMaskEClass.getEStructuralFeatures().get(13);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EAttribute getChannelMask_Channel25() {
		return (EAttribute)channelMaskEClass.getEStructuralFeatures().get(14);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EAttribute getChannelMask_Channel26() {
		return (EAttribute)channelMaskEClass.getEStructuralFeatures().get(15);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EClass getZDOClientServer() {
		return zdoClientServerEClass;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EReference getZDOClientServer_OutputAPdu() {
		return (EReference)zdoClientServerEClass.getEStructuralFeatures().get(0);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EClass getZDOServersCoordinator() {
		return zdoServersCoordinatorEClass;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EReference getZDOServersCoordinator_EndDeviceBindServer() {
		return (EReference)zdoServersCoordinatorEClass.getEStructuralFeatures().get(0);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EClass getEndDeviceBindServer() {
		return endDeviceBindServerEClass;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EAttribute getEndDeviceBindServer_Timeout() {
		return (EAttribute)endDeviceBindServerEClass.getEStructuralFeatures().get(0);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EAttribute getEndDeviceBindServer_BindingTimeout() {
		return (EAttribute)endDeviceBindServerEClass.getEStructuralFeatures().get(1);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EAttribute getEndDeviceBindServer_BindNumRetries() {
		return (EAttribute)endDeviceBindServerEClass.getEStructuralFeatures().get(2);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EClass getZDOServersRouter() {
		return zdoServersRouterEClass;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EClass getZDOServersEndDevice() {
		return zdoServersEndDeviceEClass;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EClass getDefaultServer() {
		return defaultServerEClass;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EClass getDeviceAnnceServer() {
		return deviceAnnceServerEClass;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EClass getActiveEpServer() {
		return activeEpServerEClass;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EClass getNwkAddrServer() {
		return nwkAddrServerEClass;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EClass getIeeeAddrServer() {
		return ieeeAddrServerEClass;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EClass getMatchDescServer() {
		return matchDescServerEClass;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EClass getNodeDescServer() {
		return nodeDescServerEClass;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EClass getPermitJoiningServer() {
		return permitJoiningServerEClass;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EClass getPowerDescServer() {
		return powerDescServerEClass;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EClass getSimpleDescServer() {
		return simpleDescServerEClass;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EClass getSystemServerDiscoveryServer() {
		return systemServerDiscoveryServerEClass;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EClass getMgmtLqiServer() {
		return mgmtLqiServerEClass;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EClass getMgmtRtgServer() {
		return mgmtRtgServerEClass;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EClass getMgmtLeaveServer() {
		return mgmtLeaveServerEClass;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EClass getNodeDescriptor() {
		return nodeDescriptorEClass;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EAttribute getNodeDescriptor_ManufacturerCode() {
		return (EAttribute)nodeDescriptorEClass.getEStructuralFeatures().get(0);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EAttribute getNodeDescriptor_LogicalType() {
		return (EAttribute)nodeDescriptorEClass.getEStructuralFeatures().get(1);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EAttribute getNodeDescriptor_ComplexDescriptorAvailable() {
		return (EAttribute)nodeDescriptorEClass.getEStructuralFeatures().get(2);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EAttribute getNodeDescriptor_UserDescriptorAvailable() {
		return (EAttribute)nodeDescriptorEClass.getEStructuralFeatures().get(3);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EAttribute getNodeDescriptor_APSFlags() {
		return (EAttribute)nodeDescriptorEClass.getEStructuralFeatures().get(4);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EAttribute getNodeDescriptor_FrequencyBand() {
		return (EAttribute)nodeDescriptorEClass.getEStructuralFeatures().get(5);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EAttribute getNodeDescriptor_AlternatePANCoordinator() {
		return (EAttribute)nodeDescriptorEClass.getEStructuralFeatures().get(6);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EAttribute getNodeDescriptor_DeviceType() {
		return (EAttribute)nodeDescriptorEClass.getEStructuralFeatures().get(7);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EAttribute getNodeDescriptor_PowerSource() {
		return (EAttribute)nodeDescriptorEClass.getEStructuralFeatures().get(8);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EAttribute getNodeDescriptor_RxOnWhenIdle() {
		return (EAttribute)nodeDescriptorEClass.getEStructuralFeatures().get(9);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EAttribute getNodeDescriptor_Security() {
		return (EAttribute)nodeDescriptorEClass.getEStructuralFeatures().get(10);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EAttribute getNodeDescriptor_AllocateAddress() {
		return (EAttribute)nodeDescriptorEClass.getEStructuralFeatures().get(11);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EAttribute getNodeDescriptor_MaximumBufferSize() {
		return (EAttribute)nodeDescriptorEClass.getEStructuralFeatures().get(12);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EAttribute getNodeDescriptor_MaximumIncomingTransferSize() {
		return (EAttribute)nodeDescriptorEClass.getEStructuralFeatures().get(13);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EAttribute getNodeDescriptor_MaximumOutgoingTransferSize() {
		return (EAttribute)nodeDescriptorEClass.getEStructuralFeatures().get(14);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EAttribute getNodeDescriptor_ExtendedActiveEndpointListAvailable() {
		return (EAttribute)nodeDescriptorEClass.getEStructuralFeatures().get(15);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EAttribute getNodeDescriptor_ExtendedSimpleDescriptorListAvailable() {
		return (EAttribute)nodeDescriptorEClass.getEStructuralFeatures().get(16);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EAttribute getNodeDescriptor_PrimaryTrustCenter() {
		return (EAttribute)nodeDescriptorEClass.getEStructuralFeatures().get(17);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EAttribute getNodeDescriptor_BackupTrustCenter() {
		return (EAttribute)nodeDescriptorEClass.getEStructuralFeatures().get(18);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EAttribute getNodeDescriptor_PrimaryBindingTableCache() {
		return (EAttribute)nodeDescriptorEClass.getEStructuralFeatures().get(19);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EAttribute getNodeDescriptor_BackupBindingTableCache() {
		return (EAttribute)nodeDescriptorEClass.getEStructuralFeatures().get(20);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EAttribute getNodeDescriptor_PrimaryDiscoveryCache() {
		return (EAttribute)nodeDescriptorEClass.getEStructuralFeatures().get(21);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EAttribute getNodeDescriptor_BackupDiscoveryCache() {
		return (EAttribute)nodeDescriptorEClass.getEStructuralFeatures().get(22);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EReference getNodeDescriptor_Node() {
		return (EReference)nodeDescriptorEClass.getEStructuralFeatures().get(23);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EAttribute getNodeDescriptor_NetworkManager() {
		return (EAttribute)nodeDescriptorEClass.getEStructuralFeatures().get(24);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EClass getNodePowerDescriptor() {
		return nodePowerDescriptorEClass;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EAttribute getNodePowerDescriptor_ConstantPower() {
		return (EAttribute)nodePowerDescriptorEClass.getEStructuralFeatures().get(0);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EAttribute getNodePowerDescriptor_RechargeableBattery() {
		return (EAttribute)nodePowerDescriptorEClass.getEStructuralFeatures().get(1);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EAttribute getNodePowerDescriptor_DisposableBattery() {
		return (EAttribute)nodePowerDescriptorEClass.getEStructuralFeatures().get(2);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EAttribute getNodePowerDescriptor_DefaultPowerSource() {
		return (EAttribute)nodePowerDescriptorEClass.getEStructuralFeatures().get(3);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EAttribute getNodePowerDescriptor_DefaultPowerMode() {
		return (EAttribute)nodePowerDescriptorEClass.getEStructuralFeatures().get(4);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EClass getBindUnbindServer() {
		return bindUnbindServerEClass;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EClass getMgmtBindServer() {
		return mgmtBindServerEClass;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EClass getExtendedActiveEpServer() {
		return extendedActiveEpServerEClass;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EClass getExtendedSimpleDescServer() {
		return extendedSimpleDescServerEClass;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EClass getZdoClient() {
		return zdoClientEClass;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EClass getMgmtNWKUpdateServer() {
		return mgmtNWKUpdateServerEClass;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EClass getZDOCommonServers() {
		return zdoCommonServersEClass;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EReference getZDOCommonServers_DefaultServer() {
		return (EReference)zdoCommonServersEClass.getEStructuralFeatures().get(0);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EReference getZDOCommonServers_MgmtNWKUpdateServer() {
		return (EReference)zdoCommonServersEClass.getEStructuralFeatures().get(13);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EReference getZDOCommonServers_ZdoClient() {
		return (EReference)zdoCommonServersEClass.getEStructuralFeatures().get(1);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EReference getZDOCommonServers_DeviceAnnceServer() {
		return (EReference)zdoCommonServersEClass.getEStructuralFeatures().get(2);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EReference getZDOCommonServers_ActiveEpServer() {
		return (EReference)zdoCommonServersEClass.getEStructuralFeatures().get(3);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EReference getZDOCommonServers_NwkAddrServer() {
		return (EReference)zdoCommonServersEClass.getEStructuralFeatures().get(4);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EReference getZDOCommonServers_IeeeAddrServer() {
		return (EReference)zdoCommonServersEClass.getEStructuralFeatures().get(5);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EReference getZDOCommonServers_SystemServerDiscoveryServer() {
		return (EReference)zdoCommonServersEClass.getEStructuralFeatures().get(6);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EReference getZDOCommonServers_NodeDescServer() {
		return (EReference)zdoCommonServersEClass.getEStructuralFeatures().get(7);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EReference getZDOCommonServers_PowerDescServer() {
		return (EReference)zdoCommonServersEClass.getEStructuralFeatures().get(8);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EReference getZDOCommonServers_MatchDescServer() {
		return (EReference)zdoCommonServersEClass.getEStructuralFeatures().get(9);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EReference getZDOCommonServers_SimpleDescServer() {
		return (EReference)zdoCommonServersEClass.getEStructuralFeatures().get(10);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EReference getZDOCommonServers_MgmtLqiServer() {
		return (EReference)zdoCommonServersEClass.getEStructuralFeatures().get(11);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EReference getZDOCommonServers_MgmtLeaveServer() {
		return (EReference)zdoCommonServersEClass.getEStructuralFeatures().get(12);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EReference getZDOCommonServers_BindUnbindServer() {
		return (EReference)zdoCommonServersEClass.getEStructuralFeatures().get(14);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EReference getZDOCommonServers_ExtendedActiveEpServer() {
		return (EReference)zdoCommonServersEClass.getEStructuralFeatures().get(15);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EReference getZDOCommonServers_ExtendedSimpleDescServer() {
		return (EReference)zdoCommonServersEClass.getEStructuralFeatures().get(16);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EReference getZDOCommonServers_BindRequestServer() {
		return (EReference)zdoCommonServersEClass.getEStructuralFeatures().get(17);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EReference getZDOCommonServers_MgmtBindServer() {
		return (EReference)zdoCommonServersEClass.getEStructuralFeatures().get(18);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EReference getZDOCommonServers_MgmtNWKEnhanceUpdateServer() {
		return (EReference)zdoCommonServersEClass.getEStructuralFeatures().get(19);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EClass getNotImplemented() {
		return notImplementedEClass;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EReference getNotImplemented_ComplexDescriptor() {
		return (EReference)notImplementedEClass.getEStructuralFeatures().get(0);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EReference getNotImplemented_DiscoveryTable() {
		return (EReference)notImplementedEClass.getEStructuralFeatures().get(1);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EReference getNotImplemented_DiscoveryCache() {
		return (EReference)notImplementedEClass.getEStructuralFeatures().get(2);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EReference getNotImplemented_BindingCache() {
		return (EReference)notImplementedEClass.getEStructuralFeatures().get(3);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EClass getKeyDescriptorTable() {
		return keyDescriptorTableEClass;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EAttribute getKeyDescriptorTable_Size() {
		return (EAttribute)keyDescriptorTableEClass.getEStructuralFeatures().get(0);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EReference getKeyDescriptorTable_PreconfiguredKey() {
		return (EReference)keyDescriptorTableEClass.getEStructuralFeatures().get(1);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EClass getPreconfiguredKey() {
		return preconfiguredKeyEClass;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EAttribute getPreconfiguredKey_Key() {
		return (EAttribute)preconfiguredKeyEClass.getEStructuralFeatures().get(0);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EAttribute getPreconfiguredKey_IEEEAddress() {
		return (EAttribute)preconfiguredKeyEClass.getEStructuralFeatures().get(1);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EClass getZDOCoordRouterOnlyServers() {
		return zdoCoordRouterOnlyServersEClass;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EReference getZDOCoordRouterOnlyServers_PermitJoiningServer() {
		return (EReference)zdoCoordRouterOnlyServersEClass.getEStructuralFeatures().get(0);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EReference getZDOCoordRouterOnlyServers_MgmtRtgServer() {
		return (EReference)zdoCoordRouterOnlyServersEClass.getEStructuralFeatures().get(1);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EReference getZDOCoordRouterOnlyServers_MgmtMibIeeeServer() {
		return (EReference)zdoCoordRouterOnlyServersEClass.getEStructuralFeatures().get(2);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EReference getZDOCoordRouterOnlyServers_ParentAnnceServer() {
		return (EReference)zdoCoordRouterOnlyServersEClass.getEStructuralFeatures().get(3);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EClass getPreConfiguredNwkKey() {
		return preConfiguredNwkKeyEClass;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EClass getDefaultNwkKey() {
		return defaultNwkKeyEClass;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EAttribute getDefaultNwkKey_Random() {
		return (EAttribute)defaultNwkKeyEClass.getEStructuralFeatures().get(0);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EClass getNwkKey() {
		return nwkKeyEClass;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EAttribute getNwkKey_KeySequenceNumber() {
		return (EAttribute)nwkKeyEClass.getEStructuralFeatures().get(0);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EAttribute getNwkKey_Key() {
		return (EAttribute)nwkKeyEClass.getEStructuralFeatures().get(1);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EAttribute getNwkKey_Id() {
		return (EAttribute)nwkKeyEClass.getEStructuralFeatures().get(2);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EClass getPreconfiguredTCLinkKey() {
		return preconfiguredTCLinkKeyEClass;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EAttribute getPreconfiguredTCLinkKey_Id() {
		return (EAttribute)preconfiguredTCLinkKeyEClass.getEStructuralFeatures().get(0);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EClass getTCKey() {
		return tcKeyEClass;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EClass getBindRequestServer() {
		return bindRequestServerEClass;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EAttribute getBindRequestServer_SimultaneousRequests() {
		return (EAttribute)bindRequestServerEClass.getEStructuralFeatures().get(0);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EAttribute getBindRequestServer_TimeInterval() {
		return (EAttribute)bindRequestServerEClass.getEStructuralFeatures().get(1);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EClass getGreenPowerSecurityTable() {
		return greenPowerSecurityTableEClass;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EAttribute getGreenPowerSecurityTable_Size() {
		return (EAttribute)greenPowerSecurityTableEClass.getEStructuralFeatures().get(0);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EClass getGreenPowerTxQueue() {
		return greenPowerTxQueueEClass;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EAttribute getGreenPowerTxQueue_Size() {
		return (EAttribute)greenPowerTxQueueEClass.getEStructuralFeatures().get(0);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EClass getMgmtMibIeeeServer() {
		return mgmtMibIeeeServerEClass;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EClass getMgmtNWKEnhanceUpdateServer() {
		return mgmtNWKEnhanceUpdateServerEClass;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EClass getMacInterfaceList() {
		return macInterfaceListEClass;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EReference getMacInterfaceList_MacInterface() {
		return (EReference)macInterfaceListEClass.getEStructuralFeatures().get(0);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EClass getMacInterface() {
		return macInterfaceEClass;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EAttribute getMacInterface_RouterAllowed() {
		return (EAttribute)macInterfaceEClass.getEStructuralFeatures().get(0);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EAttribute getMacInterface_ChannelListSize() {
		return (EAttribute)macInterfaceEClass.getEStructuralFeatures().get(1);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EAttribute getMacInterface_Index() {
		return (EAttribute)macInterfaceEClass.getEStructuralFeatures().get(2);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EAttribute getMacInterface_RadioType() {
		return (EAttribute)macInterfaceEClass.getEStructuralFeatures().get(3);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EAttribute getMacInterface_Enabled() {
		return (EAttribute)macInterfaceEClass.getEStructuralFeatures().get(4);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EClass getParentAnnceServer() {
		return parentAnnceServerEClass;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EEnum getNodeLogicalType() {
		return nodeLogicalTypeEEnum;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EEnum getFrequencyBands() {
		return frequencyBandsEEnum;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EEnum getPowerSources() {
		return powerSourcesEEnum;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EEnum getPowerModes() {
		return powerModesEEnum;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EEnum getNetworkSelectionTypes() {
		return networkSelectionTypesEEnum;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EEnum getRadioType() {
		return radioTypeEEnum;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EDataType getEUShort() {
		return euShortEDataType;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EDataType getEExtPANId() {
		return eExtPANIdEDataType;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EDataType getEPermitJoining() {
		return ePermitJoiningEDataType;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EDataType getESecKey() {
		return eSecKeyEDataType;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public ZPSConfigurationFactory getZPSConfigurationFactory() {
		return (ZPSConfigurationFactory)getEFactoryInstance();
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	private boolean isCreated = false;

	/**
	 * Creates the meta-model objects for the package.  This method is
	 * guarded to have no affect on any invocation but its first.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void createPackageContents() {
		if (isCreated) return;
		isCreated = true;

		// Create classes and their features
		profileEClass = createEClass(PROFILE);
		createEAttribute(profileEClass, PROFILE__ID);
		createEReference(profileEClass, PROFILE__CLUSTERS);

		clusterEClass = createEClass(CLUSTER);
		createEAttribute(clusterEClass, CLUSTER__ID);

		nodeEClass = createEClass(NODE);
		createEReference(nodeEClass, NODE__ENDPOINTS);
		createEReference(nodeEClass, NODE__PDU_CONFIGURATION);
		createEReference(nodeEClass, NODE__CHANNEL_MASK);
		createEReference(nodeEClass, NODE__NODE_DESCRIPTOR);
		createEReference(nodeEClass, NODE__NODE_POWER_DESCRIPTOR);
		createEReference(nodeEClass, NODE__USER_DESCRIPTOR);
		createEReference(nodeEClass, NODE__BINDING_TABLE);
		createEReference(nodeEClass, NODE__GROUP_TABLE);
		createEReference(nodeEClass, NODE__KEY_DESCRIPTOR_TABLE);
		createEReference(nodeEClass, NODE__GREEN_POWER_TX_QUEUE);
		createEReference(nodeEClass, NODE__GREEN_POWER_SECURITY_TABLE);
		createEAttribute(nodeEClass, NODE__DISCOVERY_NEIGHBOUR_TABLE_SIZE);
		createEAttribute(nodeEClass, NODE__ACTIVE_NEIGHBOUR_TABLE_SIZE);
		createEAttribute(nodeEClass, NODE__ROUTE_DISCOVERY_TABLE_SIZE);
		createEAttribute(nodeEClass, NODE__ROUTING_TABLE_SIZE);
		createEAttribute(nodeEClass, NODE__BROADCAST_TRANSACTION_TABLE_SIZE);
		createEAttribute(nodeEClass, NODE__ROUTE_RECORD_TABLE_SIZE);
		createEAttribute(nodeEClass, NODE__ADDRESS_MAP_TABLE_SIZE);
		createEAttribute(nodeEClass, NODE__SECURITY_MATERIAL_SETS);
		createEAttribute(nodeEClass, NODE__MAX_NUM_SIMULTANEOUS_APSDE_REQ);
		createEAttribute(nodeEClass, NODE__MAX_NUM_SIMULTANEOUS_APSDE_ACK_REQ);
		createEAttribute(nodeEClass, NODE__MAC_MUTEX_NAME);
		createEAttribute(nodeEClass, NODE__ZPS_MUTEX_NAME);
		createEAttribute(nodeEClass, NODE__FRAGMENTATION_MAX_NUM_SIMUL_RX);
		createEAttribute(nodeEClass, NODE__FRAGMENTATION_MAX_NUM_SIMUL_TX);
		createEAttribute(nodeEClass, NODE__DEFAULT_EVENT_MESSAGE_NAME);
		createEAttribute(nodeEClass, NODE__MAC_DCFM_IND_MESSAGE);
		createEAttribute(nodeEClass, NODE__MAC_TIME_EVENT_MESSAGE);
		createEAttribute(nodeEClass, NODE__APS_NON_MEMBER_RADIUS);
		createEAttribute(nodeEClass, NODE__APS_DESIGNATED_COORDINATOR);
		createEAttribute(nodeEClass, NODE__APS_USE_INSECURE_JOIN);
		createEAttribute(nodeEClass, NODE__APS_MAX_WINDOW_SIZE);
		createEAttribute(nodeEClass, NODE__APS_INTERFRAME_DELAY);
		createEAttribute(nodeEClass, NODE__APS_DUPLICATE_TABLE_SIZE);
		createEAttribute(nodeEClass, NODE__APS_SECURITY_TIMEOUT_PERIOD);
		createEAttribute(nodeEClass, NODE__APS_USE_EXT_PAN_ID);
		createEReference(nodeEClass, NODE__INITIAL_NETWORK_KEY);
		createEAttribute(nodeEClass, NODE__SECURITY_ENABLED);
		createEAttribute(nodeEClass, NODE__MAC_MLME_DCFM_IND_MESSAGE);
		createEAttribute(nodeEClass, NODE__MAC_MCPS_DCFM_IND_MESSAGE);
		createEAttribute(nodeEClass, NODE__APS_PERSISTENCE_TIME);
		createEAttribute(nodeEClass, NODE__NUM_APSME_SIMUL_COMMANDS);
		createEAttribute(nodeEClass, NODE__STACK_PROFILE);
		createEAttribute(nodeEClass, NODE__INTER_PAN);
		createEAttribute(nodeEClass, NODE__GREEN_POWER_SUPPORT);
		createEAttribute(nodeEClass, NODE__NWK_FC_SAVE_COUNT_BIT_SHIFT);
		createEAttribute(nodeEClass, NODE__APS_FC_SAVE_COUNT_BIT_SHIFT);
		createEAttribute(nodeEClass, NODE__MAC_TABLE_SIZE);
		createEAttribute(nodeEClass, NODE__DEFAULT_CALLBACK_NAME);
		createEReference(nodeEClass, NODE__MAC_INTERFACE_LIST);

		coordinatorEClass = createEClass(COORDINATOR);
		createEReference(coordinatorEClass, COORDINATOR__ZDO_SERVERS);

		routerEClass = createEClass(ROUTER);
		createEReference(routerEClass, ROUTER__ZDO_SERVERS);

		endDeviceEClass = createEClass(END_DEVICE);
		createEReference(endDeviceEClass, END_DEVICE__ZDO_SERVERS);
		createEAttribute(endDeviceEClass, END_DEVICE__NUM_POLL_FAILURES_BEFORE_REJOIN);
		createEAttribute(endDeviceEClass, END_DEVICE__SLEEPING);
		createEAttribute(endDeviceEClass, END_DEVICE__FRAGMENTED_TX_POLL_PERIOD);
		createEAttribute(endDeviceEClass, END_DEVICE__FRAGMENTED_RX_POLL_PERIOD);
		createEAttribute(endDeviceEClass, END_DEVICE__APS_POLL_PERIOD);

		endPointEClass = createEClass(END_POINT);
		createEReference(endPointEClass, END_POINT__INPUT_CLUSTERS);
		createEReference(endPointEClass, END_POINT__OUTPUT_CLUSTERS);
		createEAttribute(endPointEClass, END_POINT__ID);
		createEAttribute(endPointEClass, END_POINT__ENABLED);
		createEAttribute(endPointEClass, END_POINT__APPLICATION_DEVICE_ID);
		createEAttribute(endPointEClass, END_POINT__APPLICATION_DEVICE_VERSION);
		createEReference(endPointEClass, END_POINT__PROFILE);
		createEAttribute(endPointEClass, END_POINT__MESSAGE);
		createEReference(endPointEClass, END_POINT__NODE);
		createEAttribute(endPointEClass, END_POINT__NAME);

		primaryDiscoveryCacheEClass = createEClass(PRIMARY_DISCOVERY_CACHE);
		createEAttribute(primaryDiscoveryCacheEClass, PRIMARY_DISCOVERY_CACHE__SIZE);

		backupDiscoveryCacheEClass = createEClass(BACKUP_DISCOVERY_CACHE);
		createEAttribute(backupDiscoveryCacheEClass, BACKUP_DISCOVERY_CACHE__SIZE);

		discoveryTableEClass = createEClass(DISCOVERY_TABLE);
		createEAttribute(discoveryTableEClass, DISCOVERY_TABLE__SIZE);

		bindingTableEClass = createEClass(BINDING_TABLE);
		createEAttribute(bindingTableEClass, BINDING_TABLE__SIZE);

		groupTableEClass = createEClass(GROUP_TABLE);
		createEAttribute(groupTableEClass, GROUP_TABLE__SIZE);

		zigbeeWirelessNetworkEClass = createEClass(ZIGBEE_WIRELESS_NETWORK);
		createEReference(zigbeeWirelessNetworkEClass, ZIGBEE_WIRELESS_NETWORK__PROFILES);
		createEReference(zigbeeWirelessNetworkEClass, ZIGBEE_WIRELESS_NETWORK__COORDINATOR);
		createEReference(zigbeeWirelessNetworkEClass, ZIGBEE_WIRELESS_NETWORK__CHILD_NODES);
		createEAttribute(zigbeeWirelessNetworkEClass, ZIGBEE_WIRELESS_NETWORK__DEFAULT_EXTENDED_PAN_ID);
		createEAttribute(zigbeeWirelessNetworkEClass, ZIGBEE_WIRELESS_NETWORK__MAX_NUMBER_NODES);
		createEAttribute(zigbeeWirelessNetworkEClass, ZIGBEE_WIRELESS_NETWORK__VERSION);
		createEAttribute(zigbeeWirelessNetworkEClass, ZIGBEE_WIRELESS_NETWORK__DEFAULT_SECURITY_ENABLED);

		primaryBindingCacheEClass = createEClass(PRIMARY_BINDING_CACHE);
		createEAttribute(primaryBindingCacheEClass, PRIMARY_BINDING_CACHE__TABLE_SIZE);
		createEAttribute(primaryBindingCacheEClass, PRIMARY_BINDING_CACHE__NUM_TABLES);

		backupBindingCacheEClass = createEClass(BACKUP_BINDING_CACHE);
		createEAttribute(backupBindingCacheEClass, BACKUP_BINDING_CACHE__TABLE_SIZE);
		createEAttribute(backupBindingCacheEClass, BACKUP_BINDING_CACHE__NUM_TABLES);

		primaryGroupCacheEClass = createEClass(PRIMARY_GROUP_CACHE);
		createEAttribute(primaryGroupCacheEClass, PRIMARY_GROUP_CACHE__SIZE);

		backupGroupCacheEClass = createEClass(BACKUP_GROUP_CACHE);
		createEAttribute(backupGroupCacheEClass, BACKUP_GROUP_CACHE__SIZE);

		inputClusterEClass = createEClass(INPUT_CLUSTER);
		createEReference(inputClusterEClass, INPUT_CLUSTER__CLUSTER);
		createEReference(inputClusterEClass, INPUT_CLUSTER__RX_APDU);
		createEReference(inputClusterEClass, INPUT_CLUSTER__END_POINT);
		createEAttribute(inputClusterEClass, INPUT_CLUSTER__DISCOVERABLE);

		outputClusterEClass = createEClass(OUTPUT_CLUSTER);
		createEReference(outputClusterEClass, OUTPUT_CLUSTER__CLUSTER);
		createEReference(outputClusterEClass, OUTPUT_CLUSTER__END_POINT);
		createEReference(outputClusterEClass, OUTPUT_CLUSTER__TX_APD_US);
		createEAttribute(outputClusterEClass, OUTPUT_CLUSTER__DISCOVERABLE);

		alwaysOnNodeEClass = createEClass(ALWAYS_ON_NODE);
		createEReference(alwaysOnNodeEClass, ALWAYS_ON_NODE__TRUST_CENTER);
		createEAttribute(alwaysOnNodeEClass, ALWAYS_ON_NODE__PERMIT_JOINING_TIME);
		createEAttribute(alwaysOnNodeEClass, ALWAYS_ON_NODE__CHILD_TABLE_SIZE);

		complexDescriptorEClass = createEClass(COMPLEX_DESCRIPTOR);

		userDescriptorEClass = createEClass(USER_DESCRIPTOR);
		createEAttribute(userDescriptorEClass, USER_DESCRIPTOR__USER_DESCRIPTION);

		trustCenterEClass = createEClass(TRUST_CENTER);
		createEAttribute(trustCenterEClass, TRUST_CENTER__DEVICE_TABLE_SIZE);
		createEReference(trustCenterEClass, TRUST_CENTER__KEYS);

		discoveryCacheEClass = createEClass(DISCOVERY_CACHE);

		bindingCacheEClass = createEClass(BINDING_CACHE);

		namedObjectEClass = createEClass(NAMED_OBJECT);
		createEAttribute(namedObjectEClass, NAMED_OBJECT__NAME);

		childNodesEClass = createEClass(CHILD_NODES);
		createEAttribute(childNodesEClass, CHILD_NODES__SCAN_DURATION);
		createEAttribute(childNodesEClass, CHILD_NODES__NETWORK_SELECTION);

		apduEClass = createEClass(APDU);
		createEAttribute(apduEClass, APDU__ID);
		createEAttribute(apduEClass, APDU__NAME);
		createEAttribute(apduEClass, APDU__SIZE);
		createEAttribute(apduEClass, APDU__INSTANCES);
		createEReference(apduEClass, APDU__PDU_CONFIG);

		pduManagerEClass = createEClass(PDU_MANAGER);
		createEReference(pduManagerEClass, PDU_MANAGER__APD_US);
		createEReference(pduManagerEClass, PDU_MANAGER__CONTAINER_NODE);
		createEAttribute(pduManagerEClass, PDU_MANAGER__NUM_NPD_US);
		createEAttribute(pduManagerEClass, PDU_MANAGER__PDUM_MUTEX_NAME);

		channelMaskEClass = createEClass(CHANNEL_MASK);
		createEAttribute(channelMaskEClass, CHANNEL_MASK__CHANNEL11);
		createEAttribute(channelMaskEClass, CHANNEL_MASK__CHANNEL12);
		createEAttribute(channelMaskEClass, CHANNEL_MASK__CHANNEL13);
		createEAttribute(channelMaskEClass, CHANNEL_MASK__CHANNEL14);
		createEAttribute(channelMaskEClass, CHANNEL_MASK__CHANNEL15);
		createEAttribute(channelMaskEClass, CHANNEL_MASK__CHANNEL16);
		createEAttribute(channelMaskEClass, CHANNEL_MASK__CHANNEL17);
		createEAttribute(channelMaskEClass, CHANNEL_MASK__CHANNEL18);
		createEAttribute(channelMaskEClass, CHANNEL_MASK__CHANNEL19);
		createEAttribute(channelMaskEClass, CHANNEL_MASK__CHANNEL20);
		createEAttribute(channelMaskEClass, CHANNEL_MASK__CHANNEL21);
		createEAttribute(channelMaskEClass, CHANNEL_MASK__CHANNEL22);
		createEAttribute(channelMaskEClass, CHANNEL_MASK__CHANNEL23);
		createEAttribute(channelMaskEClass, CHANNEL_MASK__CHANNEL24);
		createEAttribute(channelMaskEClass, CHANNEL_MASK__CHANNEL25);
		createEAttribute(channelMaskEClass, CHANNEL_MASK__CHANNEL26);

		zdoClientServerEClass = createEClass(ZDO_CLIENT_SERVER);
		createEReference(zdoClientServerEClass, ZDO_CLIENT_SERVER__OUTPUT_APDU);

		zdoServersCoordinatorEClass = createEClass(ZDO_SERVERS_COORDINATOR);
		createEReference(zdoServersCoordinatorEClass, ZDO_SERVERS_COORDINATOR__END_DEVICE_BIND_SERVER);

		zdoServersRouterEClass = createEClass(ZDO_SERVERS_ROUTER);

		zdoServersEndDeviceEClass = createEClass(ZDO_SERVERS_END_DEVICE);

		defaultServerEClass = createEClass(DEFAULT_SERVER);

		endDeviceBindServerEClass = createEClass(END_DEVICE_BIND_SERVER);
		createEAttribute(endDeviceBindServerEClass, END_DEVICE_BIND_SERVER__TIMEOUT);
		createEAttribute(endDeviceBindServerEClass, END_DEVICE_BIND_SERVER__BINDING_TIMEOUT);
		createEAttribute(endDeviceBindServerEClass, END_DEVICE_BIND_SERVER__BIND_NUM_RETRIES);

		deviceAnnceServerEClass = createEClass(DEVICE_ANNCE_SERVER);

		activeEpServerEClass = createEClass(ACTIVE_EP_SERVER);

		nwkAddrServerEClass = createEClass(NWK_ADDR_SERVER);

		ieeeAddrServerEClass = createEClass(IEEE_ADDR_SERVER);

		matchDescServerEClass = createEClass(MATCH_DESC_SERVER);

		nodeDescServerEClass = createEClass(NODE_DESC_SERVER);

		permitJoiningServerEClass = createEClass(PERMIT_JOINING_SERVER);

		powerDescServerEClass = createEClass(POWER_DESC_SERVER);

		simpleDescServerEClass = createEClass(SIMPLE_DESC_SERVER);

		systemServerDiscoveryServerEClass = createEClass(SYSTEM_SERVER_DISCOVERY_SERVER);

		mgmtLqiServerEClass = createEClass(MGMT_LQI_SERVER);

		mgmtRtgServerEClass = createEClass(MGMT_RTG_SERVER);

		mgmtLeaveServerEClass = createEClass(MGMT_LEAVE_SERVER);

		nodeDescriptorEClass = createEClass(NODE_DESCRIPTOR);
		createEAttribute(nodeDescriptorEClass, NODE_DESCRIPTOR__MANUFACTURER_CODE);
		createEAttribute(nodeDescriptorEClass, NODE_DESCRIPTOR__LOGICAL_TYPE);
		createEAttribute(nodeDescriptorEClass, NODE_DESCRIPTOR__COMPLEX_DESCRIPTOR_AVAILABLE);
		createEAttribute(nodeDescriptorEClass, NODE_DESCRIPTOR__USER_DESCRIPTOR_AVAILABLE);
		createEAttribute(nodeDescriptorEClass, NODE_DESCRIPTOR__APS_FLAGS);
		createEAttribute(nodeDescriptorEClass, NODE_DESCRIPTOR__FREQUENCY_BAND);
		createEAttribute(nodeDescriptorEClass, NODE_DESCRIPTOR__ALTERNATE_PAN_COORDINATOR);
		createEAttribute(nodeDescriptorEClass, NODE_DESCRIPTOR__DEVICE_TYPE);
		createEAttribute(nodeDescriptorEClass, NODE_DESCRIPTOR__POWER_SOURCE);
		createEAttribute(nodeDescriptorEClass, NODE_DESCRIPTOR__RX_ON_WHEN_IDLE);
		createEAttribute(nodeDescriptorEClass, NODE_DESCRIPTOR__SECURITY);
		createEAttribute(nodeDescriptorEClass, NODE_DESCRIPTOR__ALLOCATE_ADDRESS);
		createEAttribute(nodeDescriptorEClass, NODE_DESCRIPTOR__MAXIMUM_BUFFER_SIZE);
		createEAttribute(nodeDescriptorEClass, NODE_DESCRIPTOR__MAXIMUM_INCOMING_TRANSFER_SIZE);
		createEAttribute(nodeDescriptorEClass, NODE_DESCRIPTOR__MAXIMUM_OUTGOING_TRANSFER_SIZE);
		createEAttribute(nodeDescriptorEClass, NODE_DESCRIPTOR__EXTENDED_ACTIVE_ENDPOINT_LIST_AVAILABLE);
		createEAttribute(nodeDescriptorEClass, NODE_DESCRIPTOR__EXTENDED_SIMPLE_DESCRIPTOR_LIST_AVAILABLE);
		createEAttribute(nodeDescriptorEClass, NODE_DESCRIPTOR__PRIMARY_TRUST_CENTER);
		createEAttribute(nodeDescriptorEClass, NODE_DESCRIPTOR__BACKUP_TRUST_CENTER);
		createEAttribute(nodeDescriptorEClass, NODE_DESCRIPTOR__PRIMARY_BINDING_TABLE_CACHE);
		createEAttribute(nodeDescriptorEClass, NODE_DESCRIPTOR__BACKUP_BINDING_TABLE_CACHE);
		createEAttribute(nodeDescriptorEClass, NODE_DESCRIPTOR__PRIMARY_DISCOVERY_CACHE);
		createEAttribute(nodeDescriptorEClass, NODE_DESCRIPTOR__BACKUP_DISCOVERY_CACHE);
		createEReference(nodeDescriptorEClass, NODE_DESCRIPTOR__NODE);
		createEAttribute(nodeDescriptorEClass, NODE_DESCRIPTOR__NETWORK_MANAGER);

		nodePowerDescriptorEClass = createEClass(NODE_POWER_DESCRIPTOR);
		createEAttribute(nodePowerDescriptorEClass, NODE_POWER_DESCRIPTOR__CONSTANT_POWER);
		createEAttribute(nodePowerDescriptorEClass, NODE_POWER_DESCRIPTOR__RECHARGEABLE_BATTERY);
		createEAttribute(nodePowerDescriptorEClass, NODE_POWER_DESCRIPTOR__DISPOSABLE_BATTERY);
		createEAttribute(nodePowerDescriptorEClass, NODE_POWER_DESCRIPTOR__DEFAULT_POWER_SOURCE);
		createEAttribute(nodePowerDescriptorEClass, NODE_POWER_DESCRIPTOR__DEFAULT_POWER_MODE);

		bindUnbindServerEClass = createEClass(BIND_UNBIND_SERVER);

		mgmtBindServerEClass = createEClass(MGMT_BIND_SERVER);

		extendedActiveEpServerEClass = createEClass(EXTENDED_ACTIVE_EP_SERVER);

		extendedSimpleDescServerEClass = createEClass(EXTENDED_SIMPLE_DESC_SERVER);

		zdoClientEClass = createEClass(ZDO_CLIENT);

		mgmtNWKUpdateServerEClass = createEClass(MGMT_NWK_UPDATE_SERVER);

		zdoCommonServersEClass = createEClass(ZDO_COMMON_SERVERS);
		createEReference(zdoCommonServersEClass, ZDO_COMMON_SERVERS__DEFAULT_SERVER);
		createEReference(zdoCommonServersEClass, ZDO_COMMON_SERVERS__ZDO_CLIENT);
		createEReference(zdoCommonServersEClass, ZDO_COMMON_SERVERS__DEVICE_ANNCE_SERVER);
		createEReference(zdoCommonServersEClass, ZDO_COMMON_SERVERS__ACTIVE_EP_SERVER);
		createEReference(zdoCommonServersEClass, ZDO_COMMON_SERVERS__NWK_ADDR_SERVER);
		createEReference(zdoCommonServersEClass, ZDO_COMMON_SERVERS__IEEE_ADDR_SERVER);
		createEReference(zdoCommonServersEClass, ZDO_COMMON_SERVERS__SYSTEM_SERVER_DISCOVERY_SERVER);
		createEReference(zdoCommonServersEClass, ZDO_COMMON_SERVERS__NODE_DESC_SERVER);
		createEReference(zdoCommonServersEClass, ZDO_COMMON_SERVERS__POWER_DESC_SERVER);
		createEReference(zdoCommonServersEClass, ZDO_COMMON_SERVERS__MATCH_DESC_SERVER);
		createEReference(zdoCommonServersEClass, ZDO_COMMON_SERVERS__SIMPLE_DESC_SERVER);
		createEReference(zdoCommonServersEClass, ZDO_COMMON_SERVERS__MGMT_LQI_SERVER);
		createEReference(zdoCommonServersEClass, ZDO_COMMON_SERVERS__MGMT_LEAVE_SERVER);
		createEReference(zdoCommonServersEClass, ZDO_COMMON_SERVERS__MGMT_NWK_UPDATE_SERVER);
		createEReference(zdoCommonServersEClass, ZDO_COMMON_SERVERS__BIND_UNBIND_SERVER);
		createEReference(zdoCommonServersEClass, ZDO_COMMON_SERVERS__EXTENDED_ACTIVE_EP_SERVER);
		createEReference(zdoCommonServersEClass, ZDO_COMMON_SERVERS__EXTENDED_SIMPLE_DESC_SERVER);
		createEReference(zdoCommonServersEClass, ZDO_COMMON_SERVERS__BIND_REQUEST_SERVER);
		createEReference(zdoCommonServersEClass, ZDO_COMMON_SERVERS__MGMT_BIND_SERVER);
		createEReference(zdoCommonServersEClass, ZDO_COMMON_SERVERS__MGMT_NWK_ENHANCE_UPDATE_SERVER);

		notImplementedEClass = createEClass(NOT_IMPLEMENTED);
		createEReference(notImplementedEClass, NOT_IMPLEMENTED__COMPLEX_DESCRIPTOR);
		createEReference(notImplementedEClass, NOT_IMPLEMENTED__DISCOVERY_TABLE);
		createEReference(notImplementedEClass, NOT_IMPLEMENTED__DISCOVERY_CACHE);
		createEReference(notImplementedEClass, NOT_IMPLEMENTED__BINDING_CACHE);

		keyDescriptorTableEClass = createEClass(KEY_DESCRIPTOR_TABLE);
		createEAttribute(keyDescriptorTableEClass, KEY_DESCRIPTOR_TABLE__SIZE);
		createEReference(keyDescriptorTableEClass, KEY_DESCRIPTOR_TABLE__PRECONFIGURED_KEY);

		preconfiguredKeyEClass = createEClass(PRECONFIGURED_KEY);
		createEAttribute(preconfiguredKeyEClass, PRECONFIGURED_KEY__KEY);
		createEAttribute(preconfiguredKeyEClass, PRECONFIGURED_KEY__IEEE_ADDRESS);

		zdoCoordRouterOnlyServersEClass = createEClass(ZDO_COORD_ROUTER_ONLY_SERVERS);
		createEReference(zdoCoordRouterOnlyServersEClass, ZDO_COORD_ROUTER_ONLY_SERVERS__PERMIT_JOINING_SERVER);
		createEReference(zdoCoordRouterOnlyServersEClass, ZDO_COORD_ROUTER_ONLY_SERVERS__MGMT_RTG_SERVER);
		createEReference(zdoCoordRouterOnlyServersEClass, ZDO_COORD_ROUTER_ONLY_SERVERS__MGMT_MIB_IEEE_SERVER);
		createEReference(zdoCoordRouterOnlyServersEClass, ZDO_COORD_ROUTER_ONLY_SERVERS__PARENT_ANNCE_SERVER);

		preConfiguredNwkKeyEClass = createEClass(PRE_CONFIGURED_NWK_KEY);

		defaultNwkKeyEClass = createEClass(DEFAULT_NWK_KEY);
		createEAttribute(defaultNwkKeyEClass, DEFAULT_NWK_KEY__RANDOM);

		nwkKeyEClass = createEClass(NWK_KEY);
		createEAttribute(nwkKeyEClass, NWK_KEY__KEY_SEQUENCE_NUMBER);
		createEAttribute(nwkKeyEClass, NWK_KEY__KEY);
		createEAttribute(nwkKeyEClass, NWK_KEY__ID);

		preconfiguredTCLinkKeyEClass = createEClass(PRECONFIGURED_TC_LINK_KEY);
		createEAttribute(preconfiguredTCLinkKeyEClass, PRECONFIGURED_TC_LINK_KEY__ID);

		tcKeyEClass = createEClass(TC_KEY);

		bindRequestServerEClass = createEClass(BIND_REQUEST_SERVER);
		createEAttribute(bindRequestServerEClass, BIND_REQUEST_SERVER__SIMULTANEOUS_REQUESTS);
		createEAttribute(bindRequestServerEClass, BIND_REQUEST_SERVER__TIME_INTERVAL);

		greenPowerSecurityTableEClass = createEClass(GREEN_POWER_SECURITY_TABLE);
		createEAttribute(greenPowerSecurityTableEClass, GREEN_POWER_SECURITY_TABLE__SIZE);

		greenPowerTxQueueEClass = createEClass(GREEN_POWER_TX_QUEUE);
		createEAttribute(greenPowerTxQueueEClass, GREEN_POWER_TX_QUEUE__SIZE);

		mgmtMibIeeeServerEClass = createEClass(MGMT_MIB_IEEE_SERVER);

		parentAnnceServerEClass = createEClass(PARENT_ANNCE_SERVER);

		mgmtNWKEnhanceUpdateServerEClass = createEClass(MGMT_NWK_ENHANCE_UPDATE_SERVER);

		macInterfaceListEClass = createEClass(MAC_INTERFACE_LIST);
		createEReference(macInterfaceListEClass, MAC_INTERFACE_LIST__MAC_INTERFACE);

		macInterfaceEClass = createEClass(MAC_INTERFACE);
		createEAttribute(macInterfaceEClass, MAC_INTERFACE__ROUTER_ALLOWED);
		createEAttribute(macInterfaceEClass, MAC_INTERFACE__CHANNEL_LIST_SIZE);
		createEAttribute(macInterfaceEClass, MAC_INTERFACE__INDEX);
		createEAttribute(macInterfaceEClass, MAC_INTERFACE__RADIO_TYPE);
		createEAttribute(macInterfaceEClass, MAC_INTERFACE__ENABLED);

		// Create enums
		nodeLogicalTypeEEnum = createEEnum(NODE_LOGICAL_TYPE);
		frequencyBandsEEnum = createEEnum(FREQUENCY_BANDS);
		powerSourcesEEnum = createEEnum(POWER_SOURCES);
		powerModesEEnum = createEEnum(POWER_MODES);
		networkSelectionTypesEEnum = createEEnum(NETWORK_SELECTION_TYPES);
		radioTypeEEnum = createEEnum(RADIO_TYPE);

		// Create data types
		euShortEDataType = createEDataType(EU_SHORT);
		eExtPANIdEDataType = createEDataType(EEXT_PAN_ID);
		ePermitJoiningEDataType = createEDataType(EPERMIT_JOINING);
		eSecKeyEDataType = createEDataType(ESEC_KEY);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	private boolean isInitialized = false;

	/**
	 * Complete the initialization of the package and its meta-model.  This
	 * method is guarded to have no affect on any invocation but its first.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void initializePackageContents() {
		if (isInitialized) return;
		isInitialized = true;

		// Initialize package
		setName(eNAME);
		setNsPrefix(eNS_PREFIX);
		setNsURI(eNS_URI);

		// Create type parameters

		// Set bounds for type parameters

		// Add supertypes to classes
		profileEClass.getESuperTypes().add(this.getNamedObject());
		clusterEClass.getESuperTypes().add(this.getNamedObject());
		nodeEClass.getESuperTypes().add(this.getNamedObject());
		coordinatorEClass.getESuperTypes().add(this.getAlwaysOnNode());
		routerEClass.getESuperTypes().add(this.getAlwaysOnNode());
		routerEClass.getESuperTypes().add(this.getChildNodes());
		endDeviceEClass.getESuperTypes().add(this.getNode());
		endDeviceEClass.getESuperTypes().add(this.getChildNodes());
		primaryDiscoveryCacheEClass.getESuperTypes().add(this.getDiscoveryCache());
		backupDiscoveryCacheEClass.getESuperTypes().add(this.getDiscoveryCache());
		primaryBindingCacheEClass.getESuperTypes().add(this.getBindingCache());
		backupBindingCacheEClass.getESuperTypes().add(this.getBindingCache());
		alwaysOnNodeEClass.getESuperTypes().add(this.getNode());
		zdoServersCoordinatorEClass.getESuperTypes().add(this.getZDOCommonServers());
		zdoServersCoordinatorEClass.getESuperTypes().add(this.getZDOCoordRouterOnlyServers());
		zdoServersRouterEClass.getESuperTypes().add(this.getZDOCommonServers());
		zdoServersRouterEClass.getESuperTypes().add(this.getZDOCoordRouterOnlyServers());
		zdoServersEndDeviceEClass.getESuperTypes().add(this.getZDOCommonServers());
		defaultServerEClass.getESuperTypes().add(this.getZDOClientServer());
		endDeviceBindServerEClass.getESuperTypes().add(this.getZDOClientServer());
		deviceAnnceServerEClass.getESuperTypes().add(this.getZDOClientServer());
		activeEpServerEClass.getESuperTypes().add(this.getZDOClientServer());
		nwkAddrServerEClass.getESuperTypes().add(this.getZDOClientServer());
		ieeeAddrServerEClass.getESuperTypes().add(this.getZDOClientServer());
		matchDescServerEClass.getESuperTypes().add(this.getZDOClientServer());
		nodeDescServerEClass.getESuperTypes().add(this.getZDOClientServer());
		permitJoiningServerEClass.getESuperTypes().add(this.getZDOClientServer());
		powerDescServerEClass.getESuperTypes().add(this.getZDOClientServer());
		simpleDescServerEClass.getESuperTypes().add(this.getZDOClientServer());
		systemServerDiscoveryServerEClass.getESuperTypes().add(this.getZDOClientServer());
		mgmtLqiServerEClass.getESuperTypes().add(this.getZDOClientServer());
		mgmtRtgServerEClass.getESuperTypes().add(this.getZDOClientServer());
		mgmtLeaveServerEClass.getESuperTypes().add(this.getZDOClientServer());
		bindUnbindServerEClass.getESuperTypes().add(this.getZDOClientServer());
		mgmtBindServerEClass.getESuperTypes().add(this.getZDOClientServer());
		extendedActiveEpServerEClass.getESuperTypes().add(this.getZDOClientServer());
		extendedSimpleDescServerEClass.getESuperTypes().add(this.getZDOClientServer());
		zdoClientEClass.getESuperTypes().add(this.getZDOClientServer());
		mgmtNWKUpdateServerEClass.getESuperTypes().add(this.getZDOClientServer());
		preConfiguredNwkKeyEClass.getESuperTypes().add(this.getNwkKey());
		defaultNwkKeyEClass.getESuperTypes().add(this.getNwkKey());
		nwkKeyEClass.getESuperTypes().add(this.getTCKey());
		preconfiguredTCLinkKeyEClass.getESuperTypes().add(this.getTCKey());
		bindRequestServerEClass.getESuperTypes().add(this.getZDOClientServer());
		mgmtMibIeeeServerEClass.getESuperTypes().add(this.getZDOClientServer());
		parentAnnceServerEClass.getESuperTypes().add(this.getZDOClientServer());
		mgmtNWKEnhanceUpdateServerEClass.getESuperTypes().add(this.getZDOClientServer());

		// Initialize classes and features; add operations and parameters
		initEClass(profileEClass, Profile.class, "Profile", !IS_ABSTRACT, !IS_INTERFACE, IS_GENERATED_INSTANCE_CLASS);
		initEAttribute(getProfile_Id(), this.getEUShort(), "Id", "1", 1, 1, Profile.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEReference(getProfile_Clusters(), this.getCluster(), null, "Clusters", null, 1, 65535, Profile.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, IS_COMPOSITE, !IS_RESOLVE_PROXIES, !IS_UNSETTABLE, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);

		initEClass(clusterEClass, Cluster.class, "Cluster", !IS_ABSTRACT, !IS_INTERFACE, IS_GENERATED_INSTANCE_CLASS);
		initEAttribute(getCluster_Id(), this.getEUShort(), "Id", "0", 1, 1, Cluster.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);

		initEClass(nodeEClass, Node.class, "Node", IS_ABSTRACT, !IS_INTERFACE, IS_GENERATED_INSTANCE_CLASS);
		initEReference(getNode_Endpoints(), this.getEndPoint(), this.getEndPoint_Node(), "Endpoints", null, 1, 255, Node.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, IS_COMPOSITE, !IS_RESOLVE_PROXIES, !IS_UNSETTABLE, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEReference(getNode_PDUConfiguration(), this.getPDUManager(), this.getPDUManager_ContainerNode(), "PDUConfiguration", null, 1, 1, Node.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, IS_COMPOSITE, !IS_RESOLVE_PROXIES, !IS_UNSETTABLE, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEReference(getNode_ChannelMask(), this.getChannelMask(), null, "ChannelMask", null, 1, 1, Node.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, IS_COMPOSITE, !IS_RESOLVE_PROXIES, !IS_UNSETTABLE, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEReference(getNode_NodeDescriptor(), this.getNodeDescriptor(), this.getNodeDescriptor_Node(), "NodeDescriptor", null, 1, 1, Node.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, IS_COMPOSITE, !IS_RESOLVE_PROXIES, !IS_UNSETTABLE, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEReference(getNode_NodePowerDescriptor(), this.getNodePowerDescriptor(), null, "NodePowerDescriptor", null, 1, 1, Node.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, IS_COMPOSITE, !IS_RESOLVE_PROXIES, !IS_UNSETTABLE, IS_UNIQUE, IS_DERIVED, IS_ORDERED);
		initEReference(getNode_UserDescriptor(), this.getUserDescriptor(), null, "UserDescriptor", null, 0, 1, Node.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, IS_COMPOSITE, !IS_RESOLVE_PROXIES, !IS_UNSETTABLE, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEReference(getNode_BindingTable(), this.getBindingTable(), null, "BindingTable", null, 0, 1, Node.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, IS_COMPOSITE, !IS_RESOLVE_PROXIES, !IS_UNSETTABLE, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEReference(getNode_GroupTable(), this.getGroupTable(), null, "GroupTable", null, 0, 1, Node.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, IS_COMPOSITE, !IS_RESOLVE_PROXIES, !IS_UNSETTABLE, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEReference(getNode_KeyDescriptorTable(), this.getKeyDescriptorTable(), null, "KeyDescriptorTable", null, 0, 1, Node.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, IS_COMPOSITE, !IS_RESOLVE_PROXIES, !IS_UNSETTABLE, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEReference(getNode_GreenPowerTxQueue(), this.getGreenPowerTxQueue(), null, "GreenPowerTxQueue", null, 0, 1, Node.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, IS_COMPOSITE, !IS_RESOLVE_PROXIES, !IS_UNSETTABLE, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEReference(getNode_GreenPowerSecurityTable(), this.getGreenPowerSecurityTable(), null, "GreenPowerSecurityTable", null, 0, 1, Node.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, IS_COMPOSITE, !IS_RESOLVE_PROXIES, !IS_UNSETTABLE, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEAttribute(getNode_DiscoveryNeighbourTableSize(), ecorePackage.getEBigInteger(), "DiscoveryNeighbourTableSize", "16", 1, 1, Node.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEAttribute(getNode_ActiveNeighbourTableSize(), ecorePackage.getEBigInteger(), "ActiveNeighbourTableSize", "26", 1, 1, Node.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEAttribute(getNode_RouteDiscoveryTableSize(), ecorePackage.getEBigInteger(), "RouteDiscoveryTableSize", "2", 1, 1, Node.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEAttribute(getNode_RoutingTableSize(), ecorePackage.getEBigInteger(), "RoutingTableSize", "255", 1, 1, Node.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEAttribute(getNode_BroadcastTransactionTableSize(), ecorePackage.getEBigInteger(), "BroadcastTransactionTableSize", "9", 1, 1, Node.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEAttribute(getNode_RouteRecordTableSize(), ecorePackage.getEBigInteger(), "RouteRecordTableSize", "2", 1, 1, Node.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEAttribute(getNode_AddressMapTableSize(), ecorePackage.getEBigInteger(), "AddressMapTableSize", "10", 1, 1, Node.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEAttribute(getNode_SecurityMaterialSets(), ecorePackage.getEBigInteger(), "SecurityMaterialSets", "2", 1, 1, Node.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEAttribute(getNode_MaxNumSimultaneousApsdeReq(), ecorePackage.getEInt(), "MaxNumSimultaneousApsdeReq", "5", 1, 1, Node.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEAttribute(getNode_MaxNumSimultaneousApsdeAckReq(), ecorePackage.getEBigInteger(), "MaxNumSimultaneousApsdeAckReq", "3", 1, 1, Node.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEAttribute(getNode_MACMutexName(), ecorePackage.getEString(), "MACMutexName", "mutexMAC", 1, 1, Node.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEAttribute(getNode_ZPSMutexName(), ecorePackage.getEString(), "ZPSMutexName", "mutexZPS", 1, 1, Node.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEAttribute(getNode_FragmentationMaxNumSimulRx(), ecorePackage.getEInt(), "FragmentationMaxNumSimulRx", "0", 1, 1, Node.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEAttribute(getNode_FragmentationMaxNumSimulTx(), ecorePackage.getEInt(), "FragmentationMaxNumSimulTx", "0", 1, 1, Node.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEAttribute(getNode_DefaultEventMessageName(), ecorePackage.getEString(), "DefaultEventMessageName", "APP_msgZpsEvents", 1, 1, Node.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEAttribute(getNode_MACDcfmIndMessage(), ecorePackage.getEString(), "MACDcfmIndMessage", "zps_msgDcfmInd", 1, 1, Node.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEAttribute(getNode_MACTimeEventMessage(), ecorePackage.getEString(), "MACTimeEventMessage", "zps_msgTimeEvents", 1, 1, Node.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEAttribute(getNode_ApsNonMemberRadius(), ecorePackage.getEInt(), "apsNonMemberRadius", "2", 1, 1, Node.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEAttribute(getNode_ApsDesignatedCoordinator(), ecorePackage.getEBoolean(), "apsDesignatedCoordinator", "false", 1, 1, Node.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, IS_UNIQUE, IS_DERIVED, IS_ORDERED);
		initEAttribute(getNode_ApsUseInsecureJoin(), ecorePackage.getEBoolean(), "apsUseInsecureJoin", "true", 1, 1, Node.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEAttribute(getNode_ApsMaxWindowSize(), ecorePackage.getEInt(), "apsMaxWindowSize", "8", 1, 1, Node.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEAttribute(getNode_ApsInterframeDelay(), ecorePackage.getEInt(), "apsInterframeDelay", "10", 1, 1, Node.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEAttribute(getNode_APSDuplicateTableSize(), ecorePackage.getEInt(), "APSDuplicateTableSize", "8", 1, 1, Node.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEAttribute(getNode_ApsSecurityTimeoutPeriod(), ecorePackage.getEBigInteger(), "apsSecurityTimeoutPeriod", "1000", 1, 1, Node.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEAttribute(getNode_ApsUseExtPANId(), this.getEExtPANId(), "apsUseExtPANId", "0", 1, 1, Node.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEReference(getNode_InitialNetworkKey(), this.getTCKey(), null, "InitialNetworkKey", null, 0, 1, Node.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_COMPOSITE, IS_RESOLVE_PROXIES, !IS_UNSETTABLE, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEAttribute(getNode_SecurityEnabled(), ecorePackage.getEBoolean(), "SecurityEnabled", "true", 1, 1, Node.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEAttribute(getNode_MACMlmeDcfmIndMessage(), ecorePackage.getEString(), "MACMlmeDcfmIndMessage", "zps_msgMlmeDcfmInd", 1, 1, Node.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEAttribute(getNode_MACMcpsDcfmIndMessage(), ecorePackage.getEString(), "MACMcpsDcfmIndMessage", "zps_msgMcpsDcfmInd", 1, 1, Node.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEAttribute(getNode_APSPersistenceTime(), ecorePackage.getEInt(), "APSPersistenceTime", "100", 1, 1, Node.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEAttribute(getNode_NumAPSMESimulCommands(), ecorePackage.getEInt(), "NumAPSMESimulCommands", "4", 1, 1, Node.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEAttribute(getNode_StackProfile(), ecorePackage.getEInt(), "StackProfile", "2", 1, 1, Node.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEAttribute(getNode_InterPAN(), ecorePackage.getEBoolean(), "InterPAN", "false", 1, 1, Node.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEAttribute(getNode_GreenPowerSupport(), ecorePackage.getEBoolean(), "GreenPowerSupport", "false", 1, 1, Node.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEAttribute(getNode_NwkFcSaveCountBitShift(), ecorePackage.getEInt(), "NwkFcSaveCountBitShift", "10", 1, 1, Node.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEAttribute(getNode_ApsFcSaveCountBitShift(), ecorePackage.getEInt(), "ApsFcSaveCountBitShift", "10", 1, 1, Node.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEAttribute(getNode_MacTableSize(), ecorePackage.getEBigInteger(), "MacTableSize", "36", 1, 1, Node.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEAttribute(getNode_DefaultCallbackName(), ecorePackage.getEString(), "DefaultCallbackName", "APP_vGenCallback", 1, 1, Node.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEReference(getNode_MacInterfaceList(), this.getMacInterfaceList(), null, "MacInterfaceList", null, 0, 1, Node.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, IS_COMPOSITE, !IS_RESOLVE_PROXIES, !IS_UNSETTABLE, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);

		initEClass(coordinatorEClass, Coordinator.class, "Coordinator", !IS_ABSTRACT, !IS_INTERFACE, IS_GENERATED_INSTANCE_CLASS);
		initEReference(getCoordinator_ZDOServers(), this.getZDOServersCoordinator(), null, "ZDOServers", null, 1, 1, Coordinator.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, IS_COMPOSITE, !IS_RESOLVE_PROXIES, !IS_UNSETTABLE, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);

		initEClass(routerEClass, Router.class, "Router", !IS_ABSTRACT, !IS_INTERFACE, IS_GENERATED_INSTANCE_CLASS);
		initEReference(getRouter_ZDOServers(), this.getZDOServersRouter(), null, "ZDOServers", null, 1, 1, Router.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, IS_COMPOSITE, !IS_RESOLVE_PROXIES, !IS_UNSETTABLE, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);

		initEClass(endDeviceEClass, EndDevice.class, "EndDevice", !IS_ABSTRACT, !IS_INTERFACE, IS_GENERATED_INSTANCE_CLASS);
		initEReference(getEndDevice_ZDOServers(), this.getZDOServersEndDevice(), null, "ZDOServers", null, 1, 1, EndDevice.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, IS_COMPOSITE, !IS_RESOLVE_PROXIES, !IS_UNSETTABLE, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEAttribute(getEndDevice_NumPollFailuresBeforeRejoin(), ecorePackage.getEInt(), "NumPollFailuresBeforeRejoin", "3", 0, 1, EndDevice.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEAttribute(getEndDevice_Sleeping(), ecorePackage.getEBoolean(), "Sleeping", "false", 1, 1, EndDevice.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEAttribute(getEndDevice_FragmentedTxPollPeriod(), ecorePackage.getEInt(), "FragmentedTxPollPeriod", "25", 0, 1, EndDevice.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEAttribute(getEndDevice_FragmentedRxPollPeriod(), ecorePackage.getEInt(), "FragmentedRxPollPeriod", "25", 0, 1, EndDevice.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEAttribute(getEndDevice_APSPollPeriod(), ecorePackage.getEInt(), "APSPollPeriod", "100", 0, 1, EndDevice.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);

		initEClass(endPointEClass, EndPoint.class, "EndPoint", !IS_ABSTRACT, !IS_INTERFACE, IS_GENERATED_INSTANCE_CLASS);
		initEReference(getEndPoint_InputClusters(), this.getInputCluster(), this.getInputCluster_EndPoint(), "InputClusters", null, 0, 255, EndPoint.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, IS_COMPOSITE, !IS_RESOLVE_PROXIES, !IS_UNSETTABLE, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEReference(getEndPoint_OutputClusters(), this.getOutputCluster(), this.getOutputCluster_EndPoint(), "OutputClusters", null, 0, 255, EndPoint.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, IS_COMPOSITE, !IS_RESOLVE_PROXIES, !IS_UNSETTABLE, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEAttribute(getEndPoint_Id(), ecorePackage.getEInt(), "Id", "1", 1, 1, EndPoint.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEAttribute(getEndPoint_Enabled(), ecorePackage.getEBoolean(), "Enabled", "true", 1, 1, EndPoint.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEAttribute(getEndPoint_ApplicationDeviceId(), ecorePackage.getEInt(), "ApplicationDeviceId", "0", 1, 1, EndPoint.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEAttribute(getEndPoint_ApplicationDeviceVersion(), ecorePackage.getEInt(), "ApplicationDeviceVersion", "0", 1, 1, EndPoint.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEReference(getEndPoint_Profile(), this.getProfile(), null, "Profile", null, 1, 1, EndPoint.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_COMPOSITE, IS_RESOLVE_PROXIES, !IS_UNSETTABLE, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEAttribute(getEndPoint_Message(), ecorePackage.getEString(), "Message", null, 0, 1, EndPoint.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEReference(getEndPoint_Node(), this.getNode(), this.getNode_Endpoints(), "Node", null, 1, 1, EndPoint.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_COMPOSITE, !IS_RESOLVE_PROXIES, !IS_UNSETTABLE, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEAttribute(getEndPoint_Name(), ecorePackage.getEString(), "Name", null, 1, 1, EndPoint.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);

		initEClass(primaryDiscoveryCacheEClass, PrimaryDiscoveryCache.class, "PrimaryDiscoveryCache", !IS_ABSTRACT, !IS_INTERFACE, IS_GENERATED_INSTANCE_CLASS);
		initEAttribute(getPrimaryDiscoveryCache_Size(), ecorePackage.getEBigInteger(), "Size", null, 0, 1, PrimaryDiscoveryCache.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);

		initEClass(backupDiscoveryCacheEClass, BackupDiscoveryCache.class, "BackupDiscoveryCache", !IS_ABSTRACT, !IS_INTERFACE, IS_GENERATED_INSTANCE_CLASS);
		initEAttribute(getBackupDiscoveryCache_Size(), ecorePackage.getEBigInteger(), "Size", null, 0, 1, BackupDiscoveryCache.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);

		initEClass(discoveryTableEClass, DiscoveryTable.class, "DiscoveryTable", !IS_ABSTRACT, !IS_INTERFACE, IS_GENERATED_INSTANCE_CLASS);
		initEAttribute(getDiscoveryTable_Size(), ecorePackage.getEInt(), "Size", null, 0, 1, DiscoveryTable.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);

		initEClass(bindingTableEClass, BindingTable.class, "BindingTable", !IS_ABSTRACT, !IS_INTERFACE, IS_GENERATED_INSTANCE_CLASS);
		initEAttribute(getBindingTable_Size(), ecorePackage.getEInt(), "Size", "5", 0, 1, BindingTable.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);

		initEClass(groupTableEClass, GroupTable.class, "GroupTable", !IS_ABSTRACT, !IS_INTERFACE, IS_GENERATED_INSTANCE_CLASS);
		initEAttribute(getGroupTable_Size(), ecorePackage.getEInt(), "Size", "16", 0, 1, GroupTable.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);

		initEClass(zigbeeWirelessNetworkEClass, ZigbeeWirelessNetwork.class, "ZigbeeWirelessNetwork", !IS_ABSTRACT, !IS_INTERFACE, IS_GENERATED_INSTANCE_CLASS);
		initEReference(getZigbeeWirelessNetwork_Profiles(), this.getProfile(), null, "Profiles", null, 1, -1, ZigbeeWirelessNetwork.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, IS_COMPOSITE, !IS_RESOLVE_PROXIES, !IS_UNSETTABLE, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEReference(getZigbeeWirelessNetwork_Coordinator(), this.getCoordinator(), null, "Coordinator", null, 0, 1, ZigbeeWirelessNetwork.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, IS_COMPOSITE, !IS_RESOLVE_PROXIES, !IS_UNSETTABLE, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEReference(getZigbeeWirelessNetwork_ChildNodes(), this.getChildNodes(), null, "ChildNodes", null, 0, -1, ZigbeeWirelessNetwork.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, IS_COMPOSITE, !IS_RESOLVE_PROXIES, !IS_UNSETTABLE, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEAttribute(getZigbeeWirelessNetwork_DefaultExtendedPANId(), this.getEExtPANId(), "DefaultExtendedPANId", "0", 0, 1, ZigbeeWirelessNetwork.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEAttribute(getZigbeeWirelessNetwork_MaxNumberNodes(), ecorePackage.getEInt(), "MaxNumberNodes", "20", 0, 1, ZigbeeWirelessNetwork.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEAttribute(getZigbeeWirelessNetwork_Version(), ecorePackage.getEString(), "Version", "1.2", 1, 1, ZigbeeWirelessNetwork.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEAttribute(getZigbeeWirelessNetwork_DefaultSecurityEnabled(), ecorePackage.getEBoolean(), "DefaultSecurityEnabled", "true", 1, 1, ZigbeeWirelessNetwork.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);

		initEClass(primaryBindingCacheEClass, PrimaryBindingCache.class, "PrimaryBindingCache", !IS_ABSTRACT, !IS_INTERFACE, IS_GENERATED_INSTANCE_CLASS);
		initEAttribute(getPrimaryBindingCache_TableSize(), ecorePackage.getEBigInteger(), "TableSize", null, 1, 1, PrimaryBindingCache.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEAttribute(getPrimaryBindingCache_NumTables(), ecorePackage.getEBigInteger(), "NumTables", null, 1, 1, PrimaryBindingCache.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);

		initEClass(backupBindingCacheEClass, BackupBindingCache.class, "BackupBindingCache", !IS_ABSTRACT, !IS_INTERFACE, IS_GENERATED_INSTANCE_CLASS);
		initEAttribute(getBackupBindingCache_TableSize(), ecorePackage.getEBigInteger(), "TableSize", null, 1, 1, BackupBindingCache.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEAttribute(getBackupBindingCache_NumTables(), ecorePackage.getEBigInteger(), "NumTables", null, 1, 1, BackupBindingCache.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);

		initEClass(primaryGroupCacheEClass, PrimaryGroupCache.class, "PrimaryGroupCache", !IS_ABSTRACT, !IS_INTERFACE, IS_GENERATED_INSTANCE_CLASS);
		initEAttribute(getPrimaryGroupCache_Size(), ecorePackage.getEBigInteger(), "Size", null, 0, 1, PrimaryGroupCache.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);

		initEClass(backupGroupCacheEClass, BackupGroupCache.class, "BackupGroupCache", !IS_ABSTRACT, !IS_INTERFACE, IS_GENERATED_INSTANCE_CLASS);
		initEAttribute(getBackupGroupCache_Size(), ecorePackage.getEBigInteger(), "Size", null, 0, 1, BackupGroupCache.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);

		initEClass(inputClusterEClass, InputCluster.class, "InputCluster", !IS_ABSTRACT, !IS_INTERFACE, IS_GENERATED_INSTANCE_CLASS);
		initEReference(getInputCluster_Cluster(), this.getCluster(), null, "Cluster", null, 1, 1, InputCluster.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_COMPOSITE, IS_RESOLVE_PROXIES, !IS_UNSETTABLE, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEReference(getInputCluster_RxAPDU(), this.getAPDU(), null, "RxAPDU", null, 1, 1, InputCluster.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_COMPOSITE, IS_RESOLVE_PROXIES, !IS_UNSETTABLE, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEReference(getInputCluster_EndPoint(), this.getEndPoint(), this.getEndPoint_InputClusters(), "EndPoint", null, 1, 1, InputCluster.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_COMPOSITE, !IS_RESOLVE_PROXIES, !IS_UNSETTABLE, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEAttribute(getInputCluster_Discoverable(), ecorePackage.getEBoolean(), "Discoverable", "true", 1, 1, InputCluster.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);

		initEClass(outputClusterEClass, OutputCluster.class, "OutputCluster", !IS_ABSTRACT, !IS_INTERFACE, IS_GENERATED_INSTANCE_CLASS);
		initEReference(getOutputCluster_Cluster(), this.getCluster(), null, "Cluster", null, 1, 1, OutputCluster.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_COMPOSITE, IS_RESOLVE_PROXIES, !IS_UNSETTABLE, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEReference(getOutputCluster_EndPoint(), this.getEndPoint(), this.getEndPoint_OutputClusters(), "EndPoint", null, 1, 1, OutputCluster.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_COMPOSITE, !IS_RESOLVE_PROXIES, !IS_UNSETTABLE, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEReference(getOutputCluster_TxAPDUs(), this.getAPDU(), null, "TxAPDUs", null, 0, -1, OutputCluster.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_COMPOSITE, IS_RESOLVE_PROXIES, !IS_UNSETTABLE, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEAttribute(getOutputCluster_Discoverable(), ecorePackage.getEBoolean(), "Discoverable", "true", 1, 1, OutputCluster.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);

		initEClass(alwaysOnNodeEClass, AlwaysOnNode.class, "AlwaysOnNode", IS_ABSTRACT, !IS_INTERFACE, IS_GENERATED_INSTANCE_CLASS);
		initEReference(getAlwaysOnNode_TrustCenter(), this.getTrustCenter(), null, "TrustCenter", null, 0, 1, AlwaysOnNode.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, IS_COMPOSITE, !IS_RESOLVE_PROXIES, !IS_UNSETTABLE, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEAttribute(getAlwaysOnNode_PermitJoiningTime(), ecorePackage.getEInt(), "PermitJoiningTime", "255", 1, 1, AlwaysOnNode.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEAttribute(getAlwaysOnNode_ChildTableSize(), ecorePackage.getEInt(), "ChildTableSize", "6", 1, 1, AlwaysOnNode.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);

		initEClass(complexDescriptorEClass, ComplexDescriptor.class, "ComplexDescriptor", !IS_ABSTRACT, !IS_INTERFACE, IS_GENERATED_INSTANCE_CLASS);

		initEClass(userDescriptorEClass, UserDescriptor.class, "UserDescriptor", !IS_ABSTRACT, !IS_INTERFACE, IS_GENERATED_INSTANCE_CLASS);
		initEAttribute(getUserDescriptor_UserDescription(), ecorePackage.getEString(), "UserDescription", null, 1, 1, UserDescriptor.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);

		initEClass(trustCenterEClass, TrustCenter.class, "TrustCenter", !IS_ABSTRACT, !IS_INTERFACE, IS_GENERATED_INSTANCE_CLASS);
		initEAttribute(getTrustCenter_DeviceTableSize(), ecorePackage.getEInt(), "DeviceTableSize", null, 1, 1, TrustCenter.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEReference(getTrustCenter_Keys(), this.getTCKey(), null, "Keys", null, 0, 1, TrustCenter.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, IS_COMPOSITE, !IS_RESOLVE_PROXIES, !IS_UNSETTABLE, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);

		initEClass(discoveryCacheEClass, DiscoveryCache.class, "DiscoveryCache", !IS_ABSTRACT, !IS_INTERFACE, IS_GENERATED_INSTANCE_CLASS);

		initEClass(bindingCacheEClass, BindingCache.class, "BindingCache", IS_ABSTRACT, !IS_INTERFACE, IS_GENERATED_INSTANCE_CLASS);

		initEClass(namedObjectEClass, NamedObject.class, "NamedObject", IS_ABSTRACT, !IS_INTERFACE, IS_GENERATED_INSTANCE_CLASS);
		initEAttribute(getNamedObject_Name(), ecorePackage.getEString(), "Name", null, 1, 1, NamedObject.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_UNSETTABLE, IS_ID, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);

		initEClass(childNodesEClass, ChildNodes.class, "ChildNodes", IS_ABSTRACT, !IS_INTERFACE, IS_GENERATED_INSTANCE_CLASS);
		initEAttribute(getChildNodes_ScanDuration(), ecorePackage.getEByte(), "ScanDuration", "3", 1, 1, ChildNodes.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEAttribute(getChildNodes_NetworkSelection(), this.getNetworkSelectionTypes(), "NetworkSelection", "User Selected", 1, 1, ChildNodes.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);

		initEClass(apduEClass, com.jennic.ZPSConfiguration.APDU.class, "APDU", !IS_ABSTRACT, !IS_INTERFACE, IS_GENERATED_INSTANCE_CLASS);
		initEAttribute(getAPDU_Id(), ecorePackage.getEString(), "Id", "", 1, 1, com.jennic.ZPSConfiguration.APDU.class, !IS_TRANSIENT, IS_VOLATILE, IS_CHANGEABLE, IS_UNSETTABLE, IS_ID, IS_UNIQUE, IS_DERIVED, IS_ORDERED);
		initEAttribute(getAPDU_Name(), ecorePackage.getEString(), "Name", null, 1, 1, com.jennic.ZPSConfiguration.APDU.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEAttribute(getAPDU_Size(), ecorePackage.getEInt(), "Size", "1", 1, 1, com.jennic.ZPSConfiguration.APDU.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEAttribute(getAPDU_Instances(), ecorePackage.getEInt(), "Instances", "1", 1, 1, com.jennic.ZPSConfiguration.APDU.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEReference(getAPDU_PDUConfig(), this.getPDUManager(), this.getPDUManager_APDUs(), "PDUConfig", null, 1, 1, com.jennic.ZPSConfiguration.APDU.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_COMPOSITE, !IS_RESOLVE_PROXIES, !IS_UNSETTABLE, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);

		initEClass(pduManagerEClass, PDUManager.class, "PDUManager", !IS_ABSTRACT, !IS_INTERFACE, IS_GENERATED_INSTANCE_CLASS);
		initEReference(getPDUManager_APDUs(), this.getAPDU(), this.getAPDU_PDUConfig(), "APDUs", null, 0, -1, PDUManager.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, IS_COMPOSITE, !IS_RESOLVE_PROXIES, !IS_UNSETTABLE, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEReference(getPDUManager_ContainerNode(), this.getNode(), this.getNode_PDUConfiguration(), "ContainerNode", null, 0, 1, PDUManager.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_COMPOSITE, !IS_RESOLVE_PROXIES, !IS_UNSETTABLE, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEAttribute(getPDUManager_NumNPDUs(), ecorePackage.getEInt(), "NumNPDUs", "25", 1, 1, PDUManager.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEAttribute(getPDUManager_PDUMMutexName(), ecorePackage.getEString(), "PDUMMutexName", "mutexPDUM", 1, 1, PDUManager.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);

		initEClass(channelMaskEClass, ChannelMask.class, "ChannelMask", !IS_ABSTRACT, !IS_INTERFACE, IS_GENERATED_INSTANCE_CLASS);
		initEAttribute(getChannelMask_Channel11(), ecorePackage.getEBoolean(), "Channel11", "true", 1, 1, ChannelMask.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEAttribute(getChannelMask_Channel12(), ecorePackage.getEBoolean(), "Channel12", "true", 1, 1, ChannelMask.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEAttribute(getChannelMask_Channel13(), ecorePackage.getEBoolean(), "Channel13", "true", 1, 1, ChannelMask.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEAttribute(getChannelMask_Channel14(), ecorePackage.getEBoolean(), "Channel14", "true", 1, 1, ChannelMask.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEAttribute(getChannelMask_Channel15(), ecorePackage.getEBoolean(), "Channel15", "true", 1, 1, ChannelMask.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEAttribute(getChannelMask_Channel16(), ecorePackage.getEBoolean(), "Channel16", "true", 1, 1, ChannelMask.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEAttribute(getChannelMask_Channel17(), ecorePackage.getEBoolean(), "Channel17", "true", 1, 1, ChannelMask.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEAttribute(getChannelMask_Channel18(), ecorePackage.getEBoolean(), "Channel18", "true", 1, 1, ChannelMask.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEAttribute(getChannelMask_Channel19(), ecorePackage.getEBoolean(), "Channel19", "true", 1, 1, ChannelMask.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEAttribute(getChannelMask_Channel20(), ecorePackage.getEBoolean(), "Channel20", "true", 1, 1, ChannelMask.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEAttribute(getChannelMask_Channel21(), ecorePackage.getEBoolean(), "Channel21", "true", 1, 1, ChannelMask.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEAttribute(getChannelMask_Channel22(), ecorePackage.getEBoolean(), "Channel22", "true", 1, 1, ChannelMask.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEAttribute(getChannelMask_Channel23(), ecorePackage.getEBoolean(), "Channel23", "true", 1, 1, ChannelMask.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEAttribute(getChannelMask_Channel24(), ecorePackage.getEBoolean(), "Channel24", "true", 1, 1, ChannelMask.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEAttribute(getChannelMask_Channel25(), ecorePackage.getEBoolean(), "Channel25", "true", 1, 1, ChannelMask.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEAttribute(getChannelMask_Channel26(), ecorePackage.getEBoolean(), "Channel26", "true", 1, 1, ChannelMask.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);

		initEClass(zdoClientServerEClass, ZDOClientServer.class, "ZDOClientServer", IS_ABSTRACT, !IS_INTERFACE, IS_GENERATED_INSTANCE_CLASS);
		initEReference(getZDOClientServer_OutputAPdu(), this.getAPDU(), null, "OutputAPdu", null, 1, 1, ZDOClientServer.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_COMPOSITE, IS_RESOLVE_PROXIES, !IS_UNSETTABLE, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);

		initEClass(zdoServersCoordinatorEClass, ZDOServersCoordinator.class, "ZDOServersCoordinator", !IS_ABSTRACT, !IS_INTERFACE, IS_GENERATED_INSTANCE_CLASS);
		initEReference(getZDOServersCoordinator_EndDeviceBindServer(), this.getEndDeviceBindServer(), null, "EndDeviceBindServer", null, 0, 1, ZDOServersCoordinator.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, IS_COMPOSITE, !IS_RESOLVE_PROXIES, !IS_UNSETTABLE, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);

		initEClass(zdoServersRouterEClass, ZDOServersRouter.class, "ZDOServersRouter", !IS_ABSTRACT, !IS_INTERFACE, IS_GENERATED_INSTANCE_CLASS);

		initEClass(zdoServersEndDeviceEClass, ZDOServersEndDevice.class, "ZDOServersEndDevice", !IS_ABSTRACT, !IS_INTERFACE, IS_GENERATED_INSTANCE_CLASS);

		initEClass(defaultServerEClass, DefaultServer.class, "DefaultServer", !IS_ABSTRACT, !IS_INTERFACE, IS_GENERATED_INSTANCE_CLASS);

		initEClass(endDeviceBindServerEClass, EndDeviceBindServer.class, "EndDeviceBindServer", !IS_ABSTRACT, !IS_INTERFACE, IS_GENERATED_INSTANCE_CLASS);
		initEAttribute(getEndDeviceBindServer_Timeout(), ecorePackage.getEInt(), "Timeout", "5", 1, 1, EndDeviceBindServer.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEAttribute(getEndDeviceBindServer_BindingTimeout(), ecorePackage.getEInt(), "BindingTimeout", "10", 0, 1, EndDeviceBindServer.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEAttribute(getEndDeviceBindServer_BindNumRetries(), ecorePackage.getEInt(), "BindNumRetries", "3", 1, 1, EndDeviceBindServer.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);

		initEClass(deviceAnnceServerEClass, DeviceAnnceServer.class, "DeviceAnnceServer", !IS_ABSTRACT, !IS_INTERFACE, IS_GENERATED_INSTANCE_CLASS);

		initEClass(activeEpServerEClass, ActiveEpServer.class, "ActiveEpServer", !IS_ABSTRACT, !IS_INTERFACE, IS_GENERATED_INSTANCE_CLASS);

		initEClass(nwkAddrServerEClass, NwkAddrServer.class, "NwkAddrServer", !IS_ABSTRACT, !IS_INTERFACE, IS_GENERATED_INSTANCE_CLASS);

		initEClass(ieeeAddrServerEClass, IeeeAddrServer.class, "IeeeAddrServer", !IS_ABSTRACT, !IS_INTERFACE, IS_GENERATED_INSTANCE_CLASS);

		initEClass(matchDescServerEClass, MatchDescServer.class, "MatchDescServer", !IS_ABSTRACT, !IS_INTERFACE, IS_GENERATED_INSTANCE_CLASS);

		initEClass(nodeDescServerEClass, NodeDescServer.class, "NodeDescServer", !IS_ABSTRACT, !IS_INTERFACE, IS_GENERATED_INSTANCE_CLASS);

		initEClass(permitJoiningServerEClass, PermitJoiningServer.class, "PermitJoiningServer", !IS_ABSTRACT, !IS_INTERFACE, IS_GENERATED_INSTANCE_CLASS);

		initEClass(powerDescServerEClass, PowerDescServer.class, "PowerDescServer", !IS_ABSTRACT, !IS_INTERFACE, IS_GENERATED_INSTANCE_CLASS);

		initEClass(simpleDescServerEClass, SimpleDescServer.class, "SimpleDescServer", !IS_ABSTRACT, !IS_INTERFACE, IS_GENERATED_INSTANCE_CLASS);

		initEClass(systemServerDiscoveryServerEClass, SystemServerDiscoveryServer.class, "SystemServerDiscoveryServer", !IS_ABSTRACT, !IS_INTERFACE, IS_GENERATED_INSTANCE_CLASS);

		initEClass(mgmtLqiServerEClass, MgmtLqiServer.class, "MgmtLqiServer", !IS_ABSTRACT, !IS_INTERFACE, IS_GENERATED_INSTANCE_CLASS);

		initEClass(mgmtRtgServerEClass, MgmtRtgServer.class, "MgmtRtgServer", !IS_ABSTRACT, !IS_INTERFACE, IS_GENERATED_INSTANCE_CLASS);

		initEClass(mgmtLeaveServerEClass, MgmtLeaveServer.class, "MgmtLeaveServer", !IS_ABSTRACT, !IS_INTERFACE, IS_GENERATED_INSTANCE_CLASS);

		initEClass(nodeDescriptorEClass, NodeDescriptor.class, "NodeDescriptor", !IS_ABSTRACT, !IS_INTERFACE, IS_GENERATED_INSTANCE_CLASS);
		initEAttribute(getNodeDescriptor_ManufacturerCode(), ecorePackage.getEInt(), "ManufacturerCode", "0", 1, 1, NodeDescriptor.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEAttribute(getNodeDescriptor_LogicalType(), this.getNodeLogicalType(), "LogicalType", "ZED", 1, 1, NodeDescriptor.class, !IS_TRANSIENT, IS_VOLATILE, !IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, IS_UNIQUE, IS_DERIVED, IS_ORDERED);
		initEAttribute(getNodeDescriptor_ComplexDescriptorAvailable(), ecorePackage.getEBoolean(), "ComplexDescriptorAvailable", "false", 1, 1, NodeDescriptor.class, !IS_TRANSIENT, IS_VOLATILE, !IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, IS_UNIQUE, IS_DERIVED, IS_ORDERED);
		initEAttribute(getNodeDescriptor_UserDescriptorAvailable(), ecorePackage.getEBoolean(), "UserDescriptorAvailable", "false", 1, 1, NodeDescriptor.class, !IS_TRANSIENT, IS_VOLATILE, IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, IS_UNIQUE, IS_DERIVED, IS_ORDERED);
		initEAttribute(getNodeDescriptor_APSFlags(), ecorePackage.getEBigInteger(), "APSFlags", "0", 1, 1, NodeDescriptor.class, !IS_TRANSIENT, IS_VOLATILE, !IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEAttribute(getNodeDescriptor_FrequencyBand(), this.getFrequencyBands(), "FrequencyBand", "2.4GHz", 0, 1, NodeDescriptor.class, !IS_TRANSIENT, IS_VOLATILE, !IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, IS_UNIQUE, IS_DERIVED, IS_ORDERED);
		initEAttribute(getNodeDescriptor_AlternatePANCoordinator(), ecorePackage.getEBoolean(), "AlternatePANCoordinator", "false", 1, 1, NodeDescriptor.class, !IS_TRANSIENT, IS_VOLATILE, !IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, IS_UNIQUE, IS_DERIVED, IS_ORDERED);
		initEAttribute(getNodeDescriptor_DeviceType(), ecorePackage.getEBoolean(), "DeviceType", "false", 1, 1, NodeDescriptor.class, !IS_TRANSIENT, IS_VOLATILE, !IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, IS_UNIQUE, IS_DERIVED, IS_ORDERED);
		initEAttribute(getNodeDescriptor_PowerSource(), ecorePackage.getEBoolean(), "PowerSource", "false", 1, 1, NodeDescriptor.class, !IS_TRANSIENT, IS_VOLATILE, !IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, IS_UNIQUE, IS_DERIVED, IS_ORDERED);
		initEAttribute(getNodeDescriptor_RxOnWhenIdle(), ecorePackage.getEBoolean(), "RxOnWhenIdle", "true", 1, 1, NodeDescriptor.class, !IS_TRANSIENT, IS_VOLATILE, !IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, IS_UNIQUE, IS_DERIVED, IS_ORDERED);
		initEAttribute(getNodeDescriptor_Security(), ecorePackage.getEBoolean(), "Security", "false", 1, 1, NodeDescriptor.class, !IS_TRANSIENT, IS_VOLATILE, !IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, IS_UNIQUE, IS_DERIVED, IS_ORDERED);
		initEAttribute(getNodeDescriptor_AllocateAddress(), ecorePackage.getEBoolean(), "AllocateAddress", "true", 1, 1, NodeDescriptor.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEAttribute(getNodeDescriptor_MaximumBufferSize(), ecorePackage.getEBigInteger(), "MaximumBufferSize", "127", 1, 1, NodeDescriptor.class, !IS_TRANSIENT, !IS_VOLATILE, !IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEAttribute(getNodeDescriptor_MaximumIncomingTransferSize(), ecorePackage.getEInt(), "MaximumIncomingTransferSize", "0", 1, 1, NodeDescriptor.class, !IS_TRANSIENT, IS_VOLATILE, !IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, IS_UNIQUE, IS_DERIVED, IS_ORDERED);
		initEAttribute(getNodeDescriptor_MaximumOutgoingTransferSize(), ecorePackage.getEInt(), "MaximumOutgoingTransferSize", "0", 1, 1, NodeDescriptor.class, !IS_TRANSIENT, IS_VOLATILE, !IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, IS_UNIQUE, IS_DERIVED, IS_ORDERED);
		initEAttribute(getNodeDescriptor_ExtendedActiveEndpointListAvailable(), ecorePackage.getEBoolean(), "ExtendedActiveEndpointListAvailable", "false", 1, 1, NodeDescriptor.class, !IS_TRANSIENT, IS_VOLATILE, !IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, IS_UNIQUE, IS_DERIVED, IS_ORDERED);
		initEAttribute(getNodeDescriptor_ExtendedSimpleDescriptorListAvailable(), ecorePackage.getEBoolean(), "ExtendedSimpleDescriptorListAvailable", "false", 1, 1, NodeDescriptor.class, !IS_TRANSIENT, IS_VOLATILE, !IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, IS_UNIQUE, IS_DERIVED, IS_ORDERED);
		initEAttribute(getNodeDescriptor_PrimaryTrustCenter(), ecorePackage.getEBoolean(), "PrimaryTrustCenter", "false", 1, 1, NodeDescriptor.class, !IS_TRANSIENT, IS_VOLATILE, !IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, IS_UNIQUE, IS_DERIVED, IS_ORDERED);
		initEAttribute(getNodeDescriptor_BackupTrustCenter(), ecorePackage.getEBoolean(), "BackupTrustCenter", "false", 1, 1, NodeDescriptor.class, !IS_TRANSIENT, IS_VOLATILE, !IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEAttribute(getNodeDescriptor_PrimaryBindingTableCache(), ecorePackage.getEBoolean(), "PrimaryBindingTableCache", "false", 1, 1, NodeDescriptor.class, !IS_TRANSIENT, IS_VOLATILE, !IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, IS_UNIQUE, IS_DERIVED, IS_ORDERED);
		initEAttribute(getNodeDescriptor_BackupBindingTableCache(), ecorePackage.getEBoolean(), "BackupBindingTableCache", "false", 1, 1, NodeDescriptor.class, !IS_TRANSIENT, IS_VOLATILE, !IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, IS_UNIQUE, IS_DERIVED, IS_ORDERED);
		initEAttribute(getNodeDescriptor_PrimaryDiscoveryCache(), ecorePackage.getEBoolean(), "PrimaryDiscoveryCache", "false", 1, 1, NodeDescriptor.class, !IS_TRANSIENT, IS_VOLATILE, !IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, IS_UNIQUE, IS_DERIVED, IS_ORDERED);
		initEAttribute(getNodeDescriptor_BackupDiscoveryCache(), ecorePackage.getEBoolean(), "BackupDiscoveryCache", "false", 1, 1, NodeDescriptor.class, !IS_TRANSIENT, IS_VOLATILE, !IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, IS_UNIQUE, IS_DERIVED, IS_ORDERED);
		initEReference(getNodeDescriptor_Node(), this.getNode(), this.getNode_NodeDescriptor(), "Node", null, 0, 1, NodeDescriptor.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_COMPOSITE, !IS_RESOLVE_PROXIES, !IS_UNSETTABLE, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEAttribute(getNodeDescriptor_NetworkManager(), ecorePackage.getEBoolean(), "NetworkManager", "false", 1, 1, NodeDescriptor.class, !IS_TRANSIENT, IS_VOLATILE, !IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, IS_UNIQUE, IS_DERIVED, IS_ORDERED);

		initEClass(nodePowerDescriptorEClass, NodePowerDescriptor.class, "NodePowerDescriptor", !IS_ABSTRACT, !IS_INTERFACE, IS_GENERATED_INSTANCE_CLASS);
		initEAttribute(getNodePowerDescriptor_ConstantPower(), ecorePackage.getEBoolean(), "ConstantPower", "true", 1, 1, NodePowerDescriptor.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEAttribute(getNodePowerDescriptor_RechargeableBattery(), ecorePackage.getEBoolean(), "RechargeableBattery", "false", 1, 1, NodePowerDescriptor.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEAttribute(getNodePowerDescriptor_DisposableBattery(), ecorePackage.getEBoolean(), "DisposableBattery", "false", 1, 1, NodePowerDescriptor.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEAttribute(getNodePowerDescriptor_DefaultPowerSource(), this.getPowerSources(), "DefaultPowerSource", "Constant Power", 1, 1, NodePowerDescriptor.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEAttribute(getNodePowerDescriptor_DefaultPowerMode(), this.getPowerModes(), "DefaultPowerMode", "Synchronised with RxOnWhenIdle", 1, 1, NodePowerDescriptor.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);

		initEClass(bindUnbindServerEClass, BindUnbindServer.class, "BindUnbindServer", !IS_ABSTRACT, !IS_INTERFACE, IS_GENERATED_INSTANCE_CLASS);

		initEClass(mgmtBindServerEClass, MgmtBindServer.class, "MgmtBindServer", !IS_ABSTRACT, !IS_INTERFACE, IS_GENERATED_INSTANCE_CLASS);

		initEClass(extendedActiveEpServerEClass, ExtendedActiveEpServer.class, "ExtendedActiveEpServer", !IS_ABSTRACT, !IS_INTERFACE, IS_GENERATED_INSTANCE_CLASS);

		initEClass(extendedSimpleDescServerEClass, ExtendedSimpleDescServer.class, "ExtendedSimpleDescServer", !IS_ABSTRACT, !IS_INTERFACE, IS_GENERATED_INSTANCE_CLASS);

		initEClass(zdoClientEClass, ZdoClient.class, "ZdoClient", !IS_ABSTRACT, !IS_INTERFACE, IS_GENERATED_INSTANCE_CLASS);

		initEClass(mgmtNWKUpdateServerEClass, MgmtNWKUpdateServer.class, "MgmtNWKUpdateServer", !IS_ABSTRACT, !IS_INTERFACE, IS_GENERATED_INSTANCE_CLASS);

		initEClass(zdoCommonServersEClass, ZDOCommonServers.class, "ZDOCommonServers", IS_ABSTRACT, !IS_INTERFACE, IS_GENERATED_INSTANCE_CLASS);
		initEReference(getZDOCommonServers_DefaultServer(), this.getDefaultServer(), null, "DefaultServer", null, 1, 1, ZDOCommonServers.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, IS_COMPOSITE, !IS_RESOLVE_PROXIES, !IS_UNSETTABLE, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEReference(getZDOCommonServers_ZdoClient(), this.getZdoClient(), null, "ZdoClient", null, 1, 1, ZDOCommonServers.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, IS_COMPOSITE, !IS_RESOLVE_PROXIES, !IS_UNSETTABLE, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEReference(getZDOCommonServers_DeviceAnnceServer(), this.getDeviceAnnceServer(), null, "DeviceAnnceServer", null, 0, 1, ZDOCommonServers.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, IS_COMPOSITE, !IS_RESOLVE_PROXIES, !IS_UNSETTABLE, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEReference(getZDOCommonServers_ActiveEpServer(), this.getActiveEpServer(), null, "ActiveEpServer", null, 0, 1, ZDOCommonServers.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, IS_COMPOSITE, !IS_RESOLVE_PROXIES, !IS_UNSETTABLE, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEReference(getZDOCommonServers_NwkAddrServer(), this.getNwkAddrServer(), null, "NwkAddrServer", null, 0, 1, ZDOCommonServers.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, IS_COMPOSITE, !IS_RESOLVE_PROXIES, !IS_UNSETTABLE, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEReference(getZDOCommonServers_IeeeAddrServer(), this.getIeeeAddrServer(), null, "IeeeAddrServer", null, 0, 1, ZDOCommonServers.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, IS_COMPOSITE, !IS_RESOLVE_PROXIES, !IS_UNSETTABLE, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEReference(getZDOCommonServers_SystemServerDiscoveryServer(), this.getSystemServerDiscoveryServer(), null, "SystemServerDiscoveryServer", null, 0, 1, ZDOCommonServers.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, IS_COMPOSITE, !IS_RESOLVE_PROXIES, !IS_UNSETTABLE, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEReference(getZDOCommonServers_NodeDescServer(), this.getNodeDescServer(), null, "NodeDescServer", null, 0, 1, ZDOCommonServers.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, IS_COMPOSITE, !IS_RESOLVE_PROXIES, !IS_UNSETTABLE, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEReference(getZDOCommonServers_PowerDescServer(), this.getPowerDescServer(), null, "PowerDescServer", null, 0, 1, ZDOCommonServers.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, IS_COMPOSITE, !IS_RESOLVE_PROXIES, !IS_UNSETTABLE, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEReference(getZDOCommonServers_MatchDescServer(), this.getMatchDescServer(), null, "MatchDescServer", null, 0, 1, ZDOCommonServers.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, IS_COMPOSITE, !IS_RESOLVE_PROXIES, !IS_UNSETTABLE, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEReference(getZDOCommonServers_SimpleDescServer(), this.getSimpleDescServer(), null, "SimpleDescServer", null, 0, 1, ZDOCommonServers.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, IS_COMPOSITE, !IS_RESOLVE_PROXIES, !IS_UNSETTABLE, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEReference(getZDOCommonServers_MgmtLqiServer(), this.getMgmtLqiServer(), null, "MgmtLqiServer", null, 0, 1, ZDOCommonServers.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, IS_COMPOSITE, !IS_RESOLVE_PROXIES, !IS_UNSETTABLE, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEReference(getZDOCommonServers_MgmtLeaveServer(), this.getMgmtLeaveServer(), null, "MgmtLeaveServer", null, 0, 1, ZDOCommonServers.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, IS_COMPOSITE, !IS_RESOLVE_PROXIES, !IS_UNSETTABLE, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEReference(getZDOCommonServers_MgmtNWKUpdateServer(), this.getMgmtNWKUpdateServer(), null, "MgmtNWKUpdateServer", null, 0, 1, ZDOCommonServers.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, IS_COMPOSITE, !IS_RESOLVE_PROXIES, !IS_UNSETTABLE, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEReference(getZDOCommonServers_BindUnbindServer(), this.getBindUnbindServer(), null, "BindUnbindServer", null, 0, 1, ZDOCommonServers.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, IS_COMPOSITE, !IS_RESOLVE_PROXIES, !IS_UNSETTABLE, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEReference(getZDOCommonServers_ExtendedActiveEpServer(), this.getExtendedActiveEpServer(), null, "ExtendedActiveEpServer", null, 0, 1, ZDOCommonServers.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, IS_COMPOSITE, !IS_RESOLVE_PROXIES, !IS_UNSETTABLE, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEReference(getZDOCommonServers_ExtendedSimpleDescServer(), this.getExtendedSimpleDescServer(), null, "ExtendedSimpleDescServer", null, 0, 1, ZDOCommonServers.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, IS_COMPOSITE, !IS_RESOLVE_PROXIES, !IS_UNSETTABLE, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEReference(getZDOCommonServers_BindRequestServer(), this.getBindRequestServer(), null, "BindRequestServer", null, 1, 1, ZDOCommonServers.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, IS_COMPOSITE, !IS_RESOLVE_PROXIES, !IS_UNSETTABLE, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEReference(getZDOCommonServers_MgmtBindServer(), this.getMgmtBindServer(), null, "MgmtBindServer", null, 0, 1, ZDOCommonServers.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, IS_COMPOSITE, !IS_RESOLVE_PROXIES, !IS_UNSETTABLE, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEReference(getZDOCommonServers_MgmtNWKEnhanceUpdateServer(), this.getMgmtNWKEnhanceUpdateServer(), null, "MgmtNWKEnhanceUpdateServer", null, 0, 1, ZDOCommonServers.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, IS_COMPOSITE, !IS_RESOLVE_PROXIES, !IS_UNSETTABLE, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);

		initEClass(notImplementedEClass, NotImplemented.class, "NotImplemented", !IS_ABSTRACT, !IS_INTERFACE, IS_GENERATED_INSTANCE_CLASS);
		initEReference(getNotImplemented_ComplexDescriptor(), this.getComplexDescriptor(), null, "ComplexDescriptor", null, 0, 1, NotImplemented.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, IS_COMPOSITE, !IS_RESOLVE_PROXIES, !IS_UNSETTABLE, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEReference(getNotImplemented_DiscoveryTable(), this.getDiscoveryTable(), null, "DiscoveryTable", null, 0, 1, NotImplemented.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, IS_COMPOSITE, !IS_RESOLVE_PROXIES, !IS_UNSETTABLE, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEReference(getNotImplemented_DiscoveryCache(), this.getDiscoveryCache(), null, "DiscoveryCache", null, 0, 1, NotImplemented.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, IS_COMPOSITE, !IS_RESOLVE_PROXIES, !IS_UNSETTABLE, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEReference(getNotImplemented_BindingCache(), this.getBindingCache(), null, "BindingCache", null, 0, 1, NotImplemented.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, IS_COMPOSITE, !IS_RESOLVE_PROXIES, !IS_UNSETTABLE, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);

		initEClass(keyDescriptorTableEClass, KeyDescriptorTable.class, "KeyDescriptorTable", !IS_ABSTRACT, !IS_INTERFACE, IS_GENERATED_INSTANCE_CLASS);
		initEAttribute(getKeyDescriptorTable_Size(), ecorePackage.getEInt(), "Size", "8", 1, 1, KeyDescriptorTable.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEReference(getKeyDescriptorTable_PreconfiguredKey(), this.getPreconfiguredKey(), null, "PreconfiguredKey", null, 0, -1, KeyDescriptorTable.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, IS_COMPOSITE, !IS_RESOLVE_PROXIES, !IS_UNSETTABLE, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);

		initEClass(preconfiguredKeyEClass, PreconfiguredKey.class, "PreconfiguredKey", !IS_ABSTRACT, !IS_INTERFACE, IS_GENERATED_INSTANCE_CLASS);
		initEAttribute(getPreconfiguredKey_Key(), this.getESecKey(), "Key", "0", 1, 1, PreconfiguredKey.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEAttribute(getPreconfiguredKey_IEEEAddress(), this.getEExtPANId(), "IEEEAddress", "0", 1, 1, PreconfiguredKey.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);

		initEClass(zdoCoordRouterOnlyServersEClass, ZDOCoordRouterOnlyServers.class, "ZDOCoordRouterOnlyServers", IS_ABSTRACT, !IS_INTERFACE, IS_GENERATED_INSTANCE_CLASS);
		initEReference(getZDOCoordRouterOnlyServers_PermitJoiningServer(), this.getPermitJoiningServer(), null, "PermitJoiningServer", null, 0, 1, ZDOCoordRouterOnlyServers.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, IS_COMPOSITE, !IS_RESOLVE_PROXIES, !IS_UNSETTABLE, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEReference(getZDOCoordRouterOnlyServers_MgmtRtgServer(), this.getMgmtRtgServer(), null, "MgmtRtgServer", null, 0, 1, ZDOCoordRouterOnlyServers.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, IS_COMPOSITE, !IS_RESOLVE_PROXIES, !IS_UNSETTABLE, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEReference(getZDOCoordRouterOnlyServers_MgmtMibIeeeServer(), this.getMgmtMibIeeeServer(), null, "MgmtMibIeeeServer", null, 0, 1, ZDOCoordRouterOnlyServers.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, IS_COMPOSITE, !IS_RESOLVE_PROXIES, !IS_UNSETTABLE, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEReference(getZDOCoordRouterOnlyServers_ParentAnnceServer(), this.getParentAnnceServer(), null, "ParentAnnceServer", null, 0, 1, ZDOCoordRouterOnlyServers.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, IS_COMPOSITE, !IS_RESOLVE_PROXIES, !IS_UNSETTABLE, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);

		initEClass(preConfiguredNwkKeyEClass, PreConfiguredNwkKey.class, "PreConfiguredNwkKey", !IS_ABSTRACT, !IS_INTERFACE, IS_GENERATED_INSTANCE_CLASS);

		initEClass(defaultNwkKeyEClass, DefaultNwkKey.class, "DefaultNwkKey", !IS_ABSTRACT, !IS_INTERFACE, IS_GENERATED_INSTANCE_CLASS);
		initEAttribute(getDefaultNwkKey_Random(), ecorePackage.getEBoolean(), "Random", "true", 1, 1, DefaultNwkKey.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);

		initEClass(nwkKeyEClass, NwkKey.class, "NwkKey", IS_ABSTRACT, !IS_INTERFACE, IS_GENERATED_INSTANCE_CLASS);
		initEAttribute(getNwkKey_KeySequenceNumber(), ecorePackage.getEInt(), "KeySequenceNumber", "1", 1, 1, NwkKey.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEAttribute(getNwkKey_Key(), this.getESecKey(), "Key", "0", 1, 1, NwkKey.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEAttribute(getNwkKey_Id(), ecorePackage.getEString(), "Id", null, 1, 1, NwkKey.class, !IS_TRANSIENT, IS_VOLATILE, IS_CHANGEABLE, IS_UNSETTABLE, IS_ID, IS_UNIQUE, IS_DERIVED, IS_ORDERED);

		initEClass(preconfiguredTCLinkKeyEClass, PreconfiguredTCLinkKey.class, "PreconfiguredTCLinkKey", !IS_ABSTRACT, !IS_INTERFACE, IS_GENERATED_INSTANCE_CLASS);
		initEAttribute(getPreconfiguredTCLinkKey_Id(), ecorePackage.getEString(), "Id", null, 1, 1, PreconfiguredTCLinkKey.class, !IS_TRANSIENT, IS_VOLATILE, IS_CHANGEABLE, IS_UNSETTABLE, IS_ID, IS_UNIQUE, IS_DERIVED, IS_ORDERED);

		initEClass(tcKeyEClass, TCKey.class, "TCKey", IS_ABSTRACT, !IS_INTERFACE, IS_GENERATED_INSTANCE_CLASS);

		initEClass(bindRequestServerEClass, BindRequestServer.class, "BindRequestServer", !IS_ABSTRACT, !IS_INTERFACE, IS_GENERATED_INSTANCE_CLASS);
		initEAttribute(getBindRequestServer_SimultaneousRequests(), this.getEUShort(), "SimultaneousRequests", "3", 1, 1, BindRequestServer.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEAttribute(getBindRequestServer_TimeInterval(), this.getEUShort(), "TimeInterval", "1", 1, 1, BindRequestServer.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);

		initEClass(greenPowerSecurityTableEClass, GreenPowerSecurityTable.class, "GreenPowerSecurityTable", !IS_ABSTRACT, !IS_INTERFACE, IS_GENERATED_INSTANCE_CLASS);
		initEAttribute(getGreenPowerSecurityTable_Size(), ecorePackage.getEInt(), "Size", "5", 0, 1, GreenPowerSecurityTable.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);

		initEClass(greenPowerTxQueueEClass, GreenPowerTxQueue.class, "GreenPowerTxQueue", !IS_ABSTRACT, !IS_INTERFACE, IS_GENERATED_INSTANCE_CLASS);
		initEAttribute(getGreenPowerTxQueue_Size(), ecorePackage.getEInt(), "Size", "5", 0, 1, GreenPowerTxQueue.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);

		initEClass(mgmtMibIeeeServerEClass, MgmtMibIeeeServer.class, "MgmtMibIeeeServer", !IS_ABSTRACT, !IS_INTERFACE, IS_GENERATED_INSTANCE_CLASS);

		initEClass(parentAnnceServerEClass, ParentAnnceServer.class, "ParentAnnceServer", !IS_ABSTRACT, !IS_INTERFACE, IS_GENERATED_INSTANCE_CLASS);

		initEClass(mgmtNWKEnhanceUpdateServerEClass, MgmtNWKEnhanceUpdateServer.class, "MgmtNWKEnhanceUpdateServer", !IS_ABSTRACT, !IS_INTERFACE, IS_GENERATED_INSTANCE_CLASS);

		initEClass(macInterfaceListEClass, MacInterfaceList.class, "MacInterfaceList", !IS_ABSTRACT, !IS_INTERFACE, IS_GENERATED_INSTANCE_CLASS);
		initEReference(getMacInterfaceList_MacInterface(), this.getMacInterface(), null, "MacInterface", null, 0, -1, MacInterfaceList.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, IS_COMPOSITE, !IS_RESOLVE_PROXIES, !IS_UNSETTABLE, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);

		initEClass(macInterfaceEClass, MacInterface.class, "MacInterface", !IS_ABSTRACT, !IS_INTERFACE, IS_GENERATED_INSTANCE_CLASS);
		initEAttribute(getMacInterface_RouterAllowed(), ecorePackage.getEBoolean(), "RouterAllowed", null, 1, 1, MacInterface.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEAttribute(getMacInterface_ChannelListSize(), ecorePackage.getEInt(), "ChannelListSize", "1", 1, 1, MacInterface.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEAttribute(getMacInterface_Index(), ecorePackage.getEShort(), "index", "0", 1, 1, MacInterface.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEAttribute(getMacInterface_RadioType(), this.getRadioType(), "RadioType", "RT2400MHz", 1, 1, MacInterface.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEAttribute(getMacInterface_Enabled(), ecorePackage.getEBoolean(), "Enabled", "true", 1, 1, MacInterface.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);

		// Initialize enums and add enum literals
		initEEnum(nodeLogicalTypeEEnum, NodeLogicalType.class, "NodeLogicalType");
		addEEnumLiteral(nodeLogicalTypeEEnum, NodeLogicalType.ZIGBEE_COORDINATOR);
		addEEnumLiteral(nodeLogicalTypeEEnum, NodeLogicalType.ZIGBEE_ROUTER);
		addEEnumLiteral(nodeLogicalTypeEEnum, NodeLogicalType.ZIGBEE_END_DEVICE);

		initEEnum(frequencyBandsEEnum, FrequencyBands.class, "FrequencyBands");
		addEEnumLiteral(frequencyBandsEEnum, FrequencyBands.FREQ868_MHZ);
		addEEnumLiteral(frequencyBandsEEnum, FrequencyBands.FREQ914_MHZ);
		addEEnumLiteral(frequencyBandsEEnum, FrequencyBands.FREQ2400_MHZ);

		initEEnum(powerSourcesEEnum, PowerSources.class, "PowerSources");
		addEEnumLiteral(powerSourcesEEnum, PowerSources.CONSTANT_POWER);
		addEEnumLiteral(powerSourcesEEnum, PowerSources.RECHARGEABLE_BATTERY);
		addEEnumLiteral(powerSourcesEEnum, PowerSources.DISPOSABLE_BATTERY);

		initEEnum(powerModesEEnum, PowerModes.class, "PowerModes");
		addEEnumLiteral(powerModesEEnum, PowerModes.RX_ON_WHEN_IDLE_SYNC);
		addEEnumLiteral(powerModesEEnum, PowerModes.PERIODIC);
		addEEnumLiteral(powerModesEEnum, PowerModes.STIMULATED);

		initEEnum(networkSelectionTypesEEnum, NetworkSelectionTypes.class, "NetworkSelectionTypes");
		addEEnumLiteral(networkSelectionTypesEEnum, NetworkSelectionTypes.USER);
		addEEnumLiteral(networkSelectionTypesEEnum, NetworkSelectionTypes.AUTOMATIC);

		initEEnum(radioTypeEEnum, RadioType.class, "RadioType");
		addEEnumLiteral(radioTypeEEnum, RadioType.RT2400M_HZ);
		addEEnumLiteral(radioTypeEEnum, RadioType.RT868M_HZ);
		addEEnumLiteral(radioTypeEEnum, RadioType.RT915M_HZ);

		// Initialize data types
		initEDataType(euShortEDataType, Integer.class, "EUShort", IS_SERIALIZABLE, !IS_GENERATED_INSTANCE_CLASS);
		initEDataType(eExtPANIdEDataType, BigInteger.class, "EExtPANId", IS_SERIALIZABLE, !IS_GENERATED_INSTANCE_CLASS);
		initEDataType(ePermitJoiningEDataType, Integer.class, "EPermitJoining", IS_SERIALIZABLE, !IS_GENERATED_INSTANCE_CLASS);
		initEDataType(eSecKeyEDataType, BigInteger.class, "ESecKey", IS_SERIALIZABLE, !IS_GENERATED_INSTANCE_CLASS);

		// Create resource
		createResource(eNS_URI);

		// Create annotations
		// http:///org/eclipse/emf/ecore/util/ExtendedMetaData
		createExtendedMetaDataAnnotations();
		// http://jennic.com/hexdec
		createHexdecAnnotations();
		// http://jennic.com/internal
		createInternalAnnotations();
		// http:///com/jennic/zpsconfig
		createZpsconfigAnnotations();
		// OCL
		createOCLAnnotations();
	}

	/**
	 * Initializes the annotations for <b>http:///com/jennic/zpsconfig</b>.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	protected void createZpsconfigAnnotations() {
		String source = "http:///com/jennic/zpsconfig";	
		addAnnotation
		  (getNode_ApsNonMemberRadius(), 
		   source, 
		   new String[] {
			 "propertyClass", "Jennic,Standard,Advanced"
		   });
	}

	/**
	 * Initializes the annotations for <b>http:///org/eclipse/emf/ecore/util/ExtendedMetaData</b>.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	protected void createExtendedMetaDataAnnotations() {
		String source = "http:///org/eclipse/emf/ecore/util/ExtendedMetaData";	
		addAnnotation
		  (this, 
		   source, 
		   new String[] {
			 "elementFormDefault", "qualified"
		   });	
		addAnnotation
		  (getNode_MACMutexName(), 
		   source, 
		   new String[] {
			 "namespace", "zpscfg",
			 "name", "MACMutexName",
			 "kind", "attribute"
		   });	
		addAnnotation
		  (getNode_ZPSMutexName(), 
		   source, 
		   new String[] {
			 "namespace", "##targetNamespace",
			 "kind", "attribute"
		   });	
		addAnnotation
		  (getNode_FragmentationMaxNumSimulRx(), 
		   source, 
		   new String[] {
			 "namespace", "##targetNamespace",
			 "kind", "attribute"
		   });	
		addAnnotation
		  (getNode_FragmentationMaxNumSimulTx(), 
		   source, 
		   new String[] {
			 "namespace", "##targetNamespace",
			 "kind", "attribute"
		   });	
		addAnnotation
		  (getNode_DefaultEventMessageName(), 
		   source, 
		   new String[] {
			 "namespace", "##targetNamespace",
			 "kind", "attribute"
		   });	
		addAnnotation
		  (getNode_MACDcfmIndMessage(), 
		   source, 
		   new String[] {
			 "namespace", "##targetNamespace",
			 "kind", "attribute"
		   });	
		addAnnotation
		  (getNode_MACTimeEventMessage(), 
		   source, 
		   new String[] {
			 "namespace", "##targetNamespace",
			 "kind", "attribute"
		   });	
		addAnnotation
		  (getNode_ApsDesignatedCoordinator(), 
		   source, 
		   new String[] {
			 "namespace", ""
		   });	
		addAnnotation
		  (getNode_ApsMaxWindowSize(), 
		   source, 
		   new String[] {
			 "namespace", ""
		   });	
		addAnnotation
		  (getNode_ApsSecurityTimeoutPeriod(), 
		   source, 
		   new String[] {
			 "kind", "attribute"
		   });	
		addAnnotation
		  (getNode_MACMlmeDcfmIndMessage(), 
		   source, 
		   new String[] {
			 "namespace", "##targetNamespace",
			 "kind", "attribute"
		   });	
		addAnnotation
		  (getNode_MACMcpsDcfmIndMessage(), 
		   source, 
		   new String[] {
			 "namespace", "##targetNamespace",
			 "kind", "attribute"
		   });	
		addAnnotation
		  (getZigbeeWirelessNetwork_DefaultExtendedPANId(), 
		   source, 
		   new String[] {
			 "namespace", "##targetNamespace",
			 "kind", "attribute"
		   });	
		addAnnotation
		  (getInputCluster_Discoverable(), 
		   source, 
		   new String[] {
			 "namespace", ""
		   });	
		addAnnotation
		  (getPDUManager_PDUMMutexName(), 
		   source, 
		   new String[] {
			 "namespace", "##targetNamespace",
			 "kind", "attribute"
		   });
	}

	/**
	 * Initializes the annotations for <b>http://jennic.com/internal</b>.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	protected void createInternalAnnotations() {
		String source = "http://jennic.com/internal";	
		addAnnotation
		  (getNode_MACMutexName(), 
		   source, 
		   new String[] {
		   });	
		addAnnotation
		  (getNode_MACDcfmIndMessage(), 
		   source, 
		   new String[] {
		   });	
		addAnnotation
		  (getNode_MACTimeEventMessage(), 
		   source, 
		   new String[] {
		   });	
		addAnnotation
		  (getNode_MACMlmeDcfmIndMessage(), 
		   source, 
		   new String[] {
		   });	
		addAnnotation
		  (getNode_MACMcpsDcfmIndMessage(), 
		   source, 
		   new String[] {
		   });
	}

	/**
	 * Initializes the annotations for <b>http://jennic.com/hexdec</b>.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	protected void createHexdecAnnotations() {
		String source = "http://jennic.com/hexdec";	
		addAnnotation
		  (getProfile_Id(), 
		   source, 
		   new String[] {
			 "min", "0",
			 "max", "65535",
			 "hex", ""
		   });	
		addAnnotation
		  (getCluster_Id(), 
		   source, 
		   new String[] {
			 "min", "0",
			 "max", "65535",
			 "hex", ""
		   });	
		addAnnotation
		  (getNode_DiscoveryNeighbourTableSize(), 
		   source, 
		   new String[] {
			 "min", "1",
			 "max", "255"
		   });	
		addAnnotation
		  (getNode_ActiveNeighbourTableSize(), 
		   source, 
		   new String[] {
			 "min", "1",
			 "max", "255"
		   });	
		addAnnotation
		  (getNode_RouteDiscoveryTableSize(), 
		   source, 
		   new String[] {
			 "min", "1",
			 "max", "255"
		   });	
		addAnnotation
		  (getNode_RoutingTableSize(), 
		   source, 
		   new String[] {
			 "min", "1",
			 "max", "65535"
		   });	
		addAnnotation
		  (getNode_BroadcastTransactionTableSize(), 
		   source, 
		   new String[] {
			 "min", "1",
			 "max", "255"
		   });	
		addAnnotation
		  (getNode_RouteRecordTableSize(), 
		   source, 
		   new String[] {
			 "min", "1",
			 "max", "255"
		   });	
		addAnnotation
		  (getNode_AddressMapTableSize(), 
		   source, 
		   new String[] {
			 "min", "1",
			 "max", "255"
		   });	
		addAnnotation
		  (getNode_SecurityMaterialSets(), 
		   source, 
		   new String[] {
			 "min", "1",
			 "max", "255"
		   });	
		addAnnotation
		  (getNode_MaxNumSimultaneousApsdeReq(), 
		   source, 
		   new String[] {
			 "min", "1",
			 "max", "255"
		   });	
		addAnnotation
		  (getNode_MaxNumSimultaneousApsdeAckReq(), 
		   source, 
		   new String[] {
			 "min", "1",
			 "max", "255"
		   });	
		addAnnotation
		  (getNode_FragmentationMaxNumSimulRx(), 
		   source, 
		   new String[] {
			 "min", "0",
			 "max", "255"
		   });	
		addAnnotation
		  (getNode_FragmentationMaxNumSimulTx(), 
		   source, 
		   new String[] {
			 "min", "0",
			 "max", "255"
		   });	
		addAnnotation
		  (getNode_ApsNonMemberRadius(), 
		   source, 
		   new String[] {
			 "min", "0",
			 "max", "7"
		   });	
		addAnnotation
		  (getNode_ApsMaxWindowSize(), 
		   source, 
		   new String[] {
			 "min", "1",
			 "max", "8"
		   });	
		addAnnotation
		  (getNode_ApsInterframeDelay(), 
		   source, 
		   new String[] {
			 "min", "10",
			 "max", "255"
		   });	
		addAnnotation
		  (getNode_APSDuplicateTableSize(), 
		   source, 
		   new String[] {
			 "min", "1",
			 "max", "255"
		   });	
		addAnnotation
		  (getNode_ApsSecurityTimeoutPeriod(), 
		   source, 
		   new String[] {
			 "min", "1000",
			 "max", "4294967295"
		   });	
		addAnnotation
		  (getNode_ApsUseExtPANId(), 
		   source, 
		   new String[] {
			 "min", "0",
			 "max", "18446744073709551615",
			 "hex", "",
			 "hex_width", "16"
		   });	
		addAnnotation
		  (getNode_APSPersistenceTime(), 
		   source, 
		   new String[] {
			 "min", "25",
			 "max", "255"
		   });	
		addAnnotation
		  (getNode_NumAPSMESimulCommands(), 
		   source, 
		   new String[] {
			 "min", "1",
			 "max", "65535"
		   });	
		addAnnotation
		  (getNode_StackProfile(), 
		   source, 
		   new String[] {
			 "min", "0",
			 "max", "15"
		   });	
		addAnnotation
		  (getNode_NwkFcSaveCountBitShift(), 
		   source, 
		   new String[] {
			 "min", "1",
			 "max", "32"
		   });	
		addAnnotation
		  (getNode_ApsFcSaveCountBitShift(), 
		   source, 
		   new String[] {
			 "min", "1",
			 "max", "32"
		   });	
		addAnnotation
		  (getEndDevice_NumPollFailuresBeforeRejoin(), 
		   source, 
		   new String[] {
			 "min", "0",
			 "max", "255"
		   });	
		addAnnotation
		  (getEndDevice_FragmentedTxPollPeriod(), 
		   source, 
		   new String[] {
			 "min", "25",
			 "max", "255"
		   });	
		addAnnotation
		  (getEndDevice_FragmentedRxPollPeriod(), 
		   source, 
		   new String[] {
			 "min", "25",
			 "max", "255"
		   });	
		addAnnotation
		  (getEndDevice_APSPollPeriod(), 
		   source, 
		   new String[] {
			 "min", "25",
			 "max", "65535"
		   });	
		addAnnotation
		  (getEndPoint_Id(), 
		   source, 
		   new String[] {
			 "min", "1",
			 "max", "255"
		   });	
		addAnnotation
		  (getEndPoint_ApplicationDeviceId(), 
		   source, 
		   new String[] {
			 "min", "0",
			 "max", "65535"
		   });	
		addAnnotation
		  (getEndPoint_ApplicationDeviceVersion(), 
		   source, 
		   new String[] {
			 "min", "0",
			 "max", "15"
		   });	
		addAnnotation
		  (getBindingTable_Size(), 
		   source, 
		   new String[] {
			 "min", "1",
			 "max", "65535"
		   });	
		addAnnotation
		  (getGroupTable_Size(), 
		   source, 
		   new String[] {
			 "min", "1",
			 "max", "65535"
		   });	
		addAnnotation
		  (getZigbeeWirelessNetwork_DefaultExtendedPANId(), 
		   source, 
		   new String[] {
			 "hex", "",
			 "hex_width", "16",
			 "min", "0",
			 "max", "0xFFFFFFFFFFFFFFFF"
		   });	
		addAnnotation
		  (getZigbeeWirelessNetwork_MaxNumberNodes(), 
		   source, 
		   new String[] {
			 "min", "1",
			 "max", "500"
		   });	
		addAnnotation
		  (getAlwaysOnNode_PermitJoiningTime(), 
		   source, 
		   new String[] {
			 "min", "0",
			 "max", "255"
		   });	
		addAnnotation
		  (getAlwaysOnNode_ChildTableSize(), 
		   source, 
		   new String[] {
			 "min", "1",
			 "max", "48"
		   });	
		addAnnotation
		  (getTrustCenter_DeviceTableSize(), 
		   source, 
		   new String[] {
			 "min", "0",
			 "max", "65535"
		   });	
		addAnnotation
		  (getChildNodes_ScanDuration(), 
		   source, 
		   new String[] {
			 "min", "0",
			 "max", "14"
		   });	
		addAnnotation
		  (getAPDU_Size(), 
		   source, 
		   new String[] {
			 "min", "1",
			 "max", "25500"
		   });	
		addAnnotation
		  (getAPDU_Instances(), 
		   source, 
		   new String[] {
			 "min", "1",
			 "max", "65535"
		   });	
		addAnnotation
		  (getPDUManager_NumNPDUs(), 
		   source, 
		   new String[] {
			 "min", "8",
			 "max", "65535"
		   });	
		addAnnotation
		  (eExtPANIdEDataType, 
		   source, 
		   new String[] {
			 "editor", "hexdec"
		   });	
		addAnnotation
		  (getNodeDescriptor_ManufacturerCode(), 
		   source, 
		   new String[] {
			 "min", "0",
			 "max", "65535"
		   });	
		addAnnotation
		  (getKeyDescriptorTable_Size(), 
		   source, 
		   new String[] {
			 "min", "1",
			 "max", "65535"
		   });	
		addAnnotation
		  (getPreconfiguredKey_Key(), 
		   source, 
		   new String[] {
			 "hex", "",
			 "hex_width", "32"
		   });	
		addAnnotation
		  (getPreconfiguredKey_IEEEAddress(), 
		   source, 
		   new String[] {
			 "hex", "",
			 "min", "0",
			 "max", "18446744073709551615",
			 "hex_width", "16"
		   });	
		addAnnotation
		  (getNwkKey_KeySequenceNumber(), 
		   source, 
		   new String[] {
			 "min", "0",
			 "max", "255"
		   });	
		addAnnotation
		  (getNwkKey_Key(), 
		   source, 
		   new String[] {
			 "hex", "",
			 "hex_width", "32"
		   });	
		addAnnotation
		  (getGreenPowerSecurityTable_Size(), 
		   source, 
		   new String[] {
			 "min", "1",
			 "max", "65535"
		   });	
		addAnnotation
		  (getGreenPowerTxQueue_Size(), 
		   source, 
		   new String[] {
			 "min", "1",
			 "max", "65535"
		   });
	}

	/**
	 * Initializes the annotations for <b>OCL</b>.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	protected void createOCLAnnotations() {
		String source = "OCL";	
		addAnnotation
		  (getAPDU_Id(), 
		   source, 
		   new String[] {
			 "derive", ""
		   },
		   new URI[] {
			 URI.createURI(eNS_URI).appendFragment("//APDU/Id/%OCL%/@details.0")
		   });
	}

} //ZPSConfigurationPackageImpl
