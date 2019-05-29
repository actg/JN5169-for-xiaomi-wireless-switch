/**
 * (C) Jennic Ltd
 *
 * $Id: PreconfiguredKeyImpl.java 78102 2016-03-24 15:35:29Z nxp29741 $
 */
package com.jennic.ZPSConfiguration.impl;

import com.jennic.ZPSConfiguration.PreconfiguredKey;
import com.jennic.ZPSConfiguration.ZPSConfigurationFactory;
import com.jennic.ZPSConfiguration.ZPSConfigurationPackage;

import org.eclipse.emf.common.notify.Notification;

import org.eclipse.emf.ecore.EClass;

import org.eclipse.emf.ecore.impl.ENotificationImpl;
import org.eclipse.emf.ecore.impl.EObjectImpl;

/**
 * <!-- begin-user-doc -->
 * An implementation of the model object '<em><b>Preconfigured Key</b></em>'.
 * <!-- end-user-doc -->
 * <p>
 * The following features are implemented:
 * <ul>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.PreconfiguredKeyImpl#getKey <em>Key</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.PreconfiguredKeyImpl#getIEEEAddress <em>IEEE Address</em>}</li>
 * </ul>
 * </p>
 *
 * @generated
 */
public class PreconfiguredKeyImpl extends EObjectImpl implements PreconfiguredKey {
	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public static final String copyright = "(C) NXP B.V";

	/**
	 * The default value of the '{@link #getKey() <em>Key</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getKey()
	 * @generated
	 * @ordered
	 */
	protected static final Object KEY_EDEFAULT = (Object)ZPSConfigurationFactory.eINSTANCE.createFromString(ZPSConfigurationPackage.eINSTANCE.getESecKey(), "0");

	/**
	 * The cached value of the '{@link #getKey() <em>Key</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getKey()
	 * @generated
	 * @ordered
	 */
	protected Object key = KEY_EDEFAULT;

	/**
	 * The default value of the '{@link #getIEEEAddress() <em>IEEE Address</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getIEEEAddress()
	 * @generated
	 * @ordered
	 */
	protected static final Object IEEE_ADDRESS_EDEFAULT = (Object)ZPSConfigurationFactory.eINSTANCE.createFromString(ZPSConfigurationPackage.eINSTANCE.getEExtPANId(), "0");

	/**
	 * The cached value of the '{@link #getIEEEAddress() <em>IEEE Address</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getIEEEAddress()
	 * @generated
	 * @ordered
	 */
	protected Object ieeeAddress = IEEE_ADDRESS_EDEFAULT;

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	protected PreconfiguredKeyImpl() {
		super();
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	@Override
	protected EClass eStaticClass() {
		return ZPSConfigurationPackage.Literals.PRECONFIGURED_KEY;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public Object getKey() {
		return key;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void setKey(Object newKey) {
		Object oldKey = key;
		key = newKey;
		if (eNotificationRequired())
			eNotify(new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.PRECONFIGURED_KEY__KEY, oldKey, key));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public Object getIEEEAddress() {
		return ieeeAddress;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void setIEEEAddress(Object newIEEEAddress) {
		Object oldIEEEAddress = ieeeAddress;
		ieeeAddress = newIEEEAddress;
		if (eNotificationRequired())
			eNotify(new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.PRECONFIGURED_KEY__IEEE_ADDRESS, oldIEEEAddress, ieeeAddress));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	@Override
	public Object eGet(int featureID, boolean resolve, boolean coreType) {
		switch (featureID) {
			case ZPSConfigurationPackage.PRECONFIGURED_KEY__KEY:
				return getKey();
			case ZPSConfigurationPackage.PRECONFIGURED_KEY__IEEE_ADDRESS:
				return getIEEEAddress();
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
			case ZPSConfigurationPackage.PRECONFIGURED_KEY__KEY:
				setKey((Object)newValue);
				return;
			case ZPSConfigurationPackage.PRECONFIGURED_KEY__IEEE_ADDRESS:
				setIEEEAddress((Object)newValue);
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
			case ZPSConfigurationPackage.PRECONFIGURED_KEY__KEY:
				setKey(KEY_EDEFAULT);
				return;
			case ZPSConfigurationPackage.PRECONFIGURED_KEY__IEEE_ADDRESS:
				setIEEEAddress(IEEE_ADDRESS_EDEFAULT);
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
			case ZPSConfigurationPackage.PRECONFIGURED_KEY__KEY:
				return KEY_EDEFAULT == null ? key != null : !KEY_EDEFAULT.equals(key);
			case ZPSConfigurationPackage.PRECONFIGURED_KEY__IEEE_ADDRESS:
				return IEEE_ADDRESS_EDEFAULT == null ? ieeeAddress != null : !IEEE_ADDRESS_EDEFAULT.equals(ieeeAddress);
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
		result.append(" (Key: ");
		result.append(key);
		result.append(", IEEEAddress: ");
		result.append(ieeeAddress);
		result.append(')');
		return result.toString();
	}

} //PreconfiguredKeyImpl
