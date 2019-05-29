/**
 * (C) Jennic Ltd
 *
 * $Id: NodeDescriptorImpl.java 78109 2016-03-24 15:51:22Z nxp29741 $
 */
package com.jennic.ZPSConfiguration.impl;


import java.math.BigInteger;
import java.util.Iterator;
import java.util.ListIterator;

import org.eclipse.emf.common.notify.Notification;
import org.eclipse.emf.common.notify.NotificationChain;

import org.eclipse.emf.ecore.EClass;
import org.eclipse.emf.ecore.InternalEObject;

import org.eclipse.emf.ecore.impl.ENotificationImpl;
import org.eclipse.emf.ecore.impl.EObjectImpl;

import org.eclipse.emf.ecore.util.EcoreUtil;

import com.jennic.ZPSConfiguration.APDU;
import com.jennic.ZPSConfiguration.AlwaysOnNode;
import com.jennic.ZPSConfiguration.Coordinator;
import com.jennic.ZPSConfiguration.EndDevice;
import com.jennic.ZPSConfiguration.EndPoint;
import com.jennic.ZPSConfiguration.FrequencyBands;
import com.jennic.ZPSConfiguration.InputCluster;
import com.jennic.ZPSConfiguration.Node;
import com.jennic.ZPSConfiguration.NodeDescriptor;
import com.jennic.ZPSConfiguration.NodeLogicalType;
import com.jennic.ZPSConfiguration.NodePowerDescriptor;
import com.jennic.ZPSConfiguration.OutputCluster;
import com.jennic.ZPSConfiguration.Router;
import com.jennic.ZPSConfiguration.ZDOCommonServers;
import com.jennic.ZPSConfiguration.ZPSConfigurationPackage;

/**
 * <!-- begin-user-doc -->
 * An implementation of the model object '<em><b>Node Descriptor</b></em>'.
 * <!-- end-user-doc -->
 * <p>
 * The following features are implemented:
 * <ul>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.NodeDescriptorImpl#getManufacturerCode <em>Manufacturer Code</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.NodeDescriptorImpl#getLogicalType <em>Logical Type</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.NodeDescriptorImpl#isComplexDescriptorAvailable <em>Complex Descriptor Available</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.NodeDescriptorImpl#isUserDescriptorAvailable <em>User Descriptor Available</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.NodeDescriptorImpl#getAPSFlags <em>APS Flags</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.NodeDescriptorImpl#getFrequencyBand <em>Frequency Band</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.NodeDescriptorImpl#isAlternatePANCoordinator <em>Alternate PAN Coordinator</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.NodeDescriptorImpl#isDeviceType <em>Device Type</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.NodeDescriptorImpl#isPowerSource <em>Power Source</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.NodeDescriptorImpl#isRxOnWhenIdle <em>Rx On When Idle</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.NodeDescriptorImpl#isSecurity <em>Security</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.NodeDescriptorImpl#isAllocateAddress <em>Allocate Address</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.NodeDescriptorImpl#getMaximumBufferSize <em>Maximum Buffer Size</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.NodeDescriptorImpl#getMaximumIncomingTransferSize <em>Maximum Incoming Transfer Size</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.NodeDescriptorImpl#getMaximumOutgoingTransferSize <em>Maximum Outgoing Transfer Size</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.NodeDescriptorImpl#isExtendedActiveEndpointListAvailable <em>Extended Active Endpoint List Available</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.NodeDescriptorImpl#isExtendedSimpleDescriptorListAvailable <em>Extended Simple Descriptor List Available</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.NodeDescriptorImpl#isPrimaryTrustCenter <em>Primary Trust Center</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.NodeDescriptorImpl#isBackupTrustCenter <em>Backup Trust Center</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.NodeDescriptorImpl#isPrimaryBindingTableCache <em>Primary Binding Table Cache</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.NodeDescriptorImpl#isBackupBindingTableCache <em>Backup Binding Table Cache</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.NodeDescriptorImpl#isPrimaryDiscoveryCache <em>Primary Discovery Cache</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.NodeDescriptorImpl#isBackupDiscoveryCache <em>Backup Discovery Cache</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.NodeDescriptorImpl#getNode <em>Node</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.NodeDescriptorImpl#isNetworkManager <em>Network Manager</em>}</li>
 * </ul>
 * </p>
 *
 * @generated
 */
public class NodeDescriptorImpl extends EObjectImpl implements NodeDescriptor {
	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public static final String copyright = "(C) NXP B.V";

	/**
	 * The default value of the '{@link #getManufacturerCode() <em>Manufacturer Code</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getManufacturerCode()
	 * @generated
	 * @ordered
	 */
	protected static final int MANUFACTURER_CODE_EDEFAULT = 0;

	/**
	 * The cached value of the '{@link #getManufacturerCode() <em>Manufacturer Code</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getManufacturerCode()
	 * @generated
	 * @ordered
	 */
	protected int manufacturerCode = MANUFACTURER_CODE_EDEFAULT;

	/**
	 * The default value of the '{@link #getLogicalType() <em>Logical Type</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getLogicalType()
	 * @generated
	 * @ordered
	 */
	protected static final NodeLogicalType LOGICAL_TYPE_EDEFAULT = NodeLogicalType.ZIGBEE_END_DEVICE;

	/**
	 * The default value of the '{@link #isComplexDescriptorAvailable() <em>Complex Descriptor Available</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #isComplexDescriptorAvailable()
	 * @generated
	 * @ordered
	 */
	protected static final boolean COMPLEX_DESCRIPTOR_AVAILABLE_EDEFAULT = false;

	/**
	 * The default value of the '{@link #isUserDescriptorAvailable() <em>User Descriptor Available</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #isUserDescriptorAvailable()
	 * @generated
	 * @ordered
	 */
	protected static final boolean USER_DESCRIPTOR_AVAILABLE_EDEFAULT = false;

	/**
	 * The default value of the '{@link #getAPSFlags() <em>APS Flags</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getAPSFlags()
	 * @generated
	 * @ordered
	 */
	protected static final BigInteger APS_FLAGS_EDEFAULT = new BigInteger("0");

	/**
	 * The default value of the '{@link #getFrequencyBand() <em>Frequency Band</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getFrequencyBand()
	 * @generated
	 * @ordered
	 */
	protected static final FrequencyBands FREQUENCY_BAND_EDEFAULT = FrequencyBands.FREQ2400_MHZ;

	/**
	 * The default value of the '{@link #isAlternatePANCoordinator() <em>Alternate PAN Coordinator</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #isAlternatePANCoordinator()
	 * @generated
	 * @ordered
	 */
	protected static final boolean ALTERNATE_PAN_COORDINATOR_EDEFAULT = false;

	/**
	 * The default value of the '{@link #isDeviceType() <em>Device Type</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #isDeviceType()
	 * @generated
	 * @ordered
	 */
	protected static final boolean DEVICE_TYPE_EDEFAULT = false;

	/**
	 * The default value of the '{@link #isPowerSource() <em>Power Source</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #isPowerSource()
	 * @generated
	 * @ordered
	 */
	protected static final boolean POWER_SOURCE_EDEFAULT = false;

	/**
	 * The default value of the '{@link #isRxOnWhenIdle() <em>Rx On When Idle</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #isRxOnWhenIdle()
	 * @generated
	 * @ordered
	 */
	protected static final boolean RX_ON_WHEN_IDLE_EDEFAULT = true;

	/**
	 * The default value of the '{@link #isSecurity() <em>Security</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #isSecurity()
	 * @generated
	 * @ordered
	 */
	protected static final boolean SECURITY_EDEFAULT = false;

	/**
	 * The default value of the '{@link #isAllocateAddress() <em>Allocate Address</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #isAllocateAddress()
	 * @generated
	 * @ordered
	 */
	protected static final boolean ALLOCATE_ADDRESS_EDEFAULT = true;

	/**
	 * The cached value of the '{@link #isAllocateAddress() <em>Allocate Address</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #isAllocateAddress()
	 * @generated
	 * @ordered
	 */
	protected boolean allocateAddress = ALLOCATE_ADDRESS_EDEFAULT;

	/**
	 * The default value of the '{@link #getMaximumBufferSize() <em>Maximum Buffer Size</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getMaximumBufferSize()
	 * @generated
	 * @ordered
	 */
	protected static final BigInteger MAXIMUM_BUFFER_SIZE_EDEFAULT = new BigInteger("127");

	/**
	 * The cached value of the '{@link #getMaximumBufferSize() <em>Maximum Buffer Size</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getMaximumBufferSize()
	 * @generated
	 * @ordered
	 */
	protected BigInteger maximumBufferSize = MAXIMUM_BUFFER_SIZE_EDEFAULT;

	/**
	 * The default value of the '{@link #getMaximumIncomingTransferSize() <em>Maximum Incoming Transfer Size</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getMaximumIncomingTransferSize()
	 * @generated
	 * @ordered
	 */
	protected static final int MAXIMUM_INCOMING_TRANSFER_SIZE_EDEFAULT = 0;

	/**
	 * The default value of the '{@link #getMaximumOutgoingTransferSize() <em>Maximum Outgoing Transfer Size</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getMaximumOutgoingTransferSize()
	 * @generated
	 * @ordered
	 */
	protected static final int MAXIMUM_OUTGOING_TRANSFER_SIZE_EDEFAULT = 0;

	/**
	 * The default value of the '{@link #isExtendedActiveEndpointListAvailable() <em>Extended Active Endpoint List Available</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #isExtendedActiveEndpointListAvailable()
	 * @generated
	 * @ordered
	 */
	protected static final boolean EXTENDED_ACTIVE_ENDPOINT_LIST_AVAILABLE_EDEFAULT = false;

	/**
	 * The default value of the '{@link #isExtendedSimpleDescriptorListAvailable() <em>Extended Simple Descriptor List Available</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #isExtendedSimpleDescriptorListAvailable()
	 * @generated
	 * @ordered
	 */
	protected static final boolean EXTENDED_SIMPLE_DESCRIPTOR_LIST_AVAILABLE_EDEFAULT = false;

	/**
	 * The default value of the '{@link #isPrimaryTrustCenter() <em>Primary Trust Center</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #isPrimaryTrustCenter()
	 * @generated
	 * @ordered
	 */
	protected static final boolean PRIMARY_TRUST_CENTER_EDEFAULT = false;

	/**
	 * The default value of the '{@link #isBackupTrustCenter() <em>Backup Trust Center</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #isBackupTrustCenter()
	 * @generated
	 * @ordered
	 */
	protected static final boolean BACKUP_TRUST_CENTER_EDEFAULT = false;

	/**
	 * The default value of the '{@link #isPrimaryBindingTableCache() <em>Primary Binding Table Cache</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #isPrimaryBindingTableCache()
	 * @generated
	 * @ordered
	 */
	protected static final boolean PRIMARY_BINDING_TABLE_CACHE_EDEFAULT = false;

	/**
	 * The default value of the '{@link #isBackupBindingTableCache() <em>Backup Binding Table Cache</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #isBackupBindingTableCache()
	 * @generated
	 * @ordered
	 */
	protected static final boolean BACKUP_BINDING_TABLE_CACHE_EDEFAULT = false;

	/**
	 * The default value of the '{@link #isPrimaryDiscoveryCache() <em>Primary Discovery Cache</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #isPrimaryDiscoveryCache()
	 * @generated
	 * @ordered
	 */
	protected static final boolean PRIMARY_DISCOVERY_CACHE_EDEFAULT = false;

	/**
	 * The default value of the '{@link #isBackupDiscoveryCache() <em>Backup Discovery Cache</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #isBackupDiscoveryCache()
	 * @generated
	 * @ordered
	 */
	protected static final boolean BACKUP_DISCOVERY_CACHE_EDEFAULT = false;

	/**
	 * The default value of the '{@link #isNetworkManager() <em>Network Manager</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #isNetworkManager()
	 * @generated
	 * @ordered
	 */
	protected static final boolean NETWORK_MANAGER_EDEFAULT = false;

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	protected NodeDescriptorImpl() {
		super();
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	@Override
	protected EClass eStaticClass() {
		return ZPSConfigurationPackage.Literals.NODE_DESCRIPTOR;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public int getManufacturerCode() {
		return manufacturerCode;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void setManufacturerCode(int newManufacturerCode) {
		int oldManufacturerCode = manufacturerCode;
		manufacturerCode = newManufacturerCode;
		if (eNotificationRequired())
			eNotify(new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.NODE_DESCRIPTOR__MANUFACTURER_CODE, oldManufacturerCode, manufacturerCode));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated NOT
	 */
	public NodeLogicalType getLogicalType() {
		if (getNode().getClass() == CoordinatorImpl.class) {
			return NodeLogicalType.ZIGBEE_COORDINATOR;
		} else if (getNode().getClass() == RouterImpl.class) { 
			return NodeLogicalType.ZIGBEE_ROUTER;
		} else { 
			return NodeLogicalType.ZIGBEE_END_DEVICE;
		}
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated NOT
	 */
	public boolean isComplexDescriptorAvailable() {
		return false;
		// return getNode().getComplexDescriptor() != null;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated NOT
	 */
	public boolean isUserDescriptorAvailable() {
		return getNode().getUserDescriptor() != null;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void setUserDescriptorAvailable(boolean newUserDescriptorAvailable) {
		// TODO: implement this method to set the 'User Descriptor Available' attribute
		// Ensure that you remove @generated or mark it @generated NOT
		throw new UnsupportedOperationException();
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated NOT
	 */
	public BigInteger getAPSFlags() {
		return BigInteger.ZERO;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated NOT
	 */
	public FrequencyBands getFrequencyBand() {
		return FrequencyBands.FREQ2400_MHZ;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated NOT
	 */
	public boolean isAlternatePANCoordinator() {
		return getNode().getClass() == CoordinatorImpl.class;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated NOT
	 */
	public boolean isDeviceType() {
		return getNode().getClass() != EndDeviceImpl.class;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated NOT
	 */
	public boolean isPowerSource() {
		NodePowerDescriptor nodePwrDescr = getNode().getNodePowerDescriptor();
		
		if (null != nodePwrDescr) {
			return nodePwrDescr.isConstantPower();
		} else {
			return true;
		}
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated NOT
	 */
	public boolean isRxOnWhenIdle() {
		
		if (this.eContainer() instanceof EndDeviceImpl) {
			EndDevice ed = (EndDevice)this.eContainer();
			
			return !ed.isSleeping();
		}
		
		return true;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated NOT
	 */
	public boolean isSecurity() {
		// always standard security
		return false;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public boolean isAllocateAddress() {
		return allocateAddress;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void setAllocateAddress(boolean newAllocateAddress) {
		boolean oldAllocateAddress = allocateAddress;
		allocateAddress = newAllocateAddress;
		if (eNotificationRequired())
			eNotify(new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.NODE_DESCRIPTOR__ALLOCATE_ADDRESS, oldAllocateAddress, allocateAddress));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public BigInteger getMaximumBufferSize() {
		return maximumBufferSize;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated NOT
	 */
	public int getMaximumIncomingTransferSize() {
		ListIterator<EndPoint> it;
		int val = 0;
		String apduName = "apduZDP";
		
		for (it = getNode().getEndpoints().listIterator(); it.hasNext(); ) {
			EndPoint endPoint = it.next();
			
			ListIterator<InputCluster> clIt;
			
			for (clIt = endPoint.getInputClusters().listIterator(); clIt.hasNext(); ) {
				InputCluster inputCluster = clIt.next();
				
				APDU rxAPDU = inputCluster.getRxAPDU();
				
				if (null != rxAPDU && null != rxAPDU.getName() && 0 != apduName.compareTo(rxAPDU.getName()) ) {
					if (rxAPDU.getSize() > val) {
						val = rxAPDU.getSize();
					}
				}
			}
		}
		
		return val;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated NOT
	 */
	public int getMaximumOutgoingTransferSize() {
		ListIterator<EndPoint> it;
		int val = 0;
		String apduName = "apduZDP";
		
		for (it = getNode().getEndpoints().listIterator(); it.hasNext(); ) {
			EndPoint endPoint = it.next();
			
			ListIterator<OutputCluster> clIt;
			
			for (clIt = endPoint.getOutputClusters().listIterator(); clIt.hasNext(); ) {
				OutputCluster outputCluster = clIt.next();
				
				for (Iterator<APDU> iterator = outputCluster.getTxAPDUs().iterator(); iterator
						.hasNext();) {
					APDU txAPDU = iterator.next();

					if (null != txAPDU && null != txAPDU.getName() && 0 != apduName.compareTo(txAPDU.getName())) {
						if (txAPDU.getSize() > val) {
							val = txAPDU.getSize();
						}
					}
				}				
			}
		}
		
		return val;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated NOT
	 */
	public boolean isExtendedActiveEndpointListAvailable() {
		Object parent = this.eContainer();
		
		ZDOCommonServers servers = null;
		
		if (parent instanceof EndDeviceImpl) {
			EndDevice ed = (EndDevice)parent;
			
			servers = ed.getZDOServers();
		} else if (parent instanceof RouterImpl) {
			Router r = (Router)parent;
			
			servers = r.getZDOServers();			
		} else if (parent instanceof CoordinatorImpl) {
			Coordinator c = (Coordinator)parent;
			
			servers = c.getZDOServers();
		}
		
		if (null != servers) {
			return null != servers.getExtendedActiveEpServer();
		}
		
		return false;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated NOT
	 */
	public boolean isExtendedSimpleDescriptorListAvailable() {
		Object parent = this.eContainer();
		
		ZDOCommonServers servers = null;
		
		if (parent instanceof EndDeviceImpl) {
			EndDevice ed = (EndDevice)parent;
			
			servers = ed.getZDOServers();
		} else if (parent instanceof RouterImpl) {
			Router r = (Router)parent;
			
			servers = r.getZDOServers();			
		} else if (parent instanceof CoordinatorImpl) {
			Coordinator c = (Coordinator)parent;
			
			servers = c.getZDOServers();
		}
		
		if (null != servers) {
			return null != servers.getExtendedSimpleDescServer();
		}
		
		return false;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated NOT
	 */
	public boolean isPrimaryTrustCenter() {
		if (getNode().getClass() == CoordinatorImpl.class || getNode().getClass() == RouterImpl.class) {
			return null != ((AlwaysOnNode)getNode()).getTrustCenter();
		} else {
			return false;
		}
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated NOT
	 */
	public boolean isBackupTrustCenter() {
		// TODO: need backup trust centre adding
		return false;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated NOT
	 */
	public boolean isPrimaryBindingTableCache() {
/*
		if (getNode().getClass() == CoordinatorImpl.class || getNode().getClass() == RouterImpl.class) {
			BindingCache bc = ((AlwaysOnNode)getNode()).getBindingCache();
			
			if (null != bc) {
				return bc.getClass() == PrimaryBindingCacheImpl.class;
			} else {
				return false;
			}
		} else {
			return false;
		}
*/
		return false;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated NOT
	 */
	public boolean isBackupBindingTableCache() {
/*
		if (getNode().getClass() == CoordinatorImpl.class || getNode().getClass() == RouterImpl.class) {
			BindingCache bc = ((AlwaysOnNode)getNode()).getBindingCache();
			
			if (null != bc) {
				return bc.getClass() == BackupBindingCacheImpl.class;
			} else {
				return false;
			}
		} else {
			return false;
		}
*/
		return false;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated NOT
	 */
	public boolean isPrimaryDiscoveryCache() {
/*
		if (getNode().getClass() == CoordinatorImpl.class || getNode().getClass() == RouterImpl.class) {
			DiscoveryCache dc = ((AlwaysOnNode)getNode()).getDiscoveryCache();
			
			if (null != dc) {
				return dc.getClass() == PrimaryDiscoveryCacheImpl.class;
			} else {
				return false;
			}
		} else {
			return false;
		}
*/
		return false;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated NOT
	 */
	public boolean isBackupDiscoveryCache() {
/*
		if (getNode().getClass() == CoordinatorImpl.class || getNode().getClass() == RouterImpl.class) {
			DiscoveryCache dc = ((AlwaysOnNode)getNode()).getDiscoveryCache();
			
			if (null != dc) {
				return dc.getClass() == BackupDiscoveryCacheImpl.class;
			} else {
				return false;
			}
		} else {
			return false;
		}
*/		
		return false;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public Node getNode() {
		if (eContainerFeatureID() != ZPSConfigurationPackage.NODE_DESCRIPTOR__NODE) return null;
		return (Node)eInternalContainer();
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public NotificationChain basicSetNode(Node newNode, NotificationChain msgs) {
		msgs = eBasicSetContainer((InternalEObject)newNode, ZPSConfigurationPackage.NODE_DESCRIPTOR__NODE, msgs);
		return msgs;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void setNode(Node newNode) {
		if (newNode != eInternalContainer() || (eContainerFeatureID() != ZPSConfigurationPackage.NODE_DESCRIPTOR__NODE && newNode != null)) {
			if (EcoreUtil.isAncestor(this, newNode))
				throw new IllegalArgumentException("Recursive containment not allowed for " + toString());
			NotificationChain msgs = null;
			if (eInternalContainer() != null)
				msgs = eBasicRemoveFromContainer(msgs);
			if (newNode != null)
				msgs = ((InternalEObject)newNode).eInverseAdd(this, ZPSConfigurationPackage.NODE__NODE_DESCRIPTOR, Node.class, msgs);
			msgs = basicSetNode(newNode, msgs);
			if (msgs != null) msgs.dispatch();
		}
		else if (eNotificationRequired())
			eNotify(new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.NODE_DESCRIPTOR__NODE, newNode, newNode));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated NOT
	 */
	public boolean isNetworkManager() {
		// TODO not sure what determines this? guess at node == coordinator
		return getNode().getClass() == CoordinatorImpl.class;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	@Override
	public NotificationChain eInverseAdd(InternalEObject otherEnd, int featureID, NotificationChain msgs) {
		switch (featureID) {
			case ZPSConfigurationPackage.NODE_DESCRIPTOR__NODE:
				if (eInternalContainer() != null)
					msgs = eBasicRemoveFromContainer(msgs);
				return basicSetNode((Node)otherEnd, msgs);
		}
		return super.eInverseAdd(otherEnd, featureID, msgs);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	@Override
	public NotificationChain eInverseRemove(InternalEObject otherEnd, int featureID, NotificationChain msgs) {
		switch (featureID) {
			case ZPSConfigurationPackage.NODE_DESCRIPTOR__NODE:
				return basicSetNode(null, msgs);
		}
		return super.eInverseRemove(otherEnd, featureID, msgs);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	@Override
	public NotificationChain eBasicRemoveFromContainerFeature(NotificationChain msgs) {
		switch (eContainerFeatureID()) {
			case ZPSConfigurationPackage.NODE_DESCRIPTOR__NODE:
				return eInternalContainer().eInverseRemove(this, ZPSConfigurationPackage.NODE__NODE_DESCRIPTOR, Node.class, msgs);
		}
		return super.eBasicRemoveFromContainerFeature(msgs);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	@Override
	public Object eGet(int featureID, boolean resolve, boolean coreType) {
		switch (featureID) {
			case ZPSConfigurationPackage.NODE_DESCRIPTOR__MANUFACTURER_CODE:
				return getManufacturerCode();
			case ZPSConfigurationPackage.NODE_DESCRIPTOR__LOGICAL_TYPE:
				return getLogicalType();
			case ZPSConfigurationPackage.NODE_DESCRIPTOR__COMPLEX_DESCRIPTOR_AVAILABLE:
				return isComplexDescriptorAvailable();
			case ZPSConfigurationPackage.NODE_DESCRIPTOR__USER_DESCRIPTOR_AVAILABLE:
				return isUserDescriptorAvailable();
			case ZPSConfigurationPackage.NODE_DESCRIPTOR__APS_FLAGS:
				return getAPSFlags();
			case ZPSConfigurationPackage.NODE_DESCRIPTOR__FREQUENCY_BAND:
				return getFrequencyBand();
			case ZPSConfigurationPackage.NODE_DESCRIPTOR__ALTERNATE_PAN_COORDINATOR:
				return isAlternatePANCoordinator();
			case ZPSConfigurationPackage.NODE_DESCRIPTOR__DEVICE_TYPE:
				return isDeviceType();
			case ZPSConfigurationPackage.NODE_DESCRIPTOR__POWER_SOURCE:
				return isPowerSource();
			case ZPSConfigurationPackage.NODE_DESCRIPTOR__RX_ON_WHEN_IDLE:
				return isRxOnWhenIdle();
			case ZPSConfigurationPackage.NODE_DESCRIPTOR__SECURITY:
				return isSecurity();
			case ZPSConfigurationPackage.NODE_DESCRIPTOR__ALLOCATE_ADDRESS:
				return isAllocateAddress();
			case ZPSConfigurationPackage.NODE_DESCRIPTOR__MAXIMUM_BUFFER_SIZE:
				return getMaximumBufferSize();
			case ZPSConfigurationPackage.NODE_DESCRIPTOR__MAXIMUM_INCOMING_TRANSFER_SIZE:
				return getMaximumIncomingTransferSize();
			case ZPSConfigurationPackage.NODE_DESCRIPTOR__MAXIMUM_OUTGOING_TRANSFER_SIZE:
				return getMaximumOutgoingTransferSize();
			case ZPSConfigurationPackage.NODE_DESCRIPTOR__EXTENDED_ACTIVE_ENDPOINT_LIST_AVAILABLE:
				return isExtendedActiveEndpointListAvailable();
			case ZPSConfigurationPackage.NODE_DESCRIPTOR__EXTENDED_SIMPLE_DESCRIPTOR_LIST_AVAILABLE:
				return isExtendedSimpleDescriptorListAvailable();
			case ZPSConfigurationPackage.NODE_DESCRIPTOR__PRIMARY_TRUST_CENTER:
				return isPrimaryTrustCenter();
			case ZPSConfigurationPackage.NODE_DESCRIPTOR__BACKUP_TRUST_CENTER:
				return isBackupTrustCenter();
			case ZPSConfigurationPackage.NODE_DESCRIPTOR__PRIMARY_BINDING_TABLE_CACHE:
				return isPrimaryBindingTableCache();
			case ZPSConfigurationPackage.NODE_DESCRIPTOR__BACKUP_BINDING_TABLE_CACHE:
				return isBackupBindingTableCache();
			case ZPSConfigurationPackage.NODE_DESCRIPTOR__PRIMARY_DISCOVERY_CACHE:
				return isPrimaryDiscoveryCache();
			case ZPSConfigurationPackage.NODE_DESCRIPTOR__BACKUP_DISCOVERY_CACHE:
				return isBackupDiscoveryCache();
			case ZPSConfigurationPackage.NODE_DESCRIPTOR__NODE:
				return getNode();
			case ZPSConfigurationPackage.NODE_DESCRIPTOR__NETWORK_MANAGER:
				return isNetworkManager();
		}
		return super.eGet(featureID, resolve, coreType);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated NOT
	 */
	@Override
	public void eSet(int featureID, Object newValue) {
		switch (featureID) {
			case ZPSConfigurationPackage.NODE_DESCRIPTOR__MANUFACTURER_CODE:
				setManufacturerCode(((Integer)newValue).intValue());
				return;
			case ZPSConfigurationPackage.NODE_DESCRIPTOR__NODE:
				setNode((Node)newValue);
				return;

			case ZPSConfigurationPackage.NODE_DESCRIPTOR__ALLOCATE_ADDRESS:
				setAllocateAddress(((Boolean)newValue).booleanValue());
				return;

			// derived values that are volatile (i.e. persisted in the xml) 
			case ZPSConfigurationPackage.NODE_DESCRIPTOR__LOGICAL_TYPE:
			case ZPSConfigurationPackage.NODE_DESCRIPTOR__COMPLEX_DESCRIPTOR_AVAILABLE:
			case ZPSConfigurationPackage.NODE_DESCRIPTOR__USER_DESCRIPTOR_AVAILABLE:
			case ZPSConfigurationPackage.NODE_DESCRIPTOR__APS_FLAGS:
			case ZPSConfigurationPackage.NODE_DESCRIPTOR__FREQUENCY_BAND:
			case ZPSConfigurationPackage.NODE_DESCRIPTOR__ALTERNATE_PAN_COORDINATOR:
			case ZPSConfigurationPackage.NODE_DESCRIPTOR__DEVICE_TYPE:
			case ZPSConfigurationPackage.NODE_DESCRIPTOR__POWER_SOURCE:
			case ZPSConfigurationPackage.NODE_DESCRIPTOR__SECURITY:
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
			case ZPSConfigurationPackage.NODE_DESCRIPTOR__RX_ON_WHEN_IDLE:
				return ;
	
		}
		super.eSet(featureID, newValue);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	@Override
	public void eUnset(int featureID) {
		switch (featureID) {
			case ZPSConfigurationPackage.NODE_DESCRIPTOR__MANUFACTURER_CODE:
				setManufacturerCode(MANUFACTURER_CODE_EDEFAULT);
				return;
			case ZPSConfigurationPackage.NODE_DESCRIPTOR__USER_DESCRIPTOR_AVAILABLE:
				setUserDescriptorAvailable(USER_DESCRIPTOR_AVAILABLE_EDEFAULT);
				return;
			case ZPSConfigurationPackage.NODE_DESCRIPTOR__ALLOCATE_ADDRESS:
				setAllocateAddress(ALLOCATE_ADDRESS_EDEFAULT);
				return;
			case ZPSConfigurationPackage.NODE_DESCRIPTOR__NODE:
				setNode((Node)null);
				return;
		}
		super.eUnset(featureID);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	@Override
	public boolean eIsSet(int featureID) {
		switch (featureID) {
			case ZPSConfigurationPackage.NODE_DESCRIPTOR__MANUFACTURER_CODE:
				return manufacturerCode != MANUFACTURER_CODE_EDEFAULT;
			case ZPSConfigurationPackage.NODE_DESCRIPTOR__LOGICAL_TYPE:
				return getLogicalType() != LOGICAL_TYPE_EDEFAULT;
			case ZPSConfigurationPackage.NODE_DESCRIPTOR__COMPLEX_DESCRIPTOR_AVAILABLE:
				return isComplexDescriptorAvailable() != COMPLEX_DESCRIPTOR_AVAILABLE_EDEFAULT;
			case ZPSConfigurationPackage.NODE_DESCRIPTOR__USER_DESCRIPTOR_AVAILABLE:
				return isUserDescriptorAvailable() != USER_DESCRIPTOR_AVAILABLE_EDEFAULT;
			case ZPSConfigurationPackage.NODE_DESCRIPTOR__APS_FLAGS:
				return APS_FLAGS_EDEFAULT == null ? getAPSFlags() != null : !APS_FLAGS_EDEFAULT.equals(getAPSFlags());
			case ZPSConfigurationPackage.NODE_DESCRIPTOR__FREQUENCY_BAND:
				return getFrequencyBand() != FREQUENCY_BAND_EDEFAULT;
			case ZPSConfigurationPackage.NODE_DESCRIPTOR__ALTERNATE_PAN_COORDINATOR:
				return isAlternatePANCoordinator() != ALTERNATE_PAN_COORDINATOR_EDEFAULT;
			case ZPSConfigurationPackage.NODE_DESCRIPTOR__DEVICE_TYPE:
				return isDeviceType() != DEVICE_TYPE_EDEFAULT;
			case ZPSConfigurationPackage.NODE_DESCRIPTOR__POWER_SOURCE:
				return isPowerSource() != POWER_SOURCE_EDEFAULT;
			case ZPSConfigurationPackage.NODE_DESCRIPTOR__RX_ON_WHEN_IDLE:
				return isRxOnWhenIdle() != RX_ON_WHEN_IDLE_EDEFAULT;
			case ZPSConfigurationPackage.NODE_DESCRIPTOR__SECURITY:
				return isSecurity() != SECURITY_EDEFAULT;
			case ZPSConfigurationPackage.NODE_DESCRIPTOR__ALLOCATE_ADDRESS:
				return allocateAddress != ALLOCATE_ADDRESS_EDEFAULT;
			case ZPSConfigurationPackage.NODE_DESCRIPTOR__MAXIMUM_BUFFER_SIZE:
				return MAXIMUM_BUFFER_SIZE_EDEFAULT == null ? maximumBufferSize != null : !MAXIMUM_BUFFER_SIZE_EDEFAULT.equals(maximumBufferSize);
			case ZPSConfigurationPackage.NODE_DESCRIPTOR__MAXIMUM_INCOMING_TRANSFER_SIZE:
				return getMaximumIncomingTransferSize() != MAXIMUM_INCOMING_TRANSFER_SIZE_EDEFAULT;
			case ZPSConfigurationPackage.NODE_DESCRIPTOR__MAXIMUM_OUTGOING_TRANSFER_SIZE:
				return getMaximumOutgoingTransferSize() != MAXIMUM_OUTGOING_TRANSFER_SIZE_EDEFAULT;
			case ZPSConfigurationPackage.NODE_DESCRIPTOR__EXTENDED_ACTIVE_ENDPOINT_LIST_AVAILABLE:
				return isExtendedActiveEndpointListAvailable() != EXTENDED_ACTIVE_ENDPOINT_LIST_AVAILABLE_EDEFAULT;
			case ZPSConfigurationPackage.NODE_DESCRIPTOR__EXTENDED_SIMPLE_DESCRIPTOR_LIST_AVAILABLE:
				return isExtendedSimpleDescriptorListAvailable() != EXTENDED_SIMPLE_DESCRIPTOR_LIST_AVAILABLE_EDEFAULT;
			case ZPSConfigurationPackage.NODE_DESCRIPTOR__PRIMARY_TRUST_CENTER:
				return isPrimaryTrustCenter() != PRIMARY_TRUST_CENTER_EDEFAULT;
			case ZPSConfigurationPackage.NODE_DESCRIPTOR__BACKUP_TRUST_CENTER:
				return isBackupTrustCenter() != BACKUP_TRUST_CENTER_EDEFAULT;
			case ZPSConfigurationPackage.NODE_DESCRIPTOR__PRIMARY_BINDING_TABLE_CACHE:
				return isPrimaryBindingTableCache() != PRIMARY_BINDING_TABLE_CACHE_EDEFAULT;
			case ZPSConfigurationPackage.NODE_DESCRIPTOR__BACKUP_BINDING_TABLE_CACHE:
				return isBackupBindingTableCache() != BACKUP_BINDING_TABLE_CACHE_EDEFAULT;
			case ZPSConfigurationPackage.NODE_DESCRIPTOR__PRIMARY_DISCOVERY_CACHE:
				return isPrimaryDiscoveryCache() != PRIMARY_DISCOVERY_CACHE_EDEFAULT;
			case ZPSConfigurationPackage.NODE_DESCRIPTOR__BACKUP_DISCOVERY_CACHE:
				return isBackupDiscoveryCache() != BACKUP_DISCOVERY_CACHE_EDEFAULT;
			case ZPSConfigurationPackage.NODE_DESCRIPTOR__NODE:
				return getNode() != null;
			case ZPSConfigurationPackage.NODE_DESCRIPTOR__NETWORK_MANAGER:
				return isNetworkManager() != NETWORK_MANAGER_EDEFAULT;
		}
		return super.eIsSet(featureID);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	@Override
	public String toString() {
		if (eIsProxy()) return super.toString();

		StringBuffer result = new StringBuffer(super.toString());
		result.append(" (ManufacturerCode: ");
		result.append(manufacturerCode);
		result.append(", AllocateAddress: ");
		result.append(allocateAddress);
		result.append(", MaximumBufferSize: ");
		result.append(maximumBufferSize);
		result.append(')');
		return result.toString();
	}

} //NodeDescriptorImpl
