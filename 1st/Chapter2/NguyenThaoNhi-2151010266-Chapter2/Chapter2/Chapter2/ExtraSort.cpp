#include <iostream>
#include<conio.h>
#include <iomanip>
#include <cstring>
#include<algorithm>
#include<vector>
#define MAX 100
using namespace std;

void swap(int& x, int& y)
{
    int tmp = x;
    x = y;
    y = tmp;
}
void printList(int a[], int& n)
{
    cout << "your array is " << endl;
    cout << " Position:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout <<"|"<< i <<"|\t";
    }
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << "\t";
    }

    cout << endl << endl;
}
void counting_Sort(int a[], int n)
{
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        max = max < a[i] ? a[i] : max;
    }
    int* b;
    b = new int[max + 1];
    //memset(b, 0, max+1);
    for (int i = 0; i < max + 1; i++) b[i] = 0;
    for (int i = 0; i < n; i++)
    {
        b[a[i]]++;
    }
    cout << "Count Arr:\n";
    int tam = max + 1;
    printList(b, tam);
    for (int i = 1; i < tam; i++)
        b[i] = b[i] + b[i - 1];
    printList(b, tam);
    int* c = new int[n + 1];
    for (int i = 0; i < n; i++)
    {
        c[b[a[i]]] = a[i];
        b[a[i]]--;
        printList(b, tam);
    }
    for (int i = 1; i < n + 1; i++)
        cout << c[i] << " ";
    cout << endl;
}
void countSort(int arr[], int n, int exp)
{
    
    int output[10000];
    int i, count[10] = { 0 };

    for (i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
    for (i = 0; i < n; i++)
        arr[i] = output[i];
    printList(arr, n);
}
void Radix_Sort(int a[],int n)
{
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        max = max < a[i] ? a[i] : max;
    }
    for (int exp = 1; max / exp > 0; exp *= 10)
    {
        countSort(a, n, exp);
        printList(a, n);
    }
        
}
void bucket_Sort(int arr[], int n)
{
    vector <int> b[100000];

    for (int i = 0; i < n; i++) {
        int bi = n * arr[i]; 
        b[bi].push_back(arr[i]);
    }
    
    for (int i = 0; i < n; i++)
        sort(b[i].begin(), b[i].end());
    int index = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < b[i].size(); j++)
            arr[index++] = b[i][j];
}

int main()
{
    int a[MAX], b[MAX], n, choose;
    do
    {
        system("cls");
        cout
            << "\n1/Input arr"
            << "\n2/Print list"
            << "\n3/Using Counting Sort"
            << "\n11/Exit!"
            << "\nYour chosse: " << endl;
        cin >> choose;
        switch (choose)
        {
        case 1:
        {
            cout << "Input n:";
            cin >> n;
       

            for (int i = 0; i < n; i++)
                //cin >> a[i];
                a[i] = rand() % 10;
            printList(a, n);
            break;
        }
        case 2:
        {
            printList(a, n);
            break;
        }
        case 3:
        {
            cout << "\nArr:\n";
            printList(a, n);
            copy(a, a + n, b);
            counting_Sort(b, n);
            break;
        }
        case 4:
        {
            cout << "\nArr:\n";
            printList(a, n);
            copy(a, a + n, b);
            Radix_Sort(b, n);
            break;
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
    } while (choose < 11);
}