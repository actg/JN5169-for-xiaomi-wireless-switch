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

import oscfg.diagram.edit.parts.CallbackFunctionEditPart;
import oscfg.diagram.edit.parts.SWTimerEditPart;
import oscfg.diagram.edit.parts.Task2EditPart;
import oscfg.diagram.edit.parts.TaskEditPart;
import oscfg.diagram.providers.OscfgElementTypes;
import oscfg.diagram.providers.OscfgModelingAssistantProvider;

/**
 * @generated
 */
public class OscfgModelingAssistantProviderOfSWTimerEditPart extends
		OscfgModelingAssistantProvider {

	/**
	 * @generated
	 */
	@Override
	public List<IElementType> getRelTypesOnSource(IAdaptable source) {
		IGraphicalEditPart sourceEditPart = (IGraphicalEditPart) source
				.getAdapter(IGraphicalEditPart.class);
		return doGetRelTypesOnSource((SWTimerEditPart) sourceEditPart);
	}

	/**
	 * @generated
	 */
	public List<IElementType> doGetRelTypesOnSource(SWTimerEditPart source) {
		List<IElementType> types = new ArrayList<IElementType>(2);
		types.add(OscfgElementTypes.SWTimerActivates_4004);
		types.add(OscfgElementTypes.SWTimerTimer_callback_4005);
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
		return doGetRelTypesOnSourceAndTarget((SWTimerEditPart) sourceEditPart,
				targetEditPart);
	}

	/**
	 * @generated
	 */
	public List<IElementType> doGetRelTypesOnSourceAndTarget(
			SWTimerEditPart source, IGraphicalEditPart targetEditPart) {
		List<IElementType> types = new LinkedList<IElementType>();
		if (targetEditPart instanceof TaskEditPart) {
			types.add(OscfgElementTypes.SWTimerActivates_4004);
		}
		if (targetEditPart instanceof Task2EditPart) {
			types.add(OscfgElementTypes.SWTimerActivates_4004);
		}
		if (targetEditPart instanceof CallbackFunctionEditPart) {
			types.add(OscfgElementTypes.SWTimerTimer_callback_4005);
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
		return doGetTypesForTarget((SWTimerEditPart) sourceEditPart,
				relationshipType);
	}

	/**
	 * @generated
	 */
	public List<IElementType> doGetTypesForTarget(SWTimerEditPart source,
			IElementType relationshipType) {
		List<IElementType> types = new ArrayList<IElementType>();
		if (relationshipType == OscfgElementTypes.SWTimerActivates_4004) {
			types.add(OscfgElementTypes.Task_3010);
			types.add(OscfgElementTypes.Task_3020);
		} else if (relationshipType == OscfgElementTypes.SWTimerTimer_callback_4005) {
			types.add(OscfgElementTypes.CallbackFunction_3015);
		}
		return types;
	}

}
