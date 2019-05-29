/**
 * (C) Jennic Ltd
 *
 * $Id$
 */
package com.jennic.ZPSConfiguration;

import org.eclipse.emf.ecore.EObject;

/**
 * <!-- begin-user-doc -->
 * A representation of the model object '<em><b>APDU</b></em>'.
 * <!-- end-user-doc -->
 *
 * <p>
 * The following features are supported:
 * <ul>
 *   <li>{@link com.jennic.ZPSConfiguration.APDU#getId <em>Id</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.APDU#getName <em>Name</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.APDU#getSize <em>Size</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.APDU#getInstances <em>Instances</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.APDU#getPDUConfig <em>PDU Config</em>}</li>
 * </ul>
 * </p>
 *
 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getAPDU()
 * @model
 * @generated
 */
public interface APDU extends EObject {
	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	String copyright = "(C) NXP B.V";

	/**
	 * Returns the value of the '<em><b>Id</b></em>' attribute.
	 * The default value is <code>""</code>.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Id</em>' attribute isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Id</em>' attribute.
	 * @see #isSetId()
	 * @see #unsetId()
	 * @see #setId(String)
	 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getAPDU_Id()
	 * @model default="" unsettable="true" id="true" required="true" volatile="true" derived="true"
	 *        annotation="OCL derive=''"
	 * @generated
	 */
	String getId();

	/**
	 * Sets the value of the '{@link com.jennic.ZPSConfiguration.APDU#getId <em>Id</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>Id</em>' attribute.
	 * @see #isSetId()
	 * @see #unsetId()
	 * @see #getId()
	 * @generated
	 */
	void setId(String value);

	/**
	 * Unsets the value of the '{@link com.jennic.ZPSConfiguration.APDU#getId <em>Id</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #isSetId()
	 * @see #getId()
	 * @see #setId(String)
	 * @generated
	 */
	void unsetId();

	/**
	 * Returns whether the value of the '{@link com.jennic.ZPSConfiguration.APDU#getId <em>Id</em>}' attribute is set.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return whether the value of the '<em>Id</em>' attribute is set.
	 * @see #unsetId()
	 * @see #getId()
	 * @see #setId(String)
	 * @generated
	 */
	boolean isSetId();

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
	 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getAPDU_Name()
	 * @model required="true"
	 * @generated
	 */
	String getName();

	/**
	 * Sets the value of the '{@link com.jennic.ZPSConfiguration.APDU#getName <em>Name</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>Name</em>' attribute.
	 * @see #getName()
	 * @generated
	 */
	void setName(String value);

	/**
	 * Returns the value of the '<em><b>Size</b></em>' attribute.
	 * The default value is <code>"1"</code>.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Size</em>' attribute isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Size</em>' attribute.
	 * @see #setSize(int)
	 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getAPDU_Size()
	 * @model default="1" required="true"
	 *        annotation="http://jennic.com/hexdec min='1' max='25500'"
	 * @generated
	 */
	int getSize();

	/**
	 * Sets the value of the '{@link com.jennic.ZPSConfiguration.APDU#getSize <em>Size</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>Size</em>' attribute.
	 * @see #getSize()
	 * @generated
	 */
	void setSize(int value);

	/**
	 * Returns the value of the '<em><b>Instances</b></em>' attribute.
	 * The default value is <code>"1"</code>.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Instances</em>' attribute isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Instances</em>' attribute.
	 * @see #setInstances(int)
	 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getAPDU_Instances()
	 * @model default="1" required="true"
	 *        annotation="http://jennic.com/hexdec min='1' max='65535'"
	 * @generated
	 */
	int getInstances();

	/**
	 * Sets the value of the '{@link com.jennic.ZPSConfiguration.APDU#getInstances <em>Instances</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>Instances</em>' attribute.
	 * @see #getInstances()
	 * @generated
	 */
	void setInstances(int value);

	/**
	 * Returns the value of the '<em><b>PDU Config</b></em>' container reference.
	 * It is bidirectional and its opposite is '{@link com.jennic.ZPSConfiguration.PDUManager#getAPDUs <em>APD Us</em>}'.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>PDU Config</em>' container reference isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>PDU Config</em>' container reference.
	 * @see #setPDUConfig(PDUManager)
	 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getAPDU_PDUConfig()
	 * @see com.jennic.ZPSConfiguration.PDUManager#getAPDUs
	 * @model opposite="APDUs" required="true" transient="false"
	 * @generated
	 */
	PDUManager getPDUConfig();

	/**
	 * Sets the value of the '{@link com.jennic.ZPSConfiguration.APDU#getPDUConfig <em>PDU Config</em>}' container reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>PDU Config</em>' container reference.
	 * @see #getPDUConfig()
	 * @generated
	 */
	void setPDUConfig(PDUManager value);

} // APDU
