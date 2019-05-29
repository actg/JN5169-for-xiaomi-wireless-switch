/**
 * (C) Jennic Ltd
 *
 * $Id: ZDOCommonServers.java 78102 2016-03-24 15:35:29Z nxp29741 $
 */
package com.jennic.ZPSConfiguration;

import org.eclipse.emf.ecore.EObject;

/**
 * <!-- begin-user-doc -->
 * A representation of the model object '<em><b>ZDO Common Servers</b></em>'.
 * <!-- end-user-doc -->
 *
 * <p>
 * The following features are supported:
 * <ul>
 *   <li>{@link com.jennic.ZPSConfiguration.ZDOCommonServers#getDefaultServer <em>Default Server</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.ZDOCommonServers#getZdoClient <em>Zdo Client</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.ZDOCommonServers#getDeviceAnnceServer <em>Device Annce Server</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.ZDOCommonServers#getActiveEpServer <em>Active Ep Server</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.ZDOCommonServers#getNwkAddrServer <em>Nwk Addr Server</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.ZDOCommonServers#getIeeeAddrServer <em>Ieee Addr Server</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.ZDOCommonServers#getSystemServerDiscoveryServer <em>System Server Discovery Server</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.ZDOCommonServers#getNodeDescServer <em>Node Desc Server</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.ZDOCommonServers#getPowerDescServer <em>Power Desc Server</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.ZDOCommonServers#getMatchDescServer <em>Match Desc Server</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.ZDOCommonServers#getSimpleDescServer <em>Simple Desc Server</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.ZDOCommonServers#getMgmtLqiServer <em>Mgmt Lqi Server</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.ZDOCommonServers#getMgmtLeaveServer <em>Mgmt Leave Server</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.ZDOCommonServers#getMgmtNWKUpdateServer <em>Mgmt NWK Update Server</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.ZDOCommonServers#getBindUnbindServer <em>Bind Unbind Server</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.ZDOCommonServers#getExtendedActiveEpServer <em>Extended Active Ep Server</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.ZDOCommonServers#getExtendedSimpleDescServer <em>Extended Simple Desc Server</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.ZDOCommonServers#getBindRequestServer <em>Bind Request Server</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.ZDOCommonServers#getMgmtBindServer <em>Mgmt Bind Server</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.ZDOCommonServers#getMgmtNWKEnhanceUpdateServer <em>Mgmt NWK Enhance Update Server</em>}</li>
 * </ul>
 * </p>
 *
 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getZDOCommonServers()
 * @model abstract="true"
 * @generated
 */
public interface ZDOCommonServers extends EObject {
	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	String copyright = "(C) NXP B.V";

	/**
	 * Returns the value of the '<em><b>Default Server</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Default Server</em>' containment reference isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Default Server</em>' containment reference.
	 * @see #setDefaultServer(DefaultServer)
	 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getZDOCommonServers_DefaultServer()
	 * @model containment="true" required="true"
	 * @generated
	 */
	DefaultServer getDefaultServer();

	/**
	 * Sets the value of the '{@link com.jennic.ZPSConfiguration.ZDOCommonServers#getDefaultServer <em>Default Server</em>}' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>Default Server</em>' containment reference.
	 * @see #getDefaultServer()
	 * @generated
	 */
	void setDefaultServer(DefaultServer value);

	/**
	 * Returns the value of the '<em><b>Mgmt NWK Update Server</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Mgmt NWK Update Server</em>' containment reference isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Mgmt NWK Update Server</em>' containment reference.
	 * @see #setMgmtNWKUpdateServer(MgmtNWKUpdateServer)
	 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getZDOCommonServers_MgmtNWKUpdateServer()
	 * @model containment="true"
	 * @generated
	 */
	MgmtNWKUpdateServer getMgmtNWKUpdateServer();

	/**
	 * Sets the value of the '{@link com.jennic.ZPSConfiguration.ZDOCommonServers#getMgmtNWKUpdateServer <em>Mgmt NWK Update Server</em>}' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>Mgmt NWK Update Server</em>' containment reference.
	 * @see #getMgmtNWKUpdateServer()
	 * @generated
	 */
	void setMgmtNWKUpdateServer(MgmtNWKUpdateServer value);

	/**
	 * Returns the value of the '<em><b>Zdo Client</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Zdo Client</em>' containment reference isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Zdo Client</em>' containment reference.
	 * @see #setZdoClient(ZdoClient)
	 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getZDOCommonServers_ZdoClient()
	 * @model containment="true" required="true"
	 * @generated
	 */
	ZdoClient getZdoClient();

	/**
	 * Sets the value of the '{@link com.jennic.ZPSConfiguration.ZDOCommonServers#getZdoClient <em>Zdo Client</em>}' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>Zdo Client</em>' containment reference.
	 * @see #getZdoClient()
	 * @generated
	 */
	void setZdoClient(ZdoClient value);

	/**
	 * Returns the value of the '<em><b>Device Annce Server</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Device Annce Server</em>' containment reference isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Device Annce Server</em>' containment reference.
	 * @see #setDeviceAnnceServer(DeviceAnnceServer)
	 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getZDOCommonServers_DeviceAnnceServer()
	 * @model containment="true"
	 * @generated
	 */
	DeviceAnnceServer getDeviceAnnceServer();

	/**
	 * Sets the value of the '{@link com.jennic.ZPSConfiguration.ZDOCommonServers#getDeviceAnnceServer <em>Device Annce Server</em>}' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>Device Annce Server</em>' containment reference.
	 * @see #getDeviceAnnceServer()
	 * @generated
	 */
	void setDeviceAnnceServer(DeviceAnnceServer value);

	/**
	 * Returns the value of the '<em><b>Active Ep Server</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Active Ep Server</em>' containment reference isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Active Ep Server</em>' containment reference.
	 * @see #setActiveEpServer(ActiveEpServer)
	 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getZDOCommonServers_ActiveEpServer()
	 * @model containment="true"
	 * @generated
	 */
	ActiveEpServer getActiveEpServer();

	/**
	 * Sets the value of the '{@link com.jennic.ZPSConfiguration.ZDOCommonServers#getActiveEpServer <em>Active Ep Server</em>}' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>Active Ep Server</em>' containment reference.
	 * @see #getActiveEpServer()
	 * @generated
	 */
	void setActiveEpServer(ActiveEpServer value);

	/**
	 * Returns the value of the '<em><b>Nwk Addr Server</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Nwk Addr Server</em>' containment reference isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Nwk Addr Server</em>' containment reference.
	 * @see #setNwkAddrServer(NwkAddrServer)
	 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getZDOCommonServers_NwkAddrServer()
	 * @model containment="true"
	 * @generated
	 */
	NwkAddrServer getNwkAddrServer();

	/**
	 * Sets the value of the '{@link com.jennic.ZPSConfiguration.ZDOCommonServers#getNwkAddrServer <em>Nwk Addr Server</em>}' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>Nwk Addr Server</em>' containment reference.
	 * @see #getNwkAddrServer()
	 * @generated
	 */
	void setNwkAddrServer(NwkAddrServer value);

	/**
	 * Returns the value of the '<em><b>Ieee Addr Server</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Ieee Addr Server</em>' containment reference isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Ieee Addr Server</em>' containment reference.
	 * @see #setIeeeAddrServer(IeeeAddrServer)
	 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getZDOCommonServers_IeeeAddrServer()
	 * @model containment="true"
	 * @generated
	 */
	IeeeAddrServer getIeeeAddrServer();

	/**
	 * Sets the value of the '{@link com.jennic.ZPSConfiguration.ZDOCommonServers#getIeeeAddrServer <em>Ieee Addr Server</em>}' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>Ieee Addr Server</em>' containment reference.
	 * @see #getIeeeAddrServer()
	 * @generated
	 */
	void setIeeeAddrServer(IeeeAddrServer value);

	/**
	 * Returns the value of the '<em><b>System Server Discovery Server</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>System Server Discovery Server</em>' containment reference isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>System Server Discovery Server</em>' containment reference.
	 * @see #setSystemServerDiscoveryServer(SystemServerDiscoveryServer)
	 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getZDOCommonServers_SystemServerDiscoveryServer()
	 * @model containment="true"
	 * @generated
	 */
	SystemServerDiscoveryServer getSystemServerDiscoveryServer();

	/**
	 * Sets the value of the '{@link com.jennic.ZPSConfiguration.ZDOCommonServers#getSystemServerDiscoveryServer <em>System Server Discovery Server</em>}' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>System Server Discovery Server</em>' containment reference.
	 * @see #getSystemServerDiscoveryServer()
	 * @generated
	 */
	void setSystemServerDiscoveryServer(SystemServerDiscoveryServer value);

	/**
	 * Returns the value of the '<em><b>Node Desc Server</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Node Desc Server</em>' containment reference isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Node Desc Server</em>' containment reference.
	 * @see #setNodeDescServer(NodeDescServer)
	 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getZDOCommonServers_NodeDescServer()
	 * @model containment="true"
	 * @generated
	 */
	NodeDescServer getNodeDescServer();

	/**
	 * Sets the value of the '{@link com.jennic.ZPSConfiguration.ZDOCommonServers#getNodeDescServer <em>Node Desc Server</em>}' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>Node Desc Server</em>' containment reference.
	 * @see #getNodeDescServer()
	 * @generated
	 */
	void setNodeDescServer(NodeDescServer value);

	/**
	 * Returns the value of the '<em><b>Power Desc Server</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Power Desc Server</em>' containment reference isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Power Desc Server</em>' containment reference.
	 * @see #setPowerDescServer(PowerDescServer)
	 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getZDOCommonServers_PowerDescServer()
	 * @model containment="true"
	 * @generated
	 */
	PowerDescServer getPowerDescServer();

	/**
	 * Sets the value of the '{@link com.jennic.ZPSConfiguration.ZDOCommonServers#getPowerDescServer <em>Power Desc Server</em>}' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>Power Desc Server</em>' containment reference.
	 * @see #getPowerDescServer()
	 * @generated
	 */
	void setPowerDescServer(PowerDescServer value);

	/**
	 * Returns the value of the '<em><b>Match Desc Server</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Match Desc Server</em>' containment reference isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Match Desc Server</em>' containment reference.
	 * @see #setMatchDescServer(MatchDescServer)
	 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getZDOCommonServers_MatchDescServer()
	 * @model containment="true"
	 * @generated
	 */
	MatchDescServer getMatchDescServer();

	/**
	 * Sets the value of the '{@link com.jennic.ZPSConfiguration.ZDOCommonServers#getMatchDescServer <em>Match Desc Server</em>}' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>Match Desc Server</em>' containment reference.
	 * @see #getMatchDescServer()
	 * @generated
	 */
	void setMatchDescServer(MatchDescServer value);

	/**
	 * Returns the value of the '<em><b>Simple Desc Server</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Simple Desc Server</em>' containment reference isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Simple Desc Server</em>' containment reference.
	 * @see #setSimpleDescServer(SimpleDescServer)
	 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getZDOCommonServers_SimpleDescServer()
	 * @model containment="true"
	 * @generated
	 */
	SimpleDescServer getSimpleDescServer();

	/**
	 * Sets the value of the '{@link com.jennic.ZPSConfiguration.ZDOCommonServers#getSimpleDescServer <em>Simple Desc Server</em>}' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>Simple Desc Server</em>' containment reference.
	 * @see #getSimpleDescServer()
	 * @generated
	 */
	void setSimpleDescServer(SimpleDescServer value);

	/**
	 * Returns the value of the '<em><b>Mgmt Lqi Server</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Mgmt Lqi Server</em>' containment reference isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Mgmt Lqi Server</em>' containment reference.
	 * @see #setMgmtLqiServer(MgmtLqiServer)
	 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getZDOCommonServers_MgmtLqiServer()
	 * @model containment="true"
	 * @generated
	 */
	MgmtLqiServer getMgmtLqiServer();

	/**
	 * Sets the value of the '{@link com.jennic.ZPSConfiguration.ZDOCommonServers#getMgmtLqiServer <em>Mgmt Lqi Server</em>}' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>Mgmt Lqi Server</em>' containment reference.
	 * @see #getMgmtLqiServer()
	 * @generated
	 */
	void setMgmtLqiServer(MgmtLqiServer value);

	/**
	 * Returns the value of the '<em><b>Mgmt Leave Server</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Mgmt Leave Server</em>' containment reference isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Mgmt Leave Server</em>' containment reference.
	 * @see #setMgmtLeaveServer(MgmtLeaveServer)
	 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getZDOCommonServers_MgmtLeaveServer()
	 * @model containment="true"
	 * @generated
	 */
	MgmtLeaveServer getMgmtLeaveServer();

	/**
	 * Sets the value of the '{@link com.jennic.ZPSConfiguration.ZDOCommonServers#getMgmtLeaveServer <em>Mgmt Leave Server</em>}' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>Mgmt Leave Server</em>' containment reference.
	 * @see #getMgmtLeaveServer()
	 * @generated
	 */
	void setMgmtLeaveServer(MgmtLeaveServer value);

	/**
	 * Returns the value of the '<em><b>Bind Unbind Server</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Bind Unbind Server</em>' containment reference isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Bind Unbind Server</em>' containment reference.
	 * @see #setBindUnbindServer(BindUnbindServer)
	 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getZDOCommonServers_BindUnbindServer()
	 * @model containment="true"
	 * @generated
	 */
	BindUnbindServer getBindUnbindServer();

	/**
	 * Sets the value of the '{@link com.jennic.ZPSConfiguration.ZDOCommonServers#getBindUnbindServer <em>Bind Unbind Server</em>}' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>Bind Unbind Server</em>' containment reference.
	 * @see #getBindUnbindServer()
	 * @generated
	 */
	void setBindUnbindServer(BindUnbindServer value);

	/**
	 * Returns the value of the '<em><b>Extended Active Ep Server</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Extended Active Ep Server</em>' containment reference isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Extended Active Ep Server</em>' containment reference.
	 * @see #setExtendedActiveEpServer(ExtendedActiveEpServer)
	 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getZDOCommonServers_ExtendedActiveEpServer()
	 * @model containment="true"
	 * @generated
	 */
	ExtendedActiveEpServer getExtendedActiveEpServer();

	/**
	 * Sets the value of the '{@link com.jennic.ZPSConfiguration.ZDOCommonServers#getExtendedActiveEpServer <em>Extended Active Ep Server</em>}' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>Extended Active Ep Server</em>' containment reference.
	 * @see #getExtendedActiveEpServer()
	 * @generated
	 */
	void setExtendedActiveEpServer(ExtendedActiveEpServer value);

	/**
	 * Returns the value of the '<em><b>Extended Simple Desc Server</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Extended Simple Desc Server</em>' containment reference isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Extended Simple Desc Server</em>' containment reference.
	 * @see #setExtendedSimpleDescServer(ExtendedSimpleDescServer)
	 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getZDOCommonServers_ExtendedSimpleDescServer()
	 * @model containment="true"
	 * @generated
	 */
	ExtendedSimpleDescServer getExtendedSimpleDescServer();

	/**
	 * Sets the value of the '{@link com.jennic.ZPSConfiguration.ZDOCommonServers#getExtendedSimpleDescServer <em>Extended Simple Desc Server</em>}' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>Extended Simple Desc Server</em>' containment reference.
	 * @see #getExtendedSimpleDescServer()
	 * @generated
	 */
	void setExtendedSimpleDescServer(ExtendedSimpleDescServer value);

	/**
	 * Returns the value of the '<em><b>Bind Request Server</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Bind Request Server</em>' containment reference isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Bind Request Server</em>' containment reference.
	 * @see #setBindRequestServer(BindRequestServer)
	 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getZDOCommonServers_BindRequestServer()
	 * @model containment="true" required="true"
	 * @generated
	 */
	BindRequestServer getBindRequestServer();

	/**
	 * Sets the value of the '{@link com.jennic.ZPSConfiguration.ZDOCommonServers#getBindRequestServer <em>Bind Request Server</em>}' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>Bind Request Server</em>' containment reference.
	 * @see #getBindRequestServer()
	 * @generated
	 */
	void setBindRequestServer(BindRequestServer value);

	/**
	 * Returns the value of the '<em><b>Mgmt Bind Server</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Mgmt Bind Server</em>' containment reference isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Mgmt Bind Server</em>' containment reference.
	 * @see #setMgmtBindServer(MgmtBindServer)
	 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getZDOCommonServers_MgmtBindServer()
	 * @model containment="true"
	 * @generated
	 */
	MgmtBindServer getMgmtBindServer();

	/**
	 * Sets the value of the '{@link com.jennic.ZPSConfiguration.ZDOCommonServers#getMgmtBindServer <em>Mgmt Bind Server</em>}' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>Mgmt Bind Server</em>' containment reference.
	 * @see #getMgmtBindServer()
	 * @generated
	 */
	void setMgmtBindServer(MgmtBindServer value);

	/**
	 * Returns the value of the '<em><b>Mgmt NWK Enhance Update Server</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Mgmt NWK Enhance Update Server</em>' reference isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Mgmt NWK Enhance Update Server</em>' containment reference.
	 * @see #setMgmtNWKEnhanceUpdateServer(MgmtNWKEnhanceUpdateServer)
	 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getZDOCommonServers_MgmtNWKEnhanceUpdateServer()
	 * @model containment="true"
	 * @generated
	 */
	MgmtNWKEnhanceUpdateServer getMgmtNWKEnhanceUpdateServer();

	/**
	 * Sets the value of the '{@link com.jennic.ZPSConfiguration.ZDOCommonServers#getMgmtNWKEnhanceUpdateServer <em>Mgmt NWK Enhance Update Server</em>}' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>Mgmt NWK Enhance Update Server</em>' containment reference.
	 * @see #getMgmtNWKEnhanceUpdateServer()
	 * @generated
	 */
	void setMgmtNWKEnhanceUpdateServer(MgmtNWKEnhanceUpdateServer value);

} // ZDOCommonServers
