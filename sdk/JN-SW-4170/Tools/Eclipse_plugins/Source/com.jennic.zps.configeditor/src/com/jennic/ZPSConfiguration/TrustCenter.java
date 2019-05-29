/**
 * (C) Jennic Ltd
 *
 * $Id$
 */
package com.jennic.ZPSConfiguration;

import org.eclipse.emf.ecore.EObject;

/**
 * <!-- begin-user-doc -->
 * A representation of the model object '<em><b>Trust Center</b></em>'.
 * <!-- end-user-doc -->
 *
 * <p>
 * The following features are supported:
 * <ul>
 *   <li>{@link com.jennic.ZPSConfiguration.TrustCenter#getDeviceTableSize <em>Device Table Size</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.TrustCenter#getKeys <em>Keys</em>}</li>
 * </ul>
 * </p>
 *
 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getTrustCenter()
 * @model
 * @generated
 */
public interface TrustCenter extends EObject {
	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	String copyright = "(C) NXP B.V";

	/**
	 * Returns the value of the '<em><b>Device Table Size</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Device Table Size</em>' attribute isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Device Table Size</em>' attribute.
	 * @see #setDeviceTableSize(int)
	 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getTrustCenter_DeviceTableSize()
	 * @model required="true"
	 *        annotation="http://jennic.com/hexdec min='0' max='65535'"
	 * @generated
	 */
	int getDeviceTableSize();

	/**
	 * Sets the value of the '{@link com.jennic.ZPSConfiguration.TrustCenter#getDeviceTableSize <em>Device Table Size</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>Device Table Size</em>' attribute.
	 * @see #getDeviceTableSize()
	 * @generated
	 */
	void setDeviceTableSize(int value);

	/**
	 * Returns the value of the '<em><b>Keys</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Keys</em>' containment reference isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Keys</em>' containment reference.
	 * @see #setKeys(TCKey)
	 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getTrustCenter_Keys()
	 * @model containment="true"
	 * @generated
	 */
	TCKey getKeys();

	/**
	 * Sets the value of the '{@link com.jennic.ZPSConfiguration.TrustCenter#getKeys <em>Keys</em>}' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>Keys</em>' containment reference.
	 * @see #getKeys()
	 * @generated
	 */
	void setKeys(TCKey value);

} // TrustCenter
