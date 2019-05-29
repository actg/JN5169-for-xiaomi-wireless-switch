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

import com.jennic.ZPSConfiguration.APDU;
import com.jennic.ZPSConfiguration.Node;
import com.jennic.ZPSConfiguration.PDUManager;
import com.jennic.ZPSConfiguration.ZPSConfigurationPackage;

/**
 * <!-- begin-user-doc -->
 * An implementation of the model object '<em><b>PDU Manager</b></em>'.
 * <!-- end-user-doc -->
 * <p>
 * The following features are implemented:
 * <ul>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.PDUManagerImpl#getAPDUs <em>APD Us</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.PDUManagerImpl#getContainerNode <em>Container Node</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.PDUManagerImpl#getNumNPDUs <em>Num NPD Us</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.PDUManagerImpl#getPDUMMutexName <em>PDUM Mutex Name</em>}</li>
 * </ul>
 * </p>
 *
 * @generated
 */
public class PDUManagerImpl extends EObjectImpl implements PDUManager {
	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public static final String copyright = "(C) NXP B.V";

	/**
	 * The cached value of the '{@link #getAPDUs() <em>APD Us</em>}' containment reference list.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getAPDUs()
	 * @generated
	 * @ordered
	 */
	protected EList<APDU> apdUs;

	/**
	 * The default value of the '{@link #getNumNPDUs() <em>Num NPD Us</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getNumNPDUs()
	 * @generated
	 * @ordered
	 */
	protected static final int NUM_NPD_US_EDEFAULT = 25;

	/**
	 * The cached value of the '{@link #getNumNPDUs() <em>Num NPD Us</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getNumNPDUs()
	 * @generated
	 * @ordered
	 */
	protected int numNPDUs = NUM_NPD_US_EDEFAULT;

	/**
	 * The default value of the '{@link #getPDUMMutexName() <em>PDUM Mutex Name</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getPDUMMutexName()
	 * @generated
	 * @ordered
	 */
	protected static final String PDUM_MUTEX_NAME_EDEFAULT = "mutexPDUM";

	/**
	 * The cached value of the '{@link #getPDUMMutexName() <em>PDUM Mutex Name</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getPDUMMutexName()
	 * @generated
	 * @ordered
	 */
	protected String pdumMutexName = PDUM_MUTEX_NAME_EDEFAULT;

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	protected PDUManagerImpl() {
		super();
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	@Override
	protected EClass eStaticClass() {
		return ZPSConfigurationPackage.Literals.PDU_MANAGER;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EList<APDU> getAPDUs() {
		if (apdUs == null) {
			apdUs = new EObjectContainmentWithInverseEList<APDU>(APDU.class, this, ZPSConfigurationPackage.PDU_MANAGER__APD_US, ZPSConfigurationPackage.APDU__PDU_CONFIG);
		}
		return apdUs;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public Node getContainerNode() {
		if (eContainerFeatureID() != ZPSConfigurationPackage.PDU_MANAGER__CONTAINER_NODE) return null;
		return (Node)eInternalContainer();
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public NotificationChain basicSetContainerNode(Node newContainerNode, NotificationChain msgs) {
		msgs = eBasicSetContainer((InternalEObject)newContainerNode, ZPSConfigurationPackage.PDU_MANAGER__CONTAINER_NODE, msgs);
		return msgs;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void setContainerNode(Node newContainerNode) {
		if (newContainerNode != eInternalContainer() || (eContainerFeatureID() != ZPSConfigurationPackage.PDU_MANAGER__CONTAINER_NODE && newContainerNode != null)) {
			if (EcoreUtil.isAncestor(this, newContainerNode))
				throw new IllegalArgumentException("Recursive containment not allowed for " + toString());
			NotificationChain msgs = null;
			if (eInternalContainer() != null)
				msgs = eBasicRemoveFromContainer(msgs);
			if (newContainerNode != null)
				msgs = ((InternalEObject)newContainerNode).eInverseAdd(this, ZPSConfigurationPackage.NODE__PDU_CONFIGURATION, Node.class, msgs);
			msgs = basicSetContainerNode(newContainerNode, msgs);
			if (msgs != null) msgs.dispatch();
		}
		else if (eNotificationRequired())
			eNotify(new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.PDU_MANAGER__CONTAINER_NODE, newContainerNode, newContainerNode));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public int getNumNPDUs() {
		return numNPDUs;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void setNumNPDUs(int newNumNPDUs) {
		int oldNumNPDUs = numNPDUs;
		numNPDUs = newNumNPDUs;
		if (eNotificationRequired())
			eNotify(new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.PDU_MANAGER__NUM_NPD_US, oldNumNPDUs, numNPDUs));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public String getPDUMMutexName() {
		return pdumMutexName;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void setPDUMMutexName(String newPDUMMutexName) {
		String oldPDUMMutexName = pdumMutexName;
		pdumMutexName = newPDUMMutexName;
		if (eNotificationRequired())
			eNotify(new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.PDU_MANAGER__PDUM_MUTEX_NAME, oldPDUMMutexName, pdumMutexName));
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
			case ZPSConfigurationPackage.PDU_MANAGER__APD_US:
				return ((InternalEList<InternalEObject>)(InternalEList<?>)getAPDUs()).basicAdd(otherEnd, msgs);
			case ZPSConfigurationPackage.PDU_MANAGER__CONTAINER_NODE:
				if (eInternalContainer() != null)
					msgs = eBasicRemoveFromContainer(msgs);
				return basicSetContainerNode((Node)otherEnd, msgs);
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
			case ZPSConfigurationPackage.PDU_MANAGER__APD_US:
				return ((InternalEList<?>)getAPDUs()).basicRemove(otherEnd, msgs);
			case ZPSConfigurationPackage.PDU_MANAGER__CONTAINER_NODE:
				return basicSetContainerNode(null, msgs);
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
			case ZPSConfigurationPackage.PDU_MANAGER__CONTAINER_NODE:
				return eInternalContainer().eInverseRemove(this, ZPSConfigurationPackage.NODE__PDU_CONFIGURATION, Node.class, msgs);
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
			case ZPSConfigurationPackage.PDU_MANAGER__APD_US:
				return getAPDUs();
			case ZPSConfigurationPackage.PDU_MANAGER__CONTAINER_NODE:
				return getContainerNode();
			case ZPSConfigurationPackage.PDU_MANAGER__NUM_NPD_US:
				return getNumNPDUs();
			case ZPSConfigurationPackage.PDU_MANAGER__PDUM_MUTEX_NAME:
				return getPDUMMutexName();
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
			case ZPSConfigurationPackage.PDU_MANAGER__APD_US:
				getAPDUs().clear();
				getAPDUs().addAll((Collection<? extends APDU>)newValue);
				return;
			case ZPSConfigurationPackage.PDU_MANAGER__CONTAINER_NODE:
				setContainerNode((Node)newValue);
				return;
			case ZPSConfigurationPackage.PDU_MANAGER__NUM_NPD_US:
				setNumNPDUs((Integer)newValue);
				return;
			case ZPSConfigurationPackage.PDU_MANAGER__PDUM_MUTEX_NAME:
				setPDUMMutexName((String)newValue);
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
			case ZPSConfigurationPackage.PDU_MANAGER__APD_US:
				getAPDUs().clear();
				return;
			case ZPSConfigurationPackage.PDU_MANAGER__CONTAINER_NODE:
				setContainerNode((Node)null);
				return;
			case ZPSConfigurationPackage.PDU_MANAGER__NUM_NPD_US:
				setNumNPDUs(NUM_NPD_US_EDEFAULT);
				return;
			case ZPSConfigurationPackage.PDU_MANAGER__PDUM_MUTEX_NAME:
				setPDUMMutexName(PDUM_MUTEX_NAME_EDEFAULT);
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
			case ZPSConfigurationPackage.PDU_MANAGER__APD_US:
				return apdUs != null && !apdUs.isEmpty();
			case ZPSConfigurationPackage.PDU_MANAGER__CONTAINER_NODE:
				return getContainerNode() != null;
			case ZPSConfigurationPackage.PDU_MANAGER__NUM_NPD_US:
				return numNPDUs != NUM_NPD_US_EDEFAULT;
			case ZPSConfigurationPackage.PDU_MANAGER__PDUM_MUTEX_NAME:
				return PDUM_MUTEX_NAME_EDEFAULT == null ? pdumMutexName != null : !PDUM_MUTEX_NAME_EDEFAULT.equals(pdumMutexName);
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
		result.append(" (NumNPDUs: ");
		result.append(numNPDUs);
		result.append(", PDUMMutexName: ");
		result.append(pdumMutexName);
		result.append(')');
		return result.toString();
	}

} //PDUManagerImpl
