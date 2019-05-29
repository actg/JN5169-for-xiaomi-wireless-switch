/**
 * (C) Jennic Ltd
 *
 * $Id: PowerModes.java 78102 2016-03-24 15:35:29Z nxp29741 $
 */
package com.jennic.ZPSConfiguration;

import java.util.Arrays;
import java.util.Collections;
import java.util.List;

import org.eclipse.emf.common.util.Enumerator;

/**
 * <!-- begin-user-doc -->
 * A representation of the literals of the enumeration '<em><b>Power Modes</b></em>',
 * and utility methods for working with them.
 * <!-- end-user-doc -->
 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getPowerModes()
 * @model
 * @generated
 */
public enum PowerModes implements Enumerator {
	/**
	 * The '<em><b>Rx On When Idle Sync</b></em>' literal object.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #RX_ON_WHEN_IDLE_SYNC_VALUE
	 * @generated
	 * @ordered
	 */
	RX_ON_WHEN_IDLE_SYNC(0, "RxOnWhenIdleSync", "Synchronised with RxOnWhenIdle"),

	/**
	 * The '<em><b>Periodic</b></em>' literal object.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #PERIODIC_VALUE
	 * @generated
	 * @ordered
	 */
	PERIODIC(1, "Periodic", "Periodic"),

	/**
	 * The '<em><b>Stimulated</b></em>' literal object.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #STIMULATED_VALUE
	 * @generated
	 * @ordered
	 */
	STIMULATED(2, "Stimulated", "Stimulated");

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public static final String copyright = "(C) NXP B.V";

	/**
	 * The '<em><b>Rx On When Idle Sync</b></em>' literal value.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of '<em><b>Rx On When Idle Sync</b></em>' literal object isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @see #RX_ON_WHEN_IDLE_SYNC
	 * @model name="RxOnWhenIdleSync" literal="Synchronised with RxOnWhenIdle"
	 * @generated
	 * @ordered
	 */
	public static final int RX_ON_WHEN_IDLE_SYNC_VALUE = 0;

	/**
	 * The '<em><b>Periodic</b></em>' literal value.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of '<em><b>Periodic</b></em>' literal object isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @see #PERIODIC
	 * @model name="Periodic"
	 * @generated
	 * @ordered
	 */
	public static final int PERIODIC_VALUE = 1;

	/**
	 * The '<em><b>Stimulated</b></em>' literal value.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of '<em><b>Stimulated</b></em>' literal object isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @see #STIMULATED
	 * @model name="Stimulated"
	 * @generated
	 * @ordered
	 */
	public static final int STIMULATED_VALUE = 2;

	/**
	 * An array of all the '<em><b>Power Modes</b></em>' enumerators.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	private static final PowerModes[] VALUES_ARRAY =
		new PowerModes[] {
			RX_ON_WHEN_IDLE_SYNC,
			PERIODIC,
			STIMULATED,
		};

	/**
	 * A public read-only list of all the '<em><b>Power Modes</b></em>' enumerators.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public static final List<PowerModes> VALUES = Collections.unmodifiableList(Arrays.asList(VALUES_ARRAY));

	/**
	 * Returns the '<em><b>Power Modes</b></em>' literal with the specified literal value.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public static PowerModes get(String literal) {
		for (int i = 0; i < VALUES_ARRAY.length; ++i) {
			PowerModes result = VALUES_ARRAY[i];
			if (result.toString().equals(literal)) {
				return result;
			}
		}
		return null;
	}

	/**
	 * Returns the '<em><b>Power Modes</b></em>' literal with the specified name.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public static PowerModes getByName(String name) {
		for (int i = 0; i < VALUES_ARRAY.length; ++i) {
			PowerModes result = VALUES_ARRAY[i];
			if (result.getName().equals(name)) {
				return result;
			}
		}
		return null;
	}

	/**
	 * Returns the '<em><b>Power Modes</b></em>' literal with the specified integer value.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public static PowerModes get(int value) {
		switch (value) {
			case RX_ON_WHEN_IDLE_SYNC_VALUE: return RX_ON_WHEN_IDLE_SYNC;
			case PERIODIC_VALUE: return PERIODIC;
			case STIMULATED_VALUE: return STIMULATED;
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
	private PowerModes(int value, String name, String literal) {
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
	
} //PowerModes
