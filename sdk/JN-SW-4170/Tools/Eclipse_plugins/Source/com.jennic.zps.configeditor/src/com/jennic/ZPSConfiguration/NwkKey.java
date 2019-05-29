/**
 * (C) Jennic Ltd
 *
 * $Id: NwkKey.java 78102 2016-03-24 15:35:29Z nxp29741 $
 */
package com.jennic.ZPSConfiguration;

/**
 * <!-- begin-user-doc -->
 * A representation of the model object '<em><b>Nwk Key</b></em>'.
 * <!-- end-user-doc -->
 *
 * <p>
 * The following features are supported:
 * <ul>
 *   <li>{@link com.jennic.ZPSConfiguration.NwkKey#getKeySequenceNumber <em>Key Sequence Number</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.NwkKey#getKey <em>Key</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.NwkKey#getId <em>Id</em>}</li>
 * </ul>
 * </p>
 *
 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getNwkKey()
 * @model abstract="true"
 * @generated
 */
public interface NwkKey extends TCKey {
	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	String copyright = "(C) NXP B.V";

	/**
	 * Returns the value of the '<em><b>Key Sequence Number</b></em>' attribute.
	 * The default value is <code>"1"</code>.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Key Sequence Number</em>' attribute isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Key Sequence Number</em>' attribute.
	 * @see #setKeySequenceNumber(int)
	 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getNwkKey_KeySequenceNumber()
	 * @model default="1" required="true"
	 *        annotation="http://jennic.com/hexdec min='0' max='255'"
	 * @generated
	 */
	int getKeySequenceNumber();

	/**
	 * Sets the value of the '{@link com.jennic.ZPSConfiguration.NwkKey#getKeySequenceNumber <em>Key Sequence Number</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>Key Sequence Number</em>' attribute.
	 * @see #getKeySequenceNumber()
	 * @generated
	 */
	void setKeySequenceNumber(int value);

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
	 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getNwkKey_Key()
	 * @model default="0" dataType="com.jennic.ZPSConfiguration.ESecKey" required="true"
	 *        annotation="http://jennic.com/hexdec hex='' hex_width='32'"
	 * @generated
	 */
	Object getKey();

	/**
	 * Sets the value of the '{@link com.jennic.ZPSConfiguration.NwkKey#getKey <em>Key</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>Key</em>' attribute.
	 * @see #getKey()
	 * @generated
	 */
	void setKey(Object value);

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
	 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getNwkKey_Id()
	 * @model unsettable="true" id="true" required="true" volatile="true" derived="true"
	 * @generated
	 */
	String getId();

	/**
	 * Sets the value of the '{@link com.jennic.ZPSConfiguration.NwkKey#getId <em>Id</em>}' attribute.
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
	 * Unsets the value of the '{@link com.jennic.ZPSConfiguration.NwkKey#getId <em>Id</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #isSetId()
	 * @see #getId()
	 * @see #setId(String)
	 * @generated
	 */
	void unsetId();

	/**
	 * Returns whether the value of the '{@link com.jennic.ZPSConfiguration.NwkKey#getId <em>Id</em>}' attribute is set.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return whether the value of the '<em>Id</em>' attribute is set.
	 * @see #unsetId()
	 * @see #getId()
	 * @see #setId(String)
	 * @generated
	 */
	boolean isSetId();

} // NwkKey
