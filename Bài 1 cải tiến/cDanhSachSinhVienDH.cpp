#include "cDanhSachSinhVienDH.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "cDaiHoc.h"
using namespace std;

void cDanhSachSinhVienDH::readDataFromFile(const std::string& filename) {
    ifstream file(filename);
    if (!file) {
        cerr << "Unable to open\n";
        return;
    }

    string line;
    while (std::getline(file, line)) {
        istringstream ss(line);
        string id, name, addr, thesis_name;
        int credit;
        float avg_score, thesis_score;

        getline(ss, id, '|');
        getline(ss, name, '|');
        getline(ss, addr, '|');
        ss >> credit;
        ss.ignore(1, '|');
        ss >> avg_score;
        ss.ignore(1, '|');
        getline(ss, thesis_name, '|');
        ss >> thesis_score;
        
        cDaiHoc student(id, name, addr, credit, avg_score, thesis_name, thesis_score);
        DSSV.push_back(student);
    }
}

void cDanhSachSinhVienDH::getInputStudentFromConsole(const string& filename)
{
    cDaiHoc student;
    student.getInputInformation();
    DSSV.push_back(student);
    addDataIntoFile(filename, student);
}

int cDanhSachSinhVienDH::checkGraduateList()
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

void cDanhSachSinhVienDH::printStudentList()
{
    for (auto i = DSSV.begin(); i != DSSV.end(); i++)
        i->printData();
}