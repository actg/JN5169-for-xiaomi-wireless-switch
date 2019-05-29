/**
 * (C) Jennic Ltd
 */
package com.jennic.ZPSConfiguration.impl;

import com.jennic.ZPSConfiguration.MacInterface;
import com.jennic.ZPSConfiguration.MacInterfaceList;
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
import org.eclipse.emf.ecore.util.EObjectResolvingEList;
import org.eclipse.emf.ecore.util.InternalEList;

/**
 * <!-- begin-user-doc -->
 * An implementation of the model object '<em><b>Mac Interface List</b></em>'.
 * <!-- end-user-doc -->
 * <p>
 * The following features are implemented:
 * <ul>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.MacInterfaceListImpl#getMacInterface <em>Mac Interface</em>}</li>
 * </ul>
 * </p>
 *
 * @generated
 */
public class MacInterfaceListImpl extends EObjectImpl implements MacInterfaceList {
	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public static final String copyright = "(C) NXP B.V";

	/**
	 * The cached value of the '{@link #getMacInterface() <em>Mac Interface</em>}' containment reference list.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getMacInterface()
	 * @generated
	 * @ordered
	 */
	protected EList<MacInterface> macInterface;

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	protected MacInterfaceListImpl() {
		super();
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	@Override
	protected EClass eStaticClass() {
		return ZPSConfigurationPackage.Literals.MAC_INTERFACE_LIST;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EList<MacInterface> getMacInterface() {
		if (macInterface == null) {
			macInterface = new EObjectContainmentEList<MacInterface>(MacInterface.class, this, ZPSConfigurationPackage.MAC_INTERFACE_LIST__MAC_INTERFACE);
		}
		return macInterface;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	@Override
	public NotificationChain eInverseRemove(InternalEObject otherEnd, int featureID, NotificationChain msgs) {
		switch (featureID) {
			case ZPSConfigurationPackage.MAC_INTERFACE_LIST__MAC_INTERFACE:
				return ((InternalEList<?>)getMacInterface()).basicRemove(otherEnd, msgs);
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
			case ZPSConfigurationPackage.MAC_INTERFACE_LIST__MAC_INTERFACE:
				return getMacInterface();
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
			case ZPSConfigurationPackage.MAC_INTERFACE_LIST__MAC_INTERFACE:
				getMacInterface().clear();
				getMacInterface().addAll((Collection<? extends MacInterface>)newValue);
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
			case ZPSConfigurationPackage.MAC_INTERFACE_LIST__MAC_INTERFACE:
				getMacInterface().clear();
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
			case ZPSConfigurationPackage.MAC_INTERFACE_LIST__MAC_INTERFACE:
				return macInterface != null && !macInterface.isEmpty();
		}
		return super.eIsSet(featureID);
	}

} //MacInterfaceListImpl
