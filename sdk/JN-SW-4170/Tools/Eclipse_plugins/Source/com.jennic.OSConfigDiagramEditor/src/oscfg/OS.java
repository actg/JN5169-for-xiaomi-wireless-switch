/**
 * <copyright>
 * </copyright>
 *
 * $Id$
 */
package oscfg;

import org.eclipse.emf.common.util.EList;

import org.eclipse.emf.ecore.EObject;

/**
 * <!-- begin-user-doc -->
 * A representation of the model object '<em><b>OS</b></em>'.
 * <!-- end-user-doc -->
 *
 * <p>
 * The following features are supported:
 * <ul>
 *   <li>{@link oscfg.OS#getTarget <em>Target</em>}</li>
 *   <li>{@link oscfg.OS#getModules <em>Modules</em>}</li>
 *   <li>{@link oscfg.OS#isErrorHook <em>Error Hook</em>}</li>
 *   <li>{@link oscfg.OS#isStrictErrorChecks <em>Strict Error Checks</em>}</li>
 *   <li>{@link oscfg.OS#isClearStack <em>Clear Stack</em>}</li>
 * </ul>
 * </p>
 *
 * @see oscfg.OscfgPackage#getOS()
 * @model
 * @generated
 */
public interface OS extends EObject {
	/**
	 * Returns the value of the '<em><b>Target</b></em>' attribute.
	 * The default value is <code>"JN516x"</code>.
	 * The literals are from the enumeration {@link oscfg.TargetTypes}.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Target</em>' attribute isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Target</em>' attribute.
	 * @see oscfg.TargetTypes
	 * @see #setTarget(TargetTypes)
	 * @see oscfg.OscfgPackage#getOS_Target()
	 * @model default="JN516x" required="true"
	 *        extendedMetaData="namespace='##targetNamespace'"
	 * @generated
	 */
	TargetTypes getTarget();

	/**
	 * Sets the value of the '{@link oscfg.OS#getTarget <em>Target</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>Target</em>' attribute.
	 * @see oscfg.TargetTypes
	 * @see #getTarget()
	 * @generated
	 */
	void setTarget(TargetTypes value);

	/**
	 * Returns the value of the '<em><b>Modules</b></em>' containment reference list.
	 * The list contents are of type {@link oscfg.Module}.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Modules</em>' containment reference list isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Modules</em>' containment reference list.
	 * @see oscfg.OscfgPackage#getOS_Modules()
	 * @model containment="true" required="true"
	 *        extendedMetaData="namespace='##targetNamespace'"
	 * @generated
	 */
	EList<Module> getModules();

	/**
	 * Returns the value of the '<em><b>Error Hook</b></em>' attribute.
	 * The default value is <code>"true"</code>.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Error Hook</em>' attribute isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Error Hook</em>' attribute.
	 * @see #setErrorHook(boolean)
	 * @see oscfg.OscfgPackage#getOS_ErrorHook()
	 * @model default="true" required="true"
	 *        extendedMetaData="namespace='##targetNamespace'"
	 * @generated
	 */
	boolean isErrorHook();

	/**
	 * Sets the value of the '{@link oscfg.OS#isErrorHook <em>Error Hook</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>Error Hook</em>' attribute.
	 * @see #isErrorHook()
	 * @generated
	 */
	void setErrorHook(boolean value);

	/**
	 * Returns the value of the '<em><b>Strict Error Checks</b></em>' attribute.
	 * The default value is <code>"true"</code>.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Strict Error Checks</em>' attribute isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Strict Error Checks</em>' attribute.
	 * @see #setStrictErrorChecks(boolean)
	 * @see oscfg.OscfgPackage#getOS_StrictErrorChecks()
	 * @model default="true" required="true"
	 *        extendedMetaData="namespace='##targetNamespace'"
	 * @generated
	 */
	boolean isStrictErrorChecks();

	/**
	 * Sets the value of the '{@link oscfg.OS#isStrictErrorChecks <em>Strict Error Checks</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>Strict Error Checks</em>' attribute.
	 * @see #isStrictErrorChecks()
	 * @generated
	 */
	void setStrictErrorChecks(boolean value);

	/**
	 * Returns the value of the '<em><b>Clear Stack</b></em>' attribute.
	 * The default value is <code>"false"</code>.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Clear Stack</em>' attribute isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Clear Stack</em>' attribute.
	 * @see #setClearStack(boolean)
	 * @see oscfg.OscfgPackage#getOS_ClearStack()
	 * @model default="false" required="true"
	 *        extendedMetaData="namespace='##targetNamespace'"
	 * @generated
	 */
	boolean isClearStack();

	/**
	 * Sets the value of the '{@link oscfg.OS#isClearStack <em>Clear Stack</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>Clear Stack</em>' attribute.
	 * @see #isClearStack()
	 * @generated
	 */
	void setClearStack(boolean value);

} // OS
