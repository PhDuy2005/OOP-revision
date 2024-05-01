#pragma once
#include <string>
using namespace std;
#include "cCaoDang.h"
#include "cDaiHoc.h"
#include "cBasicInformation.h"

class cSinhVien
{
private:
	cBasicInformation information;
	char he_dao_tao;

	cCaoDang* cao_dang;
	cDaiHoc* dai_hoc;
public:
	cSinhVien() {};

	void getStudentData();
};

