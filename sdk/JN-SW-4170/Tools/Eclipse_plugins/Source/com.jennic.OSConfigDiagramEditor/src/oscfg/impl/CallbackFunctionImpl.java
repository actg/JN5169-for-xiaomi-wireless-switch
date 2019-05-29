/**
 * <copyright>
 * </copyright>
 *
 * $Id$
 */
package oscfg.impl;

import java.util.Collection;
import org.eclipse.emf.common.util.EList;

import org.eclipse.emf.ecore.EClass;

import org.eclipse.emf.ecore.util.EObjectResolvingEList;

import oscfg.CallbackFunction;
import oscfg.Message;
import oscfg.OscfgPackage;
import oscfg.Poster;

/**
 * <!-- begin-user-doc -->
 * An implementation of the model object '<em><b>Callback Function</b></em>'.
 * <!-- end-user-doc -->
 * <p>
 * The following features are implemented:
 * <ul>
 *   <li>{@link oscfg.impl.CallbackFunctionImpl#getPostMessage <em>Post Message</em>}</li>
 * </ul>
 * </p>
 *
 * @generated
 */
public class CallbackFunctionImpl extends NamedObjectImpl implements CallbackFunction {
	/**
	 * The cached value of the '{@link #getPostMessage() <em>Post Message</em>}' reference list.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getPostMessage()
	 * @generated
	 * @ordered
	 */
	protected EList<Message> postMessage;

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	protected CallbackFunctionImpl() {
		super();
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	@Override
	protected EClass eStaticClass() {
		return OscfgPackage.Literals.CALLBACK_FUNCTION;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EList<Message> getPostMessage() {
		if (postMessage == null) {
			postMessage = new EObjectResolvingEList<Message>(Message.class, this, OscfgPackage.CALLBACK_FUNCTION__POST_MESSAGE);
		}
		return postMessage;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	@Override
	public Object eGet(int featureID, boolean resolve, boolean coreType) {
		switch (featureID) {
			case OscfgPackage.CALLBACK_FUNCTION__POST_MESSAGE:
				return getPostMessage();
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
			case OscfgPackage.CALLBACK_FUNCTION__POST_MESSAGE:
				getPostMessage().clear();
				getPostMessage().addAll((Collection<? extends Message>)newValue);
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
			case OscfgPackage.CALLBACK_FUNCTION__POST_MESSAGE:
				getPostMessage().clear();
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
			case OscfgPackage.CALLBACK_FUNCTION__POST_MESSAGE:
				return postMessage != null && !postMessage.isEmpty();
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
		if (baseClass == Poster.class) {
			switch (derivedFeatureID) {
				case OscfgPackage.CALLBACK_FUNCTION__POST_MESSAGE: return OscfgPackage.POSTER__POST_MESSAGE;
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
		if (baseClass == Poster.class) {
			switch (baseFeatureID) {
				case OscfgPackage.POSTER__POST_MESSAGE: return OscfgPackage.CALLBACK_FUNCTION__POST_MESSAGE;
				default: return -1;
			}
		}
		return super.eDerivedStructuralFeatureID(baseFeatureID, baseClass);
	}

} //CallbackFunctionImpl
