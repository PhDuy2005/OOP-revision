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

	friend void updateNewTopScore(const string& filename, cCaoDang); 
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

