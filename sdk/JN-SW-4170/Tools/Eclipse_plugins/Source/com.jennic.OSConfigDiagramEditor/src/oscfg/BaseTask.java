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
 * A representation of the model object '<em><b>Base Task</b></em>'.
 * <!-- end-user-doc -->
 *
 * <p>
 * The following features are supported:
 * <ul>
 *   <li>{@link oscfg.BaseTask#getCollectMessage <em>Collect Message</em>}</li>
 *   <li>{@link oscfg.BaseTask#getEnterExitMutex <em>Enter Exit Mutex</em>}</li>
 * </ul>
 * </p>
 *
 * @see oscfg.OscfgPackage#getBaseTask()
 * @model abstract="true"
 * @generated
 */
public interface BaseTask extends NamedObject, Poster {
	/**
	 * Returns the value of the '<em><b>Collect Message</b></em>' reference list.
	 * The list contents are of type {@link oscfg.Message}.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Collect Message</em>' reference list isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Collect Message</em>' reference list.
	 * @see oscfg.OscfgPackage#getBaseTask_CollectMessage()
	 * @model
	 * @generated
	 */
	EList<Message> getCollectMessage();

	/**
	 * Returns the value of the '<em><b>Enter Exit Mutex</b></em>' reference list.
	 * The list contents are of type {@link oscfg.Mutex}.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Enter Exit Mutex</em>' reference list isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Enter Exit Mutex</em>' reference list.
	 * @see oscfg.OscfgPackage#getBaseTask_EnterExitMutex()
	 * @model extendedMetaData="namespace='##targetNamespace'"
	 * @generated
	 */
	EList<Mutex> getEnterExitMutex();

} // BaseTask
