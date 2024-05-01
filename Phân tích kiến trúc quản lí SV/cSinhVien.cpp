#include "cSinhVien.h"
#include <iostream>
#include <string>
using namespace std;

void cSinhVien::getStudentData()
{
	information.getBasicInformation();
	cout << "Nhap 'd' de bieu thi SV thuoc he dao tao DH hoac 'c' de bieu thi SV thuoc he dao tao CD\n";
	cout << "Moi nhap he dao tao cua SV: ";
	cin >> he_dao_tao;

	switch (he_dao_tao) {
	case 'd':
		cao_dang = nullptr;
		dai_hoc = new cDaiHoc;
		dai_hoc->getThesisInput();
		break;
	case 'c':
		dai_hoc = nullptr;
		cao_dang = new cCaoDang;
		cao_dang->getGradScoreInput();
	}
}
