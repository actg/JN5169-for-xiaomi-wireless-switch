package oscfg.diagram.edit.policies;

import org.eclipse.gef.commands.Command;
import org.eclipse.gmf.runtime.emf.type.core.requests.CreateElementRequest;

import oscfg.OscfgPackage;
import oscfg.diagram.edit.commands.SWTimerCreateCommand;
import oscfg.diagram.providers.OscfgElementTypes;

/**
 * @generated
 */
public class HWCounterSoftwareTimersItemSemanticEditPolicy extends
		OscfgBaseItemSemanticEditPolicy {

	/**
	 * @generated
	 */
	public HWCounterSoftwareTimersItemSemanticEditPolicy() {
		super(OscfgElementTypes.HWCounter_3014);
	}

	/**
	 * @generated
	 */
	protected Command getCreateCommand(CreateElementRequest req) {
		if (OscfgElementTypes.SWTimer_3006 == req.getElementType()) {
			return getGEFWrapper(new SWTimerCreateCommand(req));
		}
		return super.getCreateCommand(req);
	}

}
