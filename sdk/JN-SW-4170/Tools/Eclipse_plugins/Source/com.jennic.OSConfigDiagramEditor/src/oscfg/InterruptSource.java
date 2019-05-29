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
 * A representation of the model object '<em><b>Interrupt Source</b></em>'.
 * <!-- end-user-doc -->
 *
 * <p>
 * The following features are supported:
 * <ul>
 *   <li>{@link oscfg.InterruptSource#getSource <em>Source</em>}</li>
 *   <li>{@link oscfg.InterruptSource#getSourceISR <em>Source ISR</em>}</li>
 * </ul>
 * </p>
 *
 * @see oscfg.OscfgPackage#getInterruptSource()
 * @model
 * @generated
 */
public interface InterruptSource extends EObject {
	/**
	 * Returns the value of the '<em><b>Source</b></em>' attribute.
	 * The default value is <code>"SystemController"</code>.
	 * The literals are from the enumeration {@link oscfg.VectorType}.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Source</em>' attribute isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Source</em>' attribute.
	 * @see oscfg.VectorType
	 * @see #isSetSource()
	 * @see #unsetSource()
	 * @see #setSource(VectorType)
	 * @see oscfg.OscfgPackage#getInterruptSource_Source()
	 * @model default="SystemController" unsettable="true" id="true" required="true"
	 *        extendedMetaData="kind='attribute' name='vector' namespace='##targetNamespace'"
	 * @generated
	 */
	VectorType getSource();

	/**
	 * Sets the value of the '{@link oscfg.InterruptSource#getSource <em>Source</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>Source</em>' attribute.
	 * @see oscfg.VectorType
	 * @see #isSetSource()
	 * @see #unsetSource()
	 * @see #getSource()
	 * @generated
	 */
	void setSource(VectorType value);

	/**
	 * Unsets the value of the '{@link oscfg.InterruptSource#getSource <em>Source</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #isSetSource()
	 * @see #getSource()
	 * @see #setSource(VectorType)
	 * @generated
	 */
	void unsetSource();

	/**
	 * Returns whether the value of the '{@link oscfg.InterruptSource#getSource <em>Source</em>}' attribute is set.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return whether the value of the '<em>Source</em>' attribute is set.
	 * @see #unsetSource()
	 * @see #getSource()
	 * @see #setSource(VectorType)
	 * @generated
	 */
	boolean isSetSource();

	/**
	 * Returns the value of the '<em><b>Source ISR</b></em>' reference.
	 * It is bidirectional and its opposite is '{@link oscfg.ISR#getISRSource <em>ISR Source</em>}'.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Source ISR</em>' reference isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Source ISR</em>' reference.
	 * @see #setSourceISR(ISR)
	 * @see oscfg.OscfgPackage#getInterruptSource_SourceISR()
	 * @see oscfg.ISR#getISRSource
	 * @model opposite="ISRSource" required="true"
	 *        extendedMetaData="namespace='##targetNamespace'"
	 * @generated
	 */
	ISR getSourceISR();

	/**
	 * Sets the value of the '{@link oscfg.InterruptSource#getSourceISR <em>Source ISR</em>}' reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>Source ISR</em>' reference.
	 * @see #getSourceISR()
	 * @generated
	 */
	void setSourceISR(ISR value);

} // InterruptSource
