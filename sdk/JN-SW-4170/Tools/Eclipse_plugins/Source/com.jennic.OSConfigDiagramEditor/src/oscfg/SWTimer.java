/**
 * <copyright>
 * </copyright>
 *
 * $Id$
 */
package oscfg;

/**
 * <!-- begin-user-doc -->
 * A representation of the model object '<em><b>SW Timer</b></em>'.
 * <!-- end-user-doc -->
 *
 * <p>
 * The following features are supported:
 * <ul>
 *   <li>{@link oscfg.SWTimer#getActivates <em>Activates</em>}</li>
 *   <li>{@link oscfg.SWTimer#getTimer_callback <em>Timer callback</em>}</li>
 * </ul>
 * </p>
 *
 * @see oscfg.OscfgPackage#getSWTimer()
 * @model
 * @generated
 */
public interface SWTimer extends NamedObject {
	/**
	 * Returns the value of the '<em><b>Activates</b></em>' reference.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Activates</em>' reference isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Activates</em>' reference.
	 * @see #setActivates(Task)
	 * @see oscfg.OscfgPackage#getSWTimer_Activates()
	 * @model extendedMetaData="namespace='##targetNamespace'"
	 * @generated
	 */
	Task getActivates();

	/**
	 * Sets the value of the '{@link oscfg.SWTimer#getActivates <em>Activates</em>}' reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>Activates</em>' reference.
	 * @see #getActivates()
	 * @generated
	 */
	void setActivates(Task value);

	/**
	 * Returns the value of the '<em><b>Timer callback</b></em>' reference.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Timer callback</em>' reference isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Timer callback</em>' reference.
	 * @see #setTimer_callback(CallbackFunction)
	 * @see oscfg.OscfgPackage#getSWTimer_Timer_callback()
	 * @model
	 * @generated
	 */
	CallbackFunction getTimer_callback();

	/**
	 * Sets the value of the '{@link oscfg.SWTimer#getTimer_callback <em>Timer callback</em>}' reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>Timer callback</em>' reference.
	 * @see #getTimer_callback()
	 * @generated
	 */
	void setTimer_callback(CallbackFunction value);

} // SWTimer
