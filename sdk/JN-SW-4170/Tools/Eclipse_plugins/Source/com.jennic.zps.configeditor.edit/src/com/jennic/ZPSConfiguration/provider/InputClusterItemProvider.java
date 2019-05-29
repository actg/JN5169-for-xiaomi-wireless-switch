/**
 * (C) Jennic Ltd 2008
 *
 * $Id$
 */
package com.jennic.ZPSConfiguration.provider;



import java.util.Collection;
import java.util.Iterator;
import java.util.List;

import org.eclipse.emf.common.notify.AdapterFactory;
import org.eclipse.emf.common.notify.Notification;

import org.eclipse.emf.common.util.BasicEList;
import org.eclipse.emf.common.util.EList;
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

import com.jennic.ZPSConfiguration.APDU;
import com.jennic.ZPSConfiguration.Cluster;
import com.jennic.ZPSConfiguration.EndPoint;
import com.jennic.ZPSConfiguration.InputCluster;
import com.jennic.ZPSConfiguration.ZPSConfigurationPackage;

/**
 * This is the item provider adapter for a {@link com.jennic.ZPSConfiguration.InputCluster} object.
 * <!-- begin-user-doc -->
 * <!-- end-user-doc -->
 * @generated
 */
public class InputClusterItemProvider
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
	public InputClusterItemProvider(AdapterFactory adapterFactory) {
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

		addClusterPropertyDescriptor(object);
		addRxAPDUPropertyDescriptor(object);
		addDiscoverablePropertyDescriptor(object);

		return itemPropertyDescriptors;
	}

	/*
	 * @generated NOT
	 */
	private boolean Editable(Object object) {
		InputCluster ic = (InputCluster)object;
		EndPoint ep = (EndPoint)ic.eContainer();
		String zdo = "ZDO";
		boolean editable = true;
		
		/*if (null != ep.getName() && 0 == zdo.compareTo(ep.getName())) {
			editable = false;
		}*/
		
		return editable;
	}

	/**
	 * This adds a property descriptor for the Cluster feature.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated NOT
	 */
	protected void addClusterPropertyDescriptor(Object object) {
		itemPropertyDescriptors.add
			(new ItemPropertyDescriptor (
				((ComposeableAdapterFactory)adapterFactory).getRootAdapterFactory(),
				 getResourceLocator(),
				 getString("_UI_InputCluster_Cluster_feature"),
				 getString("_UI_PropertyDescriptor_description", "_UI_InputCluster_Cluster_feature", "_UI_InputCluster_type"),
				 ZPSConfigurationPackage.Literals.INPUT_CLUSTER__CLUSTER,
				 Editable(object),
				 false,
				 true,
				 null,
				 null,
				 null)
				{
					/* display only the APDUs for the node the InputCluster is on */
					public EList<Cluster> getChoiceOfValues(Object object)
					{
						InputCluster inputCluster = (InputCluster)object;
					
						return inputCluster.getEndPoint().getProfile().getClusters();
					}
				}
			);
	}

	/**
	 * This adds a property descriptor for the Rx APDU feature.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated NOT
	 */
	protected void addRxAPDUPropertyDescriptor(Object object) {
		itemPropertyDescriptors.add
			( new ItemPropertyDescriptor (
				 ((ComposeableAdapterFactory)adapterFactory).getRootAdapterFactory(),
				 getResourceLocator(),
				 getString("_UI_InputCluster_RxAPDU_feature"),
				 getString("_UI_PropertyDescriptor_description", "_UI_InputCluster_RxAPDU_feature", "_UI_InputCluster_type"),
				 ZPSConfigurationPackage.Literals.INPUT_CLUSTER__RX_APDU,
				 true,
				 false,
				 true,
				 null,
				 null,
				 null)
			{
				/* display only the APDUs for the node the InputCluster is on */
				public EList<APDU> getChoiceOfValues(Object object)
				{
					InputCluster inputCluster = (InputCluster)object;
					EList<APDU> apdus = inputCluster.getEndPoint().getNode().getPDUConfiguration().getAPDUs();
					String zdp = "apduZDP";
					String zdo = "ZDO";
					EList<APDU> selAPDUs = new BasicEList<APDU>();
					
					if (0 == zdo.compareTo(inputCluster.getEndPoint().getName())) {
						return apdus;
					}
					
					for (Iterator<APDU> iterator = apdus.iterator(); iterator.hasNext(); ) {
						APDU apdu = iterator.next();
						
						/*if (null != apdu.getName() && 0 == zdp.compareTo(apdu.getName())) {

						} else {*/
							selAPDUs.add(apdu);
						/*}*/
					}
					
					return selAPDUs; 
				}
			});
	}

	/**
	 * This adds a property descriptor for the Discoverable feature.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated NOT
	 */
	protected void addDiscoverablePropertyDescriptor(Object object) {
		itemPropertyDescriptors.add
			(createItemPropertyDescriptor
				(((ComposeableAdapterFactory)adapterFactory).getRootAdapterFactory(),
				 getResourceLocator(),
				 getString("_UI_InputCluster_Discoverable_feature"),
				 getString("_UI_PropertyDescriptor_description", "_UI_InputCluster_Discoverable_feature", "_UI_InputCluster_type"),
				 ZPSConfigurationPackage.Literals.INPUT_CLUSTER__DISCOVERABLE,
				 Editable(object),
				 false,
				 false,
				 ItemPropertyDescriptor.BOOLEAN_VALUE_IMAGE,
				 null,
				 null));
	}

	/**
	 * This returns InputCluster.gif.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated NOT
	 */
	@Override
	public Object getImage(Object object) {
		return overlayImage(object, getResourceLocator().getImage("full/obj16/InputCluster.png"));
	}

	/**
	 * This returns the label text for the adapted class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated NOT
	 */
	@Override
	public String getText(Object object) {
		InputCluster inputCluster = (InputCluster)object;
		String details;
		
		String cluster;
		if (null != inputCluster.getCluster()) {
			cluster = "\"" + inputCluster.getCluster().getName() + "\"";
		} else {
			cluster = "\"<undefined>\"";
		}

		String rxapdu;
		if (null != inputCluster.getRxAPDU()) {
			rxapdu = inputCluster.getRxAPDU().getName();
		} else {
			rxapdu = "<undefined>";
		}
		
		details = cluster + " -> " + rxapdu;

		return getString("_UI_InputCluster_type") + " " + details;
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

		switch (notification.getFeatureID(InputCluster.class)) {
			case ZPSConfigurationPackage.INPUT_CLUSTER__CLUSTER:
			case ZPSConfigurationPackage.INPUT_CLUSTER__RX_APDU:
			case ZPSConfigurationPackage.INPUT_CLUSTER__END_POINT:
			case ZPSConfigurationPackage.INPUT_CLUSTER__DISCOVERABLE:
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
