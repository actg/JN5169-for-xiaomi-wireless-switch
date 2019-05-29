/**
 * (C) Jennic Ltd
 *
 * $Id$
 */
package com.jennic.ZPSConfiguration;

import java.math.BigInteger;

/**
 * <!-- begin-user-doc -->
 * A representation of the model object '<em><b>Primary Binding Cache</b></em>'.
 * <!-- end-user-doc -->
 *
 * <p>
 * The following features are supported:
 * <ul>
 *   <li>{@link com.jennic.ZPSConfiguration.PrimaryBindingCache#getTableSize <em>Table Size</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.PrimaryBindingCache#getNumTables <em>Num Tables</em>}</li>
 * </ul>
 * </p>
 *
 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getPrimaryBindingCache()
 * @model
 * @generated
 */
public interface PrimaryBindingCache extends BindingCache {
	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	String copyright = "(C) NXP B.V";

	/**
	 * Returns the value of the '<em><b>Table Size</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Table Size</em>' attribute isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Table Size</em>' attribute.
	 * @see #setTableSize(BigInteger)
	 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getPrimaryBindingCache_TableSize()
	 * @model required="true"
	 * @generated
	 */
	BigInteger getTableSize();

	/**
	 * Sets the value of the '{@link com.jennic.ZPSConfiguration.PrimaryBindingCache#getTableSize <em>Table Size</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>Table Size</em>' attribute.
	 * @see #getTableSize()
	 * @generated
	 */
	void setTableSize(BigInteger value);

	/**
	 * Returns the value of the '<em><b>Num Tables</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Num Tables</em>' attribute isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Num Tables</em>' attribute.
	 * @see #setNumTables(BigInteger)
	 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getPrimaryBindingCache_NumTables()
	 * @model required="true"
	 * @generated
	 */
	BigInteger getNumTables();

	/**
	 * Sets the value of the '{@link com.jennic.ZPSConfiguration.PrimaryBindingCache#getNumTables <em>Num Tables</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>Num Tables</em>' attribute.
	 * @see #getNumTables()
	 * @generated
	 */
	void setNumTables(BigInteger value);

} // PrimaryBindingCache
