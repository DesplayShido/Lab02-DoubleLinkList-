#include "Linklist.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
	LinkList list;
	CreateList(list);
	InsertList(list);
	double X = AverageList(list);
	cout << X << endl;
	switch (CheckArrangeList(list))
	{
	case 0:
		cout << "Danh sach khong duoc sap xep theo thu tu !" << endl;
		break;
	case 1:
		cout << "Danh sach duoc sap xep theo thu tu giam dan !" << endl;
		break;
	case 2:
		cout << "Danh sach duoc sap xep theo thu tu tang dan !" << endl;
		break;
	}
	return 0;
}