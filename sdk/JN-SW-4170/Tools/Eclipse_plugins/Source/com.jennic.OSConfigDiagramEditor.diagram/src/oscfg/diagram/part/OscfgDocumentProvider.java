package oscfg.diagram.part;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.URL;
import java.util.ArrayList;
import java.util.Collection;
import java.util.Collections;
import java.util.HashMap;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;

import org.eclipse.core.commands.ExecutionException;
import org.eclipse.core.resources.IFile;
import org.eclipse.core.resources.IResource;
import org.eclipse.core.resources.IResourceStatus;
import org.eclipse.core.resources.IStorage;
import org.eclipse.core.resources.ResourcesPlugin;
import org.eclipse.core.runtime.CoreException;
import org.eclipse.core.runtime.FileLocator;
import org.eclipse.core.runtime.IAdaptable;
import org.eclipse.core.runtime.IProgressMonitor;
import org.eclipse.core.runtime.IStatus;
import org.eclipse.core.runtime.Path;
import org.eclipse.core.runtime.Platform;
import org.eclipse.core.runtime.Status;
import org.eclipse.core.runtime.jobs.ISchedulingRule;
import org.eclipse.core.runtime.jobs.MultiRule;
import org.eclipse.emf.common.notify.Adapter;
import org.eclipse.emf.common.notify.Notification;
import org.eclipse.emf.common.notify.Notifier;
import org.eclipse.emf.common.ui.URIEditorInput;
import org.eclipse.emf.common.util.URI;
import org.eclipse.emf.ecore.EObject;
import org.eclipse.emf.ecore.resource.Resource;
import org.eclipse.emf.ecore.resource.ResourceSet;
import org.eclipse.emf.ecore.util.EContentAdapter;
import org.eclipse.emf.ecore.util.EcoreUtil;
import org.eclipse.emf.transaction.NotificationFilter;
import org.eclipse.emf.transaction.TransactionalEditingDomain;
import org.eclipse.emf.workspace.util.WorkspaceSynchronizer;
import org.eclipse.gmf.runtime.common.core.command.CommandResult;
import org.eclipse.gmf.runtime.diagram.core.DiagramEditingDomainFactory;
import org.eclipse.gmf.runtime.diagram.ui.resources.editor.document.AbstractDocumentProvider;
import org.eclipse.gmf.runtime.diagram.ui.resources.editor.document.DiagramDocument;
import org.eclipse.gmf.runtime.diagram.ui.resources.editor.document.IDiagramDocument;
import org.eclipse.gmf.runtime.diagram.ui.resources.editor.document.IDiagramDocumentProvider;
import org.eclipse.gmf.runtime.diagram.ui.resources.editor.document.IDocument;
import org.eclipse.gmf.runtime.diagram.ui.resources.editor.internal.EditorStatusCodes;
import org.eclipse.gmf.runtime.diagram.ui.resources.editor.internal.util.DiagramIOUtil;
import org.eclipse.gmf.runtime.emf.commands.core.command.AbstractTransactionalCommand;
import org.eclipse.gmf.runtime.emf.core.resources.GMFResourceFactory;
import org.eclipse.gmf.runtime.notation.Diagram;
import org.eclipse.jface.operation.IRunnableContext;
import org.eclipse.osgi.util.NLS;
import org.eclipse.swt.widgets.Display;
import org.eclipse.ui.IEditorInput;
import org.eclipse.ui.part.FileEditorInput;

/**
 * @generated
 */
public class OscfgDocumentProvider extends AbstractDocumentProvider implements
		IDiagramDocumentProvider {

	/**
	 * @generated
	 */
	protected ElementInfo createElementInfo(Object element)
			throws CoreException {
		if (false == element instanceof FileEditorInput
				&& false == element instanceof URIEditorInput) {
			throw new CoreException(
					new Status(
							IStatus.ERROR,
							OscfgDiagramEditorPlugin.ID,
							0,
							NLS.bind(
									Messages.OscfgDocumentProvider_IncorrectInputError,
									new Object[] {
											element,
											"org.eclipse.ui.part.FileEditorInput", "org.eclipse.emf.common.ui.URIEditorInput" }), //$NON-NLS-1$ //$NON-NLS-2$ 
							null));
		}
		IEditorInput editorInput = (IEditorInput) element;
		IDiagramDocument document = (IDiagramDocument) createDocument(editorInput);

		ResourceSetInfo info = new ResourceSetInfo(document, editorInput);
		info.setModificationStamp(computeModificationStamp(info));
		info.fStatus = null;
		return info;
	}

	/**
	 * @generated
	 */
	protected IDocument createDocument(Object element) throws CoreException {
		if (false == element instanceof FileEditorInput
				&& false == element instanceof URIEditorInput) {
			throw new CoreException(
					new Status(
							IStatus.ERROR,
							OscfgDiagramEditorPlugin.ID,
							0,
							NLS.bind(
									Messages.OscfgDocumentProvider_IncorrectInputError,
									new Object[] {
											element,
											"org.eclipse.ui.part.FileEditorInput", "org.eclipse.emf.common.ui.URIEditorInput" }), //$NON-NLS-1$ //$NON-NLS-2$ 
							null));
		}
		IDocument document = createEmptyDocument();
		setDocumentContent(document, (IEditorInput) element);
		setupDocument(element, document);
		return document;
	}

	/**
	 * Sets up the given document as it would be provided for the given element. The
	 * content of the document is not changed. This default implementation is empty.
	 * Subclasses may reimplement.
	 * 
	 * @param element the blue-print element
	 * @param document the document to set up
	 * @generated
	 */
	protected void setupDocument(Object element, IDocument document) {
		// for subclasses
	}

	/**
	 * @generated
	 */
	private long computeModificationStamp(ResourceSetInfo info) {
		int result = 0;
		for (Iterator<Resource> it = info.getLoadedResourcesIterator(); it
				.hasNext();) {
			Resource nextResource = it.next();
			IFile file = WorkspaceSynchronizer.getFile(nextResource);
			if (file != null) {
				if (file.getLocation() != null) {
					result += file.getLocation().toFile().lastModified();
				} else {
					result += file.getModificationStamp();
				}
			}
		}
		return result;
	}

	/**
	 * @generated
	 */
	protected IDocument createEmptyDocument() {
		DiagramDocument document = new DiagramDocument();
		document.setEditingDomain(createEditingDomain());
		return document;
	}

	/**
	 * @generated
	 */
	private TransactionalEditingDomain createEditingDomain() {
		TransactionalEditingDomain editingDomain = DiagramEditingDomainFactory
				.getInstance().createEditingDomain();
		editingDomain
				.setID("com.jennic.OSConfigDiagramEditor.diagram.EditingDomain"); //$NON-NLS-1$
		final NotificationFilter diagramResourceModifiedFilter = NotificationFilter
				.createNotifierFilter(editingDomain.getResourceSet())
				.and(NotificationFilter.createEventTypeFilter(Notification.ADD))
				.and(NotificationFilter.createFeatureFilter(ResourceSet.class,
						ResourceSet.RESOURCE_SET__RESOURCES));
		editingDomain.getResourceSet().eAdapters().add(new Adapter() {

			private Notifier myTarger;

			public Notifier getTarget() {
				return myTarger;
			}

			public boolean isAdapterForType(Object type) {
				return false;
			}

			public void notifyChanged(Notification notification) {
				if (diagramResourceModifiedFilter.matches(notification)) {
					Object value = notification.getNewValue();
					if (value instanceof Resource) {
						((Resource) value).setTrackingModification(true);
					}
				}
			}

			public void setTarget(Notifier newTarget) {
				myTarger = newTarget;
			}

		});

		return editingDomain;
	}

	/**
	 * @generated NOT
	 */
	protected void setDocumentContent(IDocument document, IEditorInput element)
			throws CoreException {
		IDiagramDocument diagramDocument = (IDiagramDocument) document;
		TransactionalEditingDomain domain = diagramDocument.getEditingDomain();
		if (element instanceof FileEditorInput) {
			IStorage storage = ((FileEditorInput) element).getStorage();

			try {
				URL url = FileLocator.resolve(FileLocator.find(Platform
						.getBundle("com.jennic.OSConfigDiagramEditor.diagram"),
						new Path("OSDiagFix/OSDIagFix.exe"),
						Collections.EMPTY_MAP));
				url = org.eclipse.core.runtime.FileLocator.toFileURL(url);

				String[] cmd = { url.getPath(),
						"-f\"" + ((FileEditorInput) element).getPath() + "\"" };
				Process p = Runtime.getRuntime().exec(cmd);

				//				BufferedReader bri = new BufferedReader(new InputStreamReader(p.getInputStream()));
				//				BufferedReader bre = new BufferedReader(new InputStreamReader(p.getErrorStream()));
				//				String line;
				//				while ((line = bri.readLine()) != null) {
				//				  System.out.println(line);
				//				}
				//				bri.close();
				//				while ((line = bre.readLine()) != null) {
				//				  System.out.println(line);
				//				}
				//				bre.close();

				p.waitFor();
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}

			Diagram diagram = DiagramIOUtil.load(domain, storage, true,
					getProgressMonitor());
			document.setContent(diagram);
		} else if (element instanceof URIEditorInput) {
			URI uri = ((URIEditorInput) element).getURI();
			Resource resource = null;
			try {
				resource = domain.getResourceSet().getResource(
						uri.trimFragment(), false);
				if (resource == null) {
					resource = domain.getResourceSet().createResource(
							uri.trimFragment());
				}
				if (!resource.isLoaded()) {
					try {
						Map options = new HashMap(
								GMFResourceFactory.getDefaultLoadOptions());
						// @see 171060 
						// options.put(org.eclipse.emf.ecore.xmi.XMLResource.OPTION_RECORD_UNKNOWN_FEATURE, Boolean.TRUE);
						resource.load(options);
					} catch (IOException e) {
						resource.unload();
						throw e;
					}
				}
				if (uri.fragment() != null) {
					EObject rootElement = resource.getEObject(uri.fragment());
					if (rootElement instanceof Diagram) {
						document.setContent((Diagram) rootElement);
						return;
					}
				} else {
					for (Iterator it = resource.getContents().iterator(); it
							.hasNext();) {
						Object rootElement = it.next();
						if (rootElement instanceof Diagram) {
							document.setContent((Diagram) rootElement);
							return;
						}
					}
				}
				throw new RuntimeException(
						Messages.OscfgDocumentProvider_NoDiagramInResourceError);
			} catch (Exception e) {
				CoreException thrownExcp = null;
				if (e instanceof CoreException) {
					thrownExcp = (CoreException) e;
				} else {
					String msg = e.getLocalizedMessage();
					thrownExcp = new CoreException(
							new Status(
									IStatus.ERROR,
									OscfgDiagramEditorPlugin.ID,
									0,
									msg != null ? msg
											: Messages.OscfgDocumentProvider_DiagramLoadingError,
									e));
				}
				throw thrownExcp;
			}
		} else {
			throw new CoreException(
					new Status(
							IStatus.ERROR,
							OscfgDiagramEditorPlugin.ID,
							0,
							NLS.bind(
									Messages.OscfgDocumentProvider_IncorrectInputError,
									new Object[] {
											element,
											"org.eclipse.ui.part.FileEditorInput", "org.eclipse.emf.common.ui.URIEditorInput" }), //$NON-NLS-1$ //$NON-NLS-2$ 
							null));
		}
	}

	/**
	 * @generated
	 */
	public long getModificationStamp(Object element) {
		ResourceSetInfo info = getResourceSetInfo(element);
		if (info != null) {
			return computeModificationStamp(info);
		}
		return super.getModificationStamp(element);
	}

	/**
	 * @generated
	 */
	public boolean isDeleted(Object element) {
		IDiagramDocument document = getDiagramDocument(element);
		if (document != null) {
			Resource diagramResource = document.getDiagram().eResource();
			if (diagramResource != null) {
				IFile file = WorkspaceSynchronizer.getFile(diagramResource);
				return file == null || file.getLocation() == null
						|| !file.getLocation().toFile().exists();
			}
		}
		return super.isDeleted(element);
	}

	/**
	 * @generated
	 */
	public ResourceSetInfo getResourceSetInfo(Object editorInput) {
		return (ResourceSetInfo) super.getElementInfo(editorInput);
	}

	/**
	 * @generated
	 */
	protected void disposeElementInfo(Object element, ElementInfo info) {
		if (info instanceof ResourceSetInfo) {
			ResourceSetInfo resourceSetInfo = (ResourceSetInfo) info;
			resourceSetInfo.dispose();
		}
		super.disposeElementInfo(element, info);
	}

	/**
	 * @generated
	 */
	protected void doValidateState(Object element, Object computationContext)
			throws CoreException {
		ResourceSetInfo info = getResourceSetInfo(element);
		if (info != null) {
			LinkedList<IFile> files2Validate = new LinkedList<IFile>();
			for (Iterator<Resource> it = info.getLoadedResourcesIterator(); it
					.hasNext();) {
				Resource nextResource = it.next();
				IFile file = WorkspaceSynchronizer.getFile(nextResource);
				if (file != null && file.isReadOnly()) {
					files2Validate.add(file);
				}
			}
			ResourcesPlugin.getWorkspace().validateEdit(
					(IFile[]) files2Validate.toArray(new IFile[files2Validate
							.size()]), computationContext);
		}

		super.doValidateState(element, computationContext);
	}

	/**
	 * @generated
	 */
	public boolean isReadOnly(Object element) {
		ResourceSetInfo info = getResourceSetInfo(element);
		if (info != null) {
			if (info.isUpdateCache()) {
				try {
					updateCache(element);
				} catch (CoreException ex) {
					OscfgDiagramEditorPlugin.getInstance().logError(
							Messages.OscfgDocumentProvider_isModifiable, ex);
					// Error message to log was initially taken from org.eclipse.gmf.runtime.diagram.ui.resources.editor.ide.internal.l10n.EditorMessages.StorageDocumentProvider_isModifiable
				}
			}
			return info.isReadOnly();
		}
		return super.isReadOnly(element);
	}

	/**
	 * @generated
	 */
	public boolean isModifiable(Object element) {
		if (!isStateValidated(element)) {
			if (element instanceof FileEditorInput
					|| element instanceof URIEditorInput) {
				return true;
			}
		}
		ResourceSetInfo info = getResourceSetInfo(element);
		if (info != null) {
			if (info.isUpdateCache()) {
				try {
					updateCache(element);
				} catch (CoreException ex) {
					OscfgDiagramEditorPlugin.getInstance().logError(
							Messages.OscfgDocumentProvider_isModifiable, ex);
					// Error message to log was initially taken from org.eclipse.gmf.runtime.diagram.ui.resources.editor.ide.internal.l10n.EditorMessages.StorageDocumentProvider_isModifiable
				}
			}
			return info.isModifiable();
		}
		return super.isModifiable(element);
	}

	/**
	 * @generated
	 */
	protected void updateCache(Object element) throws CoreException {
		ResourceSetInfo info = getResourceSetInfo(element);
		if (info != null) {
			for (Iterator<Resource> it = info.getLoadedResourcesIterator(); it
					.hasNext();) {
				Resource nextResource = it.next();
				IFile file = WorkspaceSynchronizer.getFile(nextResource);
				if (file != null && file.isReadOnly()) {
					info.setReadOnly(true);
					info.setModifiable(false);
					return;
				}
			}
			info.setReadOnly(false);
			info.setModifiable(true);
			return;
		}
	}

	/**
	 * @generated
	 */
	protected void doUpdateStateCache(Object element) throws CoreException {
		ResourceSetInfo info = getResourceSetInfo(element);
		if (info != null) {
			info.setUpdateCache(true);
		}
		super.doUpdateStateCache(element);
	}

	/**
	 * @generated
	 */
	public boolean isSynchronized(Object element) {
		ResourceSetInfo info = getResourceSetInfo(element);
		if (info != null) {
			return info.isSynchronized();
		}
		return super.isSynchronized(element);
	}

	/**
	 * @generated
	 */
	protected ISchedulingRule getResetRule(Object element) {
		ResourceSetInfo info = getResourceSetInfo(element);
		if (info != null) {
			LinkedList<ISchedulingRule> rules = new LinkedList<ISchedulingRule>();
			for (Iterator<Resource> it = info.getLoadedResourcesIterator(); it
					.hasNext();) {
				Resource nextResource = it.next();
				IFile file = WorkspaceSynchronizer.getFile(nextResource);
				if (file != null) {
					rules.add(ResourcesPlugin.getWorkspace().getRuleFactory()
							.modifyRule(file));
				}
			}
			return new MultiRule(
					(ISchedulingRule[]) rules.toArray(new ISchedulingRule[rules
							.size()]));
		}
		return null;
	}

	/**
	 * @generated
	 */
	protected ISchedulingRule getSaveRule(Object element) {
		ResourceSetInfo info = getResourceSetInfo(element);
		if (info != null) {
			LinkedList<ISchedulingRule> rules = new LinkedList<ISchedulingRule>();
			for (Iterator<Resource> it = info.getLoadedResourcesIterator(); it
					.hasNext();) {
				Resource nextResource = it.next();
				IFile file = WorkspaceSynchronizer.getFile(nextResource);
				if (file != null) {
					rules.add(computeSchedulingRule(file));
				}
			}
			return new MultiRule(
					(ISchedulingRule[]) rules.toArray(new ISchedulingRule[rules
							.size()]));
		}
		return null;
	}

	/**
	 * @generated
	 */
	protected ISchedulingRule getSynchronizeRule(Object element) {
		ResourceSetInfo info = getResourceSetInfo(element);
		if (info != null) {
			LinkedList<ISchedulingRule> rules = new LinkedList<ISchedulingRule>();
			for (Iterator<Resource> it = info.getLoadedResourcesIterator(); it
					.hasNext();) {
				Resource nextResource = it.next();
				IFile file = WorkspaceSynchronizer.getFile(nextResource);
				if (file != null) {
					rules.add(ResourcesPlugin.getWorkspace().getRuleFactory()
							.refreshRule(file));
				}
			}
			return new MultiRule(
					(ISchedulingRule[]) rules.toArray(new ISchedulingRule[rules
							.size()]));
		}
		return null;
	}

	/**
	 * @generated
	 */
	protected ISchedulingRule getValidateStateRule(Object element) {
		ResourceSetInfo info = getResourceSetInfo(element);
		if (info != null) {
			LinkedList<ISchedulingRule> files = new LinkedList<ISchedulingRule>();
			for (Iterator<Resource> it = info.getLoadedResourcesIterator(); it
					.hasNext();) {
				Resource nextResource = it.next();
				IFile file = WorkspaceSynchronizer.getFile(nextResource);
				if (file != null) {
					files.add(file);
				}
			}
			return ResourcesPlugin
					.getWorkspace()
					.getRuleFactory()
					.validateEditRule(
							(IFile[]) files.toArray(new IFile[files.size()]));
		}
		return null;
	}

	/**
	 * @generated
	 */
	private ISchedulingRule computeSchedulingRule(IResource toCreateOrModify) {
		if (toCreateOrModify.exists())
			return ResourcesPlugin.getWorkspace().getRuleFactory()
					.modifyRule(toCreateOrModify);

		IResource parent = toCreateOrModify;
		do {
			/*
			 * XXX This is a workaround for
			 * https://bugs.eclipse.org/bugs/show_bug.cgi?id=67601
			 * IResourceRuleFactory.createRule should iterate the hierarchy
			 * itself.
			 */
			toCreateOrModify = parent;
			parent = toCreateOrModify.getParent();
		} while (parent != null && !parent.exists());

		return ResourcesPlugin.getWorkspace().getRuleFactory()
				.createRule(toCreateOrModify);
	}

	/**
	 * @generated
	 */
	protected void doSynchronize(Object element, IProgressMonitor monitor)
			throws CoreException {
		ResourceSetInfo info = getResourceSetInfo(element);
		if (info != null) {
			for (Iterator<Resource> it = info.getLoadedResourcesIterator(); it
					.hasNext();) {
				Resource nextResource = it.next();
				handleElementChanged(info, nextResource, monitor);
			}
			return;
		}
		super.doSynchronize(element, monitor);
	}

	/**
	 * @generated
	 */
	protected void doSaveDocument(IProgressMonitor monitor, Object element,
			IDocument document, boolean overwrite) throws CoreException {
		ResourceSetInfo info = getResourceSetInfo(element);
		if (info != null) {
			if (!overwrite && !info.isSynchronized()) {
				throw new CoreException(
						new Status(
								IStatus.ERROR,
								OscfgDiagramEditorPlugin.ID,
								IResourceStatus.OUT_OF_SYNC_LOCAL,
								Messages.OscfgDocumentProvider_UnsynchronizedFileSaveError,
								null));
			}
			info.stopResourceListening();
			fireElementStateChanging(element);
			try {
				monitor.beginTask(
						Messages.OscfgDocumentProvider_SaveDiagramTask, info
								.getResourceSet().getResources().size() + 1); //"Saving diagram"
				for (Iterator<Resource> it = info.getLoadedResourcesIterator(); it
						.hasNext();) {
					Resource nextResource = it.next();
					monitor.setTaskName(NLS
							.bind(Messages.OscfgDocumentProvider_SaveNextResourceTask,
									nextResource.getURI()));
					if (nextResource.isLoaded()
							&& !info.getEditingDomain()
									.isReadOnly(nextResource)) {
						try {
							nextResource.save(OscfgDiagramEditorUtil
									.getSaveOptions());
						} catch (IOException e) {
							fireElementStateChangeFailed(element);
							throw new CoreException(new Status(IStatus.ERROR,
									OscfgDiagramEditorPlugin.ID,
									EditorStatusCodes.RESOURCE_FAILURE,
									e.getLocalizedMessage(), null));
						}
					}
					monitor.worked(1);
				}
				monitor.done();
				info.setModificationStamp(computeModificationStamp(info));
			} catch (RuntimeException x) {
				fireElementStateChangeFailed(element);
				throw x;
			} finally {
				info.startResourceListening();
			}
		} else {
			URI newResoruceURI;
			List<IFile> affectedFiles = null;
			if (element instanceof FileEditorInput) {
				IFile newFile = ((FileEditorInput) element).getFile();
				affectedFiles = Collections.singletonList(newFile);
				newResoruceURI = URI.createPlatformResourceURI(newFile
						.getFullPath().toString(), true);
			} else if (element instanceof URIEditorInput) {
				newResoruceURI = ((URIEditorInput) element).getURI();
			} else {
				fireElementStateChangeFailed(element);
				throw new CoreException(
						new Status(
								IStatus.ERROR,
								OscfgDiagramEditorPlugin.ID,
								0,
								NLS.bind(
										Messages.OscfgDocumentProvider_IncorrectInputError,
										new Object[] {
												element,
												"org.eclipse.ui.part.FileEditorInput", "org.eclipse.emf.common.ui.URIEditorInput" }), //$NON-NLS-1$ //$NON-NLS-2$ 
								null));
			}
			if (false == document instanceof IDiagramDocument) {
				fireElementStateChangeFailed(element);
				throw new CoreException(
						new Status(
								IStatus.ERROR,
								OscfgDiagramEditorPlugin.ID,
								0,
								"Incorrect document used: " + document + " instead of org.eclipse.gmf.runtime.diagram.ui.resources.editor.document.IDiagramDocument", null)); //$NON-NLS-1$ //$NON-NLS-2$
			}
			IDiagramDocument diagramDocument = (IDiagramDocument) document;
			final Resource newResource = diagramDocument.getEditingDomain()
					.getResourceSet().createResource(newResoruceURI);
			final Diagram diagramCopy = (Diagram) EcoreUtil
					.copy(diagramDocument.getDiagram());
			try {
				new AbstractTransactionalCommand(
						diagramDocument.getEditingDomain(), NLS.bind(
								Messages.OscfgDocumentProvider_SaveAsOperation,
								diagramCopy.getName()), affectedFiles) {
					protected CommandResult doExecuteWithResult(
							IProgressMonitor monitor, IAdaptable info)
							throws ExecutionException {
						newResource.getContents().add(diagramCopy);
						return CommandResult.newOKCommandResult();
					}
				}.execute(monitor, null);
				newResource.save(OscfgDiagramEditorUtil.getSaveOptions());
			} catch (ExecutionException e) {
				fireElementStateChangeFailed(element);
				throw new CoreException(new Status(IStatus.ERROR,
						OscfgDiagramEditorPlugin.ID, 0,
						e.getLocalizedMessage(), null));
			} catch (IOException e) {
				fireElementStateChangeFailed(element);
				throw new CoreException(new Status(IStatus.ERROR,
						OscfgDiagramEditorPlugin.ID, 0,
						e.getLocalizedMessage(), null));
			}
			newResource.unload();
		}
	}

	/**
	 * @generated
	 */
	protected void handleElementChanged(ResourceSetInfo info,
			Resource changedResource, IProgressMonitor monitor) {
		IFile file = WorkspaceSynchronizer.getFile(changedResource);
		if (file != null) {
			try {
				file.refreshLocal(IResource.DEPTH_INFINITE, monitor);
			} catch (CoreException ex) {
				OscfgDiagramEditorPlugin
						.getInstance()
						.logError(
								Messages.OscfgDocumentProvider_handleElementContentChanged,
								ex);
				// Error message to log was initially taken from org.eclipse.gmf.runtime.diagram.ui.resources.editor.ide.internal.l10n.EditorMessages.FileDocumentProvider_handleElementContentChanged
			}
		}
		changedResource.unload();

		fireElementContentAboutToBeReplaced(info.getEditorInput());
		removeUnchangedElementListeners(info.getEditorInput(), info);
		info.fStatus = null;
		try {
			setDocumentContent(info.fDocument, info.getEditorInput());
		} catch (CoreException e) {
			info.fStatus = e.getStatus();
		}
		if (!info.fCanBeSaved) {
			info.setModificationStamp(computeModificationStamp(info));
		}
		addUnchangedElementListeners(info.getEditorInput(), info);
		fireElementContentReplaced(info.getEditorInput());
	}

	/**
	 * @generated
	 */
	protected void handleElementMoved(IEditorInput input, URI uri) {
		if (input instanceof FileEditorInput) {
			IFile newFile = ResourcesPlugin
					.getWorkspace()
					.getRoot()
					.getFile(
							new Path(URI.decode(uri.path()))
									.removeFirstSegments(1));
			fireElementMoved(input, newFile == null ? null
					: new FileEditorInput(newFile));
			return;
		}
		// TODO: append suffix to the URI! (use diagram as a parameter)
		fireElementMoved(input, new URIEditorInput(uri));
	}

	/**
	 * @generated
	 */
	public IEditorInput createInputWithEditingDomain(IEditorInput editorInput,
			TransactionalEditingDomain domain) {
		return editorInput;
	}

	/**
	 * @generated
	 */
	public IDiagramDocument getDiagramDocument(Object element) {
		IDocument doc = getDocument(element);
		if (doc instanceof IDiagramDocument) {
			return (IDiagramDocument) doc;
		}
		return null;
	}

	/**
	 * @generated
	 */
	protected IRunnableContext getOperationRunner(IProgressMonitor monitor) {
		return null;
	}

	/**
	 * @generated
	 */
	protected class ResourceSetInfo extends ElementInfo {

		/**
		 * @generated
		 */
		private long myModificationStamp = IResource.NULL_STAMP;

		/**
		 * @generated
		 */
		private WorkspaceSynchronizer mySynchronizer;

		/**
		 * @generated
		 */
		private LinkedList<Resource> myUnSynchronizedResources = new LinkedList<Resource>();

		/**
		 * @generated
		 */
		private IDiagramDocument myDocument;

		/**
		 * @generated
		 */
		private IEditorInput myEditorInput;

		/**
		 * @generated
		 */
		private boolean myUpdateCache = true;

		/**
		 * @generated
		 */
		private boolean myModifiable = false;

		/**
		 * @generated
		 */
		private boolean myReadOnly = true;

		/**
		 * @generated
		 */
		private ResourceSetModificationListener myResourceSetListener;

		/**
		 * @generated
		 */
		public ResourceSetInfo(IDiagramDocument document,
				IEditorInput editorInput) {
			super(document);
			myDocument = document;
			myEditorInput = editorInput;
			startResourceListening();
			myResourceSetListener = new ResourceSetModificationListener(this);
			getResourceSet().eAdapters().add(myResourceSetListener);
		}

		/**
		 * @generated
		 */
		public long getModificationStamp() {
			return myModificationStamp;
		}

		/**
		 * @generated
		 */
		public void setModificationStamp(long modificationStamp) {
			myModificationStamp = modificationStamp;
		}

		/**
		 * @generated
		 */
		public TransactionalEditingDomain getEditingDomain() {
			return myDocument.getEditingDomain();
		}

		/**
		 * @generated
		 */
		public ResourceSet getResourceSet() {
			return getEditingDomain().getResourceSet();
		}

		/**
		 * @generated
		 */
		public Iterator<Resource> getLoadedResourcesIterator() {
			return new ArrayList<Resource>(getResourceSet().getResources())
					.iterator();
		}

		/**
		 * @generated
		 */
		public IEditorInput getEditorInput() {
			return myEditorInput;
		}

		/**
		 * @generated
		 */
		public void dispose() {
			stopResourceListening();
			getResourceSet().eAdapters().remove(myResourceSetListener);
			for (Iterator<Resource> it = getLoadedResourcesIterator(); it
					.hasNext();) {
				Resource resource = it.next();
				resource.unload();
			}
			getEditingDomain().dispose();
		}

		/**
		 * @generated
		 */
		public boolean isSynchronized() {
			return myUnSynchronizedResources.size() == 0;
		}

		/**
		 * @generated
		 */
		public void setUnSynchronized(Resource resource) {
			myUnSynchronizedResources.add(resource);
		}

		/**
		 * @generated
		 */
		public void setSynchronized(Resource resource) {
			myUnSynchronizedResources.remove(resource);
		}

		/**
		 * @generated
		 */
		public final void stopResourceListening() {
			mySynchronizer.dispose();
			mySynchronizer = null;
		}

		/**
		 * @generated
		 */
		public final void startResourceListening() {
			mySynchronizer = new WorkspaceSynchronizer(getEditingDomain(),
					new SynchronizerDelegate());
		}

		/**
		 * @generated
		 */
		public boolean isUpdateCache() {
			return myUpdateCache;
		}

		/**
		 * @generated
		 */
		public void setUpdateCache(boolean update) {
			myUpdateCache = update;
		}

		/**
		 * @generated
		 */
		public boolean isModifiable() {
			return myModifiable;
		}

		/**
		 * @generated
		 */
		public void setModifiable(boolean modifiable) {
			myModifiable = modifiable;
		}

		/**
		 * @generated
		 */
		public boolean isReadOnly() {
			return myReadOnly;
		}

		/**
		 * @generated
		 */
		public void setReadOnly(boolean readOnly) {
			myReadOnly = readOnly;
		}

		/**
		 * @generated
		 */
		private class SynchronizerDelegate implements
				WorkspaceSynchronizer.Delegate {

			/**
			 * @generated
			 */
			public void dispose() {
			}

			/**
			 * @generated
			 */
			public boolean handleResourceChanged(final Resource resource) {
				synchronized (ResourceSetInfo.this) {
					if (ResourceSetInfo.this.fCanBeSaved) {
						ResourceSetInfo.this.setUnSynchronized(resource);
						return true;
					}
				}
				Display.getDefault().asyncExec(new Runnable() {
					public void run() {
						handleElementChanged(ResourceSetInfo.this, resource,
								null);
					}
				});
				return true;
			}

			/**
			 * @generated
			 */
			public boolean handleResourceDeleted(Resource resource) {
				synchronized (ResourceSetInfo.this) {
					if (ResourceSetInfo.this.fCanBeSaved) {
						ResourceSetInfo.this.setUnSynchronized(resource);
						return true;
					}
				}
				Display.getDefault().asyncExec(new Runnable() {
					public void run() {
						fireElementDeleted(ResourceSetInfo.this
								.getEditorInput());
					}
				});
				return true;
			}

			/**
			 * @generated
			 */
			public boolean handleResourceMoved(Resource resource,
					final URI newURI) {
				synchronized (ResourceSetInfo.this) {
					if (ResourceSetInfo.this.fCanBeSaved) {
						ResourceSetInfo.this.setUnSynchronized(resource);
						return true;
					}
				}
				if (myDocument.getDiagram().eResource() == resource) {
					Display.getDefault().asyncExec(new Runnable() {
						public void run() {
							handleElementMoved(
									ResourceSetInfo.this.getEditorInput(),
									newURI);
						}
					});
				} else {
					handleResourceDeleted(resource);
				}
				return true;
			}

		}

	}

	/**
	 * @generated
	 */
	private class ResourceSetModificationListener extends EContentAdapter {

		/**
		 * @generated
		 */
		private NotificationFilter myModifiedFilter;

		/**
		 * @generated
		 */
		private ResourceSetInfo myInfo;

		/**
		 * @generated
		 */
		public ResourceSetModificationListener(ResourceSetInfo info) {
			myInfo = info;
			myModifiedFilter = NotificationFilter
					.createEventTypeFilter(Notification.SET)
					.or(NotificationFilter
							.createEventTypeFilter(Notification.UNSET))
					.and(NotificationFilter.createFeatureFilter(Resource.class,
							Resource.RESOURCE__IS_MODIFIED));
		}

		/**
		 * @generated
		 */
		public void notifyChanged(Notification notification) {
			if (notification.getNotifier() instanceof ResourceSet) {
				super.notifyChanged(notification);
			}
			if (!notification.isTouch()
					&& myModifiedFilter.matches(notification)) {
				if (notification.getNotifier() instanceof Resource) {
					Resource resource = (Resource) notification.getNotifier();
					if (resource.isLoaded()) {
						boolean modified = false;
						for (Iterator/*<org.eclipse.emf.ecore.resource.Resource>*/it = myInfo
								.getLoadedResourcesIterator(); it.hasNext()
								&& !modified;) {
							Resource nextResource = (Resource) it.next();
							if (nextResource.isLoaded()) {
								modified = nextResource.isModified();
							}
						}
						boolean dirtyStateChanged = false;
						synchronized (myInfo) {
							if (modified != myInfo.fCanBeSaved) {
								myInfo.fCanBeSaved = modified;
								dirtyStateChanged = true;
							}
							if (!resource.isModified()) {
								myInfo.setSynchronized(resource);
							}
						}
						if (dirtyStateChanged) {
							fireElementDirtyStateChanged(
									myInfo.getEditorInput(), modified);

							if (!modified) {
								myInfo.setModificationStamp(computeModificationStamp(myInfo));
							}
						}
					}
				}
			}
		}

	}

}
