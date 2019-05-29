/**
 * <copyright>
 * </copyright>
 *
 * $Id$
 */
package oscfg.impl;

import java.util.Collection;

import org.eclipse.emf.common.notify.NotificationChain;

import org.eclipse.emf.common.util.EList;

import org.eclipse.emf.ecore.EClass;
import org.eclipse.emf.ecore.InternalEObject;

import org.eclipse.emf.ecore.util.EObjectContainmentWithInverseEList;
import org.eclipse.emf.ecore.util.InternalEList;

import oscfg.CooperativeGroup;
import oscfg.OscfgPackage;
import oscfg.Task;

/**
 * <!-- begin-user-doc -->
 * An implementation of the model object '<em><b>Cooperative Group</b></em>'.
 * <!-- end-user-doc -->
 * <p>
 * The following features are implemented:
 * <ul>
 *   <li>{@link oscfg.impl.CooperativeGroupImpl#getCooperativeTasks <em>Cooperative Tasks</em>}</li>
 * </ul>
 * </p>
 *
 * @generated
 */
public class CooperativeGroupImpl extends NamedObjectImpl implements CooperativeGroup {
	/**
	 * The cached value of the '{@link #getCooperativeTasks() <em>Cooperative Tasks</em>}' containment reference list.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getCooperativeTasks()
	 * @generated
	 * @ordered
	 */
	protected EList<Task> cooperativeTasks;

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	protected CooperativeGroupImpl() {
		super();
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	@Override
	protected EClass eStaticClass() {
		return OscfgPackage.Literals.COOPERATIVE_GROUP;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EList<Task> getCooperativeTasks() {
		if (cooperativeTasks == null) {
			cooperativeTasks = new EObjectContainmentWithInverseEList<Task>(Task.class, this, OscfgPackage.COOPERATIVE_GROUP__COOPERATIVE_TASKS, OscfgPackage.TASK__COOPERATIVE_GROUP);
		}
		return cooperativeTasks;
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
			case OscfgPackage.COOPERATIVE_GROUP__COOPERATIVE_TASKS:
				return ((InternalEList<InternalEObject>)(InternalEList<?>)getCooperativeTasks()).basicAdd(otherEnd, msgs);
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
			case OscfgPackage.COOPERATIVE_GROUP__COOPERATIVE_TASKS:
				return ((InternalEList<?>)getCooperativeTasks()).basicRemove(otherEnd, msgs);
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
			case OscfgPackage.COOPERATIVE_GROUP__COOPERATIVE_TASKS:
				return getCooperativeTasks();
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
			case OscfgPackage.COOPERATIVE_GROUP__COOPERATIVE_TASKS:
				getCooperativeTasks().clear();
				getCooperativeTasks().addAll((Collection<? extends Task>)newValue);
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
			case OscfgPackage.COOPERATIVE_GROUP__COOPERATIVE_TASKS:
				getCooperativeTasks().clear();
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
			case OscfgPackage.COOPERATIVE_GROUP__COOPERATIVE_TASKS:
				return cooperativeTasks != null && !cooperativeTasks.isEmpty();
		}
		return super.eIsSet(featureID);
	}

} //CooperativeGroupImpl
