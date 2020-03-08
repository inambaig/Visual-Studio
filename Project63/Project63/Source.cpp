#include <iostream>
#include <string>
#include <queue> 
using namespace std;

//Data type for each event to be occur
struct Event
{
	string name;
	int value;
	int PID;
	bool IsInteractive;
	int completion;
	void Display()
	{
		cout << PID << " " << name << " " << value << " " << completion << endl;
	}
};

//1st list containing Events for A process

struct node
{
	Event E;
	node *next;
};

class List_Events
{
private:
	node *head, *tail;
public:
	List_Events()
	{
		head = NULL;
		tail = NULL;
	}

	void add_node(Event n)
	{
		node *tmp = new node;
		tmp->E = n;
		tmp->next = NULL;

		if (head == NULL)
		{
			head = tmp;
			tail = tmp;
		}
		else
		{
			tail->next = tmp;
			tail = tail->next;
		}
	}
	void display()
	{
		struct node* ptr;
		ptr = head;
		while (ptr != NULL)
		{

			ptr->E.Display();
			ptr = ptr->next;
		}
	}
	//returns Event on top of list
	Event getEvent()
	{
		struct node* ptr;
		ptr = head;
		if (head == NULL)
		{
			Event tmp;
			tmp.name = '\0';
			return tmp;
		}
		else
		{
			return ptr->E;
		}
	}
	//remove events form list
	void removeEvent()
	{
		node *tmp = new node;
		tmp = head;
		head = head->next;
		delete tmp;
	}
	void setEcompl(int comp)
	{
		head->E.completion = comp;
	}

	bool empty()
	{
		if (head == NULL)
		{
			//cout<<"empty"<<endl;
			return true;
		}
		return false;
	}

};

//list of process , which contains a list of events in it
struct Process
{
	List_Events list;
	int Sq;
	Process *next;
	void Display()
	{
		cout << Sq << endl;
		list.display();
	}
};

class List_Process
{
private:
	Process *head, *tail;
	int size;
public:
	List_Process()
	{
		head = NULL;
		tail = NULL;
		size = 0;
	}


	void add_node(int id, List_Events L)
	{
		Process *tmp = new Process;
		tmp->Sq = id;
		tmp->list = L;
		tmp->next = NULL;

		if (head == NULL)
		{
			head = tmp;
			tail = tmp;
		}
		else
		{
			tail->next = tmp;
			tail = tmp;
		}
		size++;
	}
	void display()
	{
		struct Process* ptr;
		ptr = head;
		while (ptr != NULL)
		{

			ptr->Display();
			ptr = ptr->next;
		}
	}
	//searching a event of a process
	Event search(int sq)
	{

		struct Process* ptr;
		ptr = head;
		while (ptr != NULL)
		{
			if (ptr->Sq == sq)
			{
				return ptr->list.getEvent();
			}
			ptr = ptr->next;
		}
		Event tmp;
		tmp.name = '\0';
		return tmp;
	}
	void remove(int sq)
	{
		struct Process* ptr;
		ptr = head;
		while (ptr != NULL)
		{
			if (ptr->Sq == sq)
			{
				//	cout<<"remove from:"<<sq<<endl;
				ptr->list.removeEvent();
				if (ptr->list.empty())
				{
					removeSq(sq);
				}
			}
			ptr = ptr->next;
		}
	}
	//
	void setCompletion(int sq, int comp)
	{
		struct Process* ptr;
		ptr = head;
		while (ptr != NULL)
		{
			if (ptr->Sq == sq)
			{
				return ptr->list.setEcompl(comp);
			}
			ptr = ptr->next;
		}
	}
	void removeSq(int sq)
	{
		size--;
		if (head->Sq == sq)
		{
			Process *temp = new Process;
			temp = head;
			head = head->next;
			delete temp;
			//	cout<<"removeing sq: 1st: "<<sq<<endl;

		}
		else if (tail->Sq == sq)
		{
			Process *current = new Process;
			Process *previous = new Process;
			current = head;
			while (current->next != NULL)
			{
				previous = current;
				current = current->next;
			}
			tail = previous;
			previous->next = NULL;
			delete current;
			//cout<<"removeing sq: last: "<<sq<<endl;
		}
		else
		{
			Process *current = new Process;
			Process *previous = new Process;
			current = head;
			for (int i = 1; i<sq; i++)
			{
				previous = current;
				current = current->next;
			}
			previous->next = current->next;
			//	cout<<"removeing sq: mid: "<<sq<<endl;


		}
		//cout<<"head: "<<head<<endl;

	}

	bool empty()
	{
		//	cout<<"empty bigger"<<endl;
		if (size == 0)
		{
			return true;
		}
		return false;
	}



};
//for displaying A queue
void showq(queue <int> gq)
{
	queue <int> g = gq;
	while (!g.empty())
	{
		cout << '\t' << g.front();
		g.pop();
	}
	cout << '\n';
}
// universal veriable 
List_Process a;
//a class routine to process Requests
class routine
{
public:
	int nfreecores;
	//queues
	queue <int> I;
	queue <int> NI;
	queue <int> ssd;
	bool ssdFree;
	float ssdAccess;
	float ssdTime;


	routine(int n)
	{
		nfreecores = n;
		ssdFree = true;
		ssdAccess = 0;
		ssdTime = 0;
	}
	//a function which process requests
	void processRequest(int seqno, int Ctime, bool i)
	{
		//cout<<"Time: "<<Ctime<<"  ";
		Event current;
		current = a.search(seqno);
		//cout<<"name: "<<current.name<<endl;
		if (current.name == "START")
		{
			cout << "Process is Loaded in Memory  PID: " << current.PID << " at Time: " << Ctime << endl;
			arrival(Ctime, seqno);
		}
		else if (current.name == "CORE")
		{
			if (current.completion != 0 && current.completion >= Ctime)
			{
				a.remove(seqno);

				core_release(seqno, Ctime);
			}
			else
			{
				core_request(Ctime, seqno, i);
			}

		}
		else if (current.name == "SSD")
		{
			if (current.completion != 0 && current.completion >= Ctime)
			{
				a.remove(seqno);
				ssd_release(seqno, Ctime);
			}
			else
			{
				ssd_request(Ctime, seqno);
			}
		}
		else if (current.name == "TTY")
		{
			if (current.completion != 0 && current.completion >= Ctime)
			{
				a.remove(seqno);
				user_release(seqno, Ctime);
			}
			else
			{
				user_request(Ctime, seqno);
			}
		}

		return;
	}
	void arrival(int Ctime, int seqno)
	{
		Event current;
		current = a.search(seqno);
		//mark process non-interactive
		current.IsInteractive = false;
		a.remove(seqno);
		//process first request of new process
		processRequest(seqno, Ctime, false);
	}
	void core_request(int Ctime, int seqno, bool isinteract)
	{
		//cout<<"coreRequest "<<Ctime<<endl;
		if (nfreecores > 0)
		{
			nfreecores--;
			//schedule completion at time
			//current_time + how_long
			//for process seqno;
			Event current;
			current = a.search(seqno);
			int completionTime = Ctime + current.value;
			a.setCompletion(seqno, completionTime);
			current = a.search(seqno);
			//current.Display();


		}
		else
		{
			if (isinteract)
			{

				//queue proc_id in i_queue
				I.push(seqno);
				return;
			}
			else
			{

				//queue proc_id in ni_queue
				//cout<<"NI"<<endl;
				NI.push(seqno);
				return;
			} // inner if
		} // outer if
	}
	void core_release(int seqno1, int Ctime)
	{
		//cout<<"coreRelease "<<Ctime<<endl;
		if (!I.empty())
		{
			//pop first request in i_queue
			//schedule its completion at
			//current_time + how_long;
			int seqno = I.front();
			I.pop();

			Event current;
			current = a.search(seqno);
			int completionTime = Ctime + current.value;
			a.setCompletion(seqno, completionTime);
			current = a.search(seqno);
			NI.push(seqno);
			//current.Display();

		}
		else if (!NI.empty())
		{
			int seqno = NI.front();
			NI.pop();

			Event current;
			current = a.search(seqno);
			int completionTime = Ctime + current.value;
			a.setCompletion(seqno, completionTime);
			current = a.search(seqno);
			//current.Display();
		}
		else
		{
			nfreecores++;
		} //if
		//process next process request;
		processRequest(seqno1, Ctime, false);
	} // core_release

	void ssd_request(int Ctime, int seqno)
	{
		if (ssdFree)
		{
			//cout<<"SSD Request"<<endl;
			ssdFree = false;
			Event current;
			current = a.search(seqno);
			if (current.value>0)
			{
				int completionTime = Ctime + current.value;
				ssdTime += current.value;
				a.setCompletion(seqno, completionTime);
				current = a.search(seqno);
			}
			else
			{
				a.remove(seqno);
				ssd_release(seqno, Ctime);
			}
			ssdAccess++;
		}
		else
		{
			ssd.push(seqno);

		} // if
	} // ssd_request

	void ssd_release(int seqno1, int Ctime)
	{
		//cout<<"SSD Release"<<endl;
		if (!ssd.empty())
		{
			int seqno = ssd.front();
			ssd.pop();
			ssdAccess++;
			//cout<<"SSD"<<endl;
			//	showq(ssd);
			Event current;
			current = a.search(seqno);
			if (current.value>0)
			{

				int completionTime = Ctime + current.value;
				ssdTime += current.value;
				a.setCompletion(seqno, completionTime);
				current = a.search(seqno);
				NI.push(seqno);
			}
			else
			{
				a.remove(seqno);
				ssd_release(seqno, Ctime);

			}
		}
		else
		{
			ssdFree = true;
		} // if
		processRequest(seqno1, Ctime, false);
	} // ssd_release

	void user_request(int Ctime, int seqno)
	{
		//schedule completion at time
		//current_time + how_long
		//for process process_id;
		//cout<<"user request"<<endl;
		Event current;
		current = a.search(seqno);
		int completionTime = Ctime + current.value;
		a.setCompletion(seqno, completionTime);
		current = a.search(seqno);
	} // user_request 	
	void user_release(int seqno, int Ctime)
	{

		//cout<<"user rlease"<<endl;

		//isinteract = interactive;
		//process next process request;
		processRequest(seqno, Ctime, true);
	} // user_release
};

int main()
{
	Event E;

	int nfreecores = 0;
	cin >> E.name;
	cin >> nfreecores;
	cin >> E.name;
	int sq = 0;
	//Saving whole process in list of list
	while (true)
	{

		if (E.name == "END")
		{
			break;
		}
		else
		{
			cin >> E.value;
			if (E.name == "START")
			{
				Event pid;

				List_Events tmp;

				Event s;
				string some;
				cin >> some;
				cin >> s.PID;
				E.PID = s.PID;
				tmp.add_node(E);
				while (true)
				{
					cin >> s.name;
					if (s.name == "END" || s.name == "START")
					{
						E.name = s.name;
						break;
					}
					else
					{
						cin >> s.value;
						tmp.add_node(s);
					}
				}
				a.add_node(sq++, tmp);

			}
		}
	}
	//all events are saved in a list displaying that
	//a.display();

	//queues


	routine obj(nfreecores);

	int CurrentTime = 0;


	while (true)
	{

		for (int i = 0; i<sq; i++)
		{
			if (a.empty())
			{
				break;
			}
			Event current;
			current = a.search(i);
			//current.Display();

			if (current.name == "START")
			{
				//cout<<"start"<<endl;
				a.setCompletion(i, current.value);
			}
			current = a.search(i);
			//cout<<"compare: "<<current.completion<<" "<<CurrentTime<<endl;
			if (current.completion == CurrentTime)
			{
				//cout<<"compare: "<<current.completion<<" "<<CurrentTime<<endl;
				obj.processRequest(i, CurrentTime, false);

			}


		}
		//cout<<"Queu"<<endl;
		//showq(obj.NI);
		if (a.empty())
		{
			//cout<<"END OF PROGRAM";
			break;
		}

		CurrentTime++;

	}
	cout << endl << endl << "\t Smmary" << endl;
	cout << "Total Simulation Time: " << CurrentTime << endl;
	cout << "Number of Pocesses that have completed: " << sq << endl;
	cout << "Total Number SSD accessed: " << obj.ssdAccess << endl;
	cout << "Average Number of Busy Cores : " << nfreecores << endl;
	cout << "SSD utilization: " << obj.ssdTime / obj.ssdAccess << endl;
	return 0;

}
