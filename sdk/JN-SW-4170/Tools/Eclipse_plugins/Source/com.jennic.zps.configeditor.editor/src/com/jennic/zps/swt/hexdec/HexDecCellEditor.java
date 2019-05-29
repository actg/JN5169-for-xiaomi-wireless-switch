package com.jennic.zps.swt.hexdec;

import java.text.MessageFormat;

import org.eclipse.core.runtime.Assert;
import org.eclipse.jface.viewers.CellEditor;
import org.eclipse.swt.SWT;
import org.eclipse.swt.events.FocusAdapter;
import org.eclipse.swt.events.FocusEvent;
import org.eclipse.swt.events.KeyAdapter;
import org.eclipse.swt.events.KeyEvent;
import org.eclipse.swt.events.ModifyEvent;
import org.eclipse.swt.events.MouseAdapter;
import org.eclipse.swt.events.MouseEvent;
import org.eclipse.swt.events.SelectionEvent;
import org.eclipse.swt.events.TraverseEvent;
import org.eclipse.swt.events.TraverseListener;
import org.eclipse.swt.widgets.Composite;
import org.eclipse.swt.widgets.Control;

public class HexDecCellEditor extends CellEditor {
	private HexDecComponent c;
//    private ModifyListener modifyListener;

	/**
     * State information for updating action enablement
     */
    private boolean isSelection = false;

    private boolean isDeleteable = false;

    private boolean isSelectable = false;

    private static final int defaultStyle = SWT.SINGLE;

	public HexDecCellEditor() {
		super();
		setStyle(defaultStyle);
	}

	public HexDecCellEditor(Composite parent) {
		super(parent, defaultStyle);
	}

	public HexDecCellEditor(Composite parent, int style) {
		super(parent, style);
	}

	   /**
     * Checks to see if the "deletable" state (can delete/
     * nothing to delete) has changed and if so fire an
     * enablement changed notification.
     */
    private void checkDeleteable() {
        boolean oldIsDeleteable = isDeleteable;
        isDeleteable = isDeleteEnabled();
        if (oldIsDeleteable != isDeleteable) {
            fireEnablementChanged(DELETE);
        }
    }

    /**
     * Checks to see if the "selectable" state (can select)
     * has changed and if so fire an enablement changed notification.
     */
    private void checkSelectable() {
        boolean oldIsSelectable = isSelectable;
        isSelectable = isSelectAllEnabled();
        if (oldIsSelectable != isSelectable) {
            fireEnablementChanged(SELECT_ALL);
        }
    }

    /**
     * Checks to see if the selection state (selection /
     * no selection) has changed and if so fire an
     * enablement changed notification.
     */
    private void checkSelection() {
        boolean oldIsSelection = isSelection;
        isSelection = c.textField.getSelectionCount() > 0;
        if (oldIsSelection != isSelection) {
            fireEnablementChanged(COPY);
            fireEnablementChanged(CUT);
        }
    }

    @Override
	protected Control createControl(Composite parent) {
		c = new HexDecComponent(parent, defaultStyle);

        c.addKeyListener(new KeyAdapter() {
            // hook key pressed - see PR 14201  
            @Override
			public void keyPressed(KeyEvent e) {
                keyReleaseOccured(e);

                // as a result of processing the above call, clients may have
                // disposed this cell editor
                if ((getControl() == null) || getControl().isDisposed()) {
					return;
				}
                checkSelection(); // see explanation below
                checkDeleteable();
                checkSelectable();
            }
        });
        c.addTraverseListener(new TraverseListener() {
            public void keyTraversed(TraverseEvent e) {
                if (e.detail == SWT.TRAVERSE_ESCAPE
                        || e.detail == SWT.TRAVERSE_RETURN) {
                    e.doit = false;
                }
            }
        });
        // We really want a selection listener but it is not supported so we
        // use a key listener and a mouse listener to know when selection changes
        // may have occurred
        c.addMouseListener(new MouseAdapter() {
            @Override
			public void mouseUp(MouseEvent e) {
                checkSelection();
                checkDeleteable();
                checkSelectable();
            }
        });
        c.addFocusListener(new FocusAdapter() {
            @Override
			public void focusLost(FocusEvent e) {
    			fireApplyEditorValue();
    			deactivate();
            }
        });
//        c.addModifyListener(getModifyListener());
		
		return c;
	}

	@Override
	protected Object doGetValue() {
		return c.getValue();
	}

	@Override
	protected void doSetFocus() {
        if (c != null) {
            c.doSetFocus();
            checkSelection();
            checkDeleteable();
            checkSelectable();
        }
	}

	@Override
	protected void doSetValue(Object value) {
		c.setValueObject(value);
	}

//	@Override
//	protected Object openDialogBox(Control cellEditorWindow) {
		// TODO Auto-generated method stub
//		return null;
//	}

//	@Override
//	protected void updateContents(Object object) {
//		doSetValue(object);
//	}

	/**
	 * These get called back from the child HexDecComponent whenever the
	 * user pressed ESC or newline and are used to remove focus from the
	 * editor fields in the eclipse property sheet
	 */
	void editingApplied() {
		this.fireApplyEditorValue();
	}

	void editingCancelled() {
		this.fireCancelEditor();
	}

    /**
     * Processes a modify event that occurred in this text cell editor.
     * This framework method performs validation and sets the error message
     * accordingly, and then reports a change via <code>fireEditorValueChanged</code>.
     * Subclasses should call this method at appropriate times. Subclasses
     * may extend or reimplement.
     *
     * @param e the SWT modify event
     */
    protected void editOccured(ModifyEvent e) {
        String value = c.getValueStr();
        if (value == null) {
			value = "";//$NON-NLS-1$
		}
        Object typedValue = value;
        boolean oldValidState = isValueValid();
        boolean newValidState = isCorrect(typedValue);
        if (typedValue == null && newValidState)
			extracted();
        if (!newValidState) {
            // try to insert the current value into the error message.
            setErrorMessage(MessageFormat.format(getErrorMessage(),
                    new Object[] { value }));
        }
        valueChanged(oldValidState, newValidState);
    }

	private void extracted() {
		{
			Assert.isTrue(false,
                    "Validator isn't limiting the cell editor's type range");//$NON-NLS-1$
		}
	}

    /**
     * Return the modify listener.
     */
/*
    private ModifyListener getModifyListener() {
        if (modifyListener == null) {
            modifyListener = new ModifyListener() {
                public void modifyText(ModifyEvent e) {
                    editOccured(e);
                }
            };
        }
        return modifyListener;
    }
*/
    /**
     * Handles a default selection event from the text control by applying the editor
     * value and deactivating this cell editor.
     * 
     * @param event the selection event
     * 
     * @since 3.0
     */
    protected void handleDefaultSelection(SelectionEvent event) {
        // same with enter-key handling code in keyReleaseOccured(e);
        fireApplyEditorValue();
        deactivate();
    }

    /**
     * The <code>TextCellEditor</code>  implementation of this 
     * <code>CellEditor</code> method returns <code>true</code> if 
     * the current selection is not empty.
     */
    @Override
	public boolean isCopyEnabled() {
        if (c == null || c.isDisposed()) {
			return false;
		}
        return c.getSelectionCount() > 0;
    }

    /**
     * The <code>TextCellEditor</code>  implementation of this 
     * <code>CellEditor</code> method returns <code>true</code> if 
     * the current selection is not empty.
     */
    @Override
	public boolean isCutEnabled() {
        if (c == null || c.isDisposed()) {
			return false;
		}
        return c.getSelectionCount() > 0;
    }

    /**
     * The <code>TextCellEditor</code>  implementation of this 
     * <code>CellEditor</code> method returns <code>true</code>
     * if there is a selection or if the caret is not positioned 
     * at the end of the text.
     */
    @Override
	public boolean isDeleteEnabled() {
        if (c == null || c.isDisposed()) {
			return false;
		}
        return c.getSelectionCount() > 0
                || c.getCaretPosition() < c.getCharCount();
    }

    /**
     * The <code>TextCellEditor</code>  implementation of this 
     * <code>CellEditor</code> method always returns <code>true</code>.
     */
    @Override
	public boolean isPasteEnabled() {
        if (c == null || c.isDisposed()) {
			return false;
		}
        return true;
    }

    /**
     * Check if save all is enabled
     * @return true if it is 
     */
    public boolean isSaveAllEnabled() {
        if (c == null || c.isDisposed()) {
			return false;
		}
        return true;
    }

    /**
     * Returns <code>true</code> if this cell editor is
     * able to perform the select all action.
     * <p>
     * This default implementation always returns 
     * <code>false</code>.
     * </p>
     * <p>
     * Subclasses may override
     * </p>
     * @return <code>true</code> if select all is possible,
     *  <code>false</code> otherwise
     */
    @Override
	public boolean isSelectAllEnabled() {
        if (c == null || c.isDisposed()) {
			return false;
		}
        return c.getCharCount() > 0;
    }

	public void setLimits(String minLimit, String maxLimit) {
		c.setLimits(minLimit, maxLimit);
	}

	public void setRange(int range, boolean signed) {
		c.setRange(range, signed);
	}

	public void setFormatToHex() {
		c.setFormatToHex();
	}

	public void setHexWidth(int width) {
		c.setHexWidth(width);
	}

	   /**
     * The <code>TextCellEditor</code> implementation of this
     * <code>CellEditor</code> method copies the
     * current selection to the clipboard. 
     */
    @Override
	public void performCopy() {
        c.copy();
    }

    /**
     * The <code>TextCellEditor</code> implementation of this
     * <code>CellEditor</code> method cuts the
     * current selection to the clipboard. 
     */
    @Override
	public void performCut() {
        c.cut();
        checkSelection();
        checkDeleteable();
        checkSelectable();
    }

    /**
     * The <code>TextCellEditor</code> implementation of this
     * <code>CellEditor</code> method deletes the
     * current selection or, if there is no selection,
     * the character next character from the current position. 
     */
    @Override
	public void performDelete() {
        if (c.getSelectionCount() > 0) {
			// remove the contents of the current selection
            c.insert(""); //$NON-NLS-1$
		} else {
            // remove the next character
            int pos = c.getCaretPosition();
            if (pos < c.getCharCount()) {
                c.setSelection(pos, pos + 1);
                c.insert(""); //$NON-NLS-1$
            }
        }
        checkSelection();
        checkDeleteable();
        checkSelectable();
    }

    /**
     * The <code>TextCellEditor</code> implementation of this
     * <code>CellEditor</code> method pastes the
     * the clipboard contents over the current selection. 
     */
    @Override
	public void performPaste() {
        c.paste();
        checkSelection();
        checkDeleteable();
        checkSelectable();
    }

    /**
     * The <code>TextCellEditor</code> implementation of this
     * <code>CellEditor</code> method selects all of the
     * current text. 
     */
    @Override
	public void performSelectAll() {
        c.selectAll();
        checkSelection();
        checkDeleteable();
    }

    /**
     * Processes a key release event that occurred in this cell editor.
     * <p>
     * The <code>TextCellEditor</code> implementation of this framework method 
     * ignores when the RETURN key is pressed since this is handled in 
     * <code>handleDefaultSelection</code>.
     * An exception is made for Ctrl+Enter for multi-line texts, since
     * a default selection event is not sent in this case. 
     * </p>
     *
     * @param keyEvent the key event
     */
    @Override
	protected void keyReleaseOccured(KeyEvent keyEvent) {
        if (keyEvent.character == '\r') { // Return key
            // Enter is handled in handleDefaultSelection.
            // Do not apply the editor value in response to an Enter key event
            // since this can be received from the IME when the intent is -not-
            // to apply the value.  
            // See bug 39074 [CellEditors] [DBCS] canna input mode fires bogus event from Text Control
            //
            // An exception is made for Ctrl+Enter for multi-line texts, since
            // a default selection event is not sent in this case. 
            if (c != null && !c.isDisposed()
                    && (c.getStyle() & SWT.MULTI) != 0) {
                if ((keyEvent.stateMask & SWT.CTRL) != 0) {
                    super.keyReleaseOccured(keyEvent);
                }
            }
            return;
        }
        super.keyReleaseOccured(keyEvent);
    }
}
