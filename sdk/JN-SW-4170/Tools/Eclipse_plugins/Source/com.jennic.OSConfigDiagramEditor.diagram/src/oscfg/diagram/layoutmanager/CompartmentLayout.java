/*******************************************************************************
 * Copyright (c) 2000, 2005 IBM Corporation and others.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *
 * Contributors:
 *     IBM Corporation - initial API and implementation
 *******************************************************************************/
package oscfg.diagram.layoutmanager;

import java.util.Iterator;

import org.eclipse.draw2d.AbstractHintLayout;
import org.eclipse.draw2d.IFigure;
import org.eclipse.draw2d.geometry.Dimension;
import org.eclipse.draw2d.geometry.Rectangle;
import org.eclipse.draw2d.geometry.Transposer;

/**
 * Lays out children in rows or columns, wrapping when the current row/column is filled.
 * The aligment and spacing of rows in the parent can be configured.  The aligment and
 * spacing of children within a row can be configured.
 */
public class CompartmentLayout extends AbstractHintLayout
{


	/** The transposer used in converting horizontal layout to vertical. */
	protected Transposer transposer; {
		transposer = new Transposer();
		transposer.setEnabled(false);
	}
	
	/**
	 * Constructs a FlowLayout with horizontal orientation.
	 * @since 2.0
	 */
	public CompartmentLayout() { }

	/**
	 * @see org.eclipse.draw2d.AbstractHintLayout#isSensitiveHorizontally(IFigure)
	 */
	protected boolean isSensitiveHorizontally(IFigure parent) {
		return true;
	}

	/**
	 * @see org.eclipse.draw2d.AbstractHintLayout#isSensitiveVertically(IFigure)
	 */
	protected boolean isSensitiveVertically(IFigure parent) {
		return true;
	}

	/**
	 * Sets the given bounds for the child figure input.
	 *
	 * @param parent the parent figure
	 * @param child the child figure
	 * @param bounds the size of the child to be set
	 * @since 2.0
	 */
	protected void setBoundsOfChild(IFigure parent, IFigure child, Rectangle bounds) {
		parent.getClientArea(Rectangle.SINGLETON);
		bounds.translate(Rectangle.SINGLETON.x, Rectangle.SINGLETON.y);
		child.setBounds(bounds);
	}

	/**
	 * Provides the given child's preferred size.
	 * 
	 * @param child the Figure whose preferred size needs to be calculated
	 * @param wHint the width hint
	 * @param hHint the height hint
	 * @return the child's preferred size
	 */
	protected Dimension getChildSize(IFigure child, int wHint, int hHint) {
		return child.getPreferredSize(wHint, hHint);
	}

	/**
	 * @see org.eclipse.draw2d.AbstractLayout#calculatePreferredSize(IFigure, int, int)
	 */
	protected Dimension calculatePreferredSize(IFigure container, int wHint, int hHint) {
		// Subtract out the insets from the hints
		if (wHint > -1)
			wHint = Math.max(0, wHint - container.getInsets().getWidth());
		if (hHint > -1)
			hHint = Math.max(0, hHint - container.getInsets().getHeight());
		

		// The preferred dimension that is to be calculated and returned
		Dimension prefSize = new Dimension();
		
		// Flush out the last row's data
		prefSize.height = hHint;
		prefSize.width = wHint;
	
		// Transpose the dimension back, and compensate for the border.
		prefSize = transposer.t(prefSize);
		prefSize.width += container.getInsets().getWidth();
		prefSize.height += container.getInsets().getHeight();
		prefSize.union(getBorderPreferredSize(container));
	
		return prefSize;
	}
	
	/**
	 * @see org.eclipse.draw2d.LayoutManager#layout(IFigure)
	 */
	public void layout(IFigure parent) {	
		Iterator<IFigure> iterator = parent.getChildren().iterator();
	
		int hHint = parent.getClientArea().height;
		int wHint = parent.getClientArea().width;
		int sy = 0;
		
		while (iterator.hasNext()) {
			IFigure f = iterator.next();
			Dimension pref = transposer.t(getChildSize(f, wHint, hHint));
			if (!iterator.hasNext()) {
				/* stretch last child to fill parent area */
				pref.height = hHint - sy;
			}
			if (pref.width > wHint) {
				pref.width = wHint;
			}
			Rectangle r = new Rectangle(0, sy, pref.width, pref.height);
			sy += pref.height;
			setBoundsOfChild(parent, f, r);	
		}
	}
	
}
