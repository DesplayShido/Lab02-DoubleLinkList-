#pragma once
#ifndef Linklist_h
#define LinkList_h

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
void InsertList(LinkList& l);
void AddHead(LinkList& l, Node* node);
void AddTail(LinkList& l, Node* node);
void InsertAfterNodeSearch(LinkList& l, Node* head, Node* nodesearch);
int RemoveHead(LinkList& l);
int RemoveTail(LinkList& l);
int RemoveInNodeSearch(LinkList& l, Node* head);
Node* SearchNode(LinkList l, int index);
void PrintList(LinkList l);
double AverageList(LinkList l);
int CheckArrangeList(LinkList& l);

#endif "LinkList_h"
