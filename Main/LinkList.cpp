#include "LinkList.h"
#include <iostream>
#include <cstdlib>

using namespace std;

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

// Ham tao danh sach gom 50000 so nguyen

void InsertList(LinkList& l)
{
	Node* node = NULL;
	srand(time(NULL));
	for (int i = 0; i < 50000; i++) {
		int x = rand() % 100 + 1;
		node = CreateNode(x);
		AddTail(l, node);
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

int CheckArrangeList(LinkList& l)
{
	for (Node* node = l.Head; node->next != NULL; node = node->next)
		if (node->data > node->next->data) {
			for (Node* node = l.Head; node->next != NULL; node = node->next)
				if (node->data < node->next->data)
					return 0;
			return 1;
		}
	return 2;
}
