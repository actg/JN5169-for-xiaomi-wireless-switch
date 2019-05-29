/**
 * <copyright>
 * </copyright>
 *
 * $Id$
 */
package oscfg;

/**
 * <!-- begin-user-doc -->
 * A representation of the model object '<em><b>Task</b></em>'.
 * <!-- end-user-doc -->
 *
 * <p>
 * The following features are supported:
 * <ul>
 *   <li>{@link oscfg.Task#getAutostarted <em>Autostarted</em>}</li>
 *   <li>{@link oscfg.Task#getPriority <em>Priority</em>}</li>
 *   <li>{@link oscfg.Task#getCooperativeGroup <em>Cooperative Group</em>}</li>
 * </ul>
 * </p>
 *
 * @see oscfg.OscfgPackage#getTask()
 * @model
 * @generated
 */
public interface Task extends BaseTask {
	/**
	 * Returns the value of the '<em><b>Autostarted</b></em>' attribute.
	 * The default value is <code>"false"</code>.
	 * The literals are from the enumeration {@link oscfg.AutostartedType}.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Autostarted</em>' attribute isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Autostarted</em>' attribute.
	 * @see oscfg.AutostartedType
	 * @see #isSetAutostarted()
	 * @see #unsetAutostarted()
	 * @see #setAutostarted(AutostartedType)
	 * @see oscfg.OscfgPackage#getTask_Autostarted()
	 * @model default="false" unique="false" unsettable="true"
	 *        extendedMetaData="kind='attribute' name='autostarted' namespace='##targetNamespace' nsPrefix='oscfg' form='qualified'"
	 * @generated
	 */
	AutostartedType getAutostarted();

	/**
	 * Sets the value of the '{@link oscfg.Task#getAutostarted <em>Autostarted</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>Autostarted</em>' attribute.
	 * @see oscfg.AutostartedType
	 * @see #isSetAutostarted()
	 * @see #unsetAutostarted()
	 * @see #getAutostarted()
	 * @generated
	 */
	void setAutostarted(AutostartedType value);

	/**
	 * Unsets the value of the '{@link oscfg.Task#getAutostarted <em>Autostarted</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #isSetAutostarted()
	 * @see #getAutostarted()
	 * @see #setAutostarted(AutostartedType)
	 * @generated
	 */
	void unsetAutostarted();

	/**
	 * Returns whether the value of the '{@link oscfg.Task#getAutostarted <em>Autostarted</em>}' attribute is set.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return whether the value of the '<em>Autostarted</em>' attribute is set.
	 * @see #unsetAutostarted()
	 * @see #getAutostarted()
	 * @see #setAutostarted(AutostartedType)
	 * @generated
	 */
	boolean isSetAutostarted();

	/**
	 * Returns the value of the '<em><b>Priority</b></em>' attribute.
	 * The default value is <code>"1"</code>.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Priority</em>' attribute isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Priority</em>' attribute.
	 * @see #setPriority(int)
	 * @see oscfg.OscfgPackage#getTask_Priority()
	 * @model default="1" unique="false" dataType="oscfg.TaskPriorityType" required="true"
	 *        extendedMetaData="kind='attribute' name='priority' namespace='##targetNamespace'"
	 * @generated
	 */
	int getPriority();

	/**
	 * Sets the value of the '{@link oscfg.Task#getPriority <em>Priority</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>Priority</em>' attribute.
	 * @see #getPriority()
	 * @generated
	 */
	void setPriority(int value);

	/**
	 * Returns the value of the '<em><b>Cooperative Group</b></em>' container reference.
	 * It is bidirectional and its opposite is '{@link oscfg.CooperativeGroup#getCooperativeTasks <em>Cooperative Tasks</em>}'.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Cooperative Group</em>' container reference isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Cooperative Group</em>' container reference.
	 * @see #setCooperativeGroup(CooperativeGroup)
	 * @see oscfg.OscfgPackage#getTask_CooperativeGroup()
	 * @see oscfg.CooperativeGroup#getCooperativeTasks
	 * @model opposite="CooperativeTasks" transient="false"
	 * @generated
	 */
	CooperativeGroup getCooperativeGroup();

	/**
	 * Sets the value of the '{@link oscfg.Task#getCooperativeGroup <em>Cooperative Group</em>}' container reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>Cooperative Group</em>' container reference.
	 * @see #getCooperativeGroup()
	 * @generated
	 */
	void setCooperativeGroup(CooperativeGroup value);

} // Task
