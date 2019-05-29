/**
 * <copyright>
 * </copyright>
 *
 * $Id$
 */
package oscfg.impl;

import org.eclipse.emf.common.util.Enumerator;

import org.eclipse.emf.ecore.EAttribute;
import org.eclipse.emf.ecore.EClass;
import org.eclipse.emf.ecore.EDataType;
import org.eclipse.emf.ecore.EEnum;
import org.eclipse.emf.ecore.EPackage;
import org.eclipse.emf.ecore.EReference;

import org.eclipse.emf.ecore.EValidator;
import org.eclipse.emf.ecore.impl.EPackageImpl;

import org.eclipse.emf.ecore.xml.type.XMLTypePackage;

import oscfg.AutostartedType;
import oscfg.BaseTask;
import oscfg.CallbackFunction;
import oscfg.Configuration;
import oscfg.CooperativeGroup;
import oscfg.DocumentRoot;
import oscfg.HWCounter;
import oscfg.InterruptSource;
import oscfg.Message;
import oscfg.Module;
import oscfg.Mutex;
import oscfg.NamedObject;
import oscfg.OscfgFactory;
import oscfg.OscfgPackage;
import oscfg.Poster;
import oscfg.SWTimer;
import oscfg.TargetTypes;
import oscfg.Task;
import oscfg.TypeType;
import oscfg.VectorType;
import oscfg.util.OscfgValidator;

/**
 * <!-- begin-user-doc -->
 * An implementation of the model <b>Package</b>.
 * <!-- end-user-doc -->
 * @generated
 */
public class OscfgPackageImpl extends EPackageImpl implements OscfgPackage {
	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	private EClass callbackFunctionEClass = null;

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	private EClass configurationEClass = null;

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	private EClass documentRootEClass = null;

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	private EClass hwCounterEClass = null;

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	private EClass isrEClass = null;

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	private EClass messageEClass = null;

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	private EClass mutexEClass = null;

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	private EClass moduleEClass = null;

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	private EClass swTimerEClass = null;

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	private EClass taskEClass = null;

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	private EClass baseTaskEClass = null;

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	private EClass interruptSourceEClass = null;

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	private EClass osEClass = null;

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	private EClass cooperativeGroupEClass = null;

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	private EClass namedObjectEClass = null;

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	private EClass posterEClass = null;

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	private EEnum autostartedTypeEEnum = null;

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	private EEnum typeTypeEEnum = null;

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	private EEnum vectorTypeEEnum = null;

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	private EEnum targetTypesEEnum = null;

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	private EDataType autostartedTypeObjectEDataType = null;

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	private EDataType queueTypeEDataType = null;

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	private EDataType taskPriorityTypeEDataType = null;

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	private EDataType typeTypeObjectEDataType = null;

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	private EDataType vectorTypeObjectEDataType = null;

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	private EDataType iplTypeEDataType = null;

	/**
	 * Creates an instance of the model <b>Package</b>, registered with
	 * {@link org.eclipse.emf.ecore.EPackage.Registry EPackage.Registry} by the package
	 * package URI value.
	 * <p>Note: the correct way to create the package is via the static
	 * factory method {@link #init init()}, which also performs
	 * initialization of the package, or returns the registered package,
	 * if one already exists.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see org.eclipse.emf.ecore.EPackage.Registry
	 * @see oscfg.OscfgPackage#eNS_URI
	 * @see #init()
	 * @generated
	 */
	private OscfgPackageImpl() {
		super(eNS_URI, OscfgFactory.eINSTANCE);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	private static boolean isInited = false;

	/**
	 * Creates, registers, and initializes the <b>Package</b> for this model, and for any others upon which it depends.
	 * 
	 * <p>This method is used to initialize {@link OscfgPackage#eINSTANCE} when that field is accessed.
	 * Clients should not invoke it directly. Instead, they should simply access that field to obtain the package.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #eNS_URI
	 * @see #createPackageContents()
	 * @see #initializePackageContents()
	 * @generated
	 */
	public static OscfgPackage init() {
		if (isInited) return (OscfgPackage)EPackage.Registry.INSTANCE.getEPackage(OscfgPackage.eNS_URI);

		// Obtain or create and register package
		OscfgPackageImpl theOscfgPackage = (OscfgPackageImpl)(EPackage.Registry.INSTANCE.get(eNS_URI) instanceof OscfgPackageImpl ? EPackage.Registry.INSTANCE.get(eNS_URI) : new OscfgPackageImpl());

		isInited = true;

		// Initialize simple dependencies
		XMLTypePackage.eINSTANCE.eClass();

		// Create package meta-data objects
		theOscfgPackage.createPackageContents();

		// Initialize created meta-data
		theOscfgPackage.initializePackageContents();

		// Register package validator
		EValidator.Registry.INSTANCE.put
			(theOscfgPackage, 
			 new EValidator.Descriptor() {
				 public EValidator getEValidator() {
					 return OscfgValidator.INSTANCE;
				 }
			 });

		// Mark meta-data to indicate it can't be changed
		theOscfgPackage.freeze();

  
		// Update the registry and return the package
		EPackage.Registry.INSTANCE.put(OscfgPackage.eNS_URI, theOscfgPackage);
		return theOscfgPackage;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EClass getCallbackFunction() {
		return callbackFunctionEClass;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EClass getConfiguration() {
		return configurationEClass;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EReference getConfiguration_OS() {
		return (EReference)configurationEClass.getEStructuralFeatures().get(0);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EAttribute getConfiguration_Version() {
		return (EAttribute)configurationEClass.getEStructuralFeatures().get(1);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EClass getDocumentRoot() {
		return documentRootEClass;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EAttribute getDocumentRoot_Mixed() {
		return (EAttribute)documentRootEClass.getEStructuralFeatures().get(0);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EReference getDocumentRoot_XMLNSPrefixMap() {
		return (EReference)documentRootEClass.getEStructuralFeatures().get(1);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EReference getDocumentRoot_XSISchemaLocation() {
		return (EReference)documentRootEClass.getEStructuralFeatures().get(2);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EReference getDocumentRoot_Configuration() {
		return (EReference)documentRootEClass.getEStructuralFeatures().get(3);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EClass getHWCounter() {
		return hwCounterEClass;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EReference getHWCounter_SWTimers() {
		return (EReference)hwCounterEClass.getEStructuralFeatures().get(0);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EReference getHWCounter_Disable_callback() {
		return (EReference)hwCounterEClass.getEStructuralFeatures().get(1);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EReference getHWCounter_Enable_callback() {
		return (EReference)hwCounterEClass.getEStructuralFeatures().get(2);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EReference getHWCounter_Get_callback() {
		return (EReference)hwCounterEClass.getEStructuralFeatures().get(3);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EReference getHWCounter_Set_callback() {
		return (EReference)hwCounterEClass.getEStructuralFeatures().get(4);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EClass getISR() {
		return isrEClass;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EAttribute getISR_IPL() {
		return (EAttribute)isrEClass.getEStructuralFeatures().get(0);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EAttribute getISR_Type() {
		return (EAttribute)isrEClass.getEStructuralFeatures().get(1);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EReference getISR_ISRSource() {
		return (EReference)isrEClass.getEStructuralFeatures().get(2);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EClass getMessage() {
		return messageEClass;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EAttribute getMessage_Ctype() {
		return (EAttribute)messageEClass.getEStructuralFeatures().get(0);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EAttribute getMessage_Queue() {
		return (EAttribute)messageEClass.getEStructuralFeatures().get(1);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EReference getMessage_Notifies() {
		return (EReference)messageEClass.getEStructuralFeatures().get(2);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EReference getMessage_CallsBack() {
		return (EReference)messageEClass.getEStructuralFeatures().get(3);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EClass getMutex() {
		return mutexEClass;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EClass getModule() {
		return moduleEClass;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EReference getModule_ISRs() {
		return (EReference)moduleEClass.getEStructuralFeatures().get(0);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EReference getModule_Mutexs() {
		return (EReference)moduleEClass.getEStructuralFeatures().get(1);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EReference getModule_Messages() {
		return (EReference)moduleEClass.getEStructuralFeatures().get(2);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EReference getModule_HWCounters() {
		return (EReference)moduleEClass.getEStructuralFeatures().get(3);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EReference getModule_Callbacks() {
		return (EReference)moduleEClass.getEStructuralFeatures().get(4);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EReference getModule_InterruptSources() {
		return (EReference)moduleEClass.getEStructuralFeatures().get(5);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EReference getModule_Tasks() {
		return (EReference)moduleEClass.getEStructuralFeatures().get(6);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EReference getModule_CooperativeTaskGroups() {
		return (EReference)moduleEClass.getEStructuralFeatures().get(7);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EClass getSWTimer() {
		return swTimerEClass;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EReference getSWTimer_Activates() {
		return (EReference)swTimerEClass.getEStructuralFeatures().get(0);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EReference getSWTimer_Timer_callback() {
		return (EReference)swTimerEClass.getEStructuralFeatures().get(1);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EClass getTask() {
		return taskEClass;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EAttribute getTask_Autostarted() {
		return (EAttribute)taskEClass.getEStructuralFeatures().get(0);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EAttribute getTask_Priority() {
		return (EAttribute)taskEClass.getEStructuralFeatures().get(1);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EReference getTask_CooperativeGroup() {
		return (EReference)taskEClass.getEStructuralFeatures().get(2);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EClass getBaseTask() {
		return baseTaskEClass;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EReference getBaseTask_CollectMessage() {
		return (EReference)baseTaskEClass.getEStructuralFeatures().get(0);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EReference getBaseTask_EnterExitMutex() {
		return (EReference)baseTaskEClass.getEStructuralFeatures().get(1);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EClass getInterruptSource() {
		return interruptSourceEClass;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EAttribute getInterruptSource_Source() {
		return (EAttribute)interruptSourceEClass.getEStructuralFeatures().get(0);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EReference getInterruptSource_SourceISR() {
		return (EReference)interruptSourceEClass.getEStructuralFeatures().get(1);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EClass getOS() {
		return osEClass;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EAttribute getOS_Target() {
		return (EAttribute)osEClass.getEStructuralFeatures().get(0);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EReference getOS_Modules() {
		return (EReference)osEClass.getEStructuralFeatures().get(1);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EAttribute getOS_ErrorHook() {
		return (EAttribute)osEClass.getEStructuralFeatures().get(2);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EAttribute getOS_StrictErrorChecks() {
		return (EAttribute)osEClass.getEStructuralFeatures().get(3);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EAttribute getOS_ClearStack() {
		return (EAttribute)osEClass.getEStructuralFeatures().get(4);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EClass getCooperativeGroup() {
		return cooperativeGroupEClass;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EReference getCooperativeGroup_CooperativeTasks() {
		return (EReference)cooperativeGroupEClass.getEStructuralFeatures().get(0);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EClass getNamedObject() {
		return namedObjectEClass;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EAttribute getNamedObject_Name() {
		return (EAttribute)namedObjectEClass.getEStructuralFeatures().get(0);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EClass getPoster() {
		return posterEClass;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EReference getPoster_PostMessage() {
		return (EReference)posterEClass.getEStructuralFeatures().get(0);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EEnum getAutostartedType() {
		return autostartedTypeEEnum;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EEnum getTypeType() {
		return typeTypeEEnum;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EEnum getVectorType() {
		return vectorTypeEEnum;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EEnum getTargetTypes() {
		return targetTypesEEnum;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EDataType getAutostartedTypeObject() {
		return autostartedTypeObjectEDataType;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EDataType getQueueType() {
		return queueTypeEDataType;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EDataType getTaskPriorityType() {
		return taskPriorityTypeEDataType;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EDataType getTypeTypeObject() {
		return typeTypeObjectEDataType;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EDataType getVectorTypeObject() {
		return vectorTypeObjectEDataType;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EDataType getIPLType() {
		return iplTypeEDataType;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public OscfgFactory getOscfgFactory() {
		return (OscfgFactory)getEFactoryInstance();
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	private boolean isCreated = false;

	/**
	 * Creates the meta-model objects for the package.  This method is
	 * guarded to have no affect on any invocation but its first.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void createPackageContents() {
		if (isCreated) return;
		isCreated = true;

		// Create classes and their features
		callbackFunctionEClass = createEClass(CALLBACK_FUNCTION);

		configurationEClass = createEClass(CONFIGURATION);
		createEReference(configurationEClass, CONFIGURATION__OS);
		createEAttribute(configurationEClass, CONFIGURATION__VERSION);

		documentRootEClass = createEClass(DOCUMENT_ROOT);
		createEAttribute(documentRootEClass, DOCUMENT_ROOT__MIXED);
		createEReference(documentRootEClass, DOCUMENT_ROOT__XMLNS_PREFIX_MAP);
		createEReference(documentRootEClass, DOCUMENT_ROOT__XSI_SCHEMA_LOCATION);
		createEReference(documentRootEClass, DOCUMENT_ROOT__CONFIGURATION);

		hwCounterEClass = createEClass(HW_COUNTER);
		createEReference(hwCounterEClass, HW_COUNTER__SW_TIMERS);
		createEReference(hwCounterEClass, HW_COUNTER__DISABLE_CALLBACK);
		createEReference(hwCounterEClass, HW_COUNTER__ENABLE_CALLBACK);
		createEReference(hwCounterEClass, HW_COUNTER__GET_CALLBACK);
		createEReference(hwCounterEClass, HW_COUNTER__SET_CALLBACK);

		isrEClass = createEClass(ISR);
		createEAttribute(isrEClass, ISR__IPL);
		createEAttribute(isrEClass, ISR__TYPE);
		createEReference(isrEClass, ISR__ISR_SOURCE);

		messageEClass = createEClass(MESSAGE);
		createEAttribute(messageEClass, MESSAGE__CTYPE);
		createEAttribute(messageEClass, MESSAGE__QUEUE);
		createEReference(messageEClass, MESSAGE__NOTIFIES);
		createEReference(messageEClass, MESSAGE__CALLS_BACK);

		mutexEClass = createEClass(MUTEX);

		moduleEClass = createEClass(MODULE);
		createEReference(moduleEClass, MODULE__IS_RS);
		createEReference(moduleEClass, MODULE__MUTEXS);
		createEReference(moduleEClass, MODULE__MESSAGES);
		createEReference(moduleEClass, MODULE__HW_COUNTERS);
		createEReference(moduleEClass, MODULE__CALLBACKS);
		createEReference(moduleEClass, MODULE__INTERRUPT_SOURCES);
		createEReference(moduleEClass, MODULE__TASKS);
		createEReference(moduleEClass, MODULE__COOPERATIVE_TASK_GROUPS);

		swTimerEClass = createEClass(SW_TIMER);
		createEReference(swTimerEClass, SW_TIMER__ACTIVATES);
		createEReference(swTimerEClass, SW_TIMER__TIMER_CALLBACK);

		taskEClass = createEClass(TASK);
		createEAttribute(taskEClass, TASK__AUTOSTARTED);
		createEAttribute(taskEClass, TASK__PRIORITY);
		createEReference(taskEClass, TASK__COOPERATIVE_GROUP);

		baseTaskEClass = createEClass(BASE_TASK);
		createEReference(baseTaskEClass, BASE_TASK__COLLECT_MESSAGE);
		createEReference(baseTaskEClass, BASE_TASK__ENTER_EXIT_MUTEX);

		interruptSourceEClass = createEClass(INTERRUPT_SOURCE);
		createEAttribute(interruptSourceEClass, INTERRUPT_SOURCE__SOURCE);
		createEReference(interruptSourceEClass, INTERRUPT_SOURCE__SOURCE_ISR);

		osEClass = createEClass(OS);
		createEAttribute(osEClass, OS__TARGET);
		createEReference(osEClass, OS__MODULES);
		createEAttribute(osEClass, OS__ERROR_HOOK);
		createEAttribute(osEClass, OS__STRICT_ERROR_CHECKS);
		createEAttribute(osEClass, OS__CLEAR_STACK);

		cooperativeGroupEClass = createEClass(COOPERATIVE_GROUP);
		createEReference(cooperativeGroupEClass, COOPERATIVE_GROUP__COOPERATIVE_TASKS);

		namedObjectEClass = createEClass(NAMED_OBJECT);
		createEAttribute(namedObjectEClass, NAMED_OBJECT__NAME);

		posterEClass = createEClass(POSTER);
		createEReference(posterEClass, POSTER__POST_MESSAGE);

		// Create enums
		autostartedTypeEEnum = createEEnum(AUTOSTARTED_TYPE);
		typeTypeEEnum = createEEnum(TYPE_TYPE);
		vectorTypeEEnum = createEEnum(VECTOR_TYPE);
		targetTypesEEnum = createEEnum(TARGET_TYPES);

		// Create data types
		autostartedTypeObjectEDataType = createEDataType(AUTOSTARTED_TYPE_OBJECT);
		typeTypeObjectEDataType = createEDataType(TYPE_TYPE_OBJECT);
		vectorTypeObjectEDataType = createEDataType(VECTOR_TYPE_OBJECT);
		iplTypeEDataType = createEDataType(IPL_TYPE);
		queueTypeEDataType = createEDataType(QUEUE_TYPE);
		taskPriorityTypeEDataType = createEDataType(TASK_PRIORITY_TYPE);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	private boolean isInitialized = false;

	/**
	 * Complete the initialization of the package and its meta-model.  This
	 * method is guarded to have no affect on any invocation but its first.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void initializePackageContents() {
		if (isInitialized) return;
		isInitialized = true;

		// Initialize package
		setName(eNAME);
		setNsPrefix(eNS_PREFIX);
		setNsURI(eNS_URI);

		// Obtain other dependent packages
		XMLTypePackage theXMLTypePackage = (XMLTypePackage)EPackage.Registry.INSTANCE.getEPackage(XMLTypePackage.eNS_URI);

		// Create type parameters

		// Set bounds for type parameters

		// Add supertypes to classes
		callbackFunctionEClass.getESuperTypes().add(this.getNamedObject());
		callbackFunctionEClass.getESuperTypes().add(this.getPoster());
		hwCounterEClass.getESuperTypes().add(this.getNamedObject());
		isrEClass.getESuperTypes().add(this.getBaseTask());
		messageEClass.getESuperTypes().add(this.getNamedObject());
		mutexEClass.getESuperTypes().add(this.getNamedObject());
		moduleEClass.getESuperTypes().add(this.getNamedObject());
		swTimerEClass.getESuperTypes().add(this.getNamedObject());
		taskEClass.getESuperTypes().add(this.getBaseTask());
		baseTaskEClass.getESuperTypes().add(this.getNamedObject());
		baseTaskEClass.getESuperTypes().add(this.getPoster());
		cooperativeGroupEClass.getESuperTypes().add(this.getNamedObject());

		// Initialize classes and features; add operations and parameters
		initEClass(callbackFunctionEClass, CallbackFunction.class, "CallbackFunction", !IS_ABSTRACT, !IS_INTERFACE, IS_GENERATED_INSTANCE_CLASS);

		initEClass(configurationEClass, Configuration.class, "Configuration", !IS_ABSTRACT, !IS_INTERFACE, IS_GENERATED_INSTANCE_CLASS);
		initEReference(getConfiguration_OS(), this.getOS(), null, "OS", null, 1, 1, Configuration.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, IS_COMPOSITE, !IS_RESOLVE_PROXIES, !IS_UNSETTABLE, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEAttribute(getConfiguration_Version(), theXMLTypePackage.getString(), "Version", "1.0", 1, 1, Configuration.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);

		initEClass(documentRootEClass, DocumentRoot.class, "DocumentRoot", !IS_ABSTRACT, !IS_INTERFACE, IS_GENERATED_INSTANCE_CLASS);
		initEAttribute(getDocumentRoot_Mixed(), ecorePackage.getEFeatureMapEntry(), "mixed", null, 0, -1, DocumentRoot.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, !IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEReference(getDocumentRoot_XMLNSPrefixMap(), ecorePackage.getEStringToStringMapEntry(), null, "xMLNSPrefixMap", null, 0, -1, DocumentRoot.class, IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, IS_COMPOSITE, !IS_RESOLVE_PROXIES, !IS_UNSETTABLE, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEReference(getDocumentRoot_XSISchemaLocation(), ecorePackage.getEStringToStringMapEntry(), null, "xSISchemaLocation", null, 0, -1, DocumentRoot.class, IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, IS_COMPOSITE, !IS_RESOLVE_PROXIES, !IS_UNSETTABLE, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEReference(getDocumentRoot_Configuration(), this.getConfiguration(), null, "Configuration", null, 1, 1, DocumentRoot.class, IS_TRANSIENT, IS_VOLATILE, IS_CHANGEABLE, IS_COMPOSITE, !IS_RESOLVE_PROXIES, !IS_UNSETTABLE, IS_UNIQUE, IS_DERIVED, IS_ORDERED);

		initEClass(hwCounterEClass, HWCounter.class, "HWCounter", !IS_ABSTRACT, !IS_INTERFACE, IS_GENERATED_INSTANCE_CLASS);
		initEReference(getHWCounter_SWTimers(), this.getSWTimer(), null, "SWTimers", null, 0, -1, HWCounter.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, IS_COMPOSITE, !IS_RESOLVE_PROXIES, !IS_UNSETTABLE, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEReference(getHWCounter_Disable_callback(), this.getCallbackFunction(), null, "disable_callback", null, 0, 1, HWCounter.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_COMPOSITE, IS_RESOLVE_PROXIES, !IS_UNSETTABLE, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEReference(getHWCounter_Enable_callback(), this.getCallbackFunction(), null, "enable_callback", null, 0, 1, HWCounter.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_COMPOSITE, IS_RESOLVE_PROXIES, !IS_UNSETTABLE, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEReference(getHWCounter_Get_callback(), this.getCallbackFunction(), null, "get_callback", null, 1, 1, HWCounter.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_COMPOSITE, IS_RESOLVE_PROXIES, !IS_UNSETTABLE, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEReference(getHWCounter_Set_callback(), this.getCallbackFunction(), null, "set_callback", null, 1, 1, HWCounter.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_COMPOSITE, IS_RESOLVE_PROXIES, !IS_UNSETTABLE, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);

		initEClass(isrEClass, oscfg.ISR.class, "ISR", !IS_ABSTRACT, !IS_INTERFACE, IS_GENERATED_INSTANCE_CLASS);
		initEAttribute(getISR_IPL(), this.getIPLType(), "IPL", "1", 1, 1, oscfg.ISR.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, !IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEAttribute(getISR_Type(), this.getTypeType(), "type", "controlled", 1, 1, oscfg.ISR.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, IS_UNSETTABLE, !IS_ID, !IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEReference(getISR_ISRSource(), this.getInterruptSource(), this.getInterruptSource_SourceISR(), "ISRSource", null, 1, -1, oscfg.ISR.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_COMPOSITE, IS_RESOLVE_PROXIES, !IS_UNSETTABLE, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);

		initEClass(messageEClass, Message.class, "Message", !IS_ABSTRACT, !IS_INTERFACE, IS_GENERATED_INSTANCE_CLASS);
		initEAttribute(getMessage_Ctype(), theXMLTypePackage.getString(), "ctype", null, 0, 1, Message.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, !IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEAttribute(getMessage_Queue(), this.getQueueType(), "queue", "0", 0, 1, Message.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, !IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEReference(getMessage_Notifies(), this.getTask(), null, "Notifies", null, 0, 1, Message.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_COMPOSITE, IS_RESOLVE_PROXIES, !IS_UNSETTABLE, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEReference(getMessage_CallsBack(), this.getCallbackFunction(), null, "CallsBack", null, 0, 1, Message.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_COMPOSITE, IS_RESOLVE_PROXIES, !IS_UNSETTABLE, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);

		initEClass(mutexEClass, Mutex.class, "Mutex", !IS_ABSTRACT, !IS_INTERFACE, IS_GENERATED_INSTANCE_CLASS);

		initEClass(moduleEClass, Module.class, "Module", !IS_ABSTRACT, !IS_INTERFACE, IS_GENERATED_INSTANCE_CLASS);
		initEReference(getModule_ISRs(), this.getISR(), null, "ISRs", null, 0, -1, Module.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, IS_COMPOSITE, !IS_RESOLVE_PROXIES, !IS_UNSETTABLE, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEReference(getModule_Mutexs(), this.getMutex(), null, "Mutexs", null, 0, -1, Module.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, IS_COMPOSITE, !IS_RESOLVE_PROXIES, !IS_UNSETTABLE, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEReference(getModule_Messages(), this.getMessage(), null, "Messages", null, 0, -1, Module.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, IS_COMPOSITE, !IS_RESOLVE_PROXIES, !IS_UNSETTABLE, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEReference(getModule_HWCounters(), this.getHWCounter(), null, "HWCounters", null, 0, -1, Module.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, IS_COMPOSITE, !IS_RESOLVE_PROXIES, !IS_UNSETTABLE, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEReference(getModule_Callbacks(), this.getCallbackFunction(), null, "Callbacks", null, 0, -1, Module.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, IS_COMPOSITE, !IS_RESOLVE_PROXIES, !IS_UNSETTABLE, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEReference(getModule_InterruptSources(), this.getInterruptSource(), null, "InterruptSources", null, 0, 16, Module.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, IS_COMPOSITE, !IS_RESOLVE_PROXIES, !IS_UNSETTABLE, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEReference(getModule_Tasks(), this.getTask(), null, "Tasks", null, 0, 32, Module.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, IS_COMPOSITE, !IS_RESOLVE_PROXIES, !IS_UNSETTABLE, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEReference(getModule_CooperativeTaskGroups(), this.getCooperativeGroup(), null, "CooperativeTaskGroups", null, 0, -1, Module.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, IS_COMPOSITE, !IS_RESOLVE_PROXIES, !IS_UNSETTABLE, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);

		initEClass(swTimerEClass, SWTimer.class, "SWTimer", !IS_ABSTRACT, !IS_INTERFACE, IS_GENERATED_INSTANCE_CLASS);
		initEReference(getSWTimer_Activates(), this.getTask(), null, "Activates", null, 0, 1, SWTimer.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_COMPOSITE, IS_RESOLVE_PROXIES, !IS_UNSETTABLE, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEReference(getSWTimer_Timer_callback(), this.getCallbackFunction(), null, "timer_callback", null, 0, 1, SWTimer.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_COMPOSITE, IS_RESOLVE_PROXIES, !IS_UNSETTABLE, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);

		initEClass(taskEClass, Task.class, "Task", !IS_ABSTRACT, !IS_INTERFACE, IS_GENERATED_INSTANCE_CLASS);
		initEAttribute(getTask_Autostarted(), this.getAutostartedType(), "autostarted", "false", 0, 1, Task.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, IS_UNSETTABLE, !IS_ID, !IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEAttribute(getTask_Priority(), this.getTaskPriorityType(), "priority", "1", 1, 1, Task.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, !IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEReference(getTask_CooperativeGroup(), this.getCooperativeGroup(), this.getCooperativeGroup_CooperativeTasks(), "CooperativeGroup", null, 0, 1, Task.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_COMPOSITE, !IS_RESOLVE_PROXIES, !IS_UNSETTABLE, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);

		initEClass(baseTaskEClass, BaseTask.class, "BaseTask", IS_ABSTRACT, !IS_INTERFACE, IS_GENERATED_INSTANCE_CLASS);
		initEReference(getBaseTask_CollectMessage(), this.getMessage(), null, "CollectMessage", null, 0, -1, BaseTask.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_COMPOSITE, IS_RESOLVE_PROXIES, !IS_UNSETTABLE, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEReference(getBaseTask_EnterExitMutex(), this.getMutex(), null, "EnterExitMutex", null, 0, -1, BaseTask.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_COMPOSITE, IS_RESOLVE_PROXIES, !IS_UNSETTABLE, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);

		initEClass(interruptSourceEClass, InterruptSource.class, "InterruptSource", !IS_ABSTRACT, !IS_INTERFACE, IS_GENERATED_INSTANCE_CLASS);
		initEAttribute(getInterruptSource_Source(), this.getVectorType(), "source", "SystemController", 1, 1, InterruptSource.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, IS_UNSETTABLE, IS_ID, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEReference(getInterruptSource_SourceISR(), this.getISR(), this.getISR_ISRSource(), "SourceISR", null, 1, 1, InterruptSource.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_COMPOSITE, IS_RESOLVE_PROXIES, !IS_UNSETTABLE, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);

		initEClass(osEClass, oscfg.OS.class, "OS", !IS_ABSTRACT, !IS_INTERFACE, IS_GENERATED_INSTANCE_CLASS);
		initEAttribute(getOS_Target(), this.getTargetTypes(), "target", "JN516x", 1, 1, oscfg.OS.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEReference(getOS_Modules(), this.getModule(), null, "Modules", null, 1, -1, oscfg.OS.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, IS_COMPOSITE, !IS_RESOLVE_PROXIES, !IS_UNSETTABLE, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEAttribute(getOS_ErrorHook(), ecorePackage.getEBoolean(), "errorHook", "true", 1, 1, oscfg.OS.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEAttribute(getOS_StrictErrorChecks(), ecorePackage.getEBoolean(), "strictErrorChecks", "true", 1, 1, oscfg.OS.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);
		initEAttribute(getOS_ClearStack(), ecorePackage.getEBoolean(), "clearStack", "false", 1, 1, oscfg.OS.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_UNSETTABLE, !IS_ID, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);

		initEClass(cooperativeGroupEClass, CooperativeGroup.class, "CooperativeGroup", !IS_ABSTRACT, !IS_INTERFACE, IS_GENERATED_INSTANCE_CLASS);
		initEReference(getCooperativeGroup_CooperativeTasks(), this.getTask(), this.getTask_CooperativeGroup(), "CooperativeTasks", null, 2, 32, CooperativeGroup.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, IS_COMPOSITE, !IS_RESOLVE_PROXIES, !IS_UNSETTABLE, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);

		initEClass(namedObjectEClass, NamedObject.class, "NamedObject", IS_ABSTRACT, !IS_INTERFACE, IS_GENERATED_INSTANCE_CLASS);
		initEAttribute(getNamedObject_Name(), theXMLTypePackage.getString(), "name", null, 1, 1, NamedObject.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_UNSETTABLE, IS_ID, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);

		addEOperation(namedObjectEClass, ecorePackage.getEBoolean(), "verifyName", 0, 1, IS_UNIQUE, IS_ORDERED);

		initEClass(posterEClass, Poster.class, "Poster", IS_ABSTRACT, !IS_INTERFACE, IS_GENERATED_INSTANCE_CLASS);
		initEReference(getPoster_PostMessage(), this.getMessage(), null, "PostMessage", null, 0, -1, Poster.class, !IS_TRANSIENT, !IS_VOLATILE, IS_CHANGEABLE, !IS_COMPOSITE, IS_RESOLVE_PROXIES, !IS_UNSETTABLE, IS_UNIQUE, !IS_DERIVED, IS_ORDERED);

		// Initialize enums and add enum literals
		initEEnum(autostartedTypeEEnum, AutostartedType.class, "AutostartedType");
		addEEnumLiteral(autostartedTypeEEnum, AutostartedType.TRUE);
		addEEnumLiteral(autostartedTypeEEnum, AutostartedType.FALSE);

		initEEnum(typeTypeEEnum, TypeType.class, "TypeType");
		addEEnumLiteral(typeTypeEEnum, TypeType.CONTROLLED);
		addEEnumLiteral(typeTypeEEnum, TypeType.UNCONTROLLED);

		initEEnum(vectorTypeEEnum, VectorType.class, "VectorType");
		addEEnumLiteral(vectorTypeEEnum, VectorType.SYSTEM_CONTROLLER);
		addEEnumLiteral(vectorTypeEEnum, VectorType.BBC);
		addEEnumLiteral(vectorTypeEEnum, VectorType.AES);
		addEEnumLiteral(vectorTypeEEnum, VectorType.PHY);
		addEEnumLiteral(vectorTypeEEnum, VectorType.UART0);
		addEEnumLiteral(vectorTypeEEnum, VectorType.UART1);
		addEEnumLiteral(vectorTypeEEnum, VectorType.TIMER0);
		addEEnumLiteral(vectorTypeEEnum, VectorType.TIMER1);
		addEEnumLiteral(vectorTypeEEnum, VectorType.SERIAL_INTERFACE);
		addEEnumLiteral(vectorTypeEEnum, VectorType.SPI);
		addEEnumLiteral(vectorTypeEEnum, VectorType.INTELLIGENT_PERIPHERAL);
		addEEnumLiteral(vectorTypeEEnum, VectorType.ANALOGUE_PERIPHERAL);
		addEEnumLiteral(vectorTypeEEnum, VectorType.TIMER2);
		addEEnumLiteral(vectorTypeEEnum, VectorType.TICK_TIMER);
		addEEnumLiteral(vectorTypeEEnum, VectorType.SAMPLE_FIFO);
		addEEnumLiteral(vectorTypeEEnum, VectorType.DIGITAL_AUDIO_IF);
		addEEnumLiteral(vectorTypeEEnum, VectorType.BUS_ERROR);
		addEEnumLiteral(vectorTypeEEnum, VectorType.DATA_PAGE_FAULT);
		addEEnumLiteral(vectorTypeEEnum, VectorType.INSTRUCTION_PAGE_FAULT);
		addEEnumLiteral(vectorTypeEEnum, VectorType.TICK_TIMER_EXCEPTION);
		addEEnumLiteral(vectorTypeEEnum, VectorType.ALIGNMENT);
		addEEnumLiteral(vectorTypeEEnum, VectorType.ILLEGAL_INSTRUCTION);
		addEEnumLiteral(vectorTypeEEnum, VectorType.DTLB_MISS);
		addEEnumLiteral(vectorTypeEEnum, VectorType.ITLB_MISS);
		addEEnumLiteral(vectorTypeEEnum, VectorType.RANGE);
		addEEnumLiteral(vectorTypeEEnum, VectorType.SYSTEM_CALL);
		addEEnumLiteral(vectorTypeEEnum, VectorType.FLOATING_POINT);
		addEEnumLiteral(vectorTypeEEnum, VectorType.TRAP);
		addEEnumLiteral(vectorTypeEEnum, VectorType.UNIMPLEMENTED_MODULE);
		addEEnumLiteral(vectorTypeEEnum, VectorType.STACK_OVERFLOW_EXCEPTION);
		addEEnumLiteral(vectorTypeEEnum, VectorType.SPI_SLAVE);
		addEEnumLiteral(vectorTypeEEnum, VectorType.SPI_MASTER);
		addEEnumLiteral(vectorTypeEEnum, VectorType.I2C);
		addEEnumLiteral(vectorTypeEEnum, VectorType.TIMER3);
		addEEnumLiteral(vectorTypeEEnum, VectorType.TIMER4);

		initEEnum(targetTypesEEnum, TargetTypes.class, "TargetTypes");
		addEEnumLiteral(targetTypesEEnum, TargetTypes.JN51_6X);

		// Initialize data types
		initEDataType(autostartedTypeObjectEDataType, Enumerator.class, "AutostartedTypeObject", IS_SERIALIZABLE, !IS_GENERATED_INSTANCE_CLASS);
		initEDataType(typeTypeObjectEDataType, Enumerator.class, "TypeTypeObject", IS_SERIALIZABLE, !IS_GENERATED_INSTANCE_CLASS);
		initEDataType(vectorTypeObjectEDataType, Enumerator.class, "VectorTypeObject", IS_SERIALIZABLE, !IS_GENERATED_INSTANCE_CLASS);
		initEDataType(iplTypeEDataType, int.class, "IPLType", IS_SERIALIZABLE, !IS_GENERATED_INSTANCE_CLASS);
		initEDataType(queueTypeEDataType, int.class, "QueueType", IS_SERIALIZABLE, !IS_GENERATED_INSTANCE_CLASS);
		initEDataType(taskPriorityTypeEDataType, int.class, "TaskPriorityType", IS_SERIALIZABLE, !IS_GENERATED_INSTANCE_CLASS);

		// Create resource
		createResource(eNS_URI);

		// Create annotations
		// http:///org/eclipse/emf/ecore/util/ExtendedMetaData
		createExtendedMetaDataAnnotations();
	}

	/**
	 * Initializes the annotations for <b>http:///org/eclipse/emf/ecore/util/ExtendedMetaData</b>.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	protected void createExtendedMetaDataAnnotations() {
		String source = "http:///org/eclipse/emf/ecore/util/ExtendedMetaData";			
		addAnnotation
		  (this, 
		   source, 
		   new String[] {
			 "elementFormDefault", "qualified"
		   });		
		addAnnotation
		  (getConfiguration_OS(), 
		   source, 
		   new String[] {
			 "kind", "element",
			 "name", "OS",
			 "namespace", "##targetNamespace"
		   });		
		addAnnotation
		  (getDocumentRoot_Mixed(), 
		   source, 
		   new String[] {
			 "kind", "elementWildcard",
			 "name", ":mixed"
		   });		
		addAnnotation
		  (getDocumentRoot_XMLNSPrefixMap(), 
		   source, 
		   new String[] {
			 "kind", "attribute",
			 "name", "xmlns:prefix"
		   });		
		addAnnotation
		  (getDocumentRoot_XSISchemaLocation(), 
		   source, 
		   new String[] {
			 "kind", "attribute",
			 "name", "xsi:schemaLocation"
		   });		
		addAnnotation
		  (getDocumentRoot_Configuration(), 
		   source, 
		   new String[] {
			 "kind", "element",
			 "name", "Configuration",
			 "namespace", "##targetNamespace"
		   });		
		addAnnotation
		  (getHWCounter_SWTimers(), 
		   source, 
		   new String[] {
			 "kind", "element",
			 "name", "SWTimer"
		   });		
		addAnnotation
		  (getHWCounter_Disable_callback(), 
		   source, 
		   new String[] {
			 "namespace", "##targetNamespace"
		   });		
		addAnnotation
		  (getHWCounter_Enable_callback(), 
		   source, 
		   new String[] {
			 "namespace", "##targetNamespace"
		   });		
		addAnnotation
		  (getHWCounter_Get_callback(), 
		   source, 
		   new String[] {
			 "namespace", "##targetNamespace"
		   });		
		addAnnotation
		  (getHWCounter_Set_callback(), 
		   source, 
		   new String[] {
			 "namespace", "##targetNamespace"
		   });		
		addAnnotation
		  (getISR_IPL(), 
		   source, 
		   new String[] {
			 "kind", "attribute",
			 "name", "IPL",
			 "namespace", "##targetNamespace"
		   });		
		addAnnotation
		  (getISR_Type(), 
		   source, 
		   new String[] {
			 "kind", "attribute",
			 "name", "type",
			 "namespace", "##targetNamespace"
		   });		
		addAnnotation
		  (getMessage_Ctype(), 
		   source, 
		   new String[] {
			 "kind", "attribute",
			 "name", "ctype",
			 "namespace", "##targetNamespace"
		   });		
		addAnnotation
		  (getMessage_Queue(), 
		   source, 
		   new String[] {
			 "kind", "attribute",
			 "name", "queue",
			 "namespace", "##targetNamespace"
		   });		
		addAnnotation
		  (getMessage_Notifies(), 
		   source, 
		   new String[] {
			 "namespace", "##targetNamespace"
		   });		
		addAnnotation
		  (getMessage_CallsBack(), 
		   source, 
		   new String[] {
			 "namespace", "##targetNamespace"
		   });		
		addAnnotation
		  (getModule_ISRs(), 
		   source, 
		   new String[] {
			 "kind", "element",
			 "name", "ISR",
			 "namespace", "##targetNamespace"
		   });		
		addAnnotation
		  (getModule_Mutexs(), 
		   source, 
		   new String[] {
			 "kind", "element",
			 "name", "Mutex",
			 "namespace", "##targetNamespace"
		   });		
		addAnnotation
		  (getModule_Messages(), 
		   source, 
		   new String[] {
			 "kind", "element",
			 "name", "Message",
			 "namespace", "##targetNamespace"
		   });		
		addAnnotation
		  (getModule_HWCounters(), 
		   source, 
		   new String[] {
			 "kind", "element",
			 "name", "HWCounter"
		   });		
		addAnnotation
		  (getModule_Callbacks(), 
		   source, 
		   new String[] {
			 "namespace", "##targetNamespace"
		   });		
		addAnnotation
		  (getModule_InterruptSources(), 
		   source, 
		   new String[] {
			 "namespace", "##targetNamespace"
		   });		
		addAnnotation
		  (getModule_Tasks(), 
		   source, 
		   new String[] {
			 "kind", "element",
			 "name", "Task",
			 "namespace", "##targetNamespace"
		   });		
		addAnnotation
		  (getModule_CooperativeTaskGroups(), 
		   source, 
		   new String[] {
			 "namespace", "##targetNamespace"
		   });		
		addAnnotation
		  (getSWTimer_Activates(), 
		   source, 
		   new String[] {
			 "namespace", "##targetNamespace"
		   });		
		addAnnotation
		  (getTask_Autostarted(), 
		   source, 
		   new String[] {
			 "kind", "attribute",
			 "name", "autostarted",
			 "namespace", "##targetNamespace",
			 "nsPrefix", "oscfg",
			 "form", "qualified"
		   });		
		addAnnotation
		  (getTask_Priority(), 
		   source, 
		   new String[] {
			 "kind", "attribute",
			 "name", "priority",
			 "namespace", "##targetNamespace"
		   });		
		addAnnotation
		  (getBaseTask_EnterExitMutex(), 
		   source, 
		   new String[] {
			 "namespace", "##targetNamespace"
		   });		
		addAnnotation
		  (getInterruptSource_Source(), 
		   source, 
		   new String[] {
			 "kind", "attribute",
			 "name", "vector",
			 "namespace", "##targetNamespace"
		   });		
		addAnnotation
		  (getInterruptSource_SourceISR(), 
		   source, 
		   new String[] {
			 "namespace", "##targetNamespace"
		   });		
		addAnnotation
		  (getOS_Target(), 
		   source, 
		   new String[] {
			 "namespace", "##targetNamespace"
		   });		
		addAnnotation
		  (getOS_Modules(), 
		   source, 
		   new String[] {
			 "namespace", "##targetNamespace"
		   });		
		addAnnotation
		  (getOS_ErrorHook(), 
		   source, 
		   new String[] {
			 "namespace", "##targetNamespace"
		   });		
		addAnnotation
		  (getOS_StrictErrorChecks(), 
		   source, 
		   new String[] {
			 "namespace", "##targetNamespace"
		   });		
		addAnnotation
		  (getOS_ClearStack(), 
		   source, 
		   new String[] {
			 "namespace", "##targetNamespace"
		   });		
		addAnnotation
		  (getCooperativeGroup_CooperativeTasks(), 
		   source, 
		   new String[] {
			 "namespace", "##targetNamespace"
		   });			
		addAnnotation
		  (getNamedObject_Name(), 
		   source, 
		   new String[] {
			 "kind", "attribute",
			 "name", "name",
			 "namespace", "##targetNamespace"
		   });		
		addAnnotation
		  (iplTypeEDataType, 
		   source, 
		   new String[] {
			 "name", "IPLType",
			 "baseType", "int",
			 "minInclusive", "1",
			 "maxInclusive", "16"
		   });		
		addAnnotation
		  (queueTypeEDataType, 
		   source, 
		   new String[] {
			 "name", "QueueType",
			 "baseType", "int",
			 "minInclusive", "0",
			 "maxInclusive", "2147483647"
		   });		
		addAnnotation
		  (taskPriorityTypeEDataType, 
		   source, 
		   new String[] {
			 "name", "TaskPriorityType",
			 "baseType", "int",
			 "minInclusive", "1",
			 "maxInclusive", "2147483647"
		   });
	}

} //OscfgPackageImpl
