#include <iostream>
#include<conio.h>
#include <iomanip>
#define MAX 100
using namespace std;

 void swap(int &x, int &y)
{
    int tmp=x;
    x=y;
    y=tmp;
}
 void printList(int a[], int &n)
{
    cout <<"your array is " <<endl;
    cout <<"Position:"<<setw(10);
    for (int i = 0; i < n; i++)
    {
        cout <<i<<setw(10);
    }
    cout <<endl <<"a[i]:"<<setw(10);
    for (int i = 0; i < n; i++)
    {
        cout <<a[i]<<setw(10);
    }
        
    cout <<endl;
}
void counting_Sort(int a[],int n)
{
    int max=0;
    for (int i=0;i<n;i++)
    {
        max = max<a[i] ? a[i]: max;
    }
    int *b;
    b = new int[max + 1];
    memset(b, 0, sizeof(b));
    for (int i=0;i<n;i++)
    {
       b[a[i]]++;
    }
    cout <<"Count Arr:\n";
    printList(b,max);
    for (int i=1;i<n;i++)
        a[i]=a[i]+a[i-1];
    int *c=new int [n+1];
    for (int i=0;i<n;i++)
    {
        c[b[a[i]]] = a[i];
        b[a[i]]--;
    }
    printList(c,n);
}

int main ()
{
    int a[MAX],b[MAX],n,choose;
    
    do
    {
        system("cls");
        cout 
            <<"\n1/Input arr"
            <<"\n2/Print list"
            <<"\n3/Using Counting Sort"
            <<"\n11/Exit!"
            <<"\nYour chosse: "<<endl;
        cin >> choose;
        switch (choose)
        {
            case 1:
            {
                cout <<"Input n:";
                cin >>n;
                for (int i=0; i<n; i++)
                cin >>a[i];
                printList(a,n);
                break;
            }
            case 2:
            {
                printList(a,n);
                break;
            }
            case 3:
            {
                cout <<"\nArr:\n";
                printList(a,n);
                copy (a,a+n,b);
                counting_Sort(b,n);
                break;
            }
            case 4:
            {
                
            }
             case 5:
            {
                
            }
             case 6:
            {
                
            }
             case 7:
            {
                
            }
            case 8:
            {
                
            }
        }
        system("pause");
        _getch();
    }while (choose <11);
}