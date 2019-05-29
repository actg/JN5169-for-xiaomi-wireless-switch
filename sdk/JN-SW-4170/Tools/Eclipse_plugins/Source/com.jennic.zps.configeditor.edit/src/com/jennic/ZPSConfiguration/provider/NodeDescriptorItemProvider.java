/**
 * (C) Jennic Ltd
 *
 * $Id: NodeDescriptorItemProvider.java 78102 2016-03-24 15:35:29Z nxp29741 $
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

import com.jennic.ZPSConfiguration.NodeDescriptor;
import com.jennic.ZPSConfiguration.ZPSConfigurationPackage;

/**
 * This is the item provider adapter for a {@link com.jennic.ZPSConfiguration.NodeDescriptor} object.
 * <!-- begin-user-doc -->
 * <!-- end-user-doc -->
 * @generated
 */
public class NodeDescriptorItemProvider
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
	public NodeDescriptorItemProvider(AdapterFactory adapterFactory) {
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

			addManufacturerCodePropertyDescriptor(object);
			addLogicalTypePropertyDescriptor(object);
			addComplexDescriptorAvailablePropertyDescriptor(object);
			addUserDescriptorAvailablePropertyDescriptor(object);
			addAPSFlagsPropertyDescriptor(object);
			addFrequencyBandPropertyDescriptor(object);
			addAlternatePANCoordinatorPropertyDescriptor(object);
			addDeviceTypePropertyDescriptor(object);
			addPowerSourcePropertyDescriptor(object);
			addRxOnWhenIdlePropertyDescriptor(object);
			addSecurityPropertyDescriptor(object);
			addAllocateAddressPropertyDescriptor(object);
			addMaximumBufferSizePropertyDescriptor(object);
			addMaximumIncomingTransferSizePropertyDescriptor(object);
			addMaximumOutgoingTransferSizePropertyDescriptor(object);
			addExtendedActiveEndpointListAvailablePropertyDescriptor(object);
			addExtendedSimpleDescriptorListAvailablePropertyDescriptor(object);
			addPrimaryTrustCenterPropertyDescriptor(object);
			addBackupTrustCenterPropertyDescriptor(object);
			addPrimaryBindingTableCachePropertyDescriptor(object);
			addBackupBindingTableCachePropertyDescriptor(object);
			addPrimaryDiscoveryCachePropertyDescriptor(object);
			addBackupDiscoveryCachePropertyDescriptor(object);
			addNetworkManagerPropertyDescriptor(object);
		}
		return itemPropertyDescriptors;
	}

	/**
	 * This adds a property descriptor for the Manufacturer Code feature.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	protected void addManufacturerCodePropertyDescriptor(Object object) {
		itemPropertyDescriptors.add
			(createItemPropertyDescriptor
				(((ComposeableAdapterFactory)adapterFactory).getRootAdapterFactory(),
				 getResourceLocator(),
				 getString("_UI_NodeDescriptor_ManufacturerCode_feature"),
				 getString("_UI_PropertyDescriptor_description", "_UI_NodeDescriptor_ManufacturerCode_feature", "_UI_NodeDescriptor_type"),
				 ZPSConfigurationPackage.Literals.NODE_DESCRIPTOR__MANUFACTURER_CODE,
				 true,
				 false,
				 false,
				 ItemPropertyDescriptor.INTEGRAL_VALUE_IMAGE,
				 null,
				 null));
	}

	/**
	 * This adds a property descriptor for the Logical Type feature.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	protected void addLogicalTypePropertyDescriptor(Object object) {
		itemPropertyDescriptors.add
			(createItemPropertyDescriptor
				(((ComposeableAdapterFactory)adapterFactory).getRootAdapterFactory(),
				 getResourceLocator(),
				 getString("_UI_NodeDescriptor_LogicalType_feature"),
				 getString("_UI_PropertyDescriptor_description", "_UI_NodeDescriptor_LogicalType_feature", "_UI_NodeDescriptor_type"),
				 ZPSConfigurationPackage.Literals.NODE_DESCRIPTOR__LOGICAL_TYPE,
				 false,
				 false,
				 false,
				 ItemPropertyDescriptor.GENERIC_VALUE_IMAGE,
				 null,
				 null));
	}

	/**
	 * This adds a property descriptor for the Complex Descriptor Available feature.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	protected void addComplexDescriptorAvailablePropertyDescriptor(Object object) {
		itemPropertyDescriptors.add
			(createItemPropertyDescriptor
				(((ComposeableAdapterFactory)adapterFactory).getRootAdapterFactory(),
				 getResourceLocator(),
				 getString("_UI_NodeDescriptor_ComplexDescriptorAvailable_feature"),
				 getString("_UI_PropertyDescriptor_description", "_UI_NodeDescriptor_ComplexDescriptorAvailable_feature", "_UI_NodeDescriptor_type"),
				 ZPSConfigurationPackage.Literals.NODE_DESCRIPTOR__COMPLEX_DESCRIPTOR_AVAILABLE,
				 false,
				 false,
				 false,
				 ItemPropertyDescriptor.BOOLEAN_VALUE_IMAGE,
				 getString("_UI_DescriptorAvailabilityPropertyCategory"),
				 null));
	}

	/**
	 * This adds a property descriptor for the User Descriptor Available feature.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	protected void addUserDescriptorAvailablePropertyDescriptor(Object object) {
		itemPropertyDescriptors.add
			(createItemPropertyDescriptor
				(((ComposeableAdapterFactory)adapterFactory).getRootAdapterFactory(),
				 getResourceLocator(),
				 getString("_UI_NodeDescriptor_UserDescriptorAvailable_feature"),
				 getString("_UI_PropertyDescriptor_description", "_UI_NodeDescriptor_UserDescriptorAvailable_feature", "_UI_NodeDescriptor_type"),
				 ZPSConfigurationPackage.Literals.NODE_DESCRIPTOR__USER_DESCRIPTOR_AVAILABLE,
				 false,
				 false,
				 false,
				 ItemPropertyDescriptor.BOOLEAN_VALUE_IMAGE,
				 getString("_UI_DescriptorAvailabilityPropertyCategory"),
				 null));
	}

	/**
	 * This adds a property descriptor for the APS Flags feature.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	protected void addAPSFlagsPropertyDescriptor(Object object) {
		itemPropertyDescriptors.add
			(createItemPropertyDescriptor
				(((ComposeableAdapterFactory)adapterFactory).getRootAdapterFactory(),
				 getResourceLocator(),
				 getString("_UI_NodeDescriptor_APSFlags_feature"),
				 getString("_UI_PropertyDescriptor_description", "_UI_NodeDescriptor_APSFlags_feature", "_UI_NodeDescriptor_type"),
				 ZPSConfigurationPackage.Literals.NODE_DESCRIPTOR__APS_FLAGS,
				 false,
				 false,
				 false,
				 ItemPropertyDescriptor.GENERIC_VALUE_IMAGE,
				 null,
				 null));
	}

	/**
	 * This adds a property descriptor for the Frequency Band feature.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	protected void addFrequencyBandPropertyDescriptor(Object object) {
		itemPropertyDescriptors.add
			(createItemPropertyDescriptor
				(((ComposeableAdapterFactory)adapterFactory).getRootAdapterFactory(),
				 getResourceLocator(),
				 getString("_UI_NodeDescriptor_FrequencyBand_feature"),
				 getString("_UI_PropertyDescriptor_description", "_UI_NodeDescriptor_FrequencyBand_feature", "_UI_NodeDescriptor_type"),
				 ZPSConfigurationPackage.Literals.NODE_DESCRIPTOR__FREQUENCY_BAND,
				 false,
				 false,
				 false,
				 ItemPropertyDescriptor.GENERIC_VALUE_IMAGE,
				 null,
				 null));
	}

	/**
	 * This adds a property descriptor for the Alternate PAN Coordinator feature.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	protected void addAlternatePANCoordinatorPropertyDescriptor(Object object) {
		itemPropertyDescriptors.add
			(createItemPropertyDescriptor
				(((ComposeableAdapterFactory)adapterFactory).getRootAdapterFactory(),
				 getResourceLocator(),
				 getString("_UI_NodeDescriptor_AlternatePANCoordinator_feature"),
				 getString("_UI_NodeDescriptor_AlternatePANCoordinator_description"),
				 ZPSConfigurationPackage.Literals.NODE_DESCRIPTOR__ALTERNATE_PAN_COORDINATOR,
				 false,
				 false,
				 false,
				 ItemPropertyDescriptor.BOOLEAN_VALUE_IMAGE,
				 getString("_UI_MACCapabilityFlagsPropertyCategory"),
				 null));
	}

	/**
	 * This adds a property descriptor for the Device Type feature.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	protected void addDeviceTypePropertyDescriptor(Object object) {
		itemPropertyDescriptors.add
			(createItemPropertyDescriptor
				(((ComposeableAdapterFactory)adapterFactory).getRootAdapterFactory(),
				 getResourceLocator(),
				 getString("_UI_NodeDescriptor_DeviceType_feature"),
				 getString("_UI_NodeDescriptor_DeviceType_description"),
				 ZPSConfigurationPackage.Literals.NODE_DESCRIPTOR__DEVICE_TYPE,
				 false,
				 false,
				 false,
				 ItemPropertyDescriptor.BOOLEAN_VALUE_IMAGE,
				 getString("_UI_MACCapabilityFlagsPropertyCategory"),
				 null));
	}

	/**
	 * This adds a property descriptor for the Power Source feature.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	protected void addPowerSourcePropertyDescriptor(Object object) {
		itemPropertyDescriptors.add
			(createItemPropertyDescriptor
				(((ComposeableAdapterFactory)adapterFactory).getRootAdapterFactory(),
				 getResourceLocator(),
				 getString("_UI_NodeDescriptor_PowerSource_feature"),
				 getString("_UI_NodeDescriptor_PowerSource_description"),
				 ZPSConfigurationPackage.Literals.NODE_DESCRIPTOR__POWER_SOURCE,
				 false,
				 false,
				 false,
				 ItemPropertyDescriptor.BOOLEAN_VALUE_IMAGE,
				 getString("_UI_MACCapabilityFlagsPropertyCategory"),
				 null));
	}

	/**
	 * This adds a property descriptor for the Rx On When Idle feature.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	protected void addRxOnWhenIdlePropertyDescriptor(Object object) {
		itemPropertyDescriptors.add
			(createItemPropertyDescriptor
				(((ComposeableAdapterFactory)adapterFactory).getRootAdapterFactory(),
				 getResourceLocator(),
				 getString("_UI_NodeDescriptor_RxOnWhenIdle_feature"),
				 getString("_UI_NodeDescriptor_RxOnWhenIdle_description"),
				 ZPSConfigurationPackage.Literals.NODE_DESCRIPTOR__RX_ON_WHEN_IDLE,
				 false,
				 false,
				 false,
				 ItemPropertyDescriptor.BOOLEAN_VALUE_IMAGE,
				 getString("_UI_MACCapabilityFlagsPropertyCategory"),
				 null));
	}

	/**
	 * This adds a property descriptor for the Security feature.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	protected void addSecurityPropertyDescriptor(Object object) {
		itemPropertyDescriptors.add
			(createItemPropertyDescriptor
				(((ComposeableAdapterFactory)adapterFactory).getRootAdapterFactory(),
				 getResourceLocator(),
				 getString("_UI_NodeDescriptor_Security_feature"),
				 getString("_UI_NodeDescriptor_Security_description"),
				 ZPSConfigurationPackage.Literals.NODE_DESCRIPTOR__SECURITY,
				 false,
				 false,
				 false,
				 ItemPropertyDescriptor.BOOLEAN_VALUE_IMAGE,
				 getString("_UI_MACCapabilityFlagsPropertyCategory"),
				 null));
	}

	/**
	 * This adds a property descriptor for the Allocate Address feature.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	protected void addAllocateAddressPropertyDescriptor(Object object) {
		itemPropertyDescriptors.add
			(createItemPropertyDescriptor
				(((ComposeableAdapterFactory)adapterFactory).getRootAdapterFactory(),
				 getResourceLocator(),
				 getString("_UI_NodeDescriptor_AllocateAddress_feature"),
				 getString("_UI_NodeDescriptor_AllocateAddress_description"),
				 ZPSConfigurationPackage.Literals.NODE_DESCRIPTOR__ALLOCATE_ADDRESS,
				 true,
				 false,
				 false,
				 ItemPropertyDescriptor.BOOLEAN_VALUE_IMAGE,
				 getString("_UI_MACCapabilityFlagsPropertyCategory"),
				 null));
	}

	/**
	 * This adds a property descriptor for the Maximum Buffer Size feature.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	protected void addMaximumBufferSizePropertyDescriptor(Object object) {
		itemPropertyDescriptors.add
			(createItemPropertyDescriptor
				(((ComposeableAdapterFactory)adapterFactory).getRootAdapterFactory(),
				 getResourceLocator(),
				 getString("_UI_NodeDescriptor_MaximumBufferSize_feature"),
				 getString("_UI_PropertyDescriptor_description", "_UI_NodeDescriptor_MaximumBufferSize_feature", "_UI_NodeDescriptor_type"),
				 ZPSConfigurationPackage.Literals.NODE_DESCRIPTOR__MAXIMUM_BUFFER_SIZE,
				 false,
				 false,
				 false,
				 ItemPropertyDescriptor.GENERIC_VALUE_IMAGE,
				 null,
				 null));
	}

	/**
	 * This adds a property descriptor for the Maximum Incoming Transfer Size feature.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	protected void addMaximumIncomingTransferSizePropertyDescriptor(Object object) {
		itemPropertyDescriptors.add
			(createItemPropertyDescriptor
				(((ComposeableAdapterFactory)adapterFactory).getRootAdapterFactory(),
				 getResourceLocator(),
				 getString("_UI_NodeDescriptor_MaximumIncomingTransferSize_feature"),
				 getString("_UI_PropertyDescriptor_description", "_UI_NodeDescriptor_MaximumIncomingTransferSize_feature", "_UI_NodeDescriptor_type"),
				 ZPSConfigurationPackage.Literals.NODE_DESCRIPTOR__MAXIMUM_INCOMING_TRANSFER_SIZE,
				 false,
				 false,
				 false,
				 ItemPropertyDescriptor.INTEGRAL_VALUE_IMAGE,
				 null,
				 null));
	}

	/**
	 * This adds a property descriptor for the Maximum Outgoing Transfer Size feature.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	protected void addMaximumOutgoingTransferSizePropertyDescriptor(Object object) {
		itemPropertyDescriptors.add
			(createItemPropertyDescriptor
				(((ComposeableAdapterFactory)adapterFactory).getRootAdapterFactory(),
				 getResourceLocator(),
				 getString("_UI_NodeDescriptor_MaximumOutgoingTransferSize_feature"),
				 getString("_UI_PropertyDescriptor_description", "_UI_NodeDescriptor_MaximumOutgoingTransferSize_feature", "_UI_NodeDescriptor_type"),
				 ZPSConfigurationPackage.Literals.NODE_DESCRIPTOR__MAXIMUM_OUTGOING_TRANSFER_SIZE,
				 false,
				 false,
				 false,
				 ItemPropertyDescriptor.INTEGRAL_VALUE_IMAGE,
				 null,
				 null));
	}

	/**
	 * This adds a property descriptor for the Extended Active Endpoint List Available feature.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	protected void addExtendedActiveEndpointListAvailablePropertyDescriptor(Object object) {
		itemPropertyDescriptors.add
			(createItemPropertyDescriptor
				(((ComposeableAdapterFactory)adapterFactory).getRootAdapterFactory(),
				 getResourceLocator(),
				 getString("_UI_NodeDescriptor_ExtendedActiveEndpointListAvailable_feature"),
				 getString("_UI_PropertyDescriptor_description", "_UI_NodeDescriptor_ExtendedActiveEndpointListAvailable_feature", "_UI_NodeDescriptor_type"),
				 ZPSConfigurationPackage.Literals.NODE_DESCRIPTOR__EXTENDED_ACTIVE_ENDPOINT_LIST_AVAILABLE,
				 false,
				 false,
				 false,
				 ItemPropertyDescriptor.BOOLEAN_VALUE_IMAGE,
				 getString("_UI_DescriptorCapabilitiesPropertyCategory"),
				 null));
	}

	/**
	 * This adds a property descriptor for the Extended Simple Descriptor List Available feature.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	protected void addExtendedSimpleDescriptorListAvailablePropertyDescriptor(Object object) {
		itemPropertyDescriptors.add
			(createItemPropertyDescriptor
				(((ComposeableAdapterFactory)adapterFactory).getRootAdapterFactory(),
				 getResourceLocator(),
				 getString("_UI_NodeDescriptor_ExtendedSimpleDescriptorListAvailable_feature"),
				 getString("_UI_PropertyDescriptor_description", "_UI_NodeDescriptor_ExtendedSimpleDescriptorListAvailable_feature", "_UI_NodeDescriptor_type"),
				 ZPSConfigurationPackage.Literals.NODE_DESCRIPTOR__EXTENDED_SIMPLE_DESCRIPTOR_LIST_AVAILABLE,
				 false,
				 false,
				 false,
				 ItemPropertyDescriptor.BOOLEAN_VALUE_IMAGE,
				 getString("_UI_DescriptorCapabilitiesPropertyCategory"),
				 null));
	}

	/**
	 * This adds a property descriptor for the Primary Trust Center feature.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	protected void addPrimaryTrustCenterPropertyDescriptor(Object object) {
		itemPropertyDescriptors.add
			(createItemPropertyDescriptor
				(((ComposeableAdapterFactory)adapterFactory).getRootAdapterFactory(),
				 getResourceLocator(),
				 getString("_UI_NodeDescriptor_PrimaryTrustCenter_feature"),
				 getString("_UI_PropertyDescriptor_description", "_UI_NodeDescriptor_PrimaryTrustCenter_feature", "_UI_NodeDescriptor_type"),
				 ZPSConfigurationPackage.Literals.NODE_DESCRIPTOR__PRIMARY_TRUST_CENTER,
				 false,
				 false,
				 false,
				 ItemPropertyDescriptor.BOOLEAN_VALUE_IMAGE,
				 getString("_UI_SystemServerCapabilitiesPropertyCategory"),
				 null));
	}

	/**
	 * This adds a property descriptor for the Backup Trust Center feature.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	protected void addBackupTrustCenterPropertyDescriptor(Object object) {
		itemPropertyDescriptors.add
			(createItemPropertyDescriptor
				(((ComposeableAdapterFactory)adapterFactory).getRootAdapterFactory(),
				 getResourceLocator(),
				 getString("_UI_NodeDescriptor_BackupTrustCenter_feature"),
				 getString("_UI_PropertyDescriptor_description", "_UI_NodeDescriptor_BackupTrustCenter_feature", "_UI_NodeDescriptor_type"),
				 ZPSConfigurationPackage.Literals.NODE_DESCRIPTOR__BACKUP_TRUST_CENTER,
				 false,
				 false,
				 false,
				 ItemPropertyDescriptor.BOOLEAN_VALUE_IMAGE,
				 getString("_UI_SystemServerCapabilitiesPropertyCategory"),
				 null));
	}

	/**
	 * This adds a property descriptor for the Primary Binding Table Cache feature.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	protected void addPrimaryBindingTableCachePropertyDescriptor(Object object) {
		itemPropertyDescriptors.add
			(createItemPropertyDescriptor
				(((ComposeableAdapterFactory)adapterFactory).getRootAdapterFactory(),
				 getResourceLocator(),
				 getString("_UI_NodeDescriptor_PrimaryBindingTableCache_feature"),
				 getString("_UI_PropertyDescriptor_description", "_UI_NodeDescriptor_PrimaryBindingTableCache_feature", "_UI_NodeDescriptor_type"),
				 ZPSConfigurationPackage.Literals.NODE_DESCRIPTOR__PRIMARY_BINDING_TABLE_CACHE,
				 false,
				 false,
				 false,
				 ItemPropertyDescriptor.BOOLEAN_VALUE_IMAGE,
				 getString("_UI_SystemServerCapabilitiesPropertyCategory"),
				 null));
	}

	/**
	 * This adds a property descriptor for the Backup Binding Table Cache feature.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	protected void addBackupBindingTableCachePropertyDescriptor(Object object) {
		itemPropertyDescriptors.add
			(createItemPropertyDescriptor
				(((ComposeableAdapterFactory)adapterFactory).getRootAdapterFactory(),
				 getResourceLocator(),
				 getString("_UI_NodeDescriptor_BackupBindingTableCache_feature"),
				 getString("_UI_PropertyDescriptor_description", "_UI_NodeDescriptor_BackupBindingTableCache_feature", "_UI_NodeDescriptor_type"),
				 ZPSConfigurationPackage.Literals.NODE_DESCRIPTOR__BACKUP_BINDING_TABLE_CACHE,
				 false,
				 false,
				 false,
				 ItemPropertyDescriptor.BOOLEAN_VALUE_IMAGE,
				 getString("_UI_SystemServerCapabilitiesPropertyCategory"),
				 null));
	}

	/**
	 * This adds a property descriptor for the Primary Discovery Cache feature.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	protected void addPrimaryDiscoveryCachePropertyDescriptor(Object object) {
		itemPropertyDescriptors.add
			(createItemPropertyDescriptor
				(((ComposeableAdapterFactory)adapterFactory).getRootAdapterFactory(),
				 getResourceLocator(),
				 getString("_UI_NodeDescriptor_PrimaryDiscoveryCache_feature"),
				 getString("_UI_PropertyDescriptor_description", "_UI_NodeDescriptor_PrimaryDiscoveryCache_feature", "_UI_NodeDescriptor_type"),
				 ZPSConfigurationPackage.Literals.NODE_DESCRIPTOR__PRIMARY_DISCOVERY_CACHE,
				 false,
				 false,
				 false,
				 ItemPropertyDescriptor.BOOLEAN_VALUE_IMAGE,
				 getString("_UI_SystemServerCapabilitiesPropertyCategory"),
				 null));
	}

	/**
	 * This adds a property descriptor for the Backup Discovery Cache feature.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	protected void addBackupDiscoveryCachePropertyDescriptor(Object object) {
		itemPropertyDescriptors.add
			(createItemPropertyDescriptor
				(((ComposeableAdapterFactory)adapterFactory).getRootAdapterFactory(),
				 getResourceLocator(),
				 getString("_UI_NodeDescriptor_BackupDiscoveryCache_feature"),
				 getString("_UI_PropertyDescriptor_description", "_UI_NodeDescriptor_BackupDiscoveryCache_feature", "_UI_NodeDescriptor_type"),
				 ZPSConfigurationPackage.Literals.NODE_DESCRIPTOR__BACKUP_DISCOVERY_CACHE,
				 false,
				 false,
				 false,
				 ItemPropertyDescriptor.BOOLEAN_VALUE_IMAGE,
				 getString("_UI_SystemServerCapabilitiesPropertyCategory"),
				 null));
	}

	/**
	 * This adds a property descriptor for the Network Manager feature.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	protected void addNetworkManagerPropertyDescriptor(Object object) {
		itemPropertyDescriptors.add
			(createItemPropertyDescriptor
				(((ComposeableAdapterFactory)adapterFactory).getRootAdapterFactory(),
				 getResourceLocator(),
				 getString("_UI_NodeDescriptor_NetworkManager_feature"),
				 getString("_UI_PropertyDescriptor_description", "_UI_NodeDescriptor_NetworkManager_feature", "_UI_NodeDescriptor_type"),
				 ZPSConfigurationPackage.Literals.NODE_DESCRIPTOR__NETWORK_MANAGER,
				 false,
				 false,
				 false,
				 ItemPropertyDescriptor.BOOLEAN_VALUE_IMAGE,
				 getString("_UI_SystemServerCapabilitiesPropertyCategory"),
				 null));
	}

	/**
	 * This returns NodeDescriptor.gif.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated NOT
	 */
	@Override
	public Object getImage(Object object) {
		return overlayImage(object, getResourceLocator().getImage("full/obj16/NodeDescriptor.png"));
	}

	/**
	 * This returns the label text for the adapted class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated NOT
	 */
	@Override
	public String getText(Object object) {
		NodeDescriptor nodeDescriptor = (NodeDescriptor)object;
		String label = "(Manufacturer Code = " + nodeDescriptor.getManufacturerCode();
		label += ")";
		
		return getString("_UI_NodeDescriptor_type") + " " + label;
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

		switch (notification.getFeatureID(NodeDescriptor.class)) {
			case ZPSConfigurationPackage.NODE_DESCRIPTOR__MANUFACTURER_CODE:
			case ZPSConfigurationPackage.NODE_DESCRIPTOR__LOGICAL_TYPE:
			case ZPSConfigurationPackage.NODE_DESCRIPTOR__COMPLEX_DESCRIPTOR_AVAILABLE:
			case ZPSConfigurationPackage.NODE_DESCRIPTOR__USER_DESCRIPTOR_AVAILABLE:
			case ZPSConfigurationPackage.NODE_DESCRIPTOR__APS_FLAGS:
			case ZPSConfigurationPackage.NODE_DESCRIPTOR__FREQUENCY_BAND:
			case ZPSConfigurationPackage.NODE_DESCRIPTOR__ALTERNATE_PAN_COORDINATOR:
			case ZPSConfigurationPackage.NODE_DESCRIPTOR__DEVICE_TYPE:
			case ZPSConfigurationPackage.NODE_DESCRIPTOR__POWER_SOURCE:
			case ZPSConfigurationPackage.NODE_DESCRIPTOR__RX_ON_WHEN_IDLE:
			case ZPSConfigurationPackage.NODE_DESCRIPTOR__SECURITY:
			case ZPSConfigurationPackage.NODE_DESCRIPTOR__ALLOCATE_ADDRESS:
			case ZPSConfigurationPackage.NODE_DESCRIPTOR__MAXIMUM_BUFFER_SIZE:
			case ZPSConfigurationPackage.NODE_DESCRIPTOR__MAXIMUM_INCOMING_TRANSFER_SIZE:
			case ZPSConfigurationPackage.NODE_DESCRIPTOR__MAXIMUM_OUTGOING_TRANSFER_SIZE:
			case ZPSConfigurationPackage.NODE_DESCRIPTOR__EXTENDED_ACTIVE_ENDPOINT_LIST_AVAILABLE:
			case ZPSConfigurationPackage.NODE_DESCRIPTOR__EXTENDED_SIMPLE_DESCRIPTOR_LIST_AVAILABLE:
			case ZPSConfigurationPackage.NODE_DESCRIPTOR__PRIMARY_TRUST_CENTER:
			case ZPSConfigurationPackage.NODE_DESCRIPTOR__BACKUP_TRUST_CENTER:
			case ZPSConfigurationPackage.NODE_DESCRIPTOR__PRIMARY_BINDING_TABLE_CACHE:
			case ZPSConfigurationPackage.NODE_DESCRIPTOR__BACKUP_BINDING_TABLE_CACHE:
			case ZPSConfigurationPackage.NODE_DESCRIPTOR__PRIMARY_DISCOVERY_CACHE:
			case ZPSConfigurationPackage.NODE_DESCRIPTOR__BACKUP_DISCOVERY_CACHE:
			case ZPSConfigurationPackage.NODE_DESCRIPTOR__NETWORK_MANAGER:
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
