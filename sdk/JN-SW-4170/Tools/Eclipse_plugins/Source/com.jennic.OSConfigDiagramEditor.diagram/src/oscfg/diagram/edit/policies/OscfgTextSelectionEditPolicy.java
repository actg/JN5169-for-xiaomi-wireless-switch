package oscfg.diagram.edit.policies;

import org.eclipse.draw2d.ColorConstants;
import org.eclipse.draw2d.Figure;
import org.eclipse.draw2d.FigureListener;
import org.eclipse.draw2d.Graphics;
import org.eclipse.draw2d.IFigure;
import org.eclipse.draw2d.Label;
import org.eclipse.draw2d.RectangleFigure;
import org.eclipse.draw2d.geometry.Rectangle;
import org.eclipse.gef.editpolicies.SelectionEditPolicy;
import org.eclipse.gmf.runtime.draw2d.ui.figures.WrapLabel;
import org.eclipse.gmf.runtime.draw2d.ui.figures.WrappingLabel;
import org.eclipse.gmf.tooling.runtime.edit.policies.labels.IRefreshableFeedbackEditPolicy;

/**
 * @generated
 */
public class OscfgTextSelectionEditPolicy extends SelectionEditPolicy implements
		IRefreshableFeedbackEditPolicy {

	/**
	 * @generated
	 */
	private IFigure selectionFeedbackFigure;

	/**
	 * @generated
	 */
	private IFigure focusFeedbackFigure;

	/**
	 * @generated
	 */
	private FigureListener hostPositionListener;

	/**
	 * @generated
	 */
	protected void showPrimarySelection() {
		if (getHostFigure() instanceof WrappingLabel) {
			((WrappingLabel) getHostFigure()).setSelected(true);
			((WrappingLabel) getHostFigure()).setFocus(true);
		} else {
			showSelection();
			showFocus();
		}
	}

	/**
	 * @generated
	 */
	protected void showSelection() {
		if (getHostFigure() instanceof WrappingLabel) {
			((WrappingLabel) getHostFigure()).setSelected(true);
			((WrappingLabel) getHostFigure()).setFocus(false);
		} else {
			hideSelection();
			addFeedback(selectionFeedbackFigure = createSelectionFeedbackFigure());
			getHostFigure().addFigureListener(getHostPositionListener());
			refreshSelectionFeedback();
			hideFocus();
		}
	}

	/**
	 * @generated
	 */
	protected void hideSelection() {
		if (getHostFigure() instanceof WrappingLabel) {
			((WrappingLabel) getHostFigure()).setSelected(false);
			((WrappingLabel) getHostFigure()).setFocus(false);
		} else {
			if (selectionFeedbackFigure != null) {
				removeFeedback(selectionFeedbackFigure);
				getHostFigure().removeFigureListener(getHostPositionListener());
				selectionFeedbackFigure = null;
			}
			hideFocus();
		}
	}

	/**
	 * @generated
	 */
	protected void showFocus() {
		if (getHostFigure() instanceof WrappingLabel) {
			((WrappingLabel) getHostFigure()).setFocus(true);
		} else {
			hideFocus();
			addFeedback(focusFeedbackFigure = createFocusFeedbackFigure());
			refreshFocusFeedback();
		}
	}

	/**
	 * @generated
	 */
	protected void hideFocus() {
		if (getHostFigure() instanceof WrappingLabel) {
			((WrappingLabel) getHostFigure()).setFocus(false);
		} else {
			if (focusFeedbackFigure != null) {
				removeFeedback(focusFeedbackFigure);
				focusFeedbackFigure = null;
			}
		}
	}

	/**
	 * @generated
	 */
	protected Rectangle getFeedbackBounds() {
		Rectangle bounds;
		if (getHostFigure() instanceof Label) {
			bounds = ((Label) getHostFigure()).getTextBounds();
			bounds.intersect(getHostFigure().getBounds());
		} else {
			bounds = getHostFigure().getBounds().getCopy();
		}
		getHostFigure().getParent().translateToAbsolute(bounds);
		getFeedbackLayer().translateToRelative(bounds);
		return bounds;
	}

	/**
	 * @generated
	 */
	protected IFigure createSelectionFeedbackFigure() {
		if (getHostFigure() instanceof Label) {
			Label feedbackFigure = new Label();
			feedbackFigure.setOpaque(true);
			feedbackFigure
					.setBackgroundColor(ColorConstants.menuBackgroundSelected);
			feedbackFigure
					.setForegroundColor(ColorConstants.menuForegroundSelected);
			return feedbackFigure;
		} else {
			RectangleFigure feedbackFigure = new RectangleFigure();
			feedbackFigure.setFill(false);
			return feedbackFigure;
		}
	}

	/**
	 * @generated
	 */
	protected IFigure createFocusFeedbackFigure() {
		return new Figure() {

			protected void paintFigure(Graphics graphics) {
				graphics.drawFocus(getBounds().getResized(-1, -1));
			}
		};
	}

	/**
	 * @generated
	 */
	protected void updateLabel(Label target) {
		Label source = (Label) getHostFigure();
		target.setText(source.getText());
		target.setTextAlignment(source.getTextAlignment());
		target.setFont(source.getFont());
	}

	/**
	 * @generated
	 */
	protected void refreshSelectionFeedback() {
		if (selectionFeedbackFigure != null) {
			if (selectionFeedbackFigure instanceof Label) {
				updateLabel((Label) selectionFeedbackFigure);
				selectionFeedbackFigure.setBounds(getFeedbackBounds());
			} else {
				selectionFeedbackFigure.setBounds(getFeedbackBounds().expand(5,
						5));
			}
		}
	}

	/**
	 * @generated
	 */
	protected void refreshFocusFeedback() {
		if (focusFeedbackFigure != null) {
			focusFeedbackFigure.setBounds(getFeedbackBounds());
		}
	}

	/**
	 * @generated
	 */
	@Override
	public void refreshFeedback() {
		refreshSelectionFeedback();
		refreshFocusFeedback();
	}

	/**
	 * @generated
	 */
	private FigureListener getHostPositionListener() {
		if (hostPositionListener == null) {
			hostPositionListener = new FigureListener() {
				public void figureMoved(IFigure source) {
					refreshFeedback();
				}
			};
		}
		return hostPositionListener;
	}
}
