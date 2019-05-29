/**
 * (C) Jennic Ltd 2008
 *
 * $Id$
 */
package com.jennic.ZPSConfiguration.provider;

import java.util.Collection;
import java.util.Iterator;
import java.util.List;

import org.eclipse.emf.common.command.Command;
import org.eclipse.emf.common.command.UnexecutableCommand;
import org.eclipse.emf.common.notify.AdapterFactory;
import org.eclipse.emf.common.notify.Notification;

import org.eclipse.emf.common.util.ResourceLocator;

import org.eclipse.emf.ecore.EObject;
import org.eclipse.emf.ecore.EStructuralFeature;

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

import com.jennic.ZPSConfiguration.Node;
import com.jennic.ZPSConfiguration.Profile;
import com.jennic.ZPSConfiguration.ZPSConfigurationFactory;
import com.jennic.ZPSConfiguration.ZPSConfigurationPackage;
import com.jennic.ZPSConfiguration.ZigbeeWirelessNetwork;
import com.jennic.ZPSConfiguration.provider.util.ZigbeeWirelessNetworkChildEnricher;

/**
 * This is the item provider adapter for a {@link com.jennic.ZPSConfiguration.ZigbeeWirelessNetwork} object.
 * <!-- begin-user-doc -->
 * <!-- end-user-doc -->
 * @generated
 */
public class ZigbeeWirelessNetworkItemProvider
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
	public ZigbeeWirelessNetworkItemProvider(AdapterFactory adapterFactory) {
		super(adapterFactory);
	}

	/**
	 * This returns the property descriptors for the adapted class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	@Override
	public List<IItemPropertyDescriptor> getPropertyDescriptors(Object object) {
		if (itemPropertyDescriptors == null) {
			super.getPropertyDescriptors(object);

			addDefaultExtendedPANIdPropertyDescriptor(object);
			addMaxNumberNodesPropertyDescriptor(object);
			addVersionPropertyDescriptor(object);
			addDefaultSecurityEnabledPropertyDescriptor(object);
		}
		return itemPropertyDescriptors;
	}

	/**
	 * This adds a property descriptor for the Default Extended PAN Id feature.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	protected void addDefaultExtendedPANIdPropertyDescriptor(Object object) {
		itemPropertyDescriptors.add
			(createItemPropertyDescriptor
				(((ComposeableAdapterFactory)adapterFactory).getRootAdapterFactory(),
				 getResourceLocator(),
				 getString("_UI_ZigbeeWirelessNetwork_DefaultExtendedPANId_feature"),
				 getString("_UI_PropertyDescriptor_description", "_UI_ZigbeeWirelessNetwork_DefaultExtendedPANId_feature", "_UI_ZigbeeWirelessNetwork_type"),
				 ZPSConfigurationPackage.Literals.ZIGBEE_WIRELESS_NETWORK__DEFAULT_EXTENDED_PAN_ID,
				 true,
				 false,
				 false,
				 ItemPropertyDescriptor.GENERIC_VALUE_IMAGE,
				 null,
				 null));
	}

	/**
	 * This adds a property descriptor for the Max Number Nodes feature.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	protected void addMaxNumberNodesPropertyDescriptor(Object object) {
		itemPropertyDescriptors.add
			(createItemPropertyDescriptor
				(((ComposeableAdapterFactory)adapterFactory).getRootAdapterFactory(),
				 getResourceLocator(),
				 getString("_UI_ZigbeeWirelessNetwork_MaxNumberNodes_feature"),
				 getString("_UI_PropertyDescriptor_description", "_UI_ZigbeeWirelessNetwork_MaxNumberNodes_feature", "_UI_ZigbeeWirelessNetwork_type"),
				 ZPSConfigurationPackage.Literals.ZIGBEE_WIRELESS_NETWORK__MAX_NUMBER_NODES,
				 true,
				 false,
				 false,
				 ItemPropertyDescriptor.INTEGRAL_VALUE_IMAGE,
				 null,
				 null));
	}

	/**
	 * This adds a property descriptor for the Version feature.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	protected void addVersionPropertyDescriptor(Object object) {
		itemPropertyDescriptors.add
			(createItemPropertyDescriptor
				(((ComposeableAdapterFactory)adapterFactory).getRootAdapterFactory(),
				 getResourceLocator(),
				 getString("_UI_ZigbeeWirelessNetwork_Version_feature"),
				 getString("_UI_PropertyDescriptor_description", "_UI_ZigbeeWirelessNetwork_Version_feature", "_UI_ZigbeeWirelessNetwork_type"),
				 ZPSConfigurationPackage.Literals.ZIGBEE_WIRELESS_NETWORK__VERSION,
				 true,
				 false,
				 false,
				 ItemPropertyDescriptor.GENERIC_VALUE_IMAGE,
				 null,
				 new String[] {
					"com.jennic.internal"
				 }));
	}

	/**
	 * This adds a property descriptor for the Default Security Enabled feature.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	protected void addDefaultSecurityEnabledPropertyDescriptor(Object object) {
		itemPropertyDescriptors.add
			(createItemPropertyDescriptor
				(((ComposeableAdapterFactory)adapterFactory).getRootAdapterFactory(),
				 getResourceLocator(),
				 getString("_UI_ZigbeeWirelessNetwork_DefaultSecurityEnabled_feature"),
				 getString("_UI_PropertyDescriptor_description", "_UI_ZigbeeWirelessNetwork_DefaultSecurityEnabled_feature", "_UI_ZigbeeWirelessNetwork_type"),
				 ZPSConfigurationPackage.Literals.ZIGBEE_WIRELESS_NETWORK__DEFAULT_SECURITY_ENABLED,
				 true,
				 false,
				 false,
				 ItemPropertyDescriptor.BOOLEAN_VALUE_IMAGE,
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
			childrenFeatures.add(ZPSConfigurationPackage.Literals.ZIGBEE_WIRELESS_NETWORK__PROFILES);
			childrenFeatures.add(ZPSConfigurationPackage.Literals.ZIGBEE_WIRELESS_NETWORK__COORDINATOR);
			childrenFeatures.add(ZPSConfigurationPackage.Literals.ZIGBEE_WIRELESS_NETWORK__CHILD_NODES);
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
	 * This returns ZigbeeWirelessNetwork.gif.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated NOT
	 */
	@Override
	public Object getImage(Object object) {
		return overlayImage(object, getResourceLocator().getImage("full/obj16/ZigbeeWirelessNetwork.png"));
	}

	/**
	 * This returns the label text for the adapted class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated NOT
	 */
	@Override
	public String getText(Object object) {
/*
		BigInteger labelValue = (BigInteger) ((ZigbeeWirelessNetwork)object).getExtendedPANId();
		String numberStr = "";
		
		if (null != labelValue) {
			numberStr = labelValue.toString(16).toUpperCase();
		
			while (numberStr.length() < 16) {
				numberStr = "0" + numberStr;
			}
		}
		
		String label = labelValue == null ? null : "(Extended PAN Id = 0x" + numberStr + ")";
*/
		String label = null;
		return label == null || label.length() == 0 ?
			getString("_UI_ZigbeeWirelessNetwork_type") :
			getString("_UI_ZigbeeWirelessNetwork_type") + " " + label;
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

		switch (notification.getFeatureID(ZigbeeWirelessNetwork.class)) {
			case ZPSConfigurationPackage.ZIGBEE_WIRELESS_NETWORK__DEFAULT_EXTENDED_PAN_ID:
			case ZPSConfigurationPackage.ZIGBEE_WIRELESS_NETWORK__MAX_NUMBER_NODES:
			case ZPSConfigurationPackage.ZIGBEE_WIRELESS_NETWORK__VERSION:
			case ZPSConfigurationPackage.ZIGBEE_WIRELESS_NETWORK__DEFAULT_SECURITY_ENABLED:
				fireNotifyChanged(new ViewerNotification(notification, notification.getNotifier(), false, true));
				return;
			case ZPSConfigurationPackage.ZIGBEE_WIRELESS_NETWORK__PROFILES:
			case ZPSConfigurationPackage.ZIGBEE_WIRELESS_NETWORK__COORDINATOR:
			case ZPSConfigurationPackage.ZIGBEE_WIRELESS_NETWORK__CHILD_NODES:
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
				(ZPSConfigurationPackage.Literals.ZIGBEE_WIRELESS_NETWORK__PROFILES,
				 ZPSConfigurationFactory.eINSTANCE.createProfile()));

		newChildDescriptors.add
			(createChildParameter
				(ZPSConfigurationPackage.Literals.ZIGBEE_WIRELESS_NETWORK__COORDINATOR,
				 ZPSConfigurationFactory.eINSTANCE.createCoordinator()));

		newChildDescriptors.add
			(createChildParameter
				(ZPSConfigurationPackage.Literals.ZIGBEE_WIRELESS_NETWORK__CHILD_NODES,
				 ZPSConfigurationFactory.eINSTANCE.createRouter()));

		newChildDescriptors.add
			(createChildParameter
				(ZPSConfigurationPackage.Literals.ZIGBEE_WIRELESS_NETWORK__CHILD_NODES,
				 ZPSConfigurationFactory.eINSTANCE.createEndDevice()));
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

	if( owner instanceof ZigbeeWirelessNetwork) {
		ZigbeeWirelessNetworkChildEnricher e = new ZigbeeWirelessNetworkChildEnricher((ZigbeeWirelessNetwork)owner) ;
		e.enrich(collection) ;
	}

		return super.createAddCommand(domain, owner, feature, collection, index);
	}

	/**
	 * @generated NOT
	 */
	@Override
	protected Command createSetCommand(EditingDomain domain, EObject owner,
			EStructuralFeature feature, Object value) {

		if( owner instanceof ZigbeeWirelessNetwork && value instanceof Node) {
			ZigbeeWirelessNetworkChildEnricher e = new ZigbeeWirelessNetworkChildEnricher((ZigbeeWirelessNetwork)owner) ;
			e.enrich((Node)value) ;
		}

		return super.createSetCommand(domain, owner, feature, value);
	}

	/**
	 * @generated NOT
	 */
	@Override
	protected Command createRemoveCommand(EditingDomain domain, EObject owner,
			EStructuralFeature feature, Collection<?> collection) {

		for (Iterator<?> iterator = collection.iterator(); iterator.hasNext();) {
			Object object = (Object) iterator.next();

			if (object instanceof Profile) {
				String name = ((Profile)object).getName();
				
				/*if (null != name && 0 == name.compareTo("ZDP")) {
					return UnexecutableCommand.INSTANCE;
				}*/
			}
		}
		
		return super.createRemoveCommand(domain, owner, feature, collection);
	}	
}
