#include "Header.h"
void setCore(command*&cmd, queue<command*> &nonInteractive)
{

	if (nonInteractive.size() == 0)
	{
		nonInteractive.push(cmd);
	}
	else
	{
		bool isDone = false;
		for (int i = 0; i < nonInteractive.size(); i++)
		{
			if (cmd->requestTime < nonInteractive.front()->requestTime)
			{
				nonInteractive.push(cmd);
				isDone = true;
				for (int j = 0; j < (nonInteractive.size() - i) - 1; j++)
				{
					nonInteractive.push(nonInteractive.front());
					nonInteractive.pop();
				}
				break;
			}
			else
			{
				nonInteractive.push(nonInteractive.front());
				nonInteractive.pop();
			}

		}
		if (isDone == false)
		{
			nonInteractive.push(cmd);
		}
	}
}
int cc = 0;
process* hipeProc = NULL;
void checkCompleted(ProcessTable pt, queue<command*> nonInteractive, int currentTime)
{
	node*curr = pt.head;
	pt;
	while (curr)
	{
		bool isCompleted = true;
		for (int i = 0; i < nonInteractive.size(); i++)
		{
			if (nonInteractive.front()->p == curr->data)
			{
				isCompleted = false;
			}
			nonInteractive.push(nonInteractive.front());
			nonInteractive.pop();
		}
		if (isCompleted && curr->data->isDisabled == false)
		{
			if (cc >= 1 && cc <= 3 && curr->data->pid != hipeProc->pid)
			{
				hipeProc->currentState = "BLOCKED";
			}
			cc++;
			curr->data->currentState = "TERMINATED";
			cout << "Process " << curr->data->pid << " terminates at time " << currentTime << endl;
			pt.display();
			curr->data->isDisabled = true;
			hipeProc->currentState = "READY";
		}
		curr = curr->next;
	}
}

command** createArray(queue<command*> nonInteractive)
{

	command**arr = new command*[nonInteractive.size()];
	for (int i = 0; i < nonInteractive.size(); i++)
	{
		arr[i] = nonInteractive.front();
		nonInteractive.push(nonInteractive.front());
		nonInteractive.pop();
	}
	return arr;
}

void reOrder(queue<command*> &nonInteractive)
{
	command**arr = createArray(nonInteractive);
	int size = nonInteractive.size();
	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (arr[i]->requestTime >= arr[j]->requestTime)
			{
				command*c1 = arr[i];
				arr[i] = arr[j];
				arr[j] = c1;
			}
		}
		nonInteractive.pop();
	}
	for (int i = 0; i < size; i++)
	{
		nonInteractive.push(arr[i]);
	}
}

void reValue(queue<command*> &nonInteractive, int difference, process*p)
{
	for (int i = 0; i < nonInteractive.size(); i++)
	{
		if (nonInteractive.front()->p == p)
		{
			nonInteractive.front()->requestTime += difference;
		}
		nonInteractive.push(nonInteractive.front());
		nonInteractive.pop();
	}
	reOrder(nonInteractive);
}
int main()
{
	ProcessTable pt;
	string input = "";
	int cores = 0;
	queue<process*> interactive;
	queue<command*> nonInteractive;
	queue<process*> waiting;
	queue<process*> completed;
	int currentTime = 120;
	process*currentP = NULL;
	int currentProcessTime = 0;
	cin >> input;
	cin >> cores;
	double summaryCores = 0;
	int summarySSDAccesses = 0;
	double summarySSDPercentAccess = 0;
	int time = 0;
	bool start=false;
	while (true)
	{
		cin >> input;
		if (input == "END")
			break;
		if (input == "START")
		{
			int time1 = 0;
			cin >> time;
			cin >> input;
			cin >> time1;
			currentProcessTime = time;
			process *p = new process;
			p->pid = time1;
			p->startTime = time;
			p->currentState = "READY";
			currentP = p;
			cout << "Process " << time1 << " starts at time " << time << " ms" << endl;
			cout << "Process Table: " << endl;
			pt.display();
			pt.add(p, 0);
			if (start == false)
			{
				hipeProc = p;
				p->currentState = "RUNNING";
				start = true;
			}
		}
		else if (input == "CORE" || input == "SSD" || input == "TTY")
		{
			cin >> time;
			command *cmd = new command();
			cmd->commandName = input;
			cmd->time = time;
			cmd->requestTime = currentProcessTime;
			cmd->p = currentP;
			currentProcessTime += time;
			if (input == "CORE")
			{
				summaryCores += time;
				setCore(cmd, nonInteractive);
			}
			if (input == "SSD")
			{
				summarySSDAccesses++;
				summarySSDPercentAccess += time;
			}
		}
	}
	int currTime = 0;
	currentTime = nonInteractive.front()->requestTime;
	while (!nonInteractive.empty())
	{
		if (currentTime >= nonInteractive.front()->requestTime)
		{
			int difference = currentTime - nonInteractive.front()->requestTime;
			currentTime += nonInteractive.front()->time;
			process*p = nonInteractive.front()->p;
			nonInteractive.pop();
			reValue(nonInteractive, difference, p);
			if (!nonInteractive.empty())
				nonInteractive.front()->p->currentState = "RUNNING";
			checkCompleted(pt, nonInteractive, currentTime);
			if (!nonInteractive.empty())
				nonInteractive.front()->p->currentState = "READY";
		}
		else
		{
			currentTime++;
		}
	}

	summaryCores /= currentTime;
	summarySSDPercentAccess /= currentTime;
	cout << "Total elapsed time: " << currentTime << " ms" << endl;
	cout << "Number of processes that completed: " << pt.size << endl;
	cout << "Total number of SSD accesses: " << summarySSDAccesses << endl;
	cout << "Average number of busy cores: " << summaryCores << endl;
	cout << "SSD utilization: " << summarySSDPercentAccess << endl;

	system("pause");
	return 0;
}