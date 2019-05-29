package oscfg.diagram.providers;

import java.lang.ref.WeakReference;

import org.eclipse.gef.EditPart;
import org.eclipse.gef.EditPartFactory;
import org.eclipse.gmf.runtime.common.core.service.IOperation;
import org.eclipse.gmf.runtime.diagram.ui.editparts.IGraphicalEditPart;
import org.eclipse.gmf.runtime.diagram.ui.services.editpart.AbstractEditPartProvider;
import org.eclipse.gmf.runtime.diagram.ui.services.editpart.CreateGraphicEditPartOperation;
import org.eclipse.gmf.runtime.diagram.ui.services.editpart.IEditPartOperation;
import org.eclipse.gmf.runtime.notation.View;

import org.eclipse.gmf.tooling.runtime.providers.DefaultEditPartProvider;
import oscfg.diagram.edit.parts.ConfigurationEditPart;
import oscfg.diagram.edit.parts.OscfgEditPartFactory;
import oscfg.diagram.part.OscfgVisualIDRegistry;

/**
 * @generated
 */
public class OscfgEditPartProvider extends DefaultEditPartProvider {

	/**
	 * @generated
	 */
	public OscfgEditPartProvider() {
		super(new OscfgEditPartFactory(), OscfgVisualIDRegistry.TYPED_INSTANCE,
				ConfigurationEditPart.MODEL_ID);
	}
}
