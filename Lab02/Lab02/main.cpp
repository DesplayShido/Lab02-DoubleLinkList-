#include "Linklist.h"
#include <iostream>
#include <string>

using namespace std;

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
	cout << "----- Danh sach nhan vien da nhap ----- " << endl;
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
	cout << "----- Danh sach nhan vien sau khi duoc sap xep theo luong giam dan ----" << endl;
	PrintList(list);
	system("pause");
	system("cls");

	// Xuat danh sach sau khi xoa 1 nhan vien
	cout << "Nhap ma so nhan vien can xoa: ";
	cin >> x;
	if (SearchNodeWithCode(list, x) == NULL) {
		cout << "khong ton tai nhan vien co ma so" << x;
		return 0;
	}
	RemoveInNodeSearch(list, SearchNodeWithCode(list, x));
	cout << "----- Danh sach sau khi xoa mot nhan vien la -----" << endl;
	PrintList(list);
	return 0;
}