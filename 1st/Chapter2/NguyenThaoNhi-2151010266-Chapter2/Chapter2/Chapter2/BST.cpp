#include <iostream>
#include <iomanip>
#include <conio.h>
#define SPACE 5

using namespace std;

struct Node 
{
	int data;
	Node* left;
	Node* right;
};
//type a binary search tree
typedef Node* Tree;
//create a new node 
Node* createNode(int a)
{
	Node* p = new Node;
	p->data = a;
	p->left = NULL;
	p->right = NULL;
	return p;

}
void create_Tree(Tree& root)
{
	root = NULL;
}
void DestroyTree(Tree& root)
{
    if (root)
    {
        DestroyTree(root->left);
        DestroyTree(root->right);
        delete root;
    }
}

void AddNode(Tree& root, Node* node)
{
    if (root)
    {
        if (root->data == node->data) //if exist -> exit 
            return;
        if (node->data < root->data) // recursive add to the left
            AddNode(root->left, node);
        else
            AddNode(root->right, node);//recursive add to the right
    }
    else
    {
        root = node;
    }
}

Node* FindNode(Tree root, int x)
{
    if (root)
    {
        if (root->data == x)
            return root;
        if (x < root->data)
            return FindNode(root->left, x);
        return FindNode(root->right, x);
    }
    return NULL;
}

void PrintTree(Tree root)// print tree using LNR
{
    if (root)
    {
        cout << "||" << endl;
        PrintTree(root->left);
        cout << root->data << endl;
        PrintTree(root->right);
    }
}

void display(Tree root, int space)
{
    if (root ==NULL) // base case
        return;
    space +=SPACE; //Increase distance between Levels
    display (root->right,space); //process right child first
    cout << endl; 
    for (int i = SPACE;i<space ;i++)// print current node after space count 
    cout << " ";
    cout <<root->data<<"\n";
    display (root->left, space);//Process left child
}

bool Search(Tree& root, int x)
{
    if (root)
    {
        if (root->data == x) //if exist -> exit 
            return true;
        if (x < root->data) // recursive add to the left
            Search(root->left, x);
        else
            Search(root->right,x);//recursive add to the right
    }
    else
    {
        return false;
    }
}
void FindAndReplace1(Tree& p, Tree& tree)
{
    if (tree->left) // chưa phải nhỏ nhất (trái nhất)
        FindAndReplace1(p, tree->left); // tiếp tục tìm
    else // tree là nút trái nhất
    {
        p->data = tree->data; // copy data
        p = tree; // trỏ nút p vào nút tree sẽ làm thế mạng bị xóa
        tree = tree->right; // nút trái không còn tuy nhiên nút phải có thể còn nên ta phải nối chúng lại
    }
}
void DeleteNode(Tree& root, int x)
{
    if (root)
    {
        if (x > root->data)
            DeleteNode(root->right, x);
        else if (x < root->data)
            DeleteNode(root->left, x);
        else
        {
            Node* p = root;
            if (!root->left)
                root = root->right;
            else if (!root->right)
                root = root->left;
            else
                FindAndReplace1(p, root->right);
            // FindAndReplace2(p, root->left);
            delete p;
        }
    }
    else
    {
        cout << "Not found!\n";
    }
}
void LNR(Tree root)
{
    if (root !=NULL)
    {
        LNR(root->left);
        cout <<root->data<<" ";
        LNR(root-> right);
    }
}
void NLR(Tree root)
{
    if (root!=NULL)
    {
        cout << root->data<<" ";
        NLR(root->left);
        NLR(root->right);
    }
}
void LRN(Tree root)
{
    if (root!=NULL)
    {
        LRN(root->left);
        LRN(root->right);
        cout << root -> data<<" ";
    }
}
int main()
{
    int n, choose;
    bool flag = false;
    Node* Tree1;
    create_Tree(Tree1);
    do
    {
        system("cls");
        cout
            << "\n1/Input arr"
            << "\n2/Print list"
            << "\n3/Search x"
            << "\n4/Delete x"
            << "\n5/Traverse the BST with NLR"
            << "\n6/Traverse the BST with LNR"
            << "\n7/Traverse the BST with LRN"
            << "\n8/Display the BST"
            << "\n11/Exit!"
            << "\nYour choice: " << endl;
        cin >> choose;
        switch (choose)
        {
        case 1:
        {
            if (flag)
            {
                DestroyTree(Tree1);
                create_Tree(Tree1);
            }
            cout << "Input n:";
            cin >> n;
            
            for (int i = 0; i < n; i++)
            {
                //cin >> a[i];
                int x = rand() % 10;
                cout << x << " ";
                AddNode(Tree1, createNode(x));
            }
            cout << endl;
                
            //PrintTree(Tree1);
            //printList(a, n);
            display(Tree1,1);
            flag = true;
            break;
        }
        case 2:
        {
            //printList(a, n);
            //PrintTree(Tree1);
            display (Tree1,1);
            break;
        }

        case 3:
        {
            int x;
            cout << "Input x to find: ";
            cin >> x;
            if (Search(Tree1, x))
                cout <<x<< " does Exist \n";
            else cout <<x<< " doesn't exist \n";
            break;
        }
        case 4:
        {
            int x;
            cout << "Input x to delete:";
            cin >> x;
            cout << "Before:\n";
            display (Tree1,1);
            //PrintTree(Tree1);
            cout << endl;
            DeleteNode(Tree1, x);
            cout << "After:";
            display(Tree1,1);
            //PrintTree(Tree1);
            cout << endl;
            break;
        }
        case 5:
        {
            cout <<"Traverse NLR: ";
            NLR(Tree1);
            cout <<endl;
            break;
        }
        case 6:
        {
            cout <<"Traverse LNR: ";
            LNR(Tree1);
            cout <<endl;
            break;
        }
        case 7:
        {
            cout <<"Traverse LRN: ";
            LRN(Tree1);
            cout <<endl;
            break;
        }
        case 8:
        {
            cout <<"Display BST: "<<endl;
            display (Tree1,1);
            cout <<endl;
            break;
        }
        }
        system("pause");
        _getch();
    } while (choose < 11);
}