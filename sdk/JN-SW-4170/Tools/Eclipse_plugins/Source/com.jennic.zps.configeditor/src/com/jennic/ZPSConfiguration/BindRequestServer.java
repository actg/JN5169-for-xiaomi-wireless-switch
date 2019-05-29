/**
 * (C) Jennic Ltd
 *
 * $Id$
 */
package com.jennic.ZPSConfiguration;


/**
 * <!-- begin-user-doc -->
 * A representation of the model object '<em><b>Bind Request Server</b></em>'.
 * <!-- end-user-doc -->
 *
 * <p>
 * The following features are supported:
 * <ul>
 *   <li>{@link com.jennic.ZPSConfiguration.BindRequestServer#getSimultaneousRequests <em>Simultaneous Requests</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.BindRequestServer#getTimeInterval <em>Time Interval</em>}</li>
 * </ul>
 * </p>
 *
 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getBindRequestServer()
 * @model
 * @generated
 */
public interface BindRequestServer extends ZDOClientServer {
	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	String copyright = "(C) NXP B.V";

	/**
	 * Returns the value of the '<em><b>Simultaneous Requests</b></em>' attribute.
	 * The default value is <code>"3"</code>.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Simultaneous Requests</em>' attribute isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Simultaneous Requests</em>' attribute.
	 * @see #setSimultaneousRequests(Integer)
	 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getBindRequestServer_SimultaneousRequests()
	 * @model default="3" dataType="com.jennic.ZPSConfiguration.EUShort" required="true"
	 * @generated
	 */
	Object getSimultaneousRequests();

	/**
	 * Sets the value of the '{@link com.jennic.ZPSConfiguration.BindRequestServer#getSimultaneousRequests <em>Simultaneous Requests</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>Simultaneous Requests</em>' attribute.
	 * @see #getSimultaneousRequests()
	 * @generated
	 */
	void setSimultaneousRequests(Object value);

	/**
	 * Returns the value of the '<em><b>Time Interval</b></em>' attribute.
	 * The default value is <code>"1"</code>.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Time Interval</em>' attribute isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Time Interval</em>' attribute.
	 * @see #setTimeInterval(Integer)
	 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getBindRequestServer_TimeInterval()
	 * @model default="1" dataType="com.jennic.ZPSConfiguration.EUShort" required="true"
	 * @generated
	 */
	Object getTimeInterval();

	/**
	 * Sets the value of the '{@link com.jennic.ZPSConfiguration.BindRequestServer#getTimeInterval <em>Time Interval</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>Time Interval</em>' attribute.
	 * @see #getTimeInterval()
	 * @generated
	 */
	void setTimeInterval(Object value);

} // BindRequestServer
