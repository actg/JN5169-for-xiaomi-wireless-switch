/*
 * (C) Jennic Ltd. 2008 All Rights Reserved
 * 
 */
package oscfg.diagram.providers.assistants;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;

import org.eclipse.core.runtime.IAdaptable;
import org.eclipse.gmf.runtime.diagram.ui.editparts.IGraphicalEditPart;
import org.eclipse.gmf.runtime.emf.type.core.IElementType;

import oscfg.diagram.edit.parts.ISREditPart;
import oscfg.diagram.edit.parts.InterruptSourceEditPart;
import oscfg.diagram.providers.OscfgElementTypes;
import oscfg.diagram.providers.OscfgModelingAssistantProvider;

/**
 * @generated
 */
public class OscfgModelingAssistantProviderOfInterruptSourceEditPart extends
		OscfgModelingAssistantProvider {

	/**
	 * @generated
	 */
	@Override
	public List<IElementType> getRelTypesOnSource(IAdaptable source) {
		IGraphicalEditPart sourceEditPart = (IGraphicalEditPart) source
				.getAdapter(IGraphicalEditPart.class);
		return doGetRelTypesOnSource((InterruptSourceEditPart) sourceEditPart);
	}

	/**
	 * @generated
	 */
	public List<IElementType> doGetRelTypesOnSource(
			InterruptSourceEditPart source) {
		List<IElementType> types = new ArrayList<IElementType>(1);
		types.add(OscfgElementTypes.InterruptSourceSourceISR_4011);
		return types;
	}

	/**
	 * @generated
	 */
	@Override
	public List<IElementType> getRelTypesOnSourceAndTarget(IAdaptable source,
			IAdaptable target) {
		IGraphicalEditPart sourceEditPart = (IGraphicalEditPart) source
				.getAdapter(IGraphicalEditPart.class);
		IGraphicalEditPart targetEditPart = (IGraphicalEditPart) target
				.getAdapter(IGraphicalEditPart.class);
		return doGetRelTypesOnSourceAndTarget(
				(InterruptSourceEditPart) sourceEditPart, targetEditPart);
	}

	/**
	 * @generated
	 */
	public List<IElementType> doGetRelTypesOnSourceAndTarget(
			InterruptSourceEditPart source, IGraphicalEditPart targetEditPart) {
		List<IElementType> types = new LinkedList<IElementType>();
		if (targetEditPart instanceof ISREditPart) {
			types.add(OscfgElementTypes.InterruptSourceSourceISR_4011);
		}
		return types;
	}

	/**
	 * @generated
	 */
	@Override
	public List<IElementType> getTypesForTarget(IAdaptable source,
			IElementType relationshipType) {
		IGraphicalEditPart sourceEditPart = (IGraphicalEditPart) source
				.getAdapter(IGraphicalEditPart.class);
		return doGetTypesForTarget((InterruptSourceEditPart) sourceEditPart,
				relationshipType);
	}

	/**
	 * @generated
	 */
	public List<IElementType> doGetTypesForTarget(
			InterruptSourceEditPart source, IElementType relationshipType) {
		List<IElementType> types = new ArrayList<IElementType>();
		if (relationshipType == OscfgElementTypes.InterruptSourceSourceISR_4011) {
			types.add(OscfgElementTypes.ISR_3011);
		}
		return types;
	}

}
