/**
 * (C) Jennic Ltd
 *
 * $Id: PreconfiguredTCLinkKey.java 78102 2016-03-24 15:35:29Z nxp29741 $
 */
package com.jennic.ZPSConfiguration;


/**
 * <!-- begin-user-doc -->
 * A representation of the model object '<em><b>Preconfigured TC Link Key</b></em>'.
 * <!-- end-user-doc -->
 *
 * <p>
 * The following features are supported:
 * <ul>
 *   <li>{@link com.jennic.ZPSConfiguration.PreconfiguredTCLinkKey#getId <em>Id</em>}</li>
 * </ul>
 * </p>
 *
 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getPreconfiguredTCLinkKey()
 * @model
 * @generated
 */
public interface PreconfiguredTCLinkKey extends TCKey {
	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	String copyright = "(C) NXP B.V";

	/**
	 * Returns the value of the '<em><b>Id</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Id</em>' attribute isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Id</em>' attribute.
	 * @see #isSetId()
	 * @see #unsetId()
	 * @see #setId(String)
	 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getPreconfiguredTCLinkKey_Id()
	 * @model unsettable="true" id="true" required="true" volatile="true" derived="true"
	 * @generated
	 */
	String getId();

	/**
	 * Sets the value of the '{@link com.jennic.ZPSConfiguration.PreconfiguredTCLinkKey#getId <em>Id</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>Id</em>' attribute.
	 * @see #isSetId()
	 * @see #unsetId()
	 * @see #getId()
	 * @generated
	 */
	void setId(String value);

	/**
	 * Unsets the value of the '{@link com.jennic.ZPSConfiguration.PreconfiguredTCLinkKey#getId <em>Id</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #isSetId()
	 * @see #getId()
	 * @see #setId(String)
	 * @generated
	 */
	void unsetId();

	/**
	 * Returns whether the value of the '{@link com.jennic.ZPSConfiguration.PreconfiguredTCLinkKey#getId <em>Id</em>}' attribute is set.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return whether the value of the '<em>Id</em>' attribute is set.
	 * @see #unsetId()
	 * @see #getId()
	 * @see #setId(String)
	 * @generated
	 */
	boolean isSetId();

} // PreconfiguredTCLinkKey
