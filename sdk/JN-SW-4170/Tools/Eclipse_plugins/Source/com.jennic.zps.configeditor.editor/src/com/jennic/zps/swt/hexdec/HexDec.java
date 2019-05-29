package com.jennic.zps.swt.hexdec;

import java.math.BigInteger;

/**
 * The <code>HexDec</code> class provides decimal and hex representations
 * of numerical values expressed as Strings.
 * 
 * @author sc
 *
 */
public class HexDec {
	public static final int RANGE_ARBITRARY = 0 ;
	public static final int RANGE_BYTE = 1 ;
	public static final int RANGE_SHORT = 2 ;
	public static final int RANGE_INT = 4 ;
	public static final int RANGE_LONG = 8 ;
	
	private String hexString ;
	private String decString ;
	private int range ;
	private boolean signed ;
	
	private BigInteger minLimit = null ;
	private BigInteger maxLimit = null ;
	private int hexWidth = 0;
	
	
	/**
	 * Create with default values of range:0, signed:false
	 */
	public HexDec() {
		this(0,false) ;
	}
	
	/**
	 * Specify a valid range in byes and whether to accept signed values
	 * @param range - 0=arbitrary otherwise the number of bytes in the target datatype,
	 * eg int=4
	 * @param signed - true if we are to accept signed values, otherwise false
	 */
	public HexDec(int range, boolean signed) {
		hexString = "0x00" ;
		decString = "0" ;
		setRange(range) ;
		setSigned(signed) ;
	}
	
	private void checkLimits(BigInteger b) throws NumberFormatException {
		if(b != null) {
			if(minLimit != null) {
				if(b.compareTo(minLimit) < 0) {
					throw new NumberFormatException("Value less than minimum limit") ;
				}
			}
			if(maxLimit != null) {
				if(b.compareTo(maxLimit) > 0) {
					throw new NumberFormatException("Value greater than maximum limit") ;
				}
			}
		}
	}
	
	
	private boolean isHex(String s) {
		if(s.indexOf("0x") >= 0 || s.indexOf("0X") >= 0) {
			return true ;
		} else {
			return false ;
		}
	}
	
	private boolean isNegative(String s) {
		if(s.indexOf("-") >= 0) {
			return true ;
		} else {
			return false ;
		}
	}
	
	private BigInteger createInteger(String val) throws NumberFormatException {
		if(isHex(val)) {
			// we know its positive cos we're not allowing negative hex entry
			return new BigInteger(val.substring(2),16) ;
		} else {
			return new BigInteger(val) ;			
		}		
	}
	
	private void parseSignedString(String val) throws NumberFormatException {
		
		if (val.equals("-")) {
			val += "0";
		}
		BigInteger b = createInteger(val) ;

		String newHexValue = null ;
		String newDecValue = null ;
		
		switch(range) {
		case RANGE_BYTE:
			BigInteger maxByte = new BigInteger(String.valueOf(Byte.MAX_VALUE)) ;
			BigInteger minByte = new BigInteger(String.valueOf(Byte.MIN_VALUE)) ;
			if(b.compareTo(maxByte) > 0 || b.compareTo(minByte) < 0) {
				throw new NumberFormatException("Value out of range") ;
			}
			int bVal = b.intValue() ;
			newDecValue = Integer.toString(bVal) ;
			newHexValue = Integer.toHexString(bVal) ;
			if(isNegative(val)) {
				// lop off the extraneous FF's
				newHexValue = newHexValue.substring(6) ;
			}
			break ;
		case RANGE_SHORT:
			BigInteger maxShort = new BigInteger(String.valueOf(Short.MAX_VALUE)) ;
			BigInteger minShort = new BigInteger(String.valueOf(Short.MIN_VALUE)) ;
			if(b.compareTo(maxShort) > 0 || b.compareTo(minShort) < 0) {
				throw new NumberFormatException("Value out of range") ;
			}
			int sVal = b.intValue() ;
			newDecValue = Integer.toString(sVal) ;
			newHexValue = Integer.toHexString(sVal) ;
			if(isNegative(val)) {
				// lop off the extraneous FF's
				newHexValue = newHexValue.substring(4) ;
			}
			break ;
		case RANGE_INT:
			BigInteger maxInt = new BigInteger(String.valueOf(Integer.MAX_VALUE)) ;
			BigInteger minInt = new BigInteger(String.valueOf(Integer.MIN_VALUE)) ;
			if(b.compareTo(maxInt) > 0 || b.compareTo(minInt) < 0) {
				throw new NumberFormatException("Value out of range") ;
			}
			int iVal = b.intValue() ;
			newDecValue = Integer.toString(iVal) ;
			newHexValue = Integer.toHexString(iVal) ;
			break ;
		case RANGE_LONG:
			BigInteger maxLong = new BigInteger(String.valueOf(Long.MAX_VALUE)) ;
			BigInteger minLong = new BigInteger(String.valueOf(Long.MIN_VALUE)) ;
			if(b.compareTo(maxLong) > 0 || b.compareTo(minLong) < 0) {
				throw new NumberFormatException("Value out of range") ;
			}
			int lVal = b.intValue() ;
			newDecValue = Long.toString(lVal) ;
			newHexValue = Long.toHexString(lVal) ;
			break ;
		case RANGE_ARBITRARY:
		default:
			newHexValue = b.toString(16) ;
			newDecValue = b.toString() ;
			break ;
		}
		
		checkLimits(b) ;
		
		hexString = newHexValue ;
		decString = newDecValue ;
		
	}
	
	
	
	private void parseUnsignedString(String val) throws NumberFormatException {
		BigInteger b = createInteger(val) ;

		String newHexValue = b.toString(16) ;
		String newDecValue = b.toString() ;

		
		if((range > 0) && (newHexValue.length() > (range * 2))) {
			throw new NumberFormatException("Value out of range") ;
		}

		checkLimits(b) ;
		
		hexString = newHexValue ;
		decString = newDecValue ;
	}

	
	/**
	 * Set the component to the desired value. Values are represented
	 * as strings in either decimal or hexadecimal format. Signed hexadecimal
	 * numbers are not allowed.
	 * 
	 * The value is checked against the current sign, range and limits settings
	 * and a NumberFormatException thrown if it is not compatible with any
	 * of these tests.
	 * 
	 * @param val - the string value of a number
	 * @throws NumberFormatException
	 */
	public void parseString(String val) throws NumberFormatException {
		// Dont bother trying if we haven't got a value
		if(val == null) return ;
		if(val.length() == 0) return ;
		
		// Check we're not in unsigned mode and val is negative
		if(signed == false && isNegative(val)) {
			throw new NumberFormatException("Signed values are not allowed") ;
		}
		
		// We're not going to allow negative hex numbers as input
		if(isHex(val) && isNegative(val)) {
			throw new NumberFormatException("Negative hex entry is not allowed") ;
		}
		
		if(signed) {
			parseSignedString(val) ;
		} else {
			parseUnsignedString(val) ;			
		}

	}
	
	
	
	/**
	 * Return the current value as a decimal string
	 * @return - the value
	 */
	@Override
	public String toString() {
		return decString ;
	}
	
	/**
	 * Return the current value as a hex string
	 * @return - the value
	 */
	public String toHex() {
		String hexStr = hexString.toUpperCase();

		/* pad hex string with leading 0s as required */
		while (hexStr.length() < hexWidth) {
			hexStr = "0" + hexStr;
		}
		
		return "0x" + hexStr;
	}
	
	/**
	 * Return the current value as a decimal string
	 * @return - the value
	 */
	public String toDecimal() {
		return decString ;
	}

	/**
	 * Get the primitive type that numbers will be representing.
	 * This can be one of
	 * 	RANGE_ARBITRARY
	 * 	RANGE_BYTE
	 * 	RANGE_SHORT
	 * 	RANGE_INT
	 * 	RANGE_LONG
	 * 
	 * @return - the range
	 */
	public int getRange() {
		return range;
	}

	/**
	 * Set the primitive type that numbers will be representing.
	 * This can be one of
	 * 	RANGE_ARBITRARY
	 * 	RANGE_BYTE
	 * 	RANGE_SHORT
	 * 	RANGE_INT
	 * 	RANGE_LONG
	 * 
	 * Attempting to set a value that cannot be represented by the chosen type
	 * will result in a NumberFormatException.
	 * 
	 * The default value is RANGE_ARBITRARY
	 * 
	 * @param range - the desired range
	 */
	public void setRange(int range) {
		this.range = range;
	}

	/**
	 * Return whether or not signed values are allowed
	 * 
	 * @return true if signed values allowed, otherwise false
	 */
	public boolean isSigned() {
		return signed;
	}

	/**
	 * Set whether or not to accept signed values.
	 * The default value is false
	 * @param signed
	 */
	public void setSigned(boolean signed) {
		this.signed = signed;
	}
	
	
	/**
	 * Set the minimum and maximum values that are allowed. Positive values may
	 * be entered in decimal or hex, negatives must be entered in decimal.
	 * If there is no upper or lower limit than this can be set by passing
	 * null as the limit value.
	 * If any of the values cannot be parsed then no error is thrown and the
	 * relevant limit is set to null.
	 * 
	 * @param min - the minimum value
	 * @param max - the maximum value
	 */
	public void setLimits(String min, String max) {
		BigInteger newMin = null ;
		BigInteger newMax = null ;
		
		if(min != null) {
			try {
				newMin = createInteger(min) ;
			} catch (NumberFormatException e) {
				newMin = null ;
			}
		}
		if(max != null) {
			try {
				newMax = createInteger(max) ;
			} catch (NumberFormatException e) {
				newMax = null ;
			}
		}
		
		minLimit = newMin ;
		maxLimit = newMax ;		
	}

	public void setHexWidth(int width) {
		this.hexWidth = width;
	}

}
