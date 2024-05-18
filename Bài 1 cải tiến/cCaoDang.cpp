#include "cCaoDang.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

cCaoDang::cCaoDang(string ID, string name, string addr, int inp_credit, float avg_score, float grad_score)
{
	student_ID = ID;
	student_name = name;
	student_address = addr;
	credit = inp_credit;
	average_score = avg_score;

	graduate_score = grad_score;
}

float cCaoDang::getAverageScore()
{
	return average_score;
}

void cCaoDang::getInputInformation()
{
	cout << "Nhap MSSV: ";
	cin.ignore();
	getline(cin, student_ID);

	cout << "Nhap ho ten cua SV: ";
	getline(cin, student_name);

	cout << "Nhap dia chi nha cua SV: ";
	getline(cin, student_address);

	cout << "Nhap tong so tin chi cua SV: ";
	cin >> credit;

	cout << "Nhap diem trung binh cua SV: ";
	cin >> average_score;

	cout << "Nhap diem tot nghiep SV: ";
	cin >> graduate_score;
}

void addDataIntoFile(const string& filename, cCaoDang student)
{
	fstream fileOut(filename, ios_base::app);
	fileOut << student.student_ID << "|"
		<< student.student_name << "|"
		<< student.student_address << "|"
		<< student.credit << "|"
		<< student.average_score << "|"
		<< student.graduate_score << endl;
	fileOut.close();
}

void cCaoDang::printData() {
	cout << "MSSV: " << student_ID << endl;
	cout << "Ho va ten SV: " << student_name << endl;
	cout << "Dia chi cua SV: " << student_address << endl;
	cout << "Tong so tin chi cua SV: " << credit << endl;
	cout << "Diem trung binh cua SV: " << average_score << endl;
	cout << "Diem tot nghiep: " << graduate_score << endl;
}

bool cCaoDang::ableToGraduate() {
	if (credit < 110)
		return false;
	if (average_score < 5)
		return false;
	if (graduate_score < 5)
		return false;
	return true;
}