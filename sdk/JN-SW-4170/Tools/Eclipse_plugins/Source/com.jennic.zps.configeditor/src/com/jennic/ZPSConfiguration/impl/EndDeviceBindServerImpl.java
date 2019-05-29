/**
 * (C) Jennic Ltd
 *
 * $Id$
 */
package com.jennic.ZPSConfiguration.impl;


import org.eclipse.emf.common.notify.Notification;

import org.eclipse.emf.ecore.EClass;

import org.eclipse.emf.ecore.impl.ENotificationImpl;

import com.jennic.ZPSConfiguration.EndDeviceBindServer;
import com.jennic.ZPSConfiguration.ZPSConfigurationPackage;

/**
 * <!-- begin-user-doc -->
 * An implementation of the model object '<em><b>End Device Bind Server</b></em>'.
 * <!-- end-user-doc -->
 * <p>
 * The following features are implemented:
 * <ul>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.EndDeviceBindServerImpl#getTimeout <em>Timeout</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.EndDeviceBindServerImpl#getBindingTimeout <em>Binding Timeout</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.EndDeviceBindServerImpl#getBindNumRetries <em>Bind Num Retries</em>}</li>
 * </ul>
 * </p>
 *
 * @generated
 */
public class EndDeviceBindServerImpl extends ZDOClientServerImpl implements EndDeviceBindServer {
	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public static final String copyright = "(C) NXP B.V";

	/**
	 * The default value of the '{@link #getTimeout() <em>Timeout</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getTimeout()
	 * @generated
	 * @ordered
	 */
	protected static final int TIMEOUT_EDEFAULT = 5;

	/**
	 * The cached value of the '{@link #getTimeout() <em>Timeout</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getTimeout()
	 * @generated
	 * @ordered
	 */
	protected int timeout = TIMEOUT_EDEFAULT;

	/**
	 * The default value of the '{@link #getBindingTimeout() <em>Binding Timeout</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getBindingTimeout()
	 * @generated
	 * @ordered
	 */
	protected static final int BINDING_TIMEOUT_EDEFAULT = 10;

	/**
	 * The cached value of the '{@link #getBindingTimeout() <em>Binding Timeout</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getBindingTimeout()
	 * @generated
	 * @ordered
	 */
	protected int bindingTimeout = BINDING_TIMEOUT_EDEFAULT;

	/**
	 * The default value of the '{@link #getBindNumRetries() <em>Bind Num Retries</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getBindNumRetries()
	 * @generated
	 * @ordered
	 */
	protected static final int BIND_NUM_RETRIES_EDEFAULT = 3;

	/**
	 * The cached value of the '{@link #getBindNumRetries() <em>Bind Num Retries</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getBindNumRetries()
	 * @generated
	 * @ordered
	 */
	protected int bindNumRetries = BIND_NUM_RETRIES_EDEFAULT;

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	protected EndDeviceBindServerImpl() {
		super();
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	@Override
	protected EClass eStaticClass() {
		return ZPSConfigurationPackage.Literals.END_DEVICE_BIND_SERVER;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public int getTimeout() {
		return timeout;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void setTimeout(int newTimeout) {
		int oldTimeout = timeout;
		timeout = newTimeout;
		if (eNotificationRequired())
			eNotify(new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.END_DEVICE_BIND_SERVER__TIMEOUT, oldTimeout, timeout));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public int getBindingTimeout() {
		return bindingTimeout;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void setBindingTimeout(int newBindingTimeout) {
		int oldBindingTimeout = bindingTimeout;
		bindingTimeout = newBindingTimeout;
		if (eNotificationRequired())
			eNotify(new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.END_DEVICE_BIND_SERVER__BINDING_TIMEOUT, oldBindingTimeout, bindingTimeout));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public int getBindNumRetries() {
		return bindNumRetries;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void setBindNumRetries(int newBindNumRetries) {
		int oldBindNumRetries = bindNumRetries;
		bindNumRetries = newBindNumRetries;
		if (eNotificationRequired())
			eNotify(new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.END_DEVICE_BIND_SERVER__BIND_NUM_RETRIES, oldBindNumRetries, bindNumRetries));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	@Override
	public Object eGet(int featureID, boolean resolve, boolean coreType) {
		switch (featureID) {
			case ZPSConfigurationPackage.END_DEVICE_BIND_SERVER__TIMEOUT:
				return getTimeout();
			case ZPSConfigurationPackage.END_DEVICE_BIND_SERVER__BINDING_TIMEOUT:
				return getBindingTimeout();
			case ZPSConfigurationPackage.END_DEVICE_BIND_SERVER__BIND_NUM_RETRIES:
				return getBindNumRetries();
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
			case ZPSConfigurationPackage.END_DEVICE_BIND_SERVER__TIMEOUT:
				setTimeout((Integer)newValue);
				return;
			case ZPSConfigurationPackage.END_DEVICE_BIND_SERVER__BINDING_TIMEOUT:
				setBindingTimeout((Integer)newValue);
				return;
			case ZPSConfigurationPackage.END_DEVICE_BIND_SERVER__BIND_NUM_RETRIES:
				setBindNumRetries((Integer)newValue);
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
			case ZPSConfigurationPackage.END_DEVICE_BIND_SERVER__TIMEOUT:
				setTimeout(TIMEOUT_EDEFAULT);
				return;
			case ZPSConfigurationPackage.END_DEVICE_BIND_SERVER__BINDING_TIMEOUT:
				setBindingTimeout(BINDING_TIMEOUT_EDEFAULT);
				return;
			case ZPSConfigurationPackage.END_DEVICE_BIND_SERVER__BIND_NUM_RETRIES:
				setBindNumRetries(BIND_NUM_RETRIES_EDEFAULT);
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
			case ZPSConfigurationPackage.END_DEVICE_BIND_SERVER__TIMEOUT:
				return timeout != TIMEOUT_EDEFAULT;
			case ZPSConfigurationPackage.END_DEVICE_BIND_SERVER__BINDING_TIMEOUT:
				return bindingTimeout != BINDING_TIMEOUT_EDEFAULT;
			case ZPSConfigurationPackage.END_DEVICE_BIND_SERVER__BIND_NUM_RETRIES:
				return bindNumRetries != BIND_NUM_RETRIES_EDEFAULT;
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
		result.append(" (Timeout: ");
		result.append(timeout);
		result.append(", BindingTimeout: ");
		result.append(bindingTimeout);
		result.append(", BindNumRetries: ");
		result.append(bindNumRetries);
		result.append(')');
		return result.toString();
	}

} //EndDeviceBindServerImpl
