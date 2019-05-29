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
import org.eclipse.emf.ecore.impl.EObjectImpl;

import oscfg.ISR;
import oscfg.InterruptSource;
import oscfg.OscfgPackage;
import oscfg.VectorType;

/**
 * <!-- begin-user-doc -->
 * An implementation of the model object '<em><b>Interrupt Source</b></em>'.
 * <!-- end-user-doc -->
 * <p>
 * The following features are implemented:
 * <ul>
 *   <li>{@link oscfg.impl.InterruptSourceImpl#getSource <em>Source</em>}</li>
 *   <li>{@link oscfg.impl.InterruptSourceImpl#getSourceISR <em>Source ISR</em>}</li>
 * </ul>
 * </p>
 *
 * @generated
 */
public class InterruptSourceImpl extends EObjectImpl implements InterruptSource {
	/**
	 * The default value of the '{@link #getSource() <em>Source</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getSource()
	 * @generated
	 * @ordered
	 */
	protected static final VectorType SOURCE_EDEFAULT = VectorType.SYSTEM_CONTROLLER;

	/**
	 * The cached value of the '{@link #getSource() <em>Source</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getSource()
	 * @generated
	 * @ordered
	 */
	protected VectorType source = SOURCE_EDEFAULT;

	/**
	 * This is true if the Source attribute has been set.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	protected boolean sourceESet;

	/**
	 * The cached value of the '{@link #getSourceISR() <em>Source ISR</em>}' reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getSourceISR()
	 * @generated
	 * @ordered
	 */
	protected ISR sourceISR;

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	protected InterruptSourceImpl() {
		super();
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	@Override
	protected EClass eStaticClass() {
		return OscfgPackage.Literals.INTERRUPT_SOURCE;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public VectorType getSource() {
		return source;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void setSource(VectorType newSource) {
		VectorType oldSource = source;
		source = newSource == null ? SOURCE_EDEFAULT : newSource;
		boolean oldSourceESet = sourceESet;
		sourceESet = true;
		if (eNotificationRequired())
			eNotify(new ENotificationImpl(this, Notification.SET, OscfgPackage.INTERRUPT_SOURCE__SOURCE, oldSource, source, !oldSourceESet));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void unsetSource() {
		VectorType oldSource = source;
		boolean oldSourceESet = sourceESet;
		source = SOURCE_EDEFAULT;
		sourceESet = false;
		if (eNotificationRequired())
			eNotify(new ENotificationImpl(this, Notification.UNSET, OscfgPackage.INTERRUPT_SOURCE__SOURCE, oldSource, SOURCE_EDEFAULT, oldSourceESet));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public boolean isSetSource() {
		return sourceESet;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public ISR getSourceISR() {
		if (sourceISR != null && sourceISR.eIsProxy()) {
			InternalEObject oldSourceISR = (InternalEObject)sourceISR;
			sourceISR = (ISR)eResolveProxy(oldSourceISR);
			if (sourceISR != oldSourceISR) {
				if (eNotificationRequired())
					eNotify(new ENotificationImpl(this, Notification.RESOLVE, OscfgPackage.INTERRUPT_SOURCE__SOURCE_ISR, oldSourceISR, sourceISR));
			}
		}
		return sourceISR;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public ISR basicGetSourceISR() {
		return sourceISR;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public NotificationChain basicSetSourceISR(ISR newSourceISR, NotificationChain msgs) {
		ISR oldSourceISR = sourceISR;
		sourceISR = newSourceISR;
		if (eNotificationRequired()) {
			ENotificationImpl notification = new ENotificationImpl(this, Notification.SET, OscfgPackage.INTERRUPT_SOURCE__SOURCE_ISR, oldSourceISR, newSourceISR);
			if (msgs == null) msgs = notification; else msgs.add(notification);
		}
		return msgs;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void setSourceISR(ISR newSourceISR) {
		if (newSourceISR != sourceISR) {
			NotificationChain msgs = null;
			if (sourceISR != null)
				msgs = ((InternalEObject)sourceISR).eInverseRemove(this, OscfgPackage.ISR__ISR_SOURCE, ISR.class, msgs);
			if (newSourceISR != null)
				msgs = ((InternalEObject)newSourceISR).eInverseAdd(this, OscfgPackage.ISR__ISR_SOURCE, ISR.class, msgs);
			msgs = basicSetSourceISR(newSourceISR, msgs);
			if (msgs != null) msgs.dispatch();
		}
		else if (eNotificationRequired())
			eNotify(new ENotificationImpl(this, Notification.SET, OscfgPackage.INTERRUPT_SOURCE__SOURCE_ISR, newSourceISR, newSourceISR));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	@Override
	public NotificationChain eInverseAdd(InternalEObject otherEnd, int featureID, NotificationChain msgs) {
		switch (featureID) {
			case OscfgPackage.INTERRUPT_SOURCE__SOURCE_ISR:
				if (sourceISR != null)
					msgs = ((InternalEObject)sourceISR).eInverseRemove(this, OscfgPackage.ISR__ISR_SOURCE, ISR.class, msgs);
				return basicSetSourceISR((ISR)otherEnd, msgs);
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
			case OscfgPackage.INTERRUPT_SOURCE__SOURCE_ISR:
				return basicSetSourceISR(null, msgs);
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
			case OscfgPackage.INTERRUPT_SOURCE__SOURCE:
				return getSource();
			case OscfgPackage.INTERRUPT_SOURCE__SOURCE_ISR:
				if (resolve) return getSourceISR();
				return basicGetSourceISR();
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
			case OscfgPackage.INTERRUPT_SOURCE__SOURCE:
				setSource((VectorType)newValue);
				return;
			case OscfgPackage.INTERRUPT_SOURCE__SOURCE_ISR:
				setSourceISR((ISR)newValue);
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
			case OscfgPackage.INTERRUPT_SOURCE__SOURCE:
				unsetSource();
				return;
			case OscfgPackage.INTERRUPT_SOURCE__SOURCE_ISR:
				setSourceISR((ISR)null);
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
			case OscfgPackage.INTERRUPT_SOURCE__SOURCE:
				return isSetSource();
			case OscfgPackage.INTERRUPT_SOURCE__SOURCE_ISR:
				return sourceISR != null;
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
		result.append(" (source: ");
		if (sourceESet) result.append(source); else result.append("<unset>");
		result.append(')');
		return result.toString();
	}

} //InterruptSourceImpl
