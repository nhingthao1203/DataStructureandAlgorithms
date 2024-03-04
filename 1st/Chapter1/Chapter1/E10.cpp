#include <iostream>
#define MAX 100

using namespace std;

int sp = -1;

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

number* addEnd(number* l, int x,int &sp)
{
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
	sp++;
	return l;
}
number* deleteEnd(number* l,int&sp, bool check)
{
	number* p = l;
	number* q = NULL;
	while (p->next != NULL) 
	{
		q = p;
		p = p->next;
	}
	cout << p->integer << "\t";
	q->next = NULL;
	if (check) cout << "\ndelete successful !" << endl;
	sp--;
	return l;
	delete p;
}
bool checkEmpty(int& sp)
{
	if (sp == -1)
		return true;
	return false;
}
bool checkFull(int sp)
{
	if (sp == MAX - 1)
		return true;
	return false;
}
void init()
{
	sp = -1;
}

void printList(number* l) 
{
	number* p = l;
	while (p != NULL) 
	{
		cout << p->integer << " ";
		p = p->next;
	}
	cout << endl;
}

int main()
{
	int tmp;
	int choose;
	int x;
	init();
	number* first = NULL;
	do {
		cout << "Inpt element >=0: ";
		cin >> tmp;
		if (tmp >= 0&&!checkFull(sp)) 
		{
			first = addEnd(first, tmp,sp);
		}
	} while (tmp >= 0&&!checkFull(sp));
	printList(first);
	while (!checkEmpty(sp))
	{
		cout << "Your stack after pop the last element:";
		deleteEnd(first,sp,true);
		printList(first);
	}
	//decimal to binary number
	{
		cout << "Input X:";
		cin >> x;
		init();
		int tm;
		while (x != 0)
		{
			tm = x % 2;
			x = x / 2;
			addEnd(first, tm, sp);
		}
		cout << "Decimal to binary number: ";
		while (!checkEmpty(sp))
		deleteEnd(first, sp,false);
		
	}
	//Hanoi tower
	
	system("pause");
	return 0;
}