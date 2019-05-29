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
import org.eclipse.emf.ecore.impl.EObjectImpl;

import org.eclipse.emf.ecore.util.EcoreUtil;

import com.jennic.ZPSConfiguration.APDU;
import com.jennic.ZPSConfiguration.PDUManager;
import com.jennic.ZPSConfiguration.ZPSConfigurationPackage;

/**
 * <!-- begin-user-doc -->
 * An implementation of the model object '<em><b>APDU</b></em>'.
 * <!-- end-user-doc -->
 * <p>
 * The following features are implemented:
 * <ul>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.APDUImpl#getId <em>Id</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.APDUImpl#getName <em>Name</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.APDUImpl#getSize <em>Size</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.APDUImpl#getInstances <em>Instances</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.APDUImpl#getPDUConfig <em>PDU Config</em>}</li>
 * </ul>
 * </p>
 *
 * @generated
 */
public class APDUImpl extends EObjectImpl implements APDU {
	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public static final String copyright = "(C) NXP B.V";

	/**
	 * The default value of the '{@link #getId() <em>Id</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getId()
	 * @generated
	 * @ordered
	 */
	protected static final String ID_EDEFAULT = "";

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
	 * The default value of the '{@link #getSize() <em>Size</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getSize()
	 * @generated
	 * @ordered
	 */
	protected static final int SIZE_EDEFAULT = 1;

	/**
	 * The cached value of the '{@link #getSize() <em>Size</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getSize()
	 * @generated
	 * @ordered
	 */
	protected int size = SIZE_EDEFAULT;

	/**
	 * The default value of the '{@link #getInstances() <em>Instances</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getInstances()
	 * @generated
	 * @ordered
	 */
	protected static final int INSTANCES_EDEFAULT = 1;

	/**
	 * The cached value of the '{@link #getInstances() <em>Instances</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getInstances()
	 * @generated
	 * @ordered
	 */
	protected int instances = INSTANCES_EDEFAULT;

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	protected APDUImpl() {
		super();
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	@Override
	protected EClass eStaticClass() {
		return ZPSConfigurationPackage.Literals.APDU;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated NOT
	 */
	public String getId() {
		String id = getPDUConfig().getContainerNode().getName();
		return id + "->" + name;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated NOT
	 */
	public void setId(String newId) {
		/* nothing to do as generated but persisted */
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated NOT
	 */
	public void unsetId() {
		/* nothing to do as generated but persisted */
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated NOT
	 */
	public boolean isSetId() {
		/* always true as generated but persisted */
		return true;
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
			eNotify(new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.APDU__NAME, oldName, name));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public int getSize() {
		return size;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void setSize(int newSize) {
		int oldSize = size;
		size = newSize;
		if (eNotificationRequired())
			eNotify(new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.APDU__SIZE, oldSize, size));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public int getInstances() {
		return instances;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void setInstances(int newInstances) {
		int oldInstances = instances;
		instances = newInstances;
		if (eNotificationRequired())
			eNotify(new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.APDU__INSTANCES, oldInstances, instances));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public PDUManager getPDUConfig() {
		if (eContainerFeatureID() != ZPSConfigurationPackage.APDU__PDU_CONFIG) return null;
		return (PDUManager)eInternalContainer();
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public NotificationChain basicSetPDUConfig(PDUManager newPDUConfig, NotificationChain msgs) {
		msgs = eBasicSetContainer((InternalEObject)newPDUConfig, ZPSConfigurationPackage.APDU__PDU_CONFIG, msgs);
		return msgs;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void setPDUConfig(PDUManager newPDUConfig) {
		if (newPDUConfig != eInternalContainer() || (eContainerFeatureID() != ZPSConfigurationPackage.APDU__PDU_CONFIG && newPDUConfig != null)) {
			if (EcoreUtil.isAncestor(this, newPDUConfig))
				throw new IllegalArgumentException("Recursive containment not allowed for " + toString());
			NotificationChain msgs = null;
			if (eInternalContainer() != null)
				msgs = eBasicRemoveFromContainer(msgs);
			if (newPDUConfig != null)
				msgs = ((InternalEObject)newPDUConfig).eInverseAdd(this, ZPSConfigurationPackage.PDU_MANAGER__APD_US, PDUManager.class, msgs);
			msgs = basicSetPDUConfig(newPDUConfig, msgs);
			if (msgs != null) msgs.dispatch();
		}
		else if (eNotificationRequired())
			eNotify(new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.APDU__PDU_CONFIG, newPDUConfig, newPDUConfig));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	@Override
	public NotificationChain eInverseAdd(InternalEObject otherEnd, int featureID, NotificationChain msgs) {
		switch (featureID) {
			case ZPSConfigurationPackage.APDU__PDU_CONFIG:
				if (eInternalContainer() != null)
					msgs = eBasicRemoveFromContainer(msgs);
				return basicSetPDUConfig((PDUManager)otherEnd, msgs);
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
			case ZPSConfigurationPackage.APDU__PDU_CONFIG:
				return basicSetPDUConfig(null, msgs);
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
			case ZPSConfigurationPackage.APDU__PDU_CONFIG:
				return eInternalContainer().eInverseRemove(this, ZPSConfigurationPackage.PDU_MANAGER__APD_US, PDUManager.class, msgs);
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
			case ZPSConfigurationPackage.APDU__ID:
				return getId();
			case ZPSConfigurationPackage.APDU__NAME:
				return getName();
			case ZPSConfigurationPackage.APDU__SIZE:
				return getSize();
			case ZPSConfigurationPackage.APDU__INSTANCES:
				return getInstances();
			case ZPSConfigurationPackage.APDU__PDU_CONFIG:
				return getPDUConfig();
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
			case ZPSConfigurationPackage.APDU__ID:
				setId((String)newValue);
				return;
			case ZPSConfigurationPackage.APDU__NAME:
				setName((String)newValue);
				return;
			case ZPSConfigurationPackage.APDU__SIZE:
				setSize((Integer)newValue);
				return;
			case ZPSConfigurationPackage.APDU__INSTANCES:
				setInstances((Integer)newValue);
				return;
			case ZPSConfigurationPackage.APDU__PDU_CONFIG:
				setPDUConfig((PDUManager)newValue);
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
			case ZPSConfigurationPackage.APDU__ID:
				unsetId();
				return;
			case ZPSConfigurationPackage.APDU__NAME:
				setName(NAME_EDEFAULT);
				return;
			case ZPSConfigurationPackage.APDU__SIZE:
				setSize(SIZE_EDEFAULT);
				return;
			case ZPSConfigurationPackage.APDU__INSTANCES:
				setInstances(INSTANCES_EDEFAULT);
				return;
			case ZPSConfigurationPackage.APDU__PDU_CONFIG:
				setPDUConfig((PDUManager)null);
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
			case ZPSConfigurationPackage.APDU__ID:
				return isSetId();
			case ZPSConfigurationPackage.APDU__NAME:
				return NAME_EDEFAULT == null ? name != null : !NAME_EDEFAULT.equals(name);
			case ZPSConfigurationPackage.APDU__SIZE:
				return size != SIZE_EDEFAULT;
			case ZPSConfigurationPackage.APDU__INSTANCES:
				return instances != INSTANCES_EDEFAULT;
			case ZPSConfigurationPackage.APDU__PDU_CONFIG:
				return getPDUConfig() != null;
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
		result.append(" (Name: ");
		result.append(name);
		result.append(", Size: ");
		result.append(size);
		result.append(", Instances: ");
		result.append(instances);
		result.append(')');
		return result.toString();
	}

} //APDUImpl
