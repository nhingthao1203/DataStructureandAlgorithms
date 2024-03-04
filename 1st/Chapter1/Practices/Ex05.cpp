#include <iostream>
#define MAX 100

using namespace std;

int a[MAX]={0,1,2,3,4};
int sp,n,x;


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
void show (int a[],int sp)
{
    if (checkEmpty(a,sp))
        cout <<"\nStack is emty";
    else 
    {
        cout <<"\nYour stack\n";
        for (int i=0;i<n;i++)
             cout << a[i]<<"\t";
        cout <<endl;

    }
}
void push_back(int a[], int& sp, int& n, int x)
{
    if (!checkFull(a,sp))
    {
        a[++sp]=x;
        n++;
        show(a, sp);

    }
}
void pop_back(int a[], int& sp, int& n, int x)
{
    if (!checkEmpty(a,sp))
    {
        x=a[sp--];
        n--;
        cout << "\nYour stack after pop the last in element";
        show(a,sp);
    }
}

int main()
{
    init(a,sp);
    do {
        cout <<"Input element push in stack(input -1 for stop): \n";
        cin >>x;
        if (x!=-1)
        push_back(a,sp,n, x);
    }while (x!=-1);
    while (checkEmpty){
        pop_back(a,sp,n,x);
        //cout <<endl<<i<<"\t";

    }
        
    return 0;
    system("pause");
    //show(a,sp);

}