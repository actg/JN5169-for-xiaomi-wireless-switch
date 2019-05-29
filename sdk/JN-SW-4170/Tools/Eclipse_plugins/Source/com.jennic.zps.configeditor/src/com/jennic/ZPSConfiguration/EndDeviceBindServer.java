/**
 * (C) Jennic Ltd
 *
 * $Id$
 */
package com.jennic.ZPSConfiguration;

/**
 * <!-- begin-user-doc -->
 * A representation of the model object '<em><b>End Device Bind Server</b></em>'.
 * <!-- end-user-doc -->
 *
 * <p>
 * The following features are supported:
 * <ul>
 *   <li>{@link com.jennic.ZPSConfiguration.EndDeviceBindServer#getTimeout <em>Timeout</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.EndDeviceBindServer#getBindingTimeout <em>Binding Timeout</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.EndDeviceBindServer#getBindNumRetries <em>Bind Num Retries</em>}</li>
 * </ul>
 * </p>
 *
 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getEndDeviceBindServer()
 * @model
 * @generated
 */
public interface EndDeviceBindServer extends ZDOClientServer {
	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	String copyright = "(C) NXP B.V";

	/**
	 * Returns the value of the '<em><b>Timeout</b></em>' attribute.
	 * The default value is <code>"5"</code>.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Timeout</em>' attribute isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Timeout</em>' attribute.
	 * @see #setTimeout(int)
	 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getEndDeviceBindServer_Timeout()
	 * @model default="5" required="true"
	 * @generated
	 */
	int getTimeout();

	/**
	 * Sets the value of the '{@link com.jennic.ZPSConfiguration.EndDeviceBindServer#getTimeout <em>Timeout</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>Timeout</em>' attribute.
	 * @see #getTimeout()
	 * @generated
	 */
	void setTimeout(int value);

	/**
	 * Returns the value of the '<em><b>Binding Timeout</b></em>' attribute.
	 * The default value is <code>"10"</code>.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Binding Timeout</em>' attribute isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Binding Timeout</em>' attribute.
	 * @see #setBindingTimeout(int)
	 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getEndDeviceBindServer_BindingTimeout()
	 * @model default="10"
	 * @generated
	 */
	int getBindingTimeout();

	/**
	 * Sets the value of the '{@link com.jennic.ZPSConfiguration.EndDeviceBindServer#getBindingTimeout <em>Binding Timeout</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>Binding Timeout</em>' attribute.
	 * @see #getBindingTimeout()
	 * @generated
	 */
	void setBindingTimeout(int value);

	/**
	 * Returns the value of the '<em><b>Bind Num Retries</b></em>' attribute.
	 * The default value is <code>"3"</code>.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Bind Num Retries</em>' attribute isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Bind Num Retries</em>' attribute.
	 * @see #setBindNumRetries(int)
	 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getEndDeviceBindServer_BindNumRetries()
	 * @model default="3" required="true"
	 * @generated
	 */
	int getBindNumRetries();

	/**
	 * Sets the value of the '{@link com.jennic.ZPSConfiguration.EndDeviceBindServer#getBindNumRetries <em>Bind Num Retries</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>Bind Num Retries</em>' attribute.
	 * @see #getBindNumRetries()
	 * @generated
	 */
	void setBindNumRetries(int value);

} // EndDeviceBindServer
