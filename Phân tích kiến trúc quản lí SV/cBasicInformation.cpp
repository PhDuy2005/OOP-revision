#include "cBasicInformation.h"
#include <iostream>
#include <string>
using namespace std;

cBasicInformation::cBasicInformation(string ID, string name, string addr, int credit, float score)
{
	student_ID = ID;
	student_name = name;
	student_address = addr;
	this->credit = credit;
	average_score = score;
}

void cBasicInformation::getBasicInformation()
{
	cout << "Nhap MSSV:\n";
	getline(cin, student_ID);

	cout << "Nhap ho ten SV:\n";
	getline(cin, student_name);

	cout << "Nhap dia chi SV:\n";
	getline(cin, student_address);

	cout << "Nhap so tin chi cua SV: ";
	cin >> credit;

	cout << "Nhap diem trung binh cua SV: ";
	cin >> average_score;
}
