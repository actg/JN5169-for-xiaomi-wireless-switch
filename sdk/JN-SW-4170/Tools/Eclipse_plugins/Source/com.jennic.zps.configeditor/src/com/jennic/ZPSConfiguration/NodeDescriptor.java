/**
 * (C) Jennic Ltd
 *
 * $Id: NodeDescriptor.java 78109 2016-03-24 15:51:22Z nxp29741 $
 */
package com.jennic.ZPSConfiguration;

import java.math.BigInteger;

import org.eclipse.emf.ecore.EObject;

/**
 * <!-- begin-user-doc -->
 * A representation of the model object '<em><b>Node Descriptor</b></em>'.
 * <!-- end-user-doc -->
 *
 * <p>
 * The following features are supported:
 * <ul>
 *   <li>{@link com.jennic.ZPSConfiguration.NodeDescriptor#getManufacturerCode <em>Manufacturer Code</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.NodeDescriptor#getLogicalType <em>Logical Type</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.NodeDescriptor#isComplexDescriptorAvailable <em>Complex Descriptor Available</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.NodeDescriptor#isUserDescriptorAvailable <em>User Descriptor Available</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.NodeDescriptor#getAPSFlags <em>APS Flags</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.NodeDescriptor#getFrequencyBand <em>Frequency Band</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.NodeDescriptor#isAlternatePANCoordinator <em>Alternate PAN Coordinator</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.NodeDescriptor#isDeviceType <em>Device Type</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.NodeDescriptor#isPowerSource <em>Power Source</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.NodeDescriptor#isRxOnWhenIdle <em>Rx On When Idle</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.NodeDescriptor#isSecurity <em>Security</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.NodeDescriptor#isAllocateAddress <em>Allocate Address</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.NodeDescriptor#getMaximumBufferSize <em>Maximum Buffer Size</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.NodeDescriptor#getMaximumIncomingTransferSize <em>Maximum Incoming Transfer Size</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.NodeDescriptor#getMaximumOutgoingTransferSize <em>Maximum Outgoing Transfer Size</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.NodeDescriptor#isExtendedActiveEndpointListAvailable <em>Extended Active Endpoint List Available</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.NodeDescriptor#isExtendedSimpleDescriptorListAvailable <em>Extended Simple Descriptor List Available</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.NodeDescriptor#isPrimaryTrustCenter <em>Primary Trust Center</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.NodeDescriptor#isBackupTrustCenter <em>Backup Trust Center</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.NodeDescriptor#isPrimaryBindingTableCache <em>Primary Binding Table Cache</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.NodeDescriptor#isBackupBindingTableCache <em>Backup Binding Table Cache</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.NodeDescriptor#isPrimaryDiscoveryCache <em>Primary Discovery Cache</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.NodeDescriptor#isBackupDiscoveryCache <em>Backup Discovery Cache</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.NodeDescriptor#getNode <em>Node</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.NodeDescriptor#isNetworkManager <em>Network Manager</em>}</li>
 * </ul>
 * </p>
 *
 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getNodeDescriptor()
 * @model
 * @generated
 */
public interface NodeDescriptor extends EObject {
	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	String copyright = "(C) NXP B.V";

	/**
	 * Returns the value of the '<em><b>Manufacturer Code</b></em>' attribute.
	 * The default value is <code>"0"</code>.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Manufacturer Code</em>' attribute isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Manufacturer Code</em>' attribute.
	 * @see #setManufacturerCode(int)
	 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getNodeDescriptor_ManufacturerCode()
	 * @model default="0" required="true"
	 *        annotation="http://jennic.com/hexdec min='0' max='65535'"
	 * @generated
	 */
	int getManufacturerCode();

	/**
	 * Sets the value of the '{@link com.jennic.ZPSConfiguration.NodeDescriptor#getManufacturerCode <em>Manufacturer Code</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>Manufacturer Code</em>' attribute.
	 * @see #getManufacturerCode()
	 * @generated
	 */
	void setManufacturerCode(int value);

	/**
	 * Returns the value of the '<em><b>Logical Type</b></em>' attribute.
	 * The default value is <code>"ZED"</code>.
	 * The literals are from the enumeration {@link com.jennic.ZPSConfiguration.NodeLogicalType}.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Logical Type</em>' attribute isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Logical Type</em>' attribute.
	 * @see com.jennic.ZPSConfiguration.NodeLogicalType
	 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getNodeDescriptor_LogicalType()
	 * @model default="ZED" required="true" changeable="false" volatile="true" derived="true"
	 * @generated
	 */
	NodeLogicalType getLogicalType();

	/**
	 * Returns the value of the '<em><b>Complex Descriptor Available</b></em>' attribute.
	 * The default value is <code>"false"</code>.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Complex Descriptor Available</em>' attribute isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Complex Descriptor Available</em>' attribute.
	 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getNodeDescriptor_ComplexDescriptorAvailable()
	 * @model default="false" required="true" changeable="false" volatile="true" derived="true"
	 * @generated
	 */
	boolean isComplexDescriptorAvailable();

	/**
	 * Returns the value of the '<em><b>User Descriptor Available</b></em>' attribute.
	 * The default value is <code>"false"</code>.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>User Descriptor Available</em>' attribute isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>User Descriptor Available</em>' attribute.
	 * @see #setUserDescriptorAvailable(boolean)
	 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getNodeDescriptor_UserDescriptorAvailable()
	 * @model default="false" required="true" volatile="true" derived="true"
	 * @generated
	 */
	boolean isUserDescriptorAvailable();

	/**
	 * Sets the value of the '{@link com.jennic.ZPSConfiguration.NodeDescriptor#isUserDescriptorAvailable <em>User Descriptor Available</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>User Descriptor Available</em>' attribute.
	 * @see #isUserDescriptorAvailable()
	 * @generated
	 */
	void setUserDescriptorAvailable(boolean value);

	/**
	 * Returns the value of the '<em><b>APS Flags</b></em>' attribute.
	 * The default value is <code>"0"</code>.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>APS Flags</em>' attribute isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>APS Flags</em>' attribute.
	 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getNodeDescriptor_APSFlags()
	 * @model default="0" required="true" changeable="false" volatile="true"
	 * @generated
	 */
	BigInteger getAPSFlags();

	/**
	 * Returns the value of the '<em><b>Frequency Band</b></em>' attribute.
	 * The default value is <code>"2.4GHz"</code>.
	 * The literals are from the enumeration {@link com.jennic.ZPSConfiguration.FrequencyBands}.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Frequency Band</em>' attribute isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Frequency Band</em>' attribute.
	 * @see com.jennic.ZPSConfiguration.FrequencyBands
	 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getNodeDescriptor_FrequencyBand()
	 * @model default="2.4GHz" changeable="false" volatile="true" derived="true"
	 * @generated
	 */
	FrequencyBands getFrequencyBand();

	/**
	 * Returns the value of the '<em><b>Alternate PAN Coordinator</b></em>' attribute.
	 * The default value is <code>"false"</code>.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Alternate PAN Coordinator</em>' attribute isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Alternate PAN Coordinator</em>' attribute.
	 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getNodeDescriptor_AlternatePANCoordinator()
	 * @model default="false" required="true" changeable="false" volatile="true" derived="true"
	 * @generated
	 */
	boolean isAlternatePANCoordinator();

	/**
	 * Returns the value of the '<em><b>Device Type</b></em>' attribute.
	 * The default value is <code>"false"</code>.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Device Type</em>' attribute isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Device Type</em>' attribute.
	 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getNodeDescriptor_DeviceType()
	 * @model default="false" required="true" changeable="false" volatile="true" derived="true"
	 * @generated
	 */
	boolean isDeviceType();

	/**
	 * Returns the value of the '<em><b>Power Source</b></em>' attribute.
	 * The default value is <code>"false"</code>.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Power Source</em>' attribute isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Power Source</em>' attribute.
	 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getNodeDescriptor_PowerSource()
	 * @model default="false" required="true" changeable="false" volatile="true" derived="true"
	 * @generated
	 */
	boolean isPowerSource();

	/**
	 * Returns the value of the '<em><b>Rx On When Idle</b></em>' attribute.
	 * The default value is <code>"true"</code>.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Rx On When Idle</em>' attribute isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Rx On When Idle</em>' attribute.
	 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getNodeDescriptor_RxOnWhenIdle()
	 * @model default="true" required="true" changeable="false" volatile="true" derived="true"
	 * @generated
	 */
	boolean isRxOnWhenIdle();

	/**
	 * Returns the value of the '<em><b>Security</b></em>' attribute.
	 * The default value is <code>"false"</code>.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Security</em>' attribute isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Security</em>' attribute.
	 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getNodeDescriptor_Security()
	 * @model default="false" required="true" changeable="false" volatile="true" derived="true"
	 * @generated
	 */
	boolean isSecurity();

	/**
	 * Returns the value of the '<em><b>Allocate Address</b></em>' attribute.
	 * The default value is <code>"true"</code>.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Allocate Address</em>' attribute isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Allocate Address</em>' attribute.
	 * @see #setAllocateAddress(boolean)
	 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getNodeDescriptor_AllocateAddress()
	 * @model default="true" required="true"
	 * @generated
	 */
	boolean isAllocateAddress();

	/**
	 * Sets the value of the '{@link com.jennic.ZPSConfiguration.NodeDescriptor#isAllocateAddress <em>Allocate Address</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>Allocate Address</em>' attribute.
	 * @see #isAllocateAddress()
	 * @generated
	 */
	void setAllocateAddress(boolean value);

	/**
	 * Returns the value of the '<em><b>Maximum Buffer Size</b></em>' attribute.
	 * The default value is <code>"127"</code>.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Maximum Buffer Size</em>' attribute isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Maximum Buffer Size</em>' attribute.
	 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getNodeDescriptor_MaximumBufferSize()
	 * @model default="127" required="true" changeable="false"
	 * @generated
	 */
	BigInteger getMaximumBufferSize();

	/**
	 * Returns the value of the '<em><b>Maximum Incoming Transfer Size</b></em>' attribute.
	 * The default value is <code>"0"</code>.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Maximum Incoming Transfer Size</em>' attribute isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Maximum Incoming Transfer Size</em>' attribute.
	 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getNodeDescriptor_MaximumIncomingTransferSize()
	 * @model default="0" required="true" changeable="false" volatile="true" derived="true"
	 * @generated
	 */
	int getMaximumIncomingTransferSize();

	/**
	 * Returns the value of the '<em><b>Maximum Outgoing Transfer Size</b></em>' attribute.
	 * The default value is <code>"0"</code>.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Maximum Outgoing Transfer Size</em>' attribute isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Maximum Outgoing Transfer Size</em>' attribute.
	 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getNodeDescriptor_MaximumOutgoingTransferSize()
	 * @model default="0" required="true" changeable="false" volatile="true" derived="true"
	 * @generated
	 */
	int getMaximumOutgoingTransferSize();

	/**
	 * Returns the value of the '<em><b>Extended Active Endpoint List Available</b></em>' attribute.
	 * The default value is <code>"false"</code>.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Extended Active Endpoint List Available</em>' attribute isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Extended Active Endpoint List Available</em>' attribute.
	 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getNodeDescriptor_ExtendedActiveEndpointListAvailable()
	 * @model default="false" required="true" changeable="false" volatile="true" derived="true"
	 * @generated
	 */
	boolean isExtendedActiveEndpointListAvailable();

	/**
	 * Returns the value of the '<em><b>Extended Simple Descriptor List Available</b></em>' attribute.
	 * The default value is <code>"false"</code>.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Extended Simple Descriptor List Available</em>' attribute isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Extended Simple Descriptor List Available</em>' attribute.
	 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getNodeDescriptor_ExtendedSimpleDescriptorListAvailable()
	 * @model default="false" required="true" changeable="false" volatile="true" derived="true"
	 * @generated
	 */
	boolean isExtendedSimpleDescriptorListAvailable();

	/**
	 * Returns the value of the '<em><b>Primary Trust Center</b></em>' attribute.
	 * The default value is <code>"false"</code>.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Primary Trust Center</em>' attribute isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Primary Trust Center</em>' attribute.
	 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getNodeDescriptor_PrimaryTrustCenter()
	 * @model default="false" required="true" changeable="false" volatile="true" derived="true"
	 * @generated
	 */
	boolean isPrimaryTrustCenter();

	/**
	 * Returns the value of the '<em><b>Backup Trust Center</b></em>' attribute.
	 * The default value is <code>"false"</code>.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Backup Trust Center</em>' attribute isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Backup Trust Center</em>' attribute.
	 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getNodeDescriptor_BackupTrustCenter()
	 * @model default="false" required="true" changeable="false" volatile="true"
	 * @generated
	 */
	boolean isBackupTrustCenter();

	/**
	 * Returns the value of the '<em><b>Primary Binding Table Cache</b></em>' attribute.
	 * The default value is <code>"false"</code>.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Primary Binding Table Cache</em>' attribute isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Primary Binding Table Cache</em>' attribute.
	 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getNodeDescriptor_PrimaryBindingTableCache()
	 * @model default="false" required="true" changeable="false" volatile="true" derived="true"
	 * @generated
	 */
	boolean isPrimaryBindingTableCache();

	/**
	 * Returns the value of the '<em><b>Backup Binding Table Cache</b></em>' attribute.
	 * The default value is <code>"false"</code>.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Backup Binding Table Cache</em>' attribute isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Backup Binding Table Cache</em>' attribute.
	 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getNodeDescriptor_BackupBindingTableCache()
	 * @model default="false" required="true" changeable="false" volatile="true" derived="true"
	 * @generated
	 */
	boolean isBackupBindingTableCache();

	/**
	 * Returns the value of the '<em><b>Primary Discovery Cache</b></em>' attribute.
	 * The default value is <code>"false"</code>.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Primary Discovery Cache</em>' attribute isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Primary Discovery Cache</em>' attribute.
	 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getNodeDescriptor_PrimaryDiscoveryCache()
	 * @model default="false" required="true" changeable="false" volatile="true" derived="true"
	 * @generated
	 */
	boolean isPrimaryDiscoveryCache();

	/**
	 * Returns the value of the '<em><b>Backup Discovery Cache</b></em>' attribute.
	 * The default value is <code>"false"</code>.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Backup Discovery Cache</em>' attribute isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Backup Discovery Cache</em>' attribute.
	 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getNodeDescriptor_BackupDiscoveryCache()
	 * @model default="false" required="true" changeable="false" volatile="true" derived="true"
	 * @generated
	 */
	boolean isBackupDiscoveryCache();

	/**
	 * Returns the value of the '<em><b>Node</b></em>' container reference.
	 * It is bidirectional and its opposite is '{@link com.jennic.ZPSConfiguration.Node#getNodeDescriptor <em>Node Descriptor</em>}'.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Node</em>' container reference isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Node</em>' container reference.
	 * @see #setNode(Node)
	 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getNodeDescriptor_Node()
	 * @see com.jennic.ZPSConfiguration.Node#getNodeDescriptor
	 * @model opposite="NodeDescriptor" transient="false"
	 * @generated
	 */
	Node getNode();

	/**
	 * Sets the value of the '{@link com.jennic.ZPSConfiguration.NodeDescriptor#getNode <em>Node</em>}' container reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>Node</em>' container reference.
	 * @see #getNode()
	 * @generated
	 */
	void setNode(Node value);

	/**
	 * Returns the value of the '<em><b>Network Manager</b></em>' attribute.
	 * The default value is <code>"false"</code>.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Network Manager</em>' attribute isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Network Manager</em>' attribute.
	 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getNodeDescriptor_NetworkManager()
	 * @model default="false" required="true" changeable="false" volatile="true" derived="true"
	 * @generated
	 */
	boolean isNetworkManager();

} // NodeDescriptor
