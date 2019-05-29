package oscfg.diagram.edit.policies;

import org.eclipse.gef.commands.Command;
import org.eclipse.gmf.runtime.emf.type.core.requests.CreateElementRequest;

import oscfg.OscfgPackage;
import oscfg.diagram.edit.commands.ModuleCreateCommand;
import oscfg.diagram.providers.OscfgElementTypes;

/**
 * @generated
 */
public class OSOSModulesItemSemanticEditPolicy extends
		OscfgBaseItemSemanticEditPolicy {

	/**
	 * @generated
	 */
	public OSOSModulesItemSemanticEditPolicy() {
		super(OscfgElementTypes.OS_2001);
	}

	/**
	 * @generated
	 */
	protected Command getCreateCommand(CreateElementRequest req) {
		if (OscfgElementTypes.Module_3009 == req.getElementType()) {
			return getGEFWrapper(new ModuleCreateCommand(req));
		}
		return super.getCreateCommand(req);
	}

}
