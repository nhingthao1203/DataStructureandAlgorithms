#include<iostream>
#include<vector>

using namespace std;

int tam, n, choose;
vector <int> a;
void print_list(vector <int>a) 
{
    for (int i = 0; i < a.size();i++)
    cout << a[i] <<"  ";
    cout<<endl;
}
void bubbleSort(vector <int> &a) 
{
    for (int i = 0; i < a.size();i++)
        for (int j = a.size(); j>i;j--)
    if (a[j]<a[j-1])
    {
        int tam = a[j];
        a[j]=a[j-1];
        a[j-1]=tam;
        print_list(a);
    }
    cout <<"Sort by bubble sort:\n";
    print_list(a);
}
void InsertionSort(vector <int> &a)
{
    int x,j;
    for (int i = 1; i < a.size(); i++)
    {
        x=a[i];
        j = i-1;
        while (0<=j && x<a[j])
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=x;
        print_list(a);

    }
    cout <<"Sort by insertion sort:\n";
        print_list(a);
}
int main()
{
    cout <<"Input n:";
    cin >> n;
    cout <<"Input your array:";
    for (int i=0; i<n;i++)
    {
        cin >> tam;
        a.push_back(tam);
    } 
    cout <<"Your array is:\n";
    print_list(a);
    cout <<"1. Bubble Sort\n"
        <<"2.Insertion Sort\n"
        <<"You choose: ";
    cin >> choose;
    switch (choose)
    {
    case 1:
        print_list(a);
        bubbleSort(a);
        break;
    case 2:
        print_list(a);
        InsertionSort(a);
    default:
        cout <<"Thanks for using!";
        break;
    }
    return 0;
}