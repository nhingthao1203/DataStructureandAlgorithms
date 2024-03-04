#include <iostream>
#define M 101
using namespace std;

struct Node
{
    int key;
    Node* next;
};
Node* heads[M];
Node* z;
void init()
{
    z= new Node;
    z-> next =z;
    for (int i=0;i<M,i++)
    heads[i]= z;
}
int main()
{
    return 0;
}