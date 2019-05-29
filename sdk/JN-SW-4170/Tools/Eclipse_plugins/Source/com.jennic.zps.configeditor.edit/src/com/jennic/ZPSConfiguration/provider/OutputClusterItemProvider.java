/**
 * <copyright>
 * </copyright>
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
import com.jennic.ZPSConfiguration.OutputCluster;
import com.jennic.ZPSConfiguration.ZPSConfigurationPackage;

/**
 * This is the item provider adapter for a {@link com.jennic.ZPSConfiguration.OutputCluster} object.
 * <!-- begin-user-doc -->
 * <!-- end-user-doc -->
 * @generated
 */
public class OutputClusterItemProvider
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
	public OutputClusterItemProvider(AdapterFactory adapterFactory) {
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
		addTxAPDUsPropertyDescriptor(object);
		addDiscoverablePropertyDescriptor(object);

		return itemPropertyDescriptors;
	}

	/*
	 * @generated NOT
	 */
	private boolean Editable(Object object) {
		OutputCluster oc = (OutputCluster)object;
		EndPoint ep = (EndPoint)oc.eContainer();
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
				 getString("_UI_OutputCluster_Cluster_feature"),
				 getString("_UI_PropertyDescriptor_description", "_UI_OutputCluster_Cluster_feature", "_UI_OutputCluster_type"),
				 ZPSConfigurationPackage.Literals.OUTPUT_CLUSTER__CLUSTER,
				 Editable(object),
				 false,
				 true,
				 null,
				 null,
				 null)
			{
				@Override
				public EList<Cluster> getChoiceOfValues(Object object)
				{
					OutputCluster outputCluster = (OutputCluster)object;				

					return outputCluster.getEndPoint().getProfile().getClusters();
				}
				
			});
	}

	/**
	 * This adds a property descriptor for the Tx APD Us feature.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated NOT
	 */
	protected void addTxAPDUsPropertyDescriptor(Object object) {
		itemPropertyDescriptors.add
			(new ItemPropertyDescriptor (
				((ComposeableAdapterFactory)adapterFactory).getRootAdapterFactory(),
				 getResourceLocator(),
				 getString("_UI_OutputCluster_TxAPDUs_feature"),
				 getString("_UI_PropertyDescriptor_description", "_UI_OutputCluster_TxAPDUs_feature", "_UI_OutputCluster_type"),
				 ZPSConfigurationPackage.Literals.OUTPUT_CLUSTER__TX_APD_US,
				 true,
				 false,
				 true,
				 null,
				 null,
				 null)
			{
				
			/* display only the APDUs for the node the InputCluster is on */
			@Override
			public EList<APDU> getChoiceOfValues(Object object)
			{
				OutputCluster outputCluster = (OutputCluster)object;
				EList<APDU> apdus = outputCluster.getEndPoint().getNode().getPDUConfiguration().getAPDUs();
				String zdp = "apduZDP";
				String zdo = "ZDO";
				EList<APDU> selAPDUs = new BasicEList<APDU>();

				if (0 == zdo.compareTo(outputCluster.getEndPoint().getName())) {
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
				 getString("_UI_OutputCluster_Discoverable_feature"),
				 getString("_UI_PropertyDescriptor_description", "_UI_OutputCluster_Discoverable_feature", "_UI_OutputCluster_type"),
				 ZPSConfigurationPackage.Literals.OUTPUT_CLUSTER__DISCOVERABLE,
				 Editable(object),
				 false,
				 false,
				 ItemPropertyDescriptor.BOOLEAN_VALUE_IMAGE,
				 null,
				 null));
	}

	/**
	 * This returns OutputCluster.gif.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated NOT
	 */
	@Override
	public Object getImage(Object object) {
		return overlayImage(object, getResourceLocator().getImage("full/obj16/OutputCluster.png"));
	}

	/**
	 * This returns the label text for the adapted class.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated NOT
	 */
	@Override
	public String getText(Object object) {
		OutputCluster outputCluster = (OutputCluster)object;		
		String details;
		
		String cluster;		
		if (null != outputCluster.getCluster()) {
			cluster = "\"" + outputCluster.getCluster().getName() + "\"";
		} else {
			cluster = "\"<undefined>\"";
		}
		

		String txAPDUListStr = "";
				
		for (Iterator<APDU> iterator = outputCluster.getTxAPDUs().iterator(); iterator.hasNext();) {
			APDU txAPdu = iterator.next();
			
			txAPDUListStr += txAPdu.getName();
			if (iterator.hasNext()) {
				txAPDUListStr += ", ";
			}
		}
		
		if (outputCluster.getTxAPDUs().size() == 1) {
			details = cluster + " <- " + txAPDUListStr;
		} else if (outputCluster.getTxAPDUs().size() > 1) {
			details = cluster + " <- (" + txAPDUListStr + ")";
		} else {
			details = cluster + " <- <undefined>";			
		}

		return getString("_UI_OutputCluster_type") + " " + details;
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

		switch (notification.getFeatureID(OutputCluster.class)) {
			case ZPSConfigurationPackage.OUTPUT_CLUSTER__CLUSTER:
			case ZPSConfigurationPackage.OUTPUT_CLUSTER__END_POINT:
			case ZPSConfigurationPackage.OUTPUT_CLUSTER__TX_APD_US:
			case ZPSConfigurationPackage.OUTPUT_CLUSTER__DISCOVERABLE:
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
