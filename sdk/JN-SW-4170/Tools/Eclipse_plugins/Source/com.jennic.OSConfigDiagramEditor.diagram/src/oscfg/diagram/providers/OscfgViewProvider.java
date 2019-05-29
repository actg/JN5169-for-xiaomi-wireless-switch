package oscfg.diagram.providers;

import java.util.ArrayList;
import org.eclipse.core.runtime.IAdaptable;
import org.eclipse.emf.ecore.EAnnotation;
import org.eclipse.emf.ecore.EObject;
import org.eclipse.emf.ecore.EcoreFactory;
import org.eclipse.emf.transaction.util.TransactionUtil;
import org.eclipse.gmf.runtime.common.core.service.AbstractProvider;
import org.eclipse.gmf.runtime.common.core.service.IOperation;
import org.eclipse.gmf.runtime.diagram.core.preferences.PreferencesHint;
import org.eclipse.gmf.runtime.diagram.core.providers.AbstractViewProvider;
import org.eclipse.gmf.runtime.diagram.core.providers.IViewProvider;
import org.eclipse.gmf.runtime.diagram.core.services.view.CreateDiagramViewOperation;
import org.eclipse.gmf.runtime.diagram.core.services.view.CreateEdgeViewOperation;
import org.eclipse.gmf.runtime.diagram.core.services.view.CreateNodeViewOperation;
import org.eclipse.gmf.runtime.diagram.core.services.view.CreateViewForKindOperation;
import org.eclipse.gmf.runtime.diagram.core.services.view.CreateViewOperation;
import org.eclipse.gmf.runtime.diagram.core.util.ViewUtil;
import org.eclipse.gmf.runtime.diagram.ui.preferences.IPreferenceConstants;
import org.eclipse.gmf.runtime.draw2d.ui.figures.FigureUtilities;
import org.eclipse.gmf.runtime.emf.core.util.EMFCoreUtil;
import org.eclipse.gmf.runtime.emf.type.core.IElementType;
import org.eclipse.gmf.runtime.emf.type.core.IHintedType;
import org.eclipse.gmf.runtime.notation.DecorationNode;
import org.eclipse.gmf.runtime.notation.Diagram;
import org.eclipse.gmf.runtime.notation.Edge;
import org.eclipse.gmf.runtime.notation.FontStyle;
import org.eclipse.gmf.runtime.notation.Location;
import org.eclipse.gmf.runtime.notation.MeasurementUnit;
import org.eclipse.gmf.runtime.notation.Node;
import org.eclipse.gmf.runtime.notation.NotationFactory;
import org.eclipse.gmf.runtime.notation.NotationPackage;
import org.eclipse.gmf.runtime.notation.RelativeBendpoints;
import org.eclipse.gmf.runtime.notation.Routing;
import org.eclipse.gmf.runtime.notation.TitleStyle;
import org.eclipse.gmf.runtime.notation.View;

import org.eclipse.gmf.runtime.notation.datatype.RelativeBendpoint;
import org.eclipse.jface.preference.IPreferenceStore;
import org.eclipse.jface.preference.PreferenceConverter;
import org.eclipse.swt.SWT;
import org.eclipse.swt.graphics.FontData;
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
import oscfg.diagram.part.OscfgVisualIDRegistry;
import oscfg.diagram.view.factories.BaseTaskCollectMessageViewFactory;
import oscfg.diagram.view.factories.BaseTaskEnterExitMutexViewFactory;
import oscfg.diagram.view.factories.CallbackFunctionNameViewFactory;
import oscfg.diagram.view.factories.CallbackFunctionViewFactory;
import oscfg.diagram.view.factories.ConfigurationViewFactory;
import oscfg.diagram.view.factories.CooperativeGroupCooperativeTasksViewFactory;
import oscfg.diagram.view.factories.CooperativeGroupNameViewFactory;
import oscfg.diagram.view.factories.CooperativeGroupViewFactory;
import oscfg.diagram.view.factories.HWCounterDisable_callbackViewFactory;
import oscfg.diagram.view.factories.HWCounterEnable_callbackViewFactory;
import oscfg.diagram.view.factories.HWCounterGet_callbackViewFactory;
import oscfg.diagram.view.factories.HWCounterNameViewFactory;
import oscfg.diagram.view.factories.HWCounterSet_callbackViewFactory;
import oscfg.diagram.view.factories.HWCounterSoftwareTimersViewFactory;
import oscfg.diagram.view.factories.HWCounterViewFactory;
import oscfg.diagram.view.factories.ISRIPLViewFactory;
import oscfg.diagram.view.factories.ISRNameViewFactory;
import oscfg.diagram.view.factories.ISRTypeViewFactory;
import oscfg.diagram.view.factories.ISRViewFactory;
import oscfg.diagram.view.factories.InterruptSourceSourceISRViewFactory;
import oscfg.diagram.view.factories.InterruptSourceSourceViewFactory;
import oscfg.diagram.view.factories.InterruptSourceViewFactory;
import oscfg.diagram.view.factories.MessageCtypeViewFactory;
import oscfg.diagram.view.factories.MessageNameViewFactory;
import oscfg.diagram.view.factories.MessageNotifiesViewFactory;
import oscfg.diagram.view.factories.MessageQueueViewFactory;
import oscfg.diagram.view.factories.MessageViewFactory;
import oscfg.diagram.view.factories.ModuleModuleObjectsViewFactory;
import oscfg.diagram.view.factories.ModuleNameViewFactory;
import oscfg.diagram.view.factories.ModuleViewFactory;
import oscfg.diagram.view.factories.MutexNameViewFactory;
import oscfg.diagram.view.factories.MutexViewFactory;
import oscfg.diagram.view.factories.OSOSModulesViewFactory;
import oscfg.diagram.view.factories.OSTargetViewFactory;
import oscfg.diagram.view.factories.OSViewFactory;
import oscfg.diagram.view.factories.PosterPostMessageViewFactory;
import oscfg.diagram.view.factories.SWTimerActivatesViewFactory;
import oscfg.diagram.view.factories.SWTimerNameViewFactory;
import oscfg.diagram.view.factories.SWTimerTimer_callbackViewFactory;
import oscfg.diagram.view.factories.SWTimerViewFactory;
import oscfg.diagram.view.factories.Task2ViewFactory;
import oscfg.diagram.view.factories.TaskAutostarted2ViewFactory;
import oscfg.diagram.view.factories.TaskAutostartedViewFactory;
import oscfg.diagram.view.factories.TaskName2ViewFactory;
import oscfg.diagram.view.factories.TaskNameViewFactory;
import oscfg.diagram.view.factories.TaskPriority2ViewFactory;
import oscfg.diagram.view.factories.TaskPriorityViewFactory;
import oscfg.diagram.view.factories.TaskViewFactory;
import oscfg.diagram.view.factories.WrappingLabel10ViewFactory;
import oscfg.diagram.view.factories.WrappingLabel11ViewFactory;
import oscfg.diagram.view.factories.WrappingLabel2ViewFactory;
import oscfg.diagram.view.factories.WrappingLabel3ViewFactory;
import oscfg.diagram.view.factories.WrappingLabel4ViewFactory;
import oscfg.diagram.view.factories.WrappingLabel5ViewFactory;
import oscfg.diagram.view.factories.WrappingLabel6ViewFactory;
import oscfg.diagram.view.factories.WrappingLabel7ViewFactory;
import oscfg.diagram.view.factories.WrappingLabel8ViewFactory;
import oscfg.diagram.view.factories.WrappingLabel9ViewFactory;
import oscfg.diagram.view.factories.WrappingLabelViewFactory;

/**
 * @generated
 */
public class OscfgViewProvider extends AbstractProvider implements
		IViewProvider {

	/**
	 * @generated
	 */
	public final boolean provides(IOperation operation) {
		if (operation instanceof CreateViewForKindOperation) {
			return provides((CreateViewForKindOperation) operation);
		}
		assert operation instanceof CreateViewOperation;
		if (operation instanceof CreateDiagramViewOperation) {
			return provides((CreateDiagramViewOperation) operation);
		} else if (operation instanceof CreateEdgeViewOperation) {
			return provides((CreateEdgeViewOperation) operation);
		} else if (operation instanceof CreateNodeViewOperation) {
			return provides((CreateNodeViewOperation) operation);
		}
		return false;
	}

	/**
	 * @generated
	 */
	protected boolean provides(CreateViewForKindOperation op) {
		/*
		 if (op.getViewKind() == Node.class)
		 return getNodeViewClass(op.getSemanticAdapter(), op.getContainerView(), op.getSemanticHint()) != null;
		 if (op.getViewKind() == Edge.class)
		 return getEdgeViewClass(op.getSemanticAdapter(), op.getContainerView(), op.getSemanticHint()) != null;
		 */
		return true;
	}

	/**
	 * @generated
	 */
	protected boolean provides(CreateDiagramViewOperation op) {
		return ConfigurationEditPart.MODEL_ID.equals(op.getSemanticHint())
				&& OscfgVisualIDRegistry
						.getDiagramVisualID(getSemanticElement(op
								.getSemanticAdapter())) != -1;
	}

	/**
	 * @generated
	 */
	protected boolean provides(CreateNodeViewOperation op) {
		if (op.getContainerView() == null) {
			return false;
		}
		IElementType elementType = getSemanticElementType(op
				.getSemanticAdapter());
		EObject domainElement = getSemanticElement(op.getSemanticAdapter());
		int visualID;
		if (op.getSemanticHint() == null) {
			// Semantic hint is not specified. Can be a result of call from CanonicalEditPolicy.
			// In this situation there should be NO elementType, visualID will be determined
			// by VisualIDRegistry.getNodeVisualID() for domainElement.
			if (elementType != null || domainElement == null) {
				return false;
			}
			visualID = OscfgVisualIDRegistry.getNodeVisualID(
					op.getContainerView(), domainElement);
		} else {
			visualID = OscfgVisualIDRegistry.getVisualID(op.getSemanticHint());
			if (elementType != null) {
				if (!OscfgElementTypes.isKnownElementType(elementType)
						|| (!(elementType instanceof IHintedType))) {
					return false; // foreign element type
				}
				String elementTypeHint = ((IHintedType) elementType)
						.getSemanticHint();
				if (!op.getSemanticHint().equals(elementTypeHint)) {
					return false; // if semantic hint is specified it should be the same as in element type
				}
				if (domainElement != null
						&& visualID != OscfgVisualIDRegistry.getNodeVisualID(
								op.getContainerView(), domainElement)) {
					return false; // visual id for node EClass should match visual id from element type
				}
			} else {
				if (!ConfigurationEditPart.MODEL_ID
						.equals(OscfgVisualIDRegistry.getModelID(op
								.getContainerView()))) {
					return false; // foreign diagram
				}
				switch (visualID) {
				case OSEditPart.VISUAL_ID:
				case ModuleEditPart.VISUAL_ID:
				case TaskEditPart.VISUAL_ID:
				case ISREditPart.VISUAL_ID:
				case MutexEditPart.VISUAL_ID:
				case MessageEditPart.VISUAL_ID:
				case HWCounterEditPart.VISUAL_ID:
				case SWTimerEditPart.VISUAL_ID:
				case CallbackFunctionEditPart.VISUAL_ID:
				case InterruptSourceEditPart.VISUAL_ID:
				case CooperativeGroupEditPart.VISUAL_ID:
				case Task2EditPart.VISUAL_ID:
					if (domainElement == null
							|| visualID != OscfgVisualIDRegistry
									.getNodeVisualID(op.getContainerView(),
											domainElement)) {
						return false; // visual id in semantic hint should match visual id for domain element
					}
					break;
				default:
					return false;
				}
			}
		}
		return OSEditPart.VISUAL_ID == visualID
				|| ModuleEditPart.VISUAL_ID == visualID
				|| TaskEditPart.VISUAL_ID == visualID
				|| ISREditPart.VISUAL_ID == visualID
				|| MutexEditPart.VISUAL_ID == visualID
				|| MessageEditPart.VISUAL_ID == visualID
				|| HWCounterEditPart.VISUAL_ID == visualID
				|| SWTimerEditPart.VISUAL_ID == visualID
				|| CallbackFunctionEditPart.VISUAL_ID == visualID
				|| InterruptSourceEditPart.VISUAL_ID == visualID
				|| CooperativeGroupEditPart.VISUAL_ID == visualID
				|| Task2EditPart.VISUAL_ID == visualID;
	}

	/**
	 * @generated
	 */
	protected boolean provides(CreateEdgeViewOperation op) {
		IElementType elementType = getSemanticElementType(op
				.getSemanticAdapter());
		if (!OscfgElementTypes.isKnownElementType(elementType)
				|| (!(elementType instanceof IHintedType))) {
			return false; // foreign element type
		}
		String elementTypeHint = ((IHintedType) elementType).getSemanticHint();
		if (elementTypeHint == null
				|| (op.getSemanticHint() != null && !elementTypeHint.equals(op
						.getSemanticHint()))) {
			return false; // our hint is visual id and must be specified, and it should be the same as in element type
		}
		int visualID = OscfgVisualIDRegistry.getVisualID(elementTypeHint);
		EObject domainElement = getSemanticElement(op.getSemanticAdapter());
		if (domainElement != null
				&& visualID != OscfgVisualIDRegistry
						.getLinkWithClassVisualID(domainElement)) {
			return false; // visual id for link EClass should match visual id from element type
		}
		return true;
	}

	/**
	 * @generated
	 */
	public Diagram createDiagram(IAdaptable semanticAdapter,
			String diagramKind, PreferencesHint preferencesHint) {
		Diagram diagram = NotationFactory.eINSTANCE.createDiagram();
		diagram.getStyles().add(NotationFactory.eINSTANCE.createDiagramStyle());
		diagram.setType(ConfigurationEditPart.MODEL_ID);
		diagram.setElement(getSemanticElement(semanticAdapter));
		diagram.setMeasurementUnit(MeasurementUnit.PIXEL_LITERAL);
		return diagram;
	}

	/**
	 * @generated
	 */
	public Node createNode(IAdaptable semanticAdapter, View containerView,
			String semanticHint, int index, boolean persisted,
			PreferencesHint preferencesHint) {
		final EObject domainElement = getSemanticElement(semanticAdapter);
		final int visualID;
		if (semanticHint == null) {
			visualID = OscfgVisualIDRegistry.getNodeVisualID(containerView,
					domainElement);
		} else {
			visualID = OscfgVisualIDRegistry.getVisualID(semanticHint);
		}
		switch (visualID) {
		case OSEditPart.VISUAL_ID:
			return createOS_2001(domainElement, containerView, index,
					persisted, preferencesHint);
		case ModuleEditPart.VISUAL_ID:
			return createModule_3009(domainElement, containerView, index,
					persisted, preferencesHint);
		case TaskEditPart.VISUAL_ID:
			return createTask_3010(domainElement, containerView, index,
					persisted, preferencesHint);
		case ISREditPart.VISUAL_ID:
			return createISR_3011(domainElement, containerView, index,
					persisted, preferencesHint);
		case MutexEditPart.VISUAL_ID:
			return createMutex_3012(domainElement, containerView, index,
					persisted, preferencesHint);
		case MessageEditPart.VISUAL_ID:
			return createMessage_3013(domainElement, containerView, index,
					persisted, preferencesHint);
		case HWCounterEditPart.VISUAL_ID:
			return createHWCounter_3014(domainElement, containerView, index,
					persisted, preferencesHint);
		case SWTimerEditPart.VISUAL_ID:
			return createSWTimer_3006(domainElement, containerView, index,
					persisted, preferencesHint);
		case CallbackFunctionEditPart.VISUAL_ID:
			return createCallbackFunction_3015(domainElement, containerView,
					index, persisted, preferencesHint);
		case InterruptSourceEditPart.VISUAL_ID:
			return createInterruptSource_3016(domainElement, containerView,
					index, persisted, preferencesHint);
		case CooperativeGroupEditPart.VISUAL_ID:
			return createCooperativeGroup_3017(domainElement, containerView,
					index, persisted, preferencesHint);
		case Task2EditPart.VISUAL_ID:
			return createTask_3020(domainElement, containerView, index,
					persisted, preferencesHint);
		}
		// can't happen, provided #provides(CreateNodeViewOperation) is correct
		return null;
	}

	/**
	 * @generated
	 */
	public Edge createEdge(IAdaptable semanticAdapter, View containerView,
			String semanticHint, int index, boolean persisted,
			PreferencesHint preferencesHint) {
		IElementType elementType = getSemanticElementType(semanticAdapter);
		String elementTypeHint = ((IHintedType) elementType).getSemanticHint();
		switch (OscfgVisualIDRegistry.getVisualID(elementTypeHint)) {
		case BaseTaskCollectMessageEditPart.VISUAL_ID:
			return createBaseTaskCollectMessage_4001(containerView, index,
					persisted, preferencesHint);
		case PosterPostMessageEditPart.VISUAL_ID:
			return createPosterPostMessage_4012(containerView, index,
					persisted, preferencesHint);
		case BaseTaskEnterExitMutexEditPart.VISUAL_ID:
			return createBaseTaskEnterExitMutex_4003(containerView, index,
					persisted, preferencesHint);
		case SWTimerActivatesEditPart.VISUAL_ID:
			return createSWTimerActivates_4004(containerView, index, persisted,
					preferencesHint);
		case SWTimerTimer_callbackEditPart.VISUAL_ID:
			return createSWTimerTimer_callback_4005(containerView, index,
					persisted, preferencesHint);
		case MessageNotifiesEditPart.VISUAL_ID:
			return createMessageNotifies_4006(containerView, index, persisted,
					preferencesHint);
		case HWCounterEnable_callbackEditPart.VISUAL_ID:
			return createHWCounterEnable_callback_4007(containerView, index,
					persisted, preferencesHint);
		case HWCounterDisable_callbackEditPart.VISUAL_ID:
			return createHWCounterDisable_callback_4008(containerView, index,
					persisted, preferencesHint);
		case HWCounterGet_callbackEditPart.VISUAL_ID:
			return createHWCounterGet_callback_4009(containerView, index,
					persisted, preferencesHint);
		case HWCounterSet_callbackEditPart.VISUAL_ID:
			return createHWCounterSet_callback_4010(containerView, index,
					persisted, preferencesHint);
		case InterruptSourceSourceISREditPart.VISUAL_ID:
			return createInterruptSourceSourceISR_4011(containerView, index,
					persisted, preferencesHint);
		}
		// can never happen, provided #provides(CreateEdgeViewOperation) is correct
		return null;
	}

	/**
	 * @generated
	 */
	public Node createOS_2001(EObject domainElement, View containerView,
			int index, boolean persisted, PreferencesHint preferencesHint) {
		Node node = NotationFactory.eINSTANCE.createNode();
		node.getStyles()
				.add(NotationFactory.eINSTANCE.createDescriptionStyle());
		node.setLayoutConstraint(NotationFactory.eINSTANCE.createBounds());
		node.setType(OscfgVisualIDRegistry.getType(OSEditPart.VISUAL_ID));
		ViewUtil.insertChildView(containerView, node, index, persisted);
		node.setElement(domainElement);
		stampShortcut(containerView, node);
		// initializeFromPreferences 
		final IPreferenceStore prefStore = (IPreferenceStore) preferencesHint
				.getPreferenceStore();
		Node label5008 = createLabel(node,
				OscfgVisualIDRegistry.getType(OSTargetEditPart.VISUAL_ID));
		createCompartment(node,
				OscfgVisualIDRegistry.getType(OSOSModulesEditPart.VISUAL_ID),
				false, false, false, false);
		return node;
	}

	/**
	 * @generated
	 */
	public Node createModule_3009(EObject domainElement, View containerView,
			int index, boolean persisted, PreferencesHint preferencesHint) {
		Node node = NotationFactory.eINSTANCE.createNode();
		node.getStyles()
				.add(NotationFactory.eINSTANCE.createDescriptionStyle());
		node.setLayoutConstraint(NotationFactory.eINSTANCE.createBounds());
		node.setType(OscfgVisualIDRegistry.getType(ModuleEditPart.VISUAL_ID));
		ViewUtil.insertChildView(containerView, node, index, persisted);
		node.setElement(domainElement);
		// initializeFromPreferences 
		final IPreferenceStore prefStore = (IPreferenceStore) preferencesHint
				.getPreferenceStore();
		Node label5032 = createLabel(node,
				OscfgVisualIDRegistry.getType(ModuleNameEditPart.VISUAL_ID));
		createCompartment(node,
				OscfgVisualIDRegistry
						.getType(ModuleModuleObjectsEditPart.VISUAL_ID), false,
				false, false, false);
		return node;
	}

	/**
	 * @generated
	 */
	public Node createTask_3010(EObject domainElement, View containerView,
			int index, boolean persisted, PreferencesHint preferencesHint) {
		Node node = NotationFactory.eINSTANCE.createNode();
		node.getStyles()
				.add(NotationFactory.eINSTANCE.createDescriptionStyle());
		node.setLayoutConstraint(NotationFactory.eINSTANCE.createBounds());
		node.setType(OscfgVisualIDRegistry.getType(TaskEditPart.VISUAL_ID));
		ViewUtil.insertChildView(containerView, node, index, persisted);
		node.setElement(domainElement);
		// initializeFromPreferences 
		final IPreferenceStore prefStore = (IPreferenceStore) preferencesHint
				.getPreferenceStore();
		Node label5018 = createLabel(node,
				OscfgVisualIDRegistry.getType(TaskNameEditPart.VISUAL_ID));
		Node label5019 = createLabel(node,
				OscfgVisualIDRegistry.getType(TaskPriorityEditPart.VISUAL_ID));
		Node label5020 = createLabel(node,
				OscfgVisualIDRegistry
						.getType(TaskAutostartedEditPart.VISUAL_ID));
		return node;
	}

	/**
	 * @generated
	 */
	public Node createISR_3011(EObject domainElement, View containerView,
			int index, boolean persisted, PreferencesHint preferencesHint) {
		Node node = NotationFactory.eINSTANCE.createNode();
		node.getStyles()
				.add(NotationFactory.eINSTANCE.createDescriptionStyle());
		node.setLayoutConstraint(NotationFactory.eINSTANCE.createBounds());
		node.setType(OscfgVisualIDRegistry.getType(ISREditPart.VISUAL_ID));
		ViewUtil.insertChildView(containerView, node, index, persisted);
		node.setElement(domainElement);
		// initializeFromPreferences 
		final IPreferenceStore prefStore = (IPreferenceStore) preferencesHint
				.getPreferenceStore();
		Node label5022 = createLabel(node,
				OscfgVisualIDRegistry.getType(ISRNameEditPart.VISUAL_ID));
		Node label5023 = createLabel(node,
				OscfgVisualIDRegistry.getType(ISRTypeEditPart.VISUAL_ID));
		Node label5024 = createLabel(node,
				OscfgVisualIDRegistry.getType(ISRIPLEditPart.VISUAL_ID));
		return node;
	}

	/**
	 * @generated
	 */
	public Node createMutex_3012(EObject domainElement, View containerView,
			int index, boolean persisted, PreferencesHint preferencesHint) {
		Node node = NotationFactory.eINSTANCE.createNode();
		node.getStyles()
				.add(NotationFactory.eINSTANCE.createDescriptionStyle());
		node.setLayoutConstraint(NotationFactory.eINSTANCE.createBounds());
		node.setType(OscfgVisualIDRegistry.getType(MutexEditPart.VISUAL_ID));
		ViewUtil.insertChildView(containerView, node, index, persisted);
		node.setElement(domainElement);
		// initializeFromPreferences 
		final IPreferenceStore prefStore = (IPreferenceStore) preferencesHint
				.getPreferenceStore();
		Node label5025 = createLabel(node,
				OscfgVisualIDRegistry.getType(MutexNameEditPart.VISUAL_ID));
		return node;
	}

	/**
	 * @generated
	 */
	public Node createMessage_3013(EObject domainElement, View containerView,
			int index, boolean persisted, PreferencesHint preferencesHint) {
		Node node = NotationFactory.eINSTANCE.createNode();
		node.getStyles()
				.add(NotationFactory.eINSTANCE.createDescriptionStyle());
		node.setLayoutConstraint(NotationFactory.eINSTANCE.createBounds());
		node.setType(OscfgVisualIDRegistry.getType(MessageEditPart.VISUAL_ID));
		ViewUtil.insertChildView(containerView, node, index, persisted);
		node.setElement(domainElement);
		// initializeFromPreferences 
		final IPreferenceStore prefStore = (IPreferenceStore) preferencesHint
				.getPreferenceStore();
		Node label5026 = createLabel(node,
				OscfgVisualIDRegistry.getType(MessageNameEditPart.VISUAL_ID));
		Node label5027 = createLabel(node,
				OscfgVisualIDRegistry.getType(MessageCtypeEditPart.VISUAL_ID));
		Node label5028 = createLabel(node,
				OscfgVisualIDRegistry.getType(MessageQueueEditPart.VISUAL_ID));
		return node;
	}

	/**
	 * @generated
	 */
	public Node createHWCounter_3014(EObject domainElement, View containerView,
			int index, boolean persisted, PreferencesHint preferencesHint) {
		Node node = NotationFactory.eINSTANCE.createNode();
		node.getStyles()
				.add(NotationFactory.eINSTANCE.createDescriptionStyle());
		node.setLayoutConstraint(NotationFactory.eINSTANCE.createBounds());
		node.setType(OscfgVisualIDRegistry.getType(HWCounterEditPart.VISUAL_ID));
		ViewUtil.insertChildView(containerView, node, index, persisted);
		node.setElement(domainElement);
		// initializeFromPreferences 
		final IPreferenceStore prefStore = (IPreferenceStore) preferencesHint
				.getPreferenceStore();
		Node label5029 = createLabel(node,
				OscfgVisualIDRegistry.getType(HWCounterNameEditPart.VISUAL_ID));
		createCompartment(node,
				OscfgVisualIDRegistry
						.getType(HWCounterSoftwareTimersEditPart.VISUAL_ID),
				false, true, false, false);
		return node;
	}

	/**
	 * @generated
	 */
	public Node createSWTimer_3006(EObject domainElement, View containerView,
			int index, boolean persisted, PreferencesHint preferencesHint) {
		Node node = NotationFactory.eINSTANCE.createNode();
		node.getStyles()
				.add(NotationFactory.eINSTANCE.createDescriptionStyle());
		node.setLayoutConstraint(NotationFactory.eINSTANCE.createBounds());
		node.setType(OscfgVisualIDRegistry.getType(SWTimerEditPart.VISUAL_ID));
		ViewUtil.insertChildView(containerView, node, index, persisted);
		node.setElement(domainElement);
		// initializeFromPreferences 
		final IPreferenceStore prefStore = (IPreferenceStore) preferencesHint
				.getPreferenceStore();
		Node label5005 = createLabel(node,
				OscfgVisualIDRegistry.getType(SWTimerNameEditPart.VISUAL_ID));
		return node;
	}

	/**
	 * @generated
	 */
	public Node createCallbackFunction_3015(EObject domainElement,
			View containerView, int index, boolean persisted,
			PreferencesHint preferencesHint) {
		Node node = NotationFactory.eINSTANCE.createNode();
		node.getStyles()
				.add(NotationFactory.eINSTANCE.createDescriptionStyle());
		node.setLayoutConstraint(NotationFactory.eINSTANCE.createBounds());
		node.setType(OscfgVisualIDRegistry
				.getType(CallbackFunctionEditPart.VISUAL_ID));
		ViewUtil.insertChildView(containerView, node, index, persisted);
		node.setElement(domainElement);
		// initializeFromPreferences 
		final IPreferenceStore prefStore = (IPreferenceStore) preferencesHint
				.getPreferenceStore();
		Node label5030 = createLabel(node,
				OscfgVisualIDRegistry
						.getType(CallbackFunctionNameEditPart.VISUAL_ID));
		return node;
	}

	/**
	 * @generated
	 */
	public Node createInterruptSource_3016(EObject domainElement,
			View containerView, int index, boolean persisted,
			PreferencesHint preferencesHint) {
		Node node = NotationFactory.eINSTANCE.createNode();
		node.getStyles()
				.add(NotationFactory.eINSTANCE.createDescriptionStyle());
		node.setLayoutConstraint(NotationFactory.eINSTANCE.createBounds());
		node.setType(OscfgVisualIDRegistry
				.getType(InterruptSourceEditPart.VISUAL_ID));
		ViewUtil.insertChildView(containerView, node, index, persisted);
		node.setElement(domainElement);
		// initializeFromPreferences 
		final IPreferenceStore prefStore = (IPreferenceStore) preferencesHint
				.getPreferenceStore();
		Node label5031 = createLabel(node,
				OscfgVisualIDRegistry
						.getType(InterruptSourceSourceEditPart.VISUAL_ID));
		return node;
	}

	/**
	 * @generated
	 */
	public Node createCooperativeGroup_3017(EObject domainElement,
			View containerView, int index, boolean persisted,
			PreferencesHint preferencesHint) {
		Node node = NotationFactory.eINSTANCE.createNode();
		node.getStyles()
				.add(NotationFactory.eINSTANCE.createDescriptionStyle());
		node.setLayoutConstraint(NotationFactory.eINSTANCE.createBounds());
		node.setType(OscfgVisualIDRegistry
				.getType(CooperativeGroupEditPart.VISUAL_ID));
		ViewUtil.insertChildView(containerView, node, index, persisted);
		node.setElement(domainElement);
		// initializeFromPreferences 
		final IPreferenceStore prefStore = (IPreferenceStore) preferencesHint
				.getPreferenceStore();
		Node label5036 = createLabel(node,
				OscfgVisualIDRegistry
						.getType(CooperativeGroupNameEditPart.VISUAL_ID));
		createCompartment(
				node,
				OscfgVisualIDRegistry
						.getType(CooperativeGroupCooperativeTasksEditPart.VISUAL_ID),
				false, true, false, false);
		return node;
	}

	/**
	 * @generated
	 */
	public Node createTask_3020(EObject domainElement, View containerView,
			int index, boolean persisted, PreferencesHint preferencesHint) {
		Node node = NotationFactory.eINSTANCE.createNode();
		node.getStyles()
				.add(NotationFactory.eINSTANCE.createDescriptionStyle());
		node.setLayoutConstraint(NotationFactory.eINSTANCE.createBounds());
		node.setType(OscfgVisualIDRegistry.getType(Task2EditPart.VISUAL_ID));
		ViewUtil.insertChildView(containerView, node, index, persisted);
		node.setElement(domainElement);
		// initializeFromPreferences 
		final IPreferenceStore prefStore = (IPreferenceStore) preferencesHint
				.getPreferenceStore();
		Node label5040 = createLabel(node,
				OscfgVisualIDRegistry.getType(TaskName2EditPart.VISUAL_ID));
		Node label5041 = createLabel(node,
				OscfgVisualIDRegistry.getType(TaskPriority2EditPart.VISUAL_ID));
		Node label5042 = createLabel(node,
				OscfgVisualIDRegistry
						.getType(TaskAutostarted2EditPart.VISUAL_ID));
		return node;
	}

	/**
	 * @generated
	 */
	public Edge createBaseTaskCollectMessage_4001(View containerView,
			int index, boolean persisted, PreferencesHint preferencesHint) {
		Edge edge = NotationFactory.eINSTANCE.createEdge();
		edge.getStyles().add(NotationFactory.eINSTANCE.createRoutingStyle());
		RelativeBendpoints bendpoints = NotationFactory.eINSTANCE
				.createRelativeBendpoints();
		ArrayList<RelativeBendpoint> points = new ArrayList<RelativeBendpoint>(
				2);
		points.add(new RelativeBendpoint());
		points.add(new RelativeBendpoint());
		bendpoints.setPoints(points);
		edge.setBendpoints(bendpoints);
		ViewUtil.insertChildView(containerView, edge, index, persisted);
		edge.setType(OscfgVisualIDRegistry
				.getType(BaseTaskCollectMessageEditPart.VISUAL_ID));
		edge.setElement(null);
		// initializePreferences
		final IPreferenceStore prefStore = (IPreferenceStore) preferencesHint
				.getPreferenceStore();
		Routing routing = Routing.get(prefStore
				.getInt(IPreferenceConstants.PREF_LINE_STYLE));
		if (routing != null) {
			ViewUtil.setStructuralFeatureValue(edge,
					NotationPackage.eINSTANCE.getRoutingStyle_Routing(),
					routing);
		}
		Node label6002 = createLabel(edge,
				OscfgVisualIDRegistry.getType(WrappingLabelEditPart.VISUAL_ID));
		label6002.setLayoutConstraint(NotationFactory.eINSTANCE
				.createLocation());
		Location location6002 = (Location) label6002.getLayoutConstraint();
		location6002.setX(0);
		location6002.setY(40);
		return edge;
	}

	/**
	 * @generated
	 */
	public Edge createPosterPostMessage_4012(View containerView, int index,
			boolean persisted, PreferencesHint preferencesHint) {
		Edge edge = NotationFactory.eINSTANCE.createEdge();
		edge.getStyles().add(NotationFactory.eINSTANCE.createRoutingStyle());
		RelativeBendpoints bendpoints = NotationFactory.eINSTANCE
				.createRelativeBendpoints();
		ArrayList<RelativeBendpoint> points = new ArrayList<RelativeBendpoint>(
				2);
		points.add(new RelativeBendpoint());
		points.add(new RelativeBendpoint());
		bendpoints.setPoints(points);
		edge.setBendpoints(bendpoints);
		ViewUtil.insertChildView(containerView, edge, index, persisted);
		edge.setType(OscfgVisualIDRegistry
				.getType(PosterPostMessageEditPart.VISUAL_ID));
		edge.setElement(null);
		// initializePreferences
		final IPreferenceStore prefStore = (IPreferenceStore) preferencesHint
				.getPreferenceStore();
		Routing routing = Routing.get(prefStore
				.getInt(IPreferenceConstants.PREF_LINE_STYLE));
		if (routing != null) {
			ViewUtil.setStructuralFeatureValue(edge,
					NotationPackage.eINSTANCE.getRoutingStyle_Routing(),
					routing);
		}
		Node label6012 = createLabel(edge,
				OscfgVisualIDRegistry.getType(WrappingLabel2EditPart.VISUAL_ID));
		label6012.setLayoutConstraint(NotationFactory.eINSTANCE
				.createLocation());
		Location location6012 = (Location) label6012.getLayoutConstraint();
		location6012.setX(0);
		location6012.setY(40);
		return edge;
	}

	/**
	 * @generated
	 */
	public Edge createBaseTaskEnterExitMutex_4003(View containerView,
			int index, boolean persisted, PreferencesHint preferencesHint) {
		Edge edge = NotationFactory.eINSTANCE.createEdge();
		edge.getStyles().add(NotationFactory.eINSTANCE.createRoutingStyle());
		RelativeBendpoints bendpoints = NotationFactory.eINSTANCE
				.createRelativeBendpoints();
		ArrayList<RelativeBendpoint> points = new ArrayList<RelativeBendpoint>(
				2);
		points.add(new RelativeBendpoint());
		points.add(new RelativeBendpoint());
		bendpoints.setPoints(points);
		edge.setBendpoints(bendpoints);
		ViewUtil.insertChildView(containerView, edge, index, persisted);
		edge.setType(OscfgVisualIDRegistry
				.getType(BaseTaskEnterExitMutexEditPart.VISUAL_ID));
		edge.setElement(null);
		// initializePreferences
		final IPreferenceStore prefStore = (IPreferenceStore) preferencesHint
				.getPreferenceStore();
		Routing routing = Routing.get(prefStore
				.getInt(IPreferenceConstants.PREF_LINE_STYLE));
		if (routing != null) {
			ViewUtil.setStructuralFeatureValue(edge,
					NotationPackage.eINSTANCE.getRoutingStyle_Routing(),
					routing);
		}
		Node label6004 = createLabel(edge,
				OscfgVisualIDRegistry.getType(WrappingLabel3EditPart.VISUAL_ID));
		label6004.setLayoutConstraint(NotationFactory.eINSTANCE
				.createLocation());
		Location location6004 = (Location) label6004.getLayoutConstraint();
		location6004.setX(0);
		location6004.setY(40);
		return edge;
	}

	/**
	 * @generated
	 */
	public Edge createSWTimerActivates_4004(View containerView, int index,
			boolean persisted, PreferencesHint preferencesHint) {
		Edge edge = NotationFactory.eINSTANCE.createEdge();
		edge.getStyles().add(NotationFactory.eINSTANCE.createRoutingStyle());
		RelativeBendpoints bendpoints = NotationFactory.eINSTANCE
				.createRelativeBendpoints();
		ArrayList<RelativeBendpoint> points = new ArrayList<RelativeBendpoint>(
				2);
		points.add(new RelativeBendpoint());
		points.add(new RelativeBendpoint());
		bendpoints.setPoints(points);
		edge.setBendpoints(bendpoints);
		ViewUtil.insertChildView(containerView, edge, index, persisted);
		edge.setType(OscfgVisualIDRegistry
				.getType(SWTimerActivatesEditPart.VISUAL_ID));
		edge.setElement(null);
		// initializePreferences
		final IPreferenceStore prefStore = (IPreferenceStore) preferencesHint
				.getPreferenceStore();
		Routing routing = Routing.get(prefStore
				.getInt(IPreferenceConstants.PREF_LINE_STYLE));
		if (routing != null) {
			ViewUtil.setStructuralFeatureValue(edge,
					NotationPackage.eINSTANCE.getRoutingStyle_Routing(),
					routing);
		}
		Node label6005 = createLabel(edge,
				OscfgVisualIDRegistry.getType(WrappingLabel4EditPart.VISUAL_ID));
		label6005.setLayoutConstraint(NotationFactory.eINSTANCE
				.createLocation());
		Location location6005 = (Location) label6005.getLayoutConstraint();
		location6005.setX(0);
		location6005.setY(40);
		return edge;
	}

	/**
	 * @generated
	 */
	public Edge createSWTimerTimer_callback_4005(View containerView, int index,
			boolean persisted, PreferencesHint preferencesHint) {
		Edge edge = NotationFactory.eINSTANCE.createEdge();
		edge.getStyles().add(NotationFactory.eINSTANCE.createRoutingStyle());
		RelativeBendpoints bendpoints = NotationFactory.eINSTANCE
				.createRelativeBendpoints();
		ArrayList<RelativeBendpoint> points = new ArrayList<RelativeBendpoint>(
				2);
		points.add(new RelativeBendpoint());
		points.add(new RelativeBendpoint());
		bendpoints.setPoints(points);
		edge.setBendpoints(bendpoints);
		ViewUtil.insertChildView(containerView, edge, index, persisted);
		edge.setType(OscfgVisualIDRegistry
				.getType(SWTimerTimer_callbackEditPart.VISUAL_ID));
		edge.setElement(null);
		// initializePreferences
		final IPreferenceStore prefStore = (IPreferenceStore) preferencesHint
				.getPreferenceStore();
		Routing routing = Routing.get(prefStore
				.getInt(IPreferenceConstants.PREF_LINE_STYLE));
		if (routing != null) {
			ViewUtil.setStructuralFeatureValue(edge,
					NotationPackage.eINSTANCE.getRoutingStyle_Routing(),
					routing);
		}
		Node label6006 = createLabel(edge,
				OscfgVisualIDRegistry.getType(WrappingLabel5EditPart.VISUAL_ID));
		label6006.setLayoutConstraint(NotationFactory.eINSTANCE
				.createLocation());
		Location location6006 = (Location) label6006.getLayoutConstraint();
		location6006.setX(0);
		location6006.setY(40);
		return edge;
	}

	/**
	 * @generated
	 */
	public Edge createMessageNotifies_4006(View containerView, int index,
			boolean persisted, PreferencesHint preferencesHint) {
		Edge edge = NotationFactory.eINSTANCE.createEdge();
		edge.getStyles().add(NotationFactory.eINSTANCE.createRoutingStyle());
		RelativeBendpoints bendpoints = NotationFactory.eINSTANCE
				.createRelativeBendpoints();
		ArrayList<RelativeBendpoint> points = new ArrayList<RelativeBendpoint>(
				2);
		points.add(new RelativeBendpoint());
		points.add(new RelativeBendpoint());
		bendpoints.setPoints(points);
		edge.setBendpoints(bendpoints);
		ViewUtil.insertChildView(containerView, edge, index, persisted);
		edge.setType(OscfgVisualIDRegistry
				.getType(MessageNotifiesEditPart.VISUAL_ID));
		edge.setElement(null);
		// initializePreferences
		final IPreferenceStore prefStore = (IPreferenceStore) preferencesHint
				.getPreferenceStore();
		Routing routing = Routing.get(prefStore
				.getInt(IPreferenceConstants.PREF_LINE_STYLE));
		if (routing != null) {
			ViewUtil.setStructuralFeatureValue(edge,
					NotationPackage.eINSTANCE.getRoutingStyle_Routing(),
					routing);
		}
		Node label6003 = createLabel(edge,
				OscfgVisualIDRegistry.getType(WrappingLabel6EditPart.VISUAL_ID));
		label6003.setLayoutConstraint(NotationFactory.eINSTANCE
				.createLocation());
		Location location6003 = (Location) label6003.getLayoutConstraint();
		location6003.setX(0);
		location6003.setY(40);
		return edge;
	}

	/**
	 * @generated
	 */
	public Edge createHWCounterEnable_callback_4007(View containerView,
			int index, boolean persisted, PreferencesHint preferencesHint) {
		Edge edge = NotationFactory.eINSTANCE.createEdge();
		edge.getStyles().add(NotationFactory.eINSTANCE.createRoutingStyle());
		RelativeBendpoints bendpoints = NotationFactory.eINSTANCE
				.createRelativeBendpoints();
		ArrayList<RelativeBendpoint> points = new ArrayList<RelativeBendpoint>(
				2);
		points.add(new RelativeBendpoint());
		points.add(new RelativeBendpoint());
		bendpoints.setPoints(points);
		edge.setBendpoints(bendpoints);
		ViewUtil.insertChildView(containerView, edge, index, persisted);
		edge.setType(OscfgVisualIDRegistry
				.getType(HWCounterEnable_callbackEditPart.VISUAL_ID));
		edge.setElement(null);
		// initializePreferences
		final IPreferenceStore prefStore = (IPreferenceStore) preferencesHint
				.getPreferenceStore();
		Routing routing = Routing.get(prefStore
				.getInt(IPreferenceConstants.PREF_LINE_STYLE));
		if (routing != null) {
			ViewUtil.setStructuralFeatureValue(edge,
					NotationPackage.eINSTANCE.getRoutingStyle_Routing(),
					routing);
		}
		Node label6007 = createLabel(edge,
				OscfgVisualIDRegistry.getType(WrappingLabel7EditPart.VISUAL_ID));
		label6007.setLayoutConstraint(NotationFactory.eINSTANCE
				.createLocation());
		Location location6007 = (Location) label6007.getLayoutConstraint();
		location6007.setX(0);
		location6007.setY(40);
		return edge;
	}

	/**
	 * @generated
	 */
	public Edge createHWCounterDisable_callback_4008(View containerView,
			int index, boolean persisted, PreferencesHint preferencesHint) {
		Edge edge = NotationFactory.eINSTANCE.createEdge();
		edge.getStyles().add(NotationFactory.eINSTANCE.createRoutingStyle());
		RelativeBendpoints bendpoints = NotationFactory.eINSTANCE
				.createRelativeBendpoints();
		ArrayList<RelativeBendpoint> points = new ArrayList<RelativeBendpoint>(
				2);
		points.add(new RelativeBendpoint());
		points.add(new RelativeBendpoint());
		bendpoints.setPoints(points);
		edge.setBendpoints(bendpoints);
		ViewUtil.insertChildView(containerView, edge, index, persisted);
		edge.setType(OscfgVisualIDRegistry
				.getType(HWCounterDisable_callbackEditPart.VISUAL_ID));
		edge.setElement(null);
		// initializePreferences
		final IPreferenceStore prefStore = (IPreferenceStore) preferencesHint
				.getPreferenceStore();
		Routing routing = Routing.get(prefStore
				.getInt(IPreferenceConstants.PREF_LINE_STYLE));
		if (routing != null) {
			ViewUtil.setStructuralFeatureValue(edge,
					NotationPackage.eINSTANCE.getRoutingStyle_Routing(),
					routing);
		}
		Node label6008 = createLabel(edge,
				OscfgVisualIDRegistry.getType(WrappingLabel8EditPart.VISUAL_ID));
		label6008.setLayoutConstraint(NotationFactory.eINSTANCE
				.createLocation());
		Location location6008 = (Location) label6008.getLayoutConstraint();
		location6008.setX(0);
		location6008.setY(40);
		return edge;
	}

	/**
	 * @generated
	 */
	public Edge createHWCounterGet_callback_4009(View containerView, int index,
			boolean persisted, PreferencesHint preferencesHint) {
		Edge edge = NotationFactory.eINSTANCE.createEdge();
		edge.getStyles().add(NotationFactory.eINSTANCE.createRoutingStyle());
		RelativeBendpoints bendpoints = NotationFactory.eINSTANCE
				.createRelativeBendpoints();
		ArrayList<RelativeBendpoint> points = new ArrayList<RelativeBendpoint>(
				2);
		points.add(new RelativeBendpoint());
		points.add(new RelativeBendpoint());
		bendpoints.setPoints(points);
		edge.setBendpoints(bendpoints);
		ViewUtil.insertChildView(containerView, edge, index, persisted);
		edge.setType(OscfgVisualIDRegistry
				.getType(HWCounterGet_callbackEditPart.VISUAL_ID));
		edge.setElement(null);
		// initializePreferences
		final IPreferenceStore prefStore = (IPreferenceStore) preferencesHint
				.getPreferenceStore();
		Routing routing = Routing.get(prefStore
				.getInt(IPreferenceConstants.PREF_LINE_STYLE));
		if (routing != null) {
			ViewUtil.setStructuralFeatureValue(edge,
					NotationPackage.eINSTANCE.getRoutingStyle_Routing(),
					routing);
		}
		Node label6009 = createLabel(edge,
				OscfgVisualIDRegistry.getType(WrappingLabel9EditPart.VISUAL_ID));
		label6009.setLayoutConstraint(NotationFactory.eINSTANCE
				.createLocation());
		Location location6009 = (Location) label6009.getLayoutConstraint();
		location6009.setX(0);
		location6009.setY(40);
		return edge;
	}

	/**
	 * @generated
	 */
	public Edge createHWCounterSet_callback_4010(View containerView, int index,
			boolean persisted, PreferencesHint preferencesHint) {
		Edge edge = NotationFactory.eINSTANCE.createEdge();
		edge.getStyles().add(NotationFactory.eINSTANCE.createRoutingStyle());
		RelativeBendpoints bendpoints = NotationFactory.eINSTANCE
				.createRelativeBendpoints();
		ArrayList<RelativeBendpoint> points = new ArrayList<RelativeBendpoint>(
				2);
		points.add(new RelativeBendpoint());
		points.add(new RelativeBendpoint());
		bendpoints.setPoints(points);
		edge.setBendpoints(bendpoints);
		ViewUtil.insertChildView(containerView, edge, index, persisted);
		edge.setType(OscfgVisualIDRegistry
				.getType(HWCounterSet_callbackEditPart.VISUAL_ID));
		edge.setElement(null);
		// initializePreferences
		final IPreferenceStore prefStore = (IPreferenceStore) preferencesHint
				.getPreferenceStore();
		Routing routing = Routing.get(prefStore
				.getInt(IPreferenceConstants.PREF_LINE_STYLE));
		if (routing != null) {
			ViewUtil.setStructuralFeatureValue(edge,
					NotationPackage.eINSTANCE.getRoutingStyle_Routing(),
					routing);
		}
		Node label6010 = createLabel(edge,
				OscfgVisualIDRegistry
						.getType(WrappingLabel10EditPart.VISUAL_ID));
		label6010.setLayoutConstraint(NotationFactory.eINSTANCE
				.createLocation());
		Location location6010 = (Location) label6010.getLayoutConstraint();
		location6010.setX(0);
		location6010.setY(40);
		return edge;
	}

	/**
	 * @generated
	 */
	public Edge createInterruptSourceSourceISR_4011(View containerView,
			int index, boolean persisted, PreferencesHint preferencesHint) {
		Edge edge = NotationFactory.eINSTANCE.createEdge();
		edge.getStyles().add(NotationFactory.eINSTANCE.createRoutingStyle());
		RelativeBendpoints bendpoints = NotationFactory.eINSTANCE
				.createRelativeBendpoints();
		ArrayList<RelativeBendpoint> points = new ArrayList<RelativeBendpoint>(
				2);
		points.add(new RelativeBendpoint());
		points.add(new RelativeBendpoint());
		bendpoints.setPoints(points);
		edge.setBendpoints(bendpoints);
		ViewUtil.insertChildView(containerView, edge, index, persisted);
		edge.setType(OscfgVisualIDRegistry
				.getType(InterruptSourceSourceISREditPart.VISUAL_ID));
		edge.setElement(null);
		// initializePreferences
		final IPreferenceStore prefStore = (IPreferenceStore) preferencesHint
				.getPreferenceStore();
		Routing routing = Routing.get(prefStore
				.getInt(IPreferenceConstants.PREF_LINE_STYLE));
		if (routing != null) {
			ViewUtil.setStructuralFeatureValue(edge,
					NotationPackage.eINSTANCE.getRoutingStyle_Routing(),
					routing);
		}
		Node label6011 = createLabel(edge,
				OscfgVisualIDRegistry
						.getType(WrappingLabel11EditPart.VISUAL_ID));
		label6011.setLayoutConstraint(NotationFactory.eINSTANCE
				.createLocation());
		Location location6011 = (Location) label6011.getLayoutConstraint();
		location6011.setX(0);
		location6011.setY(40);
		return edge;
	}

	/**
	 * @generated
	 */
	private void stampShortcut(View containerView, Node target) {
		if (!ConfigurationEditPart.MODEL_ID.equals(OscfgVisualIDRegistry
				.getModelID(containerView))) {
			EAnnotation shortcutAnnotation = EcoreFactory.eINSTANCE
					.createEAnnotation();
			shortcutAnnotation.setSource("Shortcut"); //$NON-NLS-1$
			shortcutAnnotation.getDetails().put(
					"modelID", ConfigurationEditPart.MODEL_ID); //$NON-NLS-1$
			target.getEAnnotations().add(shortcutAnnotation);
		}
	}

	/**
	 * @generated
	 */
	private Node createLabel(View owner, String hint) {
		DecorationNode rv = NotationFactory.eINSTANCE.createDecorationNode();
		rv.setType(hint);
		ViewUtil.insertChildView(owner, rv, ViewUtil.APPEND, true);
		return rv;
	}

	/**
	 * @generated
	 */
	private Node createCompartment(View owner, String hint,
			boolean canCollapse, boolean hasTitle, boolean canSort,
			boolean canFilter) {
		//SemanticListCompartment rv = NotationFactory.eINSTANCE.createSemanticListCompartment();
		//rv.setShowTitle(showTitle);
		//rv.setCollapsed(isCollapsed);
		Node rv;
		if (canCollapse) {
			rv = NotationFactory.eINSTANCE.createBasicCompartment();
		} else {
			rv = NotationFactory.eINSTANCE.createDecorationNode();
		}
		if (hasTitle) {
			TitleStyle ts = NotationFactory.eINSTANCE.createTitleStyle();
			ts.setShowTitle(true);
			rv.getStyles().add(ts);
		}
		if (canSort) {
			rv.getStyles().add(NotationFactory.eINSTANCE.createSortingStyle());
		}
		if (canFilter) {
			rv.getStyles()
					.add(NotationFactory.eINSTANCE.createFilteringStyle());
		}
		rv.setType(hint);
		ViewUtil.insertChildView(owner, rv, ViewUtil.APPEND, true);
		return rv;
	}

	/**
	 * @generated
	 */
	private EObject getSemanticElement(IAdaptable semanticAdapter) {
		if (semanticAdapter == null) {
			return null;
		}
		EObject eObject = (EObject) semanticAdapter.getAdapter(EObject.class);
		if (eObject != null) {
			return EMFCoreUtil.resolve(
					TransactionUtil.getEditingDomain(eObject), eObject);
		}
		return null;
	}

	/**
	 * @generated
	 */
	private IElementType getSemanticElementType(IAdaptable semanticAdapter) {
		if (semanticAdapter == null) {
			return null;
		}
		return (IElementType) semanticAdapter.getAdapter(IElementType.class);
	}
}
