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

import org.eclipse.emf.ecore.util.EObjectWithInverseResolvingEList;
import org.eclipse.emf.ecore.util.InternalEList;

import oscfg.ISR;
import oscfg.InterruptSource;
import oscfg.OscfgPackage;
import oscfg.TypeType;

/**
 * <!-- begin-user-doc -->
 * An implementation of the model object '<em><b>ISR</b></em>'.
 * <!-- end-user-doc -->
 * <p>
 * The following features are implemented:
 * <ul>
 *   <li>{@link oscfg.impl.ISRImpl#getIPL <em>IPL</em>}</li>
 *   <li>{@link oscfg.impl.ISRImpl#getType <em>Type</em>}</li>
 *   <li>{@link oscfg.impl.ISRImpl#getISRSource <em>ISR Source</em>}</li>
 * </ul>
 * </p>
 *
 * @generated
 */
public class ISRImpl extends BaseTaskImpl implements ISR {
	/**
	 * The default value of the '{@link #getIPL() <em>IPL</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getIPL()
	 * @generated
	 * @ordered
	 */
	protected static final int IPL_EDEFAULT = 1; // TODO The default value literal "" is not valid.

	/**
	 * The cached value of the '{@link #getIPL() <em>IPL</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getIPL()
	 * @generated
	 * @ordered
	 */
	protected int ipl = IPL_EDEFAULT;

	/**
	 * The default value of the '{@link #getType() <em>Type</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getType()
	 * @generated
	 * @ordered
	 */
	protected static final TypeType TYPE_EDEFAULT = TypeType.CONTROLLED;

	/**
	 * The cached value of the '{@link #getType() <em>Type</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getType()
	 * @generated
	 * @ordered
	 */
	protected TypeType type = TYPE_EDEFAULT;

	/**
	 * This is true if the Type attribute has been set.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	protected boolean typeESet;

	/**
	 * The cached value of the '{@link #getISRSource() <em>ISR Source</em>}' reference list.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getISRSource()
	 * @generated
	 * @ordered
	 */
	protected EList<InterruptSource> isrSource;

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	protected ISRImpl() {
		super();
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	@Override
	protected EClass eStaticClass() {
		return OscfgPackage.Literals.ISR;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public int getIPL() {
		return ipl;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void setIPL(int newIPL) {
		int oldIPL = ipl;
		ipl = newIPL;
		if (eNotificationRequired())
			eNotify(new ENotificationImpl(this, Notification.SET, OscfgPackage.ISR__IPL, oldIPL, ipl));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public TypeType getType() {
		return type;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void setType(TypeType newType) {
		TypeType oldType = type;
		type = newType == null ? TYPE_EDEFAULT : newType;
		boolean oldTypeESet = typeESet;
		typeESet = true;
		if (eNotificationRequired())
			eNotify(new ENotificationImpl(this, Notification.SET, OscfgPackage.ISR__TYPE, oldType, type, !oldTypeESet));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void unsetType() {
		TypeType oldType = type;
		boolean oldTypeESet = typeESet;
		type = TYPE_EDEFAULT;
		typeESet = false;
		if (eNotificationRequired())
			eNotify(new ENotificationImpl(this, Notification.UNSET, OscfgPackage.ISR__TYPE, oldType, TYPE_EDEFAULT, oldTypeESet));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public boolean isSetType() {
		return typeESet;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EList<InterruptSource> getISRSource() {
		if (isrSource == null) {
			isrSource = new EObjectWithInverseResolvingEList<InterruptSource>(InterruptSource.class, this, OscfgPackage.ISR__ISR_SOURCE, OscfgPackage.INTERRUPT_SOURCE__SOURCE_ISR);
		}
		return isrSource;
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
			case OscfgPackage.ISR__ISR_SOURCE:
				return ((InternalEList<InternalEObject>)(InternalEList<?>)getISRSource()).basicAdd(otherEnd, msgs);
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
			case OscfgPackage.ISR__ISR_SOURCE:
				return ((InternalEList<?>)getISRSource()).basicRemove(otherEnd, msgs);
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
			case OscfgPackage.ISR__IPL:
				return getIPL();
			case OscfgPackage.ISR__TYPE:
				return getType();
			case OscfgPackage.ISR__ISR_SOURCE:
				return getISRSource();
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
			case OscfgPackage.ISR__IPL:
				setIPL((Integer)newValue);
				return;
			case OscfgPackage.ISR__TYPE:
				setType((TypeType)newValue);
				return;
			case OscfgPackage.ISR__ISR_SOURCE:
				getISRSource().clear();
				getISRSource().addAll((Collection<? extends InterruptSource>)newValue);
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
			case OscfgPackage.ISR__IPL:
				setIPL(IPL_EDEFAULT);
				return;
			case OscfgPackage.ISR__TYPE:
				unsetType();
				return;
			case OscfgPackage.ISR__ISR_SOURCE:
				getISRSource().clear();
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
			case OscfgPackage.ISR__IPL:
				return ipl != IPL_EDEFAULT;
			case OscfgPackage.ISR__TYPE:
				return isSetType();
			case OscfgPackage.ISR__ISR_SOURCE:
				return isrSource != null && !isrSource.isEmpty();
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
		result.append(" (IPL: ");
		result.append(ipl);
		result.append(", type: ");
		if (typeESet) result.append(type); else result.append("<unset>");
		result.append(')');
		return result.toString();
	}

} //ISRImpl
