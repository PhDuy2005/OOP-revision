#include "cDaiHoc.h"
#include <iostream>
#include <string>
using namespace std;

void cDaiHoc::getThesisInput()
{
	cout << "Nhap ten luan van:\n";
	cin.ignore();
	getline(cin, thesis_name);

	cout << "Nhap diem luan van: ";
	cin >> thesis_score;
}
