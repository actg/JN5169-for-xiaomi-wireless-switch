package oscfg.diagram.edit.policies;

import org.eclipse.gef.commands.Command;
import org.eclipse.gmf.runtime.emf.type.core.commands.DestroyReferenceCommand;
import org.eclipse.gmf.runtime.emf.type.core.requests.DestroyReferenceRequest;
import oscfg.diagram.providers.OscfgElementTypes;

/**
 * @generated
 */
public class HWCounterEnable_callbackItemSemanticEditPolicy extends
		OscfgBaseItemSemanticEditPolicy {

	/**
	 * @generated
	 */
	public HWCounterEnable_callbackItemSemanticEditPolicy() {
		super(OscfgElementTypes.HWCounterEnable_callback_4007);
	}

	/**
	 * @generated
	 */
	protected Command getDestroyReferenceCommand(DestroyReferenceRequest req) {
		return getGEFWrapper(new DestroyReferenceCommand(req));
	}

}
