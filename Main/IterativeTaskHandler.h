#pragma once
//#include "IterativeTask.h"
#include <memory>
#include <queue>
#include <vector>
#include <functional>

class IterativeTask;
using namespace std;

class IterativeTaskHandler
{
private:
		std::priority_queue<std::shared_ptr<IterativeTask>, std::vector<std::shared_ptr<IterativeTask>>,
			std::greater<std::shared_ptr<IterativeTask>>> minHeap;

public:
	 void pushIterativeTask(shared_ptr<IterativeTask> iterativeTask);
	 shared_ptr<IterativeTask> popIterativeTask();
	 void checkTime();//check with the top of heap

	 bool isEmpty() {
		 return minHeap.empty();
	 }

};
