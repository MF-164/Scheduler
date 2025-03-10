//#include "doctest.h"
//#include "../Main/Scheduler.h"
//#include "Helper.h"
//
//TEST_CASE("Scheduler::execute") {
//	Scheduler scheduler(new ReadFromJSON(), new Utility());
//	clearAll(scheduler);
//	SUBCASE("Scheduler::execute - Successful Execution of Critical Task") {
//		shared_ptr<Task> criticalTask(new Task(Scheduler::taskIds++, PrioritiesLevel::CRITICAL, 2));
//
//		/*scheduler.insertTask(criticalTask);
//
//		std::thread schedulerThread(&RealTimeScheduler::realTimeSchedulerFunction, &scheduler.getRealTimeScheduler());
//		std::this_thread::sleep_for(std::chrono::milliseconds(30));*/
//		Scheduler::execute(criticalTask);
//
//		CHECK_EQ(criticalTask->getStatus(), TaskStatus::COMPLETED);
//
//		//schedulerThread.detach();
//	}
//	SUBCASE("Scheduler::execute - Preemption of Non-Critical Task") {
//		clearAll(scheduler);
//		shared_ptr<Task> higherPriorityTask(new Task(Scheduler::taskIds++, PrioritiesLevel::HIGHER, 5));
//		shared_ptr<Task> criticalTask(new Task(Scheduler::taskIds++, PrioritiesLevel::CRITICAL, 2));
//
//		// Insert tasks into the scheduler
//		scheduler.insertTask(higherPriorityTask);
//		scheduler.insertTask(criticalTask);
//
//		// Create a thread to execute tasks in the scheduler
//		std::thread schedulerThread([&scheduler, higherPriorityTask, criticalTask]() {
//			// Simulate execution of tasks
//			scheduler.execute(higherPriorityTask); // Start executing the non-critical task
//			scheduler.execute(criticalTask);       // Then, execute the critical task
//			});
//
//		// Allow time for tasks to be processed
//		std::this_thread::sleep_for(std::chrono::milliseconds(35));
//
//		// Check if the higher priority task was preempted and critical task completed
//		CHECK_EQ(higherPriorityTask->getStatus(), TaskStatus::SUSPENDED);
//		CHECK_EQ(criticalTask->getStatus(), TaskStatus::COMPLETED);
//
//		// Ensure the scheduler thread finishes
//		schedulerThread.detach();
//	}
//
//	SUBCASE("Scheduler::execute - Boundary Condition: Minimum Running Time") {
//		shared_ptr<Task> minTimeTask(new Task(Scheduler::taskIds++, PrioritiesLevel::CRITICAL, 0));
//
//		//scheduler.insertTask(minTimeTask);
//
//		//std::thread schedulerThread(&RealTimeScheduler::realTimeSchedulerFunction, &scheduler.getRealTimeScheduler());
//		Scheduler::execute(minTimeTask);
//
//
//		CHECK_EQ(minTimeTask->getStatus(), TaskStatus::COMPLETED);
//
//		//schedulerThread.detach();
//	}
//	SUBCASE("Scheduler::execute - Boundary Condition: Maximum Running Time") {
//		clearAll(scheduler);
//		// Assuming a reasonable maximum running time, like 100 for example
//		shared_ptr<Task> maxTimeTask(new Task(Scheduler::taskIds++, PrioritiesLevel::CRITICAL, 10));
//
//		//scheduler.insertTask(maxTimeTask);
//
//		//std::thread schedulerThread(&RealTimeScheduler::realTimeSchedulerFunction, &scheduler.getRealTimeScheduler());
//		//::this_thread::sleep_for(std::chrono::milliseconds(30)); // Wait until task is completed
//		Scheduler::execute(maxTimeTask);
//		CHECK_EQ(maxTimeTask->getStatus(), TaskStatus::COMPLETED);
//
//		//schedulerThread.detach();
//	}
//
//	class FailingTask : public Task {
//	public:
//		FailingTask() : Task(1, PrioritiesLevel::HIGHER, 2) {}
//
//		void setRunningTime(int time) override {
//			throw std::runtime_error("Simulated failure");
//		}
//	};
//
//	SUBCASE("SchedulerTest, TaskFailureHandledCorrectly") {
//		Scheduler scheduler(new ReadFromJSON(), new Utility());
//
//		auto failingTask = std::make_shared<FailingTask>();
//
//		scheduler.execute(failingTask);
//
//		CHECK_EQ(failingTask->getStatus(), TaskStatus::TERMINATED);
//
//		clearAll(scheduler);
//	}
//}
