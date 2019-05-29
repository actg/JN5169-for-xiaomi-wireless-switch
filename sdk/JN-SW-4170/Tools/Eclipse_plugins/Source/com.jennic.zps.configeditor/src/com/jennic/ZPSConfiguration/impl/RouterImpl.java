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

import com.jennic.ZPSConfiguration.ChildNodes;
import com.jennic.ZPSConfiguration.NetworkSelectionTypes;
import com.jennic.ZPSConfiguration.Router;
import com.jennic.ZPSConfiguration.ZDOServersRouter;
import com.jennic.ZPSConfiguration.ZPSConfigurationPackage;

/**
 * <!-- begin-user-doc -->
 * An implementation of the model object '<em><b>Router</b></em>'.
 * <!-- end-user-doc -->
 * <p>
 * The following features are implemented:
 * <ul>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.RouterImpl#getScanDuration <em>Scan Duration</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.RouterImpl#getNetworkSelection <em>Network Selection</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.RouterImpl#getZDOServers <em>ZDO Servers</em>}</li>
 * </ul>
 * </p>
 *
 * @generated
 */
public class RouterImpl extends AlwaysOnNodeImpl implements Router {
	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public static final String copyright = "(C) NXP B.V";

	/**
	 * The default value of the '{@link #getScanDuration() <em>Scan Duration</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getScanDuration()
	 * @generated
	 * @ordered
	 */
	protected static final byte SCAN_DURATION_EDEFAULT = 0x03;

	/**
	 * The cached value of the '{@link #getScanDuration() <em>Scan Duration</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getScanDuration()
	 * @generated
	 * @ordered
	 */
	protected byte scanDuration = SCAN_DURATION_EDEFAULT;

	/**
	 * The default value of the '{@link #getNetworkSelection() <em>Network Selection</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getNetworkSelection()
	 * @generated
	 * @ordered
	 */
	protected static final NetworkSelectionTypes NETWORK_SELECTION_EDEFAULT = NetworkSelectionTypes.USER;

	/**
	 * The cached value of the '{@link #getNetworkSelection() <em>Network Selection</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getNetworkSelection()
	 * @generated
	 * @ordered
	 */
	protected NetworkSelectionTypes networkSelection = NETWORK_SELECTION_EDEFAULT;

	/**
	 * The cached value of the '{@link #getZDOServers() <em>ZDO Servers</em>}' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getZDOServers()
	 * @generated
	 * @ordered
	 */
	protected ZDOServersRouter zdoServers;

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	protected RouterImpl() {
		super();
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	@Override
	protected EClass eStaticClass() {
		return ZPSConfigurationPackage.Literals.ROUTER;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public byte getScanDuration() {
		return scanDuration;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void setScanDuration(byte newScanDuration) {
		byte oldScanDuration = scanDuration;
		scanDuration = newScanDuration;
		if (eNotificationRequired())
			eNotify(new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.ROUTER__SCAN_DURATION, oldScanDuration, scanDuration));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public NetworkSelectionTypes getNetworkSelection() {
		return networkSelection;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void setNetworkSelection(NetworkSelectionTypes newNetworkSelection) {
		NetworkSelectionTypes oldNetworkSelection = networkSelection;
		networkSelection = newNetworkSelection == null ? NETWORK_SELECTION_EDEFAULT : newNetworkSelection;
		if (eNotificationRequired())
			eNotify(new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.ROUTER__NETWORK_SELECTION, oldNetworkSelection, networkSelection));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public ZDOServersRouter getZDOServers() {
		return zdoServers;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public NotificationChain basicSetZDOServers(ZDOServersRouter newZDOServers, NotificationChain msgs) {
		ZDOServersRouter oldZDOServers = zdoServers;
		zdoServers = newZDOServers;
		if (eNotificationRequired()) {
			ENotificationImpl notification = new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.ROUTER__ZDO_SERVERS, oldZDOServers, newZDOServers);
			if (msgs == null) msgs = notification; else msgs.add(notification);
		}
		return msgs;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void setZDOServers(ZDOServersRouter newZDOServers) {
		if (newZDOServers != zdoServers) {
			NotificationChain msgs = null;
			if (zdoServers != null)
				msgs = ((InternalEObject)zdoServers).eInverseRemove(this, EOPPOSITE_FEATURE_BASE - ZPSConfigurationPackage.ROUTER__ZDO_SERVERS, null, msgs);
			if (newZDOServers != null)
				msgs = ((InternalEObject)newZDOServers).eInverseAdd(this, EOPPOSITE_FEATURE_BASE - ZPSConfigurationPackage.ROUTER__ZDO_SERVERS, null, msgs);
			msgs = basicSetZDOServers(newZDOServers, msgs);
			if (msgs != null) msgs.dispatch();
		}
		else if (eNotificationRequired())
			eNotify(new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.ROUTER__ZDO_SERVERS, newZDOServers, newZDOServers));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	@Override
	public NotificationChain eInverseRemove(InternalEObject otherEnd, int featureID, NotificationChain msgs) {
		switch (featureID) {
			case ZPSConfigurationPackage.ROUTER__ZDO_SERVERS:
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
			case ZPSConfigurationPackage.ROUTER__SCAN_DURATION:
				return getScanDuration();
			case ZPSConfigurationPackage.ROUTER__NETWORK_SELECTION:
				return getNetworkSelection();
			case ZPSConfigurationPackage.ROUTER__ZDO_SERVERS:
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
			case ZPSConfigurationPackage.ROUTER__SCAN_DURATION:
				setScanDuration((Byte)newValue);
				return;
			case ZPSConfigurationPackage.ROUTER__NETWORK_SELECTION:
				setNetworkSelection((NetworkSelectionTypes)newValue);
				return;
			case ZPSConfigurationPackage.ROUTER__ZDO_SERVERS:
				setZDOServers((ZDOServersRouter)newValue);
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
			case ZPSConfigurationPackage.ROUTER__SCAN_DURATION:
				setScanDuration(SCAN_DURATION_EDEFAULT);
				return;
			case ZPSConfigurationPackage.ROUTER__NETWORK_SELECTION:
				setNetworkSelection(NETWORK_SELECTION_EDEFAULT);
				return;
			case ZPSConfigurationPackage.ROUTER__ZDO_SERVERS:
				setZDOServers((ZDOServersRouter)null);
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
			case ZPSConfigurationPackage.ROUTER__SCAN_DURATION:
				return scanDuration != SCAN_DURATION_EDEFAULT;
			case ZPSConfigurationPackage.ROUTER__NETWORK_SELECTION:
				return networkSelection != NETWORK_SELECTION_EDEFAULT;
			case ZPSConfigurationPackage.ROUTER__ZDO_SERVERS:
				return zdoServers != null;
		}
		return super.eIsSet(featureID);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	@Override
	public int eBaseStructuralFeatureID(int derivedFeatureID, Class<?> baseClass) {
		if (baseClass == ChildNodes.class) {
			switch (derivedFeatureID) {
				case ZPSConfigurationPackage.ROUTER__SCAN_DURATION: return ZPSConfigurationPackage.CHILD_NODES__SCAN_DURATION;
				case ZPSConfigurationPackage.ROUTER__NETWORK_SELECTION: return ZPSConfigurationPackage.CHILD_NODES__NETWORK_SELECTION;
				default: return -1;
			}
		}
		return super.eBaseStructuralFeatureID(derivedFeatureID, baseClass);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	@Override
	public int eDerivedStructuralFeatureID(int baseFeatureID, Class<?> baseClass) {
		if (baseClass == ChildNodes.class) {
			switch (baseFeatureID) {
				case ZPSConfigurationPackage.CHILD_NODES__SCAN_DURATION: return ZPSConfigurationPackage.ROUTER__SCAN_DURATION;
				case ZPSConfigurationPackage.CHILD_NODES__NETWORK_SELECTION: return ZPSConfigurationPackage.ROUTER__NETWORK_SELECTION;
				default: return -1;
			}
		}
		return super.eDerivedStructuralFeatureID(baseFeatureID, baseClass);
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
		result.append(" (ScanDuration: ");
		result.append(scanDuration);
		result.append(", NetworkSelection: ");
		result.append(networkSelection);
		result.append(')');
		return result.toString();
	}

} //RouterImpl
