package oscfg.diagram.view.factories;

import java.util.ArrayList;
import java.util.List;

import org.eclipse.core.runtime.IAdaptable;
import org.eclipse.gmf.runtime.diagram.core.util.ViewUtil;
import org.eclipse.gmf.runtime.diagram.ui.view.factories.ConnectionViewFactory;
import org.eclipse.gmf.runtime.notation.NotationFactory;
import org.eclipse.gmf.runtime.notation.View;

import oscfg.diagram.edit.parts.HWCounterDisable_callbackEditPart;
import oscfg.diagram.edit.parts.WrappingLabel8EditPart;
import oscfg.diagram.part.OscfgVisualIDRegistry;

/**
 * @generated
 */
public class HWCounterDisable_callbackViewFactory extends ConnectionViewFactory {

	/**
	 * @generated
	 */
	protected List createStyles(View view) {
		List styles = new ArrayList();
		styles.add(NotationFactory.eINSTANCE.createRoutingStyle());
		styles.add(NotationFactory.eINSTANCE.createFontStyle());
		return styles;
	}

	/**
	 * @generated
	 */
	protected void decorateView(View containerView, View view,
			IAdaptable semanticAdapter, String semanticHint, int index,
			boolean persisted) {
		if (semanticHint == null) {
			semanticHint = OscfgVisualIDRegistry
					.getType(HWCounterDisable_callbackEditPart.VISUAL_ID);
			view.setType(semanticHint);
		}
		super.decorateView(containerView, view, semanticAdapter, semanticHint,
				index, persisted);
		IAdaptable eObjectAdapter = null;
		getViewService()
				.createNode(
						eObjectAdapter,
						view,
						OscfgVisualIDRegistry
								.getType(WrappingLabel8EditPart.VISUAL_ID),
						ViewUtil.APPEND, true, getPreferencesHint());
	}
}
