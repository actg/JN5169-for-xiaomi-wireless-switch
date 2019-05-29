package oscfg.diagram.edit.parts;

import org.eclipse.draw2d.IFigure;
import org.eclipse.draw2d.ScrollPane;
import org.eclipse.gef.EditPart;
import org.eclipse.gef.Request;
import org.eclipse.gmf.runtime.diagram.core.edithelpers.CreateElementRequestAdapter;
import org.eclipse.gmf.runtime.diagram.ui.editparts.ShapeCompartmentEditPart;
import org.eclipse.gmf.runtime.diagram.ui.editpolicies.CreationEditPolicy;
import org.eclipse.gmf.runtime.diagram.ui.editpolicies.DragDropEditPolicy;
import org.eclipse.gmf.runtime.diagram.ui.editpolicies.EditPolicyRoles;
import org.eclipse.gmf.runtime.diagram.ui.figures.ResizableCompartmentFigure;
import org.eclipse.gmf.runtime.diagram.ui.requests.CreateUnspecifiedTypeConnectionRequest;
import org.eclipse.gmf.runtime.diagram.ui.requests.CreateViewAndElementRequest;
import org.eclipse.gmf.runtime.diagram.ui.requests.RequestConstants;
import org.eclipse.gmf.runtime.draw2d.ui.figures.ConstrainedToolbarLayout;
import org.eclipse.gmf.runtime.emf.type.core.IElementType;
import org.eclipse.gmf.runtime.notation.View;

import org.eclipse.gmf.tooling.runtime.edit.policies.reparent.CreationEditPolicyWithCustomReparent;
import oscfg.diagram.edit.policies.ModuleModuleObjectsCanonicalEditPolicy;
import oscfg.diagram.edit.policies.ModuleModuleObjectsItemSemanticEditPolicy;
import oscfg.diagram.part.Messages;
import oscfg.diagram.part.OscfgVisualIDRegistry;
import oscfg.diagram.providers.OscfgElementTypes;

/**
 * @generated
 */
public class ModuleModuleObjectsEditPart extends ShapeCompartmentEditPart {

	/**
	 * @generated
	 */
	public static final int VISUAL_ID = 7003;

	/**
	 * @generated
	 */
	public ModuleModuleObjectsEditPart(View view) {
		super(view);
	}

	/**
	 * @generated
	 */
	public String getCompartmentName() {
		return Messages.ModuleModuleObjectsEditPart_title;
	}

	/**
	 * @generated
	 */
	public IFigure createFigure() {
		ResizableCompartmentFigure result = (ResizableCompartmentFigure) super
				.createFigure();
		result.setTitleVisibility(false);
		return result;
	}

	/**
	 * @generated
	 */
	protected void createDefaultEditPolicies() {
		super.createDefaultEditPolicies();
		installEditPolicy(EditPolicyRoles.SEMANTIC_ROLE,
				new ModuleModuleObjectsItemSemanticEditPolicy());
		installEditPolicy(EditPolicyRoles.CREATION_ROLE,
				new CreationEditPolicyWithCustomReparent(
						OscfgVisualIDRegistry.TYPED_INSTANCE));
		installEditPolicy(EditPolicyRoles.DRAG_DROP_ROLE,
				new DragDropEditPolicy());
		installEditPolicy(EditPolicyRoles.CANONICAL_ROLE,
				new ModuleModuleObjectsCanonicalEditPolicy());
	}

	/**
	 * @generated
	 */
	protected void setRatio(Double ratio) {
		if (getFigure().getParent().getLayoutManager() instanceof ConstrainedToolbarLayout) {
			super.setRatio(ratio);
		}
	}

	/**
	 * @generated
	 */
	public EditPart getTargetEditPart(Request request) {
		if (request instanceof CreateViewAndElementRequest) {
			CreateElementRequestAdapter adapter = ((CreateViewAndElementRequest) request)
					.getViewAndElementDescriptor()
					.getCreateElementRequestAdapter();
			IElementType type = (IElementType) adapter
					.getAdapter(IElementType.class);
			if (type == OscfgElementTypes.Task_3010) {
				return this;
			}
			if (type == OscfgElementTypes.ISR_3011) {
				return this;
			}
			if (type == OscfgElementTypes.Mutex_3012) {
				return this;
			}
			if (type == OscfgElementTypes.Message_3013) {
				return this;
			}
			if (type == OscfgElementTypes.HWCounter_3014) {
				return this;
			}
			if (type == OscfgElementTypes.CallbackFunction_3015) {
				return this;
			}
			if (type == OscfgElementTypes.InterruptSource_3016) {
				return this;
			}
			if (type == OscfgElementTypes.CooperativeGroup_3017) {
				return this;
			}
			return getParent().getTargetEditPart(request);
		}
		if (request instanceof CreateUnspecifiedTypeConnectionRequest) {
			if (RequestConstants.REQ_CONNECTION_END.equals(request.getType())) {
				for (Object type : ((CreateUnspecifiedTypeConnectionRequest) request)
						.getElementTypes()) {
					if (type instanceof IElementType) {
						IElementType elementType = (IElementType) type;
						if (elementType
								.equals(OscfgElementTypes.BaseTaskCollectMessage_4001)
								|| elementType
										.equals(OscfgElementTypes.BaseTaskEnterExitMutex_4003)
								|| elementType
										.equals(OscfgElementTypes.SWTimerActivates_4004)
								|| elementType
										.equals(OscfgElementTypes.SWTimerTimer_callback_4005)
								|| elementType
										.equals(OscfgElementTypes.MessageNotifies_4006)
								|| elementType
										.equals(OscfgElementTypes.HWCounterEnable_callback_4007)
								|| elementType
										.equals(OscfgElementTypes.HWCounterDisable_callback_4008)
								|| elementType
										.equals(OscfgElementTypes.HWCounterGet_callback_4009)
								|| elementType
										.equals(OscfgElementTypes.HWCounterSet_callback_4010)
								|| elementType
										.equals(OscfgElementTypes.InterruptSourceSourceISR_4011)
								|| elementType
										.equals(OscfgElementTypes.PosterPostMessage_4012))
							return super.getTargetEditPart(request);
					}
				}
			}
			return getParent().getTargetEditPart(request);
		}
		return super.getTargetEditPart(request);
	}

}
