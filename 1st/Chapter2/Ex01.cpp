#include <iostream>
#include<conio.h>
#define MAX 100
using namespace std;

struct node 
        {
            int info;
            node *left;
            node *right;
        };
        int sp;
        void init ()
        {
            sp = -1;
        }
        bool isEmpty()
        {
            if (sp == -1)
                return true;
            return false; 
        }
        bool isFull()
        {
            if (sp==MAX-1)
                return true;
            return false;
        }
        node *createNumber(int x)
        {
            node* tmp = new node;
            tmp -> link =NULL;
            tmp ->info =x;
            return tmp;
        }
        node* push_back(node* l,int x)
        {
            if (l == NULL)
            {
                node* q=createNumber(x);
                return q;
            }
            node * p =l;
            while (p->link!=NULL)
            {
                p = p->link;
            }
            node *tmp=new node();
            //tmp->info=x;
            p->link=NULL;
            p->info =x;
            return l;
        }
        node *pop_back(node *l)
        {
            node *p=l;
            node *q=NULL;
            while (p->link!=NULL)
            {
                q = p;
                p= p->link;

            }
            q-> link=NULL;
            return l;
            delete p;
        }
        void printList(node*l)
        {
            node *p=l;
            while (p->link!=NULL)
            {
                cout <<p->info<<"\t";
                p=p->link;
            }
            cout <<endl;
        }
    void InsertionSort(node*l)
    {
        int 
    }


int main ();
{
    int tmp;
    int choose;
    do
    {
        cout <<"Input number: ";
        cin >> tmp;
        if (tmp>=0)
            first = push_back(first,tmp);
    }while(tmp>=0);
    printList(first);
    
}