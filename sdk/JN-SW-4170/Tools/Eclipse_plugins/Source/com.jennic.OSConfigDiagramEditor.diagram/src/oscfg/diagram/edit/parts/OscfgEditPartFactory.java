package oscfg.diagram.edit.parts;

import org.eclipse.draw2d.FigureUtilities;
import org.eclipse.draw2d.Label;
import org.eclipse.draw2d.geometry.Dimension;
import org.eclipse.draw2d.geometry.Rectangle;
import org.eclipse.gef.EditPart;
import org.eclipse.gef.EditPartFactory;
import org.eclipse.gef.tools.CellEditorLocator;
import org.eclipse.gmf.runtime.diagram.ui.editparts.ITextAwareEditPart;
import org.eclipse.gmf.runtime.draw2d.ui.figures.WrappingLabel;
import org.eclipse.gmf.runtime.notation.View;
import org.eclipse.gmf.tooling.runtime.directedit.locator.CellEditorLocatorAccess;
import org.eclipse.jface.viewers.CellEditor;
import org.eclipse.swt.SWT;
import org.eclipse.swt.widgets.Text;

import oscfg.diagram.part.OscfgVisualIDRegistry;

/**
 * @generated
 */
public class OscfgEditPartFactory implements EditPartFactory {

	/**
	 * @generated
	 */
	public EditPart createEditPart(EditPart context, Object model) {
		if (model instanceof View) {
			View view = (View) model;
			switch (OscfgVisualIDRegistry.getVisualID(view)) {

			case ConfigurationEditPart.VISUAL_ID:
				return new ConfigurationEditPart(view);

			case OSEditPart.VISUAL_ID:
				return new OSEditPart(view);

			case OSTargetEditPart.VISUAL_ID:
				return new OSTargetEditPart(view);

			case ModuleEditPart.VISUAL_ID:
				return new ModuleEditPart(view);

			case ModuleNameEditPart.VISUAL_ID:
				return new ModuleNameEditPart(view);

			case TaskEditPart.VISUAL_ID:
				return new TaskEditPart(view);

			case TaskNameEditPart.VISUAL_ID:
				return new TaskNameEditPart(view);

			case TaskPriorityEditPart.VISUAL_ID:
				return new TaskPriorityEditPart(view);

			case TaskAutostartedEditPart.VISUAL_ID:
				return new TaskAutostartedEditPart(view);

			case ISREditPart.VISUAL_ID:
				return new ISREditPart(view);

			case ISRNameEditPart.VISUAL_ID:
				return new ISRNameEditPart(view);

			case ISRTypeEditPart.VISUAL_ID:
				return new ISRTypeEditPart(view);

			case ISRIPLEditPart.VISUAL_ID:
				return new ISRIPLEditPart(view);

			case MutexEditPart.VISUAL_ID:
				return new MutexEditPart(view);

			case MutexNameEditPart.VISUAL_ID:
				return new MutexNameEditPart(view);

			case MessageEditPart.VISUAL_ID:
				return new MessageEditPart(view);

			case MessageNameEditPart.VISUAL_ID:
				return new MessageNameEditPart(view);

			case MessageCtypeEditPart.VISUAL_ID:
				return new MessageCtypeEditPart(view);

			case MessageQueueEditPart.VISUAL_ID:
				return new MessageQueueEditPart(view);

			case HWCounterEditPart.VISUAL_ID:
				return new HWCounterEditPart(view);

			case HWCounterNameEditPart.VISUAL_ID:
				return new HWCounterNameEditPart(view);

			case SWTimerEditPart.VISUAL_ID:
				return new SWTimerEditPart(view);

			case SWTimerNameEditPart.VISUAL_ID:
				return new SWTimerNameEditPart(view);

			case CallbackFunctionEditPart.VISUAL_ID:
				return new CallbackFunctionEditPart(view);

			case CallbackFunctionNameEditPart.VISUAL_ID:
				return new CallbackFunctionNameEditPart(view);

			case InterruptSourceEditPart.VISUAL_ID:
				return new InterruptSourceEditPart(view);

			case InterruptSourceSourceEditPart.VISUAL_ID:
				return new InterruptSourceSourceEditPart(view);

			case CooperativeGroupEditPart.VISUAL_ID:
				return new CooperativeGroupEditPart(view);

			case CooperativeGroupNameEditPart.VISUAL_ID:
				return new CooperativeGroupNameEditPart(view);

			case Task2EditPart.VISUAL_ID:
				return new Task2EditPart(view);

			case TaskName2EditPart.VISUAL_ID:
				return new TaskName2EditPart(view);

			case TaskPriority2EditPart.VISUAL_ID:
				return new TaskPriority2EditPart(view);

			case TaskAutostarted2EditPart.VISUAL_ID:
				return new TaskAutostarted2EditPart(view);

			case OSOSModulesEditPart.VISUAL_ID:
				return new OSOSModulesEditPart(view);

			case ModuleModuleObjectsEditPart.VISUAL_ID:
				return new ModuleModuleObjectsEditPart(view);

			case HWCounterSoftwareTimersEditPart.VISUAL_ID:
				return new HWCounterSoftwareTimersEditPart(view);

			case CooperativeGroupCooperativeTasksEditPart.VISUAL_ID:
				return new CooperativeGroupCooperativeTasksEditPart(view);

			case BaseTaskCollectMessageEditPart.VISUAL_ID:
				return new BaseTaskCollectMessageEditPart(view);

			case WrappingLabelEditPart.VISUAL_ID:
				return new WrappingLabelEditPart(view);

			case PosterPostMessageEditPart.VISUAL_ID:
				return new PosterPostMessageEditPart(view);

			case WrappingLabel2EditPart.VISUAL_ID:
				return new WrappingLabel2EditPart(view);

			case BaseTaskEnterExitMutexEditPart.VISUAL_ID:
				return new BaseTaskEnterExitMutexEditPart(view);

			case WrappingLabel3EditPart.VISUAL_ID:
				return new WrappingLabel3EditPart(view);

			case SWTimerActivatesEditPart.VISUAL_ID:
				return new SWTimerActivatesEditPart(view);

			case WrappingLabel4EditPart.VISUAL_ID:
				return new WrappingLabel4EditPart(view);

			case SWTimerTimer_callbackEditPart.VISUAL_ID:
				return new SWTimerTimer_callbackEditPart(view);

			case WrappingLabel5EditPart.VISUAL_ID:
				return new WrappingLabel5EditPart(view);

			case MessageNotifiesEditPart.VISUAL_ID:
				return new MessageNotifiesEditPart(view);

			case WrappingLabel6EditPart.VISUAL_ID:
				return new WrappingLabel6EditPart(view);

			case HWCounterEnable_callbackEditPart.VISUAL_ID:
				return new HWCounterEnable_callbackEditPart(view);

			case WrappingLabel7EditPart.VISUAL_ID:
				return new WrappingLabel7EditPart(view);

			case HWCounterDisable_callbackEditPart.VISUAL_ID:
				return new HWCounterDisable_callbackEditPart(view);

			case WrappingLabel8EditPart.VISUAL_ID:
				return new WrappingLabel8EditPart(view);

			case HWCounterGet_callbackEditPart.VISUAL_ID:
				return new HWCounterGet_callbackEditPart(view);

			case WrappingLabel9EditPart.VISUAL_ID:
				return new WrappingLabel9EditPart(view);

			case HWCounterSet_callbackEditPart.VISUAL_ID:
				return new HWCounterSet_callbackEditPart(view);

			case WrappingLabel10EditPart.VISUAL_ID:
				return new WrappingLabel10EditPart(view);

			case InterruptSourceSourceISREditPart.VISUAL_ID:
				return new InterruptSourceSourceISREditPart(view);

			case WrappingLabel11EditPart.VISUAL_ID:
				return new WrappingLabel11EditPart(view);

			}
		}
		return createUnrecognizedEditPart(context, model);
	}

	/**
	 * @generated
	 */
	private EditPart createUnrecognizedEditPart(EditPart context, Object model) {
		// Handle creation of unrecognized child node EditParts here
		return null;
	}

	/**
	 * @generated
	 */
	public static CellEditorLocator getTextCellEditorLocator(
			ITextAwareEditPart source) {
		return CellEditorLocatorAccess.INSTANCE
				.getTextCellEditorLocator(source);
	}
}
