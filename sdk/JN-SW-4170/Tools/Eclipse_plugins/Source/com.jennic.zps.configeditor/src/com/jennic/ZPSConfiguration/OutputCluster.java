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
 * A representation of the model object '<em><b>Output Cluster</b></em>'.
 * <!-- end-user-doc -->
 *
 * <p>
 * The following features are supported:
 * <ul>
 *   <li>{@link com.jennic.ZPSConfiguration.OutputCluster#getCluster <em>Cluster</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.OutputCluster#getEndPoint <em>End Point</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.OutputCluster#getTxAPDUs <em>Tx APD Us</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.OutputCluster#isDiscoverable <em>Discoverable</em>}</li>
 * </ul>
 * </p>
 *
 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getOutputCluster()
 * @model
 * @generated
 */
public interface OutputCluster extends EObject {
	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	String copyright = "(C) NXP B.V";

	/**
	 * Returns the value of the '<em><b>Cluster</b></em>' reference.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Cluster</em>' reference isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Cluster</em>' reference.
	 * @see #setCluster(Cluster)
	 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getOutputCluster_Cluster()
	 * @model required="true"
	 * @generated
	 */
	Cluster getCluster();

	/**
	 * Sets the value of the '{@link com.jennic.ZPSConfiguration.OutputCluster#getCluster <em>Cluster</em>}' reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>Cluster</em>' reference.
	 * @see #getCluster()
	 * @generated
	 */
	void setCluster(Cluster value);

	/**
	 * Returns the value of the '<em><b>End Point</b></em>' container reference.
	 * It is bidirectional and its opposite is '{@link com.jennic.ZPSConfiguration.EndPoint#getOutputClusters <em>Output Clusters</em>}'.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>End Point</em>' container reference isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>End Point</em>' container reference.
	 * @see #setEndPoint(EndPoint)
	 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getOutputCluster_EndPoint()
	 * @see com.jennic.ZPSConfiguration.EndPoint#getOutputClusters
	 * @model opposite="OutputClusters" required="true" transient="false"
	 * @generated
	 */
	EndPoint getEndPoint();

	/**
	 * Sets the value of the '{@link com.jennic.ZPSConfiguration.OutputCluster#getEndPoint <em>End Point</em>}' container reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>End Point</em>' container reference.
	 * @see #getEndPoint()
	 * @generated
	 */
	void setEndPoint(EndPoint value);

	/**
	 * Returns the value of the '<em><b>Tx APD Us</b></em>' reference list.
	 * The list contents are of type {@link com.jennic.ZPSConfiguration.APDU}.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Tx APD Us</em>' reference list isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Tx APD Us</em>' reference list.
	 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getOutputCluster_TxAPDUs()
	 * @model
	 * @generated
	 */
	EList<APDU> getTxAPDUs();

	/**
	 * Returns the value of the '<em><b>Discoverable</b></em>' attribute.
	 * The default value is <code>"true"</code>.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Discoverable</em>' attribute isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Discoverable</em>' attribute.
	 * @see #setDiscoverable(boolean)
	 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getOutputCluster_Discoverable()
	 * @model default="true" required="true"
	 * @generated
	 */
	boolean isDiscoverable();

	/**
	 * Sets the value of the '{@link com.jennic.ZPSConfiguration.OutputCluster#isDiscoverable <em>Discoverable</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>Discoverable</em>' attribute.
	 * @see #isDiscoverable()
	 * @generated
	 */
	void setDiscoverable(boolean value);

} // OutputCluster
