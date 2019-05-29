/**
 * (C) Jennic Ltd
 *
 * $Id: NotImplementedImpl.java 78102 2016-03-24 15:35:29Z nxp29741 $
 */
package com.jennic.ZPSConfiguration.impl;

import com.jennic.ZPSConfiguration.BindingCache;
import com.jennic.ZPSConfiguration.ComplexDescriptor;
import com.jennic.ZPSConfiguration.DiscoveryCache;
import com.jennic.ZPSConfiguration.DiscoveryTable;
import com.jennic.ZPSConfiguration.NotImplemented;
import com.jennic.ZPSConfiguration.ZPSConfigurationPackage;

import org.eclipse.emf.common.notify.Notification;
import org.eclipse.emf.common.notify.NotificationChain;

import org.eclipse.emf.ecore.EClass;
import org.eclipse.emf.ecore.InternalEObject;

import org.eclipse.emf.ecore.impl.ENotificationImpl;
import org.eclipse.emf.ecore.impl.EObjectImpl;

/**
 * <!-- begin-user-doc -->
 * An implementation of the model object '<em><b>Not Implemented</b></em>'.
 * <!-- end-user-doc -->
 * <p>
 * The following features are implemented:
 * <ul>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.NotImplementedImpl#getComplexDescriptor <em>Complex Descriptor</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.NotImplementedImpl#getDiscoveryTable <em>Discovery Table</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.NotImplementedImpl#getDiscoveryCache <em>Discovery Cache</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.NotImplementedImpl#getBindingCache <em>Binding Cache</em>}</li>
 * </ul>
 * </p>
 *
 * @generated
 */
public class NotImplementedImpl extends EObjectImpl implements NotImplemented {
	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public static final String copyright = "(C) NXP B.V";

	/**
	 * The cached value of the '{@link #getComplexDescriptor() <em>Complex Descriptor</em>}' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getComplexDescriptor()
	 * @generated
	 * @ordered
	 */
	protected ComplexDescriptor complexDescriptor;

	/**
	 * The cached value of the '{@link #getDiscoveryTable() <em>Discovery Table</em>}' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getDiscoveryTable()
	 * @generated
	 * @ordered
	 */
	protected DiscoveryTable discoveryTable;

	/**
	 * The cached value of the '{@link #getDiscoveryCache() <em>Discovery Cache</em>}' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getDiscoveryCache()
	 * @generated
	 * @ordered
	 */
	protected DiscoveryCache discoveryCache;

	/**
	 * The cached value of the '{@link #getBindingCache() <em>Binding Cache</em>}' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getBindingCache()
	 * @generated
	 * @ordered
	 */
	protected BindingCache bindingCache;

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	protected NotImplementedImpl() {
		super();
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	@Override
	protected EClass eStaticClass() {
		return ZPSConfigurationPackage.Literals.NOT_IMPLEMENTED;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public ComplexDescriptor getComplexDescriptor() {
		return complexDescriptor;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public NotificationChain basicSetComplexDescriptor(ComplexDescriptor newComplexDescriptor, NotificationChain msgs) {
		ComplexDescriptor oldComplexDescriptor = complexDescriptor;
		complexDescriptor = newComplexDescriptor;
		if (eNotificationRequired()) {
			ENotificationImpl notification = new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.NOT_IMPLEMENTED__COMPLEX_DESCRIPTOR, oldComplexDescriptor, newComplexDescriptor);
			if (msgs == null) msgs = notification; else msgs.add(notification);
		}
		return msgs;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void setComplexDescriptor(ComplexDescriptor newComplexDescriptor) {
		if (newComplexDescriptor != complexDescriptor) {
			NotificationChain msgs = null;
			if (complexDescriptor != null)
				msgs = ((InternalEObject)complexDescriptor).eInverseRemove(this, EOPPOSITE_FEATURE_BASE - ZPSConfigurationPackage.NOT_IMPLEMENTED__COMPLEX_DESCRIPTOR, null, msgs);
			if (newComplexDescriptor != null)
				msgs = ((InternalEObject)newComplexDescriptor).eInverseAdd(this, EOPPOSITE_FEATURE_BASE - ZPSConfigurationPackage.NOT_IMPLEMENTED__COMPLEX_DESCRIPTOR, null, msgs);
			msgs = basicSetComplexDescriptor(newComplexDescriptor, msgs);
			if (msgs != null) msgs.dispatch();
		}
		else if (eNotificationRequired())
			eNotify(new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.NOT_IMPLEMENTED__COMPLEX_DESCRIPTOR, newComplexDescriptor, newComplexDescriptor));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public DiscoveryTable getDiscoveryTable() {
		return discoveryTable;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public NotificationChain basicSetDiscoveryTable(DiscoveryTable newDiscoveryTable, NotificationChain msgs) {
		DiscoveryTable oldDiscoveryTable = discoveryTable;
		discoveryTable = newDiscoveryTable;
		if (eNotificationRequired()) {
			ENotificationImpl notification = new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.NOT_IMPLEMENTED__DISCOVERY_TABLE, oldDiscoveryTable, newDiscoveryTable);
			if (msgs == null) msgs = notification; else msgs.add(notification);
		}
		return msgs;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void setDiscoveryTable(DiscoveryTable newDiscoveryTable) {
		if (newDiscoveryTable != discoveryTable) {
			NotificationChain msgs = null;
			if (discoveryTable != null)
				msgs = ((InternalEObject)discoveryTable).eInverseRemove(this, EOPPOSITE_FEATURE_BASE - ZPSConfigurationPackage.NOT_IMPLEMENTED__DISCOVERY_TABLE, null, msgs);
			if (newDiscoveryTable != null)
				msgs = ((InternalEObject)newDiscoveryTable).eInverseAdd(this, EOPPOSITE_FEATURE_BASE - ZPSConfigurationPackage.NOT_IMPLEMENTED__DISCOVERY_TABLE, null, msgs);
			msgs = basicSetDiscoveryTable(newDiscoveryTable, msgs);
			if (msgs != null) msgs.dispatch();
		}
		else if (eNotificationRequired())
			eNotify(new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.NOT_IMPLEMENTED__DISCOVERY_TABLE, newDiscoveryTable, newDiscoveryTable));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public DiscoveryCache getDiscoveryCache() {
		return discoveryCache;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public NotificationChain basicSetDiscoveryCache(DiscoveryCache newDiscoveryCache, NotificationChain msgs) {
		DiscoveryCache oldDiscoveryCache = discoveryCache;
		discoveryCache = newDiscoveryCache;
		if (eNotificationRequired()) {
			ENotificationImpl notification = new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.NOT_IMPLEMENTED__DISCOVERY_CACHE, oldDiscoveryCache, newDiscoveryCache);
			if (msgs == null) msgs = notification; else msgs.add(notification);
		}
		return msgs;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void setDiscoveryCache(DiscoveryCache newDiscoveryCache) {
		if (newDiscoveryCache != discoveryCache) {
			NotificationChain msgs = null;
			if (discoveryCache != null)
				msgs = ((InternalEObject)discoveryCache).eInverseRemove(this, EOPPOSITE_FEATURE_BASE - ZPSConfigurationPackage.NOT_IMPLEMENTED__DISCOVERY_CACHE, null, msgs);
			if (newDiscoveryCache != null)
				msgs = ((InternalEObject)newDiscoveryCache).eInverseAdd(this, EOPPOSITE_FEATURE_BASE - ZPSConfigurationPackage.NOT_IMPLEMENTED__DISCOVERY_CACHE, null, msgs);
			msgs = basicSetDiscoveryCache(newDiscoveryCache, msgs);
			if (msgs != null) msgs.dispatch();
		}
		else if (eNotificationRequired())
			eNotify(new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.NOT_IMPLEMENTED__DISCOVERY_CACHE, newDiscoveryCache, newDiscoveryCache));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public BindingCache getBindingCache() {
		return bindingCache;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public NotificationChain basicSetBindingCache(BindingCache newBindingCache, NotificationChain msgs) {
		BindingCache oldBindingCache = bindingCache;
		bindingCache = newBindingCache;
		if (eNotificationRequired()) {
			ENotificationImpl notification = new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.NOT_IMPLEMENTED__BINDING_CACHE, oldBindingCache, newBindingCache);
			if (msgs == null) msgs = notification; else msgs.add(notification);
		}
		return msgs;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void setBindingCache(BindingCache newBindingCache) {
		if (newBindingCache != bindingCache) {
			NotificationChain msgs = null;
			if (bindingCache != null)
				msgs = ((InternalEObject)bindingCache).eInverseRemove(this, EOPPOSITE_FEATURE_BASE - ZPSConfigurationPackage.NOT_IMPLEMENTED__BINDING_CACHE, null, msgs);
			if (newBindingCache != null)
				msgs = ((InternalEObject)newBindingCache).eInverseAdd(this, EOPPOSITE_FEATURE_BASE - ZPSConfigurationPackage.NOT_IMPLEMENTED__BINDING_CACHE, null, msgs);
			msgs = basicSetBindingCache(newBindingCache, msgs);
			if (msgs != null) msgs.dispatch();
		}
		else if (eNotificationRequired())
			eNotify(new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.NOT_IMPLEMENTED__BINDING_CACHE, newBindingCache, newBindingCache));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	@Override
	public NotificationChain eInverseRemove(InternalEObject otherEnd, int featureID, NotificationChain msgs) {
		switch (featureID) {
			case ZPSConfigurationPackage.NOT_IMPLEMENTED__COMPLEX_DESCRIPTOR:
				return basicSetComplexDescriptor(null, msgs);
			case ZPSConfigurationPackage.NOT_IMPLEMENTED__DISCOVERY_TABLE:
				return basicSetDiscoveryTable(null, msgs);
			case ZPSConfigurationPackage.NOT_IMPLEMENTED__DISCOVERY_CACHE:
				return basicSetDiscoveryCache(null, msgs);
			case ZPSConfigurationPackage.NOT_IMPLEMENTED__BINDING_CACHE:
				return basicSetBindingCache(null, msgs);
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
			case ZPSConfigurationPackage.NOT_IMPLEMENTED__COMPLEX_DESCRIPTOR:
				return getComplexDescriptor();
			case ZPSConfigurationPackage.NOT_IMPLEMENTED__DISCOVERY_TABLE:
				return getDiscoveryTable();
			case ZPSConfigurationPackage.NOT_IMPLEMENTED__DISCOVERY_CACHE:
				return getDiscoveryCache();
			case ZPSConfigurationPackage.NOT_IMPLEMENTED__BINDING_CACHE:
				return getBindingCache();
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
			case ZPSConfigurationPackage.NOT_IMPLEMENTED__COMPLEX_DESCRIPTOR:
				setComplexDescriptor((ComplexDescriptor)newValue);
				return;
			case ZPSConfigurationPackage.NOT_IMPLEMENTED__DISCOVERY_TABLE:
				setDiscoveryTable((DiscoveryTable)newValue);
				return;
			case ZPSConfigurationPackage.NOT_IMPLEMENTED__DISCOVERY_CACHE:
				setDiscoveryCache((DiscoveryCache)newValue);
				return;
			case ZPSConfigurationPackage.NOT_IMPLEMENTED__BINDING_CACHE:
				setBindingCache((BindingCache)newValue);
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
			case ZPSConfigurationPackage.NOT_IMPLEMENTED__COMPLEX_DESCRIPTOR:
				setComplexDescriptor((ComplexDescriptor)null);
				return;
			case ZPSConfigurationPackage.NOT_IMPLEMENTED__DISCOVERY_TABLE:
				setDiscoveryTable((DiscoveryTable)null);
				return;
			case ZPSConfigurationPackage.NOT_IMPLEMENTED__DISCOVERY_CACHE:
				setDiscoveryCache((DiscoveryCache)null);
				return;
			case ZPSConfigurationPackage.NOT_IMPLEMENTED__BINDING_CACHE:
				setBindingCache((BindingCache)null);
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
			case ZPSConfigurationPackage.NOT_IMPLEMENTED__COMPLEX_DESCRIPTOR:
				return complexDescriptor != null;
			case ZPSConfigurationPackage.NOT_IMPLEMENTED__DISCOVERY_TABLE:
				return discoveryTable != null;
			case ZPSConfigurationPackage.NOT_IMPLEMENTED__DISCOVERY_CACHE:
				return discoveryCache != null;
			case ZPSConfigurationPackage.NOT_IMPLEMENTED__BINDING_CACHE:
				return bindingCache != null;
		}
		return super.eIsSet(featureID);
	}

} //NotImplementedImpl
