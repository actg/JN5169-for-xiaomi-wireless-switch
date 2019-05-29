/*
 * (C) Jennic Ltd. 2008 All Rights Reserved
 * 
 */
package oscfg.diagram.providers.assistants;

import java.util.ArrayList;
import java.util.List;

import org.eclipse.core.runtime.IAdaptable;
import org.eclipse.gmf.runtime.emf.type.core.IElementType;

import oscfg.diagram.providers.OscfgElementTypes;
import oscfg.diagram.providers.OscfgModelingAssistantProvider;

/**
 * @generated
 */
public class OscfgModelingAssistantProviderOfConfigurationEditPart extends
		OscfgModelingAssistantProvider {

	/**
	 * @generated
	 */
	@Override
	public List<IElementType> getTypesForPopupBar(IAdaptable host) {
		List<IElementType> types = new ArrayList<IElementType>(1);
		types.add(OscfgElementTypes.OS_2001);
		return types;
	}

}
