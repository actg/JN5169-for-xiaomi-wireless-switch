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
 * A representation of the model object '<em><b>Module</b></em>'.
 * <!-- end-user-doc -->
 *
 * <p>
 * The following features are supported:
 * <ul>
 *   <li>{@link oscfg.Module#getISRs <em>IS Rs</em>}</li>
 *   <li>{@link oscfg.Module#getMutexs <em>Mutexs</em>}</li>
 *   <li>{@link oscfg.Module#getMessages <em>Messages</em>}</li>
 *   <li>{@link oscfg.Module#getHWCounters <em>HW Counters</em>}</li>
 *   <li>{@link oscfg.Module#getCallbacks <em>Callbacks</em>}</li>
 *   <li>{@link oscfg.Module#getInterruptSources <em>Interrupt Sources</em>}</li>
 *   <li>{@link oscfg.Module#getTasks <em>Tasks</em>}</li>
 *   <li>{@link oscfg.Module#getCooperativeTaskGroups <em>Cooperative Task Groups</em>}</li>
 * </ul>
 * </p>
 *
 * @see oscfg.OscfgPackage#getModule()
 * @model
 * @generated
 */
public interface Module extends NamedObject {
	/**
	 * Returns the value of the '<em><b>IS Rs</b></em>' containment reference list.
	 * The list contents are of type {@link oscfg.ISR}.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>IS Rs</em>' containment reference list isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>IS Rs</em>' containment reference list.
	 * @see oscfg.OscfgPackage#getModule_ISRs()
	 * @model containment="true"
	 *        extendedMetaData="kind='element' name='ISR' namespace='##targetNamespace'"
	 * @generated
	 */
	EList<ISR> getISRs();

	/**
	 * Returns the value of the '<em><b>Mutexs</b></em>' containment reference list.
	 * The list contents are of type {@link oscfg.Mutex}.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Mutexs</em>' containment reference list isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Mutexs</em>' containment reference list.
	 * @see oscfg.OscfgPackage#getModule_Mutexs()
	 * @model containment="true"
	 *        extendedMetaData="kind='element' name='Mutex' namespace='##targetNamespace'"
	 * @generated
	 */
	EList<Mutex> getMutexs();

	/**
	 * Returns the value of the '<em><b>Messages</b></em>' containment reference list.
	 * The list contents are of type {@link oscfg.Message}.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Messages</em>' containment reference list isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Messages</em>' containment reference list.
	 * @see oscfg.OscfgPackage#getModule_Messages()
	 * @model containment="true"
	 *        extendedMetaData="kind='element' name='Message' namespace='##targetNamespace'"
	 * @generated
	 */
	EList<Message> getMessages();

	/**
	 * Returns the value of the '<em><b>HW Counters</b></em>' containment reference list.
	 * The list contents are of type {@link oscfg.HWCounter}.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>HW Counters</em>' containment reference list isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>HW Counters</em>' containment reference list.
	 * @see oscfg.OscfgPackage#getModule_HWCounters()
	 * @model containment="true"
	 *        extendedMetaData="kind='element' name='HWCounter'"
	 * @generated
	 */
	EList<HWCounter> getHWCounters();

	/**
	 * Returns the value of the '<em><b>Callbacks</b></em>' containment reference list.
	 * The list contents are of type {@link oscfg.CallbackFunction}.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Callbacks</em>' containment reference list isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Callbacks</em>' containment reference list.
	 * @see oscfg.OscfgPackage#getModule_Callbacks()
	 * @model containment="true"
	 *        extendedMetaData="namespace='##targetNamespace'"
	 * @generated
	 */
	EList<CallbackFunction> getCallbacks();

	/**
	 * Returns the value of the '<em><b>Interrupt Sources</b></em>' containment reference list.
	 * The list contents are of type {@link oscfg.InterruptSource}.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Interrupt Sources</em>' containment reference list isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Interrupt Sources</em>' containment reference list.
	 * @see oscfg.OscfgPackage#getModule_InterruptSources()
	 * @model containment="true" upper="16"
	 *        extendedMetaData="namespace='##targetNamespace'"
	 * @generated
	 */
	EList<InterruptSource> getInterruptSources();

	/**
	 * Returns the value of the '<em><b>Tasks</b></em>' containment reference list.
	 * The list contents are of type {@link oscfg.Task}.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Tasks</em>' containment reference list isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Tasks</em>' containment reference list.
	 * @see oscfg.OscfgPackage#getModule_Tasks()
	 * @model containment="true" upper="32"
	 *        extendedMetaData="kind='element' name='Task' namespace='##targetNamespace'"
	 * @generated
	 */
	EList<Task> getTasks();

	/**
	 * Returns the value of the '<em><b>Cooperative Task Groups</b></em>' containment reference list.
	 * The list contents are of type {@link oscfg.CooperativeGroup}.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Cooperative Task Groups</em>' containment reference list isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Cooperative Task Groups</em>' containment reference list.
	 * @see oscfg.OscfgPackage#getModule_CooperativeTaskGroups()
	 * @model containment="true"
	 *        extendedMetaData="namespace='##targetNamespace'"
	 * @generated
	 */
	EList<CooperativeGroup> getCooperativeTaskGroups();

} // Module
