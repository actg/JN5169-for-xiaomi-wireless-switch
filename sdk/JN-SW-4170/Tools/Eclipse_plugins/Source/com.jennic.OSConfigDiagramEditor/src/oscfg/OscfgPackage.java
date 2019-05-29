/**
 * <copyright>
 * </copyright>
 *
 * $Id$
 */
package oscfg;

import org.eclipse.emf.ecore.EAttribute;
import org.eclipse.emf.ecore.EClass;
import org.eclipse.emf.ecore.EDataType;
import org.eclipse.emf.ecore.EEnum;
import org.eclipse.emf.ecore.EPackage;
import org.eclipse.emf.ecore.EReference;

/**
 * <!-- begin-user-doc -->
 * The <b>Package</b> for the model.
 * It contains accessors for the meta objects to represent
 * <ul>
 *   <li>each class,</li>
 *   <li>each feature of each class,</li>
 *   <li>each enum,</li>
 *   <li>and each data type</li>
 * </ul>
 * <!-- end-user-doc -->
 * <!-- begin-model-doc -->
 * 
 * 			OS Configuration
 * 			Copyright 2007 Jennic.com. All rights reserved.
 * 		
 * <!-- end-model-doc -->
 * @see oscfg.OscfgFactory
 * @model kind="package"
 *        extendedMetaData="elementFormDefault='qualified'"
 * @generated
 */
public interface OscfgPackage extends EPackage {
	/**
	 * The package name.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	String eNAME = "oscfg";

	/**
	 * The package namespace URI.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	String eNS_URI = "http://www.jennic.com/OSConfig";

	/**
	 * The package namespace name.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	String eNS_PREFIX = "oscfg";

	/**
	 * The singleton instance of the package.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	OscfgPackage eINSTANCE = oscfg.impl.OscfgPackageImpl.init();

	/**
	 * The meta object id for the '{@link oscfg.impl.NamedObjectImpl <em>Named Object</em>}' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see oscfg.impl.NamedObjectImpl
	 * @see oscfg.impl.OscfgPackageImpl#getNamedObject()
	 * @generated
	 */
	int NAMED_OBJECT = 14;

	/**
	 * The feature id for the '<em><b>Name</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int NAMED_OBJECT__NAME = 0;

	/**
	 * The number of structural features of the '<em>Named Object</em>' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int NAMED_OBJECT_FEATURE_COUNT = 1;

	/**
	 * The meta object id for the '{@link oscfg.impl.CallbackFunctionImpl <em>Callback Function</em>}' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see oscfg.impl.CallbackFunctionImpl
	 * @see oscfg.impl.OscfgPackageImpl#getCallbackFunction()
	 * @generated
	 */
	int CALLBACK_FUNCTION = 0;

	/**
	 * The feature id for the '<em><b>Name</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int CALLBACK_FUNCTION__NAME = NAMED_OBJECT__NAME;

	/**
	 * The feature id for the '<em><b>Post Message</b></em>' reference list.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int CALLBACK_FUNCTION__POST_MESSAGE = NAMED_OBJECT_FEATURE_COUNT + 0;

	/**
	 * The number of structural features of the '<em>Callback Function</em>' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int CALLBACK_FUNCTION_FEATURE_COUNT = NAMED_OBJECT_FEATURE_COUNT + 1;

	/**
	 * The meta object id for the '{@link oscfg.impl.ConfigurationImpl <em>Configuration</em>}' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see oscfg.impl.ConfigurationImpl
	 * @see oscfg.impl.OscfgPackageImpl#getConfiguration()
	 * @generated
	 */
	int CONFIGURATION = 1;

	/**
	 * The feature id for the '<em><b>OS</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int CONFIGURATION__OS = 0;

	/**
	 * The feature id for the '<em><b>Version</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int CONFIGURATION__VERSION = 1;

	/**
	 * The number of structural features of the '<em>Configuration</em>' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int CONFIGURATION_FEATURE_COUNT = 2;

	/**
	 * The meta object id for the '{@link oscfg.impl.DocumentRootImpl <em>Document Root</em>}' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see oscfg.impl.DocumentRootImpl
	 * @see oscfg.impl.OscfgPackageImpl#getDocumentRoot()
	 * @generated
	 */
	int DOCUMENT_ROOT = 2;

	/**
	 * The feature id for the '<em><b>Mixed</b></em>' attribute list.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int DOCUMENT_ROOT__MIXED = 0;

	/**
	 * The feature id for the '<em><b>XMLNS Prefix Map</b></em>' map.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int DOCUMENT_ROOT__XMLNS_PREFIX_MAP = 1;

	/**
	 * The feature id for the '<em><b>XSI Schema Location</b></em>' map.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int DOCUMENT_ROOT__XSI_SCHEMA_LOCATION = 2;

	/**
	 * The feature id for the '<em><b>Configuration</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int DOCUMENT_ROOT__CONFIGURATION = 3;

	/**
	 * The number of structural features of the '<em>Document Root</em>' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int DOCUMENT_ROOT_FEATURE_COUNT = 4;

	/**
	 * The meta object id for the '{@link oscfg.impl.HWCounterImpl <em>HW Counter</em>}' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see oscfg.impl.HWCounterImpl
	 * @see oscfg.impl.OscfgPackageImpl#getHWCounter()
	 * @generated
	 */
	int HW_COUNTER = 3;

	/**
	 * The feature id for the '<em><b>Name</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int HW_COUNTER__NAME = NAMED_OBJECT__NAME;

	/**
	 * The feature id for the '<em><b>SW Timers</b></em>' containment reference list.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int HW_COUNTER__SW_TIMERS = NAMED_OBJECT_FEATURE_COUNT + 0;

	/**
	 * The feature id for the '<em><b>Disable callback</b></em>' reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int HW_COUNTER__DISABLE_CALLBACK = NAMED_OBJECT_FEATURE_COUNT + 1;

	/**
	 * The feature id for the '<em><b>Enable callback</b></em>' reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int HW_COUNTER__ENABLE_CALLBACK = NAMED_OBJECT_FEATURE_COUNT + 2;

	/**
	 * The feature id for the '<em><b>Get callback</b></em>' reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int HW_COUNTER__GET_CALLBACK = NAMED_OBJECT_FEATURE_COUNT + 3;

	/**
	 * The feature id for the '<em><b>Set callback</b></em>' reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int HW_COUNTER__SET_CALLBACK = NAMED_OBJECT_FEATURE_COUNT + 4;

	/**
	 * The number of structural features of the '<em>HW Counter</em>' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int HW_COUNTER_FEATURE_COUNT = NAMED_OBJECT_FEATURE_COUNT + 5;

	/**
	 * The meta object id for the '{@link oscfg.impl.BaseTaskImpl <em>Base Task</em>}' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see oscfg.impl.BaseTaskImpl
	 * @see oscfg.impl.OscfgPackageImpl#getBaseTask()
	 * @generated
	 */
	int BASE_TASK = 10;

	/**
	 * The feature id for the '<em><b>Name</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int BASE_TASK__NAME = NAMED_OBJECT__NAME;

	/**
	 * The feature id for the '<em><b>Post Message</b></em>' reference list.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int BASE_TASK__POST_MESSAGE = NAMED_OBJECT_FEATURE_COUNT + 0;

	/**
	 * The feature id for the '<em><b>Collect Message</b></em>' reference list.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int BASE_TASK__COLLECT_MESSAGE = NAMED_OBJECT_FEATURE_COUNT + 1;

	/**
	 * The feature id for the '<em><b>Enter Exit Mutex</b></em>' reference list.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int BASE_TASK__ENTER_EXIT_MUTEX = NAMED_OBJECT_FEATURE_COUNT + 2;

	/**
	 * The number of structural features of the '<em>Base Task</em>' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int BASE_TASK_FEATURE_COUNT = NAMED_OBJECT_FEATURE_COUNT + 3;

	/**
	 * The meta object id for the '{@link oscfg.impl.ISRImpl <em>ISR</em>}' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see oscfg.impl.ISRImpl
	 * @see oscfg.impl.OscfgPackageImpl#getISR()
	 * @generated
	 */
	int ISR = 4;

	/**
	 * The feature id for the '<em><b>Name</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ISR__NAME = BASE_TASK__NAME;

	/**
	 * The feature id for the '<em><b>Post Message</b></em>' reference list.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ISR__POST_MESSAGE = BASE_TASK__POST_MESSAGE;

	/**
	 * The feature id for the '<em><b>Collect Message</b></em>' reference list.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ISR__COLLECT_MESSAGE = BASE_TASK__COLLECT_MESSAGE;

	/**
	 * The feature id for the '<em><b>Enter Exit Mutex</b></em>' reference list.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ISR__ENTER_EXIT_MUTEX = BASE_TASK__ENTER_EXIT_MUTEX;

	/**
	 * The feature id for the '<em><b>IPL</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ISR__IPL = BASE_TASK_FEATURE_COUNT + 0;

	/**
	 * The feature id for the '<em><b>Type</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ISR__TYPE = BASE_TASK_FEATURE_COUNT + 1;

	/**
	 * The feature id for the '<em><b>ISR Source</b></em>' reference list.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ISR__ISR_SOURCE = BASE_TASK_FEATURE_COUNT + 2;

	/**
	 * The number of structural features of the '<em>ISR</em>' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int ISR_FEATURE_COUNT = BASE_TASK_FEATURE_COUNT + 3;

	/**
	 * The meta object id for the '{@link oscfg.impl.MessageImpl <em>Message</em>}' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see oscfg.impl.MessageImpl
	 * @see oscfg.impl.OscfgPackageImpl#getMessage()
	 * @generated
	 */
	int MESSAGE = 5;

	/**
	 * The feature id for the '<em><b>Name</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int MESSAGE__NAME = NAMED_OBJECT__NAME;

	/**
	 * The feature id for the '<em><b>Ctype</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int MESSAGE__CTYPE = NAMED_OBJECT_FEATURE_COUNT + 0;

	/**
	 * The feature id for the '<em><b>Queue</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int MESSAGE__QUEUE = NAMED_OBJECT_FEATURE_COUNT + 1;

	/**
	 * The feature id for the '<em><b>Notifies</b></em>' reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int MESSAGE__NOTIFIES = NAMED_OBJECT_FEATURE_COUNT + 2;

	/**
	 * The feature id for the '<em><b>Calls Back</b></em>' reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int MESSAGE__CALLS_BACK = NAMED_OBJECT_FEATURE_COUNT + 3;

	/**
	 * The number of structural features of the '<em>Message</em>' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int MESSAGE_FEATURE_COUNT = NAMED_OBJECT_FEATURE_COUNT + 4;

	/**
	 * The meta object id for the '{@link oscfg.impl.MutexImpl <em>Mutex</em>}' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see oscfg.impl.MutexImpl
	 * @see oscfg.impl.OscfgPackageImpl#getMutex()
	 * @generated
	 */
	int MUTEX = 6;

	/**
	 * The feature id for the '<em><b>Name</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int MUTEX__NAME = NAMED_OBJECT__NAME;

	/**
	 * The number of structural features of the '<em>Mutex</em>' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int MUTEX_FEATURE_COUNT = NAMED_OBJECT_FEATURE_COUNT + 0;

	/**
	 * The meta object id for the '{@link oscfg.impl.ModuleImpl <em>Module</em>}' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see oscfg.impl.ModuleImpl
	 * @see oscfg.impl.OscfgPackageImpl#getModule()
	 * @generated
	 */
	int MODULE = 7;

	/**
	 * The feature id for the '<em><b>Name</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int MODULE__NAME = NAMED_OBJECT__NAME;

	/**
	 * The feature id for the '<em><b>IS Rs</b></em>' containment reference list.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int MODULE__IS_RS = NAMED_OBJECT_FEATURE_COUNT + 0;

	/**
	 * The feature id for the '<em><b>Mutexs</b></em>' containment reference list.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int MODULE__MUTEXS = NAMED_OBJECT_FEATURE_COUNT + 1;

	/**
	 * The feature id for the '<em><b>Messages</b></em>' containment reference list.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int MODULE__MESSAGES = NAMED_OBJECT_FEATURE_COUNT + 2;

	/**
	 * The feature id for the '<em><b>HW Counters</b></em>' containment reference list.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int MODULE__HW_COUNTERS = NAMED_OBJECT_FEATURE_COUNT + 3;

	/**
	 * The feature id for the '<em><b>Callbacks</b></em>' containment reference list.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int MODULE__CALLBACKS = NAMED_OBJECT_FEATURE_COUNT + 4;

	/**
	 * The feature id for the '<em><b>Interrupt Sources</b></em>' containment reference list.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int MODULE__INTERRUPT_SOURCES = NAMED_OBJECT_FEATURE_COUNT + 5;

	/**
	 * The feature id for the '<em><b>Tasks</b></em>' containment reference list.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int MODULE__TASKS = NAMED_OBJECT_FEATURE_COUNT + 6;

	/**
	 * The feature id for the '<em><b>Cooperative Task Groups</b></em>' containment reference list.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int MODULE__COOPERATIVE_TASK_GROUPS = NAMED_OBJECT_FEATURE_COUNT + 7;

	/**
	 * The number of structural features of the '<em>Module</em>' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int MODULE_FEATURE_COUNT = NAMED_OBJECT_FEATURE_COUNT + 8;

	/**
	 * The meta object id for the '{@link oscfg.impl.SWTimerImpl <em>SW Timer</em>}' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see oscfg.impl.SWTimerImpl
	 * @see oscfg.impl.OscfgPackageImpl#getSWTimer()
	 * @generated
	 */
	int SW_TIMER = 8;

	/**
	 * The feature id for the '<em><b>Name</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int SW_TIMER__NAME = NAMED_OBJECT__NAME;

	/**
	 * The feature id for the '<em><b>Activates</b></em>' reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int SW_TIMER__ACTIVATES = NAMED_OBJECT_FEATURE_COUNT + 0;

	/**
	 * The feature id for the '<em><b>Timer callback</b></em>' reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int SW_TIMER__TIMER_CALLBACK = NAMED_OBJECT_FEATURE_COUNT + 1;

	/**
	 * The number of structural features of the '<em>SW Timer</em>' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int SW_TIMER_FEATURE_COUNT = NAMED_OBJECT_FEATURE_COUNT + 2;

	/**
	 * The meta object id for the '{@link oscfg.impl.TaskImpl <em>Task</em>}' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see oscfg.impl.TaskImpl
	 * @see oscfg.impl.OscfgPackageImpl#getTask()
	 * @generated
	 */
	int TASK = 9;

	/**
	 * The feature id for the '<em><b>Name</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int TASK__NAME = BASE_TASK__NAME;

	/**
	 * The feature id for the '<em><b>Post Message</b></em>' reference list.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int TASK__POST_MESSAGE = BASE_TASK__POST_MESSAGE;

	/**
	 * The feature id for the '<em><b>Collect Message</b></em>' reference list.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int TASK__COLLECT_MESSAGE = BASE_TASK__COLLECT_MESSAGE;

	/**
	 * The feature id for the '<em><b>Enter Exit Mutex</b></em>' reference list.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int TASK__ENTER_EXIT_MUTEX = BASE_TASK__ENTER_EXIT_MUTEX;

	/**
	 * The feature id for the '<em><b>Autostarted</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int TASK__AUTOSTARTED = BASE_TASK_FEATURE_COUNT + 0;

	/**
	 * The feature id for the '<em><b>Priority</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int TASK__PRIORITY = BASE_TASK_FEATURE_COUNT + 1;

	/**
	 * The feature id for the '<em><b>Cooperative Group</b></em>' container reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int TASK__COOPERATIVE_GROUP = BASE_TASK_FEATURE_COUNT + 2;

	/**
	 * The number of structural features of the '<em>Task</em>' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int TASK_FEATURE_COUNT = BASE_TASK_FEATURE_COUNT + 3;

	/**
	 * The meta object id for the '{@link oscfg.impl.InterruptSourceImpl <em>Interrupt Source</em>}' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see oscfg.impl.InterruptSourceImpl
	 * @see oscfg.impl.OscfgPackageImpl#getInterruptSource()
	 * @generated
	 */
	int INTERRUPT_SOURCE = 11;

	/**
	 * The feature id for the '<em><b>Source</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int INTERRUPT_SOURCE__SOURCE = 0;

	/**
	 * The feature id for the '<em><b>Source ISR</b></em>' reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int INTERRUPT_SOURCE__SOURCE_ISR = 1;

	/**
	 * The number of structural features of the '<em>Interrupt Source</em>' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int INTERRUPT_SOURCE_FEATURE_COUNT = 2;

	/**
	 * The meta object id for the '{@link oscfg.impl.OSImpl <em>OS</em>}' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see oscfg.impl.OSImpl
	 * @see oscfg.impl.OscfgPackageImpl#getOS()
	 * @generated
	 */
	int OS = 12;

	/**
	 * The feature id for the '<em><b>Target</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int OS__TARGET = 0;

	/**
	 * The feature id for the '<em><b>Modules</b></em>' containment reference list.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int OS__MODULES = 1;

	/**
	 * The feature id for the '<em><b>Error Hook</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int OS__ERROR_HOOK = 2;

	/**
	 * The feature id for the '<em><b>Strict Error Checks</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int OS__STRICT_ERROR_CHECKS = 3;

	/**
	 * The feature id for the '<em><b>Clear Stack</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int OS__CLEAR_STACK = 4;

	/**
	 * The number of structural features of the '<em>OS</em>' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int OS_FEATURE_COUNT = 5;

	/**
	 * The meta object id for the '{@link oscfg.impl.CooperativeGroupImpl <em>Cooperative Group</em>}' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see oscfg.impl.CooperativeGroupImpl
	 * @see oscfg.impl.OscfgPackageImpl#getCooperativeGroup()
	 * @generated
	 */
	int COOPERATIVE_GROUP = 13;

	/**
	 * The feature id for the '<em><b>Name</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int COOPERATIVE_GROUP__NAME = NAMED_OBJECT__NAME;

	/**
	 * The feature id for the '<em><b>Cooperative Tasks</b></em>' containment reference list.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int COOPERATIVE_GROUP__COOPERATIVE_TASKS = NAMED_OBJECT_FEATURE_COUNT + 0;

	/**
	 * The number of structural features of the '<em>Cooperative Group</em>' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int COOPERATIVE_GROUP_FEATURE_COUNT = NAMED_OBJECT_FEATURE_COUNT + 1;

	/**
	 * The meta object id for the '{@link oscfg.impl.PosterImpl <em>Poster</em>}' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see oscfg.impl.PosterImpl
	 * @see oscfg.impl.OscfgPackageImpl#getPoster()
	 * @generated
	 */
	int POSTER = 15;

	/**
	 * The feature id for the '<em><b>Post Message</b></em>' reference list.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int POSTER__POST_MESSAGE = 0;

	/**
	 * The number of structural features of the '<em>Poster</em>' class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @ordered
	 */
	int POSTER_FEATURE_COUNT = 1;

	/**
	 * The meta object id for the '{@link oscfg.AutostartedType <em>Autostarted Type</em>}' enum.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see oscfg.AutostartedType
	 * @see oscfg.impl.OscfgPackageImpl#getAutostartedType()
	 * @generated
	 */
	int AUTOSTARTED_TYPE = 16;

	/**
	 * The meta object id for the '{@link oscfg.TypeType <em>Type Type</em>}' enum.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see oscfg.TypeType
	 * @see oscfg.impl.OscfgPackageImpl#getTypeType()
	 * @generated
	 */
	int TYPE_TYPE = 17;

	/**
	 * The meta object id for the '{@link oscfg.VectorType <em>Vector Type</em>}' enum.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see oscfg.VectorType
	 * @see oscfg.impl.OscfgPackageImpl#getVectorType()
	 * @generated
	 */
	int VECTOR_TYPE = 18;

	/**
	 * The meta object id for the '{@link oscfg.TargetTypes <em>Target Types</em>}' enum.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see oscfg.TargetTypes
	 * @see oscfg.impl.OscfgPackageImpl#getTargetTypes()
	 * @generated
	 */
	int TARGET_TYPES = 19;

	/**
	 * The meta object id for the '<em>Autostarted Type Object</em>' data type.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see org.eclipse.emf.common.util.Enumerator
	 * @see oscfg.impl.OscfgPackageImpl#getAutostartedTypeObject()
	 * @generated
	 */
	int AUTOSTARTED_TYPE_OBJECT = 20;

	/**
	 * The meta object id for the '<em>Queue Type</em>' data type.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see oscfg.impl.OscfgPackageImpl#getQueueType()
	 * @generated
	 */
	int QUEUE_TYPE = 24;

	/**
	 * The meta object id for the '<em>Task Priority Type</em>' data type.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see oscfg.impl.OscfgPackageImpl#getTaskPriorityType()
	 * @generated
	 */
	int TASK_PRIORITY_TYPE = 25;

	/**
	 * The meta object id for the '<em>Type Type Object</em>' data type.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see org.eclipse.emf.common.util.Enumerator
	 * @see oscfg.impl.OscfgPackageImpl#getTypeTypeObject()
	 * @generated
	 */
	int TYPE_TYPE_OBJECT = 21;

	/**
	 * The meta object id for the '<em>Vector Type Object</em>' data type.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see org.eclipse.emf.common.util.Enumerator
	 * @see oscfg.impl.OscfgPackageImpl#getVectorTypeObject()
	 * @generated
	 */
	int VECTOR_TYPE_OBJECT = 22;


	/**
	 * The meta object id for the '<em>IPL Type</em>' data type.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see oscfg.impl.OscfgPackageImpl#getIPLType()
	 * @generated
	 */
	int IPL_TYPE = 23;


	/**
	 * Returns the meta object for class '{@link oscfg.CallbackFunction <em>Callback Function</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for class '<em>Callback Function</em>'.
	 * @see oscfg.CallbackFunction
	 * @generated
	 */
	EClass getCallbackFunction();

	/**
	 * Returns the meta object for class '{@link oscfg.Configuration <em>Configuration</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for class '<em>Configuration</em>'.
	 * @see oscfg.Configuration
	 * @generated
	 */
	EClass getConfiguration();

	/**
	 * Returns the meta object for the containment reference '{@link oscfg.Configuration#getOS <em>OS</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the containment reference '<em>OS</em>'.
	 * @see oscfg.Configuration#getOS()
	 * @see #getConfiguration()
	 * @generated
	 */
	EReference getConfiguration_OS();

	/**
	 * Returns the meta object for the attribute '{@link oscfg.Configuration#getVersion <em>Version</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the attribute '<em>Version</em>'.
	 * @see oscfg.Configuration#getVersion()
	 * @see #getConfiguration()
	 * @generated
	 */
	EAttribute getConfiguration_Version();

	/**
	 * Returns the meta object for class '{@link oscfg.DocumentRoot <em>Document Root</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for class '<em>Document Root</em>'.
	 * @see oscfg.DocumentRoot
	 * @generated
	 */
	EClass getDocumentRoot();

	/**
	 * Returns the meta object for the attribute list '{@link oscfg.DocumentRoot#getMixed <em>Mixed</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the attribute list '<em>Mixed</em>'.
	 * @see oscfg.DocumentRoot#getMixed()
	 * @see #getDocumentRoot()
	 * @generated
	 */
	EAttribute getDocumentRoot_Mixed();

	/**
	 * Returns the meta object for the map '{@link oscfg.DocumentRoot#getXMLNSPrefixMap <em>XMLNS Prefix Map</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the map '<em>XMLNS Prefix Map</em>'.
	 * @see oscfg.DocumentRoot#getXMLNSPrefixMap()
	 * @see #getDocumentRoot()
	 * @generated
	 */
	EReference getDocumentRoot_XMLNSPrefixMap();

	/**
	 * Returns the meta object for the map '{@link oscfg.DocumentRoot#getXSISchemaLocation <em>XSI Schema Location</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the map '<em>XSI Schema Location</em>'.
	 * @see oscfg.DocumentRoot#getXSISchemaLocation()
	 * @see #getDocumentRoot()
	 * @generated
	 */
	EReference getDocumentRoot_XSISchemaLocation();

	/**
	 * Returns the meta object for the containment reference '{@link oscfg.DocumentRoot#getConfiguration <em>Configuration</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the containment reference '<em>Configuration</em>'.
	 * @see oscfg.DocumentRoot#getConfiguration()
	 * @see #getDocumentRoot()
	 * @generated
	 */
	EReference getDocumentRoot_Configuration();

	/**
	 * Returns the meta object for class '{@link oscfg.HWCounter <em>HW Counter</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for class '<em>HW Counter</em>'.
	 * @see oscfg.HWCounter
	 * @generated
	 */
	EClass getHWCounter();

	/**
	 * Returns the meta object for the containment reference list '{@link oscfg.HWCounter#getSWTimers <em>SW Timers</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the containment reference list '<em>SW Timers</em>'.
	 * @see oscfg.HWCounter#getSWTimers()
	 * @see #getHWCounter()
	 * @generated
	 */
	EReference getHWCounter_SWTimers();

	/**
	 * Returns the meta object for the reference '{@link oscfg.HWCounter#getDisable_callback <em>Disable callback</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the reference '<em>Disable callback</em>'.
	 * @see oscfg.HWCounter#getDisable_callback()
	 * @see #getHWCounter()
	 * @generated
	 */
	EReference getHWCounter_Disable_callback();

	/**
	 * Returns the meta object for the reference '{@link oscfg.HWCounter#getEnable_callback <em>Enable callback</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the reference '<em>Enable callback</em>'.
	 * @see oscfg.HWCounter#getEnable_callback()
	 * @see #getHWCounter()
	 * @generated
	 */
	EReference getHWCounter_Enable_callback();

	/**
	 * Returns the meta object for the reference '{@link oscfg.HWCounter#getGet_callback <em>Get callback</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the reference '<em>Get callback</em>'.
	 * @see oscfg.HWCounter#getGet_callback()
	 * @see #getHWCounter()
	 * @generated
	 */
	EReference getHWCounter_Get_callback();

	/**
	 * Returns the meta object for the reference '{@link oscfg.HWCounter#getSet_callback <em>Set callback</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the reference '<em>Set callback</em>'.
	 * @see oscfg.HWCounter#getSet_callback()
	 * @see #getHWCounter()
	 * @generated
	 */
	EReference getHWCounter_Set_callback();

	/**
	 * Returns the meta object for class '{@link oscfg.ISR <em>ISR</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for class '<em>ISR</em>'.
	 * @see oscfg.ISR
	 * @generated
	 */
	EClass getISR();

	/**
	 * Returns the meta object for the attribute '{@link oscfg.ISR#getIPL <em>IPL</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the attribute '<em>IPL</em>'.
	 * @see oscfg.ISR#getIPL()
	 * @see #getISR()
	 * @generated
	 */
	EAttribute getISR_IPL();

	/**
	 * Returns the meta object for the attribute '{@link oscfg.ISR#getType <em>Type</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the attribute '<em>Type</em>'.
	 * @see oscfg.ISR#getType()
	 * @see #getISR()
	 * @generated
	 */
	EAttribute getISR_Type();

	/**
	 * Returns the meta object for the reference list '{@link oscfg.ISR#getISRSource <em>ISR Source</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the reference list '<em>ISR Source</em>'.
	 * @see oscfg.ISR#getISRSource()
	 * @see #getISR()
	 * @generated
	 */
	EReference getISR_ISRSource();

	/**
	 * Returns the meta object for class '{@link oscfg.Message <em>Message</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for class '<em>Message</em>'.
	 * @see oscfg.Message
	 * @generated
	 */
	EClass getMessage();

	/**
	 * Returns the meta object for the attribute '{@link oscfg.Message#getCtype <em>Ctype</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the attribute '<em>Ctype</em>'.
	 * @see oscfg.Message#getCtype()
	 * @see #getMessage()
	 * @generated
	 */
	EAttribute getMessage_Ctype();

	/**
	 * Returns the meta object for the attribute '{@link oscfg.Message#getQueue <em>Queue</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the attribute '<em>Queue</em>'.
	 * @see oscfg.Message#getQueue()
	 * @see #getMessage()
	 * @generated
	 */
	EAttribute getMessage_Queue();

	/**
	 * Returns the meta object for the reference '{@link oscfg.Message#getNotifies <em>Notifies</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the reference '<em>Notifies</em>'.
	 * @see oscfg.Message#getNotifies()
	 * @see #getMessage()
	 * @generated
	 */
	EReference getMessage_Notifies();

	/**
	 * Returns the meta object for the reference '{@link oscfg.Message#getCallsBack <em>Calls Back</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the reference '<em>Calls Back</em>'.
	 * @see oscfg.Message#getCallsBack()
	 * @see #getMessage()
	 * @generated
	 */
	EReference getMessage_CallsBack();

	/**
	 * Returns the meta object for class '{@link oscfg.Mutex <em>Mutex</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for class '<em>Mutex</em>'.
	 * @see oscfg.Mutex
	 * @generated
	 */
	EClass getMutex();

	/**
	 * Returns the meta object for class '{@link oscfg.Module <em>Module</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for class '<em>Module</em>'.
	 * @see oscfg.Module
	 * @generated
	 */
	EClass getModule();

	/**
	 * Returns the meta object for the containment reference list '{@link oscfg.Module#getISRs <em>IS Rs</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the containment reference list '<em>IS Rs</em>'.
	 * @see oscfg.Module#getISRs()
	 * @see #getModule()
	 * @generated
	 */
	EReference getModule_ISRs();

	/**
	 * Returns the meta object for the containment reference list '{@link oscfg.Module#getMutexs <em>Mutexs</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the containment reference list '<em>Mutexs</em>'.
	 * @see oscfg.Module#getMutexs()
	 * @see #getModule()
	 * @generated
	 */
	EReference getModule_Mutexs();

	/**
	 * Returns the meta object for the containment reference list '{@link oscfg.Module#getMessages <em>Messages</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the containment reference list '<em>Messages</em>'.
	 * @see oscfg.Module#getMessages()
	 * @see #getModule()
	 * @generated
	 */
	EReference getModule_Messages();

	/**
	 * Returns the meta object for the containment reference list '{@link oscfg.Module#getHWCounters <em>HW Counters</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the containment reference list '<em>HW Counters</em>'.
	 * @see oscfg.Module#getHWCounters()
	 * @see #getModule()
	 * @generated
	 */
	EReference getModule_HWCounters();

	/**
	 * Returns the meta object for the containment reference list '{@link oscfg.Module#getCallbacks <em>Callbacks</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the containment reference list '<em>Callbacks</em>'.
	 * @see oscfg.Module#getCallbacks()
	 * @see #getModule()
	 * @generated
	 */
	EReference getModule_Callbacks();

	/**
	 * Returns the meta object for the containment reference list '{@link oscfg.Module#getInterruptSources <em>Interrupt Sources</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the containment reference list '<em>Interrupt Sources</em>'.
	 * @see oscfg.Module#getInterruptSources()
	 * @see #getModule()
	 * @generated
	 */
	EReference getModule_InterruptSources();

	/**
	 * Returns the meta object for the containment reference list '{@link oscfg.Module#getTasks <em>Tasks</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the containment reference list '<em>Tasks</em>'.
	 * @see oscfg.Module#getTasks()
	 * @see #getModule()
	 * @generated
	 */
	EReference getModule_Tasks();

	/**
	 * Returns the meta object for the containment reference list '{@link oscfg.Module#getCooperativeTaskGroups <em>Cooperative Task Groups</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the containment reference list '<em>Cooperative Task Groups</em>'.
	 * @see oscfg.Module#getCooperativeTaskGroups()
	 * @see #getModule()
	 * @generated
	 */
	EReference getModule_CooperativeTaskGroups();

	/**
	 * Returns the meta object for class '{@link oscfg.SWTimer <em>SW Timer</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for class '<em>SW Timer</em>'.
	 * @see oscfg.SWTimer
	 * @generated
	 */
	EClass getSWTimer();

	/**
	 * Returns the meta object for the reference '{@link oscfg.SWTimer#getActivates <em>Activates</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the reference '<em>Activates</em>'.
	 * @see oscfg.SWTimer#getActivates()
	 * @see #getSWTimer()
	 * @generated
	 */
	EReference getSWTimer_Activates();

	/**
	 * Returns the meta object for the reference '{@link oscfg.SWTimer#getTimer_callback <em>Timer callback</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the reference '<em>Timer callback</em>'.
	 * @see oscfg.SWTimer#getTimer_callback()
	 * @see #getSWTimer()
	 * @generated
	 */
	EReference getSWTimer_Timer_callback();

	/**
	 * Returns the meta object for class '{@link oscfg.Task <em>Task</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for class '<em>Task</em>'.
	 * @see oscfg.Task
	 * @generated
	 */
	EClass getTask();

	/**
	 * Returns the meta object for the attribute '{@link oscfg.Task#getAutostarted <em>Autostarted</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the attribute '<em>Autostarted</em>'.
	 * @see oscfg.Task#getAutostarted()
	 * @see #getTask()
	 * @generated
	 */
	EAttribute getTask_Autostarted();

	/**
	 * Returns the meta object for the attribute '{@link oscfg.Task#getPriority <em>Priority</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the attribute '<em>Priority</em>'.
	 * @see oscfg.Task#getPriority()
	 * @see #getTask()
	 * @generated
	 */
	EAttribute getTask_Priority();

	/**
	 * Returns the meta object for the container reference '{@link oscfg.Task#getCooperativeGroup <em>Cooperative Group</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the container reference '<em>Cooperative Group</em>'.
	 * @see oscfg.Task#getCooperativeGroup()
	 * @see #getTask()
	 * @generated
	 */
	EReference getTask_CooperativeGroup();

	/**
	 * Returns the meta object for class '{@link oscfg.BaseTask <em>Base Task</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for class '<em>Base Task</em>'.
	 * @see oscfg.BaseTask
	 * @generated
	 */
	EClass getBaseTask();

	/**
	 * Returns the meta object for the reference list '{@link oscfg.BaseTask#getCollectMessage <em>Collect Message</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the reference list '<em>Collect Message</em>'.
	 * @see oscfg.BaseTask#getCollectMessage()
	 * @see #getBaseTask()
	 * @generated
	 */
	EReference getBaseTask_CollectMessage();

	/**
	 * Returns the meta object for the reference list '{@link oscfg.BaseTask#getEnterExitMutex <em>Enter Exit Mutex</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the reference list '<em>Enter Exit Mutex</em>'.
	 * @see oscfg.BaseTask#getEnterExitMutex()
	 * @see #getBaseTask()
	 * @generated
	 */
	EReference getBaseTask_EnterExitMutex();

	/**
	 * Returns the meta object for class '{@link oscfg.InterruptSource <em>Interrupt Source</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for class '<em>Interrupt Source</em>'.
	 * @see oscfg.InterruptSource
	 * @generated
	 */
	EClass getInterruptSource();

	/**
	 * Returns the meta object for the attribute '{@link oscfg.InterruptSource#getSource <em>Source</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the attribute '<em>Source</em>'.
	 * @see oscfg.InterruptSource#getSource()
	 * @see #getInterruptSource()
	 * @generated
	 */
	EAttribute getInterruptSource_Source();

	/**
	 * Returns the meta object for the reference '{@link oscfg.InterruptSource#getSourceISR <em>Source ISR</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the reference '<em>Source ISR</em>'.
	 * @see oscfg.InterruptSource#getSourceISR()
	 * @see #getInterruptSource()
	 * @generated
	 */
	EReference getInterruptSource_SourceISR();

	/**
	 * Returns the meta object for class '{@link oscfg.OS <em>OS</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for class '<em>OS</em>'.
	 * @see oscfg.OS
	 * @generated
	 */
	EClass getOS();

	/**
	 * Returns the meta object for the attribute '{@link oscfg.OS#getTarget <em>Target</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the attribute '<em>Target</em>'.
	 * @see oscfg.OS#getTarget()
	 * @see #getOS()
	 * @generated
	 */
	EAttribute getOS_Target();

	/**
	 * Returns the meta object for the containment reference list '{@link oscfg.OS#getModules <em>Modules</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the containment reference list '<em>Modules</em>'.
	 * @see oscfg.OS#getModules()
	 * @see #getOS()
	 * @generated
	 */
	EReference getOS_Modules();

	/**
	 * Returns the meta object for the attribute '{@link oscfg.OS#isErrorHook <em>Error Hook</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the attribute '<em>Error Hook</em>'.
	 * @see oscfg.OS#isErrorHook()
	 * @see #getOS()
	 * @generated
	 */
	EAttribute getOS_ErrorHook();

	/**
	 * Returns the meta object for the attribute '{@link oscfg.OS#isStrictErrorChecks <em>Strict Error Checks</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the attribute '<em>Strict Error Checks</em>'.
	 * @see oscfg.OS#isStrictErrorChecks()
	 * @see #getOS()
	 * @generated
	 */
	EAttribute getOS_StrictErrorChecks();

	/**
	 * Returns the meta object for the attribute '{@link oscfg.OS#isClearStack <em>Clear Stack</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the attribute '<em>Clear Stack</em>'.
	 * @see oscfg.OS#isClearStack()
	 * @see #getOS()
	 * @generated
	 */
	EAttribute getOS_ClearStack();

	/**
	 * Returns the meta object for class '{@link oscfg.CooperativeGroup <em>Cooperative Group</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for class '<em>Cooperative Group</em>'.
	 * @see oscfg.CooperativeGroup
	 * @generated
	 */
	EClass getCooperativeGroup();

	/**
	 * Returns the meta object for the containment reference list '{@link oscfg.CooperativeGroup#getCooperativeTasks <em>Cooperative Tasks</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the containment reference list '<em>Cooperative Tasks</em>'.
	 * @see oscfg.CooperativeGroup#getCooperativeTasks()
	 * @see #getCooperativeGroup()
	 * @generated
	 */
	EReference getCooperativeGroup_CooperativeTasks();

	/**
	 * Returns the meta object for class '{@link oscfg.NamedObject <em>Named Object</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for class '<em>Named Object</em>'.
	 * @see oscfg.NamedObject
	 * @generated
	 */
	EClass getNamedObject();

	/**
	 * Returns the meta object for the attribute '{@link oscfg.NamedObject#getName <em>Name</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the attribute '<em>Name</em>'.
	 * @see oscfg.NamedObject#getName()
	 * @see #getNamedObject()
	 * @generated
	 */
	EAttribute getNamedObject_Name();

	/**
	 * Returns the meta object for class '{@link oscfg.Poster <em>Poster</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for class '<em>Poster</em>'.
	 * @see oscfg.Poster
	 * @generated
	 */
	EClass getPoster();

	/**
	 * Returns the meta object for the reference list '{@link oscfg.Poster#getPostMessage <em>Post Message</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for the reference list '<em>Post Message</em>'.
	 * @see oscfg.Poster#getPostMessage()
	 * @see #getPoster()
	 * @generated
	 */
	EReference getPoster_PostMessage();

	/**
	 * Returns the meta object for enum '{@link oscfg.AutostartedType <em>Autostarted Type</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for enum '<em>Autostarted Type</em>'.
	 * @see oscfg.AutostartedType
	 * @generated
	 */
	EEnum getAutostartedType();

	/**
	 * Returns the meta object for enum '{@link oscfg.TypeType <em>Type Type</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for enum '<em>Type Type</em>'.
	 * @see oscfg.TypeType
	 * @generated
	 */
	EEnum getTypeType();

	/**
	 * Returns the meta object for enum '{@link oscfg.VectorType <em>Vector Type</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for enum '<em>Vector Type</em>'.
	 * @see oscfg.VectorType
	 * @generated
	 */
	EEnum getVectorType();

	/**
	 * Returns the meta object for enum '{@link oscfg.TargetTypes <em>Target Types</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for enum '<em>Target Types</em>'.
	 * @see oscfg.TargetTypes
	 * @generated
	 */
	EEnum getTargetTypes();

	/**
	 * Returns the meta object for data type '{@link org.eclipse.emf.common.util.Enumerator <em>Autostarted Type Object</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for data type '<em>Autostarted Type Object</em>'.
	 * @see org.eclipse.emf.common.util.Enumerator
	 * @model instanceClass="org.eclipse.emf.common.util.Enumerator"
	 * @generated
	 */
	EDataType getAutostartedTypeObject();

	/**
	 * Returns the meta object for data type '<em>Queue Type</em>'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for data type '<em>Queue Type</em>'.
	 * @model instanceClass="int"
	 *        extendedMetaData="name='QueueType' baseType='int' minInclusive='0' maxInclusive='2147483647'"
	 * @generated
	 */
	EDataType getQueueType();

	/**
	 * Returns the meta object for data type '<em>Task Priority Type</em>'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for data type '<em>Task Priority Type</em>'.
	 * @model instanceClass="int"
	 *        extendedMetaData="name='TaskPriorityType' baseType='int' minInclusive='1' maxInclusive='2147483647'"
	 * @generated
	 */
	EDataType getTaskPriorityType();

	/**
	 * Returns the meta object for data type '{@link org.eclipse.emf.common.util.Enumerator <em>Type Type Object</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for data type '<em>Type Type Object</em>'.
	 * @see org.eclipse.emf.common.util.Enumerator
	 * @model instanceClass="org.eclipse.emf.common.util.Enumerator"
	 * @generated
	 */
	EDataType getTypeTypeObject();

	/**
	 * Returns the meta object for data type '{@link org.eclipse.emf.common.util.Enumerator <em>Vector Type Object</em>}'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for data type '<em>Vector Type Object</em>'.
	 * @see org.eclipse.emf.common.util.Enumerator
	 * @model instanceClass="org.eclipse.emf.common.util.Enumerator"
	 * @generated
	 */
	EDataType getVectorTypeObject();

	/**
	 * Returns the meta object for data type '<em>IPL Type</em>'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the meta object for data type '<em>IPL Type</em>'.
	 * @model instanceClass="int"
	 *        extendedMetaData="name='IPLType' baseType='int' minInclusive='1' maxInclusive='16'"
	 * @generated
	 */
	EDataType getIPLType();

	/**
	 * Returns the factory that creates the instances of the model.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the factory that creates the instances of the model.
	 * @generated
	 */
	OscfgFactory getOscfgFactory();

	/**
	 * <!-- begin-user-doc -->
	 * Defines literals for the meta objects that represent
	 * <ul>
	 *   <li>each class,</li>
	 *   <li>each feature of each class,</li>
	 *   <li>each enum,</li>
	 *   <li>and each data type</li>
	 * </ul>
	 * <!-- end-user-doc -->
	 * @generated
	 */
	interface Literals {
		/**
		 * The meta object literal for the '{@link oscfg.impl.CallbackFunctionImpl <em>Callback Function</em>}' class.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @see oscfg.impl.CallbackFunctionImpl
		 * @see oscfg.impl.OscfgPackageImpl#getCallbackFunction()
		 * @generated
		 */
		EClass CALLBACK_FUNCTION = eINSTANCE.getCallbackFunction();

		/**
		 * The meta object literal for the '{@link oscfg.impl.ConfigurationImpl <em>Configuration</em>}' class.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @see oscfg.impl.ConfigurationImpl
		 * @see oscfg.impl.OscfgPackageImpl#getConfiguration()
		 * @generated
		 */
		EClass CONFIGURATION = eINSTANCE.getConfiguration();

		/**
		 * The meta object literal for the '<em><b>OS</b></em>' containment reference feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EReference CONFIGURATION__OS = eINSTANCE.getConfiguration_OS();

		/**
		 * The meta object literal for the '<em><b>Version</b></em>' attribute feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EAttribute CONFIGURATION__VERSION = eINSTANCE.getConfiguration_Version();

		/**
		 * The meta object literal for the '{@link oscfg.impl.DocumentRootImpl <em>Document Root</em>}' class.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @see oscfg.impl.DocumentRootImpl
		 * @see oscfg.impl.OscfgPackageImpl#getDocumentRoot()
		 * @generated
		 */
		EClass DOCUMENT_ROOT = eINSTANCE.getDocumentRoot();

		/**
		 * The meta object literal for the '<em><b>Mixed</b></em>' attribute list feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EAttribute DOCUMENT_ROOT__MIXED = eINSTANCE.getDocumentRoot_Mixed();

		/**
		 * The meta object literal for the '<em><b>XMLNS Prefix Map</b></em>' map feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EReference DOCUMENT_ROOT__XMLNS_PREFIX_MAP = eINSTANCE.getDocumentRoot_XMLNSPrefixMap();

		/**
		 * The meta object literal for the '<em><b>XSI Schema Location</b></em>' map feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EReference DOCUMENT_ROOT__XSI_SCHEMA_LOCATION = eINSTANCE.getDocumentRoot_XSISchemaLocation();

		/**
		 * The meta object literal for the '<em><b>Configuration</b></em>' containment reference feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EReference DOCUMENT_ROOT__CONFIGURATION = eINSTANCE.getDocumentRoot_Configuration();

		/**
		 * The meta object literal for the '{@link oscfg.impl.HWCounterImpl <em>HW Counter</em>}' class.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @see oscfg.impl.HWCounterImpl
		 * @see oscfg.impl.OscfgPackageImpl#getHWCounter()
		 * @generated
		 */
		EClass HW_COUNTER = eINSTANCE.getHWCounter();

		/**
		 * The meta object literal for the '<em><b>SW Timers</b></em>' containment reference list feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EReference HW_COUNTER__SW_TIMERS = eINSTANCE.getHWCounter_SWTimers();

		/**
		 * The meta object literal for the '<em><b>Disable callback</b></em>' reference feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EReference HW_COUNTER__DISABLE_CALLBACK = eINSTANCE.getHWCounter_Disable_callback();

		/**
		 * The meta object literal for the '<em><b>Enable callback</b></em>' reference feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EReference HW_COUNTER__ENABLE_CALLBACK = eINSTANCE.getHWCounter_Enable_callback();

		/**
		 * The meta object literal for the '<em><b>Get callback</b></em>' reference feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EReference HW_COUNTER__GET_CALLBACK = eINSTANCE.getHWCounter_Get_callback();

		/**
		 * The meta object literal for the '<em><b>Set callback</b></em>' reference feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EReference HW_COUNTER__SET_CALLBACK = eINSTANCE.getHWCounter_Set_callback();

		/**
		 * The meta object literal for the '{@link oscfg.impl.ISRImpl <em>ISR</em>}' class.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @see oscfg.impl.ISRImpl
		 * @see oscfg.impl.OscfgPackageImpl#getISR()
		 * @generated
		 */
		EClass ISR = eINSTANCE.getISR();

		/**
		 * The meta object literal for the '<em><b>IPL</b></em>' attribute feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EAttribute ISR__IPL = eINSTANCE.getISR_IPL();

		/**
		 * The meta object literal for the '<em><b>Type</b></em>' attribute feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EAttribute ISR__TYPE = eINSTANCE.getISR_Type();

		/**
		 * The meta object literal for the '<em><b>ISR Source</b></em>' reference list feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EReference ISR__ISR_SOURCE = eINSTANCE.getISR_ISRSource();

		/**
		 * The meta object literal for the '{@link oscfg.impl.MessageImpl <em>Message</em>}' class.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @see oscfg.impl.MessageImpl
		 * @see oscfg.impl.OscfgPackageImpl#getMessage()
		 * @generated
		 */
		EClass MESSAGE = eINSTANCE.getMessage();

		/**
		 * The meta object literal for the '<em><b>Ctype</b></em>' attribute feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EAttribute MESSAGE__CTYPE = eINSTANCE.getMessage_Ctype();

		/**
		 * The meta object literal for the '<em><b>Queue</b></em>' attribute feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EAttribute MESSAGE__QUEUE = eINSTANCE.getMessage_Queue();

		/**
		 * The meta object literal for the '<em><b>Notifies</b></em>' reference feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EReference MESSAGE__NOTIFIES = eINSTANCE.getMessage_Notifies();

		/**
		 * The meta object literal for the '<em><b>Calls Back</b></em>' reference feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EReference MESSAGE__CALLS_BACK = eINSTANCE.getMessage_CallsBack();

		/**
		 * The meta object literal for the '{@link oscfg.impl.MutexImpl <em>Mutex</em>}' class.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @see oscfg.impl.MutexImpl
		 * @see oscfg.impl.OscfgPackageImpl#getMutex()
		 * @generated
		 */
		EClass MUTEX = eINSTANCE.getMutex();

		/**
		 * The meta object literal for the '{@link oscfg.impl.ModuleImpl <em>Module</em>}' class.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @see oscfg.impl.ModuleImpl
		 * @see oscfg.impl.OscfgPackageImpl#getModule()
		 * @generated
		 */
		EClass MODULE = eINSTANCE.getModule();

		/**
		 * The meta object literal for the '<em><b>IS Rs</b></em>' containment reference list feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EReference MODULE__IS_RS = eINSTANCE.getModule_ISRs();

		/**
		 * The meta object literal for the '<em><b>Mutexs</b></em>' containment reference list feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EReference MODULE__MUTEXS = eINSTANCE.getModule_Mutexs();

		/**
		 * The meta object literal for the '<em><b>Messages</b></em>' containment reference list feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EReference MODULE__MESSAGES = eINSTANCE.getModule_Messages();

		/**
		 * The meta object literal for the '<em><b>HW Counters</b></em>' containment reference list feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EReference MODULE__HW_COUNTERS = eINSTANCE.getModule_HWCounters();

		/**
		 * The meta object literal for the '<em><b>Callbacks</b></em>' containment reference list feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EReference MODULE__CALLBACKS = eINSTANCE.getModule_Callbacks();

		/**
		 * The meta object literal for the '<em><b>Interrupt Sources</b></em>' containment reference list feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EReference MODULE__INTERRUPT_SOURCES = eINSTANCE.getModule_InterruptSources();

		/**
		 * The meta object literal for the '<em><b>Tasks</b></em>' containment reference list feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EReference MODULE__TASKS = eINSTANCE.getModule_Tasks();

		/**
		 * The meta object literal for the '<em><b>Cooperative Task Groups</b></em>' containment reference list feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EReference MODULE__COOPERATIVE_TASK_GROUPS = eINSTANCE.getModule_CooperativeTaskGroups();

		/**
		 * The meta object literal for the '{@link oscfg.impl.SWTimerImpl <em>SW Timer</em>}' class.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @see oscfg.impl.SWTimerImpl
		 * @see oscfg.impl.OscfgPackageImpl#getSWTimer()
		 * @generated
		 */
		EClass SW_TIMER = eINSTANCE.getSWTimer();

		/**
		 * The meta object literal for the '<em><b>Activates</b></em>' reference feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EReference SW_TIMER__ACTIVATES = eINSTANCE.getSWTimer_Activates();

		/**
		 * The meta object literal for the '<em><b>Timer callback</b></em>' reference feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EReference SW_TIMER__TIMER_CALLBACK = eINSTANCE.getSWTimer_Timer_callback();

		/**
		 * The meta object literal for the '{@link oscfg.impl.TaskImpl <em>Task</em>}' class.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @see oscfg.impl.TaskImpl
		 * @see oscfg.impl.OscfgPackageImpl#getTask()
		 * @generated
		 */
		EClass TASK = eINSTANCE.getTask();

		/**
		 * The meta object literal for the '<em><b>Autostarted</b></em>' attribute feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EAttribute TASK__AUTOSTARTED = eINSTANCE.getTask_Autostarted();

		/**
		 * The meta object literal for the '<em><b>Priority</b></em>' attribute feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EAttribute TASK__PRIORITY = eINSTANCE.getTask_Priority();

		/**
		 * The meta object literal for the '<em><b>Cooperative Group</b></em>' container reference feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EReference TASK__COOPERATIVE_GROUP = eINSTANCE.getTask_CooperativeGroup();

		/**
		 * The meta object literal for the '{@link oscfg.impl.BaseTaskImpl <em>Base Task</em>}' class.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @see oscfg.impl.BaseTaskImpl
		 * @see oscfg.impl.OscfgPackageImpl#getBaseTask()
		 * @generated
		 */
		EClass BASE_TASK = eINSTANCE.getBaseTask();

		/**
		 * The meta object literal for the '<em><b>Collect Message</b></em>' reference list feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EReference BASE_TASK__COLLECT_MESSAGE = eINSTANCE.getBaseTask_CollectMessage();

		/**
		 * The meta object literal for the '<em><b>Enter Exit Mutex</b></em>' reference list feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EReference BASE_TASK__ENTER_EXIT_MUTEX = eINSTANCE.getBaseTask_EnterExitMutex();

		/**
		 * The meta object literal for the '{@link oscfg.impl.InterruptSourceImpl <em>Interrupt Source</em>}' class.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @see oscfg.impl.InterruptSourceImpl
		 * @see oscfg.impl.OscfgPackageImpl#getInterruptSource()
		 * @generated
		 */
		EClass INTERRUPT_SOURCE = eINSTANCE.getInterruptSource();

		/**
		 * The meta object literal for the '<em><b>Source</b></em>' attribute feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EAttribute INTERRUPT_SOURCE__SOURCE = eINSTANCE.getInterruptSource_Source();

		/**
		 * The meta object literal for the '<em><b>Source ISR</b></em>' reference feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EReference INTERRUPT_SOURCE__SOURCE_ISR = eINSTANCE.getInterruptSource_SourceISR();

		/**
		 * The meta object literal for the '{@link oscfg.impl.OSImpl <em>OS</em>}' class.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @see oscfg.impl.OSImpl
		 * @see oscfg.impl.OscfgPackageImpl#getOS()
		 * @generated
		 */
		EClass OS = eINSTANCE.getOS();

		/**
		 * The meta object literal for the '<em><b>Target</b></em>' attribute feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EAttribute OS__TARGET = eINSTANCE.getOS_Target();

		/**
		 * The meta object literal for the '<em><b>Modules</b></em>' containment reference list feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EReference OS__MODULES = eINSTANCE.getOS_Modules();

		/**
		 * The meta object literal for the '<em><b>Error Hook</b></em>' attribute feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EAttribute OS__ERROR_HOOK = eINSTANCE.getOS_ErrorHook();

		/**
		 * The meta object literal for the '<em><b>Strict Error Checks</b></em>' attribute feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EAttribute OS__STRICT_ERROR_CHECKS = eINSTANCE.getOS_StrictErrorChecks();

		/**
		 * The meta object literal for the '<em><b>Clear Stack</b></em>' attribute feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EAttribute OS__CLEAR_STACK = eINSTANCE.getOS_ClearStack();

		/**
		 * The meta object literal for the '{@link oscfg.impl.CooperativeGroupImpl <em>Cooperative Group</em>}' class.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @see oscfg.impl.CooperativeGroupImpl
		 * @see oscfg.impl.OscfgPackageImpl#getCooperativeGroup()
		 * @generated
		 */
		EClass COOPERATIVE_GROUP = eINSTANCE.getCooperativeGroup();

		/**
		 * The meta object literal for the '<em><b>Cooperative Tasks</b></em>' containment reference list feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EReference COOPERATIVE_GROUP__COOPERATIVE_TASKS = eINSTANCE.getCooperativeGroup_CooperativeTasks();

		/**
		 * The meta object literal for the '{@link oscfg.impl.NamedObjectImpl <em>Named Object</em>}' class.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @see oscfg.impl.NamedObjectImpl
		 * @see oscfg.impl.OscfgPackageImpl#getNamedObject()
		 * @generated
		 */
		EClass NAMED_OBJECT = eINSTANCE.getNamedObject();

		/**
		 * The meta object literal for the '<em><b>Name</b></em>' attribute feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EAttribute NAMED_OBJECT__NAME = eINSTANCE.getNamedObject_Name();

		/**
		 * The meta object literal for the '{@link oscfg.impl.PosterImpl <em>Poster</em>}' class.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @see oscfg.impl.PosterImpl
		 * @see oscfg.impl.OscfgPackageImpl#getPoster()
		 * @generated
		 */
		EClass POSTER = eINSTANCE.getPoster();

		/**
		 * The meta object literal for the '<em><b>Post Message</b></em>' reference list feature.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		EReference POSTER__POST_MESSAGE = eINSTANCE.getPoster_PostMessage();

		/**
		 * The meta object literal for the '{@link oscfg.AutostartedType <em>Autostarted Type</em>}' enum.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @see oscfg.AutostartedType
		 * @see oscfg.impl.OscfgPackageImpl#getAutostartedType()
		 * @generated
		 */
		EEnum AUTOSTARTED_TYPE = eINSTANCE.getAutostartedType();

		/**
		 * The meta object literal for the '{@link oscfg.TypeType <em>Type Type</em>}' enum.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @see oscfg.TypeType
		 * @see oscfg.impl.OscfgPackageImpl#getTypeType()
		 * @generated
		 */
		EEnum TYPE_TYPE = eINSTANCE.getTypeType();

		/**
		 * The meta object literal for the '{@link oscfg.VectorType <em>Vector Type</em>}' enum.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @see oscfg.VectorType
		 * @see oscfg.impl.OscfgPackageImpl#getVectorType()
		 * @generated
		 */
		EEnum VECTOR_TYPE = eINSTANCE.getVectorType();

		/**
		 * The meta object literal for the '{@link oscfg.TargetTypes <em>Target Types</em>}' enum.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @see oscfg.TargetTypes
		 * @see oscfg.impl.OscfgPackageImpl#getTargetTypes()
		 * @generated
		 */
		EEnum TARGET_TYPES = eINSTANCE.getTargetTypes();

		/**
		 * The meta object literal for the '<em>Autostarted Type Object</em>' data type.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @see org.eclipse.emf.common.util.Enumerator
		 * @see oscfg.impl.OscfgPackageImpl#getAutostartedTypeObject()
		 * @generated
		 */
		EDataType AUTOSTARTED_TYPE_OBJECT = eINSTANCE.getAutostartedTypeObject();

		/**
		 * The meta object literal for the '<em>Queue Type</em>' data type.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @see oscfg.impl.OscfgPackageImpl#getQueueType()
		 * @generated
		 */
		EDataType QUEUE_TYPE = eINSTANCE.getQueueType();

		/**
		 * The meta object literal for the '<em>Task Priority Type</em>' data type.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @see oscfg.impl.OscfgPackageImpl#getTaskPriorityType()
		 * @generated
		 */
		EDataType TASK_PRIORITY_TYPE = eINSTANCE.getTaskPriorityType();

		/**
		 * The meta object literal for the '<em>Type Type Object</em>' data type.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @see org.eclipse.emf.common.util.Enumerator
		 * @see oscfg.impl.OscfgPackageImpl#getTypeTypeObject()
		 * @generated
		 */
		EDataType TYPE_TYPE_OBJECT = eINSTANCE.getTypeTypeObject();

		/**
		 * The meta object literal for the '<em>Vector Type Object</em>' data type.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @see org.eclipse.emf.common.util.Enumerator
		 * @see oscfg.impl.OscfgPackageImpl#getVectorTypeObject()
		 * @generated
		 */
		EDataType VECTOR_TYPE_OBJECT = eINSTANCE.getVectorTypeObject();

		/**
		 * The meta object literal for the '<em>IPL Type</em>' data type.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @see oscfg.impl.OscfgPackageImpl#getIPLType()
		 * @generated
		 */
		EDataType IPL_TYPE = eINSTANCE.getIPLType();

	}

} //OscfgPackage
