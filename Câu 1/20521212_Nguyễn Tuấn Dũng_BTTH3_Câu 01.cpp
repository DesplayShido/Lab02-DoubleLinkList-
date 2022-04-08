#include <iostream>

using namespace std;

// Cau 01   
// a: ----------------------------------------------------------------------------------------------------------------
struct Node
{
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

// b: ----------------------------------------------------------------------------------------------------------------
void CreateList(LinkList& l)
{
    l.Head = l.Tail = NULL;
}

// c: ----------------------------------------------------------------------------------------------------------------
bool CheckNULL(LinkList l) 
{
    if (l.Head == NULL)
        return true;
    return false;
}

// d: ----------------------------------------------------------------------------------------------------------------
Node* CreateNode(int input)
{
    Node* node;
    node = new Node;
    node->data = input;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

// e: ----------------------------------------------------------------------------------------------------------------
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

// f: ----------------------------------------------------------------------------------------------------------------
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

// g: ----------------------------------------------------------------------------------------------------------------
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

// h: ----------------------------------------------------------------------------------------------------------------
void InsertList(LinkList& l, int input) 
{
    Node* node = NULL;
    int x;
    cout << "nhap danh sach (cach nhau 1 dau space): ";
    for (int i = 0; i < input; i++) {
        cin >> x;
        node = CreateNode(x);
        AddTail(l, node);
    }
}

// i: ----------------------------------------------------------------------------------------------------------------
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

// j: ----------------------------------------------------------------------------------------------------------------
Node* SearchNode(LinkList l, int index)
{
    for (Node* node = l.Head; node != NULL; node = node->next) {
        if (node->data == index && node != NULL)
            return node;
    }
    return NULL;
}

// k: ----------------------------------------------------------------------------------------------------------------
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

// l: ----------------------------------------------------------------------------------------------------------------
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

// m: ----------------------------------------------------------------------------------------------------------------
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

int main() {
	// Cau 01:
	int n;
	LinkList list;
	CreateList(list);

    // Nhap danh sach
	cout << "Nhap n: ";
	cin >> n;
    InsertList(list, n);

    // Check rong
    if (CheckNULL(list)) {
        cout << "Danh sach rong !";
        return 0;
    }
    // Xuat danh sach
	PrintList(list);
}