/**
 * <copyright>
 * </copyright>
 *
 * $Id$
 */
package oscfg.impl;

import java.util.Collection;

import org.eclipse.emf.common.notify.Notification;
import org.eclipse.emf.common.notify.NotificationChain;

import org.eclipse.emf.common.util.EList;

import org.eclipse.emf.ecore.EClass;
import org.eclipse.emf.ecore.InternalEObject;

import org.eclipse.emf.ecore.impl.ENotificationImpl;

import org.eclipse.emf.ecore.util.EObjectContainmentEList;
import org.eclipse.emf.ecore.util.InternalEList;

import oscfg.CallbackFunction;
import oscfg.HWCounter;
import oscfg.OscfgPackage;
import oscfg.SWTimer;

/**
 * <!-- begin-user-doc -->
 * An implementation of the model object '<em><b>HW Counter</b></em>'.
 * <!-- end-user-doc -->
 * <p>
 * The following features are implemented:
 * <ul>
 *   <li>{@link oscfg.impl.HWCounterImpl#getSWTimers <em>SW Timers</em>}</li>
 *   <li>{@link oscfg.impl.HWCounterImpl#getDisable_callback <em>Disable callback</em>}</li>
 *   <li>{@link oscfg.impl.HWCounterImpl#getEnable_callback <em>Enable callback</em>}</li>
 *   <li>{@link oscfg.impl.HWCounterImpl#getGet_callback <em>Get callback</em>}</li>
 *   <li>{@link oscfg.impl.HWCounterImpl#getSet_callback <em>Set callback</em>}</li>
 * </ul>
 * </p>
 *
 * @generated
 */
public class HWCounterImpl extends NamedObjectImpl implements HWCounter {
	/**
	 * The cached value of the '{@link #getSWTimers() <em>SW Timers</em>}' containment reference list.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getSWTimers()
	 * @generated
	 * @ordered
	 */
	protected EList<SWTimer> swTimers;

	/**
	 * The cached value of the '{@link #getDisable_callback() <em>Disable callback</em>}' reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getDisable_callback()
	 * @generated
	 * @ordered
	 */
	protected CallbackFunction disable_callback;

	/**
	 * The cached value of the '{@link #getEnable_callback() <em>Enable callback</em>}' reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getEnable_callback()
	 * @generated
	 * @ordered
	 */
	protected CallbackFunction enable_callback;

	/**
	 * The cached value of the '{@link #getGet_callback() <em>Get callback</em>}' reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getGet_callback()
	 * @generated
	 * @ordered
	 */
	protected CallbackFunction get_callback;

	/**
	 * The cached value of the '{@link #getSet_callback() <em>Set callback</em>}' reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getSet_callback()
	 * @generated
	 * @ordered
	 */
	protected CallbackFunction set_callback;

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	protected HWCounterImpl() {
		super();
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	@Override
	protected EClass eStaticClass() {
		return OscfgPackage.Literals.HW_COUNTER;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EList<SWTimer> getSWTimers() {
		if (swTimers == null) {
			swTimers = new EObjectContainmentEList<SWTimer>(SWTimer.class, this, OscfgPackage.HW_COUNTER__SW_TIMERS);
		}
		return swTimers;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public CallbackFunction getDisable_callback() {
		if (disable_callback != null && disable_callback.eIsProxy()) {
			InternalEObject oldDisable_callback = (InternalEObject)disable_callback;
			disable_callback = (CallbackFunction)eResolveProxy(oldDisable_callback);
			if (disable_callback != oldDisable_callback) {
				if (eNotificationRequired())
					eNotify(new ENotificationImpl(this, Notification.RESOLVE, OscfgPackage.HW_COUNTER__DISABLE_CALLBACK, oldDisable_callback, disable_callback));
			}
		}
		return disable_callback;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public CallbackFunction basicGetDisable_callback() {
		return disable_callback;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void setDisable_callback(CallbackFunction newDisable_callback) {
		CallbackFunction oldDisable_callback = disable_callback;
		disable_callback = newDisable_callback;
		if (eNotificationRequired())
			eNotify(new ENotificationImpl(this, Notification.SET, OscfgPackage.HW_COUNTER__DISABLE_CALLBACK, oldDisable_callback, disable_callback));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public CallbackFunction getEnable_callback() {
		if (enable_callback != null && enable_callback.eIsProxy()) {
			InternalEObject oldEnable_callback = (InternalEObject)enable_callback;
			enable_callback = (CallbackFunction)eResolveProxy(oldEnable_callback);
			if (enable_callback != oldEnable_callback) {
				if (eNotificationRequired())
					eNotify(new ENotificationImpl(this, Notification.RESOLVE, OscfgPackage.HW_COUNTER__ENABLE_CALLBACK, oldEnable_callback, enable_callback));
			}
		}
		return enable_callback;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public CallbackFunction basicGetEnable_callback() {
		return enable_callback;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void setEnable_callback(CallbackFunction newEnable_callback) {
		CallbackFunction oldEnable_callback = enable_callback;
		enable_callback = newEnable_callback;
		if (eNotificationRequired())
			eNotify(new ENotificationImpl(this, Notification.SET, OscfgPackage.HW_COUNTER__ENABLE_CALLBACK, oldEnable_callback, enable_callback));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public CallbackFunction getGet_callback() {
		if (get_callback != null && get_callback.eIsProxy()) {
			InternalEObject oldGet_callback = (InternalEObject)get_callback;
			get_callback = (CallbackFunction)eResolveProxy(oldGet_callback);
			if (get_callback != oldGet_callback) {
				if (eNotificationRequired())
					eNotify(new ENotificationImpl(this, Notification.RESOLVE, OscfgPackage.HW_COUNTER__GET_CALLBACK, oldGet_callback, get_callback));
			}
		}
		return get_callback;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public CallbackFunction basicGetGet_callback() {
		return get_callback;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void setGet_callback(CallbackFunction newGet_callback) {
		CallbackFunction oldGet_callback = get_callback;
		get_callback = newGet_callback;
		if (eNotificationRequired())
			eNotify(new ENotificationImpl(this, Notification.SET, OscfgPackage.HW_COUNTER__GET_CALLBACK, oldGet_callback, get_callback));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public CallbackFunction getSet_callback() {
		if (set_callback != null && set_callback.eIsProxy()) {
			InternalEObject oldSet_callback = (InternalEObject)set_callback;
			set_callback = (CallbackFunction)eResolveProxy(oldSet_callback);
			if (set_callback != oldSet_callback) {
				if (eNotificationRequired())
					eNotify(new ENotificationImpl(this, Notification.RESOLVE, OscfgPackage.HW_COUNTER__SET_CALLBACK, oldSet_callback, set_callback));
			}
		}
		return set_callback;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public CallbackFunction basicGetSet_callback() {
		return set_callback;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void setSet_callback(CallbackFunction newSet_callback) {
		CallbackFunction oldSet_callback = set_callback;
		set_callback = newSet_callback;
		if (eNotificationRequired())
			eNotify(new ENotificationImpl(this, Notification.SET, OscfgPackage.HW_COUNTER__SET_CALLBACK, oldSet_callback, set_callback));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	@Override
	public NotificationChain eInverseRemove(InternalEObject otherEnd, int featureID, NotificationChain msgs) {
		switch (featureID) {
			case OscfgPackage.HW_COUNTER__SW_TIMERS:
				return ((InternalEList<?>)getSWTimers()).basicRemove(otherEnd, msgs);
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
			case OscfgPackage.HW_COUNTER__SW_TIMERS:
				return getSWTimers();
			case OscfgPackage.HW_COUNTER__DISABLE_CALLBACK:
				if (resolve) return getDisable_callback();
				return basicGetDisable_callback();
			case OscfgPackage.HW_COUNTER__ENABLE_CALLBACK:
				if (resolve) return getEnable_callback();
				return basicGetEnable_callback();
			case OscfgPackage.HW_COUNTER__GET_CALLBACK:
				if (resolve) return getGet_callback();
				return basicGetGet_callback();
			case OscfgPackage.HW_COUNTER__SET_CALLBACK:
				if (resolve) return getSet_callback();
				return basicGetSet_callback();
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
			case OscfgPackage.HW_COUNTER__SW_TIMERS:
				getSWTimers().clear();
				getSWTimers().addAll((Collection<? extends SWTimer>)newValue);
				return;
			case OscfgPackage.HW_COUNTER__DISABLE_CALLBACK:
				setDisable_callback((CallbackFunction)newValue);
				return;
			case OscfgPackage.HW_COUNTER__ENABLE_CALLBACK:
				setEnable_callback((CallbackFunction)newValue);
				return;
			case OscfgPackage.HW_COUNTER__GET_CALLBACK:
				setGet_callback((CallbackFunction)newValue);
				return;
			case OscfgPackage.HW_COUNTER__SET_CALLBACK:
				setSet_callback((CallbackFunction)newValue);
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
			case OscfgPackage.HW_COUNTER__SW_TIMERS:
				getSWTimers().clear();
				return;
			case OscfgPackage.HW_COUNTER__DISABLE_CALLBACK:
				setDisable_callback((CallbackFunction)null);
				return;
			case OscfgPackage.HW_COUNTER__ENABLE_CALLBACK:
				setEnable_callback((CallbackFunction)null);
				return;
			case OscfgPackage.HW_COUNTER__GET_CALLBACK:
				setGet_callback((CallbackFunction)null);
				return;
			case OscfgPackage.HW_COUNTER__SET_CALLBACK:
				setSet_callback((CallbackFunction)null);
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
			case OscfgPackage.HW_COUNTER__SW_TIMERS:
				return swTimers != null && !swTimers.isEmpty();
			case OscfgPackage.HW_COUNTER__DISABLE_CALLBACK:
				return disable_callback != null;
			case OscfgPackage.HW_COUNTER__ENABLE_CALLBACK:
				return enable_callback != null;
			case OscfgPackage.HW_COUNTER__GET_CALLBACK:
				return get_callback != null;
			case OscfgPackage.HW_COUNTER__SET_CALLBACK:
				return set_callback != null;
		}
		return super.eIsSet(featureID);
	}

} //HWCounterImpl
