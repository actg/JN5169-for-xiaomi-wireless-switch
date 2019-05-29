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

import oscfg.diagram.edit.parts.MessageEditPart;
import oscfg.diagram.edit.parts.MutexEditPart;
import oscfg.diagram.edit.parts.TaskEditPart;
import oscfg.diagram.providers.OscfgElementTypes;
import oscfg.diagram.providers.OscfgModelingAssistantProvider;

/**
 * @generated
 */
public class OscfgModelingAssistantProviderOfTaskEditPart extends
		OscfgModelingAssistantProvider {

	/**
	 * @generated
	 */
	@Override
	public List<IElementType> getRelTypesOnSource(IAdaptable source) {
		IGraphicalEditPart sourceEditPart = (IGraphicalEditPart) source
				.getAdapter(IGraphicalEditPart.class);
		return doGetRelTypesOnSource((TaskEditPart) sourceEditPart);
	}

	/**
	 * @generated
	 */
	public List<IElementType> doGetRelTypesOnSource(TaskEditPart source) {
		List<IElementType> types = new ArrayList<IElementType>(3);
		types.add(OscfgElementTypes.BaseTaskCollectMessage_4001);
		types.add(OscfgElementTypes.PosterPostMessage_4012);
		types.add(OscfgElementTypes.BaseTaskEnterExitMutex_4003);
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
		return doGetRelTypesOnSourceAndTarget((TaskEditPart) sourceEditPart,
				targetEditPart);
	}

	/**
	 * @generated
	 */
	public List<IElementType> doGetRelTypesOnSourceAndTarget(
			TaskEditPart source, IGraphicalEditPart targetEditPart) {
		List<IElementType> types = new LinkedList<IElementType>();
		if (targetEditPart instanceof MessageEditPart) {
			types.add(OscfgElementTypes.BaseTaskCollectMessage_4001);
		}
		if (targetEditPart instanceof MessageEditPart) {
			types.add(OscfgElementTypes.PosterPostMessage_4012);
		}
		if (targetEditPart instanceof MutexEditPart) {
			types.add(OscfgElementTypes.BaseTaskEnterExitMutex_4003);
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
		return doGetTypesForTarget((TaskEditPart) sourceEditPart,
				relationshipType);
	}

	/**
	 * @generated
	 */
	public List<IElementType> doGetTypesForTarget(TaskEditPart source,
			IElementType relationshipType) {
		List<IElementType> types = new ArrayList<IElementType>();
		if (relationshipType == OscfgElementTypes.BaseTaskCollectMessage_4001) {
			types.add(OscfgElementTypes.Message_3013);
		} else if (relationshipType == OscfgElementTypes.PosterPostMessage_4012) {
			types.add(OscfgElementTypes.Message_3013);
		} else if (relationshipType == OscfgElementTypes.BaseTaskEnterExitMutex_4003) {
			types.add(OscfgElementTypes.Mutex_3012);
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
		return doGetRelTypesOnTarget((TaskEditPart) targetEditPart);
	}

	/**
	 * @generated
	 */
	public List<IElementType> doGetRelTypesOnTarget(TaskEditPart target) {
		List<IElementType> types = new ArrayList<IElementType>(2);
		types.add(OscfgElementTypes.SWTimerActivates_4004);
		types.add(OscfgElementTypes.MessageNotifies_4006);
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
		return doGetTypesForSource((TaskEditPart) targetEditPart,
				relationshipType);
	}

	/**
	 * @generated
	 */
	public List<IElementType> doGetTypesForSource(TaskEditPart target,
			IElementType relationshipType) {
		List<IElementType> types = new ArrayList<IElementType>();
		if (relationshipType == OscfgElementTypes.SWTimerActivates_4004) {
			types.add(OscfgElementTypes.SWTimer_3006);
		} else if (relationshipType == OscfgElementTypes.MessageNotifies_4006) {
			types.add(OscfgElementTypes.Message_3013);
		}
		return types;
	}

}
