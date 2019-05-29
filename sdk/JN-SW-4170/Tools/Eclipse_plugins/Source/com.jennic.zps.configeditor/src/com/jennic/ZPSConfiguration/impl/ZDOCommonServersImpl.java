/**
 * (C) Jennic Ltd
 *
 * $Id: ZDOCommonServersImpl.java 78117 2016-03-24 16:31:23Z nxp29741 $
 */
package com.jennic.ZPSConfiguration.impl;


import org.eclipse.emf.common.notify.Notification;
import org.eclipse.emf.common.notify.NotificationChain;

import org.eclipse.emf.ecore.EClass;
import org.eclipse.emf.ecore.InternalEObject;

import org.eclipse.emf.ecore.impl.ENotificationImpl;
import org.eclipse.emf.ecore.impl.EObjectImpl;

import com.jennic.ZPSConfiguration.ActiveEpServer;
import com.jennic.ZPSConfiguration.BindRequestServer;
import com.jennic.ZPSConfiguration.BindUnbindServer;
import com.jennic.ZPSConfiguration.DefaultServer;
import com.jennic.ZPSConfiguration.DeviceAnnceServer;
import com.jennic.ZPSConfiguration.ExtendedActiveEpServer;
import com.jennic.ZPSConfiguration.ExtendedSimpleDescServer;
import com.jennic.ZPSConfiguration.IeeeAddrServer;
import com.jennic.ZPSConfiguration.MatchDescServer;
import com.jennic.ZPSConfiguration.MgmtBindServer;
import com.jennic.ZPSConfiguration.MgmtLeaveServer;
import com.jennic.ZPSConfiguration.MgmtLqiServer;
import com.jennic.ZPSConfiguration.MgmtMibIeeeServer;
import com.jennic.ZPSConfiguration.MgmtNWKEnhanceUpdateServer;
import com.jennic.ZPSConfiguration.MgmtNWKUpdateServer;
import com.jennic.ZPSConfiguration.NodeDescServer;
import com.jennic.ZPSConfiguration.NwkAddrServer;
import com.jennic.ZPSConfiguration.PowerDescServer;
import com.jennic.ZPSConfiguration.SimpleDescServer;
import com.jennic.ZPSConfiguration.SystemServerDiscoveryServer;
import com.jennic.ZPSConfiguration.ZDOCommonServers;
import com.jennic.ZPSConfiguration.ZPSConfigurationPackage;
import com.jennic.ZPSConfiguration.ZdoClient;

/**
 * <!-- begin-user-doc -->
 * An implementation of the model object '<em><b>ZDO Common Servers</b></em>'.
 * <!-- end-user-doc -->
 * <p>
 * The following features are implemented:
 * <ul>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.ZDOCommonServersImpl#getDefaultServer <em>Default Server</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.ZDOCommonServersImpl#getZdoClient <em>Zdo Client</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.ZDOCommonServersImpl#getDeviceAnnceServer <em>Device Annce Server</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.ZDOCommonServersImpl#getActiveEpServer <em>Active Ep Server</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.ZDOCommonServersImpl#getNwkAddrServer <em>Nwk Addr Server</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.ZDOCommonServersImpl#getIeeeAddrServer <em>Ieee Addr Server</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.ZDOCommonServersImpl#getSystemServerDiscoveryServer <em>System Server Discovery Server</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.ZDOCommonServersImpl#getNodeDescServer <em>Node Desc Server</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.ZDOCommonServersImpl#getPowerDescServer <em>Power Desc Server</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.ZDOCommonServersImpl#getMatchDescServer <em>Match Desc Server</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.ZDOCommonServersImpl#getSimpleDescServer <em>Simple Desc Server</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.ZDOCommonServersImpl#getMgmtLqiServer <em>Mgmt Lqi Server</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.ZDOCommonServersImpl#getMgmtLeaveServer <em>Mgmt Leave Server</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.ZDOCommonServersImpl#getMgmtNWKUpdateServer <em>Mgmt NWK Update Server</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.ZDOCommonServersImpl#getBindUnbindServer <em>Bind Unbind Server</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.ZDOCommonServersImpl#getExtendedActiveEpServer <em>Extended Active Ep Server</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.ZDOCommonServersImpl#getExtendedSimpleDescServer <em>Extended Simple Desc Server</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.ZDOCommonServersImpl#getBindRequestServer <em>Bind Request Server</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.ZDOCommonServersImpl#getMgmtBindServer <em>Mgmt Bind Server</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.ZDOCommonServersImpl#getMgmtNWKEnhanceUpdateServer <em>Mgmt NWK Enhance Update Server</em>}</li>
 * </ul>
 * </p>
 *
 * @generated
 */
public abstract class ZDOCommonServersImpl extends EObjectImpl implements ZDOCommonServers {
	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public static final String copyright = "(C) NXP B.V";

	/**
	 * The cached value of the '{@link #getDefaultServer() <em>Default Server</em>}' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getDefaultServer()
	 * @generated
	 * @ordered
	 */
	protected DefaultServer defaultServer;

	/**
	 * The cached value of the '{@link #getZdoClient() <em>Zdo Client</em>}' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getZdoClient()
	 * @generated
	 * @ordered
	 */
	protected ZdoClient zdoClient;

	/**
	 * The cached value of the '{@link #getDeviceAnnceServer() <em>Device Annce Server</em>}' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getDeviceAnnceServer()
	 * @generated
	 * @ordered
	 */
	protected DeviceAnnceServer deviceAnnceServer;

	/**
	 * The cached value of the '{@link #getActiveEpServer() <em>Active Ep Server</em>}' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getActiveEpServer()
	 * @generated
	 * @ordered
	 */
	protected ActiveEpServer activeEpServer;

	/**
	 * The cached value of the '{@link #getNwkAddrServer() <em>Nwk Addr Server</em>}' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getNwkAddrServer()
	 * @generated
	 * @ordered
	 */
	protected NwkAddrServer nwkAddrServer;

	/**
	 * The cached value of the '{@link #getIeeeAddrServer() <em>Ieee Addr Server</em>}' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getIeeeAddrServer()
	 * @generated
	 * @ordered
	 */
	protected IeeeAddrServer ieeeAddrServer;

	/**
	 * The cached value of the '{@link #getSystemServerDiscoveryServer() <em>System Server Discovery Server</em>}' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getSystemServerDiscoveryServer()
	 * @generated
	 * @ordered
	 */
	protected SystemServerDiscoveryServer systemServerDiscoveryServer;

	/**
	 * The cached value of the '{@link #getNodeDescServer() <em>Node Desc Server</em>}' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getNodeDescServer()
	 * @generated
	 * @ordered
	 */
	protected NodeDescServer nodeDescServer;

	/**
	 * The cached value of the '{@link #getPowerDescServer() <em>Power Desc Server</em>}' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getPowerDescServer()
	 * @generated
	 * @ordered
	 */
	protected PowerDescServer powerDescServer;

	/**
	 * The cached value of the '{@link #getMatchDescServer() <em>Match Desc Server</em>}' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getMatchDescServer()
	 * @generated
	 * @ordered
	 */
	protected MatchDescServer matchDescServer;

	/**
	 * The cached value of the '{@link #getSimpleDescServer() <em>Simple Desc Server</em>}' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getSimpleDescServer()
	 * @generated
	 * @ordered
	 */
	protected SimpleDescServer simpleDescServer;

	/**
	 * The cached value of the '{@link #getMgmtLqiServer() <em>Mgmt Lqi Server</em>}' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getMgmtLqiServer()
	 * @generated
	 * @ordered
	 */
	protected MgmtLqiServer mgmtLqiServer;

	/**
	 * The cached value of the '{@link #getMgmtLeaveServer() <em>Mgmt Leave Server</em>}' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getMgmtLeaveServer()
	 * @generated
	 * @ordered
	 */
	protected MgmtLeaveServer mgmtLeaveServer;

	/**
	 * The cached value of the '{@link #getMgmtNWKUpdateServer() <em>Mgmt NWK Update Server</em>}' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getMgmtNWKUpdateServer()
	 * @generated
	 * @ordered
	 */
	protected MgmtNWKUpdateServer mgmtNWKUpdateServer;

	/**
	 * The cached value of the '{@link #getBindUnbindServer() <em>Bind Unbind Server</em>}' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getBindUnbindServer()
	 * @generated
	 * @ordered
	 */
	protected BindUnbindServer bindUnbindServer;

	/**
	 * The cached value of the '{@link #getExtendedActiveEpServer() <em>Extended Active Ep Server</em>}' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getExtendedActiveEpServer()
	 * @generated
	 * @ordered
	 */
	protected ExtendedActiveEpServer extendedActiveEpServer;

	/**
	 * The cached value of the '{@link #getExtendedSimpleDescServer() <em>Extended Simple Desc Server</em>}' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getExtendedSimpleDescServer()
	 * @generated
	 * @ordered
	 */
	protected ExtendedSimpleDescServer extendedSimpleDescServer;

	/**
	 * The cached value of the '{@link #getBindRequestServer() <em>Bind Request Server</em>}' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getBindRequestServer()
	 * @generated
	 * @ordered
	 */
	protected BindRequestServer bindRequestServer;

	/**
	 * The cached value of the '{@link #getMgmtBindServer() <em>Mgmt Bind Server</em>}' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getMgmtBindServer()
	 * @generated
	 * @ordered
	 */
	protected MgmtBindServer mgmtBindServer;

	/**
	 * The cached value of the '{@link #getMgmtNWKEnhanceUpdateServer() <em>Mgmt NWK Enhance Update Server</em>}' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getMgmtNWKEnhanceUpdateServer()
	 * @generated
	 * @ordered
	 */
	protected MgmtNWKEnhanceUpdateServer mgmtNWKEnhanceUpdateServer;

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	protected ZDOCommonServersImpl() {
		super();
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	@Override
	protected EClass eStaticClass() {
		return ZPSConfigurationPackage.Literals.ZDO_COMMON_SERVERS;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public DefaultServer getDefaultServer() {
		return defaultServer;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public NotificationChain basicSetDefaultServer(DefaultServer newDefaultServer, NotificationChain msgs) {
		DefaultServer oldDefaultServer = defaultServer;
		defaultServer = newDefaultServer;
		if (eNotificationRequired()) {
			ENotificationImpl notification = new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.ZDO_COMMON_SERVERS__DEFAULT_SERVER, oldDefaultServer, newDefaultServer);
			if (msgs == null) msgs = notification; else msgs.add(notification);
		}
		return msgs;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void setDefaultServer(DefaultServer newDefaultServer) {
		if (newDefaultServer != defaultServer) {
			NotificationChain msgs = null;
			if (defaultServer != null)
				msgs = ((InternalEObject)defaultServer).eInverseRemove(this, EOPPOSITE_FEATURE_BASE - ZPSConfigurationPackage.ZDO_COMMON_SERVERS__DEFAULT_SERVER, null, msgs);
			if (newDefaultServer != null)
				msgs = ((InternalEObject)newDefaultServer).eInverseAdd(this, EOPPOSITE_FEATURE_BASE - ZPSConfigurationPackage.ZDO_COMMON_SERVERS__DEFAULT_SERVER, null, msgs);
			msgs = basicSetDefaultServer(newDefaultServer, msgs);
			if (msgs != null) msgs.dispatch();
		}
		else if (eNotificationRequired())
			eNotify(new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.ZDO_COMMON_SERVERS__DEFAULT_SERVER, newDefaultServer, newDefaultServer));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public MgmtNWKUpdateServer getMgmtNWKUpdateServer() {
		return mgmtNWKUpdateServer;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public NotificationChain basicSetMgmtNWKUpdateServer(MgmtNWKUpdateServer newMgmtNWKUpdateServer, NotificationChain msgs) {
		MgmtNWKUpdateServer oldMgmtNWKUpdateServer = mgmtNWKUpdateServer;
		mgmtNWKUpdateServer = newMgmtNWKUpdateServer;
		if (eNotificationRequired()) {
			ENotificationImpl notification = new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.ZDO_COMMON_SERVERS__MGMT_NWK_UPDATE_SERVER, oldMgmtNWKUpdateServer, newMgmtNWKUpdateServer);
			if (msgs == null) msgs = notification; else msgs.add(notification);
		}
		return msgs;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void setMgmtNWKUpdateServer(MgmtNWKUpdateServer newMgmtNWKUpdateServer) {
		if (newMgmtNWKUpdateServer != mgmtNWKUpdateServer) {
			NotificationChain msgs = null;
			if (mgmtNWKUpdateServer != null)
				msgs = ((InternalEObject)mgmtNWKUpdateServer).eInverseRemove(this, EOPPOSITE_FEATURE_BASE - ZPSConfigurationPackage.ZDO_COMMON_SERVERS__MGMT_NWK_UPDATE_SERVER, null, msgs);
			if (newMgmtNWKUpdateServer != null)
				msgs = ((InternalEObject)newMgmtNWKUpdateServer).eInverseAdd(this, EOPPOSITE_FEATURE_BASE - ZPSConfigurationPackage.ZDO_COMMON_SERVERS__MGMT_NWK_UPDATE_SERVER, null, msgs);
			msgs = basicSetMgmtNWKUpdateServer(newMgmtNWKUpdateServer, msgs);
			if (msgs != null) msgs.dispatch();
		}
		else if (eNotificationRequired())
			eNotify(new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.ZDO_COMMON_SERVERS__MGMT_NWK_UPDATE_SERVER, newMgmtNWKUpdateServer, newMgmtNWKUpdateServer));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public ZdoClient getZdoClient() {
		return zdoClient;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public NotificationChain basicSetZdoClient(ZdoClient newZdoClient, NotificationChain msgs) {
		ZdoClient oldZdoClient = zdoClient;
		zdoClient = newZdoClient;
		if (eNotificationRequired()) {
			ENotificationImpl notification = new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.ZDO_COMMON_SERVERS__ZDO_CLIENT, oldZdoClient, newZdoClient);
			if (msgs == null) msgs = notification; else msgs.add(notification);
		}
		return msgs;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void setZdoClient(ZdoClient newZdoClient) {
		if (newZdoClient != zdoClient) {
			NotificationChain msgs = null;
			if (zdoClient != null)
				msgs = ((InternalEObject)zdoClient).eInverseRemove(this, EOPPOSITE_FEATURE_BASE - ZPSConfigurationPackage.ZDO_COMMON_SERVERS__ZDO_CLIENT, null, msgs);
			if (newZdoClient != null)
				msgs = ((InternalEObject)newZdoClient).eInverseAdd(this, EOPPOSITE_FEATURE_BASE - ZPSConfigurationPackage.ZDO_COMMON_SERVERS__ZDO_CLIENT, null, msgs);
			msgs = basicSetZdoClient(newZdoClient, msgs);
			if (msgs != null) msgs.dispatch();
		}
		else if (eNotificationRequired())
			eNotify(new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.ZDO_COMMON_SERVERS__ZDO_CLIENT, newZdoClient, newZdoClient));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public DeviceAnnceServer getDeviceAnnceServer() {
		return deviceAnnceServer;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public NotificationChain basicSetDeviceAnnceServer(DeviceAnnceServer newDeviceAnnceServer, NotificationChain msgs) {
		DeviceAnnceServer oldDeviceAnnceServer = deviceAnnceServer;
		deviceAnnceServer = newDeviceAnnceServer;
		if (eNotificationRequired()) {
			ENotificationImpl notification = new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.ZDO_COMMON_SERVERS__DEVICE_ANNCE_SERVER, oldDeviceAnnceServer, newDeviceAnnceServer);
			if (msgs == null) msgs = notification; else msgs.add(notification);
		}
		return msgs;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void setDeviceAnnceServer(DeviceAnnceServer newDeviceAnnceServer) {
		if (newDeviceAnnceServer != deviceAnnceServer) {
			NotificationChain msgs = null;
			if (deviceAnnceServer != null)
				msgs = ((InternalEObject)deviceAnnceServer).eInverseRemove(this, EOPPOSITE_FEATURE_BASE - ZPSConfigurationPackage.ZDO_COMMON_SERVERS__DEVICE_ANNCE_SERVER, null, msgs);
			if (newDeviceAnnceServer != null)
				msgs = ((InternalEObject)newDeviceAnnceServer).eInverseAdd(this, EOPPOSITE_FEATURE_BASE - ZPSConfigurationPackage.ZDO_COMMON_SERVERS__DEVICE_ANNCE_SERVER, null, msgs);
			msgs = basicSetDeviceAnnceServer(newDeviceAnnceServer, msgs);
			if (msgs != null) msgs.dispatch();
		}
		else if (eNotificationRequired())
			eNotify(new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.ZDO_COMMON_SERVERS__DEVICE_ANNCE_SERVER, newDeviceAnnceServer, newDeviceAnnceServer));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public ActiveEpServer getActiveEpServer() {
		return activeEpServer;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public NotificationChain basicSetActiveEpServer(ActiveEpServer newActiveEpServer, NotificationChain msgs) {
		ActiveEpServer oldActiveEpServer = activeEpServer;
		activeEpServer = newActiveEpServer;
		if (eNotificationRequired()) {
			ENotificationImpl notification = new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.ZDO_COMMON_SERVERS__ACTIVE_EP_SERVER, oldActiveEpServer, newActiveEpServer);
			if (msgs == null) msgs = notification; else msgs.add(notification);
		}
		return msgs;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void setActiveEpServer(ActiveEpServer newActiveEpServer) {
		if (newActiveEpServer != activeEpServer) {
			NotificationChain msgs = null;
			if (activeEpServer != null)
				msgs = ((InternalEObject)activeEpServer).eInverseRemove(this, EOPPOSITE_FEATURE_BASE - ZPSConfigurationPackage.ZDO_COMMON_SERVERS__ACTIVE_EP_SERVER, null, msgs);
			if (newActiveEpServer != null)
				msgs = ((InternalEObject)newActiveEpServer).eInverseAdd(this, EOPPOSITE_FEATURE_BASE - ZPSConfigurationPackage.ZDO_COMMON_SERVERS__ACTIVE_EP_SERVER, null, msgs);
			msgs = basicSetActiveEpServer(newActiveEpServer, msgs);
			if (msgs != null) msgs.dispatch();
		}
		else if (eNotificationRequired())
			eNotify(new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.ZDO_COMMON_SERVERS__ACTIVE_EP_SERVER, newActiveEpServer, newActiveEpServer));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public NwkAddrServer getNwkAddrServer() {
		return nwkAddrServer;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public NotificationChain basicSetNwkAddrServer(NwkAddrServer newNwkAddrServer, NotificationChain msgs) {
		NwkAddrServer oldNwkAddrServer = nwkAddrServer;
		nwkAddrServer = newNwkAddrServer;
		if (eNotificationRequired()) {
			ENotificationImpl notification = new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.ZDO_COMMON_SERVERS__NWK_ADDR_SERVER, oldNwkAddrServer, newNwkAddrServer);
			if (msgs == null) msgs = notification; else msgs.add(notification);
		}
		return msgs;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void setNwkAddrServer(NwkAddrServer newNwkAddrServer) {
		if (newNwkAddrServer != nwkAddrServer) {
			NotificationChain msgs = null;
			if (nwkAddrServer != null)
				msgs = ((InternalEObject)nwkAddrServer).eInverseRemove(this, EOPPOSITE_FEATURE_BASE - ZPSConfigurationPackage.ZDO_COMMON_SERVERS__NWK_ADDR_SERVER, null, msgs);
			if (newNwkAddrServer != null)
				msgs = ((InternalEObject)newNwkAddrServer).eInverseAdd(this, EOPPOSITE_FEATURE_BASE - ZPSConfigurationPackage.ZDO_COMMON_SERVERS__NWK_ADDR_SERVER, null, msgs);
			msgs = basicSetNwkAddrServer(newNwkAddrServer, msgs);
			if (msgs != null) msgs.dispatch();
		}
		else if (eNotificationRequired())
			eNotify(new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.ZDO_COMMON_SERVERS__NWK_ADDR_SERVER, newNwkAddrServer, newNwkAddrServer));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public IeeeAddrServer getIeeeAddrServer() {
		return ieeeAddrServer;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public NotificationChain basicSetIeeeAddrServer(IeeeAddrServer newIeeeAddrServer, NotificationChain msgs) {
		IeeeAddrServer oldIeeeAddrServer = ieeeAddrServer;
		ieeeAddrServer = newIeeeAddrServer;
		if (eNotificationRequired()) {
			ENotificationImpl notification = new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.ZDO_COMMON_SERVERS__IEEE_ADDR_SERVER, oldIeeeAddrServer, newIeeeAddrServer);
			if (msgs == null) msgs = notification; else msgs.add(notification);
		}
		return msgs;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void setIeeeAddrServer(IeeeAddrServer newIeeeAddrServer) {
		if (newIeeeAddrServer != ieeeAddrServer) {
			NotificationChain msgs = null;
			if (ieeeAddrServer != null)
				msgs = ((InternalEObject)ieeeAddrServer).eInverseRemove(this, EOPPOSITE_FEATURE_BASE - ZPSConfigurationPackage.ZDO_COMMON_SERVERS__IEEE_ADDR_SERVER, null, msgs);
			if (newIeeeAddrServer != null)
				msgs = ((InternalEObject)newIeeeAddrServer).eInverseAdd(this, EOPPOSITE_FEATURE_BASE - ZPSConfigurationPackage.ZDO_COMMON_SERVERS__IEEE_ADDR_SERVER, null, msgs);
			msgs = basicSetIeeeAddrServer(newIeeeAddrServer, msgs);
			if (msgs != null) msgs.dispatch();
		}
		else if (eNotificationRequired())
			eNotify(new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.ZDO_COMMON_SERVERS__IEEE_ADDR_SERVER, newIeeeAddrServer, newIeeeAddrServer));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public SystemServerDiscoveryServer getSystemServerDiscoveryServer() {
		return systemServerDiscoveryServer;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public NotificationChain basicSetSystemServerDiscoveryServer(SystemServerDiscoveryServer newSystemServerDiscoveryServer, NotificationChain msgs) {
		SystemServerDiscoveryServer oldSystemServerDiscoveryServer = systemServerDiscoveryServer;
		systemServerDiscoveryServer = newSystemServerDiscoveryServer;
		if (eNotificationRequired()) {
			ENotificationImpl notification = new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.ZDO_COMMON_SERVERS__SYSTEM_SERVER_DISCOVERY_SERVER, oldSystemServerDiscoveryServer, newSystemServerDiscoveryServer);
			if (msgs == null) msgs = notification; else msgs.add(notification);
		}
		return msgs;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void setSystemServerDiscoveryServer(SystemServerDiscoveryServer newSystemServerDiscoveryServer) {
		if (newSystemServerDiscoveryServer != systemServerDiscoveryServer) {
			NotificationChain msgs = null;
			if (systemServerDiscoveryServer != null)
				msgs = ((InternalEObject)systemServerDiscoveryServer).eInverseRemove(this, EOPPOSITE_FEATURE_BASE - ZPSConfigurationPackage.ZDO_COMMON_SERVERS__SYSTEM_SERVER_DISCOVERY_SERVER, null, msgs);
			if (newSystemServerDiscoveryServer != null)
				msgs = ((InternalEObject)newSystemServerDiscoveryServer).eInverseAdd(this, EOPPOSITE_FEATURE_BASE - ZPSConfigurationPackage.ZDO_COMMON_SERVERS__SYSTEM_SERVER_DISCOVERY_SERVER, null, msgs);
			msgs = basicSetSystemServerDiscoveryServer(newSystemServerDiscoveryServer, msgs);
			if (msgs != null) msgs.dispatch();
		}
		else if (eNotificationRequired())
			eNotify(new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.ZDO_COMMON_SERVERS__SYSTEM_SERVER_DISCOVERY_SERVER, newSystemServerDiscoveryServer, newSystemServerDiscoveryServer));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public NodeDescServer getNodeDescServer() {
		return nodeDescServer;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public NotificationChain basicSetNodeDescServer(NodeDescServer newNodeDescServer, NotificationChain msgs) {
		NodeDescServer oldNodeDescServer = nodeDescServer;
		nodeDescServer = newNodeDescServer;
		if (eNotificationRequired()) {
			ENotificationImpl notification = new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.ZDO_COMMON_SERVERS__NODE_DESC_SERVER, oldNodeDescServer, newNodeDescServer);
			if (msgs == null) msgs = notification; else msgs.add(notification);
		}
		return msgs;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void setNodeDescServer(NodeDescServer newNodeDescServer) {
		if (newNodeDescServer != nodeDescServer) {
			NotificationChain msgs = null;
			if (nodeDescServer != null)
				msgs = ((InternalEObject)nodeDescServer).eInverseRemove(this, EOPPOSITE_FEATURE_BASE - ZPSConfigurationPackage.ZDO_COMMON_SERVERS__NODE_DESC_SERVER, null, msgs);
			if (newNodeDescServer != null)
				msgs = ((InternalEObject)newNodeDescServer).eInverseAdd(this, EOPPOSITE_FEATURE_BASE - ZPSConfigurationPackage.ZDO_COMMON_SERVERS__NODE_DESC_SERVER, null, msgs);
			msgs = basicSetNodeDescServer(newNodeDescServer, msgs);
			if (msgs != null) msgs.dispatch();
		}
		else if (eNotificationRequired())
			eNotify(new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.ZDO_COMMON_SERVERS__NODE_DESC_SERVER, newNodeDescServer, newNodeDescServer));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public PowerDescServer getPowerDescServer() {
		return powerDescServer;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public NotificationChain basicSetPowerDescServer(PowerDescServer newPowerDescServer, NotificationChain msgs) {
		PowerDescServer oldPowerDescServer = powerDescServer;
		powerDescServer = newPowerDescServer;
		if (eNotificationRequired()) {
			ENotificationImpl notification = new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.ZDO_COMMON_SERVERS__POWER_DESC_SERVER, oldPowerDescServer, newPowerDescServer);
			if (msgs == null) msgs = notification; else msgs.add(notification);
		}
		return msgs;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void setPowerDescServer(PowerDescServer newPowerDescServer) {
		if (newPowerDescServer != powerDescServer) {
			NotificationChain msgs = null;
			if (powerDescServer != null)
				msgs = ((InternalEObject)powerDescServer).eInverseRemove(this, EOPPOSITE_FEATURE_BASE - ZPSConfigurationPackage.ZDO_COMMON_SERVERS__POWER_DESC_SERVER, null, msgs);
			if (newPowerDescServer != null)
				msgs = ((InternalEObject)newPowerDescServer).eInverseAdd(this, EOPPOSITE_FEATURE_BASE - ZPSConfigurationPackage.ZDO_COMMON_SERVERS__POWER_DESC_SERVER, null, msgs);
			msgs = basicSetPowerDescServer(newPowerDescServer, msgs);
			if (msgs != null) msgs.dispatch();
		}
		else if (eNotificationRequired())
			eNotify(new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.ZDO_COMMON_SERVERS__POWER_DESC_SERVER, newPowerDescServer, newPowerDescServer));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public MatchDescServer getMatchDescServer() {
		return matchDescServer;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public NotificationChain basicSetMatchDescServer(MatchDescServer newMatchDescServer, NotificationChain msgs) {
		MatchDescServer oldMatchDescServer = matchDescServer;
		matchDescServer = newMatchDescServer;
		if (eNotificationRequired()) {
			ENotificationImpl notification = new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.ZDO_COMMON_SERVERS__MATCH_DESC_SERVER, oldMatchDescServer, newMatchDescServer);
			if (msgs == null) msgs = notification; else msgs.add(notification);
		}
		return msgs;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void setMatchDescServer(MatchDescServer newMatchDescServer) {
		if (newMatchDescServer != matchDescServer) {
			NotificationChain msgs = null;
			if (matchDescServer != null)
				msgs = ((InternalEObject)matchDescServer).eInverseRemove(this, EOPPOSITE_FEATURE_BASE - ZPSConfigurationPackage.ZDO_COMMON_SERVERS__MATCH_DESC_SERVER, null, msgs);
			if (newMatchDescServer != null)
				msgs = ((InternalEObject)newMatchDescServer).eInverseAdd(this, EOPPOSITE_FEATURE_BASE - ZPSConfigurationPackage.ZDO_COMMON_SERVERS__MATCH_DESC_SERVER, null, msgs);
			msgs = basicSetMatchDescServer(newMatchDescServer, msgs);
			if (msgs != null) msgs.dispatch();
		}
		else if (eNotificationRequired())
			eNotify(new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.ZDO_COMMON_SERVERS__MATCH_DESC_SERVER, newMatchDescServer, newMatchDescServer));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public SimpleDescServer getSimpleDescServer() {
		return simpleDescServer;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public NotificationChain basicSetSimpleDescServer(SimpleDescServer newSimpleDescServer, NotificationChain msgs) {
		SimpleDescServer oldSimpleDescServer = simpleDescServer;
		simpleDescServer = newSimpleDescServer;
		if (eNotificationRequired()) {
			ENotificationImpl notification = new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.ZDO_COMMON_SERVERS__SIMPLE_DESC_SERVER, oldSimpleDescServer, newSimpleDescServer);
			if (msgs == null) msgs = notification; else msgs.add(notification);
		}
		return msgs;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void setSimpleDescServer(SimpleDescServer newSimpleDescServer) {
		if (newSimpleDescServer != simpleDescServer) {
			NotificationChain msgs = null;
			if (simpleDescServer != null)
				msgs = ((InternalEObject)simpleDescServer).eInverseRemove(this, EOPPOSITE_FEATURE_BASE - ZPSConfigurationPackage.ZDO_COMMON_SERVERS__SIMPLE_DESC_SERVER, null, msgs);
			if (newSimpleDescServer != null)
				msgs = ((InternalEObject)newSimpleDescServer).eInverseAdd(this, EOPPOSITE_FEATURE_BASE - ZPSConfigurationPackage.ZDO_COMMON_SERVERS__SIMPLE_DESC_SERVER, null, msgs);
			msgs = basicSetSimpleDescServer(newSimpleDescServer, msgs);
			if (msgs != null) msgs.dispatch();
		}
		else if (eNotificationRequired())
			eNotify(new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.ZDO_COMMON_SERVERS__SIMPLE_DESC_SERVER, newSimpleDescServer, newSimpleDescServer));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public MgmtLqiServer getMgmtLqiServer() {
		return mgmtLqiServer;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public NotificationChain basicSetMgmtLqiServer(MgmtLqiServer newMgmtLqiServer, NotificationChain msgs) {
		MgmtLqiServer oldMgmtLqiServer = mgmtLqiServer;
		mgmtLqiServer = newMgmtLqiServer;
		if (eNotificationRequired()) {
			ENotificationImpl notification = new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.ZDO_COMMON_SERVERS__MGMT_LQI_SERVER, oldMgmtLqiServer, newMgmtLqiServer);
			if (msgs == null) msgs = notification; else msgs.add(notification);
		}
		return msgs;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void setMgmtLqiServer(MgmtLqiServer newMgmtLqiServer) {
		if (newMgmtLqiServer != mgmtLqiServer) {
			NotificationChain msgs = null;
			if (mgmtLqiServer != null)
				msgs = ((InternalEObject)mgmtLqiServer).eInverseRemove(this, EOPPOSITE_FEATURE_BASE - ZPSConfigurationPackage.ZDO_COMMON_SERVERS__MGMT_LQI_SERVER, null, msgs);
			if (newMgmtLqiServer != null)
				msgs = ((InternalEObject)newMgmtLqiServer).eInverseAdd(this, EOPPOSITE_FEATURE_BASE - ZPSConfigurationPackage.ZDO_COMMON_SERVERS__MGMT_LQI_SERVER, null, msgs);
			msgs = basicSetMgmtLqiServer(newMgmtLqiServer, msgs);
			if (msgs != null) msgs.dispatch();
		}
		else if (eNotificationRequired())
			eNotify(new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.ZDO_COMMON_SERVERS__MGMT_LQI_SERVER, newMgmtLqiServer, newMgmtLqiServer));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public MgmtLeaveServer getMgmtLeaveServer() {
		return mgmtLeaveServer;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public NotificationChain basicSetMgmtLeaveServer(MgmtLeaveServer newMgmtLeaveServer, NotificationChain msgs) {
		MgmtLeaveServer oldMgmtLeaveServer = mgmtLeaveServer;
		mgmtLeaveServer = newMgmtLeaveServer;
		if (eNotificationRequired()) {
			ENotificationImpl notification = new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.ZDO_COMMON_SERVERS__MGMT_LEAVE_SERVER, oldMgmtLeaveServer, newMgmtLeaveServer);
			if (msgs == null) msgs = notification; else msgs.add(notification);
		}
		return msgs;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void setMgmtLeaveServer(MgmtLeaveServer newMgmtLeaveServer) {
		if (newMgmtLeaveServer != mgmtLeaveServer) {
			NotificationChain msgs = null;
			if (mgmtLeaveServer != null)
				msgs = ((InternalEObject)mgmtLeaveServer).eInverseRemove(this, EOPPOSITE_FEATURE_BASE - ZPSConfigurationPackage.ZDO_COMMON_SERVERS__MGMT_LEAVE_SERVER, null, msgs);
			if (newMgmtLeaveServer != null)
				msgs = ((InternalEObject)newMgmtLeaveServer).eInverseAdd(this, EOPPOSITE_FEATURE_BASE - ZPSConfigurationPackage.ZDO_COMMON_SERVERS__MGMT_LEAVE_SERVER, null, msgs);
			msgs = basicSetMgmtLeaveServer(newMgmtLeaveServer, msgs);
			if (msgs != null) msgs.dispatch();
		}
		else if (eNotificationRequired())
			eNotify(new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.ZDO_COMMON_SERVERS__MGMT_LEAVE_SERVER, newMgmtLeaveServer, newMgmtLeaveServer));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public BindUnbindServer getBindUnbindServer() {
		return bindUnbindServer;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public NotificationChain basicSetBindUnbindServer(BindUnbindServer newBindUnbindServer, NotificationChain msgs) {
		BindUnbindServer oldBindUnbindServer = bindUnbindServer;
		bindUnbindServer = newBindUnbindServer;
		if (eNotificationRequired()) {
			ENotificationImpl notification = new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.ZDO_COMMON_SERVERS__BIND_UNBIND_SERVER, oldBindUnbindServer, newBindUnbindServer);
			if (msgs == null) msgs = notification; else msgs.add(notification);
		}
		return msgs;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void setBindUnbindServer(BindUnbindServer newBindUnbindServer) {
		if (newBindUnbindServer != bindUnbindServer) {
			NotificationChain msgs = null;
			if (bindUnbindServer != null)
				msgs = ((InternalEObject)bindUnbindServer).eInverseRemove(this, EOPPOSITE_FEATURE_BASE - ZPSConfigurationPackage.ZDO_COMMON_SERVERS__BIND_UNBIND_SERVER, null, msgs);
			if (newBindUnbindServer != null)
				msgs = ((InternalEObject)newBindUnbindServer).eInverseAdd(this, EOPPOSITE_FEATURE_BASE - ZPSConfigurationPackage.ZDO_COMMON_SERVERS__BIND_UNBIND_SERVER, null, msgs);
			msgs = basicSetBindUnbindServer(newBindUnbindServer, msgs);
			if (msgs != null) msgs.dispatch();
		}
		else if (eNotificationRequired())
			eNotify(new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.ZDO_COMMON_SERVERS__BIND_UNBIND_SERVER, newBindUnbindServer, newBindUnbindServer));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public ExtendedActiveEpServer getExtendedActiveEpServer() {
		return extendedActiveEpServer;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public NotificationChain basicSetExtendedActiveEpServer(ExtendedActiveEpServer newExtendedActiveEpServer, NotificationChain msgs) {
		ExtendedActiveEpServer oldExtendedActiveEpServer = extendedActiveEpServer;
		extendedActiveEpServer = newExtendedActiveEpServer;
		if (eNotificationRequired()) {
			ENotificationImpl notification = new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.ZDO_COMMON_SERVERS__EXTENDED_ACTIVE_EP_SERVER, oldExtendedActiveEpServer, newExtendedActiveEpServer);
			if (msgs == null) msgs = notification; else msgs.add(notification);
		}
		return msgs;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void setExtendedActiveEpServer(ExtendedActiveEpServer newExtendedActiveEpServer) {
		if (newExtendedActiveEpServer != extendedActiveEpServer) {
			NotificationChain msgs = null;
			if (extendedActiveEpServer != null)
				msgs = ((InternalEObject)extendedActiveEpServer).eInverseRemove(this, EOPPOSITE_FEATURE_BASE - ZPSConfigurationPackage.ZDO_COMMON_SERVERS__EXTENDED_ACTIVE_EP_SERVER, null, msgs);
			if (newExtendedActiveEpServer != null)
				msgs = ((InternalEObject)newExtendedActiveEpServer).eInverseAdd(this, EOPPOSITE_FEATURE_BASE - ZPSConfigurationPackage.ZDO_COMMON_SERVERS__EXTENDED_ACTIVE_EP_SERVER, null, msgs);
			msgs = basicSetExtendedActiveEpServer(newExtendedActiveEpServer, msgs);
			if (msgs != null) msgs.dispatch();
		}
		else if (eNotificationRequired())
			eNotify(new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.ZDO_COMMON_SERVERS__EXTENDED_ACTIVE_EP_SERVER, newExtendedActiveEpServer, newExtendedActiveEpServer));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public ExtendedSimpleDescServer getExtendedSimpleDescServer() {
		return extendedSimpleDescServer;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public NotificationChain basicSetExtendedSimpleDescServer(ExtendedSimpleDescServer newExtendedSimpleDescServer, NotificationChain msgs) {
		ExtendedSimpleDescServer oldExtendedSimpleDescServer = extendedSimpleDescServer;
		extendedSimpleDescServer = newExtendedSimpleDescServer;
		if (eNotificationRequired()) {
			ENotificationImpl notification = new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.ZDO_COMMON_SERVERS__EXTENDED_SIMPLE_DESC_SERVER, oldExtendedSimpleDescServer, newExtendedSimpleDescServer);
			if (msgs == null) msgs = notification; else msgs.add(notification);
		}
		return msgs;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void setExtendedSimpleDescServer(ExtendedSimpleDescServer newExtendedSimpleDescServer) {
		if (newExtendedSimpleDescServer != extendedSimpleDescServer) {
			NotificationChain msgs = null;
			if (extendedSimpleDescServer != null)
				msgs = ((InternalEObject)extendedSimpleDescServer).eInverseRemove(this, EOPPOSITE_FEATURE_BASE - ZPSConfigurationPackage.ZDO_COMMON_SERVERS__EXTENDED_SIMPLE_DESC_SERVER, null, msgs);
			if (newExtendedSimpleDescServer != null)
				msgs = ((InternalEObject)newExtendedSimpleDescServer).eInverseAdd(this, EOPPOSITE_FEATURE_BASE - ZPSConfigurationPackage.ZDO_COMMON_SERVERS__EXTENDED_SIMPLE_DESC_SERVER, null, msgs);
			msgs = basicSetExtendedSimpleDescServer(newExtendedSimpleDescServer, msgs);
			if (msgs != null) msgs.dispatch();
		}
		else if (eNotificationRequired())
			eNotify(new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.ZDO_COMMON_SERVERS__EXTENDED_SIMPLE_DESC_SERVER, newExtendedSimpleDescServer, newExtendedSimpleDescServer));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public BindRequestServer getBindRequestServer() {
		return bindRequestServer;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public NotificationChain basicSetBindRequestServer(BindRequestServer newBindRequestServer, NotificationChain msgs) {
		BindRequestServer oldBindRequestServer = bindRequestServer;
		bindRequestServer = newBindRequestServer;
		if (eNotificationRequired()) {
			ENotificationImpl notification = new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.ZDO_COMMON_SERVERS__BIND_REQUEST_SERVER, oldBindRequestServer, newBindRequestServer);
			if (msgs == null) msgs = notification; else msgs.add(notification);
		}
		return msgs;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void setBindRequestServer(BindRequestServer newBindRequestServer) {
		if (newBindRequestServer != bindRequestServer) {
			NotificationChain msgs = null;
			if (bindRequestServer != null)
				msgs = ((InternalEObject)bindRequestServer).eInverseRemove(this, EOPPOSITE_FEATURE_BASE - ZPSConfigurationPackage.ZDO_COMMON_SERVERS__BIND_REQUEST_SERVER, null, msgs);
			if (newBindRequestServer != null)
				msgs = ((InternalEObject)newBindRequestServer).eInverseAdd(this, EOPPOSITE_FEATURE_BASE - ZPSConfigurationPackage.ZDO_COMMON_SERVERS__BIND_REQUEST_SERVER, null, msgs);
			msgs = basicSetBindRequestServer(newBindRequestServer, msgs);
			if (msgs != null) msgs.dispatch();
		}
		else if (eNotificationRequired())
			eNotify(new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.ZDO_COMMON_SERVERS__BIND_REQUEST_SERVER, newBindRequestServer, newBindRequestServer));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public MgmtBindServer getMgmtBindServer() {
		return mgmtBindServer;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public NotificationChain basicSetMgmtBindServer(MgmtBindServer newMgmtBindServer, NotificationChain msgs) {
		MgmtBindServer oldMgmtBindServer = mgmtBindServer;
		mgmtBindServer = newMgmtBindServer;
		if (eNotificationRequired()) {
			ENotificationImpl notification = new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.ZDO_COMMON_SERVERS__MGMT_BIND_SERVER, oldMgmtBindServer, newMgmtBindServer);
			if (msgs == null) msgs = notification; else msgs.add(notification);
		}
		return msgs;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void setMgmtBindServer(MgmtBindServer newMgmtBindServer) {
		if (newMgmtBindServer != mgmtBindServer) {
			NotificationChain msgs = null;
			if (mgmtBindServer != null)
				msgs = ((InternalEObject)mgmtBindServer).eInverseRemove(this, EOPPOSITE_FEATURE_BASE - ZPSConfigurationPackage.ZDO_COMMON_SERVERS__MGMT_BIND_SERVER, null, msgs);
			if (newMgmtBindServer != null)
				msgs = ((InternalEObject)newMgmtBindServer).eInverseAdd(this, EOPPOSITE_FEATURE_BASE - ZPSConfigurationPackage.ZDO_COMMON_SERVERS__MGMT_BIND_SERVER, null, msgs);
			msgs = basicSetMgmtBindServer(newMgmtBindServer, msgs);
			if (msgs != null) msgs.dispatch();
		}
		else if (eNotificationRequired())
			eNotify(new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.ZDO_COMMON_SERVERS__MGMT_BIND_SERVER, newMgmtBindServer, newMgmtBindServer));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public MgmtNWKEnhanceUpdateServer getMgmtNWKEnhanceUpdateServer() {
		return mgmtNWKEnhanceUpdateServer;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public NotificationChain basicSetMgmtNWKEnhanceUpdateServer(MgmtNWKEnhanceUpdateServer newMgmtNWKEnhanceUpdateServer, NotificationChain msgs) {
		MgmtNWKEnhanceUpdateServer oldMgmtNWKEnhanceUpdateServer = mgmtNWKEnhanceUpdateServer;
		mgmtNWKEnhanceUpdateServer = newMgmtNWKEnhanceUpdateServer;
		if (eNotificationRequired()) {
			ENotificationImpl notification = new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.ZDO_COMMON_SERVERS__MGMT_NWK_ENHANCE_UPDATE_SERVER, oldMgmtNWKEnhanceUpdateServer, newMgmtNWKEnhanceUpdateServer);
			if (msgs == null) msgs = notification; else msgs.add(notification);
		}
		return msgs;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void setMgmtNWKEnhanceUpdateServer(MgmtNWKEnhanceUpdateServer newMgmtNWKEnhanceUpdateServer) {
		if (newMgmtNWKEnhanceUpdateServer != mgmtNWKEnhanceUpdateServer) {
			NotificationChain msgs = null;
			if (mgmtNWKEnhanceUpdateServer != null)
				msgs = ((InternalEObject)mgmtNWKEnhanceUpdateServer).eInverseRemove(this, EOPPOSITE_FEATURE_BASE - ZPSConfigurationPackage.ZDO_COMMON_SERVERS__MGMT_NWK_ENHANCE_UPDATE_SERVER, null, msgs);
			if (newMgmtNWKEnhanceUpdateServer != null)
				msgs = ((InternalEObject)newMgmtNWKEnhanceUpdateServer).eInverseAdd(this, EOPPOSITE_FEATURE_BASE - ZPSConfigurationPackage.ZDO_COMMON_SERVERS__MGMT_NWK_ENHANCE_UPDATE_SERVER, null, msgs);
			msgs = basicSetMgmtNWKEnhanceUpdateServer(newMgmtNWKEnhanceUpdateServer, msgs);
			if (msgs != null) msgs.dispatch();
		}
		else if (eNotificationRequired())
			eNotify(new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.ZDO_COMMON_SERVERS__MGMT_NWK_ENHANCE_UPDATE_SERVER, newMgmtNWKEnhanceUpdateServer, newMgmtNWKEnhanceUpdateServer));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	@Override
	public NotificationChain eInverseRemove(InternalEObject otherEnd, int featureID, NotificationChain msgs) {
		switch (featureID) {
			case ZPSConfigurationPackage.ZDO_COMMON_SERVERS__DEFAULT_SERVER:
				return basicSetDefaultServer(null, msgs);
			case ZPSConfigurationPackage.ZDO_COMMON_SERVERS__ZDO_CLIENT:
				return basicSetZdoClient(null, msgs);
			case ZPSConfigurationPackage.ZDO_COMMON_SERVERS__DEVICE_ANNCE_SERVER:
				return basicSetDeviceAnnceServer(null, msgs);
			case ZPSConfigurationPackage.ZDO_COMMON_SERVERS__ACTIVE_EP_SERVER:
				return basicSetActiveEpServer(null, msgs);
			case ZPSConfigurationPackage.ZDO_COMMON_SERVERS__NWK_ADDR_SERVER:
				return basicSetNwkAddrServer(null, msgs);
			case ZPSConfigurationPackage.ZDO_COMMON_SERVERS__IEEE_ADDR_SERVER:
				return basicSetIeeeAddrServer(null, msgs);
			case ZPSConfigurationPackage.ZDO_COMMON_SERVERS__SYSTEM_SERVER_DISCOVERY_SERVER:
				return basicSetSystemServerDiscoveryServer(null, msgs);
			case ZPSConfigurationPackage.ZDO_COMMON_SERVERS__NODE_DESC_SERVER:
				return basicSetNodeDescServer(null, msgs);
			case ZPSConfigurationPackage.ZDO_COMMON_SERVERS__POWER_DESC_SERVER:
				return basicSetPowerDescServer(null, msgs);
			case ZPSConfigurationPackage.ZDO_COMMON_SERVERS__MATCH_DESC_SERVER:
				return basicSetMatchDescServer(null, msgs);
			case ZPSConfigurationPackage.ZDO_COMMON_SERVERS__SIMPLE_DESC_SERVER:
				return basicSetSimpleDescServer(null, msgs);
			case ZPSConfigurationPackage.ZDO_COMMON_SERVERS__MGMT_LQI_SERVER:
				return basicSetMgmtLqiServer(null, msgs);
			case ZPSConfigurationPackage.ZDO_COMMON_SERVERS__MGMT_LEAVE_SERVER:
				return basicSetMgmtLeaveServer(null, msgs);
			case ZPSConfigurationPackage.ZDO_COMMON_SERVERS__MGMT_NWK_UPDATE_SERVER:
				return basicSetMgmtNWKUpdateServer(null, msgs);
			case ZPSConfigurationPackage.ZDO_COMMON_SERVERS__BIND_UNBIND_SERVER:
				return basicSetBindUnbindServer(null, msgs);
			case ZPSConfigurationPackage.ZDO_COMMON_SERVERS__EXTENDED_ACTIVE_EP_SERVER:
				return basicSetExtendedActiveEpServer(null, msgs);
			case ZPSConfigurationPackage.ZDO_COMMON_SERVERS__EXTENDED_SIMPLE_DESC_SERVER:
				return basicSetExtendedSimpleDescServer(null, msgs);
			case ZPSConfigurationPackage.ZDO_COMMON_SERVERS__BIND_REQUEST_SERVER:
				return basicSetBindRequestServer(null, msgs);
			case ZPSConfigurationPackage.ZDO_COMMON_SERVERS__MGMT_BIND_SERVER:
				return basicSetMgmtBindServer(null, msgs);
			case ZPSConfigurationPackage.ZDO_COMMON_SERVERS__MGMT_NWK_ENHANCE_UPDATE_SERVER:
				return basicSetMgmtNWKEnhanceUpdateServer(null, msgs);
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
			case ZPSConfigurationPackage.ZDO_COMMON_SERVERS__DEFAULT_SERVER:
				return getDefaultServer();
			case ZPSConfigurationPackage.ZDO_COMMON_SERVERS__ZDO_CLIENT:
				return getZdoClient();
			case ZPSConfigurationPackage.ZDO_COMMON_SERVERS__DEVICE_ANNCE_SERVER:
				return getDeviceAnnceServer();
			case ZPSConfigurationPackage.ZDO_COMMON_SERVERS__ACTIVE_EP_SERVER:
				return getActiveEpServer();
			case ZPSConfigurationPackage.ZDO_COMMON_SERVERS__NWK_ADDR_SERVER:
				return getNwkAddrServer();
			case ZPSConfigurationPackage.ZDO_COMMON_SERVERS__IEEE_ADDR_SERVER:
				return getIeeeAddrServer();
			case ZPSConfigurationPackage.ZDO_COMMON_SERVERS__SYSTEM_SERVER_DISCOVERY_SERVER:
				return getSystemServerDiscoveryServer();
			case ZPSConfigurationPackage.ZDO_COMMON_SERVERS__NODE_DESC_SERVER:
				return getNodeDescServer();
			case ZPSConfigurationPackage.ZDO_COMMON_SERVERS__POWER_DESC_SERVER:
				return getPowerDescServer();
			case ZPSConfigurationPackage.ZDO_COMMON_SERVERS__MATCH_DESC_SERVER:
				return getMatchDescServer();
			case ZPSConfigurationPackage.ZDO_COMMON_SERVERS__SIMPLE_DESC_SERVER:
				return getSimpleDescServer();
			case ZPSConfigurationPackage.ZDO_COMMON_SERVERS__MGMT_LQI_SERVER:
				return getMgmtLqiServer();
			case ZPSConfigurationPackage.ZDO_COMMON_SERVERS__MGMT_LEAVE_SERVER:
				return getMgmtLeaveServer();
			case ZPSConfigurationPackage.ZDO_COMMON_SERVERS__MGMT_NWK_UPDATE_SERVER:
				return getMgmtNWKUpdateServer();
			case ZPSConfigurationPackage.ZDO_COMMON_SERVERS__BIND_UNBIND_SERVER:
				return getBindUnbindServer();
			case ZPSConfigurationPackage.ZDO_COMMON_SERVERS__EXTENDED_ACTIVE_EP_SERVER:
				return getExtendedActiveEpServer();
			case ZPSConfigurationPackage.ZDO_COMMON_SERVERS__EXTENDED_SIMPLE_DESC_SERVER:
				return getExtendedSimpleDescServer();
			case ZPSConfigurationPackage.ZDO_COMMON_SERVERS__BIND_REQUEST_SERVER:
				return getBindRequestServer();
			case ZPSConfigurationPackage.ZDO_COMMON_SERVERS__MGMT_BIND_SERVER:
				return getMgmtBindServer();
			case ZPSConfigurationPackage.ZDO_COMMON_SERVERS__MGMT_NWK_ENHANCE_UPDATE_SERVER:
				return getMgmtNWKEnhanceUpdateServer();
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
			case ZPSConfigurationPackage.ZDO_COMMON_SERVERS__DEFAULT_SERVER:
				setDefaultServer((DefaultServer)newValue);
				return;
			case ZPSConfigurationPackage.ZDO_COMMON_SERVERS__ZDO_CLIENT:
				setZdoClient((ZdoClient)newValue);
				return;
			case ZPSConfigurationPackage.ZDO_COMMON_SERVERS__DEVICE_ANNCE_SERVER:
				setDeviceAnnceServer((DeviceAnnceServer)newValue);
				return;
			case ZPSConfigurationPackage.ZDO_COMMON_SERVERS__ACTIVE_EP_SERVER:
				setActiveEpServer((ActiveEpServer)newValue);
				return;
			case ZPSConfigurationPackage.ZDO_COMMON_SERVERS__NWK_ADDR_SERVER:
				setNwkAddrServer((NwkAddrServer)newValue);
				return;
			case ZPSConfigurationPackage.ZDO_COMMON_SERVERS__IEEE_ADDR_SERVER:
				setIeeeAddrServer((IeeeAddrServer)newValue);
				return;
			case ZPSConfigurationPackage.ZDO_COMMON_SERVERS__SYSTEM_SERVER_DISCOVERY_SERVER:
				setSystemServerDiscoveryServer((SystemServerDiscoveryServer)newValue);
				return;
			case ZPSConfigurationPackage.ZDO_COMMON_SERVERS__NODE_DESC_SERVER:
				setNodeDescServer((NodeDescServer)newValue);
				return;
			case ZPSConfigurationPackage.ZDO_COMMON_SERVERS__POWER_DESC_SERVER:
				setPowerDescServer((PowerDescServer)newValue);
				return;
			case ZPSConfigurationPackage.ZDO_COMMON_SERVERS__MATCH_DESC_SERVER:
				setMatchDescServer((MatchDescServer)newValue);
				return;
			case ZPSConfigurationPackage.ZDO_COMMON_SERVERS__SIMPLE_DESC_SERVER:
				setSimpleDescServer((SimpleDescServer)newValue);
				return;
			case ZPSConfigurationPackage.ZDO_COMMON_SERVERS__MGMT_LQI_SERVER:
				setMgmtLqiServer((MgmtLqiServer)newValue);
				return;
			case ZPSConfigurationPackage.ZDO_COMMON_SERVERS__MGMT_LEAVE_SERVER:
				setMgmtLeaveServer((MgmtLeaveServer)newValue);
				return;
			case ZPSConfigurationPackage.ZDO_COMMON_SERVERS__MGMT_NWK_UPDATE_SERVER:
				setMgmtNWKUpdateServer((MgmtNWKUpdateServer)newValue);
				return;
			case ZPSConfigurationPackage.ZDO_COMMON_SERVERS__BIND_UNBIND_SERVER:
				setBindUnbindServer((BindUnbindServer)newValue);
				return;
			case ZPSConfigurationPackage.ZDO_COMMON_SERVERS__EXTENDED_ACTIVE_EP_SERVER:
				setExtendedActiveEpServer((ExtendedActiveEpServer)newValue);
				return;
			case ZPSConfigurationPackage.ZDO_COMMON_SERVERS__EXTENDED_SIMPLE_DESC_SERVER:
				setExtendedSimpleDescServer((ExtendedSimpleDescServer)newValue);
				return;
			case ZPSConfigurationPackage.ZDO_COMMON_SERVERS__BIND_REQUEST_SERVER:
				setBindRequestServer((BindRequestServer)newValue);
				return;
			case ZPSConfigurationPackage.ZDO_COMMON_SERVERS__MGMT_BIND_SERVER:
				setMgmtBindServer((MgmtBindServer)newValue);
				return;
			case ZPSConfigurationPackage.ZDO_COMMON_SERVERS__MGMT_NWK_ENHANCE_UPDATE_SERVER:
				setMgmtNWKEnhanceUpdateServer((MgmtNWKEnhanceUpdateServer)newValue);
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
			case ZPSConfigurationPackage.ZDO_COMMON_SERVERS__DEFAULT_SERVER:
				setDefaultServer((DefaultServer)null);
				return;
			case ZPSConfigurationPackage.ZDO_COMMON_SERVERS__ZDO_CLIENT:
				setZdoClient((ZdoClient)null);
				return;
			case ZPSConfigurationPackage.ZDO_COMMON_SERVERS__DEVICE_ANNCE_SERVER:
				setDeviceAnnceServer((DeviceAnnceServer)null);
				return;
			case ZPSConfigurationPackage.ZDO_COMMON_SERVERS__ACTIVE_EP_SERVER:
				setActiveEpServer((ActiveEpServer)null);
				return;
			case ZPSConfigurationPackage.ZDO_COMMON_SERVERS__NWK_ADDR_SERVER:
				setNwkAddrServer((NwkAddrServer)null);
				return;
			case ZPSConfigurationPackage.ZDO_COMMON_SERVERS__IEEE_ADDR_SERVER:
				setIeeeAddrServer((IeeeAddrServer)null);
				return;
			case ZPSConfigurationPackage.ZDO_COMMON_SERVERS__SYSTEM_SERVER_DISCOVERY_SERVER:
				setSystemServerDiscoveryServer((SystemServerDiscoveryServer)null);
				return;
			case ZPSConfigurationPackage.ZDO_COMMON_SERVERS__NODE_DESC_SERVER:
				setNodeDescServer((NodeDescServer)null);
				return;
			case ZPSConfigurationPackage.ZDO_COMMON_SERVERS__POWER_DESC_SERVER:
				setPowerDescServer((PowerDescServer)null);
				return;
			case ZPSConfigurationPackage.ZDO_COMMON_SERVERS__MATCH_DESC_SERVER:
				setMatchDescServer((MatchDescServer)null);
				return;
			case ZPSConfigurationPackage.ZDO_COMMON_SERVERS__SIMPLE_DESC_SERVER:
				setSimpleDescServer((SimpleDescServer)null);
				return;
			case ZPSConfigurationPackage.ZDO_COMMON_SERVERS__MGMT_LQI_SERVER:
				setMgmtLqiServer((MgmtLqiServer)null);
				return;
			case ZPSConfigurationPackage.ZDO_COMMON_SERVERS__MGMT_LEAVE_SERVER:
				setMgmtLeaveServer((MgmtLeaveServer)null);
				return;
			case ZPSConfigurationPackage.ZDO_COMMON_SERVERS__MGMT_NWK_UPDATE_SERVER:
				setMgmtNWKUpdateServer((MgmtNWKUpdateServer)null);
				return;
			case ZPSConfigurationPackage.ZDO_COMMON_SERVERS__BIND_UNBIND_SERVER:
				setBindUnbindServer((BindUnbindServer)null);
				return;
			case ZPSConfigurationPackage.ZDO_COMMON_SERVERS__EXTENDED_ACTIVE_EP_SERVER:
				setExtendedActiveEpServer((ExtendedActiveEpServer)null);
				return;
			case ZPSConfigurationPackage.ZDO_COMMON_SERVERS__EXTENDED_SIMPLE_DESC_SERVER:
				setExtendedSimpleDescServer((ExtendedSimpleDescServer)null);
				return;
			case ZPSConfigurationPackage.ZDO_COMMON_SERVERS__BIND_REQUEST_SERVER:
				setBindRequestServer((BindRequestServer)null);
				return;
			case ZPSConfigurationPackage.ZDO_COMMON_SERVERS__MGMT_BIND_SERVER:
				setMgmtBindServer((MgmtBindServer)null);
				return;
			case ZPSConfigurationPackage.ZDO_COMMON_SERVERS__MGMT_NWK_ENHANCE_UPDATE_SERVER:
				setMgmtNWKEnhanceUpdateServer((MgmtNWKEnhanceUpdateServer)null);
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
			case ZPSConfigurationPackage.ZDO_COMMON_SERVERS__DEFAULT_SERVER:
				return defaultServer != null;
			case ZPSConfigurationPackage.ZDO_COMMON_SERVERS__ZDO_CLIENT:
				return zdoClient != null;
			case ZPSConfigurationPackage.ZDO_COMMON_SERVERS__DEVICE_ANNCE_SERVER:
				return deviceAnnceServer != null;
			case ZPSConfigurationPackage.ZDO_COMMON_SERVERS__ACTIVE_EP_SERVER:
				return activeEpServer != null;
			case ZPSConfigurationPackage.ZDO_COMMON_SERVERS__NWK_ADDR_SERVER:
				return nwkAddrServer != null;
			case ZPSConfigurationPackage.ZDO_COMMON_SERVERS__IEEE_ADDR_SERVER:
				return ieeeAddrServer != null;
			case ZPSConfigurationPackage.ZDO_COMMON_SERVERS__SYSTEM_SERVER_DISCOVERY_SERVER:
				return systemServerDiscoveryServer != null;
			case ZPSConfigurationPackage.ZDO_COMMON_SERVERS__NODE_DESC_SERVER:
				return nodeDescServer != null;
			case ZPSConfigurationPackage.ZDO_COMMON_SERVERS__POWER_DESC_SERVER:
				return powerDescServer != null;
			case ZPSConfigurationPackage.ZDO_COMMON_SERVERS__MATCH_DESC_SERVER:
				return matchDescServer != null;
			case ZPSConfigurationPackage.ZDO_COMMON_SERVERS__SIMPLE_DESC_SERVER:
				return simpleDescServer != null;
			case ZPSConfigurationPackage.ZDO_COMMON_SERVERS__MGMT_LQI_SERVER:
				return mgmtLqiServer != null;
			case ZPSConfigurationPackage.ZDO_COMMON_SERVERS__MGMT_LEAVE_SERVER:
				return mgmtLeaveServer != null;
			case ZPSConfigurationPackage.ZDO_COMMON_SERVERS__MGMT_NWK_UPDATE_SERVER:
				return mgmtNWKUpdateServer != null;
			case ZPSConfigurationPackage.ZDO_COMMON_SERVERS__BIND_UNBIND_SERVER:
				return bindUnbindServer != null;
			case ZPSConfigurationPackage.ZDO_COMMON_SERVERS__EXTENDED_ACTIVE_EP_SERVER:
				return extendedActiveEpServer != null;
			case ZPSConfigurationPackage.ZDO_COMMON_SERVERS__EXTENDED_SIMPLE_DESC_SERVER:
				return extendedSimpleDescServer != null;
			case ZPSConfigurationPackage.ZDO_COMMON_SERVERS__BIND_REQUEST_SERVER:
				return bindRequestServer != null;
			case ZPSConfigurationPackage.ZDO_COMMON_SERVERS__MGMT_BIND_SERVER:
				return mgmtBindServer != null;
			case ZPSConfigurationPackage.ZDO_COMMON_SERVERS__MGMT_NWK_ENHANCE_UPDATE_SERVER:
				return mgmtNWKEnhanceUpdateServer != null;
		}
		return super.eIsSet(featureID);
	}

} //ZDOCommonServersImpl
