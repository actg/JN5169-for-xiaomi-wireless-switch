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
import oscfg.diagram.edit.parts.HWCounterEditPart;
import oscfg.diagram.providers.OscfgElementTypes;
import oscfg.diagram.providers.OscfgModelingAssistantProvider;

/**
 * @generated
 */
public class OscfgModelingAssistantProviderOfHWCounterEditPart extends
		OscfgModelingAssistantProvider {

	/**
	 * @generated
	 */
	@Override
	public List<IElementType> getRelTypesOnSource(IAdaptable source) {
		IGraphicalEditPart sourceEditPart = (IGraphicalEditPart) source
				.getAdapter(IGraphicalEditPart.class);
		return doGetRelTypesOnSource((HWCounterEditPart) sourceEditPart);
	}

	/**
	 * @generated
	 */
	public List<IElementType> doGetRelTypesOnSource(HWCounterEditPart source) {
		List<IElementType> types = new ArrayList<IElementType>(4);
		types.add(OscfgElementTypes.HWCounterEnable_callback_4007);
		types.add(OscfgElementTypes.HWCounterDisable_callback_4008);
		types.add(OscfgElementTypes.HWCounterGet_callback_4009);
		types.add(OscfgElementTypes.HWCounterSet_callback_4010);
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
				(HWCounterEditPart) sourceEditPart, targetEditPart);
	}

	/**
	 * @generated
	 */
	public List<IElementType> doGetRelTypesOnSourceAndTarget(
			HWCounterEditPart source, IGraphicalEditPart targetEditPart) {
		List<IElementType> types = new LinkedList<IElementType>();
		if (targetEditPart instanceof CallbackFunctionEditPart) {
			types.add(OscfgElementTypes.HWCounterEnable_callback_4007);
		}
		if (targetEditPart instanceof CallbackFunctionEditPart) {
			types.add(OscfgElementTypes.HWCounterDisable_callback_4008);
		}
		if (targetEditPart instanceof CallbackFunctionEditPart) {
			types.add(OscfgElementTypes.HWCounterGet_callback_4009);
		}
		if (targetEditPart instanceof CallbackFunctionEditPart) {
			types.add(OscfgElementTypes.HWCounterSet_callback_4010);
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
		return doGetTypesForTarget((HWCounterEditPart) sourceEditPart,
				relationshipType);
	}

	/**
	 * @generated
	 */
	public List<IElementType> doGetTypesForTarget(HWCounterEditPart source,
			IElementType relationshipType) {
		List<IElementType> types = new ArrayList<IElementType>();
		if (relationshipType == OscfgElementTypes.HWCounterEnable_callback_4007) {
			types.add(OscfgElementTypes.CallbackFunction_3015);
		} else if (relationshipType == OscfgElementTypes.HWCounterDisable_callback_4008) {
			types.add(OscfgElementTypes.CallbackFunction_3015);
		} else if (relationshipType == OscfgElementTypes.HWCounterGet_callback_4009) {
			types.add(OscfgElementTypes.CallbackFunction_3015);
		} else if (relationshipType == OscfgElementTypes.HWCounterSet_callback_4010) {
			types.add(OscfgElementTypes.CallbackFunction_3015);
		}
		return types;
	}

}
