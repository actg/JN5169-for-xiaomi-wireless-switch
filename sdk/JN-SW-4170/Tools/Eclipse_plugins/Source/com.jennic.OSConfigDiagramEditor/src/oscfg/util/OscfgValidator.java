/**
 * <copyright>
 * </copyright>
 *
 * $Id$
 */
package oscfg.util;

import java.util.Map;

import org.eclipse.emf.common.util.DiagnosticChain;
import org.eclipse.emf.common.util.Enumerator;
import org.eclipse.emf.common.util.ResourceLocator;

import org.eclipse.emf.ecore.EPackage;

import org.eclipse.emf.ecore.util.EObjectValidator;

import oscfg.*;

/**
 * <!-- begin-user-doc -->
 * The <b>Validator</b> for the model.
 * <!-- end-user-doc -->
 * @see oscfg.OscfgPackage
 * @generated
 */
public class OscfgValidator extends EObjectValidator {
	/**
	 * The cached model package
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public static final OscfgValidator INSTANCE = new OscfgValidator();

	/**
	 * A constant for the {@link org.eclipse.emf.common.util.Diagnostic#getSource() source} of diagnostic {@link org.eclipse.emf.common.util.Diagnostic#getCode() codes} from this package.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see org.eclipse.emf.common.util.Diagnostic#getSource()
	 * @see org.eclipse.emf.common.util.Diagnostic#getCode()
	 * @generated
	 */
	public static final String DIAGNOSTIC_SOURCE = "oscfg";

	/**
	 * A constant with a fixed name that can be used as the base value for additional hand written constants.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	private static final int GENERATED_DIAGNOSTIC_CODE_COUNT = 0;

	/**
	 * A constant with a fixed name that can be used as the base value for additional hand written constants in a derived class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	protected static final int DIAGNOSTIC_CODE_COUNT = GENERATED_DIAGNOSTIC_CODE_COUNT;

	/**
	 * Creates an instance of the switch.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public OscfgValidator() {
		super();
	}

	/**
	 * Returns the package of this validator switch.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	@Override
	protected EPackage getEPackage() {
	  return OscfgPackage.eINSTANCE;
	}

	/**
	 * Calls <code>validateXXX</code> for the corresponding classifier of the model.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	@Override
	protected boolean validate(int classifierID, Object value, DiagnosticChain diagnostics, Map<Object, Object> context) {
		switch (classifierID) {
			case OscfgPackage.CALLBACK_FUNCTION:
				return validateCallbackFunction((CallbackFunction)value, diagnostics, context);
			case OscfgPackage.CONFIGURATION:
				return validateConfiguration((Configuration)value, diagnostics, context);
			case OscfgPackage.DOCUMENT_ROOT:
				return validateDocumentRoot((DocumentRoot)value, diagnostics, context);
			case OscfgPackage.HW_COUNTER:
				return validateHWCounter((HWCounter)value, diagnostics, context);
			case OscfgPackage.ISR:
				return validateISR((ISR)value, diagnostics, context);
			case OscfgPackage.MESSAGE:
				return validateMessage((Message)value, diagnostics, context);
			case OscfgPackage.MUTEX:
				return validateMutex((Mutex)value, diagnostics, context);
			case OscfgPackage.MODULE:
				return validateModule((Module)value, diagnostics, context);
			case OscfgPackage.SW_TIMER:
				return validateSWTimer((SWTimer)value, diagnostics, context);
			case OscfgPackage.TASK:
				return validateTask((Task)value, diagnostics, context);
			case OscfgPackage.BASE_TASK:
				return validateBaseTask((BaseTask)value, diagnostics, context);
			case OscfgPackage.INTERRUPT_SOURCE:
				return validateInterruptSource((InterruptSource)value, diagnostics, context);
			case OscfgPackage.OS:
				return validateOS((OS)value, diagnostics, context);
			case OscfgPackage.COOPERATIVE_GROUP:
				return validateCooperativeGroup((CooperativeGroup)value, diagnostics, context);
			case OscfgPackage.NAMED_OBJECT:
				return validateNamedObject((NamedObject)value, diagnostics, context);
			case OscfgPackage.POSTER:
				return validatePoster((Poster)value, diagnostics, context);
			case OscfgPackage.AUTOSTARTED_TYPE:
				return validateAutostartedType((AutostartedType)value, diagnostics, context);
			case OscfgPackage.TYPE_TYPE:
				return validateTypeType((TypeType)value, diagnostics, context);
			case OscfgPackage.VECTOR_TYPE:
				return validateVectorType((VectorType)value, diagnostics, context);
			case OscfgPackage.TARGET_TYPES:
				return validateTargetTypes((TargetTypes)value, diagnostics, context);
			case OscfgPackage.AUTOSTARTED_TYPE_OBJECT:
				return validateAutostartedTypeObject((Enumerator)value, diagnostics, context);
			case OscfgPackage.TYPE_TYPE_OBJECT:
				return validateTypeTypeObject((Enumerator)value, diagnostics, context);
			case OscfgPackage.VECTOR_TYPE_OBJECT:
				return validateVectorTypeObject((Enumerator)value, diagnostics, context);
			case OscfgPackage.IPL_TYPE:
				return validateIPLType((Integer)value, diagnostics, context);
			case OscfgPackage.QUEUE_TYPE:
				return validateQueueType((Integer)value, diagnostics, context);
			case OscfgPackage.TASK_PRIORITY_TYPE:
				return validateTaskPriorityType((Integer)value, diagnostics, context);
			default:
				return true;
		}
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public boolean validateCallbackFunction(CallbackFunction callbackFunction, DiagnosticChain diagnostics, Map<Object, Object> context) {
		return validate_EveryDefaultConstraint(callbackFunction, diagnostics, context);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public boolean validateConfiguration(Configuration configuration, DiagnosticChain diagnostics, Map<Object, Object> context) {
		return validate_EveryDefaultConstraint(configuration, diagnostics, context);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public boolean validateDocumentRoot(DocumentRoot documentRoot, DiagnosticChain diagnostics, Map<Object, Object> context) {
		return validate_EveryDefaultConstraint(documentRoot, diagnostics, context);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public boolean validateHWCounter(HWCounter hwCounter, DiagnosticChain diagnostics, Map<Object, Object> context) {
		return validate_EveryDefaultConstraint(hwCounter, diagnostics, context);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public boolean validateISR(ISR isr, DiagnosticChain diagnostics, Map<Object, Object> context) {
		return validate_EveryDefaultConstraint(isr, diagnostics, context);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public boolean validateMessage(Message message, DiagnosticChain diagnostics, Map<Object, Object> context) {
		return validate_EveryDefaultConstraint(message, diagnostics, context);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public boolean validateMutex(Mutex mutex, DiagnosticChain diagnostics, Map<Object, Object> context) {
		return validate_EveryDefaultConstraint(mutex, diagnostics, context);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public boolean validateModule(Module module, DiagnosticChain diagnostics, Map<Object, Object> context) {
		return validate_EveryDefaultConstraint(module, diagnostics, context);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public boolean validateSWTimer(SWTimer swTimer, DiagnosticChain diagnostics, Map<Object, Object> context) {
		return validate_EveryDefaultConstraint(swTimer, diagnostics, context);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public boolean validateTask(Task task, DiagnosticChain diagnostics, Map<Object, Object> context) {
		return validate_EveryDefaultConstraint(task, diagnostics, context);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public boolean validateBaseTask(BaseTask baseTask, DiagnosticChain diagnostics, Map<Object, Object> context) {
		return validate_EveryDefaultConstraint(baseTask, diagnostics, context);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public boolean validateInterruptSource(InterruptSource interruptSource, DiagnosticChain diagnostics, Map<Object, Object> context) {
		return validate_EveryDefaultConstraint(interruptSource, diagnostics, context);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public boolean validateOS(OS os, DiagnosticChain diagnostics, Map<Object, Object> context) {
		return validate_EveryDefaultConstraint(os, diagnostics, context);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public boolean validateCooperativeGroup(CooperativeGroup cooperativeGroup, DiagnosticChain diagnostics, Map<Object, Object> context) {
		return validate_EveryDefaultConstraint(cooperativeGroup, diagnostics, context);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public boolean validateNamedObject(NamedObject namedObject, DiagnosticChain diagnostics, Map<Object, Object> context) {
		return validate_EveryDefaultConstraint(namedObject, diagnostics, context);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public boolean validatePoster(Poster poster, DiagnosticChain diagnostics, Map<Object, Object> context) {
		return validate_EveryDefaultConstraint(poster, diagnostics, context);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public boolean validateAutostartedType(AutostartedType autostartedType, DiagnosticChain diagnostics, Map<Object, Object> context) {
		return true;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public boolean validateTypeType(TypeType typeType, DiagnosticChain diagnostics, Map<Object, Object> context) {
		return true;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public boolean validateVectorType(VectorType vectorType, DiagnosticChain diagnostics, Map<Object, Object> context) {
		return true;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public boolean validateTargetTypes(TargetTypes targetTypes, DiagnosticChain diagnostics, Map<Object, Object> context) {
		return true;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public boolean validateAutostartedTypeObject(Enumerator autostartedTypeObject, DiagnosticChain diagnostics, Map<Object, Object> context) {
		return true;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public boolean validateTypeTypeObject(Enumerator typeTypeObject, DiagnosticChain diagnostics, Map<Object, Object> context) {
		return true;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public boolean validateVectorTypeObject(Enumerator vectorTypeObject, DiagnosticChain diagnostics, Map<Object, Object> context) {
		return true;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public boolean validateIPLType(int iplType, DiagnosticChain diagnostics, Map<Object, Object> context) {
		boolean result = validateIPLType_Min(iplType, diagnostics, context);
		if (result || diagnostics != null) result &= validateIPLType_Max(iplType, diagnostics, context);
		return result;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @see #validateIPLType_Min
	 */
	public static final int IPL_TYPE__MIN__VALUE = 1;

	/**
	 * Validates the Min constraint of '<em>IPL Type</em>'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public boolean validateIPLType_Min(int iplType, DiagnosticChain diagnostics, Map<Object, Object> context) {
		boolean result = iplType >= IPL_TYPE__MIN__VALUE;
		if (!result && diagnostics != null)
			reportMinViolation(OscfgPackage.Literals.IPL_TYPE, iplType, IPL_TYPE__MIN__VALUE, true, diagnostics, context);
		return result;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @see #validateIPLType_Max
	 */
	public static final int IPL_TYPE__MAX__VALUE = 16;

	/**
	 * Validates the Max constraint of '<em>IPL Type</em>'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public boolean validateIPLType_Max(int iplType, DiagnosticChain diagnostics, Map<Object, Object> context) {
		boolean result = iplType <= IPL_TYPE__MAX__VALUE;
		if (!result && diagnostics != null)
			reportMaxViolation(OscfgPackage.Literals.IPL_TYPE, iplType, IPL_TYPE__MAX__VALUE, true, diagnostics, context);
		return result;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public boolean validateQueueType(int queueType, DiagnosticChain diagnostics, Map<Object, Object> context) {
		boolean result = validateQueueType_Min(queueType, diagnostics, context);
		if (result || diagnostics != null) result &= validateQueueType_Max(queueType, diagnostics, context);
		return result;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @see #validateQueueType_Min
	 */
	public static final int QUEUE_TYPE__MIN__VALUE = 0;

	/**
	 * Validates the Min constraint of '<em>Queue Type</em>'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public boolean validateQueueType_Min(int queueType, DiagnosticChain diagnostics, Map<Object, Object> context) {
		boolean result = queueType >= QUEUE_TYPE__MIN__VALUE;
		if (!result && diagnostics != null)
			reportMinViolation(OscfgPackage.Literals.QUEUE_TYPE, queueType, QUEUE_TYPE__MIN__VALUE, true, diagnostics, context);
		return result;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @see #validateQueueType_Max
	 */
	public static final int QUEUE_TYPE__MAX__VALUE = 2147483647;

	/**
	 * Validates the Max constraint of '<em>Queue Type</em>'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public boolean validateQueueType_Max(int queueType, DiagnosticChain diagnostics, Map<Object, Object> context) {
		boolean result = queueType <= QUEUE_TYPE__MAX__VALUE;
		if (!result && diagnostics != null)
			reportMaxViolation(OscfgPackage.Literals.QUEUE_TYPE, queueType, QUEUE_TYPE__MAX__VALUE, true, diagnostics, context);
		return result;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public boolean validateTaskPriorityType(int taskPriorityType, DiagnosticChain diagnostics, Map<Object, Object> context) {
		boolean result = validateTaskPriorityType_Min(taskPriorityType, diagnostics, context);
		if (result || diagnostics != null) result &= validateTaskPriorityType_Max(taskPriorityType, diagnostics, context);
		return result;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @see #validateTaskPriorityType_Min
	 */
	public static final int TASK_PRIORITY_TYPE__MIN__VALUE = 1;

	/**
	 * Validates the Min constraint of '<em>Task Priority Type</em>'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public boolean validateTaskPriorityType_Min(int taskPriorityType, DiagnosticChain diagnostics, Map<Object, Object> context) {
		boolean result = taskPriorityType >= TASK_PRIORITY_TYPE__MIN__VALUE;
		if (!result && diagnostics != null)
			reportMinViolation(OscfgPackage.Literals.TASK_PRIORITY_TYPE, taskPriorityType, TASK_PRIORITY_TYPE__MIN__VALUE, true, diagnostics, context);
		return result;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 * @see #validateTaskPriorityType_Max
	 */
	public static final int TASK_PRIORITY_TYPE__MAX__VALUE = 2147483647;

	/**
	 * Validates the Max constraint of '<em>Task Priority Type</em>'.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public boolean validateTaskPriorityType_Max(int taskPriorityType, DiagnosticChain diagnostics, Map<Object, Object> context) {
		boolean result = taskPriorityType <= TASK_PRIORITY_TYPE__MAX__VALUE;
		if (!result && diagnostics != null)
			reportMaxViolation(OscfgPackage.Literals.TASK_PRIORITY_TYPE, taskPriorityType, TASK_PRIORITY_TYPE__MAX__VALUE, true, diagnostics, context);
		return result;
	}

	/**
	 * Returns the resource locator that will be used to fetch messages for this validator's diagnostics.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	@Override
	public ResourceLocator getResourceLocator() {
		// TODO
		// Specialize this to return a resource locator for messages specific to this validator.
		// Ensure that you remove @generated or mark it @generated NOT
		return super.getResourceLocator();
	}

} //OscfgValidator
