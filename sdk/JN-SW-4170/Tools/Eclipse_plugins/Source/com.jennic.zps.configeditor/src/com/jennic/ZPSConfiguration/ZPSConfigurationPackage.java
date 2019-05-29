/**
 * (C) Jennic Ltd
 *
 * $Id$
 */
package com.jennic.ZPSConfiguration;

import org.eclipse.emf.ecore.EAttribute;
import org.eclipse.emf.ecore.EClass;
import org.eclipse.emf.ecore.EDataType;
import org.eclipse.emf.ecore.EEnum;
import org.eclipse.emf.ecore.EPackage;
import org.eclipse.emf.ecore.EReference;

/**
 * <!-- begin-user-doc -->
 * The <b>Package</b> for the model.
 * It contains accessors for the meta objects to represent
 * <ul>
 *   <li>each class,</li>
 *   <li>each feature of each class,</li>
 *   <li>each enum,</li>
 *   <li>and each data type</li>
 * </ul>
 * <!-- end-user-doc -->
 * @see com.jennic.ZPSConfiguration.ZPSConfigurationFactory
 * @model kind="package"
 *        extendedMetaData="elementFormDefault='qualified'"
 * @generated
 */
public interface ZPSConfigurationPackage extends EPackage {
	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	String copyright = "(C) NXP B.V";

	/**
	 * The package name.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	String eNAME = "ZPSConfiguration";

	/**
	 * The package namespace URI.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	String eNS_URI = "http://www.nxp.com/zpscfg";

	/**
	 * The package namespace name.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	String eNS_PREFIX = "zpscfg";

	/**
	 * The singleton instance of the package.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	ZPSConfigurationPackage eINSTANCE = com.jennic.ZPSConfiguration.impl.ZPSConfigurationPackageImpl.init();

	/**
	 * The meta object id for the '{@link com.jennic.ZPSConfiguration.impl.NamedObjectImpl <em>Named Object</em>}' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see com.jennic.ZPSConfiguration.impl.NamedObjectImpl
	 * @see com.jennic.ZPSConfiguration.impl.ZPSConfigurationPackageImpl#getNamedObject()
	 * @generated
	 */
	int NAMED_OBJECT = 25;

	/**
	 * The feature id for the '<em><b>Name</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int NAMED_OBJECT__NAME = 0;

	/**
	 * The number of structural features of the '<em>Named Object</em>' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int NAMED_OBJECT_FEATURE_COUNT = 1;

	/**
	 * The meta object id for the '{@link com.jennic.ZPSConfiguration.impl.ProfileImpl <em>Profile</em>}' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see com.jennic.ZPSConfiguration.impl.ProfileImpl
	 * @see com.jennic.ZPSConfiguration.impl.ZPSConfigurationPackageImpl#getProfile()
	 * @generated
	 */
	int PROFILE = 0;

	/**
	 * The feature id for the '<em><b>Name</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int PROFILE__NAME = NAMED_OBJECT__NAME;

	/**
	 * The feature id for the '<em><b>Id</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int PROFILE__ID = NAMED_OBJECT_FEATURE_COUNT + 0;

	/**
	 * The feature id for the '<em><b>Clusters</b></em>' containment reference list.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int PROFILE__CLUSTERS = NAMED_OBJECT_FEATURE_COUNT + 1;

	/**
	 * The number of structural features of the '<em>Profile</em>' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int PROFILE_FEATURE_COUNT = NAMED_OBJECT_FEATURE_COUNT + 2;

	/**
	 * The meta object id for the '{@link com.jennic.ZPSConfiguration.impl.ClusterImpl <em>Cluster</em>}' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see com.jennic.ZPSConfiguration.impl.ClusterImpl
	 * @see com.jennic.ZPSConfiguration.impl.ZPSConfigurationPackageImpl#getCluster()
	 * @generated
	 */
	int CLUSTER = 1;

	/**
	 * The feature id for the '<em><b>Name</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int CLUSTER__NAME = NAMED_OBJECT__NAME;

	/**
	 * The feature id for the '<em><b>Id</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int CLUSTER__ID = NAMED_OBJECT_FEATURE_COUNT + 0;

	/**
	 * The number of structural features of the '<em>Cluster</em>' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int CLUSTER_FEATURE_COUNT = NAMED_OBJECT_FEATURE_COUNT + 1;

	/**
	 * The meta object id for the '{@link com.jennic.ZPSConfiguration.impl.NodeImpl <em>Node</em>}' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see com.jennic.ZPSConfiguration.impl.NodeImpl
	 * @see com.jennic.ZPSConfiguration.impl.ZPSConfigurationPackageImpl#getNode()
	 * @generated
	 */
	int NODE = 2;

	/**
	 * The feature id for the '<em><b>Name</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int NODE__NAME = NAMED_OBJECT__NAME;

	/**
	 * The feature id for the '<em><b>Endpoints</b></em>' containment reference list.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int NODE__ENDPOINTS = NAMED_OBJECT_FEATURE_COUNT + 0;

	/**
	 * The feature id for the '<em><b>PDU Configuration</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int NODE__PDU_CONFIGURATION = NAMED_OBJECT_FEATURE_COUNT + 1;

	/**
	 * The feature id for the '<em><b>Channel Mask</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int NODE__CHANNEL_MASK = NAMED_OBJECT_FEATURE_COUNT + 2;

	/**
	 * The feature id for the '<em><b>Node Descriptor</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int NODE__NODE_DESCRIPTOR = NAMED_OBJECT_FEATURE_COUNT + 3;

	/**
	 * The feature id for the '<em><b>Node Power Descriptor</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int NODE__NODE_POWER_DESCRIPTOR = NAMED_OBJECT_FEATURE_COUNT + 4;

	/**
	 * The feature id for the '<em><b>User Descriptor</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int NODE__USER_DESCRIPTOR = NAMED_OBJECT_FEATURE_COUNT + 5;

	/**
	 * The feature id for the '<em><b>Binding Table</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int NODE__BINDING_TABLE = NAMED_OBJECT_FEATURE_COUNT + 6;

	/**
	 * The feature id for the '<em><b>Group Table</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int NODE__GROUP_TABLE = NAMED_OBJECT_FEATURE_COUNT + 7;

	/**
	 * The feature id for the '<em><b>Key Descriptor Table</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int NODE__KEY_DESCRIPTOR_TABLE = NAMED_OBJECT_FEATURE_COUNT + 8;

	/**
	 * The feature id for the '<em><b>Green Power Tx Queue</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int NODE__GREEN_POWER_TX_QUEUE = NAMED_OBJECT_FEATURE_COUNT + 9;

	/**
	 * The feature id for the '<em><b>Green Power Security Table</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int NODE__GREEN_POWER_SECURITY_TABLE = NAMED_OBJECT_FEATURE_COUNT + 10;

	/**
	 * The feature id for the '<em><b>Discovery Neighbour Table Size</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int NODE__DISCOVERY_NEIGHBOUR_TABLE_SIZE = NAMED_OBJECT_FEATURE_COUNT + 11;

	/**
	 * The feature id for the '<em><b>Active Neighbour Table Size</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int NODE__ACTIVE_NEIGHBOUR_TABLE_SIZE = NAMED_OBJECT_FEATURE_COUNT + 12;

	/**
	 * The feature id for the '<em><b>Route Discovery Table Size</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int NODE__ROUTE_DISCOVERY_TABLE_SIZE = NAMED_OBJECT_FEATURE_COUNT + 13;

	/**
	 * The feature id for the '<em><b>Routing Table Size</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int NODE__ROUTING_TABLE_SIZE = NAMED_OBJECT_FEATURE_COUNT + 14;

	/**
	 * The feature id for the '<em><b>Broadcast Transaction Table Size</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int NODE__BROADCAST_TRANSACTION_TABLE_SIZE = NAMED_OBJECT_FEATURE_COUNT + 15;

	/**
	 * The feature id for the '<em><b>Route Record Table Size</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int NODE__ROUTE_RECORD_TABLE_SIZE = NAMED_OBJECT_FEATURE_COUNT + 16;

	/**
	 * The feature id for the '<em><b>Address Map Table Size</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int NODE__ADDRESS_MAP_TABLE_SIZE = NAMED_OBJECT_FEATURE_COUNT + 17;

	/**
	 * The feature id for the '<em><b>Security Material Sets</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int NODE__SECURITY_MATERIAL_SETS = NAMED_OBJECT_FEATURE_COUNT + 18;

	/**
	 * The feature id for the '<em><b>Max Num Simultaneous Apsde Req</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int NODE__MAX_NUM_SIMULTANEOUS_APSDE_REQ = NAMED_OBJECT_FEATURE_COUNT + 19;

	/**
	 * The feature id for the '<em><b>Max Num Simultaneous Apsde Ack Req</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int NODE__MAX_NUM_SIMULTANEOUS_APSDE_ACK_REQ = NAMED_OBJECT_FEATURE_COUNT + 20;

	/**
	 * The feature id for the '<em><b>MAC Mutex Name</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int NODE__MAC_MUTEX_NAME = NAMED_OBJECT_FEATURE_COUNT + 21;

	/**
	 * The feature id for the '<em><b>ZPS Mutex Name</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int NODE__ZPS_MUTEX_NAME = NAMED_OBJECT_FEATURE_COUNT + 22;

	/**
	 * The feature id for the '<em><b>Fragmentation Max Num Simul Rx</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int NODE__FRAGMENTATION_MAX_NUM_SIMUL_RX = NAMED_OBJECT_FEATURE_COUNT + 23;

	/**
	 * The feature id for the '<em><b>Fragmentation Max Num Simul Tx</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int NODE__FRAGMENTATION_MAX_NUM_SIMUL_TX = NAMED_OBJECT_FEATURE_COUNT + 24;

	/**
	 * The feature id for the '<em><b>Default Event Message Name</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int NODE__DEFAULT_EVENT_MESSAGE_NAME = NAMED_OBJECT_FEATURE_COUNT + 25;

	/**
	 * The feature id for the '<em><b>MAC Dcfm Ind Message</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int NODE__MAC_DCFM_IND_MESSAGE = NAMED_OBJECT_FEATURE_COUNT + 26;

	/**
	 * The feature id for the '<em><b>MAC Time Event Message</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int NODE__MAC_TIME_EVENT_MESSAGE = NAMED_OBJECT_FEATURE_COUNT + 27;

	/**
	 * The feature id for the '<em><b>Aps Non Member Radius</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int NODE__APS_NON_MEMBER_RADIUS = NAMED_OBJECT_FEATURE_COUNT + 28;

	/**
	 * The feature id for the '<em><b>Aps Designated Coordinator</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int NODE__APS_DESIGNATED_COORDINATOR = NAMED_OBJECT_FEATURE_COUNT + 29;

	/**
	 * The feature id for the '<em><b>Aps Use Insecure Join</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int NODE__APS_USE_INSECURE_JOIN = NAMED_OBJECT_FEATURE_COUNT + 30;

	/**
	 * The feature id for the '<em><b>Aps Max Window Size</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int NODE__APS_MAX_WINDOW_SIZE = NAMED_OBJECT_FEATURE_COUNT + 31;

	/**
	 * The feature id for the '<em><b>Aps Interframe Delay</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int NODE__APS_INTERFRAME_DELAY = NAMED_OBJECT_FEATURE_COUNT + 32;

	/**
	 * The feature id for the '<em><b>APS Duplicate Table Size</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int NODE__APS_DUPLICATE_TABLE_SIZE = NAMED_OBJECT_FEATURE_COUNT + 33;

	/**
	 * The feature id for the '<em><b>Aps Security Timeout Period</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int NODE__APS_SECURITY_TIMEOUT_PERIOD = NAMED_OBJECT_FEATURE_COUNT + 34;

	/**
	 * The feature id for the '<em><b>Aps Use Ext PAN Id</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int NODE__APS_USE_EXT_PAN_ID = NAMED_OBJECT_FEATURE_COUNT + 35;

	/**
	 * The feature id for the '<em><b>Initial Network Key</b></em>' reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int NODE__INITIAL_NETWORK_KEY = NAMED_OBJECT_FEATURE_COUNT + 36;

	/**
	 * The feature id for the '<em><b>Security Enabled</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int NODE__SECURITY_ENABLED = NAMED_OBJECT_FEATURE_COUNT + 37;

	/**
	 * The feature id for the '<em><b>MAC Mlme Dcfm Ind Message</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int NODE__MAC_MLME_DCFM_IND_MESSAGE = NAMED_OBJECT_FEATURE_COUNT + 38;

	/**
	 * The feature id for the '<em><b>MAC Mcps Dcfm Ind Message</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int NODE__MAC_MCPS_DCFM_IND_MESSAGE = NAMED_OBJECT_FEATURE_COUNT + 39;

	/**
	 * The feature id for the '<em><b>APS Persistence Time</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int NODE__APS_PERSISTENCE_TIME = NAMED_OBJECT_FEATURE_COUNT + 40;

	/**
	 * The feature id for the '<em><b>Num APSME Simul Commands</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int NODE__NUM_APSME_SIMUL_COMMANDS = NAMED_OBJECT_FEATURE_COUNT + 41;

	/**
	 * The feature id for the '<em><b>Stack Profile</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int NODE__STACK_PROFILE = NAMED_OBJECT_FEATURE_COUNT + 42;

	/**
	 * The feature id for the '<em><b>Inter PAN</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int NODE__INTER_PAN = NAMED_OBJECT_FEATURE_COUNT + 43;

	/**
	 * The feature id for the '<em><b>Green Power Support</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int NODE__GREEN_POWER_SUPPORT = NAMED_OBJECT_FEATURE_COUNT + 44;

	/**
	 * The feature id for the '<em><b>Nwk Fc Save Count Bit Shift</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int NODE__NWK_FC_SAVE_COUNT_BIT_SHIFT = NAMED_OBJECT_FEATURE_COUNT + 45;

	/**
	 * The feature id for the '<em><b>Aps Fc Save Count Bit Shift</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int NODE__APS_FC_SAVE_COUNT_BIT_SHIFT = NAMED_OBJECT_FEATURE_COUNT + 46;

	/**
	 * The feature id for the '<em><b>Mac Table Size</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int NODE__MAC_TABLE_SIZE = NAMED_OBJECT_FEATURE_COUNT + 47;

	/**
	 * The feature id for the '<em><b>Default Callback Name</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int NODE__DEFAULT_CALLBACK_NAME = NAMED_OBJECT_FEATURE_COUNT + 48;

	/**
	 * The feature id for the '<em><b>Mac Interface List</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int NODE__MAC_INTERFACE_LIST = NAMED_OBJECT_FEATURE_COUNT + 49;

	/**
	 * The number of structural features of the '<em>Node</em>' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int NODE_FEATURE_COUNT = NAMED_OBJECT_FEATURE_COUNT + 50;

	/**
	 * The meta object id for the '{@link com.jennic.ZPSConfiguration.impl.AlwaysOnNodeImpl <em>Always On Node</em>}' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see com.jennic.ZPSConfiguration.impl.AlwaysOnNodeImpl
	 * @see com.jennic.ZPSConfiguration.impl.ZPSConfigurationPackageImpl#getAlwaysOnNode()
	 * @generated
	 */
	int ALWAYS_ON_NODE = 19;

	/**
	 * The feature id for the '<em><b>Name</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ALWAYS_ON_NODE__NAME = NODE__NAME;

	/**
	 * The feature id for the '<em><b>Endpoints</b></em>' containment reference list.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ALWAYS_ON_NODE__ENDPOINTS = NODE__ENDPOINTS;

	/**
	 * The feature id for the '<em><b>PDU Configuration</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ALWAYS_ON_NODE__PDU_CONFIGURATION = NODE__PDU_CONFIGURATION;

	/**
	 * The feature id for the '<em><b>Channel Mask</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ALWAYS_ON_NODE__CHANNEL_MASK = NODE__CHANNEL_MASK;

	/**
	 * The feature id for the '<em><b>Node Descriptor</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ALWAYS_ON_NODE__NODE_DESCRIPTOR = NODE__NODE_DESCRIPTOR;

	/**
	 * The feature id for the '<em><b>Node Power Descriptor</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ALWAYS_ON_NODE__NODE_POWER_DESCRIPTOR = NODE__NODE_POWER_DESCRIPTOR;

	/**
	 * The feature id for the '<em><b>User Descriptor</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ALWAYS_ON_NODE__USER_DESCRIPTOR = NODE__USER_DESCRIPTOR;

	/**
	 * The feature id for the '<em><b>Binding Table</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ALWAYS_ON_NODE__BINDING_TABLE = NODE__BINDING_TABLE;

	/**
	 * The feature id for the '<em><b>Group Table</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ALWAYS_ON_NODE__GROUP_TABLE = NODE__GROUP_TABLE;

	/**
	 * The feature id for the '<em><b>Key Descriptor Table</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ALWAYS_ON_NODE__KEY_DESCRIPTOR_TABLE = NODE__KEY_DESCRIPTOR_TABLE;

	/**
	 * The feature id for the '<em><b>Green Power Tx Queue</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ALWAYS_ON_NODE__GREEN_POWER_TX_QUEUE = NODE__GREEN_POWER_TX_QUEUE;

	/**
	 * The feature id for the '<em><b>Green Power Security Table</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ALWAYS_ON_NODE__GREEN_POWER_SECURITY_TABLE = NODE__GREEN_POWER_SECURITY_TABLE;

	/**
	 * The feature id for the '<em><b>Discovery Neighbour Table Size</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ALWAYS_ON_NODE__DISCOVERY_NEIGHBOUR_TABLE_SIZE = NODE__DISCOVERY_NEIGHBOUR_TABLE_SIZE;

	/**
	 * The feature id for the '<em><b>Active Neighbour Table Size</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ALWAYS_ON_NODE__ACTIVE_NEIGHBOUR_TABLE_SIZE = NODE__ACTIVE_NEIGHBOUR_TABLE_SIZE;

	/**
	 * The feature id for the '<em><b>Route Discovery Table Size</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ALWAYS_ON_NODE__ROUTE_DISCOVERY_TABLE_SIZE = NODE__ROUTE_DISCOVERY_TABLE_SIZE;

	/**
	 * The feature id for the '<em><b>Routing Table Size</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ALWAYS_ON_NODE__ROUTING_TABLE_SIZE = NODE__ROUTING_TABLE_SIZE;

	/**
	 * The feature id for the '<em><b>Broadcast Transaction Table Size</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ALWAYS_ON_NODE__BROADCAST_TRANSACTION_TABLE_SIZE = NODE__BROADCAST_TRANSACTION_TABLE_SIZE;

	/**
	 * The feature id for the '<em><b>Route Record Table Size</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ALWAYS_ON_NODE__ROUTE_RECORD_TABLE_SIZE = NODE__ROUTE_RECORD_TABLE_SIZE;

	/**
	 * The feature id for the '<em><b>Address Map Table Size</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ALWAYS_ON_NODE__ADDRESS_MAP_TABLE_SIZE = NODE__ADDRESS_MAP_TABLE_SIZE;

	/**
	 * The feature id for the '<em><b>Security Material Sets</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ALWAYS_ON_NODE__SECURITY_MATERIAL_SETS = NODE__SECURITY_MATERIAL_SETS;

	/**
	 * The feature id for the '<em><b>Max Num Simultaneous Apsde Req</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ALWAYS_ON_NODE__MAX_NUM_SIMULTANEOUS_APSDE_REQ = NODE__MAX_NUM_SIMULTANEOUS_APSDE_REQ;

	/**
	 * The feature id for the '<em><b>Max Num Simultaneous Apsde Ack Req</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ALWAYS_ON_NODE__MAX_NUM_SIMULTANEOUS_APSDE_ACK_REQ = NODE__MAX_NUM_SIMULTANEOUS_APSDE_ACK_REQ;

	/**
	 * The feature id for the '<em><b>MAC Mutex Name</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ALWAYS_ON_NODE__MAC_MUTEX_NAME = NODE__MAC_MUTEX_NAME;

	/**
	 * The feature id for the '<em><b>ZPS Mutex Name</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ALWAYS_ON_NODE__ZPS_MUTEX_NAME = NODE__ZPS_MUTEX_NAME;

	/**
	 * The feature id for the '<em><b>Fragmentation Max Num Simul Rx</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ALWAYS_ON_NODE__FRAGMENTATION_MAX_NUM_SIMUL_RX = NODE__FRAGMENTATION_MAX_NUM_SIMUL_RX;

	/**
	 * The feature id for the '<em><b>Fragmentation Max Num Simul Tx</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ALWAYS_ON_NODE__FRAGMENTATION_MAX_NUM_SIMUL_TX = NODE__FRAGMENTATION_MAX_NUM_SIMUL_TX;

	/**
	 * The feature id for the '<em><b>Default Event Message Name</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ALWAYS_ON_NODE__DEFAULT_EVENT_MESSAGE_NAME = NODE__DEFAULT_EVENT_MESSAGE_NAME;

	/**
	 * The feature id for the '<em><b>MAC Dcfm Ind Message</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ALWAYS_ON_NODE__MAC_DCFM_IND_MESSAGE = NODE__MAC_DCFM_IND_MESSAGE;

	/**
	 * The feature id for the '<em><b>MAC Time Event Message</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ALWAYS_ON_NODE__MAC_TIME_EVENT_MESSAGE = NODE__MAC_TIME_EVENT_MESSAGE;

	/**
	 * The feature id for the '<em><b>Aps Non Member Radius</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ALWAYS_ON_NODE__APS_NON_MEMBER_RADIUS = NODE__APS_NON_MEMBER_RADIUS;

	/**
	 * The feature id for the '<em><b>Aps Designated Coordinator</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ALWAYS_ON_NODE__APS_DESIGNATED_COORDINATOR = NODE__APS_DESIGNATED_COORDINATOR;

	/**
	 * The feature id for the '<em><b>Aps Use Insecure Join</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ALWAYS_ON_NODE__APS_USE_INSECURE_JOIN = NODE__APS_USE_INSECURE_JOIN;

	/**
	 * The feature id for the '<em><b>Aps Max Window Size</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ALWAYS_ON_NODE__APS_MAX_WINDOW_SIZE = NODE__APS_MAX_WINDOW_SIZE;

	/**
	 * The feature id for the '<em><b>Aps Interframe Delay</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ALWAYS_ON_NODE__APS_INTERFRAME_DELAY = NODE__APS_INTERFRAME_DELAY;

	/**
	 * The feature id for the '<em><b>APS Duplicate Table Size</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ALWAYS_ON_NODE__APS_DUPLICATE_TABLE_SIZE = NODE__APS_DUPLICATE_TABLE_SIZE;

	/**
	 * The feature id for the '<em><b>Aps Security Timeout Period</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ALWAYS_ON_NODE__APS_SECURITY_TIMEOUT_PERIOD = NODE__APS_SECURITY_TIMEOUT_PERIOD;

	/**
	 * The feature id for the '<em><b>Aps Use Ext PAN Id</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ALWAYS_ON_NODE__APS_USE_EXT_PAN_ID = NODE__APS_USE_EXT_PAN_ID;

	/**
	 * The feature id for the '<em><b>Initial Network Key</b></em>' reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ALWAYS_ON_NODE__INITIAL_NETWORK_KEY = NODE__INITIAL_NETWORK_KEY;

	/**
	 * The feature id for the '<em><b>Security Enabled</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ALWAYS_ON_NODE__SECURITY_ENABLED = NODE__SECURITY_ENABLED;

	/**
	 * The feature id for the '<em><b>MAC Mlme Dcfm Ind Message</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ALWAYS_ON_NODE__MAC_MLME_DCFM_IND_MESSAGE = NODE__MAC_MLME_DCFM_IND_MESSAGE;

	/**
	 * The feature id for the '<em><b>MAC Mcps Dcfm Ind Message</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ALWAYS_ON_NODE__MAC_MCPS_DCFM_IND_MESSAGE = NODE__MAC_MCPS_DCFM_IND_MESSAGE;

	/**
	 * The feature id for the '<em><b>APS Persistence Time</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ALWAYS_ON_NODE__APS_PERSISTENCE_TIME = NODE__APS_PERSISTENCE_TIME;

	/**
	 * The feature id for the '<em><b>Num APSME Simul Commands</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ALWAYS_ON_NODE__NUM_APSME_SIMUL_COMMANDS = NODE__NUM_APSME_SIMUL_COMMANDS;

	/**
	 * The feature id for the '<em><b>Stack Profile</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ALWAYS_ON_NODE__STACK_PROFILE = NODE__STACK_PROFILE;

	/**
	 * The feature id for the '<em><b>Inter PAN</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ALWAYS_ON_NODE__INTER_PAN = NODE__INTER_PAN;

	/**
	 * The feature id for the '<em><b>Green Power Support</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ALWAYS_ON_NODE__GREEN_POWER_SUPPORT = NODE__GREEN_POWER_SUPPORT;

	/**
	 * The feature id for the '<em><b>Nwk Fc Save Count Bit Shift</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ALWAYS_ON_NODE__NWK_FC_SAVE_COUNT_BIT_SHIFT = NODE__NWK_FC_SAVE_COUNT_BIT_SHIFT;

	/**
	 * The feature id for the '<em><b>Aps Fc Save Count Bit Shift</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ALWAYS_ON_NODE__APS_FC_SAVE_COUNT_BIT_SHIFT = NODE__APS_FC_SAVE_COUNT_BIT_SHIFT;

	/**
	 * The feature id for the '<em><b>Mac Table Size</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ALWAYS_ON_NODE__MAC_TABLE_SIZE = NODE__MAC_TABLE_SIZE;

	/**
	 * The feature id for the '<em><b>Default Callback Name</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ALWAYS_ON_NODE__DEFAULT_CALLBACK_NAME = NODE__DEFAULT_CALLBACK_NAME;

	/**
	 * The feature id for the '<em><b>Mac Interface List</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ALWAYS_ON_NODE__MAC_INTERFACE_LIST = NODE__MAC_INTERFACE_LIST;

	/**
	 * The feature id for the '<em><b>Trust Center</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ALWAYS_ON_NODE__TRUST_CENTER = NODE_FEATURE_COUNT + 0;

	/**
	 * The feature id for the '<em><b>Permit Joining Time</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ALWAYS_ON_NODE__PERMIT_JOINING_TIME = NODE_FEATURE_COUNT + 1;

	/**
	 * The feature id for the '<em><b>Child Table Size</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ALWAYS_ON_NODE__CHILD_TABLE_SIZE = NODE_FEATURE_COUNT + 2;

	/**
	 * The number of structural features of the '<em>Always On Node</em>' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ALWAYS_ON_NODE_FEATURE_COUNT = NODE_FEATURE_COUNT + 3;

	/**
	 * The meta object id for the '{@link com.jennic.ZPSConfiguration.impl.CoordinatorImpl <em>Coordinator</em>}' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see com.jennic.ZPSConfiguration.impl.CoordinatorImpl
	 * @see com.jennic.ZPSConfiguration.impl.ZPSConfigurationPackageImpl#getCoordinator()
	 * @generated
	 */
	int COORDINATOR = 3;

	/**
	 * The feature id for the '<em><b>Name</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int COORDINATOR__NAME = ALWAYS_ON_NODE__NAME;

	/**
	 * The feature id for the '<em><b>Endpoints</b></em>' containment reference list.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int COORDINATOR__ENDPOINTS = ALWAYS_ON_NODE__ENDPOINTS;

	/**
	 * The feature id for the '<em><b>PDU Configuration</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int COORDINATOR__PDU_CONFIGURATION = ALWAYS_ON_NODE__PDU_CONFIGURATION;

	/**
	 * The feature id for the '<em><b>Channel Mask</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int COORDINATOR__CHANNEL_MASK = ALWAYS_ON_NODE__CHANNEL_MASK;

	/**
	 * The feature id for the '<em><b>Node Descriptor</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int COORDINATOR__NODE_DESCRIPTOR = ALWAYS_ON_NODE__NODE_DESCRIPTOR;

	/**
	 * The feature id for the '<em><b>Node Power Descriptor</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int COORDINATOR__NODE_POWER_DESCRIPTOR = ALWAYS_ON_NODE__NODE_POWER_DESCRIPTOR;

	/**
	 * The feature id for the '<em><b>User Descriptor</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int COORDINATOR__USER_DESCRIPTOR = ALWAYS_ON_NODE__USER_DESCRIPTOR;

	/**
	 * The feature id for the '<em><b>Binding Table</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int COORDINATOR__BINDING_TABLE = ALWAYS_ON_NODE__BINDING_TABLE;

	/**
	 * The feature id for the '<em><b>Group Table</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int COORDINATOR__GROUP_TABLE = ALWAYS_ON_NODE__GROUP_TABLE;

	/**
	 * The feature id for the '<em><b>Key Descriptor Table</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int COORDINATOR__KEY_DESCRIPTOR_TABLE = ALWAYS_ON_NODE__KEY_DESCRIPTOR_TABLE;

	/**
	 * The feature id for the '<em><b>Green Power Tx Queue</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int COORDINATOR__GREEN_POWER_TX_QUEUE = ALWAYS_ON_NODE__GREEN_POWER_TX_QUEUE;

	/**
	 * The feature id for the '<em><b>Green Power Security Table</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int COORDINATOR__GREEN_POWER_SECURITY_TABLE = ALWAYS_ON_NODE__GREEN_POWER_SECURITY_TABLE;

	/**
	 * The feature id for the '<em><b>Discovery Neighbour Table Size</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int COORDINATOR__DISCOVERY_NEIGHBOUR_TABLE_SIZE = ALWAYS_ON_NODE__DISCOVERY_NEIGHBOUR_TABLE_SIZE;

	/**
	 * The feature id for the '<em><b>Active Neighbour Table Size</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int COORDINATOR__ACTIVE_NEIGHBOUR_TABLE_SIZE = ALWAYS_ON_NODE__ACTIVE_NEIGHBOUR_TABLE_SIZE;

	/**
	 * The feature id for the '<em><b>Route Discovery Table Size</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int COORDINATOR__ROUTE_DISCOVERY_TABLE_SIZE = ALWAYS_ON_NODE__ROUTE_DISCOVERY_TABLE_SIZE;

	/**
	 * The feature id for the '<em><b>Routing Table Size</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int COORDINATOR__ROUTING_TABLE_SIZE = ALWAYS_ON_NODE__ROUTING_TABLE_SIZE;

	/**
	 * The feature id for the '<em><b>Broadcast Transaction Table Size</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int COORDINATOR__BROADCAST_TRANSACTION_TABLE_SIZE = ALWAYS_ON_NODE__BROADCAST_TRANSACTION_TABLE_SIZE;

	/**
	 * The feature id for the '<em><b>Route Record Table Size</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int COORDINATOR__ROUTE_RECORD_TABLE_SIZE = ALWAYS_ON_NODE__ROUTE_RECORD_TABLE_SIZE;

	/**
	 * The feature id for the '<em><b>Address Map Table Size</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int COORDINATOR__ADDRESS_MAP_TABLE_SIZE = ALWAYS_ON_NODE__ADDRESS_MAP_TABLE_SIZE;

	/**
	 * The feature id for the '<em><b>Security Material Sets</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int COORDINATOR__SECURITY_MATERIAL_SETS = ALWAYS_ON_NODE__SECURITY_MATERIAL_SETS;

	/**
	 * The feature id for the '<em><b>Max Num Simultaneous Apsde Req</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int COORDINATOR__MAX_NUM_SIMULTANEOUS_APSDE_REQ = ALWAYS_ON_NODE__MAX_NUM_SIMULTANEOUS_APSDE_REQ;

	/**
	 * The feature id for the '<em><b>Max Num Simultaneous Apsde Ack Req</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int COORDINATOR__MAX_NUM_SIMULTANEOUS_APSDE_ACK_REQ = ALWAYS_ON_NODE__MAX_NUM_SIMULTANEOUS_APSDE_ACK_REQ;

	/**
	 * The feature id for the '<em><b>MAC Mutex Name</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int COORDINATOR__MAC_MUTEX_NAME = ALWAYS_ON_NODE__MAC_MUTEX_NAME;

	/**
	 * The feature id for the '<em><b>ZPS Mutex Name</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int COORDINATOR__ZPS_MUTEX_NAME = ALWAYS_ON_NODE__ZPS_MUTEX_NAME;

	/**
	 * The feature id for the '<em><b>Fragmentation Max Num Simul Rx</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int COORDINATOR__FRAGMENTATION_MAX_NUM_SIMUL_RX = ALWAYS_ON_NODE__FRAGMENTATION_MAX_NUM_SIMUL_RX;

	/**
	 * The feature id for the '<em><b>Fragmentation Max Num Simul Tx</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int COORDINATOR__FRAGMENTATION_MAX_NUM_SIMUL_TX = ALWAYS_ON_NODE__FRAGMENTATION_MAX_NUM_SIMUL_TX;

	/**
	 * The feature id for the '<em><b>Default Event Message Name</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int COORDINATOR__DEFAULT_EVENT_MESSAGE_NAME = ALWAYS_ON_NODE__DEFAULT_EVENT_MESSAGE_NAME;

	/**
	 * The feature id for the '<em><b>MAC Dcfm Ind Message</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int COORDINATOR__MAC_DCFM_IND_MESSAGE = ALWAYS_ON_NODE__MAC_DCFM_IND_MESSAGE;

	/**
	 * The feature id for the '<em><b>MAC Time Event Message</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int COORDINATOR__MAC_TIME_EVENT_MESSAGE = ALWAYS_ON_NODE__MAC_TIME_EVENT_MESSAGE;

	/**
	 * The feature id for the '<em><b>Aps Non Member Radius</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int COORDINATOR__APS_NON_MEMBER_RADIUS = ALWAYS_ON_NODE__APS_NON_MEMBER_RADIUS;

	/**
	 * The feature id for the '<em><b>Aps Designated Coordinator</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int COORDINATOR__APS_DESIGNATED_COORDINATOR = ALWAYS_ON_NODE__APS_DESIGNATED_COORDINATOR;

	/**
	 * The feature id for the '<em><b>Aps Use Insecure Join</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int COORDINATOR__APS_USE_INSECURE_JOIN = ALWAYS_ON_NODE__APS_USE_INSECURE_JOIN;

	/**
	 * The feature id for the '<em><b>Aps Max Window Size</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int COORDINATOR__APS_MAX_WINDOW_SIZE = ALWAYS_ON_NODE__APS_MAX_WINDOW_SIZE;

	/**
	 * The feature id for the '<em><b>Aps Interframe Delay</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int COORDINATOR__APS_INTERFRAME_DELAY = ALWAYS_ON_NODE__APS_INTERFRAME_DELAY;

	/**
	 * The feature id for the '<em><b>APS Duplicate Table Size</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int COORDINATOR__APS_DUPLICATE_TABLE_SIZE = ALWAYS_ON_NODE__APS_DUPLICATE_TABLE_SIZE;

	/**
	 * The feature id for the '<em><b>Aps Security Timeout Period</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int COORDINATOR__APS_SECURITY_TIMEOUT_PERIOD = ALWAYS_ON_NODE__APS_SECURITY_TIMEOUT_PERIOD;

	/**
	 * The feature id for the '<em><b>Aps Use Ext PAN Id</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int COORDINATOR__APS_USE_EXT_PAN_ID = ALWAYS_ON_NODE__APS_USE_EXT_PAN_ID;

	/**
	 * The feature id for the '<em><b>Initial Network Key</b></em>' reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int COORDINATOR__INITIAL_NETWORK_KEY = ALWAYS_ON_NODE__INITIAL_NETWORK_KEY;

	/**
	 * The feature id for the '<em><b>Security Enabled</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int COORDINATOR__SECURITY_ENABLED = ALWAYS_ON_NODE__SECURITY_ENABLED;

	/**
	 * The feature id for the '<em><b>MAC Mlme Dcfm Ind Message</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int COORDINATOR__MAC_MLME_DCFM_IND_MESSAGE = ALWAYS_ON_NODE__MAC_MLME_DCFM_IND_MESSAGE;

	/**
	 * The feature id for the '<em><b>MAC Mcps Dcfm Ind Message</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int COORDINATOR__MAC_MCPS_DCFM_IND_MESSAGE = ALWAYS_ON_NODE__MAC_MCPS_DCFM_IND_MESSAGE;

	/**
	 * The feature id for the '<em><b>APS Persistence Time</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int COORDINATOR__APS_PERSISTENCE_TIME = ALWAYS_ON_NODE__APS_PERSISTENCE_TIME;

	/**
	 * The feature id for the '<em><b>Num APSME Simul Commands</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int COORDINATOR__NUM_APSME_SIMUL_COMMANDS = ALWAYS_ON_NODE__NUM_APSME_SIMUL_COMMANDS;

	/**
	 * The feature id for the '<em><b>Stack Profile</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int COORDINATOR__STACK_PROFILE = ALWAYS_ON_NODE__STACK_PROFILE;

	/**
	 * The feature id for the '<em><b>Inter PAN</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int COORDINATOR__INTER_PAN = ALWAYS_ON_NODE__INTER_PAN;

	/**
	 * The feature id for the '<em><b>Green Power Support</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int COORDINATOR__GREEN_POWER_SUPPORT = ALWAYS_ON_NODE__GREEN_POWER_SUPPORT;

	/**
	 * The feature id for the '<em><b>Nwk Fc Save Count Bit Shift</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int COORDINATOR__NWK_FC_SAVE_COUNT_BIT_SHIFT = ALWAYS_ON_NODE__NWK_FC_SAVE_COUNT_BIT_SHIFT;

	/**
	 * The feature id for the '<em><b>Aps Fc Save Count Bit Shift</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int COORDINATOR__APS_FC_SAVE_COUNT_BIT_SHIFT = ALWAYS_ON_NODE__APS_FC_SAVE_COUNT_BIT_SHIFT;

	/**
	 * The feature id for the '<em><b>Mac Table Size</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int COORDINATOR__MAC_TABLE_SIZE = ALWAYS_ON_NODE__MAC_TABLE_SIZE;

	/**
	 * The feature id for the '<em><b>Default Callback Name</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int COORDINATOR__DEFAULT_CALLBACK_NAME = ALWAYS_ON_NODE__DEFAULT_CALLBACK_NAME;

	/**
	 * The feature id for the '<em><b>Mac Interface List</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int COORDINATOR__MAC_INTERFACE_LIST = ALWAYS_ON_NODE__MAC_INTERFACE_LIST;

	/**
	 * The feature id for the '<em><b>Trust Center</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int COORDINATOR__TRUST_CENTER = ALWAYS_ON_NODE__TRUST_CENTER;

	/**
	 * The feature id for the '<em><b>Permit Joining Time</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int COORDINATOR__PERMIT_JOINING_TIME = ALWAYS_ON_NODE__PERMIT_JOINING_TIME;

	/**
	 * The feature id for the '<em><b>Child Table Size</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int COORDINATOR__CHILD_TABLE_SIZE = ALWAYS_ON_NODE__CHILD_TABLE_SIZE;

	/**
	 * The feature id for the '<em><b>ZDO Servers</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int COORDINATOR__ZDO_SERVERS = ALWAYS_ON_NODE_FEATURE_COUNT + 0;

	/**
	 * The number of structural features of the '<em>Coordinator</em>' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int COORDINATOR_FEATURE_COUNT = ALWAYS_ON_NODE_FEATURE_COUNT + 1;

	/**
	 * The meta object id for the '{@link com.jennic.ZPSConfiguration.impl.RouterImpl <em>Router</em>}' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see com.jennic.ZPSConfiguration.impl.RouterImpl
	 * @see com.jennic.ZPSConfiguration.impl.ZPSConfigurationPackageImpl#getRouter()
	 * @generated
	 */
	int ROUTER = 4;

	/**
	 * The feature id for the '<em><b>Name</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ROUTER__NAME = ALWAYS_ON_NODE__NAME;

	/**
	 * The feature id for the '<em><b>Endpoints</b></em>' containment reference list.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ROUTER__ENDPOINTS = ALWAYS_ON_NODE__ENDPOINTS;

	/**
	 * The feature id for the '<em><b>PDU Configuration</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ROUTER__PDU_CONFIGURATION = ALWAYS_ON_NODE__PDU_CONFIGURATION;

	/**
	 * The feature id for the '<em><b>Channel Mask</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ROUTER__CHANNEL_MASK = ALWAYS_ON_NODE__CHANNEL_MASK;

	/**
	 * The feature id for the '<em><b>Node Descriptor</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ROUTER__NODE_DESCRIPTOR = ALWAYS_ON_NODE__NODE_DESCRIPTOR;

	/**
	 * The feature id for the '<em><b>Node Power Descriptor</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ROUTER__NODE_POWER_DESCRIPTOR = ALWAYS_ON_NODE__NODE_POWER_DESCRIPTOR;

	/**
	 * The feature id for the '<em><b>User Descriptor</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ROUTER__USER_DESCRIPTOR = ALWAYS_ON_NODE__USER_DESCRIPTOR;

	/**
	 * The feature id for the '<em><b>Binding Table</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ROUTER__BINDING_TABLE = ALWAYS_ON_NODE__BINDING_TABLE;

	/**
	 * The feature id for the '<em><b>Group Table</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ROUTER__GROUP_TABLE = ALWAYS_ON_NODE__GROUP_TABLE;

	/**
	 * The feature id for the '<em><b>Key Descriptor Table</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ROUTER__KEY_DESCRIPTOR_TABLE = ALWAYS_ON_NODE__KEY_DESCRIPTOR_TABLE;

	/**
	 * The feature id for the '<em><b>Green Power Tx Queue</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ROUTER__GREEN_POWER_TX_QUEUE = ALWAYS_ON_NODE__GREEN_POWER_TX_QUEUE;

	/**
	 * The feature id for the '<em><b>Green Power Security Table</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ROUTER__GREEN_POWER_SECURITY_TABLE = ALWAYS_ON_NODE__GREEN_POWER_SECURITY_TABLE;

	/**
	 * The feature id for the '<em><b>Discovery Neighbour Table Size</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ROUTER__DISCOVERY_NEIGHBOUR_TABLE_SIZE = ALWAYS_ON_NODE__DISCOVERY_NEIGHBOUR_TABLE_SIZE;

	/**
	 * The feature id for the '<em><b>Active Neighbour Table Size</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ROUTER__ACTIVE_NEIGHBOUR_TABLE_SIZE = ALWAYS_ON_NODE__ACTIVE_NEIGHBOUR_TABLE_SIZE;

	/**
	 * The feature id for the '<em><b>Route Discovery Table Size</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ROUTER__ROUTE_DISCOVERY_TABLE_SIZE = ALWAYS_ON_NODE__ROUTE_DISCOVERY_TABLE_SIZE;

	/**
	 * The feature id for the '<em><b>Routing Table Size</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ROUTER__ROUTING_TABLE_SIZE = ALWAYS_ON_NODE__ROUTING_TABLE_SIZE;

	/**
	 * The feature id for the '<em><b>Broadcast Transaction Table Size</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ROUTER__BROADCAST_TRANSACTION_TABLE_SIZE = ALWAYS_ON_NODE__BROADCAST_TRANSACTION_TABLE_SIZE;

	/**
	 * The feature id for the '<em><b>Route Record Table Size</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ROUTER__ROUTE_RECORD_TABLE_SIZE = ALWAYS_ON_NODE__ROUTE_RECORD_TABLE_SIZE;

	/**
	 * The feature id for the '<em><b>Address Map Table Size</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ROUTER__ADDRESS_MAP_TABLE_SIZE = ALWAYS_ON_NODE__ADDRESS_MAP_TABLE_SIZE;

	/**
	 * The feature id for the '<em><b>Security Material Sets</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ROUTER__SECURITY_MATERIAL_SETS = ALWAYS_ON_NODE__SECURITY_MATERIAL_SETS;

	/**
	 * The feature id for the '<em><b>Max Num Simultaneous Apsde Req</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ROUTER__MAX_NUM_SIMULTANEOUS_APSDE_REQ = ALWAYS_ON_NODE__MAX_NUM_SIMULTANEOUS_APSDE_REQ;

	/**
	 * The feature id for the '<em><b>Max Num Simultaneous Apsde Ack Req</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ROUTER__MAX_NUM_SIMULTANEOUS_APSDE_ACK_REQ = ALWAYS_ON_NODE__MAX_NUM_SIMULTANEOUS_APSDE_ACK_REQ;

	/**
	 * The feature id for the '<em><b>MAC Mutex Name</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ROUTER__MAC_MUTEX_NAME = ALWAYS_ON_NODE__MAC_MUTEX_NAME;

	/**
	 * The feature id for the '<em><b>ZPS Mutex Name</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ROUTER__ZPS_MUTEX_NAME = ALWAYS_ON_NODE__ZPS_MUTEX_NAME;

	/**
	 * The feature id for the '<em><b>Fragmentation Max Num Simul Rx</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ROUTER__FRAGMENTATION_MAX_NUM_SIMUL_RX = ALWAYS_ON_NODE__FRAGMENTATION_MAX_NUM_SIMUL_RX;

	/**
	 * The feature id for the '<em><b>Fragmentation Max Num Simul Tx</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ROUTER__FRAGMENTATION_MAX_NUM_SIMUL_TX = ALWAYS_ON_NODE__FRAGMENTATION_MAX_NUM_SIMUL_TX;

	/**
	 * The feature id for the '<em><b>Default Event Message Name</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ROUTER__DEFAULT_EVENT_MESSAGE_NAME = ALWAYS_ON_NODE__DEFAULT_EVENT_MESSAGE_NAME;

	/**
	 * The feature id for the '<em><b>MAC Dcfm Ind Message</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ROUTER__MAC_DCFM_IND_MESSAGE = ALWAYS_ON_NODE__MAC_DCFM_IND_MESSAGE;

	/**
	 * The feature id for the '<em><b>MAC Time Event Message</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ROUTER__MAC_TIME_EVENT_MESSAGE = ALWAYS_ON_NODE__MAC_TIME_EVENT_MESSAGE;

	/**
	 * The feature id for the '<em><b>Aps Non Member Radius</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ROUTER__APS_NON_MEMBER_RADIUS = ALWAYS_ON_NODE__APS_NON_MEMBER_RADIUS;

	/**
	 * The feature id for the '<em><b>Aps Designated Coordinator</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ROUTER__APS_DESIGNATED_COORDINATOR = ALWAYS_ON_NODE__APS_DESIGNATED_COORDINATOR;

	/**
	 * The feature id for the '<em><b>Aps Use Insecure Join</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ROUTER__APS_USE_INSECURE_JOIN = ALWAYS_ON_NODE__APS_USE_INSECURE_JOIN;

	/**
	 * The feature id for the '<em><b>Aps Max Window Size</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ROUTER__APS_MAX_WINDOW_SIZE = ALWAYS_ON_NODE__APS_MAX_WINDOW_SIZE;

	/**
	 * The feature id for the '<em><b>Aps Interframe Delay</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ROUTER__APS_INTERFRAME_DELAY = ALWAYS_ON_NODE__APS_INTERFRAME_DELAY;

	/**
	 * The feature id for the '<em><b>APS Duplicate Table Size</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ROUTER__APS_DUPLICATE_TABLE_SIZE = ALWAYS_ON_NODE__APS_DUPLICATE_TABLE_SIZE;

	/**
	 * The feature id for the '<em><b>Aps Security Timeout Period</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ROUTER__APS_SECURITY_TIMEOUT_PERIOD = ALWAYS_ON_NODE__APS_SECURITY_TIMEOUT_PERIOD;

	/**
	 * The feature id for the '<em><b>Aps Use Ext PAN Id</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ROUTER__APS_USE_EXT_PAN_ID = ALWAYS_ON_NODE__APS_USE_EXT_PAN_ID;

	/**
	 * The feature id for the '<em><b>Initial Network Key</b></em>' reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ROUTER__INITIAL_NETWORK_KEY = ALWAYS_ON_NODE__INITIAL_NETWORK_KEY;

	/**
	 * The feature id for the '<em><b>Security Enabled</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ROUTER__SECURITY_ENABLED = ALWAYS_ON_NODE__SECURITY_ENABLED;

	/**
	 * The feature id for the '<em><b>MAC Mlme Dcfm Ind Message</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ROUTER__MAC_MLME_DCFM_IND_MESSAGE = ALWAYS_ON_NODE__MAC_MLME_DCFM_IND_MESSAGE;

	/**
	 * The feature id for the '<em><b>MAC Mcps Dcfm Ind Message</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ROUTER__MAC_MCPS_DCFM_IND_MESSAGE = ALWAYS_ON_NODE__MAC_MCPS_DCFM_IND_MESSAGE;

	/**
	 * The feature id for the '<em><b>APS Persistence Time</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ROUTER__APS_PERSISTENCE_TIME = ALWAYS_ON_NODE__APS_PERSISTENCE_TIME;

	/**
	 * The feature id for the '<em><b>Num APSME Simul Commands</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ROUTER__NUM_APSME_SIMUL_COMMANDS = ALWAYS_ON_NODE__NUM_APSME_SIMUL_COMMANDS;

	/**
	 * The feature id for the '<em><b>Stack Profile</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ROUTER__STACK_PROFILE = ALWAYS_ON_NODE__STACK_PROFILE;

	/**
	 * The feature id for the '<em><b>Inter PAN</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ROUTER__INTER_PAN = ALWAYS_ON_NODE__INTER_PAN;

	/**
	 * The feature id for the '<em><b>Green Power Support</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ROUTER__GREEN_POWER_SUPPORT = ALWAYS_ON_NODE__GREEN_POWER_SUPPORT;

	/**
	 * The feature id for the '<em><b>Nwk Fc Save Count Bit Shift</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ROUTER__NWK_FC_SAVE_COUNT_BIT_SHIFT = ALWAYS_ON_NODE__NWK_FC_SAVE_COUNT_BIT_SHIFT;

	/**
	 * The feature id for the '<em><b>Aps Fc Save Count Bit Shift</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ROUTER__APS_FC_SAVE_COUNT_BIT_SHIFT = ALWAYS_ON_NODE__APS_FC_SAVE_COUNT_BIT_SHIFT;

	/**
	 * The feature id for the '<em><b>Mac Table Size</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ROUTER__MAC_TABLE_SIZE = ALWAYS_ON_NODE__MAC_TABLE_SIZE;

	/**
	 * The feature id for the '<em><b>Default Callback Name</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ROUTER__DEFAULT_CALLBACK_NAME = ALWAYS_ON_NODE__DEFAULT_CALLBACK_NAME;

	/**
	 * The feature id for the '<em><b>Mac Interface List</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ROUTER__MAC_INTERFACE_LIST = ALWAYS_ON_NODE__MAC_INTERFACE_LIST;

	/**
	 * The feature id for the '<em><b>Trust Center</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ROUTER__TRUST_CENTER = ALWAYS_ON_NODE__TRUST_CENTER;

	/**
	 * The feature id for the '<em><b>Permit Joining Time</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ROUTER__PERMIT_JOINING_TIME = ALWAYS_ON_NODE__PERMIT_JOINING_TIME;

	/**
	 * The feature id for the '<em><b>Child Table Size</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ROUTER__CHILD_TABLE_SIZE = ALWAYS_ON_NODE__CHILD_TABLE_SIZE;

	/**
	 * The feature id for the '<em><b>Scan Duration</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ROUTER__SCAN_DURATION = ALWAYS_ON_NODE_FEATURE_COUNT + 0;

	/**
	 * The feature id for the '<em><b>Network Selection</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ROUTER__NETWORK_SELECTION = ALWAYS_ON_NODE_FEATURE_COUNT + 1;

	/**
	 * The feature id for the '<em><b>ZDO Servers</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ROUTER__ZDO_SERVERS = ALWAYS_ON_NODE_FEATURE_COUNT + 2;

	/**
	 * The number of structural features of the '<em>Router</em>' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ROUTER_FEATURE_COUNT = ALWAYS_ON_NODE_FEATURE_COUNT + 3;

	/**
	 * The meta object id for the '{@link com.jennic.ZPSConfiguration.impl.EndDeviceImpl <em>End Device</em>}' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see com.jennic.ZPSConfiguration.impl.EndDeviceImpl
	 * @see com.jennic.ZPSConfiguration.impl.ZPSConfigurationPackageImpl#getEndDevice()
	 * @generated
	 */
	int END_DEVICE = 5;

	/**
	 * The feature id for the '<em><b>Name</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int END_DEVICE__NAME = NODE__NAME;

	/**
	 * The feature id for the '<em><b>Endpoints</b></em>' containment reference list.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int END_DEVICE__ENDPOINTS = NODE__ENDPOINTS;

	/**
	 * The feature id for the '<em><b>PDU Configuration</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int END_DEVICE__PDU_CONFIGURATION = NODE__PDU_CONFIGURATION;

	/**
	 * The feature id for the '<em><b>Channel Mask</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int END_DEVICE__CHANNEL_MASK = NODE__CHANNEL_MASK;

	/**
	 * The feature id for the '<em><b>Node Descriptor</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int END_DEVICE__NODE_DESCRIPTOR = NODE__NODE_DESCRIPTOR;

	/**
	 * The feature id for the '<em><b>Node Power Descriptor</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int END_DEVICE__NODE_POWER_DESCRIPTOR = NODE__NODE_POWER_DESCRIPTOR;

	/**
	 * The feature id for the '<em><b>User Descriptor</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int END_DEVICE__USER_DESCRIPTOR = NODE__USER_DESCRIPTOR;

	/**
	 * The feature id for the '<em><b>Binding Table</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int END_DEVICE__BINDING_TABLE = NODE__BINDING_TABLE;

	/**
	 * The feature id for the '<em><b>Group Table</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int END_DEVICE__GROUP_TABLE = NODE__GROUP_TABLE;

	/**
	 * The feature id for the '<em><b>Key Descriptor Table</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int END_DEVICE__KEY_DESCRIPTOR_TABLE = NODE__KEY_DESCRIPTOR_TABLE;

	/**
	 * The feature id for the '<em><b>Green Power Tx Queue</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int END_DEVICE__GREEN_POWER_TX_QUEUE = NODE__GREEN_POWER_TX_QUEUE;

	/**
	 * The feature id for the '<em><b>Green Power Security Table</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int END_DEVICE__GREEN_POWER_SECURITY_TABLE = NODE__GREEN_POWER_SECURITY_TABLE;

	/**
	 * The feature id for the '<em><b>Discovery Neighbour Table Size</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int END_DEVICE__DISCOVERY_NEIGHBOUR_TABLE_SIZE = NODE__DISCOVERY_NEIGHBOUR_TABLE_SIZE;

	/**
	 * The feature id for the '<em><b>Active Neighbour Table Size</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int END_DEVICE__ACTIVE_NEIGHBOUR_TABLE_SIZE = NODE__ACTIVE_NEIGHBOUR_TABLE_SIZE;

	/**
	 * The feature id for the '<em><b>Route Discovery Table Size</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int END_DEVICE__ROUTE_DISCOVERY_TABLE_SIZE = NODE__ROUTE_DISCOVERY_TABLE_SIZE;

	/**
	 * The feature id for the '<em><b>Routing Table Size</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int END_DEVICE__ROUTING_TABLE_SIZE = NODE__ROUTING_TABLE_SIZE;

	/**
	 * The feature id for the '<em><b>Broadcast Transaction Table Size</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int END_DEVICE__BROADCAST_TRANSACTION_TABLE_SIZE = NODE__BROADCAST_TRANSACTION_TABLE_SIZE;

	/**
	 * The feature id for the '<em><b>Route Record Table Size</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int END_DEVICE__ROUTE_RECORD_TABLE_SIZE = NODE__ROUTE_RECORD_TABLE_SIZE;

	/**
	 * The feature id for the '<em><b>Address Map Table Size</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int END_DEVICE__ADDRESS_MAP_TABLE_SIZE = NODE__ADDRESS_MAP_TABLE_SIZE;

	/**
	 * The feature id for the '<em><b>Security Material Sets</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int END_DEVICE__SECURITY_MATERIAL_SETS = NODE__SECURITY_MATERIAL_SETS;

	/**
	 * The feature id for the '<em><b>Max Num Simultaneous Apsde Req</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int END_DEVICE__MAX_NUM_SIMULTANEOUS_APSDE_REQ = NODE__MAX_NUM_SIMULTANEOUS_APSDE_REQ;

	/**
	 * The feature id for the '<em><b>Max Num Simultaneous Apsde Ack Req</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int END_DEVICE__MAX_NUM_SIMULTANEOUS_APSDE_ACK_REQ = NODE__MAX_NUM_SIMULTANEOUS_APSDE_ACK_REQ;

	/**
	 * The feature id for the '<em><b>MAC Mutex Name</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int END_DEVICE__MAC_MUTEX_NAME = NODE__MAC_MUTEX_NAME;

	/**
	 * The feature id for the '<em><b>ZPS Mutex Name</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int END_DEVICE__ZPS_MUTEX_NAME = NODE__ZPS_MUTEX_NAME;

	/**
	 * The feature id for the '<em><b>Fragmentation Max Num Simul Rx</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int END_DEVICE__FRAGMENTATION_MAX_NUM_SIMUL_RX = NODE__FRAGMENTATION_MAX_NUM_SIMUL_RX;

	/**
	 * The feature id for the '<em><b>Fragmentation Max Num Simul Tx</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int END_DEVICE__FRAGMENTATION_MAX_NUM_SIMUL_TX = NODE__FRAGMENTATION_MAX_NUM_SIMUL_TX;

	/**
	 * The feature id for the '<em><b>Default Event Message Name</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int END_DEVICE__DEFAULT_EVENT_MESSAGE_NAME = NODE__DEFAULT_EVENT_MESSAGE_NAME;

	/**
	 * The feature id for the '<em><b>MAC Dcfm Ind Message</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int END_DEVICE__MAC_DCFM_IND_MESSAGE = NODE__MAC_DCFM_IND_MESSAGE;

	/**
	 * The feature id for the '<em><b>MAC Time Event Message</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int END_DEVICE__MAC_TIME_EVENT_MESSAGE = NODE__MAC_TIME_EVENT_MESSAGE;

	/**
	 * The feature id for the '<em><b>Aps Non Member Radius</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int END_DEVICE__APS_NON_MEMBER_RADIUS = NODE__APS_NON_MEMBER_RADIUS;

	/**
	 * The feature id for the '<em><b>Aps Designated Coordinator</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int END_DEVICE__APS_DESIGNATED_COORDINATOR = NODE__APS_DESIGNATED_COORDINATOR;

	/**
	 * The feature id for the '<em><b>Aps Use Insecure Join</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int END_DEVICE__APS_USE_INSECURE_JOIN = NODE__APS_USE_INSECURE_JOIN;

	/**
	 * The feature id for the '<em><b>Aps Max Window Size</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int END_DEVICE__APS_MAX_WINDOW_SIZE = NODE__APS_MAX_WINDOW_SIZE;

	/**
	 * The feature id for the '<em><b>Aps Interframe Delay</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int END_DEVICE__APS_INTERFRAME_DELAY = NODE__APS_INTERFRAME_DELAY;

	/**
	 * The feature id for the '<em><b>APS Duplicate Table Size</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int END_DEVICE__APS_DUPLICATE_TABLE_SIZE = NODE__APS_DUPLICATE_TABLE_SIZE;

	/**
	 * The feature id for the '<em><b>Aps Security Timeout Period</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int END_DEVICE__APS_SECURITY_TIMEOUT_PERIOD = NODE__APS_SECURITY_TIMEOUT_PERIOD;

	/**
	 * The feature id for the '<em><b>Aps Use Ext PAN Id</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int END_DEVICE__APS_USE_EXT_PAN_ID = NODE__APS_USE_EXT_PAN_ID;

	/**
	 * The feature id for the '<em><b>Initial Network Key</b></em>' reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int END_DEVICE__INITIAL_NETWORK_KEY = NODE__INITIAL_NETWORK_KEY;

	/**
	 * The feature id for the '<em><b>Security Enabled</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int END_DEVICE__SECURITY_ENABLED = NODE__SECURITY_ENABLED;

	/**
	 * The feature id for the '<em><b>MAC Mlme Dcfm Ind Message</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int END_DEVICE__MAC_MLME_DCFM_IND_MESSAGE = NODE__MAC_MLME_DCFM_IND_MESSAGE;

	/**
	 * The feature id for the '<em><b>MAC Mcps Dcfm Ind Message</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int END_DEVICE__MAC_MCPS_DCFM_IND_MESSAGE = NODE__MAC_MCPS_DCFM_IND_MESSAGE;

	/**
	 * The feature id for the '<em><b>APS Persistence Time</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int END_DEVICE__APS_PERSISTENCE_TIME = NODE__APS_PERSISTENCE_TIME;

	/**
	 * The feature id for the '<em><b>Num APSME Simul Commands</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int END_DEVICE__NUM_APSME_SIMUL_COMMANDS = NODE__NUM_APSME_SIMUL_COMMANDS;

	/**
	 * The feature id for the '<em><b>Stack Profile</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int END_DEVICE__STACK_PROFILE = NODE__STACK_PROFILE;

	/**
	 * The feature id for the '<em><b>Inter PAN</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int END_DEVICE__INTER_PAN = NODE__INTER_PAN;

	/**
	 * The feature id for the '<em><b>Green Power Support</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int END_DEVICE__GREEN_POWER_SUPPORT = NODE__GREEN_POWER_SUPPORT;

	/**
	 * The feature id for the '<em><b>Nwk Fc Save Count Bit Shift</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int END_DEVICE__NWK_FC_SAVE_COUNT_BIT_SHIFT = NODE__NWK_FC_SAVE_COUNT_BIT_SHIFT;

	/**
	 * The feature id for the '<em><b>Aps Fc Save Count Bit Shift</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int END_DEVICE__APS_FC_SAVE_COUNT_BIT_SHIFT = NODE__APS_FC_SAVE_COUNT_BIT_SHIFT;

	/**
	 * The feature id for the '<em><b>Mac Table Size</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int END_DEVICE__MAC_TABLE_SIZE = NODE__MAC_TABLE_SIZE;

	/**
	 * The feature id for the '<em><b>Default Callback Name</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int END_DEVICE__DEFAULT_CALLBACK_NAME = NODE__DEFAULT_CALLBACK_NAME;

	/**
	 * The feature id for the '<em><b>Mac Interface List</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int END_DEVICE__MAC_INTERFACE_LIST = NODE__MAC_INTERFACE_LIST;

	/**
	 * The feature id for the '<em><b>Scan Duration</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int END_DEVICE__SCAN_DURATION = NODE_FEATURE_COUNT + 0;

	/**
	 * The feature id for the '<em><b>Network Selection</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int END_DEVICE__NETWORK_SELECTION = NODE_FEATURE_COUNT + 1;

	/**
	 * The feature id for the '<em><b>ZDO Servers</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int END_DEVICE__ZDO_SERVERS = NODE_FEATURE_COUNT + 2;

	/**
	 * The feature id for the '<em><b>Num Poll Failures Before Rejoin</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int END_DEVICE__NUM_POLL_FAILURES_BEFORE_REJOIN = NODE_FEATURE_COUNT + 3;

	/**
	 * The feature id for the '<em><b>Sleeping</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int END_DEVICE__SLEEPING = NODE_FEATURE_COUNT + 4;

	/**
	 * The feature id for the '<em><b>Fragmented Tx Poll Period</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int END_DEVICE__FRAGMENTED_TX_POLL_PERIOD = NODE_FEATURE_COUNT + 5;

	/**
	 * The feature id for the '<em><b>Fragmented Rx Poll Period</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int END_DEVICE__FRAGMENTED_RX_POLL_PERIOD = NODE_FEATURE_COUNT + 6;

	/**
	 * The feature id for the '<em><b>APS Poll Period</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int END_DEVICE__APS_POLL_PERIOD = NODE_FEATURE_COUNT + 7;

	/**
	 * The number of structural features of the '<em>End Device</em>' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int END_DEVICE_FEATURE_COUNT = NODE_FEATURE_COUNT + 8;

	/**
	 * The meta object id for the '{@link com.jennic.ZPSConfiguration.impl.EndPointImpl <em>End Point</em>}' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see com.jennic.ZPSConfiguration.impl.EndPointImpl
	 * @see com.jennic.ZPSConfiguration.impl.ZPSConfigurationPackageImpl#getEndPoint()
	 * @generated
	 */
	int END_POINT = 6;

	/**
	 * The feature id for the '<em><b>Input Clusters</b></em>' containment reference list.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int END_POINT__INPUT_CLUSTERS = 0;

	/**
	 * The feature id for the '<em><b>Output Clusters</b></em>' containment reference list.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int END_POINT__OUTPUT_CLUSTERS = 1;

	/**
	 * The feature id for the '<em><b>Id</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int END_POINT__ID = 2;

	/**
	 * The feature id for the '<em><b>Enabled</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int END_POINT__ENABLED = 3;

	/**
	 * The feature id for the '<em><b>Application Device Id</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int END_POINT__APPLICATION_DEVICE_ID = 4;

	/**
	 * The feature id for the '<em><b>Application Device Version</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int END_POINT__APPLICATION_DEVICE_VERSION = 5;

	/**
	 * The feature id for the '<em><b>Profile</b></em>' reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int END_POINT__PROFILE = 6;

	/**
	 * The feature id for the '<em><b>Message</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int END_POINT__MESSAGE = 7;

	/**
	 * The feature id for the '<em><b>Node</b></em>' container reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int END_POINT__NODE = 8;

	/**
	 * The feature id for the '<em><b>Name</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int END_POINT__NAME = 9;

	/**
	 * The number of structural features of the '<em>End Point</em>' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int END_POINT_FEATURE_COUNT = 10;

	/**
	 * The meta object id for the '{@link com.jennic.ZPSConfiguration.impl.DiscoveryCacheImpl <em>Discovery Cache</em>}' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see com.jennic.ZPSConfiguration.impl.DiscoveryCacheImpl
	 * @see com.jennic.ZPSConfiguration.impl.ZPSConfigurationPackageImpl#getDiscoveryCache()
	 * @generated
	 */
	int DISCOVERY_CACHE = 23;

	/**
	 * The number of structural features of the '<em>Discovery Cache</em>' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int DISCOVERY_CACHE_FEATURE_COUNT = 0;

	/**
	 * The meta object id for the '{@link com.jennic.ZPSConfiguration.impl.PrimaryDiscoveryCacheImpl <em>Primary Discovery Cache</em>}' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see com.jennic.ZPSConfiguration.impl.PrimaryDiscoveryCacheImpl
	 * @see com.jennic.ZPSConfiguration.impl.ZPSConfigurationPackageImpl#getPrimaryDiscoveryCache()
	 * @generated
	 */
	int PRIMARY_DISCOVERY_CACHE = 7;

	/**
	 * The feature id for the '<em><b>Size</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int PRIMARY_DISCOVERY_CACHE__SIZE = DISCOVERY_CACHE_FEATURE_COUNT + 0;

	/**
	 * The number of structural features of the '<em>Primary Discovery Cache</em>' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int PRIMARY_DISCOVERY_CACHE_FEATURE_COUNT = DISCOVERY_CACHE_FEATURE_COUNT + 1;

	/**
	 * The meta object id for the '{@link com.jennic.ZPSConfiguration.impl.BackupDiscoveryCacheImpl <em>Backup Discovery Cache</em>}' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see com.jennic.ZPSConfiguration.impl.BackupDiscoveryCacheImpl
	 * @see com.jennic.ZPSConfiguration.impl.ZPSConfigurationPackageImpl#getBackupDiscoveryCache()
	 * @generated
	 */
	int BACKUP_DISCOVERY_CACHE = 8;

	/**
	 * The feature id for the '<em><b>Size</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int BACKUP_DISCOVERY_CACHE__SIZE = DISCOVERY_CACHE_FEATURE_COUNT + 0;

	/**
	 * The number of structural features of the '<em>Backup Discovery Cache</em>' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int BACKUP_DISCOVERY_CACHE_FEATURE_COUNT = DISCOVERY_CACHE_FEATURE_COUNT + 1;

	/**
	 * The meta object id for the '{@link com.jennic.ZPSConfiguration.impl.DiscoveryTableImpl <em>Discovery Table</em>}' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see com.jennic.ZPSConfiguration.impl.DiscoveryTableImpl
	 * @see com.jennic.ZPSConfiguration.impl.ZPSConfigurationPackageImpl#getDiscoveryTable()
	 * @generated
	 */
	int DISCOVERY_TABLE = 9;

	/**
	 * The feature id for the '<em><b>Size</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int DISCOVERY_TABLE__SIZE = 0;

	/**
	 * The number of structural features of the '<em>Discovery Table</em>' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int DISCOVERY_TABLE_FEATURE_COUNT = 1;

	/**
	 * The meta object id for the '{@link com.jennic.ZPSConfiguration.impl.BindingTableImpl <em>Binding Table</em>}' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see com.jennic.ZPSConfiguration.impl.BindingTableImpl
	 * @see com.jennic.ZPSConfiguration.impl.ZPSConfigurationPackageImpl#getBindingTable()
	 * @generated
	 */
	int BINDING_TABLE = 10;

	/**
	 * The feature id for the '<em><b>Size</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int BINDING_TABLE__SIZE = 0;

	/**
	 * The number of structural features of the '<em>Binding Table</em>' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int BINDING_TABLE_FEATURE_COUNT = 1;

	/**
	 * The meta object id for the '{@link com.jennic.ZPSConfiguration.impl.GroupTableImpl <em>Group Table</em>}' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see com.jennic.ZPSConfiguration.impl.GroupTableImpl
	 * @see com.jennic.ZPSConfiguration.impl.ZPSConfigurationPackageImpl#getGroupTable()
	 * @generated
	 */
	int GROUP_TABLE = 11;

	/**
	 * The feature id for the '<em><b>Size</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int GROUP_TABLE__SIZE = 0;

	/**
	 * The number of structural features of the '<em>Group Table</em>' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int GROUP_TABLE_FEATURE_COUNT = 1;

	/**
	 * The meta object id for the '{@link com.jennic.ZPSConfiguration.impl.ZigbeeWirelessNetworkImpl <em>Zigbee Wireless Network</em>}' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see com.jennic.ZPSConfiguration.impl.ZigbeeWirelessNetworkImpl
	 * @see com.jennic.ZPSConfiguration.impl.ZPSConfigurationPackageImpl#getZigbeeWirelessNetwork()
	 * @generated
	 */
	int ZIGBEE_WIRELESS_NETWORK = 12;

	/**
	 * The feature id for the '<em><b>Profiles</b></em>' containment reference list.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ZIGBEE_WIRELESS_NETWORK__PROFILES = 0;

	/**
	 * The feature id for the '<em><b>Coordinator</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ZIGBEE_WIRELESS_NETWORK__COORDINATOR = 1;

	/**
	 * The feature id for the '<em><b>Child Nodes</b></em>' containment reference list.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ZIGBEE_WIRELESS_NETWORK__CHILD_NODES = 2;

	/**
	 * The feature id for the '<em><b>Default Extended PAN Id</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ZIGBEE_WIRELESS_NETWORK__DEFAULT_EXTENDED_PAN_ID = 3;

	/**
	 * The feature id for the '<em><b>Max Number Nodes</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ZIGBEE_WIRELESS_NETWORK__MAX_NUMBER_NODES = 4;

	/**
	 * The feature id for the '<em><b>Version</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ZIGBEE_WIRELESS_NETWORK__VERSION = 5;

	/**
	 * The feature id for the '<em><b>Default Security Enabled</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ZIGBEE_WIRELESS_NETWORK__DEFAULT_SECURITY_ENABLED = 6;

	/**
	 * The number of structural features of the '<em>Zigbee Wireless Network</em>' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ZIGBEE_WIRELESS_NETWORK_FEATURE_COUNT = 7;

	/**
	 * The meta object id for the '{@link com.jennic.ZPSConfiguration.impl.BindingCacheImpl <em>Binding Cache</em>}' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see com.jennic.ZPSConfiguration.impl.BindingCacheImpl
	 * @see com.jennic.ZPSConfiguration.impl.ZPSConfigurationPackageImpl#getBindingCache()
	 * @generated
	 */
	int BINDING_CACHE = 24;

	/**
	 * The number of structural features of the '<em>Binding Cache</em>' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int BINDING_CACHE_FEATURE_COUNT = 0;

	/**
	 * The meta object id for the '{@link com.jennic.ZPSConfiguration.impl.PrimaryBindingCacheImpl <em>Primary Binding Cache</em>}' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see com.jennic.ZPSConfiguration.impl.PrimaryBindingCacheImpl
	 * @see com.jennic.ZPSConfiguration.impl.ZPSConfigurationPackageImpl#getPrimaryBindingCache()
	 * @generated
	 */
	int PRIMARY_BINDING_CACHE = 13;

	/**
	 * The feature id for the '<em><b>Table Size</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int PRIMARY_BINDING_CACHE__TABLE_SIZE = BINDING_CACHE_FEATURE_COUNT + 0;

	/**
	 * The feature id for the '<em><b>Num Tables</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int PRIMARY_BINDING_CACHE__NUM_TABLES = BINDING_CACHE_FEATURE_COUNT + 1;

	/**
	 * The number of structural features of the '<em>Primary Binding Cache</em>' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int PRIMARY_BINDING_CACHE_FEATURE_COUNT = BINDING_CACHE_FEATURE_COUNT + 2;

	/**
	 * The meta object id for the '{@link com.jennic.ZPSConfiguration.impl.BackupBindingCacheImpl <em>Backup Binding Cache</em>}' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see com.jennic.ZPSConfiguration.impl.BackupBindingCacheImpl
	 * @see com.jennic.ZPSConfiguration.impl.ZPSConfigurationPackageImpl#getBackupBindingCache()
	 * @generated
	 */
	int BACKUP_BINDING_CACHE = 14;

	/**
	 * The feature id for the '<em><b>Table Size</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int BACKUP_BINDING_CACHE__TABLE_SIZE = BINDING_CACHE_FEATURE_COUNT + 0;

	/**
	 * The feature id for the '<em><b>Num Tables</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int BACKUP_BINDING_CACHE__NUM_TABLES = BINDING_CACHE_FEATURE_COUNT + 1;

	/**
	 * The number of structural features of the '<em>Backup Binding Cache</em>' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int BACKUP_BINDING_CACHE_FEATURE_COUNT = BINDING_CACHE_FEATURE_COUNT + 2;

	/**
	 * The meta object id for the '{@link com.jennic.ZPSConfiguration.impl.PrimaryGroupCacheImpl <em>Primary Group Cache</em>}' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see com.jennic.ZPSConfiguration.impl.PrimaryGroupCacheImpl
	 * @see com.jennic.ZPSConfiguration.impl.ZPSConfigurationPackageImpl#getPrimaryGroupCache()
	 * @generated
	 */
	int PRIMARY_GROUP_CACHE = 15;

	/**
	 * The feature id for the '<em><b>Size</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int PRIMARY_GROUP_CACHE__SIZE = 0;

	/**
	 * The number of structural features of the '<em>Primary Group Cache</em>' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int PRIMARY_GROUP_CACHE_FEATURE_COUNT = 1;

	/**
	 * The meta object id for the '{@link com.jennic.ZPSConfiguration.impl.BackupGroupCacheImpl <em>Backup Group Cache</em>}' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see com.jennic.ZPSConfiguration.impl.BackupGroupCacheImpl
	 * @see com.jennic.ZPSConfiguration.impl.ZPSConfigurationPackageImpl#getBackupGroupCache()
	 * @generated
	 */
	int BACKUP_GROUP_CACHE = 16;

	/**
	 * The feature id for the '<em><b>Size</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int BACKUP_GROUP_CACHE__SIZE = 0;

	/**
	 * The number of structural features of the '<em>Backup Group Cache</em>' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int BACKUP_GROUP_CACHE_FEATURE_COUNT = 1;

	/**
	 * The meta object id for the '{@link com.jennic.ZPSConfiguration.impl.InputClusterImpl <em>Input Cluster</em>}' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see com.jennic.ZPSConfiguration.impl.InputClusterImpl
	 * @see com.jennic.ZPSConfiguration.impl.ZPSConfigurationPackageImpl#getInputCluster()
	 * @generated
	 */
	int INPUT_CLUSTER = 17;

	/**
	 * The feature id for the '<em><b>Cluster</b></em>' reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int INPUT_CLUSTER__CLUSTER = 0;

	/**
	 * The feature id for the '<em><b>Rx APDU</b></em>' reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int INPUT_CLUSTER__RX_APDU = 1;

	/**
	 * The feature id for the '<em><b>End Point</b></em>' container reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int INPUT_CLUSTER__END_POINT = 2;

	/**
	 * The feature id for the '<em><b>Discoverable</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int INPUT_CLUSTER__DISCOVERABLE = 3;

	/**
	 * The number of structural features of the '<em>Input Cluster</em>' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int INPUT_CLUSTER_FEATURE_COUNT = 4;

	/**
	 * The meta object id for the '{@link com.jennic.ZPSConfiguration.impl.OutputClusterImpl <em>Output Cluster</em>}' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see com.jennic.ZPSConfiguration.impl.OutputClusterImpl
	 * @see com.jennic.ZPSConfiguration.impl.ZPSConfigurationPackageImpl#getOutputCluster()
	 * @generated
	 */
	int OUTPUT_CLUSTER = 18;

	/**
	 * The feature id for the '<em><b>Cluster</b></em>' reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int OUTPUT_CLUSTER__CLUSTER = 0;

	/**
	 * The feature id for the '<em><b>End Point</b></em>' container reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int OUTPUT_CLUSTER__END_POINT = 1;

	/**
	 * The feature id for the '<em><b>Tx APD Us</b></em>' reference list.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int OUTPUT_CLUSTER__TX_APD_US = 2;

	/**
	 * The feature id for the '<em><b>Discoverable</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int OUTPUT_CLUSTER__DISCOVERABLE = 3;

	/**
	 * The number of structural features of the '<em>Output Cluster</em>' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int OUTPUT_CLUSTER_FEATURE_COUNT = 4;

	/**
	 * The meta object id for the '{@link com.jennic.ZPSConfiguration.impl.ComplexDescriptorImpl <em>Complex Descriptor</em>}' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see com.jennic.ZPSConfiguration.impl.ComplexDescriptorImpl
	 * @see com.jennic.ZPSConfiguration.impl.ZPSConfigurationPackageImpl#getComplexDescriptor()
	 * @generated
	 */
	int COMPLEX_DESCRIPTOR = 20;

	/**
	 * The number of structural features of the '<em>Complex Descriptor</em>' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int COMPLEX_DESCRIPTOR_FEATURE_COUNT = 0;

	/**
	 * The meta object id for the '{@link com.jennic.ZPSConfiguration.impl.UserDescriptorImpl <em>User Descriptor</em>}' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see com.jennic.ZPSConfiguration.impl.UserDescriptorImpl
	 * @see com.jennic.ZPSConfiguration.impl.ZPSConfigurationPackageImpl#getUserDescriptor()
	 * @generated
	 */
	int USER_DESCRIPTOR = 21;

	/**
	 * The feature id for the '<em><b>User Description</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int USER_DESCRIPTOR__USER_DESCRIPTION = 0;

	/**
	 * The number of structural features of the '<em>User Descriptor</em>' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int USER_DESCRIPTOR_FEATURE_COUNT = 1;

	/**
	 * The meta object id for the '{@link com.jennic.ZPSConfiguration.impl.TrustCenterImpl <em>Trust Center</em>}' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see com.jennic.ZPSConfiguration.impl.TrustCenterImpl
	 * @see com.jennic.ZPSConfiguration.impl.ZPSConfigurationPackageImpl#getTrustCenter()
	 * @generated
	 */
	int TRUST_CENTER = 22;

	/**
	 * The feature id for the '<em><b>Device Table Size</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int TRUST_CENTER__DEVICE_TABLE_SIZE = 0;

	/**
	 * The feature id for the '<em><b>Keys</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int TRUST_CENTER__KEYS = 1;

	/**
	 * The number of structural features of the '<em>Trust Center</em>' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int TRUST_CENTER_FEATURE_COUNT = 2;

	/**
	 * The meta object id for the '{@link com.jennic.ZPSConfiguration.impl.ChildNodesImpl <em>Child Nodes</em>}' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see com.jennic.ZPSConfiguration.impl.ChildNodesImpl
	 * @see com.jennic.ZPSConfiguration.impl.ZPSConfigurationPackageImpl#getChildNodes()
	 * @generated
	 */
	int CHILD_NODES = 26;

	/**
	 * The feature id for the '<em><b>Scan Duration</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int CHILD_NODES__SCAN_DURATION = 0;

	/**
	 * The feature id for the '<em><b>Network Selection</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int CHILD_NODES__NETWORK_SELECTION = 1;

	/**
	 * The number of structural features of the '<em>Child Nodes</em>' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int CHILD_NODES_FEATURE_COUNT = 2;

	/**
	 * The meta object id for the '{@link com.jennic.ZPSConfiguration.impl.APDUImpl <em>APDU</em>}' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see com.jennic.ZPSConfiguration.impl.APDUImpl
	 * @see com.jennic.ZPSConfiguration.impl.ZPSConfigurationPackageImpl#getAPDU()
	 * @generated
	 */
	int APDU = 27;

	/**
	 * The feature id for the '<em><b>Id</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int APDU__ID = 0;

	/**
	 * The feature id for the '<em><b>Name</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int APDU__NAME = 1;

	/**
	 * The feature id for the '<em><b>Size</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int APDU__SIZE = 2;

	/**
	 * The feature id for the '<em><b>Instances</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int APDU__INSTANCES = 3;

	/**
	 * The feature id for the '<em><b>PDU Config</b></em>' container reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int APDU__PDU_CONFIG = 4;

	/**
	 * The number of structural features of the '<em>APDU</em>' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int APDU_FEATURE_COUNT = 5;

	/**
	 * The meta object id for the '{@link com.jennic.ZPSConfiguration.impl.PDUManagerImpl <em>PDU Manager</em>}' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see com.jennic.ZPSConfiguration.impl.PDUManagerImpl
	 * @see com.jennic.ZPSConfiguration.impl.ZPSConfigurationPackageImpl#getPDUManager()
	 * @generated
	 */
	int PDU_MANAGER = 28;

	/**
	 * The feature id for the '<em><b>APD Us</b></em>' containment reference list.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int PDU_MANAGER__APD_US = 0;

	/**
	 * The feature id for the '<em><b>Container Node</b></em>' container reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int PDU_MANAGER__CONTAINER_NODE = 1;

	/**
	 * The feature id for the '<em><b>Num NPD Us</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int PDU_MANAGER__NUM_NPD_US = 2;

	/**
	 * The feature id for the '<em><b>PDUM Mutex Name</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int PDU_MANAGER__PDUM_MUTEX_NAME = 3;

	/**
	 * The number of structural features of the '<em>PDU Manager</em>' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int PDU_MANAGER_FEATURE_COUNT = 4;

	/**
	 * The meta object id for the '{@link com.jennic.ZPSConfiguration.impl.ChannelMaskImpl <em>Channel Mask</em>}' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see com.jennic.ZPSConfiguration.impl.ChannelMaskImpl
	 * @see com.jennic.ZPSConfiguration.impl.ZPSConfigurationPackageImpl#getChannelMask()
	 * @generated
	 */
	int CHANNEL_MASK = 29;

	/**
	 * The feature id for the '<em><b>Channel11</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int CHANNEL_MASK__CHANNEL11 = 0;

	/**
	 * The feature id for the '<em><b>Channel12</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int CHANNEL_MASK__CHANNEL12 = 1;

	/**
	 * The feature id for the '<em><b>Channel13</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int CHANNEL_MASK__CHANNEL13 = 2;

	/**
	 * The feature id for the '<em><b>Channel14</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int CHANNEL_MASK__CHANNEL14 = 3;

	/**
	 * The feature id for the '<em><b>Channel15</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int CHANNEL_MASK__CHANNEL15 = 4;

	/**
	 * The feature id for the '<em><b>Channel16</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int CHANNEL_MASK__CHANNEL16 = 5;

	/**
	 * The feature id for the '<em><b>Channel17</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int CHANNEL_MASK__CHANNEL17 = 6;

	/**
	 * The feature id for the '<em><b>Channel18</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int CHANNEL_MASK__CHANNEL18 = 7;

	/**
	 * The feature id for the '<em><b>Channel19</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int CHANNEL_MASK__CHANNEL19 = 8;

	/**
	 * The feature id for the '<em><b>Channel20</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int CHANNEL_MASK__CHANNEL20 = 9;

	/**
	 * The feature id for the '<em><b>Channel21</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int CHANNEL_MASK__CHANNEL21 = 10;

	/**
	 * The feature id for the '<em><b>Channel22</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int CHANNEL_MASK__CHANNEL22 = 11;

	/**
	 * The feature id for the '<em><b>Channel23</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int CHANNEL_MASK__CHANNEL23 = 12;

	/**
	 * The feature id for the '<em><b>Channel24</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int CHANNEL_MASK__CHANNEL24 = 13;

	/**
	 * The feature id for the '<em><b>Channel25</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int CHANNEL_MASK__CHANNEL25 = 14;

	/**
	 * The feature id for the '<em><b>Channel26</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int CHANNEL_MASK__CHANNEL26 = 15;

	/**
	 * The number of structural features of the '<em>Channel Mask</em>' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int CHANNEL_MASK_FEATURE_COUNT = 16;

	/**
	 * The meta object id for the '{@link com.jennic.ZPSConfiguration.impl.ZDOClientServerImpl <em>ZDO Client Server</em>}' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see com.jennic.ZPSConfiguration.impl.ZDOClientServerImpl
	 * @see com.jennic.ZPSConfiguration.impl.ZPSConfigurationPackageImpl#getZDOClientServer()
	 * @generated
	 */
	int ZDO_CLIENT_SERVER = 30;

	/**
	 * The feature id for the '<em><b>Output APdu</b></em>' reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ZDO_CLIENT_SERVER__OUTPUT_APDU = 0;

	/**
	 * The number of structural features of the '<em>ZDO Client Server</em>' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ZDO_CLIENT_SERVER_FEATURE_COUNT = 1;

	/**
	 * The meta object id for the '{@link com.jennic.ZPSConfiguration.impl.ZDOCommonServersImpl <em>ZDO Common Servers</em>}' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see com.jennic.ZPSConfiguration.impl.ZDOCommonServersImpl
	 * @see com.jennic.ZPSConfiguration.impl.ZPSConfigurationPackageImpl#getZDOCommonServers()
	 * @generated
	 */
	int ZDO_COMMON_SERVERS = 57;

	/**
	 * The feature id for the '<em><b>Default Server</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ZDO_COMMON_SERVERS__DEFAULT_SERVER = 0;

	/**
	 * The feature id for the '<em><b>Zdo Client</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ZDO_COMMON_SERVERS__ZDO_CLIENT = 1;

	/**
	 * The feature id for the '<em><b>Device Annce Server</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ZDO_COMMON_SERVERS__DEVICE_ANNCE_SERVER = 2;

	/**
	 * The feature id for the '<em><b>Active Ep Server</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ZDO_COMMON_SERVERS__ACTIVE_EP_SERVER = 3;

	/**
	 * The feature id for the '<em><b>Nwk Addr Server</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ZDO_COMMON_SERVERS__NWK_ADDR_SERVER = 4;

	/**
	 * The feature id for the '<em><b>Ieee Addr Server</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ZDO_COMMON_SERVERS__IEEE_ADDR_SERVER = 5;

	/**
	 * The feature id for the '<em><b>System Server Discovery Server</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ZDO_COMMON_SERVERS__SYSTEM_SERVER_DISCOVERY_SERVER = 6;

	/**
	 * The feature id for the '<em><b>Node Desc Server</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ZDO_COMMON_SERVERS__NODE_DESC_SERVER = 7;

	/**
	 * The feature id for the '<em><b>Power Desc Server</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ZDO_COMMON_SERVERS__POWER_DESC_SERVER = 8;

	/**
	 * The feature id for the '<em><b>Match Desc Server</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ZDO_COMMON_SERVERS__MATCH_DESC_SERVER = 9;

	/**
	 * The feature id for the '<em><b>Simple Desc Server</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ZDO_COMMON_SERVERS__SIMPLE_DESC_SERVER = 10;

	/**
	 * The feature id for the '<em><b>Mgmt Lqi Server</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ZDO_COMMON_SERVERS__MGMT_LQI_SERVER = 11;

	/**
	 * The feature id for the '<em><b>Mgmt Leave Server</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ZDO_COMMON_SERVERS__MGMT_LEAVE_SERVER = 12;

	/**
	 * The feature id for the '<em><b>Mgmt NWK Update Server</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ZDO_COMMON_SERVERS__MGMT_NWK_UPDATE_SERVER = 13;

	/**
	 * The feature id for the '<em><b>Bind Unbind Server</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ZDO_COMMON_SERVERS__BIND_UNBIND_SERVER = 14;

	/**
	 * The feature id for the '<em><b>Extended Active Ep Server</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ZDO_COMMON_SERVERS__EXTENDED_ACTIVE_EP_SERVER = 15;

	/**
	 * The feature id for the '<em><b>Extended Simple Desc Server</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ZDO_COMMON_SERVERS__EXTENDED_SIMPLE_DESC_SERVER = 16;

	/**
	 * The feature id for the '<em><b>Bind Request Server</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ZDO_COMMON_SERVERS__BIND_REQUEST_SERVER = 17;

	/**
	 * The feature id for the '<em><b>Mgmt Bind Server</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ZDO_COMMON_SERVERS__MGMT_BIND_SERVER = 18;

	/**
	 * The feature id for the '<em><b>Mgmt NWK Enhance Update Server</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ZDO_COMMON_SERVERS__MGMT_NWK_ENHANCE_UPDATE_SERVER = 19;

	/**
	 * The number of structural features of the '<em>ZDO Common Servers</em>' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ZDO_COMMON_SERVERS_FEATURE_COUNT = 20;

	/**
	 * The meta object id for the '{@link com.jennic.ZPSConfiguration.impl.ZDOServersCoordinatorImpl <em>ZDO Servers Coordinator</em>}' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see com.jennic.ZPSConfiguration.impl.ZDOServersCoordinatorImpl
	 * @see com.jennic.ZPSConfiguration.impl.ZPSConfigurationPackageImpl#getZDOServersCoordinator()
	 * @generated
	 */
	int ZDO_SERVERS_COORDINATOR = 31;

	/**
	 * The feature id for the '<em><b>Default Server</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ZDO_SERVERS_COORDINATOR__DEFAULT_SERVER = ZDO_COMMON_SERVERS__DEFAULT_SERVER;

	/**
	 * The feature id for the '<em><b>Zdo Client</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ZDO_SERVERS_COORDINATOR__ZDO_CLIENT = ZDO_COMMON_SERVERS__ZDO_CLIENT;

	/**
	 * The feature id for the '<em><b>Device Annce Server</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ZDO_SERVERS_COORDINATOR__DEVICE_ANNCE_SERVER = ZDO_COMMON_SERVERS__DEVICE_ANNCE_SERVER;

	/**
	 * The feature id for the '<em><b>Active Ep Server</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ZDO_SERVERS_COORDINATOR__ACTIVE_EP_SERVER = ZDO_COMMON_SERVERS__ACTIVE_EP_SERVER;

	/**
	 * The feature id for the '<em><b>Nwk Addr Server</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ZDO_SERVERS_COORDINATOR__NWK_ADDR_SERVER = ZDO_COMMON_SERVERS__NWK_ADDR_SERVER;

	/**
	 * The feature id for the '<em><b>Ieee Addr Server</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ZDO_SERVERS_COORDINATOR__IEEE_ADDR_SERVER = ZDO_COMMON_SERVERS__IEEE_ADDR_SERVER;

	/**
	 * The feature id for the '<em><b>System Server Discovery Server</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ZDO_SERVERS_COORDINATOR__SYSTEM_SERVER_DISCOVERY_SERVER = ZDO_COMMON_SERVERS__SYSTEM_SERVER_DISCOVERY_SERVER;

	/**
	 * The feature id for the '<em><b>Node Desc Server</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ZDO_SERVERS_COORDINATOR__NODE_DESC_SERVER = ZDO_COMMON_SERVERS__NODE_DESC_SERVER;

	/**
	 * The feature id for the '<em><b>Power Desc Server</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ZDO_SERVERS_COORDINATOR__POWER_DESC_SERVER = ZDO_COMMON_SERVERS__POWER_DESC_SERVER;

	/**
	 * The feature id for the '<em><b>Match Desc Server</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ZDO_SERVERS_COORDINATOR__MATCH_DESC_SERVER = ZDO_COMMON_SERVERS__MATCH_DESC_SERVER;

	/**
	 * The feature id for the '<em><b>Simple Desc Server</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ZDO_SERVERS_COORDINATOR__SIMPLE_DESC_SERVER = ZDO_COMMON_SERVERS__SIMPLE_DESC_SERVER;

	/**
	 * The feature id for the '<em><b>Mgmt Lqi Server</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ZDO_SERVERS_COORDINATOR__MGMT_LQI_SERVER = ZDO_COMMON_SERVERS__MGMT_LQI_SERVER;

	/**
	 * The feature id for the '<em><b>Mgmt Leave Server</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ZDO_SERVERS_COORDINATOR__MGMT_LEAVE_SERVER = ZDO_COMMON_SERVERS__MGMT_LEAVE_SERVER;

	/**
	 * The feature id for the '<em><b>Mgmt NWK Update Server</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ZDO_SERVERS_COORDINATOR__MGMT_NWK_UPDATE_SERVER = ZDO_COMMON_SERVERS__MGMT_NWK_UPDATE_SERVER;

	/**
	 * The feature id for the '<em><b>Bind Unbind Server</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ZDO_SERVERS_COORDINATOR__BIND_UNBIND_SERVER = ZDO_COMMON_SERVERS__BIND_UNBIND_SERVER;

	/**
	 * The feature id for the '<em><b>Extended Active Ep Server</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ZDO_SERVERS_COORDINATOR__EXTENDED_ACTIVE_EP_SERVER = ZDO_COMMON_SERVERS__EXTENDED_ACTIVE_EP_SERVER;

	/**
	 * The feature id for the '<em><b>Extended Simple Desc Server</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ZDO_SERVERS_COORDINATOR__EXTENDED_SIMPLE_DESC_SERVER = ZDO_COMMON_SERVERS__EXTENDED_SIMPLE_DESC_SERVER;

	/**
	 * The feature id for the '<em><b>Bind Request Server</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ZDO_SERVERS_COORDINATOR__BIND_REQUEST_SERVER = ZDO_COMMON_SERVERS__BIND_REQUEST_SERVER;

	/**
	 * The feature id for the '<em><b>Mgmt Bind Server</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ZDO_SERVERS_COORDINATOR__MGMT_BIND_SERVER = ZDO_COMMON_SERVERS__MGMT_BIND_SERVER;

	/**
	 * The feature id for the '<em><b>Mgmt NWK Enhance Update Server</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ZDO_SERVERS_COORDINATOR__MGMT_NWK_ENHANCE_UPDATE_SERVER = ZDO_COMMON_SERVERS__MGMT_NWK_ENHANCE_UPDATE_SERVER;

	/**
	 * The feature id for the '<em><b>Permit Joining Server</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ZDO_SERVERS_COORDINATOR__PERMIT_JOINING_SERVER = ZDO_COMMON_SERVERS_FEATURE_COUNT + 0;

	/**
	 * The feature id for the '<em><b>Mgmt Rtg Server</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ZDO_SERVERS_COORDINATOR__MGMT_RTG_SERVER = ZDO_COMMON_SERVERS_FEATURE_COUNT + 1;

	/**
	 * The feature id for the '<em><b>Mgmt Mib Ieee Server</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ZDO_SERVERS_COORDINATOR__MGMT_MIB_IEEE_SERVER = ZDO_COMMON_SERVERS_FEATURE_COUNT + 2;

	/**
	 * The feature id for the '<em><b>Parent Annce Server</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ZDO_SERVERS_COORDINATOR__PARENT_ANNCE_SERVER = ZDO_COMMON_SERVERS_FEATURE_COUNT + 3;

	/**
	 * The feature id for the '<em><b>End Device Bind Server</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ZDO_SERVERS_COORDINATOR__END_DEVICE_BIND_SERVER = ZDO_COMMON_SERVERS_FEATURE_COUNT + 4;

	/**
	 * The number of structural features of the '<em>ZDO Servers Coordinator</em>' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ZDO_SERVERS_COORDINATOR_FEATURE_COUNT = ZDO_COMMON_SERVERS_FEATURE_COUNT + 5;

	/**
	 * The meta object id for the '{@link com.jennic.ZPSConfiguration.impl.EndDeviceBindServerImpl <em>End Device Bind Server</em>}' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see com.jennic.ZPSConfiguration.impl.EndDeviceBindServerImpl
	 * @see com.jennic.ZPSConfiguration.impl.ZPSConfigurationPackageImpl#getEndDeviceBindServer()
	 * @generated
	 */
	int END_DEVICE_BIND_SERVER = 35;

	/**
	 * The meta object id for the '{@link com.jennic.ZPSConfiguration.impl.ZDOServersRouterImpl <em>ZDO Servers Router</em>}' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see com.jennic.ZPSConfiguration.impl.ZDOServersRouterImpl
	 * @see com.jennic.ZPSConfiguration.impl.ZPSConfigurationPackageImpl#getZDOServersRouter()
	 * @generated
	 */
	int ZDO_SERVERS_ROUTER = 32;

	/**
	 * The feature id for the '<em><b>Default Server</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ZDO_SERVERS_ROUTER__DEFAULT_SERVER = ZDO_COMMON_SERVERS__DEFAULT_SERVER;

	/**
	 * The feature id for the '<em><b>Zdo Client</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ZDO_SERVERS_ROUTER__ZDO_CLIENT = ZDO_COMMON_SERVERS__ZDO_CLIENT;

	/**
	 * The feature id for the '<em><b>Device Annce Server</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ZDO_SERVERS_ROUTER__DEVICE_ANNCE_SERVER = ZDO_COMMON_SERVERS__DEVICE_ANNCE_SERVER;

	/**
	 * The feature id for the '<em><b>Active Ep Server</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ZDO_SERVERS_ROUTER__ACTIVE_EP_SERVER = ZDO_COMMON_SERVERS__ACTIVE_EP_SERVER;

	/**
	 * The feature id for the '<em><b>Nwk Addr Server</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ZDO_SERVERS_ROUTER__NWK_ADDR_SERVER = ZDO_COMMON_SERVERS__NWK_ADDR_SERVER;

	/**
	 * The feature id for the '<em><b>Ieee Addr Server</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ZDO_SERVERS_ROUTER__IEEE_ADDR_SERVER = ZDO_COMMON_SERVERS__IEEE_ADDR_SERVER;

	/**
	 * The feature id for the '<em><b>System Server Discovery Server</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ZDO_SERVERS_ROUTER__SYSTEM_SERVER_DISCOVERY_SERVER = ZDO_COMMON_SERVERS__SYSTEM_SERVER_DISCOVERY_SERVER;

	/**
	 * The feature id for the '<em><b>Node Desc Server</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ZDO_SERVERS_ROUTER__NODE_DESC_SERVER = ZDO_COMMON_SERVERS__NODE_DESC_SERVER;

	/**
	 * The feature id for the '<em><b>Power Desc Server</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ZDO_SERVERS_ROUTER__POWER_DESC_SERVER = ZDO_COMMON_SERVERS__POWER_DESC_SERVER;

	/**
	 * The feature id for the '<em><b>Match Desc Server</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ZDO_SERVERS_ROUTER__MATCH_DESC_SERVER = ZDO_COMMON_SERVERS__MATCH_DESC_SERVER;

	/**
	 * The feature id for the '<em><b>Simple Desc Server</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ZDO_SERVERS_ROUTER__SIMPLE_DESC_SERVER = ZDO_COMMON_SERVERS__SIMPLE_DESC_SERVER;

	/**
	 * The feature id for the '<em><b>Mgmt Lqi Server</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ZDO_SERVERS_ROUTER__MGMT_LQI_SERVER = ZDO_COMMON_SERVERS__MGMT_LQI_SERVER;

	/**
	 * The feature id for the '<em><b>Mgmt Leave Server</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ZDO_SERVERS_ROUTER__MGMT_LEAVE_SERVER = ZDO_COMMON_SERVERS__MGMT_LEAVE_SERVER;

	/**
	 * The feature id for the '<em><b>Mgmt NWK Update Server</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ZDO_SERVERS_ROUTER__MGMT_NWK_UPDATE_SERVER = ZDO_COMMON_SERVERS__MGMT_NWK_UPDATE_SERVER;

	/**
	 * The feature id for the '<em><b>Bind Unbind Server</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ZDO_SERVERS_ROUTER__BIND_UNBIND_SERVER = ZDO_COMMON_SERVERS__BIND_UNBIND_SERVER;

	/**
	 * The feature id for the '<em><b>Extended Active Ep Server</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ZDO_SERVERS_ROUTER__EXTENDED_ACTIVE_EP_SERVER = ZDO_COMMON_SERVERS__EXTENDED_ACTIVE_EP_SERVER;

	/**
	 * The feature id for the '<em><b>Extended Simple Desc Server</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ZDO_SERVERS_ROUTER__EXTENDED_SIMPLE_DESC_SERVER = ZDO_COMMON_SERVERS__EXTENDED_SIMPLE_DESC_SERVER;

	/**
	 * The feature id for the '<em><b>Bind Request Server</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ZDO_SERVERS_ROUTER__BIND_REQUEST_SERVER = ZDO_COMMON_SERVERS__BIND_REQUEST_SERVER;

	/**
	 * The feature id for the '<em><b>Mgmt Bind Server</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ZDO_SERVERS_ROUTER__MGMT_BIND_SERVER = ZDO_COMMON_SERVERS__MGMT_BIND_SERVER;

	/**
	 * The feature id for the '<em><b>Mgmt NWK Enhance Update Server</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ZDO_SERVERS_ROUTER__MGMT_NWK_ENHANCE_UPDATE_SERVER = ZDO_COMMON_SERVERS__MGMT_NWK_ENHANCE_UPDATE_SERVER;

	/**
	 * The feature id for the '<em><b>Permit Joining Server</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ZDO_SERVERS_ROUTER__PERMIT_JOINING_SERVER = ZDO_COMMON_SERVERS_FEATURE_COUNT + 0;

	/**
	 * The feature id for the '<em><b>Mgmt Rtg Server</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ZDO_SERVERS_ROUTER__MGMT_RTG_SERVER = ZDO_COMMON_SERVERS_FEATURE_COUNT + 1;

	/**
	 * The feature id for the '<em><b>Mgmt Mib Ieee Server</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ZDO_SERVERS_ROUTER__MGMT_MIB_IEEE_SERVER = ZDO_COMMON_SERVERS_FEATURE_COUNT + 2;

	/**
	 * The feature id for the '<em><b>Parent Annce Server</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ZDO_SERVERS_ROUTER__PARENT_ANNCE_SERVER = ZDO_COMMON_SERVERS_FEATURE_COUNT + 3;

	/**
	 * The number of structural features of the '<em>ZDO Servers Router</em>' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ZDO_SERVERS_ROUTER_FEATURE_COUNT = ZDO_COMMON_SERVERS_FEATURE_COUNT + 4;

	/**
	 * The meta object id for the '{@link com.jennic.ZPSConfiguration.impl.ZDOServersEndDeviceImpl <em>ZDO Servers End Device</em>}' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see com.jennic.ZPSConfiguration.impl.ZDOServersEndDeviceImpl
	 * @see com.jennic.ZPSConfiguration.impl.ZPSConfigurationPackageImpl#getZDOServersEndDevice()
	 * @generated
	 */
	int ZDO_SERVERS_END_DEVICE = 33;

	/**
	 * The feature id for the '<em><b>Default Server</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ZDO_SERVERS_END_DEVICE__DEFAULT_SERVER = ZDO_COMMON_SERVERS__DEFAULT_SERVER;

	/**
	 * The feature id for the '<em><b>Zdo Client</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ZDO_SERVERS_END_DEVICE__ZDO_CLIENT = ZDO_COMMON_SERVERS__ZDO_CLIENT;

	/**
	 * The feature id for the '<em><b>Device Annce Server</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ZDO_SERVERS_END_DEVICE__DEVICE_ANNCE_SERVER = ZDO_COMMON_SERVERS__DEVICE_ANNCE_SERVER;

	/**
	 * The feature id for the '<em><b>Active Ep Server</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ZDO_SERVERS_END_DEVICE__ACTIVE_EP_SERVER = ZDO_COMMON_SERVERS__ACTIVE_EP_SERVER;

	/**
	 * The feature id for the '<em><b>Nwk Addr Server</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ZDO_SERVERS_END_DEVICE__NWK_ADDR_SERVER = ZDO_COMMON_SERVERS__NWK_ADDR_SERVER;

	/**
	 * The feature id for the '<em><b>Ieee Addr Server</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ZDO_SERVERS_END_DEVICE__IEEE_ADDR_SERVER = ZDO_COMMON_SERVERS__IEEE_ADDR_SERVER;

	/**
	 * The feature id for the '<em><b>System Server Discovery Server</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ZDO_SERVERS_END_DEVICE__SYSTEM_SERVER_DISCOVERY_SERVER = ZDO_COMMON_SERVERS__SYSTEM_SERVER_DISCOVERY_SERVER;

	/**
	 * The feature id for the '<em><b>Node Desc Server</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ZDO_SERVERS_END_DEVICE__NODE_DESC_SERVER = ZDO_COMMON_SERVERS__NODE_DESC_SERVER;

	/**
	 * The feature id for the '<em><b>Power Desc Server</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ZDO_SERVERS_END_DEVICE__POWER_DESC_SERVER = ZDO_COMMON_SERVERS__POWER_DESC_SERVER;

	/**
	 * The feature id for the '<em><b>Match Desc Server</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ZDO_SERVERS_END_DEVICE__MATCH_DESC_SERVER = ZDO_COMMON_SERVERS__MATCH_DESC_SERVER;

	/**
	 * The feature id for the '<em><b>Simple Desc Server</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ZDO_SERVERS_END_DEVICE__SIMPLE_DESC_SERVER = ZDO_COMMON_SERVERS__SIMPLE_DESC_SERVER;

	/**
	 * The feature id for the '<em><b>Mgmt Lqi Server</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ZDO_SERVERS_END_DEVICE__MGMT_LQI_SERVER = ZDO_COMMON_SERVERS__MGMT_LQI_SERVER;

	/**
	 * The feature id for the '<em><b>Mgmt Leave Server</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ZDO_SERVERS_END_DEVICE__MGMT_LEAVE_SERVER = ZDO_COMMON_SERVERS__MGMT_LEAVE_SERVER;

	/**
	 * The feature id for the '<em><b>Mgmt NWK Update Server</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ZDO_SERVERS_END_DEVICE__MGMT_NWK_UPDATE_SERVER = ZDO_COMMON_SERVERS__MGMT_NWK_UPDATE_SERVER;

	/**
	 * The feature id for the '<em><b>Bind Unbind Server</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ZDO_SERVERS_END_DEVICE__BIND_UNBIND_SERVER = ZDO_COMMON_SERVERS__BIND_UNBIND_SERVER;

	/**
	 * The feature id for the '<em><b>Extended Active Ep Server</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ZDO_SERVERS_END_DEVICE__EXTENDED_ACTIVE_EP_SERVER = ZDO_COMMON_SERVERS__EXTENDED_ACTIVE_EP_SERVER;

	/**
	 * The feature id for the '<em><b>Extended Simple Desc Server</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ZDO_SERVERS_END_DEVICE__EXTENDED_SIMPLE_DESC_SERVER = ZDO_COMMON_SERVERS__EXTENDED_SIMPLE_DESC_SERVER;

	/**
	 * The feature id for the '<em><b>Bind Request Server</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ZDO_SERVERS_END_DEVICE__BIND_REQUEST_SERVER = ZDO_COMMON_SERVERS__BIND_REQUEST_SERVER;

	/**
	 * The feature id for the '<em><b>Mgmt Bind Server</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ZDO_SERVERS_END_DEVICE__MGMT_BIND_SERVER = ZDO_COMMON_SERVERS__MGMT_BIND_SERVER;

	/**
	 * The feature id for the '<em><b>Mgmt NWK Enhance Update Server</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ZDO_SERVERS_END_DEVICE__MGMT_NWK_ENHANCE_UPDATE_SERVER = ZDO_COMMON_SERVERS__MGMT_NWK_ENHANCE_UPDATE_SERVER;

	/**
	 * The number of structural features of the '<em>ZDO Servers End Device</em>' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ZDO_SERVERS_END_DEVICE_FEATURE_COUNT = ZDO_COMMON_SERVERS_FEATURE_COUNT + 0;

	/**
	 * The meta object id for the '{@link com.jennic.ZPSConfiguration.impl.DefaultServerImpl <em>Default Server</em>}' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see com.jennic.ZPSConfiguration.impl.DefaultServerImpl
	 * @see com.jennic.ZPSConfiguration.impl.ZPSConfigurationPackageImpl#getDefaultServer()
	 * @generated
	 */
	int DEFAULT_SERVER = 34;

	/**
	 * The feature id for the '<em><b>Output APdu</b></em>' reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int DEFAULT_SERVER__OUTPUT_APDU = ZDO_CLIENT_SERVER__OUTPUT_APDU;

	/**
	 * The number of structural features of the '<em>Default Server</em>' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int DEFAULT_SERVER_FEATURE_COUNT = ZDO_CLIENT_SERVER_FEATURE_COUNT + 0;

	/**
	 * The feature id for the '<em><b>Output APdu</b></em>' reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int END_DEVICE_BIND_SERVER__OUTPUT_APDU = ZDO_CLIENT_SERVER__OUTPUT_APDU;

	/**
	 * The feature id for the '<em><b>Timeout</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int END_DEVICE_BIND_SERVER__TIMEOUT = ZDO_CLIENT_SERVER_FEATURE_COUNT + 0;

	/**
	 * The feature id for the '<em><b>Binding Timeout</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int END_DEVICE_BIND_SERVER__BINDING_TIMEOUT = ZDO_CLIENT_SERVER_FEATURE_COUNT + 1;

	/**
	 * The feature id for the '<em><b>Bind Num Retries</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int END_DEVICE_BIND_SERVER__BIND_NUM_RETRIES = ZDO_CLIENT_SERVER_FEATURE_COUNT + 2;

	/**
	 * The number of structural features of the '<em>End Device Bind Server</em>' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int END_DEVICE_BIND_SERVER_FEATURE_COUNT = ZDO_CLIENT_SERVER_FEATURE_COUNT + 3;

	/**
	 * The meta object id for the '{@link com.jennic.ZPSConfiguration.impl.DeviceAnnceServerImpl <em>Device Annce Server</em>}' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see com.jennic.ZPSConfiguration.impl.DeviceAnnceServerImpl
	 * @see com.jennic.ZPSConfiguration.impl.ZPSConfigurationPackageImpl#getDeviceAnnceServer()
	 * @generated
	 */
	int DEVICE_ANNCE_SERVER = 36;

	/**
	 * The feature id for the '<em><b>Output APdu</b></em>' reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int DEVICE_ANNCE_SERVER__OUTPUT_APDU = ZDO_CLIENT_SERVER__OUTPUT_APDU;

	/**
	 * The number of structural features of the '<em>Device Annce Server</em>' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int DEVICE_ANNCE_SERVER_FEATURE_COUNT = ZDO_CLIENT_SERVER_FEATURE_COUNT + 0;

	/**
	 * The meta object id for the '{@link com.jennic.ZPSConfiguration.impl.ActiveEpServerImpl <em>Active Ep Server</em>}' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see com.jennic.ZPSConfiguration.impl.ActiveEpServerImpl
	 * @see com.jennic.ZPSConfiguration.impl.ZPSConfigurationPackageImpl#getActiveEpServer()
	 * @generated
	 */
	int ACTIVE_EP_SERVER = 37;

	/**
	 * The feature id for the '<em><b>Output APdu</b></em>' reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ACTIVE_EP_SERVER__OUTPUT_APDU = ZDO_CLIENT_SERVER__OUTPUT_APDU;

	/**
	 * The number of structural features of the '<em>Active Ep Server</em>' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ACTIVE_EP_SERVER_FEATURE_COUNT = ZDO_CLIENT_SERVER_FEATURE_COUNT + 0;

	/**
	 * The meta object id for the '{@link com.jennic.ZPSConfiguration.impl.NwkAddrServerImpl <em>Nwk Addr Server</em>}' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see com.jennic.ZPSConfiguration.impl.NwkAddrServerImpl
	 * @see com.jennic.ZPSConfiguration.impl.ZPSConfigurationPackageImpl#getNwkAddrServer()
	 * @generated
	 */
	int NWK_ADDR_SERVER = 38;

	/**
	 * The feature id for the '<em><b>Output APdu</b></em>' reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int NWK_ADDR_SERVER__OUTPUT_APDU = ZDO_CLIENT_SERVER__OUTPUT_APDU;

	/**
	 * The number of structural features of the '<em>Nwk Addr Server</em>' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int NWK_ADDR_SERVER_FEATURE_COUNT = ZDO_CLIENT_SERVER_FEATURE_COUNT + 0;

	/**
	 * The meta object id for the '{@link com.jennic.ZPSConfiguration.impl.IeeeAddrServerImpl <em>Ieee Addr Server</em>}' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see com.jennic.ZPSConfiguration.impl.IeeeAddrServerImpl
	 * @see com.jennic.ZPSConfiguration.impl.ZPSConfigurationPackageImpl#getIeeeAddrServer()
	 * @generated
	 */
	int IEEE_ADDR_SERVER = 39;

	/**
	 * The feature id for the '<em><b>Output APdu</b></em>' reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int IEEE_ADDR_SERVER__OUTPUT_APDU = ZDO_CLIENT_SERVER__OUTPUT_APDU;

	/**
	 * The number of structural features of the '<em>Ieee Addr Server</em>' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int IEEE_ADDR_SERVER_FEATURE_COUNT = ZDO_CLIENT_SERVER_FEATURE_COUNT + 0;

	/**
	 * The meta object id for the '{@link com.jennic.ZPSConfiguration.impl.MatchDescServerImpl <em>Match Desc Server</em>}' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see com.jennic.ZPSConfiguration.impl.MatchDescServerImpl
	 * @see com.jennic.ZPSConfiguration.impl.ZPSConfigurationPackageImpl#getMatchDescServer()
	 * @generated
	 */
	int MATCH_DESC_SERVER = 40;

	/**
	 * The feature id for the '<em><b>Output APdu</b></em>' reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int MATCH_DESC_SERVER__OUTPUT_APDU = ZDO_CLIENT_SERVER__OUTPUT_APDU;

	/**
	 * The number of structural features of the '<em>Match Desc Server</em>' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int MATCH_DESC_SERVER_FEATURE_COUNT = ZDO_CLIENT_SERVER_FEATURE_COUNT + 0;

	/**
	 * The meta object id for the '{@link com.jennic.ZPSConfiguration.impl.NodeDescServerImpl <em>Node Desc Server</em>}' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see com.jennic.ZPSConfiguration.impl.NodeDescServerImpl
	 * @see com.jennic.ZPSConfiguration.impl.ZPSConfigurationPackageImpl#getNodeDescServer()
	 * @generated
	 */
	int NODE_DESC_SERVER = 41;

	/**
	 * The feature id for the '<em><b>Output APdu</b></em>' reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int NODE_DESC_SERVER__OUTPUT_APDU = ZDO_CLIENT_SERVER__OUTPUT_APDU;

	/**
	 * The number of structural features of the '<em>Node Desc Server</em>' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int NODE_DESC_SERVER_FEATURE_COUNT = ZDO_CLIENT_SERVER_FEATURE_COUNT + 0;

	/**
	 * The meta object id for the '{@link com.jennic.ZPSConfiguration.impl.PermitJoiningServerImpl <em>Permit Joining Server</em>}' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see com.jennic.ZPSConfiguration.impl.PermitJoiningServerImpl
	 * @see com.jennic.ZPSConfiguration.impl.ZPSConfigurationPackageImpl#getPermitJoiningServer()
	 * @generated
	 */
	int PERMIT_JOINING_SERVER = 42;

	/**
	 * The feature id for the '<em><b>Output APdu</b></em>' reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int PERMIT_JOINING_SERVER__OUTPUT_APDU = ZDO_CLIENT_SERVER__OUTPUT_APDU;

	/**
	 * The number of structural features of the '<em>Permit Joining Server</em>' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int PERMIT_JOINING_SERVER_FEATURE_COUNT = ZDO_CLIENT_SERVER_FEATURE_COUNT + 0;

	/**
	 * The meta object id for the '{@link com.jennic.ZPSConfiguration.impl.PowerDescServerImpl <em>Power Desc Server</em>}' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see com.jennic.ZPSConfiguration.impl.PowerDescServerImpl
	 * @see com.jennic.ZPSConfiguration.impl.ZPSConfigurationPackageImpl#getPowerDescServer()
	 * @generated
	 */
	int POWER_DESC_SERVER = 43;

	/**
	 * The feature id for the '<em><b>Output APdu</b></em>' reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int POWER_DESC_SERVER__OUTPUT_APDU = ZDO_CLIENT_SERVER__OUTPUT_APDU;

	/**
	 * The number of structural features of the '<em>Power Desc Server</em>' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int POWER_DESC_SERVER_FEATURE_COUNT = ZDO_CLIENT_SERVER_FEATURE_COUNT + 0;

	/**
	 * The meta object id for the '{@link com.jennic.ZPSConfiguration.impl.SimpleDescServerImpl <em>Simple Desc Server</em>}' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see com.jennic.ZPSConfiguration.impl.SimpleDescServerImpl
	 * @see com.jennic.ZPSConfiguration.impl.ZPSConfigurationPackageImpl#getSimpleDescServer()
	 * @generated
	 */
	int SIMPLE_DESC_SERVER = 44;

	/**
	 * The feature id for the '<em><b>Output APdu</b></em>' reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int SIMPLE_DESC_SERVER__OUTPUT_APDU = ZDO_CLIENT_SERVER__OUTPUT_APDU;

	/**
	 * The number of structural features of the '<em>Simple Desc Server</em>' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int SIMPLE_DESC_SERVER_FEATURE_COUNT = ZDO_CLIENT_SERVER_FEATURE_COUNT + 0;

	/**
	 * The meta object id for the '{@link com.jennic.ZPSConfiguration.impl.SystemServerDiscoveryServerImpl <em>System Server Discovery Server</em>}' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see com.jennic.ZPSConfiguration.impl.SystemServerDiscoveryServerImpl
	 * @see com.jennic.ZPSConfiguration.impl.ZPSConfigurationPackageImpl#getSystemServerDiscoveryServer()
	 * @generated
	 */
	int SYSTEM_SERVER_DISCOVERY_SERVER = 45;

	/**
	 * The feature id for the '<em><b>Output APdu</b></em>' reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int SYSTEM_SERVER_DISCOVERY_SERVER__OUTPUT_APDU = ZDO_CLIENT_SERVER__OUTPUT_APDU;

	/**
	 * The number of structural features of the '<em>System Server Discovery Server</em>' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int SYSTEM_SERVER_DISCOVERY_SERVER_FEATURE_COUNT = ZDO_CLIENT_SERVER_FEATURE_COUNT + 0;

	/**
	 * The meta object id for the '{@link com.jennic.ZPSConfiguration.impl.MgmtLqiServerImpl <em>Mgmt Lqi Server</em>}' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see com.jennic.ZPSConfiguration.impl.MgmtLqiServerImpl
	 * @see com.jennic.ZPSConfiguration.impl.ZPSConfigurationPackageImpl#getMgmtLqiServer()
	 * @generated
	 */
	int MGMT_LQI_SERVER = 46;

	/**
	 * The feature id for the '<em><b>Output APdu</b></em>' reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int MGMT_LQI_SERVER__OUTPUT_APDU = ZDO_CLIENT_SERVER__OUTPUT_APDU;

	/**
	 * The number of structural features of the '<em>Mgmt Lqi Server</em>' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int MGMT_LQI_SERVER_FEATURE_COUNT = ZDO_CLIENT_SERVER_FEATURE_COUNT + 0;

	/**
	 * The meta object id for the '{@link com.jennic.ZPSConfiguration.impl.MgmtRtgServerImpl <em>Mgmt Rtg Server</em>}' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see com.jennic.ZPSConfiguration.impl.MgmtRtgServerImpl
	 * @see com.jennic.ZPSConfiguration.impl.ZPSConfigurationPackageImpl#getMgmtRtgServer()
	 * @generated
	 */
	int MGMT_RTG_SERVER = 47;

	/**
	 * The feature id for the '<em><b>Output APdu</b></em>' reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int MGMT_RTG_SERVER__OUTPUT_APDU = ZDO_CLIENT_SERVER__OUTPUT_APDU;

	/**
	 * The number of structural features of the '<em>Mgmt Rtg Server</em>' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int MGMT_RTG_SERVER_FEATURE_COUNT = ZDO_CLIENT_SERVER_FEATURE_COUNT + 0;

	/**
	 * The meta object id for the '{@link com.jennic.ZPSConfiguration.impl.MgmtLeaveServerImpl <em>Mgmt Leave Server</em>}' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see com.jennic.ZPSConfiguration.impl.MgmtLeaveServerImpl
	 * @see com.jennic.ZPSConfiguration.impl.ZPSConfigurationPackageImpl#getMgmtLeaveServer()
	 * @generated
	 */
	int MGMT_LEAVE_SERVER = 48;

	/**
	 * The feature id for the '<em><b>Output APdu</b></em>' reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int MGMT_LEAVE_SERVER__OUTPUT_APDU = ZDO_CLIENT_SERVER__OUTPUT_APDU;

	/**
	 * The number of structural features of the '<em>Mgmt Leave Server</em>' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int MGMT_LEAVE_SERVER_FEATURE_COUNT = ZDO_CLIENT_SERVER_FEATURE_COUNT + 0;

	/**
	 * The meta object id for the '{@link com.jennic.ZPSConfiguration.impl.NodeDescriptorImpl <em>Node Descriptor</em>}' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see com.jennic.ZPSConfiguration.impl.NodeDescriptorImpl
	 * @see com.jennic.ZPSConfiguration.impl.ZPSConfigurationPackageImpl#getNodeDescriptor()
	 * @generated
	 */
	int NODE_DESCRIPTOR = 49;

	/**
	 * The feature id for the '<em><b>Manufacturer Code</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int NODE_DESCRIPTOR__MANUFACTURER_CODE = 0;

	/**
	 * The feature id for the '<em><b>Logical Type</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int NODE_DESCRIPTOR__LOGICAL_TYPE = 1;

	/**
	 * The feature id for the '<em><b>Complex Descriptor Available</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int NODE_DESCRIPTOR__COMPLEX_DESCRIPTOR_AVAILABLE = 2;

	/**
	 * The feature id for the '<em><b>User Descriptor Available</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int NODE_DESCRIPTOR__USER_DESCRIPTOR_AVAILABLE = 3;

	/**
	 * The feature id for the '<em><b>APS Flags</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int NODE_DESCRIPTOR__APS_FLAGS = 4;

	/**
	 * The feature id for the '<em><b>Frequency Band</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int NODE_DESCRIPTOR__FREQUENCY_BAND = 5;

	/**
	 * The feature id for the '<em><b>Alternate PAN Coordinator</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int NODE_DESCRIPTOR__ALTERNATE_PAN_COORDINATOR = 6;

	/**
	 * The feature id for the '<em><b>Device Type</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int NODE_DESCRIPTOR__DEVICE_TYPE = 7;

	/**
	 * The feature id for the '<em><b>Power Source</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int NODE_DESCRIPTOR__POWER_SOURCE = 8;

	/**
	 * The feature id for the '<em><b>Rx On When Idle</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int NODE_DESCRIPTOR__RX_ON_WHEN_IDLE = 9;

	/**
	 * The feature id for the '<em><b>Security</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int NODE_DESCRIPTOR__SECURITY = 10;

	/**
	 * The feature id for the '<em><b>Allocate Address</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int NODE_DESCRIPTOR__ALLOCATE_ADDRESS = 11;

	/**
	 * The feature id for the '<em><b>Maximum Buffer Size</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int NODE_DESCRIPTOR__MAXIMUM_BUFFER_SIZE = 12;

	/**
	 * The feature id for the '<em><b>Maximum Incoming Transfer Size</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int NODE_DESCRIPTOR__MAXIMUM_INCOMING_TRANSFER_SIZE = 13;

	/**
	 * The feature id for the '<em><b>Maximum Outgoing Transfer Size</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int NODE_DESCRIPTOR__MAXIMUM_OUTGOING_TRANSFER_SIZE = 14;

	/**
	 * The feature id for the '<em><b>Extended Active Endpoint List Available</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int NODE_DESCRIPTOR__EXTENDED_ACTIVE_ENDPOINT_LIST_AVAILABLE = 15;

	/**
	 * The feature id for the '<em><b>Extended Simple Descriptor List Available</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int NODE_DESCRIPTOR__EXTENDED_SIMPLE_DESCRIPTOR_LIST_AVAILABLE = 16;

	/**
	 * The feature id for the '<em><b>Primary Trust Center</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int NODE_DESCRIPTOR__PRIMARY_TRUST_CENTER = 17;

	/**
	 * The feature id for the '<em><b>Backup Trust Center</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int NODE_DESCRIPTOR__BACKUP_TRUST_CENTER = 18;

	/**
	 * The feature id for the '<em><b>Primary Binding Table Cache</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int NODE_DESCRIPTOR__PRIMARY_BINDING_TABLE_CACHE = 19;

	/**
	 * The feature id for the '<em><b>Backup Binding Table Cache</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int NODE_DESCRIPTOR__BACKUP_BINDING_TABLE_CACHE = 20;

	/**
	 * The feature id for the '<em><b>Primary Discovery Cache</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int NODE_DESCRIPTOR__PRIMARY_DISCOVERY_CACHE = 21;

	/**
	 * The feature id for the '<em><b>Backup Discovery Cache</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int NODE_DESCRIPTOR__BACKUP_DISCOVERY_CACHE = 22;

	/**
	 * The feature id for the '<em><b>Node</b></em>' container reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int NODE_DESCRIPTOR__NODE = 23;

	/**
	 * The feature id for the '<em><b>Network Manager</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int NODE_DESCRIPTOR__NETWORK_MANAGER = 24;

	/**
	 * The number of structural features of the '<em>Node Descriptor</em>' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int NODE_DESCRIPTOR_FEATURE_COUNT = 25;

	/**
	 * The meta object id for the '{@link com.jennic.ZPSConfiguration.impl.NodePowerDescriptorImpl <em>Node Power Descriptor</em>}' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see com.jennic.ZPSConfiguration.impl.NodePowerDescriptorImpl
	 * @see com.jennic.ZPSConfiguration.impl.ZPSConfigurationPackageImpl#getNodePowerDescriptor()
	 * @generated
	 */
	int NODE_POWER_DESCRIPTOR = 50;

	/**
	 * The feature id for the '<em><b>Constant Power</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int NODE_POWER_DESCRIPTOR__CONSTANT_POWER = 0;

	/**
	 * The feature id for the '<em><b>Rechargeable Battery</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int NODE_POWER_DESCRIPTOR__RECHARGEABLE_BATTERY = 1;

	/**
	 * The feature id for the '<em><b>Disposable Battery</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int NODE_POWER_DESCRIPTOR__DISPOSABLE_BATTERY = 2;

	/**
	 * The feature id for the '<em><b>Default Power Source</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int NODE_POWER_DESCRIPTOR__DEFAULT_POWER_SOURCE = 3;

	/**
	 * The feature id for the '<em><b>Default Power Mode</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int NODE_POWER_DESCRIPTOR__DEFAULT_POWER_MODE = 4;

	/**
	 * The number of structural features of the '<em>Node Power Descriptor</em>' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int NODE_POWER_DESCRIPTOR_FEATURE_COUNT = 5;

	/**
	 * The meta object id for the '{@link com.jennic.ZPSConfiguration.impl.BindUnbindServerImpl <em>Bind Unbind Server</em>}' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see com.jennic.ZPSConfiguration.impl.BindUnbindServerImpl
	 * @see com.jennic.ZPSConfiguration.impl.ZPSConfigurationPackageImpl#getBindUnbindServer()
	 * @generated
	 */
	int BIND_UNBIND_SERVER = 51;

	/**
	 * The feature id for the '<em><b>Output APdu</b></em>' reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int BIND_UNBIND_SERVER__OUTPUT_APDU = ZDO_CLIENT_SERVER__OUTPUT_APDU;

	/**
	 * The number of structural features of the '<em>Bind Unbind Server</em>' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int BIND_UNBIND_SERVER_FEATURE_COUNT = ZDO_CLIENT_SERVER_FEATURE_COUNT + 0;

	/**
	 * The meta object id for the '{@link com.jennic.ZPSConfiguration.impl.MgmtBindServerImpl <em>Mgmt Bind Server</em>}' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see com.jennic.ZPSConfiguration.impl.MgmtBindServerImpl
	 * @see com.jennic.ZPSConfiguration.impl.ZPSConfigurationPackageImpl#getMgmtBindServer()
	 * @generated
	 */
	int MGMT_BIND_SERVER = 52;

	/**
	 * The feature id for the '<em><b>Output APdu</b></em>' reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int MGMT_BIND_SERVER__OUTPUT_APDU = ZDO_CLIENT_SERVER__OUTPUT_APDU;

	/**
	 * The number of structural features of the '<em>Mgmt Bind Server</em>' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int MGMT_BIND_SERVER_FEATURE_COUNT = ZDO_CLIENT_SERVER_FEATURE_COUNT + 0;

	/**
	 * The meta object id for the '{@link com.jennic.ZPSConfiguration.impl.ExtendedActiveEpServerImpl <em>Extended Active Ep Server</em>}' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see com.jennic.ZPSConfiguration.impl.ExtendedActiveEpServerImpl
	 * @see com.jennic.ZPSConfiguration.impl.ZPSConfigurationPackageImpl#getExtendedActiveEpServer()
	 * @generated
	 */
	int EXTENDED_ACTIVE_EP_SERVER = 53;

	/**
	 * The meta object id for the '{@link com.jennic.ZPSConfiguration.impl.ExtendedSimpleDescServerImpl <em>Extended Simple Desc Server</em>}' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see com.jennic.ZPSConfiguration.impl.ExtendedSimpleDescServerImpl
	 * @see com.jennic.ZPSConfiguration.impl.ZPSConfigurationPackageImpl#getExtendedSimpleDescServer()
	 * @generated
	 */
	int EXTENDED_SIMPLE_DESC_SERVER = 54;

	/**
	 * The meta object id for the '{@link com.jennic.ZPSConfiguration.impl.ZdoClientImpl <em>Zdo Client</em>}' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see com.jennic.ZPSConfiguration.impl.ZdoClientImpl
	 * @see com.jennic.ZPSConfiguration.impl.ZPSConfigurationPackageImpl#getZdoClient()
	 * @generated
	 */
	int ZDO_CLIENT = 55;

	/**
	 * The meta object id for the '{@link com.jennic.ZPSConfiguration.impl.MgmtNWKUpdateServerImpl <em>Mgmt NWK Update Server</em>}' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see com.jennic.ZPSConfiguration.impl.MgmtNWKUpdateServerImpl
	 * @see com.jennic.ZPSConfiguration.impl.ZPSConfigurationPackageImpl#getMgmtNWKUpdateServer()
	 * @generated
	 */
	int MGMT_NWK_UPDATE_SERVER = 56;

	/**
	 * The meta object id for the '{@link com.jennic.ZPSConfiguration.impl.NotImplementedImpl <em>Not Implemented</em>}' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see com.jennic.ZPSConfiguration.impl.NotImplementedImpl
	 * @see com.jennic.ZPSConfiguration.impl.ZPSConfigurationPackageImpl#getNotImplemented()
	 * @generated
	 */
	int NOT_IMPLEMENTED = 58;

	/**
	 * The meta object id for the '{@link com.jennic.ZPSConfiguration.impl.KeyDescriptorTableImpl <em>Key Descriptor Table</em>}' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see com.jennic.ZPSConfiguration.impl.KeyDescriptorTableImpl
	 * @see com.jennic.ZPSConfiguration.impl.ZPSConfigurationPackageImpl#getKeyDescriptorTable()
	 * @generated
	 */
	int KEY_DESCRIPTOR_TABLE = 59;

	/**
	 * The meta object id for the '{@link com.jennic.ZPSConfiguration.impl.PreconfiguredKeyImpl <em>Preconfigured Key</em>}' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see com.jennic.ZPSConfiguration.impl.PreconfiguredKeyImpl
	 * @see com.jennic.ZPSConfiguration.impl.ZPSConfigurationPackageImpl#getPreconfiguredKey()
	 * @generated
	 */
	int PRECONFIGURED_KEY = 60;

	/**
	 * The meta object id for the '{@link com.jennic.ZPSConfiguration.impl.ZDOCoordRouterOnlyServersImpl <em>ZDO Coord Router Only Servers</em>}' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see com.jennic.ZPSConfiguration.impl.ZDOCoordRouterOnlyServersImpl
	 * @see com.jennic.ZPSConfiguration.impl.ZPSConfigurationPackageImpl#getZDOCoordRouterOnlyServers()
	 * @generated
	 */
	int ZDO_COORD_ROUTER_ONLY_SERVERS = 61;

	/**
	 * The meta object id for the '{@link com.jennic.ZPSConfiguration.impl.TCKeyImpl <em>TC Key</em>}' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see com.jennic.ZPSConfiguration.impl.TCKeyImpl
	 * @see com.jennic.ZPSConfiguration.impl.ZPSConfigurationPackageImpl#getTCKey()
	 * @generated
	 */
	int TC_KEY = 66;

	/**
	 * The meta object id for the '{@link com.jennic.ZPSConfiguration.impl.NwkKeyImpl <em>Nwk Key</em>}' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see com.jennic.ZPSConfiguration.impl.NwkKeyImpl
	 * @see com.jennic.ZPSConfiguration.impl.ZPSConfigurationPackageImpl#getNwkKey()
	 * @generated
	 */
	int NWK_KEY = 64;

	/**
	 * The meta object id for the '{@link com.jennic.ZPSConfiguration.impl.PreConfiguredNwkKeyImpl <em>Pre Configured Nwk Key</em>}' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see com.jennic.ZPSConfiguration.impl.PreConfiguredNwkKeyImpl
	 * @see com.jennic.ZPSConfiguration.impl.ZPSConfigurationPackageImpl#getPreConfiguredNwkKey()
	 * @generated
	 */
	int PRE_CONFIGURED_NWK_KEY = 62;

	/**
	 * The meta object id for the '{@link com.jennic.ZPSConfiguration.impl.DefaultNwkKeyImpl <em>Default Nwk Key</em>}' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see com.jennic.ZPSConfiguration.impl.DefaultNwkKeyImpl
	 * @see com.jennic.ZPSConfiguration.impl.ZPSConfigurationPackageImpl#getDefaultNwkKey()
	 * @generated
	 */
	int DEFAULT_NWK_KEY = 63;

	/**
	 * The meta object id for the '{@link com.jennic.ZPSConfiguration.impl.PreconfiguredTCLinkKeyImpl <em>Preconfigured TC Link Key</em>}' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see com.jennic.ZPSConfiguration.impl.PreconfiguredTCLinkKeyImpl
	 * @see com.jennic.ZPSConfiguration.impl.ZPSConfigurationPackageImpl#getPreconfiguredTCLinkKey()
	 * @generated
	 */
	int PRECONFIGURED_TC_LINK_KEY = 65;

	/**
	 * The meta object id for the '{@link com.jennic.ZPSConfiguration.impl.BindRequestServerImpl <em>Bind Request Server</em>}' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see com.jennic.ZPSConfiguration.impl.BindRequestServerImpl
	 * @see com.jennic.ZPSConfiguration.impl.ZPSConfigurationPackageImpl#getBindRequestServer()
	 * @generated
	 */
	int BIND_REQUEST_SERVER = 67;

	/**
	 * The feature id for the '<em><b>Output APdu</b></em>' reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int EXTENDED_ACTIVE_EP_SERVER__OUTPUT_APDU = ZDO_CLIENT_SERVER__OUTPUT_APDU;

	/**
	 * The number of structural features of the '<em>Extended Active Ep Server</em>' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int EXTENDED_ACTIVE_EP_SERVER_FEATURE_COUNT = ZDO_CLIENT_SERVER_FEATURE_COUNT + 0;

	/**
	 * The feature id for the '<em><b>Output APdu</b></em>' reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int EXTENDED_SIMPLE_DESC_SERVER__OUTPUT_APDU = ZDO_CLIENT_SERVER__OUTPUT_APDU;

	/**
	 * The number of structural features of the '<em>Extended Simple Desc Server</em>' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int EXTENDED_SIMPLE_DESC_SERVER_FEATURE_COUNT = ZDO_CLIENT_SERVER_FEATURE_COUNT + 0;

	/**
	 * The feature id for the '<em><b>Output APdu</b></em>' reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ZDO_CLIENT__OUTPUT_APDU = ZDO_CLIENT_SERVER__OUTPUT_APDU;

	/**
	 * The number of structural features of the '<em>Zdo Client</em>' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ZDO_CLIENT_FEATURE_COUNT = ZDO_CLIENT_SERVER_FEATURE_COUNT + 0;

	/**
	 * The feature id for the '<em><b>Output APdu</b></em>' reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int MGMT_NWK_UPDATE_SERVER__OUTPUT_APDU = ZDO_CLIENT_SERVER__OUTPUT_APDU;

	/**
	 * The number of structural features of the '<em>Mgmt NWK Update Server</em>' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int MGMT_NWK_UPDATE_SERVER_FEATURE_COUNT = ZDO_CLIENT_SERVER_FEATURE_COUNT + 0;

	/**
	 * The feature id for the '<em><b>Complex Descriptor</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int NOT_IMPLEMENTED__COMPLEX_DESCRIPTOR = 0;

	/**
	 * The feature id for the '<em><b>Discovery Table</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int NOT_IMPLEMENTED__DISCOVERY_TABLE = 1;

	/**
	 * The feature id for the '<em><b>Discovery Cache</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int NOT_IMPLEMENTED__DISCOVERY_CACHE = 2;

	/**
	 * The feature id for the '<em><b>Binding Cache</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int NOT_IMPLEMENTED__BINDING_CACHE = 3;

	/**
	 * The number of structural features of the '<em>Not Implemented</em>' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int NOT_IMPLEMENTED_FEATURE_COUNT = 4;

	/**
	 * The feature id for the '<em><b>Size</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int KEY_DESCRIPTOR_TABLE__SIZE = 0;

	/**
	 * The feature id for the '<em><b>Preconfigured Key</b></em>' containment reference list.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int KEY_DESCRIPTOR_TABLE__PRECONFIGURED_KEY = 1;

	/**
	 * The number of structural features of the '<em>Key Descriptor Table</em>' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int KEY_DESCRIPTOR_TABLE_FEATURE_COUNT = 2;

	/**
	 * The feature id for the '<em><b>Key</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int PRECONFIGURED_KEY__KEY = 0;

	/**
	 * The feature id for the '<em><b>IEEE Address</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int PRECONFIGURED_KEY__IEEE_ADDRESS = 1;

	/**
	 * The number of structural features of the '<em>Preconfigured Key</em>' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int PRECONFIGURED_KEY_FEATURE_COUNT = 2;

	/**
	 * The feature id for the '<em><b>Permit Joining Server</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ZDO_COORD_ROUTER_ONLY_SERVERS__PERMIT_JOINING_SERVER = 0;

	/**
	 * The feature id for the '<em><b>Mgmt Rtg Server</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ZDO_COORD_ROUTER_ONLY_SERVERS__MGMT_RTG_SERVER = 1;

	/**
	 * The feature id for the '<em><b>Mgmt Mib Ieee Server</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ZDO_COORD_ROUTER_ONLY_SERVERS__MGMT_MIB_IEEE_SERVER = 2;

	/**
	 * The feature id for the '<em><b>Parent Annce Server</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ZDO_COORD_ROUTER_ONLY_SERVERS__PARENT_ANNCE_SERVER = 3;

	/**
	 * The number of structural features of the '<em>ZDO Coord Router Only Servers</em>' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ZDO_COORD_ROUTER_ONLY_SERVERS_FEATURE_COUNT = 4;

	/**
	 * The number of structural features of the '<em>TC Key</em>' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int TC_KEY_FEATURE_COUNT = 0;

	/**
	 * The feature id for the '<em><b>Key Sequence Number</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int NWK_KEY__KEY_SEQUENCE_NUMBER = TC_KEY_FEATURE_COUNT + 0;

	/**
	 * The feature id for the '<em><b>Key</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int NWK_KEY__KEY = TC_KEY_FEATURE_COUNT + 1;

	/**
	 * The feature id for the '<em><b>Id</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int NWK_KEY__ID = TC_KEY_FEATURE_COUNT + 2;

	/**
	 * The number of structural features of the '<em>Nwk Key</em>' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int NWK_KEY_FEATURE_COUNT = TC_KEY_FEATURE_COUNT + 3;

	/**
	 * The feature id for the '<em><b>Key Sequence Number</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int PRE_CONFIGURED_NWK_KEY__KEY_SEQUENCE_NUMBER = NWK_KEY__KEY_SEQUENCE_NUMBER;

	/**
	 * The feature id for the '<em><b>Key</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int PRE_CONFIGURED_NWK_KEY__KEY = NWK_KEY__KEY;

	/**
	 * The feature id for the '<em><b>Id</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int PRE_CONFIGURED_NWK_KEY__ID = NWK_KEY__ID;

	/**
	 * The number of structural features of the '<em>Pre Configured Nwk Key</em>' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int PRE_CONFIGURED_NWK_KEY_FEATURE_COUNT = NWK_KEY_FEATURE_COUNT + 0;

	/**
	 * The feature id for the '<em><b>Key Sequence Number</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int DEFAULT_NWK_KEY__KEY_SEQUENCE_NUMBER = NWK_KEY__KEY_SEQUENCE_NUMBER;

	/**
	 * The feature id for the '<em><b>Key</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int DEFAULT_NWK_KEY__KEY = NWK_KEY__KEY;

	/**
	 * The feature id for the '<em><b>Id</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int DEFAULT_NWK_KEY__ID = NWK_KEY__ID;

	/**
	 * The feature id for the '<em><b>Random</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int DEFAULT_NWK_KEY__RANDOM = NWK_KEY_FEATURE_COUNT + 0;

	/**
	 * The number of structural features of the '<em>Default Nwk Key</em>' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int DEFAULT_NWK_KEY_FEATURE_COUNT = NWK_KEY_FEATURE_COUNT + 1;

	/**
	 * The feature id for the '<em><b>Id</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int PRECONFIGURED_TC_LINK_KEY__ID = TC_KEY_FEATURE_COUNT + 0;

	/**
	 * The number of structural features of the '<em>Preconfigured TC Link Key</em>' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int PRECONFIGURED_TC_LINK_KEY_FEATURE_COUNT = TC_KEY_FEATURE_COUNT + 1;

	/**
	 * The feature id for the '<em><b>Output APdu</b></em>' reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int BIND_REQUEST_SERVER__OUTPUT_APDU = ZDO_CLIENT_SERVER__OUTPUT_APDU;

	/**
	 * The feature id for the '<em><b>Simultaneous Requests</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int BIND_REQUEST_SERVER__SIMULTANEOUS_REQUESTS = ZDO_CLIENT_SERVER_FEATURE_COUNT + 0;

	/**
	 * The feature id for the '<em><b>Time Interval</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int BIND_REQUEST_SERVER__TIME_INTERVAL = ZDO_CLIENT_SERVER_FEATURE_COUNT + 1;

	/**
	 * The number of structural features of the '<em>Bind Request Server</em>' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int BIND_REQUEST_SERVER_FEATURE_COUNT = ZDO_CLIENT_SERVER_FEATURE_COUNT + 2;

	/**
	 * The meta object id for the '{@link com.jennic.ZPSConfiguration.impl.GreenPowerSecurityTableImpl <em>Green Power Security Table</em>}' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see com.jennic.ZPSConfiguration.impl.GreenPowerSecurityTableImpl
	 * @see com.jennic.ZPSConfiguration.impl.ZPSConfigurationPackageImpl#getGreenPowerSecurityTable()
	 * @generated
	 */
	int GREEN_POWER_SECURITY_TABLE = 68;

	/**
	 * The feature id for the '<em><b>Size</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int GREEN_POWER_SECURITY_TABLE__SIZE = 0;

	/**
	 * The number of structural features of the '<em>Green Power Security Table</em>' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int GREEN_POWER_SECURITY_TABLE_FEATURE_COUNT = 1;

	/**
	 * The meta object id for the '{@link com.jennic.ZPSConfiguration.impl.GreenPowerTxQueueImpl <em>Green Power Tx Queue</em>}' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see com.jennic.ZPSConfiguration.impl.GreenPowerTxQueueImpl
	 * @see com.jennic.ZPSConfiguration.impl.ZPSConfigurationPackageImpl#getGreenPowerTxQueue()
	 * @generated
	 */
	int GREEN_POWER_TX_QUEUE = 69;

	/**
	 * The feature id for the '<em><b>Size</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int GREEN_POWER_TX_QUEUE__SIZE = 0;

	/**
	 * The number of structural features of the '<em>Green Power Tx Queue</em>' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int GREEN_POWER_TX_QUEUE_FEATURE_COUNT = 1;

	/**
	 * The meta object id for the '{@link com.jennic.ZPSConfiguration.impl.MgmtMibIeeeServerImpl <em>Mgmt Mib Ieee Server</em>}' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see com.jennic.ZPSConfiguration.impl.MgmtMibIeeeServerImpl
	 * @see com.jennic.ZPSConfiguration.impl.ZPSConfigurationPackageImpl#getMgmtMibIeeeServer()
	 * @generated
	 */
	int MGMT_MIB_IEEE_SERVER = 70;

	/**
	 * The feature id for the '<em><b>Output APdu</b></em>' reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int MGMT_MIB_IEEE_SERVER__OUTPUT_APDU = ZDO_CLIENT_SERVER__OUTPUT_APDU;

	/**
	 * The number of structural features of the '<em>Mgmt Mib Ieee Server</em>' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int MGMT_MIB_IEEE_SERVER_FEATURE_COUNT = ZDO_CLIENT_SERVER_FEATURE_COUNT + 0;

	/**
	 * The meta object id for the '{@link com.jennic.ZPSConfiguration.impl.MgmtNWKEnhanceUpdateServerImpl <em>Mgmt NWK Enhance Update Server</em>}' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see com.jennic.ZPSConfiguration.impl.MgmtNWKEnhanceUpdateServerImpl
	 * @see com.jennic.ZPSConfiguration.impl.ZPSConfigurationPackageImpl#getMgmtNWKEnhanceUpdateServer()
	 * @generated
	 */
	int MGMT_NWK_ENHANCE_UPDATE_SERVER = 72;

	/**
	 * The meta object id for the '{@link com.jennic.ZPSConfiguration.impl.MacInterfaceListImpl <em>Mac Interface List</em>}' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see com.jennic.ZPSConfiguration.impl.MacInterfaceListImpl
	 * @see com.jennic.ZPSConfiguration.impl.ZPSConfigurationPackageImpl#getMacInterfaceList()
	 * @generated
	 */
	int MAC_INTERFACE_LIST = 73;

	/**
	 * The meta object id for the '{@link com.jennic.ZPSConfiguration.impl.MacInterfaceImpl <em>Mac Interface</em>}' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see com.jennic.ZPSConfiguration.impl.MacInterfaceImpl
	 * @see com.jennic.ZPSConfiguration.impl.ZPSConfigurationPackageImpl#getMacInterface()
	 * @generated
	 */
	int MAC_INTERFACE = 74;

	/**
	 * The meta object id for the '{@link com.jennic.ZPSConfiguration.impl.ParentAnnceServerImpl <em>Parent Annce Server</em>}' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see com.jennic.ZPSConfiguration.impl.ParentAnnceServerImpl
	 * @see com.jennic.ZPSConfiguration.impl.ZPSConfigurationPackageImpl#getParentAnnceServer()
	 * @generated
	 */
	int PARENT_ANNCE_SERVER = 71;

	/**
	 * The feature id for the '<em><b>Output APdu</b></em>' reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int PARENT_ANNCE_SERVER__OUTPUT_APDU = ZDO_CLIENT_SERVER__OUTPUT_APDU;

	/**
	 * The number of structural features of the '<em>Parent Annce Server</em>' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int PARENT_ANNCE_SERVER_FEATURE_COUNT = ZDO_CLIENT_SERVER_FEATURE_COUNT + 0;

	/**
	 * The feature id for the '<em><b>Output APdu</b></em>' reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int MGMT_NWK_ENHANCE_UPDATE_SERVER__OUTPUT_APDU = ZDO_CLIENT_SERVER__OUTPUT_APDU;

	/**
	 * The number of structural features of the '<em>Mgmt NWK Enhance Update Server</em>' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int MGMT_NWK_ENHANCE_UPDATE_SERVER_FEATURE_COUNT = ZDO_CLIENT_SERVER_FEATURE_COUNT + 0;

	/**
	 * The feature id for the '<em><b>Mac Interface</b></em>' containment reference list.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int MAC_INTERFACE_LIST__MAC_INTERFACE = 0;

	/**
	 * The number of structural features of the '<em>Mac Interface List</em>' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int MAC_INTERFACE_LIST_FEATURE_COUNT = 1;

	/**
	 * The feature id for the '<em><b>Router Allowed</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int MAC_INTERFACE__ROUTER_ALLOWED = 0;

	/**
	 * The feature id for the '<em><b>Channel List Size</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int MAC_INTERFACE__CHANNEL_LIST_SIZE = 1;

	/**
	 * The feature id for the '<em><b>Index</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int MAC_INTERFACE__INDEX = 2;

	/**
	 * The feature id for the '<em><b>Radio Type</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int MAC_INTERFACE__RADIO_TYPE = 3;

	/**
	 * The feature id for the '<em><b>Enabled</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int MAC_INTERFACE__ENABLED = 4;

	/**
	 * The number of structural features of the '<em>Mac Interface</em>' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int MAC_INTERFACE_FEATURE_COUNT = 5;

	/**
	 * The meta object id for the '{@link com.jennic.ZPSConfiguration.NodeLogicalType <em>Node Logical Type</em>}' enum.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see com.jennic.ZPSConfiguration.NodeLogicalType
	 * @see com.jennic.ZPSConfiguration.impl.ZPSConfigurationPackageImpl#getNodeLogicalType()
	 * @generated
	 */
	int NODE_LOGICAL_TYPE = 75;

	/**
	 * The meta object id for the '{@link com.jennic.ZPSConfiguration.FrequencyBands <em>Frequency Bands</em>}' enum.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see com.jennic.ZPSConfiguration.FrequencyBands
	 * @see com.jennic.ZPSConfiguration.impl.ZPSConfigurationPackageImpl#getFrequencyBands()
	 * @generated
	 */
	int FREQUENCY_BANDS = 76;

	/**
	 * The meta object id for the '{@link com.jennic.ZPSConfiguration.PowerSources <em>Power Sources</em>}' enum.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see com.jennic.ZPSConfiguration.PowerSources
	 * @see com.jennic.ZPSConfiguration.impl.ZPSConfigurationPackageImpl#getPowerSources()
	 * @generated
	 */
	int POWER_SOURCES = 77;

	/**
	 * The meta object id for the '{@link com.jennic.ZPSConfiguration.PowerModes <em>Power Modes</em>}' enum.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see com.jennic.ZPSConfiguration.PowerModes
	 * @see com.jennic.ZPSConfiguration.impl.ZPSConfigurationPackageImpl#getPowerModes()
	 * @generated
	 */
	int POWER_MODES = 78;

	/**
	 * The meta object id for the '{@link com.jennic.ZPSConfiguration.NetworkSelectionTypes <em>Network Selection Types</em>}' enum.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see com.jennic.ZPSConfiguration.NetworkSelectionTypes
	 * @see com.jennic.ZPSConfiguration.impl.ZPSConfigurationPackageImpl#getNetworkSelectionTypes()
	 * @generated
	 */
	int NETWORK_SELECTION_TYPES = 79;

	/**
	 * The meta object id for the '{@link com.jennic.ZPSConfiguration.RadioType <em>Radio Type</em>}' enum.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see com.jennic.ZPSConfiguration.RadioType
	 * @see com.jennic.ZPSConfiguration.impl.ZPSConfigurationPackageImpl#getRadioType()
	 * @generated
	 */
	int RADIO_TYPE = 80;

	/**
	 * The meta object id for the '<em>EU Short</em>' data type.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see Integer
	 * @see com.jennic.ZPSConfiguration.impl.ZPSConfigurationPackageImpl#getEUShort()
	 * @generated
	 */
	int EU_SHORT = 81;

	/**
	 * The meta object id for the '<em>EExt PAN Id</em>' data type.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see BigInteger
	 * @see com.jennic.ZPSConfiguration.impl.ZPSConfigurationPackageImpl#getEExtPANId()
	 * @generated
	 */
	int EEXT_PAN_ID = 82;


	/**
	 * The meta object id for the '<em>EPermit Joining</em>' data type.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see Integer
	 * @see com.jennic.ZPSConfiguration.impl.ZPSConfigurationPackageImpl#getEPermitJoining()
	 * @generated
	 */
	int EPERMIT_JOINING = 83;

	/**
	 * The meta object id for the '<em>ESec Key</em>' data type.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see BigInteger
	 * @see com.jennic.ZPSConfiguration.impl.ZPSConfigurationPackageImpl#getESecKey()
	 * @generated
	 */
	int ESEC_KEY = 84;


	/**
	 * Returns the meta object for class '{@link com.jennic.ZPSConfiguration.Profile <em>Profile</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for class '<em>Profile</em>'.
	 * @see com.jennic.ZPSConfiguration.Profile
	 * @generated
	 */
	EClass getProfile();

	/**
	 * Returns the meta object for the attribute '{@link com.jennic.ZPSConfiguration.Profile#getId <em>Id</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the attribute '<em>Id</em>'.
	 * @see com.jennic.ZPSConfiguration.Profile#getId()
	 * @see #getProfile()
	 * @generated
	 */
	EAttribute getProfile_Id();

	/**
	 * Returns the meta object for the containment reference list '{@link com.jennic.ZPSConfiguration.Profile#getClusters <em>Clusters</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the containment reference list '<em>Clusters</em>'.
	 * @see com.jennic.ZPSConfiguration.Profile#getClusters()
	 * @see #getProfile()
	 * @generated
	 */
	EReference getProfile_Clusters();

	/**
	 * Returns the meta object for class '{@link com.jennic.ZPSConfiguration.Cluster <em>Cluster</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for class '<em>Cluster</em>'.
	 * @see com.jennic.ZPSConfiguration.Cluster
	 * @generated
	 */
	EClass getCluster();

	/**
	 * Returns the meta object for the attribute '{@link com.jennic.ZPSConfiguration.Cluster#getId <em>Id</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the attribute '<em>Id</em>'.
	 * @see com.jennic.ZPSConfiguration.Cluster#getId()
	 * @see #getCluster()
	 * @generated
	 */
	EAttribute getCluster_Id();

	/**
	 * Returns the meta object for class '{@link com.jennic.ZPSConfiguration.Node <em>Node</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for class '<em>Node</em>'.
	 * @see com.jennic.ZPSConfiguration.Node
	 * @generated
	 */
	EClass getNode();

	/**
	 * Returns the meta object for the containment reference list '{@link com.jennic.ZPSConfiguration.Node#getEndpoints <em>Endpoints</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the containment reference list '<em>Endpoints</em>'.
	 * @see com.jennic.ZPSConfiguration.Node#getEndpoints()
	 * @see #getNode()
	 * @generated
	 */
	EReference getNode_Endpoints();

	/**
	 * Returns the meta object for the containment reference '{@link com.jennic.ZPSConfiguration.Node#getBindingTable <em>Binding Table</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the containment reference '<em>Binding Table</em>'.
	 * @see com.jennic.ZPSConfiguration.Node#getBindingTable()
	 * @see #getNode()
	 * @generated
	 */
	EReference getNode_BindingTable();

	/**
	 * Returns the meta object for the containment reference '{@link com.jennic.ZPSConfiguration.Node#getUserDescriptor <em>User Descriptor</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the containment reference '<em>User Descriptor</em>'.
	 * @see com.jennic.ZPSConfiguration.Node#getUserDescriptor()
	 * @see #getNode()
	 * @generated
	 */
	EReference getNode_UserDescriptor();

	/**
	 * Returns the meta object for the containment reference '{@link com.jennic.ZPSConfiguration.Node#getPDUConfiguration <em>PDU Configuration</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the containment reference '<em>PDU Configuration</em>'.
	 * @see com.jennic.ZPSConfiguration.Node#getPDUConfiguration()
	 * @see #getNode()
	 * @generated
	 */
	EReference getNode_PDUConfiguration();

	/**
	 * Returns the meta object for the containment reference '{@link com.jennic.ZPSConfiguration.Node#getGroupTable <em>Group Table</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the containment reference '<em>Group Table</em>'.
	 * @see com.jennic.ZPSConfiguration.Node#getGroupTable()
	 * @see #getNode()
	 * @generated
	 */
	EReference getNode_GroupTable();

	/**
	 * Returns the meta object for the attribute '{@link com.jennic.ZPSConfiguration.Node#getMaxNumSimultaneousApsdeAckReq <em>Max Num Simultaneous Apsde Ack Req</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the attribute '<em>Max Num Simultaneous Apsde Ack Req</em>'.
	 * @see com.jennic.ZPSConfiguration.Node#getMaxNumSimultaneousApsdeAckReq()
	 * @see #getNode()
	 * @generated
	 */
	EAttribute getNode_MaxNumSimultaneousApsdeAckReq();

	/**
	 * Returns the meta object for the containment reference '{@link com.jennic.ZPSConfiguration.Node#getChannelMask <em>Channel Mask</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the containment reference '<em>Channel Mask</em>'.
	 * @see com.jennic.ZPSConfiguration.Node#getChannelMask()
	 * @see #getNode()
	 * @generated
	 */
	EReference getNode_ChannelMask();

	/**
	 * Returns the meta object for the attribute '{@link com.jennic.ZPSConfiguration.Node#getDiscoveryNeighbourTableSize <em>Discovery Neighbour Table Size</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the attribute '<em>Discovery Neighbour Table Size</em>'.
	 * @see com.jennic.ZPSConfiguration.Node#getDiscoveryNeighbourTableSize()
	 * @see #getNode()
	 * @generated
	 */
	EAttribute getNode_DiscoveryNeighbourTableSize();

	/**
	 * Returns the meta object for the attribute '{@link com.jennic.ZPSConfiguration.Node#getActiveNeighbourTableSize <em>Active Neighbour Table Size</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the attribute '<em>Active Neighbour Table Size</em>'.
	 * @see com.jennic.ZPSConfiguration.Node#getActiveNeighbourTableSize()
	 * @see #getNode()
	 * @generated
	 */
	EAttribute getNode_ActiveNeighbourTableSize();

	/**
	 * Returns the meta object for the attribute '{@link com.jennic.ZPSConfiguration.Node#getRouteDiscoveryTableSize <em>Route Discovery Table Size</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the attribute '<em>Route Discovery Table Size</em>'.
	 * @see com.jennic.ZPSConfiguration.Node#getRouteDiscoveryTableSize()
	 * @see #getNode()
	 * @generated
	 */
	EAttribute getNode_RouteDiscoveryTableSize();

	/**
	 * Returns the meta object for the attribute '{@link com.jennic.ZPSConfiguration.Node#getRoutingTableSize <em>Routing Table Size</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the attribute '<em>Routing Table Size</em>'.
	 * @see com.jennic.ZPSConfiguration.Node#getRoutingTableSize()
	 * @see #getNode()
	 * @generated
	 */
	EAttribute getNode_RoutingTableSize();

	/**
	 * Returns the meta object for the attribute '{@link com.jennic.ZPSConfiguration.Node#getBroadcastTransactionTableSize <em>Broadcast Transaction Table Size</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the attribute '<em>Broadcast Transaction Table Size</em>'.
	 * @see com.jennic.ZPSConfiguration.Node#getBroadcastTransactionTableSize()
	 * @see #getNode()
	 * @generated
	 */
	EAttribute getNode_BroadcastTransactionTableSize();

	/**
	 * Returns the meta object for the attribute '{@link com.jennic.ZPSConfiguration.Node#getRouteRecordTableSize <em>Route Record Table Size</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the attribute '<em>Route Record Table Size</em>'.
	 * @see com.jennic.ZPSConfiguration.Node#getRouteRecordTableSize()
	 * @see #getNode()
	 * @generated
	 */
	EAttribute getNode_RouteRecordTableSize();

	/**
	 * Returns the meta object for the attribute '{@link com.jennic.ZPSConfiguration.Node#getAddressMapTableSize <em>Address Map Table Size</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the attribute '<em>Address Map Table Size</em>'.
	 * @see com.jennic.ZPSConfiguration.Node#getAddressMapTableSize()
	 * @see #getNode()
	 * @generated
	 */
	EAttribute getNode_AddressMapTableSize();

	/**
	 * Returns the meta object for the attribute '{@link com.jennic.ZPSConfiguration.Node#getSecurityMaterialSets <em>Security Material Sets</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the attribute '<em>Security Material Sets</em>'.
	 * @see com.jennic.ZPSConfiguration.Node#getSecurityMaterialSets()
	 * @see #getNode()
	 * @generated
	 */
	EAttribute getNode_SecurityMaterialSets();

	/**
	 * Returns the meta object for the containment reference '{@link com.jennic.ZPSConfiguration.Node#getNodeDescriptor <em>Node Descriptor</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the containment reference '<em>Node Descriptor</em>'.
	 * @see com.jennic.ZPSConfiguration.Node#getNodeDescriptor()
	 * @see #getNode()
	 * @generated
	 */
	EReference getNode_NodeDescriptor();

	/**
	 * Returns the meta object for the containment reference '{@link com.jennic.ZPSConfiguration.Node#getNodePowerDescriptor <em>Node Power Descriptor</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the containment reference '<em>Node Power Descriptor</em>'.
	 * @see com.jennic.ZPSConfiguration.Node#getNodePowerDescriptor()
	 * @see #getNode()
	 * @generated
	 */
	EReference getNode_NodePowerDescriptor();

	/**
	 * Returns the meta object for the attribute '{@link com.jennic.ZPSConfiguration.Node#getMaxNumSimultaneousApsdeReq <em>Max Num Simultaneous Apsde Req</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the attribute '<em>Max Num Simultaneous Apsde Req</em>'.
	 * @see com.jennic.ZPSConfiguration.Node#getMaxNumSimultaneousApsdeReq()
	 * @see #getNode()
	 * @generated
	 */
	EAttribute getNode_MaxNumSimultaneousApsdeReq();

	/**
	 * Returns the meta object for the attribute '{@link com.jennic.ZPSConfiguration.Node#getMACMutexName <em>MAC Mutex Name</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the attribute '<em>MAC Mutex Name</em>'.
	 * @see com.jennic.ZPSConfiguration.Node#getMACMutexName()
	 * @see #getNode()
	 * @generated
	 */
	EAttribute getNode_MACMutexName();

	/**
	 * Returns the meta object for the attribute '{@link com.jennic.ZPSConfiguration.Node#getZPSMutexName <em>ZPS Mutex Name</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the attribute '<em>ZPS Mutex Name</em>'.
	 * @see com.jennic.ZPSConfiguration.Node#getZPSMutexName()
	 * @see #getNode()
	 * @generated
	 */
	EAttribute getNode_ZPSMutexName();

	/**
	 * Returns the meta object for the attribute '{@link com.jennic.ZPSConfiguration.Node#getFragmentationMaxNumSimulRx <em>Fragmentation Max Num Simul Rx</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the attribute '<em>Fragmentation Max Num Simul Rx</em>'.
	 * @see com.jennic.ZPSConfiguration.Node#getFragmentationMaxNumSimulRx()
	 * @see #getNode()
	 * @generated
	 */
	EAttribute getNode_FragmentationMaxNumSimulRx();

	/**
	 * Returns the meta object for the attribute '{@link com.jennic.ZPSConfiguration.Node#getFragmentationMaxNumSimulTx <em>Fragmentation Max Num Simul Tx</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the attribute '<em>Fragmentation Max Num Simul Tx</em>'.
	 * @see com.jennic.ZPSConfiguration.Node#getFragmentationMaxNumSimulTx()
	 * @see #getNode()
	 * @generated
	 */
	EAttribute getNode_FragmentationMaxNumSimulTx();

	/**
	 * Returns the meta object for the attribute '{@link com.jennic.ZPSConfiguration.Node#getDefaultEventMessageName <em>Default Event Message Name</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the attribute '<em>Default Event Message Name</em>'.
	 * @see com.jennic.ZPSConfiguration.Node#getDefaultEventMessageName()
	 * @see #getNode()
	 * @generated
	 */
	EAttribute getNode_DefaultEventMessageName();

	/**
	 * Returns the meta object for the attribute '{@link com.jennic.ZPSConfiguration.Node#getMACDcfmIndMessage <em>MAC Dcfm Ind Message</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the attribute '<em>MAC Dcfm Ind Message</em>'.
	 * @see com.jennic.ZPSConfiguration.Node#getMACDcfmIndMessage()
	 * @see #getNode()
	 * @generated
	 */
	EAttribute getNode_MACDcfmIndMessage();

	/**
	 * Returns the meta object for the attribute '{@link com.jennic.ZPSConfiguration.Node#getMACTimeEventMessage <em>MAC Time Event Message</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the attribute '<em>MAC Time Event Message</em>'.
	 * @see com.jennic.ZPSConfiguration.Node#getMACTimeEventMessage()
	 * @see #getNode()
	 * @generated
	 */
	EAttribute getNode_MACTimeEventMessage();

	/**
	 * Returns the meta object for the attribute '{@link com.jennic.ZPSConfiguration.Node#getApsNonMemberRadius <em>Aps Non Member Radius</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the attribute '<em>Aps Non Member Radius</em>'.
	 * @see com.jennic.ZPSConfiguration.Node#getApsNonMemberRadius()
	 * @see #getNode()
	 * @generated
	 */
	EAttribute getNode_ApsNonMemberRadius();

	/**
	 * Returns the meta object for the attribute '{@link com.jennic.ZPSConfiguration.Node#isApsDesignatedCoordinator <em>Aps Designated Coordinator</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the attribute '<em>Aps Designated Coordinator</em>'.
	 * @see com.jennic.ZPSConfiguration.Node#isApsDesignatedCoordinator()
	 * @see #getNode()
	 * @generated
	 */
	EAttribute getNode_ApsDesignatedCoordinator();

	/**
	 * Returns the meta object for the attribute '{@link com.jennic.ZPSConfiguration.Node#isApsUseInsecureJoin <em>Aps Use Insecure Join</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the attribute '<em>Aps Use Insecure Join</em>'.
	 * @see com.jennic.ZPSConfiguration.Node#isApsUseInsecureJoin()
	 * @see #getNode()
	 * @generated
	 */
	EAttribute getNode_ApsUseInsecureJoin();

	/**
	 * Returns the meta object for the attribute '{@link com.jennic.ZPSConfiguration.Node#getApsMaxWindowSize <em>Aps Max Window Size</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the attribute '<em>Aps Max Window Size</em>'.
	 * @see com.jennic.ZPSConfiguration.Node#getApsMaxWindowSize()
	 * @see #getNode()
	 * @generated
	 */
	EAttribute getNode_ApsMaxWindowSize();

	/**
	 * Returns the meta object for the attribute '{@link com.jennic.ZPSConfiguration.Node#getApsInterframeDelay <em>Aps Interframe Delay</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the attribute '<em>Aps Interframe Delay</em>'.
	 * @see com.jennic.ZPSConfiguration.Node#getApsInterframeDelay()
	 * @see #getNode()
	 * @generated
	 */
	EAttribute getNode_ApsInterframeDelay();

	/**
	 * Returns the meta object for the attribute '{@link com.jennic.ZPSConfiguration.Node#getApsSecurityTimeoutPeriod <em>Aps Security Timeout Period</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the attribute '<em>Aps Security Timeout Period</em>'.
	 * @see com.jennic.ZPSConfiguration.Node#getApsSecurityTimeoutPeriod()
	 * @see #getNode()
	 * @generated
	 */
	EAttribute getNode_ApsSecurityTimeoutPeriod();

	/**
	 * Returns the meta object for the containment reference '{@link com.jennic.ZPSConfiguration.Node#getKeyDescriptorTable <em>Key Descriptor Table</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the containment reference '<em>Key Descriptor Table</em>'.
	 * @see com.jennic.ZPSConfiguration.Node#getKeyDescriptorTable()
	 * @see #getNode()
	 * @generated
	 */
	EReference getNode_KeyDescriptorTable();

	/**
	 * Returns the meta object for the attribute '{@link com.jennic.ZPSConfiguration.Node#getApsUseExtPANId <em>Aps Use Ext PAN Id</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the attribute '<em>Aps Use Ext PAN Id</em>'.
	 * @see com.jennic.ZPSConfiguration.Node#getApsUseExtPANId()
	 * @see #getNode()
	 * @generated
	 */
	EAttribute getNode_ApsUseExtPANId();

	/**
	 * Returns the meta object for the reference '{@link com.jennic.ZPSConfiguration.Node#getInitialNetworkKey <em>Initial Network Key</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the reference '<em>Initial Network Key</em>'.
	 * @see com.jennic.ZPSConfiguration.Node#getInitialNetworkKey()
	 * @see #getNode()
	 * @generated
	 */
	EReference getNode_InitialNetworkKey();

	/**
	 * Returns the meta object for the attribute '{@link com.jennic.ZPSConfiguration.Node#isSecurityEnabled <em>Security Enabled</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the attribute '<em>Security Enabled</em>'.
	 * @see com.jennic.ZPSConfiguration.Node#isSecurityEnabled()
	 * @see #getNode()
	 * @generated
	 */
	EAttribute getNode_SecurityEnabled();

	/**
	 * Returns the meta object for the attribute '{@link com.jennic.ZPSConfiguration.Node#getMACMlmeDcfmIndMessage <em>MAC Mlme Dcfm Ind Message</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the attribute '<em>MAC Mlme Dcfm Ind Message</em>'.
	 * @see com.jennic.ZPSConfiguration.Node#getMACMlmeDcfmIndMessage()
	 * @see #getNode()
	 * @generated
	 */
	EAttribute getNode_MACMlmeDcfmIndMessage();

	/**
	 * Returns the meta object for the attribute '{@link com.jennic.ZPSConfiguration.Node#getMACMcpsDcfmIndMessage <em>MAC Mcps Dcfm Ind Message</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the attribute '<em>MAC Mcps Dcfm Ind Message</em>'.
	 * @see com.jennic.ZPSConfiguration.Node#getMACMcpsDcfmIndMessage()
	 * @see #getNode()
	 * @generated
	 */
	EAttribute getNode_MACMcpsDcfmIndMessage();

	/**
	 * Returns the meta object for the attribute '{@link com.jennic.ZPSConfiguration.Node#getAPSPersistenceTime <em>APS Persistence Time</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the attribute '<em>APS Persistence Time</em>'.
	 * @see com.jennic.ZPSConfiguration.Node#getAPSPersistenceTime()
	 * @see #getNode()
	 * @generated
	 */
	EAttribute getNode_APSPersistenceTime();

	/**
	 * Returns the meta object for the attribute '{@link com.jennic.ZPSConfiguration.Node#getNumAPSMESimulCommands <em>Num APSME Simul Commands</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the attribute '<em>Num APSME Simul Commands</em>'.
	 * @see com.jennic.ZPSConfiguration.Node#getNumAPSMESimulCommands()
	 * @see #getNode()
	 * @generated
	 */
	EAttribute getNode_NumAPSMESimulCommands();

	/**
	 * Returns the meta object for the attribute '{@link com.jennic.ZPSConfiguration.Node#getStackProfile <em>Stack Profile</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the attribute '<em>Stack Profile</em>'.
	 * @see com.jennic.ZPSConfiguration.Node#getStackProfile()
	 * @see #getNode()
	 * @generated
	 */
	EAttribute getNode_StackProfile();

	/**
	 * Returns the meta object for the attribute '{@link com.jennic.ZPSConfiguration.Node#isInterPAN <em>Inter PAN</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the attribute '<em>Inter PAN</em>'.
	 * @see com.jennic.ZPSConfiguration.Node#isInterPAN()
	 * @see #getNode()
	 * @generated
	 */
	EAttribute getNode_InterPAN();

	/**
	 * Returns the meta object for the attribute '{@link com.jennic.ZPSConfiguration.Node#isGreenPowerSupport <em>Green Power Support</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the attribute '<em>Green Power Support</em>'.
	 * @see com.jennic.ZPSConfiguration.Node#isGreenPowerSupport()
	 * @see #getNode()
	 * @generated
	 */
	EAttribute getNode_GreenPowerSupport();

	/**
	 * Returns the meta object for the attribute '{@link com.jennic.ZPSConfiguration.Node#getNwkFcSaveCountBitShift <em>Nwk Fc Save Count Bit Shift</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the attribute '<em>Nwk Fc Save Count Bit Shift</em>'.
	 * @see com.jennic.ZPSConfiguration.Node#getNwkFcSaveCountBitShift()
	 * @see #getNode()
	 * @generated
	 */
	EAttribute getNode_NwkFcSaveCountBitShift();

	/**
	 * Returns the meta object for the attribute '{@link com.jennic.ZPSConfiguration.Node#getApsFcSaveCountBitShift <em>Aps Fc Save Count Bit Shift</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the attribute '<em>Aps Fc Save Count Bit Shift</em>'.
	 * @see com.jennic.ZPSConfiguration.Node#getApsFcSaveCountBitShift()
	 * @see #getNode()
	 * @generated
	 */
	EAttribute getNode_ApsFcSaveCountBitShift();

	/**
	 * Returns the meta object for the attribute '{@link com.jennic.ZPSConfiguration.Node#getMacTableSize <em>Mac Table Size</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the attribute '<em>Mac Table Size</em>'.
	 * @see com.jennic.ZPSConfiguration.Node#getMacTableSize()
	 * @see #getNode()
	 * @generated
	 */
	EAttribute getNode_MacTableSize();

	/**
	 * Returns the meta object for the attribute '{@link com.jennic.ZPSConfiguration.Node#getDefaultCallbackName <em>Default Callback Name</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the attribute '<em>Default Callback Name</em>'.
	 * @see com.jennic.ZPSConfiguration.Node#getDefaultCallbackName()
	 * @see #getNode()
	 * @generated
	 */
	EAttribute getNode_DefaultCallbackName();

	/**
	 * Returns the meta object for the containment reference '{@link com.jennic.ZPSConfiguration.Node#getMacInterfaceList <em>Mac Interface List</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the containment reference '<em>Mac Interface List</em>'.
	 * @see com.jennic.ZPSConfiguration.Node#getMacInterfaceList()
	 * @see #getNode()
	 * @generated
	 */
	EReference getNode_MacInterfaceList();

	/**
	 * Returns the meta object for the containment reference '{@link com.jennic.ZPSConfiguration.Node#getGreenPowerTxQueue <em>Green Power Tx Queue</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the containment reference '<em>Green Power Tx Queue</em>'.
	 * @see com.jennic.ZPSConfiguration.Node#getGreenPowerTxQueue()
	 * @see #getNode()
	 * @generated
	 */
	EReference getNode_GreenPowerTxQueue();

	/**
	 * Returns the meta object for the containment reference '{@link com.jennic.ZPSConfiguration.Node#getGreenPowerSecurityTable <em>Green Power Security Table</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the containment reference '<em>Green Power Security Table</em>'.
	 * @see com.jennic.ZPSConfiguration.Node#getGreenPowerSecurityTable()
	 * @see #getNode()
	 * @generated
	 */
	EReference getNode_GreenPowerSecurityTable();

	/**
	 * Returns the meta object for the attribute '{@link com.jennic.ZPSConfiguration.Node#getAPSDuplicateTableSize <em>APS Duplicate Table Size</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the attribute '<em>APS Duplicate Table Size</em>'.
	 * @see com.jennic.ZPSConfiguration.Node#getAPSDuplicateTableSize()
	 * @see #getNode()
	 * @generated
	 */
	EAttribute getNode_APSDuplicateTableSize();

	/**
	 * Returns the meta object for class '{@link com.jennic.ZPSConfiguration.Coordinator <em>Coordinator</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for class '<em>Coordinator</em>'.
	 * @see com.jennic.ZPSConfiguration.Coordinator
	 * @generated
	 */
	EClass getCoordinator();

	/**
	 * Returns the meta object for the containment reference '{@link com.jennic.ZPSConfiguration.Coordinator#getZDOServers <em>ZDO Servers</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the containment reference '<em>ZDO Servers</em>'.
	 * @see com.jennic.ZPSConfiguration.Coordinator#getZDOServers()
	 * @see #getCoordinator()
	 * @generated
	 */
	EReference getCoordinator_ZDOServers();

	/**
	 * Returns the meta object for class '{@link com.jennic.ZPSConfiguration.Router <em>Router</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for class '<em>Router</em>'.
	 * @see com.jennic.ZPSConfiguration.Router
	 * @generated
	 */
	EClass getRouter();

	/**
	 * Returns the meta object for the containment reference '{@link com.jennic.ZPSConfiguration.Router#getZDOServers <em>ZDO Servers</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the containment reference '<em>ZDO Servers</em>'.
	 * @see com.jennic.ZPSConfiguration.Router#getZDOServers()
	 * @see #getRouter()
	 * @generated
	 */
	EReference getRouter_ZDOServers();

	/**
	 * Returns the meta object for class '{@link com.jennic.ZPSConfiguration.EndDevice <em>End Device</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for class '<em>End Device</em>'.
	 * @see com.jennic.ZPSConfiguration.EndDevice
	 * @generated
	 */
	EClass getEndDevice();

	/**
	 * Returns the meta object for the containment reference '{@link com.jennic.ZPSConfiguration.EndDevice#getZDOServers <em>ZDO Servers</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the containment reference '<em>ZDO Servers</em>'.
	 * @see com.jennic.ZPSConfiguration.EndDevice#getZDOServers()
	 * @see #getEndDevice()
	 * @generated
	 */
	EReference getEndDevice_ZDOServers();

	/**
	 * Returns the meta object for the attribute '{@link com.jennic.ZPSConfiguration.EndDevice#getNumPollFailuresBeforeRejoin <em>Num Poll Failures Before Rejoin</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the attribute '<em>Num Poll Failures Before Rejoin</em>'.
	 * @see com.jennic.ZPSConfiguration.EndDevice#getNumPollFailuresBeforeRejoin()
	 * @see #getEndDevice()
	 * @generated
	 */
	EAttribute getEndDevice_NumPollFailuresBeforeRejoin();

	/**
	 * Returns the meta object for the attribute '{@link com.jennic.ZPSConfiguration.EndDevice#isSleeping <em>Sleeping</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the attribute '<em>Sleeping</em>'.
	 * @see com.jennic.ZPSConfiguration.EndDevice#isSleeping()
	 * @see #getEndDevice()
	 * @generated
	 */
	EAttribute getEndDevice_Sleeping();

	/**
	 * Returns the meta object for the attribute '{@link com.jennic.ZPSConfiguration.EndDevice#getFragmentedTxPollPeriod <em>Fragmented Tx Poll Period</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the attribute '<em>Fragmented Tx Poll Period</em>'.
	 * @see com.jennic.ZPSConfiguration.EndDevice#getFragmentedTxPollPeriod()
	 * @see #getEndDevice()
	 * @generated
	 */
	EAttribute getEndDevice_FragmentedTxPollPeriod();

	/**
	 * Returns the meta object for the attribute '{@link com.jennic.ZPSConfiguration.EndDevice#getFragmentedRxPollPeriod <em>Fragmented Rx Poll Period</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the attribute '<em>Fragmented Rx Poll Period</em>'.
	 * @see com.jennic.ZPSConfiguration.EndDevice#getFragmentedRxPollPeriod()
	 * @see #getEndDevice()
	 * @generated
	 */
	EAttribute getEndDevice_FragmentedRxPollPeriod();

	/**
	 * Returns the meta object for the attribute '{@link com.jennic.ZPSConfiguration.EndDevice#getAPSPollPeriod <em>APS Poll Period</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the attribute '<em>APS Poll Period</em>'.
	 * @see com.jennic.ZPSConfiguration.EndDevice#getAPSPollPeriod()
	 * @see #getEndDevice()
	 * @generated
	 */
	EAttribute getEndDevice_APSPollPeriod();

	/**
	 * Returns the meta object for class '{@link com.jennic.ZPSConfiguration.EndPoint <em>End Point</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for class '<em>End Point</em>'.
	 * @see com.jennic.ZPSConfiguration.EndPoint
	 * @generated
	 */
	EClass getEndPoint();

	/**
	 * Returns the meta object for the containment reference list '{@link com.jennic.ZPSConfiguration.EndPoint#getInputClusters <em>Input Clusters</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the containment reference list '<em>Input Clusters</em>'.
	 * @see com.jennic.ZPSConfiguration.EndPoint#getInputClusters()
	 * @see #getEndPoint()
	 * @generated
	 */
	EReference getEndPoint_InputClusters();

	/**
	 * Returns the meta object for the containment reference list '{@link com.jennic.ZPSConfiguration.EndPoint#getOutputClusters <em>Output Clusters</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the containment reference list '<em>Output Clusters</em>'.
	 * @see com.jennic.ZPSConfiguration.EndPoint#getOutputClusters()
	 * @see #getEndPoint()
	 * @generated
	 */
	EReference getEndPoint_OutputClusters();

	/**
	 * Returns the meta object for the attribute '{@link com.jennic.ZPSConfiguration.EndPoint#getId <em>Id</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the attribute '<em>Id</em>'.
	 * @see com.jennic.ZPSConfiguration.EndPoint#getId()
	 * @see #getEndPoint()
	 * @generated
	 */
	EAttribute getEndPoint_Id();

	/**
	 * Returns the meta object for the attribute '{@link com.jennic.ZPSConfiguration.EndPoint#isEnabled <em>Enabled</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the attribute '<em>Enabled</em>'.
	 * @see com.jennic.ZPSConfiguration.EndPoint#isEnabled()
	 * @see #getEndPoint()
	 * @generated
	 */
	EAttribute getEndPoint_Enabled();

	/**
	 * Returns the meta object for the attribute '{@link com.jennic.ZPSConfiguration.EndPoint#getApplicationDeviceId <em>Application Device Id</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the attribute '<em>Application Device Id</em>'.
	 * @see com.jennic.ZPSConfiguration.EndPoint#getApplicationDeviceId()
	 * @see #getEndPoint()
	 * @generated
	 */
	EAttribute getEndPoint_ApplicationDeviceId();

	/**
	 * Returns the meta object for the attribute '{@link com.jennic.ZPSConfiguration.EndPoint#getApplicationDeviceVersion <em>Application Device Version</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the attribute '<em>Application Device Version</em>'.
	 * @see com.jennic.ZPSConfiguration.EndPoint#getApplicationDeviceVersion()
	 * @see #getEndPoint()
	 * @generated
	 */
	EAttribute getEndPoint_ApplicationDeviceVersion();

	/**
	 * Returns the meta object for the reference '{@link com.jennic.ZPSConfiguration.EndPoint#getProfile <em>Profile</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the reference '<em>Profile</em>'.
	 * @see com.jennic.ZPSConfiguration.EndPoint#getProfile()
	 * @see #getEndPoint()
	 * @generated
	 */
	EReference getEndPoint_Profile();

	/**
	 * Returns the meta object for the attribute '{@link com.jennic.ZPSConfiguration.EndPoint#getMessage <em>Message</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the attribute '<em>Message</em>'.
	 * @see com.jennic.ZPSConfiguration.EndPoint#getMessage()
	 * @see #getEndPoint()
	 * @generated
	 */
	EAttribute getEndPoint_Message();

	/**
	 * Returns the meta object for the container reference '{@link com.jennic.ZPSConfiguration.EndPoint#getNode <em>Node</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the container reference '<em>Node</em>'.
	 * @see com.jennic.ZPSConfiguration.EndPoint#getNode()
	 * @see #getEndPoint()
	 * @generated
	 */
	EReference getEndPoint_Node();

	/**
	 * Returns the meta object for the attribute '{@link com.jennic.ZPSConfiguration.EndPoint#getName <em>Name</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the attribute '<em>Name</em>'.
	 * @see com.jennic.ZPSConfiguration.EndPoint#getName()
	 * @see #getEndPoint()
	 * @generated
	 */
	EAttribute getEndPoint_Name();

	/**
	 * Returns the meta object for class '{@link com.jennic.ZPSConfiguration.PrimaryDiscoveryCache <em>Primary Discovery Cache</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for class '<em>Primary Discovery Cache</em>'.
	 * @see com.jennic.ZPSConfiguration.PrimaryDiscoveryCache
	 * @generated
	 */
	EClass getPrimaryDiscoveryCache();

	/**
	 * Returns the meta object for the attribute '{@link com.jennic.ZPSConfiguration.PrimaryDiscoveryCache#getSize <em>Size</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the attribute '<em>Size</em>'.
	 * @see com.jennic.ZPSConfiguration.PrimaryDiscoveryCache#getSize()
	 * @see #getPrimaryDiscoveryCache()
	 * @generated
	 */
	EAttribute getPrimaryDiscoveryCache_Size();

	/**
	 * Returns the meta object for class '{@link com.jennic.ZPSConfiguration.BackupDiscoveryCache <em>Backup Discovery Cache</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for class '<em>Backup Discovery Cache</em>'.
	 * @see com.jennic.ZPSConfiguration.BackupDiscoveryCache
	 * @generated
	 */
	EClass getBackupDiscoveryCache();

	/**
	 * Returns the meta object for the attribute '{@link com.jennic.ZPSConfiguration.BackupDiscoveryCache#getSize <em>Size</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the attribute '<em>Size</em>'.
	 * @see com.jennic.ZPSConfiguration.BackupDiscoveryCache#getSize()
	 * @see #getBackupDiscoveryCache()
	 * @generated
	 */
	EAttribute getBackupDiscoveryCache_Size();

	/**
	 * Returns the meta object for class '{@link com.jennic.ZPSConfiguration.DiscoveryTable <em>Discovery Table</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for class '<em>Discovery Table</em>'.
	 * @see com.jennic.ZPSConfiguration.DiscoveryTable
	 * @generated
	 */
	EClass getDiscoveryTable();

	/**
	 * Returns the meta object for the attribute '{@link com.jennic.ZPSConfiguration.DiscoveryTable#getSize <em>Size</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the attribute '<em>Size</em>'.
	 * @see com.jennic.ZPSConfiguration.DiscoveryTable#getSize()
	 * @see #getDiscoveryTable()
	 * @generated
	 */
	EAttribute getDiscoveryTable_Size();

	/**
	 * Returns the meta object for class '{@link com.jennic.ZPSConfiguration.BindingTable <em>Binding Table</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for class '<em>Binding Table</em>'.
	 * @see com.jennic.ZPSConfiguration.BindingTable
	 * @generated
	 */
	EClass getBindingTable();

	/**
	 * Returns the meta object for the attribute '{@link com.jennic.ZPSConfiguration.BindingTable#getSize <em>Size</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the attribute '<em>Size</em>'.
	 * @see com.jennic.ZPSConfiguration.BindingTable#getSize()
	 * @see #getBindingTable()
	 * @generated
	 */
	EAttribute getBindingTable_Size();

	/**
	 * Returns the meta object for class '{@link com.jennic.ZPSConfiguration.GroupTable <em>Group Table</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for class '<em>Group Table</em>'.
	 * @see com.jennic.ZPSConfiguration.GroupTable
	 * @generated
	 */
	EClass getGroupTable();

	/**
	 * Returns the meta object for the attribute '{@link com.jennic.ZPSConfiguration.GroupTable#getSize <em>Size</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the attribute '<em>Size</em>'.
	 * @see com.jennic.ZPSConfiguration.GroupTable#getSize()
	 * @see #getGroupTable()
	 * @generated
	 */
	EAttribute getGroupTable_Size();

	/**
	 * Returns the meta object for class '{@link com.jennic.ZPSConfiguration.ZigbeeWirelessNetwork <em>Zigbee Wireless Network</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for class '<em>Zigbee Wireless Network</em>'.
	 * @see com.jennic.ZPSConfiguration.ZigbeeWirelessNetwork
	 * @generated
	 */
	EClass getZigbeeWirelessNetwork();

	/**
	 * Returns the meta object for the containment reference list '{@link com.jennic.ZPSConfiguration.ZigbeeWirelessNetwork#getProfiles <em>Profiles</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the containment reference list '<em>Profiles</em>'.
	 * @see com.jennic.ZPSConfiguration.ZigbeeWirelessNetwork#getProfiles()
	 * @see #getZigbeeWirelessNetwork()
	 * @generated
	 */
	EReference getZigbeeWirelessNetwork_Profiles();

	/**
	 * Returns the meta object for the containment reference '{@link com.jennic.ZPSConfiguration.ZigbeeWirelessNetwork#getCoordinator <em>Coordinator</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the containment reference '<em>Coordinator</em>'.
	 * @see com.jennic.ZPSConfiguration.ZigbeeWirelessNetwork#getCoordinator()
	 * @see #getZigbeeWirelessNetwork()
	 * @generated
	 */
	EReference getZigbeeWirelessNetwork_Coordinator();

	/**
	 * Returns the meta object for the containment reference list '{@link com.jennic.ZPSConfiguration.ZigbeeWirelessNetwork#getChildNodes <em>Child Nodes</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the containment reference list '<em>Child Nodes</em>'.
	 * @see com.jennic.ZPSConfiguration.ZigbeeWirelessNetwork#getChildNodes()
	 * @see #getZigbeeWirelessNetwork()
	 * @generated
	 */
	EReference getZigbeeWirelessNetwork_ChildNodes();

	/**
	 * Returns the meta object for the attribute '{@link com.jennic.ZPSConfiguration.ZigbeeWirelessNetwork#getDefaultExtendedPANId <em>Default Extended PAN Id</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the attribute '<em>Default Extended PAN Id</em>'.
	 * @see com.jennic.ZPSConfiguration.ZigbeeWirelessNetwork#getDefaultExtendedPANId()
	 * @see #getZigbeeWirelessNetwork()
	 * @generated
	 */
	EAttribute getZigbeeWirelessNetwork_DefaultExtendedPANId();

	/**
	 * Returns the meta object for the attribute '{@link com.jennic.ZPSConfiguration.ZigbeeWirelessNetwork#getMaxNumberNodes <em>Max Number Nodes</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the attribute '<em>Max Number Nodes</em>'.
	 * @see com.jennic.ZPSConfiguration.ZigbeeWirelessNetwork#getMaxNumberNodes()
	 * @see #getZigbeeWirelessNetwork()
	 * @generated
	 */
	EAttribute getZigbeeWirelessNetwork_MaxNumberNodes();

	/**
	 * Returns the meta object for the attribute '{@link com.jennic.ZPSConfiguration.ZigbeeWirelessNetwork#getVersion <em>Version</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the attribute '<em>Version</em>'.
	 * @see com.jennic.ZPSConfiguration.ZigbeeWirelessNetwork#getVersion()
	 * @see #getZigbeeWirelessNetwork()
	 * @generated
	 */
	EAttribute getZigbeeWirelessNetwork_Version();

	/**
	 * Returns the meta object for the attribute '{@link com.jennic.ZPSConfiguration.ZigbeeWirelessNetwork#isDefaultSecurityEnabled <em>Default Security Enabled</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the attribute '<em>Default Security Enabled</em>'.
	 * @see com.jennic.ZPSConfiguration.ZigbeeWirelessNetwork#isDefaultSecurityEnabled()
	 * @see #getZigbeeWirelessNetwork()
	 * @generated
	 */
	EAttribute getZigbeeWirelessNetwork_DefaultSecurityEnabled();

	/**
	 * Returns the meta object for class '{@link com.jennic.ZPSConfiguration.PrimaryBindingCache <em>Primary Binding Cache</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for class '<em>Primary Binding Cache</em>'.
	 * @see com.jennic.ZPSConfiguration.PrimaryBindingCache
	 * @generated
	 */
	EClass getPrimaryBindingCache();

	/**
	 * Returns the meta object for the attribute '{@link com.jennic.ZPSConfiguration.PrimaryBindingCache#getTableSize <em>Table Size</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the attribute '<em>Table Size</em>'.
	 * @see com.jennic.ZPSConfiguration.PrimaryBindingCache#getTableSize()
	 * @see #getPrimaryBindingCache()
	 * @generated
	 */
	EAttribute getPrimaryBindingCache_TableSize();

	/**
	 * Returns the meta object for the attribute '{@link com.jennic.ZPSConfiguration.PrimaryBindingCache#getNumTables <em>Num Tables</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the attribute '<em>Num Tables</em>'.
	 * @see com.jennic.ZPSConfiguration.PrimaryBindingCache#getNumTables()
	 * @see #getPrimaryBindingCache()
	 * @generated
	 */
	EAttribute getPrimaryBindingCache_NumTables();

	/**
	 * Returns the meta object for class '{@link com.jennic.ZPSConfiguration.BackupBindingCache <em>Backup Binding Cache</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for class '<em>Backup Binding Cache</em>'.
	 * @see com.jennic.ZPSConfiguration.BackupBindingCache
	 * @generated
	 */
	EClass getBackupBindingCache();

	/**
	 * Returns the meta object for the attribute '{@link com.jennic.ZPSConfiguration.BackupBindingCache#getTableSize <em>Table Size</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the attribute '<em>Table Size</em>'.
	 * @see com.jennic.ZPSConfiguration.BackupBindingCache#getTableSize()
	 * @see #getBackupBindingCache()
	 * @generated
	 */
	EAttribute getBackupBindingCache_TableSize();

	/**
	 * Returns the meta object for the attribute '{@link com.jennic.ZPSConfiguration.BackupBindingCache#getNumTables <em>Num Tables</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the attribute '<em>Num Tables</em>'.
	 * @see com.jennic.ZPSConfiguration.BackupBindingCache#getNumTables()
	 * @see #getBackupBindingCache()
	 * @generated
	 */
	EAttribute getBackupBindingCache_NumTables();

	/**
	 * Returns the meta object for class '{@link com.jennic.ZPSConfiguration.PrimaryGroupCache <em>Primary Group Cache</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for class '<em>Primary Group Cache</em>'.
	 * @see com.jennic.ZPSConfiguration.PrimaryGroupCache
	 * @generated
	 */
	EClass getPrimaryGroupCache();

	/**
	 * Returns the meta object for the attribute '{@link com.jennic.ZPSConfiguration.PrimaryGroupCache#getSize <em>Size</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the attribute '<em>Size</em>'.
	 * @see com.jennic.ZPSConfiguration.PrimaryGroupCache#getSize()
	 * @see #getPrimaryGroupCache()
	 * @generated
	 */
	EAttribute getPrimaryGroupCache_Size();

	/**
	 * Returns the meta object for class '{@link com.jennic.ZPSConfiguration.BackupGroupCache <em>Backup Group Cache</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for class '<em>Backup Group Cache</em>'.
	 * @see com.jennic.ZPSConfiguration.BackupGroupCache
	 * @generated
	 */
	EClass getBackupGroupCache();

	/**
	 * Returns the meta object for the attribute '{@link com.jennic.ZPSConfiguration.BackupGroupCache#getSize <em>Size</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the attribute '<em>Size</em>'.
	 * @see com.jennic.ZPSConfiguration.BackupGroupCache#getSize()
	 * @see #getBackupGroupCache()
	 * @generated
	 */
	EAttribute getBackupGroupCache_Size();

	/**
	 * Returns the meta object for class '{@link com.jennic.ZPSConfiguration.InputCluster <em>Input Cluster</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for class '<em>Input Cluster</em>'.
	 * @see com.jennic.ZPSConfiguration.InputCluster
	 * @generated
	 */
	EClass getInputCluster();

	/**
	 * Returns the meta object for the reference '{@link com.jennic.ZPSConfiguration.InputCluster#getCluster <em>Cluster</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the reference '<em>Cluster</em>'.
	 * @see com.jennic.ZPSConfiguration.InputCluster#getCluster()
	 * @see #getInputCluster()
	 * @generated
	 */
	EReference getInputCluster_Cluster();

	/**
	 * Returns the meta object for the reference '{@link com.jennic.ZPSConfiguration.InputCluster#getRxAPDU <em>Rx APDU</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the reference '<em>Rx APDU</em>'.
	 * @see com.jennic.ZPSConfiguration.InputCluster#getRxAPDU()
	 * @see #getInputCluster()
	 * @generated
	 */
	EReference getInputCluster_RxAPDU();

	/**
	 * Returns the meta object for the container reference '{@link com.jennic.ZPSConfiguration.InputCluster#getEndPoint <em>End Point</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the container reference '<em>End Point</em>'.
	 * @see com.jennic.ZPSConfiguration.InputCluster#getEndPoint()
	 * @see #getInputCluster()
	 * @generated
	 */
	EReference getInputCluster_EndPoint();

	/**
	 * Returns the meta object for the attribute '{@link com.jennic.ZPSConfiguration.InputCluster#isDiscoverable <em>Discoverable</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the attribute '<em>Discoverable</em>'.
	 * @see com.jennic.ZPSConfiguration.InputCluster#isDiscoverable()
	 * @see #getInputCluster()
	 * @generated
	 */
	EAttribute getInputCluster_Discoverable();

	/**
	 * Returns the meta object for class '{@link com.jennic.ZPSConfiguration.OutputCluster <em>Output Cluster</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for class '<em>Output Cluster</em>'.
	 * @see com.jennic.ZPSConfiguration.OutputCluster
	 * @generated
	 */
	EClass getOutputCluster();

	/**
	 * Returns the meta object for the reference '{@link com.jennic.ZPSConfiguration.OutputCluster#getCluster <em>Cluster</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the reference '<em>Cluster</em>'.
	 * @see com.jennic.ZPSConfiguration.OutputCluster#getCluster()
	 * @see #getOutputCluster()
	 * @generated
	 */
	EReference getOutputCluster_Cluster();

	/**
	 * Returns the meta object for the container reference '{@link com.jennic.ZPSConfiguration.OutputCluster#getEndPoint <em>End Point</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the container reference '<em>End Point</em>'.
	 * @see com.jennic.ZPSConfiguration.OutputCluster#getEndPoint()
	 * @see #getOutputCluster()
	 * @generated
	 */
	EReference getOutputCluster_EndPoint();

	/**
	 * Returns the meta object for the reference list '{@link com.jennic.ZPSConfiguration.OutputCluster#getTxAPDUs <em>Tx APD Us</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the reference list '<em>Tx APD Us</em>'.
	 * @see com.jennic.ZPSConfiguration.OutputCluster#getTxAPDUs()
	 * @see #getOutputCluster()
	 * @generated
	 */
	EReference getOutputCluster_TxAPDUs();

	/**
	 * Returns the meta object for the attribute '{@link com.jennic.ZPSConfiguration.OutputCluster#isDiscoverable <em>Discoverable</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the attribute '<em>Discoverable</em>'.
	 * @see com.jennic.ZPSConfiguration.OutputCluster#isDiscoverable()
	 * @see #getOutputCluster()
	 * @generated
	 */
	EAttribute getOutputCluster_Discoverable();

	/**
	 * Returns the meta object for class '{@link com.jennic.ZPSConfiguration.AlwaysOnNode <em>Always On Node</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for class '<em>Always On Node</em>'.
	 * @see com.jennic.ZPSConfiguration.AlwaysOnNode
	 * @generated
	 */
	EClass getAlwaysOnNode();

	/**
	 * Returns the meta object for the containment reference '{@link com.jennic.ZPSConfiguration.AlwaysOnNode#getTrustCenter <em>Trust Center</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the containment reference '<em>Trust Center</em>'.
	 * @see com.jennic.ZPSConfiguration.AlwaysOnNode#getTrustCenter()
	 * @see #getAlwaysOnNode()
	 * @generated
	 */
	EReference getAlwaysOnNode_TrustCenter();

	/**
	 * Returns the meta object for the attribute '{@link com.jennic.ZPSConfiguration.AlwaysOnNode#getPermitJoiningTime <em>Permit Joining Time</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the attribute '<em>Permit Joining Time</em>'.
	 * @see com.jennic.ZPSConfiguration.AlwaysOnNode#getPermitJoiningTime()
	 * @see #getAlwaysOnNode()
	 * @generated
	 */
	EAttribute getAlwaysOnNode_PermitJoiningTime();

	/**
	 * Returns the meta object for the attribute '{@link com.jennic.ZPSConfiguration.AlwaysOnNode#getChildTableSize <em>Child Table Size</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the attribute '<em>Child Table Size</em>'.
	 * @see com.jennic.ZPSConfiguration.AlwaysOnNode#getChildTableSize()
	 * @see #getAlwaysOnNode()
	 * @generated
	 */
	EAttribute getAlwaysOnNode_ChildTableSize();

	/**
	 * Returns the meta object for class '{@link com.jennic.ZPSConfiguration.ComplexDescriptor <em>Complex Descriptor</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for class '<em>Complex Descriptor</em>'.
	 * @see com.jennic.ZPSConfiguration.ComplexDescriptor
	 * @generated
	 */
	EClass getComplexDescriptor();

	/**
	 * Returns the meta object for class '{@link com.jennic.ZPSConfiguration.UserDescriptor <em>User Descriptor</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for class '<em>User Descriptor</em>'.
	 * @see com.jennic.ZPSConfiguration.UserDescriptor
	 * @generated
	 */
	EClass getUserDescriptor();

	/**
	 * Returns the meta object for the attribute '{@link com.jennic.ZPSConfiguration.UserDescriptor#getUserDescription <em>User Description</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the attribute '<em>User Description</em>'.
	 * @see com.jennic.ZPSConfiguration.UserDescriptor#getUserDescription()
	 * @see #getUserDescriptor()
	 * @generated
	 */
	EAttribute getUserDescriptor_UserDescription();

	/**
	 * Returns the meta object for class '{@link com.jennic.ZPSConfiguration.TrustCenter <em>Trust Center</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for class '<em>Trust Center</em>'.
	 * @see com.jennic.ZPSConfiguration.TrustCenter
	 * @generated
	 */
	EClass getTrustCenter();

	/**
	 * Returns the meta object for the attribute '{@link com.jennic.ZPSConfiguration.TrustCenter#getDeviceTableSize <em>Device Table Size</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the attribute '<em>Device Table Size</em>'.
	 * @see com.jennic.ZPSConfiguration.TrustCenter#getDeviceTableSize()
	 * @see #getTrustCenter()
	 * @generated
	 */
	EAttribute getTrustCenter_DeviceTableSize();

	/**
	 * Returns the meta object for the containment reference '{@link com.jennic.ZPSConfiguration.TrustCenter#getKeys <em>Keys</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the containment reference '<em>Keys</em>'.
	 * @see com.jennic.ZPSConfiguration.TrustCenter#getKeys()
	 * @see #getTrustCenter()
	 * @generated
	 */
	EReference getTrustCenter_Keys();

	/**
	 * Returns the meta object for class '{@link com.jennic.ZPSConfiguration.DiscoveryCache <em>Discovery Cache</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for class '<em>Discovery Cache</em>'.
	 * @see com.jennic.ZPSConfiguration.DiscoveryCache
	 * @generated
	 */
	EClass getDiscoveryCache();

	/**
	 * Returns the meta object for class '{@link com.jennic.ZPSConfiguration.BindingCache <em>Binding Cache</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for class '<em>Binding Cache</em>'.
	 * @see com.jennic.ZPSConfiguration.BindingCache
	 * @generated
	 */
	EClass getBindingCache();

	/**
	 * Returns the meta object for class '{@link com.jennic.ZPSConfiguration.NamedObject <em>Named Object</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for class '<em>Named Object</em>'.
	 * @see com.jennic.ZPSConfiguration.NamedObject
	 * @generated
	 */
	EClass getNamedObject();

	/**
	 * Returns the meta object for the attribute '{@link com.jennic.ZPSConfiguration.NamedObject#getName <em>Name</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the attribute '<em>Name</em>'.
	 * @see com.jennic.ZPSConfiguration.NamedObject#getName()
	 * @see #getNamedObject()
	 * @generated
	 */
	EAttribute getNamedObject_Name();

	/**
	 * Returns the meta object for class '{@link com.jennic.ZPSConfiguration.ChildNodes <em>Child Nodes</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for class '<em>Child Nodes</em>'.
	 * @see com.jennic.ZPSConfiguration.ChildNodes
	 * @generated
	 */
	EClass getChildNodes();

	/**
	 * Returns the meta object for the attribute '{@link com.jennic.ZPSConfiguration.ChildNodes#getScanDuration <em>Scan Duration</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the attribute '<em>Scan Duration</em>'.
	 * @see com.jennic.ZPSConfiguration.ChildNodes#getScanDuration()
	 * @see #getChildNodes()
	 * @generated
	 */
	EAttribute getChildNodes_ScanDuration();

	/**
	 * Returns the meta object for the attribute '{@link com.jennic.ZPSConfiguration.ChildNodes#getNetworkSelection <em>Network Selection</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the attribute '<em>Network Selection</em>'.
	 * @see com.jennic.ZPSConfiguration.ChildNodes#getNetworkSelection()
	 * @see #getChildNodes()
	 * @generated
	 */
	EAttribute getChildNodes_NetworkSelection();

	/**
	 * Returns the meta object for class '{@link com.jennic.ZPSConfiguration.APDU <em>APDU</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for class '<em>APDU</em>'.
	 * @see com.jennic.ZPSConfiguration.APDU
	 * @generated
	 */
	EClass getAPDU();

	/**
	 * Returns the meta object for the attribute '{@link com.jennic.ZPSConfiguration.APDU#getId <em>Id</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the attribute '<em>Id</em>'.
	 * @see com.jennic.ZPSConfiguration.APDU#getId()
	 * @see #getAPDU()
	 * @generated
	 */
	EAttribute getAPDU_Id();

	/**
	 * Returns the meta object for the attribute '{@link com.jennic.ZPSConfiguration.APDU#getName <em>Name</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the attribute '<em>Name</em>'.
	 * @see com.jennic.ZPSConfiguration.APDU#getName()
	 * @see #getAPDU()
	 * @generated
	 */
	EAttribute getAPDU_Name();

	/**
	 * Returns the meta object for the attribute '{@link com.jennic.ZPSConfiguration.APDU#getSize <em>Size</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the attribute '<em>Size</em>'.
	 * @see com.jennic.ZPSConfiguration.APDU#getSize()
	 * @see #getAPDU()
	 * @generated
	 */
	EAttribute getAPDU_Size();

	/**
	 * Returns the meta object for the attribute '{@link com.jennic.ZPSConfiguration.APDU#getInstances <em>Instances</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the attribute '<em>Instances</em>'.
	 * @see com.jennic.ZPSConfiguration.APDU#getInstances()
	 * @see #getAPDU()
	 * @generated
	 */
	EAttribute getAPDU_Instances();

	/**
	 * Returns the meta object for the container reference '{@link com.jennic.ZPSConfiguration.APDU#getPDUConfig <em>PDU Config</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the container reference '<em>PDU Config</em>'.
	 * @see com.jennic.ZPSConfiguration.APDU#getPDUConfig()
	 * @see #getAPDU()
	 * @generated
	 */
	EReference getAPDU_PDUConfig();

	/**
	 * Returns the meta object for class '{@link com.jennic.ZPSConfiguration.PDUManager <em>PDU Manager</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for class '<em>PDU Manager</em>'.
	 * @see com.jennic.ZPSConfiguration.PDUManager
	 * @generated
	 */
	EClass getPDUManager();

	/**
	 * Returns the meta object for the containment reference list '{@link com.jennic.ZPSConfiguration.PDUManager#getAPDUs <em>APD Us</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the containment reference list '<em>APD Us</em>'.
	 * @see com.jennic.ZPSConfiguration.PDUManager#getAPDUs()
	 * @see #getPDUManager()
	 * @generated
	 */
	EReference getPDUManager_APDUs();

	/**
	 * Returns the meta object for the container reference '{@link com.jennic.ZPSConfiguration.PDUManager#getContainerNode <em>Container Node</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the container reference '<em>Container Node</em>'.
	 * @see com.jennic.ZPSConfiguration.PDUManager#getContainerNode()
	 * @see #getPDUManager()
	 * @generated
	 */
	EReference getPDUManager_ContainerNode();

	/**
	 * Returns the meta object for the attribute '{@link com.jennic.ZPSConfiguration.PDUManager#getNumNPDUs <em>Num NPD Us</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the attribute '<em>Num NPD Us</em>'.
	 * @see com.jennic.ZPSConfiguration.PDUManager#getNumNPDUs()
	 * @see #getPDUManager()
	 * @generated
	 */
	EAttribute getPDUManager_NumNPDUs();

	/**
	 * Returns the meta object for the attribute '{@link com.jennic.ZPSConfiguration.PDUManager#getPDUMMutexName <em>PDUM Mutex Name</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the attribute '<em>PDUM Mutex Name</em>'.
	 * @see com.jennic.ZPSConfiguration.PDUManager#getPDUMMutexName()
	 * @see #getPDUManager()
	 * @generated
	 */
	EAttribute getPDUManager_PDUMMutexName();

	/**
	 * Returns the meta object for class '{@link com.jennic.ZPSConfiguration.ChannelMask <em>Channel Mask</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for class '<em>Channel Mask</em>'.
	 * @see com.jennic.ZPSConfiguration.ChannelMask
	 * @generated
	 */
	EClass getChannelMask();

	/**
	 * Returns the meta object for the attribute '{@link com.jennic.ZPSConfiguration.ChannelMask#isChannel11 <em>Channel11</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the attribute '<em>Channel11</em>'.
	 * @see com.jennic.ZPSConfiguration.ChannelMask#isChannel11()
	 * @see #getChannelMask()
	 * @generated
	 */
	EAttribute getChannelMask_Channel11();

	/**
	 * Returns the meta object for the attribute '{@link com.jennic.ZPSConfiguration.ChannelMask#isChannel12 <em>Channel12</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the attribute '<em>Channel12</em>'.
	 * @see com.jennic.ZPSConfiguration.ChannelMask#isChannel12()
	 * @see #getChannelMask()
	 * @generated
	 */
	EAttribute getChannelMask_Channel12();

	/**
	 * Returns the meta object for the attribute '{@link com.jennic.ZPSConfiguration.ChannelMask#isChannel13 <em>Channel13</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the attribute '<em>Channel13</em>'.
	 * @see com.jennic.ZPSConfiguration.ChannelMask#isChannel13()
	 * @see #getChannelMask()
	 * @generated
	 */
	EAttribute getChannelMask_Channel13();

	/**
	 * Returns the meta object for the attribute '{@link com.jennic.ZPSConfiguration.ChannelMask#isChannel14 <em>Channel14</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the attribute '<em>Channel14</em>'.
	 * @see com.jennic.ZPSConfiguration.ChannelMask#isChannel14()
	 * @see #getChannelMask()
	 * @generated
	 */
	EAttribute getChannelMask_Channel14();

	/**
	 * Returns the meta object for the attribute '{@link com.jennic.ZPSConfiguration.ChannelMask#isChannel15 <em>Channel15</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the attribute '<em>Channel15</em>'.
	 * @see com.jennic.ZPSConfiguration.ChannelMask#isChannel15()
	 * @see #getChannelMask()
	 * @generated
	 */
	EAttribute getChannelMask_Channel15();

	/**
	 * Returns the meta object for the attribute '{@link com.jennic.ZPSConfiguration.ChannelMask#isChannel16 <em>Channel16</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the attribute '<em>Channel16</em>'.
	 * @see com.jennic.ZPSConfiguration.ChannelMask#isChannel16()
	 * @see #getChannelMask()
	 * @generated
	 */
	EAttribute getChannelMask_Channel16();

	/**
	 * Returns the meta object for the attribute '{@link com.jennic.ZPSConfiguration.ChannelMask#isChannel17 <em>Channel17</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the attribute '<em>Channel17</em>'.
	 * @see com.jennic.ZPSConfiguration.ChannelMask#isChannel17()
	 * @see #getChannelMask()
	 * @generated
	 */
	EAttribute getChannelMask_Channel17();

	/**
	 * Returns the meta object for the attribute '{@link com.jennic.ZPSConfiguration.ChannelMask#isChannel18 <em>Channel18</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the attribute '<em>Channel18</em>'.
	 * @see com.jennic.ZPSConfiguration.ChannelMask#isChannel18()
	 * @see #getChannelMask()
	 * @generated
	 */
	EAttribute getChannelMask_Channel18();

	/**
	 * Returns the meta object for the attribute '{@link com.jennic.ZPSConfiguration.ChannelMask#isChannel19 <em>Channel19</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the attribute '<em>Channel19</em>'.
	 * @see com.jennic.ZPSConfiguration.ChannelMask#isChannel19()
	 * @see #getChannelMask()
	 * @generated
	 */
	EAttribute getChannelMask_Channel19();

	/**
	 * Returns the meta object for the attribute '{@link com.jennic.ZPSConfiguration.ChannelMask#isChannel20 <em>Channel20</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the attribute '<em>Channel20</em>'.
	 * @see com.jennic.ZPSConfiguration.ChannelMask#isChannel20()
	 * @see #getChannelMask()
	 * @generated
	 */
	EAttribute getChannelMask_Channel20();

	/**
	 * Returns the meta object for the attribute '{@link com.jennic.ZPSConfiguration.ChannelMask#isChannel21 <em>Channel21</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the attribute '<em>Channel21</em>'.
	 * @see com.jennic.ZPSConfiguration.ChannelMask#isChannel21()
	 * @see #getChannelMask()
	 * @generated
	 */
	EAttribute getChannelMask_Channel21();

	/**
	 * Returns the meta object for the attribute '{@link com.jennic.ZPSConfiguration.ChannelMask#isChannel22 <em>Channel22</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the attribute '<em>Channel22</em>'.
	 * @see com.jennic.ZPSConfiguration.ChannelMask#isChannel22()
	 * @see #getChannelMask()
	 * @generated
	 */
	EAttribute getChannelMask_Channel22();

	/**
	 * Returns the meta object for the attribute '{@link com.jennic.ZPSConfiguration.ChannelMask#isChannel23 <em>Channel23</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the attribute '<em>Channel23</em>'.
	 * @see com.jennic.ZPSConfiguration.ChannelMask#isChannel23()
	 * @see #getChannelMask()
	 * @generated
	 */
	EAttribute getChannelMask_Channel23();

	/**
	 * Returns the meta object for the attribute '{@link com.jennic.ZPSConfiguration.ChannelMask#isChannel24 <em>Channel24</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the attribute '<em>Channel24</em>'.
	 * @see com.jennic.ZPSConfiguration.ChannelMask#isChannel24()
	 * @see #getChannelMask()
	 * @generated
	 */
	EAttribute getChannelMask_Channel24();

	/**
	 * Returns the meta object for the attribute '{@link com.jennic.ZPSConfiguration.ChannelMask#isChannel25 <em>Channel25</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the attribute '<em>Channel25</em>'.
	 * @see com.jennic.ZPSConfiguration.ChannelMask#isChannel25()
	 * @see #getChannelMask()
	 * @generated
	 */
	EAttribute getChannelMask_Channel25();

	/**
	 * Returns the meta object for the attribute '{@link com.jennic.ZPSConfiguration.ChannelMask#isChannel26 <em>Channel26</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the attribute '<em>Channel26</em>'.
	 * @see com.jennic.ZPSConfiguration.ChannelMask#isChannel26()
	 * @see #getChannelMask()
	 * @generated
	 */
	EAttribute getChannelMask_Channel26();

	/**
	 * Returns the meta object for class '{@link com.jennic.ZPSConfiguration.ZDOClientServer <em>ZDO Client Server</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for class '<em>ZDO Client Server</em>'.
	 * @see com.jennic.ZPSConfiguration.ZDOClientServer
	 * @generated
	 */
	EClass getZDOClientServer();

	/**
	 * Returns the meta object for the reference '{@link com.jennic.ZPSConfiguration.ZDOClientServer#getOutputAPdu <em>Output APdu</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the reference '<em>Output APdu</em>'.
	 * @see com.jennic.ZPSConfiguration.ZDOClientServer#getOutputAPdu()
	 * @see #getZDOClientServer()
	 * @generated
	 */
	EReference getZDOClientServer_OutputAPdu();

	/**
	 * Returns the meta object for class '{@link com.jennic.ZPSConfiguration.ZDOServersCoordinator <em>ZDO Servers Coordinator</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for class '<em>ZDO Servers Coordinator</em>'.
	 * @see com.jennic.ZPSConfiguration.ZDOServersCoordinator
	 * @generated
	 */
	EClass getZDOServersCoordinator();

	/**
	 * Returns the meta object for the containment reference '{@link com.jennic.ZPSConfiguration.ZDOServersCoordinator#getEndDeviceBindServer <em>End Device Bind Server</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the containment reference '<em>End Device Bind Server</em>'.
	 * @see com.jennic.ZPSConfiguration.ZDOServersCoordinator#getEndDeviceBindServer()
	 * @see #getZDOServersCoordinator()
	 * @generated
	 */
	EReference getZDOServersCoordinator_EndDeviceBindServer();

	/**
	 * Returns the meta object for class '{@link com.jennic.ZPSConfiguration.EndDeviceBindServer <em>End Device Bind Server</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for class '<em>End Device Bind Server</em>'.
	 * @see com.jennic.ZPSConfiguration.EndDeviceBindServer
	 * @generated
	 */
	EClass getEndDeviceBindServer();

	/**
	 * Returns the meta object for the attribute '{@link com.jennic.ZPSConfiguration.EndDeviceBindServer#getTimeout <em>Timeout</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the attribute '<em>Timeout</em>'.
	 * @see com.jennic.ZPSConfiguration.EndDeviceBindServer#getTimeout()
	 * @see #getEndDeviceBindServer()
	 * @generated
	 */
	EAttribute getEndDeviceBindServer_Timeout();

	/**
	 * Returns the meta object for the attribute '{@link com.jennic.ZPSConfiguration.EndDeviceBindServer#getBindingTimeout <em>Binding Timeout</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the attribute '<em>Binding Timeout</em>'.
	 * @see com.jennic.ZPSConfiguration.EndDeviceBindServer#getBindingTimeout()
	 * @see #getEndDeviceBindServer()
	 * @generated
	 */
	EAttribute getEndDeviceBindServer_BindingTimeout();

	/**
	 * Returns the meta object for the attribute '{@link com.jennic.ZPSConfiguration.EndDeviceBindServer#getBindNumRetries <em>Bind Num Retries</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the attribute '<em>Bind Num Retries</em>'.
	 * @see com.jennic.ZPSConfiguration.EndDeviceBindServer#getBindNumRetries()
	 * @see #getEndDeviceBindServer()
	 * @generated
	 */
	EAttribute getEndDeviceBindServer_BindNumRetries();

	/**
	 * Returns the meta object for class '{@link com.jennic.ZPSConfiguration.ZDOServersRouter <em>ZDO Servers Router</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for class '<em>ZDO Servers Router</em>'.
	 * @see com.jennic.ZPSConfiguration.ZDOServersRouter
	 * @generated
	 */
	EClass getZDOServersRouter();

	/**
	 * Returns the meta object for class '{@link com.jennic.ZPSConfiguration.ZDOServersEndDevice <em>ZDO Servers End Device</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for class '<em>ZDO Servers End Device</em>'.
	 * @see com.jennic.ZPSConfiguration.ZDOServersEndDevice
	 * @generated
	 */
	EClass getZDOServersEndDevice();

	/**
	 * Returns the meta object for class '{@link com.jennic.ZPSConfiguration.DefaultServer <em>Default Server</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for class '<em>Default Server</em>'.
	 * @see com.jennic.ZPSConfiguration.DefaultServer
	 * @generated
	 */
	EClass getDefaultServer();

	/**
	 * Returns the meta object for class '{@link com.jennic.ZPSConfiguration.DeviceAnnceServer <em>Device Annce Server</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for class '<em>Device Annce Server</em>'.
	 * @see com.jennic.ZPSConfiguration.DeviceAnnceServer
	 * @generated
	 */
	EClass getDeviceAnnceServer();

	/**
	 * Returns the meta object for class '{@link com.jennic.ZPSConfiguration.ActiveEpServer <em>Active Ep Server</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for class '<em>Active Ep Server</em>'.
	 * @see com.jennic.ZPSConfiguration.ActiveEpServer
	 * @generated
	 */
	EClass getActiveEpServer();

	/**
	 * Returns the meta object for class '{@link com.jennic.ZPSConfiguration.NwkAddrServer <em>Nwk Addr Server</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for class '<em>Nwk Addr Server</em>'.
	 * @see com.jennic.ZPSConfiguration.NwkAddrServer
	 * @generated
	 */
	EClass getNwkAddrServer();

	/**
	 * Returns the meta object for class '{@link com.jennic.ZPSConfiguration.IeeeAddrServer <em>Ieee Addr Server</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for class '<em>Ieee Addr Server</em>'.
	 * @see com.jennic.ZPSConfiguration.IeeeAddrServer
	 * @generated
	 */
	EClass getIeeeAddrServer();

	/**
	 * Returns the meta object for class '{@link com.jennic.ZPSConfiguration.MatchDescServer <em>Match Desc Server</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for class '<em>Match Desc Server</em>'.
	 * @see com.jennic.ZPSConfiguration.MatchDescServer
	 * @generated
	 */
	EClass getMatchDescServer();

	/**
	 * Returns the meta object for class '{@link com.jennic.ZPSConfiguration.NodeDescServer <em>Node Desc Server</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for class '<em>Node Desc Server</em>'.
	 * @see com.jennic.ZPSConfiguration.NodeDescServer
	 * @generated
	 */
	EClass getNodeDescServer();

	/**
	 * Returns the meta object for class '{@link com.jennic.ZPSConfiguration.PermitJoiningServer <em>Permit Joining Server</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for class '<em>Permit Joining Server</em>'.
	 * @see com.jennic.ZPSConfiguration.PermitJoiningServer
	 * @generated
	 */
	EClass getPermitJoiningServer();

	/**
	 * Returns the meta object for class '{@link com.jennic.ZPSConfiguration.PowerDescServer <em>Power Desc Server</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for class '<em>Power Desc Server</em>'.
	 * @see com.jennic.ZPSConfiguration.PowerDescServer
	 * @generated
	 */
	EClass getPowerDescServer();

	/**
	 * Returns the meta object for class '{@link com.jennic.ZPSConfiguration.SimpleDescServer <em>Simple Desc Server</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for class '<em>Simple Desc Server</em>'.
	 * @see com.jennic.ZPSConfiguration.SimpleDescServer
	 * @generated
	 */
	EClass getSimpleDescServer();

	/**
	 * Returns the meta object for class '{@link com.jennic.ZPSConfiguration.SystemServerDiscoveryServer <em>System Server Discovery Server</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for class '<em>System Server Discovery Server</em>'.
	 * @see com.jennic.ZPSConfiguration.SystemServerDiscoveryServer
	 * @generated
	 */
	EClass getSystemServerDiscoveryServer();

	/**
	 * Returns the meta object for class '{@link com.jennic.ZPSConfiguration.MgmtLqiServer <em>Mgmt Lqi Server</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for class '<em>Mgmt Lqi Server</em>'.
	 * @see com.jennic.ZPSConfiguration.MgmtLqiServer
	 * @generated
	 */
	EClass getMgmtLqiServer();

	/**
	 * Returns the meta object for class '{@link com.jennic.ZPSConfiguration.MgmtRtgServer <em>Mgmt Rtg Server</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for class '<em>Mgmt Rtg Server</em>'.
	 * @see com.jennic.ZPSConfiguration.MgmtRtgServer
	 * @generated
	 */
	EClass getMgmtRtgServer();

	/**
	 * Returns the meta object for class '{@link com.jennic.ZPSConfiguration.MgmtLeaveServer <em>Mgmt Leave Server</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for class '<em>Mgmt Leave Server</em>'.
	 * @see com.jennic.ZPSConfiguration.MgmtLeaveServer
	 * @generated
	 */
	EClass getMgmtLeaveServer();

	/**
	 * Returns the meta object for class '{@link com.jennic.ZPSConfiguration.NodeDescriptor <em>Node Descriptor</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for class '<em>Node Descriptor</em>'.
	 * @see com.jennic.ZPSConfiguration.NodeDescriptor
	 * @generated
	 */
	EClass getNodeDescriptor();

	/**
	 * Returns the meta object for the attribute '{@link com.jennic.ZPSConfiguration.NodeDescriptor#getManufacturerCode <em>Manufacturer Code</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the attribute '<em>Manufacturer Code</em>'.
	 * @see com.jennic.ZPSConfiguration.NodeDescriptor#getManufacturerCode()
	 * @see #getNodeDescriptor()
	 * @generated
	 */
	EAttribute getNodeDescriptor_ManufacturerCode();

	/**
	 * Returns the meta object for the attribute '{@link com.jennic.ZPSConfiguration.NodeDescriptor#getLogicalType <em>Logical Type</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the attribute '<em>Logical Type</em>'.
	 * @see com.jennic.ZPSConfiguration.NodeDescriptor#getLogicalType()
	 * @see #getNodeDescriptor()
	 * @generated
	 */
	EAttribute getNodeDescriptor_LogicalType();

	/**
	 * Returns the meta object for the attribute '{@link com.jennic.ZPSConfiguration.NodeDescriptor#isComplexDescriptorAvailable <em>Complex Descriptor Available</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the attribute '<em>Complex Descriptor Available</em>'.
	 * @see com.jennic.ZPSConfiguration.NodeDescriptor#isComplexDescriptorAvailable()
	 * @see #getNodeDescriptor()
	 * @generated
	 */
	EAttribute getNodeDescriptor_ComplexDescriptorAvailable();

	/**
	 * Returns the meta object for the attribute '{@link com.jennic.ZPSConfiguration.NodeDescriptor#isUserDescriptorAvailable <em>User Descriptor Available</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the attribute '<em>User Descriptor Available</em>'.
	 * @see com.jennic.ZPSConfiguration.NodeDescriptor#isUserDescriptorAvailable()
	 * @see #getNodeDescriptor()
	 * @generated
	 */
	EAttribute getNodeDescriptor_UserDescriptorAvailable();

	/**
	 * Returns the meta object for the attribute '{@link com.jennic.ZPSConfiguration.NodeDescriptor#getAPSFlags <em>APS Flags</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the attribute '<em>APS Flags</em>'.
	 * @see com.jennic.ZPSConfiguration.NodeDescriptor#getAPSFlags()
	 * @see #getNodeDescriptor()
	 * @generated
	 */
	EAttribute getNodeDescriptor_APSFlags();

	/**
	 * Returns the meta object for the attribute '{@link com.jennic.ZPSConfiguration.NodeDescriptor#getFrequencyBand <em>Frequency Band</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the attribute '<em>Frequency Band</em>'.
	 * @see com.jennic.ZPSConfiguration.NodeDescriptor#getFrequencyBand()
	 * @see #getNodeDescriptor()
	 * @generated
	 */
	EAttribute getNodeDescriptor_FrequencyBand();

	/**
	 * Returns the meta object for the attribute '{@link com.jennic.ZPSConfiguration.NodeDescriptor#isAlternatePANCoordinator <em>Alternate PAN Coordinator</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the attribute '<em>Alternate PAN Coordinator</em>'.
	 * @see com.jennic.ZPSConfiguration.NodeDescriptor#isAlternatePANCoordinator()
	 * @see #getNodeDescriptor()
	 * @generated
	 */
	EAttribute getNodeDescriptor_AlternatePANCoordinator();

	/**
	 * Returns the meta object for the attribute '{@link com.jennic.ZPSConfiguration.NodeDescriptor#isDeviceType <em>Device Type</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the attribute '<em>Device Type</em>'.
	 * @see com.jennic.ZPSConfiguration.NodeDescriptor#isDeviceType()
	 * @see #getNodeDescriptor()
	 * @generated
	 */
	EAttribute getNodeDescriptor_DeviceType();

	/**
	 * Returns the meta object for the attribute '{@link com.jennic.ZPSConfiguration.NodeDescriptor#isPowerSource <em>Power Source</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the attribute '<em>Power Source</em>'.
	 * @see com.jennic.ZPSConfiguration.NodeDescriptor#isPowerSource()
	 * @see #getNodeDescriptor()
	 * @generated
	 */
	EAttribute getNodeDescriptor_PowerSource();

	/**
	 * Returns the meta object for the attribute '{@link com.jennic.ZPSConfiguration.NodeDescriptor#isRxOnWhenIdle <em>Rx On When Idle</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the attribute '<em>Rx On When Idle</em>'.
	 * @see com.jennic.ZPSConfiguration.NodeDescriptor#isRxOnWhenIdle()
	 * @see #getNodeDescriptor()
	 * @generated
	 */
	EAttribute getNodeDescriptor_RxOnWhenIdle();

	/**
	 * Returns the meta object for the attribute '{@link com.jennic.ZPSConfiguration.NodeDescriptor#isSecurity <em>Security</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the attribute '<em>Security</em>'.
	 * @see com.jennic.ZPSConfiguration.NodeDescriptor#isSecurity()
	 * @see #getNodeDescriptor()
	 * @generated
	 */
	EAttribute getNodeDescriptor_Security();

	/**
	 * Returns the meta object for the attribute '{@link com.jennic.ZPSConfiguration.NodeDescriptor#isAllocateAddress <em>Allocate Address</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the attribute '<em>Allocate Address</em>'.
	 * @see com.jennic.ZPSConfiguration.NodeDescriptor#isAllocateAddress()
	 * @see #getNodeDescriptor()
	 * @generated
	 */
	EAttribute getNodeDescriptor_AllocateAddress();

	/**
	 * Returns the meta object for the attribute '{@link com.jennic.ZPSConfiguration.NodeDescriptor#getMaximumBufferSize <em>Maximum Buffer Size</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the attribute '<em>Maximum Buffer Size</em>'.
	 * @see com.jennic.ZPSConfiguration.NodeDescriptor#getMaximumBufferSize()
	 * @see #getNodeDescriptor()
	 * @generated
	 */
	EAttribute getNodeDescriptor_MaximumBufferSize();

	/**
	 * Returns the meta object for the attribute '{@link com.jennic.ZPSConfiguration.NodeDescriptor#getMaximumIncomingTransferSize <em>Maximum Incoming Transfer Size</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the attribute '<em>Maximum Incoming Transfer Size</em>'.
	 * @see com.jennic.ZPSConfiguration.NodeDescriptor#getMaximumIncomingTransferSize()
	 * @see #getNodeDescriptor()
	 * @generated
	 */
	EAttribute getNodeDescriptor_MaximumIncomingTransferSize();

	/**
	 * Returns the meta object for the attribute '{@link com.jennic.ZPSConfiguration.NodeDescriptor#getMaximumOutgoingTransferSize <em>Maximum Outgoing Transfer Size</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the attribute '<em>Maximum Outgoing Transfer Size</em>'.
	 * @see com.jennic.ZPSConfiguration.NodeDescriptor#getMaximumOutgoingTransferSize()
	 * @see #getNodeDescriptor()
	 * @generated
	 */
	EAttribute getNodeDescriptor_MaximumOutgoingTransferSize();

	/**
	 * Returns the meta object for the attribute '{@link com.jennic.ZPSConfiguration.NodeDescriptor#isExtendedActiveEndpointListAvailable <em>Extended Active Endpoint List Available</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the attribute '<em>Extended Active Endpoint List Available</em>'.
	 * @see com.jennic.ZPSConfiguration.NodeDescriptor#isExtendedActiveEndpointListAvailable()
	 * @see #getNodeDescriptor()
	 * @generated
	 */
	EAttribute getNodeDescriptor_ExtendedActiveEndpointListAvailable();

	/**
	 * Returns the meta object for the attribute '{@link com.jennic.ZPSConfiguration.NodeDescriptor#isExtendedSimpleDescriptorListAvailable <em>Extended Simple Descriptor List Available</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the attribute '<em>Extended Simple Descriptor List Available</em>'.
	 * @see com.jennic.ZPSConfiguration.NodeDescriptor#isExtendedSimpleDescriptorListAvailable()
	 * @see #getNodeDescriptor()
	 * @generated
	 */
	EAttribute getNodeDescriptor_ExtendedSimpleDescriptorListAvailable();

	/**
	 * Returns the meta object for the attribute '{@link com.jennic.ZPSConfiguration.NodeDescriptor#isPrimaryTrustCenter <em>Primary Trust Center</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the attribute '<em>Primary Trust Center</em>'.
	 * @see com.jennic.ZPSConfiguration.NodeDescriptor#isPrimaryTrustCenter()
	 * @see #getNodeDescriptor()
	 * @generated
	 */
	EAttribute getNodeDescriptor_PrimaryTrustCenter();

	/**
	 * Returns the meta object for the attribute '{@link com.jennic.ZPSConfiguration.NodeDescriptor#isBackupTrustCenter <em>Backup Trust Center</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the attribute '<em>Backup Trust Center</em>'.
	 * @see com.jennic.ZPSConfiguration.NodeDescriptor#isBackupTrustCenter()
	 * @see #getNodeDescriptor()
	 * @generated
	 */
	EAttribute getNodeDescriptor_BackupTrustCenter();

	/**
	 * Returns the meta object for the attribute '{@link com.jennic.ZPSConfiguration.NodeDescriptor#isPrimaryBindingTableCache <em>Primary Binding Table Cache</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the attribute '<em>Primary Binding Table Cache</em>'.
	 * @see com.jennic.ZPSConfiguration.NodeDescriptor#isPrimaryBindingTableCache()
	 * @see #getNodeDescriptor()
	 * @generated
	 */
	EAttribute getNodeDescriptor_PrimaryBindingTableCache();

	/**
	 * Returns the meta object for the attribute '{@link com.jennic.ZPSConfiguration.NodeDescriptor#isBackupBindingTableCache <em>Backup Binding Table Cache</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the attribute '<em>Backup Binding Table Cache</em>'.
	 * @see com.jennic.ZPSConfiguration.NodeDescriptor#isBackupBindingTableCache()
	 * @see #getNodeDescriptor()
	 * @generated
	 */
	EAttribute getNodeDescriptor_BackupBindingTableCache();

	/**
	 * Returns the meta object for the attribute '{@link com.jennic.ZPSConfiguration.NodeDescriptor#isPrimaryDiscoveryCache <em>Primary Discovery Cache</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the attribute '<em>Primary Discovery Cache</em>'.
	 * @see com.jennic.ZPSConfiguration.NodeDescriptor#isPrimaryDiscoveryCache()
	 * @see #getNodeDescriptor()
	 * @generated
	 */
	EAttribute getNodeDescriptor_PrimaryDiscoveryCache();

	/**
	 * Returns the meta object for the attribute '{@link com.jennic.ZPSConfiguration.NodeDescriptor#isBackupDiscoveryCache <em>Backup Discovery Cache</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the attribute '<em>Backup Discovery Cache</em>'.
	 * @see com.jennic.ZPSConfiguration.NodeDescriptor#isBackupDiscoveryCache()
	 * @see #getNodeDescriptor()
	 * @generated
	 */
	EAttribute getNodeDescriptor_BackupDiscoveryCache();

	/**
	 * Returns the meta object for the container reference '{@link com.jennic.ZPSConfiguration.NodeDescriptor#getNode <em>Node</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the container reference '<em>Node</em>'.
	 * @see com.jennic.ZPSConfiguration.NodeDescriptor#getNode()
	 * @see #getNodeDescriptor()
	 * @generated
	 */
	EReference getNodeDescriptor_Node();

	/**
	 * Returns the meta object for the attribute '{@link com.jennic.ZPSConfiguration.NodeDescriptor#isNetworkManager <em>Network Manager</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the attribute '<em>Network Manager</em>'.
	 * @see com.jennic.ZPSConfiguration.NodeDescriptor#isNetworkManager()
	 * @see #getNodeDescriptor()
	 * @generated
	 */
	EAttribute getNodeDescriptor_NetworkManager();

	/**
	 * Returns the meta object for class '{@link com.jennic.ZPSConfiguration.NodePowerDescriptor <em>Node Power Descriptor</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for class '<em>Node Power Descriptor</em>'.
	 * @see com.jennic.ZPSConfiguration.NodePowerDescriptor
	 * @generated
	 */
	EClass getNodePowerDescriptor();

	/**
	 * Returns the meta object for the attribute '{@link com.jennic.ZPSConfiguration.NodePowerDescriptor#isConstantPower <em>Constant Power</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the attribute '<em>Constant Power</em>'.
	 * @see com.jennic.ZPSConfiguration.NodePowerDescriptor#isConstantPower()
	 * @see #getNodePowerDescriptor()
	 * @generated
	 */
	EAttribute getNodePowerDescriptor_ConstantPower();

	/**
	 * Returns the meta object for the attribute '{@link com.jennic.ZPSConfiguration.NodePowerDescriptor#isRechargeableBattery <em>Rechargeable Battery</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the attribute '<em>Rechargeable Battery</em>'.
	 * @see com.jennic.ZPSConfiguration.NodePowerDescriptor#isRechargeableBattery()
	 * @see #getNodePowerDescriptor()
	 * @generated
	 */
	EAttribute getNodePowerDescriptor_RechargeableBattery();

	/**
	 * Returns the meta object for the attribute '{@link com.jennic.ZPSConfiguration.NodePowerDescriptor#isDisposableBattery <em>Disposable Battery</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the attribute '<em>Disposable Battery</em>'.
	 * @see com.jennic.ZPSConfiguration.NodePowerDescriptor#isDisposableBattery()
	 * @see #getNodePowerDescriptor()
	 * @generated
	 */
	EAttribute getNodePowerDescriptor_DisposableBattery();

	/**
	 * Returns the meta object for the attribute '{@link com.jennic.ZPSConfiguration.NodePowerDescriptor#getDefaultPowerSource <em>Default Power Source</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the attribute '<em>Default Power Source</em>'.
	 * @see com.jennic.ZPSConfiguration.NodePowerDescriptor#getDefaultPowerSource()
	 * @see #getNodePowerDescriptor()
	 * @generated
	 */
	EAttribute getNodePowerDescriptor_DefaultPowerSource();

	/**
	 * Returns the meta object for the attribute '{@link com.jennic.ZPSConfiguration.NodePowerDescriptor#getDefaultPowerMode <em>Default Power Mode</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the attribute '<em>Default Power Mode</em>'.
	 * @see com.jennic.ZPSConfiguration.NodePowerDescriptor#getDefaultPowerMode()
	 * @see #getNodePowerDescriptor()
	 * @generated
	 */
	EAttribute getNodePowerDescriptor_DefaultPowerMode();

	/**
	 * Returns the meta object for class '{@link com.jennic.ZPSConfiguration.BindUnbindServer <em>Bind Unbind Server</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for class '<em>Bind Unbind Server</em>'.
	 * @see com.jennic.ZPSConfiguration.BindUnbindServer
	 * @generated
	 */
	EClass getBindUnbindServer();

	/**
	 * Returns the meta object for class '{@link com.jennic.ZPSConfiguration.MgmtBindServer <em>Mgmt Bind Server</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for class '<em>Mgmt Bind Server</em>'.
	 * @see com.jennic.ZPSConfiguration.MgmtBindServer
	 * @generated
	 */
	EClass getMgmtBindServer();

	/**
	 * Returns the meta object for class '{@link com.jennic.ZPSConfiguration.ExtendedActiveEpServer <em>Extended Active Ep Server</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for class '<em>Extended Active Ep Server</em>'.
	 * @see com.jennic.ZPSConfiguration.ExtendedActiveEpServer
	 * @generated
	 */
	EClass getExtendedActiveEpServer();

	/**
	 * Returns the meta object for class '{@link com.jennic.ZPSConfiguration.ExtendedSimpleDescServer <em>Extended Simple Desc Server</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for class '<em>Extended Simple Desc Server</em>'.
	 * @see com.jennic.ZPSConfiguration.ExtendedSimpleDescServer
	 * @generated
	 */
	EClass getExtendedSimpleDescServer();

	/**
	 * Returns the meta object for class '{@link com.jennic.ZPSConfiguration.ZdoClient <em>Zdo Client</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for class '<em>Zdo Client</em>'.
	 * @see com.jennic.ZPSConfiguration.ZdoClient
	 * @generated
	 */
	EClass getZdoClient();

	/**
	 * Returns the meta object for class '{@link com.jennic.ZPSConfiguration.MgmtNWKUpdateServer <em>Mgmt NWK Update Server</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for class '<em>Mgmt NWK Update Server</em>'.
	 * @see com.jennic.ZPSConfiguration.MgmtNWKUpdateServer
	 * @generated
	 */
	EClass getMgmtNWKUpdateServer();

	/**
	 * Returns the meta object for class '{@link com.jennic.ZPSConfiguration.ZDOCommonServers <em>ZDO Common Servers</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for class '<em>ZDO Common Servers</em>'.
	 * @see com.jennic.ZPSConfiguration.ZDOCommonServers
	 * @generated
	 */
	EClass getZDOCommonServers();

	/**
	 * Returns the meta object for the containment reference '{@link com.jennic.ZPSConfiguration.ZDOCommonServers#getDefaultServer <em>Default Server</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the containment reference '<em>Default Server</em>'.
	 * @see com.jennic.ZPSConfiguration.ZDOCommonServers#getDefaultServer()
	 * @see #getZDOCommonServers()
	 * @generated
	 */
	EReference getZDOCommonServers_DefaultServer();

	/**
	 * Returns the meta object for the containment reference '{@link com.jennic.ZPSConfiguration.ZDOCommonServers#getMgmtNWKUpdateServer <em>Mgmt NWK Update Server</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the containment reference '<em>Mgmt NWK Update Server</em>'.
	 * @see com.jennic.ZPSConfiguration.ZDOCommonServers#getMgmtNWKUpdateServer()
	 * @see #getZDOCommonServers()
	 * @generated
	 */
	EReference getZDOCommonServers_MgmtNWKUpdateServer();

	/**
	 * Returns the meta object for the containment reference '{@link com.jennic.ZPSConfiguration.ZDOCommonServers#getZdoClient <em>Zdo Client</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the containment reference '<em>Zdo Client</em>'.
	 * @see com.jennic.ZPSConfiguration.ZDOCommonServers#getZdoClient()
	 * @see #getZDOCommonServers()
	 * @generated
	 */
	EReference getZDOCommonServers_ZdoClient();

	/**
	 * Returns the meta object for the containment reference '{@link com.jennic.ZPSConfiguration.ZDOCommonServers#getDeviceAnnceServer <em>Device Annce Server</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the containment reference '<em>Device Annce Server</em>'.
	 * @see com.jennic.ZPSConfiguration.ZDOCommonServers#getDeviceAnnceServer()
	 * @see #getZDOCommonServers()
	 * @generated
	 */
	EReference getZDOCommonServers_DeviceAnnceServer();

	/**
	 * Returns the meta object for the containment reference '{@link com.jennic.ZPSConfiguration.ZDOCommonServers#getActiveEpServer <em>Active Ep Server</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the containment reference '<em>Active Ep Server</em>'.
	 * @see com.jennic.ZPSConfiguration.ZDOCommonServers#getActiveEpServer()
	 * @see #getZDOCommonServers()
	 * @generated
	 */
	EReference getZDOCommonServers_ActiveEpServer();

	/**
	 * Returns the meta object for the containment reference '{@link com.jennic.ZPSConfiguration.ZDOCommonServers#getNwkAddrServer <em>Nwk Addr Server</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the containment reference '<em>Nwk Addr Server</em>'.
	 * @see com.jennic.ZPSConfiguration.ZDOCommonServers#getNwkAddrServer()
	 * @see #getZDOCommonServers()
	 * @generated
	 */
	EReference getZDOCommonServers_NwkAddrServer();

	/**
	 * Returns the meta object for the containment reference '{@link com.jennic.ZPSConfiguration.ZDOCommonServers#getIeeeAddrServer <em>Ieee Addr Server</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the containment reference '<em>Ieee Addr Server</em>'.
	 * @see com.jennic.ZPSConfiguration.ZDOCommonServers#getIeeeAddrServer()
	 * @see #getZDOCommonServers()
	 * @generated
	 */
	EReference getZDOCommonServers_IeeeAddrServer();

	/**
	 * Returns the meta object for the containment reference '{@link com.jennic.ZPSConfiguration.ZDOCommonServers#getSystemServerDiscoveryServer <em>System Server Discovery Server</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the containment reference '<em>System Server Discovery Server</em>'.
	 * @see com.jennic.ZPSConfiguration.ZDOCommonServers#getSystemServerDiscoveryServer()
	 * @see #getZDOCommonServers()
	 * @generated
	 */
	EReference getZDOCommonServers_SystemServerDiscoveryServer();

	/**
	 * Returns the meta object for the containment reference '{@link com.jennic.ZPSConfiguration.ZDOCommonServers#getNodeDescServer <em>Node Desc Server</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the containment reference '<em>Node Desc Server</em>'.
	 * @see com.jennic.ZPSConfiguration.ZDOCommonServers#getNodeDescServer()
	 * @see #getZDOCommonServers()
	 * @generated
	 */
	EReference getZDOCommonServers_NodeDescServer();

	/**
	 * Returns the meta object for the containment reference '{@link com.jennic.ZPSConfiguration.ZDOCommonServers#getPowerDescServer <em>Power Desc Server</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the containment reference '<em>Power Desc Server</em>'.
	 * @see com.jennic.ZPSConfiguration.ZDOCommonServers#getPowerDescServer()
	 * @see #getZDOCommonServers()
	 * @generated
	 */
	EReference getZDOCommonServers_PowerDescServer();

	/**
	 * Returns the meta object for the containment reference '{@link com.jennic.ZPSConfiguration.ZDOCommonServers#getMatchDescServer <em>Match Desc Server</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the containment reference '<em>Match Desc Server</em>'.
	 * @see com.jennic.ZPSConfiguration.ZDOCommonServers#getMatchDescServer()
	 * @see #getZDOCommonServers()
	 * @generated
	 */
	EReference getZDOCommonServers_MatchDescServer();

	/**
	 * Returns the meta object for the containment reference '{@link com.jennic.ZPSConfiguration.ZDOCommonServers#getSimpleDescServer <em>Simple Desc Server</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the containment reference '<em>Simple Desc Server</em>'.
	 * @see com.jennic.ZPSConfiguration.ZDOCommonServers#getSimpleDescServer()
	 * @see #getZDOCommonServers()
	 * @generated
	 */
	EReference getZDOCommonServers_SimpleDescServer();

	/**
	 * Returns the meta object for the containment reference '{@link com.jennic.ZPSConfiguration.ZDOCommonServers#getMgmtLqiServer <em>Mgmt Lqi Server</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the containment reference '<em>Mgmt Lqi Server</em>'.
	 * @see com.jennic.ZPSConfiguration.ZDOCommonServers#getMgmtLqiServer()
	 * @see #getZDOCommonServers()
	 * @generated
	 */
	EReference getZDOCommonServers_MgmtLqiServer();

	/**
	 * Returns the meta object for the containment reference '{@link com.jennic.ZPSConfiguration.ZDOCommonServers#getMgmtLeaveServer <em>Mgmt Leave Server</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the containment reference '<em>Mgmt Leave Server</em>'.
	 * @see com.jennic.ZPSConfiguration.ZDOCommonServers#getMgmtLeaveServer()
	 * @see #getZDOCommonServers()
	 * @generated
	 */
	EReference getZDOCommonServers_MgmtLeaveServer();

	/**
	 * Returns the meta object for the containment reference '{@link com.jennic.ZPSConfiguration.ZDOCommonServers#getBindUnbindServer <em>Bind Unbind Server</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the containment reference '<em>Bind Unbind Server</em>'.
	 * @see com.jennic.ZPSConfiguration.ZDOCommonServers#getBindUnbindServer()
	 * @see #getZDOCommonServers()
	 * @generated
	 */
	EReference getZDOCommonServers_BindUnbindServer();

	/**
	 * Returns the meta object for the containment reference '{@link com.jennic.ZPSConfiguration.ZDOCommonServers#getExtendedActiveEpServer <em>Extended Active Ep Server</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the containment reference '<em>Extended Active Ep Server</em>'.
	 * @see com.jennic.ZPSConfiguration.ZDOCommonServers#getExtendedActiveEpServer()
	 * @see #getZDOCommonServers()
	 * @generated
	 */
	EReference getZDOCommonServers_ExtendedActiveEpServer();

	/**
	 * Returns the meta object for the containment reference '{@link com.jennic.ZPSConfiguration.ZDOCommonServers#getExtendedSimpleDescServer <em>Extended Simple Desc Server</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the containment reference '<em>Extended Simple Desc Server</em>'.
	 * @see com.jennic.ZPSConfiguration.ZDOCommonServers#getExtendedSimpleDescServer()
	 * @see #getZDOCommonServers()
	 * @generated
	 */
	EReference getZDOCommonServers_ExtendedSimpleDescServer();

	/**
	 * Returns the meta object for the containment reference '{@link com.jennic.ZPSConfiguration.ZDOCommonServers#getBindRequestServer <em>Bind Request Server</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the containment reference '<em>Bind Request Server</em>'.
	 * @see com.jennic.ZPSConfiguration.ZDOCommonServers#getBindRequestServer()
	 * @see #getZDOCommonServers()
	 * @generated
	 */
	EReference getZDOCommonServers_BindRequestServer();

	/**
	 * Returns the meta object for the containment reference '{@link com.jennic.ZPSConfiguration.ZDOCommonServers#getMgmtBindServer <em>Mgmt Bind Server</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the containment reference '<em>Mgmt Bind Server</em>'.
	 * @see com.jennic.ZPSConfiguration.ZDOCommonServers#getMgmtBindServer()
	 * @see #getZDOCommonServers()
	 * @generated
	 */
	EReference getZDOCommonServers_MgmtBindServer();

	/**
	 * Returns the meta object for the containment reference '{@link com.jennic.ZPSConfiguration.ZDOCommonServers#getMgmtNWKEnhanceUpdateServer <em>Mgmt NWK Enhance Update Server</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the containment reference '<em>Mgmt NWK Enhance Update Server</em>'.
	 * @see com.jennic.ZPSConfiguration.ZDOCommonServers#getMgmtNWKEnhanceUpdateServer()
	 * @see #getZDOCommonServers()
	 * @generated
	 */
	EReference getZDOCommonServers_MgmtNWKEnhanceUpdateServer();

	/**
	 * Returns the meta object for class '{@link com.jennic.ZPSConfiguration.NotImplemented <em>Not Implemented</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for class '<em>Not Implemented</em>'.
	 * @see com.jennic.ZPSConfiguration.NotImplemented
	 * @generated
	 */
	EClass getNotImplemented();

	/**
	 * Returns the meta object for the containment reference '{@link com.jennic.ZPSConfiguration.NotImplemented#getComplexDescriptor <em>Complex Descriptor</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the containment reference '<em>Complex Descriptor</em>'.
	 * @see com.jennic.ZPSConfiguration.NotImplemented#getComplexDescriptor()
	 * @see #getNotImplemented()
	 * @generated
	 */
	EReference getNotImplemented_ComplexDescriptor();

	/**
	 * Returns the meta object for the containment reference '{@link com.jennic.ZPSConfiguration.NotImplemented#getDiscoveryTable <em>Discovery Table</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the containment reference '<em>Discovery Table</em>'.
	 * @see com.jennic.ZPSConfiguration.NotImplemented#getDiscoveryTable()
	 * @see #getNotImplemented()
	 * @generated
	 */
	EReference getNotImplemented_DiscoveryTable();

	/**
	 * Returns the meta object for the containment reference '{@link com.jennic.ZPSConfiguration.NotImplemented#getDiscoveryCache <em>Discovery Cache</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the containment reference '<em>Discovery Cache</em>'.
	 * @see com.jennic.ZPSConfiguration.NotImplemented#getDiscoveryCache()
	 * @see #getNotImplemented()
	 * @generated
	 */
	EReference getNotImplemented_DiscoveryCache();

	/**
	 * Returns the meta object for the containment reference '{@link com.jennic.ZPSConfiguration.NotImplemented#getBindingCache <em>Binding Cache</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the containment reference '<em>Binding Cache</em>'.
	 * @see com.jennic.ZPSConfiguration.NotImplemented#getBindingCache()
	 * @see #getNotImplemented()
	 * @generated
	 */
	EReference getNotImplemented_BindingCache();

	/**
	 * Returns the meta object for class '{@link com.jennic.ZPSConfiguration.KeyDescriptorTable <em>Key Descriptor Table</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for class '<em>Key Descriptor Table</em>'.
	 * @see com.jennic.ZPSConfiguration.KeyDescriptorTable
	 * @generated
	 */
	EClass getKeyDescriptorTable();

	/**
	 * Returns the meta object for the attribute '{@link com.jennic.ZPSConfiguration.KeyDescriptorTable#getSize <em>Size</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the attribute '<em>Size</em>'.
	 * @see com.jennic.ZPSConfiguration.KeyDescriptorTable#getSize()
	 * @see #getKeyDescriptorTable()
	 * @generated
	 */
	EAttribute getKeyDescriptorTable_Size();

	/**
	 * Returns the meta object for the containment reference list '{@link com.jennic.ZPSConfiguration.KeyDescriptorTable#getPreconfiguredKey <em>Preconfigured Key</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the containment reference list '<em>Preconfigured Key</em>'.
	 * @see com.jennic.ZPSConfiguration.KeyDescriptorTable#getPreconfiguredKey()
	 * @see #getKeyDescriptorTable()
	 * @generated
	 */
	EReference getKeyDescriptorTable_PreconfiguredKey();

	/**
	 * Returns the meta object for class '{@link com.jennic.ZPSConfiguration.PreconfiguredKey <em>Preconfigured Key</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for class '<em>Preconfigured Key</em>'.
	 * @see com.jennic.ZPSConfiguration.PreconfiguredKey
	 * @generated
	 */
	EClass getPreconfiguredKey();

	/**
	 * Returns the meta object for the attribute '{@link com.jennic.ZPSConfiguration.PreconfiguredKey#getKey <em>Key</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the attribute '<em>Key</em>'.
	 * @see com.jennic.ZPSConfiguration.PreconfiguredKey#getKey()
	 * @see #getPreconfiguredKey()
	 * @generated
	 */
	EAttribute getPreconfiguredKey_Key();

	/**
	 * Returns the meta object for the attribute '{@link com.jennic.ZPSConfiguration.PreconfiguredKey#getIEEEAddress <em>IEEE Address</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the attribute '<em>IEEE Address</em>'.
	 * @see com.jennic.ZPSConfiguration.PreconfiguredKey#getIEEEAddress()
	 * @see #getPreconfiguredKey()
	 * @generated
	 */
	EAttribute getPreconfiguredKey_IEEEAddress();

	/**
	 * Returns the meta object for class '{@link com.jennic.ZPSConfiguration.ZDOCoordRouterOnlyServers <em>ZDO Coord Router Only Servers</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for class '<em>ZDO Coord Router Only Servers</em>'.
	 * @see com.jennic.ZPSConfiguration.ZDOCoordRouterOnlyServers
	 * @generated
	 */
	EClass getZDOCoordRouterOnlyServers();

	/**
	 * Returns the meta object for the containment reference '{@link com.jennic.ZPSConfiguration.ZDOCoordRouterOnlyServers#getPermitJoiningServer <em>Permit Joining Server</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the containment reference '<em>Permit Joining Server</em>'.
	 * @see com.jennic.ZPSConfiguration.ZDOCoordRouterOnlyServers#getPermitJoiningServer()
	 * @see #getZDOCoordRouterOnlyServers()
	 * @generated
	 */
	EReference getZDOCoordRouterOnlyServers_PermitJoiningServer();

	/**
	 * Returns the meta object for the containment reference '{@link com.jennic.ZPSConfiguration.ZDOCoordRouterOnlyServers#getMgmtRtgServer <em>Mgmt Rtg Server</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the containment reference '<em>Mgmt Rtg Server</em>'.
	 * @see com.jennic.ZPSConfiguration.ZDOCoordRouterOnlyServers#getMgmtRtgServer()
	 * @see #getZDOCoordRouterOnlyServers()
	 * @generated
	 */
	EReference getZDOCoordRouterOnlyServers_MgmtRtgServer();

	/**
	 * Returns the meta object for the containment reference '{@link com.jennic.ZPSConfiguration.ZDOCoordRouterOnlyServers#getMgmtMibIeeeServer <em>Mgmt Mib Ieee Server</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the containment reference '<em>Mgmt Mib Ieee Server</em>'.
	 * @see com.jennic.ZPSConfiguration.ZDOCoordRouterOnlyServers#getMgmtMibIeeeServer()
	 * @see #getZDOCoordRouterOnlyServers()
	 * @generated
	 */
	EReference getZDOCoordRouterOnlyServers_MgmtMibIeeeServer();

	/**
	 * Returns the meta object for the containment reference '{@link com.jennic.ZPSConfiguration.ZDOCoordRouterOnlyServers#getParentAnnceServer <em>Parent Annce Server</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the containment reference '<em>Parent Annce Server</em>'.
	 * @see com.jennic.ZPSConfiguration.ZDOCoordRouterOnlyServers#getParentAnnceServer()
	 * @see #getZDOCoordRouterOnlyServers()
	 * @generated
	 */
	EReference getZDOCoordRouterOnlyServers_ParentAnnceServer();

	/**
	 * Returns the meta object for class '{@link com.jennic.ZPSConfiguration.PreConfiguredNwkKey <em>Pre Configured Nwk Key</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for class '<em>Pre Configured Nwk Key</em>'.
	 * @see com.jennic.ZPSConfiguration.PreConfiguredNwkKey
	 * @generated
	 */
	EClass getPreConfiguredNwkKey();

	/**
	 * Returns the meta object for class '{@link com.jennic.ZPSConfiguration.DefaultNwkKey <em>Default Nwk Key</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for class '<em>Default Nwk Key</em>'.
	 * @see com.jennic.ZPSConfiguration.DefaultNwkKey
	 * @generated
	 */
	EClass getDefaultNwkKey();

	/**
	 * Returns the meta object for the attribute '{@link com.jennic.ZPSConfiguration.DefaultNwkKey#isRandom <em>Random</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the attribute '<em>Random</em>'.
	 * @see com.jennic.ZPSConfiguration.DefaultNwkKey#isRandom()
	 * @see #getDefaultNwkKey()
	 * @generated
	 */
	EAttribute getDefaultNwkKey_Random();

	/**
	 * Returns the meta object for class '{@link com.jennic.ZPSConfiguration.NwkKey <em>Nwk Key</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for class '<em>Nwk Key</em>'.
	 * @see com.jennic.ZPSConfiguration.NwkKey
	 * @generated
	 */
	EClass getNwkKey();

	/**
	 * Returns the meta object for the attribute '{@link com.jennic.ZPSConfiguration.NwkKey#getKeySequenceNumber <em>Key Sequence Number</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the attribute '<em>Key Sequence Number</em>'.
	 * @see com.jennic.ZPSConfiguration.NwkKey#getKeySequenceNumber()
	 * @see #getNwkKey()
	 * @generated
	 */
	EAttribute getNwkKey_KeySequenceNumber();

	/**
	 * Returns the meta object for the attribute '{@link com.jennic.ZPSConfiguration.NwkKey#getKey <em>Key</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the attribute '<em>Key</em>'.
	 * @see com.jennic.ZPSConfiguration.NwkKey#getKey()
	 * @see #getNwkKey()
	 * @generated
	 */
	EAttribute getNwkKey_Key();

	/**
	 * Returns the meta object for the attribute '{@link com.jennic.ZPSConfiguration.NwkKey#getId <em>Id</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the attribute '<em>Id</em>'.
	 * @see com.jennic.ZPSConfiguration.NwkKey#getId()
	 * @see #getNwkKey()
	 * @generated
	 */
	EAttribute getNwkKey_Id();

	/**
	 * Returns the meta object for class '{@link com.jennic.ZPSConfiguration.PreconfiguredTCLinkKey <em>Preconfigured TC Link Key</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for class '<em>Preconfigured TC Link Key</em>'.
	 * @see com.jennic.ZPSConfiguration.PreconfiguredTCLinkKey
	 * @generated
	 */
	EClass getPreconfiguredTCLinkKey();

	/**
	 * Returns the meta object for the attribute '{@link com.jennic.ZPSConfiguration.PreconfiguredTCLinkKey#getId <em>Id</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the attribute '<em>Id</em>'.
	 * @see com.jennic.ZPSConfiguration.PreconfiguredTCLinkKey#getId()
	 * @see #getPreconfiguredTCLinkKey()
	 * @generated
	 */
	EAttribute getPreconfiguredTCLinkKey_Id();

	/**
	 * Returns the meta object for class '{@link com.jennic.ZPSConfiguration.TCKey <em>TC Key</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for class '<em>TC Key</em>'.
	 * @see com.jennic.ZPSConfiguration.TCKey
	 * @generated
	 */
	EClass getTCKey();

	/**
	 * Returns the meta object for class '{@link com.jennic.ZPSConfiguration.BindRequestServer <em>Bind Request Server</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for class '<em>Bind Request Server</em>'.
	 * @see com.jennic.ZPSConfiguration.BindRequestServer
	 * @generated
	 */
	EClass getBindRequestServer();

	/**
	 * Returns the meta object for the attribute '{@link com.jennic.ZPSConfiguration.BindRequestServer#getSimultaneousRequests <em>Simultaneous Requests</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the attribute '<em>Simultaneous Requests</em>'.
	 * @see com.jennic.ZPSConfiguration.BindRequestServer#getSimultaneousRequests()
	 * @see #getBindRequestServer()
	 * @generated
	 */
	EAttribute getBindRequestServer_SimultaneousRequests();

	/**
	 * Returns the meta object for the attribute '{@link com.jennic.ZPSConfiguration.BindRequestServer#getTimeInterval <em>Time Interval</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the attribute '<em>Time Interval</em>'.
	 * @see com.jennic.ZPSConfiguration.BindRequestServer#getTimeInterval()
	 * @see #getBindRequestServer()
	 * @generated
	 */
	EAttribute getBindRequestServer_TimeInterval();

	/**
	 * Returns the meta object for class '{@link com.jennic.ZPSConfiguration.GreenPowerSecurityTable <em>Green Power Security Table</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for class '<em>Green Power Security Table</em>'.
	 * @see com.jennic.ZPSConfiguration.GreenPowerSecurityTable
	 * @generated
	 */
	EClass getGreenPowerSecurityTable();

	/**
	 * Returns the meta object for the attribute '{@link com.jennic.ZPSConfiguration.GreenPowerSecurityTable#getSize <em>Size</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the attribute '<em>Size</em>'.
	 * @see com.jennic.ZPSConfiguration.GreenPowerSecurityTable#getSize()
	 * @see #getGreenPowerSecurityTable()
	 * @generated
	 */
	EAttribute getGreenPowerSecurityTable_Size();

	/**
	 * Returns the meta object for class '{@link com.jennic.ZPSConfiguration.GreenPowerTxQueue <em>Green Power Tx Queue</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for class '<em>Green Power Tx Queue</em>'.
	 * @see com.jennic.ZPSConfiguration.GreenPowerTxQueue
	 * @generated
	 */
	EClass getGreenPowerTxQueue();

	/**
	 * Returns the meta object for the attribute '{@link com.jennic.ZPSConfiguration.GreenPowerTxQueue#getSize <em>Size</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the attribute '<em>Size</em>'.
	 * @see com.jennic.ZPSConfiguration.GreenPowerTxQueue#getSize()
	 * @see #getGreenPowerTxQueue()
	 * @generated
	 */
	EAttribute getGreenPowerTxQueue_Size();

	/**
	 * Returns the meta object for class '{@link com.jennic.ZPSConfiguration.MgmtMibIeeeServer <em>Mgmt Mib Ieee Server</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for class '<em>Mgmt Mib Ieee Server</em>'.
	 * @see com.jennic.ZPSConfiguration.MgmtMibIeeeServer
	 * @generated
	 */
	EClass getMgmtMibIeeeServer();

	/**
	 * Returns the meta object for class '{@link com.jennic.ZPSConfiguration.MgmtNWKEnhanceUpdateServer <em>Mgmt NWK Enhance Update Server</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for class '<em>Mgmt NWK Enhance Update Server</em>'.
	 * @see com.jennic.ZPSConfiguration.MgmtNWKEnhanceUpdateServer
	 * @generated
	 */
	EClass getMgmtNWKEnhanceUpdateServer();

	/**
	 * Returns the meta object for class '{@link com.jennic.ZPSConfiguration.MacInterfaceList <em>Mac Interface List</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for class '<em>Mac Interface List</em>'.
	 * @see com.jennic.ZPSConfiguration.MacInterfaceList
	 * @generated
	 */
	EClass getMacInterfaceList();

	/**
	 * Returns the meta object for the containment reference list '{@link com.jennic.ZPSConfiguration.MacInterfaceList#getMacInterface <em>Mac Interface</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the containment reference list '<em>Mac Interface</em>'.
	 * @see com.jennic.ZPSConfiguration.MacInterfaceList#getMacInterface()
	 * @see #getMacInterfaceList()
	 * @generated
	 */
	EReference getMacInterfaceList_MacInterface();

	/**
	 * Returns the meta object for class '{@link com.jennic.ZPSConfiguration.MacInterface <em>Mac Interface</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for class '<em>Mac Interface</em>'.
	 * @see com.jennic.ZPSConfiguration.MacInterface
	 * @generated
	 */
	EClass getMacInterface();

	/**
	 * Returns the meta object for the attribute '{@link com.jennic.ZPSConfiguration.MacInterface#isRouterAllowed <em>Router Allowed</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the attribute '<em>Router Allowed</em>'.
	 * @see com.jennic.ZPSConfiguration.MacInterface#isRouterAllowed()
	 * @see #getMacInterface()
	 * @generated
	 */
	EAttribute getMacInterface_RouterAllowed();

	/**
	 * Returns the meta object for the attribute '{@link com.jennic.ZPSConfiguration.MacInterface#getChannelListSize <em>Channel List Size</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the attribute '<em>Channel List Size</em>'.
	 * @see com.jennic.ZPSConfiguration.MacInterface#getChannelListSize()
	 * @see #getMacInterface()
	 * @generated
	 */
	EAttribute getMacInterface_ChannelListSize();

	/**
	 * Returns the meta object for the attribute '{@link com.jennic.ZPSConfiguration.MacInterface#getIndex <em>Index</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the attribute '<em>Index</em>'.
	 * @see com.jennic.ZPSConfiguration.MacInterface#getIndex()
	 * @see #getMacInterface()
	 * @generated
	 */
	EAttribute getMacInterface_Index();

	/**
	 * Returns the meta object for the attribute '{@link com.jennic.ZPSConfiguration.MacInterface#getRadioType <em>Radio Type</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the attribute '<em>Radio Type</em>'.
	 * @see com.jennic.ZPSConfiguration.MacInterface#getRadioType()
	 * @see #getMacInterface()
	 * @generated
	 */
	EAttribute getMacInterface_RadioType();

	/**
	 * Returns the meta object for the attribute '{@link com.jennic.ZPSConfiguration.MacInterface#isEnabled <em>Enabled</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the attribute '<em>Enabled</em>'.
	 * @see com.jennic.ZPSConfiguration.MacInterface#isEnabled()
	 * @see #getMacInterface()
	 * @generated
	 */
	EAttribute getMacInterface_Enabled();

	/**
	 * Returns the meta object for class '{@link com.jennic.ZPSConfiguration.ParentAnnceServer <em>Parent Annce Server</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for class '<em>Parent Annce Server</em>'.
	 * @see com.jennic.ZPSConfiguration.ParentAnnceServer
	 * @generated
	 */
	EClass getParentAnnceServer();

	/**
	 * Returns the meta object for enum '{@link com.jennic.ZPSConfiguration.NodeLogicalType <em>Node Logical Type</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for enum '<em>Node Logical Type</em>'.
	 * @see com.jennic.ZPSConfiguration.NodeLogicalType
	 * @generated
	 */
	EEnum getNodeLogicalType();

	/**
	 * Returns the meta object for enum '{@link com.jennic.ZPSConfiguration.FrequencyBands <em>Frequency Bands</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for enum '<em>Frequency Bands</em>'.
	 * @see com.jennic.ZPSConfiguration.FrequencyBands
	 * @generated
	 */
	EEnum getFrequencyBands();

	/**
	 * Returns the meta object for enum '{@link com.jennic.ZPSConfiguration.PowerSources <em>Power Sources</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for enum '<em>Power Sources</em>'.
	 * @see com.jennic.ZPSConfiguration.PowerSources
	 * @generated
	 */
	EEnum getPowerSources();

	/**
	 * Returns the meta object for enum '{@link com.jennic.ZPSConfiguration.PowerModes <em>Power Modes</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for enum '<em>Power Modes</em>'.
	 * @see com.jennic.ZPSConfiguration.PowerModes
	 * @generated
	 */
	EEnum getPowerModes();

	/**
	 * Returns the meta object for enum '{@link com.jennic.ZPSConfiguration.NetworkSelectionTypes <em>Network Selection Types</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for enum '<em>Network Selection Types</em>'.
	 * @see com.jennic.ZPSConfiguration.NetworkSelectionTypes
	 * @generated
	 */
	EEnum getNetworkSelectionTypes();

	/**
	 * Returns the meta object for enum '{@link com.jennic.ZPSConfiguration.RadioType <em>Radio Type</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for enum '<em>Radio Type</em>'.
	 * @see com.jennic.ZPSConfiguration.RadioType
	 * @generated
	 */
	EEnum getRadioType();

	/**
	 * Returns the meta object for data type '{@link Integer <em>EU Short</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for data type '<em>EU Short</em>'.
	 * @see Integer
	 * @model instanceClass="java.lang.Object"
	 * @generated
	 */
	EDataType getEUShort();

	/**
	 * Returns the meta object for data type '{@link BigInteger <em>EExt PAN Id</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for data type '<em>EExt PAN Id</em>'.
	 * @see BigInteger
	 * @model instanceClass="java.lang.Object"
	 *        annotation="http://jennic.com/hexdec editor='hexdec'"
	 * @generated
	 */
	EDataType getEExtPANId();

	/**
	 * Returns the meta object for data type '{@link Integer <em>EPermit Joining</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for data type '<em>EPermit Joining</em>'.
	 * @see Integer
	 * @model instanceClass="java.lang.Object"
	 * @generated
	 */
	EDataType getEPermitJoining();

	/**
	 * Returns the meta object for data type '{@link BigInteger <em>ESec Key</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for data type '<em>ESec Key</em>'.
	 * @see BigInteger
	 * @model instanceClass="java.lang.Object"
	 * @generated
	 */
	EDataType getESecKey();

	/**
	 * Returns the factory that creates the instances of the model.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the factory that creates the instances of the model.
	 * @generated
	 */
	ZPSConfigurationFactory getZPSConfigurationFactory();

	/**
	 * <!-- begin-user-doc -->
	 * Defines literals for the meta objects that represent
	 * <ul>
	 *   <li>each class,</li>
	 *   <li>each feature of each class,</li>
	 *   <li>each enum,</li>
	 *   <li>and each data type</li>
	 * </ul>
	 * <!-- end-user-doc -->
	 * @generated
	 */
	interface Literals {
		/**
		 * The meta object literal for the '{@link com.jennic.ZPSConfiguration.impl.ProfileImpl <em>Profile</em>}' class.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @see com.jennic.ZPSConfiguration.impl.ProfileImpl
		 * @see com.jennic.ZPSConfiguration.impl.ZPSConfigurationPackageImpl#getProfile()
		 * @generated
		 */
		EClass PROFILE = eINSTANCE.getProfile();

		/**
		 * The meta object literal for the '<em><b>Id</b></em>' attribute feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EAttribute PROFILE__ID = eINSTANCE.getProfile_Id();

		/**
		 * The meta object literal for the '<em><b>Clusters</b></em>' containment reference list feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EReference PROFILE__CLUSTERS = eINSTANCE.getProfile_Clusters();

		/**
		 * The meta object literal for the '{@link com.jennic.ZPSConfiguration.impl.ClusterImpl <em>Cluster</em>}' class.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @see com.jennic.ZPSConfiguration.impl.ClusterImpl
		 * @see com.jennic.ZPSConfiguration.impl.ZPSConfigurationPackageImpl#getCluster()
		 * @generated
		 */
		EClass CLUSTER = eINSTANCE.getCluster();

		/**
		 * The meta object literal for the '<em><b>Id</b></em>' attribute feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EAttribute CLUSTER__ID = eINSTANCE.getCluster_Id();

		/**
		 * The meta object literal for the '{@link com.jennic.ZPSConfiguration.impl.NodeImpl <em>Node</em>}' class.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @see com.jennic.ZPSConfiguration.impl.NodeImpl
		 * @see com.jennic.ZPSConfiguration.impl.ZPSConfigurationPackageImpl#getNode()
		 * @generated
		 */
		EClass NODE = eINSTANCE.getNode();

		/**
		 * The meta object literal for the '<em><b>Endpoints</b></em>' containment reference list feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EReference NODE__ENDPOINTS = eINSTANCE.getNode_Endpoints();

		/**
		 * The meta object literal for the '<em><b>Binding Table</b></em>' containment reference feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EReference NODE__BINDING_TABLE = eINSTANCE.getNode_BindingTable();

		/**
		 * The meta object literal for the '<em><b>User Descriptor</b></em>' containment reference feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EReference NODE__USER_DESCRIPTOR = eINSTANCE.getNode_UserDescriptor();

		/**
		 * The meta object literal for the '<em><b>PDU Configuration</b></em>' containment reference feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EReference NODE__PDU_CONFIGURATION = eINSTANCE.getNode_PDUConfiguration();

		/**
		 * The meta object literal for the '<em><b>Group Table</b></em>' containment reference feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EReference NODE__GROUP_TABLE = eINSTANCE.getNode_GroupTable();

		/**
		 * The meta object literal for the '<em><b>Max Num Simultaneous Apsde Ack Req</b></em>' attribute feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EAttribute NODE__MAX_NUM_SIMULTANEOUS_APSDE_ACK_REQ = eINSTANCE.getNode_MaxNumSimultaneousApsdeAckReq();

		/**
		 * The meta object literal for the '<em><b>Channel Mask</b></em>' containment reference feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EReference NODE__CHANNEL_MASK = eINSTANCE.getNode_ChannelMask();

		/**
		 * The meta object literal for the '<em><b>Discovery Neighbour Table Size</b></em>' attribute feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EAttribute NODE__DISCOVERY_NEIGHBOUR_TABLE_SIZE = eINSTANCE.getNode_DiscoveryNeighbourTableSize();

		/**
		 * The meta object literal for the '<em><b>Active Neighbour Table Size</b></em>' attribute feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EAttribute NODE__ACTIVE_NEIGHBOUR_TABLE_SIZE = eINSTANCE.getNode_ActiveNeighbourTableSize();

		/**
		 * The meta object literal for the '<em><b>Route Discovery Table Size</b></em>' attribute feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EAttribute NODE__ROUTE_DISCOVERY_TABLE_SIZE = eINSTANCE.getNode_RouteDiscoveryTableSize();

		/**
		 * The meta object literal for the '<em><b>Routing Table Size</b></em>' attribute feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EAttribute NODE__ROUTING_TABLE_SIZE = eINSTANCE.getNode_RoutingTableSize();

		/**
		 * The meta object literal for the '<em><b>Broadcast Transaction Table Size</b></em>' attribute feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EAttribute NODE__BROADCAST_TRANSACTION_TABLE_SIZE = eINSTANCE.getNode_BroadcastTransactionTableSize();

		/**
		 * The meta object literal for the '<em><b>Route Record Table Size</b></em>' attribute feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EAttribute NODE__ROUTE_RECORD_TABLE_SIZE = eINSTANCE.getNode_RouteRecordTableSize();

		/**
		 * The meta object literal for the '<em><b>Address Map Table Size</b></em>' attribute feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EAttribute NODE__ADDRESS_MAP_TABLE_SIZE = eINSTANCE.getNode_AddressMapTableSize();

		/**
		 * The meta object literal for the '<em><b>Security Material Sets</b></em>' attribute feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EAttribute NODE__SECURITY_MATERIAL_SETS = eINSTANCE.getNode_SecurityMaterialSets();

		/**
		 * The meta object literal for the '<em><b>Node Descriptor</b></em>' containment reference feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EReference NODE__NODE_DESCRIPTOR = eINSTANCE.getNode_NodeDescriptor();

		/**
		 * The meta object literal for the '<em><b>Node Power Descriptor</b></em>' containment reference feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EReference NODE__NODE_POWER_DESCRIPTOR = eINSTANCE.getNode_NodePowerDescriptor();

		/**
		 * The meta object literal for the '<em><b>Max Num Simultaneous Apsde Req</b></em>' attribute feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EAttribute NODE__MAX_NUM_SIMULTANEOUS_APSDE_REQ = eINSTANCE.getNode_MaxNumSimultaneousApsdeReq();

		/**
		 * The meta object literal for the '<em><b>MAC Mutex Name</b></em>' attribute feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EAttribute NODE__MAC_MUTEX_NAME = eINSTANCE.getNode_MACMutexName();

		/**
		 * The meta object literal for the '<em><b>ZPS Mutex Name</b></em>' attribute feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EAttribute NODE__ZPS_MUTEX_NAME = eINSTANCE.getNode_ZPSMutexName();

		/**
		 * The meta object literal for the '<em><b>Fragmentation Max Num Simul Rx</b></em>' attribute feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EAttribute NODE__FRAGMENTATION_MAX_NUM_SIMUL_RX = eINSTANCE.getNode_FragmentationMaxNumSimulRx();

		/**
		 * The meta object literal for the '<em><b>Fragmentation Max Num Simul Tx</b></em>' attribute feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EAttribute NODE__FRAGMENTATION_MAX_NUM_SIMUL_TX = eINSTANCE.getNode_FragmentationMaxNumSimulTx();

		/**
		 * The meta object literal for the '<em><b>Default Event Message Name</b></em>' attribute feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EAttribute NODE__DEFAULT_EVENT_MESSAGE_NAME = eINSTANCE.getNode_DefaultEventMessageName();

		/**
		 * The meta object literal for the '<em><b>MAC Dcfm Ind Message</b></em>' attribute feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EAttribute NODE__MAC_DCFM_IND_MESSAGE = eINSTANCE.getNode_MACDcfmIndMessage();

		/**
		 * The meta object literal for the '<em><b>MAC Time Event Message</b></em>' attribute feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EAttribute NODE__MAC_TIME_EVENT_MESSAGE = eINSTANCE.getNode_MACTimeEventMessage();

		/**
		 * The meta object literal for the '<em><b>Aps Non Member Radius</b></em>' attribute feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EAttribute NODE__APS_NON_MEMBER_RADIUS = eINSTANCE.getNode_ApsNonMemberRadius();

		/**
		 * The meta object literal for the '<em><b>Aps Designated Coordinator</b></em>' attribute feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EAttribute NODE__APS_DESIGNATED_COORDINATOR = eINSTANCE.getNode_ApsDesignatedCoordinator();

		/**
		 * The meta object literal for the '<em><b>Aps Use Insecure Join</b></em>' attribute feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EAttribute NODE__APS_USE_INSECURE_JOIN = eINSTANCE.getNode_ApsUseInsecureJoin();

		/**
		 * The meta object literal for the '<em><b>Aps Max Window Size</b></em>' attribute feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EAttribute NODE__APS_MAX_WINDOW_SIZE = eINSTANCE.getNode_ApsMaxWindowSize();

		/**
		 * The meta object literal for the '<em><b>Aps Interframe Delay</b></em>' attribute feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EAttribute NODE__APS_INTERFRAME_DELAY = eINSTANCE.getNode_ApsInterframeDelay();

		/**
		 * The meta object literal for the '<em><b>Aps Security Timeout Period</b></em>' attribute feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EAttribute NODE__APS_SECURITY_TIMEOUT_PERIOD = eINSTANCE.getNode_ApsSecurityTimeoutPeriod();

		/**
		 * The meta object literal for the '<em><b>Key Descriptor Table</b></em>' containment reference feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EReference NODE__KEY_DESCRIPTOR_TABLE = eINSTANCE.getNode_KeyDescriptorTable();

		/**
		 * The meta object literal for the '<em><b>Aps Use Ext PAN Id</b></em>' attribute feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EAttribute NODE__APS_USE_EXT_PAN_ID = eINSTANCE.getNode_ApsUseExtPANId();

		/**
		 * The meta object literal for the '<em><b>Initial Network Key</b></em>' reference feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EReference NODE__INITIAL_NETWORK_KEY = eINSTANCE.getNode_InitialNetworkKey();

		/**
		 * The meta object literal for the '<em><b>Security Enabled</b></em>' attribute feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EAttribute NODE__SECURITY_ENABLED = eINSTANCE.getNode_SecurityEnabled();

		/**
		 * The meta object literal for the '<em><b>MAC Mlme Dcfm Ind Message</b></em>' attribute feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EAttribute NODE__MAC_MLME_DCFM_IND_MESSAGE = eINSTANCE.getNode_MACMlmeDcfmIndMessage();

		/**
		 * The meta object literal for the '<em><b>MAC Mcps Dcfm Ind Message</b></em>' attribute feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EAttribute NODE__MAC_MCPS_DCFM_IND_MESSAGE = eINSTANCE.getNode_MACMcpsDcfmIndMessage();

		/**
		 * The meta object literal for the '<em><b>APS Persistence Time</b></em>' attribute feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EAttribute NODE__APS_PERSISTENCE_TIME = eINSTANCE.getNode_APSPersistenceTime();

		/**
		 * The meta object literal for the '<em><b>Num APSME Simul Commands</b></em>' attribute feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EAttribute NODE__NUM_APSME_SIMUL_COMMANDS = eINSTANCE.getNode_NumAPSMESimulCommands();

		/**
		 * The meta object literal for the '<em><b>Stack Profile</b></em>' attribute feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EAttribute NODE__STACK_PROFILE = eINSTANCE.getNode_StackProfile();

		/**
		 * The meta object literal for the '<em><b>Inter PAN</b></em>' attribute feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EAttribute NODE__INTER_PAN = eINSTANCE.getNode_InterPAN();

		/**
		 * The meta object literal for the '<em><b>Green Power Support</b></em>' attribute feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EAttribute NODE__GREEN_POWER_SUPPORT = eINSTANCE.getNode_GreenPowerSupport();

		/**
		 * The meta object literal for the '<em><b>Nwk Fc Save Count Bit Shift</b></em>' attribute feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EAttribute NODE__NWK_FC_SAVE_COUNT_BIT_SHIFT = eINSTANCE.getNode_NwkFcSaveCountBitShift();

		/**
		 * The meta object literal for the '<em><b>Aps Fc Save Count Bit Shift</b></em>' attribute feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EAttribute NODE__APS_FC_SAVE_COUNT_BIT_SHIFT = eINSTANCE.getNode_ApsFcSaveCountBitShift();

		/**
		 * The meta object literal for the '<em><b>Mac Table Size</b></em>' attribute feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EAttribute NODE__MAC_TABLE_SIZE = eINSTANCE.getNode_MacTableSize();

		/**
		 * The meta object literal for the '<em><b>Default Callback Name</b></em>' attribute feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EAttribute NODE__DEFAULT_CALLBACK_NAME = eINSTANCE.getNode_DefaultCallbackName();

		/**
		 * The meta object literal for the '<em><b>Mac Interface List</b></em>' containment reference feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EReference NODE__MAC_INTERFACE_LIST = eINSTANCE.getNode_MacInterfaceList();

		/**
		 * The meta object literal for the '<em><b>Green Power Tx Queue</b></em>' containment reference feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EReference NODE__GREEN_POWER_TX_QUEUE = eINSTANCE.getNode_GreenPowerTxQueue();

		/**
		 * The meta object literal for the '<em><b>Green Power Security Table</b></em>' containment reference feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EReference NODE__GREEN_POWER_SECURITY_TABLE = eINSTANCE.getNode_GreenPowerSecurityTable();

		/**
		 * The meta object literal for the '<em><b>APS Duplicate Table Size</b></em>' attribute feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EAttribute NODE__APS_DUPLICATE_TABLE_SIZE = eINSTANCE.getNode_APSDuplicateTableSize();

		/**
		 * The meta object literal for the '{@link com.jennic.ZPSConfiguration.impl.CoordinatorImpl <em>Coordinator</em>}' class.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @see com.jennic.ZPSConfiguration.impl.CoordinatorImpl
		 * @see com.jennic.ZPSConfiguration.impl.ZPSConfigurationPackageImpl#getCoordinator()
		 * @generated
		 */
		EClass COORDINATOR = eINSTANCE.getCoordinator();

		/**
		 * The meta object literal for the '<em><b>ZDO Servers</b></em>' containment reference feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EReference COORDINATOR__ZDO_SERVERS = eINSTANCE.getCoordinator_ZDOServers();

		/**
		 * The meta object literal for the '{@link com.jennic.ZPSConfiguration.impl.RouterImpl <em>Router</em>}' class.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @see com.jennic.ZPSConfiguration.impl.RouterImpl
		 * @see com.jennic.ZPSConfiguration.impl.ZPSConfigurationPackageImpl#getRouter()
		 * @generated
		 */
		EClass ROUTER = eINSTANCE.getRouter();

		/**
		 * The meta object literal for the '<em><b>ZDO Servers</b></em>' containment reference feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EReference ROUTER__ZDO_SERVERS = eINSTANCE.getRouter_ZDOServers();

		/**
		 * The meta object literal for the '{@link com.jennic.ZPSConfiguration.impl.EndDeviceImpl <em>End Device</em>}' class.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @see com.jennic.ZPSConfiguration.impl.EndDeviceImpl
		 * @see com.jennic.ZPSConfiguration.impl.ZPSConfigurationPackageImpl#getEndDevice()
		 * @generated
		 */
		EClass END_DEVICE = eINSTANCE.getEndDevice();

		/**
		 * The meta object literal for the '<em><b>ZDO Servers</b></em>' containment reference feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EReference END_DEVICE__ZDO_SERVERS = eINSTANCE.getEndDevice_ZDOServers();

		/**
		 * The meta object literal for the '<em><b>Num Poll Failures Before Rejoin</b></em>' attribute feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EAttribute END_DEVICE__NUM_POLL_FAILURES_BEFORE_REJOIN = eINSTANCE.getEndDevice_NumPollFailuresBeforeRejoin();

		/**
		 * The meta object literal for the '<em><b>Sleeping</b></em>' attribute feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EAttribute END_DEVICE__SLEEPING = eINSTANCE.getEndDevice_Sleeping();

		/**
		 * The meta object literal for the '<em><b>Fragmented Tx Poll Period</b></em>' attribute feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EAttribute END_DEVICE__FRAGMENTED_TX_POLL_PERIOD = eINSTANCE.getEndDevice_FragmentedTxPollPeriod();

		/**
		 * The meta object literal for the '<em><b>Fragmented Rx Poll Period</b></em>' attribute feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EAttribute END_DEVICE__FRAGMENTED_RX_POLL_PERIOD = eINSTANCE.getEndDevice_FragmentedRxPollPeriod();

		/**
		 * The meta object literal for the '<em><b>APS Poll Period</b></em>' attribute feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EAttribute END_DEVICE__APS_POLL_PERIOD = eINSTANCE.getEndDevice_APSPollPeriod();

		/**
		 * The meta object literal for the '{@link com.jennic.ZPSConfiguration.impl.EndPointImpl <em>End Point</em>}' class.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @see com.jennic.ZPSConfiguration.impl.EndPointImpl
		 * @see com.jennic.ZPSConfiguration.impl.ZPSConfigurationPackageImpl#getEndPoint()
		 * @generated
		 */
		EClass END_POINT = eINSTANCE.getEndPoint();

		/**
		 * The meta object literal for the '<em><b>Input Clusters</b></em>' containment reference list feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EReference END_POINT__INPUT_CLUSTERS = eINSTANCE.getEndPoint_InputClusters();

		/**
		 * The meta object literal for the '<em><b>Output Clusters</b></em>' containment reference list feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EReference END_POINT__OUTPUT_CLUSTERS = eINSTANCE.getEndPoint_OutputClusters();

		/**
		 * The meta object literal for the '<em><b>Id</b></em>' attribute feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EAttribute END_POINT__ID = eINSTANCE.getEndPoint_Id();

		/**
		 * The meta object literal for the '<em><b>Enabled</b></em>' attribute feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EAttribute END_POINT__ENABLED = eINSTANCE.getEndPoint_Enabled();

		/**
		 * The meta object literal for the '<em><b>Application Device Id</b></em>' attribute feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EAttribute END_POINT__APPLICATION_DEVICE_ID = eINSTANCE.getEndPoint_ApplicationDeviceId();

		/**
		 * The meta object literal for the '<em><b>Application Device Version</b></em>' attribute feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EAttribute END_POINT__APPLICATION_DEVICE_VERSION = eINSTANCE.getEndPoint_ApplicationDeviceVersion();

		/**
		 * The meta object literal for the '<em><b>Profile</b></em>' reference feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EReference END_POINT__PROFILE = eINSTANCE.getEndPoint_Profile();

		/**
		 * The meta object literal for the '<em><b>Message</b></em>' attribute feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EAttribute END_POINT__MESSAGE = eINSTANCE.getEndPoint_Message();

		/**
		 * The meta object literal for the '<em><b>Node</b></em>' container reference feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EReference END_POINT__NODE = eINSTANCE.getEndPoint_Node();

		/**
		 * The meta object literal for the '<em><b>Name</b></em>' attribute feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EAttribute END_POINT__NAME = eINSTANCE.getEndPoint_Name();

		/**
		 * The meta object literal for the '{@link com.jennic.ZPSConfiguration.impl.PrimaryDiscoveryCacheImpl <em>Primary Discovery Cache</em>}' class.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @see com.jennic.ZPSConfiguration.impl.PrimaryDiscoveryCacheImpl
		 * @see com.jennic.ZPSConfiguration.impl.ZPSConfigurationPackageImpl#getPrimaryDiscoveryCache()
		 * @generated
		 */
		EClass PRIMARY_DISCOVERY_CACHE = eINSTANCE.getPrimaryDiscoveryCache();

		/**
		 * The meta object literal for the '<em><b>Size</b></em>' attribute feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EAttribute PRIMARY_DISCOVERY_CACHE__SIZE = eINSTANCE.getPrimaryDiscoveryCache_Size();

		/**
		 * The meta object literal for the '{@link com.jennic.ZPSConfiguration.impl.BackupDiscoveryCacheImpl <em>Backup Discovery Cache</em>}' class.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @see com.jennic.ZPSConfiguration.impl.BackupDiscoveryCacheImpl
		 * @see com.jennic.ZPSConfiguration.impl.ZPSConfigurationPackageImpl#getBackupDiscoveryCache()
		 * @generated
		 */
		EClass BACKUP_DISCOVERY_CACHE = eINSTANCE.getBackupDiscoveryCache();

		/**
		 * The meta object literal for the '<em><b>Size</b></em>' attribute feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EAttribute BACKUP_DISCOVERY_CACHE__SIZE = eINSTANCE.getBackupDiscoveryCache_Size();

		/**
		 * The meta object literal for the '{@link com.jennic.ZPSConfiguration.impl.DiscoveryTableImpl <em>Discovery Table</em>}' class.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @see com.jennic.ZPSConfiguration.impl.DiscoveryTableImpl
		 * @see com.jennic.ZPSConfiguration.impl.ZPSConfigurationPackageImpl#getDiscoveryTable()
		 * @generated
		 */
		EClass DISCOVERY_TABLE = eINSTANCE.getDiscoveryTable();

		/**
		 * The meta object literal for the '<em><b>Size</b></em>' attribute feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EAttribute DISCOVERY_TABLE__SIZE = eINSTANCE.getDiscoveryTable_Size();

		/**
		 * The meta object literal for the '{@link com.jennic.ZPSConfiguration.impl.BindingTableImpl <em>Binding Table</em>}' class.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @see com.jennic.ZPSConfiguration.impl.BindingTableImpl
		 * @see com.jennic.ZPSConfiguration.impl.ZPSConfigurationPackageImpl#getBindingTable()
		 * @generated
		 */
		EClass BINDING_TABLE = eINSTANCE.getBindingTable();

		/**
		 * The meta object literal for the '<em><b>Size</b></em>' attribute feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EAttribute BINDING_TABLE__SIZE = eINSTANCE.getBindingTable_Size();

		/**
		 * The meta object literal for the '{@link com.jennic.ZPSConfiguration.impl.GroupTableImpl <em>Group Table</em>}' class.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @see com.jennic.ZPSConfiguration.impl.GroupTableImpl
		 * @see com.jennic.ZPSConfiguration.impl.ZPSConfigurationPackageImpl#getGroupTable()
		 * @generated
		 */
		EClass GROUP_TABLE = eINSTANCE.getGroupTable();

		/**
		 * The meta object literal for the '<em><b>Size</b></em>' attribute feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EAttribute GROUP_TABLE__SIZE = eINSTANCE.getGroupTable_Size();

		/**
		 * The meta object literal for the '{@link com.jennic.ZPSConfiguration.impl.ZigbeeWirelessNetworkImpl <em>Zigbee Wireless Network</em>}' class.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @see com.jennic.ZPSConfiguration.impl.ZigbeeWirelessNetworkImpl
		 * @see com.jennic.ZPSConfiguration.impl.ZPSConfigurationPackageImpl#getZigbeeWirelessNetwork()
		 * @generated
		 */
		EClass ZIGBEE_WIRELESS_NETWORK = eINSTANCE.getZigbeeWirelessNetwork();

		/**
		 * The meta object literal for the '<em><b>Profiles</b></em>' containment reference list feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EReference ZIGBEE_WIRELESS_NETWORK__PROFILES = eINSTANCE.getZigbeeWirelessNetwork_Profiles();

		/**
		 * The meta object literal for the '<em><b>Coordinator</b></em>' containment reference feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EReference ZIGBEE_WIRELESS_NETWORK__COORDINATOR = eINSTANCE.getZigbeeWirelessNetwork_Coordinator();

		/**
		 * The meta object literal for the '<em><b>Child Nodes</b></em>' containment reference list feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EReference ZIGBEE_WIRELESS_NETWORK__CHILD_NODES = eINSTANCE.getZigbeeWirelessNetwork_ChildNodes();

		/**
		 * The meta object literal for the '<em><b>Default Extended PAN Id</b></em>' attribute feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EAttribute ZIGBEE_WIRELESS_NETWORK__DEFAULT_EXTENDED_PAN_ID = eINSTANCE.getZigbeeWirelessNetwork_DefaultExtendedPANId();

		/**
		 * The meta object literal for the '<em><b>Max Number Nodes</b></em>' attribute feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EAttribute ZIGBEE_WIRELESS_NETWORK__MAX_NUMBER_NODES = eINSTANCE.getZigbeeWirelessNetwork_MaxNumberNodes();

		/**
		 * The meta object literal for the '<em><b>Version</b></em>' attribute feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EAttribute ZIGBEE_WIRELESS_NETWORK__VERSION = eINSTANCE.getZigbeeWirelessNetwork_Version();

		/**
		 * The meta object literal for the '<em><b>Default Security Enabled</b></em>' attribute feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EAttribute ZIGBEE_WIRELESS_NETWORK__DEFAULT_SECURITY_ENABLED = eINSTANCE.getZigbeeWirelessNetwork_DefaultSecurityEnabled();

		/**
		 * The meta object literal for the '{@link com.jennic.ZPSConfiguration.impl.PrimaryBindingCacheImpl <em>Primary Binding Cache</em>}' class.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @see com.jennic.ZPSConfiguration.impl.PrimaryBindingCacheImpl
		 * @see com.jennic.ZPSConfiguration.impl.ZPSConfigurationPackageImpl#getPrimaryBindingCache()
		 * @generated
		 */
		EClass PRIMARY_BINDING_CACHE = eINSTANCE.getPrimaryBindingCache();

		/**
		 * The meta object literal for the '<em><b>Table Size</b></em>' attribute feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EAttribute PRIMARY_BINDING_CACHE__TABLE_SIZE = eINSTANCE.getPrimaryBindingCache_TableSize();

		/**
		 * The meta object literal for the '<em><b>Num Tables</b></em>' attribute feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EAttribute PRIMARY_BINDING_CACHE__NUM_TABLES = eINSTANCE.getPrimaryBindingCache_NumTables();

		/**
		 * The meta object literal for the '{@link com.jennic.ZPSConfiguration.impl.BackupBindingCacheImpl <em>Backup Binding Cache</em>}' class.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @see com.jennic.ZPSConfiguration.impl.BackupBindingCacheImpl
		 * @see com.jennic.ZPSConfiguration.impl.ZPSConfigurationPackageImpl#getBackupBindingCache()
		 * @generated
		 */
		EClass BACKUP_BINDING_CACHE = eINSTANCE.getBackupBindingCache();

		/**
		 * The meta object literal for the '<em><b>Table Size</b></em>' attribute feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EAttribute BACKUP_BINDING_CACHE__TABLE_SIZE = eINSTANCE.getBackupBindingCache_TableSize();

		/**
		 * The meta object literal for the '<em><b>Num Tables</b></em>' attribute feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EAttribute BACKUP_BINDING_CACHE__NUM_TABLES = eINSTANCE.getBackupBindingCache_NumTables();

		/**
		 * The meta object literal for the '{@link com.jennic.ZPSConfiguration.impl.PrimaryGroupCacheImpl <em>Primary Group Cache</em>}' class.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @see com.jennic.ZPSConfiguration.impl.PrimaryGroupCacheImpl
		 * @see com.jennic.ZPSConfiguration.impl.ZPSConfigurationPackageImpl#getPrimaryGroupCache()
		 * @generated
		 */
		EClass PRIMARY_GROUP_CACHE = eINSTANCE.getPrimaryGroupCache();

		/**
		 * The meta object literal for the '<em><b>Size</b></em>' attribute feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EAttribute PRIMARY_GROUP_CACHE__SIZE = eINSTANCE.getPrimaryGroupCache_Size();

		/**
		 * The meta object literal for the '{@link com.jennic.ZPSConfiguration.impl.BackupGroupCacheImpl <em>Backup Group Cache</em>}' class.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @see com.jennic.ZPSConfiguration.impl.BackupGroupCacheImpl
		 * @see com.jennic.ZPSConfiguration.impl.ZPSConfigurationPackageImpl#getBackupGroupCache()
		 * @generated
		 */
		EClass BACKUP_GROUP_CACHE = eINSTANCE.getBackupGroupCache();

		/**
		 * The meta object literal for the '<em><b>Size</b></em>' attribute feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EAttribute BACKUP_GROUP_CACHE__SIZE = eINSTANCE.getBackupGroupCache_Size();

		/**
		 * The meta object literal for the '{@link com.jennic.ZPSConfiguration.impl.InputClusterImpl <em>Input Cluster</em>}' class.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @see com.jennic.ZPSConfiguration.impl.InputClusterImpl
		 * @see com.jennic.ZPSConfiguration.impl.ZPSConfigurationPackageImpl#getInputCluster()
		 * @generated
		 */
		EClass INPUT_CLUSTER = eINSTANCE.getInputCluster();

		/**
		 * The meta object literal for the '<em><b>Cluster</b></em>' reference feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EReference INPUT_CLUSTER__CLUSTER = eINSTANCE.getInputCluster_Cluster();

		/**
		 * The meta object literal for the '<em><b>Rx APDU</b></em>' reference feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EReference INPUT_CLUSTER__RX_APDU = eINSTANCE.getInputCluster_RxAPDU();

		/**
		 * The meta object literal for the '<em><b>End Point</b></em>' container reference feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EReference INPUT_CLUSTER__END_POINT = eINSTANCE.getInputCluster_EndPoint();

		/**
		 * The meta object literal for the '<em><b>Discoverable</b></em>' attribute feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EAttribute INPUT_CLUSTER__DISCOVERABLE = eINSTANCE.getInputCluster_Discoverable();

		/**
		 * The meta object literal for the '{@link com.jennic.ZPSConfiguration.impl.OutputClusterImpl <em>Output Cluster</em>}' class.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @see com.jennic.ZPSConfiguration.impl.OutputClusterImpl
		 * @see com.jennic.ZPSConfiguration.impl.ZPSConfigurationPackageImpl#getOutputCluster()
		 * @generated
		 */
		EClass OUTPUT_CLUSTER = eINSTANCE.getOutputCluster();

		/**
		 * The meta object literal for the '<em><b>Cluster</b></em>' reference feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EReference OUTPUT_CLUSTER__CLUSTER = eINSTANCE.getOutputCluster_Cluster();

		/**
		 * The meta object literal for the '<em><b>End Point</b></em>' container reference feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EReference OUTPUT_CLUSTER__END_POINT = eINSTANCE.getOutputCluster_EndPoint();

		/**
		 * The meta object literal for the '<em><b>Tx APD Us</b></em>' reference list feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EReference OUTPUT_CLUSTER__TX_APD_US = eINSTANCE.getOutputCluster_TxAPDUs();

		/**
		 * The meta object literal for the '<em><b>Discoverable</b></em>' attribute feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EAttribute OUTPUT_CLUSTER__DISCOVERABLE = eINSTANCE.getOutputCluster_Discoverable();

		/**
		 * The meta object literal for the '{@link com.jennic.ZPSConfiguration.impl.AlwaysOnNodeImpl <em>Always On Node</em>}' class.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @see com.jennic.ZPSConfiguration.impl.AlwaysOnNodeImpl
		 * @see com.jennic.ZPSConfiguration.impl.ZPSConfigurationPackageImpl#getAlwaysOnNode()
		 * @generated
		 */
		EClass ALWAYS_ON_NODE = eINSTANCE.getAlwaysOnNode();

		/**
		 * The meta object literal for the '<em><b>Trust Center</b></em>' containment reference feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EReference ALWAYS_ON_NODE__TRUST_CENTER = eINSTANCE.getAlwaysOnNode_TrustCenter();

		/**
		 * The meta object literal for the '<em><b>Permit Joining Time</b></em>' attribute feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EAttribute ALWAYS_ON_NODE__PERMIT_JOINING_TIME = eINSTANCE.getAlwaysOnNode_PermitJoiningTime();

		/**
		 * The meta object literal for the '<em><b>Child Table Size</b></em>' attribute feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EAttribute ALWAYS_ON_NODE__CHILD_TABLE_SIZE = eINSTANCE.getAlwaysOnNode_ChildTableSize();

		/**
		 * The meta object literal for the '{@link com.jennic.ZPSConfiguration.impl.ComplexDescriptorImpl <em>Complex Descriptor</em>}' class.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @see com.jennic.ZPSConfiguration.impl.ComplexDescriptorImpl
		 * @see com.jennic.ZPSConfiguration.impl.ZPSConfigurationPackageImpl#getComplexDescriptor()
		 * @generated
		 */
		EClass COMPLEX_DESCRIPTOR = eINSTANCE.getComplexDescriptor();

		/**
		 * The meta object literal for the '{@link com.jennic.ZPSConfiguration.impl.UserDescriptorImpl <em>User Descriptor</em>}' class.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @see com.jennic.ZPSConfiguration.impl.UserDescriptorImpl
		 * @see com.jennic.ZPSConfiguration.impl.ZPSConfigurationPackageImpl#getUserDescriptor()
		 * @generated
		 */
		EClass USER_DESCRIPTOR = eINSTANCE.getUserDescriptor();

		/**
		 * The meta object literal for the '<em><b>User Description</b></em>' attribute feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EAttribute USER_DESCRIPTOR__USER_DESCRIPTION = eINSTANCE.getUserDescriptor_UserDescription();

		/**
		 * The meta object literal for the '{@link com.jennic.ZPSConfiguration.impl.TrustCenterImpl <em>Trust Center</em>}' class.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @see com.jennic.ZPSConfiguration.impl.TrustCenterImpl
		 * @see com.jennic.ZPSConfiguration.impl.ZPSConfigurationPackageImpl#getTrustCenter()
		 * @generated
		 */
		EClass TRUST_CENTER = eINSTANCE.getTrustCenter();

		/**
		 * The meta object literal for the '<em><b>Device Table Size</b></em>' attribute feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EAttribute TRUST_CENTER__DEVICE_TABLE_SIZE = eINSTANCE.getTrustCenter_DeviceTableSize();

		/**
		 * The meta object literal for the '<em><b>Keys</b></em>' containment reference feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EReference TRUST_CENTER__KEYS = eINSTANCE.getTrustCenter_Keys();

		/**
		 * The meta object literal for the '{@link com.jennic.ZPSConfiguration.impl.DiscoveryCacheImpl <em>Discovery Cache</em>}' class.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @see com.jennic.ZPSConfiguration.impl.DiscoveryCacheImpl
		 * @see com.jennic.ZPSConfiguration.impl.ZPSConfigurationPackageImpl#getDiscoveryCache()
		 * @generated
		 */
		EClass DISCOVERY_CACHE = eINSTANCE.getDiscoveryCache();

		/**
		 * The meta object literal for the '{@link com.jennic.ZPSConfiguration.impl.BindingCacheImpl <em>Binding Cache</em>}' class.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @see com.jennic.ZPSConfiguration.impl.BindingCacheImpl
		 * @see com.jennic.ZPSConfiguration.impl.ZPSConfigurationPackageImpl#getBindingCache()
		 * @generated
		 */
		EClass BINDING_CACHE = eINSTANCE.getBindingCache();

		/**
		 * The meta object literal for the '{@link com.jennic.ZPSConfiguration.impl.NamedObjectImpl <em>Named Object</em>}' class.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @see com.jennic.ZPSConfiguration.impl.NamedObjectImpl
		 * @see com.jennic.ZPSConfiguration.impl.ZPSConfigurationPackageImpl#getNamedObject()
		 * @generated
		 */
		EClass NAMED_OBJECT = eINSTANCE.getNamedObject();

		/**
		 * The meta object literal for the '<em><b>Name</b></em>' attribute feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EAttribute NAMED_OBJECT__NAME = eINSTANCE.getNamedObject_Name();

		/**
		 * The meta object literal for the '{@link com.jennic.ZPSConfiguration.impl.ChildNodesImpl <em>Child Nodes</em>}' class.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @see com.jennic.ZPSConfiguration.impl.ChildNodesImpl
		 * @see com.jennic.ZPSConfiguration.impl.ZPSConfigurationPackageImpl#getChildNodes()
		 * @generated
		 */
		EClass CHILD_NODES = eINSTANCE.getChildNodes();

		/**
		 * The meta object literal for the '<em><b>Scan Duration</b></em>' attribute feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EAttribute CHILD_NODES__SCAN_DURATION = eINSTANCE.getChildNodes_ScanDuration();

		/**
		 * The meta object literal for the '<em><b>Network Selection</b></em>' attribute feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EAttribute CHILD_NODES__NETWORK_SELECTION = eINSTANCE.getChildNodes_NetworkSelection();

		/**
		 * The meta object literal for the '{@link com.jennic.ZPSConfiguration.impl.APDUImpl <em>APDU</em>}' class.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @see com.jennic.ZPSConfiguration.impl.APDUImpl
		 * @see com.jennic.ZPSConfiguration.impl.ZPSConfigurationPackageImpl#getAPDU()
		 * @generated
		 */
		EClass APDU = eINSTANCE.getAPDU();

		/**
		 * The meta object literal for the '<em><b>Id</b></em>' attribute feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EAttribute APDU__ID = eINSTANCE.getAPDU_Id();

		/**
		 * The meta object literal for the '<em><b>Name</b></em>' attribute feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EAttribute APDU__NAME = eINSTANCE.getAPDU_Name();

		/**
		 * The meta object literal for the '<em><b>Size</b></em>' attribute feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EAttribute APDU__SIZE = eINSTANCE.getAPDU_Size();

		/**
		 * The meta object literal for the '<em><b>Instances</b></em>' attribute feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EAttribute APDU__INSTANCES = eINSTANCE.getAPDU_Instances();

		/**
		 * The meta object literal for the '<em><b>PDU Config</b></em>' container reference feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EReference APDU__PDU_CONFIG = eINSTANCE.getAPDU_PDUConfig();

		/**
		 * The meta object literal for the '{@link com.jennic.ZPSConfiguration.impl.PDUManagerImpl <em>PDU Manager</em>}' class.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @see com.jennic.ZPSConfiguration.impl.PDUManagerImpl
		 * @see com.jennic.ZPSConfiguration.impl.ZPSConfigurationPackageImpl#getPDUManager()
		 * @generated
		 */
		EClass PDU_MANAGER = eINSTANCE.getPDUManager();

		/**
		 * The meta object literal for the '<em><b>APD Us</b></em>' containment reference list feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EReference PDU_MANAGER__APD_US = eINSTANCE.getPDUManager_APDUs();

		/**
		 * The meta object literal for the '<em><b>Container Node</b></em>' container reference feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EReference PDU_MANAGER__CONTAINER_NODE = eINSTANCE.getPDUManager_ContainerNode();

		/**
		 * The meta object literal for the '<em><b>Num NPD Us</b></em>' attribute feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EAttribute PDU_MANAGER__NUM_NPD_US = eINSTANCE.getPDUManager_NumNPDUs();

		/**
		 * The meta object literal for the '<em><b>PDUM Mutex Name</b></em>' attribute feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EAttribute PDU_MANAGER__PDUM_MUTEX_NAME = eINSTANCE.getPDUManager_PDUMMutexName();

		/**
		 * The meta object literal for the '{@link com.jennic.ZPSConfiguration.impl.ChannelMaskImpl <em>Channel Mask</em>}' class.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @see com.jennic.ZPSConfiguration.impl.ChannelMaskImpl
		 * @see com.jennic.ZPSConfiguration.impl.ZPSConfigurationPackageImpl#getChannelMask()
		 * @generated
		 */
		EClass CHANNEL_MASK = eINSTANCE.getChannelMask();

		/**
		 * The meta object literal for the '<em><b>Channel11</b></em>' attribute feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EAttribute CHANNEL_MASK__CHANNEL11 = eINSTANCE.getChannelMask_Channel11();

		/**
		 * The meta object literal for the '<em><b>Channel12</b></em>' attribute feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EAttribute CHANNEL_MASK__CHANNEL12 = eINSTANCE.getChannelMask_Channel12();

		/**
		 * The meta object literal for the '<em><b>Channel13</b></em>' attribute feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EAttribute CHANNEL_MASK__CHANNEL13 = eINSTANCE.getChannelMask_Channel13();

		/**
		 * The meta object literal for the '<em><b>Channel14</b></em>' attribute feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EAttribute CHANNEL_MASK__CHANNEL14 = eINSTANCE.getChannelMask_Channel14();

		/**
		 * The meta object literal for the '<em><b>Channel15</b></em>' attribute feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EAttribute CHANNEL_MASK__CHANNEL15 = eINSTANCE.getChannelMask_Channel15();

		/**
		 * The meta object literal for the '<em><b>Channel16</b></em>' attribute feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EAttribute CHANNEL_MASK__CHANNEL16 = eINSTANCE.getChannelMask_Channel16();

		/**
		 * The meta object literal for the '<em><b>Channel17</b></em>' attribute feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EAttribute CHANNEL_MASK__CHANNEL17 = eINSTANCE.getChannelMask_Channel17();

		/**
		 * The meta object literal for the '<em><b>Channel18</b></em>' attribute feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EAttribute CHANNEL_MASK__CHANNEL18 = eINSTANCE.getChannelMask_Channel18();

		/**
		 * The meta object literal for the '<em><b>Channel19</b></em>' attribute feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EAttribute CHANNEL_MASK__CHANNEL19 = eINSTANCE.getChannelMask_Channel19();

		/**
		 * The meta object literal for the '<em><b>Channel20</b></em>' attribute feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EAttribute CHANNEL_MASK__CHANNEL20 = eINSTANCE.getChannelMask_Channel20();

		/**
		 * The meta object literal for the '<em><b>Channel21</b></em>' attribute feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EAttribute CHANNEL_MASK__CHANNEL21 = eINSTANCE.getChannelMask_Channel21();

		/**
		 * The meta object literal for the '<em><b>Channel22</b></em>' attribute feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EAttribute CHANNEL_MASK__CHANNEL22 = eINSTANCE.getChannelMask_Channel22();

		/**
		 * The meta object literal for the '<em><b>Channel23</b></em>' attribute feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EAttribute CHANNEL_MASK__CHANNEL23 = eINSTANCE.getChannelMask_Channel23();

		/**
		 * The meta object literal for the '<em><b>Channel24</b></em>' attribute feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EAttribute CHANNEL_MASK__CHANNEL24 = eINSTANCE.getChannelMask_Channel24();

		/**
		 * The meta object literal for the '<em><b>Channel25</b></em>' attribute feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EAttribute CHANNEL_MASK__CHANNEL25 = eINSTANCE.getChannelMask_Channel25();

		/**
		 * The meta object literal for the '<em><b>Channel26</b></em>' attribute feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EAttribute CHANNEL_MASK__CHANNEL26 = eINSTANCE.getChannelMask_Channel26();

		/**
		 * The meta object literal for the '{@link com.jennic.ZPSConfiguration.impl.ZDOClientServerImpl <em>ZDO Client Server</em>}' class.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @see com.jennic.ZPSConfiguration.impl.ZDOClientServerImpl
		 * @see com.jennic.ZPSConfiguration.impl.ZPSConfigurationPackageImpl#getZDOClientServer()
		 * @generated
		 */
		EClass ZDO_CLIENT_SERVER = eINSTANCE.getZDOClientServer();

		/**
		 * The meta object literal for the '<em><b>Output APdu</b></em>' reference feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EReference ZDO_CLIENT_SERVER__OUTPUT_APDU = eINSTANCE.getZDOClientServer_OutputAPdu();

		/**
		 * The meta object literal for the '{@link com.jennic.ZPSConfiguration.impl.ZDOServersCoordinatorImpl <em>ZDO Servers Coordinator</em>}' class.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @see com.jennic.ZPSConfiguration.impl.ZDOServersCoordinatorImpl
		 * @see com.jennic.ZPSConfiguration.impl.ZPSConfigurationPackageImpl#getZDOServersCoordinator()
		 * @generated
		 */
		EClass ZDO_SERVERS_COORDINATOR = eINSTANCE.getZDOServersCoordinator();

		/**
		 * The meta object literal for the '<em><b>End Device Bind Server</b></em>' containment reference feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EReference ZDO_SERVERS_COORDINATOR__END_DEVICE_BIND_SERVER = eINSTANCE.getZDOServersCoordinator_EndDeviceBindServer();

		/**
		 * The meta object literal for the '{@link com.jennic.ZPSConfiguration.impl.EndDeviceBindServerImpl <em>End Device Bind Server</em>}' class.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @see com.jennic.ZPSConfiguration.impl.EndDeviceBindServerImpl
		 * @see com.jennic.ZPSConfiguration.impl.ZPSConfigurationPackageImpl#getEndDeviceBindServer()
		 * @generated
		 */
		EClass END_DEVICE_BIND_SERVER = eINSTANCE.getEndDeviceBindServer();

		/**
		 * The meta object literal for the '<em><b>Timeout</b></em>' attribute feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EAttribute END_DEVICE_BIND_SERVER__TIMEOUT = eINSTANCE.getEndDeviceBindServer_Timeout();

		/**
		 * The meta object literal for the '<em><b>Binding Timeout</b></em>' attribute feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EAttribute END_DEVICE_BIND_SERVER__BINDING_TIMEOUT = eINSTANCE.getEndDeviceBindServer_BindingTimeout();

		/**
		 * The meta object literal for the '<em><b>Bind Num Retries</b></em>' attribute feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EAttribute END_DEVICE_BIND_SERVER__BIND_NUM_RETRIES = eINSTANCE.getEndDeviceBindServer_BindNumRetries();

		/**
		 * The meta object literal for the '{@link com.jennic.ZPSConfiguration.impl.ZDOServersRouterImpl <em>ZDO Servers Router</em>}' class.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @see com.jennic.ZPSConfiguration.impl.ZDOServersRouterImpl
		 * @see com.jennic.ZPSConfiguration.impl.ZPSConfigurationPackageImpl#getZDOServersRouter()
		 * @generated
		 */
		EClass ZDO_SERVERS_ROUTER = eINSTANCE.getZDOServersRouter();

		/**
		 * The meta object literal for the '{@link com.jennic.ZPSConfiguration.impl.ZDOServersEndDeviceImpl <em>ZDO Servers End Device</em>}' class.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @see com.jennic.ZPSConfiguration.impl.ZDOServersEndDeviceImpl
		 * @see com.jennic.ZPSConfiguration.impl.ZPSConfigurationPackageImpl#getZDOServersEndDevice()
		 * @generated
		 */
		EClass ZDO_SERVERS_END_DEVICE = eINSTANCE.getZDOServersEndDevice();

		/**
		 * The meta object literal for the '{@link com.jennic.ZPSConfiguration.impl.DefaultServerImpl <em>Default Server</em>}' class.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @see com.jennic.ZPSConfiguration.impl.DefaultServerImpl
		 * @see com.jennic.ZPSConfiguration.impl.ZPSConfigurationPackageImpl#getDefaultServer()
		 * @generated
		 */
		EClass DEFAULT_SERVER = eINSTANCE.getDefaultServer();

		/**
		 * The meta object literal for the '{@link com.jennic.ZPSConfiguration.impl.DeviceAnnceServerImpl <em>Device Annce Server</em>}' class.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @see com.jennic.ZPSConfiguration.impl.DeviceAnnceServerImpl
		 * @see com.jennic.ZPSConfiguration.impl.ZPSConfigurationPackageImpl#getDeviceAnnceServer()
		 * @generated
		 */
		EClass DEVICE_ANNCE_SERVER = eINSTANCE.getDeviceAnnceServer();

		/**
		 * The meta object literal for the '{@link com.jennic.ZPSConfiguration.impl.ActiveEpServerImpl <em>Active Ep Server</em>}' class.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @see com.jennic.ZPSConfiguration.impl.ActiveEpServerImpl
		 * @see com.jennic.ZPSConfiguration.impl.ZPSConfigurationPackageImpl#getActiveEpServer()
		 * @generated
		 */
		EClass ACTIVE_EP_SERVER = eINSTANCE.getActiveEpServer();

		/**
		 * The meta object literal for the '{@link com.jennic.ZPSConfiguration.impl.NwkAddrServerImpl <em>Nwk Addr Server</em>}' class.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @see com.jennic.ZPSConfiguration.impl.NwkAddrServerImpl
		 * @see com.jennic.ZPSConfiguration.impl.ZPSConfigurationPackageImpl#getNwkAddrServer()
		 * @generated
		 */
		EClass NWK_ADDR_SERVER = eINSTANCE.getNwkAddrServer();

		/**
		 * The meta object literal for the '{@link com.jennic.ZPSConfiguration.impl.IeeeAddrServerImpl <em>Ieee Addr Server</em>}' class.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @see com.jennic.ZPSConfiguration.impl.IeeeAddrServerImpl
		 * @see com.jennic.ZPSConfiguration.impl.ZPSConfigurationPackageImpl#getIeeeAddrServer()
		 * @generated
		 */
		EClass IEEE_ADDR_SERVER = eINSTANCE.getIeeeAddrServer();

		/**
		 * The meta object literal for the '{@link com.jennic.ZPSConfiguration.impl.MatchDescServerImpl <em>Match Desc Server</em>}' class.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @see com.jennic.ZPSConfiguration.impl.MatchDescServerImpl
		 * @see com.jennic.ZPSConfiguration.impl.ZPSConfigurationPackageImpl#getMatchDescServer()
		 * @generated
		 */
		EClass MATCH_DESC_SERVER = eINSTANCE.getMatchDescServer();

		/**
		 * The meta object literal for the '{@link com.jennic.ZPSConfiguration.impl.NodeDescServerImpl <em>Node Desc Server</em>}' class.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @see com.jennic.ZPSConfiguration.impl.NodeDescServerImpl
		 * @see com.jennic.ZPSConfiguration.impl.ZPSConfigurationPackageImpl#getNodeDescServer()
		 * @generated
		 */
		EClass NODE_DESC_SERVER = eINSTANCE.getNodeDescServer();

		/**
		 * The meta object literal for the '{@link com.jennic.ZPSConfiguration.impl.PermitJoiningServerImpl <em>Permit Joining Server</em>}' class.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @see com.jennic.ZPSConfiguration.impl.PermitJoiningServerImpl
		 * @see com.jennic.ZPSConfiguration.impl.ZPSConfigurationPackageImpl#getPermitJoiningServer()
		 * @generated
		 */
		EClass PERMIT_JOINING_SERVER = eINSTANCE.getPermitJoiningServer();

		/**
		 * The meta object literal for the '{@link com.jennic.ZPSConfiguration.impl.PowerDescServerImpl <em>Power Desc Server</em>}' class.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @see com.jennic.ZPSConfiguration.impl.PowerDescServerImpl
		 * @see com.jennic.ZPSConfiguration.impl.ZPSConfigurationPackageImpl#getPowerDescServer()
		 * @generated
		 */
		EClass POWER_DESC_SERVER = eINSTANCE.getPowerDescServer();

		/**
		 * The meta object literal for the '{@link com.jennic.ZPSConfiguration.impl.SimpleDescServerImpl <em>Simple Desc Server</em>}' class.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @see com.jennic.ZPSConfiguration.impl.SimpleDescServerImpl
		 * @see com.jennic.ZPSConfiguration.impl.ZPSConfigurationPackageImpl#getSimpleDescServer()
		 * @generated
		 */
		EClass SIMPLE_DESC_SERVER = eINSTANCE.getSimpleDescServer();

		/**
		 * The meta object literal for the '{@link com.jennic.ZPSConfiguration.impl.SystemServerDiscoveryServerImpl <em>System Server Discovery Server</em>}' class.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @see com.jennic.ZPSConfiguration.impl.SystemServerDiscoveryServerImpl
		 * @see com.jennic.ZPSConfiguration.impl.ZPSConfigurationPackageImpl#getSystemServerDiscoveryServer()
		 * @generated
		 */
		EClass SYSTEM_SERVER_DISCOVERY_SERVER = eINSTANCE.getSystemServerDiscoveryServer();

		/**
		 * The meta object literal for the '{@link com.jennic.ZPSConfiguration.impl.MgmtLqiServerImpl <em>Mgmt Lqi Server</em>}' class.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @see com.jennic.ZPSConfiguration.impl.MgmtLqiServerImpl
		 * @see com.jennic.ZPSConfiguration.impl.ZPSConfigurationPackageImpl#getMgmtLqiServer()
		 * @generated
		 */
		EClass MGMT_LQI_SERVER = eINSTANCE.getMgmtLqiServer();

		/**
		 * The meta object literal for the '{@link com.jennic.ZPSConfiguration.impl.MgmtRtgServerImpl <em>Mgmt Rtg Server</em>}' class.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @see com.jennic.ZPSConfiguration.impl.MgmtRtgServerImpl
		 * @see com.jennic.ZPSConfiguration.impl.ZPSConfigurationPackageImpl#getMgmtRtgServer()
		 * @generated
		 */
		EClass MGMT_RTG_SERVER = eINSTANCE.getMgmtRtgServer();

		/**
		 * The meta object literal for the '{@link com.jennic.ZPSConfiguration.impl.MgmtLeaveServerImpl <em>Mgmt Leave Server</em>}' class.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @see com.jennic.ZPSConfiguration.impl.MgmtLeaveServerImpl
		 * @see com.jennic.ZPSConfiguration.impl.ZPSConfigurationPackageImpl#getMgmtLeaveServer()
		 * @generated
		 */
		EClass MGMT_LEAVE_SERVER = eINSTANCE.getMgmtLeaveServer();

		/**
		 * The meta object literal for the '{@link com.jennic.ZPSConfiguration.impl.NodeDescriptorImpl <em>Node Descriptor</em>}' class.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @see com.jennic.ZPSConfiguration.impl.NodeDescriptorImpl
		 * @see com.jennic.ZPSConfiguration.impl.ZPSConfigurationPackageImpl#getNodeDescriptor()
		 * @generated
		 */
		EClass NODE_DESCRIPTOR = eINSTANCE.getNodeDescriptor();

		/**
		 * The meta object literal for the '<em><b>Manufacturer Code</b></em>' attribute feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EAttribute NODE_DESCRIPTOR__MANUFACTURER_CODE = eINSTANCE.getNodeDescriptor_ManufacturerCode();

		/**
		 * The meta object literal for the '<em><b>Logical Type</b></em>' attribute feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EAttribute NODE_DESCRIPTOR__LOGICAL_TYPE = eINSTANCE.getNodeDescriptor_LogicalType();

		/**
		 * The meta object literal for the '<em><b>Complex Descriptor Available</b></em>' attribute feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EAttribute NODE_DESCRIPTOR__COMPLEX_DESCRIPTOR_AVAILABLE = eINSTANCE.getNodeDescriptor_ComplexDescriptorAvailable();

		/**
		 * The meta object literal for the '<em><b>User Descriptor Available</b></em>' attribute feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EAttribute NODE_DESCRIPTOR__USER_DESCRIPTOR_AVAILABLE = eINSTANCE.getNodeDescriptor_UserDescriptorAvailable();

		/**
		 * The meta object literal for the '<em><b>APS Flags</b></em>' attribute feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EAttribute NODE_DESCRIPTOR__APS_FLAGS = eINSTANCE.getNodeDescriptor_APSFlags();

		/**
		 * The meta object literal for the '<em><b>Frequency Band</b></em>' attribute feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EAttribute NODE_DESCRIPTOR__FREQUENCY_BAND = eINSTANCE.getNodeDescriptor_FrequencyBand();

		/**
		 * The meta object literal for the '<em><b>Alternate PAN Coordinator</b></em>' attribute feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EAttribute NODE_DESCRIPTOR__ALTERNATE_PAN_COORDINATOR = eINSTANCE.getNodeDescriptor_AlternatePANCoordinator();

		/**
		 * The meta object literal for the '<em><b>Device Type</b></em>' attribute feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EAttribute NODE_DESCRIPTOR__DEVICE_TYPE = eINSTANCE.getNodeDescriptor_DeviceType();

		/**
		 * The meta object literal for the '<em><b>Power Source</b></em>' attribute feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EAttribute NODE_DESCRIPTOR__POWER_SOURCE = eINSTANCE.getNodeDescriptor_PowerSource();

		/**
		 * The meta object literal for the '<em><b>Rx On When Idle</b></em>' attribute feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EAttribute NODE_DESCRIPTOR__RX_ON_WHEN_IDLE = eINSTANCE.getNodeDescriptor_RxOnWhenIdle();

		/**
		 * The meta object literal for the '<em><b>Security</b></em>' attribute feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EAttribute NODE_DESCRIPTOR__SECURITY = eINSTANCE.getNodeDescriptor_Security();

		/**
		 * The meta object literal for the '<em><b>Allocate Address</b></em>' attribute feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EAttribute NODE_DESCRIPTOR__ALLOCATE_ADDRESS = eINSTANCE.getNodeDescriptor_AllocateAddress();

		/**
		 * The meta object literal for the '<em><b>Maximum Buffer Size</b></em>' attribute feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EAttribute NODE_DESCRIPTOR__MAXIMUM_BUFFER_SIZE = eINSTANCE.getNodeDescriptor_MaximumBufferSize();

		/**
		 * The meta object literal for the '<em><b>Maximum Incoming Transfer Size</b></em>' attribute feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EAttribute NODE_DESCRIPTOR__MAXIMUM_INCOMING_TRANSFER_SIZE = eINSTANCE.getNodeDescriptor_MaximumIncomingTransferSize();

		/**
		 * The meta object literal for the '<em><b>Maximum Outgoing Transfer Size</b></em>' attribute feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EAttribute NODE_DESCRIPTOR__MAXIMUM_OUTGOING_TRANSFER_SIZE = eINSTANCE.getNodeDescriptor_MaximumOutgoingTransferSize();

		/**
		 * The meta object literal for the '<em><b>Extended Active Endpoint List Available</b></em>' attribute feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EAttribute NODE_DESCRIPTOR__EXTENDED_ACTIVE_ENDPOINT_LIST_AVAILABLE = eINSTANCE.getNodeDescriptor_ExtendedActiveEndpointListAvailable();

		/**
		 * The meta object literal for the '<em><b>Extended Simple Descriptor List Available</b></em>' attribute feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EAttribute NODE_DESCRIPTOR__EXTENDED_SIMPLE_DESCRIPTOR_LIST_AVAILABLE = eINSTANCE.getNodeDescriptor_ExtendedSimpleDescriptorListAvailable();

		/**
		 * The meta object literal for the '<em><b>Primary Trust Center</b></em>' attribute feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EAttribute NODE_DESCRIPTOR__PRIMARY_TRUST_CENTER = eINSTANCE.getNodeDescriptor_PrimaryTrustCenter();

		/**
		 * The meta object literal for the '<em><b>Backup Trust Center</b></em>' attribute feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EAttribute NODE_DESCRIPTOR__BACKUP_TRUST_CENTER = eINSTANCE.getNodeDescriptor_BackupTrustCenter();

		/**
		 * The meta object literal for the '<em><b>Primary Binding Table Cache</b></em>' attribute feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EAttribute NODE_DESCRIPTOR__PRIMARY_BINDING_TABLE_CACHE = eINSTANCE.getNodeDescriptor_PrimaryBindingTableCache();

		/**
		 * The meta object literal for the '<em><b>Backup Binding Table Cache</b></em>' attribute feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EAttribute NODE_DESCRIPTOR__BACKUP_BINDING_TABLE_CACHE = eINSTANCE.getNodeDescriptor_BackupBindingTableCache();

		/**
		 * The meta object literal for the '<em><b>Primary Discovery Cache</b></em>' attribute feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EAttribute NODE_DESCRIPTOR__PRIMARY_DISCOVERY_CACHE = eINSTANCE.getNodeDescriptor_PrimaryDiscoveryCache();

		/**
		 * The meta object literal for the '<em><b>Backup Discovery Cache</b></em>' attribute feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EAttribute NODE_DESCRIPTOR__BACKUP_DISCOVERY_CACHE = eINSTANCE.getNodeDescriptor_BackupDiscoveryCache();

		/**
		 * The meta object literal for the '<em><b>Node</b></em>' container reference feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EReference NODE_DESCRIPTOR__NODE = eINSTANCE.getNodeDescriptor_Node();

		/**
		 * The meta object literal for the '<em><b>Network Manager</b></em>' attribute feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EAttribute NODE_DESCRIPTOR__NETWORK_MANAGER = eINSTANCE.getNodeDescriptor_NetworkManager();

		/**
		 * The meta object literal for the '{@link com.jennic.ZPSConfiguration.impl.NodePowerDescriptorImpl <em>Node Power Descriptor</em>}' class.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @see com.jennic.ZPSConfiguration.impl.NodePowerDescriptorImpl
		 * @see com.jennic.ZPSConfiguration.impl.ZPSConfigurationPackageImpl#getNodePowerDescriptor()
		 * @generated
		 */
		EClass NODE_POWER_DESCRIPTOR = eINSTANCE.getNodePowerDescriptor();

		/**
		 * The meta object literal for the '<em><b>Constant Power</b></em>' attribute feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EAttribute NODE_POWER_DESCRIPTOR__CONSTANT_POWER = eINSTANCE.getNodePowerDescriptor_ConstantPower();

		/**
		 * The meta object literal for the '<em><b>Rechargeable Battery</b></em>' attribute feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EAttribute NODE_POWER_DESCRIPTOR__RECHARGEABLE_BATTERY = eINSTANCE.getNodePowerDescriptor_RechargeableBattery();

		/**
		 * The meta object literal for the '<em><b>Disposable Battery</b></em>' attribute feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EAttribute NODE_POWER_DESCRIPTOR__DISPOSABLE_BATTERY = eINSTANCE.getNodePowerDescriptor_DisposableBattery();

		/**
		 * The meta object literal for the '<em><b>Default Power Source</b></em>' attribute feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EAttribute NODE_POWER_DESCRIPTOR__DEFAULT_POWER_SOURCE = eINSTANCE.getNodePowerDescriptor_DefaultPowerSource();

		/**
		 * The meta object literal for the '<em><b>Default Power Mode</b></em>' attribute feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EAttribute NODE_POWER_DESCRIPTOR__DEFAULT_POWER_MODE = eINSTANCE.getNodePowerDescriptor_DefaultPowerMode();

		/**
		 * The meta object literal for the '{@link com.jennic.ZPSConfiguration.impl.BindUnbindServerImpl <em>Bind Unbind Server</em>}' class.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @see com.jennic.ZPSConfiguration.impl.BindUnbindServerImpl
		 * @see com.jennic.ZPSConfiguration.impl.ZPSConfigurationPackageImpl#getBindUnbindServer()
		 * @generated
		 */
		EClass BIND_UNBIND_SERVER = eINSTANCE.getBindUnbindServer();

		/**
		 * The meta object literal for the '{@link com.jennic.ZPSConfiguration.impl.MgmtBindServerImpl <em>Mgmt Bind Server</em>}' class.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @see com.jennic.ZPSConfiguration.impl.MgmtBindServerImpl
		 * @see com.jennic.ZPSConfiguration.impl.ZPSConfigurationPackageImpl#getMgmtBindServer()
		 * @generated
		 */
		EClass MGMT_BIND_SERVER = eINSTANCE.getMgmtBindServer();

		/**
		 * The meta object literal for the '{@link com.jennic.ZPSConfiguration.impl.ExtendedActiveEpServerImpl <em>Extended Active Ep Server</em>}' class.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @see com.jennic.ZPSConfiguration.impl.ExtendedActiveEpServerImpl
		 * @see com.jennic.ZPSConfiguration.impl.ZPSConfigurationPackageImpl#getExtendedActiveEpServer()
		 * @generated
		 */
		EClass EXTENDED_ACTIVE_EP_SERVER = eINSTANCE.getExtendedActiveEpServer();

		/**
		 * The meta object literal for the '{@link com.jennic.ZPSConfiguration.impl.ExtendedSimpleDescServerImpl <em>Extended Simple Desc Server</em>}' class.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @see com.jennic.ZPSConfiguration.impl.ExtendedSimpleDescServerImpl
		 * @see com.jennic.ZPSConfiguration.impl.ZPSConfigurationPackageImpl#getExtendedSimpleDescServer()
		 * @generated
		 */
		EClass EXTENDED_SIMPLE_DESC_SERVER = eINSTANCE.getExtendedSimpleDescServer();

		/**
		 * The meta object literal for the '{@link com.jennic.ZPSConfiguration.impl.ZdoClientImpl <em>Zdo Client</em>}' class.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @see com.jennic.ZPSConfiguration.impl.ZdoClientImpl
		 * @see com.jennic.ZPSConfiguration.impl.ZPSConfigurationPackageImpl#getZdoClient()
		 * @generated
		 */
		EClass ZDO_CLIENT = eINSTANCE.getZdoClient();

		/**
		 * The meta object literal for the '{@link com.jennic.ZPSConfiguration.impl.MgmtNWKUpdateServerImpl <em>Mgmt NWK Update Server</em>}' class.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @see com.jennic.ZPSConfiguration.impl.MgmtNWKUpdateServerImpl
		 * @see com.jennic.ZPSConfiguration.impl.ZPSConfigurationPackageImpl#getMgmtNWKUpdateServer()
		 * @generated
		 */
		EClass MGMT_NWK_UPDATE_SERVER = eINSTANCE.getMgmtNWKUpdateServer();

		/**
		 * The meta object literal for the '{@link com.jennic.ZPSConfiguration.impl.ZDOCommonServersImpl <em>ZDO Common Servers</em>}' class.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @see com.jennic.ZPSConfiguration.impl.ZDOCommonServersImpl
		 * @see com.jennic.ZPSConfiguration.impl.ZPSConfigurationPackageImpl#getZDOCommonServers()
		 * @generated
		 */
		EClass ZDO_COMMON_SERVERS = eINSTANCE.getZDOCommonServers();

		/**
		 * The meta object literal for the '<em><b>Default Server</b></em>' containment reference feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EReference ZDO_COMMON_SERVERS__DEFAULT_SERVER = eINSTANCE.getZDOCommonServers_DefaultServer();

		/**
		 * The meta object literal for the '<em><b>Mgmt NWK Update Server</b></em>' containment reference feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EReference ZDO_COMMON_SERVERS__MGMT_NWK_UPDATE_SERVER = eINSTANCE.getZDOCommonServers_MgmtNWKUpdateServer();

		/**
		 * The meta object literal for the '<em><b>Zdo Client</b></em>' containment reference feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EReference ZDO_COMMON_SERVERS__ZDO_CLIENT = eINSTANCE.getZDOCommonServers_ZdoClient();

		/**
		 * The meta object literal for the '<em><b>Device Annce Server</b></em>' containment reference feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EReference ZDO_COMMON_SERVERS__DEVICE_ANNCE_SERVER = eINSTANCE.getZDOCommonServers_DeviceAnnceServer();

		/**
		 * The meta object literal for the '<em><b>Active Ep Server</b></em>' containment reference feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EReference ZDO_COMMON_SERVERS__ACTIVE_EP_SERVER = eINSTANCE.getZDOCommonServers_ActiveEpServer();

		/**
		 * The meta object literal for the '<em><b>Nwk Addr Server</b></em>' containment reference feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EReference ZDO_COMMON_SERVERS__NWK_ADDR_SERVER = eINSTANCE.getZDOCommonServers_NwkAddrServer();

		/**
		 * The meta object literal for the '<em><b>Ieee Addr Server</b></em>' containment reference feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EReference ZDO_COMMON_SERVERS__IEEE_ADDR_SERVER = eINSTANCE.getZDOCommonServers_IeeeAddrServer();

		/**
		 * The meta object literal for the '<em><b>System Server Discovery Server</b></em>' containment reference feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EReference ZDO_COMMON_SERVERS__SYSTEM_SERVER_DISCOVERY_SERVER = eINSTANCE.getZDOCommonServers_SystemServerDiscoveryServer();

		/**
		 * The meta object literal for the '<em><b>Node Desc Server</b></em>' containment reference feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EReference ZDO_COMMON_SERVERS__NODE_DESC_SERVER = eINSTANCE.getZDOCommonServers_NodeDescServer();

		/**
		 * The meta object literal for the '<em><b>Power Desc Server</b></em>' containment reference feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EReference ZDO_COMMON_SERVERS__POWER_DESC_SERVER = eINSTANCE.getZDOCommonServers_PowerDescServer();

		/**
		 * The meta object literal for the '<em><b>Match Desc Server</b></em>' containment reference feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EReference ZDO_COMMON_SERVERS__MATCH_DESC_SERVER = eINSTANCE.getZDOCommonServers_MatchDescServer();

		/**
		 * The meta object literal for the '<em><b>Simple Desc Server</b></em>' containment reference feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EReference ZDO_COMMON_SERVERS__SIMPLE_DESC_SERVER = eINSTANCE.getZDOCommonServers_SimpleDescServer();

		/**
		 * The meta object literal for the '<em><b>Mgmt Lqi Server</b></em>' containment reference feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EReference ZDO_COMMON_SERVERS__MGMT_LQI_SERVER = eINSTANCE.getZDOCommonServers_MgmtLqiServer();

		/**
		 * The meta object literal for the '<em><b>Mgmt Leave Server</b></em>' containment reference feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EReference ZDO_COMMON_SERVERS__MGMT_LEAVE_SERVER = eINSTANCE.getZDOCommonServers_MgmtLeaveServer();

		/**
		 * The meta object literal for the '<em><b>Bind Unbind Server</b></em>' containment reference feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EReference ZDO_COMMON_SERVERS__BIND_UNBIND_SERVER = eINSTANCE.getZDOCommonServers_BindUnbindServer();

		/**
		 * The meta object literal for the '<em><b>Extended Active Ep Server</b></em>' containment reference feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EReference ZDO_COMMON_SERVERS__EXTENDED_ACTIVE_EP_SERVER = eINSTANCE.getZDOCommonServers_ExtendedActiveEpServer();

		/**
		 * The meta object literal for the '<em><b>Extended Simple Desc Server</b></em>' containment reference feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EReference ZDO_COMMON_SERVERS__EXTENDED_SIMPLE_DESC_SERVER = eINSTANCE.getZDOCommonServers_ExtendedSimpleDescServer();

		/**
		 * The meta object literal for the '<em><b>Bind Request Server</b></em>' containment reference feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EReference ZDO_COMMON_SERVERS__BIND_REQUEST_SERVER = eINSTANCE.getZDOCommonServers_BindRequestServer();

		/**
		 * The meta object literal for the '<em><b>Mgmt Bind Server</b></em>' containment reference feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EReference ZDO_COMMON_SERVERS__MGMT_BIND_SERVER = eINSTANCE.getZDOCommonServers_MgmtBindServer();

		/**
		 * The meta object literal for the '<em><b>Mgmt NWK Enhance Update Server</b></em>' containment reference feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EReference ZDO_COMMON_SERVERS__MGMT_NWK_ENHANCE_UPDATE_SERVER = eINSTANCE.getZDOCommonServers_MgmtNWKEnhanceUpdateServer();

		/**
		 * The meta object literal for the '{@link com.jennic.ZPSConfiguration.impl.NotImplementedImpl <em>Not Implemented</em>}' class.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @see com.jennic.ZPSConfiguration.impl.NotImplementedImpl
		 * @see com.jennic.ZPSConfiguration.impl.ZPSConfigurationPackageImpl#getNotImplemented()
		 * @generated
		 */
		EClass NOT_IMPLEMENTED = eINSTANCE.getNotImplemented();

		/**
		 * The meta object literal for the '<em><b>Complex Descriptor</b></em>' containment reference feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EReference NOT_IMPLEMENTED__COMPLEX_DESCRIPTOR = eINSTANCE.getNotImplemented_ComplexDescriptor();

		/**
		 * The meta object literal for the '<em><b>Discovery Table</b></em>' containment reference feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EReference NOT_IMPLEMENTED__DISCOVERY_TABLE = eINSTANCE.getNotImplemented_DiscoveryTable();

		/**
		 * The meta object literal for the '<em><b>Discovery Cache</b></em>' containment reference feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EReference NOT_IMPLEMENTED__DISCOVERY_CACHE = eINSTANCE.getNotImplemented_DiscoveryCache();

		/**
		 * The meta object literal for the '<em><b>Binding Cache</b></em>' containment reference feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EReference NOT_IMPLEMENTED__BINDING_CACHE = eINSTANCE.getNotImplemented_BindingCache();

		/**
		 * The meta object literal for the '{@link com.jennic.ZPSConfiguration.impl.KeyDescriptorTableImpl <em>Key Descriptor Table</em>}' class.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @see com.jennic.ZPSConfiguration.impl.KeyDescriptorTableImpl
		 * @see com.jennic.ZPSConfiguration.impl.ZPSConfigurationPackageImpl#getKeyDescriptorTable()
		 * @generated
		 */
		EClass KEY_DESCRIPTOR_TABLE = eINSTANCE.getKeyDescriptorTable();

		/**
		 * The meta object literal for the '<em><b>Size</b></em>' attribute feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EAttribute KEY_DESCRIPTOR_TABLE__SIZE = eINSTANCE.getKeyDescriptorTable_Size();

		/**
		 * The meta object literal for the '<em><b>Preconfigured Key</b></em>' containment reference list feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EReference KEY_DESCRIPTOR_TABLE__PRECONFIGURED_KEY = eINSTANCE.getKeyDescriptorTable_PreconfiguredKey();

		/**
		 * The meta object literal for the '{@link com.jennic.ZPSConfiguration.impl.PreconfiguredKeyImpl <em>Preconfigured Key</em>}' class.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @see com.jennic.ZPSConfiguration.impl.PreconfiguredKeyImpl
		 * @see com.jennic.ZPSConfiguration.impl.ZPSConfigurationPackageImpl#getPreconfiguredKey()
		 * @generated
		 */
		EClass PRECONFIGURED_KEY = eINSTANCE.getPreconfiguredKey();

		/**
		 * The meta object literal for the '<em><b>Key</b></em>' attribute feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EAttribute PRECONFIGURED_KEY__KEY = eINSTANCE.getPreconfiguredKey_Key();

		/**
		 * The meta object literal for the '<em><b>IEEE Address</b></em>' attribute feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EAttribute PRECONFIGURED_KEY__IEEE_ADDRESS = eINSTANCE.getPreconfiguredKey_IEEEAddress();

		/**
		 * The meta object literal for the '{@link com.jennic.ZPSConfiguration.impl.ZDOCoordRouterOnlyServersImpl <em>ZDO Coord Router Only Servers</em>}' class.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @see com.jennic.ZPSConfiguration.impl.ZDOCoordRouterOnlyServersImpl
		 * @see com.jennic.ZPSConfiguration.impl.ZPSConfigurationPackageImpl#getZDOCoordRouterOnlyServers()
		 * @generated
		 */
		EClass ZDO_COORD_ROUTER_ONLY_SERVERS = eINSTANCE.getZDOCoordRouterOnlyServers();

		/**
		 * The meta object literal for the '<em><b>Permit Joining Server</b></em>' containment reference feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EReference ZDO_COORD_ROUTER_ONLY_SERVERS__PERMIT_JOINING_SERVER = eINSTANCE.getZDOCoordRouterOnlyServers_PermitJoiningServer();

		/**
		 * The meta object literal for the '<em><b>Mgmt Rtg Server</b></em>' containment reference feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EReference ZDO_COORD_ROUTER_ONLY_SERVERS__MGMT_RTG_SERVER = eINSTANCE.getZDOCoordRouterOnlyServers_MgmtRtgServer();

		/**
		 * The meta object literal for the '<em><b>Mgmt Mib Ieee Server</b></em>' containment reference feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EReference ZDO_COORD_ROUTER_ONLY_SERVERS__MGMT_MIB_IEEE_SERVER = eINSTANCE.getZDOCoordRouterOnlyServers_MgmtMibIeeeServer();

		/**
		 * The meta object literal for the '<em><b>Parent Annce Server</b></em>' containment reference feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EReference ZDO_COORD_ROUTER_ONLY_SERVERS__PARENT_ANNCE_SERVER = eINSTANCE.getZDOCoordRouterOnlyServers_ParentAnnceServer();

		/**
		 * The meta object literal for the '{@link com.jennic.ZPSConfiguration.impl.PreConfiguredNwkKeyImpl <em>Pre Configured Nwk Key</em>}' class.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @see com.jennic.ZPSConfiguration.impl.PreConfiguredNwkKeyImpl
		 * @see com.jennic.ZPSConfiguration.impl.ZPSConfigurationPackageImpl#getPreConfiguredNwkKey()
		 * @generated
		 */
		EClass PRE_CONFIGURED_NWK_KEY = eINSTANCE.getPreConfiguredNwkKey();

		/**
		 * The meta object literal for the '{@link com.jennic.ZPSConfiguration.impl.DefaultNwkKeyImpl <em>Default Nwk Key</em>}' class.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @see com.jennic.ZPSConfiguration.impl.DefaultNwkKeyImpl
		 * @see com.jennic.ZPSConfiguration.impl.ZPSConfigurationPackageImpl#getDefaultNwkKey()
		 * @generated
		 */
		EClass DEFAULT_NWK_KEY = eINSTANCE.getDefaultNwkKey();

		/**
		 * The meta object literal for the '<em><b>Random</b></em>' attribute feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EAttribute DEFAULT_NWK_KEY__RANDOM = eINSTANCE.getDefaultNwkKey_Random();

		/**
		 * The meta object literal for the '{@link com.jennic.ZPSConfiguration.impl.NwkKeyImpl <em>Nwk Key</em>}' class.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @see com.jennic.ZPSConfiguration.impl.NwkKeyImpl
		 * @see com.jennic.ZPSConfiguration.impl.ZPSConfigurationPackageImpl#getNwkKey()
		 * @generated
		 */
		EClass NWK_KEY = eINSTANCE.getNwkKey();

		/**
		 * The meta object literal for the '<em><b>Key Sequence Number</b></em>' attribute feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EAttribute NWK_KEY__KEY_SEQUENCE_NUMBER = eINSTANCE.getNwkKey_KeySequenceNumber();

		/**
		 * The meta object literal for the '<em><b>Key</b></em>' attribute feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EAttribute NWK_KEY__KEY = eINSTANCE.getNwkKey_Key();

		/**
		 * The meta object literal for the '<em><b>Id</b></em>' attribute feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EAttribute NWK_KEY__ID = eINSTANCE.getNwkKey_Id();

		/**
		 * The meta object literal for the '{@link com.jennic.ZPSConfiguration.impl.PreconfiguredTCLinkKeyImpl <em>Preconfigured TC Link Key</em>}' class.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @see com.jennic.ZPSConfiguration.impl.PreconfiguredTCLinkKeyImpl
		 * @see com.jennic.ZPSConfiguration.impl.ZPSConfigurationPackageImpl#getPreconfiguredTCLinkKey()
		 * @generated
		 */
		EClass PRECONFIGURED_TC_LINK_KEY = eINSTANCE.getPreconfiguredTCLinkKey();

		/**
		 * The meta object literal for the '<em><b>Id</b></em>' attribute feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EAttribute PRECONFIGURED_TC_LINK_KEY__ID = eINSTANCE.getPreconfiguredTCLinkKey_Id();

		/**
		 * The meta object literal for the '{@link com.jennic.ZPSConfiguration.impl.TCKeyImpl <em>TC Key</em>}' class.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @see com.jennic.ZPSConfiguration.impl.TCKeyImpl
		 * @see com.jennic.ZPSConfiguration.impl.ZPSConfigurationPackageImpl#getTCKey()
		 * @generated
		 */
		EClass TC_KEY = eINSTANCE.getTCKey();

		/**
		 * The meta object literal for the '{@link com.jennic.ZPSConfiguration.impl.BindRequestServerImpl <em>Bind Request Server</em>}' class.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @see com.jennic.ZPSConfiguration.impl.BindRequestServerImpl
		 * @see com.jennic.ZPSConfiguration.impl.ZPSConfigurationPackageImpl#getBindRequestServer()
		 * @generated
		 */
		EClass BIND_REQUEST_SERVER = eINSTANCE.getBindRequestServer();

		/**
		 * The meta object literal for the '<em><b>Simultaneous Requests</b></em>' attribute feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EAttribute BIND_REQUEST_SERVER__SIMULTANEOUS_REQUESTS = eINSTANCE.getBindRequestServer_SimultaneousRequests();

		/**
		 * The meta object literal for the '<em><b>Time Interval</b></em>' attribute feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EAttribute BIND_REQUEST_SERVER__TIME_INTERVAL = eINSTANCE.getBindRequestServer_TimeInterval();

		/**
		 * The meta object literal for the '{@link com.jennic.ZPSConfiguration.impl.GreenPowerSecurityTableImpl <em>Green Power Security Table</em>}' class.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @see com.jennic.ZPSConfiguration.impl.GreenPowerSecurityTableImpl
		 * @see com.jennic.ZPSConfiguration.impl.ZPSConfigurationPackageImpl#getGreenPowerSecurityTable()
		 * @generated
		 */
		EClass GREEN_POWER_SECURITY_TABLE = eINSTANCE.getGreenPowerSecurityTable();

		/**
		 * The meta object literal for the '<em><b>Size</b></em>' attribute feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EAttribute GREEN_POWER_SECURITY_TABLE__SIZE = eINSTANCE.getGreenPowerSecurityTable_Size();

		/**
		 * The meta object literal for the '{@link com.jennic.ZPSConfiguration.impl.GreenPowerTxQueueImpl <em>Green Power Tx Queue</em>}' class.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @see com.jennic.ZPSConfiguration.impl.GreenPowerTxQueueImpl
		 * @see com.jennic.ZPSConfiguration.impl.ZPSConfigurationPackageImpl#getGreenPowerTxQueue()
		 * @generated
		 */
		EClass GREEN_POWER_TX_QUEUE = eINSTANCE.getGreenPowerTxQueue();

		/**
		 * The meta object literal for the '<em><b>Size</b></em>' attribute feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EAttribute GREEN_POWER_TX_QUEUE__SIZE = eINSTANCE.getGreenPowerTxQueue_Size();

		/**
		 * The meta object literal for the '{@link com.jennic.ZPSConfiguration.impl.MgmtMibIeeeServerImpl <em>Mgmt Mib Ieee Server</em>}' class.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @see com.jennic.ZPSConfiguration.impl.MgmtMibIeeeServerImpl
		 * @see com.jennic.ZPSConfiguration.impl.ZPSConfigurationPackageImpl#getMgmtMibIeeeServer()
		 * @generated
		 */
		EClass MGMT_MIB_IEEE_SERVER = eINSTANCE.getMgmtMibIeeeServer();

		/**
		 * The meta object literal for the '{@link com.jennic.ZPSConfiguration.impl.MgmtNWKEnhanceUpdateServerImpl <em>Mgmt NWK Enhance Update Server</em>}' class.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @see com.jennic.ZPSConfiguration.impl.MgmtNWKEnhanceUpdateServerImpl
		 * @see com.jennic.ZPSConfiguration.impl.ZPSConfigurationPackageImpl#getMgmtNWKEnhanceUpdateServer()
		 * @generated
		 */
		EClass MGMT_NWK_ENHANCE_UPDATE_SERVER = eINSTANCE.getMgmtNWKEnhanceUpdateServer();

		/**
		 * The meta object literal for the '{@link com.jennic.ZPSConfiguration.impl.MacInterfaceListImpl <em>Mac Interface List</em>}' class.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @see com.jennic.ZPSConfiguration.impl.MacInterfaceListImpl
		 * @see com.jennic.ZPSConfiguration.impl.ZPSConfigurationPackageImpl#getMacInterfaceList()
		 * @generated
		 */
		EClass MAC_INTERFACE_LIST = eINSTANCE.getMacInterfaceList();

		/**
		 * The meta object literal for the '<em><b>Mac Interface</b></em>' containment reference list feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EReference MAC_INTERFACE_LIST__MAC_INTERFACE = eINSTANCE.getMacInterfaceList_MacInterface();

		/**
		 * The meta object literal for the '{@link com.jennic.ZPSConfiguration.impl.MacInterfaceImpl <em>Mac Interface</em>}' class.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @see com.jennic.ZPSConfiguration.impl.MacInterfaceImpl
		 * @see com.jennic.ZPSConfiguration.impl.ZPSConfigurationPackageImpl#getMacInterface()
		 * @generated
		 */
		EClass MAC_INTERFACE = eINSTANCE.getMacInterface();

		/**
		 * The meta object literal for the '<em><b>Router Allowed</b></em>' attribute feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EAttribute MAC_INTERFACE__ROUTER_ALLOWED = eINSTANCE.getMacInterface_RouterAllowed();

		/**
		 * The meta object literal for the '<em><b>Channel List Size</b></em>' attribute feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EAttribute MAC_INTERFACE__CHANNEL_LIST_SIZE = eINSTANCE.getMacInterface_ChannelListSize();

		/**
		 * The meta object literal for the '<em><b>Index</b></em>' attribute feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EAttribute MAC_INTERFACE__INDEX = eINSTANCE.getMacInterface_Index();

		/**
		 * The meta object literal for the '<em><b>Radio Type</b></em>' attribute feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EAttribute MAC_INTERFACE__RADIO_TYPE = eINSTANCE.getMacInterface_RadioType();

		/**
		 * The meta object literal for the '<em><b>Enabled</b></em>' attribute feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EAttribute MAC_INTERFACE__ENABLED = eINSTANCE.getMacInterface_Enabled();

		/**
		 * The meta object literal for the '{@link com.jennic.ZPSConfiguration.impl.ParentAnnceServerImpl <em>Parent Annce Server</em>}' class.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @see com.jennic.ZPSConfiguration.impl.ParentAnnceServerImpl
		 * @see com.jennic.ZPSConfiguration.impl.ZPSConfigurationPackageImpl#getParentAnnceServer()
		 * @generated
		 */
		EClass PARENT_ANNCE_SERVER = eINSTANCE.getParentAnnceServer();

		/**
		 * The meta object literal for the '{@link com.jennic.ZPSConfiguration.NodeLogicalType <em>Node Logical Type</em>}' enum.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @see com.jennic.ZPSConfiguration.NodeLogicalType
		 * @see com.jennic.ZPSConfiguration.impl.ZPSConfigurationPackageImpl#getNodeLogicalType()
		 * @generated
		 */
		EEnum NODE_LOGICAL_TYPE = eINSTANCE.getNodeLogicalType();

		/**
		 * The meta object literal for the '{@link com.jennic.ZPSConfiguration.FrequencyBands <em>Frequency Bands</em>}' enum.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @see com.jennic.ZPSConfiguration.FrequencyBands
		 * @see com.jennic.ZPSConfiguration.impl.ZPSConfigurationPackageImpl#getFrequencyBands()
		 * @generated
		 */
		EEnum FREQUENCY_BANDS = eINSTANCE.getFrequencyBands();

		/**
		 * The meta object literal for the '{@link com.jennic.ZPSConfiguration.PowerSources <em>Power Sources</em>}' enum.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @see com.jennic.ZPSConfiguration.PowerSources
		 * @see com.jennic.ZPSConfiguration.impl.ZPSConfigurationPackageImpl#getPowerSources()
		 * @generated
		 */
		EEnum POWER_SOURCES = eINSTANCE.getPowerSources();

		/**
		 * The meta object literal for the '{@link com.jennic.ZPSConfiguration.PowerModes <em>Power Modes</em>}' enum.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @see com.jennic.ZPSConfiguration.PowerModes
		 * @see com.jennic.ZPSConfiguration.impl.ZPSConfigurationPackageImpl#getPowerModes()
		 * @generated
		 */
		EEnum POWER_MODES = eINSTANCE.getPowerModes();

		/**
		 * The meta object literal for the '{@link com.jennic.ZPSConfiguration.NetworkSelectionTypes <em>Network Selection Types</em>}' enum.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @see com.jennic.ZPSConfiguration.NetworkSelectionTypes
		 * @see com.jennic.ZPSConfiguration.impl.ZPSConfigurationPackageImpl#getNetworkSelectionTypes()
		 * @generated
		 */
		EEnum NETWORK_SELECTION_TYPES = eINSTANCE.getNetworkSelectionTypes();

		/**
		 * The meta object literal for the '{@link com.jennic.ZPSConfiguration.RadioType <em>Radio Type</em>}' enum.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @see com.jennic.ZPSConfiguration.RadioType
		 * @see com.jennic.ZPSConfiguration.impl.ZPSConfigurationPackageImpl#getRadioType()
		 * @generated
		 */
		EEnum RADIO_TYPE = eINSTANCE.getRadioType();

		/**
		 * The meta object literal for the '<em>EU Short</em>' data type.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @see Integer
		 * @see com.jennic.ZPSConfiguration.impl.ZPSConfigurationPackageImpl#getEUShort()
		 * @generated
		 */
		EDataType EU_SHORT = eINSTANCE.getEUShort();

		/**
		 * The meta object literal for the '<em>EExt PAN Id</em>' data type.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @see BigInteger
		 * @see com.jennic.ZPSConfiguration.impl.ZPSConfigurationPackageImpl#getEExtPANId()
		 * @generated
		 */
		EDataType EEXT_PAN_ID = eINSTANCE.getEExtPANId();

		/**
		 * The meta object literal for the '<em>EPermit Joining</em>' data type.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @see Integer
		 * @see com.jennic.ZPSConfiguration.impl.ZPSConfigurationPackageImpl#getEPermitJoining()
		 * @generated
		 */
		EDataType EPERMIT_JOINING = eINSTANCE.getEPermitJoining();

		/**
		 * The meta object literal for the '<em>ESec Key</em>' data type.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @see BigInteger
		 * @see com.jennic.ZPSConfiguration.impl.ZPSConfigurationPackageImpl#getESecKey()
		 * @generated
		 */
		EDataType ESEC_KEY = eINSTANCE.getESecKey();

	}

} //ZPSConfigurationPackage
