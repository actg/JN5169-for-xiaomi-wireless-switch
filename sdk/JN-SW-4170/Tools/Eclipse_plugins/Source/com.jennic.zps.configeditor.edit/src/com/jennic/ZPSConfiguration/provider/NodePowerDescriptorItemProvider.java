/**
 * (C) Jennic Ltd
 *
 * $Id: NodePowerDescriptorItemProvider.java 78102 2016-03-24 15:35:29Z nxp29741 $
 */
package com.jennic.ZPSConfiguration.provider;



import java.util.Collection;
import java.util.List;

import org.eclipse.emf.common.notify.AdapterFactory;
import org.eclipse.emf.common.notify.Notification;

import org.eclipse.emf.common.util.ResourceLocator;

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

import com.jennic.ZPSConfiguration.NodePowerDescriptor;
import com.jennic.ZPSConfiguration.ZPSConfigurationPackage;

/**
 * This is the item provider adapter for a {@link com.jennic.ZPSConfiguration.NodePowerDescriptor} object.
 * <!-- begin-user-doc -->
 * <!-- end-user-doc -->
 * @generated
 */
public class NodePowerDescriptorItemProvider
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
	public NodePowerDescriptorItemProvider(AdapterFactory adapterFactory) {
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

			addConstantPowerPropertyDescriptor(object);
			addRechargeableBatteryPropertyDescriptor(object);
			addDisposableBatteryPropertyDescriptor(object);
			addDefaultPowerSourcePropertyDescriptor(object);
			addDefaultPowerModePropertyDescriptor(object);
		}
		return itemPropertyDescriptors;
	}

	/**
	 * This adds a property descriptor for the Constant Power feature.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	protected void addConstantPowerPropertyDescriptor(Object object) {
		itemPropertyDescriptors.add
			(createItemPropertyDescriptor
				(((ComposeableAdapterFactory)adapterFactory).getRootAdapterFactory(),
				 getResourceLocator(),
				 getString("_UI_NodePowerDescriptor_ConstantPower_feature"),
				 getString("_UI_PropertyDescriptor_description", "_UI_NodePowerDescriptor_ConstantPower_feature", "_UI_NodePowerDescriptor_type"),
				 ZPSConfigurationPackage.Literals.NODE_POWER_DESCRIPTOR__CONSTANT_POWER,
				 true,
				 false,
				 false,
				 ItemPropertyDescriptor.BOOLEAN_VALUE_IMAGE,
				 getString("_UI_AvailablePowerSourcesPropertyCategory"),
				 null));
	}

	/**
	 * This adds a property descriptor for the Rechargeable Battery feature.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	protected void addRechargeableBatteryPropertyDescriptor(Object object) {
		itemPropertyDescriptors.add
			(createItemPropertyDescriptor
				(((ComposeableAdapterFactory)adapterFactory).getRootAdapterFactory(),
				 getResourceLocator(),
				 getString("_UI_NodePowerDescriptor_RechargeableBattery_feature"),
				 getString("_UI_PropertyDescriptor_description", "_UI_NodePowerDescriptor_RechargeableBattery_feature", "_UI_NodePowerDescriptor_type"),
				 ZPSConfigurationPackage.Literals.NODE_POWER_DESCRIPTOR__RECHARGEABLE_BATTERY,
				 true,
				 false,
				 false,
				 ItemPropertyDescriptor.BOOLEAN_VALUE_IMAGE,
				 getString("_UI_AvailablePowerSourcesPropertyCategory"),
				 null));
	}

	/**
	 * This adds a property descriptor for the Disposable Battery feature.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	protected void addDisposableBatteryPropertyDescriptor(Object object) {
		itemPropertyDescriptors.add
			(createItemPropertyDescriptor
				(((ComposeableAdapterFactory)adapterFactory).getRootAdapterFactory(),
				 getResourceLocator(),
				 getString("_UI_NodePowerDescriptor_DisposableBattery_feature"),
				 getString("_UI_PropertyDescriptor_description", "_UI_NodePowerDescriptor_DisposableBattery_feature", "_UI_NodePowerDescriptor_type"),
				 ZPSConfigurationPackage.Literals.NODE_POWER_DESCRIPTOR__DISPOSABLE_BATTERY,
				 true,
				 false,
				 false,
				 ItemPropertyDescriptor.BOOLEAN_VALUE_IMAGE,
				 getString("_UI_AvailablePowerSourcesPropertyCategory"),
				 null));
	}

	/**
	 * This adds a property descriptor for the Default Power Source feature.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	protected void addDefaultPowerSourcePropertyDescriptor(Object object) {
		itemPropertyDescriptors.add
			(createItemPropertyDescriptor
				(((ComposeableAdapterFactory)adapterFactory).getRootAdapterFactory(),
				 getResourceLocator(),
				 getString("_UI_NodePowerDescriptor_DefaultPowerSource_feature"),
				 getString("_UI_PropertyDescriptor_description", "_UI_NodePowerDescriptor_DefaultPowerSource_feature", "_UI_NodePowerDescriptor_type"),
				 ZPSConfigurationPackage.Literals.NODE_POWER_DESCRIPTOR__DEFAULT_POWER_SOURCE,
				 true,
				 false,
				 false,
				 ItemPropertyDescriptor.GENERIC_VALUE_IMAGE,
				 null,
				 null));
	}

	/**
	 * This adds a property descriptor for the Default Power Mode feature.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	protected void addDefaultPowerModePropertyDescriptor(Object object) {
		itemPropertyDescriptors.add
			(createItemPropertyDescriptor
				(((ComposeableAdapterFactory)adapterFactory).getRootAdapterFactory(),
				 getResourceLocator(),
				 getString("_UI_NodePowerDescriptor_DefaultPowerMode_feature"),
				 getString("_UI_PropertyDescriptor_description", "_UI_NodePowerDescriptor_DefaultPowerMode_feature", "_UI_NodePowerDescriptor_type"),
				 ZPSConfigurationPackage.Literals.NODE_POWER_DESCRIPTOR__DEFAULT_POWER_MODE,
				 true,
				 false,
				 false,
				 ItemPropertyDescriptor.GENERIC_VALUE_IMAGE,
				 null,
				 null));
	}

	/**
	 * This returns NodePowerDescriptor.gif.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated NOT
	 */
	@Override
	public Object getImage(Object object) {
		return overlayImage(object, getResourceLocator().getImage("full/obj16/NodePowerDescriptor.png"));
	}

	/**
	 * This returns the label text for the adapted class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated NOT
	 */
	@Override
	public String getText(Object object) {
		NodePowerDescriptor nodePowerDescriptor = (NodePowerDescriptor)object;
		String availPower = "";
		
		availPower += nodePowerDescriptor.isConstantPower() ? "Constant (Mains) Power" : "";
		availPower += availPower.length() > 0 && nodePowerDescriptor.isDisposableBattery() ? " + " : "";
		availPower += nodePowerDescriptor.isDisposableBattery() ? "Disposable Battery" : "";
		availPower += availPower.length() > 0 && nodePowerDescriptor.isRechargeableBattery() ? " + " : "";
		availPower += nodePowerDescriptor.isRechargeableBattery() ? "Rechargeable Battery" : "";
		
		String label = "(Default Power Mode = ";
		label += nodePowerDescriptor.getDefaultPowerMode().getLiteral();
		label += ", Default Power Source = ";
		label += nodePowerDescriptor.getDefaultPowerSource().getLiteral();
		label += ", Avalaible Power Sources = " + availPower;
		label += ")";
		
		return getString("_UI_NodePowerDescriptor_type") + " " + label;
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

		switch (notification.getFeatureID(NodePowerDescriptor.class)) {
			case ZPSConfigurationPackage.NODE_POWER_DESCRIPTOR__CONSTANT_POWER:
			case ZPSConfigurationPackage.NODE_POWER_DESCRIPTOR__RECHARGEABLE_BATTERY:
			case ZPSConfigurationPackage.NODE_POWER_DESCRIPTOR__DISPOSABLE_BATTERY:
			case ZPSConfigurationPackage.NODE_POWER_DESCRIPTOR__DEFAULT_POWER_SOURCE:
			case ZPSConfigurationPackage.NODE_POWER_DESCRIPTOR__DEFAULT_POWER_MODE:
				fireNotifyChanged(new ViewerNotification(notification, notification.getNotifier(), false, true));
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
