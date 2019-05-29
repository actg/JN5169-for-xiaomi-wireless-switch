/**
 * (C) Jennic Ltd
 *
 * $Id$
 */
package com.jennic.ZPSConfiguration.impl;


import org.eclipse.emf.common.notify.Notification;

import org.eclipse.emf.ecore.EClass;

import org.eclipse.emf.ecore.impl.ENotificationImpl;
import org.eclipse.emf.ecore.impl.EObjectImpl;

import com.jennic.ZPSConfiguration.ChildNodes;
import com.jennic.ZPSConfiguration.NetworkSelectionTypes;
import com.jennic.ZPSConfiguration.ZPSConfigurationPackage;

/**
 * <!-- begin-user-doc -->
 * An implementation of the model object '<em><b>Child Nodes</b></em>'.
 * <!-- end-user-doc -->
 * <p>
 * The following features are implemented:
 * <ul>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.ChildNodesImpl#getScanDuration <em>Scan Duration</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.ChildNodesImpl#getNetworkSelection <em>Network Selection</em>}</li>
 * </ul>
 * </p>
 *
 * @generated
 */
public abstract class ChildNodesImpl extends EObjectImpl implements ChildNodes {
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
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	protected ChildNodesImpl() {
		super();
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	@Override
	protected EClass eStaticClass() {
		return ZPSConfigurationPackage.Literals.CHILD_NODES;
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
			eNotify(new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.CHILD_NODES__SCAN_DURATION, oldScanDuration, scanDuration));
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
			eNotify(new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.CHILD_NODES__NETWORK_SELECTION, oldNetworkSelection, networkSelection));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	@Override
	public Object eGet(int featureID, boolean resolve, boolean coreType) {
		switch (featureID) {
			case ZPSConfigurationPackage.CHILD_NODES__SCAN_DURATION:
				return getScanDuration();
			case ZPSConfigurationPackage.CHILD_NODES__NETWORK_SELECTION:
				return getNetworkSelection();
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
			case ZPSConfigurationPackage.CHILD_NODES__SCAN_DURATION:
				setScanDuration((Byte)newValue);
				return;
			case ZPSConfigurationPackage.CHILD_NODES__NETWORK_SELECTION:
				setNetworkSelection((NetworkSelectionTypes)newValue);
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
			case ZPSConfigurationPackage.CHILD_NODES__SCAN_DURATION:
				setScanDuration(SCAN_DURATION_EDEFAULT);
				return;
			case ZPSConfigurationPackage.CHILD_NODES__NETWORK_SELECTION:
				setNetworkSelection(NETWORK_SELECTION_EDEFAULT);
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
			case ZPSConfigurationPackage.CHILD_NODES__SCAN_DURATION:
				return scanDuration != SCAN_DURATION_EDEFAULT;
			case ZPSConfigurationPackage.CHILD_NODES__NETWORK_SELECTION:
				return networkSelection != NETWORK_SELECTION_EDEFAULT;
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
		result.append(" (ScanDuration: ");
		result.append(scanDuration);
		result.append(", NetworkSelection: ");
		result.append(networkSelection);
		result.append(')');
		return result.toString();
	}

} //ChildNodesImpl
