/**
 * (C) Jennic Ltd
 *
 * $Id: KeyDescriptorTableImpl.java 78102 2016-03-24 15:35:29Z nxp29741 $
 */
package com.jennic.ZPSConfiguration.impl;

import com.jennic.ZPSConfiguration.KeyDescriptorTable;
import com.jennic.ZPSConfiguration.PreconfiguredKey;
import com.jennic.ZPSConfiguration.ZPSConfigurationPackage;

import java.util.Collection;

import org.eclipse.emf.common.notify.Notification;
import org.eclipse.emf.common.notify.NotificationChain;

import org.eclipse.emf.common.util.EList;

import org.eclipse.emf.ecore.EClass;
import org.eclipse.emf.ecore.InternalEObject;

import org.eclipse.emf.ecore.impl.ENotificationImpl;
import org.eclipse.emf.ecore.impl.EObjectImpl;

import org.eclipse.emf.ecore.util.EObjectContainmentEList;
import org.eclipse.emf.ecore.util.InternalEList;

/**
 * <!-- begin-user-doc -->
 * An implementation of the model object '<em><b>Key Descriptor Table</b></em>'.
 * <!-- end-user-doc -->
 * <p>
 * The following features are implemented:
 * <ul>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.KeyDescriptorTableImpl#getSize <em>Size</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.KeyDescriptorTableImpl#getPreconfiguredKey <em>Preconfigured Key</em>}</li>
 * </ul>
 * </p>
 *
 * @generated
 */
public class KeyDescriptorTableImpl extends EObjectImpl implements KeyDescriptorTable {
	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public static final String copyright = "(C) NXP B.V";

	/**
	 * The default value of the '{@link #getSize() <em>Size</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getSize()
	 * @generated
	 * @ordered
	 */
	protected static final int SIZE_EDEFAULT = 8;

	/**
	 * The cached value of the '{@link #getSize() <em>Size</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getSize()
	 * @generated
	 * @ordered
	 */
	protected int size = SIZE_EDEFAULT;

	/**
	 * The cached value of the '{@link #getPreconfiguredKey() <em>Preconfigured Key</em>}' containment reference list.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getPreconfiguredKey()
	 * @generated
	 * @ordered
	 */
	protected EList<PreconfiguredKey> preconfiguredKey;

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	protected KeyDescriptorTableImpl() {
		super();
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	@Override
	protected EClass eStaticClass() {
		return ZPSConfigurationPackage.Literals.KEY_DESCRIPTOR_TABLE;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public int getSize() {
		return size;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated NOT
	 */
	public void setSize(int newSize) {
		
		if (null != preconfiguredKey && newSize < preconfiguredKey.size()) {
			throw new IllegalArgumentException("The table size cannot be less than the number of keys currently configured");
		}
		int oldSize = size;
		size = newSize;
		if (eNotificationRequired())
			eNotify(new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.KEY_DESCRIPTOR_TABLE__SIZE, oldSize, size));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EList<PreconfiguredKey> getPreconfiguredKey() {
		if (preconfiguredKey == null) {
			preconfiguredKey = new EObjectContainmentEList<PreconfiguredKey>(PreconfiguredKey.class, this, ZPSConfigurationPackage.KEY_DESCRIPTOR_TABLE__PRECONFIGURED_KEY);
		}
		return preconfiguredKey;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	@Override
	public NotificationChain eInverseRemove(InternalEObject otherEnd, int featureID, NotificationChain msgs) {
		switch (featureID) {
			case ZPSConfigurationPackage.KEY_DESCRIPTOR_TABLE__PRECONFIGURED_KEY:
				return ((InternalEList<?>)getPreconfiguredKey()).basicRemove(otherEnd, msgs);
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
			case ZPSConfigurationPackage.KEY_DESCRIPTOR_TABLE__SIZE:
				return getSize();
			case ZPSConfigurationPackage.KEY_DESCRIPTOR_TABLE__PRECONFIGURED_KEY:
				return getPreconfiguredKey();
		}
		return super.eGet(featureID, resolve, coreType);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	@SuppressWarnings("unchecked")
	@Override
	public void eSet(int featureID, Object newValue) {
		switch (featureID) {
			case ZPSConfigurationPackage.KEY_DESCRIPTOR_TABLE__SIZE:
				setSize((Integer)newValue);
				return;
			case ZPSConfigurationPackage.KEY_DESCRIPTOR_TABLE__PRECONFIGURED_KEY:
				getPreconfiguredKey().clear();
				getPreconfiguredKey().addAll((Collection<? extends PreconfiguredKey>)newValue);
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
			case ZPSConfigurationPackage.KEY_DESCRIPTOR_TABLE__SIZE:
				setSize(SIZE_EDEFAULT);
				return;
			case ZPSConfigurationPackage.KEY_DESCRIPTOR_TABLE__PRECONFIGURED_KEY:
				getPreconfiguredKey().clear();
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
			case ZPSConfigurationPackage.KEY_DESCRIPTOR_TABLE__SIZE:
				return size != SIZE_EDEFAULT;
			case ZPSConfigurationPackage.KEY_DESCRIPTOR_TABLE__PRECONFIGURED_KEY:
				return preconfiguredKey != null && !preconfiguredKey.isEmpty();
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
		result.append(" (Size: ");
		result.append(size);
		result.append(')');
		return result.toString();
	}

} //KeyDescriptorTableImpl
