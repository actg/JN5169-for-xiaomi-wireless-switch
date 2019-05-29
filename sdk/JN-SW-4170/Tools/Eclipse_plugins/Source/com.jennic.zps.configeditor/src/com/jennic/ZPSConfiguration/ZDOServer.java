/**
 * (C) Jennic Ltd
 *
 * $Id$
 */
package com.jennic.ZPSConfiguration;

import org.eclipse.emf.ecore.EObject;

/**
 * <!-- begin-user-doc -->
 * A representation of the model object '<em><b>ZDO Server</b></em>'.
 * <!-- end-user-doc -->
 *
 * <p>
 * The following features are supported:
 * <ul>
 *   <li>{@link com.jennic.ZPSConfiguration.ZDOServer#getOutputAPdu <em>Output APdu</em>}</li>
 * </ul>
 * </p>
 *
 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getZDOServer()
 * @model abstract="true"
 * @generated
 */
public interface ZDOServer extends EObject {
	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	String copyright = "(C) Jennic Ltd";

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
	 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getZDOServer_OutputAPdu()
	 * @model required="true"
	 * @generated
	 */
	APDU getOutputAPdu();

	/**
	 * Sets the value of the '{@link com.jennic.ZPSConfiguration.ZDOServer#getOutputAPdu <em>Output APdu</em>}' reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>Output APdu</em>' reference.
	 * @see #getOutputAPdu()
	 * @generated
	 */
	void setOutputAPdu(APDU value);

} // ZDOServer
