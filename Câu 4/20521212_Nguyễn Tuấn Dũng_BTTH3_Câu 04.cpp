#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

struct Node {
	int data;
	Node* prev;
	Node* next;
};

struct LinkList
{
	Node* Head;
	Node* Tail;
};

Node* CreateNode(int input);
bool CheckNULL(LinkList l);
void CreateList(LinkList& l);
void InsertList(LinkList& l, int input);
void AddHead(LinkList& l, Node* node);
void AddTail(LinkList& l, Node* node);
void InsertAfterNodeSearch(LinkList& l, Node* head, Node* nodesearch);
int RemoveHead(LinkList& l);
int RemoveTail(LinkList& l);
int RemoveInNodeSearch(LinkList& l, Node* head);
Node* SearchNode(LinkList l, int index);
void PrintList(LinkList l);
double AverageList(LinkList l);
void CheckArrangeList(LinkList& l);


Node* CreateNode(int input)
{
	Node* node;
	node = new Node;
	node->data = input;
	node->next = NULL;
	node->prev = NULL;
	return node;
}

bool CheckNULL(LinkList l)
{
	if (l.Head == NULL)
		return true;
	return false;
}

void CreateList(LinkList& l)
{
	l.Head = l.Tail = NULL;
}

// Ham nhap
void InsertList(LinkList& l, int input)
{
	if (input == 0) {
		Node* node = NULL;
		srand(time(NULL));
		for (int i = 0; i < 50000; i++) {
			int x = rand() % 100 + 1;
			node = CreateNode(x);
			AddTail(l, node);
		}
	}
	else {
		cout << "nhap danh sach (cach nhau 1 dau space): ";
		Node* node = NULL;
		int x;
		for (int i = 0; i < input; i++) {
			cin >> x;
			node = CreateNode(x);
			AddTail(l, node);
		}
	}
}

void AddHead(LinkList& l, Node* node)
{
	if (l.Head == NULL) {
		l.Head = l.Tail = node;
	}
	else {
		node->next = l.Head;
		l.Head->prev = node;
		l.Head = node;
	}
}

void AddTail(LinkList& l, Node* node)
{
	if (l.Head == NULL) {
		l.Head = l.Tail = node;
	}
	else {
		l.Tail->next = node;
		node->prev = l.Tail;
		l.Tail = node;
	}
}

void InsertAfterNodeSearch(LinkList& l, Node* head, Node* nodesearch)
{
	if (nodesearch != NULL) {
		head->next = nodesearch->next;
		head->prev = nodesearch->prev;
		nodesearch->next = head;
		if (l.Tail == nodesearch)
			l.Tail = head;
	}
	else
		AddHead(l, head);
}

int RemoveHead(LinkList& l)
{
	if (l.Head != NULL) {
		Node* node = l.Head;
		l.Head = node->next;
		node = NULL;
		if (l.Head == NULL)
			l.Tail = NULL;
		return 1;
	}
	return 0;
}

int RemoveTail(LinkList& l)
{
	if (l.Head != NULL) {
		Node* node = l.Head->next;
		Node* NodeNext = node;
		while (node->next != NULL)
		{
			NodeNext = node;
			node = node->next;
		}
		l.Tail = NodeNext;
		l.Tail->next = NULL;
		return 1;
	}
	return 0;
}

int RemoveInNodeSearch(LinkList& l, Node* head)
{
	Node* node1 = l.Head;
	cout << head->data;
	Node* node2 = NULL;
	while (node1 != NULL) {

		if (node1->data == head->data) {
			break;
		}
		node2 = node1;
		node1 = node1->next;
	}
	if (node1 == NULL)
		return 0;
	if (node2 != NULL) {
		if (node1 == l.Tail)
			l.Tail = node2;
		node2->next = node1->next;
		delete node1;
	}
	else {
		l.Head = node1->next;
		if (l.Head == NULL)
			l.Tail = NULL;
	}
	return 1;
}

Node* SearchNode(LinkList l, int index)
{
	for (Node* node = l.Head; node != NULL; node = node->next) {
		if (node->data == index && node != NULL)
			return node;
	}
	return NULL;
}

void PrintList(LinkList l)
{
	if (l.Head != NULL) {
		Node* node = l.Head;
		while (node != NULL)
		{
			cout << node->data << " ";
			node = node->next;
		}
		cout << endl;
	}
}

// Ham tinh gia tri trung binh cua danh sach

double AverageList(LinkList l)
{
	double n = 0;
	int x = 0;
	for (Node* node = l.Head; node != NULL; node = node->next) {
		n += node->data;
		x++;
	}

	return n / x;
}

// Ham kiem tra danh sach xem co theo thu tu tang dan hoac giam dan khong

void CheckArrangeList(LinkList& l)
{
	for (Node* node = l.Head; node->next != NULL; node = node->next)
		if (node->data > node->next->data) {
			for (Node* node = l.Head; node->next != NULL; node = node->next) {
				if (node->data < node->next->data) {
					cout << "Danh sach khong duoc sap xep theo thu tu !" << endl;
					return;
				}
			}
			cout << "Danh sach duoc sap xep theo thu tu giam dan !" << endl;
			return;
		}
	cout << "Danh sach duoc sap xep theo thu tu tang dan !" << endl;
	return;
}

int main() {
	LinkList list;
	CreateList(list);
	int n;
	cout << "nhap so luong phan tu danh sach (nhap 0 de tao ngau nhien 50000 so): ";
	cin >> n;
	InsertList(list, n);
	cout << "Gia tri trung binh cua cac so nguyen trong day la: " << AverageList(list) << endl;
	CheckArrangeList(list);
}