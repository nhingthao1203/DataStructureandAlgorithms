#include <iostream>
#include<conio.h>
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
    for (int i = 0; i < n; i++)
        cout <<a[i]<<"\t";
    cout <<endl;
 }
 void SelectionSort(int b[],int n)
 {
    int min;
    for (int i = 0; i < n-1; i++)
    {
        min = i;
        for (int j = i+1; j < n; j++)
        if (b[j]<b[min]) 
            min =j;
        swap(b[min],b[i]);
        printList(b,n);
    }  
 }
 void InsertionSort(int b[], int n)
{
    int x,j;
    for (int i = 1; i < n; i++)
    {
        x=b[i];
        j = i-1;
        while (0<=j && x<b[j])
        {
            b[j+1]=b[j];
            printList(b,n);
            j--;
        }
        b[j+1]=x;
        printList(b,n);

    }
}
void InterchangeSort(int b[],int n)
{
    for (int i=0;i<n-1;i++)
        for (int j=i+1;j<n;j++)
            if (b[i]>b[j])
            {
                swap(b[i],b[j]);
                printList(b,n);
            }
}
void BubbleSort(int b[],int n)
{
    for (int i=0;i<n-1;i++)
        for (int j=n-1;j>i;j--)
        if (b[j-1]>b[j])
            {
                swap(b[j-1],b[j]);
                printList(b,n);
            }
}
void QuickSort(int b[],int left, int right,int n)
{
    int x = b[(left +right)/2];
    cout <<"x="<<x<<endl;
    int i=left;
    cout <<"i="<<i<<endl;
    int j =right;
    cout <<"j="<<j<<endl;
    while (i<j)
    {
        while (b[i]<x) 
        {
            i++;
            cout <<b[i] <<"<" << x <<"i + 1: " <<i<< endl;
            
        }
        while (b[j]>x) 
        {
            j--;
            cout <<b[j] <<">" << x <<"j - 1: " <<j<< endl;
            
        }
        if (i<=j) 
        {
            cout <<i<<"<="<<j<<endl;
            cout <<"Swap "<<b[i]<<" & " <<b[j]<<" at position "<<i<<", "<<j<<endl;
            swap(b[i],b[j]);
            printList(b,n);
            i++;
            j--;
        }
        if (left <j) QuickSort(b,left,j,n);
        if (i<right) QuickSort(b,i,right,n);
    }
}
void shift (int a[], int i,int n) 
{
    int j=2*i+1;
    if (j>=n)
    return;
    if (j+1<n && a[j]<a[j+1]) 
        j++;
    if (a[i]>=a[j]) return;
    else
    {
        int x=a[i];
        a[i] =a[j];
        a[j]=x;
        shift(a,j,n);
    }
}

void HeapSort(int b[],int n)
{
    int i=n/2;
    while (i>=0) //creat heap 
    {
        shift(b,i,n-1); 
        i--;
    }
    int right =n-1;//right is the last Heap to check
    while (right >0) 
    {
        swap(b[0],b[right]); 
        printList(b,n);
        right --;
        if (right >0)
        shift (b,0,right);
    }
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
            <<"\n3/Using SelectionSort"
            <<"\n4/Using InsertionSort "
            <<"\n5/Using InterchangeSort"
            <<"\n6/Using BubbleSort"
            <<"\n7/Using QuickSort"
            <<"\n8/Using HeapSort"
            <<"\n9/Search element x in Arr (by sequential sear)"
            <<"\n10/Search element x in Arr (by BST)"
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
                SelectionSort(b,n);
                break;
            }
            case 4:
            {
                cout <<"\nArr:\n";
                printList(a,n);
                copy (a,a+n,b);
                InsertionSort(b,n);
                break;
            }
             case 5:
            {
                cout <<"\nArr:\n";
                printList(a,n);
                copy (a,a+n,b);
                InterchangeSort(b,n);
                break;
            }
             case 6:
            {
                cout <<"\nArr:\n";
                printList(a,n);
                copy (a,a+n,b);
                BubbleSort(b,n);
                break;
            }
             case 7:
            {
                cout <<"\nArr:\n";
                printList(a,n);
                copy (a,a+n,b);
                QuickSort(b,0,n-1,n);
                break;
            }
            case 8:
            {
                cout <<"\nArr:\n";
                printList(a,n);
                copy (a,a+n,b);
                HeapSort(b,n);
                break;
            }
        }
        system("pause");
        _getch();
    }while (choose <11);
}