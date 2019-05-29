/**
 * (C) Jennic Ltd
 *
 * $Id$
 */
package com.jennic.ZPSConfiguration.impl;


import java.math.BigInteger;

import java.util.Collection;

import org.eclipse.emf.common.notify.Notification;
import org.eclipse.emf.common.notify.NotificationChain;

import org.eclipse.emf.common.util.EList;

import org.eclipse.emf.ecore.EClass;
import org.eclipse.emf.ecore.InternalEObject;

import org.eclipse.emf.ecore.impl.ENotificationImpl;

import org.eclipse.emf.ecore.util.EObjectContainmentWithInverseEList;
import org.eclipse.emf.ecore.util.InternalEList;

import com.jennic.ZPSConfiguration.BindingTable;
import com.jennic.ZPSConfiguration.ChannelMask;
import com.jennic.ZPSConfiguration.EndPoint;
import com.jennic.ZPSConfiguration.GreenPowerSecurityTable;
import com.jennic.ZPSConfiguration.GreenPowerTxQueue;
import com.jennic.ZPSConfiguration.GroupTable;
import com.jennic.ZPSConfiguration.KeyDescriptorTable;
import com.jennic.ZPSConfiguration.MacInterfaceList;
import com.jennic.ZPSConfiguration.Node;
import com.jennic.ZPSConfiguration.NodeDescriptor;
import com.jennic.ZPSConfiguration.NodePowerDescriptor;
import com.jennic.ZPSConfiguration.PDUManager;
import com.jennic.ZPSConfiguration.TCKey;
import com.jennic.ZPSConfiguration.UserDescriptor;
import com.jennic.ZPSConfiguration.ZPSConfigurationFactory;
import com.jennic.ZPSConfiguration.ZPSConfigurationPackage;

/**
 * <!-- begin-user-doc -->
 * An implementation of the model object '<em><b>Node</b></em>'.
 * <!-- end-user-doc -->
 * <p>
 * The following features are implemented:
 * <ul>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.NodeImpl#getEndpoints <em>Endpoints</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.NodeImpl#getPDUConfiguration <em>PDU Configuration</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.NodeImpl#getChannelMask <em>Channel Mask</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.NodeImpl#getNodeDescriptor <em>Node Descriptor</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.NodeImpl#getNodePowerDescriptor <em>Node Power Descriptor</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.NodeImpl#getUserDescriptor <em>User Descriptor</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.NodeImpl#getBindingTable <em>Binding Table</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.NodeImpl#getGroupTable <em>Group Table</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.NodeImpl#getKeyDescriptorTable <em>Key Descriptor Table</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.NodeImpl#getGreenPowerTxQueue <em>Green Power Tx Queue</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.NodeImpl#getGreenPowerSecurityTable <em>Green Power Security Table</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.NodeImpl#getDiscoveryNeighbourTableSize <em>Discovery Neighbour Table Size</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.NodeImpl#getActiveNeighbourTableSize <em>Active Neighbour Table Size</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.NodeImpl#getRouteDiscoveryTableSize <em>Route Discovery Table Size</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.NodeImpl#getRoutingTableSize <em>Routing Table Size</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.NodeImpl#getBroadcastTransactionTableSize <em>Broadcast Transaction Table Size</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.NodeImpl#getRouteRecordTableSize <em>Route Record Table Size</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.NodeImpl#getAddressMapTableSize <em>Address Map Table Size</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.NodeImpl#getSecurityMaterialSets <em>Security Material Sets</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.NodeImpl#getMaxNumSimultaneousApsdeReq <em>Max Num Simultaneous Apsde Req</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.NodeImpl#getMaxNumSimultaneousApsdeAckReq <em>Max Num Simultaneous Apsde Ack Req</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.NodeImpl#getMACMutexName <em>MAC Mutex Name</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.NodeImpl#getZPSMutexName <em>ZPS Mutex Name</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.NodeImpl#getFragmentationMaxNumSimulRx <em>Fragmentation Max Num Simul Rx</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.NodeImpl#getFragmentationMaxNumSimulTx <em>Fragmentation Max Num Simul Tx</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.NodeImpl#getDefaultEventMessageName <em>Default Event Message Name</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.NodeImpl#getMACDcfmIndMessage <em>MAC Dcfm Ind Message</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.NodeImpl#getMACTimeEventMessage <em>MAC Time Event Message</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.NodeImpl#getApsNonMemberRadius <em>Aps Non Member Radius</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.NodeImpl#isApsDesignatedCoordinator <em>Aps Designated Coordinator</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.NodeImpl#isApsUseInsecureJoin <em>Aps Use Insecure Join</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.NodeImpl#getApsMaxWindowSize <em>Aps Max Window Size</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.NodeImpl#getApsInterframeDelay <em>Aps Interframe Delay</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.NodeImpl#getAPSDuplicateTableSize <em>APS Duplicate Table Size</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.NodeImpl#getApsSecurityTimeoutPeriod <em>Aps Security Timeout Period</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.NodeImpl#getApsUseExtPANId <em>Aps Use Ext PAN Id</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.NodeImpl#getInitialNetworkKey <em>Initial Network Key</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.NodeImpl#isSecurityEnabled <em>Security Enabled</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.NodeImpl#getMACMlmeDcfmIndMessage <em>MAC Mlme Dcfm Ind Message</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.NodeImpl#getMACMcpsDcfmIndMessage <em>MAC Mcps Dcfm Ind Message</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.NodeImpl#getAPSPersistenceTime <em>APS Persistence Time</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.NodeImpl#getNumAPSMESimulCommands <em>Num APSME Simul Commands</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.NodeImpl#getStackProfile <em>Stack Profile</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.NodeImpl#isInterPAN <em>Inter PAN</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.NodeImpl#isGreenPowerSupport <em>Green Power Support</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.NodeImpl#getNwkFcSaveCountBitShift <em>Nwk Fc Save Count Bit Shift</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.NodeImpl#getApsFcSaveCountBitShift <em>Aps Fc Save Count Bit Shift</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.NodeImpl#getMacTableSize <em>Mac Table Size</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.NodeImpl#getDefaultCallbackName <em>Default Callback Name</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.NodeImpl#getMacInterfaceList <em>Mac Interface List</em>}</li>
 * </ul>
 * </p>
 *
 * @generated
 */
public abstract class NodeImpl extends NamedObjectImpl implements Node {
	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public static final String copyright = "(C) NXP B.V";

	/**
	 * The cached value of the '{@link #getEndpoints() <em>Endpoints</em>}' containment reference list.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getEndpoints()
	 * @generated
	 * @ordered
	 */
	protected EList<EndPoint> endpoints;

	/**
	 * The cached value of the '{@link #getPDUConfiguration() <em>PDU Configuration</em>}' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getPDUConfiguration()
	 * @generated
	 * @ordered
	 */
	protected PDUManager pduConfiguration;

	/**
	 * The cached value of the '{@link #getChannelMask() <em>Channel Mask</em>}' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getChannelMask()
	 * @generated
	 * @ordered
	 */
	protected ChannelMask channelMask;

	/**
	 * The cached value of the '{@link #getNodeDescriptor() <em>Node Descriptor</em>}' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getNodeDescriptor()
	 * @generated
	 * @ordered
	 */
	protected NodeDescriptor nodeDescriptor;

	/**
	 * The cached value of the '{@link #getNodePowerDescriptor() <em>Node Power Descriptor</em>}' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getNodePowerDescriptor()
	 * @generated
	 * @ordered
	 */
	protected NodePowerDescriptor nodePowerDescriptor;

	/**
	 * The cached value of the '{@link #getUserDescriptor() <em>User Descriptor</em>}' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getUserDescriptor()
	 * @generated
	 * @ordered
	 */
	protected UserDescriptor userDescriptor;

	/**
	 * The cached value of the '{@link #getBindingTable() <em>Binding Table</em>}' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getBindingTable()
	 * @generated
	 * @ordered
	 */
	protected BindingTable bindingTable;

	/**
	 * The cached value of the '{@link #getGroupTable() <em>Group Table</em>}' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getGroupTable()
	 * @generated
	 * @ordered
	 */
	protected GroupTable groupTable;

	/**
	 * The cached value of the '{@link #getKeyDescriptorTable() <em>Key Descriptor Table</em>}' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getKeyDescriptorTable()
	 * @generated
	 * @ordered
	 */
	protected KeyDescriptorTable keyDescriptorTable;

	/**
	 * The cached value of the '{@link #getGreenPowerTxQueue() <em>Green Power Tx Queue</em>}' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getGreenPowerTxQueue()
	 * @generated
	 * @ordered
	 */
	protected GreenPowerTxQueue greenPowerTxQueue;

	/**
	 * The cached value of the '{@link #getGreenPowerSecurityTable() <em>Green Power Security Table</em>}' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getGreenPowerSecurityTable()
	 * @generated
	 * @ordered
	 */
	protected GreenPowerSecurityTable greenPowerSecurityTable;

	/**
	 * The default value of the '{@link #getDiscoveryNeighbourTableSize() <em>Discovery Neighbour Table Size</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getDiscoveryNeighbourTableSize()
	 * @generated
	 * @ordered
	 */
	protected static final BigInteger DISCOVERY_NEIGHBOUR_TABLE_SIZE_EDEFAULT = new BigInteger("16");

	/**
	 * The cached value of the '{@link #getDiscoveryNeighbourTableSize() <em>Discovery Neighbour Table Size</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getDiscoveryNeighbourTableSize()
	 * @generated
	 * @ordered
	 */
	protected BigInteger discoveryNeighbourTableSize = DISCOVERY_NEIGHBOUR_TABLE_SIZE_EDEFAULT;

	/**
	 * The default value of the '{@link #getActiveNeighbourTableSize() <em>Active Neighbour Table Size</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getActiveNeighbourTableSize()
	 * @generated
	 * @ordered
	 */
	protected static final BigInteger ACTIVE_NEIGHBOUR_TABLE_SIZE_EDEFAULT = new BigInteger("26");

	/**
	 * The cached value of the '{@link #getActiveNeighbourTableSize() <em>Active Neighbour Table Size</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getActiveNeighbourTableSize()
	 * @generated
	 * @ordered
	 */
	protected BigInteger activeNeighbourTableSize = ACTIVE_NEIGHBOUR_TABLE_SIZE_EDEFAULT;

	/**
	 * The default value of the '{@link #getRouteDiscoveryTableSize() <em>Route Discovery Table Size</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getRouteDiscoveryTableSize()
	 * @generated
	 * @ordered
	 */
	protected static final BigInteger ROUTE_DISCOVERY_TABLE_SIZE_EDEFAULT = new BigInteger("2");

	/**
	 * The cached value of the '{@link #getRouteDiscoveryTableSize() <em>Route Discovery Table Size</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getRouteDiscoveryTableSize()
	 * @generated
	 * @ordered
	 */
	protected BigInteger routeDiscoveryTableSize = ROUTE_DISCOVERY_TABLE_SIZE_EDEFAULT;

	/**
	 * The default value of the '{@link #getRoutingTableSize() <em>Routing Table Size</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getRoutingTableSize()
	 * @generated
	 * @ordered
	 */
	protected static final BigInteger ROUTING_TABLE_SIZE_EDEFAULT = new BigInteger("255");

	/**
	 * The cached value of the '{@link #getRoutingTableSize() <em>Routing Table Size</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getRoutingTableSize()
	 * @generated
	 * @ordered
	 */
	protected BigInteger routingTableSize = ROUTING_TABLE_SIZE_EDEFAULT;

	/**
	 * The default value of the '{@link #getBroadcastTransactionTableSize() <em>Broadcast Transaction Table Size</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getBroadcastTransactionTableSize()
	 * @generated
	 * @ordered
	 */
	protected static final BigInteger BROADCAST_TRANSACTION_TABLE_SIZE_EDEFAULT = new BigInteger("9");

	/**
	 * The cached value of the '{@link #getBroadcastTransactionTableSize() <em>Broadcast Transaction Table Size</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getBroadcastTransactionTableSize()
	 * @generated
	 * @ordered
	 */
	protected BigInteger broadcastTransactionTableSize = BROADCAST_TRANSACTION_TABLE_SIZE_EDEFAULT;

	/**
	 * The default value of the '{@link #getRouteRecordTableSize() <em>Route Record Table Size</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getRouteRecordTableSize()
	 * @generated
	 * @ordered
	 */
	protected static final BigInteger ROUTE_RECORD_TABLE_SIZE_EDEFAULT = new BigInteger("2");

	/**
	 * The cached value of the '{@link #getRouteRecordTableSize() <em>Route Record Table Size</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getRouteRecordTableSize()
	 * @generated
	 * @ordered
	 */
	protected BigInteger routeRecordTableSize = ROUTE_RECORD_TABLE_SIZE_EDEFAULT;

	/**
	 * The default value of the '{@link #getAddressMapTableSize() <em>Address Map Table Size</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getAddressMapTableSize()
	 * @generated
	 * @ordered
	 */
	protected static final BigInteger ADDRESS_MAP_TABLE_SIZE_EDEFAULT = new BigInteger("10");

	/**
	 * The cached value of the '{@link #getAddressMapTableSize() <em>Address Map Table Size</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getAddressMapTableSize()
	 * @generated
	 * @ordered
	 */
	protected BigInteger addressMapTableSize = ADDRESS_MAP_TABLE_SIZE_EDEFAULT;

	/**
	 * The default value of the '{@link #getSecurityMaterialSets() <em>Security Material Sets</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getSecurityMaterialSets()
	 * @generated
	 * @ordered
	 */
	protected static final BigInteger SECURITY_MATERIAL_SETS_EDEFAULT = new BigInteger("2");

	/**
	 * The cached value of the '{@link #getSecurityMaterialSets() <em>Security Material Sets</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getSecurityMaterialSets()
	 * @generated
	 * @ordered
	 */
	protected BigInteger securityMaterialSets = SECURITY_MATERIAL_SETS_EDEFAULT;

	/**
	 * The default value of the '{@link #getMaxNumSimultaneousApsdeReq() <em>Max Num Simultaneous Apsde Req</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getMaxNumSimultaneousApsdeReq()
	 * @generated
	 * @ordered
	 */
	protected static final int MAX_NUM_SIMULTANEOUS_APSDE_REQ_EDEFAULT = 5;

	/**
	 * The cached value of the '{@link #getMaxNumSimultaneousApsdeReq() <em>Max Num Simultaneous Apsde Req</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getMaxNumSimultaneousApsdeReq()
	 * @generated
	 * @ordered
	 */
	protected int maxNumSimultaneousApsdeReq = MAX_NUM_SIMULTANEOUS_APSDE_REQ_EDEFAULT;

	/**
	 * The default value of the '{@link #getMaxNumSimultaneousApsdeAckReq() <em>Max Num Simultaneous Apsde Ack Req</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getMaxNumSimultaneousApsdeAckReq()
	 * @generated
	 * @ordered
	 */
	protected static final BigInteger MAX_NUM_SIMULTANEOUS_APSDE_ACK_REQ_EDEFAULT = new BigInteger("3");

	/**
	 * The cached value of the '{@link #getMaxNumSimultaneousApsdeAckReq() <em>Max Num Simultaneous Apsde Ack Req</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getMaxNumSimultaneousApsdeAckReq()
	 * @generated
	 * @ordered
	 */
	protected BigInteger maxNumSimultaneousApsdeAckReq = MAX_NUM_SIMULTANEOUS_APSDE_ACK_REQ_EDEFAULT;

	/**
	 * The default value of the '{@link #getMACMutexName() <em>MAC Mutex Name</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getMACMutexName()
	 * @generated
	 * @ordered
	 */
	protected static final String MAC_MUTEX_NAME_EDEFAULT = "mutexMAC";

	/**
	 * The cached value of the '{@link #getMACMutexName() <em>MAC Mutex Name</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getMACMutexName()
	 * @generated
	 * @ordered
	 */
	protected String macMutexName = MAC_MUTEX_NAME_EDEFAULT;

	/**
	 * The default value of the '{@link #getZPSMutexName() <em>ZPS Mutex Name</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getZPSMutexName()
	 * @generated
	 * @ordered
	 */
	protected static final String ZPS_MUTEX_NAME_EDEFAULT = "mutexZPS";

	/**
	 * The cached value of the '{@link #getZPSMutexName() <em>ZPS Mutex Name</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getZPSMutexName()
	 * @generated
	 * @ordered
	 */
	protected String zpsMutexName = ZPS_MUTEX_NAME_EDEFAULT;

	/**
	 * The default value of the '{@link #getFragmentationMaxNumSimulRx() <em>Fragmentation Max Num Simul Rx</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getFragmentationMaxNumSimulRx()
	 * @generated
	 * @ordered
	 */
	protected static final int FRAGMENTATION_MAX_NUM_SIMUL_RX_EDEFAULT = 0;

	/**
	 * The cached value of the '{@link #getFragmentationMaxNumSimulRx() <em>Fragmentation Max Num Simul Rx</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getFragmentationMaxNumSimulRx()
	 * @generated
	 * @ordered
	 */
	protected int fragmentationMaxNumSimulRx = FRAGMENTATION_MAX_NUM_SIMUL_RX_EDEFAULT;

	/**
	 * The default value of the '{@link #getFragmentationMaxNumSimulTx() <em>Fragmentation Max Num Simul Tx</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getFragmentationMaxNumSimulTx()
	 * @generated
	 * @ordered
	 */
	protected static final int FRAGMENTATION_MAX_NUM_SIMUL_TX_EDEFAULT = 0;

	/**
	 * The cached value of the '{@link #getFragmentationMaxNumSimulTx() <em>Fragmentation Max Num Simul Tx</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getFragmentationMaxNumSimulTx()
	 * @generated
	 * @ordered
	 */
	protected int fragmentationMaxNumSimulTx = FRAGMENTATION_MAX_NUM_SIMUL_TX_EDEFAULT;

	/**
	 * The default value of the '{@link #getDefaultEventMessageName() <em>Default Event Message Name</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getDefaultEventMessageName()
	 * @generated
	 * @ordered
	 */
	protected static final String DEFAULT_EVENT_MESSAGE_NAME_EDEFAULT = "APP_msgZpsEvents";

	/**
	 * The cached value of the '{@link #getDefaultEventMessageName() <em>Default Event Message Name</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getDefaultEventMessageName()
	 * @generated
	 * @ordered
	 */
	protected String defaultEventMessageName = DEFAULT_EVENT_MESSAGE_NAME_EDEFAULT;

	/**
	 * The default value of the '{@link #getMACDcfmIndMessage() <em>MAC Dcfm Ind Message</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getMACDcfmIndMessage()
	 * @generated
	 * @ordered
	 */
	protected static final String MAC_DCFM_IND_MESSAGE_EDEFAULT = "zps_msgDcfmInd";

	/**
	 * The cached value of the '{@link #getMACDcfmIndMessage() <em>MAC Dcfm Ind Message</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getMACDcfmIndMessage()
	 * @generated
	 * @ordered
	 */
	protected String macDcfmIndMessage = MAC_DCFM_IND_MESSAGE_EDEFAULT;

	/**
	 * The default value of the '{@link #getMACTimeEventMessage() <em>MAC Time Event Message</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getMACTimeEventMessage()
	 * @generated
	 * @ordered
	 */
	protected static final String MAC_TIME_EVENT_MESSAGE_EDEFAULT = "zps_msgTimeEvents";

	/**
	 * The cached value of the '{@link #getMACTimeEventMessage() <em>MAC Time Event Message</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getMACTimeEventMessage()
	 * @generated
	 * @ordered
	 */
	protected String macTimeEventMessage = MAC_TIME_EVENT_MESSAGE_EDEFAULT;

	/**
	 * The default value of the '{@link #getApsNonMemberRadius() <em>Aps Non Member Radius</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getApsNonMemberRadius()
	 * @generated
	 * @ordered
	 */
	protected static final int APS_NON_MEMBER_RADIUS_EDEFAULT = 2;

	/**
	 * The cached value of the '{@link #getApsNonMemberRadius() <em>Aps Non Member Radius</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getApsNonMemberRadius()
	 * @generated
	 * @ordered
	 */
	protected int apsNonMemberRadius = APS_NON_MEMBER_RADIUS_EDEFAULT;

	/**
	 * The default value of the '{@link #isApsDesignatedCoordinator() <em>Aps Designated Coordinator</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #isApsDesignatedCoordinator()
	 * @generated
	 * @ordered
	 */
	protected static final boolean APS_DESIGNATED_COORDINATOR_EDEFAULT = false;

	/**
	 * The cached value of the '{@link #isApsDesignatedCoordinator() <em>Aps Designated Coordinator</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #isApsDesignatedCoordinator()
	 * @generated
	 * @ordered
	 */
	protected boolean apsDesignatedCoordinator = APS_DESIGNATED_COORDINATOR_EDEFAULT;

	/**
	 * The default value of the '{@link #isApsUseInsecureJoin() <em>Aps Use Insecure Join</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #isApsUseInsecureJoin()
	 * @generated
	 * @ordered
	 */
	protected static final boolean APS_USE_INSECURE_JOIN_EDEFAULT = true;

	/**
	 * The cached value of the '{@link #isApsUseInsecureJoin() <em>Aps Use Insecure Join</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #isApsUseInsecureJoin()
	 * @generated
	 * @ordered
	 */
	protected boolean apsUseInsecureJoin = APS_USE_INSECURE_JOIN_EDEFAULT;

	/**
	 * The default value of the '{@link #getApsMaxWindowSize() <em>Aps Max Window Size</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getApsMaxWindowSize()
	 * @generated
	 * @ordered
	 */
	protected static final int APS_MAX_WINDOW_SIZE_EDEFAULT = 8;

	/**
	 * The cached value of the '{@link #getApsMaxWindowSize() <em>Aps Max Window Size</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getApsMaxWindowSize()
	 * @generated
	 * @ordered
	 */
	protected int apsMaxWindowSize = APS_MAX_WINDOW_SIZE_EDEFAULT;

	/**
	 * The default value of the '{@link #getApsInterframeDelay() <em>Aps Interframe Delay</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getApsInterframeDelay()
	 * @generated
	 * @ordered
	 */
	protected static final int APS_INTERFRAME_DELAY_EDEFAULT = 10;

	/**
	 * The cached value of the '{@link #getApsInterframeDelay() <em>Aps Interframe Delay</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getApsInterframeDelay()
	 * @generated
	 * @ordered
	 */
	protected int apsInterframeDelay = APS_INTERFRAME_DELAY_EDEFAULT;

	/**
	 * The default value of the '{@link #getAPSDuplicateTableSize() <em>APS Duplicate Table Size</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getAPSDuplicateTableSize()
	 * @generated
	 * @ordered
	 */
	protected static final int APS_DUPLICATE_TABLE_SIZE_EDEFAULT = 8;

	/**
	 * The cached value of the '{@link #getAPSDuplicateTableSize() <em>APS Duplicate Table Size</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getAPSDuplicateTableSize()
	 * @generated
	 * @ordered
	 */
	protected int apsDuplicateTableSize = APS_DUPLICATE_TABLE_SIZE_EDEFAULT;

	/**
	 * The default value of the '{@link #getApsSecurityTimeoutPeriod() <em>Aps Security Timeout Period</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getApsSecurityTimeoutPeriod()
	 * @generated
	 * @ordered
	 */
	protected static final BigInteger APS_SECURITY_TIMEOUT_PERIOD_EDEFAULT = new BigInteger("1000");

	/**
	 * The cached value of the '{@link #getApsSecurityTimeoutPeriod() <em>Aps Security Timeout Period</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getApsSecurityTimeoutPeriod()
	 * @generated
	 * @ordered
	 */
	protected BigInteger apsSecurityTimeoutPeriod = APS_SECURITY_TIMEOUT_PERIOD_EDEFAULT;

	/**
	 * The default value of the '{@link #getApsUseExtPANId() <em>Aps Use Ext PAN Id</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getApsUseExtPANId()
	 * @generated
	 * @ordered
	 */
	protected static final Object APS_USE_EXT_PAN_ID_EDEFAULT = (Object)ZPSConfigurationFactory.eINSTANCE.createFromString(ZPSConfigurationPackage.eINSTANCE.getEExtPANId(), "0");

	/**
	 * The cached value of the '{@link #getApsUseExtPANId() <em>Aps Use Ext PAN Id</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getApsUseExtPANId()
	 * @generated
	 * @ordered
	 */
	protected Object apsUseExtPANId = APS_USE_EXT_PAN_ID_EDEFAULT;

	/**
	 * The cached value of the '{@link #getInitialNetworkKey() <em>Initial Network Key</em>}' reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getInitialNetworkKey()
	 * @generated
	 * @ordered
	 */
	protected TCKey initialNetworkKey;

	/**
	 * The default value of the '{@link #isSecurityEnabled() <em>Security Enabled</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #isSecurityEnabled()
	 * @generated
	 * @ordered
	 */
	protected static final boolean SECURITY_ENABLED_EDEFAULT = true;

	/**
	 * The cached value of the '{@link #isSecurityEnabled() <em>Security Enabled</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #isSecurityEnabled()
	 * @generated
	 * @ordered
	 */
	protected boolean securityEnabled = SECURITY_ENABLED_EDEFAULT;

	/**
	 * The default value of the '{@link #getMACMlmeDcfmIndMessage() <em>MAC Mlme Dcfm Ind Message</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getMACMlmeDcfmIndMessage()
	 * @generated
	 * @ordered
	 */
	protected static final String MAC_MLME_DCFM_IND_MESSAGE_EDEFAULT = "zps_msgMlmeDcfmInd";

	/**
	 * The cached value of the '{@link #getMACMlmeDcfmIndMessage() <em>MAC Mlme Dcfm Ind Message</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getMACMlmeDcfmIndMessage()
	 * @generated
	 * @ordered
	 */
	protected String macMlmeDcfmIndMessage = MAC_MLME_DCFM_IND_MESSAGE_EDEFAULT;

	/**
	 * The default value of the '{@link #getMACMcpsDcfmIndMessage() <em>MAC Mcps Dcfm Ind Message</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getMACMcpsDcfmIndMessage()
	 * @generated
	 * @ordered
	 */
	protected static final String MAC_MCPS_DCFM_IND_MESSAGE_EDEFAULT = "zps_msgMcpsDcfmInd";

	/**
	 * The cached value of the '{@link #getMACMcpsDcfmIndMessage() <em>MAC Mcps Dcfm Ind Message</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getMACMcpsDcfmIndMessage()
	 * @generated
	 * @ordered
	 */
	protected String macMcpsDcfmIndMessage = MAC_MCPS_DCFM_IND_MESSAGE_EDEFAULT;

	/**
	 * The default value of the '{@link #getAPSPersistenceTime() <em>APS Persistence Time</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getAPSPersistenceTime()
	 * @generated
	 * @ordered
	 */
	protected static final int APS_PERSISTENCE_TIME_EDEFAULT = 100;

	/**
	 * The cached value of the '{@link #getAPSPersistenceTime() <em>APS Persistence Time</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getAPSPersistenceTime()
	 * @generated
	 * @ordered
	 */
	protected int apsPersistenceTime = APS_PERSISTENCE_TIME_EDEFAULT;

	/**
	 * The default value of the '{@link #getNumAPSMESimulCommands() <em>Num APSME Simul Commands</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getNumAPSMESimulCommands()
	 * @generated
	 * @ordered
	 */
	protected static final int NUM_APSME_SIMUL_COMMANDS_EDEFAULT = 4;

	/**
	 * The cached value of the '{@link #getNumAPSMESimulCommands() <em>Num APSME Simul Commands</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getNumAPSMESimulCommands()
	 * @generated
	 * @ordered
	 */
	protected int numAPSMESimulCommands = NUM_APSME_SIMUL_COMMANDS_EDEFAULT;

	/**
	 * The default value of the '{@link #getStackProfile() <em>Stack Profile</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getStackProfile()
	 * @generated
	 * @ordered
	 */
	protected static final int STACK_PROFILE_EDEFAULT = 2;

	/**
	 * The cached value of the '{@link #getStackProfile() <em>Stack Profile</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getStackProfile()
	 * @generated
	 * @ordered
	 */
	protected int stackProfile = STACK_PROFILE_EDEFAULT;

	/**
	 * The default value of the '{@link #isInterPAN() <em>Inter PAN</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #isInterPAN()
	 * @generated
	 * @ordered
	 */
	protected static final boolean INTER_PAN_EDEFAULT = false;

	/**
	 * The cached value of the '{@link #isInterPAN() <em>Inter PAN</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #isInterPAN()
	 * @generated
	 * @ordered
	 */
	protected boolean interPAN = INTER_PAN_EDEFAULT;

	/**
	 * The default value of the '{@link #isGreenPowerSupport() <em>Green Power Support</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #isGreenPowerSupport()
	 * @generated
	 * @ordered
	 */
	protected static final boolean GREEN_POWER_SUPPORT_EDEFAULT = false;

	/**
	 * The cached value of the '{@link #isGreenPowerSupport() <em>Green Power Support</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #isGreenPowerSupport()
	 * @generated
	 * @ordered
	 */
	protected boolean greenPowerSupport = GREEN_POWER_SUPPORT_EDEFAULT;

	/**
	 * The default value of the '{@link #getNwkFcSaveCountBitShift() <em>Nwk Fc Save Count Bit Shift</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getNwkFcSaveCountBitShift()
	 * @generated
	 * @ordered
	 */
	protected static final int NWK_FC_SAVE_COUNT_BIT_SHIFT_EDEFAULT = 10;

	/**
	 * The cached value of the '{@link #getNwkFcSaveCountBitShift() <em>Nwk Fc Save Count Bit Shift</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getNwkFcSaveCountBitShift()
	 * @generated
	 * @ordered
	 */
	protected int nwkFcSaveCountBitShift = NWK_FC_SAVE_COUNT_BIT_SHIFT_EDEFAULT;

	/**
	 * The default value of the '{@link #getApsFcSaveCountBitShift() <em>Aps Fc Save Count Bit Shift</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getApsFcSaveCountBitShift()
	 * @generated
	 * @ordered
	 */
	protected static final int APS_FC_SAVE_COUNT_BIT_SHIFT_EDEFAULT = 10;

	/**
	 * The cached value of the '{@link #getApsFcSaveCountBitShift() <em>Aps Fc Save Count Bit Shift</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getApsFcSaveCountBitShift()
	 * @generated
	 * @ordered
	 */
	protected int apsFcSaveCountBitShift = APS_FC_SAVE_COUNT_BIT_SHIFT_EDEFAULT;

	/**
	 * The default value of the '{@link #getMacTableSize() <em>Mac Table Size</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getMacTableSize()
	 * @generated
	 * @ordered
	 */
	protected static final BigInteger MAC_TABLE_SIZE_EDEFAULT = new BigInteger("36");

	/**
	 * The cached value of the '{@link #getMacTableSize() <em>Mac Table Size</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getMacTableSize()
	 * @generated
	 * @ordered
	 */
	protected BigInteger macTableSize = MAC_TABLE_SIZE_EDEFAULT;

	/**
	 * The default value of the '{@link #getDefaultCallbackName() <em>Default Callback Name</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getDefaultCallbackName()
	 * @generated
	 * @ordered
	 */
	protected static final String DEFAULT_CALLBACK_NAME_EDEFAULT = "APP_vGenCallback";

	/**
	 * The cached value of the '{@link #getDefaultCallbackName() <em>Default Callback Name</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getDefaultCallbackName()
	 * @generated
	 * @ordered
	 */
	protected String defaultCallbackName = DEFAULT_CALLBACK_NAME_EDEFAULT;

	/**
	 * The cached value of the '{@link #getMacInterfaceList() <em>Mac Interface List</em>}' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getMacInterfaceList()
	 * @generated
	 * @ordered
	 */
	protected MacInterfaceList macInterfaceList;

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	protected NodeImpl() {
		super();
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	@Override
	protected EClass eStaticClass() {
		return ZPSConfigurationPackage.Literals.NODE;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EList<EndPoint> getEndpoints() {
		if (endpoints == null) {
			endpoints = new EObjectContainmentWithInverseEList<EndPoint>(EndPoint.class, this, ZPSConfigurationPackage.NODE__ENDPOINTS, ZPSConfigurationPackage.END_POINT__NODE);
		}
		return endpoints;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public BindingTable getBindingTable() {
		return bindingTable;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public NotificationChain basicSetBindingTable(BindingTable newBindingTable, NotificationChain msgs) {
		BindingTable oldBindingTable = bindingTable;
		bindingTable = newBindingTable;
		if (eNotificationRequired()) {
			ENotificationImpl notification = new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.NODE__BINDING_TABLE, oldBindingTable, newBindingTable);
			if (msgs == null) msgs = notification; else msgs.add(notification);
		}
		return msgs;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void setBindingTable(BindingTable newBindingTable) {
		if (newBindingTable != bindingTable) {
			NotificationChain msgs = null;
			if (bindingTable != null)
				msgs = ((InternalEObject)bindingTable).eInverseRemove(this, EOPPOSITE_FEATURE_BASE - ZPSConfigurationPackage.NODE__BINDING_TABLE, null, msgs);
			if (newBindingTable != null)
				msgs = ((InternalEObject)newBindingTable).eInverseAdd(this, EOPPOSITE_FEATURE_BASE - ZPSConfigurationPackage.NODE__BINDING_TABLE, null, msgs);
			msgs = basicSetBindingTable(newBindingTable, msgs);
			if (msgs != null) msgs.dispatch();
		}
		else if (eNotificationRequired())
			eNotify(new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.NODE__BINDING_TABLE, newBindingTable, newBindingTable));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public UserDescriptor getUserDescriptor() {
		return userDescriptor;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public NotificationChain basicSetUserDescriptor(UserDescriptor newUserDescriptor, NotificationChain msgs) {
		UserDescriptor oldUserDescriptor = userDescriptor;
		userDescriptor = newUserDescriptor;
		if (eNotificationRequired()) {
			ENotificationImpl notification = new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.NODE__USER_DESCRIPTOR, oldUserDescriptor, newUserDescriptor);
			if (msgs == null) msgs = notification; else msgs.add(notification);
		}
		return msgs;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void setUserDescriptor(UserDescriptor newUserDescriptor) {
		if (newUserDescriptor != userDescriptor) {
			NotificationChain msgs = null;
			if (userDescriptor != null)
				msgs = ((InternalEObject)userDescriptor).eInverseRemove(this, EOPPOSITE_FEATURE_BASE - ZPSConfigurationPackage.NODE__USER_DESCRIPTOR, null, msgs);
			if (newUserDescriptor != null)
				msgs = ((InternalEObject)newUserDescriptor).eInverseAdd(this, EOPPOSITE_FEATURE_BASE - ZPSConfigurationPackage.NODE__USER_DESCRIPTOR, null, msgs);
			msgs = basicSetUserDescriptor(newUserDescriptor, msgs);
			if (msgs != null) msgs.dispatch();
		}
		else if (eNotificationRequired())
			eNotify(new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.NODE__USER_DESCRIPTOR, newUserDescriptor, newUserDescriptor));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public PDUManager getPDUConfiguration() {
		return pduConfiguration;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public NotificationChain basicSetPDUConfiguration(PDUManager newPDUConfiguration, NotificationChain msgs) {
		PDUManager oldPDUConfiguration = pduConfiguration;
		pduConfiguration = newPDUConfiguration;
		if (eNotificationRequired()) {
			ENotificationImpl notification = new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.NODE__PDU_CONFIGURATION, oldPDUConfiguration, newPDUConfiguration);
			if (msgs == null) msgs = notification; else msgs.add(notification);
		}
		return msgs;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void setPDUConfiguration(PDUManager newPDUConfiguration) {
		if (newPDUConfiguration != pduConfiguration) {
			NotificationChain msgs = null;
			if (pduConfiguration != null)
				msgs = ((InternalEObject)pduConfiguration).eInverseRemove(this, ZPSConfigurationPackage.PDU_MANAGER__CONTAINER_NODE, PDUManager.class, msgs);
			if (newPDUConfiguration != null)
				msgs = ((InternalEObject)newPDUConfiguration).eInverseAdd(this, ZPSConfigurationPackage.PDU_MANAGER__CONTAINER_NODE, PDUManager.class, msgs);
			msgs = basicSetPDUConfiguration(newPDUConfiguration, msgs);
			if (msgs != null) msgs.dispatch();
		}
		else if (eNotificationRequired())
			eNotify(new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.NODE__PDU_CONFIGURATION, newPDUConfiguration, newPDUConfiguration));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public GroupTable getGroupTable() {
		return groupTable;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public NotificationChain basicSetGroupTable(GroupTable newGroupTable, NotificationChain msgs) {
		GroupTable oldGroupTable = groupTable;
		groupTable = newGroupTable;
		if (eNotificationRequired()) {
			ENotificationImpl notification = new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.NODE__GROUP_TABLE, oldGroupTable, newGroupTable);
			if (msgs == null) msgs = notification; else msgs.add(notification);
		}
		return msgs;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void setGroupTable(GroupTable newGroupTable) {
		if (newGroupTable != groupTable) {
			NotificationChain msgs = null;
			if (groupTable != null)
				msgs = ((InternalEObject)groupTable).eInverseRemove(this, EOPPOSITE_FEATURE_BASE - ZPSConfigurationPackage.NODE__GROUP_TABLE, null, msgs);
			if (newGroupTable != null)
				msgs = ((InternalEObject)newGroupTable).eInverseAdd(this, EOPPOSITE_FEATURE_BASE - ZPSConfigurationPackage.NODE__GROUP_TABLE, null, msgs);
			msgs = basicSetGroupTable(newGroupTable, msgs);
			if (msgs != null) msgs.dispatch();
		}
		else if (eNotificationRequired())
			eNotify(new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.NODE__GROUP_TABLE, newGroupTable, newGroupTable));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public BigInteger getMaxNumSimultaneousApsdeAckReq() {
		return maxNumSimultaneousApsdeAckReq;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void setMaxNumSimultaneousApsdeAckReq(BigInteger newMaxNumSimultaneousApsdeAckReq) {
		BigInteger oldMaxNumSimultaneousApsdeAckReq = maxNumSimultaneousApsdeAckReq;
		maxNumSimultaneousApsdeAckReq = newMaxNumSimultaneousApsdeAckReq;
		if (eNotificationRequired())
			eNotify(new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.NODE__MAX_NUM_SIMULTANEOUS_APSDE_ACK_REQ, oldMaxNumSimultaneousApsdeAckReq, maxNumSimultaneousApsdeAckReq));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public ChannelMask getChannelMask() {
		return channelMask;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public NotificationChain basicSetChannelMask(ChannelMask newChannelMask, NotificationChain msgs) {
		ChannelMask oldChannelMask = channelMask;
		channelMask = newChannelMask;
		if (eNotificationRequired()) {
			ENotificationImpl notification = new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.NODE__CHANNEL_MASK, oldChannelMask, newChannelMask);
			if (msgs == null) msgs = notification; else msgs.add(notification);
		}
		return msgs;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void setChannelMask(ChannelMask newChannelMask) {
		if (newChannelMask != channelMask) {
			NotificationChain msgs = null;
			if (channelMask != null)
				msgs = ((InternalEObject)channelMask).eInverseRemove(this, EOPPOSITE_FEATURE_BASE - ZPSConfigurationPackage.NODE__CHANNEL_MASK, null, msgs);
			if (newChannelMask != null)
				msgs = ((InternalEObject)newChannelMask).eInverseAdd(this, EOPPOSITE_FEATURE_BASE - ZPSConfigurationPackage.NODE__CHANNEL_MASK, null, msgs);
			msgs = basicSetChannelMask(newChannelMask, msgs);
			if (msgs != null) msgs.dispatch();
		}
		else if (eNotificationRequired())
			eNotify(new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.NODE__CHANNEL_MASK, newChannelMask, newChannelMask));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public BigInteger getDiscoveryNeighbourTableSize() {
		return discoveryNeighbourTableSize;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void setDiscoveryNeighbourTableSize(BigInteger newDiscoveryNeighbourTableSize) {
		BigInteger oldDiscoveryNeighbourTableSize = discoveryNeighbourTableSize;
		discoveryNeighbourTableSize = newDiscoveryNeighbourTableSize;
		if (eNotificationRequired())
			eNotify(new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.NODE__DISCOVERY_NEIGHBOUR_TABLE_SIZE, oldDiscoveryNeighbourTableSize, discoveryNeighbourTableSize));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public BigInteger getActiveNeighbourTableSize() {
		return activeNeighbourTableSize;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void setActiveNeighbourTableSize(BigInteger newActiveNeighbourTableSize) {
		BigInteger oldActiveNeighbourTableSize = activeNeighbourTableSize;
		activeNeighbourTableSize = newActiveNeighbourTableSize;
		if (eNotificationRequired())
			eNotify(new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.NODE__ACTIVE_NEIGHBOUR_TABLE_SIZE, oldActiveNeighbourTableSize, activeNeighbourTableSize));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public BigInteger getRouteDiscoveryTableSize() {
		return routeDiscoveryTableSize;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void setRouteDiscoveryTableSize(BigInteger newRouteDiscoveryTableSize) {
		BigInteger oldRouteDiscoveryTableSize = routeDiscoveryTableSize;
		routeDiscoveryTableSize = newRouteDiscoveryTableSize;
		if (eNotificationRequired())
			eNotify(new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.NODE__ROUTE_DISCOVERY_TABLE_SIZE, oldRouteDiscoveryTableSize, routeDiscoveryTableSize));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public BigInteger getRoutingTableSize() {
		return routingTableSize;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void setRoutingTableSize(BigInteger newRoutingTableSize) {
		BigInteger oldRoutingTableSize = routingTableSize;
		routingTableSize = newRoutingTableSize;
		if (eNotificationRequired())
			eNotify(new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.NODE__ROUTING_TABLE_SIZE, oldRoutingTableSize, routingTableSize));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public BigInteger getBroadcastTransactionTableSize() {
		return broadcastTransactionTableSize;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void setBroadcastTransactionTableSize(BigInteger newBroadcastTransactionTableSize) {
		BigInteger oldBroadcastTransactionTableSize = broadcastTransactionTableSize;
		broadcastTransactionTableSize = newBroadcastTransactionTableSize;
		if (eNotificationRequired())
			eNotify(new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.NODE__BROADCAST_TRANSACTION_TABLE_SIZE, oldBroadcastTransactionTableSize, broadcastTransactionTableSize));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public BigInteger getRouteRecordTableSize() {
		return routeRecordTableSize;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void setRouteRecordTableSize(BigInteger newRouteRecordTableSize) {
		BigInteger oldRouteRecordTableSize = routeRecordTableSize;
		routeRecordTableSize = newRouteRecordTableSize;
		if (eNotificationRequired())
			eNotify(new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.NODE__ROUTE_RECORD_TABLE_SIZE, oldRouteRecordTableSize, routeRecordTableSize));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public BigInteger getAddressMapTableSize() {
		return addressMapTableSize;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void setAddressMapTableSize(BigInteger newAddressMapTableSize) {
		BigInteger oldAddressMapTableSize = addressMapTableSize;
		addressMapTableSize = newAddressMapTableSize;
		if (eNotificationRequired())
			eNotify(new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.NODE__ADDRESS_MAP_TABLE_SIZE, oldAddressMapTableSize, addressMapTableSize));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public BigInteger getSecurityMaterialSets() {
		return securityMaterialSets;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void setSecurityMaterialSets(BigInteger newSecurityMaterialSets) {
		BigInteger oldSecurityMaterialSets = securityMaterialSets;
		securityMaterialSets = newSecurityMaterialSets;
		if (eNotificationRequired())
			eNotify(new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.NODE__SECURITY_MATERIAL_SETS, oldSecurityMaterialSets, securityMaterialSets));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public NodeDescriptor getNodeDescriptor() {
		return nodeDescriptor;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public NotificationChain basicSetNodeDescriptor(NodeDescriptor newNodeDescriptor, NotificationChain msgs) {
		NodeDescriptor oldNodeDescriptor = nodeDescriptor;
		nodeDescriptor = newNodeDescriptor;
		if (eNotificationRequired()) {
			ENotificationImpl notification = new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.NODE__NODE_DESCRIPTOR, oldNodeDescriptor, newNodeDescriptor);
			if (msgs == null) msgs = notification; else msgs.add(notification);
		}
		return msgs;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void setNodeDescriptor(NodeDescriptor newNodeDescriptor) {
		if (newNodeDescriptor != nodeDescriptor) {
			NotificationChain msgs = null;
			if (nodeDescriptor != null)
				msgs = ((InternalEObject)nodeDescriptor).eInverseRemove(this, ZPSConfigurationPackage.NODE_DESCRIPTOR__NODE, NodeDescriptor.class, msgs);
			if (newNodeDescriptor != null)
				msgs = ((InternalEObject)newNodeDescriptor).eInverseAdd(this, ZPSConfigurationPackage.NODE_DESCRIPTOR__NODE, NodeDescriptor.class, msgs);
			msgs = basicSetNodeDescriptor(newNodeDescriptor, msgs);
			if (msgs != null) msgs.dispatch();
		}
		else if (eNotificationRequired())
			eNotify(new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.NODE__NODE_DESCRIPTOR, newNodeDescriptor, newNodeDescriptor));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public NodePowerDescriptor getNodePowerDescriptor() {
		return nodePowerDescriptor;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public NotificationChain basicSetNodePowerDescriptor(NodePowerDescriptor newNodePowerDescriptor, NotificationChain msgs) {
		NodePowerDescriptor oldNodePowerDescriptor = nodePowerDescriptor;
		nodePowerDescriptor = newNodePowerDescriptor;
		if (eNotificationRequired()) {
			ENotificationImpl notification = new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.NODE__NODE_POWER_DESCRIPTOR, oldNodePowerDescriptor, newNodePowerDescriptor);
			if (msgs == null) msgs = notification; else msgs.add(notification);
		}
		return msgs;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void setNodePowerDescriptor(NodePowerDescriptor newNodePowerDescriptor) {
		if (newNodePowerDescriptor != nodePowerDescriptor) {
			NotificationChain msgs = null;
			if (nodePowerDescriptor != null)
				msgs = ((InternalEObject)nodePowerDescriptor).eInverseRemove(this, EOPPOSITE_FEATURE_BASE - ZPSConfigurationPackage.NODE__NODE_POWER_DESCRIPTOR, null, msgs);
			if (newNodePowerDescriptor != null)
				msgs = ((InternalEObject)newNodePowerDescriptor).eInverseAdd(this, EOPPOSITE_FEATURE_BASE - ZPSConfigurationPackage.NODE__NODE_POWER_DESCRIPTOR, null, msgs);
			msgs = basicSetNodePowerDescriptor(newNodePowerDescriptor, msgs);
			if (msgs != null) msgs.dispatch();
		}
		else if (eNotificationRequired())
			eNotify(new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.NODE__NODE_POWER_DESCRIPTOR, newNodePowerDescriptor, newNodePowerDescriptor));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public int getMaxNumSimultaneousApsdeReq() {
		return maxNumSimultaneousApsdeReq;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void setMaxNumSimultaneousApsdeReq(int newMaxNumSimultaneousApsdeReq) {
		int oldMaxNumSimultaneousApsdeReq = maxNumSimultaneousApsdeReq;
		maxNumSimultaneousApsdeReq = newMaxNumSimultaneousApsdeReq;
		if (eNotificationRequired())
			eNotify(new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.NODE__MAX_NUM_SIMULTANEOUS_APSDE_REQ, oldMaxNumSimultaneousApsdeReq, maxNumSimultaneousApsdeReq));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public String getMACMutexName() {
		return macMutexName;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void setMACMutexName(String newMACMutexName) {
		String oldMACMutexName = macMutexName;
		macMutexName = newMACMutexName;
		if (eNotificationRequired())
			eNotify(new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.NODE__MAC_MUTEX_NAME, oldMACMutexName, macMutexName));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public String getZPSMutexName() {
		return zpsMutexName;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void setZPSMutexName(String newZPSMutexName) {
		String oldZPSMutexName = zpsMutexName;
		zpsMutexName = newZPSMutexName;
		if (eNotificationRequired())
			eNotify(new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.NODE__ZPS_MUTEX_NAME, oldZPSMutexName, zpsMutexName));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public int getFragmentationMaxNumSimulRx() {
		return fragmentationMaxNumSimulRx;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void setFragmentationMaxNumSimulRx(int newFragmentationMaxNumSimulRx) {
		int oldFragmentationMaxNumSimulRx = fragmentationMaxNumSimulRx;
		fragmentationMaxNumSimulRx = newFragmentationMaxNumSimulRx;
		if (eNotificationRequired())
			eNotify(new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.NODE__FRAGMENTATION_MAX_NUM_SIMUL_RX, oldFragmentationMaxNumSimulRx, fragmentationMaxNumSimulRx));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public int getFragmentationMaxNumSimulTx() {
		return fragmentationMaxNumSimulTx;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void setFragmentationMaxNumSimulTx(int newFragmentationMaxNumSimulTx) {
		int oldFragmentationMaxNumSimulTx = fragmentationMaxNumSimulTx;
		fragmentationMaxNumSimulTx = newFragmentationMaxNumSimulTx;
		if (eNotificationRequired())
			eNotify(new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.NODE__FRAGMENTATION_MAX_NUM_SIMUL_TX, oldFragmentationMaxNumSimulTx, fragmentationMaxNumSimulTx));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public String getDefaultEventMessageName() {
		return defaultEventMessageName;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void setDefaultEventMessageName(String newDefaultEventMessageName) {
		String oldDefaultEventMessageName = defaultEventMessageName;
		defaultEventMessageName = newDefaultEventMessageName;
		if (eNotificationRequired())
			eNotify(new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.NODE__DEFAULT_EVENT_MESSAGE_NAME, oldDefaultEventMessageName, defaultEventMessageName));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public String getMACDcfmIndMessage() {
		return macDcfmIndMessage;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void setMACDcfmIndMessage(String newMACDcfmIndMessage) {
		String oldMACDcfmIndMessage = macDcfmIndMessage;
		macDcfmIndMessage = newMACDcfmIndMessage;
		if (eNotificationRequired())
			eNotify(new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.NODE__MAC_DCFM_IND_MESSAGE, oldMACDcfmIndMessage, macDcfmIndMessage));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public String getMACTimeEventMessage() {
		return macTimeEventMessage;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void setMACTimeEventMessage(String newMACTimeEventMessage) {
		String oldMACTimeEventMessage = macTimeEventMessage;
		macTimeEventMessage = newMACTimeEventMessage;
		if (eNotificationRequired())
			eNotify(new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.NODE__MAC_TIME_EVENT_MESSAGE, oldMACTimeEventMessage, macTimeEventMessage));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public int getApsNonMemberRadius() {
		return apsNonMemberRadius;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void setApsNonMemberRadius(int newApsNonMemberRadius) {
		int oldApsNonMemberRadius = apsNonMemberRadius;
		apsNonMemberRadius = newApsNonMemberRadius;
		if (eNotificationRequired())
			eNotify(new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.NODE__APS_NON_MEMBER_RADIUS, oldApsNonMemberRadius, apsNonMemberRadius));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated NOT
	 */
	public boolean isApsDesignatedCoordinator() {
		
		return (this instanceof CoordinatorImpl);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void setApsDesignatedCoordinator(boolean newApsDesignatedCoordinator) {
		boolean oldApsDesignatedCoordinator = apsDesignatedCoordinator;
		apsDesignatedCoordinator = newApsDesignatedCoordinator;
		if (eNotificationRequired())
			eNotify(new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.NODE__APS_DESIGNATED_COORDINATOR, oldApsDesignatedCoordinator, apsDesignatedCoordinator));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public boolean isApsUseInsecureJoin() {
		return apsUseInsecureJoin;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void setApsUseInsecureJoin(boolean newApsUseInsecureJoin) {
		boolean oldApsUseInsecureJoin = apsUseInsecureJoin;
		apsUseInsecureJoin = newApsUseInsecureJoin;
		if (eNotificationRequired())
			eNotify(new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.NODE__APS_USE_INSECURE_JOIN, oldApsUseInsecureJoin, apsUseInsecureJoin));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public int getApsMaxWindowSize() {
		return apsMaxWindowSize;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void setApsMaxWindowSize(int newApsMaxWindowSize) {
		int oldApsMaxWindowSize = apsMaxWindowSize;
		apsMaxWindowSize = newApsMaxWindowSize;
		if (eNotificationRequired())
			eNotify(new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.NODE__APS_MAX_WINDOW_SIZE, oldApsMaxWindowSize, apsMaxWindowSize));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public int getApsInterframeDelay() {
		return apsInterframeDelay;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void setApsInterframeDelay(int newApsInterframeDelay) {
		int oldApsInterframeDelay = apsInterframeDelay;
		apsInterframeDelay = newApsInterframeDelay;
		if (eNotificationRequired())
			eNotify(new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.NODE__APS_INTERFRAME_DELAY, oldApsInterframeDelay, apsInterframeDelay));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public BigInteger getApsSecurityTimeoutPeriod() {
		return apsSecurityTimeoutPeriod;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void setApsSecurityTimeoutPeriod(BigInteger newApsSecurityTimeoutPeriod) {
		BigInteger oldApsSecurityTimeoutPeriod = apsSecurityTimeoutPeriod;
		apsSecurityTimeoutPeriod = newApsSecurityTimeoutPeriod;
		if (eNotificationRequired())
			eNotify(new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.NODE__APS_SECURITY_TIMEOUT_PERIOD, oldApsSecurityTimeoutPeriod, apsSecurityTimeoutPeriod));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public KeyDescriptorTable getKeyDescriptorTable() {
		return keyDescriptorTable;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public NotificationChain basicSetKeyDescriptorTable(KeyDescriptorTable newKeyDescriptorTable, NotificationChain msgs) {
		KeyDescriptorTable oldKeyDescriptorTable = keyDescriptorTable;
		keyDescriptorTable = newKeyDescriptorTable;
		if (eNotificationRequired()) {
			ENotificationImpl notification = new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.NODE__KEY_DESCRIPTOR_TABLE, oldKeyDescriptorTable, newKeyDescriptorTable);
			if (msgs == null) msgs = notification; else msgs.add(notification);
		}
		return msgs;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void setKeyDescriptorTable(KeyDescriptorTable newKeyDescriptorTable) {
		if (newKeyDescriptorTable != keyDescriptorTable) {
			NotificationChain msgs = null;
			if (keyDescriptorTable != null)
				msgs = ((InternalEObject)keyDescriptorTable).eInverseRemove(this, EOPPOSITE_FEATURE_BASE - ZPSConfigurationPackage.NODE__KEY_DESCRIPTOR_TABLE, null, msgs);
			if (newKeyDescriptorTable != null)
				msgs = ((InternalEObject)newKeyDescriptorTable).eInverseAdd(this, EOPPOSITE_FEATURE_BASE - ZPSConfigurationPackage.NODE__KEY_DESCRIPTOR_TABLE, null, msgs);
			msgs = basicSetKeyDescriptorTable(newKeyDescriptorTable, msgs);
			if (msgs != null) msgs.dispatch();
		}
		else if (eNotificationRequired())
			eNotify(new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.NODE__KEY_DESCRIPTOR_TABLE, newKeyDescriptorTable, newKeyDescriptorTable));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public Object getApsUseExtPANId() {
		return apsUseExtPANId;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void setApsUseExtPANId(Object newApsUseExtPANId) {
		Object oldApsUseExtPANId = apsUseExtPANId;
		apsUseExtPANId = newApsUseExtPANId;
		if (eNotificationRequired())
			eNotify(new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.NODE__APS_USE_EXT_PAN_ID, oldApsUseExtPANId, apsUseExtPANId));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public TCKey getInitialNetworkKey() {
		if (initialNetworkKey != null && initialNetworkKey.eIsProxy()) {
			InternalEObject oldInitialNetworkKey = (InternalEObject)initialNetworkKey;
			initialNetworkKey = (TCKey)eResolveProxy(oldInitialNetworkKey);
			if (initialNetworkKey != oldInitialNetworkKey) {
				if (eNotificationRequired())
					eNotify(new ENotificationImpl(this, Notification.RESOLVE, ZPSConfigurationPackage.NODE__INITIAL_NETWORK_KEY, oldInitialNetworkKey, initialNetworkKey));
			}
		}
		return initialNetworkKey;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public TCKey basicGetInitialNetworkKey() {
		return initialNetworkKey;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void setInitialNetworkKey(TCKey newInitialNetworkKey) {
		TCKey oldInitialNetworkKey = initialNetworkKey;
		initialNetworkKey = newInitialNetworkKey;
		if (eNotificationRequired())
			eNotify(new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.NODE__INITIAL_NETWORK_KEY, oldInitialNetworkKey, initialNetworkKey));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public boolean isSecurityEnabled() {
		return securityEnabled;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void setSecurityEnabled(boolean newSecurityEnabled) {
		boolean oldSecurityEnabled = securityEnabled;
		securityEnabled = newSecurityEnabled;
		if (eNotificationRequired())
			eNotify(new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.NODE__SECURITY_ENABLED, oldSecurityEnabled, securityEnabled));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public String getMACMlmeDcfmIndMessage() {
		return macMlmeDcfmIndMessage;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void setMACMlmeDcfmIndMessage(String newMACMlmeDcfmIndMessage) {
		String oldMACMlmeDcfmIndMessage = macMlmeDcfmIndMessage;
		macMlmeDcfmIndMessage = newMACMlmeDcfmIndMessage;
		if (eNotificationRequired())
			eNotify(new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.NODE__MAC_MLME_DCFM_IND_MESSAGE, oldMACMlmeDcfmIndMessage, macMlmeDcfmIndMessage));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public String getMACMcpsDcfmIndMessage() {
		return macMcpsDcfmIndMessage;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void setMACMcpsDcfmIndMessage(String newMACMcpsDcfmIndMessage) {
		String oldMACMcpsDcfmIndMessage = macMcpsDcfmIndMessage;
		macMcpsDcfmIndMessage = newMACMcpsDcfmIndMessage;
		if (eNotificationRequired())
			eNotify(new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.NODE__MAC_MCPS_DCFM_IND_MESSAGE, oldMACMcpsDcfmIndMessage, macMcpsDcfmIndMessage));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public int getAPSPersistenceTime() {
		return apsPersistenceTime;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void setAPSPersistenceTime(int newAPSPersistenceTime) {
		int oldAPSPersistenceTime = apsPersistenceTime;
		apsPersistenceTime = newAPSPersistenceTime;
		if (eNotificationRequired())
			eNotify(new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.NODE__APS_PERSISTENCE_TIME, oldAPSPersistenceTime, apsPersistenceTime));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public int getNumAPSMESimulCommands() {
		return numAPSMESimulCommands;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void setNumAPSMESimulCommands(int newNumAPSMESimulCommands) {
		int oldNumAPSMESimulCommands = numAPSMESimulCommands;
		numAPSMESimulCommands = newNumAPSMESimulCommands;
		if (eNotificationRequired())
			eNotify(new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.NODE__NUM_APSME_SIMUL_COMMANDS, oldNumAPSMESimulCommands, numAPSMESimulCommands));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public int getStackProfile() {
		return stackProfile;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void setStackProfile(int newStackProfile) {
		int oldStackProfile = stackProfile;
		stackProfile = newStackProfile;
		if (eNotificationRequired())
			eNotify(new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.NODE__STACK_PROFILE, oldStackProfile, stackProfile));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public boolean isInterPAN() {
		return interPAN;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void setInterPAN(boolean newInterPAN) {
		boolean oldInterPAN = interPAN;
		interPAN = newInterPAN;
		if (eNotificationRequired())
			eNotify(new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.NODE__INTER_PAN, oldInterPAN, interPAN));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public boolean isGreenPowerSupport() {
		return greenPowerSupport;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void setGreenPowerSupport(boolean newGreenPowerSupport) {
		boolean oldGreenPowerSupport = greenPowerSupport;
		greenPowerSupport = newGreenPowerSupport;
		if (eNotificationRequired())
			eNotify(new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.NODE__GREEN_POWER_SUPPORT, oldGreenPowerSupport, greenPowerSupport));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public int getNwkFcSaveCountBitShift() {
		return nwkFcSaveCountBitShift;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void setNwkFcSaveCountBitShift(int newNwkFcSaveCountBitShift) {
		int oldNwkFcSaveCountBitShift = nwkFcSaveCountBitShift;
		nwkFcSaveCountBitShift = newNwkFcSaveCountBitShift;
		if (eNotificationRequired())
			eNotify(new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.NODE__NWK_FC_SAVE_COUNT_BIT_SHIFT, oldNwkFcSaveCountBitShift, nwkFcSaveCountBitShift));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public int getApsFcSaveCountBitShift() {
		return apsFcSaveCountBitShift;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void setApsFcSaveCountBitShift(int newApsFcSaveCountBitShift) {
		int oldApsFcSaveCountBitShift = apsFcSaveCountBitShift;
		apsFcSaveCountBitShift = newApsFcSaveCountBitShift;
		if (eNotificationRequired())
			eNotify(new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.NODE__APS_FC_SAVE_COUNT_BIT_SHIFT, oldApsFcSaveCountBitShift, apsFcSaveCountBitShift));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public BigInteger getMacTableSize() {
		return macTableSize;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void setMacTableSize(BigInteger newMacTableSize) {
		BigInteger oldMacTableSize = macTableSize;
		macTableSize = newMacTableSize;
		if (eNotificationRequired())
			eNotify(new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.NODE__MAC_TABLE_SIZE, oldMacTableSize, macTableSize));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public String getDefaultCallbackName() {
		return defaultCallbackName;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void setDefaultCallbackName(String newDefaultCallbackName) {
		String oldDefaultCallbackName = defaultCallbackName;
		defaultCallbackName = newDefaultCallbackName;
		if (eNotificationRequired())
			eNotify(new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.NODE__DEFAULT_CALLBACK_NAME, oldDefaultCallbackName, defaultCallbackName));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public MacInterfaceList getMacInterfaceList() {
		return macInterfaceList;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public NotificationChain basicSetMacInterfaceList(MacInterfaceList newMacInterfaceList, NotificationChain msgs) {
		MacInterfaceList oldMacInterfaceList = macInterfaceList;
		macInterfaceList = newMacInterfaceList;
		if (eNotificationRequired()) {
			ENotificationImpl notification = new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.NODE__MAC_INTERFACE_LIST, oldMacInterfaceList, newMacInterfaceList);
			if (msgs == null) msgs = notification; else msgs.add(notification);
		}
		return msgs;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void setMacInterfaceList(MacInterfaceList newMacInterfaceList) {
		if (newMacInterfaceList != macInterfaceList) {
			NotificationChain msgs = null;
			if (macInterfaceList != null)
				msgs = ((InternalEObject)macInterfaceList).eInverseRemove(this, EOPPOSITE_FEATURE_BASE - ZPSConfigurationPackage.NODE__MAC_INTERFACE_LIST, null, msgs);
			if (newMacInterfaceList != null)
				msgs = ((InternalEObject)newMacInterfaceList).eInverseAdd(this, EOPPOSITE_FEATURE_BASE - ZPSConfigurationPackage.NODE__MAC_INTERFACE_LIST, null, msgs);
			msgs = basicSetMacInterfaceList(newMacInterfaceList, msgs);
			if (msgs != null) msgs.dispatch();
		}
		else if (eNotificationRequired())
			eNotify(new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.NODE__MAC_INTERFACE_LIST, newMacInterfaceList, newMacInterfaceList));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public GreenPowerTxQueue getGreenPowerTxQueue() {
		return greenPowerTxQueue;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public NotificationChain basicSetGreenPowerTxQueue(GreenPowerTxQueue newGreenPowerTxQueue, NotificationChain msgs) {
		GreenPowerTxQueue oldGreenPowerTxQueue = greenPowerTxQueue;
		greenPowerTxQueue = newGreenPowerTxQueue;
		if (eNotificationRequired()) {
			ENotificationImpl notification = new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.NODE__GREEN_POWER_TX_QUEUE, oldGreenPowerTxQueue, newGreenPowerTxQueue);
			if (msgs == null) msgs = notification; else msgs.add(notification);
		}
		return msgs;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void setGreenPowerTxQueue(GreenPowerTxQueue newGreenPowerTxQueue) {
		if (newGreenPowerTxQueue != greenPowerTxQueue) {
			NotificationChain msgs = null;
			if (greenPowerTxQueue != null)
				msgs = ((InternalEObject)greenPowerTxQueue).eInverseRemove(this, EOPPOSITE_FEATURE_BASE - ZPSConfigurationPackage.NODE__GREEN_POWER_TX_QUEUE, null, msgs);
			if (newGreenPowerTxQueue != null)
				msgs = ((InternalEObject)newGreenPowerTxQueue).eInverseAdd(this, EOPPOSITE_FEATURE_BASE - ZPSConfigurationPackage.NODE__GREEN_POWER_TX_QUEUE, null, msgs);
			msgs = basicSetGreenPowerTxQueue(newGreenPowerTxQueue, msgs);
			if (msgs != null) msgs.dispatch();
		}
		else if (eNotificationRequired())
			eNotify(new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.NODE__GREEN_POWER_TX_QUEUE, newGreenPowerTxQueue, newGreenPowerTxQueue));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public GreenPowerSecurityTable getGreenPowerSecurityTable() {
		return greenPowerSecurityTable;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public NotificationChain basicSetGreenPowerSecurityTable(GreenPowerSecurityTable newGreenPowerSecurityTable, NotificationChain msgs) {
		GreenPowerSecurityTable oldGreenPowerSecurityTable = greenPowerSecurityTable;
		greenPowerSecurityTable = newGreenPowerSecurityTable;
		if (eNotificationRequired()) {
			ENotificationImpl notification = new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.NODE__GREEN_POWER_SECURITY_TABLE, oldGreenPowerSecurityTable, newGreenPowerSecurityTable);
			if (msgs == null) msgs = notification; else msgs.add(notification);
		}
		return msgs;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void setGreenPowerSecurityTable(GreenPowerSecurityTable newGreenPowerSecurityTable) {
		if (newGreenPowerSecurityTable != greenPowerSecurityTable) {
			NotificationChain msgs = null;
			if (greenPowerSecurityTable != null)
				msgs = ((InternalEObject)greenPowerSecurityTable).eInverseRemove(this, EOPPOSITE_FEATURE_BASE - ZPSConfigurationPackage.NODE__GREEN_POWER_SECURITY_TABLE, null, msgs);
			if (newGreenPowerSecurityTable != null)
				msgs = ((InternalEObject)newGreenPowerSecurityTable).eInverseAdd(this, EOPPOSITE_FEATURE_BASE - ZPSConfigurationPackage.NODE__GREEN_POWER_SECURITY_TABLE, null, msgs);
			msgs = basicSetGreenPowerSecurityTable(newGreenPowerSecurityTable, msgs);
			if (msgs != null) msgs.dispatch();
		}
		else if (eNotificationRequired())
			eNotify(new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.NODE__GREEN_POWER_SECURITY_TABLE, newGreenPowerSecurityTable, newGreenPowerSecurityTable));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public int getAPSDuplicateTableSize() {
		return apsDuplicateTableSize;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void setAPSDuplicateTableSize(int newAPSDuplicateTableSize) {
		int oldAPSDuplicateTableSize = apsDuplicateTableSize;
		apsDuplicateTableSize = newAPSDuplicateTableSize;
		if (eNotificationRequired())
			eNotify(new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.NODE__APS_DUPLICATE_TABLE_SIZE, oldAPSDuplicateTableSize, apsDuplicateTableSize));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	@SuppressWarnings("unchecked")
	@Override
	public NotificationChain eInverseAdd(InternalEObject otherEnd, int featureID, NotificationChain msgs) {
		switch (featureID) {
			case ZPSConfigurationPackage.NODE__ENDPOINTS:
				return ((InternalEList<InternalEObject>)(InternalEList<?>)getEndpoints()).basicAdd(otherEnd, msgs);
			case ZPSConfigurationPackage.NODE__PDU_CONFIGURATION:
				if (pduConfiguration != null)
					msgs = ((InternalEObject)pduConfiguration).eInverseRemove(this, EOPPOSITE_FEATURE_BASE - ZPSConfigurationPackage.NODE__PDU_CONFIGURATION, null, msgs);
				return basicSetPDUConfiguration((PDUManager)otherEnd, msgs);
			case ZPSConfigurationPackage.NODE__NODE_DESCRIPTOR:
				if (nodeDescriptor != null)
					msgs = ((InternalEObject)nodeDescriptor).eInverseRemove(this, EOPPOSITE_FEATURE_BASE - ZPSConfigurationPackage.NODE__NODE_DESCRIPTOR, null, msgs);
				return basicSetNodeDescriptor((NodeDescriptor)otherEnd, msgs);
		}
		return super.eInverseAdd(otherEnd, featureID, msgs);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	@Override
	public NotificationChain eInverseRemove(InternalEObject otherEnd, int featureID, NotificationChain msgs) {
		switch (featureID) {
			case ZPSConfigurationPackage.NODE__ENDPOINTS:
				return ((InternalEList<?>)getEndpoints()).basicRemove(otherEnd, msgs);
			case ZPSConfigurationPackage.NODE__PDU_CONFIGURATION:
				return basicSetPDUConfiguration(null, msgs);
			case ZPSConfigurationPackage.NODE__CHANNEL_MASK:
				return basicSetChannelMask(null, msgs);
			case ZPSConfigurationPackage.NODE__NODE_DESCRIPTOR:
				return basicSetNodeDescriptor(null, msgs);
			case ZPSConfigurationPackage.NODE__NODE_POWER_DESCRIPTOR:
				return basicSetNodePowerDescriptor(null, msgs);
			case ZPSConfigurationPackage.NODE__USER_DESCRIPTOR:
				return basicSetUserDescriptor(null, msgs);
			case ZPSConfigurationPackage.NODE__BINDING_TABLE:
				return basicSetBindingTable(null, msgs);
			case ZPSConfigurationPackage.NODE__GROUP_TABLE:
				return basicSetGroupTable(null, msgs);
			case ZPSConfigurationPackage.NODE__KEY_DESCRIPTOR_TABLE:
				return basicSetKeyDescriptorTable(null, msgs);
			case ZPSConfigurationPackage.NODE__GREEN_POWER_TX_QUEUE:
				return basicSetGreenPowerTxQueue(null, msgs);
			case ZPSConfigurationPackage.NODE__GREEN_POWER_SECURITY_TABLE:
				return basicSetGreenPowerSecurityTable(null, msgs);
			case ZPSConfigurationPackage.NODE__MAC_INTERFACE_LIST:
				return basicSetMacInterfaceList(null, msgs);
		}
		return super.eInverseRemove(otherEnd, featureID, msgs);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	@Override
	public Object eGet(int featureID, boolean resolve, boolean coreType) {
		switch (featureID) {
			case ZPSConfigurationPackage.NODE__ENDPOINTS:
				return getEndpoints();
			case ZPSConfigurationPackage.NODE__PDU_CONFIGURATION:
				return getPDUConfiguration();
			case ZPSConfigurationPackage.NODE__CHANNEL_MASK:
				return getChannelMask();
			case ZPSConfigurationPackage.NODE__NODE_DESCRIPTOR:
				return getNodeDescriptor();
			case ZPSConfigurationPackage.NODE__NODE_POWER_DESCRIPTOR:
				return getNodePowerDescriptor();
			case ZPSConfigurationPackage.NODE__USER_DESCRIPTOR:
				return getUserDescriptor();
			case ZPSConfigurationPackage.NODE__BINDING_TABLE:
				return getBindingTable();
			case ZPSConfigurationPackage.NODE__GROUP_TABLE:
				return getGroupTable();
			case ZPSConfigurationPackage.NODE__KEY_DESCRIPTOR_TABLE:
				return getKeyDescriptorTable();
			case ZPSConfigurationPackage.NODE__GREEN_POWER_TX_QUEUE:
				return getGreenPowerTxQueue();
			case ZPSConfigurationPackage.NODE__GREEN_POWER_SECURITY_TABLE:
				return getGreenPowerSecurityTable();
			case ZPSConfigurationPackage.NODE__DISCOVERY_NEIGHBOUR_TABLE_SIZE:
				return getDiscoveryNeighbourTableSize();
			case ZPSConfigurationPackage.NODE__ACTIVE_NEIGHBOUR_TABLE_SIZE:
				return getActiveNeighbourTableSize();
			case ZPSConfigurationPackage.NODE__ROUTE_DISCOVERY_TABLE_SIZE:
				return getRouteDiscoveryTableSize();
			case ZPSConfigurationPackage.NODE__ROUTING_TABLE_SIZE:
				return getRoutingTableSize();
			case ZPSConfigurationPackage.NODE__BROADCAST_TRANSACTION_TABLE_SIZE:
				return getBroadcastTransactionTableSize();
			case ZPSConfigurationPackage.NODE__ROUTE_RECORD_TABLE_SIZE:
				return getRouteRecordTableSize();
			case ZPSConfigurationPackage.NODE__ADDRESS_MAP_TABLE_SIZE:
				return getAddressMapTableSize();
			case ZPSConfigurationPackage.NODE__SECURITY_MATERIAL_SETS:
				return getSecurityMaterialSets();
			case ZPSConfigurationPackage.NODE__MAX_NUM_SIMULTANEOUS_APSDE_REQ:
				return getMaxNumSimultaneousApsdeReq();
			case ZPSConfigurationPackage.NODE__MAX_NUM_SIMULTANEOUS_APSDE_ACK_REQ:
				return getMaxNumSimultaneousApsdeAckReq();
			case ZPSConfigurationPackage.NODE__MAC_MUTEX_NAME:
				return getMACMutexName();
			case ZPSConfigurationPackage.NODE__ZPS_MUTEX_NAME:
				return getZPSMutexName();
			case ZPSConfigurationPackage.NODE__FRAGMENTATION_MAX_NUM_SIMUL_RX:
				return getFragmentationMaxNumSimulRx();
			case ZPSConfigurationPackage.NODE__FRAGMENTATION_MAX_NUM_SIMUL_TX:
				return getFragmentationMaxNumSimulTx();
			case ZPSConfigurationPackage.NODE__DEFAULT_EVENT_MESSAGE_NAME:
				return getDefaultEventMessageName();
			case ZPSConfigurationPackage.NODE__MAC_DCFM_IND_MESSAGE:
				return getMACDcfmIndMessage();
			case ZPSConfigurationPackage.NODE__MAC_TIME_EVENT_MESSAGE:
				return getMACTimeEventMessage();
			case ZPSConfigurationPackage.NODE__APS_NON_MEMBER_RADIUS:
				return getApsNonMemberRadius();
			case ZPSConfigurationPackage.NODE__APS_DESIGNATED_COORDINATOR:
				return isApsDesignatedCoordinator();
			case ZPSConfigurationPackage.NODE__APS_USE_INSECURE_JOIN:
				return isApsUseInsecureJoin();
			case ZPSConfigurationPackage.NODE__APS_MAX_WINDOW_SIZE:
				return getApsMaxWindowSize();
			case ZPSConfigurationPackage.NODE__APS_INTERFRAME_DELAY:
				return getApsInterframeDelay();
			case ZPSConfigurationPackage.NODE__APS_DUPLICATE_TABLE_SIZE:
				return getAPSDuplicateTableSize();
			case ZPSConfigurationPackage.NODE__APS_SECURITY_TIMEOUT_PERIOD:
				return getApsSecurityTimeoutPeriod();
			case ZPSConfigurationPackage.NODE__APS_USE_EXT_PAN_ID:
				return getApsUseExtPANId();
			case ZPSConfigurationPackage.NODE__INITIAL_NETWORK_KEY:
				if (resolve) return getInitialNetworkKey();
				return basicGetInitialNetworkKey();
			case ZPSConfigurationPackage.NODE__SECURITY_ENABLED:
				return isSecurityEnabled();
			case ZPSConfigurationPackage.NODE__MAC_MLME_DCFM_IND_MESSAGE:
				return getMACMlmeDcfmIndMessage();
			case ZPSConfigurationPackage.NODE__MAC_MCPS_DCFM_IND_MESSAGE:
				return getMACMcpsDcfmIndMessage();
			case ZPSConfigurationPackage.NODE__APS_PERSISTENCE_TIME:
				return getAPSPersistenceTime();
			case ZPSConfigurationPackage.NODE__NUM_APSME_SIMUL_COMMANDS:
				return getNumAPSMESimulCommands();
			case ZPSConfigurationPackage.NODE__STACK_PROFILE:
				return getStackProfile();
			case ZPSConfigurationPackage.NODE__INTER_PAN:
				return isInterPAN();
			case ZPSConfigurationPackage.NODE__GREEN_POWER_SUPPORT:
				return isGreenPowerSupport();
			case ZPSConfigurationPackage.NODE__NWK_FC_SAVE_COUNT_BIT_SHIFT:
				return getNwkFcSaveCountBitShift();
			case ZPSConfigurationPackage.NODE__APS_FC_SAVE_COUNT_BIT_SHIFT:
				return getApsFcSaveCountBitShift();
			case ZPSConfigurationPackage.NODE__MAC_TABLE_SIZE:
				return getMacTableSize();
			case ZPSConfigurationPackage.NODE__DEFAULT_CALLBACK_NAME:
				return getDefaultCallbackName();
			case ZPSConfigurationPackage.NODE__MAC_INTERFACE_LIST:
				return getMacInterfaceList();
		}
		return super.eGet(featureID, resolve, coreType);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	@SuppressWarnings("unchecked")
	@Override
	public void eSet(int featureID, Object newValue) {
		switch (featureID) {
			case ZPSConfigurationPackage.NODE__ENDPOINTS:
				getEndpoints().clear();
				getEndpoints().addAll((Collection<? extends EndPoint>)newValue);
				return;
			case ZPSConfigurationPackage.NODE__PDU_CONFIGURATION:
				setPDUConfiguration((PDUManager)newValue);
				return;
			case ZPSConfigurationPackage.NODE__CHANNEL_MASK:
				setChannelMask((ChannelMask)newValue);
				return;
			case ZPSConfigurationPackage.NODE__NODE_DESCRIPTOR:
				setNodeDescriptor((NodeDescriptor)newValue);
				return;
			case ZPSConfigurationPackage.NODE__NODE_POWER_DESCRIPTOR:
				setNodePowerDescriptor((NodePowerDescriptor)newValue);
				return;
			case ZPSConfigurationPackage.NODE__USER_DESCRIPTOR:
				setUserDescriptor((UserDescriptor)newValue);
				return;
			case ZPSConfigurationPackage.NODE__BINDING_TABLE:
				setBindingTable((BindingTable)newValue);
				return;
			case ZPSConfigurationPackage.NODE__GROUP_TABLE:
				setGroupTable((GroupTable)newValue);
				return;
			case ZPSConfigurationPackage.NODE__KEY_DESCRIPTOR_TABLE:
				setKeyDescriptorTable((KeyDescriptorTable)newValue);
				return;
			case ZPSConfigurationPackage.NODE__GREEN_POWER_TX_QUEUE:
				setGreenPowerTxQueue((GreenPowerTxQueue)newValue);
				return;
			case ZPSConfigurationPackage.NODE__GREEN_POWER_SECURITY_TABLE:
				setGreenPowerSecurityTable((GreenPowerSecurityTable)newValue);
				return;
			case ZPSConfigurationPackage.NODE__DISCOVERY_NEIGHBOUR_TABLE_SIZE:
				setDiscoveryNeighbourTableSize((BigInteger)newValue);
				return;
			case ZPSConfigurationPackage.NODE__ACTIVE_NEIGHBOUR_TABLE_SIZE:
				setActiveNeighbourTableSize((BigInteger)newValue);
				return;
			case ZPSConfigurationPackage.NODE__ROUTE_DISCOVERY_TABLE_SIZE:
				setRouteDiscoveryTableSize((BigInteger)newValue);
				return;
			case ZPSConfigurationPackage.NODE__ROUTING_TABLE_SIZE:
				setRoutingTableSize((BigInteger)newValue);
				return;
			case ZPSConfigurationPackage.NODE__BROADCAST_TRANSACTION_TABLE_SIZE:
				setBroadcastTransactionTableSize((BigInteger)newValue);
				return;
			case ZPSConfigurationPackage.NODE__ROUTE_RECORD_TABLE_SIZE:
				setRouteRecordTableSize((BigInteger)newValue);
				return;
			case ZPSConfigurationPackage.NODE__ADDRESS_MAP_TABLE_SIZE:
				setAddressMapTableSize((BigInteger)newValue);
				return;
			case ZPSConfigurationPackage.NODE__SECURITY_MATERIAL_SETS:
				setSecurityMaterialSets((BigInteger)newValue);
				return;
			case ZPSConfigurationPackage.NODE__MAX_NUM_SIMULTANEOUS_APSDE_REQ:
				setMaxNumSimultaneousApsdeReq((Integer)newValue);
				return;
			case ZPSConfigurationPackage.NODE__MAX_NUM_SIMULTANEOUS_APSDE_ACK_REQ:
				setMaxNumSimultaneousApsdeAckReq((BigInteger)newValue);
				return;
			case ZPSConfigurationPackage.NODE__MAC_MUTEX_NAME:
				setMACMutexName((String)newValue);
				return;
			case ZPSConfigurationPackage.NODE__ZPS_MUTEX_NAME:
				setZPSMutexName((String)newValue);
				return;
			case ZPSConfigurationPackage.NODE__FRAGMENTATION_MAX_NUM_SIMUL_RX:
				setFragmentationMaxNumSimulRx((Integer)newValue);
				return;
			case ZPSConfigurationPackage.NODE__FRAGMENTATION_MAX_NUM_SIMUL_TX:
				setFragmentationMaxNumSimulTx((Integer)newValue);
				return;
			case ZPSConfigurationPackage.NODE__DEFAULT_EVENT_MESSAGE_NAME:
				setDefaultEventMessageName((String)newValue);
				return;
			case ZPSConfigurationPackage.NODE__MAC_DCFM_IND_MESSAGE:
				setMACDcfmIndMessage((String)newValue);
				return;
			case ZPSConfigurationPackage.NODE__MAC_TIME_EVENT_MESSAGE:
				setMACTimeEventMessage((String)newValue);
				return;
			case ZPSConfigurationPackage.NODE__APS_NON_MEMBER_RADIUS:
				setApsNonMemberRadius((Integer)newValue);
				return;
			case ZPSConfigurationPackage.NODE__APS_DESIGNATED_COORDINATOR:
				setApsDesignatedCoordinator((Boolean)newValue);
				return;
			case ZPSConfigurationPackage.NODE__APS_USE_INSECURE_JOIN:
				setApsUseInsecureJoin((Boolean)newValue);
				return;
			case ZPSConfigurationPackage.NODE__APS_MAX_WINDOW_SIZE:
				setApsMaxWindowSize((Integer)newValue);
				return;
			case ZPSConfigurationPackage.NODE__APS_INTERFRAME_DELAY:
				setApsInterframeDelay((Integer)newValue);
				return;
			case ZPSConfigurationPackage.NODE__APS_DUPLICATE_TABLE_SIZE:
				setAPSDuplicateTableSize((Integer)newValue);
				return;
			case ZPSConfigurationPackage.NODE__APS_SECURITY_TIMEOUT_PERIOD:
				setApsSecurityTimeoutPeriod((BigInteger)newValue);
				return;
			case ZPSConfigurationPackage.NODE__APS_USE_EXT_PAN_ID:
				setApsUseExtPANId((Object)newValue);
				return;
			case ZPSConfigurationPackage.NODE__INITIAL_NETWORK_KEY:
				setInitialNetworkKey((TCKey)newValue);
				return;
			case ZPSConfigurationPackage.NODE__SECURITY_ENABLED:
				setSecurityEnabled((Boolean)newValue);
				return;
			case ZPSConfigurationPackage.NODE__MAC_MLME_DCFM_IND_MESSAGE:
				setMACMlmeDcfmIndMessage((String)newValue);
				return;
			case ZPSConfigurationPackage.NODE__MAC_MCPS_DCFM_IND_MESSAGE:
				setMACMcpsDcfmIndMessage((String)newValue);
				return;
			case ZPSConfigurationPackage.NODE__APS_PERSISTENCE_TIME:
				setAPSPersistenceTime((Integer)newValue);
				return;
			case ZPSConfigurationPackage.NODE__NUM_APSME_SIMUL_COMMANDS:
				setNumAPSMESimulCommands((Integer)newValue);
				return;
			case ZPSConfigurationPackage.NODE__STACK_PROFILE:
				setStackProfile((Integer)newValue);
				return;
			case ZPSConfigurationPackage.NODE__INTER_PAN:
				setInterPAN((Boolean)newValue);
				return;
			case ZPSConfigurationPackage.NODE__GREEN_POWER_SUPPORT:
				setGreenPowerSupport((Boolean)newValue);
				return;
			case ZPSConfigurationPackage.NODE__NWK_FC_SAVE_COUNT_BIT_SHIFT:
				setNwkFcSaveCountBitShift((Integer)newValue);
				return;
			case ZPSConfigurationPackage.NODE__APS_FC_SAVE_COUNT_BIT_SHIFT:
				setApsFcSaveCountBitShift((Integer)newValue);
				return;
			case ZPSConfigurationPackage.NODE__MAC_TABLE_SIZE:
				setMacTableSize((BigInteger)newValue);
				return;
			case ZPSConfigurationPackage.NODE__DEFAULT_CALLBACK_NAME:
				setDefaultCallbackName((String)newValue);
				return;
			case ZPSConfigurationPackage.NODE__MAC_INTERFACE_LIST:
				setMacInterfaceList((MacInterfaceList)newValue);
				return;
		}
		super.eSet(featureID, newValue);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	@Override
	public void eUnset(int featureID) {
		switch (featureID) {
			case ZPSConfigurationPackage.NODE__ENDPOINTS:
				getEndpoints().clear();
				return;
			case ZPSConfigurationPackage.NODE__PDU_CONFIGURATION:
				setPDUConfiguration((PDUManager)null);
				return;
			case ZPSConfigurationPackage.NODE__CHANNEL_MASK:
				setChannelMask((ChannelMask)null);
				return;
			case ZPSConfigurationPackage.NODE__NODE_DESCRIPTOR:
				setNodeDescriptor((NodeDescriptor)null);
				return;
			case ZPSConfigurationPackage.NODE__NODE_POWER_DESCRIPTOR:
				setNodePowerDescriptor((NodePowerDescriptor)null);
				return;
			case ZPSConfigurationPackage.NODE__USER_DESCRIPTOR:
				setUserDescriptor((UserDescriptor)null);
				return;
			case ZPSConfigurationPackage.NODE__BINDING_TABLE:
				setBindingTable((BindingTable)null);
				return;
			case ZPSConfigurationPackage.NODE__GROUP_TABLE:
				setGroupTable((GroupTable)null);
				return;
			case ZPSConfigurationPackage.NODE__KEY_DESCRIPTOR_TABLE:
				setKeyDescriptorTable((KeyDescriptorTable)null);
				return;
			case ZPSConfigurationPackage.NODE__GREEN_POWER_TX_QUEUE:
				setGreenPowerTxQueue((GreenPowerTxQueue)null);
				return;
			case ZPSConfigurationPackage.NODE__GREEN_POWER_SECURITY_TABLE:
				setGreenPowerSecurityTable((GreenPowerSecurityTable)null);
				return;
			case ZPSConfigurationPackage.NODE__DISCOVERY_NEIGHBOUR_TABLE_SIZE:
				setDiscoveryNeighbourTableSize(DISCOVERY_NEIGHBOUR_TABLE_SIZE_EDEFAULT);
				return;
			case ZPSConfigurationPackage.NODE__ACTIVE_NEIGHBOUR_TABLE_SIZE:
				setActiveNeighbourTableSize(ACTIVE_NEIGHBOUR_TABLE_SIZE_EDEFAULT);
				return;
			case ZPSConfigurationPackage.NODE__ROUTE_DISCOVERY_TABLE_SIZE:
				setRouteDiscoveryTableSize(ROUTE_DISCOVERY_TABLE_SIZE_EDEFAULT);
				return;
			case ZPSConfigurationPackage.NODE__ROUTING_TABLE_SIZE:
				setRoutingTableSize(ROUTING_TABLE_SIZE_EDEFAULT);
				return;
			case ZPSConfigurationPackage.NODE__BROADCAST_TRANSACTION_TABLE_SIZE:
				setBroadcastTransactionTableSize(BROADCAST_TRANSACTION_TABLE_SIZE_EDEFAULT);
				return;
			case ZPSConfigurationPackage.NODE__ROUTE_RECORD_TABLE_SIZE:
				setRouteRecordTableSize(ROUTE_RECORD_TABLE_SIZE_EDEFAULT);
				return;
			case ZPSConfigurationPackage.NODE__ADDRESS_MAP_TABLE_SIZE:
				setAddressMapTableSize(ADDRESS_MAP_TABLE_SIZE_EDEFAULT);
				return;
			case ZPSConfigurationPackage.NODE__SECURITY_MATERIAL_SETS:
				setSecurityMaterialSets(SECURITY_MATERIAL_SETS_EDEFAULT);
				return;
			case ZPSConfigurationPackage.NODE__MAX_NUM_SIMULTANEOUS_APSDE_REQ:
				setMaxNumSimultaneousApsdeReq(MAX_NUM_SIMULTANEOUS_APSDE_REQ_EDEFAULT);
				return;
			case ZPSConfigurationPackage.NODE__MAX_NUM_SIMULTANEOUS_APSDE_ACK_REQ:
				setMaxNumSimultaneousApsdeAckReq(MAX_NUM_SIMULTANEOUS_APSDE_ACK_REQ_EDEFAULT);
				return;
			case ZPSConfigurationPackage.NODE__MAC_MUTEX_NAME:
				setMACMutexName(MAC_MUTEX_NAME_EDEFAULT);
				return;
			case ZPSConfigurationPackage.NODE__ZPS_MUTEX_NAME:
				setZPSMutexName(ZPS_MUTEX_NAME_EDEFAULT);
				return;
			case ZPSConfigurationPackage.NODE__FRAGMENTATION_MAX_NUM_SIMUL_RX:
				setFragmentationMaxNumSimulRx(FRAGMENTATION_MAX_NUM_SIMUL_RX_EDEFAULT);
				return;
			case ZPSConfigurationPackage.NODE__FRAGMENTATION_MAX_NUM_SIMUL_TX:
				setFragmentationMaxNumSimulTx(FRAGMENTATION_MAX_NUM_SIMUL_TX_EDEFAULT);
				return;
			case ZPSConfigurationPackage.NODE__DEFAULT_EVENT_MESSAGE_NAME:
				setDefaultEventMessageName(DEFAULT_EVENT_MESSAGE_NAME_EDEFAULT);
				return;
			case ZPSConfigurationPackage.NODE__MAC_DCFM_IND_MESSAGE:
				setMACDcfmIndMessage(MAC_DCFM_IND_MESSAGE_EDEFAULT);
				return;
			case ZPSConfigurationPackage.NODE__MAC_TIME_EVENT_MESSAGE:
				setMACTimeEventMessage(MAC_TIME_EVENT_MESSAGE_EDEFAULT);
				return;
			case ZPSConfigurationPackage.NODE__APS_NON_MEMBER_RADIUS:
				setApsNonMemberRadius(APS_NON_MEMBER_RADIUS_EDEFAULT);
				return;
			case ZPSConfigurationPackage.NODE__APS_DESIGNATED_COORDINATOR:
				setApsDesignatedCoordinator(APS_DESIGNATED_COORDINATOR_EDEFAULT);
				return;
			case ZPSConfigurationPackage.NODE__APS_USE_INSECURE_JOIN:
				setApsUseInsecureJoin(APS_USE_INSECURE_JOIN_EDEFAULT);
				return;
			case ZPSConfigurationPackage.NODE__APS_MAX_WINDOW_SIZE:
				setApsMaxWindowSize(APS_MAX_WINDOW_SIZE_EDEFAULT);
				return;
			case ZPSConfigurationPackage.NODE__APS_INTERFRAME_DELAY:
				setApsInterframeDelay(APS_INTERFRAME_DELAY_EDEFAULT);
				return;
			case ZPSConfigurationPackage.NODE__APS_DUPLICATE_TABLE_SIZE:
				setAPSDuplicateTableSize(APS_DUPLICATE_TABLE_SIZE_EDEFAULT);
				return;
			case ZPSConfigurationPackage.NODE__APS_SECURITY_TIMEOUT_PERIOD:
				setApsSecurityTimeoutPeriod(APS_SECURITY_TIMEOUT_PERIOD_EDEFAULT);
				return;
			case ZPSConfigurationPackage.NODE__APS_USE_EXT_PAN_ID:
				setApsUseExtPANId(APS_USE_EXT_PAN_ID_EDEFAULT);
				return;
			case ZPSConfigurationPackage.NODE__INITIAL_NETWORK_KEY:
				setInitialNetworkKey((TCKey)null);
				return;
			case ZPSConfigurationPackage.NODE__SECURITY_ENABLED:
				setSecurityEnabled(SECURITY_ENABLED_EDEFAULT);
				return;
			case ZPSConfigurationPackage.NODE__MAC_MLME_DCFM_IND_MESSAGE:
				setMACMlmeDcfmIndMessage(MAC_MLME_DCFM_IND_MESSAGE_EDEFAULT);
				return;
			case ZPSConfigurationPackage.NODE__MAC_MCPS_DCFM_IND_MESSAGE:
				setMACMcpsDcfmIndMessage(MAC_MCPS_DCFM_IND_MESSAGE_EDEFAULT);
				return;
			case ZPSConfigurationPackage.NODE__APS_PERSISTENCE_TIME:
				setAPSPersistenceTime(APS_PERSISTENCE_TIME_EDEFAULT);
				return;
			case ZPSConfigurationPackage.NODE__NUM_APSME_SIMUL_COMMANDS:
				setNumAPSMESimulCommands(NUM_APSME_SIMUL_COMMANDS_EDEFAULT);
				return;
			case ZPSConfigurationPackage.NODE__STACK_PROFILE:
				setStackProfile(STACK_PROFILE_EDEFAULT);
				return;
			case ZPSConfigurationPackage.NODE__INTER_PAN:
				setInterPAN(INTER_PAN_EDEFAULT);
				return;
			case ZPSConfigurationPackage.NODE__GREEN_POWER_SUPPORT:
				setGreenPowerSupport(GREEN_POWER_SUPPORT_EDEFAULT);
				return;
			case ZPSConfigurationPackage.NODE__NWK_FC_SAVE_COUNT_BIT_SHIFT:
				setNwkFcSaveCountBitShift(NWK_FC_SAVE_COUNT_BIT_SHIFT_EDEFAULT);
				return;
			case ZPSConfigurationPackage.NODE__APS_FC_SAVE_COUNT_BIT_SHIFT:
				setApsFcSaveCountBitShift(APS_FC_SAVE_COUNT_BIT_SHIFT_EDEFAULT);
				return;
			case ZPSConfigurationPackage.NODE__MAC_TABLE_SIZE:
				setMacTableSize(MAC_TABLE_SIZE_EDEFAULT);
				return;
			case ZPSConfigurationPackage.NODE__DEFAULT_CALLBACK_NAME:
				setDefaultCallbackName(DEFAULT_CALLBACK_NAME_EDEFAULT);
				return;
			case ZPSConfigurationPackage.NODE__MAC_INTERFACE_LIST:
				setMacInterfaceList((MacInterfaceList)null);
				return;
		}
		super.eUnset(featureID);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	@Override
	public boolean eIsSet(int featureID) {
		switch (featureID) {
			case ZPSConfigurationPackage.NODE__ENDPOINTS:
				return endpoints != null && !endpoints.isEmpty();
			case ZPSConfigurationPackage.NODE__PDU_CONFIGURATION:
				return pduConfiguration != null;
			case ZPSConfigurationPackage.NODE__CHANNEL_MASK:
				return channelMask != null;
			case ZPSConfigurationPackage.NODE__NODE_DESCRIPTOR:
				return nodeDescriptor != null;
			case ZPSConfigurationPackage.NODE__NODE_POWER_DESCRIPTOR:
				return nodePowerDescriptor != null;
			case ZPSConfigurationPackage.NODE__USER_DESCRIPTOR:
				return userDescriptor != null;
			case ZPSConfigurationPackage.NODE__BINDING_TABLE:
				return bindingTable != null;
			case ZPSConfigurationPackage.NODE__GROUP_TABLE:
				return groupTable != null;
			case ZPSConfigurationPackage.NODE__KEY_DESCRIPTOR_TABLE:
				return keyDescriptorTable != null;
			case ZPSConfigurationPackage.NODE__GREEN_POWER_TX_QUEUE:
				return greenPowerTxQueue != null;
			case ZPSConfigurationPackage.NODE__GREEN_POWER_SECURITY_TABLE:
				return greenPowerSecurityTable != null;
			case ZPSConfigurationPackage.NODE__DISCOVERY_NEIGHBOUR_TABLE_SIZE:
				return DISCOVERY_NEIGHBOUR_TABLE_SIZE_EDEFAULT == null ? discoveryNeighbourTableSize != null : !DISCOVERY_NEIGHBOUR_TABLE_SIZE_EDEFAULT.equals(discoveryNeighbourTableSize);
			case ZPSConfigurationPackage.NODE__ACTIVE_NEIGHBOUR_TABLE_SIZE:
				return ACTIVE_NEIGHBOUR_TABLE_SIZE_EDEFAULT == null ? activeNeighbourTableSize != null : !ACTIVE_NEIGHBOUR_TABLE_SIZE_EDEFAULT.equals(activeNeighbourTableSize);
			case ZPSConfigurationPackage.NODE__ROUTE_DISCOVERY_TABLE_SIZE:
				return ROUTE_DISCOVERY_TABLE_SIZE_EDEFAULT == null ? routeDiscoveryTableSize != null : !ROUTE_DISCOVERY_TABLE_SIZE_EDEFAULT.equals(routeDiscoveryTableSize);
			case ZPSConfigurationPackage.NODE__ROUTING_TABLE_SIZE:
				return ROUTING_TABLE_SIZE_EDEFAULT == null ? routingTableSize != null : !ROUTING_TABLE_SIZE_EDEFAULT.equals(routingTableSize);
			case ZPSConfigurationPackage.NODE__BROADCAST_TRANSACTION_TABLE_SIZE:
				return BROADCAST_TRANSACTION_TABLE_SIZE_EDEFAULT == null ? broadcastTransactionTableSize != null : !BROADCAST_TRANSACTION_TABLE_SIZE_EDEFAULT.equals(broadcastTransactionTableSize);
			case ZPSConfigurationPackage.NODE__ROUTE_RECORD_TABLE_SIZE:
				return ROUTE_RECORD_TABLE_SIZE_EDEFAULT == null ? routeRecordTableSize != null : !ROUTE_RECORD_TABLE_SIZE_EDEFAULT.equals(routeRecordTableSize);
			case ZPSConfigurationPackage.NODE__ADDRESS_MAP_TABLE_SIZE:
				return ADDRESS_MAP_TABLE_SIZE_EDEFAULT == null ? addressMapTableSize != null : !ADDRESS_MAP_TABLE_SIZE_EDEFAULT.equals(addressMapTableSize);
			case ZPSConfigurationPackage.NODE__SECURITY_MATERIAL_SETS:
				return SECURITY_MATERIAL_SETS_EDEFAULT == null ? securityMaterialSets != null : !SECURITY_MATERIAL_SETS_EDEFAULT.equals(securityMaterialSets);
			case ZPSConfigurationPackage.NODE__MAX_NUM_SIMULTANEOUS_APSDE_REQ:
				return maxNumSimultaneousApsdeReq != MAX_NUM_SIMULTANEOUS_APSDE_REQ_EDEFAULT;
			case ZPSConfigurationPackage.NODE__MAX_NUM_SIMULTANEOUS_APSDE_ACK_REQ:
				return MAX_NUM_SIMULTANEOUS_APSDE_ACK_REQ_EDEFAULT == null ? maxNumSimultaneousApsdeAckReq != null : !MAX_NUM_SIMULTANEOUS_APSDE_ACK_REQ_EDEFAULT.equals(maxNumSimultaneousApsdeAckReq);
			case ZPSConfigurationPackage.NODE__MAC_MUTEX_NAME:
				return MAC_MUTEX_NAME_EDEFAULT == null ? macMutexName != null : !MAC_MUTEX_NAME_EDEFAULT.equals(macMutexName);
			case ZPSConfigurationPackage.NODE__ZPS_MUTEX_NAME:
				return ZPS_MUTEX_NAME_EDEFAULT == null ? zpsMutexName != null : !ZPS_MUTEX_NAME_EDEFAULT.equals(zpsMutexName);
			case ZPSConfigurationPackage.NODE__FRAGMENTATION_MAX_NUM_SIMUL_RX:
				return fragmentationMaxNumSimulRx != FRAGMENTATION_MAX_NUM_SIMUL_RX_EDEFAULT;
			case ZPSConfigurationPackage.NODE__FRAGMENTATION_MAX_NUM_SIMUL_TX:
				return fragmentationMaxNumSimulTx != FRAGMENTATION_MAX_NUM_SIMUL_TX_EDEFAULT;
			case ZPSConfigurationPackage.NODE__DEFAULT_EVENT_MESSAGE_NAME:
				return DEFAULT_EVENT_MESSAGE_NAME_EDEFAULT == null ? defaultEventMessageName != null : !DEFAULT_EVENT_MESSAGE_NAME_EDEFAULT.equals(defaultEventMessageName);
			case ZPSConfigurationPackage.NODE__MAC_DCFM_IND_MESSAGE:
				return MAC_DCFM_IND_MESSAGE_EDEFAULT == null ? macDcfmIndMessage != null : !MAC_DCFM_IND_MESSAGE_EDEFAULT.equals(macDcfmIndMessage);
			case ZPSConfigurationPackage.NODE__MAC_TIME_EVENT_MESSAGE:
				return MAC_TIME_EVENT_MESSAGE_EDEFAULT == null ? macTimeEventMessage != null : !MAC_TIME_EVENT_MESSAGE_EDEFAULT.equals(macTimeEventMessage);
			case ZPSConfigurationPackage.NODE__APS_NON_MEMBER_RADIUS:
				return apsNonMemberRadius != APS_NON_MEMBER_RADIUS_EDEFAULT;
			case ZPSConfigurationPackage.NODE__APS_DESIGNATED_COORDINATOR:
				return apsDesignatedCoordinator != APS_DESIGNATED_COORDINATOR_EDEFAULT;
			case ZPSConfigurationPackage.NODE__APS_USE_INSECURE_JOIN:
				return apsUseInsecureJoin != APS_USE_INSECURE_JOIN_EDEFAULT;
			case ZPSConfigurationPackage.NODE__APS_MAX_WINDOW_SIZE:
				return apsMaxWindowSize != APS_MAX_WINDOW_SIZE_EDEFAULT;
			case ZPSConfigurationPackage.NODE__APS_INTERFRAME_DELAY:
				return apsInterframeDelay != APS_INTERFRAME_DELAY_EDEFAULT;
			case ZPSConfigurationPackage.NODE__APS_DUPLICATE_TABLE_SIZE:
				return apsDuplicateTableSize != APS_DUPLICATE_TABLE_SIZE_EDEFAULT;
			case ZPSConfigurationPackage.NODE__APS_SECURITY_TIMEOUT_PERIOD:
				return APS_SECURITY_TIMEOUT_PERIOD_EDEFAULT == null ? apsSecurityTimeoutPeriod != null : !APS_SECURITY_TIMEOUT_PERIOD_EDEFAULT.equals(apsSecurityTimeoutPeriod);
			case ZPSConfigurationPackage.NODE__APS_USE_EXT_PAN_ID:
				return APS_USE_EXT_PAN_ID_EDEFAULT == null ? apsUseExtPANId != null : !APS_USE_EXT_PAN_ID_EDEFAULT.equals(apsUseExtPANId);
			case ZPSConfigurationPackage.NODE__INITIAL_NETWORK_KEY:
				return initialNetworkKey != null;
			case ZPSConfigurationPackage.NODE__SECURITY_ENABLED:
				return securityEnabled != SECURITY_ENABLED_EDEFAULT;
			case ZPSConfigurationPackage.NODE__MAC_MLME_DCFM_IND_MESSAGE:
				return MAC_MLME_DCFM_IND_MESSAGE_EDEFAULT == null ? macMlmeDcfmIndMessage != null : !MAC_MLME_DCFM_IND_MESSAGE_EDEFAULT.equals(macMlmeDcfmIndMessage);
			case ZPSConfigurationPackage.NODE__MAC_MCPS_DCFM_IND_MESSAGE:
				return MAC_MCPS_DCFM_IND_MESSAGE_EDEFAULT == null ? macMcpsDcfmIndMessage != null : !MAC_MCPS_DCFM_IND_MESSAGE_EDEFAULT.equals(macMcpsDcfmIndMessage);
			case ZPSConfigurationPackage.NODE__APS_PERSISTENCE_TIME:
				return apsPersistenceTime != APS_PERSISTENCE_TIME_EDEFAULT;
			case ZPSConfigurationPackage.NODE__NUM_APSME_SIMUL_COMMANDS:
				return numAPSMESimulCommands != NUM_APSME_SIMUL_COMMANDS_EDEFAULT;
			case ZPSConfigurationPackage.NODE__STACK_PROFILE:
				return stackProfile != STACK_PROFILE_EDEFAULT;
			case ZPSConfigurationPackage.NODE__INTER_PAN:
				return interPAN != INTER_PAN_EDEFAULT;
			case ZPSConfigurationPackage.NODE__GREEN_POWER_SUPPORT:
				return greenPowerSupport != GREEN_POWER_SUPPORT_EDEFAULT;
			case ZPSConfigurationPackage.NODE__NWK_FC_SAVE_COUNT_BIT_SHIFT:
				return nwkFcSaveCountBitShift != NWK_FC_SAVE_COUNT_BIT_SHIFT_EDEFAULT;
			case ZPSConfigurationPackage.NODE__APS_FC_SAVE_COUNT_BIT_SHIFT:
				return apsFcSaveCountBitShift != APS_FC_SAVE_COUNT_BIT_SHIFT_EDEFAULT;
			case ZPSConfigurationPackage.NODE__MAC_TABLE_SIZE:
				return MAC_TABLE_SIZE_EDEFAULT == null ? macTableSize != null : !MAC_TABLE_SIZE_EDEFAULT.equals(macTableSize);
			case ZPSConfigurationPackage.NODE__DEFAULT_CALLBACK_NAME:
				return DEFAULT_CALLBACK_NAME_EDEFAULT == null ? defaultCallbackName != null : !DEFAULT_CALLBACK_NAME_EDEFAULT.equals(defaultCallbackName);
			case ZPSConfigurationPackage.NODE__MAC_INTERFACE_LIST:
				return macInterfaceList != null;
		}
		return super.eIsSet(featureID);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	@Override
	public String toString() {
		if (eIsProxy()) return super.toString();

		StringBuffer result = new StringBuffer(super.toString());
		result.append(" (DiscoveryNeighbourTableSize: ");
		result.append(discoveryNeighbourTableSize);
		result.append(", ActiveNeighbourTableSize: ");
		result.append(activeNeighbourTableSize);
		result.append(", RouteDiscoveryTableSize: ");
		result.append(routeDiscoveryTableSize);
		result.append(", RoutingTableSize: ");
		result.append(routingTableSize);
		result.append(", BroadcastTransactionTableSize: ");
		result.append(broadcastTransactionTableSize);
		result.append(", RouteRecordTableSize: ");
		result.append(routeRecordTableSize);
		result.append(", AddressMapTableSize: ");
		result.append(addressMapTableSize);
		result.append(", SecurityMaterialSets: ");
		result.append(securityMaterialSets);
		result.append(", MaxNumSimultaneousApsdeReq: ");
		result.append(maxNumSimultaneousApsdeReq);
		result.append(", MaxNumSimultaneousApsdeAckReq: ");
		result.append(maxNumSimultaneousApsdeAckReq);
		result.append(", MACMutexName: ");
		result.append(macMutexName);
		result.append(", ZPSMutexName: ");
		result.append(zpsMutexName);
		result.append(", FragmentationMaxNumSimulRx: ");
		result.append(fragmentationMaxNumSimulRx);
		result.append(", FragmentationMaxNumSimulTx: ");
		result.append(fragmentationMaxNumSimulTx);
		result.append(", DefaultEventMessageName: ");
		result.append(defaultEventMessageName);
		result.append(", MACDcfmIndMessage: ");
		result.append(macDcfmIndMessage);
		result.append(", MACTimeEventMessage: ");
		result.append(macTimeEventMessage);
		result.append(", apsNonMemberRadius: ");
		result.append(apsNonMemberRadius);
		result.append(", apsDesignatedCoordinator: ");
		result.append(apsDesignatedCoordinator);
		result.append(", apsUseInsecureJoin: ");
		result.append(apsUseInsecureJoin);
		result.append(", apsMaxWindowSize: ");
		result.append(apsMaxWindowSize);
		result.append(", apsInterframeDelay: ");
		result.append(apsInterframeDelay);
		result.append(", APSDuplicateTableSize: ");
		result.append(apsDuplicateTableSize);
		result.append(", apsSecurityTimeoutPeriod: ");
		result.append(apsSecurityTimeoutPeriod);
		result.append(", apsUseExtPANId: ");
		result.append(apsUseExtPANId);
		result.append(", SecurityEnabled: ");
		result.append(securityEnabled);
		result.append(", MACMlmeDcfmIndMessage: ");
		result.append(macMlmeDcfmIndMessage);
		result.append(", MACMcpsDcfmIndMessage: ");
		result.append(macMcpsDcfmIndMessage);
		result.append(", APSPersistenceTime: ");
		result.append(apsPersistenceTime);
		result.append(", NumAPSMESimulCommands: ");
		result.append(numAPSMESimulCommands);
		result.append(", StackProfile: ");
		result.append(stackProfile);
		result.append(", InterPAN: ");
		result.append(interPAN);
		result.append(", GreenPowerSupport: ");
		result.append(greenPowerSupport);
		result.append(", NwkFcSaveCountBitShift: ");
		result.append(nwkFcSaveCountBitShift);
		result.append(", ApsFcSaveCountBitShift: ");
		result.append(apsFcSaveCountBitShift);
		result.append(", MacTableSize: ");
		result.append(macTableSize);
		result.append(", DefaultCallbackName: ");
		result.append(defaultCallbackName);
		result.append(')');
		return result.toString();
	}

} //NodeImpl
