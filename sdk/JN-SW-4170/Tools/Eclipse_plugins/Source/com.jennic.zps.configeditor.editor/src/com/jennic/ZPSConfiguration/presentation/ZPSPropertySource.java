
package com.jennic.ZPSConfiguration.presentation;


import java.util.ArrayList;
import java.util.Collection;
import java.util.List;

import org.eclipse.emf.edit.provider.IItemPropertyDescriptor;
import org.eclipse.emf.edit.provider.IItemPropertySource;
import org.eclipse.emf.edit.ui.provider.PropertySource;
import org.eclipse.ui.views.properties.IPropertyDescriptor;

public class ZPSPropertySource extends PropertySource
{

	public ZPSPropertySource(Object object,
			IItemPropertySource itemPropertySource) {
		super(object, itemPropertySource);
	}

/**
   * This delegates to {@link IItemPropertySource#getPropertyDescriptors IItemPropertySource.getPropertyDescriptors}.
   */
	@Override
	public IPropertyDescriptor[] getPropertyDescriptors() {
		Collection<IPropertyDescriptor> result = new ArrayList<IPropertyDescriptor>();
		List<IItemPropertyDescriptor> itemPropertyDescriptors = itemPropertySource
				.getPropertyDescriptors(object);
		if (itemPropertyDescriptors != null) {
			for (IItemPropertyDescriptor itemPropertyDescriptor : itemPropertyDescriptors) {
				IPropertyDescriptor descriptor = createPropertyDescriptor(itemPropertyDescriptor);

				if (null != descriptor) {
					result.add(descriptor);
				}
			}
		}

		return result.toArray(new IPropertyDescriptor[result.size()]);
	}
}
