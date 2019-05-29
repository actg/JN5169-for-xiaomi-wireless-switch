/**
 * <copyright>
 * </copyright>
 *
 * $Id$
 */
package com.jennic.ZPSConfiguration.provider;



import java.util.Collection;
import java.util.List;

import org.eclipse.emf.common.notify.AdapterFactory;
import org.eclipse.emf.common.notify.Notification;

import org.eclipse.emf.ecore.EStructuralFeature;

import org.eclipse.emf.edit.provider.ComposeableAdapterFactory;
import org.eclipse.emf.edit.provider.IEditingDomainItemProvider;
import org.eclipse.emf.edit.provider.IItemLabelProvider;
import org.eclipse.emf.edit.provider.IItemPropertyDescriptor;
import org.eclipse.emf.edit.provider.IItemPropertySource;
import org.eclipse.emf.edit.provider.IStructuredItemContentProvider;
import org.eclipse.emf.edit.provider.ITreeItemContentProvider;
import org.eclipse.emf.edit.provider.ViewerNotification;

import com.jennic.ZPSConfiguration.ZDOServersCoordinator;
import com.jennic.ZPSConfiguration.ZPSConfigurationFactory;
import com.jennic.ZPSConfiguration.ZPSConfigurationPackage;

/**
 * This is the item provider adapter for a {@link com.jennic.ZPSConfiguration.ZDOServersCoordinator} object.
 * <!-- begin-user-doc -->
 * <!-- end-user-doc -->
 * @generated
 */
public class ZDOServersCoordinatorItemProvider
	extends ZDOCommonServersItemProvider {
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
	public ZDOServersCoordinatorItemProvider(AdapterFactory adapterFactory) {
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
			childrenFeatures.add(ZPSConfigurationPackage.Literals.ZDO_SERVERS_COORDINATOR__END_DEVICE_BIND_SERVER);
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
	 * This returns ZDOServersCoordinator.gif.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated NOT
	 */
	@Override
	public Object getImage(Object object) {
		return overlayImage(object, getResourceLocator().getImage("full/obj16/ZDOServers.png"));
	}

	/**
	 * This returns the label text for the adapted class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	@Override
	public String getText(Object object) {
		return getString("_UI_ZDOServersCoordinator_type");
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

		switch (notification.getFeatureID(ZDOServersCoordinator.class)) {
			case ZPSConfigurationPackage.ZDO_SERVERS_COORDINATOR__PERMIT_JOINING_SERVER:
			case ZPSConfigurationPackage.ZDO_SERVERS_COORDINATOR__MGMT_RTG_SERVER:
			case ZPSConfigurationPackage.ZDO_SERVERS_COORDINATOR__MGMT_MIB_IEEE_SERVER:
			case ZPSConfigurationPackage.ZDO_SERVERS_COORDINATOR__PARENT_ANNCE_SERVER:
			case ZPSConfigurationPackage.ZDO_SERVERS_COORDINATOR__END_DEVICE_BIND_SERVER:
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

		newChildDescriptors.add
			(createChildParameter
				(ZPSConfigurationPackage.Literals.ZDO_SERVERS_COORDINATOR__END_DEVICE_BIND_SERVER,
				 ZPSConfigurationFactory.eINSTANCE.createEndDeviceBindServer()));
	}

}
