#include <iostream>
#define MAX 100
#include <cstdlib>
using namespace std;

int n, x, y, *a;
void outPut()
{
	cout << "Arr:" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}
void reMove(int *&a, int& n, int X)
{
	for (int i = x; i < n; i++)
		a[i] = a[i + 1];
	n--;
}
int BS(int *a, int n, int X)//binarySearch
{
	int left = 0, right = n - 1, mid;
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (a[mid] == X) return mid;
		if (x > a[mid]) left = mid + 1;
		else right = mid - 1;
	}
	return -1; // not found x in a;
}
int main()
{
	cout << "Input n:";
	cin >> n;
	a = new int[n + 1];
	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % 10;
		cout << "a[" << i << "]=" << a[i];
		cout << endl;
	}
	outPut();
	cout << "\nFind x: ";
	cin >> x;
	if (BS(a,n, x) != -1)
		cout << "\nFind x at a[" << BS(a, n, x) << "]";
	else
		cout << "\nCan't find x ";
	cout << "\nAdd new element at the end of list :";
	cin >> y;
	a[n] = y;
	n++;
	outPut();
	cout << "\nDelete element at the end of list";
	reMove(a, n, n-1);// remove the element at the end of list
	outPut();
	cout << "\nDelete the element at the position i. Input i: ";
	int I;
	cin >> I;
	if (I<0 && I>n) cout << "\nCan't find i";
	else reMove(a, n, I-1);
	outPut();
	cout << "\nInput an element in the list. If found, remove it. X=";
	int Y;
	cin >> Y;
	if (BS(a, n, Y) == -1)
		cout << "\nCan't find " << Y << " in list";
	else
	{
		cout << "\nElemet " << Y << " at position " << BS(a, n, Y) + 1;
		reMove(a, n, BS(a,n,Y));
		outPut();
	}
	delete[]a;
	return 0;


}