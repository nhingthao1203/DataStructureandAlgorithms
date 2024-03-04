#include <iostream>
#define MAX 100

using namespace std;

int a[MAX];
int sp,n, x;


void init(int a[], int &sp) 
{
    sp=-1;
    cout <<"Convert a decimal number to a binary number x= ";
    cin >>x;
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
/*void show (int a[],int sp)
{
    if (checkEmpty(a,sp))
        cout <<"\nStack is emty";
    else 
    {
        cout <<"\nYour stack";
        for (int i=0;i<n;i++)
             cout << a[i]<<"\t";

    }
}*/
void push_back(int a[], int& sp, int& n, int x)
{
    if (!checkFull(a,sp))
    {
        a[++sp]=x;
        n++;
        //show(a, sp);

    }
}
void pop_back(int a[], int& sp, int& n, int x)
{
    if (!checkEmpty(a,sp))
    {
        //cout << "\nThe element pop_back:";
        cout <<a[sp];
        x=a[sp--];
        --n;
        //show(a,sp);
    }
}
void tranBinary()
{
    int tmp;
    while (x!=0)
    {
        tmp = x % 2;
        x = x / 2;
        push_back(a,sp,n,tmp);
    }

}

int main()
{
    
    init(a,sp);
    cout <<x<<" in binary number:\n";
    tranBinary();
    for (int i=sp;i>=0;i--)
        pop_back(a,sp,n,x);
    
    //show(a,sp);

}