/**
 * (C) Jennic Ltd
 *
 * $Id$
 */
package com.jennic.ZPSConfiguration;

import java.math.BigInteger;

import org.eclipse.emf.common.util.EList;

/**
 * <!-- begin-user-doc -->
 * A representation of the model object '<em><b>Node</b></em>'.
 * <!-- end-user-doc -->
 *
 * <p>
 * The following features are supported:
 * <ul>
 *   <li>{@link com.jennic.ZPSConfiguration.Node#getEndpoints <em>Endpoints</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.Node#getPDUConfiguration <em>PDU Configuration</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.Node#getChannelMask <em>Channel Mask</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.Node#getNodeDescriptor <em>Node Descriptor</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.Node#getNodePowerDescriptor <em>Node Power Descriptor</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.Node#getUserDescriptor <em>User Descriptor</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.Node#getBindingTable <em>Binding Table</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.Node#getGroupTable <em>Group Table</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.Node#getKeyDescriptorTable <em>Key Descriptor Table</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.Node#getGreenPowerTxQueue <em>Green Power Tx Queue</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.Node#getGreenPowerSecurityTable <em>Green Power Security Table</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.Node#getDiscoveryNeighbourTableSize <em>Discovery Neighbour Table Size</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.Node#getActiveNeighbourTableSize <em>Active Neighbour Table Size</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.Node#getRouteDiscoveryTableSize <em>Route Discovery Table Size</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.Node#getRoutingTableSize <em>Routing Table Size</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.Node#getBroadcastTransactionTableSize <em>Broadcast Transaction Table Size</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.Node#getRouteRecordTableSize <em>Route Record Table Size</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.Node#getAddressMapTableSize <em>Address Map Table Size</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.Node#getSecurityMaterialSets <em>Security Material Sets</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.Node#getMaxNumSimultaneousApsdeReq <em>Max Num Simultaneous Apsde Req</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.Node#getMaxNumSimultaneousApsdeAckReq <em>Max Num Simultaneous Apsde Ack Req</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.Node#getMACMutexName <em>MAC Mutex Name</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.Node#getZPSMutexName <em>ZPS Mutex Name</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.Node#getFragmentationMaxNumSimulRx <em>Fragmentation Max Num Simul Rx</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.Node#getFragmentationMaxNumSimulTx <em>Fragmentation Max Num Simul Tx</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.Node#getDefaultEventMessageName <em>Default Event Message Name</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.Node#getMACDcfmIndMessage <em>MAC Dcfm Ind Message</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.Node#getMACTimeEventMessage <em>MAC Time Event Message</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.Node#getApsNonMemberRadius <em>Aps Non Member Radius</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.Node#isApsDesignatedCoordinator <em>Aps Designated Coordinator</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.Node#isApsUseInsecureJoin <em>Aps Use Insecure Join</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.Node#getApsMaxWindowSize <em>Aps Max Window Size</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.Node#getApsInterframeDelay <em>Aps Interframe Delay</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.Node#getAPSDuplicateTableSize <em>APS Duplicate Table Size</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.Node#getApsSecurityTimeoutPeriod <em>Aps Security Timeout Period</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.Node#getApsUseExtPANId <em>Aps Use Ext PAN Id</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.Node#getInitialNetworkKey <em>Initial Network Key</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.Node#isSecurityEnabled <em>Security Enabled</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.Node#getMACMlmeDcfmIndMessage <em>MAC Mlme Dcfm Ind Message</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.Node#getMACMcpsDcfmIndMessage <em>MAC Mcps Dcfm Ind Message</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.Node#getAPSPersistenceTime <em>APS Persistence Time</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.Node#getNumAPSMESimulCommands <em>Num APSME Simul Commands</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.Node#getStackProfile <em>Stack Profile</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.Node#isInterPAN <em>Inter PAN</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.Node#isGreenPowerSupport <em>Green Power Support</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.Node#getNwkFcSaveCountBitShift <em>Nwk Fc Save Count Bit Shift</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.Node#getApsFcSaveCountBitShift <em>Aps Fc Save Count Bit Shift</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.Node#getMacTableSize <em>Mac Table Size</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.Node#getDefaultCallbackName <em>Default Callback Name</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.Node#getMacInterfaceList <em>Mac Interface List</em>}</li>
 * </ul>
 * </p>
 *
 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getNode()
 * @model abstract="true"
 * @generated
 */
public interface Node extends NamedObject {
	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	String copyright = "(C) NXP B.V";

	/**
	 * Returns the value of the '<em><b>Endpoints</b></em>' containment reference list.
	 * The list contents are of type {@link com.jennic.ZPSConfiguration.EndPoint}.
	 * It is bidirectional and its opposite is '{@link com.jennic.ZPSConfiguration.EndPoint#getNode <em>Node</em>}'.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Endpoints</em>' containment reference list isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Endpoints</em>' containment reference list.
	 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getNode_Endpoints()
	 * @see com.jennic.ZPSConfiguration.EndPoint#getNode
	 * @model opposite="Node" containment="true" required="true" upper="255"
	 * @generated
	 */
	EList<EndPoint> getEndpoints();

	/**
	 * Returns the value of the '<em><b>Binding Table</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Binding Table</em>' containment reference isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Binding Table</em>' containment reference.
	 * @see #setBindingTable(BindingTable)
	 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getNode_BindingTable()
	 * @model containment="true"
	 * @generated
	 */
	BindingTable getBindingTable();

	/**
	 * Sets the value of the '{@link com.jennic.ZPSConfiguration.Node#getBindingTable <em>Binding Table</em>}' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>Binding Table</em>' containment reference.
	 * @see #getBindingTable()
	 * @generated
	 */
	void setBindingTable(BindingTable value);

	/**
	 * Returns the value of the '<em><b>User Descriptor</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>User Descriptor</em>' containment reference isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>User Descriptor</em>' containment reference.
	 * @see #setUserDescriptor(UserDescriptor)
	 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getNode_UserDescriptor()
	 * @model containment="true"
	 * @generated
	 */
	UserDescriptor getUserDescriptor();

	/**
	 * Sets the value of the '{@link com.jennic.ZPSConfiguration.Node#getUserDescriptor <em>User Descriptor</em>}' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>User Descriptor</em>' containment reference.
	 * @see #getUserDescriptor()
	 * @generated
	 */
	void setUserDescriptor(UserDescriptor value);

	/**
	 * Returns the value of the '<em><b>PDU Configuration</b></em>' containment reference.
	 * It is bidirectional and its opposite is '{@link com.jennic.ZPSConfiguration.PDUManager#getContainerNode <em>Container Node</em>}'.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>PDU Configuration</em>' containment reference isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>PDU Configuration</em>' containment reference.
	 * @see #setPDUConfiguration(PDUManager)
	 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getNode_PDUConfiguration()
	 * @see com.jennic.ZPSConfiguration.PDUManager#getContainerNode
	 * @model opposite="ContainerNode" containment="true" required="true"
	 * @generated
	 */
	PDUManager getPDUConfiguration();

	/**
	 * Sets the value of the '{@link com.jennic.ZPSConfiguration.Node#getPDUConfiguration <em>PDU Configuration</em>}' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>PDU Configuration</em>' containment reference.
	 * @see #getPDUConfiguration()
	 * @generated
	 */
	void setPDUConfiguration(PDUManager value);

	/**
	 * Returns the value of the '<em><b>Group Table</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Group Table</em>' containment reference isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Group Table</em>' containment reference.
	 * @see #setGroupTable(GroupTable)
	 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getNode_GroupTable()
	 * @model containment="true"
	 * @generated
	 */
	GroupTable getGroupTable();

	/**
	 * Sets the value of the '{@link com.jennic.ZPSConfiguration.Node#getGroupTable <em>Group Table</em>}' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>Group Table</em>' containment reference.
	 * @see #getGroupTable()
	 * @generated
	 */
	void setGroupTable(GroupTable value);

	/**
	 * Returns the value of the '<em><b>Max Num Simultaneous Apsde Ack Req</b></em>' attribute.
	 * The default value is <code>"3"</code>.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Max Num Simultaneous Apsde Ack Req</em>' attribute isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Max Num Simultaneous Apsde Ack Req</em>' attribute.
	 * @see #setMaxNumSimultaneousApsdeAckReq(BigInteger)
	 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getNode_MaxNumSimultaneousApsdeAckReq()
	 * @model default="3" required="true"
	 *        annotation="http://jennic.com/hexdec min='1' max='255'"
	 * @generated
	 */
	BigInteger getMaxNumSimultaneousApsdeAckReq();

	/**
	 * Sets the value of the '{@link com.jennic.ZPSConfiguration.Node#getMaxNumSimultaneousApsdeAckReq <em>Max Num Simultaneous Apsde Ack Req</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>Max Num Simultaneous Apsde Ack Req</em>' attribute.
	 * @see #getMaxNumSimultaneousApsdeAckReq()
	 * @generated
	 */
	void setMaxNumSimultaneousApsdeAckReq(BigInteger value);

	/**
	 * Returns the value of the '<em><b>Channel Mask</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Channel Mask</em>' containment reference isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Channel Mask</em>' containment reference.
	 * @see #setChannelMask(ChannelMask)
	 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getNode_ChannelMask()
	 * @model containment="true" required="true"
	 * @generated
	 */
	ChannelMask getChannelMask();

	/**
	 * Sets the value of the '{@link com.jennic.ZPSConfiguration.Node#getChannelMask <em>Channel Mask</em>}' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>Channel Mask</em>' containment reference.
	 * @see #getChannelMask()
	 * @generated
	 */
	void setChannelMask(ChannelMask value);

	/**
	 * Returns the value of the '<em><b>Discovery Neighbour Table Size</b></em>' attribute.
	 * The default value is <code>"16"</code>.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Discovery Neighbour Table Size</em>' attribute isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Discovery Neighbour Table Size</em>' attribute.
	 * @see #setDiscoveryNeighbourTableSize(BigInteger)
	 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getNode_DiscoveryNeighbourTableSize()
	 * @model default="16" required="true"
	 *        annotation="http://jennic.com/hexdec min='1' max='255'"
	 * @generated
	 */
	BigInteger getDiscoveryNeighbourTableSize();

	/**
	 * Sets the value of the '{@link com.jennic.ZPSConfiguration.Node#getDiscoveryNeighbourTableSize <em>Discovery Neighbour Table Size</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>Discovery Neighbour Table Size</em>' attribute.
	 * @see #getDiscoveryNeighbourTableSize()
	 * @generated
	 */
	void setDiscoveryNeighbourTableSize(BigInteger value);

	/**
	 * Returns the value of the '<em><b>Active Neighbour Table Size</b></em>' attribute.
	 * The default value is <code>"26"</code>.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Active Neighbour Table Size</em>' attribute isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Active Neighbour Table Size</em>' attribute.
	 * @see #setActiveNeighbourTableSize(BigInteger)
	 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getNode_ActiveNeighbourTableSize()
	 * @model default="26" required="true"
	 *        annotation="http://jennic.com/hexdec min='1' max='255'"
	 * @generated
	 */
	BigInteger getActiveNeighbourTableSize();

	/**
	 * Sets the value of the '{@link com.jennic.ZPSConfiguration.Node#getActiveNeighbourTableSize <em>Active Neighbour Table Size</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>Active Neighbour Table Size</em>' attribute.
	 * @see #getActiveNeighbourTableSize()
	 * @generated
	 */
	void setActiveNeighbourTableSize(BigInteger value);

	/**
	 * Returns the value of the '<em><b>Route Discovery Table Size</b></em>' attribute.
	 * The default value is <code>"2"</code>.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Route Discovery Table Size</em>' attribute isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Route Discovery Table Size</em>' attribute.
	 * @see #setRouteDiscoveryTableSize(BigInteger)
	 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getNode_RouteDiscoveryTableSize()
	 * @model default="2" required="true"
	 *        annotation="http://jennic.com/hexdec min='1' max='255'"
	 * @generated
	 */
	BigInteger getRouteDiscoveryTableSize();

	/**
	 * Sets the value of the '{@link com.jennic.ZPSConfiguration.Node#getRouteDiscoveryTableSize <em>Route Discovery Table Size</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>Route Discovery Table Size</em>' attribute.
	 * @see #getRouteDiscoveryTableSize()
	 * @generated
	 */
	void setRouteDiscoveryTableSize(BigInteger value);

	/**
	 * Returns the value of the '<em><b>Routing Table Size</b></em>' attribute.
	 * The default value is <code>"255"</code>.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Routing Table Size</em>' attribute isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Routing Table Size</em>' attribute.
	 * @see #setRoutingTableSize(BigInteger)
	 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getNode_RoutingTableSize()
	 * @model default="255" required="true"
	 *        annotation="http://jennic.com/hexdec min='1' max='65535'"
	 * @generated
	 */
	BigInteger getRoutingTableSize();

	/**
	 * Sets the value of the '{@link com.jennic.ZPSConfiguration.Node#getRoutingTableSize <em>Routing Table Size</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>Routing Table Size</em>' attribute.
	 * @see #getRoutingTableSize()
	 * @generated
	 */
	void setRoutingTableSize(BigInteger value);

	/**
	 * Returns the value of the '<em><b>Broadcast Transaction Table Size</b></em>' attribute.
	 * The default value is <code>"9"</code>.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Broadcast Transaction Table Size</em>' attribute isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Broadcast Transaction Table Size</em>' attribute.
	 * @see #setBroadcastTransactionTableSize(BigInteger)
	 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getNode_BroadcastTransactionTableSize()
	 * @model default="9" required="true"
	 *        annotation="http://jennic.com/hexdec min='1' max='255'"
	 * @generated
	 */
	BigInteger getBroadcastTransactionTableSize();

	/**
	 * Sets the value of the '{@link com.jennic.ZPSConfiguration.Node#getBroadcastTransactionTableSize <em>Broadcast Transaction Table Size</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>Broadcast Transaction Table Size</em>' attribute.
	 * @see #getBroadcastTransactionTableSize()
	 * @generated
	 */
	void setBroadcastTransactionTableSize(BigInteger value);

	/**
	 * Returns the value of the '<em><b>Route Record Table Size</b></em>' attribute.
	 * The default value is <code>"2"</code>.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Route Record Table Size</em>' attribute isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Route Record Table Size</em>' attribute.
	 * @see #setRouteRecordTableSize(BigInteger)
	 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getNode_RouteRecordTableSize()
	 * @model default="2" required="true"
	 *        annotation="http://jennic.com/hexdec min='1' max='255'"
	 * @generated
	 */
	BigInteger getRouteRecordTableSize();

	/**
	 * Sets the value of the '{@link com.jennic.ZPSConfiguration.Node#getRouteRecordTableSize <em>Route Record Table Size</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>Route Record Table Size</em>' attribute.
	 * @see #getRouteRecordTableSize()
	 * @generated
	 */
	void setRouteRecordTableSize(BigInteger value);

	/**
	 * Returns the value of the '<em><b>Address Map Table Size</b></em>' attribute.
	 * The default value is <code>"10"</code>.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Address Map Table Size</em>' attribute isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Address Map Table Size</em>' attribute.
	 * @see #setAddressMapTableSize(BigInteger)
	 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getNode_AddressMapTableSize()
	 * @model default="10" required="true"
	 *        annotation="http://jennic.com/hexdec min='1' max='255'"
	 * @generated
	 */
	BigInteger getAddressMapTableSize();

	/**
	 * Sets the value of the '{@link com.jennic.ZPSConfiguration.Node#getAddressMapTableSize <em>Address Map Table Size</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>Address Map Table Size</em>' attribute.
	 * @see #getAddressMapTableSize()
	 * @generated
	 */
	void setAddressMapTableSize(BigInteger value);

	/**
	 * Returns the value of the '<em><b>Security Material Sets</b></em>' attribute.
	 * The default value is <code>"2"</code>.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Security Material Sets</em>' attribute isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Security Material Sets</em>' attribute.
	 * @see #setSecurityMaterialSets(BigInteger)
	 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getNode_SecurityMaterialSets()
	 * @model default="2" required="true"
	 *        annotation="http://jennic.com/hexdec min='1' max='255'"
	 * @generated
	 */
	BigInteger getSecurityMaterialSets();

	/**
	 * Sets the value of the '{@link com.jennic.ZPSConfiguration.Node#getSecurityMaterialSets <em>Security Material Sets</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>Security Material Sets</em>' attribute.
	 * @see #getSecurityMaterialSets()
	 * @generated
	 */
	void setSecurityMaterialSets(BigInteger value);

	/**
	 * Returns the value of the '<em><b>Node Descriptor</b></em>' containment reference.
	 * It is bidirectional and its opposite is '{@link com.jennic.ZPSConfiguration.NodeDescriptor#getNode <em>Node</em>}'.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Node Descriptor</em>' containment reference isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Node Descriptor</em>' containment reference.
	 * @see #setNodeDescriptor(NodeDescriptor)
	 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getNode_NodeDescriptor()
	 * @see com.jennic.ZPSConfiguration.NodeDescriptor#getNode
	 * @model opposite="Node" containment="true" required="true"
	 * @generated
	 */
	NodeDescriptor getNodeDescriptor();

	/**
	 * Sets the value of the '{@link com.jennic.ZPSConfiguration.Node#getNodeDescriptor <em>Node Descriptor</em>}' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>Node Descriptor</em>' containment reference.
	 * @see #getNodeDescriptor()
	 * @generated
	 */
	void setNodeDescriptor(NodeDescriptor value);

	/**
	 * Returns the value of the '<em><b>Node Power Descriptor</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Node Power Descriptor</em>' containment reference isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Node Power Descriptor</em>' containment reference.
	 * @see #setNodePowerDescriptor(NodePowerDescriptor)
	 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getNode_NodePowerDescriptor()
	 * @model containment="true" required="true" derived="true"
	 * @generated
	 */
	NodePowerDescriptor getNodePowerDescriptor();

	/**
	 * Sets the value of the '{@link com.jennic.ZPSConfiguration.Node#getNodePowerDescriptor <em>Node Power Descriptor</em>}' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>Node Power Descriptor</em>' containment reference.
	 * @see #getNodePowerDescriptor()
	 * @generated
	 */
	void setNodePowerDescriptor(NodePowerDescriptor value);

	/**
	 * Returns the value of the '<em><b>Max Num Simultaneous Apsde Req</b></em>' attribute.
	 * The default value is <code>"5"</code>.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Max Num Simultaneous Apsde Req</em>' attribute isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Max Num Simultaneous Apsde Req</em>' attribute.
	 * @see #setMaxNumSimultaneousApsdeReq(int)
	 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getNode_MaxNumSimultaneousApsdeReq()
	 * @model default="5" required="true"
	 *        annotation="http://jennic.com/hexdec min='1' max='255'"
	 * @generated
	 */
	int getMaxNumSimultaneousApsdeReq();

	/**
	 * Sets the value of the '{@link com.jennic.ZPSConfiguration.Node#getMaxNumSimultaneousApsdeReq <em>Max Num Simultaneous Apsde Req</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>Max Num Simultaneous Apsde Req</em>' attribute.
	 * @see #getMaxNumSimultaneousApsdeReq()
	 * @generated
	 */
	void setMaxNumSimultaneousApsdeReq(int value);

	/**
	 * Returns the value of the '<em><b>MAC Mutex Name</b></em>' attribute.
	 * The default value is <code>"mutexMAC"</code>.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>MAC Mutex Name</em>' attribute isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>MAC Mutex Name</em>' attribute.
	 * @see #setMACMutexName(String)
	 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getNode_MACMutexName()
	 * @model default="mutexMAC" required="true"
	 *        extendedMetaData="namespace='zpscfg' name='MACMutexName' kind='attribute'"
	 * @generated
	 */
	String getMACMutexName();

	/**
	 * Sets the value of the '{@link com.jennic.ZPSConfiguration.Node#getMACMutexName <em>MAC Mutex Name</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>MAC Mutex Name</em>' attribute.
	 * @see #getMACMutexName()
	 * @generated
	 */
	void setMACMutexName(String value);

	/**
	 * Returns the value of the '<em><b>ZPS Mutex Name</b></em>' attribute.
	 * The default value is <code>"mutexZPS"</code>.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>ZPS Mutex Name</em>' attribute isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>ZPS Mutex Name</em>' attribute.
	 * @see #setZPSMutexName(String)
	 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getNode_ZPSMutexName()
	 * @model default="mutexZPS" required="true"
	 *        extendedMetaData="namespace='##targetNamespace' kind='attribute'"
	 * @generated
	 */
	String getZPSMutexName();

	/**
	 * Sets the value of the '{@link com.jennic.ZPSConfiguration.Node#getZPSMutexName <em>ZPS Mutex Name</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>ZPS Mutex Name</em>' attribute.
	 * @see #getZPSMutexName()
	 * @generated
	 */
	void setZPSMutexName(String value);

	/**
	 * Returns the value of the '<em><b>Fragmentation Max Num Simul Rx</b></em>' attribute.
	 * The default value is <code>"0"</code>.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Fragmentation Max Num Simul Rx</em>' attribute isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Fragmentation Max Num Simul Rx</em>' attribute.
	 * @see #setFragmentationMaxNumSimulRx(int)
	 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getNode_FragmentationMaxNumSimulRx()
	 * @model default="0" required="true"
	 *        extendedMetaData="namespace='##targetNamespace' kind='attribute'"
	 *        annotation="http://jennic.com/hexdec min='0' max='255'"
	 * @generated
	 */
	int getFragmentationMaxNumSimulRx();

	/**
	 * Sets the value of the '{@link com.jennic.ZPSConfiguration.Node#getFragmentationMaxNumSimulRx <em>Fragmentation Max Num Simul Rx</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>Fragmentation Max Num Simul Rx</em>' attribute.
	 * @see #getFragmentationMaxNumSimulRx()
	 * @generated
	 */
	void setFragmentationMaxNumSimulRx(int value);

	/**
	 * Returns the value of the '<em><b>Fragmentation Max Num Simul Tx</b></em>' attribute.
	 * The default value is <code>"0"</code>.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Fragmentation Max Num Simul Tx</em>' attribute isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Fragmentation Max Num Simul Tx</em>' attribute.
	 * @see #setFragmentationMaxNumSimulTx(int)
	 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getNode_FragmentationMaxNumSimulTx()
	 * @model default="0" required="true"
	 *        extendedMetaData="namespace='##targetNamespace' kind='attribute'"
	 *        annotation="http://jennic.com/hexdec min='0' max='255'"
	 * @generated
	 */
	int getFragmentationMaxNumSimulTx();

	/**
	 * Sets the value of the '{@link com.jennic.ZPSConfiguration.Node#getFragmentationMaxNumSimulTx <em>Fragmentation Max Num Simul Tx</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>Fragmentation Max Num Simul Tx</em>' attribute.
	 * @see #getFragmentationMaxNumSimulTx()
	 * @generated
	 */
	void setFragmentationMaxNumSimulTx(int value);

	/**
	 * Returns the value of the '<em><b>Default Event Message Name</b></em>' attribute.
	 * The default value is <code>"APP_msgZpsEvents"</code>.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Default Event Message Name</em>' attribute isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Default Event Message Name</em>' attribute.
	 * @see #setDefaultEventMessageName(String)
	 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getNode_DefaultEventMessageName()
	 * @model default="APP_msgZpsEvents" required="true"
	 *        extendedMetaData="namespace='##targetNamespace' kind='attribute'"
	 * @generated
	 */
	String getDefaultEventMessageName();

	/**
	 * Sets the value of the '{@link com.jennic.ZPSConfiguration.Node#getDefaultEventMessageName <em>Default Event Message Name</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>Default Event Message Name</em>' attribute.
	 * @see #getDefaultEventMessageName()
	 * @generated
	 */
	void setDefaultEventMessageName(String value);

	/**
	 * Returns the value of the '<em><b>MAC Dcfm Ind Message</b></em>' attribute.
	 * The default value is <code>"zps_msgDcfmInd"</code>.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>MAC Dcfm Ind Message</em>' attribute isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>MAC Dcfm Ind Message</em>' attribute.
	 * @see #setMACDcfmIndMessage(String)
	 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getNode_MACDcfmIndMessage()
	 * @model default="zps_msgDcfmInd" required="true"
	 *        extendedMetaData="namespace='##targetNamespace' kind='attribute'"
	 * @generated
	 */
	String getMACDcfmIndMessage();

	/**
	 * Sets the value of the '{@link com.jennic.ZPSConfiguration.Node#getMACDcfmIndMessage <em>MAC Dcfm Ind Message</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>MAC Dcfm Ind Message</em>' attribute.
	 * @see #getMACDcfmIndMessage()
	 * @generated
	 */
	void setMACDcfmIndMessage(String value);

	/**
	 * Returns the value of the '<em><b>MAC Time Event Message</b></em>' attribute.
	 * The default value is <code>"zps_msgTimeEvents"</code>.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>MAC Time Event Message</em>' attribute isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>MAC Time Event Message</em>' attribute.
	 * @see #setMACTimeEventMessage(String)
	 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getNode_MACTimeEventMessage()
	 * @model default="zps_msgTimeEvents" required="true"
	 *        extendedMetaData="namespace='##targetNamespace' kind='attribute'"
	 * @generated
	 */
	String getMACTimeEventMessage();

	/**
	 * Sets the value of the '{@link com.jennic.ZPSConfiguration.Node#getMACTimeEventMessage <em>MAC Time Event Message</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>MAC Time Event Message</em>' attribute.
	 * @see #getMACTimeEventMessage()
	 * @generated
	 */
	void setMACTimeEventMessage(String value);

	/**
	 * Returns the value of the '<em><b>Aps Non Member Radius</b></em>' attribute.
	 * The default value is <code>"2"</code>.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Aps Non Member Radius</em>' attribute isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Aps Non Member Radius</em>' attribute.
	 * @see #setApsNonMemberRadius(int)
	 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getNode_ApsNonMemberRadius()
	 * @model default="2" required="true"
	 *        annotation="http:///com/jennic/zpsconfig propertyClass='Jennic,Standard,Advanced'"
	 *        annotation="http://jennic.com/hexdec min='0' max='7'"
	 * @generated
	 */
	int getApsNonMemberRadius();

	/**
	 * Sets the value of the '{@link com.jennic.ZPSConfiguration.Node#getApsNonMemberRadius <em>Aps Non Member Radius</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>Aps Non Member Radius</em>' attribute.
	 * @see #getApsNonMemberRadius()
	 * @generated
	 */
	void setApsNonMemberRadius(int value);

	/**
	 * Returns the value of the '<em><b>Aps Designated Coordinator</b></em>' attribute.
	 * The default value is <code>"false"</code>.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Aps Designated Coordinator</em>' attribute isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Aps Designated Coordinator</em>' attribute.
	 * @see #setApsDesignatedCoordinator(boolean)
	 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getNode_ApsDesignatedCoordinator()
	 * @model default="false" required="true" derived="true"
	 *        extendedMetaData="namespace=''"
	 * @generated
	 */
	boolean isApsDesignatedCoordinator();

	/**
	 * Sets the value of the '{@link com.jennic.ZPSConfiguration.Node#isApsDesignatedCoordinator <em>Aps Designated Coordinator</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>Aps Designated Coordinator</em>' attribute.
	 * @see #isApsDesignatedCoordinator()
	 * @generated
	 */
	void setApsDesignatedCoordinator(boolean value);

	/**
	 * Returns the value of the '<em><b>Aps Use Insecure Join</b></em>' attribute.
	 * The default value is <code>"true"</code>.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Aps Use Insecure Join</em>' attribute isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Aps Use Insecure Join</em>' attribute.
	 * @see #setApsUseInsecureJoin(boolean)
	 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getNode_ApsUseInsecureJoin()
	 * @model default="true" required="true"
	 * @generated
	 */
	boolean isApsUseInsecureJoin();

	/**
	 * Sets the value of the '{@link com.jennic.ZPSConfiguration.Node#isApsUseInsecureJoin <em>Aps Use Insecure Join</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>Aps Use Insecure Join</em>' attribute.
	 * @see #isApsUseInsecureJoin()
	 * @generated
	 */
	void setApsUseInsecureJoin(boolean value);

	/**
	 * Returns the value of the '<em><b>Aps Max Window Size</b></em>' attribute.
	 * The default value is <code>"8"</code>.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Aps Max Window Size</em>' attribute isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Aps Max Window Size</em>' attribute.
	 * @see #setApsMaxWindowSize(int)
	 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getNode_ApsMaxWindowSize()
	 * @model default="8" required="true"
	 *        extendedMetaData="namespace=''"
	 *        annotation="http://jennic.com/hexdec min='1' max='8'"
	 * @generated
	 */
	int getApsMaxWindowSize();

	/**
	 * Sets the value of the '{@link com.jennic.ZPSConfiguration.Node#getApsMaxWindowSize <em>Aps Max Window Size</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>Aps Max Window Size</em>' attribute.
	 * @see #getApsMaxWindowSize()
	 * @generated
	 */
	void setApsMaxWindowSize(int value);

	/**
	 * Returns the value of the '<em><b>Aps Interframe Delay</b></em>' attribute.
	 * The default value is <code>"10"</code>.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Aps Interframe Delay</em>' attribute isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Aps Interframe Delay</em>' attribute.
	 * @see #setApsInterframeDelay(int)
	 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getNode_ApsInterframeDelay()
	 * @model default="10" required="true"
	 *        annotation="http://jennic.com/hexdec min='10' max='255'"
	 * @generated
	 */
	int getApsInterframeDelay();

	/**
	 * Sets the value of the '{@link com.jennic.ZPSConfiguration.Node#getApsInterframeDelay <em>Aps Interframe Delay</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>Aps Interframe Delay</em>' attribute.
	 * @see #getApsInterframeDelay()
	 * @generated
	 */
	void setApsInterframeDelay(int value);

	/**
	 * Returns the value of the '<em><b>Aps Security Timeout Period</b></em>' attribute.
	 * The default value is <code>"1000"</code>.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Aps Security Timeout Period</em>' attribute isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Aps Security Timeout Period</em>' attribute.
	 * @see #setApsSecurityTimeoutPeriod(BigInteger)
	 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getNode_ApsSecurityTimeoutPeriod()
	 * @model default="1000" required="true"
	 *        extendedMetaData="kind='attribute'"
	 *        annotation="http://jennic.com/hexdec min='1000' max='4294967295'"
	 * @generated
	 */
	BigInteger getApsSecurityTimeoutPeriod();

	/**
	 * Sets the value of the '{@link com.jennic.ZPSConfiguration.Node#getApsSecurityTimeoutPeriod <em>Aps Security Timeout Period</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>Aps Security Timeout Period</em>' attribute.
	 * @see #getApsSecurityTimeoutPeriod()
	 * @generated
	 */
	void setApsSecurityTimeoutPeriod(BigInteger value);

	/**
	 * Returns the value of the '<em><b>Key Descriptor Table</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Key Descriptor Table</em>' containment reference isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Key Descriptor Table</em>' containment reference.
	 * @see #setKeyDescriptorTable(KeyDescriptorTable)
	 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getNode_KeyDescriptorTable()
	 * @model containment="true"
	 * @generated
	 */
	KeyDescriptorTable getKeyDescriptorTable();

	/**
	 * Sets the value of the '{@link com.jennic.ZPSConfiguration.Node#getKeyDescriptorTable <em>Key Descriptor Table</em>}' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>Key Descriptor Table</em>' containment reference.
	 * @see #getKeyDescriptorTable()
	 * @generated
	 */
	void setKeyDescriptorTable(KeyDescriptorTable value);

	/**
	 * Returns the value of the '<em><b>Aps Use Ext PAN Id</b></em>' attribute.
	 * The default value is <code>"0"</code>.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Aps Use Ext PAN Id</em>' attribute isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Aps Use Ext PAN Id</em>' attribute.
	 * @see #setApsUseExtPANId(BigInteger)
	 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getNode_ApsUseExtPANId()
	 * @model default="0" dataType="com.jennic.ZPSConfiguration.EExtPANId" required="true"
	 *        annotation="http://jennic.com/hexdec min='0' max='18446744073709551615' hex='' hex_width='16'"
	 * @generated
	 */
	Object getApsUseExtPANId();

	/**
	 * Sets the value of the '{@link com.jennic.ZPSConfiguration.Node#getApsUseExtPANId <em>Aps Use Ext PAN Id</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>Aps Use Ext PAN Id</em>' attribute.
	 * @see #getApsUseExtPANId()
	 * @generated
	 */
	void setApsUseExtPANId(Object value);

	/**
	 * Returns the value of the '<em><b>Initial Network Key</b></em>' reference.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Initial Network Key</em>' reference isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Initial Network Key</em>' reference.
	 * @see #setInitialNetworkKey(TCKey)
	 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getNode_InitialNetworkKey()
	 * @model
	 * @generated
	 */
	TCKey getInitialNetworkKey();

	/**
	 * Sets the value of the '{@link com.jennic.ZPSConfiguration.Node#getInitialNetworkKey <em>Initial Network Key</em>}' reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>Initial Network Key</em>' reference.
	 * @see #getInitialNetworkKey()
	 * @generated
	 */
	void setInitialNetworkKey(TCKey value);

	/**
	 * Returns the value of the '<em><b>Security Enabled</b></em>' attribute.
	 * The default value is <code>"true"</code>.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Security Enabled</em>' attribute isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Security Enabled</em>' attribute.
	 * @see #setSecurityEnabled(boolean)
	 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getNode_SecurityEnabled()
	 * @model default="true" required="true"
	 * @generated
	 */
	boolean isSecurityEnabled();

	/**
	 * Sets the value of the '{@link com.jennic.ZPSConfiguration.Node#isSecurityEnabled <em>Security Enabled</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>Security Enabled</em>' attribute.
	 * @see #isSecurityEnabled()
	 * @generated
	 */
	void setSecurityEnabled(boolean value);

	/**
	 * Returns the value of the '<em><b>MAC Mlme Dcfm Ind Message</b></em>' attribute.
	 * The default value is <code>"zps_msgMlmeDcfmInd"</code>.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>MAC Mlme Dcfm Ind Message</em>' attribute isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>MAC Mlme Dcfm Ind Message</em>' attribute.
	 * @see #setMACMlmeDcfmIndMessage(String)
	 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getNode_MACMlmeDcfmIndMessage()
	 * @model default="zps_msgMlmeDcfmInd" required="true"
	 *        extendedMetaData="namespace='##targetNamespace' kind='attribute'"
	 * @generated
	 */
	String getMACMlmeDcfmIndMessage();

	/**
	 * Sets the value of the '{@link com.jennic.ZPSConfiguration.Node#getMACMlmeDcfmIndMessage <em>MAC Mlme Dcfm Ind Message</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>MAC Mlme Dcfm Ind Message</em>' attribute.
	 * @see #getMACMlmeDcfmIndMessage()
	 * @generated
	 */
	void setMACMlmeDcfmIndMessage(String value);

	/**
	 * Returns the value of the '<em><b>MAC Mcps Dcfm Ind Message</b></em>' attribute.
	 * The default value is <code>"zps_msgMcpsDcfmInd"</code>.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>MAC Mcps Dcfm Ind Message</em>' attribute isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>MAC Mcps Dcfm Ind Message</em>' attribute.
	 * @see #setMACMcpsDcfmIndMessage(String)
	 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getNode_MACMcpsDcfmIndMessage()
	 * @model default="zps_msgMcpsDcfmInd" required="true"
	 *        extendedMetaData="namespace='##targetNamespace' kind='attribute'"
	 * @generated
	 */
	String getMACMcpsDcfmIndMessage();

	/**
	 * Sets the value of the '{@link com.jennic.ZPSConfiguration.Node#getMACMcpsDcfmIndMessage <em>MAC Mcps Dcfm Ind Message</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>MAC Mcps Dcfm Ind Message</em>' attribute.
	 * @see #getMACMcpsDcfmIndMessage()
	 * @generated
	 */
	void setMACMcpsDcfmIndMessage(String value);

	/**
	 * Returns the value of the '<em><b>APS Persistence Time</b></em>' attribute.
	 * The default value is <code>"100"</code>.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>APS Persistence Time</em>' attribute isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>APS Persistence Time</em>' attribute.
	 * @see #setAPSPersistenceTime(int)
	 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getNode_APSPersistenceTime()
	 * @model default="100" required="true"
	 *        annotation="http://jennic.com/hexdec min='25' max='255'"
	 * @generated
	 */
	int getAPSPersistenceTime();

	/**
	 * Sets the value of the '{@link com.jennic.ZPSConfiguration.Node#getAPSPersistenceTime <em>APS Persistence Time</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>APS Persistence Time</em>' attribute.
	 * @see #getAPSPersistenceTime()
	 * @generated
	 */
	void setAPSPersistenceTime(int value);

	/**
	 * Returns the value of the '<em><b>Num APSME Simul Commands</b></em>' attribute.
	 * The default value is <code>"4"</code>.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Num APSME Simul Commands</em>' attribute isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Num APSME Simul Commands</em>' attribute.
	 * @see #setNumAPSMESimulCommands(int)
	 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getNode_NumAPSMESimulCommands()
	 * @model default="4" required="true"
	 *        annotation="http://jennic.com/hexdec min='1' max='65535'"
	 * @generated
	 */
	int getNumAPSMESimulCommands();

	/**
	 * Sets the value of the '{@link com.jennic.ZPSConfiguration.Node#getNumAPSMESimulCommands <em>Num APSME Simul Commands</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>Num APSME Simul Commands</em>' attribute.
	 * @see #getNumAPSMESimulCommands()
	 * @generated
	 */
	void setNumAPSMESimulCommands(int value);

	/**
	 * Returns the value of the '<em><b>Stack Profile</b></em>' attribute.
	 * The default value is <code>"2"</code>.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Stack Profile</em>' attribute isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Stack Profile</em>' attribute.
	 * @see #setStackProfile(int)
	 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getNode_StackProfile()
	 * @model default="2" required="true"
	 *        annotation="http://jennic.com/hexdec min='0' max='15'"
	 * @generated
	 */
	int getStackProfile();

	/**
	 * Sets the value of the '{@link com.jennic.ZPSConfiguration.Node#getStackProfile <em>Stack Profile</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>Stack Profile</em>' attribute.
	 * @see #getStackProfile()
	 * @generated
	 */
	void setStackProfile(int value);

	/**
	 * Returns the value of the '<em><b>Inter PAN</b></em>' attribute.
	 * The default value is <code>"false"</code>.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Inter PAN</em>' attribute isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Inter PAN</em>' attribute.
	 * @see #setInterPAN(boolean)
	 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getNode_InterPAN()
	 * @model default="false" required="true"
	 * @generated
	 */
	boolean isInterPAN();

	/**
	 * Sets the value of the '{@link com.jennic.ZPSConfiguration.Node#isInterPAN <em>Inter PAN</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>Inter PAN</em>' attribute.
	 * @see #isInterPAN()
	 * @generated
	 */
	void setInterPAN(boolean value);

	/**
	 * Returns the value of the '<em><b>Green Power Support</b></em>' attribute.
	 * The default value is <code>"false"</code>.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Green Power Support</em>' attribute isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Green Power Support</em>' attribute.
	 * @see #setGreenPowerSupport(boolean)
	 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getNode_GreenPowerSupport()
	 * @model default="false" required="true"
	 * @generated
	 */
	boolean isGreenPowerSupport();

	/**
	 * Sets the value of the '{@link com.jennic.ZPSConfiguration.Node#isGreenPowerSupport <em>Green Power Support</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>Green Power Support</em>' attribute.
	 * @see #isGreenPowerSupport()
	 * @generated
	 */
	void setGreenPowerSupport(boolean value);

	/**
	 * Returns the value of the '<em><b>Nwk Fc Save Count Bit Shift</b></em>' attribute.
	 * The default value is <code>"10"</code>.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Nwk Fc Save Count Bit Shift</em>' attribute isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Nwk Fc Save Count Bit Shift</em>' attribute.
	 * @see #setNwkFcSaveCountBitShift(int)
	 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getNode_NwkFcSaveCountBitShift()
	 * @model default="10" required="true"
	 *        annotation="http://jennic.com/hexdec min='1' max='32'"
	 * @generated
	 */
	int getNwkFcSaveCountBitShift();

	/**
	 * Sets the value of the '{@link com.jennic.ZPSConfiguration.Node#getNwkFcSaveCountBitShift <em>Nwk Fc Save Count Bit Shift</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>Nwk Fc Save Count Bit Shift</em>' attribute.
	 * @see #getNwkFcSaveCountBitShift()
	 * @generated
	 */
	void setNwkFcSaveCountBitShift(int value);

	/**
	 * Returns the value of the '<em><b>Aps Fc Save Count Bit Shift</b></em>' attribute.
	 * The default value is <code>"10"</code>.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Aps Fc Save Count Bit Shift</em>' attribute isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Aps Fc Save Count Bit Shift</em>' attribute.
	 * @see #setApsFcSaveCountBitShift(int)
	 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getNode_ApsFcSaveCountBitShift()
	 * @model default="10" required="true"
	 *        annotation="http://jennic.com/hexdec min='1' max='32'"
	 * @generated
	 */
	int getApsFcSaveCountBitShift();

	/**
	 * Sets the value of the '{@link com.jennic.ZPSConfiguration.Node#getApsFcSaveCountBitShift <em>Aps Fc Save Count Bit Shift</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>Aps Fc Save Count Bit Shift</em>' attribute.
	 * @see #getApsFcSaveCountBitShift()
	 * @generated
	 */
	void setApsFcSaveCountBitShift(int value);

	/**
	 * Returns the value of the '<em><b>Mac Table Size</b></em>' attribute.
	 * The default value is <code>"36"</code>.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Mac Table Size</em>' attribute isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Mac Table Size</em>' attribute.
	 * @see #setMacTableSize(BigInteger)
	 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getNode_MacTableSize()
	 * @model default="36" required="true"
	 * @generated
	 */
	BigInteger getMacTableSize();

	/**
	 * Sets the value of the '{@link com.jennic.ZPSConfiguration.Node#getMacTableSize <em>Mac Table Size</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>Mac Table Size</em>' attribute.
	 * @see #getMacTableSize()
	 * @generated
	 */
	void setMacTableSize(BigInteger value);

	/**
	 * Returns the value of the '<em><b>Default Callback Name</b></em>' attribute.
	 * The default value is <code>"APP_vGenCallback"</code>.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Default Callback Name</em>' attribute isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Default Callback Name</em>' attribute.
	 * @see #setDefaultCallbackName(String)
	 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getNode_DefaultCallbackName()
	 * @model default="APP_vGenCallback" required="true"
	 * @generated
	 */
	String getDefaultCallbackName();

	/**
	 * Sets the value of the '{@link com.jennic.ZPSConfiguration.Node#getDefaultCallbackName <em>Default Callback Name</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>Default Callback Name</em>' attribute.
	 * @see #getDefaultCallbackName()
	 * @generated
	 */
	void setDefaultCallbackName(String value);

	/**
	 * Returns the value of the '<em><b>Mac Interface List</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Mac Interface List</em>' reference isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Mac Interface List</em>' containment reference.
	 * @see #setMacInterfaceList(MacInterfaceList)
	 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getNode_MacInterfaceList()
	 * @model containment="true"
	 * @generated
	 */
	MacInterfaceList getMacInterfaceList();

	/**
	 * Sets the value of the '{@link com.jennic.ZPSConfiguration.Node#getMacInterfaceList <em>Mac Interface List</em>}' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>Mac Interface List</em>' containment reference.
	 * @see #getMacInterfaceList()
	 * @generated
	 */
	void setMacInterfaceList(MacInterfaceList value);

	/**
	 * Returns the value of the '<em><b>Green Power Tx Queue</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Green Power Tx Queue</em>' containment reference isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Green Power Tx Queue</em>' containment reference.
	 * @see #setGreenPowerTxQueue(GreenPowerTxQueue)
	 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getNode_GreenPowerTxQueue()
	 * @model containment="true"
	 * @generated
	 */
	GreenPowerTxQueue getGreenPowerTxQueue();

	/**
	 * Sets the value of the '{@link com.jennic.ZPSConfiguration.Node#getGreenPowerTxQueue <em>Green Power Tx Queue</em>}' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>Green Power Tx Queue</em>' containment reference.
	 * @see #getGreenPowerTxQueue()
	 * @generated
	 */
	void setGreenPowerTxQueue(GreenPowerTxQueue value);

	/**
	 * Returns the value of the '<em><b>Green Power Security Table</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Green Power Security Table</em>' containment reference isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Green Power Security Table</em>' containment reference.
	 * @see #setGreenPowerSecurityTable(GreenPowerSecurityTable)
	 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getNode_GreenPowerSecurityTable()
	 * @model containment="true"
	 * @generated
	 */
	GreenPowerSecurityTable getGreenPowerSecurityTable();

	/**
	 * Sets the value of the '{@link com.jennic.ZPSConfiguration.Node#getGreenPowerSecurityTable <em>Green Power Security Table</em>}' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>Green Power Security Table</em>' containment reference.
	 * @see #getGreenPowerSecurityTable()
	 * @generated
	 */
	void setGreenPowerSecurityTable(GreenPowerSecurityTable value);

	/**
	 * Returns the value of the '<em><b>APS Duplicate Table Size</b></em>' attribute.
	 * The default value is <code>"8"</code>.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>APS Duplicate Table Size</em>' attribute isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>APS Duplicate Table Size</em>' attribute.
	 * @see #setAPSDuplicateTableSize(int)
	 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getNode_APSDuplicateTableSize()
	 * @model default="8" required="true"
	 *        annotation="http://jennic.com/hexdec min='1' max='255'"
	 * @generated
	 */
	int getAPSDuplicateTableSize();

	/**
	 * Sets the value of the '{@link com.jennic.ZPSConfiguration.Node#getAPSDuplicateTableSize <em>APS Duplicate Table Size</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>APS Duplicate Table Size</em>' attribute.
	 * @see #getAPSDuplicateTableSize()
	 * @generated
	 */
	void setAPSDuplicateTableSize(int value);

} // Node
