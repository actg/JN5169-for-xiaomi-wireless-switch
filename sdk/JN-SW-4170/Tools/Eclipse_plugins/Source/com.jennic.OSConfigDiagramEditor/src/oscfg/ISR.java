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
 * A representation of the model object '<em><b>ISR</b></em>'.
 * <!-- end-user-doc -->
 *
 * <p>
 * The following features are supported:
 * <ul>
 *   <li>{@link oscfg.ISR#getIPL <em>IPL</em>}</li>
 *   <li>{@link oscfg.ISR#getType <em>Type</em>}</li>
 *   <li>{@link oscfg.ISR#getISRSource <em>ISR Source</em>}</li>
 * </ul>
 * </p>
 *
 * @see oscfg.OscfgPackage#getISR()
 * @model
 * @generated
 */
public interface ISR extends BaseTask {
	/**
	 * Returns the value of the '<em><b>IPL</b></em>' attribute.
	 * The default value is <code>"1"</code>.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>IPL</em>' attribute isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>IPL</em>' attribute.
	 * @see #setIPL(int)
	 * @see oscfg.OscfgPackage#getISR_IPL()
	 * @model default="1" unique="false" dataType="oscfg.IPLType" required="true"
	 *        extendedMetaData="kind='attribute' name='IPL' namespace='##targetNamespace'"
	 * @generated
	 */
	int getIPL();

	/**
	 * Sets the value of the '{@link oscfg.ISR#getIPL <em>IPL</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>IPL</em>' attribute.
	 * @see #getIPL()
	 * @generated
	 */
	void setIPL(int value);

	/**
	 * Returns the value of the '<em><b>Type</b></em>' attribute.
	 * The default value is <code>"controlled"</code>.
	 * The literals are from the enumeration {@link oscfg.TypeType}.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Type</em>' attribute isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Type</em>' attribute.
	 * @see oscfg.TypeType
	 * @see #isSetType()
	 * @see #unsetType()
	 * @see #setType(TypeType)
	 * @see oscfg.OscfgPackage#getISR_Type()
	 * @model default="controlled" unique="false" unsettable="true" required="true"
	 *        extendedMetaData="kind='attribute' name='type' namespace='##targetNamespace'"
	 * @generated
	 */
	TypeType getType();

	/**
	 * Sets the value of the '{@link oscfg.ISR#getType <em>Type</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>Type</em>' attribute.
	 * @see oscfg.TypeType
	 * @see #isSetType()
	 * @see #unsetType()
	 * @see #getType()
	 * @generated
	 */
	void setType(TypeType value);

	/**
	 * Unsets the value of the '{@link oscfg.ISR#getType <em>Type</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #isSetType()
	 * @see #getType()
	 * @see #setType(TypeType)
	 * @generated
	 */
	void unsetType();

	/**
	 * Returns whether the value of the '{@link oscfg.ISR#getType <em>Type</em>}' attribute is set.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return whether the value of the '<em>Type</em>' attribute is set.
	 * @see #unsetType()
	 * @see #getType()
	 * @see #setType(TypeType)
	 * @generated
	 */
	boolean isSetType();

	/**
	 * Returns the value of the '<em><b>ISR Source</b></em>' reference list.
	 * The list contents are of type {@link oscfg.InterruptSource}.
	 * It is bidirectional and its opposite is '{@link oscfg.InterruptSource#getSourceISR <em>Source ISR</em>}'.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>ISR Source</em>' reference list isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>ISR Source</em>' reference list.
	 * @see oscfg.OscfgPackage#getISR_ISRSource()
	 * @see oscfg.InterruptSource#getSourceISR
	 * @model opposite="SourceISR" required="true"
	 * @generated
	 */
	EList<InterruptSource> getISRSource();

} // ISR
