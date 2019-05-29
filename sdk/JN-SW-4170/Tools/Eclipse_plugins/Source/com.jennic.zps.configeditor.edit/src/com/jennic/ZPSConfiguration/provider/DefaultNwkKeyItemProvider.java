/**
 * (C) Jennic Ltd
 *
 * $Id: DefaultNwkKeyItemProvider.java 78102 2016-03-24 15:35:29Z nxp29741 $
 */
package com.jennic.ZPSConfiguration.provider;


import com.jennic.ZPSConfiguration.DefaultNwkKey;
import com.jennic.ZPSConfiguration.ZPSConfigurationPackage;

import java.math.BigInteger;
import java.util.Collection;
import java.util.List;

import org.eclipse.emf.common.notify.AdapterFactory;
import org.eclipse.emf.common.notify.Notification;

import org.eclipse.emf.edit.provider.ComposeableAdapterFactory;
import org.eclipse.emf.edit.provider.IEditingDomainItemProvider;
import org.eclipse.emf.edit.provider.IItemLabelProvider;
import org.eclipse.emf.edit.provider.IItemPropertyDescriptor;
import org.eclipse.emf.edit.provider.IItemPropertySource;
import org.eclipse.emf.edit.provider.IStructuredItemContentProvider;
import org.eclipse.emf.edit.provider.ITreeItemContentProvider;
import org.eclipse.emf.edit.provider.ItemPropertyDescriptor;
import org.eclipse.emf.edit.provider.ViewerNotification;

/**
 * This is the item provider adapter for a {@link com.jennic.ZPSConfiguration.DefaultNwkKey} object.
 * <!-- begin-user-doc -->
 * <!-- end-user-doc -->
 * @generated
 */
public class DefaultNwkKeyItemProvider
	extends NwkKeyItemProvider {
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
	public DefaultNwkKeyItemProvider(AdapterFactory adapterFactory) {
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
		
		// generate property descriptors on the fly to allow random setting to
		// control key read-only state
		
		if (itemPropertyDescriptors != null) {
			itemPropertyDescriptors.clear();
			itemPropertyDescriptors = null;
		}
		
		super.getPropertyDescriptors(object);

		addRandomPropertyDescriptor(object);

		return itemPropertyDescriptors;
	}

	/**
	 * This adds a property descriptor for the Random feature.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	protected void addRandomPropertyDescriptor(Object object) {
		itemPropertyDescriptors.add
			(createItemPropertyDescriptor
				(((ComposeableAdapterFactory)adapterFactory).getRootAdapterFactory(),
				 getResourceLocator(),
				 getString("_UI_DefaultNwkKey_Random_feature"),
				 getString("_UI_PropertyDescriptor_description", "_UI_DefaultNwkKey_Random_feature", "_UI_DefaultNwkKey_type"),
				 ZPSConfigurationPackage.Literals.DEFAULT_NWK_KEY__RANDOM,
				 true,
				 false,
				 false,
				 ItemPropertyDescriptor.BOOLEAN_VALUE_IMAGE,
				 null,
				 null));
	}

	/**
	 * This returns DefaultNwkKey.gif.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated NOT
	 */
	@Override
	public Object getImage(Object object) {
		return overlayImage(object, getResourceLocator().getImage("full/obj16/DefaultNwkKey.png"));
	}

	/**
	 * This returns the label text for the adapted class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated NOT
	 */
	@Override
	public String getText(Object object) {
		DefaultNwkKey dnk = (DefaultNwkKey)object;
		String label;
		
		if (dnk.isRandom()) {
			label = "(Key = random)";
		} else {
			BigInteger keyVal = (BigInteger)dnk.getKey();
			String keyValStr = "<undefined>"; 
			if (keyVal != null) {
				keyValStr = keyVal.toString(16);
				
				while (keyValStr.length() < 32) {
					keyValStr = "0" + keyValStr;
				}
				keyValStr = "0x" + keyValStr;				
			}
			
			label = "(Key = " + keyValStr + ")";
		}
		
		return label == null || label.length() == 0 ?
			getString("_UI_DefaultNwkKey_type") :
			getString("_UI_DefaultNwkKey_type") + " " + label;
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

		switch (notification.getFeatureID(DefaultNwkKey.class)) {
			case ZPSConfigurationPackage.DEFAULT_NWK_KEY__RANDOM:
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

}
