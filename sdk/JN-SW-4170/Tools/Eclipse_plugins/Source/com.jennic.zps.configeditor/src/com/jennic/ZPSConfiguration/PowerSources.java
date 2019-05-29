/**
 * (C) Jennic Ltd
 *
 * $Id: PowerSources.java 78102 2016-03-24 15:35:29Z nxp29741 $
 */
package com.jennic.ZPSConfiguration;

import java.util.Arrays;
import java.util.Collections;
import java.util.List;

import org.eclipse.emf.common.util.Enumerator;

/**
 * <!-- begin-user-doc -->
 * A representation of the literals of the enumeration '<em><b>Power Sources</b></em>',
 * and utility methods for working with them.
 * <!-- end-user-doc -->
 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getPowerSources()
 * @model
 * @generated
 */
public enum PowerSources implements Enumerator {
	/**
	 * The '<em><b>Constant Power</b></em>' literal object.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #CONSTANT_POWER_VALUE
	 * @generated
	 * @ordered
	 */
	CONSTANT_POWER(0, "ConstantPower", "Constant Power"),

	/**
	 * The '<em><b>Rechargeable Battery</b></em>' literal object.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #RECHARGEABLE_BATTERY_VALUE
	 * @generated
	 * @ordered
	 */
	RECHARGEABLE_BATTERY(1, "RechargeableBattery", "Rechargeable Battery"),

	/**
	 * The '<em><b>Disposable Battery</b></em>' literal object.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #DISPOSABLE_BATTERY_VALUE
	 * @generated
	 * @ordered
	 */
	DISPOSABLE_BATTERY(2, "DisposableBattery", "Disposable Battery");

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public static final String copyright = "(C) NXP B.V";

	/**
	 * The '<em><b>Constant Power</b></em>' literal value.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of '<em><b>Constant Power</b></em>' literal object isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @see #CONSTANT_POWER
	 * @model name="ConstantPower" literal="Constant Power"
	 * @generated
	 * @ordered
	 */
	public static final int CONSTANT_POWER_VALUE = 0;

	/**
	 * The '<em><b>Rechargeable Battery</b></em>' literal value.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of '<em><b>Rechargeable Battery</b></em>' literal object isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @see #RECHARGEABLE_BATTERY
	 * @model name="RechargeableBattery" literal="Rechargeable Battery"
	 * @generated
	 * @ordered
	 */
	public static final int RECHARGEABLE_BATTERY_VALUE = 1;

	/**
	 * The '<em><b>Disposable Battery</b></em>' literal value.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of '<em><b>Disposable Battery</b></em>' literal object isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @see #DISPOSABLE_BATTERY
	 * @model name="DisposableBattery" literal="Disposable Battery"
	 * @generated
	 * @ordered
	 */
	public static final int DISPOSABLE_BATTERY_VALUE = 2;

	/**
	 * An array of all the '<em><b>Power Sources</b></em>' enumerators.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	private static final PowerSources[] VALUES_ARRAY =
		new PowerSources[] {
			CONSTANT_POWER,
			RECHARGEABLE_BATTERY,
			DISPOSABLE_BATTERY,
		};

	/**
	 * A public read-only list of all the '<em><b>Power Sources</b></em>' enumerators.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public static final List<PowerSources> VALUES = Collections.unmodifiableList(Arrays.asList(VALUES_ARRAY));

	/**
	 * Returns the '<em><b>Power Sources</b></em>' literal with the specified literal value.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public static PowerSources get(String literal) {
		for (int i = 0; i < VALUES_ARRAY.length; ++i) {
			PowerSources result = VALUES_ARRAY[i];
			if (result.toString().equals(literal)) {
				return result;
			}
		}
		return null;
	}

	/**
	 * Returns the '<em><b>Power Sources</b></em>' literal with the specified name.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public static PowerSources getByName(String name) {
		for (int i = 0; i < VALUES_ARRAY.length; ++i) {
			PowerSources result = VALUES_ARRAY[i];
			if (result.getName().equals(name)) {
				return result;
			}
		}
		return null;
	}

	/**
	 * Returns the '<em><b>Power Sources</b></em>' literal with the specified integer value.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public static PowerSources get(int value) {
		switch (value) {
			case CONSTANT_POWER_VALUE: return CONSTANT_POWER;
			case RECHARGEABLE_BATTERY_VALUE: return RECHARGEABLE_BATTERY;
			case DISPOSABLE_BATTERY_VALUE: return DISPOSABLE_BATTERY;
		}
		return null;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	private final int value;

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	private final String name;

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	private final String literal;

	/**
	 * Only this class can construct instances.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	private PowerSources(int value, String name, String literal) {
		this.value = value;
		this.name = name;
		this.literal = literal;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public int getValue() {
	  return value;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public String getName() {
	  return name;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public String getLiteral() {
	  return literal;
	}

	/**
	 * Returns the literal value of the enumerator, which is its string representation.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	@Override
	public String toString() {
		return literal;
	}
	
} //PowerSources
