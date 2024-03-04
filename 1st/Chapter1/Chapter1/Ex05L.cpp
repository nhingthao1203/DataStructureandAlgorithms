#include <iostream>
#define MAX 100

struct node
{
    int info;
    node* link;
};
using namespace std;

void init(int a[], int &sp) 
{
    sp=-1;
    /*cout <<"Input n: ";
    cin >>n;*/
}
bool checkEmpty(int a[], int &sp)
{
    if (sp==-1)
        return true;
    return false;
}
bool checkFull(int a[],int sp)
{
    if(sp==MAX-1)
        return true;
    return false;
}
node* createNumber(int x)
{
    node* temp = new node;
    temp ->link=NULL;
    temp -> info =x;
    return temp;
}
void printList (node*l)
{
    node* p=l;
    while (p!=NULL)
    {
        cout << p->info << "\t";
        p=p->link;
    }
    cout <<endl;
}
node* push_back(node* l, int x) {
	if (l == NULL) {
		node* q = createNumber(x);
		return q;
	}
	node* p = l;
	while (p->link != NULL) {
		p = p->link;
	}
	node* temp = new node;
	temp->info = x;
	temp->link = NULL;
	p->info = temp->info;
	return l;
}

node* pop_back(node *l) 
{
    node*p =l;
    node *q=NULL;
}

int main()
{
    int tmp;
    node* first =NULL;
    do {
		cout << "Input element: ";
		cin >> tmp;
		if (tmp != 0) {
			first = push_back(first, tmp);
		}
	} while (tmp != 0);
	printList(first);
    return 0;
    system("pause");
}