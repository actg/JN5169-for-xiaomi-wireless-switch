/**
 * (C) NXP B.V
 */
package com.jennic.ZPSConfiguration;

import java.util.Arrays;
import java.util.Collections;
import java.util.List;

import org.eclipse.emf.common.util.Enumerator;

/**
 * <!-- begin-user-doc -->
 * A representation of the literals of the enumeration '<em><b>Radio Type</b></em>',
 * and utility methods for working with them.
 * <!-- end-user-doc -->
 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getRadioType()
 * @model
 * @generated
 */
public enum RadioType implements Enumerator {
	/**
	 * The '<em><b>RT2400M Hz</b></em>' literal object.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #RT2400M_HZ_VALUE
	 * @generated
	 * @ordered
	 */
	RT2400M_HZ(0, "RT2400MHz", "RT2400MHz"),

	/**
	 * The '<em><b>RT868M Hz</b></em>' literal object.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #RT868M_HZ_VALUE
	 * @generated
	 * @ordered
	 */
	RT868M_HZ(1, "RT868MHz", "RT868MHz"),

	/**
	 * The '<em><b>RT915M Hz</b></em>' literal object.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #RT915M_HZ_VALUE
	 * @generated
	 * @ordered
	 */
	RT915M_HZ(2, "RT915MHz", "RT915MHz");

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public static final String copyright = "(C) NXP B.V";

	/**
	 * The '<em><b>RT2400M Hz</b></em>' literal value.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of '<em><b>RT2400M Hz</b></em>' literal object isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @see #RT2400M_HZ
	 * @model name="RT2400MHz"
	 * @generated
	 * @ordered
	 */
	public static final int RT2400M_HZ_VALUE = 0;

	/**
	 * The '<em><b>RT868M Hz</b></em>' literal value.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of '<em><b>RT868M Hz</b></em>' literal object isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @see #RT868M_HZ
	 * @model name="RT868MHz"
	 * @generated
	 * @ordered
	 */
	public static final int RT868M_HZ_VALUE = 1;

	/**
	 * The '<em><b>RT915M Hz</b></em>' literal value.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of '<em><b>RT915M Hz</b></em>' literal object isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @see #RT915M_HZ
	 * @model name="RT915MHz"
	 * @generated
	 * @ordered
	 */
	public static final int RT915M_HZ_VALUE = 2;

	/**
	 * An array of all the '<em><b>Radio Type</b></em>' enumerators.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	private static final RadioType[] VALUES_ARRAY =
		new RadioType[] {
			RT2400M_HZ,
			RT868M_HZ,
			RT915M_HZ,
		};

	/**
	 * A public read-only list of all the '<em><b>Radio Type</b></em>' enumerators.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public static final List<RadioType> VALUES = Collections.unmodifiableList(Arrays.asList(VALUES_ARRAY));

	/**
	 * Returns the '<em><b>Radio Type</b></em>' literal with the specified literal value.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public static RadioType get(String literal) {
		for (int i = 0; i < VALUES_ARRAY.length; ++i) {
			RadioType result = VALUES_ARRAY[i];
			if (result.toString().equals(literal)) {
				return result;
			}
		}
		return null;
	}

	/**
	 * Returns the '<em><b>Radio Type</b></em>' literal with the specified name.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public static RadioType getByName(String name) {
		for (int i = 0; i < VALUES_ARRAY.length; ++i) {
			RadioType result = VALUES_ARRAY[i];
			if (result.getName().equals(name)) {
				return result;
			}
		}
		return null;
	}

	/**
	 * Returns the '<em><b>Radio Type</b></em>' literal with the specified integer value.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public static RadioType get(int value) {
		switch (value) {
			case RT2400M_HZ_VALUE: return RT2400M_HZ;
			case RT868M_HZ_VALUE: return RT868M_HZ;
			case RT915M_HZ_VALUE: return RT915M_HZ;
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
	private RadioType(int value, String name, String literal) {
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
	
} //RadioType
