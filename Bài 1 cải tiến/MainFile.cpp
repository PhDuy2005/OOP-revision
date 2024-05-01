#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;
#include "cDanhSachSinhVienDH.h"
#include "cDanhSachSinhVienCD.h"

fstream file("DSSV.txt", ios_base::app | ios_base::in);

string file_dh = "DSSV_DH.txt";
string file_cd = "DSSV_CD.txt";
string file_topScore_dh = "topScore_DH.txt"; //Neu sua duong dan file nay, xin vui long sua luon duong dan trong cDanhSachSinhVienDH.cpp
string file_topScore_cd = "topScore_CD.txt"; ////Neu sua duong dan file nay, xin vui long sua luon duong dan trong cDanhSachSinhVienCD.cpp

void mainLoop(cDanhSachSinhVienDH&, cDanhSachSinhVienCD&);
void option1(cDanhSachSinhVienDH& ds_sv_dh);
void option2(cDanhSachSinhVienCD& ds_sv_cd);
void option3(cDanhSachSinhVienDH ds_sv_dh);
void option4(cDanhSachSinhVienCD ds_sv_cd);
void option5(cDanhSachSinhVienDH, cDanhSachSinhVienCD);
void option6(cDanhSachSinhVienDH);
void option7(cDanhSachSinhVienCD);

int main() {
	cDanhSachSinhVienDH ds_sv_dh;
	ds_sv_dh.readDataFromFile(file_dh);

	cDanhSachSinhVienCD ds_sv_cd;
	ds_sv_cd.readDataFromFile(file_cd);

	mainLoop(ds_sv_dh, ds_sv_cd);

	cout << "Cam on vi da su dung chuong trinh!\n";
	cout << "Neu chuong trinh co loi ki thuat, xin vui long gop y tai 23520384@gm.uit.edu.vn hoac qua cac hinh thuc tin nhan\n";
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
		cout << "8. Xoa SV he DH theo MSSV\n";
		cout << "9. Xoa SV he CD theo MSSV\n";
		cout << "0. Ket thuc chuong trinh\n";
		cout << "------------------------------------------------------\n";
		cout << "Nhap chuc nang: ";
		cin >> selection;
		system("cls");

		switch (selection) {
		case 1:
			option1(ds_sv_dh);
			cout << "\n\nNhan enter de tiep tuc!";
			system("pause");
			break;
		case 2:
			option2(ds_sv_cd);
			cout << "\n\nNhan enter de tiep tuc!";
			system("pause");
			break;
		case 3:
			option3(ds_sv_dh);
			cout << "\n\nNhan enter de tiep tuc!";
			system("pause");
			break;
		case 4:
			option4(ds_sv_cd);
			cout << "\n\nNhan enter de tiep tuc!";
			system("pause");
			break;
		case 5:
			option5(ds_sv_dh, ds_sv_cd);
			cout << "\n\nNhan enter de tiep tuc!";
			system("pause");
			break;
		case 6:
			option6(ds_sv_dh);
			cout << "\n\nNhan enter de tiep tuc!";
			system("pause");
			break;
		case 7:
			option7(ds_sv_cd);
			cout << "\n\nNhan enter de tiep tuc!";
			system("pause");
			break;
		case 8:
		case 9:
			cout << "Tinh nang chua duoc phat trien do lap trinh vien chua du trinh do";
			cout << "\n\nNhan enter de tiep tuc!";
			system("pause");
			break;
		case 0:
			break;
		default:
			cout << "So khong hop le, nhan enter de ket thuc chuong trinh";
			selection = 0;
			system("pause");
			break;
		}
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

void option6(cDanhSachSinhVienDH ds_sv_dh) {
	ds_sv_dh.printTopScoreList(file_topScore_dh);
}

void option7(cDanhSachSinhVienCD ds_sv_cd) {
	ds_sv_cd.printTopScoreList(file_topScore_cd);
}