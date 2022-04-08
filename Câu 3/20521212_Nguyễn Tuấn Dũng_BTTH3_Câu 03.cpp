#include <iostream>
#include <string>

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

void DownLine() {
    cout << "==============================================================" << endl;
}

Node* CreateNode(Data input)
{
    Node* node;
    node = new Node;
    node->data.Msnv = input.Msnv;
    node->data.Ho = input.Ho;
    node->data.Ten = input.Ten;
    node->data.NgaySinh = input.NgaySinh;
    node->data.NoiSinh = input.NoiSinh;
    node->data.NgayCongTac = input.NgayCongTac;
    node->data.Luong = input.Luong;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

void CreateList(LinkList& l)
{
    l.Head = l.Tail = NULL;
}

void InsertList(LinkList& l, int input)
{
    Node* node = NULL;
    Data data;
    for (int i = 0; i < input; i++) {
        cout << "----- Nhap thong tin nhan vien thu " << i + 1 << " -----" << endl;
        cout << "Ma so nhan vien: ";
        cin >> data.Msnv;
        cout << "Nhap ho cua nhan vien: ";
        cin.ignore();
        getline(cin, data.Ho);
        cout << "Nhap ten cua nhan vien: ";
        getline(cin, data.Ten);
        cout << "Nhap noi sinh cua nhan vien: ";
        getline(cin, data.NoiSinh);
        cout << "nhap ngay sinh cua nhan vien (vi du: 21 2 2002): ";
        cin >> data.NgaySinh.Day >> data.NgaySinh.Month >> data.NgaySinh.Year;
        cout << "Nhap ngay bat dau cong tac cua nhan vien (vi du: 21 2 2002): ";
        cin >> data.NgayCongTac.Day >> data.NgayCongTac.Month >> data.NgayCongTac.Year;
        cout << "Nhap luong cua nhan vien: ";
        cin >> data.Luong;
        Node* node = CreateNode(data);
        AddTail(l, node);
        DownLine();
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
    Node* node2 = NULL;
    while (node1 != NULL) {

        if (node1->data.Msnv == head->data.Msnv) {
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

Node* SearchNodeWithCode(LinkList l, int index)
{
    for (Node* node = l.Head; node != NULL; node = node->next) {
        if (node->data.Msnv == index && node != NULL)
            return node;
    }
    return NULL;
}

void ArrangeList(LinkList& l)
{
    for (Node* node1 = l.Head; node1 != NULL; node1 = node1->next)
        for (Node* node2 = node1->next; node2 != NULL; node2 = node2->next)
            if (node1->data.Luong < node2->data.Luong)
                SwapNode(node1, node2);
}

void SwapNode(Node* node1, Node* node2)
{
    Data Mid;
    Mid = node1->data;
    node1->data = node2->data;
    node2->data = Mid;
}

void PrintList(LinkList l)
{
    if (l.Head != NULL) {
        for (Node* node = l.Head; node != NULL; node = node->next) {
            cout << "Ma so: " << node->data.Msnv << endl;
            cout << "Ho va Ten: " << node->data.Ho << " " << node->data.Ten << endl;
            cout << "Noi sinh: " << node->data.NoiSinh << endl;
            cout << "Ngay sinh: " << node->data.NgaySinh.Day << "/" << node->data.NgaySinh.Month << "/" << node->data.NgaySinh.Year << endl;
            cout << "Ngay cong tac: " << node->data.NgayCongTac.Day << "/" << node->data.NgayCongTac.Month << "/" << node->data.NgayCongTac.Year << endl;
            cout << "Luong: " << node->data.Luong << endl;
            cout << "------------------------------------------" << endl;
        }
    }
}

void PrintListWithCode(LinkList l, int input)
{
    if (l.Head != NULL) {
        for (Node* node = l.Head; node != NULL; node = node->next)
            if (node->data.Msnv == input) {
                cout << "Ma so: " << node->data.Msnv << endl;
                cout << "Ho va Ten: " << node->data.Ho << " " << node->data.Ten << endl;
                cout << "Noi sinh: " << node->data.NoiSinh << endl;
                cout << "Ngay sinh: " << node->data.NgaySinh.Day << "/" << node->data.NgaySinh.Month << "/" << node->data.NgaySinh.Year << endl;
                cout << "Ngay cong tac: " << node->data.NgayCongTac.Day << "/" << node->data.NgayCongTac.Month << "/" << node->data.NgayCongTac.Year << endl;
                cout << "Luong: " << node->data.Luong << endl;
                DownLine();
                return;
            }
        cout << "Khong ton tai nhan vien co ma so " << input << " !" << endl;
        DownLine();
    }
}

void PrintListWithName(LinkList l, string input)
{
    if (l.Head != NULL) {
        for (Node* node = l.Head; node != NULL; node = node->next)
            if (node->data.Ten == input) {
                cout << "Ma so: " << node->data.Msnv << endl;
                cout << "Ho va Ten: " << node->data.Ho << " " << node->data.Ten << endl;
                cout << "Noi sinh: " << node->data.NoiSinh << endl;
                cout << "Ngay sinh: " << node->data.NgaySinh.Day << "/" << node->data.NgaySinh.Month << "/" << node->data.NgaySinh.Year << endl;
                cout << "Ngay cong tac: " << node->data.NgayCongTac.Day << "/" << node->data.NgayCongTac.Month << "/" << node->data.NgayCongTac.Year << endl;
                cout << "Luong: " << node->data.Luong << endl;
                DownLine();
                return;
            }
        cout << "Khong ton tai nhan vien co ten " << input << " !" << endl;
        DownLine();
    }
}




int main() {
	int n, x;
	string y;
	LinkList list;
	CreateList(list);
	cout << "Nhap so luong nhan vien can nhap: ";
	cin >> n;
	system("cls");

	//Nhap danh sach nhan vien 
	cout << "======== NHAP DANH SACH NHAN VIEN ========" << endl;
	InsertList(list, n);
	system("cls");

	// Xuat danh sach nhan vien da nhap
	cout << "======== DANH SACH NHAN VIEN ========" << endl;
	PrintList(list);
	system("pause");
	system("cls");

	// Tim nhan vien theo ma so
	cout << "Nhap ma so nhan vien can tim: ";
	cin >> x;
	cout << "------------------------------------------" << endl;
	PrintListWithCode(list, x);
	system("pause");
	system("cls");

	// Tim nhan vien theo ten
	cout << "Nhap ten nhan vien can tim: ";
	cin.ignore();
	getline(cin, y);
	cout << "------------------------------------------" << endl;
	PrintListWithName(list, y);
	system("pause");
	system("cls");

	// Sap xep danh sach theo luong giam dan
	ArrangeList(list);
	cout << "======== DANH SACH NHAN VIEN SAU KHI DUOC SAP XEP THEO LUONG GIAM DAN ========" << endl;
	PrintList(list);
	system("pause");
	system("cls");

	// Xuat danh sach sau khi xoa 1 nhan vien
	cout << "Nhap ma so nhan vien can xoa: ";
	cin >> x;
	if (SearchNodeWithCode(list, x) == NULL) {
		cout << "khong ton tai nhan vien co ma so " << x;
		return 0;
	}
	RemoveInNodeSearch(list, SearchNodeWithCode(list, x));
	cout << "======== DANH SACH NHAN VIEN SAU KHI XOA 1 NHAN VIEN ========" << endl;
	PrintList(list);
	return 0;
}