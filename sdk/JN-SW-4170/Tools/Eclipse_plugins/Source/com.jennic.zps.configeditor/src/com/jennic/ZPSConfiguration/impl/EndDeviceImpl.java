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
import com.jennic.ZPSConfiguration.EndDevice;
import com.jennic.ZPSConfiguration.NetworkSelectionTypes;
import com.jennic.ZPSConfiguration.ZDOServersEndDevice;
import com.jennic.ZPSConfiguration.ZPSConfigurationPackage;

/**
 * <!-- begin-user-doc -->
 * An implementation of the model object '<em><b>End Device</b></em>'.
 * <!-- end-user-doc -->
 * <p>
 * The following features are implemented:
 * <ul>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.EndDeviceImpl#getScanDuration <em>Scan Duration</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.EndDeviceImpl#getNetworkSelection <em>Network Selection</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.EndDeviceImpl#getZDOServers <em>ZDO Servers</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.EndDeviceImpl#getNumPollFailuresBeforeRejoin <em>Num Poll Failures Before Rejoin</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.EndDeviceImpl#isSleeping <em>Sleeping</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.EndDeviceImpl#getFragmentedTxPollPeriod <em>Fragmented Tx Poll Period</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.EndDeviceImpl#getFragmentedRxPollPeriod <em>Fragmented Rx Poll Period</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.EndDeviceImpl#getAPSPollPeriod <em>APS Poll Period</em>}</li>
 * </ul>
 * </p>
 *
 * @generated
 */
public class EndDeviceImpl extends NodeImpl implements EndDevice {
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
	protected ZDOServersEndDevice zdoServers;

	/**
	 * The default value of the '{@link #getNumPollFailuresBeforeRejoin() <em>Num Poll Failures Before Rejoin</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getNumPollFailuresBeforeRejoin()
	 * @generated
	 * @ordered
	 */
	protected static final int NUM_POLL_FAILURES_BEFORE_REJOIN_EDEFAULT = 3;

	/**
	 * The cached value of the '{@link #getNumPollFailuresBeforeRejoin() <em>Num Poll Failures Before Rejoin</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getNumPollFailuresBeforeRejoin()
	 * @generated
	 * @ordered
	 */
	protected int numPollFailuresBeforeRejoin = NUM_POLL_FAILURES_BEFORE_REJOIN_EDEFAULT;

	/**
	 * The default value of the '{@link #isSleeping() <em>Sleeping</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #isSleeping()
	 * @generated
	 * @ordered
	 */
	protected static final boolean SLEEPING_EDEFAULT = false;

	/**
	 * The cached value of the '{@link #isSleeping() <em>Sleeping</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #isSleeping()
	 * @generated
	 * @ordered
	 */
	protected boolean sleeping = SLEEPING_EDEFAULT;

	/**
	 * The default value of the '{@link #getFragmentedTxPollPeriod() <em>Fragmented Tx Poll Period</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getFragmentedTxPollPeriod()
	 * @generated
	 * @ordered
	 */
	protected static final int FRAGMENTED_TX_POLL_PERIOD_EDEFAULT = 25;

	/**
	 * The cached value of the '{@link #getFragmentedTxPollPeriod() <em>Fragmented Tx Poll Period</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getFragmentedTxPollPeriod()
	 * @generated
	 * @ordered
	 */
	protected int fragmentedTxPollPeriod = FRAGMENTED_TX_POLL_PERIOD_EDEFAULT;

	/**
	 * The default value of the '{@link #getFragmentedRxPollPeriod() <em>Fragmented Rx Poll Period</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getFragmentedRxPollPeriod()
	 * @generated
	 * @ordered
	 */
	protected static final int FRAGMENTED_RX_POLL_PERIOD_EDEFAULT = 25;

	/**
	 * The cached value of the '{@link #getFragmentedRxPollPeriod() <em>Fragmented Rx Poll Period</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getFragmentedRxPollPeriod()
	 * @generated
	 * @ordered
	 */
	protected int fragmentedRxPollPeriod = FRAGMENTED_RX_POLL_PERIOD_EDEFAULT;

	/**
	 * The default value of the '{@link #getAPSPollPeriod() <em>APS Poll Period</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getAPSPollPeriod()
	 * @generated
	 * @ordered
	 */
	protected static final int APS_POLL_PERIOD_EDEFAULT = 100;

	/**
	 * The cached value of the '{@link #getAPSPollPeriod() <em>APS Poll Period</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getAPSPollPeriod()
	 * @generated
	 * @ordered
	 */
	protected int apsPollPeriod = APS_POLL_PERIOD_EDEFAULT;

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	protected EndDeviceImpl() {
		super();
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	@Override
	protected EClass eStaticClass() {
		return ZPSConfigurationPackage.Literals.END_DEVICE;
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
			eNotify(new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.END_DEVICE__SCAN_DURATION, oldScanDuration, scanDuration));
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
			eNotify(new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.END_DEVICE__NETWORK_SELECTION, oldNetworkSelection, networkSelection));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public ZDOServersEndDevice getZDOServers() {
		return zdoServers;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public NotificationChain basicSetZDOServers(ZDOServersEndDevice newZDOServers, NotificationChain msgs) {
		ZDOServersEndDevice oldZDOServers = zdoServers;
		zdoServers = newZDOServers;
		if (eNotificationRequired()) {
			ENotificationImpl notification = new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.END_DEVICE__ZDO_SERVERS, oldZDOServers, newZDOServers);
			if (msgs == null) msgs = notification; else msgs.add(notification);
		}
		return msgs;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void setZDOServers(ZDOServersEndDevice newZDOServers) {
		if (newZDOServers != zdoServers) {
			NotificationChain msgs = null;
			if (zdoServers != null)
				msgs = ((InternalEObject)zdoServers).eInverseRemove(this, EOPPOSITE_FEATURE_BASE - ZPSConfigurationPackage.END_DEVICE__ZDO_SERVERS, null, msgs);
			if (newZDOServers != null)
				msgs = ((InternalEObject)newZDOServers).eInverseAdd(this, EOPPOSITE_FEATURE_BASE - ZPSConfigurationPackage.END_DEVICE__ZDO_SERVERS, null, msgs);
			msgs = basicSetZDOServers(newZDOServers, msgs);
			if (msgs != null) msgs.dispatch();
		}
		else if (eNotificationRequired())
			eNotify(new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.END_DEVICE__ZDO_SERVERS, newZDOServers, newZDOServers));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public int getNumPollFailuresBeforeRejoin() {
		return numPollFailuresBeforeRejoin;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void setNumPollFailuresBeforeRejoin(int newNumPollFailuresBeforeRejoin) {
		int oldNumPollFailuresBeforeRejoin = numPollFailuresBeforeRejoin;
		numPollFailuresBeforeRejoin = newNumPollFailuresBeforeRejoin;
		if (eNotificationRequired())
			eNotify(new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.END_DEVICE__NUM_POLL_FAILURES_BEFORE_REJOIN, oldNumPollFailuresBeforeRejoin, numPollFailuresBeforeRejoin));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public boolean isSleeping() {
		return sleeping;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void setSleeping(boolean newSleeping) {
		boolean oldSleeping = sleeping;
		sleeping = newSleeping;
		if (eNotificationRequired())
			eNotify(new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.END_DEVICE__SLEEPING, oldSleeping, sleeping));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public int getFragmentedTxPollPeriod() {
		return fragmentedTxPollPeriod;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void setFragmentedTxPollPeriod(int newFragmentedTxPollPeriod) {
		int oldFragmentedTxPollPeriod = fragmentedTxPollPeriod;
		fragmentedTxPollPeriod = newFragmentedTxPollPeriod;
		if (eNotificationRequired())
			eNotify(new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.END_DEVICE__FRAGMENTED_TX_POLL_PERIOD, oldFragmentedTxPollPeriod, fragmentedTxPollPeriod));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public int getFragmentedRxPollPeriod() {
		return fragmentedRxPollPeriod;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void setFragmentedRxPollPeriod(int newFragmentedRxPollPeriod) {
		int oldFragmentedRxPollPeriod = fragmentedRxPollPeriod;
		fragmentedRxPollPeriod = newFragmentedRxPollPeriod;
		if (eNotificationRequired())
			eNotify(new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.END_DEVICE__FRAGMENTED_RX_POLL_PERIOD, oldFragmentedRxPollPeriod, fragmentedRxPollPeriod));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public int getAPSPollPeriod() {
		return apsPollPeriod;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void setAPSPollPeriod(int newAPSPollPeriod) {
		int oldAPSPollPeriod = apsPollPeriod;
		apsPollPeriod = newAPSPollPeriod;
		if (eNotificationRequired())
			eNotify(new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.END_DEVICE__APS_POLL_PERIOD, oldAPSPollPeriod, apsPollPeriod));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	@Override
	public NotificationChain eInverseRemove(InternalEObject otherEnd, int featureID, NotificationChain msgs) {
		switch (featureID) {
			case ZPSConfigurationPackage.END_DEVICE__ZDO_SERVERS:
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
			case ZPSConfigurationPackage.END_DEVICE__SCAN_DURATION:
				return getScanDuration();
			case ZPSConfigurationPackage.END_DEVICE__NETWORK_SELECTION:
				return getNetworkSelection();
			case ZPSConfigurationPackage.END_DEVICE__ZDO_SERVERS:
				return getZDOServers();
			case ZPSConfigurationPackage.END_DEVICE__NUM_POLL_FAILURES_BEFORE_REJOIN:
				return getNumPollFailuresBeforeRejoin();
			case ZPSConfigurationPackage.END_DEVICE__SLEEPING:
				return isSleeping();
			case ZPSConfigurationPackage.END_DEVICE__FRAGMENTED_TX_POLL_PERIOD:
				return getFragmentedTxPollPeriod();
			case ZPSConfigurationPackage.END_DEVICE__FRAGMENTED_RX_POLL_PERIOD:
				return getFragmentedRxPollPeriod();
			case ZPSConfigurationPackage.END_DEVICE__APS_POLL_PERIOD:
				return getAPSPollPeriod();
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
			case ZPSConfigurationPackage.END_DEVICE__SCAN_DURATION:
				setScanDuration((Byte)newValue);
				return;
			case ZPSConfigurationPackage.END_DEVICE__NETWORK_SELECTION:
				setNetworkSelection((NetworkSelectionTypes)newValue);
				return;
			case ZPSConfigurationPackage.END_DEVICE__ZDO_SERVERS:
				setZDOServers((ZDOServersEndDevice)newValue);
				return;
			case ZPSConfigurationPackage.END_DEVICE__NUM_POLL_FAILURES_BEFORE_REJOIN:
				setNumPollFailuresBeforeRejoin((Integer)newValue);
				return;
			case ZPSConfigurationPackage.END_DEVICE__SLEEPING:
				setSleeping((Boolean)newValue);
				return;
			case ZPSConfigurationPackage.END_DEVICE__FRAGMENTED_TX_POLL_PERIOD:
				setFragmentedTxPollPeriod((Integer)newValue);
				return;
			case ZPSConfigurationPackage.END_DEVICE__FRAGMENTED_RX_POLL_PERIOD:
				setFragmentedRxPollPeriod((Integer)newValue);
				return;
			case ZPSConfigurationPackage.END_DEVICE__APS_POLL_PERIOD:
				setAPSPollPeriod((Integer)newValue);
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
			case ZPSConfigurationPackage.END_DEVICE__SCAN_DURATION:
				setScanDuration(SCAN_DURATION_EDEFAULT);
				return;
			case ZPSConfigurationPackage.END_DEVICE__NETWORK_SELECTION:
				setNetworkSelection(NETWORK_SELECTION_EDEFAULT);
				return;
			case ZPSConfigurationPackage.END_DEVICE__ZDO_SERVERS:
				setZDOServers((ZDOServersEndDevice)null);
				return;
			case ZPSConfigurationPackage.END_DEVICE__NUM_POLL_FAILURES_BEFORE_REJOIN:
				setNumPollFailuresBeforeRejoin(NUM_POLL_FAILURES_BEFORE_REJOIN_EDEFAULT);
				return;
			case ZPSConfigurationPackage.END_DEVICE__SLEEPING:
				setSleeping(SLEEPING_EDEFAULT);
				return;
			case ZPSConfigurationPackage.END_DEVICE__FRAGMENTED_TX_POLL_PERIOD:
				setFragmentedTxPollPeriod(FRAGMENTED_TX_POLL_PERIOD_EDEFAULT);
				return;
			case ZPSConfigurationPackage.END_DEVICE__FRAGMENTED_RX_POLL_PERIOD:
				setFragmentedRxPollPeriod(FRAGMENTED_RX_POLL_PERIOD_EDEFAULT);
				return;
			case ZPSConfigurationPackage.END_DEVICE__APS_POLL_PERIOD:
				setAPSPollPeriod(APS_POLL_PERIOD_EDEFAULT);
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
			case ZPSConfigurationPackage.END_DEVICE__SCAN_DURATION:
				return scanDuration != SCAN_DURATION_EDEFAULT;
			case ZPSConfigurationPackage.END_DEVICE__NETWORK_SELECTION:
				return networkSelection != NETWORK_SELECTION_EDEFAULT;
			case ZPSConfigurationPackage.END_DEVICE__ZDO_SERVERS:
				return zdoServers != null;
			case ZPSConfigurationPackage.END_DEVICE__NUM_POLL_FAILURES_BEFORE_REJOIN:
				return numPollFailuresBeforeRejoin != NUM_POLL_FAILURES_BEFORE_REJOIN_EDEFAULT;
			case ZPSConfigurationPackage.END_DEVICE__SLEEPING:
				return sleeping != SLEEPING_EDEFAULT;
			case ZPSConfigurationPackage.END_DEVICE__FRAGMENTED_TX_POLL_PERIOD:
				return fragmentedTxPollPeriod != FRAGMENTED_TX_POLL_PERIOD_EDEFAULT;
			case ZPSConfigurationPackage.END_DEVICE__FRAGMENTED_RX_POLL_PERIOD:
				return fragmentedRxPollPeriod != FRAGMENTED_RX_POLL_PERIOD_EDEFAULT;
			case ZPSConfigurationPackage.END_DEVICE__APS_POLL_PERIOD:
				return apsPollPeriod != APS_POLL_PERIOD_EDEFAULT;
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
				case ZPSConfigurationPackage.END_DEVICE__SCAN_DURATION: return ZPSConfigurationPackage.CHILD_NODES__SCAN_DURATION;
				case ZPSConfigurationPackage.END_DEVICE__NETWORK_SELECTION: return ZPSConfigurationPackage.CHILD_NODES__NETWORK_SELECTION;
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
				case ZPSConfigurationPackage.CHILD_NODES__SCAN_DURATION: return ZPSConfigurationPackage.END_DEVICE__SCAN_DURATION;
				case ZPSConfigurationPackage.CHILD_NODES__NETWORK_SELECTION: return ZPSConfigurationPackage.END_DEVICE__NETWORK_SELECTION;
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
		result.append(", NumPollFailuresBeforeRejoin: ");
		result.append(numPollFailuresBeforeRejoin);
		result.append(", Sleeping: ");
		result.append(sleeping);
		result.append(", FragmentedTxPollPeriod: ");
		result.append(fragmentedTxPollPeriod);
		result.append(", FragmentedRxPollPeriod: ");
		result.append(fragmentedRxPollPeriod);
		result.append(", APSPollPeriod: ");
		result.append(apsPollPeriod);
		result.append(')');
		return result.toString();
	}

} //EndDeviceImpl
