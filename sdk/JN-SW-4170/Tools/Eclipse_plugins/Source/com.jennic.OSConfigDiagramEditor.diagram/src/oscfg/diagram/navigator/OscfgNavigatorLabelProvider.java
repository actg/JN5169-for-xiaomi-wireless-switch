package oscfg.diagram.navigator;

import org.eclipse.core.runtime.IAdaptable;
import org.eclipse.gmf.runtime.common.ui.services.parser.IParser;
import org.eclipse.gmf.runtime.common.ui.services.parser.ParserOptions;
import org.eclipse.gmf.runtime.common.ui.services.parser.ParserService;
import org.eclipse.gmf.runtime.emf.core.util.EObjectAdapter;
import org.eclipse.gmf.runtime.emf.type.core.IElementType;
import org.eclipse.gmf.runtime.notation.View;
import org.eclipse.jface.resource.ImageDescriptor;
import org.eclipse.jface.resource.ImageRegistry;
import org.eclipse.jface.viewers.ITreePathLabelProvider;
import org.eclipse.jface.viewers.LabelProvider;
import org.eclipse.jface.viewers.TreePath;
import org.eclipse.jface.viewers.ViewerLabel;
import org.eclipse.swt.graphics.Image;
import org.eclipse.ui.IMemento;
import org.eclipse.ui.navigator.ICommonContentExtensionSite;
import org.eclipse.ui.navigator.ICommonLabelProvider;

import oscfg.Configuration;
import oscfg.diagram.edit.parts.BaseTaskCollectMessageEditPart;
import oscfg.diagram.edit.parts.BaseTaskEnterExitMutexEditPart;
import oscfg.diagram.edit.parts.CallbackFunctionEditPart;
import oscfg.diagram.edit.parts.CallbackFunctionNameEditPart;
import oscfg.diagram.edit.parts.ConfigurationEditPart;
import oscfg.diagram.edit.parts.CooperativeGroupEditPart;
import oscfg.diagram.edit.parts.CooperativeGroupNameEditPart;
import oscfg.diagram.edit.parts.HWCounterDisable_callbackEditPart;
import oscfg.diagram.edit.parts.HWCounterEditPart;
import oscfg.diagram.edit.parts.HWCounterEnable_callbackEditPart;
import oscfg.diagram.edit.parts.HWCounterGet_callbackEditPart;
import oscfg.diagram.edit.parts.HWCounterNameEditPart;
import oscfg.diagram.edit.parts.HWCounterSet_callbackEditPart;
import oscfg.diagram.edit.parts.ISREditPart;
import oscfg.diagram.edit.parts.ISRNameEditPart;
import oscfg.diagram.edit.parts.InterruptSourceEditPart;
import oscfg.diagram.edit.parts.InterruptSourceSourceEditPart;
import oscfg.diagram.edit.parts.InterruptSourceSourceISREditPart;
import oscfg.diagram.edit.parts.MessageEditPart;
import oscfg.diagram.edit.parts.MessageNameEditPart;
import oscfg.diagram.edit.parts.MessageNotifiesEditPart;
import oscfg.diagram.edit.parts.ModuleEditPart;
import oscfg.diagram.edit.parts.ModuleNameEditPart;
import oscfg.diagram.edit.parts.MutexEditPart;
import oscfg.diagram.edit.parts.MutexNameEditPart;
import oscfg.diagram.edit.parts.OSEditPart;
import oscfg.diagram.edit.parts.OSTargetEditPart;
import oscfg.diagram.edit.parts.PosterPostMessageEditPart;
import oscfg.diagram.edit.parts.SWTimerActivatesEditPart;
import oscfg.diagram.edit.parts.SWTimerEditPart;
import oscfg.diagram.edit.parts.SWTimerNameEditPart;
import oscfg.diagram.edit.parts.SWTimerTimer_callbackEditPart;
import oscfg.diagram.edit.parts.Task2EditPart;
import oscfg.diagram.edit.parts.TaskEditPart;
import oscfg.diagram.edit.parts.TaskName2EditPart;
import oscfg.diagram.edit.parts.TaskNameEditPart;
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
import oscfg.diagram.part.OscfgDiagramEditorPlugin;
import oscfg.diagram.part.OscfgVisualIDRegistry;
import oscfg.diagram.providers.OscfgElementTypes;
import oscfg.diagram.providers.OscfgParserProvider;

/**
 * @generated
 */
public class OscfgNavigatorLabelProvider extends LabelProvider implements
		ICommonLabelProvider, ITreePathLabelProvider {

	/**
	 * @generated
	 */
	static {
		OscfgDiagramEditorPlugin
				.getInstance()
				.getImageRegistry()
				.put("Navigator?UnknownElement", ImageDescriptor.getMissingImageDescriptor()); //$NON-NLS-1$
		OscfgDiagramEditorPlugin
				.getInstance()
				.getImageRegistry()
				.put("Navigator?ImageNotFound", ImageDescriptor.getMissingImageDescriptor()); //$NON-NLS-1$
	}

	/**
	 * @generated
	 */
	public void updateLabel(ViewerLabel label, TreePath elementPath) {
		Object element = elementPath.getLastSegment();
		if (element instanceof OscfgNavigatorItem
				&& !isOwnView(((OscfgNavigatorItem) element).getView())) {
			return;
		}
		label.setText(getText(element));
		label.setImage(getImage(element));
	}

	/**
	 * @generated
	 */
	public Image getImage(Object element) {
		if (element instanceof OscfgNavigatorGroup) {
			OscfgNavigatorGroup group = (OscfgNavigatorGroup) element;
			return OscfgDiagramEditorPlugin.getInstance().getBundledImage(
					group.getIcon());
		}

		if (element instanceof OscfgNavigatorItem) {
			OscfgNavigatorItem navigatorItem = (OscfgNavigatorItem) element;
			if (!isOwnView(navigatorItem.getView())) {
				return super.getImage(element);
			}
			return getImage(navigatorItem.getView());
		}

		return super.getImage(element);
	}

	/**
	 * @generated
	 */
	public Image getImage(View view) {
		switch (OscfgVisualIDRegistry.getVisualID(view)) {
		case ConfigurationEditPart.VISUAL_ID:
			return getImage(
					"Navigator?Diagram?http://www.jennic.com/OSConfig?Configuration", OscfgElementTypes.Configuration_1000); //$NON-NLS-1$
		case OSEditPart.VISUAL_ID:
			return getImage(
					"Navigator?TopLevelNode?http://www.jennic.com/OSConfig?OS", OscfgElementTypes.OS_2001); //$NON-NLS-1$
		case SWTimerEditPart.VISUAL_ID:
			return getImage(
					"Navigator?Node?http://www.jennic.com/OSConfig?SWTimer", OscfgElementTypes.SWTimer_3006); //$NON-NLS-1$
		case ModuleEditPart.VISUAL_ID:
			return getImage(
					"Navigator?Node?http://www.jennic.com/OSConfig?Module", OscfgElementTypes.Module_3009); //$NON-NLS-1$
		case TaskEditPart.VISUAL_ID:
			return getImage(
					"Navigator?Node?http://www.jennic.com/OSConfig?Task", OscfgElementTypes.Task_3010); //$NON-NLS-1$
		case ISREditPart.VISUAL_ID:
			return getImage(
					"Navigator?Node?http://www.jennic.com/OSConfig?ISR", OscfgElementTypes.ISR_3011); //$NON-NLS-1$
		case MutexEditPart.VISUAL_ID:
			return getImage(
					"Navigator?Node?http://www.jennic.com/OSConfig?Mutex", OscfgElementTypes.Mutex_3012); //$NON-NLS-1$
		case MessageEditPart.VISUAL_ID:
			return getImage(
					"Navigator?Node?http://www.jennic.com/OSConfig?Message", OscfgElementTypes.Message_3013); //$NON-NLS-1$
		case HWCounterEditPart.VISUAL_ID:
			return getImage(
					"Navigator?Node?http://www.jennic.com/OSConfig?HWCounter", OscfgElementTypes.HWCounter_3014); //$NON-NLS-1$
		case CallbackFunctionEditPart.VISUAL_ID:
			return getImage(
					"Navigator?Node?http://www.jennic.com/OSConfig?CallbackFunction", OscfgElementTypes.CallbackFunction_3015); //$NON-NLS-1$
		case InterruptSourceEditPart.VISUAL_ID:
			return getImage(
					"Navigator?Node?http://www.jennic.com/OSConfig?InterruptSource", OscfgElementTypes.InterruptSource_3016); //$NON-NLS-1$
		case CooperativeGroupEditPart.VISUAL_ID:
			return getImage(
					"Navigator?Node?http://www.jennic.com/OSConfig?CooperativeGroup", OscfgElementTypes.CooperativeGroup_3017); //$NON-NLS-1$
		case Task2EditPart.VISUAL_ID:
			return getImage(
					"Navigator?Node?http://www.jennic.com/OSConfig?Task", OscfgElementTypes.Task_3020); //$NON-NLS-1$
		case BaseTaskCollectMessageEditPart.VISUAL_ID:
			return getImage(
					"Navigator?Link?http://www.jennic.com/OSConfig?BaseTask?CollectMessage", OscfgElementTypes.BaseTaskCollectMessage_4001); //$NON-NLS-1$
		case BaseTaskEnterExitMutexEditPart.VISUAL_ID:
			return getImage(
					"Navigator?Link?http://www.jennic.com/OSConfig?BaseTask?EnterExitMutex", OscfgElementTypes.BaseTaskEnterExitMutex_4003); //$NON-NLS-1$
		case SWTimerActivatesEditPart.VISUAL_ID:
			return getImage(
					"Navigator?Link?http://www.jennic.com/OSConfig?SWTimer?Activates", OscfgElementTypes.SWTimerActivates_4004); //$NON-NLS-1$
		case SWTimerTimer_callbackEditPart.VISUAL_ID:
			return getImage(
					"Navigator?Link?http://www.jennic.com/OSConfig?SWTimer?timer_callback", OscfgElementTypes.SWTimerTimer_callback_4005); //$NON-NLS-1$
		case MessageNotifiesEditPart.VISUAL_ID:
			return getImage(
					"Navigator?Link?http://www.jennic.com/OSConfig?Message?Notifies", OscfgElementTypes.MessageNotifies_4006); //$NON-NLS-1$
		case HWCounterEnable_callbackEditPart.VISUAL_ID:
			return getImage(
					"Navigator?Link?http://www.jennic.com/OSConfig?HWCounter?enable_callback", OscfgElementTypes.HWCounterEnable_callback_4007); //$NON-NLS-1$
		case HWCounterDisable_callbackEditPart.VISUAL_ID:
			return getImage(
					"Navigator?Link?http://www.jennic.com/OSConfig?HWCounter?disable_callback", OscfgElementTypes.HWCounterDisable_callback_4008); //$NON-NLS-1$
		case HWCounterGet_callbackEditPart.VISUAL_ID:
			return getImage(
					"Navigator?Link?http://www.jennic.com/OSConfig?HWCounter?get_callback", OscfgElementTypes.HWCounterGet_callback_4009); //$NON-NLS-1$
		case HWCounterSet_callbackEditPart.VISUAL_ID:
			return getImage(
					"Navigator?Link?http://www.jennic.com/OSConfig?HWCounter?set_callback", OscfgElementTypes.HWCounterSet_callback_4010); //$NON-NLS-1$
		case InterruptSourceSourceISREditPart.VISUAL_ID:
			return getImage(
					"Navigator?Link?http://www.jennic.com/OSConfig?InterruptSource?SourceISR", OscfgElementTypes.InterruptSourceSourceISR_4011); //$NON-NLS-1$
		case PosterPostMessageEditPart.VISUAL_ID:
			return getImage(
					"Navigator?Link?http://www.jennic.com/OSConfig?Poster?PostMessage", OscfgElementTypes.PosterPostMessage_4012); //$NON-NLS-1$
		}
		return getImage("Navigator?UnknownElement", null); //$NON-NLS-1$
	}

	/**
	 * @generated
	 */
	private Image getImage(String key, IElementType elementType) {
		ImageRegistry imageRegistry = OscfgDiagramEditorPlugin.getInstance()
				.getImageRegistry();
		Image image = imageRegistry.get(key);
		if (image == null && elementType != null
				&& OscfgElementTypes.isKnownElementType(elementType)) {
			image = OscfgElementTypes.getImage(elementType);
			imageRegistry.put(key, image);
		}

		if (image == null) {
			image = imageRegistry.get("Navigator?ImageNotFound"); //$NON-NLS-1$
			imageRegistry.put(key, image);
		}
		return image;
	}

	/**
	 * @generated
	 */
	public String getText(Object element) {
		if (element instanceof OscfgNavigatorGroup) {
			OscfgNavigatorGroup group = (OscfgNavigatorGroup) element;
			return group.getGroupName();
		}

		if (element instanceof OscfgNavigatorItem) {
			OscfgNavigatorItem navigatorItem = (OscfgNavigatorItem) element;
			if (!isOwnView(navigatorItem.getView())) {
				return null;
			}
			return getText(navigatorItem.getView());
		}

		return super.getText(element);
	}

	/**
	 * @generated
	 */
	public String getText(View view) {
		if (view.getElement() != null && view.getElement().eIsProxy()) {
			return getUnresolvedDomainElementProxyText(view);
		}
		switch (OscfgVisualIDRegistry.getVisualID(view)) {
		case ConfigurationEditPart.VISUAL_ID:
			return getConfiguration_1000Text(view);
		case OSEditPart.VISUAL_ID:
			return getOS_2001Text(view);
		case SWTimerEditPart.VISUAL_ID:
			return getSWTimer_3006Text(view);
		case ModuleEditPart.VISUAL_ID:
			return getModule_3009Text(view);
		case TaskEditPart.VISUAL_ID:
			return getTask_3010Text(view);
		case ISREditPart.VISUAL_ID:
			return getISR_3011Text(view);
		case MutexEditPart.VISUAL_ID:
			return getMutex_3012Text(view);
		case MessageEditPart.VISUAL_ID:
			return getMessage_3013Text(view);
		case HWCounterEditPart.VISUAL_ID:
			return getHWCounter_3014Text(view);
		case CallbackFunctionEditPart.VISUAL_ID:
			return getCallbackFunction_3015Text(view);
		case InterruptSourceEditPart.VISUAL_ID:
			return getInterruptSource_3016Text(view);
		case CooperativeGroupEditPart.VISUAL_ID:
			return getCooperativeGroup_3017Text(view);
		case Task2EditPart.VISUAL_ID:
			return getTask_3020Text(view);
		case BaseTaskCollectMessageEditPart.VISUAL_ID:
			return getBaseTaskCollectMessage_4001Text(view);
		case BaseTaskEnterExitMutexEditPart.VISUAL_ID:
			return getBaseTaskEnterExitMutex_4003Text(view);
		case SWTimerActivatesEditPart.VISUAL_ID:
			return getSWTimerActivates_4004Text(view);
		case SWTimerTimer_callbackEditPart.VISUAL_ID:
			return getSWTimerTimer_callback_4005Text(view);
		case MessageNotifiesEditPart.VISUAL_ID:
			return getMessageNotifies_4006Text(view);
		case HWCounterEnable_callbackEditPart.VISUAL_ID:
			return getHWCounterEnable_callback_4007Text(view);
		case HWCounterDisable_callbackEditPart.VISUAL_ID:
			return getHWCounterDisable_callback_4008Text(view);
		case HWCounterGet_callbackEditPart.VISUAL_ID:
			return getHWCounterGet_callback_4009Text(view);
		case HWCounterSet_callbackEditPart.VISUAL_ID:
			return getHWCounterSet_callback_4010Text(view);
		case InterruptSourceSourceISREditPart.VISUAL_ID:
			return getInterruptSourceSourceISR_4011Text(view);
		case PosterPostMessageEditPart.VISUAL_ID:
			return getPosterPostMessage_4012Text(view);
		}
		return getUnknownElementText(view);
	}

	/**
	 * @generated
	 */
	private String getConfiguration_1000Text(View view) {
		Configuration domainModelElement = (Configuration) view.getElement();
		if (domainModelElement != null) {
			return String.valueOf(domainModelElement.getVersion());
		} else {
			OscfgDiagramEditorPlugin.getInstance().logError(
					"No domain element for view with visualID = " + 1000); //$NON-NLS-1$
			return ""; //$NON-NLS-1$
		}
	}

	/**
	 * @generated
	 */
	private String getOS_2001Text(View view) {
		IParser parser = OscfgParserProvider.getParser(
				OscfgElementTypes.OS_2001,
				view.getElement() != null ? view.getElement() : view,
				OscfgVisualIDRegistry.getType(OSTargetEditPart.VISUAL_ID));
		if (parser != null) {
			return parser.getPrintString(new EObjectAdapter(
					view.getElement() != null ? view.getElement() : view),
					ParserOptions.NONE.intValue());
		} else {
			OscfgDiagramEditorPlugin.getInstance().logError(
					"Parser was not found for label " + 5008); //$NON-NLS-1$
			return ""; //$NON-NLS-1$
		}
	}

	/**
	 * @generated
	 */
	private String getModule_3009Text(View view) {
		IParser parser = OscfgParserProvider.getParser(
				OscfgElementTypes.Module_3009,
				view.getElement() != null ? view.getElement() : view,
				OscfgVisualIDRegistry.getType(ModuleNameEditPart.VISUAL_ID));
		if (parser != null) {
			return parser.getPrintString(new EObjectAdapter(
					view.getElement() != null ? view.getElement() : view),
					ParserOptions.NONE.intValue());
		} else {
			OscfgDiagramEditorPlugin.getInstance().logError(
					"Parser was not found for label " + 5032); //$NON-NLS-1$
			return ""; //$NON-NLS-1$
		}
	}

	/**
	 * @generated
	 */
	private String getTask_3010Text(View view) {
		IParser parser = OscfgParserProvider.getParser(
				OscfgElementTypes.Task_3010,
				view.getElement() != null ? view.getElement() : view,
				OscfgVisualIDRegistry.getType(TaskNameEditPart.VISUAL_ID));
		if (parser != null) {
			return parser.getPrintString(new EObjectAdapter(
					view.getElement() != null ? view.getElement() : view),
					ParserOptions.NONE.intValue());
		} else {
			OscfgDiagramEditorPlugin.getInstance().logError(
					"Parser was not found for label " + 5018); //$NON-NLS-1$
			return ""; //$NON-NLS-1$
		}
	}

	/**
	 * @generated
	 */
	private String getISR_3011Text(View view) {
		IParser parser = OscfgParserProvider.getParser(
				OscfgElementTypes.ISR_3011,
				view.getElement() != null ? view.getElement() : view,
				OscfgVisualIDRegistry.getType(ISRNameEditPart.VISUAL_ID));
		if (parser != null) {
			return parser.getPrintString(new EObjectAdapter(
					view.getElement() != null ? view.getElement() : view),
					ParserOptions.NONE.intValue());
		} else {
			OscfgDiagramEditorPlugin.getInstance().logError(
					"Parser was not found for label " + 5022); //$NON-NLS-1$
			return ""; //$NON-NLS-1$
		}
	}

	/**
	 * @generated
	 */
	private String getMutex_3012Text(View view) {
		IParser parser = OscfgParserProvider.getParser(
				OscfgElementTypes.Mutex_3012,
				view.getElement() != null ? view.getElement() : view,
				OscfgVisualIDRegistry.getType(MutexNameEditPart.VISUAL_ID));
		if (parser != null) {
			return parser.getPrintString(new EObjectAdapter(
					view.getElement() != null ? view.getElement() : view),
					ParserOptions.NONE.intValue());
		} else {
			OscfgDiagramEditorPlugin.getInstance().logError(
					"Parser was not found for label " + 5025); //$NON-NLS-1$
			return ""; //$NON-NLS-1$
		}
	}

	/**
	 * @generated
	 */
	private String getMessage_3013Text(View view) {
		IParser parser = OscfgParserProvider.getParser(
				OscfgElementTypes.Message_3013,
				view.getElement() != null ? view.getElement() : view,
				OscfgVisualIDRegistry.getType(MessageNameEditPart.VISUAL_ID));
		if (parser != null) {
			return parser.getPrintString(new EObjectAdapter(
					view.getElement() != null ? view.getElement() : view),
					ParserOptions.NONE.intValue());
		} else {
			OscfgDiagramEditorPlugin.getInstance().logError(
					"Parser was not found for label " + 5026); //$NON-NLS-1$
			return ""; //$NON-NLS-1$
		}
	}

	/**
	 * @generated
	 */
	private String getHWCounter_3014Text(View view) {
		IParser parser = OscfgParserProvider.getParser(
				OscfgElementTypes.HWCounter_3014,
				view.getElement() != null ? view.getElement() : view,
				OscfgVisualIDRegistry.getType(HWCounterNameEditPart.VISUAL_ID));
		if (parser != null) {
			return parser.getPrintString(new EObjectAdapter(
					view.getElement() != null ? view.getElement() : view),
					ParserOptions.NONE.intValue());
		} else {
			OscfgDiagramEditorPlugin.getInstance().logError(
					"Parser was not found for label " + 5029); //$NON-NLS-1$
			return ""; //$NON-NLS-1$
		}
	}

	/**
	 * @generated
	 */
	private String getSWTimer_3006Text(View view) {
		IParser parser = OscfgParserProvider.getParser(
				OscfgElementTypes.SWTimer_3006,
				view.getElement() != null ? view.getElement() : view,
				OscfgVisualIDRegistry.getType(SWTimerNameEditPart.VISUAL_ID));
		if (parser != null) {
			return parser.getPrintString(new EObjectAdapter(
					view.getElement() != null ? view.getElement() : view),
					ParserOptions.NONE.intValue());
		} else {
			OscfgDiagramEditorPlugin.getInstance().logError(
					"Parser was not found for label " + 5005); //$NON-NLS-1$
			return ""; //$NON-NLS-1$
		}
	}

	/**
	 * @generated
	 */
	private String getCallbackFunction_3015Text(View view) {
		IParser parser = OscfgParserProvider.getParser(
				OscfgElementTypes.CallbackFunction_3015,
				view.getElement() != null ? view.getElement() : view,
				OscfgVisualIDRegistry
						.getType(CallbackFunctionNameEditPart.VISUAL_ID));
		if (parser != null) {
			return parser.getPrintString(new EObjectAdapter(
					view.getElement() != null ? view.getElement() : view),
					ParserOptions.NONE.intValue());
		} else {
			OscfgDiagramEditorPlugin.getInstance().logError(
					"Parser was not found for label " + 5030); //$NON-NLS-1$
			return ""; //$NON-NLS-1$
		}
	}

	/**
	 * @generated
	 */
	private String getInterruptSource_3016Text(View view) {
		IParser parser = OscfgParserProvider.getParser(
				OscfgElementTypes.InterruptSource_3016,
				view.getElement() != null ? view.getElement() : view,
				OscfgVisualIDRegistry
						.getType(InterruptSourceSourceEditPart.VISUAL_ID));
		if (parser != null) {
			return parser.getPrintString(new EObjectAdapter(
					view.getElement() != null ? view.getElement() : view),
					ParserOptions.NONE.intValue());
		} else {
			OscfgDiagramEditorPlugin.getInstance().logError(
					"Parser was not found for label " + 5031); //$NON-NLS-1$
			return ""; //$NON-NLS-1$
		}
	}

	/**
	 * @generated
	 */
	private String getCooperativeGroup_3017Text(View view) {
		IParser parser = OscfgParserProvider.getParser(
				OscfgElementTypes.CooperativeGroup_3017,
				view.getElement() != null ? view.getElement() : view,
				OscfgVisualIDRegistry
						.getType(CooperativeGroupNameEditPart.VISUAL_ID));
		if (parser != null) {
			return parser.getPrintString(new EObjectAdapter(
					view.getElement() != null ? view.getElement() : view),
					ParserOptions.NONE.intValue());
		} else {
			OscfgDiagramEditorPlugin.getInstance().logError(
					"Parser was not found for label " + 5036); //$NON-NLS-1$
			return ""; //$NON-NLS-1$
		}
	}

	/**
	 * @generated
	 */
	private String getTask_3020Text(View view) {
		IParser parser = OscfgParserProvider.getParser(
				OscfgElementTypes.Task_3020,
				view.getElement() != null ? view.getElement() : view,
				OscfgVisualIDRegistry.getType(TaskName2EditPart.VISUAL_ID));
		if (parser != null) {
			return parser.getPrintString(new EObjectAdapter(
					view.getElement() != null ? view.getElement() : view),
					ParserOptions.NONE.intValue());
		} else {
			OscfgDiagramEditorPlugin.getInstance().logError(
					"Parser was not found for label " + 5040); //$NON-NLS-1$
			return ""; //$NON-NLS-1$
		}
	}

	/**
	 * @generated
	 */
	private String getBaseTaskCollectMessage_4001Text(View view) {
		IParser parser = OscfgParserProvider.getParser(
				OscfgElementTypes.BaseTaskCollectMessage_4001,
				view.getElement() != null ? view.getElement() : view,
				OscfgVisualIDRegistry.getType(WrappingLabelEditPart.VISUAL_ID));
		if (parser != null) {
			return parser.getPrintString(new EObjectAdapter(
					view.getElement() != null ? view.getElement() : view),
					ParserOptions.NONE.intValue());
		} else {
			OscfgDiagramEditorPlugin.getInstance().logError(
					"Parser was not found for label " + 6002); //$NON-NLS-1$
			return ""; //$NON-NLS-1$
		}
	}

	/**
	 * @generated
	 */
	private String getPosterPostMessage_4012Text(View view) {
		IParser parser = OscfgParserProvider
				.getParser(OscfgElementTypes.PosterPostMessage_4012, view
						.getElement() != null ? view.getElement() : view,
						OscfgVisualIDRegistry
								.getType(WrappingLabel2EditPart.VISUAL_ID));
		if (parser != null) {
			return parser.getPrintString(new EObjectAdapter(
					view.getElement() != null ? view.getElement() : view),
					ParserOptions.NONE.intValue());
		} else {
			OscfgDiagramEditorPlugin.getInstance().logError(
					"Parser was not found for label " + 6012); //$NON-NLS-1$
			return ""; //$NON-NLS-1$
		}
	}

	/**
	 * @generated
	 */
	private String getBaseTaskEnterExitMutex_4003Text(View view) {
		IParser parser = OscfgParserProvider
				.getParser(OscfgElementTypes.BaseTaskEnterExitMutex_4003, view
						.getElement() != null ? view.getElement() : view,
						OscfgVisualIDRegistry
								.getType(WrappingLabel3EditPart.VISUAL_ID));
		if (parser != null) {
			return parser.getPrintString(new EObjectAdapter(
					view.getElement() != null ? view.getElement() : view),
					ParserOptions.NONE.intValue());
		} else {
			OscfgDiagramEditorPlugin.getInstance().logError(
					"Parser was not found for label " + 6004); //$NON-NLS-1$
			return ""; //$NON-NLS-1$
		}
	}

	/**
	 * @generated
	 */
	private String getSWTimerActivates_4004Text(View view) {
		IParser parser = OscfgParserProvider
				.getParser(OscfgElementTypes.SWTimerActivates_4004, view
						.getElement() != null ? view.getElement() : view,
						OscfgVisualIDRegistry
								.getType(WrappingLabel4EditPart.VISUAL_ID));
		if (parser != null) {
			return parser.getPrintString(new EObjectAdapter(
					view.getElement() != null ? view.getElement() : view),
					ParserOptions.NONE.intValue());
		} else {
			OscfgDiagramEditorPlugin.getInstance().logError(
					"Parser was not found for label " + 6005); //$NON-NLS-1$
			return ""; //$NON-NLS-1$
		}
	}

	/**
	 * @generated
	 */
	private String getSWTimerTimer_callback_4005Text(View view) {
		IParser parser = OscfgParserProvider
				.getParser(OscfgElementTypes.SWTimerTimer_callback_4005, view
						.getElement() != null ? view.getElement() : view,
						OscfgVisualIDRegistry
								.getType(WrappingLabel5EditPart.VISUAL_ID));
		if (parser != null) {
			return parser.getPrintString(new EObjectAdapter(
					view.getElement() != null ? view.getElement() : view),
					ParserOptions.NONE.intValue());
		} else {
			OscfgDiagramEditorPlugin.getInstance().logError(
					"Parser was not found for label " + 6006); //$NON-NLS-1$
			return ""; //$NON-NLS-1$
		}
	}

	/**
	 * @generated
	 */
	private String getMessageNotifies_4006Text(View view) {
		IParser parser = OscfgParserProvider
				.getParser(OscfgElementTypes.MessageNotifies_4006, view
						.getElement() != null ? view.getElement() : view,
						OscfgVisualIDRegistry
								.getType(WrappingLabel6EditPart.VISUAL_ID));
		if (parser != null) {
			return parser.getPrintString(new EObjectAdapter(
					view.getElement() != null ? view.getElement() : view),
					ParserOptions.NONE.intValue());
		} else {
			OscfgDiagramEditorPlugin.getInstance().logError(
					"Parser was not found for label " + 6003); //$NON-NLS-1$
			return ""; //$NON-NLS-1$
		}
	}

	/**
	 * @generated
	 */
	private String getHWCounterEnable_callback_4007Text(View view) {
		IParser parser = OscfgParserProvider
				.getParser(OscfgElementTypes.HWCounterEnable_callback_4007,
						view.getElement() != null ? view.getElement() : view,
						OscfgVisualIDRegistry
								.getType(WrappingLabel7EditPart.VISUAL_ID));
		if (parser != null) {
			return parser.getPrintString(new EObjectAdapter(
					view.getElement() != null ? view.getElement() : view),
					ParserOptions.NONE.intValue());
		} else {
			OscfgDiagramEditorPlugin.getInstance().logError(
					"Parser was not found for label " + 6007); //$NON-NLS-1$
			return ""; //$NON-NLS-1$
		}
	}

	/**
	 * @generated
	 */
	private String getHWCounterDisable_callback_4008Text(View view) {
		IParser parser = OscfgParserProvider
				.getParser(OscfgElementTypes.HWCounterDisable_callback_4008,
						view.getElement() != null ? view.getElement() : view,
						OscfgVisualIDRegistry
								.getType(WrappingLabel8EditPart.VISUAL_ID));
		if (parser != null) {
			return parser.getPrintString(new EObjectAdapter(
					view.getElement() != null ? view.getElement() : view),
					ParserOptions.NONE.intValue());
		} else {
			OscfgDiagramEditorPlugin.getInstance().logError(
					"Parser was not found for label " + 6008); //$NON-NLS-1$
			return ""; //$NON-NLS-1$
		}
	}

	/**
	 * @generated
	 */
	private String getHWCounterGet_callback_4009Text(View view) {
		IParser parser = OscfgParserProvider
				.getParser(OscfgElementTypes.HWCounterGet_callback_4009, view
						.getElement() != null ? view.getElement() : view,
						OscfgVisualIDRegistry
								.getType(WrappingLabel9EditPart.VISUAL_ID));
		if (parser != null) {
			return parser.getPrintString(new EObjectAdapter(
					view.getElement() != null ? view.getElement() : view),
					ParserOptions.NONE.intValue());
		} else {
			OscfgDiagramEditorPlugin.getInstance().logError(
					"Parser was not found for label " + 6009); //$NON-NLS-1$
			return ""; //$NON-NLS-1$
		}
	}

	/**
	 * @generated
	 */
	private String getHWCounterSet_callback_4010Text(View view) {
		IParser parser = OscfgParserProvider.getParser(
				OscfgElementTypes.HWCounterSet_callback_4010,
				view.getElement() != null ? view.getElement() : view,
				OscfgVisualIDRegistry
						.getType(WrappingLabel10EditPart.VISUAL_ID));
		if (parser != null) {
			return parser.getPrintString(new EObjectAdapter(
					view.getElement() != null ? view.getElement() : view),
					ParserOptions.NONE.intValue());
		} else {
			OscfgDiagramEditorPlugin.getInstance().logError(
					"Parser was not found for label " + 6010); //$NON-NLS-1$
			return ""; //$NON-NLS-1$
		}
	}

	/**
	 * @generated
	 */
	private String getInterruptSourceSourceISR_4011Text(View view) {
		IParser parser = OscfgParserProvider.getParser(
				OscfgElementTypes.InterruptSourceSourceISR_4011, view
						.getElement() != null ? view.getElement() : view,
				OscfgVisualIDRegistry
						.getType(WrappingLabel11EditPart.VISUAL_ID));
		if (parser != null) {
			return parser.getPrintString(new EObjectAdapter(
					view.getElement() != null ? view.getElement() : view),
					ParserOptions.NONE.intValue());
		} else {
			OscfgDiagramEditorPlugin.getInstance().logError(
					"Parser was not found for label " + 6011); //$NON-NLS-1$
			return ""; //$NON-NLS-1$
		}
	}

	/**
	 * @generated
	 */
	private String getUnknownElementText(View view) {
		return "<UnknownElement Visual_ID = " + view.getType() + ">"; //$NON-NLS-1$  //$NON-NLS-2$
	}

	/**
	 * @generated
	 */
	private String getUnresolvedDomainElementProxyText(View view) {
		return "<Unresolved domain element Visual_ID = " + view.getType() + ">"; //$NON-NLS-1$  //$NON-NLS-2$
	}

	/**
	 * @generated
	 */
	public void init(ICommonContentExtensionSite aConfig) {
	}

	/**
	 * @generated
	 */
	public void restoreState(IMemento aMemento) {
	}

	/**
	 * @generated
	 */
	public void saveState(IMemento aMemento) {
	}

	/**
	 * @generated
	 */
	public String getDescription(Object anElement) {
		return null;
	}

	/**
	 * @generated
	 */
	private boolean isOwnView(View view) {
		return ConfigurationEditPart.MODEL_ID.equals(OscfgVisualIDRegistry
				.getModelID(view));
	}

}
