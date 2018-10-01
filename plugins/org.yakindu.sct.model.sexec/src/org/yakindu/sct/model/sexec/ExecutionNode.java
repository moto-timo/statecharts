/** 
 * Copyright (c) 2015 committers of YAKINDU and others. 
 * All rights reserved. This program and the accompanying materials 
 * are made available under the terms of the Eclipse Public License v1.0 
 * which accompanies this distribution, and is available at 
 * http://www.eclipse.org/legal/epl-v10.html 
 * Contributors:
 * committers of YAKINDU - initial API and implementation
 *
*/
package org.yakindu.sct.model.sexec;

import org.eclipse.emf.common.util.EList;
import org.yakindu.base.base.NamedElement;
import org.yakindu.base.types.ComplexType;

/**
 * <!-- begin-user-doc -->
 * A representation of the model object '<em><b>Execution Node</b></em>'.
 * <!-- end-user-doc -->
 *
 * <p>
 * The following features are supported:
 * </p>
 * <ul>
 *   <li>{@link org.yakindu.sct.model.sexec.ExecutionNode#getReactions <em>Reactions</em>}</li>
 *   <li>{@link org.yakindu.sct.model.sexec.ExecutionNode#getSimpleName <em>Simple Name</em>}</li>
 *   <li>{@link org.yakindu.sct.model.sexec.ExecutionNode#getReactSequence <em>React Sequence</em>}</li>
 *   <li>{@link org.yakindu.sct.model.sexec.ExecutionNode#getLocalReactSequence <em>Local React Sequence</em>}</li>
 * </ul>
 *
 * @see org.yakindu.sct.model.sexec.SexecPackage#getExecutionNode()
 * @model
 * @generated
 */
public interface ExecutionNode extends MappedElement, NamedElement, ComplexType {
	/**
	 * Returns the value of the '<em><b>Reactions</b></em>' containment reference list.
	 * The list contents are of type {@link org.yakindu.sct.model.sexec.Reaction}.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Reactions</em>' containment reference list isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Reactions</em>' containment reference list.
	 * @see org.yakindu.sct.model.sexec.SexecPackage#getExecutionNode_Reactions()
	 * @model containment="true"
	 * @generated
	 */
	EList<Reaction> getReactions();

	/**
	 * Returns the value of the '<em><b>Simple Name</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Simple Name</em>' attribute isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Simple Name</em>' attribute.
	 * @see #setSimpleName(String)
	 * @see org.yakindu.sct.model.sexec.SexecPackage#getExecutionNode_SimpleName()
	 * @model
	 * @generated
	 */
	String getSimpleName();

	/**
	 * Sets the value of the '{@link org.yakindu.sct.model.sexec.ExecutionNode#getSimpleName <em>Simple Name</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>Simple Name</em>' attribute.
	 * @see #getSimpleName()
	 * @generated
	 */
	void setSimpleName(String value);

	/**
	 * Returns the value of the '<em><b>React Sequence</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>React Sequence</em>' containment reference isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>React Sequence</em>' containment reference.
	 * @see #setReactSequence(Sequence)
	 * @see org.yakindu.sct.model.sexec.SexecPackage#getExecutionNode_ReactSequence()
	 * @model containment="true"
	 * @generated
	 */
	Sequence getReactSequence();

	/**
	 * Sets the value of the '{@link org.yakindu.sct.model.sexec.ExecutionNode#getReactSequence <em>React Sequence</em>}' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>React Sequence</em>' containment reference.
	 * @see #getReactSequence()
	 * @generated
	 */
	void setReactSequence(Sequence value);

	/**
	 * Returns the value of the '<em><b>Local React Sequence</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Local React Sequence</em>' containment reference isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Local React Sequence</em>' containment reference.
	 * @see #setLocalReactSequence(Sequence)
	 * @see org.yakindu.sct.model.sexec.SexecPackage#getExecutionNode_LocalReactSequence()
	 * @model containment="true"
	 * @generated
	 */
	Sequence getLocalReactSequence();

	/**
	 * Sets the value of the '{@link org.yakindu.sct.model.sexec.ExecutionNode#getLocalReactSequence <em>Local React Sequence</em>}' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>Local React Sequence</em>' containment reference.
	 * @see #getLocalReactSequence()
	 * @generated
	 */
	void setLocalReactSequence(Sequence value);

} // ExecutionNode
