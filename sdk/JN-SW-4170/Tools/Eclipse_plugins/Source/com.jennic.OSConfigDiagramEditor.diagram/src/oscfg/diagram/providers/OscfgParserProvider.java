package oscfg.diagram.providers;

import org.eclipse.core.runtime.IAdaptable;
import org.eclipse.emf.ecore.EAttribute;
import org.eclipse.emf.ecore.EObject;
import org.eclipse.gmf.runtime.common.core.service.AbstractProvider;
import org.eclipse.gmf.runtime.common.core.service.IOperation;
import org.eclipse.gmf.runtime.common.ui.services.parser.GetParserOperation;
import org.eclipse.gmf.runtime.common.ui.services.parser.IParser;
import org.eclipse.gmf.runtime.common.ui.services.parser.IParserProvider;
import org.eclipse.gmf.runtime.common.ui.services.parser.ParserService;
import org.eclipse.gmf.runtime.emf.type.core.IElementType;
import org.eclipse.gmf.runtime.emf.ui.services.parser.ParserHintAdapter;
import org.eclipse.gmf.runtime.notation.View;

import oscfg.OscfgPackage;
import oscfg.diagram.edit.parts.CallbackFunctionNameEditPart;
import oscfg.diagram.edit.parts.CooperativeGroupNameEditPart;
import oscfg.diagram.edit.parts.HWCounterNameEditPart;
import oscfg.diagram.edit.parts.ISRIPLEditPart;
import oscfg.diagram.edit.parts.ISRNameEditPart;
import oscfg.diagram.edit.parts.ISRTypeEditPart;
import oscfg.diagram.edit.parts.InterruptSourceSourceEditPart;
import oscfg.diagram.edit.parts.MessageCtypeEditPart;
import oscfg.diagram.edit.parts.MessageNameEditPart;
import oscfg.diagram.edit.parts.MessageQueueEditPart;
import oscfg.diagram.edit.parts.ModuleNameEditPart;
import oscfg.diagram.edit.parts.MutexNameEditPart;
import oscfg.diagram.edit.parts.OSTargetEditPart;
import oscfg.diagram.edit.parts.SWTimerNameEditPart;
import oscfg.diagram.edit.parts.TaskAutostarted2EditPart;
import oscfg.diagram.edit.parts.TaskAutostartedEditPart;
import oscfg.diagram.edit.parts.TaskName2EditPart;
import oscfg.diagram.edit.parts.TaskNameEditPart;
import oscfg.diagram.edit.parts.TaskPriority2EditPart;
import oscfg.diagram.edit.parts.TaskPriorityEditPart;
import oscfg.diagram.parsers.MessageFormatParser;
import oscfg.diagram.part.OscfgVisualIDRegistry;

/**
 * @generated
 */
public class OscfgParserProvider extends AbstractProvider implements
		IParserProvider {

	/**
	 * @generated
	 */
	private IParser oSTarget_5008Parser;

	/**
	 * @generated
	 */
	private IParser getOSTarget_5008Parser() {
		if (oSTarget_5008Parser == null) {
			EAttribute[] features = new EAttribute[] { OscfgPackage.eINSTANCE
					.getOS_Target() };
			MessageFormatParser parser = new MessageFormatParser(features);
			parser.setViewPattern("RTOS target platform=\"{0}\""); //$NON-NLS-1$
			parser.setEditorPattern("{0}"); //$NON-NLS-1$
			parser.setEditPattern("{0}"); //$NON-NLS-1$
			oSTarget_5008Parser = parser;
		}
		return oSTarget_5008Parser;
	}

	/**
	 * @generated
	 */
	private IParser moduleName_5032Parser;

	/**
	 * @generated
	 */
	private IParser getModuleName_5032Parser() {
		if (moduleName_5032Parser == null) {
			EAttribute[] features = new EAttribute[] { OscfgPackage.eINSTANCE
					.getNamedObject_Name() };
			MessageFormatParser parser = new MessageFormatParser(features);
			moduleName_5032Parser = parser;
		}
		return moduleName_5032Parser;
	}

	/**
	 * @generated
	 */
	private IParser taskName_5018Parser;

	/**
	 * @generated
	 */
	private IParser getTaskName_5018Parser() {
		if (taskName_5018Parser == null) {
			EAttribute[] features = new EAttribute[] { OscfgPackage.eINSTANCE
					.getNamedObject_Name() };
			MessageFormatParser parser = new MessageFormatParser(features);
			parser.setViewPattern("Task \"{0}\""); //$NON-NLS-1$
			parser.setEditorPattern("{0}"); //$NON-NLS-1$
			parser.setEditPattern("{0}"); //$NON-NLS-1$
			taskName_5018Parser = parser;
		}
		return taskName_5018Parser;
	}

	/**
	 * @generated
	 */
	private IParser taskPriority_5019Parser;

	/**
	 * @generated
	 */
	private IParser getTaskPriority_5019Parser() {
		if (taskPriority_5019Parser == null) {
			EAttribute[] features = new EAttribute[] { OscfgPackage.eINSTANCE
					.getTask_Priority() };
			MessageFormatParser parser = new MessageFormatParser(features);
			parser.setViewPattern("Priority = {0,number,integer}"); //$NON-NLS-1$
			parser.setEditorPattern("{0,number,integer}"); //$NON-NLS-1$
			parser.setEditPattern("{0,number,integer}"); //$NON-NLS-1$
			taskPriority_5019Parser = parser;
		}
		return taskPriority_5019Parser;
	}

	/**
	 * @generated
	 */
	private IParser taskAutostarted_5020Parser;

	/**
	 * @generated
	 */
	private IParser getTaskAutostarted_5020Parser() {
		if (taskAutostarted_5020Parser == null) {
			EAttribute[] features = new EAttribute[] { OscfgPackage.eINSTANCE
					.getTask_Autostarted() };
			MessageFormatParser parser = new MessageFormatParser(features);
			parser.setViewPattern("Autostarted = {0}"); //$NON-NLS-1$
			parser.setEditorPattern("{0}"); //$NON-NLS-1$
			parser.setEditPattern("{0}"); //$NON-NLS-1$
			taskAutostarted_5020Parser = parser;
		}
		return taskAutostarted_5020Parser;
	}

	/**
	 * @generated
	 */
	private IParser iSRName_5022Parser;

	/**
	 * @generated
	 */
	private IParser getISRName_5022Parser() {
		if (iSRName_5022Parser == null) {
			EAttribute[] features = new EAttribute[] { OscfgPackage.eINSTANCE
					.getNamedObject_Name() };
			MessageFormatParser parser = new MessageFormatParser(features);
			parser.setViewPattern("ISR \"{0}\""); //$NON-NLS-1$
			parser.setEditorPattern("{0}"); //$NON-NLS-1$
			parser.setEditPattern("{0}"); //$NON-NLS-1$
			iSRName_5022Parser = parser;
		}
		return iSRName_5022Parser;
	}

	/**
	 * @generated
	 */
	private IParser iSRType_5023Parser;

	/**
	 * @generated
	 */
	private IParser getISRType_5023Parser() {
		if (iSRType_5023Parser == null) {
			EAttribute[] features = new EAttribute[] { OscfgPackage.eINSTANCE
					.getISR_Type() };
			MessageFormatParser parser = new MessageFormatParser(features);
			parser.setViewPattern("Type = {0}"); //$NON-NLS-1$
			parser.setEditorPattern("{0}"); //$NON-NLS-1$
			parser.setEditPattern("{0}"); //$NON-NLS-1$
			iSRType_5023Parser = parser;
		}
		return iSRType_5023Parser;
	}

	/**
	 * @generated
	 */
	private IParser iSRIPL_5024Parser;

	/**
	 * @generated
	 */
	private IParser getISRIPL_5024Parser() {
		if (iSRIPL_5024Parser == null) {
			EAttribute[] features = new EAttribute[] { OscfgPackage.eINSTANCE
					.getISR_IPL() };
			MessageFormatParser parser = new MessageFormatParser(features);
			parser.setViewPattern("IPL = {0, number,integer}"); //$NON-NLS-1$
			parser.setEditorPattern("{0,number,integer}"); //$NON-NLS-1$
			parser.setEditPattern("{0,number,integer}"); //$NON-NLS-1$
			iSRIPL_5024Parser = parser;
		}
		return iSRIPL_5024Parser;
	}

	/**
	 * @generated
	 */
	private IParser mutexName_5025Parser;

	/**
	 * @generated
	 */
	private IParser getMutexName_5025Parser() {
		if (mutexName_5025Parser == null) {
			EAttribute[] features = new EAttribute[] { OscfgPackage.eINSTANCE
					.getNamedObject_Name() };
			MessageFormatParser parser = new MessageFormatParser(features);
			parser.setViewPattern("Mutex \"{0}\""); //$NON-NLS-1$
			parser.setEditorPattern("{0}"); //$NON-NLS-1$
			parser.setEditPattern("{0}"); //$NON-NLS-1$
			mutexName_5025Parser = parser;
		}
		return mutexName_5025Parser;
	}

	/**
	 * @generated
	 */
	private IParser messageName_5026Parser;

	/**
	 * @generated
	 */
	private IParser getMessageName_5026Parser() {
		if (messageName_5026Parser == null) {
			EAttribute[] features = new EAttribute[] { OscfgPackage.eINSTANCE
					.getNamedObject_Name() };
			MessageFormatParser parser = new MessageFormatParser(features);
			parser.setViewPattern("Message \"{0}\""); //$NON-NLS-1$
			parser.setEditorPattern("{0}"); //$NON-NLS-1$
			parser.setEditPattern("{0}"); //$NON-NLS-1$
			messageName_5026Parser = parser;
		}
		return messageName_5026Parser;
	}

	/**
	 * @generated
	 */
	private IParser messageCtype_5027Parser;

	/**
	 * @generated
	 */
	private IParser getMessageCtype_5027Parser() {
		if (messageCtype_5027Parser == null) {
			EAttribute[] features = new EAttribute[] { OscfgPackage.eINSTANCE
					.getMessage_Ctype() };
			MessageFormatParser parser = new MessageFormatParser(features);
			parser.setViewPattern("C Type = {0}"); //$NON-NLS-1$
			parser.setEditorPattern("{0}"); //$NON-NLS-1$
			parser.setEditPattern("{0}"); //$NON-NLS-1$
			messageCtype_5027Parser = parser;
		}
		return messageCtype_5027Parser;
	}

	/**
	 * @generated
	 */
	private IParser messageQueue_5028Parser;

	/**
	 * @generated
	 */
	private IParser getMessageQueue_5028Parser() {
		if (messageQueue_5028Parser == null) {
			EAttribute[] features = new EAttribute[] { OscfgPackage.eINSTANCE
					.getMessage_Queue() };
			MessageFormatParser parser = new MessageFormatParser(features);
			parser.setViewPattern("Queue Size = {0}"); //$NON-NLS-1$
			parser.setEditorPattern("{0}"); //$NON-NLS-1$
			parser.setEditPattern("{0}"); //$NON-NLS-1$
			messageQueue_5028Parser = parser;
		}
		return messageQueue_5028Parser;
	}

	/**
	 * @generated
	 */
	private IParser hWCounterName_5029Parser;

	/**
	 * @generated
	 */
	private IParser getHWCounterName_5029Parser() {
		if (hWCounterName_5029Parser == null) {
			EAttribute[] features = new EAttribute[] { OscfgPackage.eINSTANCE
					.getNamedObject_Name() };
			MessageFormatParser parser = new MessageFormatParser(features);
			parser.setViewPattern("Hardware Counter \"{0}\""); //$NON-NLS-1$
			parser.setEditorPattern("{0}"); //$NON-NLS-1$
			parser.setEditPattern("{0}"); //$NON-NLS-1$
			hWCounterName_5029Parser = parser;
		}
		return hWCounterName_5029Parser;
	}

	/**
	 * @generated
	 */
	private IParser sWTimerName_5005Parser;

	/**
	 * @generated
	 */
	private IParser getSWTimerName_5005Parser() {
		if (sWTimerName_5005Parser == null) {
			EAttribute[] features = new EAttribute[] { OscfgPackage.eINSTANCE
					.getNamedObject_Name() };
			MessageFormatParser parser = new MessageFormatParser(features);
			parser.setViewPattern("Software Timer \"{0}\""); //$NON-NLS-1$
			parser.setEditorPattern("{0}"); //$NON-NLS-1$
			parser.setEditPattern("{0}"); //$NON-NLS-1$
			sWTimerName_5005Parser = parser;
		}
		return sWTimerName_5005Parser;
	}

	/**
	 * @generated
	 */
	private IParser callbackFunctionName_5030Parser;

	/**
	 * @generated
	 */
	private IParser getCallbackFunctionName_5030Parser() {
		if (callbackFunctionName_5030Parser == null) {
			EAttribute[] features = new EAttribute[] { OscfgPackage.eINSTANCE
					.getNamedObject_Name() };
			MessageFormatParser parser = new MessageFormatParser(features);
			parser.setViewPattern("Callback \"{0}\""); //$NON-NLS-1$
			parser.setEditorPattern("{0}"); //$NON-NLS-1$
			parser.setEditPattern("{0}"); //$NON-NLS-1$
			callbackFunctionName_5030Parser = parser;
		}
		return callbackFunctionName_5030Parser;
	}

	/**
	 * @generated
	 */
	private IParser interruptSourceSource_5031Parser;

	/**
	 * @generated
	 */
	private IParser getInterruptSourceSource_5031Parser() {
		if (interruptSourceSource_5031Parser == null) {
			EAttribute[] features = new EAttribute[] { OscfgPackage.eINSTANCE
					.getInterruptSource_Source() };
			MessageFormatParser parser = new MessageFormatParser(features);
			parser.setViewPattern("Interrupt Source \"{0}\""); //$NON-NLS-1$
			parser.setEditorPattern("{0}"); //$NON-NLS-1$
			parser.setEditPattern("{0}"); //$NON-NLS-1$
			interruptSourceSource_5031Parser = parser;
		}
		return interruptSourceSource_5031Parser;
	}

	/**
	 * @generated
	 */
	private IParser cooperativeGroupName_5036Parser;

	/**
	 * @generated
	 */
	private IParser getCooperativeGroupName_5036Parser() {
		if (cooperativeGroupName_5036Parser == null) {
			EAttribute[] features = new EAttribute[] { OscfgPackage.eINSTANCE
					.getNamedObject_Name() };
			MessageFormatParser parser = new MessageFormatParser(features);
			cooperativeGroupName_5036Parser = parser;
		}
		return cooperativeGroupName_5036Parser;
	}

	/**
	 * @generated
	 */
	private IParser taskName_5040Parser;

	/**
	 * @generated
	 */
	private IParser getTaskName_5040Parser() {
		if (taskName_5040Parser == null) {
			EAttribute[] features = new EAttribute[] { OscfgPackage.eINSTANCE
					.getNamedObject_Name() };
			MessageFormatParser parser = new MessageFormatParser(features);
			parser.setViewPattern("Task \"{0}\""); //$NON-NLS-1$
			parser.setEditorPattern("{0}"); //$NON-NLS-1$
			parser.setEditPattern("{0}"); //$NON-NLS-1$
			taskName_5040Parser = parser;
		}
		return taskName_5040Parser;
	}

	/**
	 * @generated
	 */
	private IParser taskPriority_5041Parser;

	/**
	 * @generated
	 */
	private IParser getTaskPriority_5041Parser() {
		if (taskPriority_5041Parser == null) {
			EAttribute[] features = new EAttribute[] { OscfgPackage.eINSTANCE
					.getTask_Priority() };
			MessageFormatParser parser = new MessageFormatParser(features);
			parser.setViewPattern("Priority = {0,number,integer}"); //$NON-NLS-1$
			parser.setEditorPattern("{0,number,integer}"); //$NON-NLS-1$
			parser.setEditPattern("{0,number,integer}"); //$NON-NLS-1$
			taskPriority_5041Parser = parser;
		}
		return taskPriority_5041Parser;
	}

	/**
	 * @generated
	 */
	private IParser taskAutostarted_5042Parser;

	/**
	 * @generated
	 */
	private IParser getTaskAutostarted_5042Parser() {
		if (taskAutostarted_5042Parser == null) {
			EAttribute[] features = new EAttribute[] { OscfgPackage.eINSTANCE
					.getTask_Autostarted() };
			MessageFormatParser parser = new MessageFormatParser(features);
			parser.setViewPattern("Autostarted = {0}"); //$NON-NLS-1$
			parser.setEditorPattern("{0}"); //$NON-NLS-1$
			parser.setEditPattern("{0}"); //$NON-NLS-1$
			taskAutostarted_5042Parser = parser;
		}
		return taskAutostarted_5042Parser;
	}

	/**
	 * @generated
	 */
	protected IParser getParser(int visualID) {
		switch (visualID) {
		case OSTargetEditPart.VISUAL_ID:
			return getOSTarget_5008Parser();
		case ModuleNameEditPart.VISUAL_ID:
			return getModuleName_5032Parser();
		case TaskNameEditPart.VISUAL_ID:
			return getTaskName_5018Parser();
		case TaskPriorityEditPart.VISUAL_ID:
			return getTaskPriority_5019Parser();
		case TaskAutostartedEditPart.VISUAL_ID:
			return getTaskAutostarted_5020Parser();
		case ISRNameEditPart.VISUAL_ID:
			return getISRName_5022Parser();
		case ISRTypeEditPart.VISUAL_ID:
			return getISRType_5023Parser();
		case ISRIPLEditPart.VISUAL_ID:
			return getISRIPL_5024Parser();
		case MutexNameEditPart.VISUAL_ID:
			return getMutexName_5025Parser();
		case MessageNameEditPart.VISUAL_ID:
			return getMessageName_5026Parser();
		case MessageCtypeEditPart.VISUAL_ID:
			return getMessageCtype_5027Parser();
		case MessageQueueEditPart.VISUAL_ID:
			return getMessageQueue_5028Parser();
		case HWCounterNameEditPart.VISUAL_ID:
			return getHWCounterName_5029Parser();
		case SWTimerNameEditPart.VISUAL_ID:
			return getSWTimerName_5005Parser();
		case CallbackFunctionNameEditPart.VISUAL_ID:
			return getCallbackFunctionName_5030Parser();
		case InterruptSourceSourceEditPart.VISUAL_ID:
			return getInterruptSourceSource_5031Parser();
		case CooperativeGroupNameEditPart.VISUAL_ID:
			return getCooperativeGroupName_5036Parser();
		case TaskName2EditPart.VISUAL_ID:
			return getTaskName_5040Parser();
		case TaskPriority2EditPart.VISUAL_ID:
			return getTaskPriority_5041Parser();
		case TaskAutostarted2EditPart.VISUAL_ID:
			return getTaskAutostarted_5042Parser();
		}
		return null;
	}

	/**
	 * Utility method that consults ParserService
	 * @generated
	 */
	public static IParser getParser(IElementType type, EObject object,
			String parserHint) {
		return ParserService.getInstance().getParser(
				new HintAdapter(type, object, parserHint));
	}

	/**
	 * @generated
	 */
	public IParser getParser(IAdaptable hint) {
		String vid = (String) hint.getAdapter(String.class);
		if (vid != null) {
			return getParser(OscfgVisualIDRegistry.getVisualID(vid));
		}
		View view = (View) hint.getAdapter(View.class);
		if (view != null) {
			return getParser(OscfgVisualIDRegistry.getVisualID(view));
		}
		return null;
	}

	/**
	 * @generated
	 */
	public boolean provides(IOperation operation) {
		if (operation instanceof GetParserOperation) {
			IAdaptable hint = ((GetParserOperation) operation).getHint();
			if (OscfgElementTypes.getElement(hint) == null) {
				return false;
			}
			return getParser(hint) != null;
		}
		return false;
	}

	/**
	 * @generated
	 */
	private static class HintAdapter extends ParserHintAdapter {

		/**
		 * @generated
		 */
		private final IElementType elementType;

		/**
		 * @generated
		 */
		public HintAdapter(IElementType type, EObject object, String parserHint) {
			super(object, parserHint);
			assert type != null;
			elementType = type;
		}

		/**
		 * @generated
		 */
		public Object getAdapter(Class adapter) {
			if (IElementType.class.equals(adapter)) {
				return elementType;
			}
			return super.getAdapter(adapter);
		}
	}

}
