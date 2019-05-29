/**
 * (C) Jennic Ltd
 */
package com.jennic.ZPSConfiguration;

import org.eclipse.emf.common.util.EList;
import org.eclipse.emf.ecore.EObject;

/**
 * <!-- begin-user-doc -->
 * A representation of the model object '<em><b>Mac Interface</b></em>'.
 * <!-- end-user-doc -->
 *
 * <p>
 * The following features are supported:
 * <ul>
 *   <li>{@link com.jennic.ZPSConfiguration.MacInterface#isRouterAllowed <em>Router Allowed</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.MacInterface#getChannelListSize <em>Channel List Size</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.MacInterface#getIndex <em>Index</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.MacInterface#getRadioType <em>Radio Type</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.MacInterface#isEnabled <em>Enabled</em>}</li>
 * </ul>
 * </p>
 *
 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getMacInterface()
 * @model
 * @generated
 */
public interface MacInterface extends EObject {
	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	String copyright = "(C) NXP B.V";

	/**
	 * Returns the value of the '<em><b>Router Allowed</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Router Allowed</em>' attribute isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Router Allowed</em>' attribute.
	 * @see #setRouterAllowed(boolean)
	 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getMacInterface_RouterAllowed()
	 * @model required="true"
	 * @generated
	 */
	boolean isRouterAllowed();

	/**
	 * Sets the value of the '{@link com.jennic.ZPSConfiguration.MacInterface#isRouterAllowed <em>Router Allowed</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>Router Allowed</em>' attribute.
	 * @see #isRouterAllowed()
	 * @generated
	 */
	void setRouterAllowed(boolean value);

	/**
	 * Returns the value of the '<em><b>Channel List Size</b></em>' attribute.
	 * The default value is <code>"1"</code>.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Channel List Size</em>' attribute isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Channel List Size</em>' attribute.
	 * @see #setChannelListSize(int)
	 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getMacInterface_ChannelListSize()
	 * @model default="1" required="true"
	 * @generated
	 */
	int getChannelListSize();

	/**
	 * Sets the value of the '{@link com.jennic.ZPSConfiguration.MacInterface#getChannelListSize <em>Channel List Size</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>Channel List Size</em>' attribute.
	 * @see #getChannelListSize()
	 * @generated
	 */
	void setChannelListSize(int value);

	/**
	 * Returns the value of the '<em><b>Index</b></em>' attribute.
	 * The default value is <code>"0"</code>.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Index</em>' attribute list isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Index</em>' attribute.
	 * @see #setIndex(short)
	 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getMacInterface_Index()
	 * @model default="0" required="true"
	 * @generated
	 */
	short getIndex();

	/**
	 * Sets the value of the '{@link com.jennic.ZPSConfiguration.MacInterface#getIndex <em>Index</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>Index</em>' attribute.
	 * @see #getIndex()
	 * @generated
	 */
	void setIndex(short value);

	/**
	 * Returns the value of the '<em><b>Radio Type</b></em>' attribute.
	 * The default value is <code>"RT2400MHz"</code>.
	 * The literals are from the enumeration {@link com.jennic.ZPSConfiguration.RadioType}.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Radio Type</em>' attribute isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Radio Type</em>' attribute.
	 * @see com.jennic.ZPSConfiguration.RadioType
	 * @see #setRadioType(RadioType)
	 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getMacInterface_RadioType()
	 * @model default="RT2400MHz" required="true"
	 * @generated
	 */
	RadioType getRadioType();

	/**
	 * Sets the value of the '{@link com.jennic.ZPSConfiguration.MacInterface#getRadioType <em>Radio Type</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>Radio Type</em>' attribute.
	 * @see com.jennic.ZPSConfiguration.RadioType
	 * @see #getRadioType()
	 * @generated
	 */
	void setRadioType(RadioType value);

	/**
	 * Returns the value of the '<em><b>Enabled</b></em>' attribute.
	 * The default value is <code>"true"</code>.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Enabled</em>' attribute isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Enabled</em>' attribute.
	 * @see #setEnabled(boolean)
	 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getMacInterface_Enabled()
	 * @model default="true" required="true"
	 * @generated
	 */
	boolean isEnabled();

	/**
	 * Sets the value of the '{@link com.jennic.ZPSConfiguration.MacInterface#isEnabled <em>Enabled</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>Enabled</em>' attribute.
	 * @see #isEnabled()
	 * @generated
	 */
	void setEnabled(boolean value);

} // MacInterface
