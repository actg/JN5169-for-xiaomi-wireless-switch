/**
 * (C) Jennic Ltd
 *
 * $Id$
 */
package com.jennic.ZPSConfiguration;

import org.eclipse.emf.ecore.EObject;

/**
 * <!-- begin-user-doc -->
 * A representation of the model object '<em><b>User Descriptor</b></em>'.
 * <!-- end-user-doc -->
 *
 * <p>
 * The following features are supported:
 * <ul>
 *   <li>{@link com.jennic.ZPSConfiguration.UserDescriptor#getUserDescription <em>User Description</em>}</li>
 * </ul>
 * </p>
 *
 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getUserDescriptor()
 * @model
 * @generated
 */
public interface UserDescriptor extends EObject {
	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	String copyright = "(C) NXP B.V";

	/**
	 * Returns the value of the '<em><b>User Description</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>User Description</em>' attribute isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>User Description</em>' attribute.
	 * @see #setUserDescription(String)
	 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getUserDescriptor_UserDescription()
	 * @model required="true"
	 * @generated
	 */
	String getUserDescription();

	/**
	 * Sets the value of the '{@link com.jennic.ZPSConfiguration.UserDescriptor#getUserDescription <em>User Description</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>User Description</em>' attribute.
	 * @see #getUserDescription()
	 * @generated
	 */
	void setUserDescription(String value);

} // UserDescriptor
