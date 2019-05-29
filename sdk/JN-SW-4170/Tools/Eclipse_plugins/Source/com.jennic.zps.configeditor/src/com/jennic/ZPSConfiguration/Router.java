/**
 * (C) Jennic Ltd
 *
 * $Id$
 */
package com.jennic.ZPSConfiguration;


/**
 * <!-- begin-user-doc -->
 * A representation of the model object '<em><b>Router</b></em>'.
 * <!-- end-user-doc -->
 *
 * <p>
 * The following features are supported:
 * <ul>
 *   <li>{@link com.jennic.ZPSConfiguration.Router#getZDOServers <em>ZDO Servers</em>}</li>
 * </ul>
 * </p>
 *
 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getRouter()
 * @model
 * @generated
 */
public interface Router extends AlwaysOnNode, ChildNodes {
	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	String copyright = "(C) NXP B.V";

	/**
	 * Returns the value of the '<em><b>ZDO Servers</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>ZDO Servers</em>' containment reference isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>ZDO Servers</em>' containment reference.
	 * @see #setZDOServers(ZDOServersRouter)
	 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getRouter_ZDOServers()
	 * @model containment="true" required="true"
	 * @generated
	 */
	ZDOServersRouter getZDOServers();

	/**
	 * Sets the value of the '{@link com.jennic.ZPSConfiguration.Router#getZDOServers <em>ZDO Servers</em>}' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>ZDO Servers</em>' containment reference.
	 * @see #getZDOServers()
	 * @generated
	 */
	void setZDOServers(ZDOServersRouter value);

} // Router
