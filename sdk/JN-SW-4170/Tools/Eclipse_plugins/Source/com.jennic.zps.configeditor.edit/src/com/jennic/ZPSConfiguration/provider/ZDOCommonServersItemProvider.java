/**
 * (C) Jennic Ltd
 *
 * $Id: ZDOCommonServersItemProvider.java 78102 2016-03-24 15:35:29Z nxp29741 $
 */
package com.jennic.ZPSConfiguration.provider;



import java.util.Collection;
import java.util.List;

import org.eclipse.emf.common.command.Command;
import org.eclipse.emf.common.command.UnexecutableCommand;
import org.eclipse.emf.common.notify.AdapterFactory;
import org.eclipse.emf.common.notify.Notification;

import org.eclipse.emf.common.util.ResourceLocator;

import org.eclipse.emf.ecore.EObject;
import org.eclipse.emf.ecore.EReference;
import org.eclipse.emf.ecore.EStructuralFeature;

import org.eclipse.emf.edit.domain.EditingDomain;
import org.eclipse.emf.edit.provider.ComposeableAdapterFactory;
import org.eclipse.emf.edit.provider.IEditingDomainItemProvider;
import org.eclipse.emf.edit.provider.IItemLabelProvider;
import org.eclipse.emf.edit.provider.IItemPropertyDescriptor;
import org.eclipse.emf.edit.provider.IItemPropertySource;
import org.eclipse.emf.edit.provider.IStructuredItemContentProvider;
import org.eclipse.emf.edit.provider.ITreeItemContentProvider;
import org.eclipse.emf.edit.provider.ItemProviderAdapter;
import org.eclipse.emf.edit.provider.ViewerNotification;

import com.jennic.ZPSConfiguration.ZDOCommonServers;
import com.jennic.ZPSConfiguration.ZPSConfigurationFactory;
import com.jennic.ZPSConfiguration.ZPSConfigurationPackage;

/**
 * This is the item provider adapter for a {@link com.jennic.ZPSConfiguration.ZDOCommonServers} object.
 * <!-- begin-user-doc -->
 * <!-- end-user-doc -->
 * @generated
 */
public class ZDOCommonServersItemProvider
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
	public ZDOCommonServersItemProvider(AdapterFactory adapterFactory) {
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
			childrenFeatures.add(ZPSConfigurationPackage.Literals.ZDO_COMMON_SERVERS__DEFAULT_SERVER);
			childrenFeatures.add(ZPSConfigurationPackage.Literals.ZDO_COMMON_SERVERS__ZDO_CLIENT);
			childrenFeatures.add(ZPSConfigurationPackage.Literals.ZDO_COMMON_SERVERS__DEVICE_ANNCE_SERVER);
			childrenFeatures.add(ZPSConfigurationPackage.Literals.ZDO_COMMON_SERVERS__ACTIVE_EP_SERVER);
			childrenFeatures.add(ZPSConfigurationPackage.Literals.ZDO_COMMON_SERVERS__NWK_ADDR_SERVER);
			childrenFeatures.add(ZPSConfigurationPackage.Literals.ZDO_COMMON_SERVERS__IEEE_ADDR_SERVER);
			childrenFeatures.add(ZPSConfigurationPackage.Literals.ZDO_COMMON_SERVERS__SYSTEM_SERVER_DISCOVERY_SERVER);
			childrenFeatures.add(ZPSConfigurationPackage.Literals.ZDO_COMMON_SERVERS__NODE_DESC_SERVER);
			childrenFeatures.add(ZPSConfigurationPackage.Literals.ZDO_COMMON_SERVERS__POWER_DESC_SERVER);
			childrenFeatures.add(ZPSConfigurationPackage.Literals.ZDO_COMMON_SERVERS__MATCH_DESC_SERVER);
			childrenFeatures.add(ZPSConfigurationPackage.Literals.ZDO_COMMON_SERVERS__SIMPLE_DESC_SERVER);
			childrenFeatures.add(ZPSConfigurationPackage.Literals.ZDO_COMMON_SERVERS__MGMT_LQI_SERVER);
			childrenFeatures.add(ZPSConfigurationPackage.Literals.ZDO_COMMON_SERVERS__MGMT_LEAVE_SERVER);
			childrenFeatures.add(ZPSConfigurationPackage.Literals.ZDO_COMMON_SERVERS__MGMT_NWK_UPDATE_SERVER);
			childrenFeatures.add(ZPSConfigurationPackage.Literals.ZDO_COMMON_SERVERS__BIND_UNBIND_SERVER);
			childrenFeatures.add(ZPSConfigurationPackage.Literals.ZDO_COMMON_SERVERS__EXTENDED_ACTIVE_EP_SERVER);
			childrenFeatures.add(ZPSConfigurationPackage.Literals.ZDO_COMMON_SERVERS__EXTENDED_SIMPLE_DESC_SERVER);
			childrenFeatures.add(ZPSConfigurationPackage.Literals.ZDO_COMMON_SERVERS__BIND_REQUEST_SERVER);
			childrenFeatures.add(ZPSConfigurationPackage.Literals.ZDO_COMMON_SERVERS__MGMT_BIND_SERVER);
			childrenFeatures.add(ZPSConfigurationPackage.Literals.ZDO_COMMON_SERVERS__MGMT_NWK_ENHANCE_UPDATE_SERVER);
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
		return getString("_UI_ZDOCommonServers_type");
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

		switch (notification.getFeatureID(ZDOCommonServers.class)) {
			case ZPSConfigurationPackage.ZDO_COMMON_SERVERS__DEFAULT_SERVER:
			case ZPSConfigurationPackage.ZDO_COMMON_SERVERS__ZDO_CLIENT:
			case ZPSConfigurationPackage.ZDO_COMMON_SERVERS__DEVICE_ANNCE_SERVER:
			case ZPSConfigurationPackage.ZDO_COMMON_SERVERS__ACTIVE_EP_SERVER:
			case ZPSConfigurationPackage.ZDO_COMMON_SERVERS__NWK_ADDR_SERVER:
			case ZPSConfigurationPackage.ZDO_COMMON_SERVERS__IEEE_ADDR_SERVER:
			case ZPSConfigurationPackage.ZDO_COMMON_SERVERS__SYSTEM_SERVER_DISCOVERY_SERVER:
			case ZPSConfigurationPackage.ZDO_COMMON_SERVERS__NODE_DESC_SERVER:
			case ZPSConfigurationPackage.ZDO_COMMON_SERVERS__POWER_DESC_SERVER:
			case ZPSConfigurationPackage.ZDO_COMMON_SERVERS__MATCH_DESC_SERVER:
			case ZPSConfigurationPackage.ZDO_COMMON_SERVERS__SIMPLE_DESC_SERVER:
			case ZPSConfigurationPackage.ZDO_COMMON_SERVERS__MGMT_LQI_SERVER:
			case ZPSConfigurationPackage.ZDO_COMMON_SERVERS__MGMT_LEAVE_SERVER:
			case ZPSConfigurationPackage.ZDO_COMMON_SERVERS__MGMT_NWK_UPDATE_SERVER:
			case ZPSConfigurationPackage.ZDO_COMMON_SERVERS__BIND_UNBIND_SERVER:
			case ZPSConfigurationPackage.ZDO_COMMON_SERVERS__EXTENDED_ACTIVE_EP_SERVER:
			case ZPSConfigurationPackage.ZDO_COMMON_SERVERS__EXTENDED_SIMPLE_DESC_SERVER:
			case ZPSConfigurationPackage.ZDO_COMMON_SERVERS__BIND_REQUEST_SERVER:
			case ZPSConfigurationPackage.ZDO_COMMON_SERVERS__MGMT_BIND_SERVER:
			case ZPSConfigurationPackage.ZDO_COMMON_SERVERS__MGMT_NWK_ENHANCE_UPDATE_SERVER:
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
				(ZPSConfigurationPackage.Literals.ZDO_COMMON_SERVERS__DEFAULT_SERVER,
				 ZPSConfigurationFactory.eINSTANCE.createDefaultServer()));

		newChildDescriptors.add
			(createChildParameter
				(ZPSConfigurationPackage.Literals.ZDO_COMMON_SERVERS__ZDO_CLIENT,
				 ZPSConfigurationFactory.eINSTANCE.createZdoClient()));

		newChildDescriptors.add
			(createChildParameter
				(ZPSConfigurationPackage.Literals.ZDO_COMMON_SERVERS__DEVICE_ANNCE_SERVER,
				 ZPSConfigurationFactory.eINSTANCE.createDeviceAnnceServer()));

		newChildDescriptors.add
			(createChildParameter
				(ZPSConfigurationPackage.Literals.ZDO_COMMON_SERVERS__ACTIVE_EP_SERVER,
				 ZPSConfigurationFactory.eINSTANCE.createActiveEpServer()));

		newChildDescriptors.add
			(createChildParameter
				(ZPSConfigurationPackage.Literals.ZDO_COMMON_SERVERS__NWK_ADDR_SERVER,
				 ZPSConfigurationFactory.eINSTANCE.createNwkAddrServer()));

		newChildDescriptors.add
			(createChildParameter
				(ZPSConfigurationPackage.Literals.ZDO_COMMON_SERVERS__IEEE_ADDR_SERVER,
				 ZPSConfigurationFactory.eINSTANCE.createIeeeAddrServer()));

		newChildDescriptors.add
			(createChildParameter
				(ZPSConfigurationPackage.Literals.ZDO_COMMON_SERVERS__SYSTEM_SERVER_DISCOVERY_SERVER,
				 ZPSConfigurationFactory.eINSTANCE.createSystemServerDiscoveryServer()));

		newChildDescriptors.add
			(createChildParameter
				(ZPSConfigurationPackage.Literals.ZDO_COMMON_SERVERS__NODE_DESC_SERVER,
				 ZPSConfigurationFactory.eINSTANCE.createNodeDescServer()));

		newChildDescriptors.add
			(createChildParameter
				(ZPSConfigurationPackage.Literals.ZDO_COMMON_SERVERS__POWER_DESC_SERVER,
				 ZPSConfigurationFactory.eINSTANCE.createPowerDescServer()));

		newChildDescriptors.add
			(createChildParameter
				(ZPSConfigurationPackage.Literals.ZDO_COMMON_SERVERS__MATCH_DESC_SERVER,
				 ZPSConfigurationFactory.eINSTANCE.createMatchDescServer()));

		newChildDescriptors.add
			(createChildParameter
				(ZPSConfigurationPackage.Literals.ZDO_COMMON_SERVERS__SIMPLE_DESC_SERVER,
				 ZPSConfigurationFactory.eINSTANCE.createSimpleDescServer()));

		newChildDescriptors.add
			(createChildParameter
				(ZPSConfigurationPackage.Literals.ZDO_COMMON_SERVERS__MGMT_LQI_SERVER,
				 ZPSConfigurationFactory.eINSTANCE.createMgmtLqiServer()));

		newChildDescriptors.add
			(createChildParameter
				(ZPSConfigurationPackage.Literals.ZDO_COMMON_SERVERS__MGMT_LEAVE_SERVER,
				 ZPSConfigurationFactory.eINSTANCE.createMgmtLeaveServer()));

		newChildDescriptors.add
			(createChildParameter
				(ZPSConfigurationPackage.Literals.ZDO_COMMON_SERVERS__MGMT_NWK_UPDATE_SERVER,
				 ZPSConfigurationFactory.eINSTANCE.createMgmtNWKUpdateServer()));

		newChildDescriptors.add
			(createChildParameter
				(ZPSConfigurationPackage.Literals.ZDO_COMMON_SERVERS__BIND_UNBIND_SERVER,
				 ZPSConfigurationFactory.eINSTANCE.createBindUnbindServer()));

		newChildDescriptors.add
			(createChildParameter
				(ZPSConfigurationPackage.Literals.ZDO_COMMON_SERVERS__EXTENDED_ACTIVE_EP_SERVER,
				 ZPSConfigurationFactory.eINSTANCE.createExtendedActiveEpServer()));

		newChildDescriptors.add
			(createChildParameter
				(ZPSConfigurationPackage.Literals.ZDO_COMMON_SERVERS__EXTENDED_SIMPLE_DESC_SERVER,
				 ZPSConfigurationFactory.eINSTANCE.createExtendedSimpleDescServer()));

		newChildDescriptors.add
			(createChildParameter
				(ZPSConfigurationPackage.Literals.ZDO_COMMON_SERVERS__BIND_REQUEST_SERVER,
				 ZPSConfigurationFactory.eINSTANCE.createBindRequestServer()));

		newChildDescriptors.add
			(createChildParameter
				(ZPSConfigurationPackage.Literals.ZDO_COMMON_SERVERS__MGMT_BIND_SERVER,
				 ZPSConfigurationFactory.eINSTANCE.createMgmtBindServer()));

		newChildDescriptors.add
			(createChildParameter
				(ZPSConfigurationPackage.Literals.ZDO_COMMON_SERVERS__MGMT_NWK_ENHANCE_UPDATE_SERVER,
				 ZPSConfigurationFactory.eINSTANCE.createMgmtNWKEnhanceUpdateServer()));
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
	protected Command createSetCommand(EditingDomain domain, EObject owner,
			EStructuralFeature feature, Object value) {
		 
		if (feature instanceof EReference){
			EReference ref = (EReference)feature;	
			
			if (
				0 == ref.getName().compareTo("DeviceAnnceServer") ||
				0 == ref.getName().compareTo("ZdoClient") ||
				0 == ref.getName().compareTo("DefaultServer")) {
								
				return UnexecutableCommand.INSTANCE;
			}			
		}
		
		return super.createSetCommand(domain, owner, feature, value);
	}	
}
