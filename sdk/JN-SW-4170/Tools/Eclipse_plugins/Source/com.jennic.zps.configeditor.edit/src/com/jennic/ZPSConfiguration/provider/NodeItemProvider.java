/**
 * (C) Jennic Ltd 2008
 *
 * $Id$
 */
package com.jennic.ZPSConfiguration.provider;



import java.util.Collection;
import java.util.Iterator;
import java.util.List;

import org.eclipse.emf.common.command.Command;
import org.eclipse.emf.common.command.UnexecutableCommand;
import org.eclipse.emf.common.notify.AdapterFactory;
import org.eclipse.emf.common.notify.Notification;

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
import org.eclipse.emf.edit.provider.ItemPropertyDescriptor;
import org.eclipse.emf.edit.provider.ViewerNotification;

import com.jennic.ZPSConfiguration.EndPoint;
import com.jennic.ZPSConfiguration.Node;
import com.jennic.ZPSConfiguration.ZPSConfigurationFactory;
import com.jennic.ZPSConfiguration.ZPSConfigurationPackage;

/**
 * This is the item provider adapter for a {@link com.jennic.ZPSConfiguration.Node} object.
 * <!-- begin-user-doc -->
 * <!-- end-user-doc -->
 * @generated
 */
public class NodeItemProvider
	extends NamedObjectItemProvider {
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
	public NodeItemProvider(AdapterFactory adapterFactory) {
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

		addDiscoveryNeighbourTableSizePropertyDescriptor(object);
		addActiveNeighbourTableSizePropertyDescriptor(object);
		addRouteDiscoveryTableSizePropertyDescriptor(object);
		addRoutingTableSizePropertyDescriptor(object);
		addBroadcastTransactionTableSizePropertyDescriptor(object);
		addRouteRecordTableSizePropertyDescriptor(object);
		addAddressMapTableSizePropertyDescriptor(object);
		addSecurityMaterialSetsPropertyDescriptor(object);
		addMaxNumSimultaneousApsdeReqPropertyDescriptor(object);
		addMaxNumSimultaneousApsdeAckReqPropertyDescriptor(object);
		addMACMutexNamePropertyDescriptor(object);
		addZPSMutexNamePropertyDescriptor(object);
		addFragmentationMaxNumSimulRxPropertyDescriptor(object);
		addFragmentationMaxNumSimulTxPropertyDescriptor(object);
		addDefaultEventMessageNamePropertyDescriptor(object);
		addMACTimeEventMessagePropertyDescriptor(object);
		addApsNonMemberRadiusPropertyDescriptor(object);
		addApsDesignatedCoordinatorPropertyDescriptor(object);
		addApsUseInsecureJoinPropertyDescriptor(object);
		addApsMaxWindowSizePropertyDescriptor(object);
		addApsInterframeDelayPropertyDescriptor(object);
		addAPSDuplicateTableSizePropertyDescriptor(object);
		addApsSecurityTimeoutPeriodPropertyDescriptor(object);
		addApsUseExtPANIdPropertyDescriptor(object);

		if (((Node)object).isSecurityEnabled()) {
			addInitialNetworkKeyPropertyDescriptor(object);
		}
		
		addSecurityEnabledPropertyDescriptor(object);
		addMACMlmeDcfmIndMessagePropertyDescriptor(object);
		addMACMcpsDcfmIndMessagePropertyDescriptor(object);
		addAPSPersistenceTimePropertyDescriptor(object);
		addNumAPSMESimulCommandsPropertyDescriptor(object);
		addStackProfilePropertyDescriptor(object);
		addInterPANPropertyDescriptor(object);
		addGreenPowerSupportPropertyDescriptor(object);
		addApsFcSaveCountBitShiftPropertyDescriptor(object);
		addNwkFcSaveCountBitShiftPropertyDescriptor(object);
		addMacTableSizePropertyDescriptor(object);
		addDefaultCallbackNamePropertyDescriptor(object);
		return itemPropertyDescriptors;
	}

	/**
	 * This adds a property descriptor for the Max Num Simultaneous Apsde Ack Req feature.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	protected void addMaxNumSimultaneousApsdeAckReqPropertyDescriptor(Object object) {
		itemPropertyDescriptors.add
			(createItemPropertyDescriptor
				(((ComposeableAdapterFactory)adapterFactory).getRootAdapterFactory(),
				 getResourceLocator(),
				 getString("_UI_Node_MaxNumSimultaneousApsdeAckReq_feature"),
				 getString("_UI_Node_MaxNumSimultaneousApsdeAckReq_description"),
				 ZPSConfigurationPackage.Literals.NODE__MAX_NUM_SIMULTANEOUS_APSDE_ACK_REQ,
				 true,
				 false,
				 false,
				 ItemPropertyDescriptor.GENERIC_VALUE_IMAGE,
				 getString("_UI_APSLayerConfigurationPropertyCategory"),
				 new String[] {
					"org.eclipse.ui.views.properties.expert"
				 }));
	}

	/**
	 * This adds a property descriptor for the Discovery Neighbour Table Size feature.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	protected void addDiscoveryNeighbourTableSizePropertyDescriptor(Object object) {
		itemPropertyDescriptors.add
			(createItemPropertyDescriptor
				(((ComposeableAdapterFactory)adapterFactory).getRootAdapterFactory(),
				 getResourceLocator(),
				 getString("_UI_Node_DiscoveryNeighbourTableSize_feature"),
				 getString("_UI_Node_DiscoveryNeighbourTableSize_description"),
				 ZPSConfigurationPackage.Literals.NODE__DISCOVERY_NEIGHBOUR_TABLE_SIZE,
				 true,
				 false,
				 false,
				 ItemPropertyDescriptor.GENERIC_VALUE_IMAGE,
				 getString("_UI_NetworkLayerConfigurationPropertyCategory"),
				 new String[] {
					"org.eclipse.ui.views.properties.expert"
				 }));
	}

	/**
	 * This adds a property descriptor for the Active Neighbour Table Size feature.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	protected void addActiveNeighbourTableSizePropertyDescriptor(Object object) {
		itemPropertyDescriptors.add
			(createItemPropertyDescriptor
				(((ComposeableAdapterFactory)adapterFactory).getRootAdapterFactory(),
				 getResourceLocator(),
				 getString("_UI_Node_ActiveNeighbourTableSize_feature"),
				 getString("_UI_Node_ActiveNeighbourTableSize_description"),
				 ZPSConfigurationPackage.Literals.NODE__ACTIVE_NEIGHBOUR_TABLE_SIZE,
				 true,
				 false,
				 false,
				 ItemPropertyDescriptor.GENERIC_VALUE_IMAGE,
				 getString("_UI_NetworkLayerConfigurationPropertyCategory"),
				 new String[] {
					"org.eclipse.ui.views.properties.expert"
				 }));
	}

	/**
	 * This adds a property descriptor for the Route Discovery Table Size feature.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	protected void addRouteDiscoveryTableSizePropertyDescriptor(Object object) {
		itemPropertyDescriptors.add
			(createItemPropertyDescriptor
				(((ComposeableAdapterFactory)adapterFactory).getRootAdapterFactory(),
				 getResourceLocator(),
				 getString("_UI_Node_RouteDiscoveryTableSize_feature"),
				 getString("_UI_Node_RouteDiscoveryTableSize_description"),
				 ZPSConfigurationPackage.Literals.NODE__ROUTE_DISCOVERY_TABLE_SIZE,
				 true,
				 false,
				 false,
				 ItemPropertyDescriptor.GENERIC_VALUE_IMAGE,
				 getString("_UI_NetworkLayerConfigurationPropertyCategory"),
				 new String[] {
					"org.eclipse.ui.views.properties.expert"
				 }));
	}

	/**
	 * This adds a property descriptor for the Routing Table Size feature.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	protected void addRoutingTableSizePropertyDescriptor(Object object) {
		itemPropertyDescriptors.add
			(createItemPropertyDescriptor
				(((ComposeableAdapterFactory)adapterFactory).getRootAdapterFactory(),
				 getResourceLocator(),
				 getString("_UI_Node_RoutingTableSize_feature"),
				 getString("_UI_Node_RoutingTableSize_description"),
				 ZPSConfigurationPackage.Literals.NODE__ROUTING_TABLE_SIZE,
				 true,
				 false,
				 false,
				 ItemPropertyDescriptor.GENERIC_VALUE_IMAGE,
				 getString("_UI_NetworkLayerConfigurationPropertyCategory"),
				 new String[] {
					"org.eclipse.ui.views.properties.expert"
				 }));
	}

	/**
	 * This adds a property descriptor for the Broadcast Transaction Table Size feature.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	protected void addBroadcastTransactionTableSizePropertyDescriptor(Object object) {
		itemPropertyDescriptors.add
			(createItemPropertyDescriptor
				(((ComposeableAdapterFactory)adapterFactory).getRootAdapterFactory(),
				 getResourceLocator(),
				 getString("_UI_Node_BroadcastTransactionTableSize_feature"),
				 getString("_UI_Node_BroadcastTransactionTableSize_description"),
				 ZPSConfigurationPackage.Literals.NODE__BROADCAST_TRANSACTION_TABLE_SIZE,
				 true,
				 false,
				 false,
				 ItemPropertyDescriptor.GENERIC_VALUE_IMAGE,
				 getString("_UI_NetworkLayerConfigurationPropertyCategory"),
				 new String[] {
					"org.eclipse.ui.views.properties.expert"
				 }));
	}

	/**
	 * This adds a property descriptor for the Route Record Table Size feature.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	protected void addRouteRecordTableSizePropertyDescriptor(Object object) {
		itemPropertyDescriptors.add
			(createItemPropertyDescriptor
				(((ComposeableAdapterFactory)adapterFactory).getRootAdapterFactory(),
				 getResourceLocator(),
				 getString("_UI_Node_RouteRecordTableSize_feature"),
				 getString("_UI_Node_RouteRecordTableSize_description"),
				 ZPSConfigurationPackage.Literals.NODE__ROUTE_RECORD_TABLE_SIZE,
				 true,
				 false,
				 false,
				 ItemPropertyDescriptor.GENERIC_VALUE_IMAGE,
				 getString("_UI_NetworkLayerConfigurationPropertyCategory"),
				 new String[] {
					"org.eclipse.ui.views.properties.expert"
				 }));
	}

	/**
	 * This adds a property descriptor for the Address Map Table Size feature.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	protected void addAddressMapTableSizePropertyDescriptor(Object object) {
		itemPropertyDescriptors.add
			(createItemPropertyDescriptor
				(((ComposeableAdapterFactory)adapterFactory).getRootAdapterFactory(),
				 getResourceLocator(),
				 getString("_UI_Node_AddressMapTableSize_feature"),
				 getString("_UI_Node_AddressMapTableSize_description"),
				 ZPSConfigurationPackage.Literals.NODE__ADDRESS_MAP_TABLE_SIZE,
				 true,
				 false,
				 false,
				 ItemPropertyDescriptor.GENERIC_VALUE_IMAGE,
				 getString("_UI_NetworkLayerConfigurationPropertyCategory"),
				 new String[] {
					"org.eclipse.ui.views.properties.expert"
				 }));
	}

	/**
	 * This adds a property descriptor for the Security Material Sets feature.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	protected void addSecurityMaterialSetsPropertyDescriptor(Object object) {
		itemPropertyDescriptors.add
			(createItemPropertyDescriptor
				(((ComposeableAdapterFactory)adapterFactory).getRootAdapterFactory(),
				 getResourceLocator(),
				 getString("_UI_Node_SecurityMaterialSets_feature"),
				 getString("_UI_Node_SecurityMaterialSets_description"),
				 ZPSConfigurationPackage.Literals.NODE__SECURITY_MATERIAL_SETS,
				 true,
				 false,
				 false,
				 ItemPropertyDescriptor.GENERIC_VALUE_IMAGE,
				 getString("_UI_NetworkLayerConfigurationPropertyCategory"),
				 new String[] {
					"org.eclipse.ui.views.properties.expert"
				 }));
	}

	/**
	 * This adds a property descriptor for the Max Num Simultaneous Apsde Req feature.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	protected void addMaxNumSimultaneousApsdeReqPropertyDescriptor(Object object) {
		itemPropertyDescriptors.add
			(createItemPropertyDescriptor
				(((ComposeableAdapterFactory)adapterFactory).getRootAdapterFactory(),
				 getResourceLocator(),
				 getString("_UI_Node_MaxNumSimultaneousApsdeReq_feature"),
				 getString("_UI_Node_MaxNumSimultaneousApsdeReq_description"),
				 ZPSConfigurationPackage.Literals.NODE__MAX_NUM_SIMULTANEOUS_APSDE_REQ,
				 true,
				 false,
				 false,
				 ItemPropertyDescriptor.INTEGRAL_VALUE_IMAGE,
				 getString("_UI_APSLayerConfigurationPropertyCategory"),
				 new String[] {
					"org.eclipse.ui.views.properties.expert"
				 }));
	}

	/**
	 * This adds a property descriptor for the MAC Mutex Name feature.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	protected void addMACMutexNamePropertyDescriptor(Object object) {
		itemPropertyDescriptors.add
			(createItemPropertyDescriptor
				(((ComposeableAdapterFactory)adapterFactory).getRootAdapterFactory(),
				 getResourceLocator(),
				 getString("_UI_Node_MACMutexName_feature"),
				 getString("_UI_Node_MACMutexName_description"),
				 ZPSConfigurationPackage.Literals.NODE__MAC_MUTEX_NAME,
				 true,
				 false,
				 false,
				 ItemPropertyDescriptor.GENERIC_VALUE_IMAGE,
				 getString("_UI_InternalPropertyCategory"),
				 new String[] {
					"com.jennic.internal"
				 }));
	}

	/**
	 * This adds a property descriptor for the ZPS Mutex Name feature.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	protected void addZPSMutexNamePropertyDescriptor(Object object) {
		itemPropertyDescriptors.add
			(createItemPropertyDescriptor
				(((ComposeableAdapterFactory)adapterFactory).getRootAdapterFactory(),
				 getResourceLocator(),
				 getString("_UI_Node_ZPSMutexName_feature"),
				 getString("_UI_Node_ZPSMutexName_description"),
				 ZPSConfigurationPackage.Literals.NODE__ZPS_MUTEX_NAME,
				 true,
				 false,
				 false,
				 ItemPropertyDescriptor.GENERIC_VALUE_IMAGE,
				 getString("_UI_AFConfigurationPropertyCategory"),
				 new String[] {
					"org.eclipse.ui.views.properties.expert"
				 }));
	}

	/**
	 * This adds a property descriptor for the Fragmentation Max Num Simul Rx feature.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	protected void addFragmentationMaxNumSimulRxPropertyDescriptor(Object object) {
		itemPropertyDescriptors.add
			(createItemPropertyDescriptor
				(((ComposeableAdapterFactory)adapterFactory).getRootAdapterFactory(),
				 getResourceLocator(),
				 getString("_UI_Node_FragmentationMaxNumSimulRx_feature"),
				 getString("_UI_Node_FragmentationMaxNumSimulRx_description"),
				 ZPSConfigurationPackage.Literals.NODE__FRAGMENTATION_MAX_NUM_SIMUL_RX,
				 true,
				 false,
				 false,
				 ItemPropertyDescriptor.INTEGRAL_VALUE_IMAGE,
				 getString("_UI_APSLayerConfigurationPropertyCategory"),
				 new String[] {
					"org.eclipse.ui.views.properties.expert"
				 }));
	}

	/**
	 * This adds a property descriptor for the Fragmentation Max Num Simul Tx feature.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	protected void addFragmentationMaxNumSimulTxPropertyDescriptor(Object object) {
		itemPropertyDescriptors.add
			(createItemPropertyDescriptor
				(((ComposeableAdapterFactory)adapterFactory).getRootAdapterFactory(),
				 getResourceLocator(),
				 getString("_UI_Node_FragmentationMaxNumSimulTx_feature"),
				 getString("_UI_Node_FragmentationMaxNumSimulTx_description"),
				 ZPSConfigurationPackage.Literals.NODE__FRAGMENTATION_MAX_NUM_SIMUL_TX,
				 true,
				 false,
				 false,
				 ItemPropertyDescriptor.INTEGRAL_VALUE_IMAGE,
				 getString("_UI_APSLayerConfigurationPropertyCategory"),
				 new String[] {
					"org.eclipse.ui.views.properties.expert"
				 }));
	}

	/**
	 * This adds a property descriptor for the Default Event Message Name feature.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	protected void addDefaultEventMessageNamePropertyDescriptor(Object object) {
		itemPropertyDescriptors.add
			(createItemPropertyDescriptor
				(((ComposeableAdapterFactory)adapterFactory).getRootAdapterFactory(),
				 getResourceLocator(),
				 getString("_UI_Node_DefaultEventMessageName_feature"),
				 getString("_UI_Node_DefaultEventMessageName_description"),
				 ZPSConfigurationPackage.Literals.NODE__DEFAULT_EVENT_MESSAGE_NAME,
				 true,
				 false,
				 false,
				 ItemPropertyDescriptor.GENERIC_VALUE_IMAGE,
				 getString("_UI_AFConfigurationPropertyCategory"),
				 new String[] {
					"org.eclipse.ui.views.properties.expert"
				 }));
	}

	/**
	 * This adds a property descriptor for the MAC Time Event Message feature.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	protected void addMACTimeEventMessagePropertyDescriptor(Object object) {
		itemPropertyDescriptors.add
			(createItemPropertyDescriptor
				(((ComposeableAdapterFactory)adapterFactory).getRootAdapterFactory(),
				 getResourceLocator(),
				 getString("_UI_Node_MACTimeEventMessage_feature"),
				 getString("_UI_Node_MACTimeEventMessage_description"),
				 ZPSConfigurationPackage.Literals.NODE__MAC_TIME_EVENT_MESSAGE,
				 true,
				 false,
				 false,
				 ItemPropertyDescriptor.GENERIC_VALUE_IMAGE,
				 getString("_UI_InternalPropertyCategory"),
				 new String[] {
					"com.jennic.internal"
				 }));
	}

	/**
	 * This adds a property descriptor for the APS Duplicate Table Size feature.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	protected void addAPSDuplicateTableSizePropertyDescriptor(Object object) {
		itemPropertyDescriptors.add
			(createItemPropertyDescriptor
				(((ComposeableAdapterFactory)adapterFactory).getRootAdapterFactory(),
				 getResourceLocator(),
				 getString("_UI_Node_APSDuplicateTableSize_feature"),
				 getString("_UI_Node_APSDuplicateTableSize_description"),
				 ZPSConfigurationPackage.Literals.NODE__APS_DUPLICATE_TABLE_SIZE,
				 true,
				 false,
				 false,
				 ItemPropertyDescriptor.INTEGRAL_VALUE_IMAGE,
				 getString("_UI_APSLayerConfigurationPropertyCategory"),
				 new String[] {
					"org.eclipse.ui.views.properties.expert"
				 }));
	}

	/**
	 * This adds a property descriptor for the Aps Non Member Radius feature.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	protected void addApsNonMemberRadiusPropertyDescriptor(Object object) {
		itemPropertyDescriptors.add
			(createItemPropertyDescriptor
				(((ComposeableAdapterFactory)adapterFactory).getRootAdapterFactory(),
				 getResourceLocator(),
				 getString("_UI_Node_apsNonMemberRadius_feature"),
				 getString("_UI_Node_apsNonMemberRadius_description"),
				 ZPSConfigurationPackage.Literals.NODE__APS_NON_MEMBER_RADIUS,
				 true,
				 false,
				 false,
				 ItemPropertyDescriptor.INTEGRAL_VALUE_IMAGE,
				 getString("_UI_AIBPropertyCategory"),
				 new String[] {
					"org.eclipse.ui.views.properties.expert"
				 }));
	}

	/**
	 * This adds a property descriptor for the Aps Designated Coordinator feature.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	protected void addApsDesignatedCoordinatorPropertyDescriptor(Object object) {
		itemPropertyDescriptors.add
			(createItemPropertyDescriptor
				(((ComposeableAdapterFactory)adapterFactory).getRootAdapterFactory(),
				 getResourceLocator(),
				 getString("_UI_Node_apsDesignatedCoordinator_feature"),
				 getString("_UI_Node_apsDesignatedCoordinator_description"),
				 ZPSConfigurationPackage.Literals.NODE__APS_DESIGNATED_COORDINATOR,
				 false,
				 false,
				 false,
				 ItemPropertyDescriptor.BOOLEAN_VALUE_IMAGE,
				 getString("_UI_AIBPropertyCategory"),
				 new String[] {
					"org.eclipse.ui.views.properties.expert"
				 }));
	}

	/**
	 * This adds a property descriptor for the Aps Use Insecure Join feature.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	protected void addApsUseInsecureJoinPropertyDescriptor(Object object) {
		itemPropertyDescriptors.add
			(createItemPropertyDescriptor
				(((ComposeableAdapterFactory)adapterFactory).getRootAdapterFactory(),
				 getResourceLocator(),
				 getString("_UI_Node_apsUseInsecureJoin_feature"),
				 getString("_UI_Node_apsUseInsecureJoin_description"),
				 ZPSConfigurationPackage.Literals.NODE__APS_USE_INSECURE_JOIN,
				 true,
				 false,
				 false,
				 ItemPropertyDescriptor.BOOLEAN_VALUE_IMAGE,
				 getString("_UI_AIBPropertyCategory"),
				 new String[] {
					"org.eclipse.ui.views.properties.expert"
				 }));
	}

	/**
	 * This adds a property descriptor for the Aps Max Window Size feature.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	protected void addApsMaxWindowSizePropertyDescriptor(Object object) {
		itemPropertyDescriptors.add
			(createItemPropertyDescriptor
				(((ComposeableAdapterFactory)adapterFactory).getRootAdapterFactory(),
				 getResourceLocator(),
				 getString("_UI_Node_apsMaxWindowSize_feature"),
				 getString("_UI_Node_apsMaxWindowSize_description"),
				 ZPSConfigurationPackage.Literals.NODE__APS_MAX_WINDOW_SIZE,
				 true,
				 false,
				 false,
				 ItemPropertyDescriptor.INTEGRAL_VALUE_IMAGE,
				 getString("_UI_AIBPropertyCategory"),
				 new String[] {
					"org.eclipse.ui.views.properties.expert"
				 }));
	}

	/**
	 * This adds a property descriptor for the Aps Interframe Delay feature.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	protected void addApsInterframeDelayPropertyDescriptor(Object object) {
		itemPropertyDescriptors.add
			(createItemPropertyDescriptor
				(((ComposeableAdapterFactory)adapterFactory).getRootAdapterFactory(),
				 getResourceLocator(),
				 getString("_UI_Node_apsInterframeDelay_feature"),
				 getString("_UI_Node_apsInterframeDelay_description"),
				 ZPSConfigurationPackage.Literals.NODE__APS_INTERFRAME_DELAY,
				 true,
				 false,
				 false,
				 ItemPropertyDescriptor.INTEGRAL_VALUE_IMAGE,
				 getString("_UI_AIBPropertyCategory"),
				 new String[] {
					"org.eclipse.ui.views.properties.expert"
				 }));
	}

	/**
	 * This adds a property descriptor for the Aps Security Timeout Period feature.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	protected void addApsSecurityTimeoutPeriodPropertyDescriptor(Object object) {
		itemPropertyDescriptors.add
			(createItemPropertyDescriptor
				(((ComposeableAdapterFactory)adapterFactory).getRootAdapterFactory(),
				 getResourceLocator(),
				 getString("_UI_Node_apsSecurityTimeoutPeriod_feature"),
				 getString("_UI_Node_apsSecurityTimeoutPeriod_description"),
				 ZPSConfigurationPackage.Literals.NODE__APS_SECURITY_TIMEOUT_PERIOD,
				 true,
				 false,
				 false,
				 ItemPropertyDescriptor.GENERIC_VALUE_IMAGE,
				 getString("_UI_AIBPropertyCategory"),
				 new String[] {
					"org.eclipse.ui.views.properties.expert"
				 }));
	}

	/**
	 * This adds a property descriptor for the Aps Use Ext PAN Id feature.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	protected void addApsUseExtPANIdPropertyDescriptor(Object object) {
		itemPropertyDescriptors.add
			(createItemPropertyDescriptor
				(((ComposeableAdapterFactory)adapterFactory).getRootAdapterFactory(),
				 getResourceLocator(),
				 getString("_UI_Node_apsUseExtPANId_feature"),
				 getString("_UI_Node_apsUseExtPANId_description"),
				 ZPSConfigurationPackage.Literals.NODE__APS_USE_EXT_PAN_ID,
				 true,
				 false,
				 false,
				 ItemPropertyDescriptor.GENERIC_VALUE_IMAGE,
				 getString("_UI_AIBPropertyCategory"),
				 new String[] {
					"org.eclipse.ui.views.properties.expert"
				 }));
	}

	/**
	 * This adds a property descriptor for the Initial Network Key feature.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	protected void addInitialNetworkKeyPropertyDescriptor(Object object) {
		itemPropertyDescriptors.add
			(createItemPropertyDescriptor
				(((ComposeableAdapterFactory)adapterFactory).getRootAdapterFactory(),
				 getResourceLocator(),
				 getString("_UI_Node_InitialNetworkKey_feature"),
				 getString("_UI_PropertyDescriptor_description", "_UI_Node_InitialNetworkKey_feature", "_UI_Node_type"),
				 ZPSConfigurationPackage.Literals.NODE__INITIAL_NETWORK_KEY,
				 true,
				 false,
				 true,
				 null,
				 null,
				 null));
	}

	/**
	 * This adds a property descriptor for the Security Enabled feature.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	protected void addSecurityEnabledPropertyDescriptor(Object object) {
		itemPropertyDescriptors.add
			(createItemPropertyDescriptor
				(((ComposeableAdapterFactory)adapterFactory).getRootAdapterFactory(),
				 getResourceLocator(),
				 getString("_UI_Node_SecurityEnabled_feature"),
				 getString("_UI_PropertyDescriptor_description", "_UI_Node_SecurityEnabled_feature", "_UI_Node_type"),
				 ZPSConfigurationPackage.Literals.NODE__SECURITY_ENABLED,
				 true,
				 false,
				 false,
				 ItemPropertyDescriptor.BOOLEAN_VALUE_IMAGE,
				 null,
				 null));
	}

	/**
	 * This adds a property descriptor for the MAC Mlme Dcfm Ind Message feature.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	protected void addMACMlmeDcfmIndMessagePropertyDescriptor(Object object) {
		itemPropertyDescriptors.add
			(createItemPropertyDescriptor
				(((ComposeableAdapterFactory)adapterFactory).getRootAdapterFactory(),
				 getResourceLocator(),
				 getString("_UI_Node_MACMlmeDcfmIndMessage_feature"),
				 getString("_UI_Node_MACMlmeDcfmIndMessage_description"),
				 ZPSConfigurationPackage.Literals.NODE__MAC_MLME_DCFM_IND_MESSAGE,
				 true,
				 false,
				 false,
				 ItemPropertyDescriptor.GENERIC_VALUE_IMAGE,
				 getString("_UI_InternalPropertyCategory"),
				 new String[] {
					"com.jennic.internal"
				 }));
	}

	/**
	 * This adds a property descriptor for the MAC Mcps Dcfm Ind Message feature.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	protected void addMACMcpsDcfmIndMessagePropertyDescriptor(Object object) {
		itemPropertyDescriptors.add
			(createItemPropertyDescriptor
				(((ComposeableAdapterFactory)adapterFactory).getRootAdapterFactory(),
				 getResourceLocator(),
				 getString("_UI_Node_MACMcpsDcfmIndMessage_feature"),
				 getString("_UI_Node_MACMcpsDcfmIndMessage_description"),
				 ZPSConfigurationPackage.Literals.NODE__MAC_MCPS_DCFM_IND_MESSAGE,
				 true,
				 false,
				 false,
				 ItemPropertyDescriptor.GENERIC_VALUE_IMAGE,
				 getString("_UI_InternalPropertyCategory"),
				 new String[] {
					"com.jennic.internal"
				 }));
	}

	/**
	 * This adds a property descriptor for the APS Persistence Time feature.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	protected void addAPSPersistenceTimePropertyDescriptor(Object object) {
		itemPropertyDescriptors.add
			(createItemPropertyDescriptor
				(((ComposeableAdapterFactory)adapterFactory).getRootAdapterFactory(),
				 getResourceLocator(),
				 getString("_UI_Node_APSPersistenceTime_feature"),
				 getString("_UI_PropertyDescriptor_description", "_UI_Node_APSPersistenceTime_feature", "_UI_Node_type"),
				 ZPSConfigurationPackage.Literals.NODE__APS_PERSISTENCE_TIME,
				 true,
				 false,
				 false,
				 ItemPropertyDescriptor.INTEGRAL_VALUE_IMAGE,
				 getString("_UI_APSLayerConfigurationPropertyCategory"),
				 new String[] {
					"org.eclipse.ui.views.properties.expert"
				 }));
	}

	/**
	 * This adds a property descriptor for the Num APSME Simul Commands feature.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	protected void addNumAPSMESimulCommandsPropertyDescriptor(Object object) {
		itemPropertyDescriptors.add
			(createItemPropertyDescriptor
				(((ComposeableAdapterFactory)adapterFactory).getRootAdapterFactory(),
				 getResourceLocator(),
				 getString("_UI_Node_NumAPSMESimulCommands_feature"),
				 getString("_UI_Node_NumAPSMESimulCommands_description"),
				 ZPSConfigurationPackage.Literals.NODE__NUM_APSME_SIMUL_COMMANDS,
				 true,
				 false,
				 false,
				 ItemPropertyDescriptor.INTEGRAL_VALUE_IMAGE,
				 getString("_UI_InternalPropertyCategory"),
				 new String[] {
					"com.jennic.internal"
				 }));
	}

	/**
	 * This adds a property descriptor for the Stack Profile feature.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	protected void addStackProfilePropertyDescriptor(Object object) {
		itemPropertyDescriptors.add
			(createItemPropertyDescriptor
				(((ComposeableAdapterFactory)adapterFactory).getRootAdapterFactory(),
				 getResourceLocator(),
				 getString("_UI_Node_StackProfile_feature"),
				 getString("_UI_Node_StackProfile_description"),
				 ZPSConfigurationPackage.Literals.NODE__STACK_PROFILE,
				 true,
				 false,
				 false,
				 ItemPropertyDescriptor.INTEGRAL_VALUE_IMAGE,
				 getString("_UI_NetworkLayerConfigurationPropertyCategory"),
				 new String[] {
					"org.eclipse.ui.views.properties.expert"
				 }));
	}

	/**
	 * This adds a property descriptor for the Inter PAN feature.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	protected void addInterPANPropertyDescriptor(Object object) {
		itemPropertyDescriptors.add
			(createItemPropertyDescriptor
				(((ComposeableAdapterFactory)adapterFactory).getRootAdapterFactory(),
				 getResourceLocator(),
				 getString("_UI_Node_InterPAN_feature"),
				 getString("_UI_Node_InterPAN_description"),
				 ZPSConfigurationPackage.Literals.NODE__INTER_PAN,
				 true,
				 false,
				 false,
				 ItemPropertyDescriptor.BOOLEAN_VALUE_IMAGE,
				 getString("_UI_APSLayerConfigurationPropertyCategory"),
				 new String[] {
					"org.eclipse.ui.views.properties.expert"
				 }));
	}

	/**
	 * This adds a property descriptor for the Green Power Support feature.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	protected void addGreenPowerSupportPropertyDescriptor(Object object) {
		itemPropertyDescriptors.add
			(createItemPropertyDescriptor
				(((ComposeableAdapterFactory)adapterFactory).getRootAdapterFactory(),
				 getResourceLocator(),
				 getString("_UI_Node_GreenPowerSupport_feature"),
				 getString("_UI_Node_GreenPowerSupport_description"),
				 ZPSConfigurationPackage.Literals.NODE__GREEN_POWER_SUPPORT,
				 true,
				 false,
				 false,
				 ItemPropertyDescriptor.BOOLEAN_VALUE_IMAGE,
				 null,
				 null));
	}

	/**
	 * This adds a property descriptor for the Nwk Fc Save Count Bit Shift feature.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	protected void addNwkFcSaveCountBitShiftPropertyDescriptor(Object object) {
		itemPropertyDescriptors.add
			(createItemPropertyDescriptor
				(((ComposeableAdapterFactory)adapterFactory).getRootAdapterFactory(),
				 getResourceLocator(),
				 getString("_UI_Node_NwkFcSaveCountBitShift_feature"),
				 getString("_UI_Node_NwkFcSaveCountBitShift_description"),
				 ZPSConfigurationPackage.Literals.NODE__NWK_FC_SAVE_COUNT_BIT_SHIFT,
				 true,
				 false,
				 false,
				 ItemPropertyDescriptor.INTEGRAL_VALUE_IMAGE,
				 getString("_UI_NetworkLayerConfigurationPropertyCategory"),
				 new String[] {
					"org.eclipse.ui.views.properties.expert"
				 }));
	}

	/**
	 * This adds a property descriptor for the Aps Fc Save Count Bit Shift feature.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	protected void addApsFcSaveCountBitShiftPropertyDescriptor(Object object) {
		itemPropertyDescriptors.add
			(createItemPropertyDescriptor
				(((ComposeableAdapterFactory)adapterFactory).getRootAdapterFactory(),
				 getResourceLocator(),
				 getString("_UI_Node_ApsFcSaveCountBitShift_feature"),
				 getString("_UI_Node_ApsFcSaveCountBitShift_description"),
				 ZPSConfigurationPackage.Literals.NODE__APS_FC_SAVE_COUNT_BIT_SHIFT,
				 true,
				 false,
				 false,
				 ItemPropertyDescriptor.INTEGRAL_VALUE_IMAGE,
				 getString("_UI_APSLayerConfigurationPropertyCategory"),
				 new String[] {
					"org.eclipse.ui.views.properties.expert"
				 }));
	}

	/**
	 * This adds a property descriptor for the Mac Table Size feature.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	protected void addMacTableSizePropertyDescriptor(Object object) {
		itemPropertyDescriptors.add
			(createItemPropertyDescriptor
				(((ComposeableAdapterFactory)adapterFactory).getRootAdapterFactory(),
				 getResourceLocator(),
				 getString("_UI_Node_MacTableSize_feature"),
				 getString("_UI_PropertyDescriptor_description", "_UI_Node_MacTableSize_feature", "_UI_Node_type"),
				 ZPSConfigurationPackage.Literals.NODE__MAC_TABLE_SIZE,
				 true,
				 false,
				 false,
				 ItemPropertyDescriptor.GENERIC_VALUE_IMAGE,
				 null,
				 null));
	}

	/**
	 * This adds a property descriptor for the Default Callback Name feature.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	protected void addDefaultCallbackNamePropertyDescriptor(Object object) {
		itemPropertyDescriptors.add
			(createItemPropertyDescriptor
				(((ComposeableAdapterFactory)adapterFactory).getRootAdapterFactory(),
				 getResourceLocator(),
				 getString("_UI_Node_DefaultCallbackName_feature"),
				 getString("_UI_PropertyDescriptor_description", "_UI_Node_DefaultCallbackName_feature", "_UI_Node_type"),
				 ZPSConfigurationPackage.Literals.NODE__DEFAULT_CALLBACK_NAME,
				 true,
				 false,
				 false,
				 ItemPropertyDescriptor.GENERIC_VALUE_IMAGE,
				 null,
				 null));
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
			childrenFeatures.add(ZPSConfigurationPackage.Literals.NODE__ENDPOINTS);
			childrenFeatures.add(ZPSConfigurationPackage.Literals.NODE__PDU_CONFIGURATION);
			childrenFeatures.add(ZPSConfigurationPackage.Literals.NODE__CHANNEL_MASK);
			childrenFeatures.add(ZPSConfigurationPackage.Literals.NODE__NODE_DESCRIPTOR);
			childrenFeatures.add(ZPSConfigurationPackage.Literals.NODE__NODE_POWER_DESCRIPTOR);
			childrenFeatures.add(ZPSConfigurationPackage.Literals.NODE__USER_DESCRIPTOR);
			childrenFeatures.add(ZPSConfigurationPackage.Literals.NODE__BINDING_TABLE);
			childrenFeatures.add(ZPSConfigurationPackage.Literals.NODE__GROUP_TABLE);
			childrenFeatures.add(ZPSConfigurationPackage.Literals.NODE__KEY_DESCRIPTOR_TABLE);
			childrenFeatures.add(ZPSConfigurationPackage.Literals.NODE__GREEN_POWER_TX_QUEUE);
			childrenFeatures.add(ZPSConfigurationPackage.Literals.NODE__GREEN_POWER_SECURITY_TABLE);
			childrenFeatures.add(ZPSConfigurationPackage.Literals.NODE__MAC_INTERFACE_LIST);
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
		String label = ((Node)object).getName();
		return label == null || label.length() == 0 ?
			getString("_UI_Node_type") :
			getString("_UI_Node_type") + " " + label;
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

		switch (notification.getFeatureID(Node.class)) {
			case ZPSConfigurationPackage.NODE__DISCOVERY_NEIGHBOUR_TABLE_SIZE:
			case ZPSConfigurationPackage.NODE__ACTIVE_NEIGHBOUR_TABLE_SIZE:
			case ZPSConfigurationPackage.NODE__ROUTE_DISCOVERY_TABLE_SIZE:
			case ZPSConfigurationPackage.NODE__ROUTING_TABLE_SIZE:
			case ZPSConfigurationPackage.NODE__BROADCAST_TRANSACTION_TABLE_SIZE:
			case ZPSConfigurationPackage.NODE__ROUTE_RECORD_TABLE_SIZE:
			case ZPSConfigurationPackage.NODE__ADDRESS_MAP_TABLE_SIZE:
			case ZPSConfigurationPackage.NODE__SECURITY_MATERIAL_SETS:
			case ZPSConfigurationPackage.NODE__MAX_NUM_SIMULTANEOUS_APSDE_REQ:
			case ZPSConfigurationPackage.NODE__MAX_NUM_SIMULTANEOUS_APSDE_ACK_REQ:
			case ZPSConfigurationPackage.NODE__MAC_MUTEX_NAME:
			case ZPSConfigurationPackage.NODE__ZPS_MUTEX_NAME:
			case ZPSConfigurationPackage.NODE__FRAGMENTATION_MAX_NUM_SIMUL_RX:
			case ZPSConfigurationPackage.NODE__FRAGMENTATION_MAX_NUM_SIMUL_TX:
			case ZPSConfigurationPackage.NODE__DEFAULT_EVENT_MESSAGE_NAME:
			case ZPSConfigurationPackage.NODE__MAC_DCFM_IND_MESSAGE:
			case ZPSConfigurationPackage.NODE__MAC_TIME_EVENT_MESSAGE:
			case ZPSConfigurationPackage.NODE__APS_NON_MEMBER_RADIUS:
			case ZPSConfigurationPackage.NODE__APS_DESIGNATED_COORDINATOR:
			case ZPSConfigurationPackage.NODE__APS_USE_INSECURE_JOIN:
			case ZPSConfigurationPackage.NODE__APS_MAX_WINDOW_SIZE:
			case ZPSConfigurationPackage.NODE__APS_INTERFRAME_DELAY:
			case ZPSConfigurationPackage.NODE__APS_DUPLICATE_TABLE_SIZE:
			case ZPSConfigurationPackage.NODE__APS_SECURITY_TIMEOUT_PERIOD:
			case ZPSConfigurationPackage.NODE__APS_USE_EXT_PAN_ID:
			case ZPSConfigurationPackage.NODE__SECURITY_ENABLED:
			case ZPSConfigurationPackage.NODE__MAC_MLME_DCFM_IND_MESSAGE:
			case ZPSConfigurationPackage.NODE__MAC_MCPS_DCFM_IND_MESSAGE:
			case ZPSConfigurationPackage.NODE__APS_PERSISTENCE_TIME:
			case ZPSConfigurationPackage.NODE__NUM_APSME_SIMUL_COMMANDS:
			case ZPSConfigurationPackage.NODE__STACK_PROFILE:
			case ZPSConfigurationPackage.NODE__INTER_PAN:
			case ZPSConfigurationPackage.NODE__GREEN_POWER_SUPPORT:
			case ZPSConfigurationPackage.NODE__NWK_FC_SAVE_COUNT_BIT_SHIFT:
			case ZPSConfigurationPackage.NODE__APS_FC_SAVE_COUNT_BIT_SHIFT:
			case ZPSConfigurationPackage.NODE__MAC_TABLE_SIZE:
			case ZPSConfigurationPackage.NODE__DEFAULT_CALLBACK_NAME:
				fireNotifyChanged(new ViewerNotification(notification, notification.getNotifier(), false, true));
				return;
			case ZPSConfigurationPackage.NODE__ENDPOINTS:
			case ZPSConfigurationPackage.NODE__PDU_CONFIGURATION:
			case ZPSConfigurationPackage.NODE__CHANNEL_MASK:
			case ZPSConfigurationPackage.NODE__NODE_DESCRIPTOR:
			case ZPSConfigurationPackage.NODE__NODE_POWER_DESCRIPTOR:
			case ZPSConfigurationPackage.NODE__USER_DESCRIPTOR:
			case ZPSConfigurationPackage.NODE__BINDING_TABLE:
			case ZPSConfigurationPackage.NODE__GROUP_TABLE:
			case ZPSConfigurationPackage.NODE__KEY_DESCRIPTOR_TABLE:
			case ZPSConfigurationPackage.NODE__GREEN_POWER_TX_QUEUE:
			case ZPSConfigurationPackage.NODE__GREEN_POWER_SECURITY_TABLE:
			case ZPSConfigurationPackage.NODE__MAC_INTERFACE_LIST:
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
	 * @generated NOT
	 */
	@Override
	protected void collectNewChildDescriptors(Collection<Object> newChildDescriptors, Object object) {
		super.collectNewChildDescriptors(newChildDescriptors, object);

		newChildDescriptors.add
			(createChildParameter
				(ZPSConfigurationPackage.Literals.NODE__ENDPOINTS,
				 ZPSConfigurationFactory.eINSTANCE.createEndPoint()));

		newChildDescriptors.add
			(createChildParameter
				(ZPSConfigurationPackage.Literals.NODE__PDU_CONFIGURATION,
				 ZPSConfigurationFactory.eINSTANCE.createPDUManager()));

		newChildDescriptors.add
			(createChildParameter
				(ZPSConfigurationPackage.Literals.NODE__CHANNEL_MASK,
				 ZPSConfigurationFactory.eINSTANCE.createChannelMask()));

		newChildDescriptors.add
			(createChildParameter
				(ZPSConfigurationPackage.Literals.NODE__NODE_DESCRIPTOR,
				 ZPSConfigurationFactory.eINSTANCE.createNodeDescriptor()));

		newChildDescriptors.add
			(createChildParameter
				(ZPSConfigurationPackage.Literals.NODE__NODE_POWER_DESCRIPTOR,
				 ZPSConfigurationFactory.eINSTANCE.createNodePowerDescriptor()));

		newChildDescriptors.add
			(createChildParameter
				(ZPSConfigurationPackage.Literals.NODE__USER_DESCRIPTOR,
				 ZPSConfigurationFactory.eINSTANCE.createUserDescriptor()));

		
		newChildDescriptors.add
			(createChildParameter
				(ZPSConfigurationPackage.Literals.NODE__BINDING_TABLE,
				 ZPSConfigurationFactory.eINSTANCE.createBindingTable()));

		newChildDescriptors.add
			(createChildParameter
				(ZPSConfigurationPackage.Literals.NODE__GROUP_TABLE,
				 ZPSConfigurationFactory.eINSTANCE.createGroupTable()));

		newChildDescriptors.add
			(createChildParameter
				(ZPSConfigurationPackage.Literals.NODE__KEY_DESCRIPTOR_TABLE,
				 ZPSConfigurationFactory.eINSTANCE.createKeyDescriptorTable()));
		
		newChildDescriptors.add
		(createChildParameter
			(ZPSConfigurationPackage.Literals.NODE__GREEN_POWER_TX_QUEUE,
			 ZPSConfigurationFactory.eINSTANCE.createGreenPowerTxQueue()));
		
		newChildDescriptors.add
		(createChildParameter
			(ZPSConfigurationPackage.Literals.NODE__GREEN_POWER_SECURITY_TABLE,
			 ZPSConfigurationFactory.eINSTANCE.createGreenPowerSecurityTable()));
		
		newChildDescriptors.add
		(createChildParameter
			(ZPSConfigurationPackage.Literals.NODE__MAC_INTERFACE_LIST,
			 ZPSConfigurationFactory.eINSTANCE.createMacInterfaceList()));
	}

	/**
	 * @generated NOT
	 */
	@Override
	protected Command createRemoveCommand(EditingDomain domain, EObject owner,
			EStructuralFeature feature, Collection<?> collection) {


		for (Iterator<?> iterator = collection.iterator(); iterator.hasNext();) {
			Object object = (Object) iterator.next();
			
			if (object instanceof EndPoint) {
				String name = ((EndPoint)(object)).getName();
				
				if (null != name && 0 == name.compareTo("ZDO")) {
					return UnexecutableCommand.INSTANCE;
				}
			}
		}
		
		return super.createRemoveCommand(domain, owner, feature, collection);
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
				0 == ref.getName().compareTo("PDUConfiguration") ||
				0 == ref.getName().compareTo("ChannelMask") ||
				0 == ref.getName().compareTo("NodePowerDescriptor") ||
				0 == ref.getName().compareTo("ZDOServers") ||
				0 == ref.getName().compareTo("NodeDescriptor")) {
								
				return UnexecutableCommand.INSTANCE;
			}			
		}		
		
		return super.createSetCommand(domain, owner, feature, value);
	}

	/**
	 * @generated NOT
	 */
	@Override
	protected Command createAddCommand(EditingDomain domain, EObject owner,
			EStructuralFeature feature, Collection<?> collection, int index) {

		if (feature instanceof EndPoint) {			
			String name = ((EndPoint)feature).getName();
			if (null != name && 0 == name.compareTo("ZDO")) {
				return UnexecutableCommand.INSTANCE;
			}	
		}

		if (owner instanceof Node) {
			
			for (Iterator<?> it = collection.iterator(); it.hasNext(); ) {
				Object obj = it.next();
				
				if (obj instanceof EndPoint) {
					EndPoint ep = (EndPoint)obj;
					
					if (ep.getNode() != owner && ep.getInputClusters() != null && ep.getInputClusters().size() > 0) {
						return UnexecutableCommand.INSTANCE;
					}
				}
			}			
		}
		
		return super.createAddCommand(domain, owner, feature, collection, index);
	}
}
