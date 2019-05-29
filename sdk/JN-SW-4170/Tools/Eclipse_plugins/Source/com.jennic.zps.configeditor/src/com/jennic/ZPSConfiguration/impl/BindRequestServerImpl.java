/**
 * (C) Jennic Ltd
 *
 * $Id$
 */
package com.jennic.ZPSConfiguration.impl;

import com.jennic.ZPSConfiguration.BindRequestServer;
import com.jennic.ZPSConfiguration.ZPSConfigurationFactory;
import com.jennic.ZPSConfiguration.ZPSConfigurationPackage;

import org.eclipse.emf.common.notify.Notification;

import org.eclipse.emf.ecore.EClass;

import org.eclipse.emf.ecore.impl.ENotificationImpl;

/**
 * <!-- begin-user-doc -->
 * An implementation of the model object '<em><b>Bind Request Server</b></em>'.
 * <!-- end-user-doc -->
 * <p>
 * The following features are implemented:
 * <ul>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.BindRequestServerImpl#getSimultaneousRequests <em>Simultaneous Requests</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.BindRequestServerImpl#getTimeInterval <em>Time Interval</em>}</li>
 * </ul>
 * </p>
 *
 * @generated
 */
public class BindRequestServerImpl extends ZDOClientServerImpl implements BindRequestServer {
	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public static final String copyright = "(C) NXP B.V";

	/**
	 * The default value of the '{@link #getSimultaneousRequests() <em>Simultaneous Requests</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getSimultaneousRequests()
	 * @generated
	 * @ordered
	 */
	protected static final Object SIMULTANEOUS_REQUESTS_EDEFAULT = (Object)ZPSConfigurationFactory.eINSTANCE.createFromString(ZPSConfigurationPackage.eINSTANCE.getEUShort(), "3");

	/**
	 * The cached value of the '{@link #getSimultaneousRequests() <em>Simultaneous Requests</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getSimultaneousRequests()
	 * @generated
	 * @ordered
	 */
	protected Object simultaneousRequests = SIMULTANEOUS_REQUESTS_EDEFAULT;

	/**
	 * The default value of the '{@link #getTimeInterval() <em>Time Interval</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getTimeInterval()
	 * @generated
	 * @ordered
	 */
	protected static final Object TIME_INTERVAL_EDEFAULT = (Object)ZPSConfigurationFactory.eINSTANCE.createFromString(ZPSConfigurationPackage.eINSTANCE.getEUShort(), "1");

	/**
	 * The cached value of the '{@link #getTimeInterval() <em>Time Interval</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getTimeInterval()
	 * @generated
	 * @ordered
	 */
	protected Object timeInterval = TIME_INTERVAL_EDEFAULT;

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	protected BindRequestServerImpl() {
		super();
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	@Override
	protected EClass eStaticClass() {
		return ZPSConfigurationPackage.Literals.BIND_REQUEST_SERVER;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public Object getSimultaneousRequests() {
		return simultaneousRequests;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void setSimultaneousRequests(Object newSimultaneousRequests) {
		Object oldSimultaneousRequests = simultaneousRequests;
		simultaneousRequests = newSimultaneousRequests;
		if (eNotificationRequired())
			eNotify(new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.BIND_REQUEST_SERVER__SIMULTANEOUS_REQUESTS, oldSimultaneousRequests, simultaneousRequests));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public Object getTimeInterval() {
		return timeInterval;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void setTimeInterval(Object newTimeInterval) {
		Object oldTimeInterval = timeInterval;
		timeInterval = newTimeInterval;
		if (eNotificationRequired())
			eNotify(new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.BIND_REQUEST_SERVER__TIME_INTERVAL, oldTimeInterval, timeInterval));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	@Override
	public Object eGet(int featureID, boolean resolve, boolean coreType) {
		switch (featureID) {
			case ZPSConfigurationPackage.BIND_REQUEST_SERVER__SIMULTANEOUS_REQUESTS:
				return getSimultaneousRequests();
			case ZPSConfigurationPackage.BIND_REQUEST_SERVER__TIME_INTERVAL:
				return getTimeInterval();
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
			case ZPSConfigurationPackage.BIND_REQUEST_SERVER__SIMULTANEOUS_REQUESTS:
				setSimultaneousRequests((Object)newValue);
				return;
			case ZPSConfigurationPackage.BIND_REQUEST_SERVER__TIME_INTERVAL:
				setTimeInterval((Object)newValue);
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
			case ZPSConfigurationPackage.BIND_REQUEST_SERVER__SIMULTANEOUS_REQUESTS:
				setSimultaneousRequests(SIMULTANEOUS_REQUESTS_EDEFAULT);
				return;
			case ZPSConfigurationPackage.BIND_REQUEST_SERVER__TIME_INTERVAL:
				setTimeInterval(TIME_INTERVAL_EDEFAULT);
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
			case ZPSConfigurationPackage.BIND_REQUEST_SERVER__SIMULTANEOUS_REQUESTS:
				return SIMULTANEOUS_REQUESTS_EDEFAULT == null ? simultaneousRequests != null : !SIMULTANEOUS_REQUESTS_EDEFAULT.equals(simultaneousRequests);
			case ZPSConfigurationPackage.BIND_REQUEST_SERVER__TIME_INTERVAL:
				return TIME_INTERVAL_EDEFAULT == null ? timeInterval != null : !TIME_INTERVAL_EDEFAULT.equals(timeInterval);
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
		result.append(" (SimultaneousRequests: ");
		result.append(simultaneousRequests);
		result.append(", TimeInterval: ");
		result.append(timeInterval);
		result.append(')');
		return result.toString();
	}

} //BindRequestServerImpl
