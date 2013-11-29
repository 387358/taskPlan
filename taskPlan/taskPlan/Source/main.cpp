
#include <iostream>
#include <vector>
#include <sstream>

#include <QtGui/QApplication>

#include "TaskPriorityQueue.h"
#include "taskServiceHeader.h"
#include "TaskIpc.h"
#include "Client.h"

int main(int argc, char *argv[])
{
	using namespace std;
	using namespace taskPlanerNamespace;

	TaskPriorityQueue tq;
	tq.executeTaskQueue();

	StateMgr mgr;
	stringstream ss;

	string command;
	int priority;
	string actionName;
	bool interrput;

	TaskIpc::conncetServer();

	while(1)
	{

		/* Debug	*/
		/*cin >> priority;
		command = "insert";
		priority = 10;
		actionName = "CallSkype";
		interrput = false;*/
		/* Debug	*/
		
		TaskIpc::receiveStateMgr(INT_MAX, mgr);
		ss.str(mgr.status);
		/*	State mgr parser	*/
		ss >> command;
		ss >> priority;
		ss >> actionName;
		ss >> interrput;

		cout << "command: " << command << endl;
		cout << "priority: " << priority << endl;
		cout << "actionName: " << actionName << endl;
		cout << "interrput: " << interrput << endl;

		if(command=="insert")
		{
			if(actionName=="Welcome")
				tq.queueInsert(priority, "Welcome", interrput);
			else if(actionName=="Wander")
				tq.queueInsert(priority, "Wander", interrput);
			else if(actionName=="TakeWater")
				tq.queueInsert(priority, "TakeWater", interrput);
			else if(actionName=="Sign")
				tq.queueInsert(priority, "Sign", interrput);
			else if(actionName=="Asking")
				tq.queueInsert(priority, "Asking", interrput);
			else if(actionName=="CallSkype")
				tq.queueInsert(priority, "CallSkype", interrput);
			else if(actionName=="Calendar")
				tq.queueInsert(priority, "Calendar", interrput);
			else
			{
				cout << "Error state message" << endl;
			}
		}
	}
	return 0;
}

