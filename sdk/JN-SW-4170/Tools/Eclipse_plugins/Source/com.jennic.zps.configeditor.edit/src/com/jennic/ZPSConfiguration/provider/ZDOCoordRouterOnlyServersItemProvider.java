/**
 * (C) Jennic Ltd
 *
 * $Id: ZDOCoordRouterOnlyServersItemProvider.java 78102 2016-03-24 15:35:29Z nxp29741 $
 */
package com.jennic.ZPSConfiguration.provider;


import com.jennic.ZPSConfiguration.ZDOCoordRouterOnlyServers;
import com.jennic.ZPSConfiguration.ZPSConfigurationFactory;
import com.jennic.ZPSConfiguration.ZPSConfigurationPackage;

import java.util.Collection;
import java.util.List;

import org.eclipse.emf.common.notify.AdapterFactory;
import org.eclipse.emf.common.notify.Notification;

import org.eclipse.emf.common.util.ResourceLocator;

import org.eclipse.emf.ecore.EStructuralFeature;

import org.eclipse.emf.edit.provider.ComposeableAdapterFactory;
import org.eclipse.emf.edit.provider.IEditingDomainItemProvider;
import org.eclipse.emf.edit.provider.IItemLabelProvider;
import org.eclipse.emf.edit.provider.IItemPropertyDescriptor;
import org.eclipse.emf.edit.provider.IItemPropertySource;
import org.eclipse.emf.edit.provider.IStructuredItemContentProvider;
import org.eclipse.emf.edit.provider.ITreeItemContentProvider;
import org.eclipse.emf.edit.provider.ItemProviderAdapter;
import org.eclipse.emf.edit.provider.ViewerNotification;

/**
 * This is the item provider adapter for a {@link com.jennic.ZPSConfiguration.ZDOCoordRouterOnlyServers} object.
 * <!-- begin-user-doc -->
 * <!-- end-user-doc -->
 * @generated
 */
public class ZDOCoordRouterOnlyServersItemProvider
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
	public ZDOCoordRouterOnlyServersItemProvider(AdapterFactory adapterFactory) {
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
			childrenFeatures.add(ZPSConfigurationPackage.Literals.ZDO_COORD_ROUTER_ONLY_SERVERS__PERMIT_JOINING_SERVER);
			childrenFeatures.add(ZPSConfigurationPackage.Literals.ZDO_COORD_ROUTER_ONLY_SERVERS__MGMT_RTG_SERVER);
			childrenFeatures.add(ZPSConfigurationPackage.Literals.ZDO_COORD_ROUTER_ONLY_SERVERS__MGMT_MIB_IEEE_SERVER);
			childrenFeatures.add(ZPSConfigurationPackage.Literals.ZDO_COORD_ROUTER_ONLY_SERVERS__PARENT_ANNCE_SERVER);
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
	 * This returns the label text for the adapted class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	@Override
	public String getText(Object object) {
		return getString("_UI_ZDOCoordRouterOnlyServers_type");
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

		switch (notification.getFeatureID(ZDOCoordRouterOnlyServers.class)) {
			case ZPSConfigurationPackage.ZDO_COORD_ROUTER_ONLY_SERVERS__PERMIT_JOINING_SERVER:
			case ZPSConfigurationPackage.ZDO_COORD_ROUTER_ONLY_SERVERS__MGMT_RTG_SERVER:
			case ZPSConfigurationPackage.ZDO_COORD_ROUTER_ONLY_SERVERS__MGMT_MIB_IEEE_SERVER:
			case ZPSConfigurationPackage.ZDO_COORD_ROUTER_ONLY_SERVERS__PARENT_ANNCE_SERVER:
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
				(ZPSConfigurationPackage.Literals.ZDO_COORD_ROUTER_ONLY_SERVERS__PERMIT_JOINING_SERVER,
				 ZPSConfigurationFactory.eINSTANCE.createPermitJoiningServer()));

		newChildDescriptors.add
			(createChildParameter
				(ZPSConfigurationPackage.Literals.ZDO_COORD_ROUTER_ONLY_SERVERS__MGMT_RTG_SERVER,
				 ZPSConfigurationFactory.eINSTANCE.createMgmtRtgServer()));

		newChildDescriptors.add
			(createChildParameter
				(ZPSConfigurationPackage.Literals.ZDO_COORD_ROUTER_ONLY_SERVERS__MGMT_MIB_IEEE_SERVER,
				 ZPSConfigurationFactory.eINSTANCE.createMgmtMibIeeeServer()));

		newChildDescriptors.add
			(createChildParameter
				(ZPSConfigurationPackage.Literals.ZDO_COORD_ROUTER_ONLY_SERVERS__PARENT_ANNCE_SERVER,
				 ZPSConfigurationFactory.eINSTANCE.createParentAnnceServer()));
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
