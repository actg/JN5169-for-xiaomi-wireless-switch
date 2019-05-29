/**
 * (C) Jennic Ltd
 *
 * $Id: ZDOClientServer.java 78102 2016-03-24 15:35:29Z nxp29741 $
 */
package com.jennic.ZPSConfiguration;

import org.eclipse.emf.ecore.EObject;

/**
 * <!-- begin-user-doc -->
 * A representation of the model object '<em><b>ZDO Client Server</b></em>'.
 * <!-- end-user-doc -->
 *
 * <p>
 * The following features are supported:
 * <ul>
 *   <li>{@link com.jennic.ZPSConfiguration.ZDOClientServer#getOutputAPdu <em>Output APdu</em>}</li>
 * </ul>
 * </p>
 *
 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getZDOClientServer()
 * @model abstract="true"
 * @generated
 */
public interface ZDOClientServer extends EObject {
	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	String copyright = "(C) NXP B.V";

	/**
	 * Returns the value of the '<em><b>Output APdu</b></em>' reference.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Output APdu</em>' reference isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Output APdu</em>' reference.
	 * @see #setOutputAPdu(APDU)
	 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getZDOClientServer_OutputAPdu()
	 * @model required="true"
	 * @generated
	 */
	APDU getOutputAPdu();

	/**
	 * Sets the value of the '{@link com.jennic.ZPSConfiguration.ZDOClientServer#getOutputAPdu <em>Output APdu</em>}' reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>Output APdu</em>' reference.
	 * @see #getOutputAPdu()
	 * @generated
	 */
	void setOutputAPdu(APDU value);

} // ZDOClientServer
