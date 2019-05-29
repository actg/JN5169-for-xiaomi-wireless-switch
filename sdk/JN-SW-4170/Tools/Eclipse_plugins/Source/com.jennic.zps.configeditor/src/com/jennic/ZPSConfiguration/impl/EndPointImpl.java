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
import org.eclipse.emf.ecore.util.EObjectContainmentWithInverseEList;
import org.eclipse.emf.ecore.util.EcoreUtil;
import org.eclipse.emf.ecore.util.InternalEList;

import com.jennic.ZPSConfiguration.EndPoint;
import com.jennic.ZPSConfiguration.InputCluster;
import com.jennic.ZPSConfiguration.Node;
import com.jennic.ZPSConfiguration.OutputCluster;
import com.jennic.ZPSConfiguration.Profile;
import com.jennic.ZPSConfiguration.ZPSConfigurationPackage;

/**
 * <!-- begin-user-doc -->
 * An implementation of the model object '<em><b>End Point</b></em>'.
 * <!-- end-user-doc -->
 * <p>
 * The following features are implemented:
 * <ul>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.EndPointImpl#getInputClusters <em>Input Clusters</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.EndPointImpl#getOutputClusters <em>Output Clusters</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.EndPointImpl#getId <em>Id</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.EndPointImpl#isEnabled <em>Enabled</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.EndPointImpl#getApplicationDeviceId <em>Application Device Id</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.EndPointImpl#getApplicationDeviceVersion <em>Application Device Version</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.EndPointImpl#getProfile <em>Profile</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.EndPointImpl#getMessage <em>Message</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.EndPointImpl#getNode <em>Node</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.EndPointImpl#getName <em>Name</em>}</li>
 * </ul>
 * </p>
 *
 * @generated
 */
public class EndPointImpl extends EObjectImpl implements EndPoint {
	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public static final String copyright = "(C) NXP B.V";

	/**
	 * The cached value of the '{@link #getInputClusters() <em>Input Clusters</em>}' containment reference list.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getInputClusters()
	 * @generated
	 * @ordered
	 */
	protected EList<InputCluster> inputClusters;

	/**
	 * The cached value of the '{@link #getOutputClusters() <em>Output Clusters</em>}' containment reference list.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getOutputClusters()
	 * @generated
	 * @ordered
	 */
	protected EList<OutputCluster> outputClusters;

	/**
	 * The default value of the '{@link #getId() <em>Id</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getId()
	 * @generated
	 * @ordered
	 */
	protected static final int ID_EDEFAULT = 1;

	/**
	 * The cached value of the '{@link #getId() <em>Id</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getId()
	 * @generated
	 * @ordered
	 */
	protected int id = ID_EDEFAULT;

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
	 * The default value of the '{@link #getApplicationDeviceId() <em>Application Device Id</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getApplicationDeviceId()
	 * @generated
	 * @ordered
	 */
	protected static final int APPLICATION_DEVICE_ID_EDEFAULT = 0;

	/**
	 * The cached value of the '{@link #getApplicationDeviceId() <em>Application Device Id</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getApplicationDeviceId()
	 * @generated
	 * @ordered
	 */
	protected int applicationDeviceId = APPLICATION_DEVICE_ID_EDEFAULT;

	/**
	 * The default value of the '{@link #getApplicationDeviceVersion() <em>Application Device Version</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getApplicationDeviceVersion()
	 * @generated
	 * @ordered
	 */
	protected static final int APPLICATION_DEVICE_VERSION_EDEFAULT = 0;

	/**
	 * The cached value of the '{@link #getApplicationDeviceVersion() <em>Application Device Version</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getApplicationDeviceVersion()
	 * @generated
	 * @ordered
	 */
	protected int applicationDeviceVersion = APPLICATION_DEVICE_VERSION_EDEFAULT;

	/**
	 * The cached value of the '{@link #getProfile() <em>Profile</em>}' reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getProfile()
	 * @generated
	 * @ordered
	 */
	protected Profile profile;

	/**
	 * The default value of the '{@link #getMessage() <em>Message</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getMessage()
	 * @generated
	 * @ordered
	 */
	protected static final String MESSAGE_EDEFAULT = null;

	/**
	 * The cached value of the '{@link #getMessage() <em>Message</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getMessage()
	 * @generated
	 * @ordered
	 */
	protected String message = MESSAGE_EDEFAULT;

	/**
	 * The default value of the '{@link #getName() <em>Name</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getName()
	 * @generated
	 * @ordered
	 */
	protected static final String NAME_EDEFAULT = null;

	/**
	 * The cached value of the '{@link #getName() <em>Name</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getName()
	 * @generated
	 * @ordered
	 */
	protected String name = NAME_EDEFAULT;

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	protected EndPointImpl() {
		super();
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	@Override
	protected EClass eStaticClass() {
		return ZPSConfigurationPackage.Literals.END_POINT;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EList<InputCluster> getInputClusters() {
		if (inputClusters == null) {
			inputClusters = new EObjectContainmentWithInverseEList<InputCluster>(InputCluster.class, this, ZPSConfigurationPackage.END_POINT__INPUT_CLUSTERS, ZPSConfigurationPackage.INPUT_CLUSTER__END_POINT);
		}
		return inputClusters;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EList<OutputCluster> getOutputClusters() {
		if (outputClusters == null) {
			outputClusters = new EObjectContainmentWithInverseEList<OutputCluster>(OutputCluster.class, this, ZPSConfigurationPackage.END_POINT__OUTPUT_CLUSTERS, ZPSConfigurationPackage.OUTPUT_CLUSTER__END_POINT);
		}
		return outputClusters;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public int getId() {
		return id;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void setId(int newId) {
		int oldId = id;
		id = newId;
		if (eNotificationRequired())
			eNotify(new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.END_POINT__ID, oldId, id));
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
			eNotify(new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.END_POINT__ENABLED, oldEnabled, enabled));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public int getApplicationDeviceId() {
		return applicationDeviceId;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void setApplicationDeviceId(int newApplicationDeviceId) {
		int oldApplicationDeviceId = applicationDeviceId;
		applicationDeviceId = newApplicationDeviceId;
		if (eNotificationRequired())
			eNotify(new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.END_POINT__APPLICATION_DEVICE_ID, oldApplicationDeviceId, applicationDeviceId));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public int getApplicationDeviceVersion() {
		return applicationDeviceVersion;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void setApplicationDeviceVersion(int newApplicationDeviceVersion) {
		int oldApplicationDeviceVersion = applicationDeviceVersion;
		applicationDeviceVersion = newApplicationDeviceVersion;
		if (eNotificationRequired())
			eNotify(new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.END_POINT__APPLICATION_DEVICE_VERSION, oldApplicationDeviceVersion, applicationDeviceVersion));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public Profile getProfile() {
		if (profile != null && profile.eIsProxy()) {
			InternalEObject oldProfile = (InternalEObject)profile;
			profile = (Profile)eResolveProxy(oldProfile);
			if (profile != oldProfile) {
				if (eNotificationRequired())
					eNotify(new ENotificationImpl(this, Notification.RESOLVE, ZPSConfigurationPackage.END_POINT__PROFILE, oldProfile, profile));
			}
		}
		return profile;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public Profile basicGetProfile() {
		return profile;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void setProfile(Profile newProfile) {
		Profile oldProfile = profile;
		profile = newProfile;
		if (eNotificationRequired())
			eNotify(new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.END_POINT__PROFILE, oldProfile, profile));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public String getMessage() {
		return message;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void setMessage(String newMessage) {
		String oldMessage = message;
		message = newMessage;
		if (eNotificationRequired())
			eNotify(new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.END_POINT__MESSAGE, oldMessage, message));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public Node getNode() {
		if (eContainerFeatureID() != ZPSConfigurationPackage.END_POINT__NODE) return null;
		return (Node)eInternalContainer();
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public NotificationChain basicSetNode(Node newNode, NotificationChain msgs) {
		msgs = eBasicSetContainer((InternalEObject)newNode, ZPSConfigurationPackage.END_POINT__NODE, msgs);
		return msgs;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void setNode(Node newNode) {
		if (newNode != eInternalContainer() || (eContainerFeatureID() != ZPSConfigurationPackage.END_POINT__NODE && newNode != null)) {
			if (EcoreUtil.isAncestor(this, newNode))
				throw new IllegalArgumentException("Recursive containment not allowed for " + toString());
			NotificationChain msgs = null;
			if (eInternalContainer() != null)
				msgs = eBasicRemoveFromContainer(msgs);
			if (newNode != null)
				msgs = ((InternalEObject)newNode).eInverseAdd(this, ZPSConfigurationPackage.NODE__ENDPOINTS, Node.class, msgs);
			msgs = basicSetNode(newNode, msgs);
			if (msgs != null) msgs.dispatch();
		}
		else if (eNotificationRequired())
			eNotify(new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.END_POINT__NODE, newNode, newNode));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public String getName() {
		return name;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void setName(String newName) {
		String oldName = name;
		name = newName;
		if (eNotificationRequired())
			eNotify(new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.END_POINT__NAME, oldName, name));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	@SuppressWarnings("unchecked")
	@Override
	public NotificationChain eInverseAdd(InternalEObject otherEnd, int featureID, NotificationChain msgs) {
		switch (featureID) {
			case ZPSConfigurationPackage.END_POINT__INPUT_CLUSTERS:
				return ((InternalEList<InternalEObject>)(InternalEList<?>)getInputClusters()).basicAdd(otherEnd, msgs);
			case ZPSConfigurationPackage.END_POINT__OUTPUT_CLUSTERS:
				return ((InternalEList<InternalEObject>)(InternalEList<?>)getOutputClusters()).basicAdd(otherEnd, msgs);
			case ZPSConfigurationPackage.END_POINT__NODE:
				if (eInternalContainer() != null)
					msgs = eBasicRemoveFromContainer(msgs);
				return basicSetNode((Node)otherEnd, msgs);
		}
		return super.eInverseAdd(otherEnd, featureID, msgs);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	@Override
	public NotificationChain eInverseRemove(InternalEObject otherEnd, int featureID, NotificationChain msgs) {
		switch (featureID) {
			case ZPSConfigurationPackage.END_POINT__INPUT_CLUSTERS:
				return ((InternalEList<?>)getInputClusters()).basicRemove(otherEnd, msgs);
			case ZPSConfigurationPackage.END_POINT__OUTPUT_CLUSTERS:
				return ((InternalEList<?>)getOutputClusters()).basicRemove(otherEnd, msgs);
			case ZPSConfigurationPackage.END_POINT__NODE:
				return basicSetNode(null, msgs);
		}
		return super.eInverseRemove(otherEnd, featureID, msgs);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	@Override
	public NotificationChain eBasicRemoveFromContainerFeature(NotificationChain msgs) {
		switch (eContainerFeatureID()) {
			case ZPSConfigurationPackage.END_POINT__NODE:
				return eInternalContainer().eInverseRemove(this, ZPSConfigurationPackage.NODE__ENDPOINTS, Node.class, msgs);
		}
		return super.eBasicRemoveFromContainerFeature(msgs);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	@Override
	public Object eGet(int featureID, boolean resolve, boolean coreType) {
		switch (featureID) {
			case ZPSConfigurationPackage.END_POINT__INPUT_CLUSTERS:
				return getInputClusters();
			case ZPSConfigurationPackage.END_POINT__OUTPUT_CLUSTERS:
				return getOutputClusters();
			case ZPSConfigurationPackage.END_POINT__ID:
				return getId();
			case ZPSConfigurationPackage.END_POINT__ENABLED:
				return isEnabled();
			case ZPSConfigurationPackage.END_POINT__APPLICATION_DEVICE_ID:
				return getApplicationDeviceId();
			case ZPSConfigurationPackage.END_POINT__APPLICATION_DEVICE_VERSION:
				return getApplicationDeviceVersion();
			case ZPSConfigurationPackage.END_POINT__PROFILE:
				if (resolve) return getProfile();
				return basicGetProfile();
			case ZPSConfigurationPackage.END_POINT__MESSAGE:
				return getMessage();
			case ZPSConfigurationPackage.END_POINT__NODE:
				return getNode();
			case ZPSConfigurationPackage.END_POINT__NAME:
				return getName();
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
			case ZPSConfigurationPackage.END_POINT__INPUT_CLUSTERS:
				getInputClusters().clear();
				getInputClusters().addAll((Collection<? extends InputCluster>)newValue);
				return;
			case ZPSConfigurationPackage.END_POINT__OUTPUT_CLUSTERS:
				getOutputClusters().clear();
				getOutputClusters().addAll((Collection<? extends OutputCluster>)newValue);
				return;
			case ZPSConfigurationPackage.END_POINT__ID:
				setId((Integer)newValue);
				return;
			case ZPSConfigurationPackage.END_POINT__ENABLED:
				setEnabled((Boolean)newValue);
				return;
			case ZPSConfigurationPackage.END_POINT__APPLICATION_DEVICE_ID:
				setApplicationDeviceId((Integer)newValue);
				return;
			case ZPSConfigurationPackage.END_POINT__APPLICATION_DEVICE_VERSION:
				setApplicationDeviceVersion((Integer)newValue);
				return;
			case ZPSConfigurationPackage.END_POINT__PROFILE:
				setProfile((Profile)newValue);
				return;
			case ZPSConfigurationPackage.END_POINT__MESSAGE:
				setMessage((String)newValue);
				return;
			case ZPSConfigurationPackage.END_POINT__NODE:
				setNode((Node)newValue);
				return;
			case ZPSConfigurationPackage.END_POINT__NAME:
				setName((String)newValue);
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
			case ZPSConfigurationPackage.END_POINT__INPUT_CLUSTERS:
				getInputClusters().clear();
				return;
			case ZPSConfigurationPackage.END_POINT__OUTPUT_CLUSTERS:
				getOutputClusters().clear();
				return;
			case ZPSConfigurationPackage.END_POINT__ID:
				setId(ID_EDEFAULT);
				return;
			case ZPSConfigurationPackage.END_POINT__ENABLED:
				setEnabled(ENABLED_EDEFAULT);
				return;
			case ZPSConfigurationPackage.END_POINT__APPLICATION_DEVICE_ID:
				setApplicationDeviceId(APPLICATION_DEVICE_ID_EDEFAULT);
				return;
			case ZPSConfigurationPackage.END_POINT__APPLICATION_DEVICE_VERSION:
				setApplicationDeviceVersion(APPLICATION_DEVICE_VERSION_EDEFAULT);
				return;
			case ZPSConfigurationPackage.END_POINT__PROFILE:
				setProfile((Profile)null);
				return;
			case ZPSConfigurationPackage.END_POINT__MESSAGE:
				setMessage(MESSAGE_EDEFAULT);
				return;
			case ZPSConfigurationPackage.END_POINT__NODE:
				setNode((Node)null);
				return;
			case ZPSConfigurationPackage.END_POINT__NAME:
				setName(NAME_EDEFAULT);
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
			case ZPSConfigurationPackage.END_POINT__INPUT_CLUSTERS:
				return inputClusters != null && !inputClusters.isEmpty();
			case ZPSConfigurationPackage.END_POINT__OUTPUT_CLUSTERS:
				return outputClusters != null && !outputClusters.isEmpty();
			case ZPSConfigurationPackage.END_POINT__ID:
				return id != ID_EDEFAULT;
			case ZPSConfigurationPackage.END_POINT__ENABLED:
				return enabled != ENABLED_EDEFAULT;
			case ZPSConfigurationPackage.END_POINT__APPLICATION_DEVICE_ID:
				return applicationDeviceId != APPLICATION_DEVICE_ID_EDEFAULT;
			case ZPSConfigurationPackage.END_POINT__APPLICATION_DEVICE_VERSION:
				return applicationDeviceVersion != APPLICATION_DEVICE_VERSION_EDEFAULT;
			case ZPSConfigurationPackage.END_POINT__PROFILE:
				return profile != null;
			case ZPSConfigurationPackage.END_POINT__MESSAGE:
				return MESSAGE_EDEFAULT == null ? message != null : !MESSAGE_EDEFAULT.equals(message);
			case ZPSConfigurationPackage.END_POINT__NODE:
				return getNode() != null;
			case ZPSConfigurationPackage.END_POINT__NAME:
				return NAME_EDEFAULT == null ? name != null : !NAME_EDEFAULT.equals(name);
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
		result.append(" (Id: ");
		result.append(id);
		result.append(", Enabled: ");
		result.append(enabled);
		result.append(", ApplicationDeviceId: ");
		result.append(applicationDeviceId);
		result.append(", ApplicationDeviceVersion: ");
		result.append(applicationDeviceVersion);
		result.append(", Message: ");
		result.append(message);
		result.append(", Name: ");
		result.append(name);
		result.append(')');
		return result.toString();
	}

} //EndPointImpl
