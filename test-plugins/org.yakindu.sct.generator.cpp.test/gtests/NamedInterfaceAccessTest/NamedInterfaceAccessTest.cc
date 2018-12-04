#include <string>
#include "gtest/gtest.h"
#include "NamedInterfaceAccess.h"
#include "sc_runner.h"
#include "sc_types.h"

namespace  {

NamedInterfaceAccess* statechart;



//! The timers are managed by a timer service. */
static SctUnitRunner * runner;

class NamedInterfaceAccessTest : public ::testing::Test{
	protected:
	virtual void SetUp() {
		statechart = new NamedInterfaceAccess();
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


TEST_F(NamedInterfaceAccessTest, SafeOpenSuccess) {
	
	statechart->enter();
	
	runner->proceed_cycles(1);
	
	statechart->getSCI_User()->raise_numberPressed(3l);
	
	runner->proceed_cycles(1);
	
	statechart->getSCI_User()->raise_numberPressed(7l);
	
	runner->proceed_cycles(1);
	
	statechart->getSCI_User()->raise_numberPressed(5l);
	
	runner->proceed_cycles(1);
	
	EXPECT_TRUE(statechart->getSCI_Safe()->isRaised_open());
	
	
}

}

