package oscfg.diagram.expressions;

import java.lang.ref.WeakReference;
import java.util.Collections;
import java.util.Iterator;
import java.util.Map;

import org.eclipse.core.runtime.IStatus;
import org.eclipse.emf.ecore.EClassifier;
import org.eclipse.emf.ecore.EEnum;
import org.eclipse.emf.ecore.EEnumLiteral;
import org.eclipse.emf.ecore.EParameter;
import org.eclipse.emf.ecore.ETypedElement;
import org.eclipse.emf.ecore.EcorePackage;
import org.eclipse.ocl.Environment;
import org.eclipse.ocl.EvaluationEnvironment;
import org.eclipse.ocl.ParserException;
import org.eclipse.ocl.Query;
import org.eclipse.ocl.ecore.EcoreFactory;
import org.eclipse.ocl.ecore.OCL.Helper;
import org.eclipse.ocl.expressions.OCLExpression;
import org.eclipse.ocl.expressions.OperationCallExp;
import org.eclipse.ocl.expressions.Variable;
import org.eclipse.ocl.helper.OCLHelper;
import org.eclipse.ocl.options.ParsingOptions;
import org.eclipse.ocl.utilities.AbstractVisitor;
import org.eclipse.ocl.utilities.PredefinedType;
import oscfg.diagram.part.OscfgDiagramEditorPlugin;

/**
 * @generated
 */
public class OscfgOCLFactory {

	/**
	 * @generated
	 */
	private final OscfgAbstractExpression[] expressions;
	/**
	 * @generated
	 */
	private final String[] expressionBodies;

	/**
	 * @generated
	 */
	protected OscfgOCLFactory() {
		this.expressions = new OscfgAbstractExpression[14];
		this.expressionBodies = new String[] {
				"if self.type = TypeType::uncontrolled then\r\n  if \r\n    oppositeEnd.source = VectorType::BusError or\r\n    oppositeEnd.source = VectorType::DataPageFault or\r\n    oppositeEnd.source = VectorType::InstructionPageFault or\r\n    oppositeEnd.source = VectorType::Alignment or\r\n    oppositeEnd.source = VectorType::IllegalInstruction or\r\n    oppositeEnd.source = VectorType::DTLBMiss or\r\n    oppositeEnd.source = VectorType::ITLBMiss or\r\n    oppositeEnd.source = VectorType::Range or\r\n    oppositeEnd.source = VectorType::SystemCall or\r\n    oppositeEnd.source = VectorType::FloatingPoint or\r\n    oppositeEnd.source = VectorType::Trap or\r\n    oppositeEnd.source = VectorType::UnimplementedModule\r\n  then\r\n    self.IPL = 16\r\n  else\r\n    true\r\n  endif\r\nelse\r\n  oppositeEnd.source = VectorType::SystemController or\r\n  oppositeEnd.source = VectorType::BBC or\r\n  oppositeEnd.source = VectorType::AES or\r\n  oppositeEnd.source = VectorType::PHY or\r\n  oppositeEnd.source = VectorType::UART0 or\r\n  oppositeEnd.source = VectorType::UART1 or\r\n  oppositeEnd.source = VectorType::Timer0 or\r\n  oppositeEnd.source = VectorType::Timer1 or\r\n  oppositeEnd.source = VectorType::Timer2 or\r\n  oppositeEnd.source = VectorType::SerialInterface or\r\n  oppositeEnd.source = VectorType::SPI or\r\n  oppositeEnd.source = VectorType::IntelligentPeripheral or\r\n  oppositeEnd.source = VectorType::AnaloguePeripheral or\r\n  oppositeEnd.source = VectorType::TickTimer or\r\n  oppositeEnd.source = VectorType::SampleFIFO or\r\n  oppositeEnd.source = VectorType::DigitalAudioIF or\r\n  oppositeEnd.source = VectorType::TickTimerException\r\nendif\r\n", //$NON-NLS-1$
				"self.Modules.ISRs->select(type = TypeType::controlled)->size() > 0", //$NON-NLS-1$
				"self.CooperativeTasks->size() >= 2", //$NON-NLS-1$
				"Task.allInstances()->select(t | t.priority = self.priority)->size() = 1", //$NON-NLS-1$
				"if self.type = TypeType::controlled then \r\n  ISR.allInstances()->select(t | t.IPL = self.IPL and t.type = TypeType::controlled)->size() = 1\r\nelse\r\n  true\r\nendif\r\n", //$NON-NLS-1$
				"InterruptSource.allInstances()->select(is | is.source = self.source)->size() = 1", //$NON-NLS-1$
				"  self.source = VectorType::SystemController or\r\n  self.source = VectorType::BBC or\r\n  self.source = VectorType::AES or\r\n  self.source = VectorType::PHY or\r\n  self.source = VectorType::UART0 or\r\n  self.source = VectorType::UART1 or\r\n  self.source = VectorType::Timer0 or\r\n  self.source = VectorType::Timer1 or\r\n  self.source = VectorType::Timer2 or\r\n  self.source = VectorType::SerialInterface or\r\n  self.source = VectorType::SPI or\r\n  self.source = VectorType::IntelligentPeripheral or\r\n  self.source = VectorType::AnaloguePeripheral or\r\n  self.source = VectorType::TickTimer or\r\n  self.source = VectorType::SampleFIFO or\r\n  self.source = VectorType::DigitalAudioIF or\r\n  self.source = VectorType::BusError or\r\n  self.source = VectorType::TickTimerException or\r\n  self.source = VectorType::Alignment or\r\n  self.source = VectorType::IllegalInstruction or\r\n  self.source = VectorType::SystemCall or\r\n  self.source = VectorType::Trap or\r\n  self.source = VectorType::UnimplementedModule\r\n", //$NON-NLS-1$
				"if\r\n  self.source = VectorType::BusError or\r\n  self.source = VectorType::DataPageFault or\r\n  self.source = VectorType::InstructionPageFault or\r\n  self.source = VectorType::Alignment or\r\n  self.source = VectorType::IllegalInstruction or\r\n  self.source = VectorType::DTLBMiss or\r\n  self.source = VectorType::ITLBMiss or\r\n  self.source = VectorType::Range or\r\n  self.source = VectorType::SystemCall or\r\n  self.source = VectorType::FloatingPoint or\r\n  self.source = VectorType::Trap or\r\n  self.source = VectorType::UnimplementedModule or\r\n  ( ( OS.allInstances()->exists(os | os.target = TargetTypes::JN514x) ) and  self.source = VectorType::TickTimerException)\r\nthen\r\n  self.SourceISR->exists(s | s.IPL = 16)\r\nelse\r\n  true\r\nendif\r\n", //$NON-NLS-1$
				"if\r\n  self.source = VectorType::SystemController or\r\n  self.source = VectorType::BBC or\r\n  self.source = VectorType::AES or\r\n  self.source = VectorType::PHY or\r\n  self.source = VectorType::UART0 or\r\n  self.source = VectorType::UART1 or\r\n  self.source = VectorType::Timer0 or\r\n  self.source = VectorType::Timer1 or\r\n  self.source = VectorType::Timer2 or\r\n  self.source = VectorType::SerialInterface or\r\n  self.source = VectorType::SPI or\r\n  self.source = VectorType::IntelligentPeripheral or\r\n  self.source = VectorType::AnaloguePeripheral or\r\n  self.source = VectorType::TickTimer or\r\n  self.source = VectorType::SampleFIFO or\r\n  self.source = VectorType::DigitalAudioIF\r\nthen\r\n  self.SourceISR->exists(s | s.IPL <= 15)\r\nelse\r\n  true\r\nendif\r\n", //$NON-NLS-1$
				"if self.type = TypeType::controlled then\r\n  self.IPL <= 15\r\nelse\r\n  true\r\nendif\r\n", //$NON-NLS-1$
				"let MaxContIPL : Integer = ISR.allInstances()->select(i | i.type = TypeType::controlled)->sortedBy(i | i.IPL)->last().IPL in\r\nif self.type = TypeType::uncontrolled then\r\n  self.IPL >= MaxContIPL and self.IPL <= 16\r\nelse\r\n  true\r\nendif\r\n", //$NON-NLS-1$
				"Task.allInstances()->size() <= 32", //$NON-NLS-1$
				"Task.allInstances()->size() > 0", //$NON-NLS-1$
				"self.verifyName()", //$NON-NLS-1$
		};
	}

	/**
	 * @generated
	 */
	private static OscfgOCLFactory getInstance() {
		OscfgOCLFactory instance = OscfgDiagramEditorPlugin.getInstance()
				.getOscfgOCLFactory();
		if (instance == null) {
			OscfgDiagramEditorPlugin.getInstance().setOscfgOCLFactory(
					instance = new OscfgOCLFactory());
		}
		return instance;
	}

	/**
	 * @generated
	 */
	public static String getExpressionBody(int index) {
		return getInstance().expressionBodies[index];
	}

	/**
	 * @generated
	 */
	public static OscfgAbstractExpression getExpression(int index,
			EClassifier context, Map<String, EClassifier> environment) {
		OscfgOCLFactory cached = getInstance();
		if (index < 0 || index >= cached.expressions.length) {
			throw new IllegalArgumentException();
		}
		if (cached.expressions[index] == null) {
			cached.expressions[index] = getExpression(
					cached.expressionBodies[index],
					context,
					environment == null ? Collections
							.<String, EClassifier> emptyMap() : environment);
		}
		return cached.expressions[index];
	}

	/**
	 * @generated
	 */
	public static OscfgAbstractExpression getExpression(String body,
			EClassifier context, Map<String, EClassifier> environment) {
		return new Expression(body, context, environment);
	}

	/**
	 * @generated
	 */
	public static OscfgAbstractExpression getExpression(String body,
			EClassifier context) {
		return getExpression(body, context,
				Collections.<String, EClassifier> emptyMap());
	}

	/**
	 * @generated
	 */
	private static class Expression extends OscfgAbstractExpression {

		/**
		 * @generated
		 */
		private final org.eclipse.ocl.ecore.OCL oclInstance;

		/**
		 * @generated
		 */
		private org.eclipse.ocl.ecore.OCLExpression oclExpression;

		/**
		 * @generated
		 */
		public Expression(String body, EClassifier context,
				Map<String, EClassifier> environment) {
			super(body, context);
			oclInstance = org.eclipse.ocl.ecore.OCL.newInstance();
			initCustomEnv(oclInstance.getEnvironment(), environment);
			Helper oclHelper = oclInstance.createOCLHelper();
			oclHelper.setContext(context());
			try {
				oclExpression = oclHelper.createQuery(body());
				setStatus(IStatus.OK, null, null);
			} catch (ParserException e) {
				setStatus(IStatus.ERROR, e.getMessage(), e);
			}
		}

		/**
		 * @generated
		 */
		@SuppressWarnings("rawtypes")
		protected Object doEvaluate(Object context, Map env) {
			if (oclExpression == null) {
				return null;
			}
			// on the first call, both evalEnvironment and extentMap are clear, for later we have finally, below.
			EvaluationEnvironment<?, ?, ?, ?, ?> evalEnv = oclInstance
					.getEvaluationEnvironment();
			// initialize environment
			for (Object nextKey : env.keySet()) {
				evalEnv.replace((String) nextKey, env.get(nextKey));
			}
			try {
				Object result = oclInstance.evaluate(context, oclExpression);
				return oclInstance.isInvalid(result) ? null : result;
			} finally {
				evalEnv.clear();
				oclInstance.setExtentMap(null); // clear allInstances cache, and get the oclInstance ready for the next call
			}
		}

		/**
		 * @generated
		 */
		private static void initCustomEnv(
				Environment<?, EClassifier, ?, ?, ?, EParameter, ?, ?, ?, ?, ?, ?> ecoreEnv,
				Map<String, EClassifier> environment) {
			// Use EObject as implicit root class for any object, to allow eContainer() and other EObject operations from OCL expressions
			ParsingOptions.setOption(ecoreEnv,
					ParsingOptions.implicitRootClass(ecoreEnv),
					EcorePackage.eINSTANCE.getEObject());
			for (String varName : environment.keySet()) {
				EClassifier varType = environment.get(varName);
				ecoreEnv.addElement(varName,
						createVar(ecoreEnv, varName, varType), false);
			}
		}

		/**
		 * @generated
		 */
		private static org.eclipse.ocl.ecore.Variable createVar(
				Environment<?, EClassifier, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?> ecoreEnv,
				String name, EClassifier type) {
			org.eclipse.ocl.ecore.Variable var = EcoreFactory.eINSTANCE
					.createVariable();
			var.setName(name);
			var.setType(ecoreEnv.getUMLReflection().getOCLType(type));
			return var;
		}
	}
}
