/**
 * (C) Jennic Ltd
 *
 * $Id: NwkKeyImpl.java 78102 2016-03-24 15:35:29Z nxp29741 $
 */
package com.jennic.ZPSConfiguration.impl;

import com.jennic.ZPSConfiguration.Node;
import com.jennic.ZPSConfiguration.NwkKey;
import com.jennic.ZPSConfiguration.ZPSConfigurationFactory;
import com.jennic.ZPSConfiguration.ZPSConfigurationPackage;

import org.eclipse.emf.common.notify.Notification;
import org.eclipse.emf.ecore.EClass;

import org.eclipse.emf.ecore.impl.ENotificationImpl;

/**
 * <!-- begin-user-doc -->
 * An implementation of the model object '<em><b>Nwk Key</b></em>'.
 * <!-- end-user-doc -->
 * <p>
 * The following features are implemented:
 * <ul>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.NwkKeyImpl#getKeySequenceNumber <em>Key Sequence Number</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.NwkKeyImpl#getKey <em>Key</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.NwkKeyImpl#getId <em>Id</em>}</li>
 * </ul>
 * </p>
 *
 * @generated
 */
public abstract class NwkKeyImpl extends TCKeyImpl implements NwkKey {
	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public static final String copyright = "(C) NXP B.V";

	/**
	 * The default value of the '{@link #getKeySequenceNumber() <em>Key Sequence Number</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getKeySequenceNumber()
	 * @generated
	 * @ordered
	 */
	protected static final int KEY_SEQUENCE_NUMBER_EDEFAULT = 1;
	/**
	 * The cached value of the '{@link #getKeySequenceNumber() <em>Key Sequence Number</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getKeySequenceNumber()
	 * @generated
	 * @ordered
	 */
	protected int keySequenceNumber = KEY_SEQUENCE_NUMBER_EDEFAULT;
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
	 * The default value of the '{@link #getId() <em>Id</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getId()
	 * @generated
	 * @ordered
	 */
	protected static final String ID_EDEFAULT = null;

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	protected NwkKeyImpl() {
		super();
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	@Override
	protected EClass eStaticClass() {
		return ZPSConfigurationPackage.Literals.NWK_KEY;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public int getKeySequenceNumber() {
		return keySequenceNumber;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void setKeySequenceNumber(int newKeySequenceNumber) {
		int oldKeySequenceNumber = keySequenceNumber;
		keySequenceNumber = newKeySequenceNumber;
		if (eNotificationRequired())
			eNotify(new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.NWK_KEY__KEY_SEQUENCE_NUMBER, oldKeySequenceNumber, keySequenceNumber));
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
			eNotify(new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.NWK_KEY__KEY, oldKey, key));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated NOT
	 */
	public String getId() {
		Node node = (Node)(eContainer().eContainer());
		String id = node.getName();
				
		return id + "->" + eClass().getName();		
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated NOT
	 */
	public void setId(String newId) {
		/* nothing to do as generated but persisted */
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated NOT
	 */
	public void unsetId() {
		/* nothing to do as generated but persisted */
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated NOT
	 */
	public boolean isSetId() {
		/* always true as generated but persisted */
		return true;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	@Override
	public Object eGet(int featureID, boolean resolve, boolean coreType) {
		switch (featureID) {
			case ZPSConfigurationPackage.NWK_KEY__KEY_SEQUENCE_NUMBER:
				return getKeySequenceNumber();
			case ZPSConfigurationPackage.NWK_KEY__KEY:
				return getKey();
			case ZPSConfigurationPackage.NWK_KEY__ID:
				return getId();
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
			case ZPSConfigurationPackage.NWK_KEY__KEY_SEQUENCE_NUMBER:
				setKeySequenceNumber((Integer)newValue);
				return;
			case ZPSConfigurationPackage.NWK_KEY__KEY:
				setKey((Object)newValue);
				return;
			case ZPSConfigurationPackage.NWK_KEY__ID:
				setId((String)newValue);
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
			case ZPSConfigurationPackage.NWK_KEY__KEY_SEQUENCE_NUMBER:
				setKeySequenceNumber(KEY_SEQUENCE_NUMBER_EDEFAULT);
				return;
			case ZPSConfigurationPackage.NWK_KEY__KEY:
				setKey(KEY_EDEFAULT);
				return;
			case ZPSConfigurationPackage.NWK_KEY__ID:
				unsetId();
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
			case ZPSConfigurationPackage.NWK_KEY__KEY_SEQUENCE_NUMBER:
				return keySequenceNumber != KEY_SEQUENCE_NUMBER_EDEFAULT;
			case ZPSConfigurationPackage.NWK_KEY__KEY:
				return KEY_EDEFAULT == null ? key != null : !KEY_EDEFAULT.equals(key);
			case ZPSConfigurationPackage.NWK_KEY__ID:
				return isSetId();
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
		result.append(" (KeySequenceNumber: ");
		result.append(keySequenceNumber);
		result.append(", Key: ");
		result.append(key);
		result.append(')');
		return result.toString();
	}

} //NwkKeyImpl
