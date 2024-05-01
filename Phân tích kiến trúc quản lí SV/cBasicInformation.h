#pragma once
#include <string>
using namespace std;

class cBasicInformation
{
private:
	string student_ID;
	string student_name;
	string student_address;
	int credit;
	float average_score;
public:
	cBasicInformation(string ID = "", string name = "", string addr = "", int credit = 0, float score = 0);

	void getBasicInformation();
	
	string getStudentID();
	void setStudentID(string);
	
	string getStudentName();
	void setStudentName(string);

	string getStudentAddress();
	void setStudentAddress();

	int getCredit();
	void setCredit(int);

	float getScore();
	void setScore(float);
};

