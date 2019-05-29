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
import org.eclipse.emf.ecore.impl.EObjectImpl;

import org.eclipse.emf.ecore.util.EObjectContainmentEList;
import org.eclipse.emf.ecore.util.InternalEList;

import oscfg.Module;
import oscfg.OS;
import oscfg.OscfgPackage;
import oscfg.TargetTypes;

/**
 * <!-- begin-user-doc -->
 * An implementation of the model object '<em><b>OS</b></em>'.
 * <!-- end-user-doc -->
 * <p>
 * The following features are implemented:
 * <ul>
 *   <li>{@link oscfg.impl.OSImpl#getTarget <em>Target</em>}</li>
 *   <li>{@link oscfg.impl.OSImpl#getModules <em>Modules</em>}</li>
 *   <li>{@link oscfg.impl.OSImpl#isErrorHook <em>Error Hook</em>}</li>
 *   <li>{@link oscfg.impl.OSImpl#isStrictErrorChecks <em>Strict Error Checks</em>}</li>
 *   <li>{@link oscfg.impl.OSImpl#isClearStack <em>Clear Stack</em>}</li>
 * </ul>
 * </p>
 *
 * @generated
 */
public class OSImpl extends EObjectImpl implements OS {
	/**
	 * The default value of the '{@link #getTarget() <em>Target</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getTarget()
	 * @generated
	 * @ordered
	 */
	protected static final TargetTypes TARGET_EDEFAULT = TargetTypes.JN51_6X;

	/**
	 * The cached value of the '{@link #getTarget() <em>Target</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getTarget()
	 * @generated
	 * @ordered
	 */
	protected TargetTypes target = TARGET_EDEFAULT;

	/**
	 * The cached value of the '{@link #getModules() <em>Modules</em>}' containment reference list.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getModules()
	 * @generated
	 * @ordered
	 */
	protected EList<Module> modules;

	/**
	 * The default value of the '{@link #isErrorHook() <em>Error Hook</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #isErrorHook()
	 * @generated
	 * @ordered
	 */
	protected static final boolean ERROR_HOOK_EDEFAULT = true;

	/**
	 * The cached value of the '{@link #isErrorHook() <em>Error Hook</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #isErrorHook()
	 * @generated
	 * @ordered
	 */
	protected boolean errorHook = ERROR_HOOK_EDEFAULT;

	/**
	 * The default value of the '{@link #isStrictErrorChecks() <em>Strict Error Checks</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #isStrictErrorChecks()
	 * @generated
	 * @ordered
	 */
	protected static final boolean STRICT_ERROR_CHECKS_EDEFAULT = true;

	/**
	 * The cached value of the '{@link #isStrictErrorChecks() <em>Strict Error Checks</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #isStrictErrorChecks()
	 * @generated
	 * @ordered
	 */
	protected boolean strictErrorChecks = STRICT_ERROR_CHECKS_EDEFAULT;

	/**
	 * The default value of the '{@link #isClearStack() <em>Clear Stack</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #isClearStack()
	 * @generated
	 * @ordered
	 */
	protected static final boolean CLEAR_STACK_EDEFAULT = false;

	/**
	 * The cached value of the '{@link #isClearStack() <em>Clear Stack</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #isClearStack()
	 * @generated
	 * @ordered
	 */
	protected boolean clearStack = CLEAR_STACK_EDEFAULT;

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	protected OSImpl() {
		super();
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	@Override
	protected EClass eStaticClass() {
		return OscfgPackage.Literals.OS;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public TargetTypes getTarget() {
		return target;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void setTarget(TargetTypes newTarget) {
		TargetTypes oldTarget = target;
		target = newTarget == null ? TARGET_EDEFAULT : newTarget;
		if (eNotificationRequired())
			eNotify(new ENotificationImpl(this, Notification.SET, OscfgPackage.OS__TARGET, oldTarget, target));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EList<Module> getModules() {
		if (modules == null) {
			modules = new EObjectContainmentEList<Module>(Module.class, this, OscfgPackage.OS__MODULES);
		}
		return modules;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public boolean isErrorHook() {
		return errorHook;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void setErrorHook(boolean newErrorHook) {
		boolean oldErrorHook = errorHook;
		errorHook = newErrorHook;
		if (eNotificationRequired())
			eNotify(new ENotificationImpl(this, Notification.SET, OscfgPackage.OS__ERROR_HOOK, oldErrorHook, errorHook));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public boolean isStrictErrorChecks() {
		return strictErrorChecks;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void setStrictErrorChecks(boolean newStrictErrorChecks) {
		boolean oldStrictErrorChecks = strictErrorChecks;
		strictErrorChecks = newStrictErrorChecks;
		if (eNotificationRequired())
			eNotify(new ENotificationImpl(this, Notification.SET, OscfgPackage.OS__STRICT_ERROR_CHECKS, oldStrictErrorChecks, strictErrorChecks));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public boolean isClearStack() {
		return clearStack;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void setClearStack(boolean newClearStack) {
		boolean oldClearStack = clearStack;
		clearStack = newClearStack;
		if (eNotificationRequired())
			eNotify(new ENotificationImpl(this, Notification.SET, OscfgPackage.OS__CLEAR_STACK, oldClearStack, clearStack));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	@Override
	public NotificationChain eInverseRemove(InternalEObject otherEnd, int featureID, NotificationChain msgs) {
		switch (featureID) {
			case OscfgPackage.OS__MODULES:
				return ((InternalEList<?>)getModules()).basicRemove(otherEnd, msgs);
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
			case OscfgPackage.OS__TARGET:
				return getTarget();
			case OscfgPackage.OS__MODULES:
				return getModules();
			case OscfgPackage.OS__ERROR_HOOK:
				return isErrorHook();
			case OscfgPackage.OS__STRICT_ERROR_CHECKS:
				return isStrictErrorChecks();
			case OscfgPackage.OS__CLEAR_STACK:
				return isClearStack();
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
			case OscfgPackage.OS__TARGET:
				setTarget((TargetTypes)newValue);
				return;
			case OscfgPackage.OS__MODULES:
				getModules().clear();
				getModules().addAll((Collection<? extends Module>)newValue);
				return;
			case OscfgPackage.OS__ERROR_HOOK:
				setErrorHook((Boolean)newValue);
				return;
			case OscfgPackage.OS__STRICT_ERROR_CHECKS:
				setStrictErrorChecks((Boolean)newValue);
				return;
			case OscfgPackage.OS__CLEAR_STACK:
				setClearStack((Boolean)newValue);
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
			case OscfgPackage.OS__TARGET:
				setTarget(TARGET_EDEFAULT);
				return;
			case OscfgPackage.OS__MODULES:
				getModules().clear();
				return;
			case OscfgPackage.OS__ERROR_HOOK:
				setErrorHook(ERROR_HOOK_EDEFAULT);
				return;
			case OscfgPackage.OS__STRICT_ERROR_CHECKS:
				setStrictErrorChecks(STRICT_ERROR_CHECKS_EDEFAULT);
				return;
			case OscfgPackage.OS__CLEAR_STACK:
				setClearStack(CLEAR_STACK_EDEFAULT);
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
			case OscfgPackage.OS__TARGET:
				return target != TARGET_EDEFAULT;
			case OscfgPackage.OS__MODULES:
				return modules != null && !modules.isEmpty();
			case OscfgPackage.OS__ERROR_HOOK:
				return errorHook != ERROR_HOOK_EDEFAULT;
			case OscfgPackage.OS__STRICT_ERROR_CHECKS:
				return strictErrorChecks != STRICT_ERROR_CHECKS_EDEFAULT;
			case OscfgPackage.OS__CLEAR_STACK:
				return clearStack != CLEAR_STACK_EDEFAULT;
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
		result.append(" (target: ");
		result.append(target);
		result.append(", errorHook: ");
		result.append(errorHook);
		result.append(", strictErrorChecks: ");
		result.append(strictErrorChecks);
		result.append(", clearStack: ");
		result.append(clearStack);
		result.append(')');
		return result.toString();
	}

} //OSImpl
