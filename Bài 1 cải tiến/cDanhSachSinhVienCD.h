#pragma once
#include <vector>
#include "cCaoDang.h"
using namespace std;

class cDanhSachSinhVienCD
{
private:
	vector<cCaoDang> DSSV;
public:
	cDanhSachSinhVienCD() {}

	void readDataFromFile(const string& filename);
	void getInputStudentFromConsole(const string& filename);
	int checkGraduateList();

	void printStudentList();
};

