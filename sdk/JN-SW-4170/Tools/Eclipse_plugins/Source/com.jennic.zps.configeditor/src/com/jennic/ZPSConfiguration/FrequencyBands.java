/**
 * (C) Jennic Ltd
 *
 * $Id: FrequencyBands.java 78153 2016-03-28 15:57:06Z nxp29741 $
 */
package com.jennic.ZPSConfiguration;

import java.util.Arrays;
import java.util.Collections;
import java.util.List;

import org.eclipse.emf.common.util.Enumerator;

/**
 * <!-- begin-user-doc -->
 * A representation of the literals of the enumeration '<em><b>Frequency Bands</b></em>',
 * and utility methods for working with them.
 * <!-- end-user-doc -->
 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getFrequencyBands()
 * @model
 * @generated
 */
public enum FrequencyBands implements Enumerator {
	/**
	 * The '<em><b>Freq868 MHz</b></em>' literal object.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #FREQ868_MHZ_VALUE
	 * @generated
	 * @ordered
	 */
	FREQ868_MHZ(0, "Freq868MHz", "868MHz"),

	/**
	 * The '<em><b>Freq914 MHz</b></em>' literal object.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #FREQ914_MHZ_VALUE
	 * @generated
	 * @ordered
	 */
	FREQ914_MHZ(2, "Freq914MHz", "914MHz"), /**
	 * The '<em><b>Freq2400 MHz</b></em>' literal object.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #FREQ2400_MHZ_VALUE
	 * @generated
	 * @ordered
	 */
	FREQ2400_MHZ(3, "Freq2400MHz", "2.4GHz");

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public static final String copyright = "(C) NXP B.V";

	/**
	 * The '<em><b>Freq868 MHz</b></em>' literal value.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of '<em><b>Freq868 MHz</b></em>' literal object isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @see #FREQ868_MHZ
	 * @model name="Freq868MHz" literal="868MHz"
	 * @generated
	 * @ordered
	 */
	public static final int FREQ868_MHZ_VALUE = 0;

	/**
	 * The '<em><b>Freq914 MHz</b></em>' literal value.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of '<em><b>Freq914 MHz</b></em>' literal object isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @see #FREQ914_MHZ
	 * @model name="Freq914MHz" literal="914MHz"
	 * @generated
	 * @ordered
	 */
	public static final int FREQ914_MHZ_VALUE = 2;

	/**
	 * The '<em><b>Freq2400 MHz</b></em>' literal value.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of '<em><b>Freq2400 MHz</b></em>' literal object isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @see #FREQ2400_MHZ
	 * @model name="Freq2400MHz" literal="2.4GHz"
	 * @generated
	 * @ordered
	 */
	public static final int FREQ2400_MHZ_VALUE = 3;

	/**
	 * An array of all the '<em><b>Frequency Bands</b></em>' enumerators.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	private static final FrequencyBands[] VALUES_ARRAY =
		new FrequencyBands[] {
			FREQ868_MHZ,
			FREQ914_MHZ,
			FREQ2400_MHZ,
		};

	/**
	 * A public read-only list of all the '<em><b>Frequency Bands</b></em>' enumerators.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public static final List<FrequencyBands> VALUES = Collections.unmodifiableList(Arrays.asList(VALUES_ARRAY));

	/**
	 * Returns the '<em><b>Frequency Bands</b></em>' literal with the specified literal value.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public static FrequencyBands get(String literal) {
		for (int i = 0; i < VALUES_ARRAY.length; ++i) {
			FrequencyBands result = VALUES_ARRAY[i];
			if (result.toString().equals(literal)) {
				return result;
			}
		}
		return null;
	}

	/**
	 * Returns the '<em><b>Frequency Bands</b></em>' literal with the specified name.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public static FrequencyBands getByName(String name) {
		for (int i = 0; i < VALUES_ARRAY.length; ++i) {
			FrequencyBands result = VALUES_ARRAY[i];
			if (result.getName().equals(name)) {
				return result;
			}
		}
		return null;
	}

	/**
	 * Returns the '<em><b>Frequency Bands</b></em>' literal with the specified integer value.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public static FrequencyBands get(int value) {
		switch (value) {
			case FREQ868_MHZ_VALUE: return FREQ868_MHZ;
			case FREQ914_MHZ_VALUE: return FREQ914_MHZ;
			case FREQ2400_MHZ_VALUE: return FREQ2400_MHZ;
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
	private FrequencyBands(int value, String name, String literal) {
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
	
} //FrequencyBands
