#ifndef Linklist_h
#define LinkList_h
#include <iostream>

using namespace std;

struct Date {
	int Day, Month, Year;
};

struct Data {
	int Msnv;
	string Ho;
	string Ten;
	string NoiSinh;
	Date NgaySinh;
	Date NgayCongTac;
	int Luong;
};

struct Node
{
	Data data;
	Node* prev;
	Node* next;
};

struct LinkList
{
	Node* Head;
	Node* Tail;
};

void DownLine();
Node* CreateNode(Data input);
void CreateList(LinkList& l);
void InsertList(LinkList& l, int input);
void AddHead(LinkList& l, Node* node);
void AddTail(LinkList& l, Node* node);
void InsertAfterNodeSearch(LinkList& l, Node* head, Node* nodesearch);
int RemoveHead(LinkList& l);
int RemoveTail(LinkList& l);
int RemoveInNodeSearch(LinkList& l, Node* head);
Node* SearchNodeWithCode(LinkList l, int index);
void ArrangeList(LinkList& l);
void SwapNode(Node* node1, Node* node2);
void PrintList(LinkList l);
void PrintListWithCode(LinkList l, int input);
void PrintListWithName(LinkList l, string input);

#endif // LinkList_h

#pragma once
