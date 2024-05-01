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

	friend void updateNewTopScore(const string& filename, cDaiHoc);
	void readDataFromFile(const string& filename);
	void getInputStudentFromConsole(const string& filename);
	int checkGraduateList();
	/// <summary>
	/// 
	/// </summary>
	/// <param name="filename">File topScore.txt</param>
	void printTopScoreList(const string& filename);
	

	void printStudentList();
};
