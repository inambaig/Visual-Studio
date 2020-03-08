#include <iostream>
#include <cstring>
#include <cstdlib>
#include <fstream>
using namespace std;

void displayBackOrders();
void insertPQ(int, int, bool);
void deletePQ();
void displayPQ();


int main()
{
	int ch, data, RushState, cost;
	double maxP = 0, minP = 0;
	int TotalWidgets = 125; //Not sure what this number is supposed to be, so I set it to 125

	//Menu
	do
	{
		//Display total number of widgets on hand
		//Their cost to the warehouse with the base price and with the amount of widgets on hand
		//Maximum and Minimum profit possible with the amount of widgets on hand
		cost = TotalWidgets * 50;
		maxP += cost * .80;
		minP = cost;
		//Orders are filled in first come first serve basis with exception of rush and back orders
		//use enum for rush status
		cout << "Total Number of Widgets in the warehouse are " << TotalWidgets << "\n"
			<< "Cost to warehouse: " << cost << "\n"
			<< "Max profit/Min profit: " << maxP << "/" << minP << "\n\n"
			<< "1) Receive orders\n"
			<< "2) Print back orders\n"
			<< "3) Close for a day\n"
			<< "4) Exit\n"
			"Enter your choice : " << endl;
		cin >> ch;

		switch (ch)
		{
			//Receive new orders
		case 1:
			//Assign number to each new order
			//number of widget ordered and rush status are entered by a user
			//extreme rush orders - filled before  any other order
			//expedite rush orders - filled before rush and no rush, but after extreme rush orders
			//back ordered orders - filled as expedite rush orders
			cout << "Enter Number of Widgets: " << endl;
			cin >> data;
			cout << "Enter its RushState (Standard Order = 0, ExpediteRushOrders = 2, ExtremeRushOrders = 3): " << endl;
			cin >> RushState;

			if (TotalWidgets - data >= 0)
			{
				TotalWidgets -= data;
			}
			else if (TotalWidgets - data < 0)
			{
				insertPQ(TotalWidgets, RushState, true);
				RushState = 1;
				data = data - TotalWidgets;
				TotalWidgets = 0;
			}

			insertPQ(data, RushState, false);
			break;

			//Display back orders only
		case 2:
			//Print back orders
			displayBackOrders();
			system("Pause");
			break;

			//Display orders
		case 3:
			//Show # orders processed w/ total cost, total profit, total cost to consumer
			//Show list of back orders and store them in a file
			//Show inventory on hand after processing
			//Show list of processed orders in order they will be shipped. Include info:
			//Order number, rush status, total quantity shipped, total quantity ordered,
			//number of units on back order, % of markup, % of discount, total cost to a customer
			//broken down by batch price, total cost, amount of markup, amount of discount, and warehouse profit.
			displayPQ();
			deletePQ();
			system("Pause");
			break;

			//Exit
		case 4:
			cout << "Exit" << endl;
			break;

			//default case
		default:
			cout << "Invalid entry. Please try again." << endl;
		}

	} while (ch != 4);

	return 0;
}

//Rush enum
enum RushStatus
{
	//Assign priority to types of orders
	ExtremeRushOrders = 3,
	ExpediteRushOrders = 2,
	backOrderedOrders = 1,
	StandardOrders = 0
};

//Struct for heap
struct node
{
	int OrderNumber;
	int data;
	int Cost;
	RushStatus RushState;
	int Profit;
	int Discount;
	struct node *next;
};
node *front = NULL;

//Function for inserting widget orders
void insertPQ(int data, int RushState, bool checkBack)
{
	node *temp, *ptr;
	temp = new node;
	temp->data = data;
	//Base price of 50
	temp->Cost = 50 * temp->data;

	if (front == NULL)
		temp->OrderNumber = 1;
	else
		temp->OrderNumber = front->OrderNumber + 1;

	//Store values for profit/discount based on type of order
	if (RushState == 3)
	{
		temp->RushState = ExtremeRushOrders;
		temp->Profit = 80;
		temp->Discount = 0;
	}
	else if (RushState == 2)
	{
		temp->RushState = ExpediteRushOrders;
		temp->Profit = 60;
		temp->Discount = 0;
	}
	else if (RushState == 1)
	{
		temp->RushState = backOrderedOrders;
		temp->Profit = 0;
		temp->Discount = 20;
	}
	else if (RushState == 0)
	{
		temp->Profit = 40;
		temp->RushState = StandardOrders;
		temp->Discount = 0;
	}
	//Check if part of the order is back ordered and apply discount as needed
	if (checkBack)
	{
		temp->Discount = 20;

		if (RushState == 0)
			temp->Discount = 10;
	}
		temp->next = front;
		front = temp;

}

//Delete function
void deletePQ()
{
	node *temp;

	if (front == NULL)
		cout << "No orders to display\n";
	else
	{
		temp = front;

		while (front != NULL)
		{
			temp = front;
			front = front->next;
			free(temp);
		}
	}
}

//Function for displaying widget orders
void displayPQ()
{
	node *ptr;
	ptr = front;
	int NumberOfOrder = 0, totalCost = 0, totalProfit = 0, TotalCostToCustomer = 0, TotalWidgetsShipped = 0, TotalWidgetsRemaining = 0, OrdersRemaining = 0;

	if (front == NULL)
		cout << "Queue is empty\n";
	else
	{
		cout << "OrderNumber\tNumberOfWidgets\t\t    RushState\t\t    TotalProfit\t\tTotalDiscount\t   Cost" << endl;

		while (ptr != NULL)
		{
			//Print order info if not a back order
			if (ptr->RushState != backOrderedOrders)
			{
				cout << ptr->OrderNumber << "\t\t\t" << ptr->data << "\t\t\t" << ptr->RushState << "\t\t\t" << ptr->Profit << "%\t\t\t" << ptr->Discount << "%" << "\t   " << ptr->Cost + (ptr->Cost*(ptr->Profit / 100)) - (ptr->Cost*(ptr->Discount / 100)) << endl;
				NumberOfOrder++;
				TotalWidgetsShipped += ptr->data;
				totalCost += ptr->Cost;
				TotalCostToCustomer += ptr->data * 30;
				totalProfit += ptr->Profit;
			}
			else
			{
				TotalWidgetsRemaining += ptr->data;
				OrdersRemaining++;
			}

			ptr = ptr->next;
		}

		//Print back orders
		cout << "\n\nBack Orders" << endl;
		displayBackOrders();
		//Print data from day
		cout << "\nNumber of orders processed: " << NumberOfOrder <<
			"\nNumber of orders remaining: " << OrdersRemaining <<
			"\nTotal number of widgets shipped: " << TotalWidgetsShipped <<
			"\nBack ordered widgets: " << TotalWidgetsRemaining <<
			"\nTotal cost: " << totalCost <<
			"\nTotal cost to customer: " << TotalCostToCustomer << endl;
		//"\nTotal Profit: " << totalProfit / NumberOfOrder << "%" << endl;
	}
}

//Function for displaying back orders
void displayBackOrders()
{
	node *ptr;
	ptr = front;
	ofstream myfile;
	myfile.open("BackOrders.txt");

	if (front == NULL)
		cout << "Queue is empty\n";
	else
	{
		//Print widget order details to console and file
		cout << "OrderNumber\tNumberOfWidgets\t\t    RushState\t\t    TotalProfit\t\tTotalDiscount\t   Cost" << endl;
		myfile << "OrderNumber\tNumberOfWidgets\t\t    RushState\t\t   TotalProfit\t\tTotalDiscount\t   Cost" << endl;

		while (ptr != NULL)
		{
			//Print back ordered widget details to console and file
			if (ptr->RushState == backOrderedOrders)
			{
				cout << ptr->OrderNumber << "\t\t\t" << ptr->data << "\t\t\t" << ptr->RushState << "\t\t\t" << ptr->Profit << "%\t\t\t" << ptr->Discount << "%" << "\t   " << ptr->Cost + (ptr->Cost*(ptr->Profit / 100)) - (ptr->Cost*(ptr->Discount / 100)) << endl;
				myfile << ptr->OrderNumber << "\t\t\t" << ptr->data << "\t\t\t" << ptr->RushState << "\t\t\t" << ptr->Profit << "%\t\t\t" << ptr->Discount << "%" << "\t   " << ptr->Cost + (ptr->Cost*(ptr->Profit / 100) - (ptr->Cost*(ptr->Discount / 100))) << endl;
			}
			ptr = ptr->next;
		}
		cout << endl;
	}
}