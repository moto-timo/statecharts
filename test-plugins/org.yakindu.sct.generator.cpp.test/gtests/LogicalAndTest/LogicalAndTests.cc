/* Generated by YAKINDU Statechart Tools code generator. */
#include <string>
#include "gtest/gtest.h"
#include "LogicalAnd.h"
#include "sc_runner.h"
#include "sc_types.h"
			


//! The timers are managed by a timer service. */
static SctUnitRunner * runner;

class LogicalAndTests : public ::testing::Test{
	protected:
	
	LogicalAnd* statechart;
	
	virtual void SetUp() {
		statechart = new LogicalAnd();
		statechart->init();
		runner = new SctUnitRunner(
			statechart,
			false,
			200
		);
	}
	virtual void TearDown() {
		delete statechart;
		delete runner;
	}
	
	
};

	TEST_F(LogicalAndTests, operandEvaluationOrder) {
		
		statechart->enter();
		
		runner->proceed_cycles(1);
		
		EXPECT_TRUE(statechart->getDefaultSCI()->get_x()== 4l && statechart->getDefaultSCI()->get_b()) << "logical and expression was executed in wrong order..." ;
		
		
}
