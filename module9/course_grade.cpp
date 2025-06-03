#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

char Grade(const int exam1, const int exam2, const int exam3);
double Average(const vector<int>& examScores);

int main() {
    string filename;
    ifstream studentFile;
    ofstream outputFile;
    string firstName;
    string lastName;
    int exam1;
    int exam2;
    int exam3;
    char grade;
    vector<string> firstNames;
    vector<string> lastNames;
    vector<int> studentExam1;
    vector<int> studentExam2;
    vector<int> studentExam3;
    vector<string> studentGrades;
    // double exam1Average;
    // double exam2Average;
    // double exam3Average;

    cout << "Enter the name of the file: ";
    cin >> filename;
    studentFile.open(filename);
    
    if (!studentFile.is_open()) {
        cout << "Error opening file." << endl;
        return 1;
    }

    while (studentFile) {
        studentFile >> firstName >> lastName >> exam1 >> exam2 >> exam3;
        if (!studentFile.fail()) {
            firstNames.push_back(firstName);
            lastNames.push_back(lastName);
            studentExam1.push_back(exam1);
            studentExam2.push_back(exam2);
            studentExam3.push_back(exam3);
        }
    }

    studentFile.close();

    outputFile.open("report.txt");
    if (!outputFile.is_open()) {
        outputFile << "Error opening output file." << endl;
        return 1;
    }

    for (int i = 0; i < firstNames.size(); i++) {
        grade = Grade(studentExam1.at(i), studentExam2.at(i), studentExam3.at(i));

        cout << firstNames.at(i) << "\t" << lastNames.at(i) << "\t" << studentExam1.at(i) << "\t" 
        << studentExam2.at(i) << "\t" << studentExam3.at(i) << "\t" << grade << endl;
    }
   
    cout << fixed << setprecision(2);
    cout << "Averages: midterm1 " << Average(studentExam1) << ", midterm2 " << Average(studentExam2) << 
        ", final " << Average(studentExam3) << endl;

    outputFile.close();

   return 0;
}

double Average(const vector<int>& examScores) {
    double sum = 0;
    for (int i = 0; i < examScores.size(); i++) {
        sum += examScores.at(i);
    }
    return sum / examScores.size();
}

char Grade(const int exam1, const int exam2, const int exam3) {
    double average = (exam1 + exam2 + exam3) / 3.0;
    if (average >= 90) {
        return 'A';
    } else if (average >= 80) {
        return 'B';
    } else if (average >= 70) {
        return 'C';
    } else if (average >= 60) {
        return 'D';
    } else {
        return 'F';
    }
}