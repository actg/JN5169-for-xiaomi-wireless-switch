/**
 * (C) Jennic Ltd
 *
 * $Id: KeyDescriptorTable.java 78102 2016-03-24 15:35:29Z nxp29741 $
 */
package com.jennic.ZPSConfiguration;

import org.eclipse.emf.common.util.EList;

import org.eclipse.emf.ecore.EObject;

/**
 * <!-- begin-user-doc -->
 * A representation of the model object '<em><b>Key Descriptor Table</b></em>'.
 * <!-- end-user-doc -->
 *
 * <p>
 * The following features are supported:
 * <ul>
 *   <li>{@link com.jennic.ZPSConfiguration.KeyDescriptorTable#getSize <em>Size</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.KeyDescriptorTable#getPreconfiguredKey <em>Preconfigured Key</em>}</li>
 * </ul>
 * </p>
 *
 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getKeyDescriptorTable()
 * @model
 * @generated
 */
public interface KeyDescriptorTable extends EObject {
	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	String copyright = "(C) NXP B.V";

	/**
	 * Returns the value of the '<em><b>Size</b></em>' attribute.
	 * The default value is <code>"8"</code>.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Size</em>' attribute isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Size</em>' attribute.
	 * @see #setSize(int)
	 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getKeyDescriptorTable_Size()
	 * @model default="8" required="true"
	 *        annotation="http://jennic.com/hexdec min='1' max='65535'"
	 * @generated
	 */
	int getSize();

	/**
	 * Sets the value of the '{@link com.jennic.ZPSConfiguration.KeyDescriptorTable#getSize <em>Size</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>Size</em>' attribute.
	 * @see #getSize()
	 * @generated
	 */
	void setSize(int value);

	/**
	 * Returns the value of the '<em><b>Preconfigured Key</b></em>' containment reference list.
	 * The list contents are of type {@link com.jennic.ZPSConfiguration.PreconfiguredKey}.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Preconfigured Key</em>' containment reference list isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Preconfigured Key</em>' containment reference list.
	 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getKeyDescriptorTable_PreconfiguredKey()
	 * @model containment="true"
	 * @generated
	 */
	EList<PreconfiguredKey> getPreconfiguredKey();

} // KeyDescriptorTable
