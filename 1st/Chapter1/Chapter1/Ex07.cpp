#include<iostream>
#define MAX 100
 
using namespace std;
int a[MAX];
int front,rear;// location of front and location of rear


// init empty queue
void init (int a[], int &front, int &rear)
{
    front =-1;
    rear =-1;
}
//check empty queue

bool checkEmpty(int a[], int front, int rear)
{
    if (front == -1)
        return true;
    return false;
}

//check full queue 
bool checkFull(int a[], int front, int rear)
{
    if ((rear - front == MAX - 1) || (rear - front == -1))
        return true;
    return false;
}
//push element by circle
void Push(int a[], int& front, int& rear, int x)
{
    if (checkFull(a,front,rear) == true)
        cout << "Queue full";
    else
    {
        if (checkEmpty(a,front,rear)) 
            front = 0; 
        if (rear == MAX - 1) 
            rear = -1; 
        a[++rear] = x; 
        cout << "Pushed " << x << endl;
    }
}
// pop element

int Pop(int a[],int&front,int &rear, int& x)
{
    if (front != -1)
    {
        x = a[front];
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front++;
            if (front > MAX - 1) front = 0;
        }
        return 1;
    } return 0;
}
void show(int a[], int front, int rear)
{
    if (checkEmpty(a,front,rear))
        cout << "\nQueu is emty";
    else
    {
        cout << "\nYour queue:\n";
        if (rear >= front)
        for (int i =front ; i <= rear; i++)
            cout << a[i] << "\t";
        else
        {
            if (rear < front)
                for (int i = front; i <= MAX - 1; i++)
                    cout << a[i] << "\t";
            for (int i = 0; i <= rear; i++)
                cout << a[i] << "\t";
        }
        cout << endl;

    }
}
int main ()
{
    init(a, front, rear);
    int x;
    do
    {
        cout << "Input element push in queue(input -1 for stop):\n";
        cin >> x;
        if (x != -1 && !checkFull(a,front,rear))
            Push(a, front, rear, x);
    } while (x!=-1&& !checkFull(a,front,rear));
    show(a, front, rear);
    while (!checkEmpty(a,front,rear))
    {
        Pop(a,front,rear,x);
        show(a, front, rear);
    }
    return 0;
    system("pause");
}