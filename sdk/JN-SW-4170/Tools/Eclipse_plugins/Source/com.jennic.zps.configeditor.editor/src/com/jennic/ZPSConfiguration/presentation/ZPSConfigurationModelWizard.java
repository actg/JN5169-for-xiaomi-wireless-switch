/**
 * <copyright>
 * </copyright>
 *
 * $Id$
 */
package com.jennic.ZPSConfiguration.presentation;


import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collection;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

import org.eclipse.emf.common.CommonPlugin;

import org.eclipse.emf.common.util.URI;

import org.eclipse.emf.ecore.EClass;
import org.eclipse.emf.ecore.EClassifier;

import org.eclipse.emf.ecore.resource.Resource;
import org.eclipse.emf.ecore.resource.ResourceSet;

import org.eclipse.emf.ecore.resource.impl.ResourceSetImpl;

import org.eclipse.emf.ecore.EObject;

import org.eclipse.emf.ecore.xmi.XMLResource;

import org.eclipse.emf.edit.ui.provider.ExtendedImageRegistry;

import org.eclipse.core.resources.IContainer;
import org.eclipse.core.resources.IFile;
import org.eclipse.core.resources.IFolder;
import org.eclipse.core.resources.IProject;
import org.eclipse.core.resources.IResource;
import org.eclipse.core.resources.ResourcesPlugin;

import org.eclipse.core.runtime.IProgressMonitor;

import org.eclipse.jface.dialogs.MessageDialog;

import org.eclipse.jface.viewers.IStructuredSelection;

import org.eclipse.jface.wizard.Wizard;

import org.eclipse.ui.INewWizard;
import org.eclipse.ui.IWorkbench;

import org.eclipse.ui.actions.WorkspaceModifyOperation;

import org.eclipse.ui.dialogs.WizardNewFileCreationPage;

import org.eclipse.ui.part.FileEditorInput;
import org.eclipse.ui.part.ISetSelectionTarget;



import org.eclipse.core.runtime.Path;

import org.eclipse.jface.viewers.ISelection;
import org.eclipse.jface.viewers.StructuredSelection;

import org.eclipse.ui.IWorkbenchPage;
import org.eclipse.ui.IWorkbenchPart;
import org.eclipse.ui.IWorkbenchWindow;
import org.eclipse.ui.PartInitException;

import com.jennic.ZPSConfiguration.Cluster;
import com.jennic.ZPSConfiguration.Profile;
import com.jennic.ZPSConfiguration.ZPSConfigurationFactory;
import com.jennic.ZPSConfiguration.ZPSConfigurationPackage;
import com.jennic.ZPSConfiguration.ZigbeeWirelessNetwork;


/**
 * This is a simple wizard for creating a new model file.
 * <!-- begin-user-doc -->
 * <!-- end-user-doc -->
 * @generated NOT
 */
public class ZPSConfigurationModelWizard extends Wizard implements INewWizard {
	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public static final String copyright = "(C) Jennic Ltd";

	/**
	 * The supported extensions for created files.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public static final List<String> FILE_EXTENSIONS =
		Collections.unmodifiableList(Arrays.asList(ZPSConfigEditorPlugin.INSTANCE.getString("_UI_ZPSConfigurationEditorFilenameExtensions").split("\\s*,\\s*")));

	/**
	 * A formatted list of supported file extensions, suitable for display.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public static final String FORMATTED_FILE_EXTENSIONS =
		ZPSConfigEditorPlugin.INSTANCE.getString("_UI_ZPSConfigurationEditorFilenameExtensions").replaceAll("\\s*,\\s*", ", ");

	/**
	 * This caches an instance of the model package.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	protected ZPSConfigurationPackage zpsConfigurationPackage = ZPSConfigurationPackage.eINSTANCE;

	/**
	 * This caches an instance of the model factory.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	protected ZPSConfigurationFactory zpsConfigurationFactory = zpsConfigurationPackage.getZPSConfigurationFactory();

	/**
	 * This is the file creation page.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	protected ZPSConfigurationModelWizardNewFileCreationPage newFileCreationPage;

	/**
	 * This is the initial object creation page.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated NOT
	 */
//	protected ZPSConfigurationModelWizardInitialObjectCreationPage initialObjectCreationPage;

	/**
	 * Remember the selection during initialization for populating the default container.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	protected IStructuredSelection selection;

	/**
	 * Remember the workbench during initialization.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	protected IWorkbench workbench;

	/**
	 * Caches the names of the types that can be created as the root object.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	protected List<String> initialObjectNames;

	/**
	 * This just records the information.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated NOT
	 */
	public void init(IWorkbench workbench, IStructuredSelection selection) {
		this.workbench = workbench;
		this.selection = selection;
		setWindowTitle(ZPSConfigEditorPlugin.INSTANCE.getString("_UI_Wizard_label"));
		setDefaultPageImageDescriptor(ExtendedImageRegistry.INSTANCE.getImageDescriptor(ZPSConfigEditorPlugin.INSTANCE.getImage("full/wizban/NewZPSConfiguration.png")));
	}

	/**
	 * Returns the names of the types that can be created as the root object.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	protected Collection<String> getInitialObjectNames() {
		if (initialObjectNames == null) {
			initialObjectNames = new ArrayList<String>();
			for (EClassifier eClassifier : zpsConfigurationPackage.getEClassifiers()) {
				if (eClassifier instanceof EClass) {
					EClass eClass = (EClass)eClassifier;
					if (!eClass.isAbstract()) {
						initialObjectNames.add(eClass.getName());
					}
				}
			}
			Collections.sort(initialObjectNames, CommonPlugin.INSTANCE.getComparator());
		}
		return initialObjectNames;
	}

	/**
	 * Create a new model.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated NOT
	 */
	protected EObject createInitialModel() {
		EClass eClass = (EClass)zpsConfigurationPackage.getEClassifier("ZigbeeWirelessNetwork");
		EObject rootObject = zpsConfigurationFactory.create(eClass);
		
		Profile zdp = zpsConfigurationFactory.createProfile();

		zdp.setName("ZDP");
		zdp.setId(0);
				
		addCluster(zpsConfigurationFactory, zdp, "NWK_addr_req",  				0x0000);
		addCluster(zpsConfigurationFactory, zdp, "IEEE_addr_req", 				0x0001);
		addCluster(zpsConfigurationFactory, zdp, "Node_Desc_req", 				0x0002);
		addCluster(zpsConfigurationFactory, zdp, "Power_Desc_req", 				0x0003);
		addCluster(zpsConfigurationFactory, zdp, "Simple_Desc_req", 			0x0004);
		addCluster(zpsConfigurationFactory, zdp, "Active_EP_req", 				0x0005);
		addCluster(zpsConfigurationFactory, zdp, "Match_Desc_req", 				0x0006);
		addCluster(zpsConfigurationFactory, zdp, "Complex_Desc_req", 			0x0010);
		addCluster(zpsConfigurationFactory, zdp, "User_Desc_req", 				0x0011);
		addCluster(zpsConfigurationFactory, zdp, "Discovery_Cache_req", 		0x0012);
		addCluster(zpsConfigurationFactory, zdp, "Device_annce", 				0x0013);
		addCluster(zpsConfigurationFactory, zdp, "User_Desc_set", 				0x0014);
		addCluster(zpsConfigurationFactory, zdp, "System_Server_Discovery_req", 0x0015);
		addCluster(zpsConfigurationFactory, zdp, "Discovery_store_req", 		0x0016);
		addCluster(zpsConfigurationFactory, zdp, "Node_Desc_store_req", 		0x0017);
		addCluster(zpsConfigurationFactory, zdp, "Power_Desc_store_req", 		0x0018);
		addCluster(zpsConfigurationFactory, zdp, "Active_EP_store_req", 		0x0019);
		addCluster(zpsConfigurationFactory, zdp, "Simple_Desc_store_req", 		0x001A);
		addCluster(zpsConfigurationFactory, zdp, "Remove_node_cache_req", 		0x001B);
		addCluster(zpsConfigurationFactory, zdp, "Find_node_chache_req", 		0x001C);
		addCluster(zpsConfigurationFactory, zdp, "Extended_Simple_Desc_req", 	0x001D);
		addCluster(zpsConfigurationFactory, zdp, "Extended_Active_EP_req", 		0x001E);
		addCluster(zpsConfigurationFactory, zdp, "Parent_Announce_req",			0x001F);
		addCluster(zpsConfigurationFactory, zdp, "End_Device_Bind_req", 		0x0020);
		addCluster(zpsConfigurationFactory, zdp, "Bind_req", 					0x0021);
		addCluster(zpsConfigurationFactory, zdp, "Unbind_req", 					0x0022);
		addCluster(zpsConfigurationFactory, zdp, "Bind_Register_req", 			0x0023);
		addCluster(zpsConfigurationFactory, zdp, "Replace_Device_req", 			0x0024);
		addCluster(zpsConfigurationFactory, zdp, "Store_Bkup_Bind_Entry_req",	0x0025);
		addCluster(zpsConfigurationFactory, zdp, "Remove_Bkup_Bind_Entry_req", 	0x0026);
		addCluster(zpsConfigurationFactory, zdp, "Backup_Bind_Table_req", 		0x0027);
		addCluster(zpsConfigurationFactory, zdp, "Recover_Bind_Table_req", 		0x0028);
		addCluster(zpsConfigurationFactory, zdp, "Backup_Source_Bind_req", 		0x0029);
		addCluster(zpsConfigurationFactory, zdp, "Recover_Source_Bind_req", 	0x002A);
		addCluster(zpsConfigurationFactory, zdp, "Mgmt_NWK_Disc_req", 			0x0030);
		addCluster(zpsConfigurationFactory, zdp, "Mgmt_Lqi_req", 				0x0031);
		addCluster(zpsConfigurationFactory, zdp, "Mgmt_Rtg_req", 				0x0032);
		addCluster(zpsConfigurationFactory, zdp, "Mgmt_Bind_req", 				0x0033);
		addCluster(zpsConfigurationFactory, zdp, "Mgmt_Leave_req", 				0x0034);
	    addCluster(zpsConfigurationFactory, zdp, "Mgmt_Direct_Join_req", 		0x0035);
	    addCluster(zpsConfigurationFactory, zdp, "Mgmt_Permit_Joining_req", 	0x0036);
	    addCluster(zpsConfigurationFactory, zdp, "Mgmt_Cache_req", 				0x0037);
	    addCluster(zpsConfigurationFactory, zdp, "Mgmt_NWK_Update_req", 		0x0038);
	    addCluster(zpsConfigurationFactory, zdp, "Mgmt_NWK_Enhanced_Update_req",0x0039);
	    addCluster(zpsConfigurationFactory, zdp, "Mgmt_NWK_IEEE_Joining_req",   0x0040);
	    addCluster(zpsConfigurationFactory, zdp, "NWK_addr_rsp", 				0x8000);
	    addCluster(zpsConfigurationFactory, zdp, "IEEE_addr_rsp", 				0x8001);
	    addCluster(zpsConfigurationFactory, zdp, "Node_Desc_rsp", 				0x8002);
	    addCluster(zpsConfigurationFactory, zdp, "Power_Desc_rsp", 				0x8003);
	    addCluster(zpsConfigurationFactory, zdp, "Simple_Desc_rsp", 			0x8004);
	    addCluster(zpsConfigurationFactory, zdp, "Active_EP_rsp", 				0x8005);
	    addCluster(zpsConfigurationFactory, zdp, "Match_Desc_rsp", 				0x8006);
	    addCluster(zpsConfigurationFactory, zdp, "Complex_Desc_rsp", 			0x8010);
	    addCluster(zpsConfigurationFactory, zdp, "User_Desc_rsp", 				0x8011);
	    addCluster(zpsConfigurationFactory, zdp, "Discovery_Cache_rsp", 		0x8012);
	    addCluster(zpsConfigurationFactory, zdp, "User_Desc_conf", 				0x8014);
	    addCluster(zpsConfigurationFactory, zdp, "System_Server_Discovery_rsp", 0x8015);
	    addCluster(zpsConfigurationFactory, zdp, "Discovery_store_rsp",			0x8016);
	    addCluster(zpsConfigurationFactory, zdp, "Node_Desc_store_rsp", 		0x8017);
	    addCluster(zpsConfigurationFactory, zdp, "Power_Desc_store_rsp", 		0x8018);
	    addCluster(zpsConfigurationFactory, zdp, "Active_EP_store_rsp", 		0x8019);
	    addCluster(zpsConfigurationFactory, zdp, "Simple_Desc_store_rsp", 		0x801A);
	    addCluster(zpsConfigurationFactory, zdp, "Remove_node_cache_rsp", 		0x801B);
	    addCluster(zpsConfigurationFactory, zdp, "Find_node_chache_rsp", 		0x801C);
	    addCluster(zpsConfigurationFactory, zdp, "Extended_Simple_Desc_rsp", 	0x801D);
	    addCluster(zpsConfigurationFactory, zdp, "Extended_Active_EP_rsp", 		0x801E);
	    addCluster(zpsConfigurationFactory, zdp, "Parent_Announce_rsp", 		0x801F);
	    addCluster(zpsConfigurationFactory, zdp, "End_Device_Bind_rsp", 		0x8020);
	    addCluster(zpsConfigurationFactory, zdp, "Bind_rsp", 					0x8021);
	    addCluster(zpsConfigurationFactory, zdp, "Unbind_rsp", 					0x8022);
	    addCluster(zpsConfigurationFactory, zdp, "Bind_Register_rsp", 			0x8023);
	    addCluster(zpsConfigurationFactory, zdp, "Replace_Device_rsp", 			0x8024);
	    addCluster(zpsConfigurationFactory, zdp, "Store_Bkup_Bind_Entry_rsp", 	0x8025);
	    addCluster(zpsConfigurationFactory, zdp, "Remove_Bkup_Bind_Entry_rsp", 	0x8026);
	    addCluster(zpsConfigurationFactory, zdp, "Backup_Bind_Table_rsp", 		0x8027);
	    addCluster(zpsConfigurationFactory, zdp, "Recover_Bind_Table_rsp",		0x8028);
	    addCluster(zpsConfigurationFactory, zdp, "Backup_Source_Bind_rsp", 		0x8029);
	    addCluster(zpsConfigurationFactory, zdp, "Recover_Source_Bind_rsp", 	0x802A);
	    addCluster(zpsConfigurationFactory, zdp, "Mgmt_NWK_Disc_rsp", 			0x8030);
	    addCluster(zpsConfigurationFactory, zdp, "Mgmt_Lqi_rsp", 				0x8031);
	    addCluster(zpsConfigurationFactory, zdp, "Mgmt_Rtg_rsp", 				0x8032);
	    addCluster(zpsConfigurationFactory, zdp, "Mgmt_Bind_rsp", 				0x8033);
	    addCluster(zpsConfigurationFactory, zdp, "Mgmt_Leave_rsp", 				0x8034);
	    addCluster(zpsConfigurationFactory, zdp, "Mgmt_Direct_Join_rsp", 		0x8035);
	    addCluster(zpsConfigurationFactory, zdp, "Mgmt_Permit_Joining_rsp", 	0x8036);
	    addCluster(zpsConfigurationFactory, zdp, "Mgmt_Cache_rsp", 				0x8037);
	    addCluster(zpsConfigurationFactory, zdp, "Mgmt_NWK_Update_rsp", 		0x8038);
	    addCluster(zpsConfigurationFactory, zdp, "Mgmt_NWK_Enhanced_Update_rsp",0x8039);
	    addCluster(zpsConfigurationFactory, zdp, "Mgmt_NWK_IEEE_Joining_rsp", 	0x8040);
		
	    ((ZigbeeWirelessNetwork)rootObject).getProfiles().add(zdp);
	    
		return rootObject;
	}

	private void addCluster(ZPSConfigurationFactory factory, Profile p, String name, int id) {
		
		Cluster c = factory.createCluster();
		
		c.setName(name);
		c.setId(id);
		
		p.getClusters().add(c);
	}
	
	/**
	 * Do the work after everything is specified.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated NOT
	 */
	@Override
	public boolean performFinish() {
		try {
			// Remember the file.
			//
			final IFile modelFile = getModelFile();

			// Do the work within an operation.
			//
			WorkspaceModifyOperation operation =
				new WorkspaceModifyOperation() {
					@Override
					protected void execute(IProgressMonitor progressMonitor) {
						try {
							// Create a resource set
							//
							ResourceSet resourceSet = new ResourceSetImpl();

							// Get the URI of the model file.
							//
							URI fileURI = URI.createPlatformResourceURI(modelFile.getFullPath().toString(), true);

							// Create a resource for this file.
							//
							Resource resource = resourceSet.createResource(fileURI);

							// Add the initial model object to the contents.
							//
							EObject rootObject = createInitialModel();
							if (rootObject != null) {
								resource.getContents().add(rootObject);
							}

							// Save the contents of the resource to the file system.
							//
							Map<Object, Object> options = new HashMap<Object, Object>();
							options.put(XMLResource.OPTION_ENCODING, "UTF-8");
							resource.save(options);
						}
						catch (Exception exception) {
							ZPSConfigEditorPlugin.INSTANCE.log(exception);
						}
						finally {
							progressMonitor.done();
						}
					}
				};

			getContainer().run(false, false, operation);

			// Select the new file resource in the current view.
			//
			IWorkbenchWindow workbenchWindow = workbench.getActiveWorkbenchWindow();
			IWorkbenchPage page = workbenchWindow.getActivePage();
			final IWorkbenchPart activePart = page.getActivePart();
			if (activePart instanceof ISetSelectionTarget) {
				final ISelection targetSelection = new StructuredSelection(modelFile);
				getShell().getDisplay().asyncExec
					(new Runnable() {
						 public void run() {
							 ((ISetSelectionTarget)activePart).selectReveal(targetSelection);
						 }
					 });
			}

			// Open an editor on the new file.
			//
			try {
				page.openEditor
					(new FileEditorInput(modelFile),
					 workbench.getEditorRegistry().getDefaultEditor(modelFile.getFullPath().toString()).getId());
			}
			catch (PartInitException exception) {
				MessageDialog.openError(workbenchWindow.getShell(), ZPSConfigEditorPlugin.INSTANCE.getString("_UI_OpenEditorError_label"), exception.getMessage());
				return false;
			}

			return true;
		}
		catch (Exception exception) {
			ZPSConfigEditorPlugin.INSTANCE.log(exception);
			return false;
		}
	}

	/**
	 * This is the one page of the wizard.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public class ZPSConfigurationModelWizardNewFileCreationPage extends WizardNewFileCreationPage {
		/**
		 * Pass in the selection.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		public ZPSConfigurationModelWizardNewFileCreationPage(String pageId, IStructuredSelection selection) {
			super(pageId, selection);
		}

		/**
		 * The framework calls this to see if the file is correct.
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		@Override
		protected boolean validatePage() {
			if (super.validatePage()) {
				String extension = new Path(getFileName()).getFileExtension();
				if (extension == null || !FILE_EXTENSIONS.contains(extension)) {
					String key = FILE_EXTENSIONS.size() > 1 ? "_WARN_FilenameExtensions" : "_WARN_FilenameExtension";
					setErrorMessage(ZPSConfigEditorPlugin.INSTANCE.getString(key, new Object [] { FORMATTED_FILE_EXTENSIONS }));
					return false;
				}
				return true;
			}
			return false;
		}

		/**
		 * <!-- begin-user-doc -->
		 * <!-- end-user-doc -->
		 * @generated
		 */
		public IFile getModelFile() {
			return ResourcesPlugin.getWorkspace().getRoot().getFile(getContainerFullPath().append(getFileName()));
		}
	}

	/**
	 * This is the page where the type of object to create is selected.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated NOT
	 */
//	removed

	/**
	 * This is the page where the type of object to create is selected.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated NOT
	 */
	// removed
	
	/**
	 * The framework calls this to create the contents of the wizard.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated NOT
	 */
		@Override
	public void addPages() {
		// Create a page, set the title, and the initial model file name.
		//
		newFileCreationPage = new ZPSConfigurationModelWizardNewFileCreationPage("Whatever", selection);
		newFileCreationPage.setTitle(ZPSConfigEditorPlugin.INSTANCE.getString("_UI_ZPSConfigurationModelWizard_label"));
		newFileCreationPage.setDescription(ZPSConfigEditorPlugin.INSTANCE.getString("_UI_ZPSConfigurationModelWizard_description"));
		newFileCreationPage.setFileName(ZPSConfigEditorPlugin.INSTANCE.getString("_UI_ZPSConfigurationEditorFilenameDefaultBase") + "." + FILE_EXTENSIONS.get(0));
		addPage(newFileCreationPage);

		// Try and get the resource selection to determine a current directory for the file dialog.
		//
		if (selection != null && !selection.isEmpty()) {
			// Get the resource...
			//
			Object selectedElement = selection.iterator().next();
			if (selectedElement instanceof IResource) {
				// Get the resource parent, if its a file.
				//
				IResource selectedResource = (IResource)selectedElement;
				if (selectedResource.getType() == IResource.FILE) {
					selectedResource = selectedResource.getParent();
				}

				// This gives us a directory...
				//
				if (selectedResource instanceof IFolder || selectedResource instanceof IProject) {
					// Set this for the container.
					//
					newFileCreationPage.setContainerFullPath(selectedResource.getFullPath());

					// Make up a unique new name here.
					//
					String defaultModelBaseFilename = ZPSConfigEditorPlugin.INSTANCE.getString("_UI_ZPSConfigurationEditorFilenameDefaultBase");
					String defaultModelFilenameExtension = FILE_EXTENSIONS.get(0);
					String modelFilename = defaultModelBaseFilename + "." + defaultModelFilenameExtension;
					for (int i = 1; ((IContainer)selectedResource).findMember(modelFilename) != null; ++i) {
						modelFilename = defaultModelBaseFilename + i + "." + defaultModelFilenameExtension;
					}
					newFileCreationPage.setFileName(modelFilename);
				}
			}
		}
//		initialObjectCreationPage = new ZPSConfigurationModelWizardInitialObjectCreationPage("Whatever2");
//		initialObjectCreationPage.setTitle(ZPSConfigEditorPlugin.INSTANCE.getString("_UI_ZPSConfigurationModelWizard_label"));
//		initialObjectCreationPage.setDescription(ZPSConfigEditorPlugin.INSTANCE.getString("_UI_Wizard_initial_object_description"));
//		addPage(initialObjectCreationPage);
	}

	/**
	 * Get the file from the page.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public IFile getModelFile() {
		return newFileCreationPage.getModelFile();
	}

}
