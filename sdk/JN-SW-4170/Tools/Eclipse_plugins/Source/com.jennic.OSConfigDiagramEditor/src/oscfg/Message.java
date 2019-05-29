/**
 * <copyright>
 * </copyright>
 *
 * $Id$
 */
package oscfg;

/**
 * <!-- begin-user-doc -->
 * A representation of the model object '<em><b>Message</b></em>'.
 * <!-- end-user-doc -->
 *
 * <p>
 * The following features are supported:
 * <ul>
 *   <li>{@link oscfg.Message#getCtype <em>Ctype</em>}</li>
 *   <li>{@link oscfg.Message#getQueue <em>Queue</em>}</li>
 *   <li>{@link oscfg.Message#getNotifies <em>Notifies</em>}</li>
 *   <li>{@link oscfg.Message#getCallsBack <em>Calls Back</em>}</li>
 * </ul>
 * </p>
 *
 * @see oscfg.OscfgPackage#getMessage()
 * @model
 * @generated
 */
public interface Message extends NamedObject {
	/**
	 * Returns the value of the '<em><b>Ctype</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Ctype</em>' attribute isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Ctype</em>' attribute.
	 * @see #setCtype(String)
	 * @see oscfg.OscfgPackage#getMessage_Ctype()
	 * @model unique="false" dataType="org.eclipse.emf.ecore.xml.type.String"
	 *        extendedMetaData="kind='attribute' name='ctype' namespace='##targetNamespace'"
	 * @generated
	 */
	String getCtype();

	/**
	 * Sets the value of the '{@link oscfg.Message#getCtype <em>Ctype</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>Ctype</em>' attribute.
	 * @see #getCtype()
	 * @generated
	 */
	void setCtype(String value);

	/**
	 * Returns the value of the '<em><b>Queue</b></em>' attribute.
	 * The default value is <code>"0"</code>.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Queue</em>' attribute isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Queue</em>' attribute.
	 * @see #setQueue(int)
	 * @see oscfg.OscfgPackage#getMessage_Queue()
	 * @model default="0" unique="false" dataType="oscfg.QueueType"
	 *        extendedMetaData="kind='attribute' name='queue' namespace='##targetNamespace'"
	 * @generated
	 */
	int getQueue();

	/**
	 * Sets the value of the '{@link oscfg.Message#getQueue <em>Queue</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>Queue</em>' attribute.
	 * @see #getQueue()
	 * @generated
	 */
	void setQueue(int value);

	/**
	 * Returns the value of the '<em><b>Notifies</b></em>' reference.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Notifies</em>' reference isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Notifies</em>' reference.
	 * @see #setNotifies(Task)
	 * @see oscfg.OscfgPackage#getMessage_Notifies()
	 * @model extendedMetaData="namespace='##targetNamespace'"
	 * @generated
	 */
	Task getNotifies();

	/**
	 * Sets the value of the '{@link oscfg.Message#getNotifies <em>Notifies</em>}' reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>Notifies</em>' reference.
	 * @see #getNotifies()
	 * @generated
	 */
	void setNotifies(Task value);

	/**
	 * Returns the value of the '<em><b>Calls Back</b></em>' reference.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Calls Back</em>' reference isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Calls Back</em>' reference.
	 * @see #setCallsBack(CallbackFunction)
	 * @see oscfg.OscfgPackage#getMessage_CallsBack()
	 * @model extendedMetaData="namespace='##targetNamespace'"
	 * @generated
	 */
	CallbackFunction getCallsBack();

	/**
	 * Sets the value of the '{@link oscfg.Message#getCallsBack <em>Calls Back</em>}' reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>Calls Back</em>' reference.
	 * @see #getCallsBack()
	 * @generated
	 */
	void setCallsBack(CallbackFunction value);

} // Message
