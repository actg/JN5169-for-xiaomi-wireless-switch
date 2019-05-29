/**
 * (C) Jennic Ltd
 *
 * $Id: PreconfiguredKey.java 78102 2016-03-24 15:35:29Z nxp29741 $
 */
package com.jennic.ZPSConfiguration;

import org.eclipse.emf.ecore.EObject;

/**
 * <!-- begin-user-doc -->
 * A representation of the model object '<em><b>Preconfigured Key</b></em>'.
 * <!-- end-user-doc -->
 *
 * <p>
 * The following features are supported:
 * <ul>
 *   <li>{@link com.jennic.ZPSConfiguration.PreconfiguredKey#getKey <em>Key</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.PreconfiguredKey#getIEEEAddress <em>IEEE Address</em>}</li>
 * </ul>
 * </p>
 *
 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getPreconfiguredKey()
 * @model
 * @generated
 */
public interface PreconfiguredKey extends EObject {
	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	String copyright = "(C) NXP B.V";

	/**
	 * Returns the value of the '<em><b>Key</b></em>' attribute.
	 * The default value is <code>"0"</code>.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Key</em>' attribute isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Key</em>' attribute.
	 * @see #setKey(BigInteger)
	 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getPreconfiguredKey_Key()
	 * @model default="0" dataType="com.jennic.ZPSConfiguration.ESecKey" required="true"
	 *        annotation="http://jennic.com/hexdec hex='' hex_width='32'"
	 * @generated
	 */
	Object getKey();

	/**
	 * Sets the value of the '{@link com.jennic.ZPSConfiguration.PreconfiguredKey#getKey <em>Key</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>Key</em>' attribute.
	 * @see #getKey()
	 * @generated
	 */
	void setKey(Object value);

	/**
	 * Returns the value of the '<em><b>IEEE Address</b></em>' attribute.
	 * The default value is <code>"0"</code>.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>IEEE Address</em>' attribute isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>IEEE Address</em>' attribute.
	 * @see #setIEEEAddress(BigInteger)
	 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getPreconfiguredKey_IEEEAddress()
	 * @model default="0" dataType="com.jennic.ZPSConfiguration.EExtPANId" required="true"
	 *        annotation="http://jennic.com/hexdec hex='' min='0' max='18446744073709551615' hex_width='16'"
	 * @generated
	 */
	Object getIEEEAddress();

	/**
	 * Sets the value of the '{@link com.jennic.ZPSConfiguration.PreconfiguredKey#getIEEEAddress <em>IEEE Address</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>IEEE Address</em>' attribute.
	 * @see #getIEEEAddress()
	 * @generated
	 */
	void setIEEEAddress(Object value);

} // PreconfiguredKey
