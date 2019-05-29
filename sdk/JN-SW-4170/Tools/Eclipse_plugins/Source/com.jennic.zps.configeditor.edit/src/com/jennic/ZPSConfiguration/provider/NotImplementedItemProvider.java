/**
 * (C) Jennic Ltd
 *
 * $Id: NotImplementedItemProvider.java 78102 2016-03-24 15:35:29Z nxp29741 $
 */
package com.jennic.ZPSConfiguration.provider;


import com.jennic.ZPSConfiguration.NotImplemented;
import com.jennic.ZPSConfiguration.ZPSConfigurationFactory;
import com.jennic.ZPSConfiguration.ZPSConfigurationPackage;

import java.util.Collection;
import java.util.List;

import org.eclipse.emf.common.notify.AdapterFactory;
import org.eclipse.emf.common.notify.Notification;

import org.eclipse.emf.common.util.ResourceLocator;

import org.eclipse.emf.ecore.EStructuralFeature;

import org.eclipse.emf.edit.provider.IEditingDomainItemProvider;
import org.eclipse.emf.edit.provider.IItemLabelProvider;
import org.eclipse.emf.edit.provider.IItemPropertyDescriptor;
import org.eclipse.emf.edit.provider.IItemPropertySource;
import org.eclipse.emf.edit.provider.IStructuredItemContentProvider;
import org.eclipse.emf.edit.provider.ITreeItemContentProvider;
import org.eclipse.emf.edit.provider.ItemProviderAdapter;
import org.eclipse.emf.edit.provider.ViewerNotification;

/**
 * This is the item provider adapter for a {@link com.jennic.ZPSConfiguration.NotImplemented} object.
 * <!-- begin-user-doc -->
 * <!-- end-user-doc -->
 * @generated
 */
public class NotImplementedItemProvider
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
	public NotImplementedItemProvider(AdapterFactory adapterFactory) {
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

		}
		return itemPropertyDescriptors;
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
			childrenFeatures.add(ZPSConfigurationPackage.Literals.NOT_IMPLEMENTED__COMPLEX_DESCRIPTOR);
			childrenFeatures.add(ZPSConfigurationPackage.Literals.NOT_IMPLEMENTED__DISCOVERY_TABLE);
			childrenFeatures.add(ZPSConfigurationPackage.Literals.NOT_IMPLEMENTED__DISCOVERY_CACHE);
			childrenFeatures.add(ZPSConfigurationPackage.Literals.NOT_IMPLEMENTED__BINDING_CACHE);
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
	 * This returns NotImplemented.gif.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	@Override
	public Object getImage(Object object) {
		return overlayImage(object, getResourceLocator().getImage("full/obj16/NotImplemented"));
	}

	/**
	 * This returns the label text for the adapted class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	@Override
	public String getText(Object object) {
		return getString("_UI_NotImplemented_type");
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

		switch (notification.getFeatureID(NotImplemented.class)) {
			case ZPSConfigurationPackage.NOT_IMPLEMENTED__COMPLEX_DESCRIPTOR:
			case ZPSConfigurationPackage.NOT_IMPLEMENTED__DISCOVERY_TABLE:
			case ZPSConfigurationPackage.NOT_IMPLEMENTED__DISCOVERY_CACHE:
			case ZPSConfigurationPackage.NOT_IMPLEMENTED__BINDING_CACHE:
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
				(ZPSConfigurationPackage.Literals.NOT_IMPLEMENTED__COMPLEX_DESCRIPTOR,
				 ZPSConfigurationFactory.eINSTANCE.createComplexDescriptor()));

		newChildDescriptors.add
			(createChildParameter
				(ZPSConfigurationPackage.Literals.NOT_IMPLEMENTED__DISCOVERY_TABLE,
				 ZPSConfigurationFactory.eINSTANCE.createDiscoveryTable()));

		newChildDescriptors.add
			(createChildParameter
				(ZPSConfigurationPackage.Literals.NOT_IMPLEMENTED__DISCOVERY_CACHE,
				 ZPSConfigurationFactory.eINSTANCE.createDiscoveryCache()));

		newChildDescriptors.add
			(createChildParameter
				(ZPSConfigurationPackage.Literals.NOT_IMPLEMENTED__DISCOVERY_CACHE,
				 ZPSConfigurationFactory.eINSTANCE.createPrimaryDiscoveryCache()));

		newChildDescriptors.add
			(createChildParameter
				(ZPSConfigurationPackage.Literals.NOT_IMPLEMENTED__DISCOVERY_CACHE,
				 ZPSConfigurationFactory.eINSTANCE.createBackupDiscoveryCache()));

		newChildDescriptors.add
			(createChildParameter
				(ZPSConfigurationPackage.Literals.NOT_IMPLEMENTED__BINDING_CACHE,
				 ZPSConfigurationFactory.eINSTANCE.createPrimaryBindingCache()));

		newChildDescriptors.add
			(createChildParameter
				(ZPSConfigurationPackage.Literals.NOT_IMPLEMENTED__BINDING_CACHE,
				 ZPSConfigurationFactory.eINSTANCE.createBackupBindingCache()));
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

}
