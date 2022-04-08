#include <iostream>
#include <string>

using namespace std;

struct Data {
	int Mshv;
	string Ten;
	string Lop;
	int ChuyenNganh;
	double Diem;
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

Node* CreateNode(Data input);
void CreateList(LinkList& l);
void AddHead(LinkList& l, Node* node);
void AddTail(LinkList& l, Node* node);
void InsertAfterNodeSearch(LinkList& l, Node* head, Node* nodesearch);
int RemoveHead(LinkList& l);
int RemoveTail(LinkList& l);
int RemoveInNodeSearch(LinkList& l, Node* head);
Node* SearchNode(LinkList l, int index);
void PrintList(LinkList l);
void PrintListWithCondition(LinkList l, int inputX, double inputY);

void DanhSanh() {
    cout << "1: Khoa hoc may tinh" << endl;
    cout << "2: Cong nghe thong tin" << endl;
    cout << "3: Thuong mai dien tu" << endl;
    cout << "4: Quan tri an ninh mang" << endl;
}

void DownLine() {
    cout << "==============================================================" << endl;
}

Node* CreateNode(Data input)
{
    Node* node;
    node = new Node;
    node->data.Mshv = input.Mshv;
    node->data.Ten = input.Ten;
    node->data.Lop = input.Lop;
    node->data.ChuyenNganh = input.ChuyenNganh;
    node->data.Diem = input.Diem;
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
    Data data;
    Node* node = NULL;
    int x;
    for (int i = 0; i < input; i++) {
        cout << "Nhap thong tin hoc vien thu " << i + 1 << ": " << endl;
        cout << "MSHV: ";
        cin >> data.Mshv;
        cin.ignore();
        cout << "Ho va ten: ";
        getline(cin, data.Ten);
        cout << "Lop: ";
        cin >> data.Lop;
        cout << "Chuyen nganh: " << endl;
    backcinnhap:
        DanhSanh();
        cin >> x;
        if (x < 1 || x > 4) {
            cout << "Nhap sai chuyen hanh, moi nhap lai !" << endl;
            goto backcinnhap;
        }
        data.ChuyenNganh = x;
        cout << "Diem tong ket: ";
        cin >> data.Diem;
        node = CreateNode(data);
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

        if (node1->data.Mshv == head->data.Mshv) {
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
        if (node->data.Mshv == index && node != NULL)
            return node;
    }
    return NULL;
}

void PrintList(LinkList l)
{
    if (l.Head != NULL) {
        for (Node* node = l.Head; node != NULL; node = node->next) {
            cout << "MSHV: " << node->data.Mshv << endl;
            cout << "Ten: " << node->data.Ten << endl;
            cout << "Lop: " << node->data.Lop << endl;
            cout << "Chuyen nganh: ";
            switch (node->data.ChuyenNganh) {
            case 1:
            {
                cout << "Khoa hoc may tinh" << endl;
                break;
            }
            case 2:
            {
                cout << "Cong nghe thong tin" << endl;
                break;
            }
            case 3:
            {
                cout << "Thuong mai dien tu" << endl;
                break;
            }
            case 4:
            {
                cout << "Quan tri an ninh mang" << endl;
                break;
            }
            }
            cout << "Diem Tong Ket: " << node->data.Diem << endl;
            cout << "------------------------------------------" << endl;
        }
    }
}

void PrintListWithCondition(LinkList l, int inputX, double inputY)
{
    if (l.Head != NULL) {
        for (Node* node = l.Head; node != NULL; node = node->next) {
            if (node->data.ChuyenNganh == 2 && node->data.Diem >= 8) {
                cout << "MSHV: " << node->data.Mshv << endl;
                cout << "Ten: " << node->data.Ten << endl;
                cout << "Lop: " << node->data.Lop << endl;
                cout << "Chuyen nganh: ";
                switch (node->data.ChuyenNganh) {
                case 1:
                {
                    cout << "Khoa hoc may tinh" << endl;
                    break;
                }
                case 2:
                {
                    cout << "Cong nghe thong tin" << endl;
                    break;
                }
                case 3:
                {
                    cout << "Thuong mai dien tu" << endl;
                    break;
                }
                case 4:
                {
                    cout << "Quan tri an ninh mang" << endl;
                    break;
                }
                }
                cout << "Diem Tong Ket: " << node->data.Diem << endl;
                cout << "------------------------------------------" << endl;
            }
        }
    }
}

int main() {
    int n, x;
    LinkList list;
    CreateList(list);
    cout << "Nhap so luong hoc vien can nhap: ";
    cin >> n;
    system("cls");

    //Nhap danh sach hoc vien 
    InsertList(list, n);
    

    // Xuat danh sach hoc vien da nhap
    cout << "Danh sach hoc vien da nhap: " << endl;
    PrintList(list);
    DownLine();

    // Liet ke danh sach hoc vien chuyen nganh "cong nghe thong tin" va diem tong ket >= 8
    cout << "Danh sach hoc vien chuyen nganh 'cong nghe thong tin' va diem tong ket >= 8: " << endl;
    PrintListWithCondition(list, 2, double(8));
    DownLine();

    // Nhap ma hoc vien va xoa hoc vien do
    cout << "Nhap ma hoc vien can xoa: ";
    cin >> x;
    cout << "------------------------------------------" << endl;
    RemoveInNodeSearch(list, SearchNode(list, x));

    // Xuat danh sach sau khi xoa
    cout << "Danh sach sau khi xoa la: " << endl;
    PrintList(list);
    DownLine();
}