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
 * A representation of the model object '<em><b>PDU Manager</b></em>'.
 * <!-- end-user-doc -->
 *
 * <p>
 * The following features are supported:
 * <ul>
 *   <li>{@link com.jennic.ZPSConfiguration.PDUManager#getAPDUs <em>APD Us</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.PDUManager#getContainerNode <em>Container Node</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.PDUManager#getNumNPDUs <em>Num NPD Us</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.PDUManager#getPDUMMutexName <em>PDUM Mutex Name</em>}</li>
 * </ul>
 * </p>
 *
 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getPDUManager()
 * @model
 * @generated
 */
public interface PDUManager extends EObject {
	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	String copyright = "(C) NXP B.V";

	/**
	 * Returns the value of the '<em><b>APD Us</b></em>' containment reference list.
	 * The list contents are of type {@link com.jennic.ZPSConfiguration.APDU}.
	 * It is bidirectional and its opposite is '{@link com.jennic.ZPSConfiguration.APDU#getPDUConfig <em>PDU Config</em>}'.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>APD Us</em>' containment reference list isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>APD Us</em>' containment reference list.
	 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getPDUManager_APDUs()
	 * @see com.jennic.ZPSConfiguration.APDU#getPDUConfig
	 * @model opposite="PDUConfig" containment="true"
	 * @generated
	 */
	EList<APDU> getAPDUs();

	/**
	 * Returns the value of the '<em><b>Container Node</b></em>' container reference.
	 * It is bidirectional and its opposite is '{@link com.jennic.ZPSConfiguration.Node#getPDUConfiguration <em>PDU Configuration</em>}'.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Container Node</em>' container reference isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Container Node</em>' container reference.
	 * @see #setContainerNode(Node)
	 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getPDUManager_ContainerNode()
	 * @see com.jennic.ZPSConfiguration.Node#getPDUConfiguration
	 * @model opposite="PDUConfiguration" transient="false"
	 * @generated
	 */
	Node getContainerNode();

	/**
	 * Sets the value of the '{@link com.jennic.ZPSConfiguration.PDUManager#getContainerNode <em>Container Node</em>}' container reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>Container Node</em>' container reference.
	 * @see #getContainerNode()
	 * @generated
	 */
	void setContainerNode(Node value);

	/**
	 * Returns the value of the '<em><b>Num NPD Us</b></em>' attribute.
	 * The default value is <code>"25"</code>.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Num NPD Us</em>' attribute isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Num NPD Us</em>' attribute.
	 * @see #setNumNPDUs(int)
	 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getPDUManager_NumNPDUs()
	 * @model default="25" required="true"
	 *        annotation="http://jennic.com/hexdec min='8' max='65535'"
	 * @generated
	 */
	int getNumNPDUs();

	/**
	 * Sets the value of the '{@link com.jennic.ZPSConfiguration.PDUManager#getNumNPDUs <em>Num NPD Us</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>Num NPD Us</em>' attribute.
	 * @see #getNumNPDUs()
	 * @generated
	 */
	void setNumNPDUs(int value);

	/**
	 * Returns the value of the '<em><b>PDUM Mutex Name</b></em>' attribute.
	 * The default value is <code>"mutexPDUM"</code>.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>PDUM Mutex Name</em>' attribute isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>PDUM Mutex Name</em>' attribute.
	 * @see #setPDUMMutexName(String)
	 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getPDUManager_PDUMMutexName()
	 * @model default="mutexPDUM" required="true"
	 *        extendedMetaData="namespace='##targetNamespace' kind='attribute'"
	 * @generated
	 */
	String getPDUMMutexName();

	/**
	 * Sets the value of the '{@link com.jennic.ZPSConfiguration.PDUManager#getPDUMMutexName <em>PDUM Mutex Name</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>PDUM Mutex Name</em>' attribute.
	 * @see #getPDUMMutexName()
	 * @generated
	 */
	void setPDUMMutexName(String value);

} // PDUManager
