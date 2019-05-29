/**
 * (C) Jennic Ltd
 *
 * $Id: NodePowerDescriptorImpl.java 78102 2016-03-24 15:35:29Z nxp29741 $
 */
package com.jennic.ZPSConfiguration.impl;


import org.eclipse.emf.common.notify.Notification;

import org.eclipse.emf.ecore.EClass;

import org.eclipse.emf.ecore.impl.ENotificationImpl;
import org.eclipse.emf.ecore.impl.EObjectImpl;

import com.jennic.ZPSConfiguration.NodePowerDescriptor;
import com.jennic.ZPSConfiguration.PowerModes;
import com.jennic.ZPSConfiguration.PowerSources;
import com.jennic.ZPSConfiguration.ZPSConfigurationPackage;

/**
 * <!-- begin-user-doc -->
 * An implementation of the model object '<em><b>Node Power Descriptor</b></em>'.
 * <!-- end-user-doc -->
 * <p>
 * The following features are implemented:
 * <ul>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.NodePowerDescriptorImpl#isConstantPower <em>Constant Power</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.NodePowerDescriptorImpl#isRechargeableBattery <em>Rechargeable Battery</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.NodePowerDescriptorImpl#isDisposableBattery <em>Disposable Battery</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.NodePowerDescriptorImpl#getDefaultPowerSource <em>Default Power Source</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.NodePowerDescriptorImpl#getDefaultPowerMode <em>Default Power Mode</em>}</li>
 * </ul>
 * </p>
 *
 * @generated
 */
public class NodePowerDescriptorImpl extends EObjectImpl implements NodePowerDescriptor {
	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public static final String copyright = "(C) NXP B.V";

	/**
	 * The default value of the '{@link #isConstantPower() <em>Constant Power</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #isConstantPower()
	 * @generated
	 * @ordered
	 */
	protected static final boolean CONSTANT_POWER_EDEFAULT = true;

	/**
	 * The cached value of the '{@link #isConstantPower() <em>Constant Power</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #isConstantPower()
	 * @generated
	 * @ordered
	 */
	protected boolean constantPower = CONSTANT_POWER_EDEFAULT;

	/**
	 * The default value of the '{@link #isRechargeableBattery() <em>Rechargeable Battery</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #isRechargeableBattery()
	 * @generated
	 * @ordered
	 */
	protected static final boolean RECHARGEABLE_BATTERY_EDEFAULT = false;

	/**
	 * The cached value of the '{@link #isRechargeableBattery() <em>Rechargeable Battery</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #isRechargeableBattery()
	 * @generated
	 * @ordered
	 */
	protected boolean rechargeableBattery = RECHARGEABLE_BATTERY_EDEFAULT;

	/**
	 * The default value of the '{@link #isDisposableBattery() <em>Disposable Battery</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #isDisposableBattery()
	 * @generated
	 * @ordered
	 */
	protected static final boolean DISPOSABLE_BATTERY_EDEFAULT = false;

	/**
	 * The cached value of the '{@link #isDisposableBattery() <em>Disposable Battery</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #isDisposableBattery()
	 * @generated
	 * @ordered
	 */
	protected boolean disposableBattery = DISPOSABLE_BATTERY_EDEFAULT;

	/**
	 * The default value of the '{@link #getDefaultPowerSource() <em>Default Power Source</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getDefaultPowerSource()
	 * @generated
	 * @ordered
	 */
	protected static final PowerSources DEFAULT_POWER_SOURCE_EDEFAULT = PowerSources.CONSTANT_POWER;

	/**
	 * The cached value of the '{@link #getDefaultPowerSource() <em>Default Power Source</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getDefaultPowerSource()
	 * @generated
	 * @ordered
	 */
	protected PowerSources defaultPowerSource = DEFAULT_POWER_SOURCE_EDEFAULT;

	/**
	 * The default value of the '{@link #getDefaultPowerMode() <em>Default Power Mode</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getDefaultPowerMode()
	 * @generated
	 * @ordered
	 */
	protected static final PowerModes DEFAULT_POWER_MODE_EDEFAULT = PowerModes.RX_ON_WHEN_IDLE_SYNC;

	/**
	 * The cached value of the '{@link #getDefaultPowerMode() <em>Default Power Mode</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getDefaultPowerMode()
	 * @generated
	 * @ordered
	 */
	protected PowerModes defaultPowerMode = DEFAULT_POWER_MODE_EDEFAULT;

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	protected NodePowerDescriptorImpl() {
		super();
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	@Override
	protected EClass eStaticClass() {
		return ZPSConfigurationPackage.Literals.NODE_POWER_DESCRIPTOR;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public boolean isConstantPower() {
		return constantPower;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void setConstantPower(boolean newConstantPower) {
		boolean oldConstantPower = constantPower;
		constantPower = newConstantPower;
		if (eNotificationRequired())
			eNotify(new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.NODE_POWER_DESCRIPTOR__CONSTANT_POWER, oldConstantPower, constantPower));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public boolean isRechargeableBattery() {
		return rechargeableBattery;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void setRechargeableBattery(boolean newRechargeableBattery) {
		boolean oldRechargeableBattery = rechargeableBattery;
		rechargeableBattery = newRechargeableBattery;
		if (eNotificationRequired())
			eNotify(new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.NODE_POWER_DESCRIPTOR__RECHARGEABLE_BATTERY, oldRechargeableBattery, rechargeableBattery));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public boolean isDisposableBattery() {
		return disposableBattery;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void setDisposableBattery(boolean newDisposableBattery) {
		boolean oldDisposableBattery = disposableBattery;
		disposableBattery = newDisposableBattery;
		if (eNotificationRequired())
			eNotify(new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.NODE_POWER_DESCRIPTOR__DISPOSABLE_BATTERY, oldDisposableBattery, disposableBattery));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public PowerSources getDefaultPowerSource() {
		return defaultPowerSource;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void setDefaultPowerSource(PowerSources newDefaultPowerSource) {
		PowerSources oldDefaultPowerSource = defaultPowerSource;
		defaultPowerSource = newDefaultPowerSource == null ? DEFAULT_POWER_SOURCE_EDEFAULT : newDefaultPowerSource;
		if (eNotificationRequired())
			eNotify(new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.NODE_POWER_DESCRIPTOR__DEFAULT_POWER_SOURCE, oldDefaultPowerSource, defaultPowerSource));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public PowerModes getDefaultPowerMode() {
		return defaultPowerMode;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void setDefaultPowerMode(PowerModes newDefaultPowerMode) {
		PowerModes oldDefaultPowerMode = defaultPowerMode;
		defaultPowerMode = newDefaultPowerMode == null ? DEFAULT_POWER_MODE_EDEFAULT : newDefaultPowerMode;
		if (eNotificationRequired())
			eNotify(new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.NODE_POWER_DESCRIPTOR__DEFAULT_POWER_MODE, oldDefaultPowerMode, defaultPowerMode));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	@Override
	public Object eGet(int featureID, boolean resolve, boolean coreType) {
		switch (featureID) {
			case ZPSConfigurationPackage.NODE_POWER_DESCRIPTOR__CONSTANT_POWER:
				return isConstantPower();
			case ZPSConfigurationPackage.NODE_POWER_DESCRIPTOR__RECHARGEABLE_BATTERY:
				return isRechargeableBattery();
			case ZPSConfigurationPackage.NODE_POWER_DESCRIPTOR__DISPOSABLE_BATTERY:
				return isDisposableBattery();
			case ZPSConfigurationPackage.NODE_POWER_DESCRIPTOR__DEFAULT_POWER_SOURCE:
				return getDefaultPowerSource();
			case ZPSConfigurationPackage.NODE_POWER_DESCRIPTOR__DEFAULT_POWER_MODE:
				return getDefaultPowerMode();
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
			case ZPSConfigurationPackage.NODE_POWER_DESCRIPTOR__CONSTANT_POWER:
				setConstantPower((Boolean)newValue);
				return;
			case ZPSConfigurationPackage.NODE_POWER_DESCRIPTOR__RECHARGEABLE_BATTERY:
				setRechargeableBattery((Boolean)newValue);
				return;
			case ZPSConfigurationPackage.NODE_POWER_DESCRIPTOR__DISPOSABLE_BATTERY:
				setDisposableBattery((Boolean)newValue);
				return;
			case ZPSConfigurationPackage.NODE_POWER_DESCRIPTOR__DEFAULT_POWER_SOURCE:
				setDefaultPowerSource((PowerSources)newValue);
				return;
			case ZPSConfigurationPackage.NODE_POWER_DESCRIPTOR__DEFAULT_POWER_MODE:
				setDefaultPowerMode((PowerModes)newValue);
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
			case ZPSConfigurationPackage.NODE_POWER_DESCRIPTOR__CONSTANT_POWER:
				setConstantPower(CONSTANT_POWER_EDEFAULT);
				return;
			case ZPSConfigurationPackage.NODE_POWER_DESCRIPTOR__RECHARGEABLE_BATTERY:
				setRechargeableBattery(RECHARGEABLE_BATTERY_EDEFAULT);
				return;
			case ZPSConfigurationPackage.NODE_POWER_DESCRIPTOR__DISPOSABLE_BATTERY:
				setDisposableBattery(DISPOSABLE_BATTERY_EDEFAULT);
				return;
			case ZPSConfigurationPackage.NODE_POWER_DESCRIPTOR__DEFAULT_POWER_SOURCE:
				setDefaultPowerSource(DEFAULT_POWER_SOURCE_EDEFAULT);
				return;
			case ZPSConfigurationPackage.NODE_POWER_DESCRIPTOR__DEFAULT_POWER_MODE:
				setDefaultPowerMode(DEFAULT_POWER_MODE_EDEFAULT);
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
			case ZPSConfigurationPackage.NODE_POWER_DESCRIPTOR__CONSTANT_POWER:
				return constantPower != CONSTANT_POWER_EDEFAULT;
			case ZPSConfigurationPackage.NODE_POWER_DESCRIPTOR__RECHARGEABLE_BATTERY:
				return rechargeableBattery != RECHARGEABLE_BATTERY_EDEFAULT;
			case ZPSConfigurationPackage.NODE_POWER_DESCRIPTOR__DISPOSABLE_BATTERY:
				return disposableBattery != DISPOSABLE_BATTERY_EDEFAULT;
			case ZPSConfigurationPackage.NODE_POWER_DESCRIPTOR__DEFAULT_POWER_SOURCE:
				return defaultPowerSource != DEFAULT_POWER_SOURCE_EDEFAULT;
			case ZPSConfigurationPackage.NODE_POWER_DESCRIPTOR__DEFAULT_POWER_MODE:
				return defaultPowerMode != DEFAULT_POWER_MODE_EDEFAULT;
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
		result.append(" (ConstantPower: ");
		result.append(constantPower);
		result.append(", RechargeableBattery: ");
		result.append(rechargeableBattery);
		result.append(", DisposableBattery: ");
		result.append(disposableBattery);
		result.append(", DefaultPowerSource: ");
		result.append(defaultPowerSource);
		result.append(", DefaultPowerMode: ");
		result.append(defaultPowerMode);
		result.append(')');
		return result.toString();
	}

} //NodePowerDescriptorImpl
