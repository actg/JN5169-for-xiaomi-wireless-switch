/**
 * (C) Jennic Ltd
 *
 * $Id: ZDOCoordRouterOnlyServers.java 78102 2016-03-24 15:35:29Z nxp29741 $
 */
package com.jennic.ZPSConfiguration;

import org.eclipse.emf.ecore.EObject;

/**
 * <!-- begin-user-doc -->
 * A representation of the model object '<em><b>ZDO Coord Router Only Servers</b></em>'.
 * <!-- end-user-doc -->
 *
 * <p>
 * The following features are supported:
 * <ul>
 *   <li>{@link com.jennic.ZPSConfiguration.ZDOCoordRouterOnlyServers#getPermitJoiningServer <em>Permit Joining Server</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.ZDOCoordRouterOnlyServers#getMgmtRtgServer <em>Mgmt Rtg Server</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.ZDOCoordRouterOnlyServers#getMgmtMibIeeeServer <em>Mgmt Mib Ieee Server</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.ZDOCoordRouterOnlyServers#getParentAnnceServer <em>Parent Annce Server</em>}</li>
 * </ul>
 * </p>
 *
 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getZDOCoordRouterOnlyServers()
 * @model abstract="true"
 * @generated
 */
public interface ZDOCoordRouterOnlyServers extends EObject {
	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	String copyright = "(C) NXP B.V";

	/**
	 * Returns the value of the '<em><b>Permit Joining Server</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Permit Joining Server</em>' containment reference isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Permit Joining Server</em>' containment reference.
	 * @see #setPermitJoiningServer(PermitJoiningServer)
	 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getZDOCoordRouterOnlyServers_PermitJoiningServer()
	 * @model containment="true"
	 * @generated
	 */
	PermitJoiningServer getPermitJoiningServer();

	/**
	 * Sets the value of the '{@link com.jennic.ZPSConfiguration.ZDOCoordRouterOnlyServers#getPermitJoiningServer <em>Permit Joining Server</em>}' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>Permit Joining Server</em>' containment reference.
	 * @see #getPermitJoiningServer()
	 * @generated
	 */
	void setPermitJoiningServer(PermitJoiningServer value);

	/**
	 * Returns the value of the '<em><b>Mgmt Rtg Server</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Mgmt Rtg Server</em>' containment reference isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Mgmt Rtg Server</em>' containment reference.
	 * @see #setMgmtRtgServer(MgmtRtgServer)
	 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getZDOCoordRouterOnlyServers_MgmtRtgServer()
	 * @model containment="true"
	 * @generated
	 */
	MgmtRtgServer getMgmtRtgServer();

	/**
	 * Sets the value of the '{@link com.jennic.ZPSConfiguration.ZDOCoordRouterOnlyServers#getMgmtRtgServer <em>Mgmt Rtg Server</em>}' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>Mgmt Rtg Server</em>' containment reference.
	 * @see #getMgmtRtgServer()
	 * @generated
	 */
	void setMgmtRtgServer(MgmtRtgServer value);

	/**
	 * Returns the value of the '<em><b>Mgmt Mib Ieee Server</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Mgmt Mib Ieee Server</em>' containment reference isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Mgmt Mib Ieee Server</em>' containment reference.
	 * @see #setMgmtMibIeeeServer(MgmtMibIeeeServer)
	 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getZDOCoordRouterOnlyServers_MgmtMibIeeeServer()
	 * @model containment="true"
	 * @generated
	 */
	MgmtMibIeeeServer getMgmtMibIeeeServer();

	/**
	 * Sets the value of the '{@link com.jennic.ZPSConfiguration.ZDOCoordRouterOnlyServers#getMgmtMibIeeeServer <em>Mgmt Mib Ieee Server</em>}' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>Mgmt Mib Ieee Server</em>' containment reference.
	 * @see #getMgmtMibIeeeServer()
	 * @generated
	 */
	void setMgmtMibIeeeServer(MgmtMibIeeeServer value);

	/**
	 * Returns the value of the '<em><b>Parent Annce Server</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Parent Annce Server</em>' containment reference isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Parent Annce Server</em>' containment reference.
	 * @see #setParentAnnceServer(ParentAnnceServer)
	 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getZDOCoordRouterOnlyServers_ParentAnnceServer()
	 * @model containment="true"
	 * @generated
	 */
	ParentAnnceServer getParentAnnceServer();

	/**
	 * Sets the value of the '{@link com.jennic.ZPSConfiguration.ZDOCoordRouterOnlyServers#getParentAnnceServer <em>Parent Annce Server</em>}' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>Parent Annce Server</em>' containment reference.
	 * @see #getParentAnnceServer()
	 * @generated
	 */
	void setParentAnnceServer(ParentAnnceServer value);

} // ZDOCoordRouterOnlyServers
