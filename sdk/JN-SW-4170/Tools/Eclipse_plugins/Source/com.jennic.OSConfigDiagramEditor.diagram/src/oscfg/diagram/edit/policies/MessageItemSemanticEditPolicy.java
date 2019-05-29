package oscfg.diagram.edit.policies;

import java.util.Iterator;
import org.eclipse.emf.ecore.EAnnotation;
import org.eclipse.gef.commands.Command;
import org.eclipse.gef.commands.CompoundCommand;
import org.eclipse.gmf.runtime.diagram.core.commands.DeleteCommand;
import org.eclipse.gmf.runtime.emf.commands.core.command.CompositeTransactionalCommand;
import org.eclipse.gmf.runtime.emf.type.core.commands.DestroyElementCommand;
import org.eclipse.gmf.runtime.emf.type.core.commands.DestroyReferenceCommand;
import org.eclipse.gmf.runtime.emf.type.core.requests.CreateRelationshipRequest;
import org.eclipse.gmf.runtime.emf.type.core.requests.DestroyElementRequest;
import org.eclipse.gmf.runtime.emf.type.core.requests.DestroyReferenceRequest;
import org.eclipse.gmf.runtime.emf.type.core.requests.ReorientReferenceRelationshipRequest;

import org.eclipse.gmf.runtime.notation.Edge;
import org.eclipse.gmf.runtime.notation.View;
import oscfg.diagram.edit.commands.BaseTaskCollectMessageCreateCommand;
import oscfg.diagram.edit.commands.BaseTaskCollectMessageReorientCommand;
import oscfg.diagram.edit.commands.MessageNotifiesCreateCommand;
import oscfg.diagram.edit.commands.MessageNotifiesReorientCommand;
import oscfg.diagram.edit.commands.PosterPostMessageCreateCommand;
import oscfg.diagram.edit.commands.PosterPostMessageReorientCommand;
import oscfg.diagram.edit.parts.BaseTaskCollectMessageEditPart;
import oscfg.diagram.edit.parts.MessageNotifiesEditPart;
import oscfg.diagram.edit.parts.PosterPostMessageEditPart;
import oscfg.diagram.part.OscfgVisualIDRegistry;
import oscfg.diagram.providers.OscfgElementTypes;

/**
 * @generated
 */
public class MessageItemSemanticEditPolicy extends
		OscfgBaseItemSemanticEditPolicy {

	/**
	 * @generated
	 */
	public MessageItemSemanticEditPolicy() {
		super(OscfgElementTypes.Message_3013);
	}

	/**
	 * @generated
	 */
	protected Command getDestroyElementCommand(DestroyElementRequest req) {
		View view = (View) getHost().getModel();
		CompositeTransactionalCommand cmd = new CompositeTransactionalCommand(
				getEditingDomain(), null);
		cmd.setTransactionNestingEnabled(false);
		for (Iterator<?> it = view.getTargetEdges().iterator(); it.hasNext();) {
			Edge incomingLink = (Edge) it.next();
			if (OscfgVisualIDRegistry.getVisualID(incomingLink) == BaseTaskCollectMessageEditPart.VISUAL_ID) {
				DestroyReferenceRequest r = new DestroyReferenceRequest(
						incomingLink.getSource().getElement(), null,
						incomingLink.getTarget().getElement(), false);
				cmd.add(new DestroyReferenceCommand(r));
				cmd.add(new DeleteCommand(getEditingDomain(), incomingLink));
				continue;
			}
			if (OscfgVisualIDRegistry.getVisualID(incomingLink) == PosterPostMessageEditPart.VISUAL_ID) {
				DestroyReferenceRequest r = new DestroyReferenceRequest(
						incomingLink.getSource().getElement(), null,
						incomingLink.getTarget().getElement(), false);
				cmd.add(new DestroyReferenceCommand(r));
				cmd.add(new DeleteCommand(getEditingDomain(), incomingLink));
				continue;
			}
		}
		for (Iterator<?> it = view.getSourceEdges().iterator(); it.hasNext();) {
			Edge outgoingLink = (Edge) it.next();
			if (OscfgVisualIDRegistry.getVisualID(outgoingLink) == MessageNotifiesEditPart.VISUAL_ID) {
				DestroyReferenceRequest r = new DestroyReferenceRequest(
						outgoingLink.getSource().getElement(), null,
						outgoingLink.getTarget().getElement(), false);
				cmd.add(new DestroyReferenceCommand(r));
				cmd.add(new DeleteCommand(getEditingDomain(), outgoingLink));
				continue;
			}
		}
		EAnnotation annotation = view.getEAnnotation("Shortcut"); //$NON-NLS-1$
		if (annotation == null) {
			// there are indirectly referenced children, need extra commands: false
			addDestroyShortcutsCommand(cmd, view);
			// delete host element
			cmd.add(new DestroyElementCommand(req));
		} else {
			cmd.add(new DeleteCommand(getEditingDomain(), view));
		}
		return getGEFWrapper(cmd.reduce());
	}

	/**
	 * @generated
	 */
	protected Command getCreateRelationshipCommand(CreateRelationshipRequest req) {
		Command command = req.getTarget() == null ? getStartCreateRelationshipCommand(req)
				: getCompleteCreateRelationshipCommand(req);
		return command != null ? command : super
				.getCreateRelationshipCommand(req);
	}

	/**
	 * @generated
	 */
	protected Command getStartCreateRelationshipCommand(
			CreateRelationshipRequest req) {
		if (OscfgElementTypes.BaseTaskCollectMessage_4001 == req
				.getElementType()) {
			return null;
		}
		if (OscfgElementTypes.PosterPostMessage_4012 == req.getElementType()) {
			return null;
		}
		if (OscfgElementTypes.MessageNotifies_4006 == req.getElementType()) {
			return getGEFWrapper(new MessageNotifiesCreateCommand(req,
					req.getSource(), req.getTarget()));
		}
		return null;
	}

	/**
	 * @generated
	 */
	protected Command getCompleteCreateRelationshipCommand(
			CreateRelationshipRequest req) {
		if (OscfgElementTypes.BaseTaskCollectMessage_4001 == req
				.getElementType()) {
			return getGEFWrapper(new BaseTaskCollectMessageCreateCommand(req,
					req.getSource(), req.getTarget()));
		}
		if (OscfgElementTypes.PosterPostMessage_4012 == req.getElementType()) {
			return getGEFWrapper(new PosterPostMessageCreateCommand(req,
					req.getSource(), req.getTarget()));
		}
		if (OscfgElementTypes.MessageNotifies_4006 == req.getElementType()) {
			return null;
		}
		return null;
	}

	/**
	 * Returns command to reorient EReference based link. New link target or source
	 * should be the domain model element associated with this node.
	 * 
	 * @generated
	 */
	protected Command getReorientReferenceRelationshipCommand(
			ReorientReferenceRelationshipRequest req) {
		switch (getVisualID(req)) {
		case BaseTaskCollectMessageEditPart.VISUAL_ID:
			return getGEFWrapper(new BaseTaskCollectMessageReorientCommand(req));
		case PosterPostMessageEditPart.VISUAL_ID:
			return getGEFWrapper(new PosterPostMessageReorientCommand(req));
		case MessageNotifiesEditPart.VISUAL_ID:
			return getGEFWrapper(new MessageNotifiesReorientCommand(req));
		}
		return super.getReorientReferenceRelationshipCommand(req);
	}

}
