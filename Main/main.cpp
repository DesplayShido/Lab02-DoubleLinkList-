#include "Linklist.h"
#include <iostream>
#include <string>

using namespace std;

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