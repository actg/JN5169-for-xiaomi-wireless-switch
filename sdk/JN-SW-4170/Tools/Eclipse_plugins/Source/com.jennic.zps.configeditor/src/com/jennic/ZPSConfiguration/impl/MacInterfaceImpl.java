/**
 * (C) Jennic Ltd
 */
package com.jennic.ZPSConfiguration.impl;

import com.jennic.ZPSConfiguration.MacInterface;
import com.jennic.ZPSConfiguration.RadioType;
import com.jennic.ZPSConfiguration.ZPSConfigurationFactory;
import com.jennic.ZPSConfiguration.ZPSConfigurationPackage;

import java.util.Collection;
import org.eclipse.emf.common.notify.Notification;

import org.eclipse.emf.common.util.EList;
import org.eclipse.emf.ecore.EClass;

import org.eclipse.emf.ecore.impl.ENotificationImpl;
import org.eclipse.emf.ecore.impl.EObjectImpl;
import org.eclipse.emf.ecore.util.EDataTypeUniqueEList;

/**
 * <!-- begin-user-doc -->
 * An implementation of the model object '<em><b>Mac Interface</b></em>'.
 * <!-- end-user-doc -->
 * <p>
 * The following features are implemented:
 * <ul>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.MacInterfaceImpl#isRouterAllowed <em>Router Allowed</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.MacInterfaceImpl#getChannelListSize <em>Channel List Size</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.MacInterfaceImpl#getIndex <em>Index</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.MacInterfaceImpl#getRadioType <em>Radio Type</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.MacInterfaceImpl#isEnabled <em>Enabled</em>}</li>
 * </ul>
 * </p>
 *
 * @generated
 */
public class MacInterfaceImpl extends EObjectImpl implements MacInterface {
	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public static final String copyright = "(C) NXP B.V";

	/**
	 * The default value of the '{@link #isRouterAllowed() <em>Router Allowed</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #isRouterAllowed()
	 * @generated
	 * @ordered
	 */
	protected static final boolean ROUTER_ALLOWED_EDEFAULT = false;

	/**
	 * The cached value of the '{@link #isRouterAllowed() <em>Router Allowed</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #isRouterAllowed()
	 * @generated
	 * @ordered
	 */
	protected boolean routerAllowed = ROUTER_ALLOWED_EDEFAULT;

	/**
	 * The default value of the '{@link #getChannelListSize() <em>Channel List Size</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getChannelListSize()
	 * @generated
	 * @ordered
	 */
	protected static final int CHANNEL_LIST_SIZE_EDEFAULT = 1;

	/**
	 * The cached value of the '{@link #getChannelListSize() <em>Channel List Size</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getChannelListSize()
	 * @generated
	 * @ordered
	 */
	protected int channelListSize = CHANNEL_LIST_SIZE_EDEFAULT;

	/**
	 * The default value of the '{@link #getIndex() <em>Index</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getIndex()
	 * @generated
	 * @ordered
	 */
	protected static final short INDEX_EDEFAULT = 0;

	/**
	 * The cached value of the '{@link #getIndex() <em>Index</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getIndex()
	 * @generated
	 * @ordered
	 */
	protected short index = INDEX_EDEFAULT;

	/**
	 * The default value of the '{@link #getRadioType() <em>Radio Type</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getRadioType()
	 * @generated
	 * @ordered
	 */
	protected static final RadioType RADIO_TYPE_EDEFAULT = RadioType.RT2400M_HZ;

	/**
	 * The cached value of the '{@link #getRadioType() <em>Radio Type</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getRadioType()
	 * @generated
	 * @ordered
	 */
	protected RadioType radioType = RADIO_TYPE_EDEFAULT;

	/**
	 * The default value of the '{@link #isEnabled() <em>Enabled</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #isEnabled()
	 * @generated
	 * @ordered
	 */
	protected static final boolean ENABLED_EDEFAULT = true;

	/**
	 * The cached value of the '{@link #isEnabled() <em>Enabled</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #isEnabled()
	 * @generated
	 * @ordered
	 */
	protected boolean enabled = ENABLED_EDEFAULT;

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	protected MacInterfaceImpl() {
		super();
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	@Override
	protected EClass eStaticClass() {
		return ZPSConfigurationPackage.Literals.MAC_INTERFACE;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public boolean isRouterAllowed() {
		return routerAllowed;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void setRouterAllowed(boolean newRouterAllowed) {
		boolean oldRouterAllowed = routerAllowed;
		routerAllowed = newRouterAllowed;
		if (eNotificationRequired())
			eNotify(new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.MAC_INTERFACE__ROUTER_ALLOWED, oldRouterAllowed, routerAllowed));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public int getChannelListSize() {
		return channelListSize;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void setChannelListSize(int newChannelListSize) {
		int oldChannelListSize = channelListSize;
		channelListSize = newChannelListSize;
		if (eNotificationRequired())
			eNotify(new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.MAC_INTERFACE__CHANNEL_LIST_SIZE, oldChannelListSize, channelListSize));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public short getIndex() {
		return index;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void setIndex(short newIndex) {
		short oldIndex = index;
		index = newIndex;
		if (eNotificationRequired())
			eNotify(new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.MAC_INTERFACE__INDEX, oldIndex, index));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public RadioType getRadioType() {
		return radioType;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void setRadioType(RadioType newRadioType) {
		RadioType oldRadioType = radioType;
		radioType = newRadioType == null ? RADIO_TYPE_EDEFAULT : newRadioType;
		if (eNotificationRequired())
			eNotify(new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.MAC_INTERFACE__RADIO_TYPE, oldRadioType, radioType));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public boolean isEnabled() {
		return enabled;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void setEnabled(boolean newEnabled) {
		boolean oldEnabled = enabled;
		enabled = newEnabled;
		if (eNotificationRequired())
			eNotify(new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.MAC_INTERFACE__ENABLED, oldEnabled, enabled));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	@Override
	public Object eGet(int featureID, boolean resolve, boolean coreType) {
		switch (featureID) {
			case ZPSConfigurationPackage.MAC_INTERFACE__ROUTER_ALLOWED:
				return isRouterAllowed();
			case ZPSConfigurationPackage.MAC_INTERFACE__CHANNEL_LIST_SIZE:
				return getChannelListSize();
			case ZPSConfigurationPackage.MAC_INTERFACE__INDEX:
				return getIndex();
			case ZPSConfigurationPackage.MAC_INTERFACE__RADIO_TYPE:
				return getRadioType();
			case ZPSConfigurationPackage.MAC_INTERFACE__ENABLED:
				return isEnabled();
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
			case ZPSConfigurationPackage.MAC_INTERFACE__ROUTER_ALLOWED:
				setRouterAllowed((Boolean)newValue);
				return;
			case ZPSConfigurationPackage.MAC_INTERFACE__CHANNEL_LIST_SIZE:
				setChannelListSize((Integer)newValue);
				return;
			case ZPSConfigurationPackage.MAC_INTERFACE__INDEX:
				setIndex((Short)newValue);
				return;
			case ZPSConfigurationPackage.MAC_INTERFACE__RADIO_TYPE:
				setRadioType((RadioType)newValue);
				return;
			case ZPSConfigurationPackage.MAC_INTERFACE__ENABLED:
				setEnabled((Boolean)newValue);
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
			case ZPSConfigurationPackage.MAC_INTERFACE__ROUTER_ALLOWED:
				setRouterAllowed(ROUTER_ALLOWED_EDEFAULT);
				return;
			case ZPSConfigurationPackage.MAC_INTERFACE__CHANNEL_LIST_SIZE:
				setChannelListSize(CHANNEL_LIST_SIZE_EDEFAULT);
				return;
			case ZPSConfigurationPackage.MAC_INTERFACE__INDEX:
				setIndex(INDEX_EDEFAULT);
				return;
			case ZPSConfigurationPackage.MAC_INTERFACE__RADIO_TYPE:
				setRadioType(RADIO_TYPE_EDEFAULT);
				return;
			case ZPSConfigurationPackage.MAC_INTERFACE__ENABLED:
				setEnabled(ENABLED_EDEFAULT);
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
			case ZPSConfigurationPackage.MAC_INTERFACE__ROUTER_ALLOWED:
				return routerAllowed != ROUTER_ALLOWED_EDEFAULT;
			case ZPSConfigurationPackage.MAC_INTERFACE__CHANNEL_LIST_SIZE:
				return channelListSize != CHANNEL_LIST_SIZE_EDEFAULT;
			case ZPSConfigurationPackage.MAC_INTERFACE__INDEX:
				return index != INDEX_EDEFAULT;
			case ZPSConfigurationPackage.MAC_INTERFACE__RADIO_TYPE:
				return radioType != RADIO_TYPE_EDEFAULT;
			case ZPSConfigurationPackage.MAC_INTERFACE__ENABLED:
				return enabled != ENABLED_EDEFAULT;
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
		result.append(" (RouterAllowed: ");
		result.append(routerAllowed);
		result.append(", ChannelListSize: ");
		result.append(channelListSize);
		result.append(", index: ");
		result.append(index);
		result.append(", RadioType: ");
		result.append(radioType);
		result.append(", Enabled: ");
		result.append(enabled);
		result.append(')');
		return result.toString();
	}

} //MacInterfaceImpl
