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

void updateNewTopScore(const string& filename, cDaiHoc student)
{
    ifstream fileIn(filename, ios_base::in);
    string str_top_score;
    getline(fileIn, str_top_score);
    float top_score = stof(str_top_score);
    fileIn.close();

    if (student.getAverageScore() > top_score) {
        ofstream fileOut(filename);
        fileOut << top_score << endl;
        addDataIntoFile(filename, student);
        fileOut.close();
        return;
    }

    if (student.getAverageScore() == top_score) {
        ofstream fileOut(filename, ios_base::app);
        addDataIntoFile(filename, student);
        fileOut.close();
        return;
    }

    if (student.getAverageScore() < top_score)
        return;
}

void cDanhSachSinhVienDH::getInputStudentFromConsole(const string& filename)
{
    cDaiHoc student;
    student.getInputInformation();
    DSSV.push_back(student);
    addDataIntoFile(filename, student);
    updateNewTopScore("topScore_DH.txt", student);
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

void cDanhSachSinhVienDH::printTopScoreList(const string& filename)
{
    ifstream fileIn(filename, ios_base::in);

    if (!fileIn) {
        cerr << "Unable to open\n";
        return;
    }

    string str_top_score;
    getline(fileIn, str_top_score);
    float top_score = stof(str_top_score);
    cout << "Duoi day la DSSV he DH co diem cao nhat (" << top_score << "):\n";

    string line;
    while (std::getline(fileIn, line)) {
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
        student.printData();
    }

    fileIn.close();
}

void cDanhSachSinhVienDH::printStudentList()
{
    for (auto i = DSSV.begin(); i != DSSV.end(); i++)
        i->printData();
}