package oscfg.diagram.part;

import org.eclipse.core.runtime.Platform;
import org.eclipse.emf.ecore.EAnnotation;
import org.eclipse.emf.ecore.EObject;
import org.eclipse.gmf.runtime.notation.Diagram;
import org.eclipse.gmf.runtime.notation.View;

import org.eclipse.gmf.tooling.runtime.structure.DiagramStructure;
import oscfg.Configuration;
import oscfg.OscfgPackage;
import oscfg.diagram.edit.parts.BaseTaskCollectMessageEditPart;
import oscfg.diagram.edit.parts.BaseTaskEnterExitMutexEditPart;
import oscfg.diagram.edit.parts.CallbackFunctionEditPart;
import oscfg.diagram.edit.parts.CallbackFunctionNameEditPart;
import oscfg.diagram.edit.parts.ConfigurationEditPart;
import oscfg.diagram.edit.parts.CooperativeGroupCooperativeTasksEditPart;
import oscfg.diagram.edit.parts.CooperativeGroupEditPart;
import oscfg.diagram.edit.parts.CooperativeGroupNameEditPart;
import oscfg.diagram.edit.parts.HWCounterDisable_callbackEditPart;
import oscfg.diagram.edit.parts.HWCounterEditPart;
import oscfg.diagram.edit.parts.HWCounterEnable_callbackEditPart;
import oscfg.diagram.edit.parts.HWCounterGet_callbackEditPart;
import oscfg.diagram.edit.parts.HWCounterNameEditPart;
import oscfg.diagram.edit.parts.HWCounterSet_callbackEditPart;
import oscfg.diagram.edit.parts.HWCounterSoftwareTimersEditPart;
import oscfg.diagram.edit.parts.ISREditPart;
import oscfg.diagram.edit.parts.ISRIPLEditPart;
import oscfg.diagram.edit.parts.ISRNameEditPart;
import oscfg.diagram.edit.parts.ISRTypeEditPart;
import oscfg.diagram.edit.parts.InterruptSourceEditPart;
import oscfg.diagram.edit.parts.InterruptSourceSourceEditPart;
import oscfg.diagram.edit.parts.InterruptSourceSourceISREditPart;
import oscfg.diagram.edit.parts.MessageCtypeEditPart;
import oscfg.diagram.edit.parts.MessageEditPart;
import oscfg.diagram.edit.parts.MessageNameEditPart;
import oscfg.diagram.edit.parts.MessageNotifiesEditPart;
import oscfg.diagram.edit.parts.MessageQueueEditPart;
import oscfg.diagram.edit.parts.ModuleEditPart;
import oscfg.diagram.edit.parts.ModuleModuleObjectsEditPart;
import oscfg.diagram.edit.parts.ModuleNameEditPart;
import oscfg.diagram.edit.parts.MutexEditPart;
import oscfg.diagram.edit.parts.MutexNameEditPart;
import oscfg.diagram.edit.parts.OSEditPart;
import oscfg.diagram.edit.parts.OSOSModulesEditPart;
import oscfg.diagram.edit.parts.OSTargetEditPart;
import oscfg.diagram.edit.parts.PosterPostMessageEditPart;
import oscfg.diagram.edit.parts.SWTimerActivatesEditPart;
import oscfg.diagram.edit.parts.SWTimerEditPart;
import oscfg.diagram.edit.parts.SWTimerNameEditPart;
import oscfg.diagram.edit.parts.SWTimerTimer_callbackEditPart;
import oscfg.diagram.edit.parts.Task2EditPart;
import oscfg.diagram.edit.parts.TaskAutostarted2EditPart;
import oscfg.diagram.edit.parts.TaskAutostartedEditPart;
import oscfg.diagram.edit.parts.TaskEditPart;
import oscfg.diagram.edit.parts.TaskName2EditPart;
import oscfg.diagram.edit.parts.TaskNameEditPart;
import oscfg.diagram.edit.parts.TaskPriority2EditPart;
import oscfg.diagram.edit.parts.TaskPriorityEditPart;
import oscfg.diagram.edit.parts.WrappingLabel10EditPart;
import oscfg.diagram.edit.parts.WrappingLabel11EditPart;
import oscfg.diagram.edit.parts.WrappingLabel2EditPart;
import oscfg.diagram.edit.parts.WrappingLabel3EditPart;
import oscfg.diagram.edit.parts.WrappingLabel4EditPart;
import oscfg.diagram.edit.parts.WrappingLabel5EditPart;
import oscfg.diagram.edit.parts.WrappingLabel6EditPart;
import oscfg.diagram.edit.parts.WrappingLabel7EditPart;
import oscfg.diagram.edit.parts.WrappingLabel8EditPart;
import oscfg.diagram.edit.parts.WrappingLabel9EditPart;
import oscfg.diagram.edit.parts.WrappingLabelEditPart;

/**
 * This registry is used to determine which type of visual object should be
 * created for the corresponding Diagram, Node, ChildNode or Link represented
 * by a domain model object.
 * 
 * @generated
 */
public class OscfgVisualIDRegistry {

	/**
	 * @generated
	 */
	private static final String DEBUG_KEY = "com.jennic.OSConfigDiagramEditor.diagram/debug/visualID"; //$NON-NLS-1$

	/**
	 * @generated
	 */
	public static int getVisualID(View view) {
		if (view instanceof Diagram) {
			if (ConfigurationEditPart.MODEL_ID.equals(view.getType())) {
				return ConfigurationEditPart.VISUAL_ID;
			} else {
				return -1;
			}
		}
		return oscfg.diagram.part.OscfgVisualIDRegistry.getVisualID(view
				.getType());
	}

	/**
	 * @generated
	 */
	public static String getModelID(View view) {
		View diagram = view.getDiagram();
		while (view != diagram) {
			EAnnotation annotation = view.getEAnnotation("Shortcut"); //$NON-NLS-1$
			if (annotation != null) {
				return (String) annotation.getDetails().get("modelID"); //$NON-NLS-1$
			}
			view = (View) view.eContainer();
		}
		return diagram != null ? diagram.getType() : null;
	}

	/**
	 * @generated
	 */
	public static int getVisualID(String type) {
		try {
			return Integer.parseInt(type);
		} catch (NumberFormatException e) {
			if (Boolean.TRUE.toString().equalsIgnoreCase(
					Platform.getDebugOption(DEBUG_KEY))) {
				OscfgDiagramEditorPlugin.getInstance().logError(
						"Unable to parse view type as a visualID number: "
								+ type);
			}
		}
		return -1;
	}

	/**
	 * @generated
	 */
	public static String getType(int visualID) {
		return Integer.toString(visualID);
	}

	/**
	 * @generated
	 */
	public static int getDiagramVisualID(EObject domainElement) {
		if (domainElement == null) {
			return -1;
		}
		if (OscfgPackage.eINSTANCE.getConfiguration().isSuperTypeOf(
				domainElement.eClass())
				&& isDiagram((Configuration) domainElement)) {
			return ConfigurationEditPart.VISUAL_ID;
		}
		return -1;
	}

	/**
	 * @generated
	 */
	public static int getNodeVisualID(View containerView, EObject domainElement) {
		if (domainElement == null) {
			return -1;
		}
		String containerModelID = oscfg.diagram.part.OscfgVisualIDRegistry
				.getModelID(containerView);
		if (!ConfigurationEditPart.MODEL_ID.equals(containerModelID)) {
			return -1;
		}
		int containerVisualID;
		if (ConfigurationEditPart.MODEL_ID.equals(containerModelID)) {
			containerVisualID = oscfg.diagram.part.OscfgVisualIDRegistry
					.getVisualID(containerView);
		} else {
			if (containerView instanceof Diagram) {
				containerVisualID = ConfigurationEditPart.VISUAL_ID;
			} else {
				return -1;
			}
		}
		switch (containerVisualID) {
		case ConfigurationEditPart.VISUAL_ID:
			if (OscfgPackage.eINSTANCE.getOS().isSuperTypeOf(
					domainElement.eClass())) {
				return OSEditPart.VISUAL_ID;
			}
			break;
		case OSOSModulesEditPart.VISUAL_ID:
			if (OscfgPackage.eINSTANCE.getModule().isSuperTypeOf(
					domainElement.eClass())) {
				return ModuleEditPart.VISUAL_ID;
			}
			break;
		case ModuleModuleObjectsEditPart.VISUAL_ID:
			if (OscfgPackage.eINSTANCE.getTask().isSuperTypeOf(
					domainElement.eClass())) {
				return TaskEditPart.VISUAL_ID;
			}
			if (OscfgPackage.eINSTANCE.getISR().isSuperTypeOf(
					domainElement.eClass())) {
				return ISREditPart.VISUAL_ID;
			}
			if (OscfgPackage.eINSTANCE.getMutex().isSuperTypeOf(
					domainElement.eClass())) {
				return MutexEditPart.VISUAL_ID;
			}
			if (OscfgPackage.eINSTANCE.getMessage().isSuperTypeOf(
					domainElement.eClass())) {
				return MessageEditPart.VISUAL_ID;
			}
			if (OscfgPackage.eINSTANCE.getHWCounter().isSuperTypeOf(
					domainElement.eClass())) {
				return HWCounterEditPart.VISUAL_ID;
			}
			if (OscfgPackage.eINSTANCE.getCallbackFunction().isSuperTypeOf(
					domainElement.eClass())) {
				return CallbackFunctionEditPart.VISUAL_ID;
			}
			if (OscfgPackage.eINSTANCE.getInterruptSource().isSuperTypeOf(
					domainElement.eClass())) {
				return InterruptSourceEditPart.VISUAL_ID;
			}
			if (OscfgPackage.eINSTANCE.getCooperativeGroup().isSuperTypeOf(
					domainElement.eClass())) {
				return CooperativeGroupEditPart.VISUAL_ID;
			}
			break;
		case HWCounterSoftwareTimersEditPart.VISUAL_ID:
			if (OscfgPackage.eINSTANCE.getSWTimer().isSuperTypeOf(
					domainElement.eClass())) {
				return SWTimerEditPart.VISUAL_ID;
			}
			break;
		case CooperativeGroupCooperativeTasksEditPart.VISUAL_ID:
			if (OscfgPackage.eINSTANCE.getTask().isSuperTypeOf(
					domainElement.eClass())) {
				return Task2EditPart.VISUAL_ID;
			}
			break;
		}
		return -1;
	}

	/**
	 * @generated
	 */
	public static boolean canCreateNode(View containerView, int nodeVisualID) {
		String containerModelID = oscfg.diagram.part.OscfgVisualIDRegistry
				.getModelID(containerView);
		if (!ConfigurationEditPart.MODEL_ID.equals(containerModelID)) {
			return false;
		}
		int containerVisualID;
		if (ConfigurationEditPart.MODEL_ID.equals(containerModelID)) {
			containerVisualID = oscfg.diagram.part.OscfgVisualIDRegistry
					.getVisualID(containerView);
		} else {
			if (containerView instanceof Diagram) {
				containerVisualID = ConfigurationEditPart.VISUAL_ID;
			} else {
				return false;
			}
		}
		switch (containerVisualID) {
		case ConfigurationEditPart.VISUAL_ID:
			if (OSEditPart.VISUAL_ID == nodeVisualID) {
				return true;
			}
			break;
		case OSEditPart.VISUAL_ID:
			if (OSTargetEditPart.VISUAL_ID == nodeVisualID) {
				return true;
			}
			if (OSOSModulesEditPart.VISUAL_ID == nodeVisualID) {
				return true;
			}
			break;
		case ModuleEditPart.VISUAL_ID:
			if (ModuleNameEditPart.VISUAL_ID == nodeVisualID) {
				return true;
			}
			if (ModuleModuleObjectsEditPart.VISUAL_ID == nodeVisualID) {
				return true;
			}
			break;
		case TaskEditPart.VISUAL_ID:
			if (TaskNameEditPart.VISUAL_ID == nodeVisualID) {
				return true;
			}
			if (TaskPriorityEditPart.VISUAL_ID == nodeVisualID) {
				return true;
			}
			if (TaskAutostartedEditPart.VISUAL_ID == nodeVisualID) {
				return true;
			}
			break;
		case ISREditPart.VISUAL_ID:
			if (ISRNameEditPart.VISUAL_ID == nodeVisualID) {
				return true;
			}
			if (ISRTypeEditPart.VISUAL_ID == nodeVisualID) {
				return true;
			}
			if (ISRIPLEditPart.VISUAL_ID == nodeVisualID) {
				return true;
			}
			break;
		case MutexEditPart.VISUAL_ID:
			if (MutexNameEditPart.VISUAL_ID == nodeVisualID) {
				return true;
			}
			break;
		case MessageEditPart.VISUAL_ID:
			if (MessageNameEditPart.VISUAL_ID == nodeVisualID) {
				return true;
			}
			if (MessageCtypeEditPart.VISUAL_ID == nodeVisualID) {
				return true;
			}
			if (MessageQueueEditPart.VISUAL_ID == nodeVisualID) {
				return true;
			}
			break;
		case HWCounterEditPart.VISUAL_ID:
			if (HWCounterNameEditPart.VISUAL_ID == nodeVisualID) {
				return true;
			}
			if (HWCounterSoftwareTimersEditPart.VISUAL_ID == nodeVisualID) {
				return true;
			}
			break;
		case SWTimerEditPart.VISUAL_ID:
			if (SWTimerNameEditPart.VISUAL_ID == nodeVisualID) {
				return true;
			}
			break;
		case CallbackFunctionEditPart.VISUAL_ID:
			if (CallbackFunctionNameEditPart.VISUAL_ID == nodeVisualID) {
				return true;
			}
			break;
		case InterruptSourceEditPart.VISUAL_ID:
			if (InterruptSourceSourceEditPart.VISUAL_ID == nodeVisualID) {
				return true;
			}
			break;
		case CooperativeGroupEditPart.VISUAL_ID:
			if (CooperativeGroupNameEditPart.VISUAL_ID == nodeVisualID) {
				return true;
			}
			if (CooperativeGroupCooperativeTasksEditPart.VISUAL_ID == nodeVisualID) {
				return true;
			}
			break;
		case Task2EditPart.VISUAL_ID:
			if (TaskName2EditPart.VISUAL_ID == nodeVisualID) {
				return true;
			}
			if (TaskPriority2EditPart.VISUAL_ID == nodeVisualID) {
				return true;
			}
			if (TaskAutostarted2EditPart.VISUAL_ID == nodeVisualID) {
				return true;
			}
			break;
		case OSOSModulesEditPart.VISUAL_ID:
			if (ModuleEditPart.VISUAL_ID == nodeVisualID) {
				return true;
			}
			break;
		case ModuleModuleObjectsEditPart.VISUAL_ID:
			if (TaskEditPart.VISUAL_ID == nodeVisualID) {
				return true;
			}
			if (ISREditPart.VISUAL_ID == nodeVisualID) {
				return true;
			}
			if (MutexEditPart.VISUAL_ID == nodeVisualID) {
				return true;
			}
			if (MessageEditPart.VISUAL_ID == nodeVisualID) {
				return true;
			}
			if (HWCounterEditPart.VISUAL_ID == nodeVisualID) {
				return true;
			}
			if (CallbackFunctionEditPart.VISUAL_ID == nodeVisualID) {
				return true;
			}
			if (InterruptSourceEditPart.VISUAL_ID == nodeVisualID) {
				return true;
			}
			if (CooperativeGroupEditPart.VISUAL_ID == nodeVisualID) {
				return true;
			}
			break;
		case HWCounterSoftwareTimersEditPart.VISUAL_ID:
			if (SWTimerEditPart.VISUAL_ID == nodeVisualID) {
				return true;
			}
			break;
		case CooperativeGroupCooperativeTasksEditPart.VISUAL_ID:
			if (Task2EditPart.VISUAL_ID == nodeVisualID) {
				return true;
			}
			break;
		case BaseTaskCollectMessageEditPart.VISUAL_ID:
			if (WrappingLabelEditPart.VISUAL_ID == nodeVisualID) {
				return true;
			}
			break;
		case PosterPostMessageEditPart.VISUAL_ID:
			if (WrappingLabel2EditPart.VISUAL_ID == nodeVisualID) {
				return true;
			}
			break;
		case BaseTaskEnterExitMutexEditPart.VISUAL_ID:
			if (WrappingLabel3EditPart.VISUAL_ID == nodeVisualID) {
				return true;
			}
			break;
		case SWTimerActivatesEditPart.VISUAL_ID:
			if (WrappingLabel4EditPart.VISUAL_ID == nodeVisualID) {
				return true;
			}
			break;
		case SWTimerTimer_callbackEditPart.VISUAL_ID:
			if (WrappingLabel5EditPart.VISUAL_ID == nodeVisualID) {
				return true;
			}
			break;
		case MessageNotifiesEditPart.VISUAL_ID:
			if (WrappingLabel6EditPart.VISUAL_ID == nodeVisualID) {
				return true;
			}
			break;
		case HWCounterEnable_callbackEditPart.VISUAL_ID:
			if (WrappingLabel7EditPart.VISUAL_ID == nodeVisualID) {
				return true;
			}
			break;
		case HWCounterDisable_callbackEditPart.VISUAL_ID:
			if (WrappingLabel8EditPart.VISUAL_ID == nodeVisualID) {
				return true;
			}
			break;
		case HWCounterGet_callbackEditPart.VISUAL_ID:
			if (WrappingLabel9EditPart.VISUAL_ID == nodeVisualID) {
				return true;
			}
			break;
		case HWCounterSet_callbackEditPart.VISUAL_ID:
			if (WrappingLabel10EditPart.VISUAL_ID == nodeVisualID) {
				return true;
			}
			break;
		case InterruptSourceSourceISREditPart.VISUAL_ID:
			if (WrappingLabel11EditPart.VISUAL_ID == nodeVisualID) {
				return true;
			}
			break;
		}
		return false;
	}

	/**
	 * @generated
	 */
	public static int getLinkWithClassVisualID(EObject domainElement) {
		if (domainElement == null) {
			return -1;
		}
		return -1;
	}

	/**
	 * User can change implementation of this method to handle some specific
	 * situations not covered by default logic.
	 * 
	 * @generated
	 */
	private static boolean isDiagram(Configuration element) {
		return true;
	}

	/**
	 * @generated
	 */
	public static boolean checkNodeVisualID(View containerView,
			EObject domainElement, int candidate) {
		if (candidate == -1) {
			//unrecognized id is always bad
			return false;
		}
		int basic = getNodeVisualID(containerView, domainElement);
		return basic == candidate;
	}

	/**
	 * @generated
	 */
	public static boolean isCompartmentVisualID(int visualID) {
		switch (visualID) {
		case OSOSModulesEditPart.VISUAL_ID:
		case ModuleModuleObjectsEditPart.VISUAL_ID:
		case HWCounterSoftwareTimersEditPart.VISUAL_ID:
		case CooperativeGroupCooperativeTasksEditPart.VISUAL_ID:
			return true;
		default:
			break;
		}
		return false;
	}

	/**
	 * @generated
	 */
	public static boolean isSemanticLeafVisualID(int visualID) {
		switch (visualID) {
		case ConfigurationEditPart.VISUAL_ID:
			return false;
		case SWTimerEditPart.VISUAL_ID:
		case TaskEditPart.VISUAL_ID:
		case ISREditPart.VISUAL_ID:
		case MutexEditPart.VISUAL_ID:
		case MessageEditPart.VISUAL_ID:
		case CallbackFunctionEditPart.VISUAL_ID:
		case InterruptSourceEditPart.VISUAL_ID:
		case Task2EditPart.VISUAL_ID:
			return true;
		default:
			break;
		}
		return false;
	}

	/**
	 * @generated
	 */
	public static final DiagramStructure TYPED_INSTANCE = new DiagramStructure() {
		/**
		 * @generated
		 */
		@Override
		public int getVisualID(View view) {
			return oscfg.diagram.part.OscfgVisualIDRegistry.getVisualID(view);
		}

		/**
		 * @generated
		 */
		@Override
		public String getModelID(View view) {
			return oscfg.diagram.part.OscfgVisualIDRegistry.getModelID(view);
		}

		/**
		 * @generated
		 */
		@Override
		public int getNodeVisualID(View containerView, EObject domainElement) {
			return oscfg.diagram.part.OscfgVisualIDRegistry.getNodeVisualID(
					containerView, domainElement);
		}

		/**
		 * @generated
		 */
		@Override
		public boolean checkNodeVisualID(View containerView,
				EObject domainElement, int candidate) {
			return oscfg.diagram.part.OscfgVisualIDRegistry.checkNodeVisualID(
					containerView, domainElement, candidate);
		}

		/**
		 * @generated
		 */
		@Override
		public boolean isCompartmentVisualID(int visualID) {
			return oscfg.diagram.part.OscfgVisualIDRegistry
					.isCompartmentVisualID(visualID);
		}

		/**
		 * @generated
		 */
		@Override
		public boolean isSemanticLeafVisualID(int visualID) {
			return oscfg.diagram.part.OscfgVisualIDRegistry
					.isSemanticLeafVisualID(visualID);
		}
	};

}
