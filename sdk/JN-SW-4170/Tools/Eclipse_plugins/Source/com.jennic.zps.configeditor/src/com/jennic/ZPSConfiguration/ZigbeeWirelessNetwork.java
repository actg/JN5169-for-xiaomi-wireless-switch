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
 * A representation of the model object '<em><b>Zigbee Wireless Network</b></em>'.
 * <!-- end-user-doc -->
 *
 * <p>
 * The following features are supported:
 * <ul>
 *   <li>{@link com.jennic.ZPSConfiguration.ZigbeeWirelessNetwork#getProfiles <em>Profiles</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.ZigbeeWirelessNetwork#getCoordinator <em>Coordinator</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.ZigbeeWirelessNetwork#getChildNodes <em>Child Nodes</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.ZigbeeWirelessNetwork#getDefaultExtendedPANId <em>Default Extended PAN Id</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.ZigbeeWirelessNetwork#getMaxNumberNodes <em>Max Number Nodes</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.ZigbeeWirelessNetwork#getVersion <em>Version</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.ZigbeeWirelessNetwork#isDefaultSecurityEnabled <em>Default Security Enabled</em>}</li>
 * </ul>
 * </p>
 *
 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getZigbeeWirelessNetwork()
 * @model
 * @generated
 */
public interface ZigbeeWirelessNetwork extends EObject {
	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	String copyright = "(C) NXP B.V";

	/**
	 * Returns the value of the '<em><b>Profiles</b></em>' containment reference list.
	 * The list contents are of type {@link com.jennic.ZPSConfiguration.Profile}.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Profiles</em>' containment reference list isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Profiles</em>' containment reference list.
	 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getZigbeeWirelessNetwork_Profiles()
	 * @model containment="true" required="true"
	 * @generated
	 */
	EList<Profile> getProfiles();

	/**
	 * Returns the value of the '<em><b>Coordinator</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Coordinator</em>' containment reference isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Coordinator</em>' containment reference.
	 * @see #setCoordinator(Coordinator)
	 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getZigbeeWirelessNetwork_Coordinator()
	 * @model containment="true"
	 * @generated
	 */
	Coordinator getCoordinator();

	/**
	 * Sets the value of the '{@link com.jennic.ZPSConfiguration.ZigbeeWirelessNetwork#getCoordinator <em>Coordinator</em>}' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>Coordinator</em>' containment reference.
	 * @see #getCoordinator()
	 * @generated
	 */
	void setCoordinator(Coordinator value);

	/**
	 * Returns the value of the '<em><b>Child Nodes</b></em>' containment reference list.
	 * The list contents are of type {@link com.jennic.ZPSConfiguration.ChildNodes}.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Child Nodes</em>' containment reference list isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Child Nodes</em>' containment reference list.
	 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getZigbeeWirelessNetwork_ChildNodes()
	 * @model containment="true"
	 * @generated
	 */
	EList<ChildNodes> getChildNodes();

	/**
	 * Returns the value of the '<em><b>Default Extended PAN Id</b></em>' attribute.
	 * The default value is <code>"0"</code>.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Default Extended PAN Id</em>' attribute isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Default Extended PAN Id</em>' attribute.
	 * @see #setDefaultExtendedPANId(BigInteger)
	 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getZigbeeWirelessNetwork_DefaultExtendedPANId()
	 * @model default="0" dataType="com.jennic.ZPSConfiguration.EExtPANId"
	 *        annotation="http://jennic.com/hexdec hex='' hex_width='16' min='0' max='0xFFFFFFFFFFFFFFFF'"
	 *        extendedMetaData="namespace='##targetNamespace' kind='attribute'"
	 * @generated
	 */
	Object getDefaultExtendedPANId();

	/**
	 * Sets the value of the '{@link com.jennic.ZPSConfiguration.ZigbeeWirelessNetwork#getDefaultExtendedPANId <em>Default Extended PAN Id</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>Default Extended PAN Id</em>' attribute.
	 * @see #getDefaultExtendedPANId()
	 * @generated
	 */
	void setDefaultExtendedPANId(Object value);

	/**
	 * Returns the value of the '<em><b>Max Number Nodes</b></em>' attribute.
	 * The default value is <code>"20"</code>.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Max Number Nodes</em>' attribute isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Max Number Nodes</em>' attribute.
	 * @see #setMaxNumberNodes(int)
	 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getZigbeeWirelessNetwork_MaxNumberNodes()
	 * @model default="20"
	 *        annotation="http://jennic.com/hexdec min='1' max='500'"
	 * @generated
	 */
	int getMaxNumberNodes();

	/**
	 * Sets the value of the '{@link com.jennic.ZPSConfiguration.ZigbeeWirelessNetwork#getMaxNumberNodes <em>Max Number Nodes</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>Max Number Nodes</em>' attribute.
	 * @see #getMaxNumberNodes()
	 * @generated
	 */
	void setMaxNumberNodes(int value);

	/**
	 * Returns the value of the '<em><b>Version</b></em>' attribute.
	 * The default value is <code>"1.2"</code>.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Version</em>' attribute isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Version</em>' attribute.
	 * @see #setVersion(String)
	 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getZigbeeWirelessNetwork_Version()
	 * @model default="1.2" required="true"
	 * @generated
	 */
	String getVersion();

	/**
	 * Sets the value of the '{@link com.jennic.ZPSConfiguration.ZigbeeWirelessNetwork#getVersion <em>Version</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>Version</em>' attribute.
	 * @see #getVersion()
	 * @generated
	 */
	void setVersion(String value);

	/**
	 * Returns the value of the '<em><b>Default Security Enabled</b></em>' attribute.
	 * The default value is <code>"true"</code>.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Default Security Enabled</em>' attribute isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Default Security Enabled</em>' attribute.
	 * @see #setDefaultSecurityEnabled(boolean)
	 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getZigbeeWirelessNetwork_DefaultSecurityEnabled()
	 * @model default="true" required="true"
	 * @generated
	 */
	boolean isDefaultSecurityEnabled();

	/**
	 * Sets the value of the '{@link com.jennic.ZPSConfiguration.ZigbeeWirelessNetwork#isDefaultSecurityEnabled <em>Default Security Enabled</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>Default Security Enabled</em>' attribute.
	 * @see #isDefaultSecurityEnabled()
	 * @generated
	 */
	void setDefaultSecurityEnabled(boolean value);

} // ZigbeeWirelessNetwork
