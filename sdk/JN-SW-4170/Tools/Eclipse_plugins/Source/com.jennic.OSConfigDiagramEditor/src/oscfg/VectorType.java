/**
 * <copyright>
 * </copyright>
 *
 * $Id$
 */
package oscfg;

import java.util.Arrays;
import java.util.Collections;
import java.util.List;

import org.eclipse.emf.common.util.Enumerator;

/**
 * <!-- begin-user-doc -->
 * A representation of the literals of the enumeration '<em><b>Vector Type</b></em>',
 * and utility methods for working with them.
 * <!-- end-user-doc -->
 * @see oscfg.OscfgPackage#getVectorType()
 * @model
 * @generated
 */
public enum VectorType implements Enumerator {
	/**
	 * The '<em><b>System Controller</b></em>' literal object.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #SYSTEM_CONTROLLER_VALUE
	 * @generated
	 * @ordered
	 */
	SYSTEM_CONTROLLER(2, "SystemController", "SystemController"), /**
	 * The '<em><b>BBC</b></em>' literal object.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #BBC_VALUE
	 * @generated
	 * @ordered
	 */
	BBC(3, "BBC", "BBC"),

	/**
	 * The '<em><b>AES</b></em>' literal object.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #AES_VALUE
	 * @generated
	 * @ordered
	 */
	AES(4, "AES", "AES"),

	/**
	 * The '<em><b>PHY</b></em>' literal object.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #PHY_VALUE
	 * @generated
	 * @ordered
	 */
	PHY(5, "PHY", "PHY"),

	/**
	 * The '<em><b>UART0</b></em>' literal object.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #UART0_VALUE
	 * @generated
	 * @ordered
	 */
	UART0(6, "UART0", "UART0"),

	/**
	 * The '<em><b>UART1</b></em>' literal object.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #UART1_VALUE
	 * @generated
	 * @ordered
	 */
	UART1(7, "UART1", "UART1"),

	/**
	 * The '<em><b>Timer0</b></em>' literal object.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #TIMER0_VALUE
	 * @generated
	 * @ordered
	 */
	TIMER0(8, "Timer0", "Timer0"),

	/**
	 * The '<em><b>Timer1</b></em>' literal object.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #TIMER1_VALUE
	 * @generated
	 * @ordered
	 */
	TIMER1(9, "Timer1", "Timer1"),

	/**
	 * The '<em><b>Serial Interface</b></em>' literal object.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #SERIAL_INTERFACE_VALUE
	 * @generated
	 * @ordered
	 */
	SERIAL_INTERFACE(10, "SerialInterface", "SerialInterface"),

	/**
	 * The '<em><b>SPI</b></em>' literal object.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #SPI_VALUE
	 * @generated
	 * @ordered
	 */
	SPI(11, "SPI", "SPI"),

	/**
	 * The '<em><b>Intelligent Peripheral</b></em>' literal object.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #INTELLIGENT_PERIPHERAL_VALUE
	 * @generated
	 * @ordered
	 */
	INTELLIGENT_PERIPHERAL(12, "IntelligentPeripheral", "IntelligentPeripheral"), /**
	 * The '<em><b>Analogue Peripheral</b></em>' literal object.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #ANALOGUE_PERIPHERAL_VALUE
	 * @generated
	 * @ordered
	 */
	ANALOGUE_PERIPHERAL(13, "AnaloguePeripheral", "AnaloguePeripheral"), /**
	 * The '<em><b>Timer2</b></em>' literal object.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #TIMER2_VALUE
	 * @generated
	 * @ordered
	 */
	TIMER2(14, "Timer2", "Timer2"), /**
	 * The '<em><b>Tick Timer</b></em>' literal object.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #TICK_TIMER_VALUE
	 * @generated
	 * @ordered
	 */
	TICK_TIMER(15, "TickTimer", "TickTimer"), /**
	 * The '<em><b>Sample FIFO</b></em>' literal object.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #SAMPLE_FIFO_VALUE
	 * @generated
	 * @ordered
	 */
	SAMPLE_FIFO(0, "SampleFIFO", "SampleFIFO"), /**
	 * The '<em><b>Digital Audio IF</b></em>' literal object.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #DIGITAL_AUDIO_IF_VALUE
	 * @generated
	 * @ordered
	 */
	DIGITAL_AUDIO_IF(1, "DigitalAudioIF", "DigitalAudioIF"), /**
	 * The '<em><b>Bus Error</b></em>' literal object.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #BUS_ERROR_VALUE
	 * @generated
	 * @ordered
	 */
	BUS_ERROR(100, "BusError", "BusError"), /**
	 * The '<em><b>Data Page Fault</b></em>' literal object.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #DATA_PAGE_FAULT_VALUE
	 * @generated
	 * @ordered
	 */
	DATA_PAGE_FAULT(101, "DataPageFault", "DataPageFault"), /**
	 * The '<em><b>Instruction Page Fault</b></em>' literal object.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #INSTRUCTION_PAGE_FAULT_VALUE
	 * @generated
	 * @ordered
	 */
	INSTRUCTION_PAGE_FAULT(102, "InstructionPageFault", "InstructionPageFault"), /**
	 * The '<em><b>Tick Timer Exception</b></em>' literal object.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #TICK_TIMER_EXCEPTION_VALUE
	 * @generated
	 * @ordered
	 */
	TICK_TIMER_EXCEPTION(103, "TickTimerException", "TickTimerException"), /**
	 * The '<em><b>Alignment</b></em>' literal object.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #ALIGNMENT_VALUE
	 * @generated
	 * @ordered
	 */
	ALIGNMENT(104, "Alignment", "Alignment"), /**
	 * The '<em><b>Illegal Instruction</b></em>' literal object.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #ILLEGAL_INSTRUCTION_VALUE
	 * @generated
	 * @ordered
	 */
	ILLEGAL_INSTRUCTION(105, "IllegalInstruction", "IllegalInstruction"), /**
	 * The '<em><b>DTLB Miss</b></em>' literal object.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #DTLB_MISS_VALUE
	 * @generated
	 * @ordered
	 */
	DTLB_MISS(106, "DTLBMiss", "D-TLBMiss"), /**
	 * The '<em><b>ITLB Miss</b></em>' literal object.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #ITLB_MISS_VALUE
	 * @generated
	 * @ordered
	 */
	ITLB_MISS(107, "ITLBMiss", "I-TLBMiss"), /**
	 * The '<em><b>Range</b></em>' literal object.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #RANGE_VALUE
	 * @generated
	 * @ordered
	 */
	RANGE(108, "Range", "Range"), /**
	 * The '<em><b>System Call</b></em>' literal object.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #SYSTEM_CALL_VALUE
	 * @generated
	 * @ordered
	 */
	SYSTEM_CALL(109, "SystemCall", "SystemCall"), /**
	 * The '<em><b>Floating Point</b></em>' literal object.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #FLOATING_POINT_VALUE
	 * @generated
	 * @ordered
	 */
	FLOATING_POINT(110, "FloatingPoint", "FloatingPoint"), /**
	 * The '<em><b>Trap</b></em>' literal object.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #TRAP_VALUE
	 * @generated
	 * @ordered
	 */
	TRAP(111, "Trap", "Trap"), /**
	 * The '<em><b>Unimplemented Module</b></em>' literal object.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #UNIMPLEMENTED_MODULE_VALUE
	 * @generated
	 * @ordered
	 */
	UNIMPLEMENTED_MODULE(112, "UnimplementedModule", "UnimplementedModule"), /**
	 * The '<em><b>Stack Overflow Exception</b></em>' literal object.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #STACK_OVERFLOW_EXCEPTION_VALUE
	 * @generated
	 * @ordered
	 */
	STACK_OVERFLOW_EXCEPTION(113, "StackOverflowException", "StackOverflowException"), /**
	 * The '<em><b>SPI Slave</b></em>' literal object.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #SPI_SLAVE_VALUE
	 * @generated
	 * @ordered
	 */
	SPI_SLAVE(9, "SPISlave", "SPISlave"), /**
	 * The '<em><b>SPI Master</b></em>' literal object.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #SPI_MASTER_VALUE
	 * @generated
	 * @ordered
	 */
	SPI_MASTER(11, "SPIMaster", "SPIMaster"), /**
	 * The '<em><b>I2C</b></em>' literal object.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #I2C_VALUE
	 * @generated
	 * @ordered
	 */
	I2C(10, "I2C", "I2C"), /**
	 * The '<em><b>Timer3</b></em>' literal object.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #TIMER3_VALUE
	 * @generated
	 * @ordered
	 */
	TIMER3(14, "Timer3", "Timer3"), /**
	 * The '<em><b>Timer4</b></em>' literal object.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #TIMER4_VALUE
	 * @generated
	 * @ordered
	 */
	TIMER4(12, "Timer4", "Timer4");

	/**
	 * The '<em><b>System Controller</b></em>' literal value.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of '<em><b>System Controller</b></em>' literal object isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @see #SYSTEM_CONTROLLER
	 * @model name="SystemController"
	 * @generated
	 * @ordered
	 */
	public static final int SYSTEM_CONTROLLER_VALUE = 2;

	/**
	 * The '<em><b>BBC</b></em>' literal value.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of '<em><b>BBC</b></em>' literal object isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @see #BBC
	 * @model
	 * @generated
	 * @ordered
	 */
	public static final int BBC_VALUE = 3;

	/**
	 * The '<em><b>AES</b></em>' literal value.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of '<em><b>AES</b></em>' literal object isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @see #AES
	 * @model
	 * @generated
	 * @ordered
	 */
	public static final int AES_VALUE = 4;

	/**
	 * The '<em><b>PHY</b></em>' literal value.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of '<em><b>PHY</b></em>' literal object isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @see #PHY
	 * @model
	 * @generated
	 * @ordered
	 */
	public static final int PHY_VALUE = 5;

	/**
	 * The '<em><b>UART0</b></em>' literal value.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of '<em><b>UART0</b></em>' literal object isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @see #UART0
	 * @model
	 * @generated
	 * @ordered
	 */
	public static final int UART0_VALUE = 6;

	/**
	 * The '<em><b>UART1</b></em>' literal value.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of '<em><b>UART1</b></em>' literal object isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @see #UART1
	 * @model
	 * @generated
	 * @ordered
	 */
	public static final int UART1_VALUE = 7;

	/**
	 * The '<em><b>Timer0</b></em>' literal value.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of '<em><b>Timer0</b></em>' literal object isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @see #TIMER0
	 * @model name="Timer0"
	 * @generated
	 * @ordered
	 */
	public static final int TIMER0_VALUE = 8;

	/**
	 * The '<em><b>Timer1</b></em>' literal value.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of '<em><b>Timer1</b></em>' literal object isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @see #TIMER1
	 * @model name="Timer1"
	 * @generated
	 * @ordered
	 */
	public static final int TIMER1_VALUE = 9;

	/**
	 * The '<em><b>Serial Interface</b></em>' literal value.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of '<em><b>Serial Interface</b></em>' literal object isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @see #SERIAL_INTERFACE
	 * @model name="SerialInterface"
	 * @generated
	 * @ordered
	 */
	public static final int SERIAL_INTERFACE_VALUE = 10;

	/**
	 * The '<em><b>SPI</b></em>' literal value.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of '<em><b>SPI</b></em>' literal object isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @see #SPI
	 * @model
	 * @generated
	 * @ordered
	 */
	public static final int SPI_VALUE = 11;

	/**
	 * The '<em><b>Intelligent Peripheral</b></em>' literal value.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of '<em><b>Intelligent Peripheral</b></em>' literal object isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @see #INTELLIGENT_PERIPHERAL
	 * @model name="IntelligentPeripheral"
	 * @generated
	 * @ordered
	 */
	public static final int INTELLIGENT_PERIPHERAL_VALUE = 12;

	/**
	 * The '<em><b>Analogue Peripheral</b></em>' literal value.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of '<em><b>Analogue Peripheral</b></em>' literal object isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @see #ANALOGUE_PERIPHERAL
	 * @model name="AnaloguePeripheral"
	 * @generated
	 * @ordered
	 */
	public static final int ANALOGUE_PERIPHERAL_VALUE = 13;

	/**
	 * The '<em><b>Timer2</b></em>' literal value.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of '<em><b>Timer2</b></em>' literal object isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @see #TIMER2
	 * @model name="Timer2"
	 * @generated
	 * @ordered
	 */
	public static final int TIMER2_VALUE = 14;

	/**
	 * The '<em><b>Tick Timer</b></em>' literal value.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of '<em><b>Tick Timer</b></em>' literal object isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @see #TICK_TIMER
	 * @model name="TickTimer"
	 * @generated
	 * @ordered
	 */
	public static final int TICK_TIMER_VALUE = 15;

	/**
	 * The '<em><b>Sample FIFO</b></em>' literal value.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of '<em><b>Sample FIFO</b></em>' literal object isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @see #SAMPLE_FIFO
	 * @model name="SampleFIFO"
	 * @generated
	 * @ordered
	 */
	public static final int SAMPLE_FIFO_VALUE = 0;

	/**
	 * The '<em><b>Digital Audio IF</b></em>' literal value.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of '<em><b>Digital Audio IF</b></em>' literal object isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @see #DIGITAL_AUDIO_IF
	 * @model name="DigitalAudioIF"
	 * @generated
	 * @ordered
	 */
	public static final int DIGITAL_AUDIO_IF_VALUE = 1;

	/**
	 * The '<em><b>Bus Error</b></em>' literal value.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of '<em><b>Bus Error</b></em>' literal object isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @see #BUS_ERROR
	 * @model name="BusError"
	 * @generated
	 * @ordered
	 */
	public static final int BUS_ERROR_VALUE = 100;

	/**
	 * The '<em><b>Data Page Fault</b></em>' literal value.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of '<em><b>Data Page Fault</b></em>' literal object isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @see #DATA_PAGE_FAULT
	 * @model name="DataPageFault"
	 * @generated
	 * @ordered
	 */
	public static final int DATA_PAGE_FAULT_VALUE = 101;

	/**
	 * The '<em><b>Instruction Page Fault</b></em>' literal value.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of '<em><b>Instruction Page Fault</b></em>' literal object isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @see #INSTRUCTION_PAGE_FAULT
	 * @model name="InstructionPageFault"
	 * @generated
	 * @ordered
	 */
	public static final int INSTRUCTION_PAGE_FAULT_VALUE = 102;

	/**
	 * The '<em><b>Tick Timer Exception</b></em>' literal value.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of '<em><b>Tick Timer Exception</b></em>' literal object isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @see #TICK_TIMER_EXCEPTION
	 * @model name="TickTimerException"
	 * @generated
	 * @ordered
	 */
	public static final int TICK_TIMER_EXCEPTION_VALUE = 103;

	/**
	 * The '<em><b>Alignment</b></em>' literal value.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of '<em><b>Alignment</b></em>' literal object isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @see #ALIGNMENT
	 * @model name="Alignment"
	 * @generated
	 * @ordered
	 */
	public static final int ALIGNMENT_VALUE = 104;

	/**
	 * The '<em><b>Illegal Instruction</b></em>' literal value.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of '<em><b>Illegal Instruction</b></em>' literal object isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @see #ILLEGAL_INSTRUCTION
	 * @model name="IllegalInstruction"
	 * @generated
	 * @ordered
	 */
	public static final int ILLEGAL_INSTRUCTION_VALUE = 105;

	/**
	 * The '<em><b>DTLB Miss</b></em>' literal value.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of '<em><b>DTLB Miss</b></em>' literal object isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @see #DTLB_MISS
	 * @model name="DTLBMiss" literal="D-TLBMiss"
	 * @generated
	 * @ordered
	 */
	public static final int DTLB_MISS_VALUE = 106;

	/**
	 * The '<em><b>ITLB Miss</b></em>' literal value.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of '<em><b>ITLB Miss</b></em>' literal object isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @see #ITLB_MISS
	 * @model name="ITLBMiss" literal="I-TLBMiss"
	 * @generated
	 * @ordered
	 */
	public static final int ITLB_MISS_VALUE = 107;

	/**
	 * The '<em><b>Range</b></em>' literal value.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of '<em><b>Range</b></em>' literal object isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @see #RANGE
	 * @model name="Range"
	 * @generated
	 * @ordered
	 */
	public static final int RANGE_VALUE = 108;

	/**
	 * The '<em><b>System Call</b></em>' literal value.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of '<em><b>System Call</b></em>' literal object isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @see #SYSTEM_CALL
	 * @model name="SystemCall"
	 * @generated
	 * @ordered
	 */
	public static final int SYSTEM_CALL_VALUE = 109;

	/**
	 * The '<em><b>Floating Point</b></em>' literal value.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of '<em><b>Floating Point</b></em>' literal object isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @see #FLOATING_POINT
	 * @model name="FloatingPoint"
	 * @generated
	 * @ordered
	 */
	public static final int FLOATING_POINT_VALUE = 110;

	/**
	 * The '<em><b>Trap</b></em>' literal value.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of '<em><b>Trap</b></em>' literal object isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @see #TRAP
	 * @model name="Trap"
	 * @generated
	 * @ordered
	 */
	public static final int TRAP_VALUE = 111;

	/**
	 * The '<em><b>Unimplemented Module</b></em>' literal value.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of '<em><b>Unimplemented Module</b></em>' literal object isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @see #UNIMPLEMENTED_MODULE
	 * @model name="UnimplementedModule"
	 * @generated
	 * @ordered
	 */
	public static final int UNIMPLEMENTED_MODULE_VALUE = 112;

	/**
	 * The '<em><b>Stack Overflow Exception</b></em>' literal value.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of '<em><b>Stack Overflow Exception</b></em>' literal object isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @see #STACK_OVERFLOW_EXCEPTION
	 * @model name="StackOverflowException"
	 * @generated
	 * @ordered
	 */
	public static final int STACK_OVERFLOW_EXCEPTION_VALUE = 113;

	/**
	 * The '<em><b>SPI Slave</b></em>' literal value.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of '<em><b>SPI Slave</b></em>' literal object isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @see #SPI_SLAVE
	 * @model name="SPISlave"
	 * @generated
	 * @ordered
	 */
	public static final int SPI_SLAVE_VALUE = 9;

	/**
	 * The '<em><b>SPI Master</b></em>' literal value.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of '<em><b>SPI Master</b></em>' literal object isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @see #SPI_MASTER
	 * @model name="SPIMaster"
	 * @generated
	 * @ordered
	 */
	public static final int SPI_MASTER_VALUE = 11;

	/**
	 * The '<em><b>I2C</b></em>' literal value.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of '<em><b>I2C</b></em>' literal object isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @see #I2C
	 * @model
	 * @generated
	 * @ordered
	 */
	public static final int I2C_VALUE = 10;

	/**
	 * The '<em><b>Timer3</b></em>' literal value.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of '<em><b>Timer3</b></em>' literal object isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @see #TIMER3
	 * @model name="Timer3"
	 * @generated
	 * @ordered
	 */
	public static final int TIMER3_VALUE = 14;

	/**
	 * The '<em><b>Timer4</b></em>' literal value.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of '<em><b>Timer4</b></em>' literal object isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @see #TIMER4
	 * @model name="Timer4"
	 * @generated
	 * @ordered
	 */
	public static final int TIMER4_VALUE = 12;

	/**
	 * An array of all the '<em><b>Vector Type</b></em>' enumerators.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	private static final VectorType[] VALUES_ARRAY =
		new VectorType[] {
			SYSTEM_CONTROLLER,
			BBC,
			AES,
			PHY,
			UART0,
			UART1,
			TIMER0,
			TIMER1,
			SERIAL_INTERFACE,
			SPI,
			INTELLIGENT_PERIPHERAL,
			ANALOGUE_PERIPHERAL,
			TIMER2,
			TICK_TIMER,
			SAMPLE_FIFO,
			DIGITAL_AUDIO_IF,
			BUS_ERROR,
			DATA_PAGE_FAULT,
			INSTRUCTION_PAGE_FAULT,
			TICK_TIMER_EXCEPTION,
			ALIGNMENT,
			ILLEGAL_INSTRUCTION,
			DTLB_MISS,
			ITLB_MISS,
			RANGE,
			SYSTEM_CALL,
			FLOATING_POINT,
			TRAP,
			UNIMPLEMENTED_MODULE,
			STACK_OVERFLOW_EXCEPTION,
			SPI_SLAVE,
			SPI_MASTER,
			I2C,
			TIMER3,
			TIMER4,
		};

	/**
	 * A public read-only list of all the '<em><b>Vector Type</b></em>' enumerators.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public static final List<VectorType> VALUES = Collections.unmodifiableList(Arrays.asList(VALUES_ARRAY));

	/**
	 * Returns the '<em><b>Vector Type</b></em>' literal with the specified literal value.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public static VectorType get(String literal) {
		for (int i = 0; i < VALUES_ARRAY.length; ++i) {
			VectorType result = VALUES_ARRAY[i];
			if (result.toString().equals(literal)) {
				return result;
			}
		}
		return null;
	}

	/**
	 * Returns the '<em><b>Vector Type</b></em>' literal with the specified name.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public static VectorType getByName(String name) {
		for (int i = 0; i < VALUES_ARRAY.length; ++i) {
			VectorType result = VALUES_ARRAY[i];
			if (result.getName().equals(name)) {
				return result;
			}
		}
		return null;
	}

	/**
	 * Returns the '<em><b>Vector Type</b></em>' literal with the specified integer value.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public static VectorType get(int value) {
		switch (value) {
			case SYSTEM_CONTROLLER_VALUE: return SYSTEM_CONTROLLER;
			case BBC_VALUE: return BBC;
			case AES_VALUE: return AES;
			case PHY_VALUE: return PHY;
			case UART0_VALUE: return UART0;
			case UART1_VALUE: return UART1;
			case TIMER0_VALUE: return TIMER0;
			case TIMER1_VALUE: return TIMER1;
			case SERIAL_INTERFACE_VALUE: return SERIAL_INTERFACE;
			case SPI_VALUE: return SPI;
			case INTELLIGENT_PERIPHERAL_VALUE: return INTELLIGENT_PERIPHERAL;
			case ANALOGUE_PERIPHERAL_VALUE: return ANALOGUE_PERIPHERAL;
			case TIMER2_VALUE: return TIMER2;
			case TICK_TIMER_VALUE: return TICK_TIMER;
			case SAMPLE_FIFO_VALUE: return SAMPLE_FIFO;
			case DIGITAL_AUDIO_IF_VALUE: return DIGITAL_AUDIO_IF;
			case BUS_ERROR_VALUE: return BUS_ERROR;
			case DATA_PAGE_FAULT_VALUE: return DATA_PAGE_FAULT;
			case INSTRUCTION_PAGE_FAULT_VALUE: return INSTRUCTION_PAGE_FAULT;
			case TICK_TIMER_EXCEPTION_VALUE: return TICK_TIMER_EXCEPTION;
			case ALIGNMENT_VALUE: return ALIGNMENT;
			case ILLEGAL_INSTRUCTION_VALUE: return ILLEGAL_INSTRUCTION;
			case DTLB_MISS_VALUE: return DTLB_MISS;
			case ITLB_MISS_VALUE: return ITLB_MISS;
			case RANGE_VALUE: return RANGE;
			case SYSTEM_CALL_VALUE: return SYSTEM_CALL;
			case FLOATING_POINT_VALUE: return FLOATING_POINT;
			case TRAP_VALUE: return TRAP;
			case UNIMPLEMENTED_MODULE_VALUE: return UNIMPLEMENTED_MODULE;
			case STACK_OVERFLOW_EXCEPTION_VALUE: return STACK_OVERFLOW_EXCEPTION;
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
	private VectorType(int value, String name, String literal) {
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
	
} //VectorType
