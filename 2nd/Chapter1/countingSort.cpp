#include<iostream>
#include<vector>

using namespace std;
int n;
vector <int> a;
void countingSort(vector<int>&a, int max)
{
    vector <int> b(max+1,0);
    vector <int> c(a.size());
    for (int i=0; i<max;i++)
        b[a[i]]++;
    for (int i=1; i<=max+1 ;i++)
    {
        b[i]=b[i]+b[i-1];
    }
    for (int i=0; i< a.size();i++)
    {
        c[b[a[i]-1]]= a[i];
        b[a[i]]--;
    }
    for (int i=0; i< a.size();i++)
        {
            a[i]=c[i];
            cout <<c[i]<<" ";
        }
    

}
int main()
{
    cout <<"Input n:\n";
    cin >>n;
    int max =0, tam;
    for (int i=0;i<n;i++) 
    {
        cin >>tam;
        a.push_back(tam);
        if (tam > max) max = tam;
    }
    countingSort(a, max);
    
    return 0;
    system("pause");

}