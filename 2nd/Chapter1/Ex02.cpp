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
void QuickSort(vector <int> &b,int left, int right,int n)
{
    int x = b[(left +right)/2];
    int i=left;
    int j =right;
    while (i<j)
    {
        while (b[i]<x) 
        {
            i++;           
        }
        while (b[j]>x) 
        {
            j--;
            
        }
        if (i<=j) 
        {
            {
                int tam= b[i];
                b[i]=b[j];
                b[j]=tam;
            }
            //swap(b[i],b[j]);
            
            i++;
            j--;
        }
        if (left <j) QuickSort(b,left,j,b.size());
        if (i<right) QuickSort(b,i,right,b.size());
    }
   // print_list(a);
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
    QuickSort(a,0,a.size(),a.size());
    print_list(a);
    return 0;
}