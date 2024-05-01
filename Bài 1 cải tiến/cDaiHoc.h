#pragma once
#include <string>
using namespace std;

class cDaiHoc
{
private:
	string student_ID;
	string student_name;
	string student_address;
	int credit;
	float average_score;

	string thesis_name;
	float thesis_score;
public:
	cDaiHoc(string ID = "", string name = "", string addr = "", int inp_credit = 0, float avg_score = 0, string inp_thesis_name = "", float inp_thesis_score = 0);
	float getAverageScore();

	void getInputInformation();
	void printData();
	bool ableToGraduate();

	friend void addDataIntoFile(const string& filename, cDaiHoc);
};

