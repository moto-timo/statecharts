
#include "gtest/gtest.h"
#include "FloatModulo.h"

#include "sc_timer_service.h"

static FloatModulo statechart;


class FloatModuloTest : public ::testing::Test
{
public:
	/* All operations from the SCTUnit test class. */
	void test();
	void setTimer(FloatModulo* statechart, const sc_eventid evid, const sc_integer time_ms, const sc_boolean periodic);
	void unsetTimer(FloatModulo* handle, const sc_eventid evid);
protected:
	sc_unit_timer_service_t timer_service;
	virtual void SetUp();
};

static FloatModuloTest * tc;


void FloatModuloTest::SetUp()
{
	floatModulo_init(&statechart);
	sc_timer_service_init(
		&timer_service,
		0,
		(sc_run_cycle_fp) &floatModulo_runCycle,
		false,
		200,
		&statechart
	);
	
	
	tc = this;
}
void FloatModuloTest::test()
{
	floatModulo_enter(&statechart);
	sc_timer_service_proceed_cycles(&timer_service, 1);
	EXPECT_TRUE(floatModulo_isFinal(&statechart));
}

void FloatModuloTest::setTimer(FloatModulo* statechart, const sc_eventid evid, const sc_integer time_ms, const sc_boolean periodic){
	sc_timer_t timer;
	sc_timer_init(&timer, time_ms, periodic, evid);
	insert_timer(&(tc->timer_service), timer);
}

void FloatModuloTest::unsetTimer(FloatModulo* handle, const sc_eventid evid){
	delete_task(&(tc->timer_service), find_time_event(&timer_service, evid));
}

TEST_F(FloatModuloTest, test) {
	test();
}


