#include <iostream>
#define MAX 100

using namespace std;

int front, rear;

struct number
{
	int integer;
	number* next;
};

number* createNumber(int x)
{
	number* temp = new number;
	temp->next = NULL;
	temp->integer = x;
	return temp;
}

bool checkEmpty(int& front, int& rear)
{
	if (front == -1)
		return true;
	return false;
}
bool checkFull(int front, int rear)
{
	if ((rear - front == MAX - 1) || (rear - front == -1))
		return true;
	return false;
}
void init()
{
	front = -1;
	rear = -1;
}
void printList(number* l)
{
	number* p = l;
	while (p != NULL)
	{
		cout << p->integer << "\t";
		p = p->next;
	}
	cout << endl;
}

number* addEnd(number* l, int x, int& front, int& rear)
{
	if (checkFull(front, rear) == true) cout << "Queue full";
	else
	{
		if (checkEmpty(front, rear))
			front = 0;
		if (rear == MAX - 1)
			rear = -1;
		rear++;
		if (l == NULL)
		{
			number* q = createNumber(x);
			return q;
		}
		number* p = l;
		while (p->next != NULL)
		{
			p = p->next;
		}
		number* temp = new number;
		temp->integer = x;
		temp->next = NULL;
		p->next = temp;
		cout << "pushed :" << x << endl;
		return l;

	}
}
number* deleteStart(number* l, int& front, int& rear)
{
	if (front != -1)
	{
		if (front == rear)
		{
			rear = -1;
			front = -1;
		}
		else {
			front++;
			if (front > MAX - 1) front = 0;
		}
		number* p = l;
		l = l->next;
		l = l->next;
		cout << "\ndelete successful !" << endl;
		return l;
		delete p;

	}
}



int main()
{
	int tmp;
	init();
	number* first = NULL;
	do {
		cout << "Inpt element >=0: ";
		cin >> tmp;
		if (tmp >= 0 && !checkFull(front, rear))
		{
			first = addEnd(first, tmp, front, rear);
		}
	} while (tmp >= 0 && !checkFull(front, rear));
	printList(first);
	while (!checkEmpty(front, rear))
	{
		cout << "Your stack after pop the last element:";
		deleteStart(first, front, rear);
		printList(first);
	}

	system("pause");
	return 0;
}