package oscfg.diagram.edit.policies;

import org.eclipse.gef.commands.Command;
import org.eclipse.gmf.runtime.emf.type.core.requests.CreateElementRequest;

import oscfg.OscfgPackage;
import oscfg.diagram.edit.commands.Task2CreateCommand;
import oscfg.diagram.providers.OscfgElementTypes;

/**
 * @generated
 */
public class CooperativeGroupCooperativeTasksItemSemanticEditPolicy extends
		OscfgBaseItemSemanticEditPolicy {

	/**
	 * @generated
	 */
	public CooperativeGroupCooperativeTasksItemSemanticEditPolicy() {
		super(OscfgElementTypes.CooperativeGroup_3017);
	}

	/**
	 * @generated
	 */
	protected Command getCreateCommand(CreateElementRequest req) {
		if (OscfgElementTypes.Task_3020 == req.getElementType()) {
			return getGEFWrapper(new Task2CreateCommand(req));
		}
		return super.getCreateCommand(req);
	}

}
