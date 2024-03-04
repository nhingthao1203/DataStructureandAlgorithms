#include <iostream>
using namespace std;
struct Node
{
	int info;
	Node* link;
};
class SinglyList
{
public:
	Node* first, * last;
	void init()
	{
		first = NULL;
	}
	void addElementAtTheBeginning(int x)
	{
		Node* p;
		p = new Node;
		p->info = x;
		p->link = first;
		first = p;
	}
	void displayList()
	{
		Node* p;
		p = first;
		while (p != NULL)
		{
			cout << p->info << " ";
			p = p->link;
		}
	}
	void findElementInList(int x)
	{
		Node* p;
		p = first;
		while (p != NULL)
		{
			if (p->info == x)
				cout << p->info;
			p = p->link;
		}
	}
	void removeFirstElement(int x)
	{
		Node* p;
		p = new Node;
		p->info = x;
		p->link = NULL;
		if (first == NULL) //Don't have last element 
			first = p;
		else
		{
			Node* q = first;
			while (q->link != NULL)
				q = q->link;
			q->link = p;
		}
	}
};
