package oscfg.diagram.edit.policies;

import org.eclipse.gef.commands.Command;
import org.eclipse.gmf.runtime.emf.type.core.requests.CreateElementRequest;

import oscfg.OscfgPackage;
import oscfg.diagram.edit.commands.CallbackFunctionCreateCommand;
import oscfg.diagram.edit.commands.CooperativeGroupCreateCommand;
import oscfg.diagram.edit.commands.HWCounterCreateCommand;
import oscfg.diagram.edit.commands.ISRCreateCommand;
import oscfg.diagram.edit.commands.InterruptSourceCreateCommand;
import oscfg.diagram.edit.commands.MessageCreateCommand;
import oscfg.diagram.edit.commands.MutexCreateCommand;
import oscfg.diagram.edit.commands.TaskCreateCommand;
import oscfg.diagram.providers.OscfgElementTypes;

/**
 * @generated
 */
public class ModuleModuleObjectsItemSemanticEditPolicy extends
		OscfgBaseItemSemanticEditPolicy {

	/**
	 * @generated
	 */
	public ModuleModuleObjectsItemSemanticEditPolicy() {
		super(OscfgElementTypes.Module_3009);
	}

	/**
	 * @generated
	 */
	protected Command getCreateCommand(CreateElementRequest req) {
		if (OscfgElementTypes.Task_3010 == req.getElementType()) {
			return getGEFWrapper(new TaskCreateCommand(req));
		}
		if (OscfgElementTypes.ISR_3011 == req.getElementType()) {
			return getGEFWrapper(new ISRCreateCommand(req));
		}
		if (OscfgElementTypes.Mutex_3012 == req.getElementType()) {
			return getGEFWrapper(new MutexCreateCommand(req));
		}
		if (OscfgElementTypes.Message_3013 == req.getElementType()) {
			return getGEFWrapper(new MessageCreateCommand(req));
		}
		if (OscfgElementTypes.HWCounter_3014 == req.getElementType()) {
			return getGEFWrapper(new HWCounterCreateCommand(req));
		}
		if (OscfgElementTypes.CallbackFunction_3015 == req.getElementType()) {
			return getGEFWrapper(new CallbackFunctionCreateCommand(req));
		}
		if (OscfgElementTypes.InterruptSource_3016 == req.getElementType()) {
			return getGEFWrapper(new InterruptSourceCreateCommand(req));
		}
		if (OscfgElementTypes.CooperativeGroup_3017 == req.getElementType()) {
			return getGEFWrapper(new CooperativeGroupCreateCommand(req));
		}
		return super.getCreateCommand(req);
	}

}
