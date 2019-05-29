/**
 * (C) Jennic Ltd
 *
 * $Id$
 */
package com.jennic.ZPSConfiguration.impl;


import java.math.BigInteger;

import org.eclipse.emf.common.notify.Notification;

import org.eclipse.emf.ecore.EClass;

import org.eclipse.emf.ecore.impl.ENotificationImpl;

import com.jennic.ZPSConfiguration.BackupBindingCache;
import com.jennic.ZPSConfiguration.ZPSConfigurationPackage;

/**
 * <!-- begin-user-doc -->
 * An implementation of the model object '<em><b>Backup Binding Cache</b></em>'.
 * <!-- end-user-doc -->
 * <p>
 * The following features are implemented:
 * <ul>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.BackupBindingCacheImpl#getTableSize <em>Table Size</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.BackupBindingCacheImpl#getNumTables <em>Num Tables</em>}</li>
 * </ul>
 * </p>
 *
 * @generated
 */
public class BackupBindingCacheImpl extends BindingCacheImpl implements BackupBindingCache {
	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public static final String copyright = "(C) NXP B.V";

	/**
	 * The default value of the '{@link #getTableSize() <em>Table Size</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getTableSize()
	 * @generated
	 * @ordered
	 */
	protected static final BigInteger TABLE_SIZE_EDEFAULT = null;

	/**
	 * The cached value of the '{@link #getTableSize() <em>Table Size</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getTableSize()
	 * @generated
	 * @ordered
	 */
	protected BigInteger tableSize = TABLE_SIZE_EDEFAULT;

	/**
	 * The default value of the '{@link #getNumTables() <em>Num Tables</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getNumTables()
	 * @generated
	 * @ordered
	 */
	protected static final BigInteger NUM_TABLES_EDEFAULT = null;

	/**
	 * The cached value of the '{@link #getNumTables() <em>Num Tables</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getNumTables()
	 * @generated
	 * @ordered
	 */
	protected BigInteger numTables = NUM_TABLES_EDEFAULT;

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	protected BackupBindingCacheImpl() {
		super();
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	@Override
	protected EClass eStaticClass() {
		return ZPSConfigurationPackage.Literals.BACKUP_BINDING_CACHE;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public BigInteger getTableSize() {
		return tableSize;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void setTableSize(BigInteger newTableSize) {
		BigInteger oldTableSize = tableSize;
		tableSize = newTableSize;
		if (eNotificationRequired())
			eNotify(new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.BACKUP_BINDING_CACHE__TABLE_SIZE, oldTableSize, tableSize));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public BigInteger getNumTables() {
		return numTables;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void setNumTables(BigInteger newNumTables) {
		BigInteger oldNumTables = numTables;
		numTables = newNumTables;
		if (eNotificationRequired())
			eNotify(new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.BACKUP_BINDING_CACHE__NUM_TABLES, oldNumTables, numTables));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	@Override
	public Object eGet(int featureID, boolean resolve, boolean coreType) {
		switch (featureID) {
			case ZPSConfigurationPackage.BACKUP_BINDING_CACHE__TABLE_SIZE:
				return getTableSize();
			case ZPSConfigurationPackage.BACKUP_BINDING_CACHE__NUM_TABLES:
				return getNumTables();
		}
		return super.eGet(featureID, resolve, coreType);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	@Override
	public void eSet(int featureID, Object newValue) {
		switch (featureID) {
			case ZPSConfigurationPackage.BACKUP_BINDING_CACHE__TABLE_SIZE:
				setTableSize((BigInteger)newValue);
				return;
			case ZPSConfigurationPackage.BACKUP_BINDING_CACHE__NUM_TABLES:
				setNumTables((BigInteger)newValue);
				return;
		}
		super.eSet(featureID, newValue);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	@Override
	public void eUnset(int featureID) {
		switch (featureID) {
			case ZPSConfigurationPackage.BACKUP_BINDING_CACHE__TABLE_SIZE:
				setTableSize(TABLE_SIZE_EDEFAULT);
				return;
			case ZPSConfigurationPackage.BACKUP_BINDING_CACHE__NUM_TABLES:
				setNumTables(NUM_TABLES_EDEFAULT);
				return;
		}
		super.eUnset(featureID);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	@Override
	public boolean eIsSet(int featureID) {
		switch (featureID) {
			case ZPSConfigurationPackage.BACKUP_BINDING_CACHE__TABLE_SIZE:
				return TABLE_SIZE_EDEFAULT == null ? tableSize != null : !TABLE_SIZE_EDEFAULT.equals(tableSize);
			case ZPSConfigurationPackage.BACKUP_BINDING_CACHE__NUM_TABLES:
				return NUM_TABLES_EDEFAULT == null ? numTables != null : !NUM_TABLES_EDEFAULT.equals(numTables);
		}
		return super.eIsSet(featureID);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	@Override
	public String toString() {
		if (eIsProxy()) return super.toString();

		StringBuffer result = new StringBuffer(super.toString());
		result.append(" (TableSize: ");
		result.append(tableSize);
		result.append(", NumTables: ");
		result.append(numTables);
		result.append(')');
		return result.toString();
	}

} //BackupBindingCacheImpl
