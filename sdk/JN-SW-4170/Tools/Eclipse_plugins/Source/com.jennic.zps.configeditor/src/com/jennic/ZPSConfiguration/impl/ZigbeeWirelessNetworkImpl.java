/**
 * (C) Jennic Ltd
 *
 * $Id$
 */
package com.jennic.ZPSConfiguration.impl;


import java.util.Collection;

import org.eclipse.emf.common.notify.Notification;
import org.eclipse.emf.common.notify.NotificationChain;

import org.eclipse.emf.common.util.EList;

import org.eclipse.emf.ecore.EClass;
import org.eclipse.emf.ecore.InternalEObject;

import org.eclipse.emf.ecore.impl.ENotificationImpl;
import org.eclipse.emf.ecore.impl.EObjectImpl;

import org.eclipse.emf.ecore.util.EObjectContainmentEList;
import org.eclipse.emf.ecore.util.InternalEList;

import com.jennic.ZPSConfiguration.ChildNodes;
import com.jennic.ZPSConfiguration.Coordinator;
import com.jennic.ZPSConfiguration.Profile;
import com.jennic.ZPSConfiguration.ZPSConfigurationFactory;
import com.jennic.ZPSConfiguration.ZPSConfigurationPackage;
import com.jennic.ZPSConfiguration.ZigbeeWirelessNetwork;

/**
 * <!-- begin-user-doc -->
 * An implementation of the model object '<em><b>Zigbee Wireless Network</b></em>'.
 * <!-- end-user-doc -->
 * <p>
 * The following features are implemented:
 * <ul>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.ZigbeeWirelessNetworkImpl#getProfiles <em>Profiles</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.ZigbeeWirelessNetworkImpl#getCoordinator <em>Coordinator</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.ZigbeeWirelessNetworkImpl#getChildNodes <em>Child Nodes</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.ZigbeeWirelessNetworkImpl#getDefaultExtendedPANId <em>Default Extended PAN Id</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.ZigbeeWirelessNetworkImpl#getMaxNumberNodes <em>Max Number Nodes</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.ZigbeeWirelessNetworkImpl#getVersion <em>Version</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.ZigbeeWirelessNetworkImpl#isDefaultSecurityEnabled <em>Default Security Enabled</em>}</li>
 * </ul>
 * </p>
 *
 * @generated
 */
public class ZigbeeWirelessNetworkImpl extends EObjectImpl implements ZigbeeWirelessNetwork {
	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public static final String copyright = "(C) NXP B.V";

	/**
	 * The cached value of the '{@link #getProfiles() <em>Profiles</em>}' containment reference list.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getProfiles()
	 * @generated
	 * @ordered
	 */
	protected EList<Profile> profiles;

	/**
	 * The cached value of the '{@link #getCoordinator() <em>Coordinator</em>}' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getCoordinator()
	 * @generated
	 * @ordered
	 */
	protected Coordinator coordinator;

	/**
	 * The cached value of the '{@link #getChildNodes() <em>Child Nodes</em>}' containment reference list.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getChildNodes()
	 * @generated
	 * @ordered
	 */
	protected EList<ChildNodes> childNodes;

	/**
	 * The default value of the '{@link #getDefaultExtendedPANId() <em>Default Extended PAN Id</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getDefaultExtendedPANId()
	 * @generated
	 * @ordered
	 */
	protected static final Object DEFAULT_EXTENDED_PAN_ID_EDEFAULT = (Object)ZPSConfigurationFactory.eINSTANCE.createFromString(ZPSConfigurationPackage.eINSTANCE.getEExtPANId(), "0");

	/**
	 * The cached value of the '{@link #getDefaultExtendedPANId() <em>Default Extended PAN Id</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getDefaultExtendedPANId()
	 * @generated
	 * @ordered
	 */
	protected Object defaultExtendedPANId = DEFAULT_EXTENDED_PAN_ID_EDEFAULT;

	/**
	 * The default value of the '{@link #getMaxNumberNodes() <em>Max Number Nodes</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getMaxNumberNodes()
	 * @generated
	 * @ordered
	 */
	protected static final int MAX_NUMBER_NODES_EDEFAULT = 20;

	/**
	 * The cached value of the '{@link #getMaxNumberNodes() <em>Max Number Nodes</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getMaxNumberNodes()
	 * @generated
	 * @ordered
	 */
	protected int maxNumberNodes = MAX_NUMBER_NODES_EDEFAULT;

	/**
	 * The default value of the '{@link #getVersion() <em>Version</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getVersion()
	 * @generated
	 * @ordered
	 */
	protected static final String VERSION_EDEFAULT = "1.2";

	/**
	 * The cached value of the '{@link #getVersion() <em>Version</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getVersion()
	 * @generated
	 * @ordered
	 */
	protected String version = VERSION_EDEFAULT;

	/**
	 * The default value of the '{@link #isDefaultSecurityEnabled() <em>Default Security Enabled</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #isDefaultSecurityEnabled()
	 * @generated
	 * @ordered
	 */
	protected static final boolean DEFAULT_SECURITY_ENABLED_EDEFAULT = true;

	/**
	 * The cached value of the '{@link #isDefaultSecurityEnabled() <em>Default Security Enabled</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #isDefaultSecurityEnabled()
	 * @generated
	 * @ordered
	 */
	protected boolean defaultSecurityEnabled = DEFAULT_SECURITY_ENABLED_EDEFAULT;

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	protected ZigbeeWirelessNetworkImpl() {
		super();
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	@Override
	protected EClass eStaticClass() {
		return ZPSConfigurationPackage.Literals.ZIGBEE_WIRELESS_NETWORK;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EList<Profile> getProfiles() {
		if (profiles == null) {
			profiles = new EObjectContainmentEList<Profile>(Profile.class, this, ZPSConfigurationPackage.ZIGBEE_WIRELESS_NETWORK__PROFILES);
		}
		return profiles;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public Coordinator getCoordinator() {
		return coordinator;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public NotificationChain basicSetCoordinator(Coordinator newCoordinator, NotificationChain msgs) {
		Coordinator oldCoordinator = coordinator;
		coordinator = newCoordinator;
		if (eNotificationRequired()) {
			ENotificationImpl notification = new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.ZIGBEE_WIRELESS_NETWORK__COORDINATOR, oldCoordinator, newCoordinator);
			if (msgs == null) msgs = notification; else msgs.add(notification);
		}
		return msgs;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void setCoordinator(Coordinator newCoordinator) {
		if (newCoordinator != coordinator) {
			NotificationChain msgs = null;
			if (coordinator != null)
				msgs = ((InternalEObject)coordinator).eInverseRemove(this, EOPPOSITE_FEATURE_BASE - ZPSConfigurationPackage.ZIGBEE_WIRELESS_NETWORK__COORDINATOR, null, msgs);
			if (newCoordinator != null)
				msgs = ((InternalEObject)newCoordinator).eInverseAdd(this, EOPPOSITE_FEATURE_BASE - ZPSConfigurationPackage.ZIGBEE_WIRELESS_NETWORK__COORDINATOR, null, msgs);
			msgs = basicSetCoordinator(newCoordinator, msgs);
			if (msgs != null) msgs.dispatch();
		}
		else if (eNotificationRequired())
			eNotify(new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.ZIGBEE_WIRELESS_NETWORK__COORDINATOR, newCoordinator, newCoordinator));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EList<ChildNodes> getChildNodes() {
		if (childNodes == null) {
			childNodes = new EObjectContainmentEList<ChildNodes>(ChildNodes.class, this, ZPSConfigurationPackage.ZIGBEE_WIRELESS_NETWORK__CHILD_NODES);
		}
		return childNodes;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public Object getDefaultExtendedPANId() {
		return defaultExtendedPANId;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void setDefaultExtendedPANId(Object newDefaultExtendedPANId) {
		Object oldDefaultExtendedPANId = defaultExtendedPANId;
		defaultExtendedPANId = newDefaultExtendedPANId;
		if (eNotificationRequired())
			eNotify(new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.ZIGBEE_WIRELESS_NETWORK__DEFAULT_EXTENDED_PAN_ID, oldDefaultExtendedPANId, defaultExtendedPANId));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public int getMaxNumberNodes() {
		return maxNumberNodes;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void setMaxNumberNodes(int newMaxNumberNodes) {
		int oldMaxNumberNodes = maxNumberNodes;
		maxNumberNodes = newMaxNumberNodes;
		if (eNotificationRequired())
			eNotify(new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.ZIGBEE_WIRELESS_NETWORK__MAX_NUMBER_NODES, oldMaxNumberNodes, maxNumberNodes));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public String getVersion() {
		return version;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated NOT
	 */
	public void setVersion(String newVersion) {
		String oldVersion = version;
		if (newVersion.compareTo("1.0") == 0) {
			version = "1.1";
		} else {
			version = newVersion;
		}
		if (eNotificationRequired())
			eNotify(new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.ZIGBEE_WIRELESS_NETWORK__VERSION, oldVersion, version));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public boolean isDefaultSecurityEnabled() {
		return defaultSecurityEnabled;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void setDefaultSecurityEnabled(boolean newDefaultSecurityEnabled) {
		boolean oldDefaultSecurityEnabled = defaultSecurityEnabled;
		defaultSecurityEnabled = newDefaultSecurityEnabled;
		if (eNotificationRequired())
			eNotify(new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.ZIGBEE_WIRELESS_NETWORK__DEFAULT_SECURITY_ENABLED, oldDefaultSecurityEnabled, defaultSecurityEnabled));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	@Override
	public NotificationChain eInverseRemove(InternalEObject otherEnd, int featureID, NotificationChain msgs) {
		switch (featureID) {
			case ZPSConfigurationPackage.ZIGBEE_WIRELESS_NETWORK__PROFILES:
				return ((InternalEList<?>)getProfiles()).basicRemove(otherEnd, msgs);
			case ZPSConfigurationPackage.ZIGBEE_WIRELESS_NETWORK__COORDINATOR:
				return basicSetCoordinator(null, msgs);
			case ZPSConfigurationPackage.ZIGBEE_WIRELESS_NETWORK__CHILD_NODES:
				return ((InternalEList<?>)getChildNodes()).basicRemove(otherEnd, msgs);
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
			case ZPSConfigurationPackage.ZIGBEE_WIRELESS_NETWORK__PROFILES:
				return getProfiles();
			case ZPSConfigurationPackage.ZIGBEE_WIRELESS_NETWORK__COORDINATOR:
				return getCoordinator();
			case ZPSConfigurationPackage.ZIGBEE_WIRELESS_NETWORK__CHILD_NODES:
				return getChildNodes();
			case ZPSConfigurationPackage.ZIGBEE_WIRELESS_NETWORK__DEFAULT_EXTENDED_PAN_ID:
				return getDefaultExtendedPANId();
			case ZPSConfigurationPackage.ZIGBEE_WIRELESS_NETWORK__MAX_NUMBER_NODES:
				return getMaxNumberNodes();
			case ZPSConfigurationPackage.ZIGBEE_WIRELESS_NETWORK__VERSION:
				return getVersion();
			case ZPSConfigurationPackage.ZIGBEE_WIRELESS_NETWORK__DEFAULT_SECURITY_ENABLED:
				return isDefaultSecurityEnabled();
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
			case ZPSConfigurationPackage.ZIGBEE_WIRELESS_NETWORK__PROFILES:
				getProfiles().clear();
				getProfiles().addAll((Collection<? extends Profile>)newValue);
				return;
			case ZPSConfigurationPackage.ZIGBEE_WIRELESS_NETWORK__COORDINATOR:
				setCoordinator((Coordinator)newValue);
				return;
			case ZPSConfigurationPackage.ZIGBEE_WIRELESS_NETWORK__CHILD_NODES:
				getChildNodes().clear();
				getChildNodes().addAll((Collection<? extends ChildNodes>)newValue);
				return;
			case ZPSConfigurationPackage.ZIGBEE_WIRELESS_NETWORK__DEFAULT_EXTENDED_PAN_ID:
				setDefaultExtendedPANId((Object)newValue);
				return;
			case ZPSConfigurationPackage.ZIGBEE_WIRELESS_NETWORK__MAX_NUMBER_NODES:
				setMaxNumberNodes((Integer)newValue);
				return;
			case ZPSConfigurationPackage.ZIGBEE_WIRELESS_NETWORK__VERSION:
				setVersion((String)newValue);
				return;
			case ZPSConfigurationPackage.ZIGBEE_WIRELESS_NETWORK__DEFAULT_SECURITY_ENABLED:
				setDefaultSecurityEnabled((Boolean)newValue);
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
			case ZPSConfigurationPackage.ZIGBEE_WIRELESS_NETWORK__PROFILES:
				getProfiles().clear();
				return;
			case ZPSConfigurationPackage.ZIGBEE_WIRELESS_NETWORK__COORDINATOR:
				setCoordinator((Coordinator)null);
				return;
			case ZPSConfigurationPackage.ZIGBEE_WIRELESS_NETWORK__CHILD_NODES:
				getChildNodes().clear();
				return;
			case ZPSConfigurationPackage.ZIGBEE_WIRELESS_NETWORK__DEFAULT_EXTENDED_PAN_ID:
				setDefaultExtendedPANId(DEFAULT_EXTENDED_PAN_ID_EDEFAULT);
				return;
			case ZPSConfigurationPackage.ZIGBEE_WIRELESS_NETWORK__MAX_NUMBER_NODES:
				setMaxNumberNodes(MAX_NUMBER_NODES_EDEFAULT);
				return;
			case ZPSConfigurationPackage.ZIGBEE_WIRELESS_NETWORK__VERSION:
				setVersion(VERSION_EDEFAULT);
				return;
			case ZPSConfigurationPackage.ZIGBEE_WIRELESS_NETWORK__DEFAULT_SECURITY_ENABLED:
				setDefaultSecurityEnabled(DEFAULT_SECURITY_ENABLED_EDEFAULT);
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
			case ZPSConfigurationPackage.ZIGBEE_WIRELESS_NETWORK__PROFILES:
				return profiles != null && !profiles.isEmpty();
			case ZPSConfigurationPackage.ZIGBEE_WIRELESS_NETWORK__COORDINATOR:
				return coordinator != null;
			case ZPSConfigurationPackage.ZIGBEE_WIRELESS_NETWORK__CHILD_NODES:
				return childNodes != null && !childNodes.isEmpty();
			case ZPSConfigurationPackage.ZIGBEE_WIRELESS_NETWORK__DEFAULT_EXTENDED_PAN_ID:
				return DEFAULT_EXTENDED_PAN_ID_EDEFAULT == null ? defaultExtendedPANId != null : !DEFAULT_EXTENDED_PAN_ID_EDEFAULT.equals(defaultExtendedPANId);
			case ZPSConfigurationPackage.ZIGBEE_WIRELESS_NETWORK__MAX_NUMBER_NODES:
				return maxNumberNodes != MAX_NUMBER_NODES_EDEFAULT;
			case ZPSConfigurationPackage.ZIGBEE_WIRELESS_NETWORK__VERSION:
				return VERSION_EDEFAULT == null ? version != null : !VERSION_EDEFAULT.equals(version);
			case ZPSConfigurationPackage.ZIGBEE_WIRELESS_NETWORK__DEFAULT_SECURITY_ENABLED:
				return defaultSecurityEnabled != DEFAULT_SECURITY_ENABLED_EDEFAULT;
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
		result.append(" (DefaultExtendedPANId: ");
		result.append(defaultExtendedPANId);
		result.append(", MaxNumberNodes: ");
		result.append(maxNumberNodes);
		result.append(", Version: ");
		result.append(version);
		result.append(", DefaultSecurityEnabled: ");
		result.append(defaultSecurityEnabled);
		result.append(')');
		return result.toString();
	}

} //ZigbeeWirelessNetworkImpl
