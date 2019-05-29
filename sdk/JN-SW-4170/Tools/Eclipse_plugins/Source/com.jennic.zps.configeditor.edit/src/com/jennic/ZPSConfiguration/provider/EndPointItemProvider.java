/**
 * (C) Jennic Ltd 2008
 *
 * $Id$
 */
package com.jennic.ZPSConfiguration.provider;


import java.util.ArrayList;
import java.util.Collection;
import java.util.Iterator;
import java.util.List;

import org.eclipse.emf.common.command.Command;
import org.eclipse.emf.common.command.UnexecutableCommand;
import org.eclipse.emf.common.notify.AdapterFactory;
import org.eclipse.emf.common.notify.Notification;

import org.eclipse.emf.common.util.BasicEList;
import org.eclipse.emf.common.util.EList;
import org.eclipse.emf.common.util.ResourceLocator;
import org.eclipse.emf.ecore.EObject;
import org.eclipse.emf.ecore.EStructuralFeature;

import org.eclipse.emf.edit.command.CopyCommand.Helper;
import org.eclipse.emf.edit.domain.EditingDomain;
import org.eclipse.emf.edit.provider.ComposeableAdapterFactory;
import org.eclipse.emf.edit.provider.IEditingDomainItemProvider;
import org.eclipse.emf.edit.provider.IItemLabelProvider;
import org.eclipse.emf.edit.provider.IItemPropertyDescriptor;
import org.eclipse.emf.edit.provider.IItemPropertySource;
import org.eclipse.emf.edit.provider.IStructuredItemContentProvider;
import org.eclipse.emf.edit.provider.ITreeItemContentProvider;
import org.eclipse.emf.edit.provider.ItemPropertyDescriptor;
import org.eclipse.emf.edit.provider.ItemProviderAdapter;
import org.eclipse.emf.edit.provider.ViewerNotification;

import com.jennic.ZPSConfiguration.APDU;
import com.jennic.ZPSConfiguration.EndPoint;
import com.jennic.ZPSConfiguration.InputCluster;
import com.jennic.ZPSConfiguration.OutputCluster;
import com.jennic.ZPSConfiguration.Profile;
import com.jennic.ZPSConfiguration.ZPSConfigurationFactory;
import com.jennic.ZPSConfiguration.ZPSConfigurationPackage;
import com.jennic.ZPSConfiguration.ZigbeeWirelessNetwork;

/**
 * This is the item provider adapter for a {@link com.jennic.ZPSConfiguration.EndPoint} object.
 * <!-- begin-user-doc -->
 * <!-- end-user-doc -->
 * @generated
 */
public class EndPointItemProvider
	extends ItemProviderAdapter
	implements
		IEditingDomainItemProvider,
		IStructuredItemContentProvider,
		ITreeItemContentProvider,
		IItemLabelProvider,
		IItemPropertySource {
	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public static final String copyright = "(C) NXP B.V";

	/**
	 * This constructs an instance from a factory and a notifier.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EndPointItemProvider(AdapterFactory adapterFactory) {
		super(adapterFactory);
	}

	/**
	 * This returns the property descriptors for the adapted class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated NOT
	 */
	@Override
	public List<IItemPropertyDescriptor> getPropertyDescriptors(Object object) {
		if (itemPropertyDescriptors != null) {
			itemPropertyDescriptors.removeAll(itemPropertyDescriptors);
			itemPropertyDescriptors = null;
		}
		super.getPropertyDescriptors(object);

		addIdPropertyDescriptor(object);
		addEnabledPropertyDescriptor(object);
		addApplicationDeviceIdPropertyDescriptor(object);
		addApplicationDeviceVersionPropertyDescriptor(object);
		addProfilePropertyDescriptor(object);
		addMessagePropertyDescriptor(object);
		addNamePropertyDescriptor(object);

		return itemPropertyDescriptors;
	}

	/**
	 * @generated NOT
	 */
	private boolean Editable(Object object) {
		boolean editable = true;
		EndPoint ep = (EndPoint)object;
		String zdo = "ZDO";
		
		/*if (null != ep.getName() && 0 == zdo.compareTo(ep.getName())) {
			editable = false;
		}*/
		
		return editable;
	}
	
	/**
	 * This adds a property descriptor for the Id feature.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated NOT
	 */
	protected void addIdPropertyDescriptor(Object object) {
		itemPropertyDescriptors.add
			(createItemPropertyDescriptor
				(((ComposeableAdapterFactory)adapterFactory).getRootAdapterFactory(),
				 getResourceLocator(),
				 getString("_UI_EndPoint_Id_feature"),
				 getString("_UI_PropertyDescriptor_description", "_UI_EndPoint_Id_feature", "_UI_EndPoint_type"),
				 ZPSConfigurationPackage.Literals.END_POINT__ID,
				 Editable(object),
				 false,
				 false,
				 ItemPropertyDescriptor.INTEGRAL_VALUE_IMAGE,
				 null,
				 null));
	}

	/**
	 * This adds a property descriptor for the Enabled feature.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated NOT
	 */
	protected void addEnabledPropertyDescriptor(Object object) {
		itemPropertyDescriptors.add
			(createItemPropertyDescriptor
				(((ComposeableAdapterFactory)adapterFactory).getRootAdapterFactory(),
				 getResourceLocator(),
				 getString("_UI_EndPoint_Enabled_feature"),
				 getString("_UI_PropertyDescriptor_description", "_UI_EndPoint_Enabled_feature", "_UI_EndPoint_type"),
				 ZPSConfigurationPackage.Literals.END_POINT__ENABLED,
				 Editable(object),
				 false,
				 false,
				 ItemPropertyDescriptor.BOOLEAN_VALUE_IMAGE,
				 null,
				 null));
	}

	/**
	 * This adds a property descriptor for the Application Device Id feature.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated NOT
	 */
	protected void addApplicationDeviceIdPropertyDescriptor(Object object) {
		itemPropertyDescriptors.add
			(createItemPropertyDescriptor
				(((ComposeableAdapterFactory)adapterFactory).getRootAdapterFactory(),
				 getResourceLocator(),
				 getString("_UI_EndPoint_ApplicationDeviceId_feature"),
				 getString("_UI_PropertyDescriptor_description", "_UI_EndPoint_ApplicationDeviceId_feature", "_UI_EndPoint_type"),
				 ZPSConfigurationPackage.Literals.END_POINT__APPLICATION_DEVICE_ID,
				 Editable(object),
				 false,
				 false,
				 ItemPropertyDescriptor.INTEGRAL_VALUE_IMAGE,
				 null,
				 null));
	}

	/**
	 * This adds a property descriptor for the Application Device Version feature.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated NOT
	 */
	protected void addApplicationDeviceVersionPropertyDescriptor(Object object) {
		itemPropertyDescriptors.add
			(createItemPropertyDescriptor
				(((ComposeableAdapterFactory)adapterFactory).getRootAdapterFactory(),
				 getResourceLocator(),
				 getString("_UI_EndPoint_ApplicationDeviceVersion_feature"),
				 getString("_UI_PropertyDescriptor_description", "_UI_EndPoint_ApplicationDeviceVersion_feature", "_UI_EndPoint_type"),
				 ZPSConfigurationPackage.Literals.END_POINT__APPLICATION_DEVICE_VERSION,
				 Editable(object),
				 false,
				 false,
				 ItemPropertyDescriptor.INTEGRAL_VALUE_IMAGE,
				 null,
				 null));
	}

	/**
	 * This adds a property descriptor for the Profile feature.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated NOT
	 */
	protected void addProfilePropertyDescriptor(Object object) {
		itemPropertyDescriptors.add
			(new ItemPropertyDescriptor
				(((ComposeableAdapterFactory)adapterFactory).getRootAdapterFactory(),
				 getResourceLocator(),
				 getString("_UI_EndPoint_Profile_feature"),
				 getString("_UI_PropertyDescriptor_description", "_UI_EndPoint_Profile_feature", "_UI_EndPoint_type"),
				 ZPSConfigurationPackage.Literals.END_POINT__PROFILE,
				 Editable(object),
				 false,
				 true,
				 null,
				 null,
				 null)
				 {
					/* display only the APDUs for the node the InputCluster is on */
					@Override
					public EList<Profile> getChoiceOfValues(Object object)
					{
						EList<Profile> profiles = ((ZigbeeWirelessNetwork)(((EndPoint)object).eContainer().eContainer())).getProfiles();
						String zdp = "ZDP";
						EList<Profile> selProfiles = new BasicEList<Profile>();
						
						
						for (Iterator<Profile> iterator = profiles.iterator(); iterator.hasNext(); ) {
							Profile profile = iterator.next();
							
							/*if (null != profile.getName() && 0 == zdp.compareTo(profile.getName())) {

							} else {*/
								selProfiles.add(profile);
							/*}*/
						}
						
						return selProfiles; 
					}
				 });
	}

	/**
	 * This adds a property descriptor for the Message feature.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	protected void addMessagePropertyDescriptor(Object object) {
		itemPropertyDescriptors.add
			(createItemPropertyDescriptor
				(((ComposeableAdapterFactory)adapterFactory).getRootAdapterFactory(),
				 getResourceLocator(),
				 getString("_UI_EndPoint_Message_feature"),
				 getString("_UI_PropertyDescriptor_description", "_UI_EndPoint_Message_feature", "_UI_EndPoint_type"),
				 ZPSConfigurationPackage.Literals.END_POINT__MESSAGE,
				 true,
				 false,
				 false,
				 ItemPropertyDescriptor.GENERIC_VALUE_IMAGE,
				 null,
				 null));
	}

	/**
	 * This adds a property descriptor for the Name feature.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated NOT
	 */
	protected void addNamePropertyDescriptor(Object object) {
		itemPropertyDescriptors.add
			(createItemPropertyDescriptor
				(((ComposeableAdapterFactory)adapterFactory).getRootAdapterFactory(),
				 getResourceLocator(),
				 getString("_UI_EndPoint_Name_feature"),
				 getString("_UI_PropertyDescriptor_description", "_UI_EndPoint_Name_feature", "_UI_EndPoint_type"),
				 ZPSConfigurationPackage.Literals.END_POINT__NAME,
				 Editable(object),
				 false,
				 false,
				 ItemPropertyDescriptor.GENERIC_VALUE_IMAGE,
				 null,
				 null));
	}

	/**
	 * This specifies how to implement {@link #getChildren} and is used to deduce an appropriate feature for an
	 * {@link org.eclipse.emf.edit.command.AddCommand}, {@link org.eclipse.emf.edit.command.RemoveCommand} or
	 * {@link org.eclipse.emf.edit.command.MoveCommand} in {@link #createCommand}.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	@Override
	public Collection<? extends EStructuralFeature> getChildrenFeatures(Object object) {
		if (childrenFeatures == null) {
			super.getChildrenFeatures(object);
			childrenFeatures.add(ZPSConfigurationPackage.Literals.END_POINT__INPUT_CLUSTERS);
			childrenFeatures.add(ZPSConfigurationPackage.Literals.END_POINT__OUTPUT_CLUSTERS);
		}
		return childrenFeatures;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	@Override
	protected EStructuralFeature getChildFeature(Object object, Object child) {
		// Check the type of the specified child object and return the proper feature to use for
		// adding (see {@link AddCommand}) it as a child.

		return super.getChildFeature(object, child);
	}

	/**
	 * This returns EndPoint.gif.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated NOT
	 */
	@Override
	public Object getImage(Object object) {
		return overlayImage(object, getResourceLocator().getImage("full/obj16/EndPoint.png"));
	}

	/**
	 * This returns the label text for the adapted class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated NOT
	 */
	@Override
	public String getText(Object object) {
		String epName = "<undefined>";
		
		if (null != ((EndPoint)object).getName()) {
			epName = ((EndPoint)object).getName();
		}
		
		String label = "\"" + epName + "\" (" + ((EndPoint)object).getId() + ")";
		return label == null || label.length() == 0 ?
			getString("_UI_EndPoint_type") :
			getString("_UI_EndPoint_type") + " " + label;
	}

	/**
	 * This handles model notifications by calling {@link #updateChildren} to update any cached
	 * children and by creating a viewer notification, which it passes to {@link #fireNotifyChanged}.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	@Override
	public void notifyChanged(Notification notification) {
		updateChildren(notification);

		switch (notification.getFeatureID(EndPoint.class)) {
			case ZPSConfigurationPackage.END_POINT__ID:
			case ZPSConfigurationPackage.END_POINT__ENABLED:
			case ZPSConfigurationPackage.END_POINT__APPLICATION_DEVICE_ID:
			case ZPSConfigurationPackage.END_POINT__APPLICATION_DEVICE_VERSION:
			case ZPSConfigurationPackage.END_POINT__MESSAGE:
			case ZPSConfigurationPackage.END_POINT__NAME:
				fireNotifyChanged(new ViewerNotification(notification, notification.getNotifier(), false, true));
				return;
			case ZPSConfigurationPackage.END_POINT__INPUT_CLUSTERS:
			case ZPSConfigurationPackage.END_POINT__OUTPUT_CLUSTERS:
				fireNotifyChanged(new ViewerNotification(notification, notification.getNotifier(), true, false));
				return;
		}
		super.notifyChanged(notification);
	}

	/**
	 * This adds {@link org.eclipse.emf.edit.command.CommandParameter}s describing the children
	 * that can be created under this object.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	@Override
	protected void collectNewChildDescriptors(Collection<Object> newChildDescriptors, Object object) {
		super.collectNewChildDescriptors(newChildDescriptors, object);

		newChildDescriptors.add
			(createChildParameter
				(ZPSConfigurationPackage.Literals.END_POINT__INPUT_CLUSTERS,
				 ZPSConfigurationFactory.eINSTANCE.createInputCluster()));

		newChildDescriptors.add
			(createChildParameter
				(ZPSConfigurationPackage.Literals.END_POINT__OUTPUT_CLUSTERS,
				 ZPSConfigurationFactory.eINSTANCE.createOutputCluster()));
	}

	/**
	 * Return the resource locator for this item provider's resources.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	@Override
	public ResourceLocator getResourceLocator() {
		return ZPSConfigEditPlugin.INSTANCE;
	}

	/**
	 * @generated NOT
	 */
	@Override
	protected Command createAddCommand(EditingDomain domain, EObject owner,
			EStructuralFeature feature, Collection<?> collection, int index) {

		if(owner instanceof EndPoint) {
			EndPoint ownerEP = (EndPoint)owner; 

			/* prevent the ZDO input cluster from being moved */
			String name = ownerEP.getName();
			/*if (null != name && 0 == name.compareTo("ZDO")) {
				return UnexecutableCommand.INSTANCE;
			}*/
			
			/* prevent input clusters being moved between endpoints on different nodes
			 * or endpoints on the same node but with a different profile */
			for (Iterator<?> it = collection.iterator(); it.hasNext(); ) {
				Object obj = it.next();
				
				if (obj instanceof InputCluster) {
					InputCluster ic = (InputCluster)obj;
					
					if (CheckInputCluster(ic, ownerEP)) {
						return UnexecutableCommand.INSTANCE;						
					}
				}
				
				if (obj instanceof OutputCluster) {
					OutputCluster oc = (OutputCluster)obj;
					
					if (CheckOutputCluster(oc, ownerEP)) {
						return UnexecutableCommand.INSTANCE;						
					}
				}				
			}
		}
		
		return super.createAddCommand(domain, owner, feature, collection, index);
	}

	/**
	 * @generated NOT
	 */
	@Override
	protected Command createSetCommand(EditingDomain domain, EObject owner,
			EStructuralFeature feature, Object value) {
		
		if (owner instanceof EndPoint) {
			EndPoint ownerEP = (EndPoint)owner; 
			
			String name = ownerEP.getName();			
			/*if (null != name && 0 == name.compareTo("ZDO")) {
				return UnexecutableCommand.INSTANCE;
			}*/
			
			if (value instanceof ArrayList) {
				ArrayList<?> al = (ArrayList<?>)value;
				
				for (Iterator<?> it = al.iterator(); it.hasNext(); ) {
					Object obj = it.next();
					
					if (obj instanceof InputCluster) {
						if (CheckInputCluster((InputCluster)obj, ownerEP)) {
							return UnexecutableCommand.INSTANCE;							
						}
					}

					if (obj instanceof OutputCluster) {
						if (CheckOutputCluster((OutputCluster)obj, ownerEP)) {
							return UnexecutableCommand.INSTANCE;							
						}
					}
				}
			}
			
			if (value instanceof InputCluster) {
				if (CheckInputCluster((InputCluster)value, ownerEP)) {
					return UnexecutableCommand.INSTANCE;							
				}				
			}

			if (value instanceof OutputCluster) {
				if (CheckOutputCluster((OutputCluster)value, ownerEP)) {
					return UnexecutableCommand.INSTANCE;							
				}
			}

		}
		
		return super.createSetCommand(domain, owner, feature, value);
	}

	private boolean CheckInputCluster(InputCluster ic, EndPoint ownerEP) {
		EndPoint parentEP = ic.getEndPoint();
		
		if (null != ic.getCluster() && ic.getCluster().eContainer() != ownerEP.getProfile()) {
			return true;						
		}
		
		if (parentEP != null) {
			/* ensure the parent of the endpoints are the same and the cluster is of the correct profile */
			if (parentEP.getNode() != ownerEP.getNode()) {
				return true;
			}
		}
		
		/* ensure any RxAPDU is present on the containing node */
		if (null != ic.getRxAPDU() && ic.getRxAPDU().getPDUConfig().getContainerNode() != ownerEP.getNode()) {
			return true;						
		}
		
		return false;
	}

	private boolean CheckOutputCluster(OutputCluster oc, EndPoint ownerEP) {
		EndPoint parentEP = oc.getEndPoint();
		
		if (null != oc.getCluster() && oc.getCluster().eContainer() != ownerEP.getProfile()) {
			return true;						
		}
		
		if (parentEP != null) {
			/* ensure the parent of the endpoints are the same and the cluster is of the correct profile */
			if (parentEP.getNode() != ownerEP.getNode()) {
				return true;
			}
		}
		
		/* ensure any TxAPDUs are present on the containing node */
		if (null != oc.getTxAPDUs()) {
			for (Iterator<APDU> it = oc.getTxAPDUs().iterator(); it.hasNext(); ) {
				APDU apdu = it.next();
				if (apdu.getPDUConfig().getContainerNode() != ownerEP.getNode()) {
					return true;
				}				
			}
		}
		
		return false;
	}

	/**
	 * @generated NOT
	 */
	@Override
	protected Command createCreateCopyCommand(EditingDomain domain,
			EObject owner, Helper helper) {

		if (owner instanceof EndPoint) {
			String name = ((EndPoint)owner).getName();
			
			/*if (null != name && 0 == name.compareTo("ZDO")) {
				return UnexecutableCommand.INSTANCE;
			}*/
		}

		return super.createCreateCopyCommand(domain, owner, helper);
	}
	
	/**
	 * @generated NOT
	 */
	@Override
	protected Command createRemoveCommand(EditingDomain domain, EObject owner,
			EStructuralFeature feature, Collection<?> collection) {

		for (Iterator<?> iterator = collection.iterator(); iterator.hasNext();) {
			Object object = iterator.next();

			if (object instanceof InputCluster || object instanceof OutputCluster) {
				String name = ((EndPoint)owner).getName();
				
				/*if (null != name && 0 == name.compareTo("ZDO")) {
					return UnexecutableCommand.INSTANCE;
				}*/
			}
		}
		
		return super.createRemoveCommand(domain, owner, feature, collection);
	}	
		
}
