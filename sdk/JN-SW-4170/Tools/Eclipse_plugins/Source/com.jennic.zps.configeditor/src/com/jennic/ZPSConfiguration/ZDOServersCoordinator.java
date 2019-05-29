/**
 * (C) Jennic Ltd
 *
 * $Id$
 */
package com.jennic.ZPSConfiguration;

/**
 * <!-- begin-user-doc -->
 * A representation of the model object '<em><b>ZDO Servers Coordinator</b></em>'.
 * <!-- end-user-doc -->
 *
 * <p>
 * The following features are supported:
 * <ul>
 *   <li>{@link com.jennic.ZPSConfiguration.ZDOServersCoordinator#getEndDeviceBindServer <em>End Device Bind Server</em>}</li>
 * </ul>
 * </p>
 *
 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getZDOServersCoordinator()
 * @model
 * @generated
 */
public interface ZDOServersCoordinator extends ZDOCommonServers, ZDOCoordRouterOnlyServers {
	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	String copyright = "(C) NXP B.V";

	/**
	 * Returns the value of the '<em><b>End Device Bind Server</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>End Device Bind Server</em>' containment reference isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>End Device Bind Server</em>' containment reference.
	 * @see #setEndDeviceBindServer(EndDeviceBindServer)
	 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getZDOServersCoordinator_EndDeviceBindServer()
	 * @model containment="true"
	 * @generated
	 */
	EndDeviceBindServer getEndDeviceBindServer();

	/**
	 * Sets the value of the '{@link com.jennic.ZPSConfiguration.ZDOServersCoordinator#getEndDeviceBindServer <em>End Device Bind Server</em>}' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>End Device Bind Server</em>' containment reference.
	 * @see #getEndDeviceBindServer()
	 * @generated
	 */
	void setEndDeviceBindServer(EndDeviceBindServer value);

} // ZDOServersCoordinator
