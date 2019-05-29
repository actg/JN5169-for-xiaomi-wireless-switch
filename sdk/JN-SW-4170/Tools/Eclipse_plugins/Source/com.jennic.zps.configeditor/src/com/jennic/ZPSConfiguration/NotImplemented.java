/**
 * (C) Jennic Ltd
 *
 * $Id: NotImplemented.java 78102 2016-03-24 15:35:29Z nxp29741 $
 */
package com.jennic.ZPSConfiguration;

import org.eclipse.emf.ecore.EObject;

/**
 * <!-- begin-user-doc -->
 * A representation of the model object '<em><b>Not Implemented</b></em>'.
 * <!-- end-user-doc -->
 *
 * <p>
 * The following features are supported:
 * <ul>
 *   <li>{@link com.jennic.ZPSConfiguration.NotImplemented#getComplexDescriptor <em>Complex Descriptor</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.NotImplemented#getDiscoveryTable <em>Discovery Table</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.NotImplemented#getDiscoveryCache <em>Discovery Cache</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.NotImplemented#getBindingCache <em>Binding Cache</em>}</li>
 * </ul>
 * </p>
 *
 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getNotImplemented()
 * @model
 * @generated
 */
public interface NotImplemented extends EObject {
	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	String copyright = "(C) NXP B.V";

	/**
	 * Returns the value of the '<em><b>Complex Descriptor</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Complex Descriptor</em>' containment reference isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Complex Descriptor</em>' containment reference.
	 * @see #setComplexDescriptor(ComplexDescriptor)
	 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getNotImplemented_ComplexDescriptor()
	 * @model containment="true"
	 * @generated
	 */
	ComplexDescriptor getComplexDescriptor();

	/**
	 * Sets the value of the '{@link com.jennic.ZPSConfiguration.NotImplemented#getComplexDescriptor <em>Complex Descriptor</em>}' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>Complex Descriptor</em>' containment reference.
	 * @see #getComplexDescriptor()
	 * @generated
	 */
	void setComplexDescriptor(ComplexDescriptor value);

	/**
	 * Returns the value of the '<em><b>Discovery Table</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Discovery Table</em>' containment reference isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Discovery Table</em>' containment reference.
	 * @see #setDiscoveryTable(DiscoveryTable)
	 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getNotImplemented_DiscoveryTable()
	 * @model containment="true"
	 * @generated
	 */
	DiscoveryTable getDiscoveryTable();

	/**
	 * Sets the value of the '{@link com.jennic.ZPSConfiguration.NotImplemented#getDiscoveryTable <em>Discovery Table</em>}' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>Discovery Table</em>' containment reference.
	 * @see #getDiscoveryTable()
	 * @generated
	 */
	void setDiscoveryTable(DiscoveryTable value);

	/**
	 * Returns the value of the '<em><b>Discovery Cache</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Discovery Cache</em>' containment reference isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Discovery Cache</em>' containment reference.
	 * @see #setDiscoveryCache(DiscoveryCache)
	 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getNotImplemented_DiscoveryCache()
	 * @model containment="true"
	 * @generated
	 */
	DiscoveryCache getDiscoveryCache();

	/**
	 * Sets the value of the '{@link com.jennic.ZPSConfiguration.NotImplemented#getDiscoveryCache <em>Discovery Cache</em>}' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>Discovery Cache</em>' containment reference.
	 * @see #getDiscoveryCache()
	 * @generated
	 */
	void setDiscoveryCache(DiscoveryCache value);

	/**
	 * Returns the value of the '<em><b>Binding Cache</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Binding Cache</em>' containment reference isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Binding Cache</em>' containment reference.
	 * @see #setBindingCache(BindingCache)
	 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getNotImplemented_BindingCache()
	 * @model containment="true"
	 * @generated
	 */
	BindingCache getBindingCache();

	/**
	 * Sets the value of the '{@link com.jennic.ZPSConfiguration.NotImplemented#getBindingCache <em>Binding Cache</em>}' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>Binding Cache</em>' containment reference.
	 * @see #getBindingCache()
	 * @generated
	 */
	void setBindingCache(BindingCache value);

} // NotImplemented
