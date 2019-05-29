/**
 * (C) Jennic Ltd
 *
 * $Id: NodePowerDescriptor.java 78102 2016-03-24 15:35:29Z nxp29741 $
 */
package com.jennic.ZPSConfiguration;

import org.eclipse.emf.ecore.EObject;

/**
 * <!-- begin-user-doc -->
 * A representation of the model object '<em><b>Node Power Descriptor</b></em>'.
 * <!-- end-user-doc -->
 *
 * <p>
 * The following features are supported:
 * <ul>
 *   <li>{@link com.jennic.ZPSConfiguration.NodePowerDescriptor#isConstantPower <em>Constant Power</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.NodePowerDescriptor#isRechargeableBattery <em>Rechargeable Battery</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.NodePowerDescriptor#isDisposableBattery <em>Disposable Battery</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.NodePowerDescriptor#getDefaultPowerSource <em>Default Power Source</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.NodePowerDescriptor#getDefaultPowerMode <em>Default Power Mode</em>}</li>
 * </ul>
 * </p>
 *
 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getNodePowerDescriptor()
 * @model
 * @generated
 */
public interface NodePowerDescriptor extends EObject {
	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	String copyright = "(C) NXP B.V";

	/**
	 * Returns the value of the '<em><b>Constant Power</b></em>' attribute.
	 * The default value is <code>"true"</code>.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Constant Power</em>' attribute isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Constant Power</em>' attribute.
	 * @see #setConstantPower(boolean)
	 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getNodePowerDescriptor_ConstantPower()
	 * @model default="true" required="true"
	 * @generated
	 */
	boolean isConstantPower();

	/**
	 * Sets the value of the '{@link com.jennic.ZPSConfiguration.NodePowerDescriptor#isConstantPower <em>Constant Power</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>Constant Power</em>' attribute.
	 * @see #isConstantPower()
	 * @generated
	 */
	void setConstantPower(boolean value);

	/**
	 * Returns the value of the '<em><b>Rechargeable Battery</b></em>' attribute.
	 * The default value is <code>"false"</code>.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Rechargeable Battery</em>' attribute isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Rechargeable Battery</em>' attribute.
	 * @see #setRechargeableBattery(boolean)
	 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getNodePowerDescriptor_RechargeableBattery()
	 * @model default="false" required="true"
	 * @generated
	 */
	boolean isRechargeableBattery();

	/**
	 * Sets the value of the '{@link com.jennic.ZPSConfiguration.NodePowerDescriptor#isRechargeableBattery <em>Rechargeable Battery</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>Rechargeable Battery</em>' attribute.
	 * @see #isRechargeableBattery()
	 * @generated
	 */
	void setRechargeableBattery(boolean value);

	/**
	 * Returns the value of the '<em><b>Disposable Battery</b></em>' attribute.
	 * The default value is <code>"false"</code>.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Disposable Battery</em>' attribute isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Disposable Battery</em>' attribute.
	 * @see #setDisposableBattery(boolean)
	 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getNodePowerDescriptor_DisposableBattery()
	 * @model default="false" required="true"
	 * @generated
	 */
	boolean isDisposableBattery();

	/**
	 * Sets the value of the '{@link com.jennic.ZPSConfiguration.NodePowerDescriptor#isDisposableBattery <em>Disposable Battery</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>Disposable Battery</em>' attribute.
	 * @see #isDisposableBattery()
	 * @generated
	 */
	void setDisposableBattery(boolean value);

	/**
	 * Returns the value of the '<em><b>Default Power Source</b></em>' attribute.
	 * The default value is <code>"Constant Power"</code>.
	 * The literals are from the enumeration {@link com.jennic.ZPSConfiguration.PowerSources}.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Default Power Source</em>' attribute isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Default Power Source</em>' attribute.
	 * @see com.jennic.ZPSConfiguration.PowerSources
	 * @see #setDefaultPowerSource(PowerSources)
	 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getNodePowerDescriptor_DefaultPowerSource()
	 * @model default="Constant Power" required="true"
	 * @generated
	 */
	PowerSources getDefaultPowerSource();

	/**
	 * Sets the value of the '{@link com.jennic.ZPSConfiguration.NodePowerDescriptor#getDefaultPowerSource <em>Default Power Source</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>Default Power Source</em>' attribute.
	 * @see com.jennic.ZPSConfiguration.PowerSources
	 * @see #getDefaultPowerSource()
	 * @generated
	 */
	void setDefaultPowerSource(PowerSources value);

	/**
	 * Returns the value of the '<em><b>Default Power Mode</b></em>' attribute.
	 * The default value is <code>"Synchronised with RxOnWhenIdle"</code>.
	 * The literals are from the enumeration {@link com.jennic.ZPSConfiguration.PowerModes}.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Default Power Mode</em>' attribute isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Default Power Mode</em>' attribute.
	 * @see com.jennic.ZPSConfiguration.PowerModes
	 * @see #setDefaultPowerMode(PowerModes)
	 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getNodePowerDescriptor_DefaultPowerMode()
	 * @model default="Synchronised with RxOnWhenIdle" required="true"
	 * @generated
	 */
	PowerModes getDefaultPowerMode();

	/**
	 * Sets the value of the '{@link com.jennic.ZPSConfiguration.NodePowerDescriptor#getDefaultPowerMode <em>Default Power Mode</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>Default Power Mode</em>' attribute.
	 * @see com.jennic.ZPSConfiguration.PowerModes
	 * @see #getDefaultPowerMode()
	 * @generated
	 */
	void setDefaultPowerMode(PowerModes value);

} // NodePowerDescriptor
