/**
 * <copyright>
 * </copyright>
 *
 * $Id$
 */
package oscfg.impl;

import org.eclipse.emf.common.util.Enumerator;

import org.eclipse.emf.ecore.EClass;
import org.eclipse.emf.ecore.EDataType;
import org.eclipse.emf.ecore.EObject;
import org.eclipse.emf.ecore.EPackage;

import org.eclipse.emf.ecore.impl.EFactoryImpl;

import org.eclipse.emf.ecore.plugin.EcorePlugin;

import oscfg.*;

/**
 * <!-- begin-user-doc -->
 * An implementation of the model <b>Factory</b>.
 * <!-- end-user-doc -->
 * @generated
 */
public class OscfgFactoryImpl extends EFactoryImpl implements OscfgFactory {
	/**
	 * Creates the default factory implementation.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public static OscfgFactory init() {
		try {
			OscfgFactory theOscfgFactory = (OscfgFactory)EPackage.Registry.INSTANCE.getEFactory(OscfgPackage.eNS_URI);
			if (theOscfgFactory != null) {
				return theOscfgFactory;
			}
		}
		catch (Exception exception) {
			EcorePlugin.INSTANCE.log(exception);
		}
		return new OscfgFactoryImpl();
	}

	/**
	 * Creates an instance of the factory.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public OscfgFactoryImpl() {
		super();
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	@Override
	public EObject create(EClass eClass) {
		switch (eClass.getClassifierID()) {
			case OscfgPackage.CALLBACK_FUNCTION: return createCallbackFunction();
			case OscfgPackage.CONFIGURATION: return createConfiguration();
			case OscfgPackage.DOCUMENT_ROOT: return createDocumentRoot();
			case OscfgPackage.HW_COUNTER: return createHWCounter();
			case OscfgPackage.ISR: return createISR();
			case OscfgPackage.MESSAGE: return createMessage();
			case OscfgPackage.MUTEX: return createMutex();
			case OscfgPackage.MODULE: return createModule();
			case OscfgPackage.SW_TIMER: return createSWTimer();
			case OscfgPackage.TASK: return createTask();
			case OscfgPackage.INTERRUPT_SOURCE: return createInterruptSource();
			case OscfgPackage.OS: return createOS();
			case OscfgPackage.COOPERATIVE_GROUP: return createCooperativeGroup();
			default:
				throw new IllegalArgumentException("The class '" + eClass.getName() + "' is not a valid classifier");
		}
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	@Override
	public Object createFromString(EDataType eDataType, String initialValue) {
		switch (eDataType.getClassifierID()) {
			case OscfgPackage.AUTOSTARTED_TYPE:
				return createAutostartedTypeFromString(eDataType, initialValue);
			case OscfgPackage.TYPE_TYPE:
				return createTypeTypeFromString(eDataType, initialValue);
			case OscfgPackage.VECTOR_TYPE:
				return createVectorTypeFromString(eDataType, initialValue);
			case OscfgPackage.TARGET_TYPES:
				return createTargetTypesFromString(eDataType, initialValue);
			case OscfgPackage.AUTOSTARTED_TYPE_OBJECT:
				return createAutostartedTypeObjectFromString(eDataType, initialValue);
			case OscfgPackage.TYPE_TYPE_OBJECT:
				return createTypeTypeObjectFromString(eDataType, initialValue);
			case OscfgPackage.VECTOR_TYPE_OBJECT:
				return createVectorTypeObjectFromString(eDataType, initialValue);
			case OscfgPackage.IPL_TYPE:
				return createIPLTypeFromString(eDataType, initialValue);
			case OscfgPackage.QUEUE_TYPE:
				return createQueueTypeFromString(eDataType, initialValue);
			case OscfgPackage.TASK_PRIORITY_TYPE:
				return createTaskPriorityTypeFromString(eDataType, initialValue);
			default:
				throw new IllegalArgumentException("The datatype '" + eDataType.getName() + "' is not a valid classifier");
		}
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	@Override
	public String convertToString(EDataType eDataType, Object instanceValue) {
		switch (eDataType.getClassifierID()) {
			case OscfgPackage.AUTOSTARTED_TYPE:
				return convertAutostartedTypeToString(eDataType, instanceValue);
			case OscfgPackage.TYPE_TYPE:
				return convertTypeTypeToString(eDataType, instanceValue);
			case OscfgPackage.VECTOR_TYPE:
				return convertVectorTypeToString(eDataType, instanceValue);
			case OscfgPackage.TARGET_TYPES:
				return convertTargetTypesToString(eDataType, instanceValue);
			case OscfgPackage.AUTOSTARTED_TYPE_OBJECT:
				return convertAutostartedTypeObjectToString(eDataType, instanceValue);
			case OscfgPackage.TYPE_TYPE_OBJECT:
				return convertTypeTypeObjectToString(eDataType, instanceValue);
			case OscfgPackage.VECTOR_TYPE_OBJECT:
				return convertVectorTypeObjectToString(eDataType, instanceValue);
			case OscfgPackage.IPL_TYPE:
				return convertIPLTypeToString(eDataType, instanceValue);
			case OscfgPackage.QUEUE_TYPE:
				return convertQueueTypeToString(eDataType, instanceValue);
			case OscfgPackage.TASK_PRIORITY_TYPE:
				return convertTaskPriorityTypeToString(eDataType, instanceValue);
			default:
				throw new IllegalArgumentException("The datatype '" + eDataType.getName() + "' is not a valid classifier");
		}
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public CallbackFunction createCallbackFunction() {
		CallbackFunctionImpl callbackFunction = new CallbackFunctionImpl();
		return callbackFunction;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public Configuration createConfiguration() {
		ConfigurationImpl configuration = new ConfigurationImpl();
		return configuration;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public DocumentRoot createDocumentRoot() {
		DocumentRootImpl documentRoot = new DocumentRootImpl();
		return documentRoot;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public HWCounter createHWCounter() {
		HWCounterImpl hwCounter = new HWCounterImpl();
		return hwCounter;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public ISR createISR() {
		ISRImpl isr = new ISRImpl();
		return isr;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public Message createMessage() {
		MessageImpl message = new MessageImpl();
		return message;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public Mutex createMutex() {
		MutexImpl mutex = new MutexImpl();
		return mutex;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public Module createModule() {
		ModuleImpl module = new ModuleImpl();
		return module;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public SWTimer createSWTimer() {
		SWTimerImpl swTimer = new SWTimerImpl();
		return swTimer;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public Task createTask() {
		TaskImpl task = new TaskImpl();
		return task;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public InterruptSource createInterruptSource() {
		InterruptSourceImpl interruptSource = new InterruptSourceImpl();
		return interruptSource;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public OS createOS() {
		OSImpl os = new OSImpl();
		return os;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public CooperativeGroup createCooperativeGroup() {
		CooperativeGroupImpl cooperativeGroup = new CooperativeGroupImpl();
		return cooperativeGroup;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public AutostartedType createAutostartedTypeFromString(EDataType eDataType, String initialValue) {
		AutostartedType result = AutostartedType.get(initialValue);
		if (result == null) throw new IllegalArgumentException("The value '" + initialValue + "' is not a valid enumerator of '" + eDataType.getName() + "'");
		return result;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public String convertAutostartedTypeToString(EDataType eDataType, Object instanceValue) {
		return instanceValue == null ? null : instanceValue.toString();
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public TypeType createTypeTypeFromString(EDataType eDataType, String initialValue) {
		TypeType result = TypeType.get(initialValue);
		if (result == null) throw new IllegalArgumentException("The value '" + initialValue + "' is not a valid enumerator of '" + eDataType.getName() + "'");
		return result;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public String convertTypeTypeToString(EDataType eDataType, Object instanceValue) {
		return instanceValue == null ? null : instanceValue.toString();
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public VectorType createVectorTypeFromString(EDataType eDataType, String initialValue) {
		VectorType result = VectorType.get(initialValue);
		if (result == null) throw new IllegalArgumentException("The value '" + initialValue + "' is not a valid enumerator of '" + eDataType.getName() + "'");
		return result;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public String convertVectorTypeToString(EDataType eDataType, Object instanceValue) {
		return instanceValue == null ? null : instanceValue.toString();
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public TargetTypes createTargetTypesFromString(EDataType eDataType, String initialValue) {
		TargetTypes result = TargetTypes.get(initialValue);
		if (result == null) throw new IllegalArgumentException("The value '" + initialValue + "' is not a valid enumerator of '" + eDataType.getName() + "'");
		return result;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public String convertTargetTypesToString(EDataType eDataType, Object instanceValue) {
		return instanceValue == null ? null : instanceValue.toString();
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public Enumerator createAutostartedTypeObjectFromString(EDataType eDataType, String initialValue) {
		return (Enumerator)super.createFromString(eDataType, initialValue);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public String convertAutostartedTypeObjectToString(EDataType eDataType, Object instanceValue) {
		return super.convertToString(eDataType, instanceValue);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated NOT
	 */
	public Integer createQueueTypeFromString(EDataType eDataType, String initialValue) {
//		if ("unqueued" == initialValue) {
//			return 0;
//		}
		return (Integer)super.createFromString(eDataType, initialValue);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated NOT
	 */
	public String convertQueueTypeToString(EDataType eDataType, Object instanceValue) {
//		if (0 == (Integer)instanceValue) {
//			return "unqueued";
//		}
		return super.convertToString(eDataType, instanceValue);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public Integer createTaskPriorityTypeFromString(EDataType eDataType, String initialValue) {
		return (Integer)super.createFromString(eDataType, initialValue);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public String convertTaskPriorityTypeToString(EDataType eDataType, Object instanceValue) {
		return super.convertToString(eDataType, instanceValue);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public Enumerator createTypeTypeObjectFromString(EDataType eDataType, String initialValue) {
		return (Enumerator)super.createFromString(eDataType, initialValue);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public String convertTypeTypeObjectToString(EDataType eDataType, Object instanceValue) {
		return super.convertToString(eDataType, instanceValue);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public Enumerator createVectorTypeObjectFromString(EDataType eDataType, String initialValue) {
		return (Enumerator)super.createFromString(eDataType, initialValue);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public String convertVectorTypeObjectToString(EDataType eDataType, Object instanceValue) {
		return super.convertToString(eDataType, instanceValue);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public Integer createIPLTypeFromString(EDataType eDataType, String initialValue) {
		return (Integer)super.createFromString(eDataType, initialValue);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public String convertIPLTypeToString(EDataType eDataType, Object instanceValue) {
		return super.convertToString(eDataType, instanceValue);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public OscfgPackage getOscfgPackage() {
		return (OscfgPackage)getEPackage();
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @deprecated
	 * @generated
	 */
	@Deprecated
	public static OscfgPackage getPackage() {
		return OscfgPackage.eINSTANCE;
	}

} //OscfgFactoryImpl
