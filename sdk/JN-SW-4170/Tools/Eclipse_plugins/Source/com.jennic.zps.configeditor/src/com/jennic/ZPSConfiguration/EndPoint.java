/**
 * (C) Jennic Ltd
 *
 * $Id$
 */
package com.jennic.ZPSConfiguration;

import org.eclipse.emf.common.util.EList;
import org.eclipse.emf.ecore.EObject;

/**
 * <!-- begin-user-doc -->
 * A representation of the model object '<em><b>End Point</b></em>'.
 * <!-- end-user-doc -->
 *
 * <p>
 * The following features are supported:
 * <ul>
 *   <li>{@link com.jennic.ZPSConfiguration.EndPoint#getInputClusters <em>Input Clusters</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.EndPoint#getOutputClusters <em>Output Clusters</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.EndPoint#getId <em>Id</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.EndPoint#isEnabled <em>Enabled</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.EndPoint#getApplicationDeviceId <em>Application Device Id</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.EndPoint#getApplicationDeviceVersion <em>Application Device Version</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.EndPoint#getProfile <em>Profile</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.EndPoint#getMessage <em>Message</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.EndPoint#getNode <em>Node</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.EndPoint#getName <em>Name</em>}</li>
 * </ul>
 * </p>
 *
 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getEndPoint()
 * @model
 * @generated
 */
public interface EndPoint extends EObject {
	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	String copyright = "(C) NXP B.V";

	/**
	 * Returns the value of the '<em><b>Input Clusters</b></em>' containment reference list.
	 * The list contents are of type {@link com.jennic.ZPSConfiguration.InputCluster}.
	 * It is bidirectional and its opposite is '{@link com.jennic.ZPSConfiguration.InputCluster#getEndPoint <em>End Point</em>}'.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Input Clusters</em>' containment reference list isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Input Clusters</em>' containment reference list.
	 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getEndPoint_InputClusters()
	 * @see com.jennic.ZPSConfiguration.InputCluster#getEndPoint
	 * @model opposite="EndPoint" containment="true" upper="255"
	 * @generated
	 */
	EList<InputCluster> getInputClusters();

	/**
	 * Returns the value of the '<em><b>Output Clusters</b></em>' containment reference list.
	 * The list contents are of type {@link com.jennic.ZPSConfiguration.OutputCluster}.
	 * It is bidirectional and its opposite is '{@link com.jennic.ZPSConfiguration.OutputCluster#getEndPoint <em>End Point</em>}'.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Output Clusters</em>' containment reference list isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Output Clusters</em>' containment reference list.
	 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getEndPoint_OutputClusters()
	 * @see com.jennic.ZPSConfiguration.OutputCluster#getEndPoint
	 * @model opposite="EndPoint" containment="true" upper="255"
	 * @generated
	 */
	EList<OutputCluster> getOutputClusters();

	/**
	 * Returns the value of the '<em><b>Id</b></em>' attribute.
	 * The default value is <code>"1"</code>.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Id</em>' attribute isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Id</em>' attribute.
	 * @see #setId(int)
	 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getEndPoint_Id()
	 * @model default="1" required="true"
	 *        annotation="http://jennic.com/hexdec min='1' max='255'"
	 * @generated
	 */
	int getId();

	/**
	 * Sets the value of the '{@link com.jennic.ZPSConfiguration.EndPoint#getId <em>Id</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>Id</em>' attribute.
	 * @see #getId()
	 * @generated
	 */
	void setId(int value);

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
	 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getEndPoint_Enabled()
	 * @model default="true" required="true"
	 * @generated
	 */
	boolean isEnabled();

	/**
	 * Sets the value of the '{@link com.jennic.ZPSConfiguration.EndPoint#isEnabled <em>Enabled</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>Enabled</em>' attribute.
	 * @see #isEnabled()
	 * @generated
	 */
	void setEnabled(boolean value);

	/**
	 * Returns the value of the '<em><b>Application Device Id</b></em>' attribute.
	 * The default value is <code>"0"</code>.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Application Device Id</em>' attribute isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Application Device Id</em>' attribute.
	 * @see #setApplicationDeviceId(int)
	 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getEndPoint_ApplicationDeviceId()
	 * @model default="0" required="true"
	 *        annotation="http://jennic.com/hexdec min='0' max='65535'"
	 * @generated
	 */
	int getApplicationDeviceId();

	/**
	 * Sets the value of the '{@link com.jennic.ZPSConfiguration.EndPoint#getApplicationDeviceId <em>Application Device Id</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>Application Device Id</em>' attribute.
	 * @see #getApplicationDeviceId()
	 * @generated
	 */
	void setApplicationDeviceId(int value);

	/**
	 * Returns the value of the '<em><b>Application Device Version</b></em>' attribute.
	 * The default value is <code>"0"</code>.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Application Device Version</em>' attribute isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Application Device Version</em>' attribute.
	 * @see #setApplicationDeviceVersion(int)
	 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getEndPoint_ApplicationDeviceVersion()
	 * @model default="0" required="true"
	 *        annotation="http://jennic.com/hexdec min='0' max='15'"
	 * @generated
	 */
	int getApplicationDeviceVersion();

	/**
	 * Sets the value of the '{@link com.jennic.ZPSConfiguration.EndPoint#getApplicationDeviceVersion <em>Application Device Version</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>Application Device Version</em>' attribute.
	 * @see #getApplicationDeviceVersion()
	 * @generated
	 */
	void setApplicationDeviceVersion(int value);

	/**
	 * Returns the value of the '<em><b>Profile</b></em>' reference.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Profile</em>' reference isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Profile</em>' reference.
	 * @see #setProfile(Profile)
	 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getEndPoint_Profile()
	 * @model required="true"
	 * @generated
	 */
	Profile getProfile();

	/**
	 * Sets the value of the '{@link com.jennic.ZPSConfiguration.EndPoint#getProfile <em>Profile</em>}' reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>Profile</em>' reference.
	 * @see #getProfile()
	 * @generated
	 */
	void setProfile(Profile value);

	/**
	 * Returns the value of the '<em><b>Message</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Message</em>' attribute isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Message</em>' attribute.
	 * @see #setMessage(String)
	 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getEndPoint_Message()
	 * @model
	 * @generated
	 */
	String getMessage();

	/**
	 * Sets the value of the '{@link com.jennic.ZPSConfiguration.EndPoint#getMessage <em>Message</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>Message</em>' attribute.
	 * @see #getMessage()
	 * @generated
	 */
	void setMessage(String value);

	/**
	 * Returns the value of the '<em><b>Node</b></em>' container reference.
	 * It is bidirectional and its opposite is '{@link com.jennic.ZPSConfiguration.Node#getEndpoints <em>Endpoints</em>}'.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Node</em>' container reference isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Node</em>' container reference.
	 * @see #setNode(Node)
	 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getEndPoint_Node()
	 * @see com.jennic.ZPSConfiguration.Node#getEndpoints
	 * @model opposite="Endpoints" required="true" transient="false"
	 * @generated
	 */
	Node getNode();

	/**
	 * Sets the value of the '{@link com.jennic.ZPSConfiguration.EndPoint#getNode <em>Node</em>}' container reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>Node</em>' container reference.
	 * @see #getNode()
	 * @generated
	 */
	void setNode(Node value);

	/**
	 * Returns the value of the '<em><b>Name</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Name</em>' attribute isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Name</em>' attribute.
	 * @see #setName(String)
	 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getEndPoint_Name()
	 * @model required="true"
	 * @generated
	 */
	String getName();

	/**
	 * Sets the value of the '{@link com.jennic.ZPSConfiguration.EndPoint#getName <em>Name</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>Name</em>' attribute.
	 * @see #getName()
	 * @generated
	 */
	void setName(String value);

} // EndPoint
