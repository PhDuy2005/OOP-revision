#include "cDanhSachSinhVienCD.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "cCaoDang.h"
using namespace std;

void cDanhSachSinhVienCD::readDataFromFile(const std::string& filename) {
    ifstream file(filename);
    if (!file) {
        cerr << "Unable to open\n";
        return;
    }

    string line;
    while (std::getline(file, line)) {
        istringstream ss(line);
        string id, name, addr;
        int credit;
        float avg_score, grad_score;

        getline(ss, id, '|');
        getline(ss, name, '|');
        getline(ss, addr, '|');
        ss >> credit;
        ss.ignore(1, '|');
        ss >> avg_score;
        ss.ignore(1, '|');
        ss >> grad_score;

        cCaoDang student(id, name, addr, credit, avg_score, grad_score);
        DSSV.push_back(student);
    }
}

void cDanhSachSinhVienCD::getInputStudentFromConsole(const string& filename)
{
    cCaoDang student;
    student.getInputInformation();
    DSSV.push_back(student);
    addDataIntoFile(filename, student);
}

void cDanhSachSinhVienCD::printStudentList()
{
    for (auto i = DSSV.begin(); i != DSSV.end(); i++)
        i->printData();
}

int cDanhSachSinhVienCD::checkGraduateList()
{
    int count = 0;
    for (auto i = DSSV.begin(); i != DSSV.end(); i++) {
        if (i->ableToGraduate() == true) {
            i->printData();
            count++;
        }
    }
    return count;
}