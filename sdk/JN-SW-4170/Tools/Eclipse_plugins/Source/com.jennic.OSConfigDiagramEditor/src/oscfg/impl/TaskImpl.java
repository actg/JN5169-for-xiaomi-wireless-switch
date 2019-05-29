/**
 * <copyright>
 * </copyright>
 *
 * $Id$
 */
package oscfg.impl;

import org.eclipse.emf.common.notify.Notification;
import org.eclipse.emf.common.notify.NotificationChain;

import org.eclipse.emf.ecore.EClass;
import org.eclipse.emf.ecore.InternalEObject;

import org.eclipse.emf.ecore.impl.ENotificationImpl;

import org.eclipse.emf.ecore.util.EcoreUtil;

import oscfg.AutostartedType;
import oscfg.CooperativeGroup;
import oscfg.OscfgPackage;
import oscfg.Task;

/**
 * <!-- begin-user-doc -->
 * An implementation of the model object '<em><b>Task</b></em>'.
 * <!-- end-user-doc -->
 * <p>
 * The following features are implemented:
 * <ul>
 *   <li>{@link oscfg.impl.TaskImpl#getAutostarted <em>Autostarted</em>}</li>
 *   <li>{@link oscfg.impl.TaskImpl#getPriority <em>Priority</em>}</li>
 *   <li>{@link oscfg.impl.TaskImpl#getCooperativeGroup <em>Cooperative Group</em>}</li>
 * </ul>
 * </p>
 *
 * @generated
 */
public class TaskImpl extends BaseTaskImpl implements Task {
	/**
	 * The default value of the '{@link #getAutostarted() <em>Autostarted</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getAutostarted()
	 * @generated
	 * @ordered
	 */
	protected static final AutostartedType AUTOSTARTED_EDEFAULT = AutostartedType.FALSE;

	/**
	 * The cached value of the '{@link #getAutostarted() <em>Autostarted</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getAutostarted()
	 * @generated
	 * @ordered
	 */
	protected AutostartedType autostarted = AUTOSTARTED_EDEFAULT;

	/**
	 * This is true if the Autostarted attribute has been set.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	protected boolean autostartedESet;

	/**
	 * The default value of the '{@link #getPriority() <em>Priority</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getPriority()
	 * @generated
	 * @ordered
	 */
	protected static final int PRIORITY_EDEFAULT = 1;

	/**
	 * The cached value of the '{@link #getPriority() <em>Priority</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getPriority()
	 * @generated
	 * @ordered
	 */
	protected int priority = PRIORITY_EDEFAULT;

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	protected TaskImpl() {
		super();
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	@Override
	protected EClass eStaticClass() {
		return OscfgPackage.Literals.TASK;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public AutostartedType getAutostarted() {
		return autostarted;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void setAutostarted(AutostartedType newAutostarted) {
		AutostartedType oldAutostarted = autostarted;
		autostarted = newAutostarted == null ? AUTOSTARTED_EDEFAULT : newAutostarted;
		boolean oldAutostartedESet = autostartedESet;
		autostartedESet = true;
		if (eNotificationRequired())
			eNotify(new ENotificationImpl(this, Notification.SET, OscfgPackage.TASK__AUTOSTARTED, oldAutostarted, autostarted, !oldAutostartedESet));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void unsetAutostarted() {
		AutostartedType oldAutostarted = autostarted;
		boolean oldAutostartedESet = autostartedESet;
		autostarted = AUTOSTARTED_EDEFAULT;
		autostartedESet = false;
		if (eNotificationRequired())
			eNotify(new ENotificationImpl(this, Notification.UNSET, OscfgPackage.TASK__AUTOSTARTED, oldAutostarted, AUTOSTARTED_EDEFAULT, oldAutostartedESet));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public boolean isSetAutostarted() {
		return autostartedESet;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public int getPriority() {
		return priority;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void setPriority(int newPriority) {
		int oldPriority = priority;
		priority = newPriority;
		if (eNotificationRequired())
			eNotify(new ENotificationImpl(this, Notification.SET, OscfgPackage.TASK__PRIORITY, oldPriority, priority));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public CooperativeGroup getCooperativeGroup() {
		if (eContainerFeatureID() != OscfgPackage.TASK__COOPERATIVE_GROUP) return null;
		return (CooperativeGroup)eInternalContainer();
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public NotificationChain basicSetCooperativeGroup(CooperativeGroup newCooperativeGroup, NotificationChain msgs) {
		msgs = eBasicSetContainer((InternalEObject)newCooperativeGroup, OscfgPackage.TASK__COOPERATIVE_GROUP, msgs);
		return msgs;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void setCooperativeGroup(CooperativeGroup newCooperativeGroup) {
		if (newCooperativeGroup != eInternalContainer() || (eContainerFeatureID() != OscfgPackage.TASK__COOPERATIVE_GROUP && newCooperativeGroup != null)) {
			if (EcoreUtil.isAncestor(this, newCooperativeGroup))
				throw new IllegalArgumentException("Recursive containment not allowed for " + toString());
			NotificationChain msgs = null;
			if (eInternalContainer() != null)
				msgs = eBasicRemoveFromContainer(msgs);
			if (newCooperativeGroup != null)
				msgs = ((InternalEObject)newCooperativeGroup).eInverseAdd(this, OscfgPackage.COOPERATIVE_GROUP__COOPERATIVE_TASKS, CooperativeGroup.class, msgs);
			msgs = basicSetCooperativeGroup(newCooperativeGroup, msgs);
			if (msgs != null) msgs.dispatch();
		}
		else if (eNotificationRequired())
			eNotify(new ENotificationImpl(this, Notification.SET, OscfgPackage.TASK__COOPERATIVE_GROUP, newCooperativeGroup, newCooperativeGroup));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	@Override
	public NotificationChain eInverseAdd(InternalEObject otherEnd, int featureID, NotificationChain msgs) {
		switch (featureID) {
			case OscfgPackage.TASK__COOPERATIVE_GROUP:
				if (eInternalContainer() != null)
					msgs = eBasicRemoveFromContainer(msgs);
				return basicSetCooperativeGroup((CooperativeGroup)otherEnd, msgs);
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
			case OscfgPackage.TASK__COOPERATIVE_GROUP:
				return basicSetCooperativeGroup(null, msgs);
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
			case OscfgPackage.TASK__COOPERATIVE_GROUP:
				return eInternalContainer().eInverseRemove(this, OscfgPackage.COOPERATIVE_GROUP__COOPERATIVE_TASKS, CooperativeGroup.class, msgs);
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
			case OscfgPackage.TASK__AUTOSTARTED:
				return getAutostarted();
			case OscfgPackage.TASK__PRIORITY:
				return getPriority();
			case OscfgPackage.TASK__COOPERATIVE_GROUP:
				return getCooperativeGroup();
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
			case OscfgPackage.TASK__AUTOSTARTED:
				setAutostarted((AutostartedType)newValue);
				return;
			case OscfgPackage.TASK__PRIORITY:
				setPriority((Integer)newValue);
				return;
			case OscfgPackage.TASK__COOPERATIVE_GROUP:
				setCooperativeGroup((CooperativeGroup)newValue);
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
			case OscfgPackage.TASK__AUTOSTARTED:
				unsetAutostarted();
				return;
			case OscfgPackage.TASK__PRIORITY:
				setPriority(PRIORITY_EDEFAULT);
				return;
			case OscfgPackage.TASK__COOPERATIVE_GROUP:
				setCooperativeGroup((CooperativeGroup)null);
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
			case OscfgPackage.TASK__AUTOSTARTED:
				return isSetAutostarted();
			case OscfgPackage.TASK__PRIORITY:
				return priority != PRIORITY_EDEFAULT;
			case OscfgPackage.TASK__COOPERATIVE_GROUP:
				return getCooperativeGroup() != null;
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
		result.append(" (autostarted: ");
		if (autostartedESet) result.append(autostarted); else result.append("<unset>");
		result.append(", priority: ");
		result.append(priority);
		result.append(')');
		return result.toString();
	}

} //TaskImpl
