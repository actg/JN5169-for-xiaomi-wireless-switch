/**
 * (C) Jennic Ltd
 *
 * $Id$
 */
package com.jennic.ZPSConfiguration.impl;


import org.eclipse.emf.common.notify.Notification;
import org.eclipse.emf.common.notify.NotificationChain;

import org.eclipse.emf.ecore.EClass;
import org.eclipse.emf.ecore.InternalEObject;

import org.eclipse.emf.ecore.impl.ENotificationImpl;

import com.jennic.ZPSConfiguration.Coordinator;
import com.jennic.ZPSConfiguration.ZDOServersCoordinator;
import com.jennic.ZPSConfiguration.ZPSConfigurationPackage;

/**
 * <!-- begin-user-doc -->
 * An implementation of the model object '<em><b>Coordinator</b></em>'.
 * <!-- end-user-doc -->
 * <p>
 * The following features are implemented:
 * <ul>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.CoordinatorImpl#getZDOServers <em>ZDO Servers</em>}</li>
 * </ul>
 * </p>
 *
 * @generated
 */
public class CoordinatorImpl extends AlwaysOnNodeImpl implements Coordinator {
	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public static final String copyright = "(C) NXP B.V";

	/**
	 * The cached value of the '{@link #getZDOServers() <em>ZDO Servers</em>}' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getZDOServers()
	 * @generated
	 * @ordered
	 */
	protected ZDOServersCoordinator zdoServers;

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	protected CoordinatorImpl() {
		super();
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	@Override
	protected EClass eStaticClass() {
		return ZPSConfigurationPackage.Literals.COORDINATOR;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public ZDOServersCoordinator getZDOServers() {
		return zdoServers;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public NotificationChain basicSetZDOServers(ZDOServersCoordinator newZDOServers, NotificationChain msgs) {
		ZDOServersCoordinator oldZDOServers = zdoServers;
		zdoServers = newZDOServers;
		if (eNotificationRequired()) {
			ENotificationImpl notification = new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.COORDINATOR__ZDO_SERVERS, oldZDOServers, newZDOServers);
			if (msgs == null) msgs = notification; else msgs.add(notification);
		}
		return msgs;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void setZDOServers(ZDOServersCoordinator newZDOServers) {
		if (newZDOServers != zdoServers) {
			NotificationChain msgs = null;
			if (zdoServers != null)
				msgs = ((InternalEObject)zdoServers).eInverseRemove(this, EOPPOSITE_FEATURE_BASE - ZPSConfigurationPackage.COORDINATOR__ZDO_SERVERS, null, msgs);
			if (newZDOServers != null)
				msgs = ((InternalEObject)newZDOServers).eInverseAdd(this, EOPPOSITE_FEATURE_BASE - ZPSConfigurationPackage.COORDINATOR__ZDO_SERVERS, null, msgs);
			msgs = basicSetZDOServers(newZDOServers, msgs);
			if (msgs != null) msgs.dispatch();
		}
		else if (eNotificationRequired())
			eNotify(new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.COORDINATOR__ZDO_SERVERS, newZDOServers, newZDOServers));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	@Override
	public NotificationChain eInverseRemove(InternalEObject otherEnd, int featureID, NotificationChain msgs) {
		switch (featureID) {
			case ZPSConfigurationPackage.COORDINATOR__ZDO_SERVERS:
				return basicSetZDOServers(null, msgs);
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
			case ZPSConfigurationPackage.COORDINATOR__ZDO_SERVERS:
				return getZDOServers();
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
			case ZPSConfigurationPackage.COORDINATOR__ZDO_SERVERS:
				setZDOServers((ZDOServersCoordinator)newValue);
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
			case ZPSConfigurationPackage.COORDINATOR__ZDO_SERVERS:
				setZDOServers((ZDOServersCoordinator)null);
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
			case ZPSConfigurationPackage.COORDINATOR__ZDO_SERVERS:
				return zdoServers != null;
		}
		return super.eIsSet(featureID);
	}

} //CoordinatorImpl
