/**
 * (C) Jennic Ltd
 *
 * $Id$
 */
package com.jennic.ZPSConfiguration.impl;


import com.jennic.ZPSConfiguration.APDU;
import org.eclipse.emf.common.notify.Notification;

import org.eclipse.emf.common.notify.NotificationChain;
import org.eclipse.emf.common.util.EList;
import org.eclipse.emf.ecore.EClass;
import org.eclipse.emf.ecore.InternalEObject;

import org.eclipse.emf.ecore.impl.ENotificationImpl;
import org.eclipse.emf.ecore.impl.EObjectImpl;
import org.eclipse.emf.ecore.util.EObjectResolvingEList;
import org.eclipse.emf.ecore.util.EcoreUtil;

import com.jennic.ZPSConfiguration.Cluster;
import com.jennic.ZPSConfiguration.EndPoint;
import com.jennic.ZPSConfiguration.OutputCluster;
import com.jennic.ZPSConfiguration.ZPSConfigurationPackage;
import java.util.Collection;

/**
 * <!-- begin-user-doc -->
 * An implementation of the model object '<em><b>Output Cluster</b></em>'.
 * <!-- end-user-doc -->
 * <p>
 * The following features are implemented:
 * <ul>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.OutputClusterImpl#getCluster <em>Cluster</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.OutputClusterImpl#getEndPoint <em>End Point</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.OutputClusterImpl#getTxAPDUs <em>Tx APD Us</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.OutputClusterImpl#isDiscoverable <em>Discoverable</em>}</li>
 * </ul>
 * </p>
 *
 * @generated
 */
public class OutputClusterImpl extends EObjectImpl implements OutputCluster {
	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public static final String copyright = "(C) NXP B.V";

	/**
	 * The cached value of the '{@link #getCluster() <em>Cluster</em>}' reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getCluster()
	 * @generated
	 * @ordered
	 */
	protected Cluster cluster;

	/**
	 * The cached value of the '{@link #getTxAPDUs() <em>Tx APD Us</em>}' reference list.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getTxAPDUs()
	 * @generated
	 * @ordered
	 */
	protected EList<APDU> txAPDUs;

	/**
	 * The default value of the '{@link #isDiscoverable() <em>Discoverable</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #isDiscoverable()
	 * @generated
	 * @ordered
	 */
	protected static final boolean DISCOVERABLE_EDEFAULT = true;

	/**
	 * The cached value of the '{@link #isDiscoverable() <em>Discoverable</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #isDiscoverable()
	 * @generated
	 * @ordered
	 */
	protected boolean discoverable = DISCOVERABLE_EDEFAULT;

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	protected OutputClusterImpl() {
		super();
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	@Override
	protected EClass eStaticClass() {
		return ZPSConfigurationPackage.Literals.OUTPUT_CLUSTER;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public Cluster getCluster() {
		if (cluster != null && cluster.eIsProxy()) {
			InternalEObject oldCluster = (InternalEObject)cluster;
			cluster = (Cluster)eResolveProxy(oldCluster);
			if (cluster != oldCluster) {
				if (eNotificationRequired())
					eNotify(new ENotificationImpl(this, Notification.RESOLVE, ZPSConfigurationPackage.OUTPUT_CLUSTER__CLUSTER, oldCluster, cluster));
			}
		}
		return cluster;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public Cluster basicGetCluster() {
		return cluster;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void setCluster(Cluster newCluster) {
		Cluster oldCluster = cluster;
		cluster = newCluster;
		if (eNotificationRequired())
			eNotify(new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.OUTPUT_CLUSTER__CLUSTER, oldCluster, cluster));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EndPoint getEndPoint() {
		if (eContainerFeatureID() != ZPSConfigurationPackage.OUTPUT_CLUSTER__END_POINT) return null;
		return (EndPoint)eInternalContainer();
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public NotificationChain basicSetEndPoint(EndPoint newEndPoint, NotificationChain msgs) {
		msgs = eBasicSetContainer((InternalEObject)newEndPoint, ZPSConfigurationPackage.OUTPUT_CLUSTER__END_POINT, msgs);
		return msgs;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void setEndPoint(EndPoint newEndPoint) {
		if (newEndPoint != eInternalContainer() || (eContainerFeatureID() != ZPSConfigurationPackage.OUTPUT_CLUSTER__END_POINT && newEndPoint != null)) {
			if (EcoreUtil.isAncestor(this, newEndPoint))
				throw new IllegalArgumentException("Recursive containment not allowed for " + toString());
			NotificationChain msgs = null;
			if (eInternalContainer() != null)
				msgs = eBasicRemoveFromContainer(msgs);
			if (newEndPoint != null)
				msgs = ((InternalEObject)newEndPoint).eInverseAdd(this, ZPSConfigurationPackage.END_POINT__OUTPUT_CLUSTERS, EndPoint.class, msgs);
			msgs = basicSetEndPoint(newEndPoint, msgs);
			if (msgs != null) msgs.dispatch();
		}
		else if (eNotificationRequired())
			eNotify(new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.OUTPUT_CLUSTER__END_POINT, newEndPoint, newEndPoint));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EList<APDU> getTxAPDUs() {
		if (txAPDUs == null) {
			txAPDUs = new EObjectResolvingEList<APDU>(APDU.class, this, ZPSConfigurationPackage.OUTPUT_CLUSTER__TX_APD_US);
		}
		return txAPDUs;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public boolean isDiscoverable() {
		return discoverable;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void setDiscoverable(boolean newDiscoverable) {
		boolean oldDiscoverable = discoverable;
		discoverable = newDiscoverable;
		if (eNotificationRequired())
			eNotify(new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.OUTPUT_CLUSTER__DISCOVERABLE, oldDiscoverable, discoverable));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	@Override
	public NotificationChain eInverseAdd(InternalEObject otherEnd, int featureID, NotificationChain msgs) {
		switch (featureID) {
			case ZPSConfigurationPackage.OUTPUT_CLUSTER__END_POINT:
				if (eInternalContainer() != null)
					msgs = eBasicRemoveFromContainer(msgs);
				return basicSetEndPoint((EndPoint)otherEnd, msgs);
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
			case ZPSConfigurationPackage.OUTPUT_CLUSTER__END_POINT:
				return basicSetEndPoint(null, msgs);
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
			case ZPSConfigurationPackage.OUTPUT_CLUSTER__END_POINT:
				return eInternalContainer().eInverseRemove(this, ZPSConfigurationPackage.END_POINT__OUTPUT_CLUSTERS, EndPoint.class, msgs);
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
			case ZPSConfigurationPackage.OUTPUT_CLUSTER__CLUSTER:
				if (resolve) return getCluster();
				return basicGetCluster();
			case ZPSConfigurationPackage.OUTPUT_CLUSTER__END_POINT:
				return getEndPoint();
			case ZPSConfigurationPackage.OUTPUT_CLUSTER__TX_APD_US:
				return getTxAPDUs();
			case ZPSConfigurationPackage.OUTPUT_CLUSTER__DISCOVERABLE:
				return isDiscoverable();
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
			case ZPSConfigurationPackage.OUTPUT_CLUSTER__CLUSTER:
				setCluster((Cluster)newValue);
				return;
			case ZPSConfigurationPackage.OUTPUT_CLUSTER__END_POINT:
				setEndPoint((EndPoint)newValue);
				return;
			case ZPSConfigurationPackage.OUTPUT_CLUSTER__TX_APD_US:
				getTxAPDUs().clear();
				getTxAPDUs().addAll((Collection<? extends APDU>)newValue);
				return;
			case ZPSConfigurationPackage.OUTPUT_CLUSTER__DISCOVERABLE:
				setDiscoverable((Boolean)newValue);
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
			case ZPSConfigurationPackage.OUTPUT_CLUSTER__CLUSTER:
				setCluster((Cluster)null);
				return;
			case ZPSConfigurationPackage.OUTPUT_CLUSTER__END_POINT:
				setEndPoint((EndPoint)null);
				return;
			case ZPSConfigurationPackage.OUTPUT_CLUSTER__TX_APD_US:
				getTxAPDUs().clear();
				return;
			case ZPSConfigurationPackage.OUTPUT_CLUSTER__DISCOVERABLE:
				setDiscoverable(DISCOVERABLE_EDEFAULT);
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
			case ZPSConfigurationPackage.OUTPUT_CLUSTER__CLUSTER:
				return cluster != null;
			case ZPSConfigurationPackage.OUTPUT_CLUSTER__END_POINT:
				return getEndPoint() != null;
			case ZPSConfigurationPackage.OUTPUT_CLUSTER__TX_APD_US:
				return txAPDUs != null && !txAPDUs.isEmpty();
			case ZPSConfigurationPackage.OUTPUT_CLUSTER__DISCOVERABLE:
				return discoverable != DISCOVERABLE_EDEFAULT;
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
		result.append(" (Discoverable: ");
		result.append(discoverable);
		result.append(')');
		return result.toString();
	}

} //OutputClusterImpl
