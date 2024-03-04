#include<iostream>
#include <conio.h>


using namespace std;

struct number {
	int integer;
	number* next;
};

number* createNumber(int x) {
	number* temp = new number;
	temp->next = NULL;
	temp->integer = x;
	return temp;
}
number* addStart(number* l, int x) {
	if (l == NULL) {
		number* p = createNumber(x);
		return p;
	}
	number* temp = new number;
	temp->integer = x;
	temp->next = l;
	l = temp;
	return l;
}
number* addEnd(number* l, int x) {
	if (l == NULL) {
		number* q = createNumber(x);
		return q;
	}
	number* p = l;
	while (p->next != NULL) {
		p = p->next;
	}
	number* temp = new number;
	temp->integer = x;
	temp->next = NULL;
	p->next = temp;
	return l;
}

void printList(number* l) {
	number* p = l;
	while (p != NULL) {
		cout << p->integer << " ";
		p = p->next;
	}
	cout << endl;
}
void find(number* l, int x) {
	int count = 0;
	number* p = l;
	cout << "danh sach vi tri cua so " << x << " : ";
	while (p != NULL ) {
		count++;
		if (p->integer == x) {
			cout <<count <<" ";
		}
		p = p->next;
	}
	cout << endl;
}
number* deleteStart(number* l) {
	number* p = l;
	l = l->next;
	cout << "delete successful !" << endl;
	return l;
	delete p;
}
number* deleteEnd(number* l) {
	number* p = l;
	number* q = NULL;
	while (p->next != NULL) {
		q = p;
		p = p->next;
	}
	q->next = NULL;
	cout << "delete successful !" << endl;
	return l;
	delete p;
}
number* deleteIndex(number* l,int index) {
	int count = 1;
	number* p = l;
	number* q = NULL;
	if (index == 1) {
		l = deleteStart(l);
		return l;
	}
	else {
		while (count != index) {
			q = p;
			p = p->next;
			count++;
		}
		q->next = p->next;
		cout << "delete successful !" << endl;
		delete p;
		return l;
	}
}
bool checkNum(number* l, int x) {
	number* p = l;
	while (p != NULL) {
		if (p->integer == x) {
			return true;
		}
		p = p->next;
	}
	return false;
}

number* deleteNumber(number* l, int num) {
	number* p = l;
	number* q = l;
	if (p->integer == num) {
		l = deleteStart(l);
		return l;
	}
	while (p->next != NULL && p->integer != num) {
		q = p;
		p = p->next;
	}
	q->next = p->next;
	delete p;
	return l;
}
number* deleteAllNumber(number* l, int num) {
	while (true) {
		if (!checkNum(l, num)) {
			break;
		}
		l = deleteNumber(l,num);
	}
	return l;
}
number* interChangeSort(number*& l) {
	for (number* q = l; q != NULL; q = q->next) {
		for (number* p = q->next; p != NULL; p = p->next) {
			if (p->integer < q->integer) {
				int tmp = p->integer;
				p->integer = q->integer;
				q->integer = tmp;
			}
		}
	}
	return l;
}

int main() {
	int tmp;
	int choose;
	number* first = NULL;
	do {
		cout << "nhap so nguyen: ";
		cin >> tmp;
		if (tmp != 0) {
			first = addEnd(first, tmp);
		}
	} while (tmp != 0);
	printList(first);
	do {
        system("cls");
		cout << "1/Print list" << endl;
		cout << "2/Find element in list" << endl;
		cout << "3/Add element in list" << endl;
		cout << "4/Add element at the last of the list" << endl;
		cout << "5/Delete 1 element at first" << endl;
		cout << "6/Delete 1 element at the end of the list" << endl;
		cout << "7/Delete 1 element at the number i in the list" << endl;
		cout << "8/Find the element and delete this element" << endl;
		cout << "9/Find the element and delete all element have the same value" << endl;
		cout << "10/Sort list 1->10" << endl;
		cout << "11/Exit " << endl;
		cin >> choose;
		switch (choose) {
		
        case 1: {
			printList(first);
			break;
		}
		case 2: {
			cout << "Input the element you want to find" << endl;
			cin >> tmp;
			find(first, tmp);
			break;
		}
		case 3: {
			cout << "Please input the value you want to add in list" << endl;
			cin >> tmp;
			first = addStart(first, tmp);
			printList(first);
			break;
		}
		case 4: {
			cout << "Pls input the value you want to add at the end of list" << endl;
			cin >> tmp;
			first = addEnd(first, tmp);
			printList(first);
			break;
		}
		case 5: {
			first = deleteStart(first);
			printList(first);
			break;
		}
		case 6: {
			first = deleteEnd(first);
			printList(first);
			break;
		}
		case 7: {
			cout << "Pls inupt the number you want to delete:" << endl;
			cin >> tmp;
			first = deleteIndex(first,tmp);
			printList(first);
			break;

		}
		case 8: {
			cout << "Pls input the value you want to delete:" << endl;
			cin >> tmp;
			first = deleteNumber(first, tmp);
			printList(first);
			break;
		}
		case 9: {
			cout << "Pls input the value you want to delete::" << endl;
			cin >> tmp;
			first = deleteAllNumber(first, tmp);
			printList(first);
			break;
		}
		case 10: {
			first=interChangeSort(first);
			printList(first);
			break;
		}
		case 11: {
			cout << "thanks for using" << endl;
			break;
		}
		default:
			cout << "error choose, pls choose again" << endl;
			break;
		}
        system("pause");
        _getch();
	} while (choose != 11);
}
