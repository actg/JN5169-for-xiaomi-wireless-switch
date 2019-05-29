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
 * A representation of the model object '<em><b>Poster</b></em>'.
 * <!-- end-user-doc -->
 *
 * <p>
 * The following features are supported:
 * <ul>
 *   <li>{@link oscfg.Poster#getPostMessage <em>Post Message</em>}</li>
 * </ul>
 * </p>
 *
 * @see oscfg.OscfgPackage#getPoster()
 * @model abstract="true"
 * @generated
 */
public interface Poster extends EObject {
	/**
	 * Returns the value of the '<em><b>Post Message</b></em>' reference list.
	 * The list contents are of type {@link oscfg.Message}.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Post Message</em>' reference list isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Post Message</em>' reference list.
	 * @see oscfg.OscfgPackage#getPoster_PostMessage()
	 * @model
	 * @generated
	 */
	EList<Message> getPostMessage();

} // Poster
