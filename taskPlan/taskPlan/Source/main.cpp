
#include <iostream>
#include <vector>

#include <QtGui/QApplication>

#include "TaskPriorityQueue.h"
#include "taskServiceHeader.h"


int main(int argc, char *argv[])
{
	using namespace std;
	using namespace taskPlanerNamespace;

	TaskPriorityQueue tq;
	//tq.queueInsert(10, "Welcome", false);
	//tq.queueInsert(10, "Sign", false);
	tq.executeTaskQueue();

	int input;
	while(1)
	{
		cin >> input;
		tq.queueInsert(10, "Welcome", false);
	}

	while(1);
	return 0;
}

