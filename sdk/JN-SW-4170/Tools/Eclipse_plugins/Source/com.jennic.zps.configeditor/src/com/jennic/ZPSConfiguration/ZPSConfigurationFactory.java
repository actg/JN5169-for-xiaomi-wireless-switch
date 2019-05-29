/**
 * (C) Jennic Ltd
 *
 * $Id$
 */
package com.jennic.ZPSConfiguration;

import org.eclipse.emf.ecore.EFactory;

/**
 * <!-- begin-user-doc -->
 * The <b>Factory</b> for the model.
 * It provides a create method for each non-abstract class of the model.
 * <!-- end-user-doc -->
 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage
 * @generated
 */
public interface ZPSConfigurationFactory extends EFactory {
	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	String copyright = "(C) NXP B.V";

	/**
	 * The singleton instance of the factory.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	ZPSConfigurationFactory eINSTANCE = com.jennic.ZPSConfiguration.impl.ZPSConfigurationFactoryImpl.init();

	/**
	 * Returns a new object of class '<em>Profile</em>'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return a new object of class '<em>Profile</em>'.
	 * @generated
	 */
	Profile createProfile();

	/**
	 * Returns a new object of class '<em>Cluster</em>'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return a new object of class '<em>Cluster</em>'.
	 * @generated
	 */
	Cluster createCluster();

	/**
	 * Returns a new object of class '<em>Coordinator</em>'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return a new object of class '<em>Coordinator</em>'.
	 * @generated
	 */
	Coordinator createCoordinator();

	/**
	 * Returns a new object of class '<em>Router</em>'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return a new object of class '<em>Router</em>'.
	 * @generated
	 */
	Router createRouter();

	/**
	 * Returns a new object of class '<em>End Device</em>'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return a new object of class '<em>End Device</em>'.
	 * @generated
	 */
	EndDevice createEndDevice();

	/**
	 * Returns a new object of class '<em>End Point</em>'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return a new object of class '<em>End Point</em>'.
	 * @generated
	 */
	EndPoint createEndPoint();

	/**
	 * Returns a new object of class '<em>Primary Discovery Cache</em>'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return a new object of class '<em>Primary Discovery Cache</em>'.
	 * @generated
	 */
	PrimaryDiscoveryCache createPrimaryDiscoveryCache();

	/**
	 * Returns a new object of class '<em>Backup Discovery Cache</em>'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return a new object of class '<em>Backup Discovery Cache</em>'.
	 * @generated
	 */
	BackupDiscoveryCache createBackupDiscoveryCache();

	/**
	 * Returns a new object of class '<em>Discovery Table</em>'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return a new object of class '<em>Discovery Table</em>'.
	 * @generated
	 */
	DiscoveryTable createDiscoveryTable();

	/**
	 * Returns a new object of class '<em>Binding Table</em>'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return a new object of class '<em>Binding Table</em>'.
	 * @generated
	 */
	BindingTable createBindingTable();

	/**
	 * Returns a new object of class '<em>Group Table</em>'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return a new object of class '<em>Group Table</em>'.
	 * @generated
	 */
	GroupTable createGroupTable();

	/**
	 * Returns a new object of class '<em>Zigbee Wireless Network</em>'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return a new object of class '<em>Zigbee Wireless Network</em>'.
	 * @generated
	 */
	ZigbeeWirelessNetwork createZigbeeWirelessNetwork();

	/**
	 * Returns a new object of class '<em>Primary Binding Cache</em>'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return a new object of class '<em>Primary Binding Cache</em>'.
	 * @generated
	 */
	PrimaryBindingCache createPrimaryBindingCache();

	/**
	 * Returns a new object of class '<em>Backup Binding Cache</em>'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return a new object of class '<em>Backup Binding Cache</em>'.
	 * @generated
	 */
	BackupBindingCache createBackupBindingCache();

	/**
	 * Returns a new object of class '<em>Primary Group Cache</em>'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return a new object of class '<em>Primary Group Cache</em>'.
	 * @generated
	 */
	PrimaryGroupCache createPrimaryGroupCache();

	/**
	 * Returns a new object of class '<em>Backup Group Cache</em>'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return a new object of class '<em>Backup Group Cache</em>'.
	 * @generated
	 */
	BackupGroupCache createBackupGroupCache();

	/**
	 * Returns a new object of class '<em>Input Cluster</em>'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return a new object of class '<em>Input Cluster</em>'.
	 * @generated
	 */
	InputCluster createInputCluster();

	/**
	 * Returns a new object of class '<em>Output Cluster</em>'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return a new object of class '<em>Output Cluster</em>'.
	 * @generated
	 */
	OutputCluster createOutputCluster();

	/**
	 * Returns a new object of class '<em>Complex Descriptor</em>'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return a new object of class '<em>Complex Descriptor</em>'.
	 * @generated
	 */
	ComplexDescriptor createComplexDescriptor();

	/**
	 * Returns a new object of class '<em>User Descriptor</em>'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return a new object of class '<em>User Descriptor</em>'.
	 * @generated
	 */
	UserDescriptor createUserDescriptor();

	/**
	 * Returns a new object of class '<em>Trust Center</em>'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return a new object of class '<em>Trust Center</em>'.
	 * @generated
	 */
	TrustCenter createTrustCenter();

	/**
	 * Returns a new object of class '<em>Discovery Cache</em>'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return a new object of class '<em>Discovery Cache</em>'.
	 * @generated
	 */
	DiscoveryCache createDiscoveryCache();

	/**
	 * Returns a new object of class '<em>APDU</em>'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return a new object of class '<em>APDU</em>'.
	 * @generated
	 */
	APDU createAPDU();

	/**
	 * Returns a new object of class '<em>PDU Manager</em>'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return a new object of class '<em>PDU Manager</em>'.
	 * @generated
	 */
	PDUManager createPDUManager();

	/**
	 * Returns a new object of class '<em>Channel Mask</em>'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return a new object of class '<em>Channel Mask</em>'.
	 * @generated
	 */
	ChannelMask createChannelMask();

	/**
	 * Returns a new object of class '<em>ZDO Servers Coordinator</em>'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return a new object of class '<em>ZDO Servers Coordinator</em>'.
	 * @generated
	 */
	ZDOServersCoordinator createZDOServersCoordinator();

	/**
	 * Returns a new object of class '<em>End Device Bind Server</em>'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return a new object of class '<em>End Device Bind Server</em>'.
	 * @generated
	 */
	EndDeviceBindServer createEndDeviceBindServer();

	/**
	 * Returns a new object of class '<em>ZDO Servers Router</em>'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return a new object of class '<em>ZDO Servers Router</em>'.
	 * @generated
	 */
	ZDOServersRouter createZDOServersRouter();

	/**
	 * Returns a new object of class '<em>ZDO Servers End Device</em>'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return a new object of class '<em>ZDO Servers End Device</em>'.
	 * @generated
	 */
	ZDOServersEndDevice createZDOServersEndDevice();

	/**
	 * Returns a new object of class '<em>Default Server</em>'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return a new object of class '<em>Default Server</em>'.
	 * @generated
	 */
	DefaultServer createDefaultServer();

	/**
	 * Returns a new object of class '<em>Device Annce Server</em>'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return a new object of class '<em>Device Annce Server</em>'.
	 * @generated
	 */
	DeviceAnnceServer createDeviceAnnceServer();

	/**
	 * Returns a new object of class '<em>Active Ep Server</em>'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return a new object of class '<em>Active Ep Server</em>'.
	 * @generated
	 */
	ActiveEpServer createActiveEpServer();

	/**
	 * Returns a new object of class '<em>Nwk Addr Server</em>'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return a new object of class '<em>Nwk Addr Server</em>'.
	 * @generated
	 */
	NwkAddrServer createNwkAddrServer();

	/**
	 * Returns a new object of class '<em>Ieee Addr Server</em>'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return a new object of class '<em>Ieee Addr Server</em>'.
	 * @generated
	 */
	IeeeAddrServer createIeeeAddrServer();

	/**
	 * Returns a new object of class '<em>Match Desc Server</em>'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return a new object of class '<em>Match Desc Server</em>'.
	 * @generated
	 */
	MatchDescServer createMatchDescServer();

	/**
	 * Returns a new object of class '<em>Node Desc Server</em>'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return a new object of class '<em>Node Desc Server</em>'.
	 * @generated
	 */
	NodeDescServer createNodeDescServer();

	/**
	 * Returns a new object of class '<em>Permit Joining Server</em>'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return a new object of class '<em>Permit Joining Server</em>'.
	 * @generated
	 */
	PermitJoiningServer createPermitJoiningServer();

	/**
	 * Returns a new object of class '<em>Power Desc Server</em>'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return a new object of class '<em>Power Desc Server</em>'.
	 * @generated
	 */
	PowerDescServer createPowerDescServer();

	/**
	 * Returns a new object of class '<em>Simple Desc Server</em>'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return a new object of class '<em>Simple Desc Server</em>'.
	 * @generated
	 */
	SimpleDescServer createSimpleDescServer();

	/**
	 * Returns a new object of class '<em>System Server Discovery Server</em>'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return a new object of class '<em>System Server Discovery Server</em>'.
	 * @generated
	 */
	SystemServerDiscoveryServer createSystemServerDiscoveryServer();

	/**
	 * Returns a new object of class '<em>Mgmt Lqi Server</em>'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return a new object of class '<em>Mgmt Lqi Server</em>'.
	 * @generated
	 */
	MgmtLqiServer createMgmtLqiServer();

	/**
	 * Returns a new object of class '<em>Mgmt Rtg Server</em>'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return a new object of class '<em>Mgmt Rtg Server</em>'.
	 * @generated
	 */
	MgmtRtgServer createMgmtRtgServer();

	/**
	 * Returns a new object of class '<em>Mgmt Leave Server</em>'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return a new object of class '<em>Mgmt Leave Server</em>'.
	 * @generated
	 */
	MgmtLeaveServer createMgmtLeaveServer();

	/**
	 * Returns a new object of class '<em>Node Descriptor</em>'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return a new object of class '<em>Node Descriptor</em>'.
	 * @generated
	 */
	NodeDescriptor createNodeDescriptor();

	/**
	 * Returns a new object of class '<em>Node Power Descriptor</em>'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return a new object of class '<em>Node Power Descriptor</em>'.
	 * @generated
	 */
	NodePowerDescriptor createNodePowerDescriptor();

	/**
	 * Returns a new object of class '<em>Bind Unbind Server</em>'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return a new object of class '<em>Bind Unbind Server</em>'.
	 * @generated
	 */
	BindUnbindServer createBindUnbindServer();

	/**
	 * Returns a new object of class '<em>Mgmt Bind Server</em>'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return a new object of class '<em>Mgmt Bind Server</em>'.
	 * @generated
	 */
	MgmtBindServer createMgmtBindServer();

	/**
	 * Returns a new object of class '<em>Extended Active Ep Server</em>'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return a new object of class '<em>Extended Active Ep Server</em>'.
	 * @generated
	 */
	ExtendedActiveEpServer createExtendedActiveEpServer();

	/**
	 * Returns a new object of class '<em>Extended Simple Desc Server</em>'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return a new object of class '<em>Extended Simple Desc Server</em>'.
	 * @generated
	 */
	ExtendedSimpleDescServer createExtendedSimpleDescServer();

	/**
	 * Returns a new object of class '<em>Zdo Client</em>'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return a new object of class '<em>Zdo Client</em>'.
	 * @generated
	 */
	ZdoClient createZdoClient();

	/**
	 * Returns a new object of class '<em>Mgmt NWK Update Server</em>'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return a new object of class '<em>Mgmt NWK Update Server</em>'.
	 * @generated
	 */
	MgmtNWKUpdateServer createMgmtNWKUpdateServer();

	/**
	 * Returns a new object of class '<em>Not Implemented</em>'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return a new object of class '<em>Not Implemented</em>'.
	 * @generated
	 */
	NotImplemented createNotImplemented();

	/**
	 * Returns a new object of class '<em>Key Descriptor Table</em>'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return a new object of class '<em>Key Descriptor Table</em>'.
	 * @generated
	 */
	KeyDescriptorTable createKeyDescriptorTable();

	/**
	 * Returns a new object of class '<em>Preconfigured Key</em>'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return a new object of class '<em>Preconfigured Key</em>'.
	 * @generated
	 */
	PreconfiguredKey createPreconfiguredKey();

	/**
	 * Returns a new object of class '<em>Pre Configured Nwk Key</em>'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return a new object of class '<em>Pre Configured Nwk Key</em>'.
	 * @generated
	 */
	PreConfiguredNwkKey createPreConfiguredNwkKey();

	/**
	 * Returns a new object of class '<em>Default Nwk Key</em>'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return a new object of class '<em>Default Nwk Key</em>'.
	 * @generated
	 */
	DefaultNwkKey createDefaultNwkKey();

	/**
	 * Returns a new object of class '<em>Preconfigured TC Link Key</em>'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return a new object of class '<em>Preconfigured TC Link Key</em>'.
	 * @generated
	 */
	PreconfiguredTCLinkKey createPreconfiguredTCLinkKey();

	/**
	 * Returns a new object of class '<em>Bind Request Server</em>'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return a new object of class '<em>Bind Request Server</em>'.
	 * @generated
	 */
	BindRequestServer createBindRequestServer();

	/**
	 * Returns a new object of class '<em>Green Power Security Table</em>'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return a new object of class '<em>Green Power Security Table</em>'.
	 * @generated
	 */
	GreenPowerSecurityTable createGreenPowerSecurityTable();

	/**
	 * Returns a new object of class '<em>Green Power Tx Queue</em>'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return a new object of class '<em>Green Power Tx Queue</em>'.
	 * @generated
	 */
	GreenPowerTxQueue createGreenPowerTxQueue();

	/**
	 * Returns a new object of class '<em>Mgmt Mib Ieee Server</em>'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return a new object of class '<em>Mgmt Mib Ieee Server</em>'.
	 * @generated
	 */
	MgmtMibIeeeServer createMgmtMibIeeeServer();

	/**
	 * Returns a new object of class '<em>Mgmt NWK Enhance Update Server</em>'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return a new object of class '<em>Mgmt NWK Enhance Update Server</em>'.
	 * @generated
	 */
	MgmtNWKEnhanceUpdateServer createMgmtNWKEnhanceUpdateServer();

	/**
	 * Returns a new object of class '<em>Mac Interface List</em>'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return a new object of class '<em>Mac Interface List</em>'.
	 * @generated
	 */
	MacInterfaceList createMacInterfaceList();

	/**
	 * Returns a new object of class '<em>Mac Interface</em>'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return a new object of class '<em>Mac Interface</em>'.
	 * @generated
	 */
	MacInterface createMacInterface();

	/**
	 * Returns a new object of class '<em>Parent Annce Server</em>'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return a new object of class '<em>Parent Annce Server</em>'.
	 * @generated
	 */
	ParentAnnceServer createParentAnnceServer();

	/**
	 * Returns the package supported by this factory.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the package supported by this factory.
	 * @generated
	 */
	ZPSConfigurationPackage getZPSConfigurationPackage();

} //ZPSConfigurationFactory
