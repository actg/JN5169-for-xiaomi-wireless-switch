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
import oscfg.diagram.edit.parts.MessageEditPart;
import oscfg.diagram.providers.OscfgElementTypes;
import oscfg.diagram.providers.OscfgModelingAssistantProvider;

/**
 * @generated
 */
public class OscfgModelingAssistantProviderOfCallbackFunctionEditPart extends
		OscfgModelingAssistantProvider {

	/**
	 * @generated
	 */
	@Override
	public List<IElementType> getRelTypesOnSource(IAdaptable source) {
		IGraphicalEditPart sourceEditPart = (IGraphicalEditPart) source
				.getAdapter(IGraphicalEditPart.class);
		return doGetRelTypesOnSource((CallbackFunctionEditPart) sourceEditPart);
	}

	/**
	 * @generated
	 */
	public List<IElementType> doGetRelTypesOnSource(
			CallbackFunctionEditPart source) {
		List<IElementType> types = new ArrayList<IElementType>(1);
		types.add(OscfgElementTypes.PosterPostMessage_4012);
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
				(CallbackFunctionEditPart) sourceEditPart, targetEditPart);
	}

	/**
	 * @generated
	 */
	public List<IElementType> doGetRelTypesOnSourceAndTarget(
			CallbackFunctionEditPart source, IGraphicalEditPart targetEditPart) {
		List<IElementType> types = new LinkedList<IElementType>();
		if (targetEditPart instanceof MessageEditPart) {
			types.add(OscfgElementTypes.PosterPostMessage_4012);
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
		return doGetTypesForTarget((CallbackFunctionEditPart) sourceEditPart,
				relationshipType);
	}

	/**
	 * @generated
	 */
	public List<IElementType> doGetTypesForTarget(
			CallbackFunctionEditPart source, IElementType relationshipType) {
		List<IElementType> types = new ArrayList<IElementType>();
		if (relationshipType == OscfgElementTypes.PosterPostMessage_4012) {
			types.add(OscfgElementTypes.Message_3013);
		}
		return types;
	}

	/**
	 * @generated
	 */
	@Override
	public List<IElementType> getRelTypesOnTarget(IAdaptable target) {
		IGraphicalEditPart targetEditPart = (IGraphicalEditPart) target
				.getAdapter(IGraphicalEditPart.class);
		return doGetRelTypesOnTarget((CallbackFunctionEditPart) targetEditPart);
	}

	/**
	 * @generated
	 */
	public List<IElementType> doGetRelTypesOnTarget(
			CallbackFunctionEditPart target) {
		List<IElementType> types = new ArrayList<IElementType>(5);
		types.add(OscfgElementTypes.SWTimerTimer_callback_4005);
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
	public List<IElementType> getTypesForSource(IAdaptable target,
			IElementType relationshipType) {
		IGraphicalEditPart targetEditPart = (IGraphicalEditPart) target
				.getAdapter(IGraphicalEditPart.class);
		return doGetTypesForSource((CallbackFunctionEditPart) targetEditPart,
				relationshipType);
	}

	/**
	 * @generated
	 */
	public List<IElementType> doGetTypesForSource(
			CallbackFunctionEditPart target, IElementType relationshipType) {
		List<IElementType> types = new ArrayList<IElementType>();
		if (relationshipType == OscfgElementTypes.SWTimerTimer_callback_4005) {
			types.add(OscfgElementTypes.SWTimer_3006);
		} else if (relationshipType == OscfgElementTypes.HWCounterEnable_callback_4007) {
			types.add(OscfgElementTypes.HWCounter_3014);
		} else if (relationshipType == OscfgElementTypes.HWCounterDisable_callback_4008) {
			types.add(OscfgElementTypes.HWCounter_3014);
		} else if (relationshipType == OscfgElementTypes.HWCounterGet_callback_4009) {
			types.add(OscfgElementTypes.HWCounter_3014);
		} else if (relationshipType == OscfgElementTypes.HWCounterSet_callback_4010) {
			types.add(OscfgElementTypes.HWCounter_3014);
		}
		return types;
	}

}
