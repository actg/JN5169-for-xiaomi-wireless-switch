/**
 * <copyright>
 * </copyright>
 *
 * $Id$
 */
package oscfg;

import org.eclipse.emf.common.util.EList;

/**
 * <!-- begin-user-doc -->
 * A representation of the model object '<em><b>HW Counter</b></em>'.
 * <!-- end-user-doc -->
 *
 * <p>
 * The following features are supported:
 * <ul>
 *   <li>{@link oscfg.HWCounter#getSWTimers <em>SW Timers</em>}</li>
 *   <li>{@link oscfg.HWCounter#getDisable_callback <em>Disable callback</em>}</li>
 *   <li>{@link oscfg.HWCounter#getEnable_callback <em>Enable callback</em>}</li>
 *   <li>{@link oscfg.HWCounter#getGet_callback <em>Get callback</em>}</li>
 *   <li>{@link oscfg.HWCounter#getSet_callback <em>Set callback</em>}</li>
 * </ul>
 * </p>
 *
 * @see oscfg.OscfgPackage#getHWCounter()
 * @model
 * @generated
 */
public interface HWCounter extends NamedObject {
	/**
	 * Returns the value of the '<em><b>SW Timers</b></em>' containment reference list.
	 * The list contents are of type {@link oscfg.SWTimer}.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>SW Timers</em>' containment reference list isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>SW Timers</em>' containment reference list.
	 * @see oscfg.OscfgPackage#getHWCounter_SWTimers()
	 * @model containment="true"
	 *        extendedMetaData="kind='element' name='SWTimer'"
	 * @generated
	 */
	EList<SWTimer> getSWTimers();

	/**
	 * Returns the value of the '<em><b>Disable callback</b></em>' reference.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Disable callback</em>' reference isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Disable callback</em>' reference.
	 * @see #setDisable_callback(CallbackFunction)
	 * @see oscfg.OscfgPackage#getHWCounter_Disable_callback()
	 * @model extendedMetaData="namespace='##targetNamespace'"
	 * @generated
	 */
	CallbackFunction getDisable_callback();

	/**
	 * Sets the value of the '{@link oscfg.HWCounter#getDisable_callback <em>Disable callback</em>}' reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>Disable callback</em>' reference.
	 * @see #getDisable_callback()
	 * @generated
	 */
	void setDisable_callback(CallbackFunction value);

	/**
	 * Returns the value of the '<em><b>Enable callback</b></em>' reference.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Enable callback</em>' reference isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Enable callback</em>' reference.
	 * @see #setEnable_callback(CallbackFunction)
	 * @see oscfg.OscfgPackage#getHWCounter_Enable_callback()
	 * @model extendedMetaData="namespace='##targetNamespace'"
	 * @generated
	 */
	CallbackFunction getEnable_callback();

	/**
	 * Sets the value of the '{@link oscfg.HWCounter#getEnable_callback <em>Enable callback</em>}' reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>Enable callback</em>' reference.
	 * @see #getEnable_callback()
	 * @generated
	 */
	void setEnable_callback(CallbackFunction value);

	/**
	 * Returns the value of the '<em><b>Get callback</b></em>' reference.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Get callback</em>' reference isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Get callback</em>' reference.
	 * @see #setGet_callback(CallbackFunction)
	 * @see oscfg.OscfgPackage#getHWCounter_Get_callback()
	 * @model required="true"
	 *        extendedMetaData="namespace='##targetNamespace'"
	 * @generated
	 */
	CallbackFunction getGet_callback();

	/**
	 * Sets the value of the '{@link oscfg.HWCounter#getGet_callback <em>Get callback</em>}' reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>Get callback</em>' reference.
	 * @see #getGet_callback()
	 * @generated
	 */
	void setGet_callback(CallbackFunction value);

	/**
	 * Returns the value of the '<em><b>Set callback</b></em>' reference.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Set callback</em>' reference isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Set callback</em>' reference.
	 * @see #setSet_callback(CallbackFunction)
	 * @see oscfg.OscfgPackage#getHWCounter_Set_callback()
	 * @model required="true"
	 *        extendedMetaData="namespace='##targetNamespace'"
	 * @generated
	 */
	CallbackFunction getSet_callback();

	/**
	 * Sets the value of the '{@link oscfg.HWCounter#getSet_callback <em>Set callback</em>}' reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>Set callback</em>' reference.
	 * @see #getSet_callback()
	 * @generated
	 */
	void setSet_callback(CallbackFunction value);

} // HWCounter
