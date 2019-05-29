package com.jennic.zps.swt.hexdec;

import java.math.BigInteger;

import org.eclipse.swt.SWT;
import org.eclipse.swt.events.KeyEvent;
import org.eclipse.swt.events.KeyListener;
import org.eclipse.swt.graphics.Point;
import org.eclipse.swt.graphics.Rectangle;
import org.eclipse.swt.layout.GridData;
import org.eclipse.swt.widgets.Composite;
import org.eclipse.swt.widgets.Display;
import org.eclipse.swt.widgets.Label;
import org.eclipse.swt.widgets.Layout;
import org.eclipse.swt.widgets.Text;

public class HexDecComponent extends Composite implements KeyListener {
	Text textField ;
	Label labelField ;
	HexDec hexdec = new HexDec() ;
	Object source ;
	HexDecCellEditor cellEditor ;
	Boolean bHex;

	private class HexDecCellLayout extends Layout {
		@Override
		public void layout(Composite editor, boolean force) {
			Rectangle bounds = editor.getClientArea();
			int halfWidth = bounds.width / 2 ;
			textField.setBounds(0,0,halfWidth,bounds.height) ;
			labelField.setBounds(halfWidth,0,halfWidth,bounds.height) ;
		}

		@Override
		public Point computeSize(Composite editor, int wHint, int hHint,
				boolean force) {
			if (wHint != SWT.DEFAULT && hHint != SWT.DEFAULT) {
				return new Point(wHint, hHint);
			}
			Point textFieldSize = textField.computeSize(SWT.DEFAULT, SWT.DEFAULT,
					force);
			Point labelFieldSize = labelField.computeSize(SWT.DEFAULT, SWT.DEFAULT,
					force);

			Point result = new Point(Math.min(textFieldSize.x,labelFieldSize.x)*2, Math.max(textFieldSize.y,labelFieldSize.y));
			return result;
		}
	}	



	HexDecComponent(Composite parent, int style) {
		super(parent, style);

		bHex = false;
		
		this.setLayout(new HexDecCellLayout());

		textField = new Text(this,SWT.NONE) ;
		textField.setTextLimit(34);
		labelField = new Label(this,SWT.NONE) ;

		textField.addKeyListener(this) ;
		textField.setLayoutData(new GridData(GridData.HORIZONTAL_ALIGN_FILL));
		labelField.setText("0X...") ;
		labelField.setLayoutData(new GridData(GridData.HORIZONTAL_ALIGN_FILL));
		

		setValueObject(source) ;
		
	}

	public void setFormatToHex() {
		bHex = true;
	}

	public void setHexWidth(int width) {
		hexdec.setHexWidth(width);
		textField.setTextLimit(width + 2);
	}

	public void doSetFocus() {
		textField.setFocus();
		/* place caret at end of text when gainaing the focus */
		//textField.setSelection(0, textField.getText().length());
		textField.selectAll();
	}
	
	/**
	 * Set the primitive type that numbers will be representing.
	 * Range can be one of
	 * 	RANGE_ARBITRARY
	 * 	RANGE_BYTE
	 * 	RANGE_SHORT
	 * 	RANGE_INT
	 * 	RANGE_LONG
	 * 
	 * @param range - the desired range
	 * @param signed = whether or not to accept signed values
	 */
	public void setRange(int range, boolean signed) {
		hexdec.setRange(range) ;
		hexdec.setSigned(signed) ;
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
	public void setLimits(String minLimit, String maxLimit) {
		hexdec.setLimits(minLimit, maxLimit) ;
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
	public void setValue(String value) throws NumberFormatException {
		hexdec.parseString(value) ;
	}

	public void setValueObject(Object value) throws NumberFormatException {
		if(value == null) {
			return ;
		}
		hexdec.parseString(value.toString()) ;
		source = value ;
		if (source instanceof BigInteger) {
			setRange(HexDec.RANGE_ARBITRARY,true) ;
		} else if (source instanceof Long) {
			setRange(HexDec.RANGE_LONG,true) ;
		} else if (source instanceof Integer) {
			setRange(HexDec.RANGE_INT,true) ;
		} else if (source instanceof Short) {
			setRange(HexDec.RANGE_SHORT,true) ;
		} else if (source instanceof Byte) {			
			setRange(HexDec.RANGE_BYTE,true) ;
		} else {
			setRange(HexDec.RANGE_ARBITRARY,true) ;
		}

		if (bHex) {
			textField.setText(hexdec.toHex());			
			labelField.setText(hexdec.toDecimal()) ;
		} else {
			textField.setText(hexdec.toDecimal());						
			labelField.setText(hexdec.toHex()) ;
		}
		
	}

	public Object getValue() {
		
		String valueStr;
		
//		if (bHex) {
//			valueStr = hexdec.toHex();
//		} else {
			valueStr = hexdec.toDecimal();			
//		}
		
		if(source == null) {
			return "" ;
		} else if (source instanceof BigInteger) {
			return new BigInteger(valueStr) ;
		} else if (source instanceof Long) {
			return Long.parseLong(valueStr) ;
		} else if (source instanceof Integer) {
			return Integer.parseInt(valueStr) ;
		} else if (source instanceof Short) {
			return Short.parseShort(valueStr) ;
		} else if (source instanceof Byte) {			
			return Byte.parseByte(valueStr) ;
		} else {
			return hexdec.toString() ;
		}

	}

	public String getValueStr() {
		
		return textField.getText();			
	}

	// ---------------------------------------------------------------------------

	@Override
	public void dispose() {
		super.dispose();
		textField.dispose() ;
		labelField.dispose();
	}

	@Override
	public void pack() {
		super.pack();
		textField.pack() ;
		labelField.pack() ;
	}

	public int getSelectionCount () {
		return textField.getSelectionCount();
	}


	public int getCaretPosition () {
		return textField.getCaretPosition();
	}
	
	public int getCharCount () {		
		return textField.getCharCount();
	}
	
	public void copy() {
		textField.copy();
	}

	public void cut() {
		textField.cut();
	}

	public void paste() {
		textField.paste();
	}

	public void selectAll() {
		textField.selectAll();
	}

	public void insert(String s) {
		textField.insert(s);
	}

	public void setSelection (int start, int end) {
		textField.setSelection(start, end);
	}	
	
	public void keyPressed(KeyEvent e) {
	}

	public void keyReleased(KeyEvent e) {
		processKeyEvent(e) ;
	}

	private void processKeyEvent(KeyEvent e) {
		switch (e.character) { 
		case SWT.CR:
		case SWT.LF:
			
			if (bHex) {
				textField.setText(hexdec.toHex());
				labelField.setText(hexdec.toDecimal()) ;
			} else {
				textField.setText(hexdec.toDecimal());
				labelField.setText(hexdec.toHex()) ;
			}
			
			if(cellEditor != null) {
				cellEditor.editingApplied() ;
			}
			textField.getShell().setFocus();
			break ;
		case SWT.ESC:
			if (bHex) {
				textField.setText(hexdec.toHex()) ;
				labelField.setText(hexdec.toDecimal()) ;
			} else {
				textField.setText(hexdec.toDecimal()) ;				
				labelField.setText(hexdec.toHex()) ;
			}
			if(cellEditor != null) {
				cellEditor.editingCancelled() ;
			}
			break; 
		default: 
			try {
				hexdec.parseString(textField.getText()) ;
				if (bHex) {
					labelField.setText(hexdec.toDecimal());
				} else {
					labelField.setText(hexdec.toHex());
				}
				labelField.setForeground(Display.getCurrent().getSystemColor(SWT.COLOR_BLACK)) ;
			} catch (NumberFormatException e1) {
				labelField.setForeground(Display.getCurrent().getSystemColor(SWT.COLOR_RED)) ;
//				error(e1.getMessage()) ;
				// re-throw the exception
				throw e1;
			}
			break;    
		} 
		labelField.pack();
	}

}
