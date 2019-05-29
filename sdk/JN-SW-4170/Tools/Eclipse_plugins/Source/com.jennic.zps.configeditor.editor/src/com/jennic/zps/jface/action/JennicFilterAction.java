package com.jennic.zps.jface.action;

import org.eclipse.jface.action.Action;
import org.eclipse.jface.action.IAction;
import org.eclipse.jface.resource.ImageDescriptor;
import org.eclipse.ui.views.properties.PropertySheetPage;

/**
 * This action hides or shows jennic internal properties in the <code>PropertySheetViewer</code>.
 */
public class JennicFilterAction extends Action {

    protected PropertySheetPage propertySheetPage;

	/**
     * Create the Filter action. This action is used to show
     * or hide jennic internal properties.
     * 
     * @param viewer the viewer
     * @param name the name
     */
    public JennicFilterAction(PropertySheetPage propertySheetPage) {
        super("Jennic", IAction.AS_CHECK_BOX);
        this.setChecked(false);
        setToolTipText("Show properties that can be modified internally by Jennic");
        setImageDescriptor(ImageDescriptor.createFromURL(this.getClass().getResource("jennic16.png")));
        this.propertySheetPage = propertySheetPage;
    }

    /**
     * Toggle the display of expert properties.
     */

    public void run() {
    	propertySheetPage.refresh();
    }

}
