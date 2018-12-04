
#include "gtest/gtest.h"
#include "HistoryWithExitPoint.h"

#include "sc_timer_service.h"

static HistoryWithExitPoint statechart;


class HistoryWithExitPointTest : public ::testing::Test
{
public:
	/* All operations from the SCTUnit test class. */
	void historyEntryAfterExit();
	void setTimer(HistoryWithExitPoint* statechart, const sc_eventid evid, const sc_integer time_ms, const sc_boolean periodic);
	void unsetTimer(HistoryWithExitPoint* handle, const sc_eventid evid);
protected:
	sc_unit_timer_service_t timer_service;
	virtual void SetUp();
};

static HistoryWithExitPointTest * tc;


void HistoryWithExitPointTest::SetUp()
{
	historyWithExitPoint_init(&statechart);
	sc_timer_service_init(
		&timer_service,
		0,
		(sc_run_cycle_fp) &historyWithExitPoint_runCycle,
		false,
		200,
		&statechart
	);
	
	
	tc = this;
}
void HistoryWithExitPointTest::historyEntryAfterExit()
{
	historyWithExitPoint_enter(&statechart);
	EXPECT_TRUE(historyWithExitPoint_isStateActive(&statechart, HistoryWithExitPoint_mr_A_r_X1));
	historyWithExitPointIface_raise_push(&statechart);
	sc_timer_service_proceed_cycles(&timer_service, 1);
	EXPECT_TRUE(historyWithExitPoint_isStateActive(&statechart, HistoryWithExitPoint_mr_B));
	historyWithExitPointIface_raise_back(&statechart);
	sc_timer_service_proceed_cycles(&timer_service, 1);
	EXPECT_TRUE(historyWithExitPoint_isStateActive(&statechart, HistoryWithExitPoint_mr_A_r_X1));
	historyWithExitPointIface_raise_next(&statechart);
	sc_timer_service_proceed_cycles(&timer_service, 1);
	EXPECT_TRUE(historyWithExitPoint_isStateActive(&statechart, HistoryWithExitPoint_mr_A_r_X2));
	historyWithExitPointIface_raise_push(&statechart);
	sc_timer_service_proceed_cycles(&timer_service, 1);
	EXPECT_TRUE(historyWithExitPoint_isStateActive(&statechart, HistoryWithExitPoint_mr_B));
	historyWithExitPointIface_raise_back(&statechart);
	sc_timer_service_proceed_cycles(&timer_service, 1);
	EXPECT_TRUE(historyWithExitPoint_isStateActive(&statechart, HistoryWithExitPoint_mr_A_r_X2));
}

void HistoryWithExitPointTest::setTimer(HistoryWithExitPoint* statechart, const sc_eventid evid, const sc_integer time_ms, const sc_boolean periodic){
	sc_timer_t timer;
	sc_timer_init(&timer, time_ms, periodic, evid);
	insert_timer(&(tc->timer_service), timer);
}

void HistoryWithExitPointTest::unsetTimer(HistoryWithExitPoint* handle, const sc_eventid evid){
	delete_task(&(tc->timer_service), find_time_event(&timer_service, evid));
}

TEST_F(HistoryWithExitPointTest, historyEntryAfterExit) {
	historyEntryAfterExit();
}


