#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;
#include <vector>
#include "cDanhSachSinhVienDH.h"
#include "cDanhSachSinhVienCD.h"

fstream file("DSSV.txt", ios_base::app | ios_base::in);

string file_dh = "DSSV_DH.txt";
string file_cd = "DSSV_CD.txt";
string file_topScore_dh = "topScore_DH.txt";
string file_topScore_cd = "topScore_CD.txt";

void mainLoop(cDanhSachSinhVienDH&, cDanhSachSinhVienCD&);
void option1(cDanhSachSinhVienDH& ds_sv_dh);
void option2(cDanhSachSinhVienCD& ds_sv_cd);
void option3(cDanhSachSinhVienDH ds_sv_dh);
void option4(cDanhSachSinhVienCD ds_sv_cd);
void option5(cDanhSachSinhVienDH, cDanhSachSinhVienCD);

int main() {
	cDanhSachSinhVienDH ds_sv_dh;
	ds_sv_dh.readDataFromFile(file_dh);

	cDanhSachSinhVienCD ds_sv_cd;
	ds_sv_cd.readDataFromFile(file_cd);

	//ds_sv_dh.getInputStudentFromConsole(file_dh);
	//mainLoop(ds_sv_dh, ds_sv_cd);
	//option4(ds_sv_cd);
	option5(ds_sv_dh, ds_sv_cd);
	return 0;
}

void mainLoop(cDanhSachSinhVienDH& ds_sv_dh, cDanhSachSinhVienCD& ds_sv_cd) {
	int selection = -1;
	while (selection != 0) {
		system("cls");
		cout << "Hay chon chuc nang:\n";
		cout << "1. Nhap thong tin cua 1 sinh vien he DH tu man hinh\n";
		cout << "2. Nhap thong tin cua 1 sinh vien he CD tu man hinh\n";
		cout << "3. Xuat danh sach sinh vien he DH\n";
		cout << "4. Xuat danh sach sinh vien he CD\n";
		cout << "5. Xuat danh sach sinh vien du dieu kien tot nghiep\n";
		cout << "6. Tim sinh vien co diem trung binh cao nhat cua he DH\n";
		cout << "7. Tim sinh vien co diem trung binh cao nhat cua he CD\n";
		cout << "0. Ket thuc chuong trinh\n";
		cin >> selection;
	}
}

void option1(cDanhSachSinhVienDH& ds_sv_dh)
{
	ds_sv_dh.getInputStudentFromConsole(file_dh);
}

void option2(cDanhSachSinhVienCD& ds_sv_cd)
{
	ds_sv_cd.getInputStudentFromConsole(file_cd);
}

void option3(cDanhSachSinhVienDH ds_sv_dh) {
	ds_sv_dh.printStudentList();
}

void option4(cDanhSachSinhVienCD ds_sv_cd)
{
	ds_sv_cd.printStudentList();
}

void option5(cDanhSachSinhVienDH ds_sv_dh, cDanhSachSinhVienCD ds_sv_cd) {
	int grad_dh = ds_sv_dh.checkGraduateList();
	int grad_cd = ds_sv_cd.checkGraduateList();
	cout << "Tong cong co " << grad_cd + grad_dh << " sinh vien du dieu kien tot nghiep, bao gom " << grad_dh << " sinh vien thuoc he DH va " << grad_cd << " sinh vien thuoc he cao dang";
}