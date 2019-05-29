package oscfg.diagram.providers;

import java.util.HashSet;
import java.util.IdentityHashMap;
import java.util.Map;
import java.util.Set;

import org.eclipse.core.runtime.IAdaptable;
import org.eclipse.emf.ecore.EClass;
import org.eclipse.emf.ecore.EClassifier;
import org.eclipse.emf.ecore.ENamedElement;
import org.eclipse.emf.ecore.EStructuralFeature;
import org.eclipse.gmf.runtime.emf.type.core.ElementTypeRegistry;
import org.eclipse.gmf.runtime.emf.type.core.IElementType;
import org.eclipse.gmf.tooling.runtime.providers.DiagramElementTypeImages;
import org.eclipse.gmf.tooling.runtime.providers.DiagramElementTypes;
import org.eclipse.jface.resource.ImageDescriptor;
import org.eclipse.jface.resource.ImageRegistry;
import org.eclipse.swt.graphics.Image;

import oscfg.OscfgPackage;
import oscfg.diagram.edit.parts.BaseTaskCollectMessageEditPart;
import oscfg.diagram.edit.parts.BaseTaskEnterExitMutexEditPart;
import oscfg.diagram.edit.parts.CallbackFunctionEditPart;
import oscfg.diagram.edit.parts.ConfigurationEditPart;
import oscfg.diagram.edit.parts.CooperativeGroupEditPart;
import oscfg.diagram.edit.parts.HWCounterDisable_callbackEditPart;
import oscfg.diagram.edit.parts.HWCounterEditPart;
import oscfg.diagram.edit.parts.HWCounterEnable_callbackEditPart;
import oscfg.diagram.edit.parts.HWCounterGet_callbackEditPart;
import oscfg.diagram.edit.parts.HWCounterSet_callbackEditPart;
import oscfg.diagram.edit.parts.ISREditPart;
import oscfg.diagram.edit.parts.InterruptSourceEditPart;
import oscfg.diagram.edit.parts.InterruptSourceSourceISREditPart;
import oscfg.diagram.edit.parts.MessageEditPart;
import oscfg.diagram.edit.parts.MessageNotifiesEditPart;
import oscfg.diagram.edit.parts.ModuleEditPart;
import oscfg.diagram.edit.parts.MutexEditPart;
import oscfg.diagram.edit.parts.OSEditPart;
import oscfg.diagram.edit.parts.PosterPostMessageEditPart;
import oscfg.diagram.edit.parts.SWTimerActivatesEditPart;
import oscfg.diagram.edit.parts.SWTimerEditPart;
import oscfg.diagram.edit.parts.SWTimerTimer_callbackEditPart;
import oscfg.diagram.edit.parts.Task2EditPart;
import oscfg.diagram.edit.parts.TaskEditPart;
import oscfg.diagram.part.OscfgDiagramEditorPlugin;

/**
 * @generated
 */
public class OscfgElementTypes {

	/**
	 * @generated
	 */
	private OscfgElementTypes() {
	}

	/**
	 * @generated
	 */
	private static Map<IElementType, ENamedElement> elements;

	/**
	 * @generated
	 */
	private static DiagramElementTypeImages elementTypeImages = new DiagramElementTypeImages(
			OscfgDiagramEditorPlugin.getInstance()
					.getItemProvidersAdapterFactory());

	/**
	 * @generated
	 */
	private static Set<IElementType> KNOWN_ELEMENT_TYPES;

	/**
	 * @generated
	 */
	public static final IElementType Configuration_1000 = getElementType("com.jennic.OSConfigDiagramEditor.diagram.Configuration_1000"); //$NON-NLS-1$

	/**
	 * @generated
	 */
	public static final IElementType OS_2001 = getElementType("com.jennic.OSConfigDiagramEditor.diagram.OS_2001"); //$NON-NLS-1$

	/**
	 * @generated
	 */
	public static final IElementType Module_3009 = getElementType("com.jennic.OSConfigDiagramEditor.diagram.Module_3009"); //$NON-NLS-1$

	/**
	 * @generated
	 */
	public static final IElementType Task_3010 = getElementType("com.jennic.OSConfigDiagramEditor.diagram.Task_3010"); //$NON-NLS-1$

	/**
	 * @generated
	 */
	public static final IElementType ISR_3011 = getElementType("com.jennic.OSConfigDiagramEditor.diagram.ISR_3011"); //$NON-NLS-1$

	/**
	 * @generated
	 */
	public static final IElementType Mutex_3012 = getElementType("com.jennic.OSConfigDiagramEditor.diagram.Mutex_3012"); //$NON-NLS-1$

	/**
	 * @generated
	 */
	public static final IElementType Message_3013 = getElementType("com.jennic.OSConfigDiagramEditor.diagram.Message_3013"); //$NON-NLS-1$

	/**
	 * @generated
	 */
	public static final IElementType HWCounter_3014 = getElementType("com.jennic.OSConfigDiagramEditor.diagram.HWCounter_3014"); //$NON-NLS-1$

	/**
	 * @generated
	 */
	public static final IElementType SWTimer_3006 = getElementType("com.jennic.OSConfigDiagramEditor.diagram.SWTimer_3006"); //$NON-NLS-1$

	/**
	 * @generated
	 */
	public static final IElementType CallbackFunction_3015 = getElementType("com.jennic.OSConfigDiagramEditor.diagram.CallbackFunction_3015"); //$NON-NLS-1$

	/**
	 * @generated
	 */
	public static final IElementType InterruptSource_3016 = getElementType("com.jennic.OSConfigDiagramEditor.diagram.InterruptSource_3016"); //$NON-NLS-1$

	/**
	 * @generated
	 */
	public static final IElementType CooperativeGroup_3017 = getElementType("com.jennic.OSConfigDiagramEditor.diagram.CooperativeGroup_3017"); //$NON-NLS-1$

	/**
	 * @generated
	 */
	public static final IElementType Task_3020 = getElementType("com.jennic.OSConfigDiagramEditor.diagram.Task_3020"); //$NON-NLS-1$

	/**
	 * @generated
	 */
	public static final IElementType BaseTaskCollectMessage_4001 = getElementType("com.jennic.OSConfigDiagramEditor.diagram.BaseTaskCollectMessage_4001"); //$NON-NLS-1$

	/**
	 * @generated
	 */
	public static final IElementType PosterPostMessage_4012 = getElementType("com.jennic.OSConfigDiagramEditor.diagram.PosterPostMessage_4012"); //$NON-NLS-1$

	/**
	 * @generated
	 */
	public static final IElementType BaseTaskEnterExitMutex_4003 = getElementType("com.jennic.OSConfigDiagramEditor.diagram.BaseTaskEnterExitMutex_4003"); //$NON-NLS-1$

	/**
	 * @generated
	 */
	public static final IElementType SWTimerActivates_4004 = getElementType("com.jennic.OSConfigDiagramEditor.diagram.SWTimerActivates_4004"); //$NON-NLS-1$

	/**
	 * @generated
	 */
	public static final IElementType SWTimerTimer_callback_4005 = getElementType("com.jennic.OSConfigDiagramEditor.diagram.SWTimerTimer_callback_4005"); //$NON-NLS-1$

	/**
	 * @generated
	 */
	public static final IElementType MessageNotifies_4006 = getElementType("com.jennic.OSConfigDiagramEditor.diagram.MessageNotifies_4006"); //$NON-NLS-1$

	/**
	 * @generated
	 */
	public static final IElementType HWCounterEnable_callback_4007 = getElementType("com.jennic.OSConfigDiagramEditor.diagram.HWCounterEnable_callback_4007"); //$NON-NLS-1$

	/**
	 * @generated
	 */
	public static final IElementType HWCounterDisable_callback_4008 = getElementType("com.jennic.OSConfigDiagramEditor.diagram.HWCounterDisable_callback_4008"); //$NON-NLS-1$

	/**
	 * @generated
	 */
	public static final IElementType HWCounterGet_callback_4009 = getElementType("com.jennic.OSConfigDiagramEditor.diagram.HWCounterGet_callback_4009"); //$NON-NLS-1$

	/**
	 * @generated
	 */
	public static final IElementType HWCounterSet_callback_4010 = getElementType("com.jennic.OSConfigDiagramEditor.diagram.HWCounterSet_callback_4010"); //$NON-NLS-1$

	/**
	 * @generated
	 */
	public static final IElementType InterruptSourceSourceISR_4011 = getElementType("com.jennic.OSConfigDiagramEditor.diagram.InterruptSourceSourceISR_4011"); //$NON-NLS-1$

	/**
	 * @generated
	 */
	public static ImageDescriptor getImageDescriptor(ENamedElement element) {
		return elementTypeImages.getImageDescriptor(element);
	}

	/**
	 * @generated
	 */
	public static Image getImage(ENamedElement element) {
		return elementTypeImages.getImage(element);
	}

	/**
	 * @generated
	 */
	public static ImageDescriptor getImageDescriptor(IAdaptable hint) {
		return getImageDescriptor(getElement(hint));
	}

	/**
	 * @generated
	 */
	public static Image getImage(IAdaptable hint) {
		return getImage(getElement(hint));
	}

	/**
	 * Returns 'type' of the ecore object associated with the hint.
	 * 
	 * @generated
	 */
	public static ENamedElement getElement(IAdaptable hint) {
		Object type = hint.getAdapter(IElementType.class);
		if (elements == null) {
			elements = new IdentityHashMap<IElementType, ENamedElement>();

			elements.put(Configuration_1000,
					OscfgPackage.eINSTANCE.getConfiguration());

			elements.put(OS_2001, OscfgPackage.eINSTANCE.getOS());

			elements.put(Module_3009, OscfgPackage.eINSTANCE.getModule());

			elements.put(Task_3010, OscfgPackage.eINSTANCE.getTask());

			elements.put(ISR_3011, OscfgPackage.eINSTANCE.getISR());

			elements.put(Mutex_3012, OscfgPackage.eINSTANCE.getMutex());

			elements.put(Message_3013, OscfgPackage.eINSTANCE.getMessage());

			elements.put(HWCounter_3014, OscfgPackage.eINSTANCE.getHWCounter());

			elements.put(SWTimer_3006, OscfgPackage.eINSTANCE.getSWTimer());

			elements.put(CallbackFunction_3015,
					OscfgPackage.eINSTANCE.getCallbackFunction());

			elements.put(InterruptSource_3016,
					OscfgPackage.eINSTANCE.getInterruptSource());

			elements.put(CooperativeGroup_3017,
					OscfgPackage.eINSTANCE.getCooperativeGroup());

			elements.put(Task_3020, OscfgPackage.eINSTANCE.getTask());

			elements.put(BaseTaskCollectMessage_4001,
					OscfgPackage.eINSTANCE.getBaseTask_CollectMessage());

			elements.put(PosterPostMessage_4012,
					OscfgPackage.eINSTANCE.getPoster_PostMessage());

			elements.put(BaseTaskEnterExitMutex_4003,
					OscfgPackage.eINSTANCE.getBaseTask_EnterExitMutex());

			elements.put(SWTimerActivates_4004,
					OscfgPackage.eINSTANCE.getSWTimer_Activates());

			elements.put(SWTimerTimer_callback_4005,
					OscfgPackage.eINSTANCE.getSWTimer_Timer_callback());

			elements.put(MessageNotifies_4006,
					OscfgPackage.eINSTANCE.getMessage_Notifies());

			elements.put(HWCounterEnable_callback_4007,
					OscfgPackage.eINSTANCE.getHWCounter_Enable_callback());

			elements.put(HWCounterDisable_callback_4008,
					OscfgPackage.eINSTANCE.getHWCounter_Disable_callback());

			elements.put(HWCounterGet_callback_4009,
					OscfgPackage.eINSTANCE.getHWCounter_Get_callback());

			elements.put(HWCounterSet_callback_4010,
					OscfgPackage.eINSTANCE.getHWCounter_Set_callback());

			elements.put(InterruptSourceSourceISR_4011,
					OscfgPackage.eINSTANCE.getInterruptSource_SourceISR());
		}
		return (ENamedElement) elements.get(type);
	}

	/**
	 * @generated
	 */
	private static IElementType getElementType(String id) {
		return ElementTypeRegistry.getInstance().getType(id);
	}

	/**
	 * @generated
	 */
	public static boolean isKnownElementType(IElementType elementType) {
		if (KNOWN_ELEMENT_TYPES == null) {
			KNOWN_ELEMENT_TYPES = new HashSet<IElementType>();
			KNOWN_ELEMENT_TYPES.add(Configuration_1000);
			KNOWN_ELEMENT_TYPES.add(OS_2001);
			KNOWN_ELEMENT_TYPES.add(Module_3009);
			KNOWN_ELEMENT_TYPES.add(Task_3010);
			KNOWN_ELEMENT_TYPES.add(ISR_3011);
			KNOWN_ELEMENT_TYPES.add(Mutex_3012);
			KNOWN_ELEMENT_TYPES.add(Message_3013);
			KNOWN_ELEMENT_TYPES.add(HWCounter_3014);
			KNOWN_ELEMENT_TYPES.add(SWTimer_3006);
			KNOWN_ELEMENT_TYPES.add(CallbackFunction_3015);
			KNOWN_ELEMENT_TYPES.add(InterruptSource_3016);
			KNOWN_ELEMENT_TYPES.add(CooperativeGroup_3017);
			KNOWN_ELEMENT_TYPES.add(Task_3020);
			KNOWN_ELEMENT_TYPES.add(BaseTaskCollectMessage_4001);
			KNOWN_ELEMENT_TYPES.add(PosterPostMessage_4012);
			KNOWN_ELEMENT_TYPES.add(BaseTaskEnterExitMutex_4003);
			KNOWN_ELEMENT_TYPES.add(SWTimerActivates_4004);
			KNOWN_ELEMENT_TYPES.add(SWTimerTimer_callback_4005);
			KNOWN_ELEMENT_TYPES.add(MessageNotifies_4006);
			KNOWN_ELEMENT_TYPES.add(HWCounterEnable_callback_4007);
			KNOWN_ELEMENT_TYPES.add(HWCounterDisable_callback_4008);
			KNOWN_ELEMENT_TYPES.add(HWCounterGet_callback_4009);
			KNOWN_ELEMENT_TYPES.add(HWCounterSet_callback_4010);
			KNOWN_ELEMENT_TYPES.add(InterruptSourceSourceISR_4011);
		}
		return KNOWN_ELEMENT_TYPES.contains(elementType);
	}

	/**
	 * @generated
	 */
	public static IElementType getElementType(int visualID) {
		switch (visualID) {
		case ConfigurationEditPart.VISUAL_ID:
			return Configuration_1000;
		case OSEditPart.VISUAL_ID:
			return OS_2001;
		case ModuleEditPart.VISUAL_ID:
			return Module_3009;
		case TaskEditPart.VISUAL_ID:
			return Task_3010;
		case ISREditPart.VISUAL_ID:
			return ISR_3011;
		case MutexEditPart.VISUAL_ID:
			return Mutex_3012;
		case MessageEditPart.VISUAL_ID:
			return Message_3013;
		case HWCounterEditPart.VISUAL_ID:
			return HWCounter_3014;
		case SWTimerEditPart.VISUAL_ID:
			return SWTimer_3006;
		case CallbackFunctionEditPart.VISUAL_ID:
			return CallbackFunction_3015;
		case InterruptSourceEditPart.VISUAL_ID:
			return InterruptSource_3016;
		case CooperativeGroupEditPart.VISUAL_ID:
			return CooperativeGroup_3017;
		case Task2EditPart.VISUAL_ID:
			return Task_3020;
		case BaseTaskCollectMessageEditPart.VISUAL_ID:
			return BaseTaskCollectMessage_4001;
		case PosterPostMessageEditPart.VISUAL_ID:
			return PosterPostMessage_4012;
		case BaseTaskEnterExitMutexEditPart.VISUAL_ID:
			return BaseTaskEnterExitMutex_4003;
		case SWTimerActivatesEditPart.VISUAL_ID:
			return SWTimerActivates_4004;
		case SWTimerTimer_callbackEditPart.VISUAL_ID:
			return SWTimerTimer_callback_4005;
		case MessageNotifiesEditPart.VISUAL_ID:
			return MessageNotifies_4006;
		case HWCounterEnable_callbackEditPart.VISUAL_ID:
			return HWCounterEnable_callback_4007;
		case HWCounterDisable_callbackEditPart.VISUAL_ID:
			return HWCounterDisable_callback_4008;
		case HWCounterGet_callbackEditPart.VISUAL_ID:
			return HWCounterGet_callback_4009;
		case HWCounterSet_callbackEditPart.VISUAL_ID:
			return HWCounterSet_callback_4010;
		case InterruptSourceSourceISREditPart.VISUAL_ID:
			return InterruptSourceSourceISR_4011;
		}
		return null;
	}

	/**
	 * @generated
	 */
	public static final DiagramElementTypes TYPED_INSTANCE = new DiagramElementTypes(
			elementTypeImages) {

		/**
		 * @generated
		 */
		@Override
		public boolean isKnownElementType(IElementType elementType) {
			return oscfg.diagram.providers.OscfgElementTypes
					.isKnownElementType(elementType);
		}

		/**
		 * @generated
		 */
		@Override
		public IElementType getElementTypeForVisualId(int visualID) {
			return oscfg.diagram.providers.OscfgElementTypes
					.getElementType(visualID);
		}

		/**
		 * @generated
		 */
		@Override
		public ENamedElement getDefiningNamedElement(
				IAdaptable elementTypeAdapter) {
			return oscfg.diagram.providers.OscfgElementTypes
					.getElement(elementTypeAdapter);
		}
	};

}
