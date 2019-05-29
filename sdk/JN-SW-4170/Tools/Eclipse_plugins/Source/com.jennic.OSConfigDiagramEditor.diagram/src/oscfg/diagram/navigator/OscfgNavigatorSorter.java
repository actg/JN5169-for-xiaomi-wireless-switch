package oscfg.diagram.navigator;

import org.eclipse.jface.viewers.ViewerSorter;

import oscfg.diagram.part.OscfgVisualIDRegistry;

/**
 * @generated
 */
public class OscfgNavigatorSorter extends ViewerSorter {

	/**
	 * @generated
	 */
	private static final int GROUP_CATEGORY = 7007;

	/**
	 * @generated
	 */
	public int category(Object element) {
		if (element instanceof OscfgNavigatorItem) {
			OscfgNavigatorItem item = (OscfgNavigatorItem) element;
			return OscfgVisualIDRegistry.getVisualID(item.getView());
		}
		return GROUP_CATEGORY;
	}

}
