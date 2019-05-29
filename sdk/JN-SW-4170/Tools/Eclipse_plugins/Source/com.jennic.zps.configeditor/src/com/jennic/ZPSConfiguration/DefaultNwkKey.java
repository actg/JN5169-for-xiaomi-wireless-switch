/**
 * (C) Jennic Ltd
 *
 * $Id: DefaultNwkKey.java 78102 2016-03-24 15:35:29Z nxp29741 $
 */
package com.jennic.ZPSConfiguration;


/**
 * <!-- begin-user-doc -->
 * A representation of the model object '<em><b>Default Nwk Key</b></em>'.
 * <!-- end-user-doc -->
 *
 * <p>
 * The following features are supported:
 * <ul>
 *   <li>{@link com.jennic.ZPSConfiguration.DefaultNwkKey#isRandom <em>Random</em>}</li>
 * </ul>
 * </p>
 *
 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getDefaultNwkKey()
 * @model
 * @generated
 */
public interface DefaultNwkKey extends NwkKey {
	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	String copyright = "(C) NXP B.V";

	/**
	 * Returns the value of the '<em><b>Random</b></em>' attribute.
	 * The default value is <code>"true"</code>.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Random</em>' attribute isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Random</em>' attribute.
	 * @see #setRandom(boolean)
	 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getDefaultNwkKey_Random()
	 * @model default="true" required="true"
	 * @generated
	 */
	boolean isRandom();

	/**
	 * Sets the value of the '{@link com.jennic.ZPSConfiguration.DefaultNwkKey#isRandom <em>Random</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>Random</em>' attribute.
	 * @see #isRandom()
	 * @generated
	 */
	void setRandom(boolean value);

} // DefaultNwkKey
