/**
 * Copyright (c) 2015 committers of YAKINDU and others.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *
 * Contributors:
 *     committers of YAKINDU - initial API and implementation
 */

package org.yakindu.sct.generator.java.test;

import org.junit.After;
import org.junit.Before;
import org.junit.Test;
import static org.junit.Assert.*;
import org.yakindu.scr.stringconversion.StringConversionStatemachine;
import org.yakindu.scr.stringconversion.StringConversionStatemachine.State;
/**
 *  Unit TestCase for StringConversion
 */
@SuppressWarnings("all")
public class StringConversionTest {

	private StringConversionStatemachine statemachine;

	@Before
	public void setUp() {
		statemachine = new StringConversionStatemachine();
		statemachine.init();
	}

	@After
	public void tearDown() {
		statemachine = null;
	}

	@Test
	public void testStringConversionTest() {
		statemachine.enter();
		statemachine.runCycle();
		assertTrue(statemachine.isStateActive(State.main_region_B));
		assertTrue(statemachine.getAnotherword().equals(
				statemachine.getWord() + statemachine.getNumber()));
		statemachine.raiseMyEvent("EventValue" + statemachine.getBoolVar());
		statemachine.runCycle();
		assertTrue(statemachine.getWord().equals(
				statemachine.getAnotherword() + statemachine.getBoolVar()
						+ statemachine.getRealVar()));
		assertTrue(statemachine.getWord().equals(
				statemachine.getAnotherword() + "true" + "1.1"));
	}
}
