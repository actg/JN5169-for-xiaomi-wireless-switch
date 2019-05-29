package oscfg.diagram.part;

import org.eclipse.core.expressions.PropertyTester;
import org.eclipse.emf.ecore.EClass;
import org.eclipse.emf.ecore.EObject;

import oscfg.OscfgPackage;

/**
 * @generated
 */
public class OscfgDomainModelElementTester extends PropertyTester {

	/**
	 * @generated
	 */
	public boolean test(Object receiver, String method, Object[] args,
			Object expectedValue) {
		if (false == receiver instanceof EObject) {
			return false;
		}
		EObject eObject = (EObject) receiver;
		EClass eClass = eObject.eClass();
		if (eClass == OscfgPackage.eINSTANCE.getCallbackFunction()) {
			return true;
		}
		if (eClass == OscfgPackage.eINSTANCE.getConfiguration()) {
			return true;
		}
		if (eClass == OscfgPackage.eINSTANCE.getDocumentRoot()) {
			return true;
		}
		if (eClass == OscfgPackage.eINSTANCE.getHWCounter()) {
			return true;
		}
		if (eClass == OscfgPackage.eINSTANCE.getISR()) {
			return true;
		}
		if (eClass == OscfgPackage.eINSTANCE.getMessage()) {
			return true;
		}
		if (eClass == OscfgPackage.eINSTANCE.getMutex()) {
			return true;
		}
		if (eClass == OscfgPackage.eINSTANCE.getModule()) {
			return true;
		}
		if (eClass == OscfgPackage.eINSTANCE.getSWTimer()) {
			return true;
		}
		if (eClass == OscfgPackage.eINSTANCE.getTask()) {
			return true;
		}
		if (eClass == OscfgPackage.eINSTANCE.getBaseTask()) {
			return true;
		}
		if (eClass == OscfgPackage.eINSTANCE.getInterruptSource()) {
			return true;
		}
		if (eClass == OscfgPackage.eINSTANCE.getOS()) {
			return true;
		}
		if (eClass == OscfgPackage.eINSTANCE.getCooperativeGroup()) {
			return true;
		}
		if (eClass == OscfgPackage.eINSTANCE.getNamedObject()) {
			return true;
		}
		if (eClass == OscfgPackage.eINSTANCE.getPoster()) {
			return true;
		}
		return false;
	}

}
