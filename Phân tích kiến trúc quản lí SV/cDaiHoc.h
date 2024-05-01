#pragma once
#include <string>
using namespace std;

class cDaiHoc
{
private:
	string thesis_name;
	float thesis_score;
public:
	string getThesisName();
	void setThesisName(string);

	float getThesisScore();
	void setThesisScore(float);

	void setThesisData(string, float);
	void getThesisInput();
};

