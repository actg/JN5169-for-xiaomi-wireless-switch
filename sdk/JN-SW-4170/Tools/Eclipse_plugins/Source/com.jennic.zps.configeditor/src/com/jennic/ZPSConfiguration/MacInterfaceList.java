/**
 * (C) Jennic Ltd
 */
package com.jennic.ZPSConfiguration;

import org.eclipse.emf.common.util.EList;

import org.eclipse.emf.ecore.EObject;

/**
 * <!-- begin-user-doc -->
 * A representation of the model object '<em><b>Mac Interface List</b></em>'.
 * <!-- end-user-doc -->
 *
 * <p>
 * The following features are supported:
 * <ul>
 *   <li>{@link com.jennic.ZPSConfiguration.MacInterfaceList#getMacInterface <em>Mac Interface</em>}</li>
 * </ul>
 * </p>
 *
 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getMacInterfaceList()
 * @model
 * @generated
 */
public interface MacInterfaceList extends EObject {
	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	String copyright = "(C) NXP B.V";

	/**
	 * Returns the value of the '<em><b>Mac Interface</b></em>' containment reference list.
	 * The list contents are of type {@link com.jennic.ZPSConfiguration.MacInterface}.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Mac Interface</em>' reference list isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Mac Interface</em>' containment reference list.
	 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getMacInterfaceList_MacInterface()
	 * @model containment="true"
	 * @generated
	 */
	EList<MacInterface> getMacInterface();

} // MacInterfaceList
