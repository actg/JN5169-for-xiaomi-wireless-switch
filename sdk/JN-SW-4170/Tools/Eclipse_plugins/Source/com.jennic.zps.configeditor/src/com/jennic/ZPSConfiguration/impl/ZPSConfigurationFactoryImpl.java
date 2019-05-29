/**
 * (C) Jennic Ltd
 *
 * $Id$
 */
package com.jennic.ZPSConfiguration.impl;


import java.math.BigInteger;

import org.eclipse.emf.ecore.EClass;
import org.eclipse.emf.ecore.EDataType;
import org.eclipse.emf.ecore.EObject;
import org.eclipse.emf.ecore.EPackage;

import org.eclipse.emf.ecore.impl.EFactoryImpl;

import org.eclipse.emf.ecore.plugin.EcorePlugin;

import com.jennic.ZPSConfiguration.*;

/**
 * <!-- begin-user-doc -->
 * An implementation of the model <b>Factory</b>.
 * <!-- end-user-doc -->
 * @generated
 */
public class ZPSConfigurationFactoryImpl extends EFactoryImpl implements ZPSConfigurationFactory {
	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public static final String copyright = "(C) NXP B.V";

	/**
	 * Creates the default factory implementation.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public static ZPSConfigurationFactory init() {
		try {
			ZPSConfigurationFactory theZPSConfigurationFactory = (ZPSConfigurationFactory)EPackage.Registry.INSTANCE.getEFactory(ZPSConfigurationPackage.eNS_URI);
			if (theZPSConfigurationFactory != null) {
				return theZPSConfigurationFactory;
			}
		}
		catch (Exception exception) {
			EcorePlugin.INSTANCE.log(exception);
		}
		return new ZPSConfigurationFactoryImpl();
	}

	/**
	 * Creates an instance of the factory.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public ZPSConfigurationFactoryImpl() {
		super();
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	@Override
	public EObject create(EClass eClass) {
		switch (eClass.getClassifierID()) {
			case ZPSConfigurationPackage.PROFILE: return createProfile();
			case ZPSConfigurationPackage.CLUSTER: return createCluster();
			case ZPSConfigurationPackage.COORDINATOR: return createCoordinator();
			case ZPSConfigurationPackage.ROUTER: return createRouter();
			case ZPSConfigurationPackage.END_DEVICE: return createEndDevice();
			case ZPSConfigurationPackage.END_POINT: return createEndPoint();
			case ZPSConfigurationPackage.PRIMARY_DISCOVERY_CACHE: return createPrimaryDiscoveryCache();
			case ZPSConfigurationPackage.BACKUP_DISCOVERY_CACHE: return createBackupDiscoveryCache();
			case ZPSConfigurationPackage.DISCOVERY_TABLE: return createDiscoveryTable();
			case ZPSConfigurationPackage.BINDING_TABLE: return createBindingTable();
			case ZPSConfigurationPackage.GROUP_TABLE: return createGroupTable();
			case ZPSConfigurationPackage.ZIGBEE_WIRELESS_NETWORK: return createZigbeeWirelessNetwork();
			case ZPSConfigurationPackage.PRIMARY_BINDING_CACHE: return createPrimaryBindingCache();
			case ZPSConfigurationPackage.BACKUP_BINDING_CACHE: return createBackupBindingCache();
			case ZPSConfigurationPackage.PRIMARY_GROUP_CACHE: return createPrimaryGroupCache();
			case ZPSConfigurationPackage.BACKUP_GROUP_CACHE: return createBackupGroupCache();
			case ZPSConfigurationPackage.INPUT_CLUSTER: return createInputCluster();
			case ZPSConfigurationPackage.OUTPUT_CLUSTER: return createOutputCluster();
			case ZPSConfigurationPackage.COMPLEX_DESCRIPTOR: return createComplexDescriptor();
			case ZPSConfigurationPackage.USER_DESCRIPTOR: return createUserDescriptor();
			case ZPSConfigurationPackage.TRUST_CENTER: return createTrustCenter();
			case ZPSConfigurationPackage.DISCOVERY_CACHE: return createDiscoveryCache();
			case ZPSConfigurationPackage.APDU: return createAPDU();
			case ZPSConfigurationPackage.PDU_MANAGER: return createPDUManager();
			case ZPSConfigurationPackage.CHANNEL_MASK: return createChannelMask();
			case ZPSConfigurationPackage.ZDO_SERVERS_COORDINATOR: return createZDOServersCoordinator();
			case ZPSConfigurationPackage.ZDO_SERVERS_ROUTER: return createZDOServersRouter();
			case ZPSConfigurationPackage.ZDO_SERVERS_END_DEVICE: return createZDOServersEndDevice();
			case ZPSConfigurationPackage.DEFAULT_SERVER: return createDefaultServer();
			case ZPSConfigurationPackage.END_DEVICE_BIND_SERVER: return createEndDeviceBindServer();
			case ZPSConfigurationPackage.DEVICE_ANNCE_SERVER: return createDeviceAnnceServer();
			case ZPSConfigurationPackage.ACTIVE_EP_SERVER: return createActiveEpServer();
			case ZPSConfigurationPackage.NWK_ADDR_SERVER: return createNwkAddrServer();
			case ZPSConfigurationPackage.IEEE_ADDR_SERVER: return createIeeeAddrServer();
			case ZPSConfigurationPackage.MATCH_DESC_SERVER: return createMatchDescServer();
			case ZPSConfigurationPackage.NODE_DESC_SERVER: return createNodeDescServer();
			case ZPSConfigurationPackage.PERMIT_JOINING_SERVER: return createPermitJoiningServer();
			case ZPSConfigurationPackage.POWER_DESC_SERVER: return createPowerDescServer();
			case ZPSConfigurationPackage.SIMPLE_DESC_SERVER: return createSimpleDescServer();
			case ZPSConfigurationPackage.SYSTEM_SERVER_DISCOVERY_SERVER: return createSystemServerDiscoveryServer();
			case ZPSConfigurationPackage.MGMT_LQI_SERVER: return createMgmtLqiServer();
			case ZPSConfigurationPackage.MGMT_RTG_SERVER: return createMgmtRtgServer();
			case ZPSConfigurationPackage.MGMT_LEAVE_SERVER: return createMgmtLeaveServer();
			case ZPSConfigurationPackage.NODE_DESCRIPTOR: return createNodeDescriptor();
			case ZPSConfigurationPackage.NODE_POWER_DESCRIPTOR: return createNodePowerDescriptor();
			case ZPSConfigurationPackage.BIND_UNBIND_SERVER: return createBindUnbindServer();
			case ZPSConfigurationPackage.MGMT_BIND_SERVER: return createMgmtBindServer();
			case ZPSConfigurationPackage.EXTENDED_ACTIVE_EP_SERVER: return createExtendedActiveEpServer();
			case ZPSConfigurationPackage.EXTENDED_SIMPLE_DESC_SERVER: return createExtendedSimpleDescServer();
			case ZPSConfigurationPackage.ZDO_CLIENT: return createZdoClient();
			case ZPSConfigurationPackage.MGMT_NWK_UPDATE_SERVER: return createMgmtNWKUpdateServer();
			case ZPSConfigurationPackage.NOT_IMPLEMENTED: return createNotImplemented();
			case ZPSConfigurationPackage.KEY_DESCRIPTOR_TABLE: return createKeyDescriptorTable();
			case ZPSConfigurationPackage.PRECONFIGURED_KEY: return createPreconfiguredKey();
			case ZPSConfigurationPackage.PRE_CONFIGURED_NWK_KEY: return createPreConfiguredNwkKey();
			case ZPSConfigurationPackage.DEFAULT_NWK_KEY: return createDefaultNwkKey();
			case ZPSConfigurationPackage.PRECONFIGURED_TC_LINK_KEY: return createPreconfiguredTCLinkKey();
			case ZPSConfigurationPackage.BIND_REQUEST_SERVER: return createBindRequestServer();
			case ZPSConfigurationPackage.GREEN_POWER_SECURITY_TABLE: return createGreenPowerSecurityTable();
			case ZPSConfigurationPackage.GREEN_POWER_TX_QUEUE: return createGreenPowerTxQueue();
			case ZPSConfigurationPackage.MGMT_MIB_IEEE_SERVER: return createMgmtMibIeeeServer();
			case ZPSConfigurationPackage.PARENT_ANNCE_SERVER: return createParentAnnceServer();
			case ZPSConfigurationPackage.MGMT_NWK_ENHANCE_UPDATE_SERVER: return createMgmtNWKEnhanceUpdateServer();
			case ZPSConfigurationPackage.MAC_INTERFACE_LIST: return createMacInterfaceList();
			case ZPSConfigurationPackage.MAC_INTERFACE: return createMacInterface();
			default:
				throw new IllegalArgumentException("The class '" + eClass.getName() + "' is not a valid classifier");
		}
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	@Override
	public Object createFromString(EDataType eDataType, String initialValue) {
		switch (eDataType.getClassifierID()) {
			case ZPSConfigurationPackage.NODE_LOGICAL_TYPE:
				return createNodeLogicalTypeFromString(eDataType, initialValue);
			case ZPSConfigurationPackage.FREQUENCY_BANDS:
				return createFrequencyBandsFromString(eDataType, initialValue);
			case ZPSConfigurationPackage.POWER_SOURCES:
				return createPowerSourcesFromString(eDataType, initialValue);
			case ZPSConfigurationPackage.POWER_MODES:
				return createPowerModesFromString(eDataType, initialValue);
			case ZPSConfigurationPackage.NETWORK_SELECTION_TYPES:
				return createNetworkSelectionTypesFromString(eDataType, initialValue);
			case ZPSConfigurationPackage.RADIO_TYPE:
				return createRadioTypeFromString(eDataType, initialValue);
			case ZPSConfigurationPackage.EU_SHORT:
				return createEUShortFromString(eDataType, initialValue);
			case ZPSConfigurationPackage.EEXT_PAN_ID:
				return createEExtPANIdFromString(eDataType, initialValue);
			case ZPSConfigurationPackage.EPERMIT_JOINING:
				return createEPermitJoiningFromString(eDataType, initialValue);
			case ZPSConfigurationPackage.ESEC_KEY:
				return createESecKeyFromString(eDataType, initialValue);
			default:
				throw new IllegalArgumentException("The datatype '" + eDataType.getName() + "' is not a valid classifier");
		}
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	@Override
	public String convertToString(EDataType eDataType, Object instanceValue) {
		switch (eDataType.getClassifierID()) {
			case ZPSConfigurationPackage.NODE_LOGICAL_TYPE:
				return convertNodeLogicalTypeToString(eDataType, instanceValue);
			case ZPSConfigurationPackage.FREQUENCY_BANDS:
				return convertFrequencyBandsToString(eDataType, instanceValue);
			case ZPSConfigurationPackage.POWER_SOURCES:
				return convertPowerSourcesToString(eDataType, instanceValue);
			case ZPSConfigurationPackage.POWER_MODES:
				return convertPowerModesToString(eDataType, instanceValue);
			case ZPSConfigurationPackage.NETWORK_SELECTION_TYPES:
				return convertNetworkSelectionTypesToString(eDataType, instanceValue);
			case ZPSConfigurationPackage.RADIO_TYPE:
				return convertRadioTypeToString(eDataType, instanceValue);
			case ZPSConfigurationPackage.EU_SHORT:
				return convertEUShortToString(eDataType, instanceValue);
			case ZPSConfigurationPackage.EEXT_PAN_ID:
				return convertEExtPANIdToString(eDataType, instanceValue);
			case ZPSConfigurationPackage.EPERMIT_JOINING:
				return convertEPermitJoiningToString(eDataType, instanceValue);
			case ZPSConfigurationPackage.ESEC_KEY:
				return convertESecKeyToString(eDataType, instanceValue);
			default:
				throw new IllegalArgumentException("The datatype '" + eDataType.getName() + "' is not a valid classifier");
		}
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public Profile createProfile() {
		ProfileImpl profile = new ProfileImpl();
		return profile;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public Cluster createCluster() {
		ClusterImpl cluster = new ClusterImpl();
		return cluster;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public Coordinator createCoordinator() {
		CoordinatorImpl coordinator = new CoordinatorImpl();
		return coordinator;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public Router createRouter() {
		RouterImpl router = new RouterImpl();
		return router;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EndDevice createEndDevice() {
		EndDeviceImpl endDevice = new EndDeviceImpl();
		return endDevice;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EndPoint createEndPoint() {
		EndPointImpl endPoint = new EndPointImpl();
		return endPoint;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public PrimaryDiscoveryCache createPrimaryDiscoveryCache() {
		PrimaryDiscoveryCacheImpl primaryDiscoveryCache = new PrimaryDiscoveryCacheImpl();
		return primaryDiscoveryCache;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public BackupDiscoveryCache createBackupDiscoveryCache() {
		BackupDiscoveryCacheImpl backupDiscoveryCache = new BackupDiscoveryCacheImpl();
		return backupDiscoveryCache;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public DiscoveryTable createDiscoveryTable() {
		DiscoveryTableImpl discoveryTable = new DiscoveryTableImpl();
		return discoveryTable;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public BindingTable createBindingTable() {
		BindingTableImpl bindingTable = new BindingTableImpl();
		return bindingTable;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public GroupTable createGroupTable() {
		GroupTableImpl groupTable = new GroupTableImpl();
		return groupTable;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public ZigbeeWirelessNetwork createZigbeeWirelessNetwork() {
		ZigbeeWirelessNetworkImpl zigbeeWirelessNetwork = new ZigbeeWirelessNetworkImpl();
		return zigbeeWirelessNetwork;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public PrimaryBindingCache createPrimaryBindingCache() {
		PrimaryBindingCacheImpl primaryBindingCache = new PrimaryBindingCacheImpl();
		return primaryBindingCache;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public BackupBindingCache createBackupBindingCache() {
		BackupBindingCacheImpl backupBindingCache = new BackupBindingCacheImpl();
		return backupBindingCache;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public PrimaryGroupCache createPrimaryGroupCache() {
		PrimaryGroupCacheImpl primaryGroupCache = new PrimaryGroupCacheImpl();
		return primaryGroupCache;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public BackupGroupCache createBackupGroupCache() {
		BackupGroupCacheImpl backupGroupCache = new BackupGroupCacheImpl();
		return backupGroupCache;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public InputCluster createInputCluster() {
		InputClusterImpl inputCluster = new InputClusterImpl();
		return inputCluster;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public OutputCluster createOutputCluster() {
		OutputClusterImpl outputCluster = new OutputClusterImpl();
		return outputCluster;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public ComplexDescriptor createComplexDescriptor() {
		ComplexDescriptorImpl complexDescriptor = new ComplexDescriptorImpl();
		return complexDescriptor;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public UserDescriptor createUserDescriptor() {
		UserDescriptorImpl userDescriptor = new UserDescriptorImpl();
		return userDescriptor;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public TrustCenter createTrustCenter() {
		TrustCenterImpl trustCenter = new TrustCenterImpl();
		return trustCenter;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public DiscoveryCache createDiscoveryCache() {
		DiscoveryCacheImpl discoveryCache = new DiscoveryCacheImpl();
		return discoveryCache;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public APDU createAPDU() {
		APDUImpl apdu = new APDUImpl();
		return apdu;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public PDUManager createPDUManager() {
		PDUManagerImpl pduManager = new PDUManagerImpl();
		return pduManager;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public ChannelMask createChannelMask() {
		ChannelMaskImpl channelMask = new ChannelMaskImpl();
		return channelMask;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public ZDOServersCoordinator createZDOServersCoordinator() {
		ZDOServersCoordinatorImpl zdoServersCoordinator = new ZDOServersCoordinatorImpl();
		return zdoServersCoordinator;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EndDeviceBindServer createEndDeviceBindServer() {
		EndDeviceBindServerImpl endDeviceBindServer = new EndDeviceBindServerImpl();
		return endDeviceBindServer;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public ZDOServersRouter createZDOServersRouter() {
		ZDOServersRouterImpl zdoServersRouter = new ZDOServersRouterImpl();
		return zdoServersRouter;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public ZDOServersEndDevice createZDOServersEndDevice() {
		ZDOServersEndDeviceImpl zdoServersEndDevice = new ZDOServersEndDeviceImpl();
		return zdoServersEndDevice;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public DefaultServer createDefaultServer() {
		DefaultServerImpl defaultServer = new DefaultServerImpl();
		return defaultServer;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public DeviceAnnceServer createDeviceAnnceServer() {
		DeviceAnnceServerImpl deviceAnnceServer = new DeviceAnnceServerImpl();
		return deviceAnnceServer;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public ActiveEpServer createActiveEpServer() {
		ActiveEpServerImpl activeEpServer = new ActiveEpServerImpl();
		return activeEpServer;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public NwkAddrServer createNwkAddrServer() {
		NwkAddrServerImpl nwkAddrServer = new NwkAddrServerImpl();
		return nwkAddrServer;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public IeeeAddrServer createIeeeAddrServer() {
		IeeeAddrServerImpl ieeeAddrServer = new IeeeAddrServerImpl();
		return ieeeAddrServer;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public MatchDescServer createMatchDescServer() {
		MatchDescServerImpl matchDescServer = new MatchDescServerImpl();
		return matchDescServer;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public NodeDescServer createNodeDescServer() {
		NodeDescServerImpl nodeDescServer = new NodeDescServerImpl();
		return nodeDescServer;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public PermitJoiningServer createPermitJoiningServer() {
		PermitJoiningServerImpl permitJoiningServer = new PermitJoiningServerImpl();
		return permitJoiningServer;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public PowerDescServer createPowerDescServer() {
		PowerDescServerImpl powerDescServer = new PowerDescServerImpl();
		return powerDescServer;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public SimpleDescServer createSimpleDescServer() {
		SimpleDescServerImpl simpleDescServer = new SimpleDescServerImpl();
		return simpleDescServer;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public SystemServerDiscoveryServer createSystemServerDiscoveryServer() {
		SystemServerDiscoveryServerImpl systemServerDiscoveryServer = new SystemServerDiscoveryServerImpl();
		return systemServerDiscoveryServer;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public MgmtLqiServer createMgmtLqiServer() {
		MgmtLqiServerImpl mgmtLqiServer = new MgmtLqiServerImpl();
		return mgmtLqiServer;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public MgmtRtgServer createMgmtRtgServer() {
		MgmtRtgServerImpl mgmtRtgServer = new MgmtRtgServerImpl();
		return mgmtRtgServer;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public MgmtLeaveServer createMgmtLeaveServer() {
		MgmtLeaveServerImpl mgmtLeaveServer = new MgmtLeaveServerImpl();
		return mgmtLeaveServer;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public NodeDescriptor createNodeDescriptor() {
		NodeDescriptorImpl nodeDescriptor = new NodeDescriptorImpl();
		return nodeDescriptor;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public NodePowerDescriptor createNodePowerDescriptor() {
		NodePowerDescriptorImpl nodePowerDescriptor = new NodePowerDescriptorImpl();
		return nodePowerDescriptor;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public BindUnbindServer createBindUnbindServer() {
		BindUnbindServerImpl bindUnbindServer = new BindUnbindServerImpl();
		return bindUnbindServer;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public MgmtBindServer createMgmtBindServer() {
		MgmtBindServerImpl mgmtBindServer = new MgmtBindServerImpl();
		return mgmtBindServer;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public ExtendedActiveEpServer createExtendedActiveEpServer() {
		ExtendedActiveEpServerImpl extendedActiveEpServer = new ExtendedActiveEpServerImpl();
		return extendedActiveEpServer;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public ExtendedSimpleDescServer createExtendedSimpleDescServer() {
		ExtendedSimpleDescServerImpl extendedSimpleDescServer = new ExtendedSimpleDescServerImpl();
		return extendedSimpleDescServer;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public ZdoClient createZdoClient() {
		ZdoClientImpl zdoClient = new ZdoClientImpl();
		return zdoClient;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public MgmtNWKUpdateServer createMgmtNWKUpdateServer() {
		MgmtNWKUpdateServerImpl mgmtNWKUpdateServer = new MgmtNWKUpdateServerImpl();
		return mgmtNWKUpdateServer;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public NotImplemented createNotImplemented() {
		NotImplementedImpl notImplemented = new NotImplementedImpl();
		return notImplemented;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public KeyDescriptorTable createKeyDescriptorTable() {
		KeyDescriptorTableImpl keyDescriptorTable = new KeyDescriptorTableImpl();
		return keyDescriptorTable;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public PreconfiguredKey createPreconfiguredKey() {
		PreconfiguredKeyImpl preconfiguredKey = new PreconfiguredKeyImpl();
		return preconfiguredKey;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public PreConfiguredNwkKey createPreConfiguredNwkKey() {
		PreConfiguredNwkKeyImpl preConfiguredNwkKey = new PreConfiguredNwkKeyImpl();
		return preConfiguredNwkKey;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public DefaultNwkKey createDefaultNwkKey() {
		DefaultNwkKeyImpl defaultNwkKey = new DefaultNwkKeyImpl();
		return defaultNwkKey;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public PreconfiguredTCLinkKey createPreconfiguredTCLinkKey() {
		PreconfiguredTCLinkKeyImpl preconfiguredTCLinkKey = new PreconfiguredTCLinkKeyImpl();
		return preconfiguredTCLinkKey;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public BindRequestServer createBindRequestServer() {
		BindRequestServerImpl bindRequestServer = new BindRequestServerImpl();
		return bindRequestServer;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public GreenPowerSecurityTable createGreenPowerSecurityTable() {
		GreenPowerSecurityTableImpl greenPowerSecurityTable = new GreenPowerSecurityTableImpl();
		return greenPowerSecurityTable;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public GreenPowerTxQueue createGreenPowerTxQueue() {
		GreenPowerTxQueueImpl greenPowerTxQueue = new GreenPowerTxQueueImpl();
		return greenPowerTxQueue;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public MgmtMibIeeeServer createMgmtMibIeeeServer() {
		MgmtMibIeeeServerImpl mgmtMibIeeeServer = new MgmtMibIeeeServerImpl();
		return mgmtMibIeeeServer;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public MgmtNWKEnhanceUpdateServer createMgmtNWKEnhanceUpdateServer() {
		MgmtNWKEnhanceUpdateServerImpl mgmtNWKEnhanceUpdateServer = new MgmtNWKEnhanceUpdateServerImpl();
		return mgmtNWKEnhanceUpdateServer;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public MacInterfaceList createMacInterfaceList() {
		MacInterfaceListImpl macInterfaceList = new MacInterfaceListImpl();
		return macInterfaceList;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public MacInterface createMacInterface() {
		MacInterfaceImpl macInterface = new MacInterfaceImpl();
		return macInterface;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public ParentAnnceServer createParentAnnceServer() {
		ParentAnnceServerImpl parentAnnceServer = new ParentAnnceServerImpl();
		return parentAnnceServer;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public NodeLogicalType createNodeLogicalTypeFromString(EDataType eDataType, String initialValue) {
		NodeLogicalType result = NodeLogicalType.get(initialValue);
		if (result == null) throw new IllegalArgumentException("The value '" + initialValue + "' is not a valid enumerator of '" + eDataType.getName() + "'");
		return result;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public String convertNodeLogicalTypeToString(EDataType eDataType, Object instanceValue) {
		return instanceValue == null ? null : instanceValue.toString();
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public FrequencyBands createFrequencyBandsFromString(EDataType eDataType, String initialValue) {
		FrequencyBands result = FrequencyBands.get(initialValue);
		if (result == null) throw new IllegalArgumentException("The value '" + initialValue + "' is not a valid enumerator of '" + eDataType.getName() + "'");
		return result;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public String convertFrequencyBandsToString(EDataType eDataType, Object instanceValue) {
		return instanceValue == null ? null : instanceValue.toString();
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public PowerSources createPowerSourcesFromString(EDataType eDataType, String initialValue) {
		PowerSources result = PowerSources.get(initialValue);
		if (result == null) throw new IllegalArgumentException("The value '" + initialValue + "' is not a valid enumerator of '" + eDataType.getName() + "'");
		return result;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public String convertPowerSourcesToString(EDataType eDataType, Object instanceValue) {
		return instanceValue == null ? null : instanceValue.toString();
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public PowerModes createPowerModesFromString(EDataType eDataType, String initialValue) {
		PowerModes result = PowerModes.get(initialValue);
		if (result == null) throw new IllegalArgumentException("The value '" + initialValue + "' is not a valid enumerator of '" + eDataType.getName() + "'");
		return result;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public String convertPowerModesToString(EDataType eDataType, Object instanceValue) {
		return instanceValue == null ? null : instanceValue.toString();
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public NetworkSelectionTypes createNetworkSelectionTypesFromString(EDataType eDataType, String initialValue) {
		NetworkSelectionTypes result = NetworkSelectionTypes.get(initialValue);
		if (result == null) throw new IllegalArgumentException("The value '" + initialValue + "' is not a valid enumerator of '" + eDataType.getName() + "'");
		return result;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public String convertNetworkSelectionTypesToString(EDataType eDataType, Object instanceValue) {
		return instanceValue == null ? null : instanceValue.toString();
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public RadioType createRadioTypeFromString(EDataType eDataType, String initialValue) {
		RadioType result = RadioType.get(initialValue);
		if (result == null) throw new IllegalArgumentException("The value '" + initialValue + "' is not a valid enumerator of '" + eDataType.getName() + "'");
		return result;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public String convertRadioTypeToString(EDataType eDataType, Object instanceValue) {
		return instanceValue == null ? null : instanceValue.toString();
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated NOT
	 */
	public Integer createEUShortFromString(EDataType eDataType, String initialValue) {
		if (initialValue.length() == 0) {
			return new Integer(0);
		} else if (initialValue.length() < 2) {
			return Integer.valueOf(initialValue);
		} else {
			if(initialValue.indexOf("0x") >= 0 || initialValue.indexOf("0X") >= 0) {
				BigInteger val = new BigInteger(initialValue.substring(2), 16);
				return val.intValue();
			} else {				
				return Integer.valueOf(initialValue);
			}
		}
//		return (Integer)super.createFromString(eDataType, initialValue);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated NOT
	 */
	public String convertEUShortToString(EDataType eDataType, Object instanceValue) {
		return "0x" + String.format("%04X", (Integer)instanceValue);
//		return super.convertToString(eDataType, instanceValue);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated NOT
	 */
	public BigInteger createEExtPANIdFromString(EDataType eDataType, String initialValue) {
		if (initialValue.length() == 0) {
			return BigInteger.ZERO;
		} else if (initialValue.length() < 2) {
			return new BigInteger(initialValue);
		} else {
			if(initialValue.indexOf("0x") >= 0 || initialValue.indexOf("0X") >= 0) {
				BigInteger val = new BigInteger(initialValue.substring(2), 16);
				return val;
			} else {				
				return new BigInteger(initialValue);
			}
		}
//		return (Long)super.createFromString(eDataType, initialValue);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated NOT
	 */
	public String convertEExtPANIdToString(EDataType eDataType, Object instanceValue) {
		return "0x" + String.format("%016X", instanceValue);
//		return super.convertToString(eDataType, instanceValue);
	}


	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public Object createEPermitJoiningFromString(EDataType eDataType, String initialValue) {
		return (Object)super.createFromString(eDataType, initialValue);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public String convertEPermitJoiningToString(EDataType eDataType, Object instanceValue) {
		return super.convertToString(eDataType, instanceValue);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated NOT
	 */
	public BigInteger createESecKeyFromString(EDataType eDataType, String initialValue) {
		if (initialValue.length() == 0) {
			return BigInteger.ZERO;
		} else if (initialValue.length() < 2) {
			return new BigInteger(initialValue);
		} else {
			if(initialValue.indexOf("0x") >= 0 || initialValue.indexOf("0X") >= 0) {
				BigInteger val = new BigInteger(initialValue.substring(2), 16);
				return val;
			} else {				
				return new BigInteger(initialValue);
			}
		}
//		return (BigInteger)super.createFromString(eDataType, initialValue);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated NOT
	 */
	public String convertESecKeyToString(EDataType eDataType, Object instanceValue) {
		return "0x" + String.format("%032X", instanceValue);
//		return super.convertToString(eDataType, instanceValue);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public ZPSConfigurationPackage getZPSConfigurationPackage() {
		return (ZPSConfigurationPackage)getEPackage();
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @deprecated
	 * @generated
	 */
	@Deprecated
	public static ZPSConfigurationPackage getPackage() {
		return ZPSConfigurationPackage.eINSTANCE;
	}

} //ZPSConfigurationFactoryImpl
