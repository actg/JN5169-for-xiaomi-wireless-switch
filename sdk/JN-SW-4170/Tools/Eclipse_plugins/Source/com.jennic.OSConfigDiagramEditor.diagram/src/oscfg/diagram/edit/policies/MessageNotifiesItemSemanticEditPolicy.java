package oscfg.diagram.edit.policies;

import org.eclipse.gef.commands.Command;
import org.eclipse.gmf.runtime.emf.type.core.commands.DestroyReferenceCommand;
import org.eclipse.gmf.runtime.emf.type.core.requests.DestroyReferenceRequest;
import oscfg.diagram.providers.OscfgElementTypes;

/**
 * @generated
 */
public class MessageNotifiesItemSemanticEditPolicy extends
		OscfgBaseItemSemanticEditPolicy {

	/**
	 * @generated
	 */
	public MessageNotifiesItemSemanticEditPolicy() {
		super(OscfgElementTypes.MessageNotifies_4006);
	}

	/**
	 * @generated
	 */
	protected Command getDestroyReferenceCommand(DestroyReferenceRequest req) {
		return getGEFWrapper(new DestroyReferenceCommand(req));
	}

}
