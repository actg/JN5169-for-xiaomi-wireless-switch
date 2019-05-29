/**
 * (C) Jennic Ltd 2008
 *
 * $Id$
 */
package com.jennic.ZPSConfiguration.util;


import org.eclipse.emf.common.notify.Adapter;
import org.eclipse.emf.common.notify.Notifier;

import org.eclipse.emf.common.notify.impl.AdapterFactoryImpl;

import org.eclipse.emf.ecore.EObject;

import com.jennic.ZPSConfiguration.*;

/**
 * <!-- begin-user-doc -->
 * The <b>Adapter Factory</b> for the model.
 * It provides an adapter <code>createXXX</code> method for each class of the model.
 * <!-- end-user-doc -->
 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage
 * @generated
 */
public class ZPSConfigurationAdapterFactory extends AdapterFactoryImpl {
	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public static final String copyright = "(C) NXP B.V";
	/**
	 * The cached model package.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	protected static ZPSConfigurationPackage modelPackage;

	/**
	 * Creates an instance of the adapter factory.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public ZPSConfigurationAdapterFactory() {
		if (modelPackage == null) {
			modelPackage = ZPSConfigurationPackage.eINSTANCE;
		}
	}

	/**
	 * Returns whether this factory is applicable for the type of the object.
	 * <!-- begin-user-doc -->
	 * This implementation returns <code>true</code> if the object is either the model's package or is an instance object of the model.
	 * <!-- end-user-doc -->
	 * @return whether this factory is applicable for the type of the object.
	 * @generated
	 */
	@Override
	public boolean isFactoryForType(Object object) {
		if (object == modelPackage) {
			return true;
		}
		if (object instanceof EObject) {
			return ((EObject)object).eClass().getEPackage() == modelPackage;
		}
		return false;
	}

	/**
	 * The switch that delegates to the <code>createXXX</code> methods.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	protected ZPSConfigurationSwitch<Adapter> modelSwitch =
		new ZPSConfigurationSwitch<Adapter>() {
			@Override
			public Adapter caseProfile(Profile object) {
				return createProfileAdapter();
			}
			@Override
			public Adapter caseCluster(Cluster object) {
				return createClusterAdapter();
			}
			@Override
			public Adapter caseNode(Node object) {
				return createNodeAdapter();
			}
			@Override
			public Adapter caseCoordinator(Coordinator object) {
				return createCoordinatorAdapter();
			}
			@Override
			public Adapter caseRouter(Router object) {
				return createRouterAdapter();
			}
			@Override
			public Adapter caseEndDevice(EndDevice object) {
				return createEndDeviceAdapter();
			}
			@Override
			public Adapter caseEndPoint(EndPoint object) {
				return createEndPointAdapter();
			}
			@Override
			public Adapter casePrimaryDiscoveryCache(PrimaryDiscoveryCache object) {
				return createPrimaryDiscoveryCacheAdapter();
			}
			@Override
			public Adapter caseBackupDiscoveryCache(BackupDiscoveryCache object) {
				return createBackupDiscoveryCacheAdapter();
			}
			@Override
			public Adapter caseDiscoveryTable(DiscoveryTable object) {
				return createDiscoveryTableAdapter();
			}
			@Override
			public Adapter caseBindingTable(BindingTable object) {
				return createBindingTableAdapter();
			}
			@Override
			public Adapter caseGroupTable(GroupTable object) {
				return createGroupTableAdapter();
			}
			@Override
			public Adapter caseZigbeeWirelessNetwork(ZigbeeWirelessNetwork object) {
				return createZigbeeWirelessNetworkAdapter();
			}
			@Override
			public Adapter casePrimaryBindingCache(PrimaryBindingCache object) {
				return createPrimaryBindingCacheAdapter();
			}
			@Override
			public Adapter caseBackupBindingCache(BackupBindingCache object) {
				return createBackupBindingCacheAdapter();
			}
			@Override
			public Adapter casePrimaryGroupCache(PrimaryGroupCache object) {
				return createPrimaryGroupCacheAdapter();
			}
			@Override
			public Adapter caseBackupGroupCache(BackupGroupCache object) {
				return createBackupGroupCacheAdapter();
			}
			@Override
			public Adapter caseInputCluster(InputCluster object) {
				return createInputClusterAdapter();
			}
			@Override
			public Adapter caseOutputCluster(OutputCluster object) {
				return createOutputClusterAdapter();
			}
			@Override
			public Adapter caseAlwaysOnNode(AlwaysOnNode object) {
				return createAlwaysOnNodeAdapter();
			}
			@Override
			public Adapter caseComplexDescriptor(ComplexDescriptor object) {
				return createComplexDescriptorAdapter();
			}
			@Override
			public Adapter caseUserDescriptor(UserDescriptor object) {
				return createUserDescriptorAdapter();
			}
			@Override
			public Adapter caseTrustCenter(TrustCenter object) {
				return createTrustCenterAdapter();
			}
			@Override
			public Adapter caseDiscoveryCache(DiscoveryCache object) {
				return createDiscoveryCacheAdapter();
			}
			@Override
			public Adapter caseBindingCache(BindingCache object) {
				return createBindingCacheAdapter();
			}
			@Override
			public Adapter caseNamedObject(NamedObject object) {
				return createNamedObjectAdapter();
			}
			@Override
			public Adapter caseChildNodes(ChildNodes object) {
				return createChildNodesAdapter();
			}
			@Override
			public Adapter caseAPDU(APDU object) {
				return createAPDUAdapter();
			}
			@Override
			public Adapter casePDUManager(PDUManager object) {
				return createPDUManagerAdapter();
			}
			@Override
			public Adapter caseChannelMask(ChannelMask object) {
				return createChannelMaskAdapter();
			}
			@Override
			public Adapter caseZDOClientServer(ZDOClientServer object) {
				return createZDOClientServerAdapter();
			}
			@Override
			public Adapter caseZDOServersCoordinator(ZDOServersCoordinator object) {
				return createZDOServersCoordinatorAdapter();
			}
			@Override
			public Adapter caseZDOServersRouter(ZDOServersRouter object) {
				return createZDOServersRouterAdapter();
			}
			@Override
			public Adapter caseZDOServersEndDevice(ZDOServersEndDevice object) {
				return createZDOServersEndDeviceAdapter();
			}
			@Override
			public Adapter caseDefaultServer(DefaultServer object) {
				return createDefaultServerAdapter();
			}
			@Override
			public Adapter caseEndDeviceBindServer(EndDeviceBindServer object) {
				return createEndDeviceBindServerAdapter();
			}
			@Override
			public Adapter caseDeviceAnnceServer(DeviceAnnceServer object) {
				return createDeviceAnnceServerAdapter();
			}
			@Override
			public Adapter caseActiveEpServer(ActiveEpServer object) {
				return createActiveEpServerAdapter();
			}
			@Override
			public Adapter caseNwkAddrServer(NwkAddrServer object) {
				return createNwkAddrServerAdapter();
			}
			@Override
			public Adapter caseIeeeAddrServer(IeeeAddrServer object) {
				return createIeeeAddrServerAdapter();
			}
			@Override
			public Adapter caseMatchDescServer(MatchDescServer object) {
				return createMatchDescServerAdapter();
			}
			@Override
			public Adapter caseNodeDescServer(NodeDescServer object) {
				return createNodeDescServerAdapter();
			}
			@Override
			public Adapter casePermitJoiningServer(PermitJoiningServer object) {
				return createPermitJoiningServerAdapter();
			}
			@Override
			public Adapter casePowerDescServer(PowerDescServer object) {
				return createPowerDescServerAdapter();
			}
			@Override
			public Adapter caseSimpleDescServer(SimpleDescServer object) {
				return createSimpleDescServerAdapter();
			}
			@Override
			public Adapter caseSystemServerDiscoveryServer(SystemServerDiscoveryServer object) {
				return createSystemServerDiscoveryServerAdapter();
			}
			@Override
			public Adapter caseMgmtLqiServer(MgmtLqiServer object) {
				return createMgmtLqiServerAdapter();
			}
			@Override
			public Adapter caseMgmtRtgServer(MgmtRtgServer object) {
				return createMgmtRtgServerAdapter();
			}
			@Override
			public Adapter caseMgmtLeaveServer(MgmtLeaveServer object) {
				return createMgmtLeaveServerAdapter();
			}
			@Override
			public Adapter caseNodeDescriptor(NodeDescriptor object) {
				return createNodeDescriptorAdapter();
			}
			@Override
			public Adapter caseNodePowerDescriptor(NodePowerDescriptor object) {
				return createNodePowerDescriptorAdapter();
			}
			@Override
			public Adapter caseBindUnbindServer(BindUnbindServer object) {
				return createBindUnbindServerAdapter();
			}
			@Override
			public Adapter caseMgmtBindServer(MgmtBindServer object) {
				return createMgmtBindServerAdapter();
			}
			@Override
			public Adapter caseExtendedActiveEpServer(ExtendedActiveEpServer object) {
				return createExtendedActiveEpServerAdapter();
			}
			@Override
			public Adapter caseExtendedSimpleDescServer(ExtendedSimpleDescServer object) {
				return createExtendedSimpleDescServerAdapter();
			}
			@Override
			public Adapter caseZdoClient(ZdoClient object) {
				return createZdoClientAdapter();
			}
			@Override
			public Adapter caseMgmtNWKUpdateServer(MgmtNWKUpdateServer object) {
				return createMgmtNWKUpdateServerAdapter();
			}
			@Override
			public Adapter caseZDOCommonServers(ZDOCommonServers object) {
				return createZDOCommonServersAdapter();
			}
			@Override
			public Adapter caseNotImplemented(NotImplemented object) {
				return createNotImplementedAdapter();
			}
			@Override
			public Adapter caseKeyDescriptorTable(KeyDescriptorTable object) {
				return createKeyDescriptorTableAdapter();
			}
			@Override
			public Adapter casePreconfiguredKey(PreconfiguredKey object) {
				return createPreconfiguredKeyAdapter();
			}
			@Override
			public Adapter caseZDOCoordRouterOnlyServers(ZDOCoordRouterOnlyServers object) {
				return createZDOCoordRouterOnlyServersAdapter();
			}
			@Override
			public Adapter casePreConfiguredNwkKey(PreConfiguredNwkKey object) {
				return createPreConfiguredNwkKeyAdapter();
			}
			@Override
			public Adapter caseDefaultNwkKey(DefaultNwkKey object) {
				return createDefaultNwkKeyAdapter();
			}
			@Override
			public Adapter caseNwkKey(NwkKey object) {
				return createNwkKeyAdapter();
			}
			@Override
			public Adapter casePreconfiguredTCLinkKey(PreconfiguredTCLinkKey object) {
				return createPreconfiguredTCLinkKeyAdapter();
			}
			@Override
			public Adapter caseTCKey(TCKey object) {
				return createTCKeyAdapter();
			}
			@Override
			public Adapter caseBindRequestServer(BindRequestServer object) {
				return createBindRequestServerAdapter();
			}
			@Override
			public Adapter caseGreenPowerSecurityTable(GreenPowerSecurityTable object) {
				return createGreenPowerSecurityTableAdapter();
			}
			@Override
			public Adapter caseGreenPowerTxQueue(GreenPowerTxQueue object) {
				return createGreenPowerTxQueueAdapter();
			}
			@Override
			public Adapter caseMgmtMibIeeeServer(MgmtMibIeeeServer object) {
				return createMgmtMibIeeeServerAdapter();
			}
			@Override
			public Adapter caseParentAnnceServer(ParentAnnceServer object) {
				return createParentAnnceServerAdapter();
			}
			@Override
			public Adapter caseMgmtNWKEnhanceUpdateServer(MgmtNWKEnhanceUpdateServer object) {
				return createMgmtNWKEnhanceUpdateServerAdapter();
			}
			@Override
			public Adapter caseMacInterfaceList(MacInterfaceList object) {
				return createMacInterfaceListAdapter();
			}
			@Override
			public Adapter caseMacInterface(MacInterface object) {
				return createMacInterfaceAdapter();
			}
			@Override
			public Adapter defaultCase(EObject object) {
				return createEObjectAdapter();
			}
		};

	/**
	 * Creates an adapter for the <code>target</code>.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param target the object to adapt.
	 * @return the adapter for the <code>target</code>.
	 * @generated
	 */
	@Override
	public Adapter createAdapter(Notifier target) {
		return modelSwitch.doSwitch((EObject)target);
	}


	/**
	 * Creates a new adapter for an object of class '{@link com.jennic.ZPSConfiguration.Profile <em>Profile</em>}'.
	 * <!-- begin-user-doc -->
	 * This default implementation returns null so that we can easily ignore cases;
	 * it's useful to ignore a case when inheritance will catch all the cases anyway.
	 * <!-- end-user-doc -->
	 * @return the new adapter.
	 * @see com.jennic.ZPSConfiguration.Profile
	 * @generated
	 */
	public Adapter createProfileAdapter() {
		return null;
	}

	/**
	 * Creates a new adapter for an object of class '{@link com.jennic.ZPSConfiguration.Cluster <em>Cluster</em>}'.
	 * <!-- begin-user-doc -->
	 * This default implementation returns null so that we can easily ignore cases;
	 * it's useful to ignore a case when inheritance will catch all the cases anyway.
	 * <!-- end-user-doc -->
	 * @return the new adapter.
	 * @see com.jennic.ZPSConfiguration.Cluster
	 * @generated
	 */
	public Adapter createClusterAdapter() {
		return null;
	}

	/**
	 * Creates a new adapter for an object of class '{@link com.jennic.ZPSConfiguration.Node <em>Node</em>}'.
	 * <!-- begin-user-doc -->
	 * This default implementation returns null so that we can easily ignore cases;
	 * it's useful to ignore a case when inheritance will catch all the cases anyway.
	 * <!-- end-user-doc -->
	 * @return the new adapter.
	 * @see com.jennic.ZPSConfiguration.Node
	 * @generated
	 */
	public Adapter createNodeAdapter() {
		return null;
	}

	/**
	 * Creates a new adapter for an object of class '{@link com.jennic.ZPSConfiguration.Coordinator <em>Coordinator</em>}'.
	 * <!-- begin-user-doc -->
	 * This default implementation returns null so that we can easily ignore cases;
	 * it's useful to ignore a case when inheritance will catch all the cases anyway.
	 * <!-- end-user-doc -->
	 * @return the new adapter.
	 * @see com.jennic.ZPSConfiguration.Coordinator
	 * @generated
	 */
	public Adapter createCoordinatorAdapter() {
		return null;
	}

	/**
	 * Creates a new adapter for an object of class '{@link com.jennic.ZPSConfiguration.Router <em>Router</em>}'.
	 * <!-- begin-user-doc -->
	 * This default implementation returns null so that we can easily ignore cases;
	 * it's useful to ignore a case when inheritance will catch all the cases anyway.
	 * <!-- end-user-doc -->
	 * @return the new adapter.
	 * @see com.jennic.ZPSConfiguration.Router
	 * @generated
	 */
	public Adapter createRouterAdapter() {
		return null;
	}

	/**
	 * Creates a new adapter for an object of class '{@link com.jennic.ZPSConfiguration.EndDevice <em>End Device</em>}'.
	 * <!-- begin-user-doc -->
	 * This default implementation returns null so that we can easily ignore cases;
	 * it's useful to ignore a case when inheritance will catch all the cases anyway.
	 * <!-- end-user-doc -->
	 * @return the new adapter.
	 * @see com.jennic.ZPSConfiguration.EndDevice
	 * @generated
	 */
	public Adapter createEndDeviceAdapter() {
		return null;
	}

	/**
	 * Creates a new adapter for an object of class '{@link com.jennic.ZPSConfiguration.EndPoint <em>End Point</em>}'.
	 * <!-- begin-user-doc -->
	 * This default implementation returns null so that we can easily ignore cases;
	 * it's useful to ignore a case when inheritance will catch all the cases anyway.
	 * <!-- end-user-doc -->
	 * @return the new adapter.
	 * @see com.jennic.ZPSConfiguration.EndPoint
	 * @generated
	 */
	public Adapter createEndPointAdapter() {
		return null;
	}

	/**
	 * Creates a new adapter for an object of class '{@link com.jennic.ZPSConfiguration.PrimaryDiscoveryCache <em>Primary Discovery Cache</em>}'.
	 * <!-- begin-user-doc -->
	 * This default implementation returns null so that we can easily ignore cases;
	 * it's useful to ignore a case when inheritance will catch all the cases anyway.
	 * <!-- end-user-doc -->
	 * @return the new adapter.
	 * @see com.jennic.ZPSConfiguration.PrimaryDiscoveryCache
	 * @generated
	 */
	public Adapter createPrimaryDiscoveryCacheAdapter() {
		return null;
	}

	/**
	 * Creates a new adapter for an object of class '{@link com.jennic.ZPSConfiguration.BackupDiscoveryCache <em>Backup Discovery Cache</em>}'.
	 * <!-- begin-user-doc -->
	 * This default implementation returns null so that we can easily ignore cases;
	 * it's useful to ignore a case when inheritance will catch all the cases anyway.
	 * <!-- end-user-doc -->
	 * @return the new adapter.
	 * @see com.jennic.ZPSConfiguration.BackupDiscoveryCache
	 * @generated
	 */
	public Adapter createBackupDiscoveryCacheAdapter() {
		return null;
	}

	/**
	 * Creates a new adapter for an object of class '{@link com.jennic.ZPSConfiguration.DiscoveryTable <em>Discovery Table</em>}'.
	 * <!-- begin-user-doc -->
	 * This default implementation returns null so that we can easily ignore cases;
	 * it's useful to ignore a case when inheritance will catch all the cases anyway.
	 * <!-- end-user-doc -->
	 * @return the new adapter.
	 * @see com.jennic.ZPSConfiguration.DiscoveryTable
	 * @generated
	 */
	public Adapter createDiscoveryTableAdapter() {
		return null;
	}

	/**
	 * Creates a new adapter for an object of class '{@link com.jennic.ZPSConfiguration.BindingTable <em>Binding Table</em>}'.
	 * <!-- begin-user-doc -->
	 * This default implementation returns null so that we can easily ignore cases;
	 * it's useful to ignore a case when inheritance will catch all the cases anyway.
	 * <!-- end-user-doc -->
	 * @return the new adapter.
	 * @see com.jennic.ZPSConfiguration.BindingTable
	 * @generated
	 */
	public Adapter createBindingTableAdapter() {
		return null;
	}

	/**
	 * Creates a new adapter for an object of class '{@link com.jennic.ZPSConfiguration.GroupTable <em>Group Table</em>}'.
	 * <!-- begin-user-doc -->
	 * This default implementation returns null so that we can easily ignore cases;
	 * it's useful to ignore a case when inheritance will catch all the cases anyway.
	 * <!-- end-user-doc -->
	 * @return the new adapter.
	 * @see com.jennic.ZPSConfiguration.GroupTable
	 * @generated
	 */
	public Adapter createGroupTableAdapter() {
		return null;
	}

	/**
	 * Creates a new adapter for an object of class '{@link com.jennic.ZPSConfiguration.ZigbeeWirelessNetwork <em>Zigbee Wireless Network</em>}'.
	 * <!-- begin-user-doc -->
	 * This default implementation returns null so that we can easily ignore cases;
	 * it's useful to ignore a case when inheritance will catch all the cases anyway.
	 * <!-- end-user-doc -->
	 * @return the new adapter.
	 * @see com.jennic.ZPSConfiguration.ZigbeeWirelessNetwork
	 * @generated
	 */
	public Adapter createZigbeeWirelessNetworkAdapter() {
		return null;
	}

	/**
	 * Creates a new adapter for an object of class '{@link com.jennic.ZPSConfiguration.PrimaryBindingCache <em>Primary Binding Cache</em>}'.
	 * <!-- begin-user-doc -->
	 * This default implementation returns null so that we can easily ignore cases;
	 * it's useful to ignore a case when inheritance will catch all the cases anyway.
	 * <!-- end-user-doc -->
	 * @return the new adapter.
	 * @see com.jennic.ZPSConfiguration.PrimaryBindingCache
	 * @generated
	 */
	public Adapter createPrimaryBindingCacheAdapter() {
		return null;
	}

	/**
	 * Creates a new adapter for an object of class '{@link com.jennic.ZPSConfiguration.BackupBindingCache <em>Backup Binding Cache</em>}'.
	 * <!-- begin-user-doc -->
	 * This default implementation returns null so that we can easily ignore cases;
	 * it's useful to ignore a case when inheritance will catch all the cases anyway.
	 * <!-- end-user-doc -->
	 * @return the new adapter.
	 * @see com.jennic.ZPSConfiguration.BackupBindingCache
	 * @generated
	 */
	public Adapter createBackupBindingCacheAdapter() {
		return null;
	}

	/**
	 * Creates a new adapter for an object of class '{@link com.jennic.ZPSConfiguration.PrimaryGroupCache <em>Primary Group Cache</em>}'.
	 * <!-- begin-user-doc -->
	 * This default implementation returns null so that we can easily ignore cases;
	 * it's useful to ignore a case when inheritance will catch all the cases anyway.
	 * <!-- end-user-doc -->
	 * @return the new adapter.
	 * @see com.jennic.ZPSConfiguration.PrimaryGroupCache
	 * @generated
	 */
	public Adapter createPrimaryGroupCacheAdapter() {
		return null;
	}

	/**
	 * Creates a new adapter for an object of class '{@link com.jennic.ZPSConfiguration.BackupGroupCache <em>Backup Group Cache</em>}'.
	 * <!-- begin-user-doc -->
	 * This default implementation returns null so that we can easily ignore cases;
	 * it's useful to ignore a case when inheritance will catch all the cases anyway.
	 * <!-- end-user-doc -->
	 * @return the new adapter.
	 * @see com.jennic.ZPSConfiguration.BackupGroupCache
	 * @generated
	 */
	public Adapter createBackupGroupCacheAdapter() {
		return null;
	}

	/**
	 * Creates a new adapter for an object of class '{@link com.jennic.ZPSConfiguration.InputCluster <em>Input Cluster</em>}'.
	 * <!-- begin-user-doc -->
	 * This default implementation returns null so that we can easily ignore cases;
	 * it's useful to ignore a case when inheritance will catch all the cases anyway.
	 * <!-- end-user-doc -->
	 * @return the new adapter.
	 * @see com.jennic.ZPSConfiguration.InputCluster
	 * @generated
	 */
	public Adapter createInputClusterAdapter() {
		return null;
	}

	/**
	 * Creates a new adapter for an object of class '{@link com.jennic.ZPSConfiguration.OutputCluster <em>Output Cluster</em>}'.
	 * <!-- begin-user-doc -->
	 * This default implementation returns null so that we can easily ignore cases;
	 * it's useful to ignore a case when inheritance will catch all the cases anyway.
	 * <!-- end-user-doc -->
	 * @return the new adapter.
	 * @see com.jennic.ZPSConfiguration.OutputCluster
	 * @generated
	 */
	public Adapter createOutputClusterAdapter() {
		return null;
	}

	/**
	 * Creates a new adapter for an object of class '{@link com.jennic.ZPSConfiguration.AlwaysOnNode <em>Always On Node</em>}'.
	 * <!-- begin-user-doc -->
	 * This default implementation returns null so that we can easily ignore cases;
	 * it's useful to ignore a case when inheritance will catch all the cases anyway.
	 * <!-- end-user-doc -->
	 * @return the new adapter.
	 * @see com.jennic.ZPSConfiguration.AlwaysOnNode
	 * @generated
	 */
	public Adapter createAlwaysOnNodeAdapter() {
		return null;
	}

	/**
	 * Creates a new adapter for an object of class '{@link com.jennic.ZPSConfiguration.ComplexDescriptor <em>Complex Descriptor</em>}'.
	 * <!-- begin-user-doc -->
	 * This default implementation returns null so that we can easily ignore cases;
	 * it's useful to ignore a case when inheritance will catch all the cases anyway.
	 * <!-- end-user-doc -->
	 * @return the new adapter.
	 * @see com.jennic.ZPSConfiguration.ComplexDescriptor
	 * @generated
	 */
	public Adapter createComplexDescriptorAdapter() {
		return null;
	}

	/**
	 * Creates a new adapter for an object of class '{@link com.jennic.ZPSConfiguration.UserDescriptor <em>User Descriptor</em>}'.
	 * <!-- begin-user-doc -->
	 * This default implementation returns null so that we can easily ignore cases;
	 * it's useful to ignore a case when inheritance will catch all the cases anyway.
	 * <!-- end-user-doc -->
	 * @return the new adapter.
	 * @see com.jennic.ZPSConfiguration.UserDescriptor
	 * @generated
	 */
	public Adapter createUserDescriptorAdapter() {
		return null;
	}

	/**
	 * Creates a new adapter for an object of class '{@link com.jennic.ZPSConfiguration.TrustCenter <em>Trust Center</em>}'.
	 * <!-- begin-user-doc -->
	 * This default implementation returns null so that we can easily ignore cases;
	 * it's useful to ignore a case when inheritance will catch all the cases anyway.
	 * <!-- end-user-doc -->
	 * @return the new adapter.
	 * @see com.jennic.ZPSConfiguration.TrustCenter
	 * @generated
	 */
	public Adapter createTrustCenterAdapter() {
		return null;
	}

	/**
	 * Creates a new adapter for an object of class '{@link com.jennic.ZPSConfiguration.DiscoveryCache <em>Discovery Cache</em>}'.
	 * <!-- begin-user-doc -->
	 * This default implementation returns null so that we can easily ignore cases;
	 * it's useful to ignore a case when inheritance will catch all the cases anyway.
	 * <!-- end-user-doc -->
	 * @return the new adapter.
	 * @see com.jennic.ZPSConfiguration.DiscoveryCache
	 * @generated
	 */
	public Adapter createDiscoveryCacheAdapter() {
		return null;
	}

	/**
	 * Creates a new adapter for an object of class '{@link com.jennic.ZPSConfiguration.BindingCache <em>Binding Cache</em>}'.
	 * <!-- begin-user-doc -->
	 * This default implementation returns null so that we can easily ignore cases;
	 * it's useful to ignore a case when inheritance will catch all the cases anyway.
	 * <!-- end-user-doc -->
	 * @return the new adapter.
	 * @see com.jennic.ZPSConfiguration.BindingCache
	 * @generated
	 */
	public Adapter createBindingCacheAdapter() {
		return null;
	}

	/**
	 * Creates a new adapter for an object of class '{@link com.jennic.ZPSConfiguration.NamedObject <em>Named Object</em>}'.
	 * <!-- begin-user-doc -->
	 * This default implementation returns null so that we can easily ignore cases;
	 * it's useful to ignore a case when inheritance will catch all the cases anyway.
	 * <!-- end-user-doc -->
	 * @return the new adapter.
	 * @see com.jennic.ZPSConfiguration.NamedObject
	 * @generated
	 */
	public Adapter createNamedObjectAdapter() {
		return null;
	}

	/**
	 * Creates a new adapter for an object of class '{@link com.jennic.ZPSConfiguration.ChildNodes <em>Child Nodes</em>}'.
	 * <!-- begin-user-doc -->
	 * This default implementation returns null so that we can easily ignore cases;
	 * it's useful to ignore a case when inheritance will catch all the cases anyway.
	 * <!-- end-user-doc -->
	 * @return the new adapter.
	 * @see com.jennic.ZPSConfiguration.ChildNodes
	 * @generated
	 */
	public Adapter createChildNodesAdapter() {
		return null;
	}

	/**
	 * Creates a new adapter for an object of class '{@link com.jennic.ZPSConfiguration.APDU <em>APDU</em>}'.
	 * <!-- begin-user-doc -->
	 * This default implementation returns null so that we can easily ignore cases;
	 * it's useful to ignore a case when inheritance will catch all the cases anyway.
	 * <!-- end-user-doc -->
	 * @return the new adapter.
	 * @see com.jennic.ZPSConfiguration.APDU
	 * @generated
	 */
	public Adapter createAPDUAdapter() {
		return null;
	}

	/**
	 * Creates a new adapter for an object of class '{@link com.jennic.ZPSConfiguration.PDUManager <em>PDU Manager</em>}'.
	 * <!-- begin-user-doc -->
	 * This default implementation returns null so that we can easily ignore cases;
	 * it's useful to ignore a case when inheritance will catch all the cases anyway.
	 * <!-- end-user-doc -->
	 * @return the new adapter.
	 * @see com.jennic.ZPSConfiguration.PDUManager
	 * @generated
	 */
	public Adapter createPDUManagerAdapter() {
		return null;
	}

	/**
	 * Creates a new adapter for an object of class '{@link com.jennic.ZPSConfiguration.ChannelMask <em>Channel Mask</em>}'.
	 * <!-- begin-user-doc -->
	 * This default implementation returns null so that we can easily ignore cases;
	 * it's useful to ignore a case when inheritance will catch all the cases anyway.
	 * <!-- end-user-doc -->
	 * @return the new adapter.
	 * @see com.jennic.ZPSConfiguration.ChannelMask
	 * @generated
	 */
	public Adapter createChannelMaskAdapter() {
		return null;
	}

	/**
	 * Creates a new adapter for an object of class '{@link com.jennic.ZPSConfiguration.ZDOClientServer <em>ZDO Client Server</em>}'.
	 * <!-- begin-user-doc -->
	 * This default implementation returns null so that we can easily ignore cases;
	 * it's useful to ignore a case when inheritance will catch all the cases anyway.
	 * <!-- end-user-doc -->
	 * @return the new adapter.
	 * @see com.jennic.ZPSConfiguration.ZDOClientServer
	 * @generated
	 */
	public Adapter createZDOClientServerAdapter() {
		return null;
	}

	/**
	 * Creates a new adapter for an object of class '{@link com.jennic.ZPSConfiguration.ZDOServersCoordinator <em>ZDO Servers Coordinator</em>}'.
	 * <!-- begin-user-doc -->
	 * This default implementation returns null so that we can easily ignore cases;
	 * it's useful to ignore a case when inheritance will catch all the cases anyway.
	 * <!-- end-user-doc -->
	 * @return the new adapter.
	 * @see com.jennic.ZPSConfiguration.ZDOServersCoordinator
	 * @generated
	 */
	public Adapter createZDOServersCoordinatorAdapter() {
		return null;
	}

	/**
	 * Creates a new adapter for an object of class '{@link com.jennic.ZPSConfiguration.EndDeviceBindServer <em>End Device Bind Server</em>}'.
	 * <!-- begin-user-doc -->
	 * This default implementation returns null so that we can easily ignore cases;
	 * it's useful to ignore a case when inheritance will catch all the cases anyway.
	 * <!-- end-user-doc -->
	 * @return the new adapter.
	 * @see com.jennic.ZPSConfiguration.EndDeviceBindServer
	 * @generated
	 */
	public Adapter createEndDeviceBindServerAdapter() {
		return null;
	}

	/**
	 * Creates a new adapter for an object of class '{@link com.jennic.ZPSConfiguration.ZDOServersRouter <em>ZDO Servers Router</em>}'.
	 * <!-- begin-user-doc -->
	 * This default implementation returns null so that we can easily ignore cases;
	 * it's useful to ignore a case when inheritance will catch all the cases anyway.
	 * <!-- end-user-doc -->
	 * @return the new adapter.
	 * @see com.jennic.ZPSConfiguration.ZDOServersRouter
	 * @generated
	 */
	public Adapter createZDOServersRouterAdapter() {
		return null;
	}

	/**
	 * Creates a new adapter for an object of class '{@link com.jennic.ZPSConfiguration.ZDOServersEndDevice <em>ZDO Servers End Device</em>}'.
	 * <!-- begin-user-doc -->
	 * This default implementation returns null so that we can easily ignore cases;
	 * it's useful to ignore a case when inheritance will catch all the cases anyway.
	 * <!-- end-user-doc -->
	 * @return the new adapter.
	 * @see com.jennic.ZPSConfiguration.ZDOServersEndDevice
	 * @generated
	 */
	public Adapter createZDOServersEndDeviceAdapter() {
		return null;
	}

	/**
	 * Creates a new adapter for an object of class '{@link com.jennic.ZPSConfiguration.DefaultServer <em>Default Server</em>}'.
	 * <!-- begin-user-doc -->
	 * This default implementation returns null so that we can easily ignore cases;
	 * it's useful to ignore a case when inheritance will catch all the cases anyway.
	 * <!-- end-user-doc -->
	 * @return the new adapter.
	 * @see com.jennic.ZPSConfiguration.DefaultServer
	 * @generated
	 */
	public Adapter createDefaultServerAdapter() {
		return null;
	}

	/**
	 * Creates a new adapter for an object of class '{@link com.jennic.ZPSConfiguration.DeviceAnnceServer <em>Device Annce Server</em>}'.
	 * <!-- begin-user-doc -->
	 * This default implementation returns null so that we can easily ignore cases;
	 * it's useful to ignore a case when inheritance will catch all the cases anyway.
	 * <!-- end-user-doc -->
	 * @return the new adapter.
	 * @see com.jennic.ZPSConfiguration.DeviceAnnceServer
	 * @generated
	 */
	public Adapter createDeviceAnnceServerAdapter() {
		return null;
	}

	/**
	 * Creates a new adapter for an object of class '{@link com.jennic.ZPSConfiguration.ActiveEpServer <em>Active Ep Server</em>}'.
	 * <!-- begin-user-doc -->
	 * This default implementation returns null so that we can easily ignore cases;
	 * it's useful to ignore a case when inheritance will catch all the cases anyway.
	 * <!-- end-user-doc -->
	 * @return the new adapter.
	 * @see com.jennic.ZPSConfiguration.ActiveEpServer
	 * @generated
	 */
	public Adapter createActiveEpServerAdapter() {
		return null;
	}

	/**
	 * Creates a new adapter for an object of class '{@link com.jennic.ZPSConfiguration.NwkAddrServer <em>Nwk Addr Server</em>}'.
	 * <!-- begin-user-doc -->
	 * This default implementation returns null so that we can easily ignore cases;
	 * it's useful to ignore a case when inheritance will catch all the cases anyway.
	 * <!-- end-user-doc -->
	 * @return the new adapter.
	 * @see com.jennic.ZPSConfiguration.NwkAddrServer
	 * @generated
	 */
	public Adapter createNwkAddrServerAdapter() {
		return null;
	}

	/**
	 * Creates a new adapter for an object of class '{@link com.jennic.ZPSConfiguration.IeeeAddrServer <em>Ieee Addr Server</em>}'.
	 * <!-- begin-user-doc -->
	 * This default implementation returns null so that we can easily ignore cases;
	 * it's useful to ignore a case when inheritance will catch all the cases anyway.
	 * <!-- end-user-doc -->
	 * @return the new adapter.
	 * @see com.jennic.ZPSConfiguration.IeeeAddrServer
	 * @generated
	 */
	public Adapter createIeeeAddrServerAdapter() {
		return null;
	}

	/**
	 * Creates a new adapter for an object of class '{@link com.jennic.ZPSConfiguration.MatchDescServer <em>Match Desc Server</em>}'.
	 * <!-- begin-user-doc -->
	 * This default implementation returns null so that we can easily ignore cases;
	 * it's useful to ignore a case when inheritance will catch all the cases anyway.
	 * <!-- end-user-doc -->
	 * @return the new adapter.
	 * @see com.jennic.ZPSConfiguration.MatchDescServer
	 * @generated
	 */
	public Adapter createMatchDescServerAdapter() {
		return null;
	}

	/**
	 * Creates a new adapter for an object of class '{@link com.jennic.ZPSConfiguration.NodeDescServer <em>Node Desc Server</em>}'.
	 * <!-- begin-user-doc -->
	 * This default implementation returns null so that we can easily ignore cases;
	 * it's useful to ignore a case when inheritance will catch all the cases anyway.
	 * <!-- end-user-doc -->
	 * @return the new adapter.
	 * @see com.jennic.ZPSConfiguration.NodeDescServer
	 * @generated
	 */
	public Adapter createNodeDescServerAdapter() {
		return null;
	}

	/**
	 * Creates a new adapter for an object of class '{@link com.jennic.ZPSConfiguration.PermitJoiningServer <em>Permit Joining Server</em>}'.
	 * <!-- begin-user-doc -->
	 * This default implementation returns null so that we can easily ignore cases;
	 * it's useful to ignore a case when inheritance will catch all the cases anyway.
	 * <!-- end-user-doc -->
	 * @return the new adapter.
	 * @see com.jennic.ZPSConfiguration.PermitJoiningServer
	 * @generated
	 */
	public Adapter createPermitJoiningServerAdapter() {
		return null;
	}

	/**
	 * Creates a new adapter for an object of class '{@link com.jennic.ZPSConfiguration.PowerDescServer <em>Power Desc Server</em>}'.
	 * <!-- begin-user-doc -->
	 * This default implementation returns null so that we can easily ignore cases;
	 * it's useful to ignore a case when inheritance will catch all the cases anyway.
	 * <!-- end-user-doc -->
	 * @return the new adapter.
	 * @see com.jennic.ZPSConfiguration.PowerDescServer
	 * @generated
	 */
	public Adapter createPowerDescServerAdapter() {
		return null;
	}

	/**
	 * Creates a new adapter for an object of class '{@link com.jennic.ZPSConfiguration.SimpleDescServer <em>Simple Desc Server</em>}'.
	 * <!-- begin-user-doc -->
	 * This default implementation returns null so that we can easily ignore cases;
	 * it's useful to ignore a case when inheritance will catch all the cases anyway.
	 * <!-- end-user-doc -->
	 * @return the new adapter.
	 * @see com.jennic.ZPSConfiguration.SimpleDescServer
	 * @generated
	 */
	public Adapter createSimpleDescServerAdapter() {
		return null;
	}

	/**
	 * Creates a new adapter for an object of class '{@link com.jennic.ZPSConfiguration.SystemServerDiscoveryServer <em>System Server Discovery Server</em>}'.
	 * <!-- begin-user-doc -->
	 * This default implementation returns null so that we can easily ignore cases;
	 * it's useful to ignore a case when inheritance will catch all the cases anyway.
	 * <!-- end-user-doc -->
	 * @return the new adapter.
	 * @see com.jennic.ZPSConfiguration.SystemServerDiscoveryServer
	 * @generated
	 */
	public Adapter createSystemServerDiscoveryServerAdapter() {
		return null;
	}

	/**
	 * Creates a new adapter for an object of class '{@link com.jennic.ZPSConfiguration.MgmtLqiServer <em>Mgmt Lqi Server</em>}'.
	 * <!-- begin-user-doc -->
	 * This default implementation returns null so that we can easily ignore cases;
	 * it's useful to ignore a case when inheritance will catch all the cases anyway.
	 * <!-- end-user-doc -->
	 * @return the new adapter.
	 * @see com.jennic.ZPSConfiguration.MgmtLqiServer
	 * @generated
	 */
	public Adapter createMgmtLqiServerAdapter() {
		return null;
	}

	/**
	 * Creates a new adapter for an object of class '{@link com.jennic.ZPSConfiguration.MgmtRtgServer <em>Mgmt Rtg Server</em>}'.
	 * <!-- begin-user-doc -->
	 * This default implementation returns null so that we can easily ignore cases;
	 * it's useful to ignore a case when inheritance will catch all the cases anyway.
	 * <!-- end-user-doc -->
	 * @return the new adapter.
	 * @see com.jennic.ZPSConfiguration.MgmtRtgServer
	 * @generated
	 */
	public Adapter createMgmtRtgServerAdapter() {
		return null;
	}

	/**
	 * Creates a new adapter for an object of class '{@link com.jennic.ZPSConfiguration.MgmtLeaveServer <em>Mgmt Leave Server</em>}'.
	 * <!-- begin-user-doc -->
	 * This default implementation returns null so that we can easily ignore cases;
	 * it's useful to ignore a case when inheritance will catch all the cases anyway.
	 * <!-- end-user-doc -->
	 * @return the new adapter.
	 * @see com.jennic.ZPSConfiguration.MgmtLeaveServer
	 * @generated
	 */
	public Adapter createMgmtLeaveServerAdapter() {
		return null;
	}

	/**
	 * Creates a new adapter for an object of class '{@link com.jennic.ZPSConfiguration.NodeDescriptor <em>Node Descriptor</em>}'.
	 * <!-- begin-user-doc -->
	 * This default implementation returns null so that we can easily ignore cases;
	 * it's useful to ignore a case when inheritance will catch all the cases anyway.
	 * <!-- end-user-doc -->
	 * @return the new adapter.
	 * @see com.jennic.ZPSConfiguration.NodeDescriptor
	 * @generated
	 */
	public Adapter createNodeDescriptorAdapter() {
		return null;
	}

	/**
	 * Creates a new adapter for an object of class '{@link com.jennic.ZPSConfiguration.NodePowerDescriptor <em>Node Power Descriptor</em>}'.
	 * <!-- begin-user-doc -->
	 * This default implementation returns null so that we can easily ignore cases;
	 * it's useful to ignore a case when inheritance will catch all the cases anyway.
	 * <!-- end-user-doc -->
	 * @return the new adapter.
	 * @see com.jennic.ZPSConfiguration.NodePowerDescriptor
	 * @generated
	 */
	public Adapter createNodePowerDescriptorAdapter() {
		return null;
	}

	/**
	 * Creates a new adapter for an object of class '{@link com.jennic.ZPSConfiguration.BindUnbindServer <em>Bind Unbind Server</em>}'.
	 * <!-- begin-user-doc -->
	 * This default implementation returns null so that we can easily ignore cases;
	 * it's useful to ignore a case when inheritance will catch all the cases anyway.
	 * <!-- end-user-doc -->
	 * @return the new adapter.
	 * @see com.jennic.ZPSConfiguration.BindUnbindServer
	 * @generated
	 */
	public Adapter createBindUnbindServerAdapter() {
		return null;
	}

	/**
	 * Creates a new adapter for an object of class '{@link com.jennic.ZPSConfiguration.MgmtBindServer <em>Mgmt Bind Server</em>}'.
	 * <!-- begin-user-doc -->
	 * This default implementation returns null so that we can easily ignore cases;
	 * it's useful to ignore a case when inheritance will catch all the cases anyway.
	 * <!-- end-user-doc -->
	 * @return the new adapter.
	 * @see com.jennic.ZPSConfiguration.MgmtBindServer
	 * @generated
	 */
	public Adapter createMgmtBindServerAdapter() {
		return null;
	}

	/**
	 * Creates a new adapter for an object of class '{@link com.jennic.ZPSConfiguration.ExtendedActiveEpServer <em>Extended Active Ep Server</em>}'.
	 * <!-- begin-user-doc -->
	 * This default implementation returns null so that we can easily ignore cases;
	 * it's useful to ignore a case when inheritance will catch all the cases anyway.
	 * <!-- end-user-doc -->
	 * @return the new adapter.
	 * @see com.jennic.ZPSConfiguration.ExtendedActiveEpServer
	 * @generated
	 */
	public Adapter createExtendedActiveEpServerAdapter() {
		return null;
	}

	/**
	 * Creates a new adapter for an object of class '{@link com.jennic.ZPSConfiguration.ExtendedSimpleDescServer <em>Extended Simple Desc Server</em>}'.
	 * <!-- begin-user-doc -->
	 * This default implementation returns null so that we can easily ignore cases;
	 * it's useful to ignore a case when inheritance will catch all the cases anyway.
	 * <!-- end-user-doc -->
	 * @return the new adapter.
	 * @see com.jennic.ZPSConfiguration.ExtendedSimpleDescServer
	 * @generated
	 */
	public Adapter createExtendedSimpleDescServerAdapter() {
		return null;
	}

	/**
	 * Creates a new adapter for an object of class '{@link com.jennic.ZPSConfiguration.ZdoClient <em>Zdo Client</em>}'.
	 * <!-- begin-user-doc -->
	 * This default implementation returns null so that we can easily ignore cases;
	 * it's useful to ignore a case when inheritance will catch all the cases anyway.
	 * <!-- end-user-doc -->
	 * @return the new adapter.
	 * @see com.jennic.ZPSConfiguration.ZdoClient
	 * @generated
	 */
	public Adapter createZdoClientAdapter() {
		return null;
	}

	/**
	 * Creates a new adapter for an object of class '{@link com.jennic.ZPSConfiguration.MgmtNWKUpdateServer <em>Mgmt NWK Update Server</em>}'.
	 * <!-- begin-user-doc -->
	 * This default implementation returns null so that we can easily ignore cases;
	 * it's useful to ignore a case when inheritance will catch all the cases anyway.
	 * <!-- end-user-doc -->
	 * @return the new adapter.
	 * @see com.jennic.ZPSConfiguration.MgmtNWKUpdateServer
	 * @generated
	 */
	public Adapter createMgmtNWKUpdateServerAdapter() {
		return null;
	}

	/**
	 * Creates a new adapter for an object of class '{@link com.jennic.ZPSConfiguration.ZDOCommonServers <em>ZDO Common Servers</em>}'.
	 * <!-- begin-user-doc -->
	 * This default implementation returns null so that we can easily ignore cases;
	 * it's useful to ignore a case when inheritance will catch all the cases anyway.
	 * <!-- end-user-doc -->
	 * @return the new adapter.
	 * @see com.jennic.ZPSConfiguration.ZDOCommonServers
	 * @generated
	 */
	public Adapter createZDOCommonServersAdapter() {
		return null;
	}

	/**
	 * Creates a new adapter for an object of class '{@link com.jennic.ZPSConfiguration.NotImplemented <em>Not Implemented</em>}'.
	 * <!-- begin-user-doc -->
	 * This default implementation returns null so that we can easily ignore cases;
	 * it's useful to ignore a case when inheritance will catch all the cases anyway.
	 * <!-- end-user-doc -->
	 * @return the new adapter.
	 * @see com.jennic.ZPSConfiguration.NotImplemented
	 * @generated
	 */
	public Adapter createNotImplementedAdapter() {
		return null;
	}

	/**
	 * Creates a new adapter for an object of class '{@link com.jennic.ZPSConfiguration.KeyDescriptorTable <em>Key Descriptor Table</em>}'.
	 * <!-- begin-user-doc -->
	 * This default implementation returns null so that we can easily ignore cases;
	 * it's useful to ignore a case when inheritance will catch all the cases anyway.
	 * <!-- end-user-doc -->
	 * @return the new adapter.
	 * @see com.jennic.ZPSConfiguration.KeyDescriptorTable
	 * @generated
	 */
	public Adapter createKeyDescriptorTableAdapter() {
		return null;
	}

	/**
	 * Creates a new adapter for an object of class '{@link com.jennic.ZPSConfiguration.PreconfiguredKey <em>Preconfigured Key</em>}'.
	 * <!-- begin-user-doc -->
	 * This default implementation returns null so that we can easily ignore cases;
	 * it's useful to ignore a case when inheritance will catch all the cases anyway.
	 * <!-- end-user-doc -->
	 * @return the new adapter.
	 * @see com.jennic.ZPSConfiguration.PreconfiguredKey
	 * @generated
	 */
	public Adapter createPreconfiguredKeyAdapter() {
		return null;
	}

	/**
	 * Creates a new adapter for an object of class '{@link com.jennic.ZPSConfiguration.ZDOCoordRouterOnlyServers <em>ZDO Coord Router Only Servers</em>}'.
	 * <!-- begin-user-doc -->
	 * This default implementation returns null so that we can easily ignore cases;
	 * it's useful to ignore a case when inheritance will catch all the cases anyway.
	 * <!-- end-user-doc -->
	 * @return the new adapter.
	 * @see com.jennic.ZPSConfiguration.ZDOCoordRouterOnlyServers
	 * @generated
	 */
	public Adapter createZDOCoordRouterOnlyServersAdapter() {
		return null;
	}

	/**
	 * Creates a new adapter for an object of class '{@link com.jennic.ZPSConfiguration.PreConfiguredNwkKey <em>Pre Configured Nwk Key</em>}'.
	 * <!-- begin-user-doc -->
	 * This default implementation returns null so that we can easily ignore cases;
	 * it's useful to ignore a case when inheritance will catch all the cases anyway.
	 * <!-- end-user-doc -->
	 * @return the new adapter.
	 * @see com.jennic.ZPSConfiguration.PreConfiguredNwkKey
	 * @generated
	 */
	public Adapter createPreConfiguredNwkKeyAdapter() {
		return null;
	}

	/**
	 * Creates a new adapter for an object of class '{@link com.jennic.ZPSConfiguration.DefaultNwkKey <em>Default Nwk Key</em>}'.
	 * <!-- begin-user-doc -->
	 * This default implementation returns null so that we can easily ignore cases;
	 * it's useful to ignore a case when inheritance will catch all the cases anyway.
	 * <!-- end-user-doc -->
	 * @return the new adapter.
	 * @see com.jennic.ZPSConfiguration.DefaultNwkKey
	 * @generated
	 */
	public Adapter createDefaultNwkKeyAdapter() {
		return null;
	}

	/**
	 * Creates a new adapter for an object of class '{@link com.jennic.ZPSConfiguration.NwkKey <em>Nwk Key</em>}'.
	 * <!-- begin-user-doc -->
	 * This default implementation returns null so that we can easily ignore cases;
	 * it's useful to ignore a case when inheritance will catch all the cases anyway.
	 * <!-- end-user-doc -->
	 * @return the new adapter.
	 * @see com.jennic.ZPSConfiguration.NwkKey
	 * @generated
	 */
	public Adapter createNwkKeyAdapter() {
		return null;
	}

	/**
	 * Creates a new adapter for an object of class '{@link com.jennic.ZPSConfiguration.PreconfiguredTCLinkKey <em>Preconfigured TC Link Key</em>}'.
	 * <!-- begin-user-doc -->
	 * This default implementation returns null so that we can easily ignore cases;
	 * it's useful to ignore a case when inheritance will catch all the cases anyway.
	 * <!-- end-user-doc -->
	 * @return the new adapter.
	 * @see com.jennic.ZPSConfiguration.PreconfiguredTCLinkKey
	 * @generated
	 */
	public Adapter createPreconfiguredTCLinkKeyAdapter() {
		return null;
	}

	/**
	 * Creates a new adapter for an object of class '{@link com.jennic.ZPSConfiguration.TCKey <em>TC Key</em>}'.
	 * <!-- begin-user-doc -->
	 * This default implementation returns null so that we can easily ignore cases;
	 * it's useful to ignore a case when inheritance will catch all the cases anyway.
	 * <!-- end-user-doc -->
	 * @return the new adapter.
	 * @see com.jennic.ZPSConfiguration.TCKey
	 * @generated
	 */
	public Adapter createTCKeyAdapter() {
		return null;
	}

	/**
	 * Creates a new adapter for an object of class '{@link com.jennic.ZPSConfiguration.BindRequestServer <em>Bind Request Server</em>}'.
	 * <!-- begin-user-doc -->
	 * This default implementation returns null so that we can easily ignore cases;
	 * it's useful to ignore a case when inheritance will catch all the cases anyway.
	 * <!-- end-user-doc -->
	 * @return the new adapter.
	 * @see com.jennic.ZPSConfiguration.BindRequestServer
	 * @generated
	 */
	public Adapter createBindRequestServerAdapter() {
		return null;
	}

	/**
	 * Creates a new adapter for an object of class '{@link com.jennic.ZPSConfiguration.GreenPowerSecurityTable <em>Green Power Security Table</em>}'.
	 * <!-- begin-user-doc -->
	 * This default implementation returns null so that we can easily ignore cases;
	 * it's useful to ignore a case when inheritance will catch all the cases anyway.
	 * <!-- end-user-doc -->
	 * @return the new adapter.
	 * @see com.jennic.ZPSConfiguration.GreenPowerSecurityTable
	 * @generated
	 */
	public Adapter createGreenPowerSecurityTableAdapter() {
		return null;
	}

	/**
	 * Creates a new adapter for an object of class '{@link com.jennic.ZPSConfiguration.GreenPowerTxQueue <em>Green Power Tx Queue</em>}'.
	 * <!-- begin-user-doc -->
	 * This default implementation returns null so that we can easily ignore cases;
	 * it's useful to ignore a case when inheritance will catch all the cases anyway.
	 * <!-- end-user-doc -->
	 * @return the new adapter.
	 * @see com.jennic.ZPSConfiguration.GreenPowerTxQueue
	 * @generated
	 */
	public Adapter createGreenPowerTxQueueAdapter() {
		return null;
	}

	/**
	 * Creates a new adapter for an object of class '{@link com.jennic.ZPSConfiguration.MgmtMibIeeeServer <em>Mgmt Mib Ieee Server</em>}'.
	 * <!-- begin-user-doc -->
	 * This default implementation returns null so that we can easily ignore cases;
	 * it's useful to ignore a case when inheritance will catch all the cases anyway.
	 * <!-- end-user-doc -->
	 * @return the new adapter.
	 * @see com.jennic.ZPSConfiguration.MgmtMibIeeeServer
	 * @generated
	 */
	public Adapter createMgmtMibIeeeServerAdapter() {
		return null;
	}

	/**
	 * Creates a new adapter for an object of class '{@link com.jennic.ZPSConfiguration.MgmtNWKEnhanceUpdateServer <em>Mgmt NWK Enhance Update Server</em>}'.
	 * <!-- begin-user-doc -->
	 * This default implementation returns null so that we can easily ignore cases;
	 * it's useful to ignore a case when inheritance will catch all the cases anyway.
	 * <!-- end-user-doc -->
	 * @return the new adapter.
	 * @see com.jennic.ZPSConfiguration.MgmtNWKEnhanceUpdateServer
	 * @generated
	 */
	public Adapter createMgmtNWKEnhanceUpdateServerAdapter() {
		return null;
	}

	/**
	 * Creates a new adapter for an object of class '{@link com.jennic.ZPSConfiguration.MacInterfaceList <em>Mac Interface List</em>}'.
	 * <!-- begin-user-doc -->
	 * This default implementation returns null so that we can easily ignore cases;
	 * it's useful to ignore a case when inheritance will catch all the cases anyway.
	 * <!-- end-user-doc -->
	 * @return the new adapter.
	 * @see com.jennic.ZPSConfiguration.MacInterfaceList
	 * @generated
	 */
	public Adapter createMacInterfaceListAdapter() {
		return null;
	}

	/**
	 * Creates a new adapter for an object of class '{@link com.jennic.ZPSConfiguration.MacInterface <em>Mac Interface</em>}'.
	 * <!-- begin-user-doc -->
	 * This default implementation returns null so that we can easily ignore cases;
	 * it's useful to ignore a case when inheritance will catch all the cases anyway.
	 * <!-- end-user-doc -->
	 * @return the new adapter.
	 * @see com.jennic.ZPSConfiguration.MacInterface
	 * @generated
	 */
	public Adapter createMacInterfaceAdapter() {
		return null;
	}

	/**
	 * Creates a new adapter for an object of class '{@link com.jennic.ZPSConfiguration.ParentAnnceServer <em>Parent Annce Server</em>}'.
	 * <!-- begin-user-doc -->
	 * This default implementation returns null so that we can easily ignore cases;
	 * it's useful to ignore a case when inheritance will catch all the cases anyway.
	 * <!-- end-user-doc -->
	 * @return the new adapter.
	 * @see com.jennic.ZPSConfiguration.ParentAnnceServer
	 * @generated
	 */
	public Adapter createParentAnnceServerAdapter() {
		return null;
	}

	/**
	 * Creates a new adapter for the default case.
	 * <!-- begin-user-doc -->
	 * This default implementation returns null.
	 * <!-- end-user-doc -->
	 * @return the new adapter.
	 * @generated
	 */
	public Adapter createEObjectAdapter() {
		return null;
	}

} //ZPSConfigurationAdapterFactory
