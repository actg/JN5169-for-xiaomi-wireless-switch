/**
 * (C) Jennic Ltd
 *
 * $Id$
 */
package com.jennic.ZPSConfiguration.impl;


import com.jennic.ZPSConfiguration.MgmtMibIeeeServer;
import org.eclipse.emf.common.notify.Notification;
import org.eclipse.emf.common.notify.NotificationChain;

import org.eclipse.emf.ecore.EClass;
import org.eclipse.emf.ecore.InternalEObject;

import org.eclipse.emf.ecore.impl.ENotificationImpl;

import com.jennic.ZPSConfiguration.MgmtRtgServer;
import com.jennic.ZPSConfiguration.ParentAnnceServer;
import com.jennic.ZPSConfiguration.PermitJoiningServer;
import com.jennic.ZPSConfiguration.ZDOCoordRouterOnlyServers;
import com.jennic.ZPSConfiguration.ZDOServersRouter;
import com.jennic.ZPSConfiguration.ZPSConfigurationPackage;

/**
 * <!-- begin-user-doc -->
 * An implementation of the model object '<em><b>ZDO Servers Router</b></em>'.
 * <!-- end-user-doc -->
 * <p>
 * The following features are implemented:
 * <ul>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.ZDOServersRouterImpl#getPermitJoiningServer <em>Permit Joining Server</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.ZDOServersRouterImpl#getMgmtRtgServer <em>Mgmt Rtg Server</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.ZDOServersRouterImpl#getMgmtMibIeeeServer <em>Mgmt Mib Ieee Server</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.ZDOServersRouterImpl#getParentAnnceServer <em>Parent Annce Server</em>}</li>
 * </ul>
 * </p>
 *
 * @generated
 */
public class ZDOServersRouterImpl extends ZDOCommonServersImpl implements ZDOServersRouter {
	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public static final String copyright = "(C) NXP B.V";

	/**
	 * The cached value of the '{@link #getPermitJoiningServer() <em>Permit Joining Server</em>}' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getPermitJoiningServer()
	 * @generated
	 * @ordered
	 */
	protected PermitJoiningServer permitJoiningServer;

	/**
	 * The cached value of the '{@link #getMgmtRtgServer() <em>Mgmt Rtg Server</em>}' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getMgmtRtgServer()
	 * @generated
	 * @ordered
	 */
	protected MgmtRtgServer mgmtRtgServer;

	/**
	 * The cached value of the '{@link #getMgmtMibIeeeServer() <em>Mgmt Mib Ieee Server</em>}' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getMgmtMibIeeeServer()
	 * @generated
	 * @ordered
	 */
	protected MgmtMibIeeeServer mgmtMibIeeeServer;

	/**
	 * The cached value of the '{@link #getParentAnnceServer() <em>Parent Annce Server</em>}' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getParentAnnceServer()
	 * @generated
	 * @ordered
	 */
	protected ParentAnnceServer parentAnnceServer;

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	protected ZDOServersRouterImpl() {
		super();
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	@Override
	protected EClass eStaticClass() {
		return ZPSConfigurationPackage.Literals.ZDO_SERVERS_ROUTER;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public PermitJoiningServer getPermitJoiningServer() {
		return permitJoiningServer;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public NotificationChain basicSetPermitJoiningServer(PermitJoiningServer newPermitJoiningServer, NotificationChain msgs) {
		PermitJoiningServer oldPermitJoiningServer = permitJoiningServer;
		permitJoiningServer = newPermitJoiningServer;
		if (eNotificationRequired()) {
			ENotificationImpl notification = new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.ZDO_SERVERS_ROUTER__PERMIT_JOINING_SERVER, oldPermitJoiningServer, newPermitJoiningServer);
			if (msgs == null) msgs = notification; else msgs.add(notification);
		}
		return msgs;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void setPermitJoiningServer(PermitJoiningServer newPermitJoiningServer) {
		if (newPermitJoiningServer != permitJoiningServer) {
			NotificationChain msgs = null;
			if (permitJoiningServer != null)
				msgs = ((InternalEObject)permitJoiningServer).eInverseRemove(this, EOPPOSITE_FEATURE_BASE - ZPSConfigurationPackage.ZDO_SERVERS_ROUTER__PERMIT_JOINING_SERVER, null, msgs);
			if (newPermitJoiningServer != null)
				msgs = ((InternalEObject)newPermitJoiningServer).eInverseAdd(this, EOPPOSITE_FEATURE_BASE - ZPSConfigurationPackage.ZDO_SERVERS_ROUTER__PERMIT_JOINING_SERVER, null, msgs);
			msgs = basicSetPermitJoiningServer(newPermitJoiningServer, msgs);
			if (msgs != null) msgs.dispatch();
		}
		else if (eNotificationRequired())
			eNotify(new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.ZDO_SERVERS_ROUTER__PERMIT_JOINING_SERVER, newPermitJoiningServer, newPermitJoiningServer));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public MgmtRtgServer getMgmtRtgServer() {
		return mgmtRtgServer;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public NotificationChain basicSetMgmtRtgServer(MgmtRtgServer newMgmtRtgServer, NotificationChain msgs) {
		MgmtRtgServer oldMgmtRtgServer = mgmtRtgServer;
		mgmtRtgServer = newMgmtRtgServer;
		if (eNotificationRequired()) {
			ENotificationImpl notification = new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.ZDO_SERVERS_ROUTER__MGMT_RTG_SERVER, oldMgmtRtgServer, newMgmtRtgServer);
			if (msgs == null) msgs = notification; else msgs.add(notification);
		}
		return msgs;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void setMgmtRtgServer(MgmtRtgServer newMgmtRtgServer) {
		if (newMgmtRtgServer != mgmtRtgServer) {
			NotificationChain msgs = null;
			if (mgmtRtgServer != null)
				msgs = ((InternalEObject)mgmtRtgServer).eInverseRemove(this, EOPPOSITE_FEATURE_BASE - ZPSConfigurationPackage.ZDO_SERVERS_ROUTER__MGMT_RTG_SERVER, null, msgs);
			if (newMgmtRtgServer != null)
				msgs = ((InternalEObject)newMgmtRtgServer).eInverseAdd(this, EOPPOSITE_FEATURE_BASE - ZPSConfigurationPackage.ZDO_SERVERS_ROUTER__MGMT_RTG_SERVER, null, msgs);
			msgs = basicSetMgmtRtgServer(newMgmtRtgServer, msgs);
			if (msgs != null) msgs.dispatch();
		}
		else if (eNotificationRequired())
			eNotify(new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.ZDO_SERVERS_ROUTER__MGMT_RTG_SERVER, newMgmtRtgServer, newMgmtRtgServer));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public MgmtMibIeeeServer getMgmtMibIeeeServer() {
		return mgmtMibIeeeServer;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public NotificationChain basicSetMgmtMibIeeeServer(MgmtMibIeeeServer newMgmtMibIeeeServer, NotificationChain msgs) {
		MgmtMibIeeeServer oldMgmtMibIeeeServer = mgmtMibIeeeServer;
		mgmtMibIeeeServer = newMgmtMibIeeeServer;
		if (eNotificationRequired()) {
			ENotificationImpl notification = new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.ZDO_SERVERS_ROUTER__MGMT_MIB_IEEE_SERVER, oldMgmtMibIeeeServer, newMgmtMibIeeeServer);
			if (msgs == null) msgs = notification; else msgs.add(notification);
		}
		return msgs;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void setMgmtMibIeeeServer(MgmtMibIeeeServer newMgmtMibIeeeServer) {
		if (newMgmtMibIeeeServer != mgmtMibIeeeServer) {
			NotificationChain msgs = null;
			if (mgmtMibIeeeServer != null)
				msgs = ((InternalEObject)mgmtMibIeeeServer).eInverseRemove(this, EOPPOSITE_FEATURE_BASE - ZPSConfigurationPackage.ZDO_SERVERS_ROUTER__MGMT_MIB_IEEE_SERVER, null, msgs);
			if (newMgmtMibIeeeServer != null)
				msgs = ((InternalEObject)newMgmtMibIeeeServer).eInverseAdd(this, EOPPOSITE_FEATURE_BASE - ZPSConfigurationPackage.ZDO_SERVERS_ROUTER__MGMT_MIB_IEEE_SERVER, null, msgs);
			msgs = basicSetMgmtMibIeeeServer(newMgmtMibIeeeServer, msgs);
			if (msgs != null) msgs.dispatch();
		}
		else if (eNotificationRequired())
			eNotify(new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.ZDO_SERVERS_ROUTER__MGMT_MIB_IEEE_SERVER, newMgmtMibIeeeServer, newMgmtMibIeeeServer));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public ParentAnnceServer getParentAnnceServer() {
		return parentAnnceServer;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public NotificationChain basicSetParentAnnceServer(ParentAnnceServer newParentAnnceServer, NotificationChain msgs) {
		ParentAnnceServer oldParentAnnceServer = parentAnnceServer;
		parentAnnceServer = newParentAnnceServer;
		if (eNotificationRequired()) {
			ENotificationImpl notification = new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.ZDO_SERVERS_ROUTER__PARENT_ANNCE_SERVER, oldParentAnnceServer, newParentAnnceServer);
			if (msgs == null) msgs = notification; else msgs.add(notification);
		}
		return msgs;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void setParentAnnceServer(ParentAnnceServer newParentAnnceServer) {
		if (newParentAnnceServer != parentAnnceServer) {
			NotificationChain msgs = null;
			if (parentAnnceServer != null)
				msgs = ((InternalEObject)parentAnnceServer).eInverseRemove(this, EOPPOSITE_FEATURE_BASE - ZPSConfigurationPackage.ZDO_SERVERS_ROUTER__PARENT_ANNCE_SERVER, null, msgs);
			if (newParentAnnceServer != null)
				msgs = ((InternalEObject)newParentAnnceServer).eInverseAdd(this, EOPPOSITE_FEATURE_BASE - ZPSConfigurationPackage.ZDO_SERVERS_ROUTER__PARENT_ANNCE_SERVER, null, msgs);
			msgs = basicSetParentAnnceServer(newParentAnnceServer, msgs);
			if (msgs != null) msgs.dispatch();
		}
		else if (eNotificationRequired())
			eNotify(new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.ZDO_SERVERS_ROUTER__PARENT_ANNCE_SERVER, newParentAnnceServer, newParentAnnceServer));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	@Override
	public NotificationChain eInverseRemove(InternalEObject otherEnd, int featureID, NotificationChain msgs) {
		switch (featureID) {
			case ZPSConfigurationPackage.ZDO_SERVERS_ROUTER__PERMIT_JOINING_SERVER:
				return basicSetPermitJoiningServer(null, msgs);
			case ZPSConfigurationPackage.ZDO_SERVERS_ROUTER__MGMT_RTG_SERVER:
				return basicSetMgmtRtgServer(null, msgs);
			case ZPSConfigurationPackage.ZDO_SERVERS_ROUTER__MGMT_MIB_IEEE_SERVER:
				return basicSetMgmtMibIeeeServer(null, msgs);
			case ZPSConfigurationPackage.ZDO_SERVERS_ROUTER__PARENT_ANNCE_SERVER:
				return basicSetParentAnnceServer(null, msgs);
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
			case ZPSConfigurationPackage.ZDO_SERVERS_ROUTER__PERMIT_JOINING_SERVER:
				return getPermitJoiningServer();
			case ZPSConfigurationPackage.ZDO_SERVERS_ROUTER__MGMT_RTG_SERVER:
				return getMgmtRtgServer();
			case ZPSConfigurationPackage.ZDO_SERVERS_ROUTER__MGMT_MIB_IEEE_SERVER:
				return getMgmtMibIeeeServer();
			case ZPSConfigurationPackage.ZDO_SERVERS_ROUTER__PARENT_ANNCE_SERVER:
				return getParentAnnceServer();
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
			case ZPSConfigurationPackage.ZDO_SERVERS_ROUTER__PERMIT_JOINING_SERVER:
				setPermitJoiningServer((PermitJoiningServer)newValue);
				return;
			case ZPSConfigurationPackage.ZDO_SERVERS_ROUTER__MGMT_RTG_SERVER:
				setMgmtRtgServer((MgmtRtgServer)newValue);
				return;
			case ZPSConfigurationPackage.ZDO_SERVERS_ROUTER__MGMT_MIB_IEEE_SERVER:
				setMgmtMibIeeeServer((MgmtMibIeeeServer)newValue);
				return;
			case ZPSConfigurationPackage.ZDO_SERVERS_ROUTER__PARENT_ANNCE_SERVER:
				setParentAnnceServer((ParentAnnceServer)newValue);
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
			case ZPSConfigurationPackage.ZDO_SERVERS_ROUTER__PERMIT_JOINING_SERVER:
				setPermitJoiningServer((PermitJoiningServer)null);
				return;
			case ZPSConfigurationPackage.ZDO_SERVERS_ROUTER__MGMT_RTG_SERVER:
				setMgmtRtgServer((MgmtRtgServer)null);
				return;
			case ZPSConfigurationPackage.ZDO_SERVERS_ROUTER__MGMT_MIB_IEEE_SERVER:
				setMgmtMibIeeeServer((MgmtMibIeeeServer)null);
				return;
			case ZPSConfigurationPackage.ZDO_SERVERS_ROUTER__PARENT_ANNCE_SERVER:
				setParentAnnceServer((ParentAnnceServer)null);
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
			case ZPSConfigurationPackage.ZDO_SERVERS_ROUTER__PERMIT_JOINING_SERVER:
				return permitJoiningServer != null;
			case ZPSConfigurationPackage.ZDO_SERVERS_ROUTER__MGMT_RTG_SERVER:
				return mgmtRtgServer != null;
			case ZPSConfigurationPackage.ZDO_SERVERS_ROUTER__MGMT_MIB_IEEE_SERVER:
				return mgmtMibIeeeServer != null;
			case ZPSConfigurationPackage.ZDO_SERVERS_ROUTER__PARENT_ANNCE_SERVER:
				return parentAnnceServer != null;
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
		if (baseClass == ZDOCoordRouterOnlyServers.class) {
			switch (derivedFeatureID) {
				case ZPSConfigurationPackage.ZDO_SERVERS_ROUTER__PERMIT_JOINING_SERVER: return ZPSConfigurationPackage.ZDO_COORD_ROUTER_ONLY_SERVERS__PERMIT_JOINING_SERVER;
				case ZPSConfigurationPackage.ZDO_SERVERS_ROUTER__MGMT_RTG_SERVER: return ZPSConfigurationPackage.ZDO_COORD_ROUTER_ONLY_SERVERS__MGMT_RTG_SERVER;
				case ZPSConfigurationPackage.ZDO_SERVERS_ROUTER__MGMT_MIB_IEEE_SERVER: return ZPSConfigurationPackage.ZDO_COORD_ROUTER_ONLY_SERVERS__MGMT_MIB_IEEE_SERVER;
				case ZPSConfigurationPackage.ZDO_SERVERS_ROUTER__PARENT_ANNCE_SERVER: return ZPSConfigurationPackage.ZDO_COORD_ROUTER_ONLY_SERVERS__PARENT_ANNCE_SERVER;
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
		if (baseClass == ZDOCoordRouterOnlyServers.class) {
			switch (baseFeatureID) {
				case ZPSConfigurationPackage.ZDO_COORD_ROUTER_ONLY_SERVERS__PERMIT_JOINING_SERVER: return ZPSConfigurationPackage.ZDO_SERVERS_ROUTER__PERMIT_JOINING_SERVER;
				case ZPSConfigurationPackage.ZDO_COORD_ROUTER_ONLY_SERVERS__MGMT_RTG_SERVER: return ZPSConfigurationPackage.ZDO_SERVERS_ROUTER__MGMT_RTG_SERVER;
				case ZPSConfigurationPackage.ZDO_COORD_ROUTER_ONLY_SERVERS__MGMT_MIB_IEEE_SERVER: return ZPSConfigurationPackage.ZDO_SERVERS_ROUTER__MGMT_MIB_IEEE_SERVER;
				case ZPSConfigurationPackage.ZDO_COORD_ROUTER_ONLY_SERVERS__PARENT_ANNCE_SERVER: return ZPSConfigurationPackage.ZDO_SERVERS_ROUTER__PARENT_ANNCE_SERVER;
				default: return -1;
			}
		}
		return super.eDerivedStructuralFeatureID(baseFeatureID, baseClass);
	}

} //ZDOServersRouterImpl
