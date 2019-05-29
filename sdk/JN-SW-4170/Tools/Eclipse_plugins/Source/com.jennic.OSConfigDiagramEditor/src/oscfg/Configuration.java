/**
 * <copyright>
 * </copyright>
 *
 * $Id$
 */
package oscfg;

import org.eclipse.emf.ecore.EObject;

/**
 * <!-- begin-user-doc -->
 * A representation of the model object '<em><b>Configuration</b></em>'.
 * <!-- end-user-doc -->
 *
 * <p>
 * The following features are supported:
 * <ul>
 *   <li>{@link oscfg.Configuration#getOS <em>OS</em>}</li>
 *   <li>{@link oscfg.Configuration#getVersion <em>Version</em>}</li>
 * </ul>
 * </p>
 *
 * @see oscfg.OscfgPackage#getConfiguration()
 * @model
 * @generated
 */
public interface Configuration extends EObject {
	/**
	 * Returns the value of the '<em><b>OS</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>OS</em>' containment reference isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>OS</em>' containment reference.
	 * @see #setOS(OS)
	 * @see oscfg.OscfgPackage#getConfiguration_OS()
	 * @model containment="true" required="true"
	 *        extendedMetaData="kind='element' name='OS' namespace='##targetNamespace'"
	 * @generated
	 */
	OS getOS();

	/**
	 * Sets the value of the '{@link oscfg.Configuration#getOS <em>OS</em>}' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>OS</em>' containment reference.
	 * @see #getOS()
	 * @generated
	 */
	void setOS(OS value);

	/**
	 * Returns the value of the '<em><b>Version</b></em>' attribute.
	 * The default value is <code>"1.0"</code>.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Version</em>' attribute isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Version</em>' attribute.
	 * @see #setVersion(String)
	 * @see oscfg.OscfgPackage#getConfiguration_Version()
	 * @model default="1.0" dataType="org.eclipse.emf.ecore.xml.type.String" required="true"
	 * @generated
	 */
	String getVersion();

	/**
	 * Sets the value of the '{@link oscfg.Configuration#getVersion <em>Version</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>Version</em>' attribute.
	 * @see #getVersion()
	 * @generated
	 */
	void setVersion(String value);

} // Configuration
