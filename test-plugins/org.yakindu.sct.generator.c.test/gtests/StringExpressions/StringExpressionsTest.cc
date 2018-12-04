
#include "gtest/gtest.h"
#include "StringExpressions.h"

#include "sc_timer_service.h"

static StringExpressions statechart;


class StringExpressionsTest : public ::testing::Test
{
public:
	/* All operations from the SCTUnit test class. */
	void stringExpressionsTest();
	void setTimer(StringExpressions* statechart, const sc_eventid evid, const sc_integer time_ms, const sc_boolean periodic);
	void unsetTimer(StringExpressions* handle, const sc_eventid evid);
protected:
	sc_unit_timer_service_t timer_service;
	virtual void SetUp();
};

static StringExpressionsTest * tc;


void StringExpressionsTest::SetUp()
{
	stringExpressions_init(&statechart);
	sc_timer_service_init(
		&timer_service,
		0,
		(sc_run_cycle_fp) &stringExpressions_runCycle,
		false,
		200,
		&statechart
	);
	
	
	tc = this;
}
void StringExpressionsTest::stringExpressionsTest()
{
	EXPECT_TRUE(strcmp(stringExpressionsIface_get_quotedStringX(&statechart), "\"X\"") == 0);
	EXPECT_TRUE(strcmp(stringExpressionsIface_get_quotedStringY(&statechart), "\"Y\"") == 0);
	stringExpressions_enter(&statechart);
	EXPECT_TRUE(stringExpressions_isStateActive(&statechart, StringExpressions_main_region_AssignmentChecked));
	stringExpressionsIface_raise_e(&statechart);
	sc_timer_service_proceed_cycles(&timer_service, 1);
	EXPECT_TRUE(stringExpressions_isStateActive(&statechart, StringExpressions_main_region_VarToVarCompareSucceeded));
	EXPECT_TRUE(stringExpressionsIface_get_guardStringEqual(&statechart));
	EXPECT_TRUE(stringExpressionsIface_get_guardStringNotEqual(&statechart));
	EXPECT_TRUE(stringExpressionsIface_get_stringVarEqual(&statechart));
	EXPECT_TRUE(stringExpressionsIface_get_stringVarNotEqual(&statechart));
	stringExpressionsIface_raise_e(&statechart);
	sc_timer_service_proceed_cycles(&timer_service, 1);
	EXPECT_TRUE(stringExpressions_isStateActive(&statechart, StringExpressions_main_region_VarToConstCompareSucceeded));
	EXPECT_TRUE(stringExpressionsIface_get_guardStringEqual(&statechart));
	EXPECT_TRUE(stringExpressionsIface_get_guardStringNotEqual(&statechart));
	EXPECT_TRUE(stringExpressionsIface_get_stringVarEqual(&statechart));
	EXPECT_TRUE(stringExpressionsIface_get_stringVarNotEqual(&statechart));
	stringExpressionsIface_raise_e(&statechart);
	sc_timer_service_proceed_cycles(&timer_service, 1);
	EXPECT_TRUE(stringExpressions_isStateActive(&statechart, StringExpressions_main_region_ConstToVarCompareSucceeded));
	EXPECT_TRUE(stringExpressionsIface_get_guardStringEqual(&statechart));
	EXPECT_TRUE(stringExpressionsIface_get_guardStringNotEqual(&statechart));
	EXPECT_TRUE(stringExpressionsIface_get_stringVarEqual(&statechart));
	EXPECT_TRUE(stringExpressionsIface_get_stringVarNotEqual(&statechart));
	stringExpressionsIface_raise_e(&statechart);
	sc_timer_service_proceed_cycles(&timer_service, 1);
	EXPECT_TRUE(stringExpressions_isStateActive(&statechart, StringExpressions_main_region_ConstToConstCompareSucceeded));
	EXPECT_TRUE(stringExpressionsIface_get_guardStringEqual(&statechart));
	EXPECT_TRUE(stringExpressionsIface_get_guardStringNotEqual(&statechart));
	EXPECT_TRUE(stringExpressionsIface_get_stringVarEqual(&statechart));
	EXPECT_TRUE(stringExpressionsIface_get_stringVarNotEqual(&statechart));
}

void StringExpressionsTest::setTimer(StringExpressions* statechart, const sc_eventid evid, const sc_integer time_ms, const sc_boolean periodic){
	sc_timer_t timer;
	sc_timer_init(&timer, time_ms, periodic, evid);
	insert_timer(&(tc->timer_service), timer);
}

void StringExpressionsTest::unsetTimer(StringExpressions* handle, const sc_eventid evid){
	delete_task(&(tc->timer_service), find_time_event(&timer_service, evid));
}

TEST_F(StringExpressionsTest, StringExpressionsTest) {
	stringExpressionsTest();
}


