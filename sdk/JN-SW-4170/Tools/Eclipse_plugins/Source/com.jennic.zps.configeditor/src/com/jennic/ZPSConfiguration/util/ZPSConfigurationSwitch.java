/**
 * (C) Jennic Ltd 2008
 *
 * $Id$
 */
package com.jennic.ZPSConfiguration.util;


import com.jennic.ZPSConfiguration.*;
import org.eclipse.emf.ecore.EObject;
import org.eclipse.emf.ecore.EPackage;
import org.eclipse.emf.ecore.util.Switch;

import com.jennic.ZPSConfiguration.APDU;
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
import com.jennic.ZPSConfiguration.GreenPowerSecurityTable;
import com.jennic.ZPSConfiguration.GreenPowerTxQueue;
import com.jennic.ZPSConfiguration.GroupTable;
import com.jennic.ZPSConfiguration.IeeeAddrServer;
import com.jennic.ZPSConfiguration.InputCluster;
import com.jennic.ZPSConfiguration.KeyDescriptorTable;
import com.jennic.ZPSConfiguration.MatchDescServer;
import com.jennic.ZPSConfiguration.MgmtBindServer;
import com.jennic.ZPSConfiguration.MgmtLeaveServer;
import com.jennic.ZPSConfiguration.MgmtLqiServer;
import com.jennic.ZPSConfiguration.MgmtNWKUpdateServer;
import com.jennic.ZPSConfiguration.MgmtRtgServer;
import com.jennic.ZPSConfiguration.NamedObject;
import com.jennic.ZPSConfiguration.Node;
import com.jennic.ZPSConfiguration.NodeDescServer;
import com.jennic.ZPSConfiguration.NodeDescriptor;
import com.jennic.ZPSConfiguration.NodePowerDescriptor;
import com.jennic.ZPSConfiguration.NotImplemented;
import com.jennic.ZPSConfiguration.NwkAddrServer;
import com.jennic.ZPSConfiguration.NwkKey;
import com.jennic.ZPSConfiguration.OutputCluster;
import com.jennic.ZPSConfiguration.PDUManager;
import com.jennic.ZPSConfiguration.PermitJoiningServer;
import com.jennic.ZPSConfiguration.PowerDescServer;
import com.jennic.ZPSConfiguration.PreConfiguredNwkKey;
import com.jennic.ZPSConfiguration.PreconfiguredKey;
import com.jennic.ZPSConfiguration.PreconfiguredTCLinkKey;
import com.jennic.ZPSConfiguration.PrimaryBindingCache;
import com.jennic.ZPSConfiguration.PrimaryDiscoveryCache;
import com.jennic.ZPSConfiguration.PrimaryGroupCache;
import com.jennic.ZPSConfiguration.Profile;
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
import com.jennic.ZPSConfiguration.ZPSConfigurationPackage;
import com.jennic.ZPSConfiguration.ZdoClient;
import com.jennic.ZPSConfiguration.ZigbeeWirelessNetwork;

/**
 * <!-- begin-user-doc -->
 * The <b>Switch</b> for the model's inheritance hierarchy.
 * It supports the call {@link #doSwitch(EObject) doSwitch(object)}
 * to invoke the <code>caseXXX</code> method for each class of the model,
 * starting with the actual class of the object
 * and proceeding up the inheritance hierarchy
 * until a non-null result is returned,
 * which is the result of the switch.
 * <!-- end-user-doc -->
 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage
 * @generated
 */
public class ZPSConfigurationSwitch<T> extends Switch<T> {
	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public static final String copyright = "(C) NXP B.V";
	/**
	 * The cached model package
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	protected static ZPSConfigurationPackage modelPackage;

	/**
	 * Creates an instance of the switch.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public ZPSConfigurationSwitch() {
		if (modelPackage == null) {
			modelPackage = ZPSConfigurationPackage.eINSTANCE;
		}
	}

	/**
	 * Checks whether this is a switch for the given package.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @parameter ePackage the package in question.
	 * @return whether this is a switch for the given package.
	 * @generated
	 */
	@Override
	protected boolean isSwitchFor(EPackage ePackage) {
		return ePackage == modelPackage;
	}

	/**
	 * Calls <code>caseXXX</code> for each class of the model until one returns a non null result; it yields that result.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the first non-null result returned by a <code>caseXXX</code> call.
	 * @generated
	 */
	@Override
	protected T doSwitch(int classifierID, EObject theEObject) {
		switch (classifierID) {
			case ZPSConfigurationPackage.PROFILE: {
				Profile profile = (Profile)theEObject;
				T result = caseProfile(profile);
				if (result == null) result = caseNamedObject(profile);
				if (result == null) result = defaultCase(theEObject);
				return result;
			}
			case ZPSConfigurationPackage.CLUSTER: {
				Cluster cluster = (Cluster)theEObject;
				T result = caseCluster(cluster);
				if (result == null) result = caseNamedObject(cluster);
				if (result == null) result = defaultCase(theEObject);
				return result;
			}
			case ZPSConfigurationPackage.NODE: {
				Node node = (Node)theEObject;
				T result = caseNode(node);
				if (result == null) result = caseNamedObject(node);
				if (result == null) result = defaultCase(theEObject);
				return result;
			}
			case ZPSConfigurationPackage.COORDINATOR: {
				Coordinator coordinator = (Coordinator)theEObject;
				T result = caseCoordinator(coordinator);
				if (result == null) result = caseAlwaysOnNode(coordinator);
				if (result == null) result = caseNode(coordinator);
				if (result == null) result = caseNamedObject(coordinator);
				if (result == null) result = defaultCase(theEObject);
				return result;
			}
			case ZPSConfigurationPackage.ROUTER: {
				Router router = (Router)theEObject;
				T result = caseRouter(router);
				if (result == null) result = caseAlwaysOnNode(router);
				if (result == null) result = caseChildNodes(router);
				if (result == null) result = caseNode(router);
				if (result == null) result = caseNamedObject(router);
				if (result == null) result = defaultCase(theEObject);
				return result;
			}
			case ZPSConfigurationPackage.END_DEVICE: {
				EndDevice endDevice = (EndDevice)theEObject;
				T result = caseEndDevice(endDevice);
				if (result == null) result = caseNode(endDevice);
				if (result == null) result = caseChildNodes(endDevice);
				if (result == null) result = caseNamedObject(endDevice);
				if (result == null) result = defaultCase(theEObject);
				return result;
			}
			case ZPSConfigurationPackage.END_POINT: {
				EndPoint endPoint = (EndPoint)theEObject;
				T result = caseEndPoint(endPoint);
				if (result == null) result = defaultCase(theEObject);
				return result;
			}
			case ZPSConfigurationPackage.PRIMARY_DISCOVERY_CACHE: {
				PrimaryDiscoveryCache primaryDiscoveryCache = (PrimaryDiscoveryCache)theEObject;
				T result = casePrimaryDiscoveryCache(primaryDiscoveryCache);
				if (result == null) result = caseDiscoveryCache(primaryDiscoveryCache);
				if (result == null) result = defaultCase(theEObject);
				return result;
			}
			case ZPSConfigurationPackage.BACKUP_DISCOVERY_CACHE: {
				BackupDiscoveryCache backupDiscoveryCache = (BackupDiscoveryCache)theEObject;
				T result = caseBackupDiscoveryCache(backupDiscoveryCache);
				if (result == null) result = caseDiscoveryCache(backupDiscoveryCache);
				if (result == null) result = defaultCase(theEObject);
				return result;
			}
			case ZPSConfigurationPackage.DISCOVERY_TABLE: {
				DiscoveryTable discoveryTable = (DiscoveryTable)theEObject;
				T result = caseDiscoveryTable(discoveryTable);
				if (result == null) result = defaultCase(theEObject);
				return result;
			}
			case ZPSConfigurationPackage.BINDING_TABLE: {
				BindingTable bindingTable = (BindingTable)theEObject;
				T result = caseBindingTable(bindingTable);
				if (result == null) result = defaultCase(theEObject);
				return result;
			}
			case ZPSConfigurationPackage.GROUP_TABLE: {
				GroupTable groupTable = (GroupTable)theEObject;
				T result = caseGroupTable(groupTable);
				if (result == null) result = defaultCase(theEObject);
				return result;
			}
			case ZPSConfigurationPackage.ZIGBEE_WIRELESS_NETWORK: {
				ZigbeeWirelessNetwork zigbeeWirelessNetwork = (ZigbeeWirelessNetwork)theEObject;
				T result = caseZigbeeWirelessNetwork(zigbeeWirelessNetwork);
				if (result == null) result = defaultCase(theEObject);
				return result;
			}
			case ZPSConfigurationPackage.PRIMARY_BINDING_CACHE: {
				PrimaryBindingCache primaryBindingCache = (PrimaryBindingCache)theEObject;
				T result = casePrimaryBindingCache(primaryBindingCache);
				if (result == null) result = caseBindingCache(primaryBindingCache);
				if (result == null) result = defaultCase(theEObject);
				return result;
			}
			case ZPSConfigurationPackage.BACKUP_BINDING_CACHE: {
				BackupBindingCache backupBindingCache = (BackupBindingCache)theEObject;
				T result = caseBackupBindingCache(backupBindingCache);
				if (result == null) result = caseBindingCache(backupBindingCache);
				if (result == null) result = defaultCase(theEObject);
				return result;
			}
			case ZPSConfigurationPackage.PRIMARY_GROUP_CACHE: {
				PrimaryGroupCache primaryGroupCache = (PrimaryGroupCache)theEObject;
				T result = casePrimaryGroupCache(primaryGroupCache);
				if (result == null) result = defaultCase(theEObject);
				return result;
			}
			case ZPSConfigurationPackage.BACKUP_GROUP_CACHE: {
				BackupGroupCache backupGroupCache = (BackupGroupCache)theEObject;
				T result = caseBackupGroupCache(backupGroupCache);
				if (result == null) result = defaultCase(theEObject);
				return result;
			}
			case ZPSConfigurationPackage.INPUT_CLUSTER: {
				InputCluster inputCluster = (InputCluster)theEObject;
				T result = caseInputCluster(inputCluster);
				if (result == null) result = defaultCase(theEObject);
				return result;
			}
			case ZPSConfigurationPackage.OUTPUT_CLUSTER: {
				OutputCluster outputCluster = (OutputCluster)theEObject;
				T result = caseOutputCluster(outputCluster);
				if (result == null) result = defaultCase(theEObject);
				return result;
			}
			case ZPSConfigurationPackage.ALWAYS_ON_NODE: {
				AlwaysOnNode alwaysOnNode = (AlwaysOnNode)theEObject;
				T result = caseAlwaysOnNode(alwaysOnNode);
				if (result == null) result = caseNode(alwaysOnNode);
				if (result == null) result = caseNamedObject(alwaysOnNode);
				if (result == null) result = defaultCase(theEObject);
				return result;
			}
			case ZPSConfigurationPackage.COMPLEX_DESCRIPTOR: {
				ComplexDescriptor complexDescriptor = (ComplexDescriptor)theEObject;
				T result = caseComplexDescriptor(complexDescriptor);
				if (result == null) result = defaultCase(theEObject);
				return result;
			}
			case ZPSConfigurationPackage.USER_DESCRIPTOR: {
				UserDescriptor userDescriptor = (UserDescriptor)theEObject;
				T result = caseUserDescriptor(userDescriptor);
				if (result == null) result = defaultCase(theEObject);
				return result;
			}
			case ZPSConfigurationPackage.TRUST_CENTER: {
				TrustCenter trustCenter = (TrustCenter)theEObject;
				T result = caseTrustCenter(trustCenter);
				if (result == null) result = defaultCase(theEObject);
				return result;
			}
			case ZPSConfigurationPackage.DISCOVERY_CACHE: {
				DiscoveryCache discoveryCache = (DiscoveryCache)theEObject;
				T result = caseDiscoveryCache(discoveryCache);
				if (result == null) result = defaultCase(theEObject);
				return result;
			}
			case ZPSConfigurationPackage.BINDING_CACHE: {
				BindingCache bindingCache = (BindingCache)theEObject;
				T result = caseBindingCache(bindingCache);
				if (result == null) result = defaultCase(theEObject);
				return result;
			}
			case ZPSConfigurationPackage.NAMED_OBJECT: {
				NamedObject namedObject = (NamedObject)theEObject;
				T result = caseNamedObject(namedObject);
				if (result == null) result = defaultCase(theEObject);
				return result;
			}
			case ZPSConfigurationPackage.CHILD_NODES: {
				ChildNodes childNodes = (ChildNodes)theEObject;
				T result = caseChildNodes(childNodes);
				if (result == null) result = defaultCase(theEObject);
				return result;
			}
			case ZPSConfigurationPackage.APDU: {
				APDU apdu = (APDU)theEObject;
				T result = caseAPDU(apdu);
				if (result == null) result = defaultCase(theEObject);
				return result;
			}
			case ZPSConfigurationPackage.PDU_MANAGER: {
				PDUManager pduManager = (PDUManager)theEObject;
				T result = casePDUManager(pduManager);
				if (result == null) result = defaultCase(theEObject);
				return result;
			}
			case ZPSConfigurationPackage.CHANNEL_MASK: {
				ChannelMask channelMask = (ChannelMask)theEObject;
				T result = caseChannelMask(channelMask);
				if (result == null) result = defaultCase(theEObject);
				return result;
			}
			case ZPSConfigurationPackage.ZDO_CLIENT_SERVER: {
				ZDOClientServer zdoClientServer = (ZDOClientServer)theEObject;
				T result = caseZDOClientServer(zdoClientServer);
				if (result == null) result = defaultCase(theEObject);
				return result;
			}
			case ZPSConfigurationPackage.ZDO_SERVERS_COORDINATOR: {
				ZDOServersCoordinator zdoServersCoordinator = (ZDOServersCoordinator)theEObject;
				T result = caseZDOServersCoordinator(zdoServersCoordinator);
				if (result == null) result = caseZDOCommonServers(zdoServersCoordinator);
				if (result == null) result = caseZDOCoordRouterOnlyServers(zdoServersCoordinator);
				if (result == null) result = defaultCase(theEObject);
				return result;
			}
			case ZPSConfigurationPackage.ZDO_SERVERS_ROUTER: {
				ZDOServersRouter zdoServersRouter = (ZDOServersRouter)theEObject;
				T result = caseZDOServersRouter(zdoServersRouter);
				if (result == null) result = caseZDOCommonServers(zdoServersRouter);
				if (result == null) result = caseZDOCoordRouterOnlyServers(zdoServersRouter);
				if (result == null) result = defaultCase(theEObject);
				return result;
			}
			case ZPSConfigurationPackage.ZDO_SERVERS_END_DEVICE: {
				ZDOServersEndDevice zdoServersEndDevice = (ZDOServersEndDevice)theEObject;
				T result = caseZDOServersEndDevice(zdoServersEndDevice);
				if (result == null) result = caseZDOCommonServers(zdoServersEndDevice);
				if (result == null) result = defaultCase(theEObject);
				return result;
			}
			case ZPSConfigurationPackage.DEFAULT_SERVER: {
				DefaultServer defaultServer = (DefaultServer)theEObject;
				T result = caseDefaultServer(defaultServer);
				if (result == null) result = caseZDOClientServer(defaultServer);
				if (result == null) result = defaultCase(theEObject);
				return result;
			}
			case ZPSConfigurationPackage.END_DEVICE_BIND_SERVER: {
				EndDeviceBindServer endDeviceBindServer = (EndDeviceBindServer)theEObject;
				T result = caseEndDeviceBindServer(endDeviceBindServer);
				if (result == null) result = caseZDOClientServer(endDeviceBindServer);
				if (result == null) result = defaultCase(theEObject);
				return result;
			}
			case ZPSConfigurationPackage.DEVICE_ANNCE_SERVER: {
				DeviceAnnceServer deviceAnnceServer = (DeviceAnnceServer)theEObject;
				T result = caseDeviceAnnceServer(deviceAnnceServer);
				if (result == null) result = caseZDOClientServer(deviceAnnceServer);
				if (result == null) result = defaultCase(theEObject);
				return result;
			}
			case ZPSConfigurationPackage.ACTIVE_EP_SERVER: {
				ActiveEpServer activeEpServer = (ActiveEpServer)theEObject;
				T result = caseActiveEpServer(activeEpServer);
				if (result == null) result = caseZDOClientServer(activeEpServer);
				if (result == null) result = defaultCase(theEObject);
				return result;
			}
			case ZPSConfigurationPackage.NWK_ADDR_SERVER: {
				NwkAddrServer nwkAddrServer = (NwkAddrServer)theEObject;
				T result = caseNwkAddrServer(nwkAddrServer);
				if (result == null) result = caseZDOClientServer(nwkAddrServer);
				if (result == null) result = defaultCase(theEObject);
				return result;
			}
			case ZPSConfigurationPackage.IEEE_ADDR_SERVER: {
				IeeeAddrServer ieeeAddrServer = (IeeeAddrServer)theEObject;
				T result = caseIeeeAddrServer(ieeeAddrServer);
				if (result == null) result = caseZDOClientServer(ieeeAddrServer);
				if (result == null) result = defaultCase(theEObject);
				return result;
			}
			case ZPSConfigurationPackage.MATCH_DESC_SERVER: {
				MatchDescServer matchDescServer = (MatchDescServer)theEObject;
				T result = caseMatchDescServer(matchDescServer);
				if (result == null) result = caseZDOClientServer(matchDescServer);
				if (result == null) result = defaultCase(theEObject);
				return result;
			}
			case ZPSConfigurationPackage.NODE_DESC_SERVER: {
				NodeDescServer nodeDescServer = (NodeDescServer)theEObject;
				T result = caseNodeDescServer(nodeDescServer);
				if (result == null) result = caseZDOClientServer(nodeDescServer);
				if (result == null) result = defaultCase(theEObject);
				return result;
			}
			case ZPSConfigurationPackage.PERMIT_JOINING_SERVER: {
				PermitJoiningServer permitJoiningServer = (PermitJoiningServer)theEObject;
				T result = casePermitJoiningServer(permitJoiningServer);
				if (result == null) result = caseZDOClientServer(permitJoiningServer);
				if (result == null) result = defaultCase(theEObject);
				return result;
			}
			case ZPSConfigurationPackage.POWER_DESC_SERVER: {
				PowerDescServer powerDescServer = (PowerDescServer)theEObject;
				T result = casePowerDescServer(powerDescServer);
				if (result == null) result = caseZDOClientServer(powerDescServer);
				if (result == null) result = defaultCase(theEObject);
				return result;
			}
			case ZPSConfigurationPackage.SIMPLE_DESC_SERVER: {
				SimpleDescServer simpleDescServer = (SimpleDescServer)theEObject;
				T result = caseSimpleDescServer(simpleDescServer);
				if (result == null) result = caseZDOClientServer(simpleDescServer);
				if (result == null) result = defaultCase(theEObject);
				return result;
			}
			case ZPSConfigurationPackage.SYSTEM_SERVER_DISCOVERY_SERVER: {
				SystemServerDiscoveryServer systemServerDiscoveryServer = (SystemServerDiscoveryServer)theEObject;
				T result = caseSystemServerDiscoveryServer(systemServerDiscoveryServer);
				if (result == null) result = caseZDOClientServer(systemServerDiscoveryServer);
				if (result == null) result = defaultCase(theEObject);
				return result;
			}
			case ZPSConfigurationPackage.MGMT_LQI_SERVER: {
				MgmtLqiServer mgmtLqiServer = (MgmtLqiServer)theEObject;
				T result = caseMgmtLqiServer(mgmtLqiServer);
				if (result == null) result = caseZDOClientServer(mgmtLqiServer);
				if (result == null) result = defaultCase(theEObject);
				return result;
			}
			case ZPSConfigurationPackage.MGMT_RTG_SERVER: {
				MgmtRtgServer mgmtRtgServer = (MgmtRtgServer)theEObject;
				T result = caseMgmtRtgServer(mgmtRtgServer);
				if (result == null) result = caseZDOClientServer(mgmtRtgServer);
				if (result == null) result = defaultCase(theEObject);
				return result;
			}
			case ZPSConfigurationPackage.MGMT_LEAVE_SERVER: {
				MgmtLeaveServer mgmtLeaveServer = (MgmtLeaveServer)theEObject;
				T result = caseMgmtLeaveServer(mgmtLeaveServer);
				if (result == null) result = caseZDOClientServer(mgmtLeaveServer);
				if (result == null) result = defaultCase(theEObject);
				return result;
			}
			case ZPSConfigurationPackage.NODE_DESCRIPTOR: {
				NodeDescriptor nodeDescriptor = (NodeDescriptor)theEObject;
				T result = caseNodeDescriptor(nodeDescriptor);
				if (result == null) result = defaultCase(theEObject);
				return result;
			}
			case ZPSConfigurationPackage.NODE_POWER_DESCRIPTOR: {
				NodePowerDescriptor nodePowerDescriptor = (NodePowerDescriptor)theEObject;
				T result = caseNodePowerDescriptor(nodePowerDescriptor);
				if (result == null) result = defaultCase(theEObject);
				return result;
			}
			case ZPSConfigurationPackage.BIND_UNBIND_SERVER: {
				BindUnbindServer bindUnbindServer = (BindUnbindServer)theEObject;
				T result = caseBindUnbindServer(bindUnbindServer);
				if (result == null) result = caseZDOClientServer(bindUnbindServer);
				if (result == null) result = defaultCase(theEObject);
				return result;
			}
			case ZPSConfigurationPackage.MGMT_BIND_SERVER: {
				MgmtBindServer mgmtBindServer = (MgmtBindServer)theEObject;
				T result = caseMgmtBindServer(mgmtBindServer);
				if (result == null) result = caseZDOClientServer(mgmtBindServer);
				if (result == null) result = defaultCase(theEObject);
				return result;
			}
			case ZPSConfigurationPackage.EXTENDED_ACTIVE_EP_SERVER: {
				ExtendedActiveEpServer extendedActiveEpServer = (ExtendedActiveEpServer)theEObject;
				T result = caseExtendedActiveEpServer(extendedActiveEpServer);
				if (result == null) result = caseZDOClientServer(extendedActiveEpServer);
				if (result == null) result = defaultCase(theEObject);
				return result;
			}
			case ZPSConfigurationPackage.EXTENDED_SIMPLE_DESC_SERVER: {
				ExtendedSimpleDescServer extendedSimpleDescServer = (ExtendedSimpleDescServer)theEObject;
				T result = caseExtendedSimpleDescServer(extendedSimpleDescServer);
				if (result == null) result = caseZDOClientServer(extendedSimpleDescServer);
				if (result == null) result = defaultCase(theEObject);
				return result;
			}
			case ZPSConfigurationPackage.ZDO_CLIENT: {
				ZdoClient zdoClient = (ZdoClient)theEObject;
				T result = caseZdoClient(zdoClient);
				if (result == null) result = caseZDOClientServer(zdoClient);
				if (result == null) result = defaultCase(theEObject);
				return result;
			}
			case ZPSConfigurationPackage.MGMT_NWK_UPDATE_SERVER: {
				MgmtNWKUpdateServer mgmtNWKUpdateServer = (MgmtNWKUpdateServer)theEObject;
				T result = caseMgmtNWKUpdateServer(mgmtNWKUpdateServer);
				if (result == null) result = caseZDOClientServer(mgmtNWKUpdateServer);
				if (result == null) result = defaultCase(theEObject);
				return result;
			}
			case ZPSConfigurationPackage.ZDO_COMMON_SERVERS: {
				ZDOCommonServers zdoCommonServers = (ZDOCommonServers)theEObject;
				T result = caseZDOCommonServers(zdoCommonServers);
				if (result == null) result = defaultCase(theEObject);
				return result;
			}
			case ZPSConfigurationPackage.NOT_IMPLEMENTED: {
				NotImplemented notImplemented = (NotImplemented)theEObject;
				T result = caseNotImplemented(notImplemented);
				if (result == null) result = defaultCase(theEObject);
				return result;
			}
			case ZPSConfigurationPackage.KEY_DESCRIPTOR_TABLE: {
				KeyDescriptorTable keyDescriptorTable = (KeyDescriptorTable)theEObject;
				T result = caseKeyDescriptorTable(keyDescriptorTable);
				if (result == null) result = defaultCase(theEObject);
				return result;
			}
			case ZPSConfigurationPackage.PRECONFIGURED_KEY: {
				PreconfiguredKey preconfiguredKey = (PreconfiguredKey)theEObject;
				T result = casePreconfiguredKey(preconfiguredKey);
				if (result == null) result = defaultCase(theEObject);
				return result;
			}
			case ZPSConfigurationPackage.ZDO_COORD_ROUTER_ONLY_SERVERS: {
				ZDOCoordRouterOnlyServers zdoCoordRouterOnlyServers = (ZDOCoordRouterOnlyServers)theEObject;
				T result = caseZDOCoordRouterOnlyServers(zdoCoordRouterOnlyServers);
				if (result == null) result = defaultCase(theEObject);
				return result;
			}
			case ZPSConfigurationPackage.PRE_CONFIGURED_NWK_KEY: {
				PreConfiguredNwkKey preConfiguredNwkKey = (PreConfiguredNwkKey)theEObject;
				T result = casePreConfiguredNwkKey(preConfiguredNwkKey);
				if (result == null) result = caseNwkKey(preConfiguredNwkKey);
				if (result == null) result = caseTCKey(preConfiguredNwkKey);
				if (result == null) result = defaultCase(theEObject);
				return result;
			}
			case ZPSConfigurationPackage.DEFAULT_NWK_KEY: {
				DefaultNwkKey defaultNwkKey = (DefaultNwkKey)theEObject;
				T result = caseDefaultNwkKey(defaultNwkKey);
				if (result == null) result = caseNwkKey(defaultNwkKey);
				if (result == null) result = caseTCKey(defaultNwkKey);
				if (result == null) result = defaultCase(theEObject);
				return result;
			}
			case ZPSConfigurationPackage.NWK_KEY: {
				NwkKey nwkKey = (NwkKey)theEObject;
				T result = caseNwkKey(nwkKey);
				if (result == null) result = caseTCKey(nwkKey);
				if (result == null) result = defaultCase(theEObject);
				return result;
			}
			case ZPSConfigurationPackage.PRECONFIGURED_TC_LINK_KEY: {
				PreconfiguredTCLinkKey preconfiguredTCLinkKey = (PreconfiguredTCLinkKey)theEObject;
				T result = casePreconfiguredTCLinkKey(preconfiguredTCLinkKey);
				if (result == null) result = caseTCKey(preconfiguredTCLinkKey);
				if (result == null) result = defaultCase(theEObject);
				return result;
			}
			case ZPSConfigurationPackage.TC_KEY: {
				TCKey tcKey = (TCKey)theEObject;
				T result = caseTCKey(tcKey);
				if (result == null) result = defaultCase(theEObject);
				return result;
			}
			case ZPSConfigurationPackage.BIND_REQUEST_SERVER: {
				BindRequestServer bindRequestServer = (BindRequestServer)theEObject;
				T result = caseBindRequestServer(bindRequestServer);
				if (result == null) result = caseZDOClientServer(bindRequestServer);
				if (result == null) result = defaultCase(theEObject);
				return result;
			}
			case ZPSConfigurationPackage.GREEN_POWER_SECURITY_TABLE: {
				GreenPowerSecurityTable greenPowerSecurityTable = (GreenPowerSecurityTable)theEObject;
				T result = caseGreenPowerSecurityTable(greenPowerSecurityTable);
				if (result == null) result = defaultCase(theEObject);
				return result;
			}
			case ZPSConfigurationPackage.GREEN_POWER_TX_QUEUE: {
				GreenPowerTxQueue greenPowerTxQueue = (GreenPowerTxQueue)theEObject;
				T result = caseGreenPowerTxQueue(greenPowerTxQueue);
				if (result == null) result = defaultCase(theEObject);
				return result;
			}
			case ZPSConfigurationPackage.MGMT_MIB_IEEE_SERVER: {
				MgmtMibIeeeServer mgmtMibIeeeServer = (MgmtMibIeeeServer)theEObject;
				T result = caseMgmtMibIeeeServer(mgmtMibIeeeServer);
				if (result == null) result = caseZDOClientServer(mgmtMibIeeeServer);
				if (result == null) result = defaultCase(theEObject);
				return result;
			}
			case ZPSConfigurationPackage.PARENT_ANNCE_SERVER: {
				ParentAnnceServer parentAnnceServer = (ParentAnnceServer)theEObject;
				T result = caseParentAnnceServer(parentAnnceServer);
				if (result == null) result = caseZDOClientServer(parentAnnceServer);
				if (result == null) result = defaultCase(theEObject);
				return result;
			}
			case ZPSConfigurationPackage.MGMT_NWK_ENHANCE_UPDATE_SERVER: {
				MgmtNWKEnhanceUpdateServer mgmtNWKEnhanceUpdateServer = (MgmtNWKEnhanceUpdateServer)theEObject;
				T result = caseMgmtNWKEnhanceUpdateServer(mgmtNWKEnhanceUpdateServer);
				if (result == null) result = caseZDOClientServer(mgmtNWKEnhanceUpdateServer);
				if (result == null) result = defaultCase(theEObject);
				return result;
			}
			case ZPSConfigurationPackage.MAC_INTERFACE_LIST: {
				MacInterfaceList macInterfaceList = (MacInterfaceList)theEObject;
				T result = caseMacInterfaceList(macInterfaceList);
				if (result == null) result = defaultCase(theEObject);
				return result;
			}
			case ZPSConfigurationPackage.MAC_INTERFACE: {
				MacInterface macInterface = (MacInterface)theEObject;
				T result = caseMacInterface(macInterface);
				if (result == null) result = defaultCase(theEObject);
				return result;
			}
			default: return defaultCase(theEObject);
		}
	}

	/**
	 * Returns the result of interpreting the object as an instance of '<em>Profile</em>'.
	 * <!-- begin-user-doc -->
	 * This implementation returns null;
	 * returning a non-null result will terminate the switch.
	 * <!-- end-user-doc -->
	 * @param object the target of the switch.
	 * @return the result of interpreting the object as an instance of '<em>Profile</em>'.
	 * @see #doSwitch(org.eclipse.emf.ecore.EObject) doSwitch(EObject)
	 * @generated
	 */
	public T caseProfile(Profile object) {
		return null;
	}

	/**
	 * Returns the result of interpreting the object as an instance of '<em>Cluster</em>'.
	 * <!-- begin-user-doc -->
	 * This implementation returns null;
	 * returning a non-null result will terminate the switch.
	 * <!-- end-user-doc -->
	 * @param object the target of the switch.
	 * @return the result of interpreting the object as an instance of '<em>Cluster</em>'.
	 * @see #doSwitch(org.eclipse.emf.ecore.EObject) doSwitch(EObject)
	 * @generated
	 */
	public T caseCluster(Cluster object) {
		return null;
	}

	/**
	 * Returns the result of interpreting the object as an instance of '<em>Node</em>'.
	 * <!-- begin-user-doc -->
	 * This implementation returns null;
	 * returning a non-null result will terminate the switch.
	 * <!-- end-user-doc -->
	 * @param object the target of the switch.
	 * @return the result of interpreting the object as an instance of '<em>Node</em>'.
	 * @see #doSwitch(org.eclipse.emf.ecore.EObject) doSwitch(EObject)
	 * @generated
	 */
	public T caseNode(Node object) {
		return null;
	}

	/**
	 * Returns the result of interpreting the object as an instance of '<em>Coordinator</em>'.
	 * <!-- begin-user-doc -->
	 * This implementation returns null;
	 * returning a non-null result will terminate the switch.
	 * <!-- end-user-doc -->
	 * @param object the target of the switch.
	 * @return the result of interpreting the object as an instance of '<em>Coordinator</em>'.
	 * @see #doSwitch(org.eclipse.emf.ecore.EObject) doSwitch(EObject)
	 * @generated
	 */
	public T caseCoordinator(Coordinator object) {
		return null;
	}

	/**
	 * Returns the result of interpreting the object as an instance of '<em>Router</em>'.
	 * <!-- begin-user-doc -->
	 * This implementation returns null;
	 * returning a non-null result will terminate the switch.
	 * <!-- end-user-doc -->
	 * @param object the target of the switch.
	 * @return the result of interpreting the object as an instance of '<em>Router</em>'.
	 * @see #doSwitch(org.eclipse.emf.ecore.EObject) doSwitch(EObject)
	 * @generated
	 */
	public T caseRouter(Router object) {
		return null;
	}

	/**
	 * Returns the result of interpreting the object as an instance of '<em>End Device</em>'.
	 * <!-- begin-user-doc -->
	 * This implementation returns null;
	 * returning a non-null result will terminate the switch.
	 * <!-- end-user-doc -->
	 * @param object the target of the switch.
	 * @return the result of interpreting the object as an instance of '<em>End Device</em>'.
	 * @see #doSwitch(org.eclipse.emf.ecore.EObject) doSwitch(EObject)
	 * @generated
	 */
	public T caseEndDevice(EndDevice object) {
		return null;
	}

	/**
	 * Returns the result of interpreting the object as an instance of '<em>End Point</em>'.
	 * <!-- begin-user-doc -->
	 * This implementation returns null;
	 * returning a non-null result will terminate the switch.
	 * <!-- end-user-doc -->
	 * @param object the target of the switch.
	 * @return the result of interpreting the object as an instance of '<em>End Point</em>'.
	 * @see #doSwitch(org.eclipse.emf.ecore.EObject) doSwitch(EObject)
	 * @generated
	 */
	public T caseEndPoint(EndPoint object) {
		return null;
	}

	/**
	 * Returns the result of interpreting the object as an instance of '<em>Primary Discovery Cache</em>'.
	 * <!-- begin-user-doc -->
	 * This implementation returns null;
	 * returning a non-null result will terminate the switch.
	 * <!-- end-user-doc -->
	 * @param object the target of the switch.
	 * @return the result of interpreting the object as an instance of '<em>Primary Discovery Cache</em>'.
	 * @see #doSwitch(org.eclipse.emf.ecore.EObject) doSwitch(EObject)
	 * @generated
	 */
	public T casePrimaryDiscoveryCache(PrimaryDiscoveryCache object) {
		return null;
	}

	/**
	 * Returns the result of interpreting the object as an instance of '<em>Backup Discovery Cache</em>'.
	 * <!-- begin-user-doc -->
	 * This implementation returns null;
	 * returning a non-null result will terminate the switch.
	 * <!-- end-user-doc -->
	 * @param object the target of the switch.
	 * @return the result of interpreting the object as an instance of '<em>Backup Discovery Cache</em>'.
	 * @see #doSwitch(org.eclipse.emf.ecore.EObject) doSwitch(EObject)
	 * @generated
	 */
	public T caseBackupDiscoveryCache(BackupDiscoveryCache object) {
		return null;
	}

	/**
	 * Returns the result of interpreting the object as an instance of '<em>Discovery Table</em>'.
	 * <!-- begin-user-doc -->
	 * This implementation returns null;
	 * returning a non-null result will terminate the switch.
	 * <!-- end-user-doc -->
	 * @param object the target of the switch.
	 * @return the result of interpreting the object as an instance of '<em>Discovery Table</em>'.
	 * @see #doSwitch(org.eclipse.emf.ecore.EObject) doSwitch(EObject)
	 * @generated
	 */
	public T caseDiscoveryTable(DiscoveryTable object) {
		return null;
	}

	/**
	 * Returns the result of interpreting the object as an instance of '<em>Binding Table</em>'.
	 * <!-- begin-user-doc -->
	 * This implementation returns null;
	 * returning a non-null result will terminate the switch.
	 * <!-- end-user-doc -->
	 * @param object the target of the switch.
	 * @return the result of interpreting the object as an instance of '<em>Binding Table</em>'.
	 * @see #doSwitch(org.eclipse.emf.ecore.EObject) doSwitch(EObject)
	 * @generated
	 */
	public T caseBindingTable(BindingTable object) {
		return null;
	}

	/**
	 * Returns the result of interpreting the object as an instance of '<em>Group Table</em>'.
	 * <!-- begin-user-doc -->
	 * This implementation returns null;
	 * returning a non-null result will terminate the switch.
	 * <!-- end-user-doc -->
	 * @param object the target of the switch.
	 * @return the result of interpreting the object as an instance of '<em>Group Table</em>'.
	 * @see #doSwitch(org.eclipse.emf.ecore.EObject) doSwitch(EObject)
	 * @generated
	 */
	public T caseGroupTable(GroupTable object) {
		return null;
	}

	/**
	 * Returns the result of interpreting the object as an instance of '<em>Zigbee Wireless Network</em>'.
	 * <!-- begin-user-doc -->
	 * This implementation returns null;
	 * returning a non-null result will terminate the switch.
	 * <!-- end-user-doc -->
	 * @param object the target of the switch.
	 * @return the result of interpreting the object as an instance of '<em>Zigbee Wireless Network</em>'.
	 * @see #doSwitch(org.eclipse.emf.ecore.EObject) doSwitch(EObject)
	 * @generated
	 */
	public T caseZigbeeWirelessNetwork(ZigbeeWirelessNetwork object) {
		return null;
	}

	/**
	 * Returns the result of interpreting the object as an instance of '<em>Primary Binding Cache</em>'.
	 * <!-- begin-user-doc -->
	 * This implementation returns null;
	 * returning a non-null result will terminate the switch.
	 * <!-- end-user-doc -->
	 * @param object the target of the switch.
	 * @return the result of interpreting the object as an instance of '<em>Primary Binding Cache</em>'.
	 * @see #doSwitch(org.eclipse.emf.ecore.EObject) doSwitch(EObject)
	 * @generated
	 */
	public T casePrimaryBindingCache(PrimaryBindingCache object) {
		return null;
	}

	/**
	 * Returns the result of interpreting the object as an instance of '<em>Backup Binding Cache</em>'.
	 * <!-- begin-user-doc -->
	 * This implementation returns null;
	 * returning a non-null result will terminate the switch.
	 * <!-- end-user-doc -->
	 * @param object the target of the switch.
	 * @return the result of interpreting the object as an instance of '<em>Backup Binding Cache</em>'.
	 * @see #doSwitch(org.eclipse.emf.ecore.EObject) doSwitch(EObject)
	 * @generated
	 */
	public T caseBackupBindingCache(BackupBindingCache object) {
		return null;
	}

	/**
	 * Returns the result of interpreting the object as an instance of '<em>Primary Group Cache</em>'.
	 * <!-- begin-user-doc -->
	 * This implementation returns null;
	 * returning a non-null result will terminate the switch.
	 * <!-- end-user-doc -->
	 * @param object the target of the switch.
	 * @return the result of interpreting the object as an instance of '<em>Primary Group Cache</em>'.
	 * @see #doSwitch(org.eclipse.emf.ecore.EObject) doSwitch(EObject)
	 * @generated
	 */
	public T casePrimaryGroupCache(PrimaryGroupCache object) {
		return null;
	}

	/**
	 * Returns the result of interpreting the object as an instance of '<em>Backup Group Cache</em>'.
	 * <!-- begin-user-doc -->
	 * This implementation returns null;
	 * returning a non-null result will terminate the switch.
	 * <!-- end-user-doc -->
	 * @param object the target of the switch.
	 * @return the result of interpreting the object as an instance of '<em>Backup Group Cache</em>'.
	 * @see #doSwitch(org.eclipse.emf.ecore.EObject) doSwitch(EObject)
	 * @generated
	 */
	public T caseBackupGroupCache(BackupGroupCache object) {
		return null;
	}

	/**
	 * Returns the result of interpreting the object as an instance of '<em>Input Cluster</em>'.
	 * <!-- begin-user-doc -->
	 * This implementation returns null;
	 * returning a non-null result will terminate the switch.
	 * <!-- end-user-doc -->
	 * @param object the target of the switch.
	 * @return the result of interpreting the object as an instance of '<em>Input Cluster</em>'.
	 * @see #doSwitch(org.eclipse.emf.ecore.EObject) doSwitch(EObject)
	 * @generated
	 */
	public T caseInputCluster(InputCluster object) {
		return null;
	}

	/**
	 * Returns the result of interpreting the object as an instance of '<em>Output Cluster</em>'.
	 * <!-- begin-user-doc -->
	 * This implementation returns null;
	 * returning a non-null result will terminate the switch.
	 * <!-- end-user-doc -->
	 * @param object the target of the switch.
	 * @return the result of interpreting the object as an instance of '<em>Output Cluster</em>'.
	 * @see #doSwitch(org.eclipse.emf.ecore.EObject) doSwitch(EObject)
	 * @generated
	 */
	public T caseOutputCluster(OutputCluster object) {
		return null;
	}

	/**
	 * Returns the result of interpreting the object as an instance of '<em>Always On Node</em>'.
	 * <!-- begin-user-doc -->
	 * This implementation returns null;
	 * returning a non-null result will terminate the switch.
	 * <!-- end-user-doc -->
	 * @param object the target of the switch.
	 * @return the result of interpreting the object as an instance of '<em>Always On Node</em>'.
	 * @see #doSwitch(org.eclipse.emf.ecore.EObject) doSwitch(EObject)
	 * @generated
	 */
	public T caseAlwaysOnNode(AlwaysOnNode object) {
		return null;
	}

	/**
	 * Returns the result of interpreting the object as an instance of '<em>Complex Descriptor</em>'.
	 * <!-- begin-user-doc -->
	 * This implementation returns null;
	 * returning a non-null result will terminate the switch.
	 * <!-- end-user-doc -->
	 * @param object the target of the switch.
	 * @return the result of interpreting the object as an instance of '<em>Complex Descriptor</em>'.
	 * @see #doSwitch(org.eclipse.emf.ecore.EObject) doSwitch(EObject)
	 * @generated
	 */
	public T caseComplexDescriptor(ComplexDescriptor object) {
		return null;
	}

	/**
	 * Returns the result of interpreting the object as an instance of '<em>User Descriptor</em>'.
	 * <!-- begin-user-doc -->
	 * This implementation returns null;
	 * returning a non-null result will terminate the switch.
	 * <!-- end-user-doc -->
	 * @param object the target of the switch.
	 * @return the result of interpreting the object as an instance of '<em>User Descriptor</em>'.
	 * @see #doSwitch(org.eclipse.emf.ecore.EObject) doSwitch(EObject)
	 * @generated
	 */
	public T caseUserDescriptor(UserDescriptor object) {
		return null;
	}

	/**
	 * Returns the result of interpreting the object as an instance of '<em>Trust Center</em>'.
	 * <!-- begin-user-doc -->
	 * This implementation returns null;
	 * returning a non-null result will terminate the switch.
	 * <!-- end-user-doc -->
	 * @param object the target of the switch.
	 * @return the result of interpreting the object as an instance of '<em>Trust Center</em>'.
	 * @see #doSwitch(org.eclipse.emf.ecore.EObject) doSwitch(EObject)
	 * @generated
	 */
	public T caseTrustCenter(TrustCenter object) {
		return null;
	}

	/**
	 * Returns the result of interpreting the object as an instance of '<em>Discovery Cache</em>'.
	 * <!-- begin-user-doc -->
	 * This implementation returns null;
	 * returning a non-null result will terminate the switch.
	 * <!-- end-user-doc -->
	 * @param object the target of the switch.
	 * @return the result of interpreting the object as an instance of '<em>Discovery Cache</em>'.
	 * @see #doSwitch(org.eclipse.emf.ecore.EObject) doSwitch(EObject)
	 * @generated
	 */
	public T caseDiscoveryCache(DiscoveryCache object) {
		return null;
	}

	/**
	 * Returns the result of interpreting the object as an instance of '<em>Binding Cache</em>'.
	 * <!-- begin-user-doc -->
	 * This implementation returns null;
	 * returning a non-null result will terminate the switch.
	 * <!-- end-user-doc -->
	 * @param object the target of the switch.
	 * @return the result of interpreting the object as an instance of '<em>Binding Cache</em>'.
	 * @see #doSwitch(org.eclipse.emf.ecore.EObject) doSwitch(EObject)
	 * @generated
	 */
	public T caseBindingCache(BindingCache object) {
		return null;
	}

	/**
	 * Returns the result of interpreting the object as an instance of '<em>Named Object</em>'.
	 * <!-- begin-user-doc -->
	 * This implementation returns null;
	 * returning a non-null result will terminate the switch.
	 * <!-- end-user-doc -->
	 * @param object the target of the switch.
	 * @return the result of interpreting the object as an instance of '<em>Named Object</em>'.
	 * @see #doSwitch(org.eclipse.emf.ecore.EObject) doSwitch(EObject)
	 * @generated
	 */
	public T caseNamedObject(NamedObject object) {
		return null;
	}

	/**
	 * Returns the result of interpreting the object as an instance of '<em>Child Nodes</em>'.
	 * <!-- begin-user-doc -->
	 * This implementation returns null;
	 * returning a non-null result will terminate the switch.
	 * <!-- end-user-doc -->
	 * @param object the target of the switch.
	 * @return the result of interpreting the object as an instance of '<em>Child Nodes</em>'.
	 * @see #doSwitch(org.eclipse.emf.ecore.EObject) doSwitch(EObject)
	 * @generated
	 */
	public T caseChildNodes(ChildNodes object) {
		return null;
	}

	/**
	 * Returns the result of interpreting the object as an instance of '<em>APDU</em>'.
	 * <!-- begin-user-doc -->
	 * This implementation returns null;
	 * returning a non-null result will terminate the switch.
	 * <!-- end-user-doc -->
	 * @param object the target of the switch.
	 * @return the result of interpreting the object as an instance of '<em>APDU</em>'.
	 * @see #doSwitch(org.eclipse.emf.ecore.EObject) doSwitch(EObject)
	 * @generated
	 */
	public T caseAPDU(APDU object) {
		return null;
	}

	/**
	 * Returns the result of interpreting the object as an instance of '<em>PDU Manager</em>'.
	 * <!-- begin-user-doc -->
	 * This implementation returns null;
	 * returning a non-null result will terminate the switch.
	 * <!-- end-user-doc -->
	 * @param object the target of the switch.
	 * @return the result of interpreting the object as an instance of '<em>PDU Manager</em>'.
	 * @see #doSwitch(org.eclipse.emf.ecore.EObject) doSwitch(EObject)
	 * @generated
	 */
	public T casePDUManager(PDUManager object) {
		return null;
	}

	/**
	 * Returns the result of interpreting the object as an instance of '<em>Channel Mask</em>'.
	 * <!-- begin-user-doc -->
	 * This implementation returns null;
	 * returning a non-null result will terminate the switch.
	 * <!-- end-user-doc -->
	 * @param object the target of the switch.
	 * @return the result of interpreting the object as an instance of '<em>Channel Mask</em>'.
	 * @see #doSwitch(org.eclipse.emf.ecore.EObject) doSwitch(EObject)
	 * @generated
	 */
	public T caseChannelMask(ChannelMask object) {
		return null;
	}

	/**
	 * Returns the result of interpreting the object as an instance of '<em>ZDO Client Server</em>'.
	 * <!-- begin-user-doc -->
	 * This implementation returns null;
	 * returning a non-null result will terminate the switch.
	 * <!-- end-user-doc -->
	 * @param object the target of the switch.
	 * @return the result of interpreting the object as an instance of '<em>ZDO Client Server</em>'.
	 * @see #doSwitch(org.eclipse.emf.ecore.EObject) doSwitch(EObject)
	 * @generated
	 */
	public T caseZDOClientServer(ZDOClientServer object) {
		return null;
	}

	/**
	 * Returns the result of interpreting the object as an instance of '<em>ZDO Servers Coordinator</em>'.
	 * <!-- begin-user-doc -->
	 * This implementation returns null;
	 * returning a non-null result will terminate the switch.
	 * <!-- end-user-doc -->
	 * @param object the target of the switch.
	 * @return the result of interpreting the object as an instance of '<em>ZDO Servers Coordinator</em>'.
	 * @see #doSwitch(org.eclipse.emf.ecore.EObject) doSwitch(EObject)
	 * @generated
	 */
	public T caseZDOServersCoordinator(ZDOServersCoordinator object) {
		return null;
	}

	/**
	 * Returns the result of interpreting the object as an instance of '<em>End Device Bind Server</em>'.
	 * <!-- begin-user-doc -->
	 * This implementation returns null;
	 * returning a non-null result will terminate the switch.
	 * <!-- end-user-doc -->
	 * @param object the target of the switch.
	 * @return the result of interpreting the object as an instance of '<em>End Device Bind Server</em>'.
	 * @see #doSwitch(org.eclipse.emf.ecore.EObject) doSwitch(EObject)
	 * @generated
	 */
	public T caseEndDeviceBindServer(EndDeviceBindServer object) {
		return null;
	}

	/**
	 * Returns the result of interpreting the object as an instance of '<em>ZDO Servers Router</em>'.
	 * <!-- begin-user-doc -->
	 * This implementation returns null;
	 * returning a non-null result will terminate the switch.
	 * <!-- end-user-doc -->
	 * @param object the target of the switch.
	 * @return the result of interpreting the object as an instance of '<em>ZDO Servers Router</em>'.
	 * @see #doSwitch(org.eclipse.emf.ecore.EObject) doSwitch(EObject)
	 * @generated
	 */
	public T caseZDOServersRouter(ZDOServersRouter object) {
		return null;
	}

	/**
	 * Returns the result of interpreting the object as an instance of '<em>ZDO Servers End Device</em>'.
	 * <!-- begin-user-doc -->
	 * This implementation returns null;
	 * returning a non-null result will terminate the switch.
	 * <!-- end-user-doc -->
	 * @param object the target of the switch.
	 * @return the result of interpreting the object as an instance of '<em>ZDO Servers End Device</em>'.
	 * @see #doSwitch(org.eclipse.emf.ecore.EObject) doSwitch(EObject)
	 * @generated
	 */
	public T caseZDOServersEndDevice(ZDOServersEndDevice object) {
		return null;
	}

	/**
	 * Returns the result of interpreting the object as an instance of '<em>Default Server</em>'.
	 * <!-- begin-user-doc -->
	 * This implementation returns null;
	 * returning a non-null result will terminate the switch.
	 * <!-- end-user-doc -->
	 * @param object the target of the switch.
	 * @return the result of interpreting the object as an instance of '<em>Default Server</em>'.
	 * @see #doSwitch(org.eclipse.emf.ecore.EObject) doSwitch(EObject)
	 * @generated
	 */
	public T caseDefaultServer(DefaultServer object) {
		return null;
	}

	/**
	 * Returns the result of interpreting the object as an instance of '<em>Device Annce Server</em>'.
	 * <!-- begin-user-doc -->
	 * This implementation returns null;
	 * returning a non-null result will terminate the switch.
	 * <!-- end-user-doc -->
	 * @param object the target of the switch.
	 * @return the result of interpreting the object as an instance of '<em>Device Annce Server</em>'.
	 * @see #doSwitch(org.eclipse.emf.ecore.EObject) doSwitch(EObject)
	 * @generated
	 */
	public T caseDeviceAnnceServer(DeviceAnnceServer object) {
		return null;
	}

	/**
	 * Returns the result of interpreting the object as an instance of '<em>Active Ep Server</em>'.
	 * <!-- begin-user-doc -->
	 * This implementation returns null;
	 * returning a non-null result will terminate the switch.
	 * <!-- end-user-doc -->
	 * @param object the target of the switch.
	 * @return the result of interpreting the object as an instance of '<em>Active Ep Server</em>'.
	 * @see #doSwitch(org.eclipse.emf.ecore.EObject) doSwitch(EObject)
	 * @generated
	 */
	public T caseActiveEpServer(ActiveEpServer object) {
		return null;
	}

	/**
	 * Returns the result of interpreting the object as an instance of '<em>Nwk Addr Server</em>'.
	 * <!-- begin-user-doc -->
	 * This implementation returns null;
	 * returning a non-null result will terminate the switch.
	 * <!-- end-user-doc -->
	 * @param object the target of the switch.
	 * @return the result of interpreting the object as an instance of '<em>Nwk Addr Server</em>'.
	 * @see #doSwitch(org.eclipse.emf.ecore.EObject) doSwitch(EObject)
	 * @generated
	 */
	public T caseNwkAddrServer(NwkAddrServer object) {
		return null;
	}

	/**
	 * Returns the result of interpreting the object as an instance of '<em>Ieee Addr Server</em>'.
	 * <!-- begin-user-doc -->
	 * This implementation returns null;
	 * returning a non-null result will terminate the switch.
	 * <!-- end-user-doc -->
	 * @param object the target of the switch.
	 * @return the result of interpreting the object as an instance of '<em>Ieee Addr Server</em>'.
	 * @see #doSwitch(org.eclipse.emf.ecore.EObject) doSwitch(EObject)
	 * @generated
	 */
	public T caseIeeeAddrServer(IeeeAddrServer object) {
		return null;
	}

	/**
	 * Returns the result of interpreting the object as an instance of '<em>Match Desc Server</em>'.
	 * <!-- begin-user-doc -->
	 * This implementation returns null;
	 * returning a non-null result will terminate the switch.
	 * <!-- end-user-doc -->
	 * @param object the target of the switch.
	 * @return the result of interpreting the object as an instance of '<em>Match Desc Server</em>'.
	 * @see #doSwitch(org.eclipse.emf.ecore.EObject) doSwitch(EObject)
	 * @generated
	 */
	public T caseMatchDescServer(MatchDescServer object) {
		return null;
	}

	/**
	 * Returns the result of interpreting the object as an instance of '<em>Node Desc Server</em>'.
	 * <!-- begin-user-doc -->
	 * This implementation returns null;
	 * returning a non-null result will terminate the switch.
	 * <!-- end-user-doc -->
	 * @param object the target of the switch.
	 * @return the result of interpreting the object as an instance of '<em>Node Desc Server</em>'.
	 * @see #doSwitch(org.eclipse.emf.ecore.EObject) doSwitch(EObject)
	 * @generated
	 */
	public T caseNodeDescServer(NodeDescServer object) {
		return null;
	}

	/**
	 * Returns the result of interpreting the object as an instance of '<em>Permit Joining Server</em>'.
	 * <!-- begin-user-doc -->
	 * This implementation returns null;
	 * returning a non-null result will terminate the switch.
	 * <!-- end-user-doc -->
	 * @param object the target of the switch.
	 * @return the result of interpreting the object as an instance of '<em>Permit Joining Server</em>'.
	 * @see #doSwitch(org.eclipse.emf.ecore.EObject) doSwitch(EObject)
	 * @generated
	 */
	public T casePermitJoiningServer(PermitJoiningServer object) {
		return null;
	}

	/**
	 * Returns the result of interpreting the object as an instance of '<em>Power Desc Server</em>'.
	 * <!-- begin-user-doc -->
	 * This implementation returns null;
	 * returning a non-null result will terminate the switch.
	 * <!-- end-user-doc -->
	 * @param object the target of the switch.
	 * @return the result of interpreting the object as an instance of '<em>Power Desc Server</em>'.
	 * @see #doSwitch(org.eclipse.emf.ecore.EObject) doSwitch(EObject)
	 * @generated
	 */
	public T casePowerDescServer(PowerDescServer object) {
		return null;
	}

	/**
	 * Returns the result of interpreting the object as an instance of '<em>Simple Desc Server</em>'.
	 * <!-- begin-user-doc -->
	 * This implementation returns null;
	 * returning a non-null result will terminate the switch.
	 * <!-- end-user-doc -->
	 * @param object the target of the switch.
	 * @return the result of interpreting the object as an instance of '<em>Simple Desc Server</em>'.
	 * @see #doSwitch(org.eclipse.emf.ecore.EObject) doSwitch(EObject)
	 * @generated
	 */
	public T caseSimpleDescServer(SimpleDescServer object) {
		return null;
	}

	/**
	 * Returns the result of interpreting the object as an instance of '<em>System Server Discovery Server</em>'.
	 * <!-- begin-user-doc -->
	 * This implementation returns null;
	 * returning a non-null result will terminate the switch.
	 * <!-- end-user-doc -->
	 * @param object the target of the switch.
	 * @return the result of interpreting the object as an instance of '<em>System Server Discovery Server</em>'.
	 * @see #doSwitch(org.eclipse.emf.ecore.EObject) doSwitch(EObject)
	 * @generated
	 */
	public T caseSystemServerDiscoveryServer(SystemServerDiscoveryServer object) {
		return null;
	}

	/**
	 * Returns the result of interpreting the object as an instance of '<em>Mgmt Lqi Server</em>'.
	 * <!-- begin-user-doc -->
	 * This implementation returns null;
	 * returning a non-null result will terminate the switch.
	 * <!-- end-user-doc -->
	 * @param object the target of the switch.
	 * @return the result of interpreting the object as an instance of '<em>Mgmt Lqi Server</em>'.
	 * @see #doSwitch(org.eclipse.emf.ecore.EObject) doSwitch(EObject)
	 * @generated
	 */
	public T caseMgmtLqiServer(MgmtLqiServer object) {
		return null;
	}

	/**
	 * Returns the result of interpreting the object as an instance of '<em>Mgmt Rtg Server</em>'.
	 * <!-- begin-user-doc -->
	 * This implementation returns null;
	 * returning a non-null result will terminate the switch.
	 * <!-- end-user-doc -->
	 * @param object the target of the switch.
	 * @return the result of interpreting the object as an instance of '<em>Mgmt Rtg Server</em>'.
	 * @see #doSwitch(org.eclipse.emf.ecore.EObject) doSwitch(EObject)
	 * @generated
	 */
	public T caseMgmtRtgServer(MgmtRtgServer object) {
		return null;
	}

	/**
	 * Returns the result of interpreting the object as an instance of '<em>Mgmt Leave Server</em>'.
	 * <!-- begin-user-doc -->
	 * This implementation returns null;
	 * returning a non-null result will terminate the switch.
	 * <!-- end-user-doc -->
	 * @param object the target of the switch.
	 * @return the result of interpreting the object as an instance of '<em>Mgmt Leave Server</em>'.
	 * @see #doSwitch(org.eclipse.emf.ecore.EObject) doSwitch(EObject)
	 * @generated
	 */
	public T caseMgmtLeaveServer(MgmtLeaveServer object) {
		return null;
	}

	/**
	 * Returns the result of interpreting the object as an instance of '<em>Node Descriptor</em>'.
	 * <!-- begin-user-doc -->
	 * This implementation returns null;
	 * returning a non-null result will terminate the switch.
	 * <!-- end-user-doc -->
	 * @param object the target of the switch.
	 * @return the result of interpreting the object as an instance of '<em>Node Descriptor</em>'.
	 * @see #doSwitch(org.eclipse.emf.ecore.EObject) doSwitch(EObject)
	 * @generated
	 */
	public T caseNodeDescriptor(NodeDescriptor object) {
		return null;
	}

	/**
	 * Returns the result of interpreting the object as an instance of '<em>Node Power Descriptor</em>'.
	 * <!-- begin-user-doc -->
	 * This implementation returns null;
	 * returning a non-null result will terminate the switch.
	 * <!-- end-user-doc -->
	 * @param object the target of the switch.
	 * @return the result of interpreting the object as an instance of '<em>Node Power Descriptor</em>'.
	 * @see #doSwitch(org.eclipse.emf.ecore.EObject) doSwitch(EObject)
	 * @generated
	 */
	public T caseNodePowerDescriptor(NodePowerDescriptor object) {
		return null;
	}

	/**
	 * Returns the result of interpreting the object as an instance of '<em>Bind Unbind Server</em>'.
	 * <!-- begin-user-doc -->
	 * This implementation returns null;
	 * returning a non-null result will terminate the switch.
	 * <!-- end-user-doc -->
	 * @param object the target of the switch.
	 * @return the result of interpreting the object as an instance of '<em>Bind Unbind Server</em>'.
	 * @see #doSwitch(org.eclipse.emf.ecore.EObject) doSwitch(EObject)
	 * @generated
	 */
	public T caseBindUnbindServer(BindUnbindServer object) {
		return null;
	}

	/**
	 * Returns the result of interpreting the object as an instance of '<em>Mgmt Bind Server</em>'.
	 * <!-- begin-user-doc -->
	 * This implementation returns null;
	 * returning a non-null result will terminate the switch.
	 * <!-- end-user-doc -->
	 * @param object the target of the switch.
	 * @return the result of interpreting the object as an instance of '<em>Mgmt Bind Server</em>'.
	 * @see #doSwitch(org.eclipse.emf.ecore.EObject) doSwitch(EObject)
	 * @generated
	 */
	public T caseMgmtBindServer(MgmtBindServer object) {
		return null;
	}

	/**
	 * Returns the result of interpreting the object as an instance of '<em>Extended Active Ep Server</em>'.
	 * <!-- begin-user-doc -->
	 * This implementation returns null;
	 * returning a non-null result will terminate the switch.
	 * <!-- end-user-doc -->
	 * @param object the target of the switch.
	 * @return the result of interpreting the object as an instance of '<em>Extended Active Ep Server</em>'.
	 * @see #doSwitch(org.eclipse.emf.ecore.EObject) doSwitch(EObject)
	 * @generated
	 */
	public T caseExtendedActiveEpServer(ExtendedActiveEpServer object) {
		return null;
	}

	/**
	 * Returns the result of interpreting the object as an instance of '<em>Extended Simple Desc Server</em>'.
	 * <!-- begin-user-doc -->
	 * This implementation returns null;
	 * returning a non-null result will terminate the switch.
	 * <!-- end-user-doc -->
	 * @param object the target of the switch.
	 * @return the result of interpreting the object as an instance of '<em>Extended Simple Desc Server</em>'.
	 * @see #doSwitch(org.eclipse.emf.ecore.EObject) doSwitch(EObject)
	 * @generated
	 */
	public T caseExtendedSimpleDescServer(ExtendedSimpleDescServer object) {
		return null;
	}

	/**
	 * Returns the result of interpreting the object as an instance of '<em>Zdo Client</em>'.
	 * <!-- begin-user-doc -->
	 * This implementation returns null;
	 * returning a non-null result will terminate the switch.
	 * <!-- end-user-doc -->
	 * @param object the target of the switch.
	 * @return the result of interpreting the object as an instance of '<em>Zdo Client</em>'.
	 * @see #doSwitch(org.eclipse.emf.ecore.EObject) doSwitch(EObject)
	 * @generated
	 */
	public T caseZdoClient(ZdoClient object) {
		return null;
	}

	/**
	 * Returns the result of interpreting the object as an instance of '<em>Mgmt NWK Update Server</em>'.
	 * <!-- begin-user-doc -->
	 * This implementation returns null;
	 * returning a non-null result will terminate the switch.
	 * <!-- end-user-doc -->
	 * @param object the target of the switch.
	 * @return the result of interpreting the object as an instance of '<em>Mgmt NWK Update Server</em>'.
	 * @see #doSwitch(org.eclipse.emf.ecore.EObject) doSwitch(EObject)
	 * @generated
	 */
	public T caseMgmtNWKUpdateServer(MgmtNWKUpdateServer object) {
		return null;
	}

	/**
	 * Returns the result of interpreting the object as an instance of '<em>ZDO Common Servers</em>'.
	 * <!-- begin-user-doc -->
	 * This implementation returns null;
	 * returning a non-null result will terminate the switch.
	 * <!-- end-user-doc -->
	 * @param object the target of the switch.
	 * @return the result of interpreting the object as an instance of '<em>ZDO Common Servers</em>'.
	 * @see #doSwitch(org.eclipse.emf.ecore.EObject) doSwitch(EObject)
	 * @generated
	 */
	public T caseZDOCommonServers(ZDOCommonServers object) {
		return null;
	}

	/**
	 * Returns the result of interpreting the object as an instance of '<em>Not Implemented</em>'.
	 * <!-- begin-user-doc -->
	 * This implementation returns null;
	 * returning a non-null result will terminate the switch.
	 * <!-- end-user-doc -->
	 * @param object the target of the switch.
	 * @return the result of interpreting the object as an instance of '<em>Not Implemented</em>'.
	 * @see #doSwitch(org.eclipse.emf.ecore.EObject) doSwitch(EObject)
	 * @generated
	 */
	public T caseNotImplemented(NotImplemented object) {
		return null;
	}

	/**
	 * Returns the result of interpreting the object as an instance of '<em>Key Descriptor Table</em>'.
	 * <!-- begin-user-doc -->
	 * This implementation returns null;
	 * returning a non-null result will terminate the switch.
	 * <!-- end-user-doc -->
	 * @param object the target of the switch.
	 * @return the result of interpreting the object as an instance of '<em>Key Descriptor Table</em>'.
	 * @see #doSwitch(org.eclipse.emf.ecore.EObject) doSwitch(EObject)
	 * @generated
	 */
	public T caseKeyDescriptorTable(KeyDescriptorTable object) {
		return null;
	}

	/**
	 * Returns the result of interpreting the object as an instance of '<em>Preconfigured Key</em>'.
	 * <!-- begin-user-doc -->
	 * This implementation returns null;
	 * returning a non-null result will terminate the switch.
	 * <!-- end-user-doc -->
	 * @param object the target of the switch.
	 * @return the result of interpreting the object as an instance of '<em>Preconfigured Key</em>'.
	 * @see #doSwitch(org.eclipse.emf.ecore.EObject) doSwitch(EObject)
	 * @generated
	 */
	public T casePreconfiguredKey(PreconfiguredKey object) {
		return null;
	}

	/**
	 * Returns the result of interpreting the object as an instance of '<em>ZDO Coord Router Only Servers</em>'.
	 * <!-- begin-user-doc -->
	 * This implementation returns null;
	 * returning a non-null result will terminate the switch.
	 * <!-- end-user-doc -->
	 * @param object the target of the switch.
	 * @return the result of interpreting the object as an instance of '<em>ZDO Coord Router Only Servers</em>'.
	 * @see #doSwitch(org.eclipse.emf.ecore.EObject) doSwitch(EObject)
	 * @generated
	 */
	public T caseZDOCoordRouterOnlyServers(ZDOCoordRouterOnlyServers object) {
		return null;
	}

	/**
	 * Returns the result of interpreting the object as an instance of '<em>Pre Configured Nwk Key</em>'.
	 * <!-- begin-user-doc -->
	 * This implementation returns null;
	 * returning a non-null result will terminate the switch.
	 * <!-- end-user-doc -->
	 * @param object the target of the switch.
	 * @return the result of interpreting the object as an instance of '<em>Pre Configured Nwk Key</em>'.
	 * @see #doSwitch(org.eclipse.emf.ecore.EObject) doSwitch(EObject)
	 * @generated
	 */
	public T casePreConfiguredNwkKey(PreConfiguredNwkKey object) {
		return null;
	}

	/**
	 * Returns the result of interpreting the object as an instance of '<em>Default Nwk Key</em>'.
	 * <!-- begin-user-doc -->
	 * This implementation returns null;
	 * returning a non-null result will terminate the switch.
	 * <!-- end-user-doc -->
	 * @param object the target of the switch.
	 * @return the result of interpreting the object as an instance of '<em>Default Nwk Key</em>'.
	 * @see #doSwitch(org.eclipse.emf.ecore.EObject) doSwitch(EObject)
	 * @generated
	 */
	public T caseDefaultNwkKey(DefaultNwkKey object) {
		return null;
	}

	/**
	 * Returns the result of interpreting the object as an instance of '<em>Nwk Key</em>'.
	 * <!-- begin-user-doc -->
	 * This implementation returns null;
	 * returning a non-null result will terminate the switch.
	 * <!-- end-user-doc -->
	 * @param object the target of the switch.
	 * @return the result of interpreting the object as an instance of '<em>Nwk Key</em>'.
	 * @see #doSwitch(org.eclipse.emf.ecore.EObject) doSwitch(EObject)
	 * @generated
	 */
	public T caseNwkKey(NwkKey object) {
		return null;
	}

	/**
	 * Returns the result of interpreting the object as an instance of '<em>Preconfigured TC Link Key</em>'.
	 * <!-- begin-user-doc -->
	 * This implementation returns null;
	 * returning a non-null result will terminate the switch.
	 * <!-- end-user-doc -->
	 * @param object the target of the switch.
	 * @return the result of interpreting the object as an instance of '<em>Preconfigured TC Link Key</em>'.
	 * @see #doSwitch(org.eclipse.emf.ecore.EObject) doSwitch(EObject)
	 * @generated
	 */
	public T casePreconfiguredTCLinkKey(PreconfiguredTCLinkKey object) {
		return null;
	}

	/**
	 * Returns the result of interpreting the object as an instance of '<em>TC Key</em>'.
	 * <!-- begin-user-doc -->
	 * This implementation returns null;
	 * returning a non-null result will terminate the switch.
	 * <!-- end-user-doc -->
	 * @param object the target of the switch.
	 * @return the result of interpreting the object as an instance of '<em>TC Key</em>'.
	 * @see #doSwitch(org.eclipse.emf.ecore.EObject) doSwitch(EObject)
	 * @generated
	 */
	public T caseTCKey(TCKey object) {
		return null;
	}

	/**
	 * Returns the result of interpreting the object as an instance of '<em>Bind Request Server</em>'.
	 * <!-- begin-user-doc -->
	 * This implementation returns null;
	 * returning a non-null result will terminate the switch.
	 * <!-- end-user-doc -->
	 * @param object the target of the switch.
	 * @return the result of interpreting the object as an instance of '<em>Bind Request Server</em>'.
	 * @see #doSwitch(org.eclipse.emf.ecore.EObject) doSwitch(EObject)
	 * @generated
	 */
	public T caseBindRequestServer(BindRequestServer object) {
		return null;
	}

	/**
	 * Returns the result of interpreting the object as an instance of '<em>Green Power Security Table</em>'.
	 * <!-- begin-user-doc -->
	 * This implementation returns null;
	 * returning a non-null result will terminate the switch.
	 * <!-- end-user-doc -->
	 * @param object the target of the switch.
	 * @return the result of interpreting the object as an instance of '<em>Green Power Security Table</em>'.
	 * @see #doSwitch(org.eclipse.emf.ecore.EObject) doSwitch(EObject)
	 * @generated
	 */
	public T caseGreenPowerSecurityTable(GreenPowerSecurityTable object) {
		return null;
	}

	/**
	 * Returns the result of interpreting the object as an instance of '<em>Green Power Tx Queue</em>'.
	 * <!-- begin-user-doc -->
	 * This implementation returns null;
	 * returning a non-null result will terminate the switch.
	 * <!-- end-user-doc -->
	 * @param object the target of the switch.
	 * @return the result of interpreting the object as an instance of '<em>Green Power Tx Queue</em>'.
	 * @see #doSwitch(org.eclipse.emf.ecore.EObject) doSwitch(EObject)
	 * @generated
	 */
	public T caseGreenPowerTxQueue(GreenPowerTxQueue object) {
		return null;
	}

	/**
	 * Returns the result of interpreting the object as an instance of '<em>Mgmt Mib Ieee Server</em>'.
	 * <!-- begin-user-doc -->
	 * This implementation returns null;
	 * returning a non-null result will terminate the switch.
	 * <!-- end-user-doc -->
	 * @param object the target of the switch.
	 * @return the result of interpreting the object as an instance of '<em>Mgmt Mib Ieee Server</em>'.
	 * @see #doSwitch(org.eclipse.emf.ecore.EObject) doSwitch(EObject)
	 * @generated
	 */
	public T caseMgmtMibIeeeServer(MgmtMibIeeeServer object) {
		return null;
	}

	/**
	 * Returns the result of interpreting the object as an instance of '<em>Mgmt NWK Enhance Update Server</em>'.
	 * <!-- begin-user-doc -->
	 * This implementation returns null;
	 * returning a non-null result will terminate the switch.
	 * <!-- end-user-doc -->
	 * @param object the target of the switch.
	 * @return the result of interpreting the object as an instance of '<em>Mgmt NWK Enhance Update Server</em>'.
	 * @see #doSwitch(org.eclipse.emf.ecore.EObject) doSwitch(EObject)
	 * @generated
	 */
	public T caseMgmtNWKEnhanceUpdateServer(MgmtNWKEnhanceUpdateServer object) {
		return null;
	}

	/**
	 * Returns the result of interpreting the object as an instance of '<em>Mac Interface List</em>'.
	 * <!-- begin-user-doc -->
	 * This implementation returns null;
	 * returning a non-null result will terminate the switch.
	 * <!-- end-user-doc -->
	 * @param object the target of the switch.
	 * @return the result of interpreting the object as an instance of '<em>Mac Interface List</em>'.
	 * @see #doSwitch(org.eclipse.emf.ecore.EObject) doSwitch(EObject)
	 * @generated
	 */
	public T caseMacInterfaceList(MacInterfaceList object) {
		return null;
	}

	/**
	 * Returns the result of interpreting the object as an instance of '<em>Mac Interface</em>'.
	 * <!-- begin-user-doc -->
	 * This implementation returns null;
	 * returning a non-null result will terminate the switch.
	 * <!-- end-user-doc -->
	 * @param object the target of the switch.
	 * @return the result of interpreting the object as an instance of '<em>Mac Interface</em>'.
	 * @see #doSwitch(org.eclipse.emf.ecore.EObject) doSwitch(EObject)
	 * @generated
	 */
	public T caseMacInterface(MacInterface object) {
		return null;
	}

	/**
	 * Returns the result of interpreting the object as an instance of '<em>Parent Annce Server</em>'.
	 * <!-- begin-user-doc -->
	 * This implementation returns null;
	 * returning a non-null result will terminate the switch.
	 * <!-- end-user-doc -->
	 * @param object the target of the switch.
	 * @return the result of interpreting the object as an instance of '<em>Parent Annce Server</em>'.
	 * @see #doSwitch(org.eclipse.emf.ecore.EObject) doSwitch(EObject)
	 * @generated
	 */
	public T caseParentAnnceServer(ParentAnnceServer object) {
		return null;
	}

	/**
	 * Returns the result of interpreting the object as an instance of '<em>EObject</em>'.
	 * <!-- begin-user-doc -->
	 * This implementation returns null;
	 * returning a non-null result will terminate the switch, but this is the last case anyway.
	 * <!-- end-user-doc -->
	 * @param object the target of the switch.
	 * @return the result of interpreting the object as an instance of '<em>EObject</em>'.
	 * @see #doSwitch(org.eclipse.emf.ecore.EObject)
	 * @generated
	 */
	@Override
	public T defaultCase(EObject object) {
		return null;
	}

} //ZPSConfigurationSwitch
