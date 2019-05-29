package oscfg.diagram.part;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

import org.eclipse.gef.Tool;
import org.eclipse.gef.palette.PaletteContainer;
import org.eclipse.gef.palette.PaletteGroup;
import org.eclipse.gef.palette.PaletteRoot;
import org.eclipse.gef.palette.PaletteSeparator;
import org.eclipse.gef.palette.PaletteStack;
import org.eclipse.gef.palette.ToolEntry;
import org.eclipse.gmf.runtime.diagram.ui.tools.UnspecifiedTypeConnectionTool;
import org.eclipse.gmf.runtime.diagram.ui.tools.UnspecifiedTypeCreationTool;

import org.eclipse.gmf.runtime.emf.type.core.IElementType;
import oscfg.diagram.providers.OscfgElementTypes;

/**
 * @generated
 */
public class OscfgPaletteFactory {

	/**
	 * @generated
	 */
	public void fillPalette(PaletteRoot paletteRoot) {
		paletteRoot.add(createOSComponent1Group());
		paletteRoot.add(createTasksISRs2Group());
		paletteRoot.add(createMutexs3Group());
		paletteRoot.add(createCountersTimers4Group());
		paletteRoot.add(createMessages5Group());
		paletteRoot.add(createCallbacks6Group());
	}

	/**
	 * Creates "OS Component" palette tool group
	 * @generated
	 */
	private PaletteContainer createOSComponent1Group() {
		PaletteGroup paletteContainer = new PaletteGroup(
				Messages.OSComponent1Group_title);
		paletteContainer.setId("createOSComponent1Group"); //$NON-NLS-1$
		paletteContainer.setDescription(Messages.OSComponent1Group_desc);
		paletteContainer.add(createOS1CreationTool());
		paletteContainer.add(createModule2CreationTool());
		return paletteContainer;
	}

	/**
	 * Creates "Tasks / ISRs" palette tool group
	 * @generated
	 */
	private PaletteContainer createTasksISRs2Group() {
		PaletteGroup paletteContainer = new PaletteGroup(
				Messages.TasksISRs2Group_title);
		paletteContainer.setId("createTasksISRs2Group"); //$NON-NLS-1$
		paletteContainer.setDescription(Messages.TasksISRs2Group_desc);
		paletteContainer.add(createTask1CreationTool());
		paletteContainer.add(createCooperativeTaskGroup2CreationTool());
		paletteContainer.add(createISR3CreationTool());
		paletteContainer.add(createInterruptSource4CreationTool());
		paletteContainer.add(createISRStimulus5CreationTool());
		return paletteContainer;
	}

	/**
	 * Creates "Mutexs" palette tool group
	 * @generated
	 */
	private PaletteContainer createMutexs3Group() {
		PaletteGroup paletteContainer = new PaletteGroup(
				Messages.Mutexs3Group_title);
		paletteContainer.setId("createMutexs3Group"); //$NON-NLS-1$
		paletteContainer.setDescription(Messages.Mutexs3Group_desc);
		paletteContainer.add(createMutex1CreationTool());
		paletteContainer.add(createCriticalSection2CreationTool());
		return paletteContainer;
	}

	/**
	 * Creates "Counters / Timers" palette tool group
	 * @generated
	 */
	private PaletteContainer createCountersTimers4Group() {
		PaletteGroup paletteContainer = new PaletteGroup(
				Messages.CountersTimers4Group_title);
		paletteContainer.setId("createCountersTimers4Group"); //$NON-NLS-1$
		paletteContainer.setDescription(Messages.CountersTimers4Group_desc);
		paletteContainer.add(createHardwareCounter1CreationTool());
		paletteContainer.add(createDisableCallback2CreationTool());
		paletteContainer.add(createEnableCallback3CreationTool());
		paletteContainer.add(createGetCallback4CreationTool());
		paletteContainer.add(createSetCallback5CreationTool());
		paletteContainer.add(createSoftwareTimer6CreationTool());
		paletteContainer.add(createSoftwareTimerActivatesTask7CreationTool());
		paletteContainer.add(createSoftwareTimerCallback8CreationTool());
		return paletteContainer;
	}

	/**
	 * Creates "Messages" palette tool group
	 * @generated
	 */
	private PaletteContainer createMessages5Group() {
		PaletteGroup paletteContainer = new PaletteGroup(
				Messages.Messages5Group_title);
		paletteContainer.setId("createMessages5Group"); //$NON-NLS-1$
		paletteContainer.setDescription(Messages.Messages5Group_desc);
		paletteContainer.add(createMessage1CreationTool());
		paletteContainer.add(createPostMessage2CreationTool());
		paletteContainer.add(createCollectMessage3CreationTool());
		paletteContainer.add(createMessageNotifiesTask4CreationTool());
		return paletteContainer;
	}

	/**
	 * Creates "Callbacks" palette tool group
	 * @generated
	 */
	private PaletteContainer createCallbacks6Group() {
		PaletteGroup paletteContainer = new PaletteGroup(
				Messages.Callbacks6Group_title);
		paletteContainer.setId("createCallbacks6Group"); //$NON-NLS-1$
		paletteContainer.add(createCallbackFunction1CreationTool());
		return paletteContainer;
	}

	/**
	 * @generated
	 */
	private ToolEntry createOS1CreationTool() {
		NodeToolEntry entry = new NodeToolEntry(Messages.OS1CreationTool_title,
				Messages.OS1CreationTool_desc,
				Collections.singletonList(OscfgElementTypes.OS_2001));
		entry.setId("createOS1CreationTool"); //$NON-NLS-1$
		entry.setSmallIcon(OscfgDiagramEditorPlugin
				.findImageDescriptor("/com.jennic.OSConfigDiagramEditor.edit/icons/full/obj16/os.png")); //$NON-NLS-1$
		entry.setLargeIcon(OscfgDiagramEditorPlugin
				.findImageDescriptor("/com.jennic.OSConfigDiagramEditor.edit/icons/full/obj32/os.png")); //$NON-NLS-1$
		return entry;
	}

	/**
	 * @generated
	 */
	private ToolEntry createModule2CreationTool() {
		NodeToolEntry entry = new NodeToolEntry(
				Messages.Module2CreationTool_title,
				Messages.Module2CreationTool_desc,
				Collections.singletonList(OscfgElementTypes.Module_3009));
		entry.setId("createModule2CreationTool"); //$NON-NLS-1$
		entry.setSmallIcon(OscfgDiagramEditorPlugin
				.findImageDescriptor("/com.jennic.OSConfigDiagramEditor.edit/icons/full/obj16/module.png")); //$NON-NLS-1$
		entry.setLargeIcon(OscfgDiagramEditorPlugin
				.findImageDescriptor("/com.jennic.OSConfigDiagramEditor.edit/icons/full/obj32/module.png")); //$NON-NLS-1$
		return entry;
	}

	/**
	 * @generated
	 */
	private ToolEntry createTask1CreationTool() {
		ArrayList<IElementType> types = new ArrayList<IElementType>(2);
		types.add(OscfgElementTypes.Task_3010);
		types.add(OscfgElementTypes.Task_3020);
		NodeToolEntry entry = new NodeToolEntry(
				Messages.Task1CreationTool_title,
				Messages.Task1CreationTool_desc, types);
		entry.setId("createTask1CreationTool"); //$NON-NLS-1$
		entry.setSmallIcon(OscfgDiagramEditorPlugin
				.findImageDescriptor("/com.jennic.OSConfigDiagramEditor.edit/icons/full/obj16/task.png")); //$NON-NLS-1$
		entry.setLargeIcon(OscfgDiagramEditorPlugin
				.findImageDescriptor("/com.jennic.OSConfigDiagramEditor.edit/icons/full/obj32/task.png")); //$NON-NLS-1$
		return entry;
	}

	/**
	 * @generated
	 */
	private ToolEntry createCooperativeTaskGroup2CreationTool() {
		NodeToolEntry entry = new NodeToolEntry(
				Messages.CooperativeTaskGroup2CreationTool_title,
				Messages.CooperativeTaskGroup2CreationTool_desc,
				Collections
						.singletonList(OscfgElementTypes.CooperativeGroup_3017));
		entry.setId("createCooperativeTaskGroup2CreationTool"); //$NON-NLS-1$
		entry.setSmallIcon(OscfgDiagramEditorPlugin
				.findImageDescriptor("/com.jennic.OSConfigDiagramEditor.edit/icons/full/obj16/coop-task.png")); //$NON-NLS-1$
		entry.setLargeIcon(OscfgDiagramEditorPlugin
				.findImageDescriptor("/com.jennic.OSConfigDiagramEditor.edit/icons/full/obj32/coop-task.png")); //$NON-NLS-1$
		return entry;
	}

	/**
	 * @generated
	 */
	private ToolEntry createISR3CreationTool() {
		NodeToolEntry entry = new NodeToolEntry(
				Messages.ISR3CreationTool_title,
				Messages.ISR3CreationTool_desc,
				Collections.singletonList(OscfgElementTypes.ISR_3011));
		entry.setId("createISR3CreationTool"); //$NON-NLS-1$
		entry.setSmallIcon(OscfgDiagramEditorPlugin
				.findImageDescriptor("/com.jennic.OSConfigDiagramEditor.edit/icons/full/obj16/isr.png")); //$NON-NLS-1$
		entry.setLargeIcon(OscfgDiagramEditorPlugin
				.findImageDescriptor("/com.jennic.OSConfigDiagramEditor.edit/icons/full/obj32/isr.png")); //$NON-NLS-1$
		return entry;
	}

	/**
	 * @generated
	 */
	private ToolEntry createInterruptSource4CreationTool() {
		NodeToolEntry entry = new NodeToolEntry(
				Messages.InterruptSource4CreationTool_title,
				Messages.InterruptSource4CreationTool_desc,
				Collections
						.singletonList(OscfgElementTypes.InterruptSource_3016));
		entry.setId("createInterruptSource4CreationTool"); //$NON-NLS-1$
		entry.setSmallIcon(OscfgDiagramEditorPlugin
				.findImageDescriptor("/com.jennic.OSConfigDiagramEditor.edit/icons/full/obj16/isource.png")); //$NON-NLS-1$
		entry.setLargeIcon(OscfgDiagramEditorPlugin
				.findImageDescriptor("/com.jennic.OSConfigDiagramEditor.edit/icons/full/obj32/isource.png")); //$NON-NLS-1$
		return entry;
	}

	/**
	 * @generated
	 */
	private ToolEntry createISRStimulus5CreationTool() {
		LinkToolEntry entry = new LinkToolEntry(
				Messages.ISRStimulus5CreationTool_title,
				Messages.ISRStimulus5CreationTool_desc,
				Collections
						.singletonList(OscfgElementTypes.InterruptSourceSourceISR_4011));
		entry.setId("createISRStimulus5CreationTool"); //$NON-NLS-1$
		entry.setSmallIcon(OscfgDiagramEditorPlugin
				.findImageDescriptor("/com.jennic.OSConfigDiagramEditor.edit/icons/full/obj16/isource-isr.png")); //$NON-NLS-1$
		entry.setLargeIcon(OscfgDiagramEditorPlugin
				.findImageDescriptor("/com.jennic.OSConfigDiagramEditor.edit/icons/full/obj32/isource-isr.png")); //$NON-NLS-1$
		return entry;
	}

	/**
	 * @generated
	 */
	private ToolEntry createMutex1CreationTool() {
		NodeToolEntry entry = new NodeToolEntry(
				Messages.Mutex1CreationTool_title,
				Messages.Mutex1CreationTool_desc,
				Collections.singletonList(OscfgElementTypes.Mutex_3012));
		entry.setId("createMutex1CreationTool"); //$NON-NLS-1$
		entry.setSmallIcon(OscfgDiagramEditorPlugin
				.findImageDescriptor("/com.jennic.OSConfigDiagramEditor.edit/icons/full/obj16/mutex.png")); //$NON-NLS-1$
		entry.setLargeIcon(OscfgDiagramEditorPlugin
				.findImageDescriptor("/com.jennic.OSConfigDiagramEditor.edit/icons/full/obj32/mutex.png")); //$NON-NLS-1$
		return entry;
	}

	/**
	 * @generated
	 */
	private ToolEntry createCriticalSection2CreationTool() {
		LinkToolEntry entry = new LinkToolEntry(
				Messages.CriticalSection2CreationTool_title,
				Messages.CriticalSection2CreationTool_desc,
				Collections
						.singletonList(OscfgElementTypes.BaseTaskEnterExitMutex_4003));
		entry.setId("createCriticalSection2CreationTool"); //$NON-NLS-1$
		entry.setSmallIcon(OscfgDiagramEditorPlugin
				.findImageDescriptor("/com.jennic.OSConfigDiagramEditor.edit/icons/full/obj16/task-mutex.png")); //$NON-NLS-1$
		entry.setLargeIcon(OscfgDiagramEditorPlugin
				.findImageDescriptor("/com.jennic.OSConfigDiagramEditor.edit/icons/full/obj32/task-mutex.png")); //$NON-NLS-1$
		return entry;
	}

	/**
	 * @generated
	 */
	private ToolEntry createHardwareCounter1CreationTool() {
		NodeToolEntry entry = new NodeToolEntry(
				Messages.HardwareCounter1CreationTool_title,
				Messages.HardwareCounter1CreationTool_desc,
				Collections.singletonList(OscfgElementTypes.HWCounter_3014));
		entry.setId("createHardwareCounter1CreationTool"); //$NON-NLS-1$
		entry.setSmallIcon(OscfgDiagramEditorPlugin
				.findImageDescriptor("/com.jennic.OSConfigDiagramEditor.edit/icons/full/obj16/hcounter.png")); //$NON-NLS-1$
		entry.setLargeIcon(OscfgDiagramEditorPlugin
				.findImageDescriptor("/com.jennic.OSConfigDiagramEditor.edit/icons/full/obj32/hcounter.png")); //$NON-NLS-1$
		return entry;
	}

	/**
	 * @generated
	 */
	private ToolEntry createDisableCallback2CreationTool() {
		LinkToolEntry entry = new LinkToolEntry(
				Messages.DisableCallback2CreationTool_title,
				Messages.DisableCallback2CreationTool_desc,
				Collections
						.singletonList(OscfgElementTypes.HWCounterDisable_callback_4008));
		entry.setId("createDisableCallback2CreationTool"); //$NON-NLS-1$
		entry.setSmallIcon(OscfgDiagramEditorPlugin
				.findImageDescriptor("/com.jennic.OSConfigDiagramEditor.edit/icons/full/obj16/hwcount-callback.png")); //$NON-NLS-1$
		entry.setLargeIcon(OscfgDiagramEditorPlugin
				.findImageDescriptor("/com.jennic.OSConfigDiagramEditor.edit/icons/full/obj32/hwcount-callback.png")); //$NON-NLS-1$
		return entry;
	}

	/**
	 * @generated
	 */
	private ToolEntry createEnableCallback3CreationTool() {
		LinkToolEntry entry = new LinkToolEntry(
				Messages.EnableCallback3CreationTool_title,
				Messages.EnableCallback3CreationTool_desc,
				Collections
						.singletonList(OscfgElementTypes.HWCounterEnable_callback_4007));
		entry.setId("createEnableCallback3CreationTool"); //$NON-NLS-1$
		entry.setSmallIcon(OscfgDiagramEditorPlugin
				.findImageDescriptor("/com.jennic.OSConfigDiagramEditor.edit/icons/full/obj16/hwcount-callback.png")); //$NON-NLS-1$
		entry.setLargeIcon(OscfgDiagramEditorPlugin
				.findImageDescriptor("/com.jennic.OSConfigDiagramEditor.edit/icons/full/obj32/hwcount-callback.png")); //$NON-NLS-1$
		return entry;
	}

	/**
	 * @generated
	 */
	private ToolEntry createGetCallback4CreationTool() {
		LinkToolEntry entry = new LinkToolEntry(
				Messages.GetCallback4CreationTool_title,
				Messages.GetCallback4CreationTool_desc,
				Collections
						.singletonList(OscfgElementTypes.HWCounterGet_callback_4009));
		entry.setId("createGetCallback4CreationTool"); //$NON-NLS-1$
		entry.setSmallIcon(OscfgDiagramEditorPlugin
				.findImageDescriptor("/com.jennic.OSConfigDiagramEditor.edit/icons/full/obj16/hwcount-callback.png")); //$NON-NLS-1$
		entry.setLargeIcon(OscfgDiagramEditorPlugin
				.findImageDescriptor("/com.jennic.OSConfigDiagramEditor.edit/icons/full/obj32/hwcount-callback.png")); //$NON-NLS-1$
		return entry;
	}

	/**
	 * @generated
	 */
	private ToolEntry createSetCallback5CreationTool() {
		LinkToolEntry entry = new LinkToolEntry(
				Messages.SetCallback5CreationTool_title,
				Messages.SetCallback5CreationTool_desc,
				Collections
						.singletonList(OscfgElementTypes.HWCounterSet_callback_4010));
		entry.setId("createSetCallback5CreationTool"); //$NON-NLS-1$
		entry.setSmallIcon(OscfgDiagramEditorPlugin
				.findImageDescriptor("/com.jennic.OSConfigDiagramEditor.edit/icons/full/obj16/hwcount-callback.png")); //$NON-NLS-1$
		entry.setLargeIcon(OscfgDiagramEditorPlugin
				.findImageDescriptor("/com.jennic.OSConfigDiagramEditor.edit/icons/full/obj32/hwcount-callback.png")); //$NON-NLS-1$
		return entry;
	}

	/**
	 * @generated
	 */
	private ToolEntry createSoftwareTimer6CreationTool() {
		NodeToolEntry entry = new NodeToolEntry(
				Messages.SoftwareTimer6CreationTool_title,
				Messages.SoftwareTimer6CreationTool_desc,
				Collections.singletonList(OscfgElementTypes.SWTimer_3006));
		entry.setId("createSoftwareTimer6CreationTool"); //$NON-NLS-1$
		entry.setSmallIcon(OscfgDiagramEditorPlugin
				.findImageDescriptor("/com.jennic.OSConfigDiagramEditor.edit/icons/full/obj16/stimer.png")); //$NON-NLS-1$
		entry.setLargeIcon(OscfgDiagramEditorPlugin
				.findImageDescriptor("/com.jennic.OSConfigDiagramEditor.edit/icons/full/obj32/stimer.png")); //$NON-NLS-1$
		return entry;
	}

	/**
	 * @generated
	 */
	private ToolEntry createSoftwareTimerActivatesTask7CreationTool() {
		LinkToolEntry entry = new LinkToolEntry(
				Messages.SoftwareTimerActivatesTask7CreationTool_title,
				Messages.SoftwareTimerActivatesTask7CreationTool_desc,
				Collections
						.singletonList(OscfgElementTypes.SWTimerActivates_4004));
		entry.setId("createSoftwareTimerActivatesTask7CreationTool"); //$NON-NLS-1$
		entry.setSmallIcon(OscfgDiagramEditorPlugin
				.findImageDescriptor("/com.jennic.OSConfigDiagramEditor.edit/icons/full/obj16/swtime-task.png")); //$NON-NLS-1$
		entry.setLargeIcon(OscfgDiagramEditorPlugin
				.findImageDescriptor("/com.jennic.OSConfigDiagramEditor.edit/icons/full/obj32/swtime-task.png")); //$NON-NLS-1$
		return entry;
	}

	/**
	 * @generated
	 */
	private ToolEntry createSoftwareTimerCallback8CreationTool() {
		LinkToolEntry entry = new LinkToolEntry(
				Messages.SoftwareTimerCallback8CreationTool_title,
				Messages.SoftwareTimerCallback8CreationTool_desc,
				Collections
						.singletonList(OscfgElementTypes.SWTimerTimer_callback_4005));
		entry.setId("createSoftwareTimerCallback8CreationTool"); //$NON-NLS-1$
		entry.setSmallIcon(OscfgDiagramEditorPlugin
				.findImageDescriptor("/com.jennic.OSConfigDiagramEditor.edit/icons/full/obj16/swtime-callback.png")); //$NON-NLS-1$
		entry.setLargeIcon(OscfgDiagramEditorPlugin
				.findImageDescriptor("/com.jennic.OSConfigDiagramEditor.edit/icons/full/obj32/swtime-callback.png")); //$NON-NLS-1$
		return entry;
	}

	/**
	 * @generated
	 */
	private ToolEntry createMessage1CreationTool() {
		NodeToolEntry entry = new NodeToolEntry(
				Messages.Message1CreationTool_title,
				Messages.Message1CreationTool_desc,
				Collections.singletonList(OscfgElementTypes.Message_3013));
		entry.setId("createMessage1CreationTool"); //$NON-NLS-1$
		entry.setSmallIcon(OscfgDiagramEditorPlugin
				.findImageDescriptor("/com.jennic.OSConfigDiagramEditor.edit/icons/full/obj16/message.png")); //$NON-NLS-1$
		entry.setLargeIcon(OscfgDiagramEditorPlugin
				.findImageDescriptor("/com.jennic.OSConfigDiagramEditor.edit/icons/full/obj32/message.png")); //$NON-NLS-1$
		return entry;
	}

	/**
	 * @generated
	 */
	private ToolEntry createPostMessage2CreationTool() {
		LinkToolEntry entry = new LinkToolEntry(
				Messages.PostMessage2CreationTool_title,
				Messages.PostMessage2CreationTool_desc,
				Collections
						.singletonList(OscfgElementTypes.PosterPostMessage_4012));
		entry.setId("createPostMessage2CreationTool"); //$NON-NLS-1$
		entry.setSmallIcon(OscfgDiagramEditorPlugin
				.findImageDescriptor("/com.jennic.OSConfigDiagramEditor.edit/icons/full/obj16/postmessage.png")); //$NON-NLS-1$
		entry.setLargeIcon(OscfgDiagramEditorPlugin
				.findImageDescriptor("/com.jennic.OSConfigDiagramEditor.edit/icons/full/obj32/postmessage.png")); //$NON-NLS-1$
		return entry;
	}

	/**
	 * @generated
	 */
	private ToolEntry createCollectMessage3CreationTool() {
		LinkToolEntry entry = new LinkToolEntry(
				Messages.CollectMessage3CreationTool_title,
				Messages.CollectMessage3CreationTool_desc,
				Collections
						.singletonList(OscfgElementTypes.BaseTaskCollectMessage_4001));
		entry.setId("createCollectMessage3CreationTool"); //$NON-NLS-1$
		entry.setSmallIcon(OscfgDiagramEditorPlugin
				.findImageDescriptor("/com.jennic.OSConfigDiagramEditor.edit/icons/full/obj16/collectmessage.png")); //$NON-NLS-1$
		entry.setLargeIcon(OscfgDiagramEditorPlugin
				.findImageDescriptor("/com.jennic.OSConfigDiagramEditor.edit/icons/full/obj32/collectmessage.png")); //$NON-NLS-1$
		return entry;
	}

	/**
	 * @generated
	 */
	private ToolEntry createMessageNotifiesTask4CreationTool() {
		LinkToolEntry entry = new LinkToolEntry(
				Messages.MessageNotifiesTask4CreationTool_title,
				Messages.MessageNotifiesTask4CreationTool_desc,
				Collections
						.singletonList(OscfgElementTypes.MessageNotifies_4006));
		entry.setId("createMessageNotifiesTask4CreationTool"); //$NON-NLS-1$
		entry.setSmallIcon(OscfgDiagramEditorPlugin
				.findImageDescriptor("/com.jennic.OSConfigDiagramEditor.edit/icons/full/obj16/message-task.png")); //$NON-NLS-1$
		entry.setLargeIcon(OscfgDiagramEditorPlugin
				.findImageDescriptor("/com.jennic.OSConfigDiagramEditor.edit/icons/full/obj32/message-task.png")); //$NON-NLS-1$
		return entry;
	}

	/**
	 * @generated
	 */
	private ToolEntry createCallbackFunction1CreationTool() {
		NodeToolEntry entry = new NodeToolEntry(
				Messages.CallbackFunction1CreationTool_title,
				Messages.CallbackFunction1CreationTool_desc,
				Collections
						.singletonList(OscfgElementTypes.CallbackFunction_3015));
		entry.setId("createCallbackFunction1CreationTool"); //$NON-NLS-1$
		entry.setSmallIcon(OscfgDiagramEditorPlugin
				.findImageDescriptor("/com.jennic.OSConfigDiagramEditor.edit/icons/full/obj16/callback.png")); //$NON-NLS-1$
		entry.setLargeIcon(OscfgDiagramEditorPlugin
				.findImageDescriptor("/com.jennic.OSConfigDiagramEditor.edit/icons/full/obj32/callback.png")); //$NON-NLS-1$
		return entry;
	}

	/**
	 * @generated
	 */
	private static class NodeToolEntry extends ToolEntry {

		/**
		 * @generated
		 */
		private final List<IElementType> elementTypes;

		/**
		 * @generated
		 */
		private NodeToolEntry(String title, String description,
				List<IElementType> elementTypes) {
			super(title, description, null, null);
			this.elementTypes = elementTypes;
		}

		/**
		 * @generated
		 */
		public Tool createTool() {
			Tool tool = new UnspecifiedTypeCreationTool(elementTypes);
			tool.setProperties(getToolProperties());
			return tool;
		}
	}

	/**
	 * @generated
	 */
	private static class LinkToolEntry extends ToolEntry {

		/**
		 * @generated
		 */
		private final List<IElementType> relationshipTypes;

		/**
		 * @generated
		 */
		private LinkToolEntry(String title, String description,
				List<IElementType> relationshipTypes) {
			super(title, description, null, null);
			this.relationshipTypes = relationshipTypes;
		}

		/**
		 * @generated
		 */
		public Tool createTool() {
			Tool tool = new UnspecifiedTypeConnectionTool(relationshipTypes);
			tool.setProperties(getToolProperties());
			return tool;
		}
	}
}
