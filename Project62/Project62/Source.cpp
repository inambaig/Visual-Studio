/*
Name:
Course:
Due Date:
This assignment is about process scheduling.
*/
#include <string>
#include <queue>
#include <iostream>
using namespace std;
// Struct to store the processes
struct process{
	int processID;
	string state;
};
// struct to store the commands
struct command {
	string n = "";
	int duration, startTime;
	process*relatedProcess;
};

// struct to create a process table node
struct processNode{
	process *data;
	processNode *next;
};

// Process Table class implementation. 
// This class is implemented using the idea of linked list
class ProcessTable {
public:
	processNode *head = NULL;

	// This method inserts in the linked list
	void insert(process *x)
	{
		processNode *current = head;
		if (head == NULL)
		{
			head = new processNode;
			current = head;
			current->data = x;
			current->next = NULL;
		}
		else
		{
			processNode * newnode;
			newnode = new processNode;
			newnode->data = x;
			newnode->next = head;
			head = newnode;
		}
	}
	// this method deletes from the linked list
	void deleteProcess(processNode*p)
	{
		if (head == p)
		{
			head = head->next;
		}
		else
		{
			processNode *current = head;
			processNode *temp = head;
			while (current->next != NULL)
			{
				if (current->next == p)
				{
					current->next = current->next->next;
					return;
				}
				if (current->next->next == NULL)
				{
					temp = current;
				}
				current = current->next;
			}
			temp->next = NULL;
			cout << endl << endl;
		}
	}

	// This method  prints the linked list
	void print()
	{
		processNode *current = head;
		if (head != NULL)
		{
			while (current != NULL)
			{
				cout << "Process " << current->data->processID << " is " << current->data->state << endl;
				current = current->next;
			}
			cout << endl << endl;
		}
		else
		{
			cout << "There are no active processes." << endl << endl;
		}
	}
	int size()
	{
		if (head == NULL)
			return 0;
		else
		{
			int size = 0;
			processNode *current = head;
			while (current != NULL)
			{
				size++;
				current = current->next;
			}
		}
	}

};


int main()
{
	queue<process*> interactive;
	queue<command*> nonInteractive;

	process* blockedProcess = NULL;
	process*proc = NULL;
	//int time = 120;
	int numberOfProcesses = 0;
	int processDuration = 0;

	double CoresBusyTime = 0;
	int countSSDAccess = 0;
	double SSDBusyTime = 0;

	ProcessTable processTable;
	string CommandName = "";
	int duration;
	cin >> CommandName;
	bool start = false;

	int numberOfCores = 0;
	cin >> numberOfCores;
	// This loop will run forever until a break statement is called
	while (true)
	{
		cin >> CommandName;
		if (CommandName == "START")
		{
			numberOfProcesses++;
			int pid = 0;
			cin >> duration;
			cin >> CommandName;
			cin >> pid;
			processDuration = duration;
			process *p = new process;
			p->processID = pid;
			p->state = "READY";
			proc = p;
			cout << "Process " << pid << " starts at time " << duration << " ms" << endl;
			cout << "Process Table: " << endl;
			processTable.print();
			processTable.insert(p);
			if (start == false)
			{
				blockedProcess = p;
				p->state = "RUNNING";
				start = true;
			}
		}
		else if (CommandName == "END")
			break;
		else if (CommandName == "CORE" || CommandName == "SSD" || CommandName == "TTY")
		{
			cin >> duration;
			command *tempCommand = new command();
			tempCommand->n = CommandName;
			tempCommand->duration = duration;
			tempCommand->startTime = processDuration;
			tempCommand->relatedProcess = proc;
			processDuration += duration;
			if (CommandName == "CORE")
			{
				CoresBusyTime += duration;
				if (nonInteractive.empty())
					nonInteractive.push(tempCommand);
				else
				{
					bool inserted = false;
					for (int i = 0; i < nonInteractive.size(); i++)
					{
						if (tempCommand->startTime < nonInteractive.front()->startTime)
						{
							nonInteractive.push(tempCommand);
							for (int j = 0; j < nonInteractive.size() - i - 1; j++)
							{
								command *tempCommand1 = nonInteractive.front();
								nonInteractive.push(tempCommand1);
								nonInteractive.pop();
							}
							inserted = true;
							break;
						}
						else
						{
							command *tempCommand = nonInteractive.front();
							nonInteractive.push(tempCommand);
							nonInteractive.pop();
						}

					}
					if (inserted == false)
						nonInteractive.push(tempCommand);
				}
			}
			if (CommandName == "SSD")
			{
				SSDBusyTime += duration;
				countSSDAccess++;
			}
		}
	}
	int currTime = 0;
	int * time = new int[numberOfCores];
	for (int x = 0; x < numberOfCores; x++)
	{
		time[x] = nonInteractive.front()->startTime;
	}
	//time = nonInteractive.front()->startTime;
	while (!nonInteractive.empty())
	{
		for (int x = 0; x < numberOfCores; x++)
		{
			if (time[x] >= nonInteractive.front()->startTime)
			{
				int difference = time[x] - nonInteractive.front()->startTime;
				time[x] += nonInteractive.front()->duration;
				process*procc = nonInteractive.front()->relatedProcess;
				nonInteractive.pop();
				for (int i = 0; i < nonInteractive.size(); i++)
				{
					if (nonInteractive.front()->relatedProcess == procc)
					{
						nonInteractive.front()->startTime += difference;
					}
					command *tempCommand = nonInteractive.front();
					nonInteractive.push(tempCommand);
					nonInteractive.pop();
				}
				command**array = new command*[nonInteractive.size()];
				for (int i = 0; i < nonInteractive.size(); i++)
				{
					array[i] = nonInteractive.front();
					command *tempCommand = nonInteractive.front();
					nonInteractive.push(tempCommand);
					nonInteractive.pop();
				}
				int size = nonInteractive.size();
				for (int i = 0; i < size; i++)
				{
					for (int j = i + 1; j < size; j++)
					{
						if (array[i]->startTime >= array[j]->startTime)
						{
							command*tempCommand = array[i];
							array[i] = array[j];
							array[j] = tempCommand;
						}
					}
					nonInteractive.pop();
				}
				for (int i = 0; i < size; i++)
				{
					nonInteractive.push(array[i]);
				}
				if (!nonInteractive.empty())
					nonInteractive.front()->relatedProcess->state = "RUNNING";

				processNode*current = processTable.head;
				while (current)
				{
					bool done = true;
					for (int i = 0; i < nonInteractive.size(); i++)
					{
						if (nonInteractive.front()->relatedProcess == current->data)
							done = false;
						command *tempCommand = nonInteractive.front();
						nonInteractive.push(tempCommand);
						nonInteractive.pop();
					}
					if (done)
					{
						current->data->state = "TERMINATED";
						cout << "Process " << current->data->processID << " terminates at time " << time[x] << endl;
						processTable.print();
						processTable.deleteProcess(current);
						blockedProcess->state = "READY";
						if (processTable.size() == 0)
							break;
					}
					current = current->next;
				}
				if (processTable.size() == 0)
					break;
				if (nonInteractive.size() != 0)
					nonInteractive.front()->relatedProcess->state = "READY";
			}
			else
			{
				time[x]++;
			}
		}
		
	}
	// The following block will print the summary of the process scheduler
	double avgCoreBusy = CoresBusyTime / time[0];
	double avgSSDBusy = SSDBusyTime / time[0];
	cout << "Total elapsed time: " << time[0] << " ms" << endl;
	cout << "Number of processes that completed: " << numberOfProcesses << endl;
	cout << "Total number of SSD accesses: " << countSSDAccess << endl;
	cout << "Average number of busy cores: " << avgCoreBusy << endl;
	cout << "SSD utilization: " << avgSSDBusy << endl;

	return 0;
}