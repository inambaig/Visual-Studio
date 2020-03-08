#include<iostream>
#include<string>
using namespace std;


struct Profile{
	string name;
	int age;
	string state;

	Profile()
	{
		name = "";
		age = 0;
		state = "";
	}
	Profile(string name, int age, string state)
	{
		this->name = name;
		this->age = age;
		this->state = state;
	}

	bool operator==(const Profile& lhs){
		return lhs.name == name;
	}
};

ostream& operator << (ostream & output, Profile p) {
	output << p.name;
	return output;
}

template <class T>
class Twitter
{
	T *user[5];
	int count = 0;
	
public:
	Twitter()
	{
		for (int i = 0; i < 5; i++)
		{
			user[i] = NULL;
		}
		
	}
	void addFollower(T *follower)
	{
		//for (int i = 0; i < 5; i++)
		//{
			if (count < 5)//(user[i] == NULL)
			{
				user[count] = follower;
				cout << "Follower is added" << endl;
				count++;
				return;
			}
		//}			
		cout << "\nlimit is reached cannot add more followers\n" << endl;
	}
	void removeFollower(T *follower)
	{
		
		for (int i = 0; i < count; i++)
		{
			//cout << "return for == operator: " << (*follower==*user[i]) << endl;
			if (*user[i] == *follower )
			{
				user[i] = NULL;
				cout << "Follower is removed" << endl;
				return;
			}
		}

		cout << *follower <<" is not a follower of this user" << endl;
	}
	void printFollowers()
	{
		for (int i = 0; i < 5; i++)
		{
			if (user[i] != NULL)
			{
				cout << "User "<< i+1 <<" : ";
				cout << *user[i];
				cout << endl;
			}
		}
	}

};

int main()
{


	string name;
	int age,c = 0;
	string state;
	char status;
	Twitter<Profile> *User1 = new Twitter<Profile>();
	Twitter<string> *User2 = new Twitter<string>();;

	while (c!=1)
	{
		string *name2 = new string ("");
		cout << "do you want to set the profile of the user? ";
		cin >> status;

		if (status == 'y' || status == 'Y')
		{
			cout << "Enter user name: ";
			cin >> name;
			cout << "what is user's age: ";
			cin >> age;
			cout << "which state do user live in: ";
			cin >> state;
		}
		else
		{
			cout << "Enter user name: ";
			cin >> *name2;
		}

		Profile *follower = new Profile(name, age, state);

		if (status == 'y' || status == 'Y')
		User1->addFollower(follower);					//adding follower to the user 1
		else 
		User2->addFollower(name2);						//adding follower to the user 2

		cout << "\nFollowers of User 1 " << endl;
		User1->printFollowers();							//printing the followers of user 1
		cout << "\nFollowers of User 2 " << endl;
		User2->printFollowers();							//printing the followers of user 2
		
		cout << "press 1 to quit" << endl;
		cin >> c;

	}
	
	int d = -1;
	while (d != 1)
	{
		string name2 = "";
		cout << "enter name for the follower you want to remove: ";
		cin >> name;
		
		Profile follower2(name, 0, "");

		cout << "which user you chose ( 1 or 2 ): ";
		cin >> c;

		if (c == 1)
			User1->removeFollower(&follower2);
		else if (c == 2)
			User2->removeFollower(&name2);

		cout << "press 1 to quit" << endl;
		cin >> d;

		cout << "\nFollowers of User 1 " << endl;
		User1->printFollowers();							//printing the followers of user 1
		cout << "\nFollowers of User 2 " << endl;
		User2->printFollowers();							//printing the followers of user 2

	}

}