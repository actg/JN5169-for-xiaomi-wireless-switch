package oscfg.diagram.edit.policies;

import java.util.Collections;
import java.util.HashMap;
import java.util.Iterator;

import java.util.Map;
import org.eclipse.emf.ecore.EClassifier;
import org.eclipse.emf.ecore.EObject;
import org.eclipse.emf.transaction.TransactionalEditingDomain;
import org.eclipse.gef.EditPart;
import org.eclipse.gef.Request;
import org.eclipse.gef.commands.Command;
import org.eclipse.gef.commands.CompoundCommand;
import org.eclipse.gef.commands.UnexecutableCommand;
import org.eclipse.gef.requests.ReconnectRequest;
import org.eclipse.gmf.runtime.common.core.command.ICommand;
import org.eclipse.gmf.runtime.common.core.command.ICompositeCommand;
import org.eclipse.gmf.runtime.diagram.core.commands.DeleteCommand;
import org.eclipse.gmf.runtime.diagram.core.util.ViewUtil;
import org.eclipse.gmf.runtime.diagram.ui.commands.CommandProxy;
import org.eclipse.gmf.runtime.diagram.ui.commands.ICommandProxy;
import org.eclipse.gmf.runtime.diagram.ui.editparts.IGraphicalEditPart;
import org.eclipse.gmf.runtime.diagram.ui.editpolicies.SemanticEditPolicy;
import org.eclipse.gmf.runtime.diagram.ui.requests.EditCommandRequestWrapper;
import org.eclipse.gmf.runtime.emf.commands.core.command.CompositeTransactionalCommand;
import org.eclipse.gmf.runtime.emf.type.core.ElementTypeRegistry;
import org.eclipse.gmf.runtime.emf.type.core.IEditHelperContext;
import org.eclipse.gmf.runtime.emf.type.core.IElementType;
import org.eclipse.gmf.runtime.emf.type.core.requests.ConfigureRequest;
import org.eclipse.gmf.runtime.emf.type.core.requests.CreateElementRequest;
import org.eclipse.gmf.runtime.emf.type.core.requests.CreateRelationshipRequest;
import org.eclipse.gmf.runtime.emf.type.core.requests.DestroyElementRequest;
import org.eclipse.gmf.runtime.emf.type.core.requests.DestroyReferenceRequest;
import org.eclipse.gmf.runtime.emf.type.core.requests.DestroyRequest;
import org.eclipse.gmf.runtime.emf.type.core.requests.DuplicateElementsRequest;
import org.eclipse.gmf.runtime.emf.type.core.requests.GetEditContextRequest;
import org.eclipse.gmf.runtime.emf.type.core.requests.IEditCommandRequest;
import org.eclipse.gmf.runtime.emf.type.core.requests.MoveRequest;
import org.eclipse.gmf.runtime.emf.type.core.requests.ReorientReferenceRelationshipRequest;
import org.eclipse.gmf.runtime.emf.type.core.requests.ReorientRelationshipRequest;
import org.eclipse.gmf.runtime.emf.type.core.requests.SetRequest;
import org.eclipse.gmf.runtime.notation.Edge;
import org.eclipse.gmf.runtime.notation.View;

import org.eclipse.gmf.tooling.runtime.edit.helpers.GeneratedEditHelperBase;
import oscfg.BaseTask;
import oscfg.CallbackFunction;
import oscfg.HWCounter;
import oscfg.InterruptSource;
import oscfg.Message;
import oscfg.Mutex;
import oscfg.OscfgPackage;
import oscfg.Poster;
import oscfg.SWTimer;
import oscfg.Task;
import oscfg.diagram.edit.helpers.OscfgBaseEditHelper;
import oscfg.diagram.expressions.OscfgAbstractExpression;
import oscfg.diagram.expressions.OscfgOCLFactory;
import oscfg.diagram.part.OscfgDiagramEditorPlugin;
import oscfg.diagram.part.OscfgVisualIDRegistry;
import oscfg.diagram.providers.OscfgElementTypes;

/**
 * @generated
 */
public class OscfgBaseItemSemanticEditPolicy extends SemanticEditPolicy {

	/**
	 * Extended request data key to hold editpart visual id.
	 * 
	 * @generated
	 */
	public static final String VISUAL_ID_KEY = "visual_id"; //$NON-NLS-1$

	/**
	 * @generated
	 */
	private final IElementType myElementType;

	/**
	 * @generated
	 */
	protected OscfgBaseItemSemanticEditPolicy(IElementType elementType) {
		myElementType = elementType;
	}

	/**
	 * Extended request data key to hold editpart visual id.
	 * Add visual id of edited editpart to extended data of the request
	 * so command switch can decide what kind of diagram element is being edited.
	 * It is done in those cases when it's not possible to deduce diagram
	 * element kind from domain element.
	 * 
	 * @generated
	 */
	public Command getCommand(Request request) {
		if (request instanceof ReconnectRequest) {
			Object view = ((ReconnectRequest) request).getConnectionEditPart()
					.getModel();
			if (view instanceof View) {
				Integer id = new Integer(
						OscfgVisualIDRegistry.getVisualID((View) view));
				request.getExtendedData().put(VISUAL_ID_KEY, id);
			}
		}
		return super.getCommand(request);
	}

	/**
	 * Returns visual id from request parameters.
	 * 
	 * @generated
	 */
	protected int getVisualID(IEditCommandRequest request) {
		Object id = request.getParameter(VISUAL_ID_KEY);
		return id instanceof Integer ? ((Integer) id).intValue() : -1;
	}

	/**
	 * @generated
	 */
	protected Command getSemanticCommand(IEditCommandRequest request) {
		IEditCommandRequest completedRequest = completeRequest(request);
		Command semanticCommand = getSemanticCommandSwitch(completedRequest);
		semanticCommand = getEditHelperCommand(completedRequest,
				semanticCommand);
		if (completedRequest instanceof DestroyRequest) {
			DestroyRequest destroyRequest = (DestroyRequest) completedRequest;
			return shouldProceed(destroyRequest) ? addDeleteViewCommand(
					semanticCommand, destroyRequest) : null;
		}
		return semanticCommand;
	}

	/**
	 * @generated
	 */
	protected Command addDeleteViewCommand(Command mainCommand,
			DestroyRequest completedRequest) {
		Command deleteViewCommand = getGEFWrapper(new DeleteCommand(
				getEditingDomain(), (View) getHost().getModel()));
		return mainCommand == null ? deleteViewCommand : mainCommand
				.chain(deleteViewCommand);
	}

	/**
	 * @generated
	 */
	private Command getEditHelperCommand(IEditCommandRequest request,
			Command editPolicyCommand) {
		if (editPolicyCommand != null) {
			ICommand command = editPolicyCommand instanceof ICommandProxy ? ((ICommandProxy) editPolicyCommand)
					.getICommand() : new CommandProxy(editPolicyCommand);
			request.setParameter(GeneratedEditHelperBase.EDIT_POLICY_COMMAND,
					command);
		}
		IElementType requestContextElementType = getContextElementType(request);
		request.setParameter(GeneratedEditHelperBase.CONTEXT_ELEMENT_TYPE,
				requestContextElementType);
		ICommand command = requestContextElementType.getEditCommand(request);
		request.setParameter(GeneratedEditHelperBase.EDIT_POLICY_COMMAND, null);
		request.setParameter(GeneratedEditHelperBase.CONTEXT_ELEMENT_TYPE, null);
		if (command != null) {
			if (!(command instanceof CompositeTransactionalCommand)) {
				command = new CompositeTransactionalCommand(getEditingDomain(),
						command.getLabel()).compose(command);
			}
			return new ICommandProxy(command);
		}
		return editPolicyCommand;
	}

	/**
	 * @generated
	 */
	private IElementType getContextElementType(IEditCommandRequest request) {
		IElementType requestContextElementType = OscfgElementTypes
				.getElementType(getVisualID(request));
		return requestContextElementType != null ? requestContextElementType
				: myElementType;
	}

	/**
	 * @generated
	 */
	protected Command getSemanticCommandSwitch(IEditCommandRequest req) {
		if (req instanceof CreateRelationshipRequest) {
			return getCreateRelationshipCommand((CreateRelationshipRequest) req);
		} else if (req instanceof CreateElementRequest) {
			return getCreateCommand((CreateElementRequest) req);
		} else if (req instanceof ConfigureRequest) {
			return getConfigureCommand((ConfigureRequest) req);
		} else if (req instanceof DestroyElementRequest) {
			return getDestroyElementCommand((DestroyElementRequest) req);
		} else if (req instanceof DestroyReferenceRequest) {
			return getDestroyReferenceCommand((DestroyReferenceRequest) req);
		} else if (req instanceof DuplicateElementsRequest) {
			return getDuplicateCommand((DuplicateElementsRequest) req);
		} else if (req instanceof GetEditContextRequest) {
			return getEditContextCommand((GetEditContextRequest) req);
		} else if (req instanceof MoveRequest) {
			return getMoveCommand((MoveRequest) req);
		} else if (req instanceof ReorientReferenceRelationshipRequest) {
			return getReorientReferenceRelationshipCommand((ReorientReferenceRelationshipRequest) req);
		} else if (req instanceof ReorientRelationshipRequest) {
			return getReorientRelationshipCommand((ReorientRelationshipRequest) req);
		} else if (req instanceof SetRequest) {
			return getSetCommand((SetRequest) req);
		}
		return null;
	}

	/**
	 * @generated
	 */
	protected Command getConfigureCommand(ConfigureRequest req) {
		return null;
	}

	/**
	 * @generated
	 */
	protected Command getCreateRelationshipCommand(CreateRelationshipRequest req) {
		return null;
	}

	/**
	 * @generated
	 */
	protected Command getCreateCommand(CreateElementRequest req) {
		return null;
	}

	/**
	 * @generated
	 */
	protected Command getSetCommand(SetRequest req) {
		return null;
	}

	/**
	 * @generated
	 */
	protected Command getEditContextCommand(GetEditContextRequest req) {
		return null;
	}

	/**
	 * @generated
	 */
	protected Command getDestroyElementCommand(DestroyElementRequest req) {
		return null;
	}

	/**
	 * @generated
	 */
	protected Command getDestroyReferenceCommand(DestroyReferenceRequest req) {
		return null;
	}

	/**
	 * @generated
	 */
	protected Command getDuplicateCommand(DuplicateElementsRequest req) {
		return null;
	}

	/**
	 * @generated
	 */
	protected Command getMoveCommand(MoveRequest req) {
		return null;
	}

	/**
	 * @generated
	 */
	protected Command getReorientReferenceRelationshipCommand(
			ReorientReferenceRelationshipRequest req) {
		return UnexecutableCommand.INSTANCE;
	}

	/**
	 * @generated
	 */
	protected Command getReorientRelationshipCommand(
			ReorientRelationshipRequest req) {
		return UnexecutableCommand.INSTANCE;
	}

	/**
	 * @generated
	 */
	protected final Command getGEFWrapper(ICommand cmd) {
		return new ICommandProxy(cmd);
	}

	/**
	 * Returns editing domain from the host edit part.
	 * 
	 * @generated
	 */
	protected TransactionalEditingDomain getEditingDomain() {
		return ((IGraphicalEditPart) getHost()).getEditingDomain();
	}

	/**
	 * Clean all shortcuts to the host element from the same diagram
	 * @generated
	 */
	protected void addDestroyShortcutsCommand(ICompositeCommand cmd, View view) {
		assert view.getEAnnotation("Shortcut") == null; //$NON-NLS-1$
		for (Iterator it = view.getDiagram().getChildren().iterator(); it
				.hasNext();) {
			View nextView = (View) it.next();
			if (nextView.getEAnnotation("Shortcut") == null || !nextView.isSetElement() || nextView.getElement() != view.getElement()) { //$NON-NLS-1$
				continue;
			}
			cmd.add(new DeleteCommand(getEditingDomain(), nextView));
		}
	}

	/**
	 * @generated
	 */
	public static LinkConstraints getLinkConstraints() {
		LinkConstraints cached = OscfgDiagramEditorPlugin.getInstance()
				.getLinkConstraints();
		if (cached == null) {
			OscfgDiagramEditorPlugin.getInstance().setLinkConstraints(
					cached = new LinkConstraints());
		}
		return cached;
	}

	/**
	 * @generated
	 */
	public static class LinkConstraints {

		/**
		 * @generated
		 */
		LinkConstraints() {
			// use static method #getLinkConstraints() to access instance
		}

		/**
		 * @generated
		 */
		public boolean canCreateBaseTaskCollectMessage_4001(BaseTask source,
				Message target) {
			if (source != null) {
				if (source.getCollectMessage().contains(target)) {
					return false;
				}
			}

			return canExistBaseTaskCollectMessage_4001(source, target);
		}

		/**
		 * @generated
		 */
		public boolean canCreatePosterPostMessage_4012(Poster source,
				Message target) {
			if (source != null) {
				if (source.getPostMessage().contains(target)) {
					return false;
				}
			}

			return canExistPosterPostMessage_4012(source, target);
		}

		/**
		 * @generated
		 */
		public boolean canCreateBaseTaskEnterExitMutex_4003(BaseTask source,
				Mutex target) {
			if (source != null) {
				if (source.getEnterExitMutex().contains(target)) {
					return false;
				}
			}

			return canExistBaseTaskEnterExitMutex_4003(source, target);
		}

		/**
		 * @generated
		 */
		public boolean canCreateSWTimerActivates_4004(SWTimer source,
				Task target) {
			if (source != null) {
				if (source.getActivates() != null) {
					return false;
				}
			}

			return canExistSWTimerActivates_4004(source, target);
		}

		/**
		 * @generated
		 */
		public boolean canCreateSWTimerTimer_callback_4005(SWTimer source,
				CallbackFunction target) {
			if (source != null) {
				if (source.getTimer_callback() != null) {
					return false;
				}
			}

			return canExistSWTimerTimer_callback_4005(source, target);
		}

		/**
		 * @generated
		 */
		public boolean canCreateMessageNotifies_4006(Message source, Task target) {
			if (source != null) {
				if (source.getNotifies() != null) {
					return false;
				}
			}

			return canExistMessageNotifies_4006(source, target);
		}

		/**
		 * @generated
		 */
		public boolean canCreateHWCounterEnable_callback_4007(HWCounter source,
				CallbackFunction target) {
			if (source != null) {
				if (source.getEnable_callback() != null) {
					return false;
				}
			}

			return canExistHWCounterEnable_callback_4007(source, target);
		}

		/**
		 * @generated
		 */
		public boolean canCreateHWCounterDisable_callback_4008(
				HWCounter source, CallbackFunction target) {
			if (source != null) {
				if (source.getDisable_callback() != null) {
					return false;
				}
			}

			return canExistHWCounterDisable_callback_4008(source, target);
		}

		/**
		 * @generated
		 */
		public boolean canCreateHWCounterGet_callback_4009(HWCounter source,
				CallbackFunction target) {
			if (source != null) {
				if (source.getGet_callback() != null) {
					return false;
				}
			}

			return canExistHWCounterGet_callback_4009(source, target);
		}

		/**
		 * @generated
		 */
		public boolean canCreateHWCounterSet_callback_4010(HWCounter source,
				CallbackFunction target) {
			if (source != null) {
				if (source.getSet_callback() != null) {
					return false;
				}
			}

			return canExistHWCounterSet_callback_4010(source, target);
		}

		/**
		 * @generated
		 */
		public boolean canCreateInterruptSourceSourceISR_4011(
				InterruptSource source, oscfg.ISR target) {
			if (source != null) {
				if (source.getSourceISR() != null) {
					return false;
				}
			}
			if (target != null && (target.getISRSource().contains(target))) {
				return false;
			}

			return canExistInterruptSourceSourceISR_4011(source, target);
		}

		/**
		 * @generated
		 */
		public boolean canExistBaseTaskCollectMessage_4001(BaseTask source,
				Message target) {
			return true;
		}

		/**
		 * @generated
		 */
		public boolean canExistPosterPostMessage_4012(Poster source,
				Message target) {
			return true;
		}

		/**
		 * @generated
		 */
		public boolean canExistBaseTaskEnterExitMutex_4003(BaseTask source,
				Mutex target) {
			return true;
		}

		/**
		 * @generated
		 */
		public boolean canExistSWTimerActivates_4004(SWTimer source, Task target) {
			return true;
		}

		/**
		 * @generated
		 */
		public boolean canExistSWTimerTimer_callback_4005(SWTimer source,
				CallbackFunction target) {
			return true;
		}

		/**
		 * @generated
		 */
		public boolean canExistMessageNotifies_4006(Message source, Task target) {
			return true;
		}

		/**
		 * @generated
		 */
		public boolean canExistHWCounterEnable_callback_4007(HWCounter source,
				CallbackFunction target) {
			return true;
		}

		/**
		 * @generated
		 */
		public boolean canExistHWCounterDisable_callback_4008(HWCounter source,
				CallbackFunction target) {
			return true;
		}

		/**
		 * @generated
		 */
		public boolean canExistHWCounterGet_callback_4009(HWCounter source,
				CallbackFunction target) {
			return true;
		}

		/**
		 * @generated
		 */
		public boolean canExistHWCounterSet_callback_4010(HWCounter source,
				CallbackFunction target) {
			return true;
		}

		/**
		 * @generated
		 */
		public boolean canExistInterruptSourceSourceISR_4011(
				InterruptSource source, oscfg.ISR target) {
			try {
				if (target == null) {
					return true;
				} else {
					Map<String, EClassifier> env = Collections
							.<String, EClassifier> singletonMap(
									"oppositeEnd", OscfgPackage.eINSTANCE.getInterruptSource()); //$NON-NLS-1$
					Object targetVal = OscfgOCLFactory.getExpression(0,
							OscfgPackage.eINSTANCE.getISR(), env).evaluate(
							target,
							Collections.singletonMap("oppositeEnd", source)); //$NON-NLS-1$
					if (false == targetVal instanceof Boolean
							|| !((Boolean) targetVal).booleanValue()) {
						return false;
					} // else fall-through
				}
				return true;
			} catch (Exception e) {
				OscfgDiagramEditorPlugin.getInstance().logError(
						"Link constraint evaluation error", e); //$NON-NLS-1$
				return false;
			}
		}

	}

}
