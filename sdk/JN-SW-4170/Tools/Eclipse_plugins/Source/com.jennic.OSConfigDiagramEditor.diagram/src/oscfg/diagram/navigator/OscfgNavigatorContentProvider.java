package oscfg.diagram.navigator;

import java.util.ArrayList;
import java.util.Collection;
import java.util.Collections;
import java.util.HashMap;
import java.util.Iterator;

import java.util.LinkedList;
import org.eclipse.core.resources.IFile;
import org.eclipse.emf.common.util.URI;
import org.eclipse.emf.ecore.EObject;
import org.eclipse.emf.ecore.resource.Resource;
import org.eclipse.emf.edit.domain.AdapterFactoryEditingDomain;
import org.eclipse.emf.transaction.TransactionalEditingDomain;
import org.eclipse.emf.workspace.util.WorkspaceSynchronizer;
import org.eclipse.gmf.runtime.emf.core.GMFEditingDomainFactory;
import org.eclipse.gmf.runtime.notation.Diagram;
import org.eclipse.gmf.runtime.notation.Edge;
import org.eclipse.gmf.runtime.notation.Node;
import org.eclipse.gmf.runtime.notation.View;
import org.eclipse.jface.viewers.Viewer;
import org.eclipse.ui.IMemento;
import org.eclipse.ui.navigator.ICommonContentExtensionSite;
import org.eclipse.ui.navigator.ICommonContentProvider;

import oscfg.diagram.edit.parts.BaseTaskCollectMessageEditPart;
import oscfg.diagram.edit.parts.BaseTaskEnterExitMutexEditPart;
import oscfg.diagram.edit.parts.CallbackFunctionEditPart;
import oscfg.diagram.edit.parts.ConfigurationEditPart;
import oscfg.diagram.edit.parts.CooperativeGroupCooperativeTasksEditPart;
import oscfg.diagram.edit.parts.CooperativeGroupEditPart;
import oscfg.diagram.edit.parts.HWCounterDisable_callbackEditPart;
import oscfg.diagram.edit.parts.HWCounterEditPart;
import oscfg.diagram.edit.parts.HWCounterEnable_callbackEditPart;
import oscfg.diagram.edit.parts.HWCounterGet_callbackEditPart;
import oscfg.diagram.edit.parts.HWCounterSet_callbackEditPart;
import oscfg.diagram.edit.parts.HWCounterSoftwareTimersEditPart;
import oscfg.diagram.edit.parts.ISREditPart;
import oscfg.diagram.edit.parts.InterruptSourceEditPart;
import oscfg.diagram.edit.parts.InterruptSourceSourceISREditPart;
import oscfg.diagram.edit.parts.MessageEditPart;
import oscfg.diagram.edit.parts.MessageNotifiesEditPart;
import oscfg.diagram.edit.parts.ModuleEditPart;
import oscfg.diagram.edit.parts.ModuleModuleObjectsEditPart;
import oscfg.diagram.edit.parts.MutexEditPart;
import oscfg.diagram.edit.parts.OSEditPart;
import oscfg.diagram.edit.parts.OSOSModulesEditPart;
import oscfg.diagram.edit.parts.PosterPostMessageEditPart;
import oscfg.diagram.edit.parts.SWTimerActivatesEditPart;
import oscfg.diagram.edit.parts.SWTimerEditPart;
import oscfg.diagram.edit.parts.SWTimerTimer_callbackEditPart;
import oscfg.diagram.edit.parts.Task2EditPart;
import oscfg.diagram.edit.parts.TaskEditPart;
import oscfg.diagram.part.Messages;
import oscfg.diagram.part.OscfgVisualIDRegistry;

/**
 * @generated
 */
public class OscfgNavigatorContentProvider implements ICommonContentProvider {

	/**
	 * @generated
	 */
	private static final Object[] EMPTY_ARRAY = new Object[0];

	/**
	 * @generated
	 */
	private Viewer myViewer;

	/**
	 * @generated
	 */
	private AdapterFactoryEditingDomain myEditingDomain;

	/**
	 * @generated
	 */
	private WorkspaceSynchronizer myWorkspaceSynchronizer;

	/**
	 * @generated
	 */
	private Runnable myViewerRefreshRunnable;

	/**
	 * @generated
	 */
	@SuppressWarnings({ "unchecked", "serial", "rawtypes" })
	public OscfgNavigatorContentProvider() {
		TransactionalEditingDomain editingDomain = GMFEditingDomainFactory.INSTANCE
				.createEditingDomain();
		myEditingDomain = (AdapterFactoryEditingDomain) editingDomain;
		myEditingDomain.setResourceToReadOnlyMap(new HashMap() {
			public Object get(Object key) {
				if (!containsKey(key)) {
					put(key, Boolean.TRUE);
				}
				return super.get(key);
			}
		});
		myViewerRefreshRunnable = new Runnable() {
			public void run() {
				if (myViewer != null) {
					myViewer.refresh();
				}
			}
		};
		myWorkspaceSynchronizer = new WorkspaceSynchronizer(editingDomain,
				new WorkspaceSynchronizer.Delegate() {
					public void dispose() {
					}

					public boolean handleResourceChanged(final Resource resource) {
						unloadAllResources();
						asyncRefresh();
						return true;
					}

					public boolean handleResourceDeleted(Resource resource) {
						unloadAllResources();
						asyncRefresh();
						return true;
					}

					public boolean handleResourceMoved(Resource resource,
							final URI newURI) {
						unloadAllResources();
						asyncRefresh();
						return true;
					}
				});
	}

	/**
	 * @generated
	 */
	public void dispose() {
		myWorkspaceSynchronizer.dispose();
		myWorkspaceSynchronizer = null;
		myViewerRefreshRunnable = null;
		myViewer = null;
		unloadAllResources();
		((TransactionalEditingDomain) myEditingDomain).dispose();
		myEditingDomain = null;
	}

	/**
	 * @generated
	 */
	public void inputChanged(Viewer viewer, Object oldInput, Object newInput) {
		myViewer = viewer;
	}

	/**
	 * @generated
	 */
	void unloadAllResources() {
		for (Resource nextResource : myEditingDomain.getResourceSet()
				.getResources()) {
			nextResource.unload();
		}
	}

	/**
	 * @generated
	 */
	void asyncRefresh() {
		if (myViewer != null && !myViewer.getControl().isDisposed()) {
			myViewer.getControl().getDisplay()
					.asyncExec(myViewerRefreshRunnable);
		}
	}

	/**
	 * @generated
	 */
	public Object[] getElements(Object inputElement) {
		return getChildren(inputElement);
	}

	/**
	 * @generated
	 */
	public void restoreState(IMemento aMemento) {
	}

	/**
	 * @generated
	 */
	public void saveState(IMemento aMemento) {
	}

	/**
	 * @generated
	 */
	public void init(ICommonContentExtensionSite aConfig) {
	}

	/**
	 * @generated
	 */
	public Object[] getChildren(Object parentElement) {
		if (parentElement instanceof IFile) {
			IFile file = (IFile) parentElement;
			URI fileURI = URI.createPlatformResourceURI(file.getFullPath()
					.toString(), true);
			Resource resource = myEditingDomain.getResourceSet().getResource(
					fileURI, true);
			ArrayList<OscfgNavigatorItem> result = new ArrayList<OscfgNavigatorItem>();
			ArrayList<View> topViews = new ArrayList<View>(resource
					.getContents().size());
			for (EObject o : resource.getContents()) {
				if (o instanceof View) {
					topViews.add((View) o);
				}
			}
			result.addAll(createNavigatorItems(
					selectViewsByType(topViews, ConfigurationEditPart.MODEL_ID),
					file, false));
			return result.toArray();
		}

		if (parentElement instanceof OscfgNavigatorGroup) {
			OscfgNavigatorGroup group = (OscfgNavigatorGroup) parentElement;
			return group.getChildren();
		}

		if (parentElement instanceof OscfgNavigatorItem) {
			OscfgNavigatorItem navigatorItem = (OscfgNavigatorItem) parentElement;
			if (navigatorItem.isLeaf() || !isOwnView(navigatorItem.getView())) {
				return EMPTY_ARRAY;
			}
			return getViewChildren(navigatorItem.getView(), parentElement);
		}

		return EMPTY_ARRAY;
	}

	/**
	 * @generated
	 */
	@SuppressWarnings("unchecked")
	private Object[] getViewChildren(View view, Object parentElement) {
		switch (OscfgVisualIDRegistry.getVisualID(view)) {

		case ConfigurationEditPart.VISUAL_ID: {
			LinkedList<OscfgAbstractNavigatorItem> result = new LinkedList<OscfgAbstractNavigatorItem>();
			Diagram sv = (Diagram) view;
			OscfgNavigatorGroup links = new OscfgNavigatorGroup(
					Messages.NavigatorGroupName_Configuration_1000_links,
					"icons/linksNavigatorGroup.gif", parentElement); //$NON-NLS-1$
			Collection<View> connectedViews;
			connectedViews = getChildrenByType(Collections.singleton(sv),
					OscfgVisualIDRegistry.getType(OSEditPart.VISUAL_ID));
			result.addAll(createNavigatorItems(connectedViews, parentElement,
					false));
			connectedViews = getDiagramLinksByType(Collections.singleton(sv),
					OscfgVisualIDRegistry
							.getType(BaseTaskCollectMessageEditPart.VISUAL_ID));
			links.addChildren(createNavigatorItems(connectedViews, links, false));
			connectedViews = getDiagramLinksByType(Collections.singleton(sv),
					OscfgVisualIDRegistry
							.getType(PosterPostMessageEditPart.VISUAL_ID));
			links.addChildren(createNavigatorItems(connectedViews, links, false));
			connectedViews = getDiagramLinksByType(Collections.singleton(sv),
					OscfgVisualIDRegistry
							.getType(BaseTaskEnterExitMutexEditPart.VISUAL_ID));
			links.addChildren(createNavigatorItems(connectedViews, links, false));
			connectedViews = getDiagramLinksByType(Collections.singleton(sv),
					OscfgVisualIDRegistry
							.getType(SWTimerActivatesEditPart.VISUAL_ID));
			links.addChildren(createNavigatorItems(connectedViews, links, false));
			connectedViews = getDiagramLinksByType(Collections.singleton(sv),
					OscfgVisualIDRegistry
							.getType(SWTimerTimer_callbackEditPart.VISUAL_ID));
			links.addChildren(createNavigatorItems(connectedViews, links, false));
			connectedViews = getDiagramLinksByType(Collections.singleton(sv),
					OscfgVisualIDRegistry
							.getType(MessageNotifiesEditPart.VISUAL_ID));
			links.addChildren(createNavigatorItems(connectedViews, links, false));
			connectedViews = getDiagramLinksByType(
					Collections.singleton(sv),
					OscfgVisualIDRegistry
							.getType(HWCounterEnable_callbackEditPart.VISUAL_ID));
			links.addChildren(createNavigatorItems(connectedViews, links, false));
			connectedViews = getDiagramLinksByType(
					Collections.singleton(sv),
					OscfgVisualIDRegistry
							.getType(HWCounterDisable_callbackEditPart.VISUAL_ID));
			links.addChildren(createNavigatorItems(connectedViews, links, false));
			connectedViews = getDiagramLinksByType(Collections.singleton(sv),
					OscfgVisualIDRegistry
							.getType(HWCounterGet_callbackEditPart.VISUAL_ID));
			links.addChildren(createNavigatorItems(connectedViews, links, false));
			connectedViews = getDiagramLinksByType(Collections.singleton(sv),
					OscfgVisualIDRegistry
							.getType(HWCounterSet_callbackEditPart.VISUAL_ID));
			links.addChildren(createNavigatorItems(connectedViews, links, false));
			connectedViews = getDiagramLinksByType(
					Collections.singleton(sv),
					OscfgVisualIDRegistry
							.getType(InterruptSourceSourceISREditPart.VISUAL_ID));
			links.addChildren(createNavigatorItems(connectedViews, links, false));
			if (!links.isEmpty()) {
				result.add(links);
			}
			return result.toArray();
		}

		case OSEditPart.VISUAL_ID: {
			LinkedList<OscfgAbstractNavigatorItem> result = new LinkedList<OscfgAbstractNavigatorItem>();
			Node sv = (Node) view;
			Collection<View> connectedViews;
			connectedViews = getChildrenByType(Collections.singleton(sv),
					OscfgVisualIDRegistry
							.getType(OSOSModulesEditPart.VISUAL_ID));
			connectedViews = getChildrenByType(connectedViews,
					OscfgVisualIDRegistry.getType(ModuleEditPart.VISUAL_ID));
			result.addAll(createNavigatorItems(connectedViews, parentElement,
					false));
			return result.toArray();
		}

		case SWTimerEditPart.VISUAL_ID: {
			LinkedList<OscfgAbstractNavigatorItem> result = new LinkedList<OscfgAbstractNavigatorItem>();
			Node sv = (Node) view;
			OscfgNavigatorGroup outgoinglinks = new OscfgNavigatorGroup(
					Messages.NavigatorGroupName_SWTimer_3006_outgoinglinks,
					"icons/outgoingLinksNavigatorGroup.gif", parentElement); //$NON-NLS-1$
			Collection<View> connectedViews;
			connectedViews = getOutgoingLinksByType(Collections.singleton(sv),
					OscfgVisualIDRegistry
							.getType(SWTimerActivatesEditPart.VISUAL_ID));
			outgoinglinks.addChildren(createNavigatorItems(connectedViews,
					outgoinglinks, true));
			connectedViews = getOutgoingLinksByType(Collections.singleton(sv),
					OscfgVisualIDRegistry
							.getType(SWTimerTimer_callbackEditPart.VISUAL_ID));
			outgoinglinks.addChildren(createNavigatorItems(connectedViews,
					outgoinglinks, true));
			if (!outgoinglinks.isEmpty()) {
				result.add(outgoinglinks);
			}
			return result.toArray();
		}

		case ModuleEditPart.VISUAL_ID: {
			LinkedList<OscfgAbstractNavigatorItem> result = new LinkedList<OscfgAbstractNavigatorItem>();
			Node sv = (Node) view;
			Collection<View> connectedViews;
			connectedViews = getChildrenByType(Collections.singleton(sv),
					OscfgVisualIDRegistry
							.getType(ModuleModuleObjectsEditPart.VISUAL_ID));
			connectedViews = getChildrenByType(connectedViews,
					OscfgVisualIDRegistry.getType(TaskEditPart.VISUAL_ID));
			result.addAll(createNavigatorItems(connectedViews, parentElement,
					false));
			connectedViews = getChildrenByType(Collections.singleton(sv),
					OscfgVisualIDRegistry
							.getType(ModuleModuleObjectsEditPart.VISUAL_ID));
			connectedViews = getChildrenByType(connectedViews,
					OscfgVisualIDRegistry.getType(ISREditPart.VISUAL_ID));
			result.addAll(createNavigatorItems(connectedViews, parentElement,
					false));
			connectedViews = getChildrenByType(Collections.singleton(sv),
					OscfgVisualIDRegistry
							.getType(ModuleModuleObjectsEditPart.VISUAL_ID));
			connectedViews = getChildrenByType(connectedViews,
					OscfgVisualIDRegistry.getType(MutexEditPart.VISUAL_ID));
			result.addAll(createNavigatorItems(connectedViews, parentElement,
					false));
			connectedViews = getChildrenByType(Collections.singleton(sv),
					OscfgVisualIDRegistry
							.getType(ModuleModuleObjectsEditPart.VISUAL_ID));
			connectedViews = getChildrenByType(connectedViews,
					OscfgVisualIDRegistry.getType(MessageEditPart.VISUAL_ID));
			result.addAll(createNavigatorItems(connectedViews, parentElement,
					false));
			connectedViews = getChildrenByType(Collections.singleton(sv),
					OscfgVisualIDRegistry
							.getType(ModuleModuleObjectsEditPart.VISUAL_ID));
			connectedViews = getChildrenByType(connectedViews,
					OscfgVisualIDRegistry.getType(HWCounterEditPart.VISUAL_ID));
			result.addAll(createNavigatorItems(connectedViews, parentElement,
					false));
			connectedViews = getChildrenByType(Collections.singleton(sv),
					OscfgVisualIDRegistry
							.getType(ModuleModuleObjectsEditPart.VISUAL_ID));
			connectedViews = getChildrenByType(connectedViews,
					OscfgVisualIDRegistry
							.getType(CallbackFunctionEditPart.VISUAL_ID));
			result.addAll(createNavigatorItems(connectedViews, parentElement,
					false));
			connectedViews = getChildrenByType(Collections.singleton(sv),
					OscfgVisualIDRegistry
							.getType(ModuleModuleObjectsEditPart.VISUAL_ID));
			connectedViews = getChildrenByType(connectedViews,
					OscfgVisualIDRegistry
							.getType(InterruptSourceEditPart.VISUAL_ID));
			result.addAll(createNavigatorItems(connectedViews, parentElement,
					false));
			connectedViews = getChildrenByType(Collections.singleton(sv),
					OscfgVisualIDRegistry
							.getType(ModuleModuleObjectsEditPart.VISUAL_ID));
			connectedViews = getChildrenByType(connectedViews,
					OscfgVisualIDRegistry
							.getType(CooperativeGroupEditPart.VISUAL_ID));
			result.addAll(createNavigatorItems(connectedViews, parentElement,
					false));
			return result.toArray();
		}

		case TaskEditPart.VISUAL_ID: {
			LinkedList<OscfgAbstractNavigatorItem> result = new LinkedList<OscfgAbstractNavigatorItem>();
			Node sv = (Node) view;
			OscfgNavigatorGroup outgoinglinks = new OscfgNavigatorGroup(
					Messages.NavigatorGroupName_Task_3010_outgoinglinks,
					"icons/outgoingLinksNavigatorGroup.gif", parentElement); //$NON-NLS-1$
			OscfgNavigatorGroup incominglinks = new OscfgNavigatorGroup(
					Messages.NavigatorGroupName_Task_3010_incominglinks,
					"icons/incomingLinksNavigatorGroup.gif", parentElement); //$NON-NLS-1$
			Collection<View> connectedViews;
			connectedViews = getOutgoingLinksByType(Collections.singleton(sv),
					OscfgVisualIDRegistry
							.getType(BaseTaskCollectMessageEditPart.VISUAL_ID));
			outgoinglinks.addChildren(createNavigatorItems(connectedViews,
					outgoinglinks, true));
			connectedViews = getOutgoingLinksByType(Collections.singleton(sv),
					OscfgVisualIDRegistry
							.getType(PosterPostMessageEditPart.VISUAL_ID));
			outgoinglinks.addChildren(createNavigatorItems(connectedViews,
					outgoinglinks, true));
			connectedViews = getOutgoingLinksByType(Collections.singleton(sv),
					OscfgVisualIDRegistry
							.getType(BaseTaskEnterExitMutexEditPart.VISUAL_ID));
			outgoinglinks.addChildren(createNavigatorItems(connectedViews,
					outgoinglinks, true));
			connectedViews = getIncomingLinksByType(Collections.singleton(sv),
					OscfgVisualIDRegistry
							.getType(SWTimerActivatesEditPart.VISUAL_ID));
			incominglinks.addChildren(createNavigatorItems(connectedViews,
					incominglinks, true));
			connectedViews = getIncomingLinksByType(Collections.singleton(sv),
					OscfgVisualIDRegistry
							.getType(MessageNotifiesEditPart.VISUAL_ID));
			incominglinks.addChildren(createNavigatorItems(connectedViews,
					incominglinks, true));
			if (!outgoinglinks.isEmpty()) {
				result.add(outgoinglinks);
			}
			if (!incominglinks.isEmpty()) {
				result.add(incominglinks);
			}
			return result.toArray();
		}

		case ISREditPart.VISUAL_ID: {
			LinkedList<OscfgAbstractNavigatorItem> result = new LinkedList<OscfgAbstractNavigatorItem>();
			Node sv = (Node) view;
			OscfgNavigatorGroup outgoinglinks = new OscfgNavigatorGroup(
					Messages.NavigatorGroupName_ISR_3011_outgoinglinks,
					"icons/outgoingLinksNavigatorGroup.gif", parentElement); //$NON-NLS-1$
			OscfgNavigatorGroup incominglinks = new OscfgNavigatorGroup(
					Messages.NavigatorGroupName_ISR_3011_incominglinks,
					"icons/incomingLinksNavigatorGroup.gif", parentElement); //$NON-NLS-1$
			Collection<View> connectedViews;
			connectedViews = getOutgoingLinksByType(Collections.singleton(sv),
					OscfgVisualIDRegistry
							.getType(BaseTaskCollectMessageEditPart.VISUAL_ID));
			outgoinglinks.addChildren(createNavigatorItems(connectedViews,
					outgoinglinks, true));
			connectedViews = getOutgoingLinksByType(Collections.singleton(sv),
					OscfgVisualIDRegistry
							.getType(PosterPostMessageEditPart.VISUAL_ID));
			outgoinglinks.addChildren(createNavigatorItems(connectedViews,
					outgoinglinks, true));
			connectedViews = getOutgoingLinksByType(Collections.singleton(sv),
					OscfgVisualIDRegistry
							.getType(BaseTaskEnterExitMutexEditPart.VISUAL_ID));
			outgoinglinks.addChildren(createNavigatorItems(connectedViews,
					outgoinglinks, true));
			connectedViews = getIncomingLinksByType(
					Collections.singleton(sv),
					OscfgVisualIDRegistry
							.getType(InterruptSourceSourceISREditPart.VISUAL_ID));
			incominglinks.addChildren(createNavigatorItems(connectedViews,
					incominglinks, true));
			if (!outgoinglinks.isEmpty()) {
				result.add(outgoinglinks);
			}
			if (!incominglinks.isEmpty()) {
				result.add(incominglinks);
			}
			return result.toArray();
		}

		case MutexEditPart.VISUAL_ID: {
			LinkedList<OscfgAbstractNavigatorItem> result = new LinkedList<OscfgAbstractNavigatorItem>();
			Node sv = (Node) view;
			OscfgNavigatorGroup incominglinks = new OscfgNavigatorGroup(
					Messages.NavigatorGroupName_Mutex_3012_incominglinks,
					"icons/incomingLinksNavigatorGroup.gif", parentElement); //$NON-NLS-1$
			Collection<View> connectedViews;
			connectedViews = getIncomingLinksByType(Collections.singleton(sv),
					OscfgVisualIDRegistry
							.getType(BaseTaskEnterExitMutexEditPart.VISUAL_ID));
			incominglinks.addChildren(createNavigatorItems(connectedViews,
					incominglinks, true));
			if (!incominglinks.isEmpty()) {
				result.add(incominglinks);
			}
			return result.toArray();
		}

		case MessageEditPart.VISUAL_ID: {
			LinkedList<OscfgAbstractNavigatorItem> result = new LinkedList<OscfgAbstractNavigatorItem>();
			Node sv = (Node) view;
			OscfgNavigatorGroup incominglinks = new OscfgNavigatorGroup(
					Messages.NavigatorGroupName_Message_3013_incominglinks,
					"icons/incomingLinksNavigatorGroup.gif", parentElement); //$NON-NLS-1$
			OscfgNavigatorGroup outgoinglinks = new OscfgNavigatorGroup(
					Messages.NavigatorGroupName_Message_3013_outgoinglinks,
					"icons/outgoingLinksNavigatorGroup.gif", parentElement); //$NON-NLS-1$
			Collection<View> connectedViews;
			connectedViews = getIncomingLinksByType(Collections.singleton(sv),
					OscfgVisualIDRegistry
							.getType(BaseTaskCollectMessageEditPart.VISUAL_ID));
			incominglinks.addChildren(createNavigatorItems(connectedViews,
					incominglinks, true));
			connectedViews = getIncomingLinksByType(Collections.singleton(sv),
					OscfgVisualIDRegistry
							.getType(PosterPostMessageEditPart.VISUAL_ID));
			incominglinks.addChildren(createNavigatorItems(connectedViews,
					incominglinks, true));
			connectedViews = getOutgoingLinksByType(Collections.singleton(sv),
					OscfgVisualIDRegistry
							.getType(MessageNotifiesEditPart.VISUAL_ID));
			outgoinglinks.addChildren(createNavigatorItems(connectedViews,
					outgoinglinks, true));
			if (!incominglinks.isEmpty()) {
				result.add(incominglinks);
			}
			if (!outgoinglinks.isEmpty()) {
				result.add(outgoinglinks);
			}
			return result.toArray();
		}

		case HWCounterEditPart.VISUAL_ID: {
			LinkedList<OscfgAbstractNavigatorItem> result = new LinkedList<OscfgAbstractNavigatorItem>();
			Node sv = (Node) view;
			OscfgNavigatorGroup outgoinglinks = new OscfgNavigatorGroup(
					Messages.NavigatorGroupName_HWCounter_3014_outgoinglinks,
					"icons/outgoingLinksNavigatorGroup.gif", parentElement); //$NON-NLS-1$
			Collection<View> connectedViews;
			connectedViews = getChildrenByType(Collections.singleton(sv),
					OscfgVisualIDRegistry
							.getType(HWCounterSoftwareTimersEditPart.VISUAL_ID));
			connectedViews = getChildrenByType(connectedViews,
					OscfgVisualIDRegistry.getType(SWTimerEditPart.VISUAL_ID));
			result.addAll(createNavigatorItems(connectedViews, parentElement,
					false));
			connectedViews = getOutgoingLinksByType(
					Collections.singleton(sv),
					OscfgVisualIDRegistry
							.getType(HWCounterEnable_callbackEditPart.VISUAL_ID));
			outgoinglinks.addChildren(createNavigatorItems(connectedViews,
					outgoinglinks, true));
			connectedViews = getOutgoingLinksByType(
					Collections.singleton(sv),
					OscfgVisualIDRegistry
							.getType(HWCounterDisable_callbackEditPart.VISUAL_ID));
			outgoinglinks.addChildren(createNavigatorItems(connectedViews,
					outgoinglinks, true));
			connectedViews = getOutgoingLinksByType(Collections.singleton(sv),
					OscfgVisualIDRegistry
							.getType(HWCounterGet_callbackEditPart.VISUAL_ID));
			outgoinglinks.addChildren(createNavigatorItems(connectedViews,
					outgoinglinks, true));
			connectedViews = getOutgoingLinksByType(Collections.singleton(sv),
					OscfgVisualIDRegistry
							.getType(HWCounterSet_callbackEditPart.VISUAL_ID));
			outgoinglinks.addChildren(createNavigatorItems(connectedViews,
					outgoinglinks, true));
			if (!outgoinglinks.isEmpty()) {
				result.add(outgoinglinks);
			}
			return result.toArray();
		}

		case CallbackFunctionEditPart.VISUAL_ID: {
			LinkedList<OscfgAbstractNavigatorItem> result = new LinkedList<OscfgAbstractNavigatorItem>();
			Node sv = (Node) view;
			OscfgNavigatorGroup outgoinglinks = new OscfgNavigatorGroup(
					Messages.NavigatorGroupName_CallbackFunction_3015_outgoinglinks,
					"icons/outgoingLinksNavigatorGroup.gif", parentElement); //$NON-NLS-1$
			OscfgNavigatorGroup incominglinks = new OscfgNavigatorGroup(
					Messages.NavigatorGroupName_CallbackFunction_3015_incominglinks,
					"icons/incomingLinksNavigatorGroup.gif", parentElement); //$NON-NLS-1$
			Collection<View> connectedViews;
			connectedViews = getOutgoingLinksByType(Collections.singleton(sv),
					OscfgVisualIDRegistry
							.getType(PosterPostMessageEditPart.VISUAL_ID));
			outgoinglinks.addChildren(createNavigatorItems(connectedViews,
					outgoinglinks, true));
			connectedViews = getIncomingLinksByType(Collections.singleton(sv),
					OscfgVisualIDRegistry
							.getType(SWTimerTimer_callbackEditPart.VISUAL_ID));
			incominglinks.addChildren(createNavigatorItems(connectedViews,
					incominglinks, true));
			connectedViews = getIncomingLinksByType(
					Collections.singleton(sv),
					OscfgVisualIDRegistry
							.getType(HWCounterEnable_callbackEditPart.VISUAL_ID));
			incominglinks.addChildren(createNavigatorItems(connectedViews,
					incominglinks, true));
			connectedViews = getIncomingLinksByType(
					Collections.singleton(sv),
					OscfgVisualIDRegistry
							.getType(HWCounterDisable_callbackEditPart.VISUAL_ID));
			incominglinks.addChildren(createNavigatorItems(connectedViews,
					incominglinks, true));
			connectedViews = getIncomingLinksByType(Collections.singleton(sv),
					OscfgVisualIDRegistry
							.getType(HWCounterGet_callbackEditPart.VISUAL_ID));
			incominglinks.addChildren(createNavigatorItems(connectedViews,
					incominglinks, true));
			connectedViews = getIncomingLinksByType(Collections.singleton(sv),
					OscfgVisualIDRegistry
							.getType(HWCounterSet_callbackEditPart.VISUAL_ID));
			incominglinks.addChildren(createNavigatorItems(connectedViews,
					incominglinks, true));
			if (!outgoinglinks.isEmpty()) {
				result.add(outgoinglinks);
			}
			if (!incominglinks.isEmpty()) {
				result.add(incominglinks);
			}
			return result.toArray();
		}

		case InterruptSourceEditPart.VISUAL_ID: {
			LinkedList<OscfgAbstractNavigatorItem> result = new LinkedList<OscfgAbstractNavigatorItem>();
			Node sv = (Node) view;
			OscfgNavigatorGroup outgoinglinks = new OscfgNavigatorGroup(
					Messages.NavigatorGroupName_InterruptSource_3016_outgoinglinks,
					"icons/outgoingLinksNavigatorGroup.gif", parentElement); //$NON-NLS-1$
			Collection<View> connectedViews;
			connectedViews = getOutgoingLinksByType(
					Collections.singleton(sv),
					OscfgVisualIDRegistry
							.getType(InterruptSourceSourceISREditPart.VISUAL_ID));
			outgoinglinks.addChildren(createNavigatorItems(connectedViews,
					outgoinglinks, true));
			if (!outgoinglinks.isEmpty()) {
				result.add(outgoinglinks);
			}
			return result.toArray();
		}

		case CooperativeGroupEditPart.VISUAL_ID: {
			LinkedList<OscfgAbstractNavigatorItem> result = new LinkedList<OscfgAbstractNavigatorItem>();
			Node sv = (Node) view;
			Collection<View> connectedViews;
			connectedViews = getChildrenByType(
					Collections.singleton(sv),
					OscfgVisualIDRegistry
							.getType(CooperativeGroupCooperativeTasksEditPart.VISUAL_ID));
			connectedViews = getChildrenByType(connectedViews,
					OscfgVisualIDRegistry.getType(Task2EditPart.VISUAL_ID));
			result.addAll(createNavigatorItems(connectedViews, parentElement,
					false));
			return result.toArray();
		}

		case Task2EditPart.VISUAL_ID: {
			LinkedList<OscfgAbstractNavigatorItem> result = new LinkedList<OscfgAbstractNavigatorItem>();
			Node sv = (Node) view;
			OscfgNavigatorGroup outgoinglinks = new OscfgNavigatorGroup(
					Messages.NavigatorGroupName_Task_3020_outgoinglinks,
					"icons/outgoingLinksNavigatorGroup.gif", parentElement); //$NON-NLS-1$
			OscfgNavigatorGroup incominglinks = new OscfgNavigatorGroup(
					Messages.NavigatorGroupName_Task_3020_incominglinks,
					"icons/incomingLinksNavigatorGroup.gif", parentElement); //$NON-NLS-1$
			Collection<View> connectedViews;
			connectedViews = getOutgoingLinksByType(Collections.singleton(sv),
					OscfgVisualIDRegistry
							.getType(BaseTaskCollectMessageEditPart.VISUAL_ID));
			outgoinglinks.addChildren(createNavigatorItems(connectedViews,
					outgoinglinks, true));
			connectedViews = getOutgoingLinksByType(Collections.singleton(sv),
					OscfgVisualIDRegistry
							.getType(PosterPostMessageEditPart.VISUAL_ID));
			outgoinglinks.addChildren(createNavigatorItems(connectedViews,
					outgoinglinks, true));
			connectedViews = getOutgoingLinksByType(Collections.singleton(sv),
					OscfgVisualIDRegistry
							.getType(BaseTaskEnterExitMutexEditPart.VISUAL_ID));
			outgoinglinks.addChildren(createNavigatorItems(connectedViews,
					outgoinglinks, true));
			connectedViews = getIncomingLinksByType(Collections.singleton(sv),
					OscfgVisualIDRegistry
							.getType(SWTimerActivatesEditPart.VISUAL_ID));
			incominglinks.addChildren(createNavigatorItems(connectedViews,
					incominglinks, true));
			connectedViews = getIncomingLinksByType(Collections.singleton(sv),
					OscfgVisualIDRegistry
							.getType(MessageNotifiesEditPart.VISUAL_ID));
			incominglinks.addChildren(createNavigatorItems(connectedViews,
					incominglinks, true));
			if (!outgoinglinks.isEmpty()) {
				result.add(outgoinglinks);
			}
			if (!incominglinks.isEmpty()) {
				result.add(incominglinks);
			}
			return result.toArray();
		}

		case BaseTaskCollectMessageEditPart.VISUAL_ID: {
			LinkedList<OscfgAbstractNavigatorItem> result = new LinkedList<OscfgAbstractNavigatorItem>();
			Edge sv = (Edge) view;
			OscfgNavigatorGroup target = new OscfgNavigatorGroup(
					Messages.NavigatorGroupName_BaseTaskCollectMessage_4001_target,
					"icons/linkTargetNavigatorGroup.gif", parentElement); //$NON-NLS-1$
			OscfgNavigatorGroup source = new OscfgNavigatorGroup(
					Messages.NavigatorGroupName_BaseTaskCollectMessage_4001_source,
					"icons/linkSourceNavigatorGroup.gif", parentElement); //$NON-NLS-1$
			Collection<View> connectedViews;
			connectedViews = getLinksTargetByType(Collections.singleton(sv),
					OscfgVisualIDRegistry.getType(MessageEditPart.VISUAL_ID));
			target.addChildren(createNavigatorItems(connectedViews, target,
					true));
			connectedViews = getLinksSourceByType(Collections.singleton(sv),
					OscfgVisualIDRegistry.getType(TaskEditPart.VISUAL_ID));
			source.addChildren(createNavigatorItems(connectedViews, source,
					true));
			connectedViews = getLinksSourceByType(Collections.singleton(sv),
					OscfgVisualIDRegistry.getType(ISREditPart.VISUAL_ID));
			source.addChildren(createNavigatorItems(connectedViews, source,
					true));
			connectedViews = getLinksSourceByType(Collections.singleton(sv),
					OscfgVisualIDRegistry.getType(Task2EditPart.VISUAL_ID));
			source.addChildren(createNavigatorItems(connectedViews, source,
					true));
			if (!target.isEmpty()) {
				result.add(target);
			}
			if (!source.isEmpty()) {
				result.add(source);
			}
			return result.toArray();
		}

		case BaseTaskEnterExitMutexEditPart.VISUAL_ID: {
			LinkedList<OscfgAbstractNavigatorItem> result = new LinkedList<OscfgAbstractNavigatorItem>();
			Edge sv = (Edge) view;
			OscfgNavigatorGroup target = new OscfgNavigatorGroup(
					Messages.NavigatorGroupName_BaseTaskEnterExitMutex_4003_target,
					"icons/linkTargetNavigatorGroup.gif", parentElement); //$NON-NLS-1$
			OscfgNavigatorGroup source = new OscfgNavigatorGroup(
					Messages.NavigatorGroupName_BaseTaskEnterExitMutex_4003_source,
					"icons/linkSourceNavigatorGroup.gif", parentElement); //$NON-NLS-1$
			Collection<View> connectedViews;
			connectedViews = getLinksTargetByType(Collections.singleton(sv),
					OscfgVisualIDRegistry.getType(MutexEditPart.VISUAL_ID));
			target.addChildren(createNavigatorItems(connectedViews, target,
					true));
			connectedViews = getLinksSourceByType(Collections.singleton(sv),
					OscfgVisualIDRegistry.getType(TaskEditPart.VISUAL_ID));
			source.addChildren(createNavigatorItems(connectedViews, source,
					true));
			connectedViews = getLinksSourceByType(Collections.singleton(sv),
					OscfgVisualIDRegistry.getType(ISREditPart.VISUAL_ID));
			source.addChildren(createNavigatorItems(connectedViews, source,
					true));
			connectedViews = getLinksSourceByType(Collections.singleton(sv),
					OscfgVisualIDRegistry.getType(Task2EditPart.VISUAL_ID));
			source.addChildren(createNavigatorItems(connectedViews, source,
					true));
			if (!target.isEmpty()) {
				result.add(target);
			}
			if (!source.isEmpty()) {
				result.add(source);
			}
			return result.toArray();
		}

		case SWTimerActivatesEditPart.VISUAL_ID: {
			LinkedList<OscfgAbstractNavigatorItem> result = new LinkedList<OscfgAbstractNavigatorItem>();
			Edge sv = (Edge) view;
			OscfgNavigatorGroup target = new OscfgNavigatorGroup(
					Messages.NavigatorGroupName_SWTimerActivates_4004_target,
					"icons/linkTargetNavigatorGroup.gif", parentElement); //$NON-NLS-1$
			OscfgNavigatorGroup source = new OscfgNavigatorGroup(
					Messages.NavigatorGroupName_SWTimerActivates_4004_source,
					"icons/linkSourceNavigatorGroup.gif", parentElement); //$NON-NLS-1$
			Collection<View> connectedViews;
			connectedViews = getLinksTargetByType(Collections.singleton(sv),
					OscfgVisualIDRegistry.getType(TaskEditPart.VISUAL_ID));
			target.addChildren(createNavigatorItems(connectedViews, target,
					true));
			connectedViews = getLinksTargetByType(Collections.singleton(sv),
					OscfgVisualIDRegistry.getType(Task2EditPart.VISUAL_ID));
			target.addChildren(createNavigatorItems(connectedViews, target,
					true));
			connectedViews = getLinksSourceByType(Collections.singleton(sv),
					OscfgVisualIDRegistry.getType(SWTimerEditPart.VISUAL_ID));
			source.addChildren(createNavigatorItems(connectedViews, source,
					true));
			if (!target.isEmpty()) {
				result.add(target);
			}
			if (!source.isEmpty()) {
				result.add(source);
			}
			return result.toArray();
		}

		case SWTimerTimer_callbackEditPart.VISUAL_ID: {
			LinkedList<OscfgAbstractNavigatorItem> result = new LinkedList<OscfgAbstractNavigatorItem>();
			Edge sv = (Edge) view;
			OscfgNavigatorGroup target = new OscfgNavigatorGroup(
					Messages.NavigatorGroupName_SWTimerTimer_callback_4005_target,
					"icons/linkTargetNavigatorGroup.gif", parentElement); //$NON-NLS-1$
			OscfgNavigatorGroup source = new OscfgNavigatorGroup(
					Messages.NavigatorGroupName_SWTimerTimer_callback_4005_source,
					"icons/linkSourceNavigatorGroup.gif", parentElement); //$NON-NLS-1$
			Collection<View> connectedViews;
			connectedViews = getLinksTargetByType(Collections.singleton(sv),
					OscfgVisualIDRegistry
							.getType(CallbackFunctionEditPart.VISUAL_ID));
			target.addChildren(createNavigatorItems(connectedViews, target,
					true));
			connectedViews = getLinksSourceByType(Collections.singleton(sv),
					OscfgVisualIDRegistry.getType(SWTimerEditPart.VISUAL_ID));
			source.addChildren(createNavigatorItems(connectedViews, source,
					true));
			if (!target.isEmpty()) {
				result.add(target);
			}
			if (!source.isEmpty()) {
				result.add(source);
			}
			return result.toArray();
		}

		case MessageNotifiesEditPart.VISUAL_ID: {
			LinkedList<OscfgAbstractNavigatorItem> result = new LinkedList<OscfgAbstractNavigatorItem>();
			Edge sv = (Edge) view;
			OscfgNavigatorGroup target = new OscfgNavigatorGroup(
					Messages.NavigatorGroupName_MessageNotifies_4006_target,
					"icons/linkTargetNavigatorGroup.gif", parentElement); //$NON-NLS-1$
			OscfgNavigatorGroup source = new OscfgNavigatorGroup(
					Messages.NavigatorGroupName_MessageNotifies_4006_source,
					"icons/linkSourceNavigatorGroup.gif", parentElement); //$NON-NLS-1$
			Collection<View> connectedViews;
			connectedViews = getLinksTargetByType(Collections.singleton(sv),
					OscfgVisualIDRegistry.getType(TaskEditPart.VISUAL_ID));
			target.addChildren(createNavigatorItems(connectedViews, target,
					true));
			connectedViews = getLinksTargetByType(Collections.singleton(sv),
					OscfgVisualIDRegistry.getType(Task2EditPart.VISUAL_ID));
			target.addChildren(createNavigatorItems(connectedViews, target,
					true));
			connectedViews = getLinksSourceByType(Collections.singleton(sv),
					OscfgVisualIDRegistry.getType(MessageEditPart.VISUAL_ID));
			source.addChildren(createNavigatorItems(connectedViews, source,
					true));
			if (!target.isEmpty()) {
				result.add(target);
			}
			if (!source.isEmpty()) {
				result.add(source);
			}
			return result.toArray();
		}

		case HWCounterEnable_callbackEditPart.VISUAL_ID: {
			LinkedList<OscfgAbstractNavigatorItem> result = new LinkedList<OscfgAbstractNavigatorItem>();
			Edge sv = (Edge) view;
			OscfgNavigatorGroup target = new OscfgNavigatorGroup(
					Messages.NavigatorGroupName_HWCounterEnable_callback_4007_target,
					"icons/linkTargetNavigatorGroup.gif", parentElement); //$NON-NLS-1$
			OscfgNavigatorGroup source = new OscfgNavigatorGroup(
					Messages.NavigatorGroupName_HWCounterEnable_callback_4007_source,
					"icons/linkSourceNavigatorGroup.gif", parentElement); //$NON-NLS-1$
			Collection<View> connectedViews;
			connectedViews = getLinksTargetByType(Collections.singleton(sv),
					OscfgVisualIDRegistry
							.getType(CallbackFunctionEditPart.VISUAL_ID));
			target.addChildren(createNavigatorItems(connectedViews, target,
					true));
			connectedViews = getLinksSourceByType(Collections.singleton(sv),
					OscfgVisualIDRegistry.getType(HWCounterEditPart.VISUAL_ID));
			source.addChildren(createNavigatorItems(connectedViews, source,
					true));
			if (!target.isEmpty()) {
				result.add(target);
			}
			if (!source.isEmpty()) {
				result.add(source);
			}
			return result.toArray();
		}

		case HWCounterDisable_callbackEditPart.VISUAL_ID: {
			LinkedList<OscfgAbstractNavigatorItem> result = new LinkedList<OscfgAbstractNavigatorItem>();
			Edge sv = (Edge) view;
			OscfgNavigatorGroup target = new OscfgNavigatorGroup(
					Messages.NavigatorGroupName_HWCounterDisable_callback_4008_target,
					"icons/linkTargetNavigatorGroup.gif", parentElement); //$NON-NLS-1$
			OscfgNavigatorGroup source = new OscfgNavigatorGroup(
					Messages.NavigatorGroupName_HWCounterDisable_callback_4008_source,
					"icons/linkSourceNavigatorGroup.gif", parentElement); //$NON-NLS-1$
			Collection<View> connectedViews;
			connectedViews = getLinksTargetByType(Collections.singleton(sv),
					OscfgVisualIDRegistry
							.getType(CallbackFunctionEditPart.VISUAL_ID));
			target.addChildren(createNavigatorItems(connectedViews, target,
					true));
			connectedViews = getLinksSourceByType(Collections.singleton(sv),
					OscfgVisualIDRegistry.getType(HWCounterEditPart.VISUAL_ID));
			source.addChildren(createNavigatorItems(connectedViews, source,
					true));
			if (!target.isEmpty()) {
				result.add(target);
			}
			if (!source.isEmpty()) {
				result.add(source);
			}
			return result.toArray();
		}

		case HWCounterGet_callbackEditPart.VISUAL_ID: {
			LinkedList<OscfgAbstractNavigatorItem> result = new LinkedList<OscfgAbstractNavigatorItem>();
			Edge sv = (Edge) view;
			OscfgNavigatorGroup target = new OscfgNavigatorGroup(
					Messages.NavigatorGroupName_HWCounterGet_callback_4009_target,
					"icons/linkTargetNavigatorGroup.gif", parentElement); //$NON-NLS-1$
			OscfgNavigatorGroup source = new OscfgNavigatorGroup(
					Messages.NavigatorGroupName_HWCounterGet_callback_4009_source,
					"icons/linkSourceNavigatorGroup.gif", parentElement); //$NON-NLS-1$
			Collection<View> connectedViews;
			connectedViews = getLinksTargetByType(Collections.singleton(sv),
					OscfgVisualIDRegistry
							.getType(CallbackFunctionEditPart.VISUAL_ID));
			target.addChildren(createNavigatorItems(connectedViews, target,
					true));
			connectedViews = getLinksSourceByType(Collections.singleton(sv),
					OscfgVisualIDRegistry.getType(HWCounterEditPart.VISUAL_ID));
			source.addChildren(createNavigatorItems(connectedViews, source,
					true));
			if (!target.isEmpty()) {
				result.add(target);
			}
			if (!source.isEmpty()) {
				result.add(source);
			}
			return result.toArray();
		}

		case HWCounterSet_callbackEditPart.VISUAL_ID: {
			LinkedList<OscfgAbstractNavigatorItem> result = new LinkedList<OscfgAbstractNavigatorItem>();
			Edge sv = (Edge) view;
			OscfgNavigatorGroup target = new OscfgNavigatorGroup(
					Messages.NavigatorGroupName_HWCounterSet_callback_4010_target,
					"icons/linkTargetNavigatorGroup.gif", parentElement); //$NON-NLS-1$
			OscfgNavigatorGroup source = new OscfgNavigatorGroup(
					Messages.NavigatorGroupName_HWCounterSet_callback_4010_source,
					"icons/linkSourceNavigatorGroup.gif", parentElement); //$NON-NLS-1$
			Collection<View> connectedViews;
			connectedViews = getLinksTargetByType(Collections.singleton(sv),
					OscfgVisualIDRegistry
							.getType(CallbackFunctionEditPart.VISUAL_ID));
			target.addChildren(createNavigatorItems(connectedViews, target,
					true));
			connectedViews = getLinksSourceByType(Collections.singleton(sv),
					OscfgVisualIDRegistry.getType(HWCounterEditPart.VISUAL_ID));
			source.addChildren(createNavigatorItems(connectedViews, source,
					true));
			if (!target.isEmpty()) {
				result.add(target);
			}
			if (!source.isEmpty()) {
				result.add(source);
			}
			return result.toArray();
		}

		case InterruptSourceSourceISREditPart.VISUAL_ID: {
			LinkedList<OscfgAbstractNavigatorItem> result = new LinkedList<OscfgAbstractNavigatorItem>();
			Edge sv = (Edge) view;
			OscfgNavigatorGroup target = new OscfgNavigatorGroup(
					Messages.NavigatorGroupName_InterruptSourceSourceISR_4011_target,
					"icons/linkTargetNavigatorGroup.gif", parentElement); //$NON-NLS-1$
			OscfgNavigatorGroup source = new OscfgNavigatorGroup(
					Messages.NavigatorGroupName_InterruptSourceSourceISR_4011_source,
					"icons/linkSourceNavigatorGroup.gif", parentElement); //$NON-NLS-1$
			Collection<View> connectedViews;
			connectedViews = getLinksTargetByType(Collections.singleton(sv),
					OscfgVisualIDRegistry.getType(ISREditPart.VISUAL_ID));
			target.addChildren(createNavigatorItems(connectedViews, target,
					true));
			connectedViews = getLinksSourceByType(Collections.singleton(sv),
					OscfgVisualIDRegistry
							.getType(InterruptSourceEditPart.VISUAL_ID));
			source.addChildren(createNavigatorItems(connectedViews, source,
					true));
			if (!target.isEmpty()) {
				result.add(target);
			}
			if (!source.isEmpty()) {
				result.add(source);
			}
			return result.toArray();
		}

		case PosterPostMessageEditPart.VISUAL_ID: {
			LinkedList<OscfgAbstractNavigatorItem> result = new LinkedList<OscfgAbstractNavigatorItem>();
			Edge sv = (Edge) view;
			OscfgNavigatorGroup target = new OscfgNavigatorGroup(
					Messages.NavigatorGroupName_PosterPostMessage_4012_target,
					"icons/linkTargetNavigatorGroup.gif", parentElement); //$NON-NLS-1$
			OscfgNavigatorGroup source = new OscfgNavigatorGroup(
					Messages.NavigatorGroupName_PosterPostMessage_4012_source,
					"icons/linkSourceNavigatorGroup.gif", parentElement); //$NON-NLS-1$
			Collection<View> connectedViews;
			connectedViews = getLinksTargetByType(Collections.singleton(sv),
					OscfgVisualIDRegistry.getType(MessageEditPart.VISUAL_ID));
			target.addChildren(createNavigatorItems(connectedViews, target,
					true));
			connectedViews = getLinksSourceByType(Collections.singleton(sv),
					OscfgVisualIDRegistry.getType(TaskEditPart.VISUAL_ID));
			source.addChildren(createNavigatorItems(connectedViews, source,
					true));
			connectedViews = getLinksSourceByType(Collections.singleton(sv),
					OscfgVisualIDRegistry.getType(ISREditPart.VISUAL_ID));
			source.addChildren(createNavigatorItems(connectedViews, source,
					true));
			connectedViews = getLinksSourceByType(Collections.singleton(sv),
					OscfgVisualIDRegistry
							.getType(CallbackFunctionEditPart.VISUAL_ID));
			source.addChildren(createNavigatorItems(connectedViews, source,
					true));
			connectedViews = getLinksSourceByType(Collections.singleton(sv),
					OscfgVisualIDRegistry.getType(Task2EditPart.VISUAL_ID));
			source.addChildren(createNavigatorItems(connectedViews, source,
					true));
			if (!target.isEmpty()) {
				result.add(target);
			}
			if (!source.isEmpty()) {
				result.add(source);
			}
			return result.toArray();
		}
		}
		return EMPTY_ARRAY;
	}

	/**
	 * @generated
	 */
	private Collection<View> getLinksSourceByType(Collection<Edge> edges,
			String type) {
		LinkedList<View> result = new LinkedList<View>();
		for (Edge nextEdge : edges) {
			View nextEdgeSource = nextEdge.getSource();
			if (type.equals(nextEdgeSource.getType())
					&& isOwnView(nextEdgeSource)) {
				result.add(nextEdgeSource);
			}
		}
		return result;
	}

	/**
	 * @generated
	 */
	private Collection<View> getLinksTargetByType(Collection<Edge> edges,
			String type) {
		LinkedList<View> result = new LinkedList<View>();
		for (Edge nextEdge : edges) {
			View nextEdgeTarget = nextEdge.getTarget();
			if (type.equals(nextEdgeTarget.getType())
					&& isOwnView(nextEdgeTarget)) {
				result.add(nextEdgeTarget);
			}
		}
		return result;
	}

	/**
	 * @generated
	 */
	private Collection<View> getOutgoingLinksByType(
			Collection<? extends View> nodes, String type) {
		LinkedList<View> result = new LinkedList<View>();
		for (View nextNode : nodes) {
			result.addAll(selectViewsByType(nextNode.getSourceEdges(), type));
		}
		return result;
	}

	/**
	 * @generated
	 */
	private Collection<View> getIncomingLinksByType(
			Collection<? extends View> nodes, String type) {
		LinkedList<View> result = new LinkedList<View>();
		for (View nextNode : nodes) {
			result.addAll(selectViewsByType(nextNode.getTargetEdges(), type));
		}
		return result;
	}

	/**
	 * @generated
	 */
	private Collection<View> getChildrenByType(
			Collection<? extends View> nodes, String type) {
		LinkedList<View> result = new LinkedList<View>();
		for (View nextNode : nodes) {
			result.addAll(selectViewsByType(nextNode.getChildren(), type));
		}
		return result;
	}

	/**
	 * @generated
	 */
	private Collection<View> getDiagramLinksByType(
			Collection<Diagram> diagrams, String type) {
		ArrayList<View> result = new ArrayList<View>();
		for (Diagram nextDiagram : diagrams) {
			result.addAll(selectViewsByType(nextDiagram.getEdges(), type));
		}
		return result;
	}

	/**
	 * @generated
	 */
	private Collection<View> selectViewsByType(Collection<View> views,
			String type) {
		ArrayList<View> result = new ArrayList<View>();
		for (View nextView : views) {
			if (type.equals(nextView.getType()) && isOwnView(nextView)) {
				result.add(nextView);
			}
		}
		return result;
	}

	/**
	 * @generated
	 */
	private boolean isOwnView(View view) {
		return ConfigurationEditPart.MODEL_ID.equals(OscfgVisualIDRegistry
				.getModelID(view));
	}

	/**
	 * @generated
	 */
	private Collection<OscfgNavigatorItem> createNavigatorItems(
			Collection<View> views, Object parent, boolean isLeafs) {
		ArrayList<OscfgNavigatorItem> result = new ArrayList<OscfgNavigatorItem>(
				views.size());
		for (View nextView : views) {
			result.add(new OscfgNavigatorItem(nextView, parent, isLeafs));
		}
		return result;
	}

	/**
	 * @generated
	 */
	public Object getParent(Object element) {
		if (element instanceof OscfgAbstractNavigatorItem) {
			OscfgAbstractNavigatorItem abstractNavigatorItem = (OscfgAbstractNavigatorItem) element;
			return abstractNavigatorItem.getParent();
		}
		return null;
	}

	/**
	 * @generated
	 */
	public boolean hasChildren(Object element) {
		return element instanceof IFile || getChildren(element).length > 0;
	}

}
