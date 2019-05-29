/**
 * (C) Jennic Ltd
 *
 * $Id$
 */
package com.jennic.ZPSConfiguration;

import org.eclipse.emf.ecore.EObject;

/**
 * <!-- begin-user-doc -->
 * A representation of the model object '<em><b>Child Nodes</b></em>'.
 * <!-- end-user-doc -->
 *
 * <p>
 * The following features are supported:
 * <ul>
 *   <li>{@link com.jennic.ZPSConfiguration.ChildNodes#getScanDuration <em>Scan Duration</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.ChildNodes#getNetworkSelection <em>Network Selection</em>}</li>
 * </ul>
 * </p>
 *
 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getChildNodes()
 * @model abstract="true"
 * @generated
 */
public interface ChildNodes extends EObject {
	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	String copyright = "(C) NXP B.V";

	/**
	 * Returns the value of the '<em><b>Scan Duration</b></em>' attribute.
	 * The default value is <code>"3"</code>.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Scan Duration</em>' attribute isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Scan Duration</em>' attribute.
	 * @see #setScanDuration(byte)
	 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getChildNodes_ScanDuration()
	 * @model default="3" required="true"
	 *        annotation="http://jennic.com/hexdec min='0' max='14'"
	 * @generated
	 */
	byte getScanDuration();

	/**
	 * Sets the value of the '{@link com.jennic.ZPSConfiguration.ChildNodes#getScanDuration <em>Scan Duration</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>Scan Duration</em>' attribute.
	 * @see #getScanDuration()
	 * @generated
	 */
	void setScanDuration(byte value);

	/**
	 * Returns the value of the '<em><b>Network Selection</b></em>' attribute.
	 * The default value is <code>"User Selected"</code>.
	 * The literals are from the enumeration {@link com.jennic.ZPSConfiguration.NetworkSelectionTypes}.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Network Selection</em>' attribute isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Network Selection</em>' attribute.
	 * @see com.jennic.ZPSConfiguration.NetworkSelectionTypes
	 * @see #setNetworkSelection(NetworkSelectionTypes)
	 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getChildNodes_NetworkSelection()
	 * @model default="User Selected" required="true"
	 * @generated
	 */
	NetworkSelectionTypes getNetworkSelection();

	/**
	 * Sets the value of the '{@link com.jennic.ZPSConfiguration.ChildNodes#getNetworkSelection <em>Network Selection</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>Network Selection</em>' attribute.
	 * @see com.jennic.ZPSConfiguration.NetworkSelectionTypes
	 * @see #getNetworkSelection()
	 * @generated
	 */
	void setNetworkSelection(NetworkSelectionTypes value);

} // ChildNodes
