/**
 * (C) Jennic Ltd
 */
package com.jennic.ZPSConfiguration;

import org.eclipse.emf.ecore.EObject;

/**
 * <!-- begin-user-doc -->
 * A representation of the model object '<em><b>Channel Page List</b></em>'.
 * <!-- end-user-doc -->
 *
 * <p>
 * The following features are supported:
 * <ul>
 *   <li>{@link com.jennic.ZPSConfiguration.ChannelPageList#getChannelPageMask <em>Channel Page Mask</em>}</li>
 * </ul>
 * </p>
 *
 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getChannelPageList()
 * @model
 * @generated
 */
public interface ChannelPageList extends EObject {
	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	String copyright = "(C) Jennic Ltd";

	/**
	 * Returns the value of the '<em><b>Channel Page Mask</b></em>' attribute.
	 * The default value is <code>"0x7FFF800"</code>.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Channel Page Mask</em>' attribute isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Channel Page Mask</em>' attribute.
	 * @see #setChannelPageMask(Object)
	 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getChannelPageList_ChannelPageMask()
	 * @model default="0x7FFF800" dataType="com.jennic.ZPSConfiguration.EChannelMask"
	 * @generated
	 */
	Object getChannelPageMask();

	/**
	 * Sets the value of the '{@link com.jennic.ZPSConfiguration.ChannelPageList#getChannelPageMask <em>Channel Page Mask</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>Channel Page Mask</em>' attribute.
	 * @see #getChannelPageMask()
	 * @generated
	 */
	void setChannelPageMask(Object value);

} // ChannelPageList
