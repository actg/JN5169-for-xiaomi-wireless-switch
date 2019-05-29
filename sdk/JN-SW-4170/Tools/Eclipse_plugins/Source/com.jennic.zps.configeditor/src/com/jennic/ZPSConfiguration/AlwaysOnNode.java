/**
 * (C) Jennic Ltd
 *
 * $Id$
 */
package com.jennic.ZPSConfiguration;


/**
 * <!-- begin-user-doc -->
 * A representation of the model object '<em><b>Always On Node</b></em>'.
 * <!-- end-user-doc -->
 *
 * <p>
 * The following features are supported:
 * <ul>
 *   <li>{@link com.jennic.ZPSConfiguration.AlwaysOnNode#getTrustCenter <em>Trust Center</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.AlwaysOnNode#getPermitJoiningTime <em>Permit Joining Time</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.AlwaysOnNode#getChildTableSize <em>Child Table Size</em>}</li>
 * </ul>
 * </p>
 *
 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getAlwaysOnNode()
 * @model abstract="true"
 * @generated
 */
public interface AlwaysOnNode extends Node {
	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	String copyright = "(C) NXP B.V";

	/**
	 * Returns the value of the '<em><b>Trust Center</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Trust Center</em>' containment reference isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Trust Center</em>' containment reference.
	 * @see #setTrustCenter(TrustCenter)
	 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getAlwaysOnNode_TrustCenter()
	 * @model containment="true"
	 * @generated
	 */
	TrustCenter getTrustCenter();

	/**
	 * Sets the value of the '{@link com.jennic.ZPSConfiguration.AlwaysOnNode#getTrustCenter <em>Trust Center</em>}' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>Trust Center</em>' containment reference.
	 * @see #getTrustCenter()
	 * @generated
	 */
	void setTrustCenter(TrustCenter value);

	/**
	 * Returns the value of the '<em><b>Permit Joining Time</b></em>' attribute.
	 * The default value is <code>"255"</code>.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Permit Joining Time</em>' attribute isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Permit Joining Time</em>' attribute.
	 * @see #setPermitJoiningTime(int)
	 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getAlwaysOnNode_PermitJoiningTime()
	 * @model default="255" required="true"
	 *        annotation="http://jennic.com/hexdec min='0' max='255'"
	 * @generated
	 */
	int getPermitJoiningTime();

	/**
	 * Sets the value of the '{@link com.jennic.ZPSConfiguration.AlwaysOnNode#getPermitJoiningTime <em>Permit Joining Time</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>Permit Joining Time</em>' attribute.
	 * @see #getPermitJoiningTime()
	 * @generated
	 */
	void setPermitJoiningTime(int value);

	/**
	 * Returns the value of the '<em><b>Child Table Size</b></em>' attribute.
	 * The default value is <code>"6"</code>.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Child Table Size</em>' attribute isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Child Table Size</em>' attribute.
	 * @see #setChildTableSize(int)
	 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getAlwaysOnNode_ChildTableSize()
	 * @model default="6" required="true"
	 *        annotation="http://jennic.com/hexdec min='1' max='48'"
	 * @generated
	 */
	int getChildTableSize();

	/**
	 * Sets the value of the '{@link com.jennic.ZPSConfiguration.AlwaysOnNode#getChildTableSize <em>Child Table Size</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>Child Table Size</em>' attribute.
	 * @see #getChildTableSize()
	 * @generated
	 */
	void setChildTableSize(int value);

} // AlwaysOnNode
