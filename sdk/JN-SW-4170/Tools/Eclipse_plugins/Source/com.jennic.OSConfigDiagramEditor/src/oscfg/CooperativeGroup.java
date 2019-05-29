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
 * A representation of the model object '<em><b>Cooperative Group</b></em>'.
 * <!-- end-user-doc -->
 *
 * <p>
 * The following features are supported:
 * <ul>
 *   <li>{@link oscfg.CooperativeGroup#getCooperativeTasks <em>Cooperative Tasks</em>}</li>
 * </ul>
 * </p>
 *
 * @see oscfg.OscfgPackage#getCooperativeGroup()
 * @model
 * @generated
 */
public interface CooperativeGroup extends NamedObject {
	/**
	 * Returns the value of the '<em><b>Cooperative Tasks</b></em>' containment reference list.
	 * The list contents are of type {@link oscfg.Task}.
	 * It is bidirectional and its opposite is '{@link oscfg.Task#getCooperativeGroup <em>Cooperative Group</em>}'.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Cooperative Tasks</em>' containment reference list isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Cooperative Tasks</em>' containment reference list.
	 * @see oscfg.OscfgPackage#getCooperativeGroup_CooperativeTasks()
	 * @see oscfg.Task#getCooperativeGroup
	 * @model opposite="CooperativeGroup" containment="true" lower="2" upper="32"
	 *        extendedMetaData="namespace='##targetNamespace'"
	 * @generated
	 */
	EList<Task> getCooperativeTasks();

} // CooperativeGroup
