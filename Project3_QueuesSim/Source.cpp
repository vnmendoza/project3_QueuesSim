//Author: Victor Mendoza

#include <iostream>
#include <time.h>
using namespace std;

struct Node {
	int data;
	Node *next;
};
class Queue {
public:
	Node *front, *rear;
	Queue() { front = rear = NULL; }

	void insert(int n);
	void deleteitem();
	void display();
	~Queue();
};

void Queue::insert(int n) {
	Node *temp = new Node;
	if (temp == NULL) {
		cout << "Overflow" << endl;
		return;
	}
	temp->data = n;
	temp->next = NULL;

	//for first node
	if (front == NULL) {
		front = rear = temp;
	}
	else {
		rear->next = temp;
		rear = temp;
	}
	//cout << n << " has been inserted successfully." << endl;
}

void Queue::display() {
	if (front == NULL) {
		cout << "Underflow." << endl;
		return;
	}
	Node *temp = front;
	//will check until NULL is not found
	while (temp) {
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

void Queue::deleteitem()
{
	if (front == NULL) {
		cout << "underflow" << endl;
		return;
	}

	//cout << front->data << " is being deleted " << endl;
	if (front == rear)//if only one node is there
		front = rear = NULL;
	else
		front = front->next;
}

Queue ::~Queue()
{
	while (front != NULL)
	{
		Node *temp = front;
		front = front->next;
		delete temp;
	}
	rear = NULL;
}

using namespace std;

int main()
{
	Queue Q;
	srand(time(0));
	int min, ctmr, serviceMin, helped, lineLen, longestLine,\
		longestWait, m, n, t, timetoServ,ctmrNum;
	bool beingServed;
	float ave(0);
	min = ctmr = serviceMin = helped = beingServed = \
		lineLen = longestLine = longestWait = m = n = timetoServ = 0;
	ctmrNum = 1;
	n = 3;
	m = 4;
	t = 30;
	int addMin = rand() % n + 1;
	min += addMin;


	for (int i = 0; i <= t; i++)
	{
		if (i <= 15 || i >= t - 15)
		{
			cout << "\n \nMinute: " << i << endl;
		}
		serviceMin--;

		if (i == min)
		{
			ctmr++;
			int addMin = rand() % n + 1;
			min += addMin;
			if (i <= 15 || i >= t - 15)
			{
				cout << "Customer " << ctmr << " Call \n";
			}
			Q.insert(i);

		}

		if (serviceMin == 0)
		{
			beingServed = false;
			helped++;
			if (i <= 15 || i >= t - 15)
			{
				if (Q.front != NULL)
				{
					cout << "Customer " << helped << " Served \n";
					timetoServ = i - Q.front->data;
				}
			}
			
		}

		if (!beingServed && Q.front != NULL)
		{
			Q.deleteitem();
			addMin = rand() % m + 1;
			serviceMin = addMin;
			beingServed = true;
		}
		lineLen = ctmr - helped;
		if (serviceMin > longestWait)
		{
			longestWait = serviceMin;
		}
		if (lineLen > longestLine)
		{
			longestLine = lineLen;
		}
		ave += timetoServ;

	}
	ave /= helped;

	cout << "\n\nNumber of customers helped: " << helped << endl;
	cout << "Number of customers left: " << ctmr - helped << endl;
	cout << "Longest line: " << longestLine << " Customers \n";
	cout << "Longest wait: " << longestWait << " minutes \n";
	cout << "Average wait: " << ave << " minutes \n";



}
// FIX LONGEST WAIT 
//commit this