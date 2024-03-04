#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>


using namespace std;
vector <float> a;
void bucketSort(vector<float>&a, int n)
{
    
    const int m =5;
    vector <vector<int>> b (m);
    for (int i = 0; i < n; i++)
    {
        int bi =(float)((a[i])/n)*m;
        if (bi<0) bi=0;
        if (bi>=m) bi=m-1;
        b[bi].push_back(a[i]);
    }
    for (int i = 0; i < n; i++)
        sort(b[i].begin(),b[i].end());
    int idx=0;
    for (int i =0;i<n;i++)
        for (int j=0; j<b[i].size();j++)
            a[idx++]=b[i][j];


}
int main()
{
    cout <<"Input n:\n";
    int n,tam, max=0;
    cin >>n;
    for (int i=0; i<n; i++)
    {
        cin >> tam;
        a.push_back(tam);
        if (tam >max) max =tam;
        
    }
    bucketSort(a,max);
    for (int i=0; i<n; i++)
    cout << a[i] << " ";
    return 0;
    system("pause");

}