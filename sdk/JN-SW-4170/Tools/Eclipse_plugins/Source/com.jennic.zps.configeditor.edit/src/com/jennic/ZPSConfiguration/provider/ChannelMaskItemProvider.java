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

import com.jennic.ZPSConfiguration.ChannelMask;
import com.jennic.ZPSConfiguration.ZPSConfigurationPackage;

/**
 * This is the item provider adapter for a {@link com.jennic.ZPSConfiguration.ChannelMask} object.
 * <!-- begin-user-doc -->
 * <!-- end-user-doc -->
 * @generated
 */
public class ChannelMaskItemProvider
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
	public ChannelMaskItemProvider(AdapterFactory adapterFactory) {
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

			addChannel11PropertyDescriptor(object);
			addChannel12PropertyDescriptor(object);
			addChannel13PropertyDescriptor(object);
			addChannel14PropertyDescriptor(object);
			addChannel15PropertyDescriptor(object);
			addChannel16PropertyDescriptor(object);
			addChannel17PropertyDescriptor(object);
			addChannel18PropertyDescriptor(object);
			addChannel19PropertyDescriptor(object);
			addChannel20PropertyDescriptor(object);
			addChannel21PropertyDescriptor(object);
			addChannel22PropertyDescriptor(object);
			addChannel23PropertyDescriptor(object);
			addChannel24PropertyDescriptor(object);
			addChannel25PropertyDescriptor(object);
			addChannel26PropertyDescriptor(object);
		}
		return itemPropertyDescriptors;
	}

	/**
	 * This adds a property descriptor for the Channel11 feature.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	protected void addChannel11PropertyDescriptor(Object object) {
		itemPropertyDescriptors.add
			(createItemPropertyDescriptor
				(((ComposeableAdapterFactory)adapterFactory).getRootAdapterFactory(),
				 getResourceLocator(),
				 getString("_UI_ChannelMask_Channel11_feature"),
				 getString("_UI_PropertyDescriptor_description", "_UI_ChannelMask_Channel11_feature", "_UI_ChannelMask_type"),
				 ZPSConfigurationPackage.Literals.CHANNEL_MASK__CHANNEL11,
				 true,
				 false,
				 false,
				 ItemPropertyDescriptor.BOOLEAN_VALUE_IMAGE,
				 null,
				 null));
	}

	/**
	 * This adds a property descriptor for the Channel12 feature.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	protected void addChannel12PropertyDescriptor(Object object) {
		itemPropertyDescriptors.add
			(createItemPropertyDescriptor
				(((ComposeableAdapterFactory)adapterFactory).getRootAdapterFactory(),
				 getResourceLocator(),
				 getString("_UI_ChannelMask_Channel12_feature"),
				 getString("_UI_PropertyDescriptor_description", "_UI_ChannelMask_Channel12_feature", "_UI_ChannelMask_type"),
				 ZPSConfigurationPackage.Literals.CHANNEL_MASK__CHANNEL12,
				 true,
				 false,
				 false,
				 ItemPropertyDescriptor.BOOLEAN_VALUE_IMAGE,
				 null,
				 null));
	}

	/**
	 * This adds a property descriptor for the Channel13 feature.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	protected void addChannel13PropertyDescriptor(Object object) {
		itemPropertyDescriptors.add
			(createItemPropertyDescriptor
				(((ComposeableAdapterFactory)adapterFactory).getRootAdapterFactory(),
				 getResourceLocator(),
				 getString("_UI_ChannelMask_Channel13_feature"),
				 getString("_UI_PropertyDescriptor_description", "_UI_ChannelMask_Channel13_feature", "_UI_ChannelMask_type"),
				 ZPSConfigurationPackage.Literals.CHANNEL_MASK__CHANNEL13,
				 true,
				 false,
				 false,
				 ItemPropertyDescriptor.BOOLEAN_VALUE_IMAGE,
				 null,
				 null));
	}

	/**
	 * This adds a property descriptor for the Channel14 feature.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	protected void addChannel14PropertyDescriptor(Object object) {
		itemPropertyDescriptors.add
			(createItemPropertyDescriptor
				(((ComposeableAdapterFactory)adapterFactory).getRootAdapterFactory(),
				 getResourceLocator(),
				 getString("_UI_ChannelMask_Channel14_feature"),
				 getString("_UI_PropertyDescriptor_description", "_UI_ChannelMask_Channel14_feature", "_UI_ChannelMask_type"),
				 ZPSConfigurationPackage.Literals.CHANNEL_MASK__CHANNEL14,
				 true,
				 false,
				 false,
				 ItemPropertyDescriptor.BOOLEAN_VALUE_IMAGE,
				 null,
				 null));
	}

	/**
	 * This adds a property descriptor for the Channel15 feature.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	protected void addChannel15PropertyDescriptor(Object object) {
		itemPropertyDescriptors.add
			(createItemPropertyDescriptor
				(((ComposeableAdapterFactory)adapterFactory).getRootAdapterFactory(),
				 getResourceLocator(),
				 getString("_UI_ChannelMask_Channel15_feature"),
				 getString("_UI_PropertyDescriptor_description", "_UI_ChannelMask_Channel15_feature", "_UI_ChannelMask_type"),
				 ZPSConfigurationPackage.Literals.CHANNEL_MASK__CHANNEL15,
				 true,
				 false,
				 false,
				 ItemPropertyDescriptor.BOOLEAN_VALUE_IMAGE,
				 null,
				 null));
	}

	/**
	 * This adds a property descriptor for the Channel16 feature.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	protected void addChannel16PropertyDescriptor(Object object) {
		itemPropertyDescriptors.add
			(createItemPropertyDescriptor
				(((ComposeableAdapterFactory)adapterFactory).getRootAdapterFactory(),
				 getResourceLocator(),
				 getString("_UI_ChannelMask_Channel16_feature"),
				 getString("_UI_PropertyDescriptor_description", "_UI_ChannelMask_Channel16_feature", "_UI_ChannelMask_type"),
				 ZPSConfigurationPackage.Literals.CHANNEL_MASK__CHANNEL16,
				 true,
				 false,
				 false,
				 ItemPropertyDescriptor.BOOLEAN_VALUE_IMAGE,
				 null,
				 null));
	}

	/**
	 * This adds a property descriptor for the Channel17 feature.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	protected void addChannel17PropertyDescriptor(Object object) {
		itemPropertyDescriptors.add
			(createItemPropertyDescriptor
				(((ComposeableAdapterFactory)adapterFactory).getRootAdapterFactory(),
				 getResourceLocator(),
				 getString("_UI_ChannelMask_Channel17_feature"),
				 getString("_UI_PropertyDescriptor_description", "_UI_ChannelMask_Channel17_feature", "_UI_ChannelMask_type"),
				 ZPSConfigurationPackage.Literals.CHANNEL_MASK__CHANNEL17,
				 true,
				 false,
				 false,
				 ItemPropertyDescriptor.BOOLEAN_VALUE_IMAGE,
				 null,
				 null));
	}

	/**
	 * This adds a property descriptor for the Channel18 feature.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	protected void addChannel18PropertyDescriptor(Object object) {
		itemPropertyDescriptors.add
			(createItemPropertyDescriptor
				(((ComposeableAdapterFactory)adapterFactory).getRootAdapterFactory(),
				 getResourceLocator(),
				 getString("_UI_ChannelMask_Channel18_feature"),
				 getString("_UI_PropertyDescriptor_description", "_UI_ChannelMask_Channel18_feature", "_UI_ChannelMask_type"),
				 ZPSConfigurationPackage.Literals.CHANNEL_MASK__CHANNEL18,
				 true,
				 false,
				 false,
				 ItemPropertyDescriptor.BOOLEAN_VALUE_IMAGE,
				 null,
				 null));
	}

	/**
	 * This adds a property descriptor for the Channel19 feature.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	protected void addChannel19PropertyDescriptor(Object object) {
		itemPropertyDescriptors.add
			(createItemPropertyDescriptor
				(((ComposeableAdapterFactory)adapterFactory).getRootAdapterFactory(),
				 getResourceLocator(),
				 getString("_UI_ChannelMask_Channel19_feature"),
				 getString("_UI_PropertyDescriptor_description", "_UI_ChannelMask_Channel19_feature", "_UI_ChannelMask_type"),
				 ZPSConfigurationPackage.Literals.CHANNEL_MASK__CHANNEL19,
				 true,
				 false,
				 false,
				 ItemPropertyDescriptor.BOOLEAN_VALUE_IMAGE,
				 null,
				 null));
	}

	/**
	 * This adds a property descriptor for the Channel20 feature.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	protected void addChannel20PropertyDescriptor(Object object) {
		itemPropertyDescriptors.add
			(createItemPropertyDescriptor
				(((ComposeableAdapterFactory)adapterFactory).getRootAdapterFactory(),
				 getResourceLocator(),
				 getString("_UI_ChannelMask_Channel20_feature"),
				 getString("_UI_PropertyDescriptor_description", "_UI_ChannelMask_Channel20_feature", "_UI_ChannelMask_type"),
				 ZPSConfigurationPackage.Literals.CHANNEL_MASK__CHANNEL20,
				 true,
				 false,
				 false,
				 ItemPropertyDescriptor.BOOLEAN_VALUE_IMAGE,
				 null,
				 null));
	}

	/**
	 * This adds a property descriptor for the Channel21 feature.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	protected void addChannel21PropertyDescriptor(Object object) {
		itemPropertyDescriptors.add
			(createItemPropertyDescriptor
				(((ComposeableAdapterFactory)adapterFactory).getRootAdapterFactory(),
				 getResourceLocator(),
				 getString("_UI_ChannelMask_Channel21_feature"),
				 getString("_UI_PropertyDescriptor_description", "_UI_ChannelMask_Channel21_feature", "_UI_ChannelMask_type"),
				 ZPSConfigurationPackage.Literals.CHANNEL_MASK__CHANNEL21,
				 true,
				 false,
				 false,
				 ItemPropertyDescriptor.BOOLEAN_VALUE_IMAGE,
				 null,
				 null));
	}

	/**
	 * This adds a property descriptor for the Channel22 feature.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	protected void addChannel22PropertyDescriptor(Object object) {
		itemPropertyDescriptors.add
			(createItemPropertyDescriptor
				(((ComposeableAdapterFactory)adapterFactory).getRootAdapterFactory(),
				 getResourceLocator(),
				 getString("_UI_ChannelMask_Channel22_feature"),
				 getString("_UI_PropertyDescriptor_description", "_UI_ChannelMask_Channel22_feature", "_UI_ChannelMask_type"),
				 ZPSConfigurationPackage.Literals.CHANNEL_MASK__CHANNEL22,
				 true,
				 false,
				 false,
				 ItemPropertyDescriptor.BOOLEAN_VALUE_IMAGE,
				 null,
				 null));
	}

	/**
	 * This adds a property descriptor for the Channel23 feature.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	protected void addChannel23PropertyDescriptor(Object object) {
		itemPropertyDescriptors.add
			(createItemPropertyDescriptor
				(((ComposeableAdapterFactory)adapterFactory).getRootAdapterFactory(),
				 getResourceLocator(),
				 getString("_UI_ChannelMask_Channel23_feature"),
				 getString("_UI_PropertyDescriptor_description", "_UI_ChannelMask_Channel23_feature", "_UI_ChannelMask_type"),
				 ZPSConfigurationPackage.Literals.CHANNEL_MASK__CHANNEL23,
				 true,
				 false,
				 false,
				 ItemPropertyDescriptor.BOOLEAN_VALUE_IMAGE,
				 null,
				 null));
	}

	/**
	 * This adds a property descriptor for the Channel24 feature.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	protected void addChannel24PropertyDescriptor(Object object) {
		itemPropertyDescriptors.add
			(createItemPropertyDescriptor
				(((ComposeableAdapterFactory)adapterFactory).getRootAdapterFactory(),
				 getResourceLocator(),
				 getString("_UI_ChannelMask_Channel24_feature"),
				 getString("_UI_PropertyDescriptor_description", "_UI_ChannelMask_Channel24_feature", "_UI_ChannelMask_type"),
				 ZPSConfigurationPackage.Literals.CHANNEL_MASK__CHANNEL24,
				 true,
				 false,
				 false,
				 ItemPropertyDescriptor.BOOLEAN_VALUE_IMAGE,
				 null,
				 null));
	}

	/**
	 * This adds a property descriptor for the Channel25 feature.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	protected void addChannel25PropertyDescriptor(Object object) {
		itemPropertyDescriptors.add
			(createItemPropertyDescriptor
				(((ComposeableAdapterFactory)adapterFactory).getRootAdapterFactory(),
				 getResourceLocator(),
				 getString("_UI_ChannelMask_Channel25_feature"),
				 getString("_UI_PropertyDescriptor_description", "_UI_ChannelMask_Channel25_feature", "_UI_ChannelMask_type"),
				 ZPSConfigurationPackage.Literals.CHANNEL_MASK__CHANNEL25,
				 true,
				 false,
				 false,
				 ItemPropertyDescriptor.BOOLEAN_VALUE_IMAGE,
				 null,
				 null));
	}

	/**
	 * This adds a property descriptor for the Channel26 feature.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	protected void addChannel26PropertyDescriptor(Object object) {
		itemPropertyDescriptors.add
			(createItemPropertyDescriptor
				(((ComposeableAdapterFactory)adapterFactory).getRootAdapterFactory(),
				 getResourceLocator(),
				 getString("_UI_ChannelMask_Channel26_feature"),
				 getString("_UI_PropertyDescriptor_description", "_UI_ChannelMask_Channel26_feature", "_UI_ChannelMask_type"),
				 ZPSConfigurationPackage.Literals.CHANNEL_MASK__CHANNEL26,
				 true,
				 false,
				 false,
				 ItemPropertyDescriptor.BOOLEAN_VALUE_IMAGE,
				 null,
				 null));
	}

	/**
	 * This returns ChannelMask.gif.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated NOT
	 */
	@Override
	public Object getImage(Object object) {
		return overlayImage(object, getResourceLocator().getImage("full/obj16/ChannelMask.png"));
	}

	/**
	 * This returns the label text for the adapted class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated NOT
	 */
	@Override
	public String getText(Object object) {
		ChannelMask channelMask = (ChannelMask)object;
		Integer maskValue = 0;

		maskValue |= channelMask.isChannel11() ? (1<<11) : 0;
		maskValue |= channelMask.isChannel12() ? (1<<12) : 0;
		maskValue |= channelMask.isChannel13() ? (1<<13) : 0;
		maskValue |= channelMask.isChannel14() ? (1<<14) : 0;
		maskValue |= channelMask.isChannel15() ? (1<<15) : 0;
		maskValue |= channelMask.isChannel16() ? (1<<16) : 0;
		maskValue |= channelMask.isChannel17() ? (1<<17) : 0;
		maskValue |= channelMask.isChannel18() ? (1<<18) : 0;
		maskValue |= channelMask.isChannel19() ? (1<<19) : 0;
		maskValue |= channelMask.isChannel20() ? (1<<20) : 0;
		maskValue |= channelMask.isChannel21() ? (1<<21) : 0;
		maskValue |= channelMask.isChannel22() ? (1<<22) : 0;
		maskValue |= channelMask.isChannel23() ? (1<<23) : 0;
		maskValue |= channelMask.isChannel24() ? (1<<24) : 0;
		maskValue |= channelMask.isChannel25() ? (1<<25) : 0;
		maskValue |= channelMask.isChannel26() ? (1<<26) : 0;

		String channelList = channelMask.isChannel11() ? "11": "";
		channelList += channelMask.isChannel12() ? ",12" : "";
		channelList += channelMask.isChannel13() ? ",13" : "";
		channelList += channelMask.isChannel14() ? ",14" : "";
		channelList += channelMask.isChannel15() ? ",15" : "";
		channelList += channelMask.isChannel16() ? ",16" : "";
		channelList += channelMask.isChannel17() ? ",17" : "";
		channelList += channelMask.isChannel18() ? ",18" : "";
		channelList += channelMask.isChannel19() ? ",19" : "";
		channelList += channelMask.isChannel20() ? ",20" : "";
		channelList += channelMask.isChannel21() ? ",21" : "";
		channelList += channelMask.isChannel22() ? ",22" : "";
		channelList += channelMask.isChannel23() ? ",23" : "";
		channelList += channelMask.isChannel24() ? ",24" : "";
		channelList += channelMask.isChannel25() ? ",25" : "";
		channelList += channelMask.isChannel26() ? ",26" : "";
		
		// PR #255 http://trac/Zigbee-PRO/ticket/255
		// Gracefully handle case when no channels are selected
		if (0 == channelList.length()) {
			channelList = "none";
		} else if (',' == channelList.charAt(0)) {
			channelList = channelList.substring(1);
		}

		return getString("_UI_ChannelMask_type") + " (" + channelList + " : 0x" + Integer.toHexString(maskValue) + ")";
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

		switch (notification.getFeatureID(ChannelMask.class)) {
			case ZPSConfigurationPackage.CHANNEL_MASK__CHANNEL11:
			case ZPSConfigurationPackage.CHANNEL_MASK__CHANNEL12:
			case ZPSConfigurationPackage.CHANNEL_MASK__CHANNEL13:
			case ZPSConfigurationPackage.CHANNEL_MASK__CHANNEL14:
			case ZPSConfigurationPackage.CHANNEL_MASK__CHANNEL15:
			case ZPSConfigurationPackage.CHANNEL_MASK__CHANNEL16:
			case ZPSConfigurationPackage.CHANNEL_MASK__CHANNEL17:
			case ZPSConfigurationPackage.CHANNEL_MASK__CHANNEL18:
			case ZPSConfigurationPackage.CHANNEL_MASK__CHANNEL19:
			case ZPSConfigurationPackage.CHANNEL_MASK__CHANNEL20:
			case ZPSConfigurationPackage.CHANNEL_MASK__CHANNEL21:
			case ZPSConfigurationPackage.CHANNEL_MASK__CHANNEL22:
			case ZPSConfigurationPackage.CHANNEL_MASK__CHANNEL23:
			case ZPSConfigurationPackage.CHANNEL_MASK__CHANNEL24:
			case ZPSConfigurationPackage.CHANNEL_MASK__CHANNEL25:
			case ZPSConfigurationPackage.CHANNEL_MASK__CHANNEL26:
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
