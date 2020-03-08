#include <fstream>
#include <string>
#include <queue>
#include <iostream>
using namespace std;


struct command {
	string n = "";
	int t;
	int request;
};
struct process{
public:
	int start = 0;
	int pid = 0;
	string state;
	queue<command> cmd;
	bool isDone = false;

	void print()
	{
		cout << "Process " << pid << " is " << state << endl;
	}
};
struct blockedd{
public:
	process* proc;
	int reborn;
};



struct node{
	process *data;
	node *next;
};
class ProcessTable {
public:
	node *head;
	int size = 0;
	ProcessTable()
	{
		head = NULL;
	}
	bool isempty()
	{
		if (head == NULL)
			return true;
		else
			return false;
	}
	void insert(process *x, int position)
	{
		node* newnode;
		newnode = new node;
		newnode->data = x;
		newnode->next = NULL;

		node*curr = head;
		if (isempty())
		{
			head = newnode;
			curr = newnode;
			size++;
		}
		else if (position > 0)
		{
			for (int i = 0; i < position; i++)
			{
				curr = curr->next;
			}
			size++;
			newnode->next = curr->next;
			curr->next = newnode;
			curr = head;
		}
		else
		{
			size++;
			newnode->next = head;
			head = newnode;
		}
	}
	void print()
	{
		node *curr = head;
		if (head == NULL)
		{
			cout << "No active processes" << endl << endl;
		}
		else
		{
			while (curr->next != NULL)
			{
				if (curr->data->isDone == false)
					curr->data->print();
				curr = curr->next;
			}
			if (curr->data->isDone == false)
				curr->data->print();
			cout << "\n\n";
		}
	}

};


process* addProcess(queue<process*> &interactive, queue<process*> &nonInteractive, queue<process*> &waiting)
{
	process *p = NULL;
	if (!(interactive.empty()))
	{
		p = interactive.front();
		interactive.pop();
		p->state = "RUNNING";
	}
	else if (!(nonInteractive.empty()))
	{
		p = nonInteractive.front();
		nonInteractive.pop();
		p->state = "RUNNING";
	}
	else if (!(waiting.empty()))
	{
		p = waiting.front();
		waiting.pop();
		p->state = "RUNNING";
	}
	return p;
}

void checkBlocked(int &currentTime, queue<process*> &interactive, queue<blockedd> &blocked)
{
	for (int j = 0; j < blocked.size(); j++)
	{

		if (blocked.front().reborn <= currentTime)
		{
			blocked.front().proc->state = "READY";
			interactive.push(blocked.front().proc);
			blocked.pop();
		}
		else
		{
			blocked.push(blocked.front());
			blocked.pop();
		}
	}
}
int main()
{
	ProcessTable proces;
	ifstream in("input11.txt");
	string cmd = "";
	int cores = 0;
	in >> cmd;
	in >> cores;
	int processCounter = 0;
	int time = 0;
	int ssdAccessCount = 0;
	int ssdAccesses = 0;
	int coreAccesses = 0;
	process **currentProcess = new process*[cores];
	queue<process*> interactive;
	queue<process*> nonInteractive;
	queue<blockedd> blocked;
	queue<process*> waiting;
	queue<process*> terminated;
	int currentTime = 120;
	process*currentP = NULL;
	int *coreBusy = new int[cores];
	int *ssdBusy = new int[cores];
	for (int i = 0; i < cores; i++)
	{
		coreBusy[i] = 0;
		ssdBusy[i] = 0;
		currentProcess[i] = 0;
	}
	while (!in.eof())
	{
		in >> cmd;
		if (cmd == "START")
		{
			int secondTime = 0;
			in >> time;
			in >> cmd;
			in >> secondTime;
			currentTime = time;
			processCounter++;
			process *p = new process;
			p->pid = secondTime;
			p->start = time;
			currentP = p;
			p->state = "READY";
			cout << "Process " << secondTime << " starts at time " << time << " ms" << endl;
			cout << "Process Table: " << endl;
			proces.print();
			proces.insert(p, 0);
			waiting.push(p);
		}
		else if (cmd == "CORE" || cmd == "SSD" || cmd == "TTY")
		{
			in >> time;
			command cmmd;
			cmmd.n = cmd;
			cmmd.t = time;
			currentP->cmd.push(cmmd);
		}
	}
	for (int i = 0; i < cores; i++)
	{
		currentProcess[i] = addProcess(interactive, nonInteractive, waiting);
		cout << "Process " << currentProcess[i] << " starts at time " << time << " ms" << endl;
		cout << "Process Table: " << endl;
		proces.print();
	}
	int currTime = 120;
	while (true)
	{
		currentTime++;
		if (terminated.size() >= processCounter)
		{
			break;
		}
		if (currentProcess[0] == NULL)
		{
			checkBlocked(currentTime, interactive, blocked);
			currentProcess[0] = addProcess(interactive, nonInteractive, waiting);
		}
		if (currentProcess[0] == NULL)
		{
			continue;
		}
		checkBlocked(currentTime, interactive, blocked);

		for (int i = 0; i < cores; i++)
		{
			process*p = currentProcess[i];
			if (currentProcess[i] == NULL)
				continue;
			command cc;

			if (coreBusy[i] <= currentTime)
			{
				if (p->cmd.size() == 0)
				{
					terminated.push(currentProcess[i]);
					currentProcess[i]->state = "TERMINATED";
					cout << "Process " << currentProcess[i]->pid << " terminates at time " << currentTime - 1 << " ms." << endl;
					currentProcess[i] = addProcess(interactive, nonInteractive, waiting);
					proces.print();
					continue;
				}
				cc = p->cmd.front();
				if (cc.n == "CORE")
				{
					if (coreBusy[i] <= currentTime)
					{
						coreBusy[i] = currentTime + cc.t;
						coreAccesses += cc.t;
						p->cmd.pop();
					}
				}
				if (cc.n == "SSD")
				{
					if (ssdBusy[0] <= currentTime)
					{
						ssdBusy[i] = currentTime + cc.t;
						ssdAccessCount++;
						ssdAccesses += cc.t;
						p->cmd.pop();
						if (cc.t == 0)
							currentTime--;
					}
				}
				if (cc.n == "TTY")
				{
					currentProcess[i]->state = "BLOCKED";
					blockedd b;
					b.proc = currentProcess[i];
					b.reborn = currentTime + cc.t;
					blocked.push(b);
					currentProcess[i] = addProcess(interactive, nonInteractive, waiting);
					p->cmd.pop();
				}
			}

		}
		currTime++;
	}

	cout << currentTime;

		cout << "Total elapsed time: " << currentTime << endl;
		cout << "Number of processes that completed: " << processCounter << endl;
		cout << "Total number of SSD accesses: " << ssdAccessCount << endl;
		cout << "Average number of busy cores: " << coreAccesses / currentTime << endl;
		cout << "SSD utilization: " << ssdAccesses / currentTime << endl;
	system("pause");
	return 0;
}