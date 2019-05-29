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

import com.jennic.ZPSConfiguration.AlwaysOnNode;
import com.jennic.ZPSConfiguration.TrustCenter;
import com.jennic.ZPSConfiguration.ZPSConfigurationPackage;

/**
 * <!-- begin-user-doc -->
 * An implementation of the model object '<em><b>Always On Node</b></em>'.
 * <!-- end-user-doc -->
 * <p>
 * The following features are implemented:
 * <ul>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.AlwaysOnNodeImpl#getTrustCenter <em>Trust Center</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.AlwaysOnNodeImpl#getPermitJoiningTime <em>Permit Joining Time</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.AlwaysOnNodeImpl#getChildTableSize <em>Child Table Size</em>}</li>
 * </ul>
 * </p>
 *
 * @generated
 */
public abstract class AlwaysOnNodeImpl extends NodeImpl implements AlwaysOnNode {
	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public static final String copyright = "(C) NXP B.V";

	/**
	 * The cached value of the '{@link #getTrustCenter() <em>Trust Center</em>}' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getTrustCenter()
	 * @generated
	 * @ordered
	 */
	protected TrustCenter trustCenter;

	/**
	 * The default value of the '{@link #getPermitJoiningTime() <em>Permit Joining Time</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getPermitJoiningTime()
	 * @generated
	 * @ordered
	 */
	protected static final int PERMIT_JOINING_TIME_EDEFAULT = 255;

	/**
	 * The cached value of the '{@link #getPermitJoiningTime() <em>Permit Joining Time</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getPermitJoiningTime()
	 * @generated
	 * @ordered
	 */
	protected int permitJoiningTime = PERMIT_JOINING_TIME_EDEFAULT;

	/**
	 * The default value of the '{@link #getChildTableSize() <em>Child Table Size</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getChildTableSize()
	 * @generated
	 * @ordered
	 */
	protected static final int CHILD_TABLE_SIZE_EDEFAULT = 6;

	/**
	 * The cached value of the '{@link #getChildTableSize() <em>Child Table Size</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getChildTableSize()
	 * @generated
	 * @ordered
	 */
	protected int childTableSize = CHILD_TABLE_SIZE_EDEFAULT;

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	protected AlwaysOnNodeImpl() {
		super();
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	@Override
	protected EClass eStaticClass() {
		return ZPSConfigurationPackage.Literals.ALWAYS_ON_NODE;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public TrustCenter getTrustCenter() {
		return trustCenter;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public NotificationChain basicSetTrustCenter(TrustCenter newTrustCenter, NotificationChain msgs) {
		TrustCenter oldTrustCenter = trustCenter;
		trustCenter = newTrustCenter;
		if (eNotificationRequired()) {
			ENotificationImpl notification = new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.ALWAYS_ON_NODE__TRUST_CENTER, oldTrustCenter, newTrustCenter);
			if (msgs == null) msgs = notification; else msgs.add(notification);
		}
		return msgs;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void setTrustCenter(TrustCenter newTrustCenter) {
		if (newTrustCenter != trustCenter) {
			NotificationChain msgs = null;
			if (trustCenter != null)
				msgs = ((InternalEObject)trustCenter).eInverseRemove(this, EOPPOSITE_FEATURE_BASE - ZPSConfigurationPackage.ALWAYS_ON_NODE__TRUST_CENTER, null, msgs);
			if (newTrustCenter != null)
				msgs = ((InternalEObject)newTrustCenter).eInverseAdd(this, EOPPOSITE_FEATURE_BASE - ZPSConfigurationPackage.ALWAYS_ON_NODE__TRUST_CENTER, null, msgs);
			msgs = basicSetTrustCenter(newTrustCenter, msgs);
			if (msgs != null) msgs.dispatch();
		}
		else if (eNotificationRequired())
			eNotify(new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.ALWAYS_ON_NODE__TRUST_CENTER, newTrustCenter, newTrustCenter));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public int getPermitJoiningTime() {
		return permitJoiningTime;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void setPermitJoiningTime(int newPermitJoiningTime) {
		int oldPermitJoiningTime = permitJoiningTime;
		permitJoiningTime = newPermitJoiningTime;
		if (eNotificationRequired())
			eNotify(new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.ALWAYS_ON_NODE__PERMIT_JOINING_TIME, oldPermitJoiningTime, permitJoiningTime));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public int getChildTableSize() {
		return childTableSize;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void setChildTableSize(int newChildTableSize) {
		int oldChildTableSize = childTableSize;
		childTableSize = newChildTableSize;
		if (eNotificationRequired())
			eNotify(new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.ALWAYS_ON_NODE__CHILD_TABLE_SIZE, oldChildTableSize, childTableSize));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	@Override
	public NotificationChain eInverseRemove(InternalEObject otherEnd, int featureID, NotificationChain msgs) {
		switch (featureID) {
			case ZPSConfigurationPackage.ALWAYS_ON_NODE__TRUST_CENTER:
				return basicSetTrustCenter(null, msgs);
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
			case ZPSConfigurationPackage.ALWAYS_ON_NODE__TRUST_CENTER:
				return getTrustCenter();
			case ZPSConfigurationPackage.ALWAYS_ON_NODE__PERMIT_JOINING_TIME:
				return getPermitJoiningTime();
			case ZPSConfigurationPackage.ALWAYS_ON_NODE__CHILD_TABLE_SIZE:
				return getChildTableSize();
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
			case ZPSConfigurationPackage.ALWAYS_ON_NODE__TRUST_CENTER:
				setTrustCenter((TrustCenter)newValue);
				return;
			case ZPSConfigurationPackage.ALWAYS_ON_NODE__PERMIT_JOINING_TIME:
				setPermitJoiningTime((Integer)newValue);
				return;
			case ZPSConfigurationPackage.ALWAYS_ON_NODE__CHILD_TABLE_SIZE:
				setChildTableSize((Integer)newValue);
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
			case ZPSConfigurationPackage.ALWAYS_ON_NODE__TRUST_CENTER:
				setTrustCenter((TrustCenter)null);
				return;
			case ZPSConfigurationPackage.ALWAYS_ON_NODE__PERMIT_JOINING_TIME:
				setPermitJoiningTime(PERMIT_JOINING_TIME_EDEFAULT);
				return;
			case ZPSConfigurationPackage.ALWAYS_ON_NODE__CHILD_TABLE_SIZE:
				setChildTableSize(CHILD_TABLE_SIZE_EDEFAULT);
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
			case ZPSConfigurationPackage.ALWAYS_ON_NODE__TRUST_CENTER:
				return trustCenter != null;
			case ZPSConfigurationPackage.ALWAYS_ON_NODE__PERMIT_JOINING_TIME:
				return permitJoiningTime != PERMIT_JOINING_TIME_EDEFAULT;
			case ZPSConfigurationPackage.ALWAYS_ON_NODE__CHILD_TABLE_SIZE:
				return childTableSize != CHILD_TABLE_SIZE_EDEFAULT;
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
		result.append(" (PermitJoiningTime: ");
		result.append(permitJoiningTime);
		result.append(", ChildTableSize: ");
		result.append(childTableSize);
		result.append(')');
		return result.toString();
	}

} //AlwaysOnNodeImpl
