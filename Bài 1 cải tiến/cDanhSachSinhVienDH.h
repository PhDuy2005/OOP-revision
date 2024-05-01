#pragma once
#include <vector>
#include "cDaiHoc.h"
using namespace std;

class cDanhSachSinhVienDH
{
private:
	vector<cDaiHoc> DSSV;
public:
	cDanhSachSinhVienDH() {}

	void readDataFromFile(const string& filename);
	void getInputStudentFromConsole(const string& filename);
	int checkGraduateList();

	void printStudentList();
};
