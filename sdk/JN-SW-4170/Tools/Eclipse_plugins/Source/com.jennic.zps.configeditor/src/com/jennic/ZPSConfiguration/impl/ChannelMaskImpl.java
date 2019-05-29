/**
 * (C) Jennic Ltd
 *
 * $Id$
 */
package com.jennic.ZPSConfiguration.impl;


import org.eclipse.emf.common.notify.Notification;

import org.eclipse.emf.ecore.EClass;

import org.eclipse.emf.ecore.impl.ENotificationImpl;
import org.eclipse.emf.ecore.impl.EObjectImpl;

import com.jennic.ZPSConfiguration.ChannelMask;
import com.jennic.ZPSConfiguration.ZPSConfigurationPackage;

/**
 * <!-- begin-user-doc -->
 * An implementation of the model object '<em><b>Channel Mask</b></em>'.
 * <!-- end-user-doc -->
 * <p>
 * The following features are implemented:
 * <ul>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.ChannelMaskImpl#isChannel11 <em>Channel11</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.ChannelMaskImpl#isChannel12 <em>Channel12</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.ChannelMaskImpl#isChannel13 <em>Channel13</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.ChannelMaskImpl#isChannel14 <em>Channel14</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.ChannelMaskImpl#isChannel15 <em>Channel15</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.ChannelMaskImpl#isChannel16 <em>Channel16</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.ChannelMaskImpl#isChannel17 <em>Channel17</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.ChannelMaskImpl#isChannel18 <em>Channel18</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.ChannelMaskImpl#isChannel19 <em>Channel19</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.ChannelMaskImpl#isChannel20 <em>Channel20</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.ChannelMaskImpl#isChannel21 <em>Channel21</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.ChannelMaskImpl#isChannel22 <em>Channel22</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.ChannelMaskImpl#isChannel23 <em>Channel23</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.ChannelMaskImpl#isChannel24 <em>Channel24</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.ChannelMaskImpl#isChannel25 <em>Channel25</em>}</li>
 *   <li>{@link com.jennic.ZPSConfiguration.impl.ChannelMaskImpl#isChannel26 <em>Channel26</em>}</li>
 * </ul>
 * </p>
 *
 * @generated
 */
public class ChannelMaskImpl extends EObjectImpl implements ChannelMask {
	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public static final String copyright = "(C) NXP B.V";

	/**
	 * The default value of the '{@link #isChannel11() <em>Channel11</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #isChannel11()
	 * @generated
	 * @ordered
	 */
	protected static final boolean CHANNEL11_EDEFAULT = true;

	/**
	 * The cached value of the '{@link #isChannel11() <em>Channel11</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #isChannel11()
	 * @generated
	 * @ordered
	 */
	protected boolean channel11 = CHANNEL11_EDEFAULT;

	/**
	 * The default value of the '{@link #isChannel12() <em>Channel12</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #isChannel12()
	 * @generated
	 * @ordered
	 */
	protected static final boolean CHANNEL12_EDEFAULT = true;

	/**
	 * The cached value of the '{@link #isChannel12() <em>Channel12</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #isChannel12()
	 * @generated
	 * @ordered
	 */
	protected boolean channel12 = CHANNEL12_EDEFAULT;

	/**
	 * The default value of the '{@link #isChannel13() <em>Channel13</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #isChannel13()
	 * @generated
	 * @ordered
	 */
	protected static final boolean CHANNEL13_EDEFAULT = true;

	/**
	 * The cached value of the '{@link #isChannel13() <em>Channel13</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #isChannel13()
	 * @generated
	 * @ordered
	 */
	protected boolean channel13 = CHANNEL13_EDEFAULT;

	/**
	 * The default value of the '{@link #isChannel14() <em>Channel14</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #isChannel14()
	 * @generated
	 * @ordered
	 */
	protected static final boolean CHANNEL14_EDEFAULT = true;

	/**
	 * The cached value of the '{@link #isChannel14() <em>Channel14</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #isChannel14()
	 * @generated
	 * @ordered
	 */
	protected boolean channel14 = CHANNEL14_EDEFAULT;

	/**
	 * The default value of the '{@link #isChannel15() <em>Channel15</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #isChannel15()
	 * @generated
	 * @ordered
	 */
	protected static final boolean CHANNEL15_EDEFAULT = true;

	/**
	 * The cached value of the '{@link #isChannel15() <em>Channel15</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #isChannel15()
	 * @generated
	 * @ordered
	 */
	protected boolean channel15 = CHANNEL15_EDEFAULT;

	/**
	 * The default value of the '{@link #isChannel16() <em>Channel16</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #isChannel16()
	 * @generated
	 * @ordered
	 */
	protected static final boolean CHANNEL16_EDEFAULT = true;

	/**
	 * The cached value of the '{@link #isChannel16() <em>Channel16</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #isChannel16()
	 * @generated
	 * @ordered
	 */
	protected boolean channel16 = CHANNEL16_EDEFAULT;

	/**
	 * The default value of the '{@link #isChannel17() <em>Channel17</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #isChannel17()
	 * @generated
	 * @ordered
	 */
	protected static final boolean CHANNEL17_EDEFAULT = true;

	/**
	 * The cached value of the '{@link #isChannel17() <em>Channel17</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #isChannel17()
	 * @generated
	 * @ordered
	 */
	protected boolean channel17 = CHANNEL17_EDEFAULT;

	/**
	 * The default value of the '{@link #isChannel18() <em>Channel18</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #isChannel18()
	 * @generated
	 * @ordered
	 */
	protected static final boolean CHANNEL18_EDEFAULT = true;

	/**
	 * The cached value of the '{@link #isChannel18() <em>Channel18</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #isChannel18()
	 * @generated
	 * @ordered
	 */
	protected boolean channel18 = CHANNEL18_EDEFAULT;

	/**
	 * The default value of the '{@link #isChannel19() <em>Channel19</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #isChannel19()
	 * @generated
	 * @ordered
	 */
	protected static final boolean CHANNEL19_EDEFAULT = true;

	/**
	 * The cached value of the '{@link #isChannel19() <em>Channel19</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #isChannel19()
	 * @generated
	 * @ordered
	 */
	protected boolean channel19 = CHANNEL19_EDEFAULT;

	/**
	 * The default value of the '{@link #isChannel20() <em>Channel20</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #isChannel20()
	 * @generated
	 * @ordered
	 */
	protected static final boolean CHANNEL20_EDEFAULT = true;

	/**
	 * The cached value of the '{@link #isChannel20() <em>Channel20</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #isChannel20()
	 * @generated
	 * @ordered
	 */
	protected boolean channel20 = CHANNEL20_EDEFAULT;

	/**
	 * The default value of the '{@link #isChannel21() <em>Channel21</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #isChannel21()
	 * @generated
	 * @ordered
	 */
	protected static final boolean CHANNEL21_EDEFAULT = true;

	/**
	 * The cached value of the '{@link #isChannel21() <em>Channel21</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #isChannel21()
	 * @generated
	 * @ordered
	 */
	protected boolean channel21 = CHANNEL21_EDEFAULT;

	/**
	 * The default value of the '{@link #isChannel22() <em>Channel22</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #isChannel22()
	 * @generated
	 * @ordered
	 */
	protected static final boolean CHANNEL22_EDEFAULT = true;

	/**
	 * The cached value of the '{@link #isChannel22() <em>Channel22</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #isChannel22()
	 * @generated
	 * @ordered
	 */
	protected boolean channel22 = CHANNEL22_EDEFAULT;

	/**
	 * The default value of the '{@link #isChannel23() <em>Channel23</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #isChannel23()
	 * @generated
	 * @ordered
	 */
	protected static final boolean CHANNEL23_EDEFAULT = true;

	/**
	 * The cached value of the '{@link #isChannel23() <em>Channel23</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #isChannel23()
	 * @generated
	 * @ordered
	 */
	protected boolean channel23 = CHANNEL23_EDEFAULT;

	/**
	 * The default value of the '{@link #isChannel24() <em>Channel24</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #isChannel24()
	 * @generated
	 * @ordered
	 */
	protected static final boolean CHANNEL24_EDEFAULT = true;

	/**
	 * The cached value of the '{@link #isChannel24() <em>Channel24</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #isChannel24()
	 * @generated
	 * @ordered
	 */
	protected boolean channel24 = CHANNEL24_EDEFAULT;

	/**
	 * The default value of the '{@link #isChannel25() <em>Channel25</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #isChannel25()
	 * @generated
	 * @ordered
	 */
	protected static final boolean CHANNEL25_EDEFAULT = true;

	/**
	 * The cached value of the '{@link #isChannel25() <em>Channel25</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #isChannel25()
	 * @generated
	 * @ordered
	 */
	protected boolean channel25 = CHANNEL25_EDEFAULT;

	/**
	 * The default value of the '{@link #isChannel26() <em>Channel26</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #isChannel26()
	 * @generated
	 * @ordered
	 */
	protected static final boolean CHANNEL26_EDEFAULT = true;

	/**
	 * The cached value of the '{@link #isChannel26() <em>Channel26</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #isChannel26()
	 * @generated
	 * @ordered
	 */
	protected boolean channel26 = CHANNEL26_EDEFAULT;

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	protected ChannelMaskImpl() {
		super();
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	@Override
	protected EClass eStaticClass() {
		return ZPSConfigurationPackage.Literals.CHANNEL_MASK;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public boolean isChannel11() {
		return channel11;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void setChannel11(boolean newChannel11) {
		boolean oldChannel11 = channel11;
		channel11 = newChannel11;
		if (eNotificationRequired())
			eNotify(new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.CHANNEL_MASK__CHANNEL11, oldChannel11, channel11));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public boolean isChannel12() {
		return channel12;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void setChannel12(boolean newChannel12) {
		boolean oldChannel12 = channel12;
		channel12 = newChannel12;
		if (eNotificationRequired())
			eNotify(new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.CHANNEL_MASK__CHANNEL12, oldChannel12, channel12));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public boolean isChannel13() {
		return channel13;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void setChannel13(boolean newChannel13) {
		boolean oldChannel13 = channel13;
		channel13 = newChannel13;
		if (eNotificationRequired())
			eNotify(new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.CHANNEL_MASK__CHANNEL13, oldChannel13, channel13));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public boolean isChannel14() {
		return channel14;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void setChannel14(boolean newChannel14) {
		boolean oldChannel14 = channel14;
		channel14 = newChannel14;
		if (eNotificationRequired())
			eNotify(new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.CHANNEL_MASK__CHANNEL14, oldChannel14, channel14));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public boolean isChannel15() {
		return channel15;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void setChannel15(boolean newChannel15) {
		boolean oldChannel15 = channel15;
		channel15 = newChannel15;
		if (eNotificationRequired())
			eNotify(new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.CHANNEL_MASK__CHANNEL15, oldChannel15, channel15));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public boolean isChannel16() {
		return channel16;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void setChannel16(boolean newChannel16) {
		boolean oldChannel16 = channel16;
		channel16 = newChannel16;
		if (eNotificationRequired())
			eNotify(new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.CHANNEL_MASK__CHANNEL16, oldChannel16, channel16));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public boolean isChannel17() {
		return channel17;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void setChannel17(boolean newChannel17) {
		boolean oldChannel17 = channel17;
		channel17 = newChannel17;
		if (eNotificationRequired())
			eNotify(new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.CHANNEL_MASK__CHANNEL17, oldChannel17, channel17));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public boolean isChannel18() {
		return channel18;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void setChannel18(boolean newChannel18) {
		boolean oldChannel18 = channel18;
		channel18 = newChannel18;
		if (eNotificationRequired())
			eNotify(new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.CHANNEL_MASK__CHANNEL18, oldChannel18, channel18));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public boolean isChannel19() {
		return channel19;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void setChannel19(boolean newChannel19) {
		boolean oldChannel19 = channel19;
		channel19 = newChannel19;
		if (eNotificationRequired())
			eNotify(new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.CHANNEL_MASK__CHANNEL19, oldChannel19, channel19));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public boolean isChannel20() {
		return channel20;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void setChannel20(boolean newChannel20) {
		boolean oldChannel20 = channel20;
		channel20 = newChannel20;
		if (eNotificationRequired())
			eNotify(new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.CHANNEL_MASK__CHANNEL20, oldChannel20, channel20));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public boolean isChannel21() {
		return channel21;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void setChannel21(boolean newChannel21) {
		boolean oldChannel21 = channel21;
		channel21 = newChannel21;
		if (eNotificationRequired())
			eNotify(new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.CHANNEL_MASK__CHANNEL21, oldChannel21, channel21));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public boolean isChannel22() {
		return channel22;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void setChannel22(boolean newChannel22) {
		boolean oldChannel22 = channel22;
		channel22 = newChannel22;
		if (eNotificationRequired())
			eNotify(new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.CHANNEL_MASK__CHANNEL22, oldChannel22, channel22));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public boolean isChannel23() {
		return channel23;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void setChannel23(boolean newChannel23) {
		boolean oldChannel23 = channel23;
		channel23 = newChannel23;
		if (eNotificationRequired())
			eNotify(new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.CHANNEL_MASK__CHANNEL23, oldChannel23, channel23));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public boolean isChannel24() {
		return channel24;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void setChannel24(boolean newChannel24) {
		boolean oldChannel24 = channel24;
		channel24 = newChannel24;
		if (eNotificationRequired())
			eNotify(new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.CHANNEL_MASK__CHANNEL24, oldChannel24, channel24));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public boolean isChannel25() {
		return channel25;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void setChannel25(boolean newChannel25) {
		boolean oldChannel25 = channel25;
		channel25 = newChannel25;
		if (eNotificationRequired())
			eNotify(new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.CHANNEL_MASK__CHANNEL25, oldChannel25, channel25));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public boolean isChannel26() {
		return channel26;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void setChannel26(boolean newChannel26) {
		boolean oldChannel26 = channel26;
		channel26 = newChannel26;
		if (eNotificationRequired())
			eNotify(new ENotificationImpl(this, Notification.SET, ZPSConfigurationPackage.CHANNEL_MASK__CHANNEL26, oldChannel26, channel26));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	@Override
	public Object eGet(int featureID, boolean resolve, boolean coreType) {
		switch (featureID) {
			case ZPSConfigurationPackage.CHANNEL_MASK__CHANNEL11:
				return isChannel11();
			case ZPSConfigurationPackage.CHANNEL_MASK__CHANNEL12:
				return isChannel12();
			case ZPSConfigurationPackage.CHANNEL_MASK__CHANNEL13:
				return isChannel13();
			case ZPSConfigurationPackage.CHANNEL_MASK__CHANNEL14:
				return isChannel14();
			case ZPSConfigurationPackage.CHANNEL_MASK__CHANNEL15:
				return isChannel15();
			case ZPSConfigurationPackage.CHANNEL_MASK__CHANNEL16:
				return isChannel16();
			case ZPSConfigurationPackage.CHANNEL_MASK__CHANNEL17:
				return isChannel17();
			case ZPSConfigurationPackage.CHANNEL_MASK__CHANNEL18:
				return isChannel18();
			case ZPSConfigurationPackage.CHANNEL_MASK__CHANNEL19:
				return isChannel19();
			case ZPSConfigurationPackage.CHANNEL_MASK__CHANNEL20:
				return isChannel20();
			case ZPSConfigurationPackage.CHANNEL_MASK__CHANNEL21:
				return isChannel21();
			case ZPSConfigurationPackage.CHANNEL_MASK__CHANNEL22:
				return isChannel22();
			case ZPSConfigurationPackage.CHANNEL_MASK__CHANNEL23:
				return isChannel23();
			case ZPSConfigurationPackage.CHANNEL_MASK__CHANNEL24:
				return isChannel24();
			case ZPSConfigurationPackage.CHANNEL_MASK__CHANNEL25:
				return isChannel25();
			case ZPSConfigurationPackage.CHANNEL_MASK__CHANNEL26:
				return isChannel26();
		}
		return super.eGet(featureID, resolve, coreType);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	@Override
	public void eSet(int featureID, Object newValue) {
		switch (featureID) {
			case ZPSConfigurationPackage.CHANNEL_MASK__CHANNEL11:
				setChannel11((Boolean)newValue);
				return;
			case ZPSConfigurationPackage.CHANNEL_MASK__CHANNEL12:
				setChannel12((Boolean)newValue);
				return;
			case ZPSConfigurationPackage.CHANNEL_MASK__CHANNEL13:
				setChannel13((Boolean)newValue);
				return;
			case ZPSConfigurationPackage.CHANNEL_MASK__CHANNEL14:
				setChannel14((Boolean)newValue);
				return;
			case ZPSConfigurationPackage.CHANNEL_MASK__CHANNEL15:
				setChannel15((Boolean)newValue);
				return;
			case ZPSConfigurationPackage.CHANNEL_MASK__CHANNEL16:
				setChannel16((Boolean)newValue);
				return;
			case ZPSConfigurationPackage.CHANNEL_MASK__CHANNEL17:
				setChannel17((Boolean)newValue);
				return;
			case ZPSConfigurationPackage.CHANNEL_MASK__CHANNEL18:
				setChannel18((Boolean)newValue);
				return;
			case ZPSConfigurationPackage.CHANNEL_MASK__CHANNEL19:
				setChannel19((Boolean)newValue);
				return;
			case ZPSConfigurationPackage.CHANNEL_MASK__CHANNEL20:
				setChannel20((Boolean)newValue);
				return;
			case ZPSConfigurationPackage.CHANNEL_MASK__CHANNEL21:
				setChannel21((Boolean)newValue);
				return;
			case ZPSConfigurationPackage.CHANNEL_MASK__CHANNEL22:
				setChannel22((Boolean)newValue);
				return;
			case ZPSConfigurationPackage.CHANNEL_MASK__CHANNEL23:
				setChannel23((Boolean)newValue);
				return;
			case ZPSConfigurationPackage.CHANNEL_MASK__CHANNEL24:
				setChannel24((Boolean)newValue);
				return;
			case ZPSConfigurationPackage.CHANNEL_MASK__CHANNEL25:
				setChannel25((Boolean)newValue);
				return;
			case ZPSConfigurationPackage.CHANNEL_MASK__CHANNEL26:
				setChannel26((Boolean)newValue);
				return;
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
			case ZPSConfigurationPackage.CHANNEL_MASK__CHANNEL11:
				setChannel11(CHANNEL11_EDEFAULT);
				return;
			case ZPSConfigurationPackage.CHANNEL_MASK__CHANNEL12:
				setChannel12(CHANNEL12_EDEFAULT);
				return;
			case ZPSConfigurationPackage.CHANNEL_MASK__CHANNEL13:
				setChannel13(CHANNEL13_EDEFAULT);
				return;
			case ZPSConfigurationPackage.CHANNEL_MASK__CHANNEL14:
				setChannel14(CHANNEL14_EDEFAULT);
				return;
			case ZPSConfigurationPackage.CHANNEL_MASK__CHANNEL15:
				setChannel15(CHANNEL15_EDEFAULT);
				return;
			case ZPSConfigurationPackage.CHANNEL_MASK__CHANNEL16:
				setChannel16(CHANNEL16_EDEFAULT);
				return;
			case ZPSConfigurationPackage.CHANNEL_MASK__CHANNEL17:
				setChannel17(CHANNEL17_EDEFAULT);
				return;
			case ZPSConfigurationPackage.CHANNEL_MASK__CHANNEL18:
				setChannel18(CHANNEL18_EDEFAULT);
				return;
			case ZPSConfigurationPackage.CHANNEL_MASK__CHANNEL19:
				setChannel19(CHANNEL19_EDEFAULT);
				return;
			case ZPSConfigurationPackage.CHANNEL_MASK__CHANNEL20:
				setChannel20(CHANNEL20_EDEFAULT);
				return;
			case ZPSConfigurationPackage.CHANNEL_MASK__CHANNEL21:
				setChannel21(CHANNEL21_EDEFAULT);
				return;
			case ZPSConfigurationPackage.CHANNEL_MASK__CHANNEL22:
				setChannel22(CHANNEL22_EDEFAULT);
				return;
			case ZPSConfigurationPackage.CHANNEL_MASK__CHANNEL23:
				setChannel23(CHANNEL23_EDEFAULT);
				return;
			case ZPSConfigurationPackage.CHANNEL_MASK__CHANNEL24:
				setChannel24(CHANNEL24_EDEFAULT);
				return;
			case ZPSConfigurationPackage.CHANNEL_MASK__CHANNEL25:
				setChannel25(CHANNEL25_EDEFAULT);
				return;
			case ZPSConfigurationPackage.CHANNEL_MASK__CHANNEL26:
				setChannel26(CHANNEL26_EDEFAULT);
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
			case ZPSConfigurationPackage.CHANNEL_MASK__CHANNEL11:
				return channel11 != CHANNEL11_EDEFAULT;
			case ZPSConfigurationPackage.CHANNEL_MASK__CHANNEL12:
				return channel12 != CHANNEL12_EDEFAULT;
			case ZPSConfigurationPackage.CHANNEL_MASK__CHANNEL13:
				return channel13 != CHANNEL13_EDEFAULT;
			case ZPSConfigurationPackage.CHANNEL_MASK__CHANNEL14:
				return channel14 != CHANNEL14_EDEFAULT;
			case ZPSConfigurationPackage.CHANNEL_MASK__CHANNEL15:
				return channel15 != CHANNEL15_EDEFAULT;
			case ZPSConfigurationPackage.CHANNEL_MASK__CHANNEL16:
				return channel16 != CHANNEL16_EDEFAULT;
			case ZPSConfigurationPackage.CHANNEL_MASK__CHANNEL17:
				return channel17 != CHANNEL17_EDEFAULT;
			case ZPSConfigurationPackage.CHANNEL_MASK__CHANNEL18:
				return channel18 != CHANNEL18_EDEFAULT;
			case ZPSConfigurationPackage.CHANNEL_MASK__CHANNEL19:
				return channel19 != CHANNEL19_EDEFAULT;
			case ZPSConfigurationPackage.CHANNEL_MASK__CHANNEL20:
				return channel20 != CHANNEL20_EDEFAULT;
			case ZPSConfigurationPackage.CHANNEL_MASK__CHANNEL21:
				return channel21 != CHANNEL21_EDEFAULT;
			case ZPSConfigurationPackage.CHANNEL_MASK__CHANNEL22:
				return channel22 != CHANNEL22_EDEFAULT;
			case ZPSConfigurationPackage.CHANNEL_MASK__CHANNEL23:
				return channel23 != CHANNEL23_EDEFAULT;
			case ZPSConfigurationPackage.CHANNEL_MASK__CHANNEL24:
				return channel24 != CHANNEL24_EDEFAULT;
			case ZPSConfigurationPackage.CHANNEL_MASK__CHANNEL25:
				return channel25 != CHANNEL25_EDEFAULT;
			case ZPSConfigurationPackage.CHANNEL_MASK__CHANNEL26:
				return channel26 != CHANNEL26_EDEFAULT;
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
		result.append(" (Channel11: ");
		result.append(channel11);
		result.append(", Channel12: ");
		result.append(channel12);
		result.append(", Channel13: ");
		result.append(channel13);
		result.append(", Channel14: ");
		result.append(channel14);
		result.append(", Channel15: ");
		result.append(channel15);
		result.append(", Channel16: ");
		result.append(channel16);
		result.append(", Channel17: ");
		result.append(channel17);
		result.append(", Channel18: ");
		result.append(channel18);
		result.append(", Channel19: ");
		result.append(channel19);
		result.append(", Channel20: ");
		result.append(channel20);
		result.append(", Channel21: ");
		result.append(channel21);
		result.append(", Channel22: ");
		result.append(channel22);
		result.append(", Channel23: ");
		result.append(channel23);
		result.append(", Channel24: ");
		result.append(channel24);
		result.append(", Channel25: ");
		result.append(channel25);
		result.append(", Channel26: ");
		result.append(channel26);
		result.append(')');
		return result.toString();
	}

} //ChannelMaskImpl
