/**
 * (C) Jennic Ltd
 *
 * $Id$
 */
package com.jennic.ZPSConfiguration;

import java.math.BigInteger;

import org.eclipse.emf.ecore.EObject;

/**
 * <!-- begin-user-doc -->
 * A representation of the model object '<em><b>Backup Group Cache</b></em>'.
 * <!-- end-user-doc -->
 *
 * <p>
 * The following features are supported:
 * <ul>
 *   <li>{@link com.jennic.ZPSConfiguration.BackupGroupCache#getSize <em>Size</em>}</li>
 * </ul>
 * </p>
 *
 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getBackupGroupCache()
 * @model
 * @generated
 */
public interface BackupGroupCache extends EObject {
	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	String copyright = "(C) NXP B.V";

	/**
	 * Returns the value of the '<em><b>Size</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Size</em>' attribute isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Size</em>' attribute.
	 * @see #setSize(BigInteger)
	 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getBackupGroupCache_Size()
	 * @model
	 * @generated
	 */
	BigInteger getSize();

	/**
	 * Sets the value of the '{@link com.jennic.ZPSConfiguration.BackupGroupCache#getSize <em>Size</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>Size</em>' attribute.
	 * @see #getSize()
	 * @generated
	 */
	void setSize(BigInteger value);

} // BackupGroupCache
