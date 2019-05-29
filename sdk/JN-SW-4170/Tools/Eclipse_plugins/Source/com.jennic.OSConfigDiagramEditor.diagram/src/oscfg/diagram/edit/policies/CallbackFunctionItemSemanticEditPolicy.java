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
import oscfg.diagram.edit.commands.HWCounterDisable_callbackCreateCommand;
import oscfg.diagram.edit.commands.HWCounterDisable_callbackReorientCommand;
import oscfg.diagram.edit.commands.HWCounterEnable_callbackCreateCommand;
import oscfg.diagram.edit.commands.HWCounterEnable_callbackReorientCommand;
import oscfg.diagram.edit.commands.HWCounterGet_callbackCreateCommand;
import oscfg.diagram.edit.commands.HWCounterGet_callbackReorientCommand;
import oscfg.diagram.edit.commands.HWCounterSet_callbackCreateCommand;
import oscfg.diagram.edit.commands.HWCounterSet_callbackReorientCommand;
import oscfg.diagram.edit.commands.PosterPostMessageCreateCommand;
import oscfg.diagram.edit.commands.PosterPostMessageReorientCommand;
import oscfg.diagram.edit.commands.SWTimerTimer_callbackCreateCommand;
import oscfg.diagram.edit.commands.SWTimerTimer_callbackReorientCommand;
import oscfg.diagram.edit.parts.HWCounterDisable_callbackEditPart;
import oscfg.diagram.edit.parts.HWCounterEnable_callbackEditPart;
import oscfg.diagram.edit.parts.HWCounterGet_callbackEditPart;
import oscfg.diagram.edit.parts.HWCounterSet_callbackEditPart;
import oscfg.diagram.edit.parts.PosterPostMessageEditPart;
import oscfg.diagram.edit.parts.SWTimerTimer_callbackEditPart;
import oscfg.diagram.part.OscfgVisualIDRegistry;
import oscfg.diagram.providers.OscfgElementTypes;

/**
 * @generated
 */
public class CallbackFunctionItemSemanticEditPolicy extends
		OscfgBaseItemSemanticEditPolicy {

	/**
	 * @generated
	 */
	public CallbackFunctionItemSemanticEditPolicy() {
		super(OscfgElementTypes.CallbackFunction_3015);
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
			if (OscfgVisualIDRegistry.getVisualID(incomingLink) == SWTimerTimer_callbackEditPart.VISUAL_ID) {
				DestroyReferenceRequest r = new DestroyReferenceRequest(
						incomingLink.getSource().getElement(), null,
						incomingLink.getTarget().getElement(), false);
				cmd.add(new DestroyReferenceCommand(r));
				cmd.add(new DeleteCommand(getEditingDomain(), incomingLink));
				continue;
			}
			if (OscfgVisualIDRegistry.getVisualID(incomingLink) == HWCounterEnable_callbackEditPart.VISUAL_ID) {
				DestroyReferenceRequest r = new DestroyReferenceRequest(
						incomingLink.getSource().getElement(), null,
						incomingLink.getTarget().getElement(), false);
				cmd.add(new DestroyReferenceCommand(r));
				cmd.add(new DeleteCommand(getEditingDomain(), incomingLink));
				continue;
			}
			if (OscfgVisualIDRegistry.getVisualID(incomingLink) == HWCounterDisable_callbackEditPart.VISUAL_ID) {
				DestroyReferenceRequest r = new DestroyReferenceRequest(
						incomingLink.getSource().getElement(), null,
						incomingLink.getTarget().getElement(), false);
				cmd.add(new DestroyReferenceCommand(r));
				cmd.add(new DeleteCommand(getEditingDomain(), incomingLink));
				continue;
			}
			if (OscfgVisualIDRegistry.getVisualID(incomingLink) == HWCounterGet_callbackEditPart.VISUAL_ID) {
				DestroyReferenceRequest r = new DestroyReferenceRequest(
						incomingLink.getSource().getElement(), null,
						incomingLink.getTarget().getElement(), false);
				cmd.add(new DestroyReferenceCommand(r));
				cmd.add(new DeleteCommand(getEditingDomain(), incomingLink));
				continue;
			}
			if (OscfgVisualIDRegistry.getVisualID(incomingLink) == HWCounterSet_callbackEditPart.VISUAL_ID) {
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
			if (OscfgVisualIDRegistry.getVisualID(outgoingLink) == PosterPostMessageEditPart.VISUAL_ID) {
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
		if (OscfgElementTypes.PosterPostMessage_4012 == req.getElementType()) {
			return getGEFWrapper(new PosterPostMessageCreateCommand(req,
					req.getSource(), req.getTarget()));
		}
		if (OscfgElementTypes.SWTimerTimer_callback_4005 == req
				.getElementType()) {
			return null;
		}
		if (OscfgElementTypes.HWCounterEnable_callback_4007 == req
				.getElementType()) {
			return null;
		}
		if (OscfgElementTypes.HWCounterDisable_callback_4008 == req
				.getElementType()) {
			return null;
		}
		if (OscfgElementTypes.HWCounterGet_callback_4009 == req
				.getElementType()) {
			return null;
		}
		if (OscfgElementTypes.HWCounterSet_callback_4010 == req
				.getElementType()) {
			return null;
		}
		return null;
	}

	/**
	 * @generated
	 */
	protected Command getCompleteCreateRelationshipCommand(
			CreateRelationshipRequest req) {
		if (OscfgElementTypes.PosterPostMessage_4012 == req.getElementType()) {
			return null;
		}
		if (OscfgElementTypes.SWTimerTimer_callback_4005 == req
				.getElementType()) {
			return getGEFWrapper(new SWTimerTimer_callbackCreateCommand(req,
					req.getSource(), req.getTarget()));
		}
		if (OscfgElementTypes.HWCounterEnable_callback_4007 == req
				.getElementType()) {
			return getGEFWrapper(new HWCounterEnable_callbackCreateCommand(req,
					req.getSource(), req.getTarget()));
		}
		if (OscfgElementTypes.HWCounterDisable_callback_4008 == req
				.getElementType()) {
			return getGEFWrapper(new HWCounterDisable_callbackCreateCommand(
					req, req.getSource(), req.getTarget()));
		}
		if (OscfgElementTypes.HWCounterGet_callback_4009 == req
				.getElementType()) {
			return getGEFWrapper(new HWCounterGet_callbackCreateCommand(req,
					req.getSource(), req.getTarget()));
		}
		if (OscfgElementTypes.HWCounterSet_callback_4010 == req
				.getElementType()) {
			return getGEFWrapper(new HWCounterSet_callbackCreateCommand(req,
					req.getSource(), req.getTarget()));
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
		case PosterPostMessageEditPart.VISUAL_ID:
			return getGEFWrapper(new PosterPostMessageReorientCommand(req));
		case SWTimerTimer_callbackEditPart.VISUAL_ID:
			return getGEFWrapper(new SWTimerTimer_callbackReorientCommand(req));
		case HWCounterEnable_callbackEditPart.VISUAL_ID:
			return getGEFWrapper(new HWCounterEnable_callbackReorientCommand(
					req));
		case HWCounterDisable_callbackEditPart.VISUAL_ID:
			return getGEFWrapper(new HWCounterDisable_callbackReorientCommand(
					req));
		case HWCounterGet_callbackEditPart.VISUAL_ID:
			return getGEFWrapper(new HWCounterGet_callbackReorientCommand(req));
		case HWCounterSet_callbackEditPart.VISUAL_ID:
			return getGEFWrapper(new HWCounterSet_callbackReorientCommand(req));
		}
		return super.getReorientReferenceRelationshipCommand(req);
	}

}
