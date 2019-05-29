/**
 * (C) Jennic Ltd
 *
 * $Id$
 */
package com.jennic.ZPSConfiguration;


/**
 * <!-- begin-user-doc -->
 * A representation of the model object '<em><b>End Device</b></em>'.
 * <!-- end-user-doc -->
 *
 * <p>
 * The following features are supported:
 * <ul>
 *   <li>{@link com.jennic.ZPSConfiguration.EndDevice#getZDOServers <em>ZDO Servers</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.EndDevice#getNumPollFailuresBeforeRejoin <em>Num Poll Failures Before Rejoin</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.EndDevice#isSleeping <em>Sleeping</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.EndDevice#getFragmentedTxPollPeriod <em>Fragmented Tx Poll Period</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.EndDevice#getFragmentedRxPollPeriod <em>Fragmented Rx Poll Period</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.EndDevice#getAPSPollPeriod <em>APS Poll Period</em>}</li>
 * </ul>
 * </p>
 *
 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getEndDevice()
 * @model
 * @generated
 */
public interface EndDevice extends Node, ChildNodes {
	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	String copyright = "(C) NXP B.V";

	/**
	 * Returns the value of the '<em><b>ZDO Servers</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>ZDO Servers</em>' containment reference isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>ZDO Servers</em>' containment reference.
	 * @see #setZDOServers(ZDOServersEndDevice)
	 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getEndDevice_ZDOServers()
	 * @model containment="true" required="true"
	 * @generated
	 */
	ZDOServersEndDevice getZDOServers();

	/**
	 * Sets the value of the '{@link com.jennic.ZPSConfiguration.EndDevice#getZDOServers <em>ZDO Servers</em>}' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>ZDO Servers</em>' containment reference.
	 * @see #getZDOServers()
	 * @generated
	 */
	void setZDOServers(ZDOServersEndDevice value);

	/**
	 * Returns the value of the '<em><b>Num Poll Failures Before Rejoin</b></em>' attribute.
	 * The default value is <code>"3"</code>.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Num Poll Failures Before Rejoin</em>' attribute isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Num Poll Failures Before Rejoin</em>' attribute.
	 * @see #setNumPollFailuresBeforeRejoin(int)
	 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getEndDevice_NumPollFailuresBeforeRejoin()
	 * @model default="3"
	 *        annotation="http://jennic.com/hexdec min='0' max='255'"
	 * @generated
	 */
	int getNumPollFailuresBeforeRejoin();

	/**
	 * Sets the value of the '{@link com.jennic.ZPSConfiguration.EndDevice#getNumPollFailuresBeforeRejoin <em>Num Poll Failures Before Rejoin</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>Num Poll Failures Before Rejoin</em>' attribute.
	 * @see #getNumPollFailuresBeforeRejoin()
	 * @generated
	 */
	void setNumPollFailuresBeforeRejoin(int value);

	/**
	 * Returns the value of the '<em><b>Sleeping</b></em>' attribute.
	 * The default value is <code>"false"</code>.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Sleeping</em>' attribute isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Sleeping</em>' attribute.
	 * @see #setSleeping(boolean)
	 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getEndDevice_Sleeping()
	 * @model default="false" required="true"
	 * @generated
	 */
	boolean isSleeping();

	/**
	 * Sets the value of the '{@link com.jennic.ZPSConfiguration.EndDevice#isSleeping <em>Sleeping</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>Sleeping</em>' attribute.
	 * @see #isSleeping()
	 * @generated
	 */
	void setSleeping(boolean value);

	/**
	 * Returns the value of the '<em><b>Fragmented Tx Poll Period</b></em>' attribute.
	 * The default value is <code>"25"</code>.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Fragmented Tx Poll Period</em>' attribute isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Fragmented Tx Poll Period</em>' attribute.
	 * @see #setFragmentedTxPollPeriod(int)
	 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getEndDevice_FragmentedTxPollPeriod()
	 * @model default="25"
	 *        annotation="http://jennic.com/hexdec min='25' max='255'"
	 * @generated
	 */
	int getFragmentedTxPollPeriod();

	/**
	 * Sets the value of the '{@link com.jennic.ZPSConfiguration.EndDevice#getFragmentedTxPollPeriod <em>Fragmented Tx Poll Period</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>Fragmented Tx Poll Period</em>' attribute.
	 * @see #getFragmentedTxPollPeriod()
	 * @generated
	 */
	void setFragmentedTxPollPeriod(int value);

	/**
	 * Returns the value of the '<em><b>Fragmented Rx Poll Period</b></em>' attribute.
	 * The default value is <code>"25"</code>.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Fragmented Rx Poll Period</em>' attribute isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Fragmented Rx Poll Period</em>' attribute.
	 * @see #setFragmentedRxPollPeriod(int)
	 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getEndDevice_FragmentedRxPollPeriod()
	 * @model default="25"
	 *        annotation="http://jennic.com/hexdec min='25' max='255'"
	 * @generated
	 */
	int getFragmentedRxPollPeriod();

	/**
	 * Sets the value of the '{@link com.jennic.ZPSConfiguration.EndDevice#getFragmentedRxPollPeriod <em>Fragmented Rx Poll Period</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>Fragmented Rx Poll Period</em>' attribute.
	 * @see #getFragmentedRxPollPeriod()
	 * @generated
	 */
	void setFragmentedRxPollPeriod(int value);

	/**
	 * Returns the value of the '<em><b>APS Poll Period</b></em>' attribute.
	 * The default value is <code>"100"</code>.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>APS Poll Period</em>' attribute isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>APS Poll Period</em>' attribute.
	 * @see #setAPSPollPeriod(int)
	 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getEndDevice_APSPollPeriod()
	 * @model default="100"
	 *        annotation="http://jennic.com/hexdec min='25' max='65535'"
	 * @generated
	 */
	int getAPSPollPeriod();

	/**
	 * Sets the value of the '{@link com.jennic.ZPSConfiguration.EndDevice#getAPSPollPeriod <em>APS Poll Period</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>APS Poll Period</em>' attribute.
	 * @see #getAPSPollPeriod()
	 * @generated
	 */
	void setAPSPollPeriod(int value);

} // EndDevice
