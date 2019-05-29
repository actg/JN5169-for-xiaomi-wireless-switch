package oscfg.diagram.part;

import java.util.Collection;
import java.util.Collections;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;

import org.eclipse.emf.ecore.EObject;
import org.eclipse.emf.ecore.EStructuralFeature;
import org.eclipse.emf.ecore.util.EcoreUtil;
import org.eclipse.gmf.runtime.notation.View;

import org.eclipse.gmf.tooling.runtime.update.DiagramUpdater;
import oscfg.BaseTask;
import oscfg.CallbackFunction;
import oscfg.Configuration;
import oscfg.CooperativeGroup;
import oscfg.HWCounter;
import oscfg.InterruptSource;
import oscfg.Message;
import oscfg.Module;
import oscfg.Mutex;
import oscfg.OscfgPackage;
import oscfg.Poster;
import oscfg.SWTimer;
import oscfg.Task;
import oscfg.diagram.edit.parts.BaseTaskCollectMessageEditPart;
import oscfg.diagram.edit.parts.BaseTaskEnterExitMutexEditPart;
import oscfg.diagram.edit.parts.CallbackFunctionEditPart;
import oscfg.diagram.edit.parts.ConfigurationEditPart;
import oscfg.diagram.edit.parts.CooperativeGroupCooperativeTasksEditPart;
import oscfg.diagram.edit.parts.CooperativeGroupEditPart;
import oscfg.diagram.edit.parts.HWCounterDisable_callbackEditPart;
import oscfg.diagram.edit.parts.HWCounterEditPart;
import oscfg.diagram.edit.parts.HWCounterEnable_callbackEditPart;
import oscfg.diagram.edit.parts.HWCounterGet_callbackEditPart;
import oscfg.diagram.edit.parts.HWCounterSet_callbackEditPart;
import oscfg.diagram.edit.parts.HWCounterSoftwareTimersEditPart;
import oscfg.diagram.edit.parts.ISREditPart;
import oscfg.diagram.edit.parts.InterruptSourceEditPart;
import oscfg.diagram.edit.parts.InterruptSourceSourceISREditPart;
import oscfg.diagram.edit.parts.MessageEditPart;
import oscfg.diagram.edit.parts.MessageNotifiesEditPart;
import oscfg.diagram.edit.parts.ModuleEditPart;
import oscfg.diagram.edit.parts.ModuleModuleObjectsEditPart;
import oscfg.diagram.edit.parts.MutexEditPart;
import oscfg.diagram.edit.parts.OSEditPart;
import oscfg.diagram.edit.parts.OSOSModulesEditPart;
import oscfg.diagram.edit.parts.PosterPostMessageEditPart;
import oscfg.diagram.edit.parts.SWTimerActivatesEditPart;
import oscfg.diagram.edit.parts.SWTimerEditPart;
import oscfg.diagram.edit.parts.SWTimerTimer_callbackEditPart;
import oscfg.diagram.edit.parts.Task2EditPart;
import oscfg.diagram.edit.parts.TaskEditPart;
import oscfg.diagram.providers.OscfgElementTypes;

/**
 * @generated
 */
public class OscfgDiagramUpdater {

	/**
	 * @generated
	 */
	public static List<OscfgNodeDescriptor> getSemanticChildren(View view) {
		switch (OscfgVisualIDRegistry.getVisualID(view)) {
		case ConfigurationEditPart.VISUAL_ID:
			return getConfiguration_1000SemanticChildren(view);
		case OSOSModulesEditPart.VISUAL_ID:
			return getOSOSModules_7001SemanticChildren(view);
		case ModuleModuleObjectsEditPart.VISUAL_ID:
			return getModuleModuleObjects_7003SemanticChildren(view);
		case HWCounterSoftwareTimersEditPart.VISUAL_ID:
			return getHWCounterSoftwareTimers_7004SemanticChildren(view);
		case CooperativeGroupCooperativeTasksEditPart.VISUAL_ID:
			return getCooperativeGroupCooperativeTasks_7005SemanticChildren(view);
		}
		return Collections.emptyList();
	}

	/**
	 * @generated
	 */
	public static List<OscfgNodeDescriptor> getOSOSModules_7001SemanticChildren(
			View view) {
		if (false == view.eContainer() instanceof View) {
			return Collections.emptyList();
		}
		View containerView = (View) view.eContainer();
		if (!containerView.isSetElement()) {
			return Collections.emptyList();
		}
		oscfg.OS modelElement = (oscfg.OS) containerView.getElement();
		LinkedList<OscfgNodeDescriptor> result = new LinkedList<OscfgNodeDescriptor>();
		for (Iterator<?> it = modelElement.getModules().iterator(); it
				.hasNext();) {
			Module childElement = (Module) it.next();
			int visualID = OscfgVisualIDRegistry.getNodeVisualID(view,
					childElement);
			if (visualID == ModuleEditPart.VISUAL_ID) {
				result.add(new OscfgNodeDescriptor(childElement, visualID));
				continue;
			}
		}
		return result;
	}

	/**
	 * @generated
	 */
	public static List<OscfgNodeDescriptor> getModuleModuleObjects_7003SemanticChildren(
			View view) {
		if (false == view.eContainer() instanceof View) {
			return Collections.emptyList();
		}
		View containerView = (View) view.eContainer();
		if (!containerView.isSetElement()) {
			return Collections.emptyList();
		}
		Module modelElement = (Module) containerView.getElement();
		LinkedList<OscfgNodeDescriptor> result = new LinkedList<OscfgNodeDescriptor>();
		for (Iterator<?> it = modelElement.getTasks().iterator(); it.hasNext();) {
			Task childElement = (Task) it.next();
			int visualID = OscfgVisualIDRegistry.getNodeVisualID(view,
					childElement);
			if (visualID == TaskEditPart.VISUAL_ID) {
				result.add(new OscfgNodeDescriptor(childElement, visualID));
				continue;
			}
		}
		for (Iterator<?> it = modelElement.getISRs().iterator(); it.hasNext();) {
			oscfg.ISR childElement = (oscfg.ISR) it.next();
			int visualID = OscfgVisualIDRegistry.getNodeVisualID(view,
					childElement);
			if (visualID == ISREditPart.VISUAL_ID) {
				result.add(new OscfgNodeDescriptor(childElement, visualID));
				continue;
			}
		}
		for (Iterator<?> it = modelElement.getMutexs().iterator(); it.hasNext();) {
			Mutex childElement = (Mutex) it.next();
			int visualID = OscfgVisualIDRegistry.getNodeVisualID(view,
					childElement);
			if (visualID == MutexEditPart.VISUAL_ID) {
				result.add(new OscfgNodeDescriptor(childElement, visualID));
				continue;
			}
		}
		for (Iterator<?> it = modelElement.getMessages().iterator(); it
				.hasNext();) {
			Message childElement = (Message) it.next();
			int visualID = OscfgVisualIDRegistry.getNodeVisualID(view,
					childElement);
			if (visualID == MessageEditPart.VISUAL_ID) {
				result.add(new OscfgNodeDescriptor(childElement, visualID));
				continue;
			}
		}
		for (Iterator<?> it = modelElement.getHWCounters().iterator(); it
				.hasNext();) {
			HWCounter childElement = (HWCounter) it.next();
			int visualID = OscfgVisualIDRegistry.getNodeVisualID(view,
					childElement);
			if (visualID == HWCounterEditPart.VISUAL_ID) {
				result.add(new OscfgNodeDescriptor(childElement, visualID));
				continue;
			}
		}
		for (Iterator<?> it = modelElement.getCallbacks().iterator(); it
				.hasNext();) {
			CallbackFunction childElement = (CallbackFunction) it.next();
			int visualID = OscfgVisualIDRegistry.getNodeVisualID(view,
					childElement);
			if (visualID == CallbackFunctionEditPart.VISUAL_ID) {
				result.add(new OscfgNodeDescriptor(childElement, visualID));
				continue;
			}
		}
		for (Iterator<?> it = modelElement.getInterruptSources().iterator(); it
				.hasNext();) {
			InterruptSource childElement = (InterruptSource) it.next();
			int visualID = OscfgVisualIDRegistry.getNodeVisualID(view,
					childElement);
			if (visualID == InterruptSourceEditPart.VISUAL_ID) {
				result.add(new OscfgNodeDescriptor(childElement, visualID));
				continue;
			}
		}
		for (Iterator<?> it = modelElement.getCooperativeTaskGroups()
				.iterator(); it.hasNext();) {
			CooperativeGroup childElement = (CooperativeGroup) it.next();
			int visualID = OscfgVisualIDRegistry.getNodeVisualID(view,
					childElement);
			if (visualID == CooperativeGroupEditPart.VISUAL_ID) {
				result.add(new OscfgNodeDescriptor(childElement, visualID));
				continue;
			}
		}
		return result;
	}

	/**
	 * @generated
	 */
	public static List<OscfgNodeDescriptor> getHWCounterSoftwareTimers_7004SemanticChildren(
			View view) {
		if (false == view.eContainer() instanceof View) {
			return Collections.emptyList();
		}
		View containerView = (View) view.eContainer();
		if (!containerView.isSetElement()) {
			return Collections.emptyList();
		}
		HWCounter modelElement = (HWCounter) containerView.getElement();
		LinkedList<OscfgNodeDescriptor> result = new LinkedList<OscfgNodeDescriptor>();
		for (Iterator<?> it = modelElement.getSWTimers().iterator(); it
				.hasNext();) {
			SWTimer childElement = (SWTimer) it.next();
			int visualID = OscfgVisualIDRegistry.getNodeVisualID(view,
					childElement);
			if (visualID == SWTimerEditPart.VISUAL_ID) {
				result.add(new OscfgNodeDescriptor(childElement, visualID));
				continue;
			}
		}
		return result;
	}

	/**
	 * @generated
	 */
	public static List<OscfgNodeDescriptor> getCooperativeGroupCooperativeTasks_7005SemanticChildren(
			View view) {
		if (false == view.eContainer() instanceof View) {
			return Collections.emptyList();
		}
		View containerView = (View) view.eContainer();
		if (!containerView.isSetElement()) {
			return Collections.emptyList();
		}
		CooperativeGroup modelElement = (CooperativeGroup) containerView
				.getElement();
		LinkedList<OscfgNodeDescriptor> result = new LinkedList<OscfgNodeDescriptor>();
		for (Iterator<?> it = modelElement.getCooperativeTasks().iterator(); it
				.hasNext();) {
			Task childElement = (Task) it.next();
			int visualID = OscfgVisualIDRegistry.getNodeVisualID(view,
					childElement);
			if (visualID == Task2EditPart.VISUAL_ID) {
				result.add(new OscfgNodeDescriptor(childElement, visualID));
				continue;
			}
		}
		return result;
	}

	/**
	 * @generated
	 */
	public static List<OscfgNodeDescriptor> getConfiguration_1000SemanticChildren(
			View view) {
		if (!view.isSetElement()) {
			return Collections.emptyList();
		}
		Configuration modelElement = (Configuration) view.getElement();
		LinkedList<OscfgNodeDescriptor> result = new LinkedList<OscfgNodeDescriptor>();
		{
			oscfg.OS childElement = modelElement.getOS();
			int visualID = OscfgVisualIDRegistry.getNodeVisualID(view,
					childElement);
			if (visualID == OSEditPart.VISUAL_ID) {
				result.add(new OscfgNodeDescriptor(childElement, visualID));
			}
		}
		return result;
	}

	/**
	 * @generated
	 */
	public static List<OscfgLinkDescriptor> getContainedLinks(View view) {
		switch (OscfgVisualIDRegistry.getVisualID(view)) {
		case ConfigurationEditPart.VISUAL_ID:
			return getConfiguration_1000ContainedLinks(view);
		case OSEditPart.VISUAL_ID:
			return getOS_2001ContainedLinks(view);
		case ModuleEditPart.VISUAL_ID:
			return getModule_3009ContainedLinks(view);
		case TaskEditPart.VISUAL_ID:
			return getTask_3010ContainedLinks(view);
		case ISREditPart.VISUAL_ID:
			return getISR_3011ContainedLinks(view);
		case MutexEditPart.VISUAL_ID:
			return getMutex_3012ContainedLinks(view);
		case MessageEditPart.VISUAL_ID:
			return getMessage_3013ContainedLinks(view);
		case HWCounterEditPart.VISUAL_ID:
			return getHWCounter_3014ContainedLinks(view);
		case SWTimerEditPart.VISUAL_ID:
			return getSWTimer_3006ContainedLinks(view);
		case CallbackFunctionEditPart.VISUAL_ID:
			return getCallbackFunction_3015ContainedLinks(view);
		case InterruptSourceEditPart.VISUAL_ID:
			return getInterruptSource_3016ContainedLinks(view);
		case CooperativeGroupEditPart.VISUAL_ID:
			return getCooperativeGroup_3017ContainedLinks(view);
		case Task2EditPart.VISUAL_ID:
			return getTask_3020ContainedLinks(view);
		}
		return Collections.emptyList();
	}

	/**
	 * @generated
	 */
	public static List<OscfgLinkDescriptor> getIncomingLinks(View view) {
		switch (OscfgVisualIDRegistry.getVisualID(view)) {
		case OSEditPart.VISUAL_ID:
			return getOS_2001IncomingLinks(view);
		case ModuleEditPart.VISUAL_ID:
			return getModule_3009IncomingLinks(view);
		case TaskEditPart.VISUAL_ID:
			return getTask_3010IncomingLinks(view);
		case ISREditPart.VISUAL_ID:
			return getISR_3011IncomingLinks(view);
		case MutexEditPart.VISUAL_ID:
			return getMutex_3012IncomingLinks(view);
		case MessageEditPart.VISUAL_ID:
			return getMessage_3013IncomingLinks(view);
		case HWCounterEditPart.VISUAL_ID:
			return getHWCounter_3014IncomingLinks(view);
		case SWTimerEditPart.VISUAL_ID:
			return getSWTimer_3006IncomingLinks(view);
		case CallbackFunctionEditPart.VISUAL_ID:
			return getCallbackFunction_3015IncomingLinks(view);
		case InterruptSourceEditPart.VISUAL_ID:
			return getInterruptSource_3016IncomingLinks(view);
		case CooperativeGroupEditPart.VISUAL_ID:
			return getCooperativeGroup_3017IncomingLinks(view);
		case Task2EditPart.VISUAL_ID:
			return getTask_3020IncomingLinks(view);
		}
		return Collections.emptyList();
	}

	/**
	 * @generated
	 */
	public static List<OscfgLinkDescriptor> getOutgoingLinks(View view) {
		switch (OscfgVisualIDRegistry.getVisualID(view)) {
		case OSEditPart.VISUAL_ID:
			return getOS_2001OutgoingLinks(view);
		case ModuleEditPart.VISUAL_ID:
			return getModule_3009OutgoingLinks(view);
		case TaskEditPart.VISUAL_ID:
			return getTask_3010OutgoingLinks(view);
		case ISREditPart.VISUAL_ID:
			return getISR_3011OutgoingLinks(view);
		case MutexEditPart.VISUAL_ID:
			return getMutex_3012OutgoingLinks(view);
		case MessageEditPart.VISUAL_ID:
			return getMessage_3013OutgoingLinks(view);
		case HWCounterEditPart.VISUAL_ID:
			return getHWCounter_3014OutgoingLinks(view);
		case SWTimerEditPart.VISUAL_ID:
			return getSWTimer_3006OutgoingLinks(view);
		case CallbackFunctionEditPart.VISUAL_ID:
			return getCallbackFunction_3015OutgoingLinks(view);
		case InterruptSourceEditPart.VISUAL_ID:
			return getInterruptSource_3016OutgoingLinks(view);
		case CooperativeGroupEditPart.VISUAL_ID:
			return getCooperativeGroup_3017OutgoingLinks(view);
		case Task2EditPart.VISUAL_ID:
			return getTask_3020OutgoingLinks(view);
		}
		return Collections.emptyList();
	}

	/**
	 * @generated
	 */
	public static List<OscfgLinkDescriptor> getConfiguration_1000ContainedLinks(
			View view) {
		return Collections.emptyList();
	}

	/**
	 * @generated
	 */
	public static List<OscfgLinkDescriptor> getOS_2001ContainedLinks(View view) {
		return Collections.emptyList();
	}

	/**
	 * @generated
	 */
	public static List<OscfgLinkDescriptor> getModule_3009ContainedLinks(
			View view) {
		return Collections.emptyList();
	}

	/**
	 * @generated
	 */
	public static List<OscfgLinkDescriptor> getTask_3010ContainedLinks(View view) {
		Task modelElement = (Task) view.getElement();
		LinkedList<OscfgLinkDescriptor> result = new LinkedList<OscfgLinkDescriptor>();
		result.addAll(getOutgoingFeatureModelFacetLinks_BaseTask_CollectMessage_4001(modelElement));
		result.addAll(getOutgoingFeatureModelFacetLinks_Poster_PostMessage_4012(modelElement));
		result.addAll(getOutgoingFeatureModelFacetLinks_BaseTask_EnterExitMutex_4003(modelElement));
		return result;
	}

	/**
	 * @generated
	 */
	public static List<OscfgLinkDescriptor> getISR_3011ContainedLinks(View view) {
		oscfg.ISR modelElement = (oscfg.ISR) view.getElement();
		LinkedList<OscfgLinkDescriptor> result = new LinkedList<OscfgLinkDescriptor>();
		result.addAll(getOutgoingFeatureModelFacetLinks_BaseTask_CollectMessage_4001(modelElement));
		result.addAll(getOutgoingFeatureModelFacetLinks_Poster_PostMessage_4012(modelElement));
		result.addAll(getOutgoingFeatureModelFacetLinks_BaseTask_EnterExitMutex_4003(modelElement));
		return result;
	}

	/**
	 * @generated
	 */
	public static List<OscfgLinkDescriptor> getMutex_3012ContainedLinks(
			View view) {
		return Collections.emptyList();
	}

	/**
	 * @generated
	 */
	public static List<OscfgLinkDescriptor> getMessage_3013ContainedLinks(
			View view) {
		Message modelElement = (Message) view.getElement();
		LinkedList<OscfgLinkDescriptor> result = new LinkedList<OscfgLinkDescriptor>();
		result.addAll(getOutgoingFeatureModelFacetLinks_Message_Notifies_4006(modelElement));
		return result;
	}

	/**
	 * @generated
	 */
	public static List<OscfgLinkDescriptor> getHWCounter_3014ContainedLinks(
			View view) {
		HWCounter modelElement = (HWCounter) view.getElement();
		LinkedList<OscfgLinkDescriptor> result = new LinkedList<OscfgLinkDescriptor>();
		result.addAll(getOutgoingFeatureModelFacetLinks_HWCounter_Enable_callback_4007(modelElement));
		result.addAll(getOutgoingFeatureModelFacetLinks_HWCounter_Disable_callback_4008(modelElement));
		result.addAll(getOutgoingFeatureModelFacetLinks_HWCounter_Get_callback_4009(modelElement));
		result.addAll(getOutgoingFeatureModelFacetLinks_HWCounter_Set_callback_4010(modelElement));
		return result;
	}

	/**
	 * @generated
	 */
	public static List<OscfgLinkDescriptor> getSWTimer_3006ContainedLinks(
			View view) {
		SWTimer modelElement = (SWTimer) view.getElement();
		LinkedList<OscfgLinkDescriptor> result = new LinkedList<OscfgLinkDescriptor>();
		result.addAll(getOutgoingFeatureModelFacetLinks_SWTimer_Activates_4004(modelElement));
		result.addAll(getOutgoingFeatureModelFacetLinks_SWTimer_Timer_callback_4005(modelElement));
		return result;
	}

	/**
	 * @generated
	 */
	public static List<OscfgLinkDescriptor> getCallbackFunction_3015ContainedLinks(
			View view) {
		CallbackFunction modelElement = (CallbackFunction) view.getElement();
		LinkedList<OscfgLinkDescriptor> result = new LinkedList<OscfgLinkDescriptor>();
		result.addAll(getOutgoingFeatureModelFacetLinks_Poster_PostMessage_4012(modelElement));
		return result;
	}

	/**
	 * @generated
	 */
	public static List<OscfgLinkDescriptor> getInterruptSource_3016ContainedLinks(
			View view) {
		InterruptSource modelElement = (InterruptSource) view.getElement();
		LinkedList<OscfgLinkDescriptor> result = new LinkedList<OscfgLinkDescriptor>();
		result.addAll(getOutgoingFeatureModelFacetLinks_InterruptSource_SourceISR_4011(modelElement));
		return result;
	}

	/**
	 * @generated
	 */
	public static List<OscfgLinkDescriptor> getCooperativeGroup_3017ContainedLinks(
			View view) {
		return Collections.emptyList();
	}

	/**
	 * @generated
	 */
	public static List<OscfgLinkDescriptor> getTask_3020ContainedLinks(View view) {
		Task modelElement = (Task) view.getElement();
		LinkedList<OscfgLinkDescriptor> result = new LinkedList<OscfgLinkDescriptor>();
		result.addAll(getOutgoingFeatureModelFacetLinks_BaseTask_CollectMessage_4001(modelElement));
		result.addAll(getOutgoingFeatureModelFacetLinks_Poster_PostMessage_4012(modelElement));
		result.addAll(getOutgoingFeatureModelFacetLinks_BaseTask_EnterExitMutex_4003(modelElement));
		return result;
	}

	/**
	 * @generated
	 */
	public static List<OscfgLinkDescriptor> getOS_2001IncomingLinks(View view) {
		return Collections.emptyList();
	}

	/**
	 * @generated
	 */
	public static List<OscfgLinkDescriptor> getModule_3009IncomingLinks(
			View view) {
		return Collections.emptyList();
	}

	/**
	 * @generated
	 */
	public static List<OscfgLinkDescriptor> getTask_3010IncomingLinks(View view) {
		Task modelElement = (Task) view.getElement();
		Map<EObject, Collection<EStructuralFeature.Setting>> crossReferences = EcoreUtil.CrossReferencer
				.find(view.eResource().getResourceSet().getResources());
		LinkedList<OscfgLinkDescriptor> result = new LinkedList<OscfgLinkDescriptor>();
		result.addAll(getIncomingFeatureModelFacetLinks_SWTimer_Activates_4004(
				modelElement, crossReferences));
		result.addAll(getIncomingFeatureModelFacetLinks_Message_Notifies_4006(
				modelElement, crossReferences));
		return result;
	}

	/**
	 * @generated
	 */
	public static List<OscfgLinkDescriptor> getISR_3011IncomingLinks(View view) {
		oscfg.ISR modelElement = (oscfg.ISR) view.getElement();
		Map<EObject, Collection<EStructuralFeature.Setting>> crossReferences = EcoreUtil.CrossReferencer
				.find(view.eResource().getResourceSet().getResources());
		LinkedList<OscfgLinkDescriptor> result = new LinkedList<OscfgLinkDescriptor>();
		result.addAll(getIncomingFeatureModelFacetLinks_InterruptSource_SourceISR_4011(
				modelElement, crossReferences));
		return result;
	}

	/**
	 * @generated
	 */
	public static List<OscfgLinkDescriptor> getMutex_3012IncomingLinks(View view) {
		Mutex modelElement = (Mutex) view.getElement();
		Map<EObject, Collection<EStructuralFeature.Setting>> crossReferences = EcoreUtil.CrossReferencer
				.find(view.eResource().getResourceSet().getResources());
		LinkedList<OscfgLinkDescriptor> result = new LinkedList<OscfgLinkDescriptor>();
		result.addAll(getIncomingFeatureModelFacetLinks_BaseTask_EnterExitMutex_4003(
				modelElement, crossReferences));
		return result;
	}

	/**
	 * @generated
	 */
	public static List<OscfgLinkDescriptor> getMessage_3013IncomingLinks(
			View view) {
		Message modelElement = (Message) view.getElement();
		Map<EObject, Collection<EStructuralFeature.Setting>> crossReferences = EcoreUtil.CrossReferencer
				.find(view.eResource().getResourceSet().getResources());
		LinkedList<OscfgLinkDescriptor> result = new LinkedList<OscfgLinkDescriptor>();
		result.addAll(getIncomingFeatureModelFacetLinks_BaseTask_CollectMessage_4001(
				modelElement, crossReferences));
		result.addAll(getIncomingFeatureModelFacetLinks_Poster_PostMessage_4012(
				modelElement, crossReferences));
		return result;
	}

	/**
	 * @generated
	 */
	public static List<OscfgLinkDescriptor> getHWCounter_3014IncomingLinks(
			View view) {
		return Collections.emptyList();
	}

	/**
	 * @generated
	 */
	public static List<OscfgLinkDescriptor> getSWTimer_3006IncomingLinks(
			View view) {
		return Collections.emptyList();
	}

	/**
	 * @generated
	 */
	public static List<OscfgLinkDescriptor> getCallbackFunction_3015IncomingLinks(
			View view) {
		CallbackFunction modelElement = (CallbackFunction) view.getElement();
		Map<EObject, Collection<EStructuralFeature.Setting>> crossReferences = EcoreUtil.CrossReferencer
				.find(view.eResource().getResourceSet().getResources());
		LinkedList<OscfgLinkDescriptor> result = new LinkedList<OscfgLinkDescriptor>();
		result.addAll(getIncomingFeatureModelFacetLinks_SWTimer_Timer_callback_4005(
				modelElement, crossReferences));
		result.addAll(getIncomingFeatureModelFacetLinks_HWCounter_Enable_callback_4007(
				modelElement, crossReferences));
		result.addAll(getIncomingFeatureModelFacetLinks_HWCounter_Disable_callback_4008(
				modelElement, crossReferences));
		result.addAll(getIncomingFeatureModelFacetLinks_HWCounter_Get_callback_4009(
				modelElement, crossReferences));
		result.addAll(getIncomingFeatureModelFacetLinks_HWCounter_Set_callback_4010(
				modelElement, crossReferences));
		return result;
	}

	/**
	 * @generated
	 */
	public static List<OscfgLinkDescriptor> getInterruptSource_3016IncomingLinks(
			View view) {
		return Collections.emptyList();
	}

	/**
	 * @generated
	 */
	public static List<OscfgLinkDescriptor> getCooperativeGroup_3017IncomingLinks(
			View view) {
		return Collections.emptyList();
	}

	/**
	 * @generated
	 */
	public static List<OscfgLinkDescriptor> getTask_3020IncomingLinks(View view) {
		Task modelElement = (Task) view.getElement();
		Map<EObject, Collection<EStructuralFeature.Setting>> crossReferences = EcoreUtil.CrossReferencer
				.find(view.eResource().getResourceSet().getResources());
		LinkedList<OscfgLinkDescriptor> result = new LinkedList<OscfgLinkDescriptor>();
		result.addAll(getIncomingFeatureModelFacetLinks_SWTimer_Activates_4004(
				modelElement, crossReferences));
		result.addAll(getIncomingFeatureModelFacetLinks_Message_Notifies_4006(
				modelElement, crossReferences));
		return result;
	}

	/**
	 * @generated
	 */
	public static List<OscfgLinkDescriptor> getOS_2001OutgoingLinks(View view) {
		return Collections.emptyList();
	}

	/**
	 * @generated
	 */
	public static List<OscfgLinkDescriptor> getModule_3009OutgoingLinks(
			View view) {
		return Collections.emptyList();
	}

	/**
	 * @generated
	 */
	public static List<OscfgLinkDescriptor> getTask_3010OutgoingLinks(View view) {
		Task modelElement = (Task) view.getElement();
		LinkedList<OscfgLinkDescriptor> result = new LinkedList<OscfgLinkDescriptor>();
		result.addAll(getOutgoingFeatureModelFacetLinks_BaseTask_CollectMessage_4001(modelElement));
		result.addAll(getOutgoingFeatureModelFacetLinks_Poster_PostMessage_4012(modelElement));
		result.addAll(getOutgoingFeatureModelFacetLinks_BaseTask_EnterExitMutex_4003(modelElement));
		return result;
	}

	/**
	 * @generated
	 */
	public static List<OscfgLinkDescriptor> getISR_3011OutgoingLinks(View view) {
		oscfg.ISR modelElement = (oscfg.ISR) view.getElement();
		LinkedList<OscfgLinkDescriptor> result = new LinkedList<OscfgLinkDescriptor>();
		result.addAll(getOutgoingFeatureModelFacetLinks_BaseTask_CollectMessage_4001(modelElement));
		result.addAll(getOutgoingFeatureModelFacetLinks_Poster_PostMessage_4012(modelElement));
		result.addAll(getOutgoingFeatureModelFacetLinks_BaseTask_EnterExitMutex_4003(modelElement));
		return result;
	}

	/**
	 * @generated
	 */
	public static List<OscfgLinkDescriptor> getMutex_3012OutgoingLinks(View view) {
		return Collections.emptyList();
	}

	/**
	 * @generated
	 */
	public static List<OscfgLinkDescriptor> getMessage_3013OutgoingLinks(
			View view) {
		Message modelElement = (Message) view.getElement();
		LinkedList<OscfgLinkDescriptor> result = new LinkedList<OscfgLinkDescriptor>();
		result.addAll(getOutgoingFeatureModelFacetLinks_Message_Notifies_4006(modelElement));
		return result;
	}

	/**
	 * @generated
	 */
	public static List<OscfgLinkDescriptor> getHWCounter_3014OutgoingLinks(
			View view) {
		HWCounter modelElement = (HWCounter) view.getElement();
		LinkedList<OscfgLinkDescriptor> result = new LinkedList<OscfgLinkDescriptor>();
		result.addAll(getOutgoingFeatureModelFacetLinks_HWCounter_Enable_callback_4007(modelElement));
		result.addAll(getOutgoingFeatureModelFacetLinks_HWCounter_Disable_callback_4008(modelElement));
		result.addAll(getOutgoingFeatureModelFacetLinks_HWCounter_Get_callback_4009(modelElement));
		result.addAll(getOutgoingFeatureModelFacetLinks_HWCounter_Set_callback_4010(modelElement));
		return result;
	}

	/**
	 * @generated
	 */
	public static List<OscfgLinkDescriptor> getSWTimer_3006OutgoingLinks(
			View view) {
		SWTimer modelElement = (SWTimer) view.getElement();
		LinkedList<OscfgLinkDescriptor> result = new LinkedList<OscfgLinkDescriptor>();
		result.addAll(getOutgoingFeatureModelFacetLinks_SWTimer_Activates_4004(modelElement));
		result.addAll(getOutgoingFeatureModelFacetLinks_SWTimer_Timer_callback_4005(modelElement));
		return result;
	}

	/**
	 * @generated
	 */
	public static List<OscfgLinkDescriptor> getCallbackFunction_3015OutgoingLinks(
			View view) {
		CallbackFunction modelElement = (CallbackFunction) view.getElement();
		LinkedList<OscfgLinkDescriptor> result = new LinkedList<OscfgLinkDescriptor>();
		result.addAll(getOutgoingFeatureModelFacetLinks_Poster_PostMessage_4012(modelElement));
		return result;
	}

	/**
	 * @generated
	 */
	public static List<OscfgLinkDescriptor> getInterruptSource_3016OutgoingLinks(
			View view) {
		InterruptSource modelElement = (InterruptSource) view.getElement();
		LinkedList<OscfgLinkDescriptor> result = new LinkedList<OscfgLinkDescriptor>();
		result.addAll(getOutgoingFeatureModelFacetLinks_InterruptSource_SourceISR_4011(modelElement));
		return result;
	}

	/**
	 * @generated
	 */
	public static List<OscfgLinkDescriptor> getCooperativeGroup_3017OutgoingLinks(
			View view) {
		return Collections.emptyList();
	}

	/**
	 * @generated
	 */
	public static List<OscfgLinkDescriptor> getTask_3020OutgoingLinks(View view) {
		Task modelElement = (Task) view.getElement();
		LinkedList<OscfgLinkDescriptor> result = new LinkedList<OscfgLinkDescriptor>();
		result.addAll(getOutgoingFeatureModelFacetLinks_BaseTask_CollectMessage_4001(modelElement));
		result.addAll(getOutgoingFeatureModelFacetLinks_Poster_PostMessage_4012(modelElement));
		result.addAll(getOutgoingFeatureModelFacetLinks_BaseTask_EnterExitMutex_4003(modelElement));
		return result;
	}

	/**
	 * @generated
	 */
	private static Collection<OscfgLinkDescriptor> getIncomingFeatureModelFacetLinks_BaseTask_CollectMessage_4001(
			Message target,
			Map<EObject, Collection<EStructuralFeature.Setting>> crossReferences) {
		LinkedList<OscfgLinkDescriptor> result = new LinkedList<OscfgLinkDescriptor>();
		Collection<EStructuralFeature.Setting> settings = crossReferences
				.get(target);
		for (EStructuralFeature.Setting setting : settings) {
			if (setting.getEStructuralFeature() == OscfgPackage.eINSTANCE
					.getBaseTask_CollectMessage()) {
				result.add(new OscfgLinkDescriptor(setting.getEObject(),
						target, OscfgElementTypes.BaseTaskCollectMessage_4001,
						BaseTaskCollectMessageEditPart.VISUAL_ID));
			}
		}
		return result;
	}

	/**
	 * @generated
	 */
	private static Collection<OscfgLinkDescriptor> getIncomingFeatureModelFacetLinks_Poster_PostMessage_4012(
			Message target,
			Map<EObject, Collection<EStructuralFeature.Setting>> crossReferences) {
		LinkedList<OscfgLinkDescriptor> result = new LinkedList<OscfgLinkDescriptor>();
		Collection<EStructuralFeature.Setting> settings = crossReferences
				.get(target);
		for (EStructuralFeature.Setting setting : settings) {
			if (setting.getEStructuralFeature() == OscfgPackage.eINSTANCE
					.getPoster_PostMessage()) {
				result.add(new OscfgLinkDescriptor(setting.getEObject(),
						target, OscfgElementTypes.PosterPostMessage_4012,
						PosterPostMessageEditPart.VISUAL_ID));
			}
		}
		return result;
	}

	/**
	 * @generated
	 */
	private static Collection<OscfgLinkDescriptor> getIncomingFeatureModelFacetLinks_BaseTask_EnterExitMutex_4003(
			Mutex target,
			Map<EObject, Collection<EStructuralFeature.Setting>> crossReferences) {
		LinkedList<OscfgLinkDescriptor> result = new LinkedList<OscfgLinkDescriptor>();
		Collection<EStructuralFeature.Setting> settings = crossReferences
				.get(target);
		for (EStructuralFeature.Setting setting : settings) {
			if (setting.getEStructuralFeature() == OscfgPackage.eINSTANCE
					.getBaseTask_EnterExitMutex()) {
				result.add(new OscfgLinkDescriptor(setting.getEObject(),
						target, OscfgElementTypes.BaseTaskEnterExitMutex_4003,
						BaseTaskEnterExitMutexEditPart.VISUAL_ID));
			}
		}
		return result;
	}

	/**
	 * @generated
	 */
	private static Collection<OscfgLinkDescriptor> getIncomingFeatureModelFacetLinks_SWTimer_Activates_4004(
			Task target,
			Map<EObject, Collection<EStructuralFeature.Setting>> crossReferences) {
		LinkedList<OscfgLinkDescriptor> result = new LinkedList<OscfgLinkDescriptor>();
		Collection<EStructuralFeature.Setting> settings = crossReferences
				.get(target);
		for (EStructuralFeature.Setting setting : settings) {
			if (setting.getEStructuralFeature() == OscfgPackage.eINSTANCE
					.getSWTimer_Activates()) {
				result.add(new OscfgLinkDescriptor(setting.getEObject(),
						target, OscfgElementTypes.SWTimerActivates_4004,
						SWTimerActivatesEditPart.VISUAL_ID));
			}
		}
		return result;
	}

	/**
	 * @generated
	 */
	private static Collection<OscfgLinkDescriptor> getIncomingFeatureModelFacetLinks_SWTimer_Timer_callback_4005(
			CallbackFunction target,
			Map<EObject, Collection<EStructuralFeature.Setting>> crossReferences) {
		LinkedList<OscfgLinkDescriptor> result = new LinkedList<OscfgLinkDescriptor>();
		Collection<EStructuralFeature.Setting> settings = crossReferences
				.get(target);
		for (EStructuralFeature.Setting setting : settings) {
			if (setting.getEStructuralFeature() == OscfgPackage.eINSTANCE
					.getSWTimer_Timer_callback()) {
				result.add(new OscfgLinkDescriptor(setting.getEObject(),
						target, OscfgElementTypes.SWTimerTimer_callback_4005,
						SWTimerTimer_callbackEditPart.VISUAL_ID));
			}
		}
		return result;
	}

	/**
	 * @generated
	 */
	private static Collection<OscfgLinkDescriptor> getIncomingFeatureModelFacetLinks_Message_Notifies_4006(
			Task target,
			Map<EObject, Collection<EStructuralFeature.Setting>> crossReferences) {
		LinkedList<OscfgLinkDescriptor> result = new LinkedList<OscfgLinkDescriptor>();
		Collection<EStructuralFeature.Setting> settings = crossReferences
				.get(target);
		for (EStructuralFeature.Setting setting : settings) {
			if (setting.getEStructuralFeature() == OscfgPackage.eINSTANCE
					.getMessage_Notifies()) {
				result.add(new OscfgLinkDescriptor(setting.getEObject(),
						target, OscfgElementTypes.MessageNotifies_4006,
						MessageNotifiesEditPart.VISUAL_ID));
			}
		}
		return result;
	}

	/**
	 * @generated
	 */
	private static Collection<OscfgLinkDescriptor> getIncomingFeatureModelFacetLinks_HWCounter_Enable_callback_4007(
			CallbackFunction target,
			Map<EObject, Collection<EStructuralFeature.Setting>> crossReferences) {
		LinkedList<OscfgLinkDescriptor> result = new LinkedList<OscfgLinkDescriptor>();
		Collection<EStructuralFeature.Setting> settings = crossReferences
				.get(target);
		for (EStructuralFeature.Setting setting : settings) {
			if (setting.getEStructuralFeature() == OscfgPackage.eINSTANCE
					.getHWCounter_Enable_callback()) {
				result.add(new OscfgLinkDescriptor(setting.getEObject(),
						target,
						OscfgElementTypes.HWCounterEnable_callback_4007,
						HWCounterEnable_callbackEditPart.VISUAL_ID));
			}
		}
		return result;
	}

	/**
	 * @generated
	 */
	private static Collection<OscfgLinkDescriptor> getIncomingFeatureModelFacetLinks_HWCounter_Disable_callback_4008(
			CallbackFunction target,
			Map<EObject, Collection<EStructuralFeature.Setting>> crossReferences) {
		LinkedList<OscfgLinkDescriptor> result = new LinkedList<OscfgLinkDescriptor>();
		Collection<EStructuralFeature.Setting> settings = crossReferences
				.get(target);
		for (EStructuralFeature.Setting setting : settings) {
			if (setting.getEStructuralFeature() == OscfgPackage.eINSTANCE
					.getHWCounter_Disable_callback()) {
				result.add(new OscfgLinkDescriptor(setting.getEObject(),
						target,
						OscfgElementTypes.HWCounterDisable_callback_4008,
						HWCounterDisable_callbackEditPart.VISUAL_ID));
			}
		}
		return result;
	}

	/**
	 * @generated
	 */
	private static Collection<OscfgLinkDescriptor> getIncomingFeatureModelFacetLinks_HWCounter_Get_callback_4009(
			CallbackFunction target,
			Map<EObject, Collection<EStructuralFeature.Setting>> crossReferences) {
		LinkedList<OscfgLinkDescriptor> result = new LinkedList<OscfgLinkDescriptor>();
		Collection<EStructuralFeature.Setting> settings = crossReferences
				.get(target);
		for (EStructuralFeature.Setting setting : settings) {
			if (setting.getEStructuralFeature() == OscfgPackage.eINSTANCE
					.getHWCounter_Get_callback()) {
				result.add(new OscfgLinkDescriptor(setting.getEObject(),
						target, OscfgElementTypes.HWCounterGet_callback_4009,
						HWCounterGet_callbackEditPart.VISUAL_ID));
			}
		}
		return result;
	}

	/**
	 * @generated
	 */
	private static Collection<OscfgLinkDescriptor> getIncomingFeatureModelFacetLinks_HWCounter_Set_callback_4010(
			CallbackFunction target,
			Map<EObject, Collection<EStructuralFeature.Setting>> crossReferences) {
		LinkedList<OscfgLinkDescriptor> result = new LinkedList<OscfgLinkDescriptor>();
		Collection<EStructuralFeature.Setting> settings = crossReferences
				.get(target);
		for (EStructuralFeature.Setting setting : settings) {
			if (setting.getEStructuralFeature() == OscfgPackage.eINSTANCE
					.getHWCounter_Set_callback()) {
				result.add(new OscfgLinkDescriptor(setting.getEObject(),
						target, OscfgElementTypes.HWCounterSet_callback_4010,
						HWCounterSet_callbackEditPart.VISUAL_ID));
			}
		}
		return result;
	}

	/**
	 * @generated
	 */
	private static Collection<OscfgLinkDescriptor> getIncomingFeatureModelFacetLinks_InterruptSource_SourceISR_4011(
			oscfg.ISR target,
			Map<EObject, Collection<EStructuralFeature.Setting>> crossReferences) {
		LinkedList<OscfgLinkDescriptor> result = new LinkedList<OscfgLinkDescriptor>();
		Collection<EStructuralFeature.Setting> settings = crossReferences
				.get(target);
		for (EStructuralFeature.Setting setting : settings) {
			if (setting.getEStructuralFeature() == OscfgPackage.eINSTANCE
					.getInterruptSource_SourceISR()) {
				result.add(new OscfgLinkDescriptor(setting.getEObject(),
						target,
						OscfgElementTypes.InterruptSourceSourceISR_4011,
						InterruptSourceSourceISREditPart.VISUAL_ID));
			}
		}
		return result;
	}

	/**
	 * @generated
	 */
	private static Collection<OscfgLinkDescriptor> getOutgoingFeatureModelFacetLinks_BaseTask_CollectMessage_4001(
			BaseTask source) {
		LinkedList<OscfgLinkDescriptor> result = new LinkedList<OscfgLinkDescriptor>();
		for (Iterator<?> destinations = source.getCollectMessage().iterator(); destinations
				.hasNext();) {
			Message destination = (Message) destinations.next();
			result.add(new OscfgLinkDescriptor(source, destination,
					OscfgElementTypes.BaseTaskCollectMessage_4001,
					BaseTaskCollectMessageEditPart.VISUAL_ID));
		}
		return result;
	}

	/**
	 * @generated
	 */
	private static Collection<OscfgLinkDescriptor> getOutgoingFeatureModelFacetLinks_Poster_PostMessage_4012(
			Poster source) {
		LinkedList<OscfgLinkDescriptor> result = new LinkedList<OscfgLinkDescriptor>();
		for (Iterator<?> destinations = source.getPostMessage().iterator(); destinations
				.hasNext();) {
			Message destination = (Message) destinations.next();
			result.add(new OscfgLinkDescriptor(source, destination,
					OscfgElementTypes.PosterPostMessage_4012,
					PosterPostMessageEditPart.VISUAL_ID));
		}
		return result;
	}

	/**
	 * @generated
	 */
	private static Collection<OscfgLinkDescriptor> getOutgoingFeatureModelFacetLinks_BaseTask_EnterExitMutex_4003(
			BaseTask source) {
		LinkedList<OscfgLinkDescriptor> result = new LinkedList<OscfgLinkDescriptor>();
		for (Iterator<?> destinations = source.getEnterExitMutex().iterator(); destinations
				.hasNext();) {
			Mutex destination = (Mutex) destinations.next();
			result.add(new OscfgLinkDescriptor(source, destination,
					OscfgElementTypes.BaseTaskEnterExitMutex_4003,
					BaseTaskEnterExitMutexEditPart.VISUAL_ID));
		}
		return result;
	}

	/**
	 * @generated
	 */
	private static Collection<OscfgLinkDescriptor> getOutgoingFeatureModelFacetLinks_SWTimer_Activates_4004(
			SWTimer source) {
		LinkedList<OscfgLinkDescriptor> result = new LinkedList<OscfgLinkDescriptor>();
		Task destination = source.getActivates();
		if (destination == null) {
			return result;
		}
		result.add(new OscfgLinkDescriptor(source, destination,
				OscfgElementTypes.SWTimerActivates_4004,
				SWTimerActivatesEditPart.VISUAL_ID));
		return result;
	}

	/**
	 * @generated
	 */
	private static Collection<OscfgLinkDescriptor> getOutgoingFeatureModelFacetLinks_SWTimer_Timer_callback_4005(
			SWTimer source) {
		LinkedList<OscfgLinkDescriptor> result = new LinkedList<OscfgLinkDescriptor>();
		CallbackFunction destination = source.getTimer_callback();
		if (destination == null) {
			return result;
		}
		result.add(new OscfgLinkDescriptor(source, destination,
				OscfgElementTypes.SWTimerTimer_callback_4005,
				SWTimerTimer_callbackEditPart.VISUAL_ID));
		return result;
	}

	/**
	 * @generated
	 */
	private static Collection<OscfgLinkDescriptor> getOutgoingFeatureModelFacetLinks_Message_Notifies_4006(
			Message source) {
		LinkedList<OscfgLinkDescriptor> result = new LinkedList<OscfgLinkDescriptor>();
		Task destination = source.getNotifies();
		if (destination == null) {
			return result;
		}
		result.add(new OscfgLinkDescriptor(source, destination,
				OscfgElementTypes.MessageNotifies_4006,
				MessageNotifiesEditPart.VISUAL_ID));
		return result;
	}

	/**
	 * @generated
	 */
	private static Collection<OscfgLinkDescriptor> getOutgoingFeatureModelFacetLinks_HWCounter_Enable_callback_4007(
			HWCounter source) {
		LinkedList<OscfgLinkDescriptor> result = new LinkedList<OscfgLinkDescriptor>();
		CallbackFunction destination = source.getEnable_callback();
		if (destination == null) {
			return result;
		}
		result.add(new OscfgLinkDescriptor(source, destination,
				OscfgElementTypes.HWCounterEnable_callback_4007,
				HWCounterEnable_callbackEditPart.VISUAL_ID));
		return result;
	}

	/**
	 * @generated
	 */
	private static Collection<OscfgLinkDescriptor> getOutgoingFeatureModelFacetLinks_HWCounter_Disable_callback_4008(
			HWCounter source) {
		LinkedList<OscfgLinkDescriptor> result = new LinkedList<OscfgLinkDescriptor>();
		CallbackFunction destination = source.getDisable_callback();
		if (destination == null) {
			return result;
		}
		result.add(new OscfgLinkDescriptor(source, destination,
				OscfgElementTypes.HWCounterDisable_callback_4008,
				HWCounterDisable_callbackEditPart.VISUAL_ID));
		return result;
	}

	/**
	 * @generated
	 */
	private static Collection<OscfgLinkDescriptor> getOutgoingFeatureModelFacetLinks_HWCounter_Get_callback_4009(
			HWCounter source) {
		LinkedList<OscfgLinkDescriptor> result = new LinkedList<OscfgLinkDescriptor>();
		CallbackFunction destination = source.getGet_callback();
		if (destination == null) {
			return result;
		}
		result.add(new OscfgLinkDescriptor(source, destination,
				OscfgElementTypes.HWCounterGet_callback_4009,
				HWCounterGet_callbackEditPart.VISUAL_ID));
		return result;
	}

	/**
	 * @generated
	 */
	private static Collection<OscfgLinkDescriptor> getOutgoingFeatureModelFacetLinks_HWCounter_Set_callback_4010(
			HWCounter source) {
		LinkedList<OscfgLinkDescriptor> result = new LinkedList<OscfgLinkDescriptor>();
		CallbackFunction destination = source.getSet_callback();
		if (destination == null) {
			return result;
		}
		result.add(new OscfgLinkDescriptor(source, destination,
				OscfgElementTypes.HWCounterSet_callback_4010,
				HWCounterSet_callbackEditPart.VISUAL_ID));
		return result;
	}

	/**
	 * @generated
	 */
	private static Collection<OscfgLinkDescriptor> getOutgoingFeatureModelFacetLinks_InterruptSource_SourceISR_4011(
			InterruptSource source) {
		LinkedList<OscfgLinkDescriptor> result = new LinkedList<OscfgLinkDescriptor>();
		oscfg.ISR destination = source.getSourceISR();
		if (destination == null) {
			return result;
		}
		result.add(new OscfgLinkDescriptor(source, destination,
				OscfgElementTypes.InterruptSourceSourceISR_4011,
				InterruptSourceSourceISREditPart.VISUAL_ID));
		return result;
	}

	/**
	 * @generated
	 */
	public static final DiagramUpdater TYPED_INSTANCE = new DiagramUpdater() {
		/**
		 * @generated
		 */
		@Override
		public List<OscfgNodeDescriptor> getSemanticChildren(View view) {
			return OscfgDiagramUpdater.getSemanticChildren(view);
		}

		/**
		 * @generated
		 */
		@Override
		public List<OscfgLinkDescriptor> getContainedLinks(View view) {
			return OscfgDiagramUpdater.getContainedLinks(view);
		}

		/**
		 * @generated
		 */
		@Override
		public List<OscfgLinkDescriptor> getIncomingLinks(View view) {
			return OscfgDiagramUpdater.getIncomingLinks(view);
		}

		/**
		 * @generated
		 */
		@Override
		public List<OscfgLinkDescriptor> getOutgoingLinks(View view) {
			return OscfgDiagramUpdater.getOutgoingLinks(view);
		}
	};

}
