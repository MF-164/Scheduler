#pragma once
#include <queue>
#include "Task.h"
#include "Consts.h"
#include <unordered_map>
#include <string>

typedef struct Queue {
	queue<Task*> queue;
	int weight;
};

#pragma once
class WeightRoundRobinScheduler
{
private:
	std::unordered_map<std::string, Queue> WRRQueues;

public:
	WeightRoundRobinScheduler();
	~WeightRoundRobinScheduler();
	WeightRoundRobinScheduler(WeightRoundRobinScheduler&& wrr) = delete;
	WeightRoundRobinScheduler(const WeightRoundRobinScheduler& wrr) = delete;

	void addTask(Task* task);
	std::unordered_map< std::string, Queue> getWrrQueues();
	void WeightRoundRobin();

};

