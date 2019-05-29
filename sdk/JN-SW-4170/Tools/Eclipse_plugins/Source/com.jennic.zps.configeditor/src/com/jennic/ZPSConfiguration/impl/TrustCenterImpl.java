/**
 * (C) Jennic Ltd
 *
 * $Id$
 */
package com.jennic.ZPSConfiguration.impl;


import com.jennic.ZPSConfiguration.TCKey;
import org.eclipse.emf.common.notify.Notification;

import org.eclipse.emf.common.notify.NotificationChain;
import org.eclipse.emf.ecore.EClass;

import org.eclipse.emf.ecore.InternalEObject;
import org.eclipse.emf.ecore.impl.ENotificationImpl;
import org.eclipse.emf.ecore.impl.EObjectImpl;

import com.jennic.ZPSConfiguration.TrustCenter;
import com.jennic.ZPSConfiguration.ZPSConfigurationPackage;

/**
 * <!-- begin-user-doc -->
 * An implementation of the model object '<em><b>Trust Center</b></em>'.
 * <!-- end-user-doc -->
 * <p>
 * The following features are implemented:
 * <ul>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.TrustCenterImpl#getDeviceTableSize <em>Device Table Size</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.TrustCenterImpl#getKeys <em>Keys</em>}</li>
 * </ul>
 * </p>
 *
 * @generated
 */
public class TrustCenterImpl extends EObjectImpl implements TrustCenter {
	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public static final String copyright = "(C) NXP B.V";

	/**
	 * The default value of the '{@link #getDeviceTableSize() <em>Device Table Size</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getDeviceTableSize()
	 * @generated
	 * @ordered
	 */
	protected static final int DEVICE_TABLE_SIZE_EDEFAULT = 0;

	/**
	 * The cached value of the '{@link #getDeviceTableSize() <em>Device Table Size</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getDeviceTableSize()
	 * @generated
	 * @ordered
	 */
	protected int deviceTableSize = DEVICE_TABLE_SIZE_EDEFAULT;

	/**
	 * The cached value of the '{@link #getKeys() <em>Keys</em>}' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getKeys()
	 * @generated
	 * @ordered
	 */
	protected TCKey keys;

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	protected TrustCenterImpl() {
		super();
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	@Override
	protected EClass eStaticClass() {
		return ZPSConfigurationPackage.Literals.TRUST_CENTER;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public int getDeviceTableSize() {
		return deviceTableSize;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void setDeviceTableSize(int newDeviceTableSize) {
		int oldDeviceTableSize = deviceTableSize;
		deviceTableSize = newDeviceTableSize;
		if (eNotificationRequired())
			eNotify(new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.TRUST_CENTER__DEVICE_TABLE_SIZE, oldDeviceTableSize, deviceTableSize));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public TCKey getKeys() {
		return keys;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public NotificationChain basicSetKeys(TCKey newKeys, NotificationChain msgs) {
		TCKey oldKeys = keys;
		keys = newKeys;
		if (eNotificationRequired()) {
			ENotificationImpl notification = new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.TRUST_CENTER__KEYS, oldKeys, newKeys);
			if (msgs == null) msgs = notification; else msgs.add(notification);
		}
		return msgs;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void setKeys(TCKey newKeys) {
		if (newKeys != keys) {
			NotificationChain msgs = null;
			if (keys != null)
				msgs = ((InternalEObject)keys).eInverseRemove(this, EOPPOSITE_FEATURE_BASE - ZPSConfigurationPackage.TRUST_CENTER__KEYS, null, msgs);
			if (newKeys != null)
				msgs = ((InternalEObject)newKeys).eInverseAdd(this, EOPPOSITE_FEATURE_BASE - ZPSConfigurationPackage.TRUST_CENTER__KEYS, null, msgs);
			msgs = basicSetKeys(newKeys, msgs);
			if (msgs != null) msgs.dispatch();
		}
		else if (eNotificationRequired())
			eNotify(new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.TRUST_CENTER__KEYS, newKeys, newKeys));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	@Override
	public NotificationChain eInverseRemove(InternalEObject otherEnd, int featureID, NotificationChain msgs) {
		switch (featureID) {
			case ZPSConfigurationPackage.TRUST_CENTER__KEYS:
				return basicSetKeys(null, msgs);
		}
		return super.eInverseRemove(otherEnd, featureID, msgs);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	@Override
	public Object eGet(int featureID, boolean resolve, boolean coreType) {
		switch (featureID) {
			case ZPSConfigurationPackage.TRUST_CENTER__DEVICE_TABLE_SIZE:
				return getDeviceTableSize();
			case ZPSConfigurationPackage.TRUST_CENTER__KEYS:
				return getKeys();
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
			case ZPSConfigurationPackage.TRUST_CENTER__DEVICE_TABLE_SIZE:
				setDeviceTableSize((Integer)newValue);
				return;
			case ZPSConfigurationPackage.TRUST_CENTER__KEYS:
				setKeys((TCKey)newValue);
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
			case ZPSConfigurationPackage.TRUST_CENTER__DEVICE_TABLE_SIZE:
				setDeviceTableSize(DEVICE_TABLE_SIZE_EDEFAULT);
				return;
			case ZPSConfigurationPackage.TRUST_CENTER__KEYS:
				setKeys((TCKey)null);
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
			case ZPSConfigurationPackage.TRUST_CENTER__DEVICE_TABLE_SIZE:
				return deviceTableSize != DEVICE_TABLE_SIZE_EDEFAULT;
			case ZPSConfigurationPackage.TRUST_CENTER__KEYS:
				return keys != null;
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
		result.append(" (DeviceTableSize: ");
		result.append(deviceTableSize);
		result.append(')');
		return result.toString();
	}

} //TrustCenterImpl
