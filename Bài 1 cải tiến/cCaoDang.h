#pragma once
#include <string>
using namespace std;

class cCaoDang
{
private:
	string student_ID;
	string student_name;
	string student_address;
	int credit;
	float average_score;

	float graduate_score;
public:
	cCaoDang(string ID = "", string name = "", string addr = "", int inp_credit = 0, float avg_score = 0, float grad_score = 0);
	float getAverageScore();

	void getInputInformation();
	void printData();
	bool ableToGraduate();

	friend void addDataIntoFile(const string& filename, cCaoDang);
};

