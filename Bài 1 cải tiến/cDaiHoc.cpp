#include "cDaiHoc.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

cDaiHoc::cDaiHoc(string ID, string name, string addr, int inp_credit, float avg_score, string inp_thesis_name, float inp_thesis_score)
{
	student_ID = ID;
	student_name = name;
	student_address = addr;
	credit = inp_credit;
	average_score = avg_score;

	thesis_name = inp_thesis_name;
	thesis_score = inp_thesis_score;
}

float cDaiHoc::getAverageScore()
{
	return average_score;
}

void cDaiHoc::getInputInformation()
{
	cout << "Nhap MSSV: ";
	getline(cin, student_ID);

	cout << "Nhap ho ten cua SV: ";
	getline(cin, student_name);

	cout << "Nhap dia chi nha cua SV: ";
	getline(cin, student_address);

	cout << "Nhap tong so tin chi cua SV: ";
	cin >> credit;

	cout << "Nhap diem trung binh cua SV: ";
	cin >> average_score;

	cin.ignore();
	cout << "Nhap ten luan van tot nghiep cua SV: ";
	getline(cin, thesis_name);

	cout << "Nhap diem luan van cua SV: ";
	cin >> thesis_score;
}

void addDataIntoFile(const string& filename, cDaiHoc student)
{
	fstream fileOut(filename, ios_base::app);
	fileOut << student.student_ID << "|"
		<< student.student_name << "|"
		<< student.student_address << "|"
		<< student.credit << "|"
		<< student.average_score << "|"
		<< student.thesis_name << "|"
		<< student.thesis_score << endl;
}

void cDaiHoc::printData() {
	cout << "MSSV: " << student_ID << endl;
	cout << "Ho va ten SV: " << student_name << endl;
	cout << "Dia chi cua SV: " << student_address << endl;
	cout << "Tong so tin chi cua SV: " << credit << endl;
	cout << "Diem trung binh cua SV: " << average_score << endl;
	cout << "Ten luan van tot nghiep: " << thesis_name << endl;
	cout << "Diem luan van: " << thesis_score << endl;
}

bool cDaiHoc::ableToGraduate() {
	if (credit < 145)
		return false;
	if (average_score < 5)
		return false;
	if (thesis_score < 5)
		return false;
	return true;
}