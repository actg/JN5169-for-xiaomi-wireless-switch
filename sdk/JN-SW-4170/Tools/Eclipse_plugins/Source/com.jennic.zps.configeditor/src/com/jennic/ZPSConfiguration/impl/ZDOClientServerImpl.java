/**
 * (C) Jennic Ltd
 *
 * $Id: ZDOClientServerImpl.java 78102 2016-03-24 15:35:29Z nxp29741 $
 */
package com.jennic.ZPSConfiguration.impl;


import org.eclipse.emf.common.notify.Notification;

import org.eclipse.emf.ecore.EClass;
import org.eclipse.emf.ecore.InternalEObject;

import org.eclipse.emf.ecore.impl.ENotificationImpl;
import org.eclipse.emf.ecore.impl.EObjectImpl;

import com.jennic.ZPSConfiguration.APDU;
import com.jennic.ZPSConfiguration.ZDOClientServer;
import com.jennic.ZPSConfiguration.ZPSConfigurationPackage;

/**
 * <!-- begin-user-doc -->
 * An implementation of the model object '<em><b>ZDO Client Server</b></em>'.
 * <!-- end-user-doc -->
 * <p>
 * The following features are implemented:
 * <ul>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.ZDOClientServerImpl#getOutputAPdu <em>Output APdu</em>}</li>
 * </ul>
 * </p>
 *
 * @generated
 */
public abstract class ZDOClientServerImpl extends EObjectImpl implements ZDOClientServer {
	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public static final String copyright = "(C) NXP B.V";

	/**
	 * The cached value of the '{@link #getOutputAPdu() <em>Output APdu</em>}' reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getOutputAPdu()
	 * @generated
	 * @ordered
	 */
	protected APDU outputAPdu;

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	protected ZDOClientServerImpl() {
		super();
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	@Override
	protected EClass eStaticClass() {
		return ZPSConfigurationPackage.Literals.ZDO_CLIENT_SERVER;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public APDU getOutputAPdu() {
		if (outputAPdu != null && outputAPdu.eIsProxy()) {
			InternalEObject oldOutputAPdu = (InternalEObject)outputAPdu;
			outputAPdu = (APDU)eResolveProxy(oldOutputAPdu);
			if (outputAPdu != oldOutputAPdu) {
				if (eNotificationRequired())
					eNotify(new ENotificationImpl(this, Notification.RESOLVE, ZPSConfigurationPackage.ZDO_CLIENT_SERVER__OUTPUT_APDU, oldOutputAPdu, outputAPdu));
			}
		}
		return outputAPdu;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public APDU basicGetOutputAPdu() {
		return outputAPdu;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void setOutputAPdu(APDU newOutputAPdu) {
		APDU oldOutputAPdu = outputAPdu;
		outputAPdu = newOutputAPdu;
		if (eNotificationRequired())
			eNotify(new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.ZDO_CLIENT_SERVER__OUTPUT_APDU, oldOutputAPdu, outputAPdu));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	@Override
	public Object eGet(int featureID, boolean resolve, boolean coreType) {
		switch (featureID) {
			case ZPSConfigurationPackage.ZDO_CLIENT_SERVER__OUTPUT_APDU:
				if (resolve) return getOutputAPdu();
				return basicGetOutputAPdu();
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
			case ZPSConfigurationPackage.ZDO_CLIENT_SERVER__OUTPUT_APDU:
				setOutputAPdu((APDU)newValue);
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
			case ZPSConfigurationPackage.ZDO_CLIENT_SERVER__OUTPUT_APDU:
				setOutputAPdu((APDU)null);
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
			case ZPSConfigurationPackage.ZDO_CLIENT_SERVER__OUTPUT_APDU:
				return outputAPdu != null;
		}
		return super.eIsSet(featureID);
	}

} //ZDOClientServerImpl
