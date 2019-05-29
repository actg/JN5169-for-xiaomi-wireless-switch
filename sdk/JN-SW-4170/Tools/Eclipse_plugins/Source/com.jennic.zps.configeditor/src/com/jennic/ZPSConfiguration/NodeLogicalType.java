/**
 * (C) Jennic Ltd
 *
 * $Id: NodeLogicalType.java 78102 2016-03-24 15:35:29Z nxp29741 $
 */
package com.jennic.ZPSConfiguration;

import java.util.Arrays;
import java.util.Collections;
import java.util.List;

import org.eclipse.emf.common.util.Enumerator;

/**
 * <!-- begin-user-doc -->
 * A representation of the literals of the enumeration '<em><b>Node Logical Type</b></em>',
 * and utility methods for working with them.
 * <!-- end-user-doc -->
 * @see com.jennic.ZPSConfiguration.ZPSConfigurationPackage#getNodeLogicalType()
 * @model
 * @generated
 */
public enum NodeLogicalType implements Enumerator {
	/**
	 * The '<em><b>Zigbee Coordinator</b></em>' literal object.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #ZIGBEE_COORDINATOR_VALUE
	 * @generated
	 * @ordered
	 */
	ZIGBEE_COORDINATOR(0, "ZigbeeCoordinator", "ZC"),

	/**
	 * The '<em><b>Zigbee Router</b></em>' literal object.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #ZIGBEE_ROUTER_VALUE
	 * @generated
	 * @ordered
	 */
	ZIGBEE_ROUTER(1, "ZigbeeRouter", "ZR"),

	/**
	 * The '<em><b>Zigbee End Device</b></em>' literal object.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #ZIGBEE_END_DEVICE_VALUE
	 * @generated
	 * @ordered
	 */
	ZIGBEE_END_DEVICE(2, "ZigbeeEndDevice", "ZED");

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public static final String copyright = "(C) NXP B.V";

	/**
	 * The '<em><b>Zigbee Coordinator</b></em>' literal value.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of '<em><b>Zigbee Coordinator</b></em>' literal object isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @see #ZIGBEE_COORDINATOR
	 * @model name="ZigbeeCoordinator" literal="ZC"
	 * @generated
	 * @ordered
	 */
	public static final int ZIGBEE_COORDINATOR_VALUE = 0;

	/**
	 * The '<em><b>Zigbee Router</b></em>' literal value.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of '<em><b>Zigbee Router</b></em>' literal object isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @see #ZIGBEE_ROUTER
	 * @model name="ZigbeeRouter" literal="ZR"
	 * @generated
	 * @ordered
	 */
	public static final int ZIGBEE_ROUTER_VALUE = 1;

	/**
	 * The '<em><b>Zigbee End Device</b></em>' literal value.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of '<em><b>Zigbee End Device</b></em>' literal object isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @see #ZIGBEE_END_DEVICE
	 * @model name="ZigbeeEndDevice" literal="ZED"
	 * @generated
	 * @ordered
	 */
	public static final int ZIGBEE_END_DEVICE_VALUE = 2;

	/**
	 * An array of all the '<em><b>Node Logical Type</b></em>' enumerators.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	private static final NodeLogicalType[] VALUES_ARRAY =
		new NodeLogicalType[] {
			ZIGBEE_COORDINATOR,
			ZIGBEE_ROUTER,
			ZIGBEE_END_DEVICE,
		};

	/**
	 * A public read-only list of all the '<em><b>Node Logical Type</b></em>' enumerators.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public static final List<NodeLogicalType> VALUES = Collections.unmodifiableList(Arrays.asList(VALUES_ARRAY));

	/**
	 * Returns the '<em><b>Node Logical Type</b></em>' literal with the specified literal value.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public static NodeLogicalType get(String literal) {
		for (int i = 0; i < VALUES_ARRAY.length; ++i) {
			NodeLogicalType result = VALUES_ARRAY[i];
			if (result.toString().equals(literal)) {
				return result;
			}
		}
		return null;
	}

	/**
	 * Returns the '<em><b>Node Logical Type</b></em>' literal with the specified name.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public static NodeLogicalType getByName(String name) {
		for (int i = 0; i < VALUES_ARRAY.length; ++i) {
			NodeLogicalType result = VALUES_ARRAY[i];
			if (result.getName().equals(name)) {
				return result;
			}
		}
		return null;
	}

	/**
	 * Returns the '<em><b>Node Logical Type</b></em>' literal with the specified integer value.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public static NodeLogicalType get(int value) {
		switch (value) {
			case ZIGBEE_COORDINATOR_VALUE: return ZIGBEE_COORDINATOR;
			case ZIGBEE_ROUTER_VALUE: return ZIGBEE_ROUTER;
			case ZIGBEE_END_DEVICE_VALUE: return ZIGBEE_END_DEVICE;
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
	private NodeLogicalType(int value, String name, String literal) {
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
	
} //NodeLogicalType
