#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <limits>

using namespace std;

class StudentScholarship
{
private:
    string studentName;
    string indexNumber;
    string programme;
    int level;
    double gpa;
    double attendancePercentage;
    string conductStatus;
    string eligibilityStatus;

public:

    void setStudentDetails()
    {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "\nEnter Student Name: ";
        getline(cin, studentName);

        cout << "Enter Index Number: ";
        getline(cin, indexNumber);

        cout << "Enter Programme: ";
        getline(cin, programme);

        cout << "Enter Level: ";
        cin >> level;

        do
        {
            cout << "Enter GPA (0 - 4): ";
            cin >> gpa;

            if(gpa < 0 || gpa > 4)
                cout << "Invalid GPA. Please enter a value between 0 and 4.\n";

        } while(gpa < 0 || gpa > 4);

        do
        {
            cout << "Enter Attendance Percentage (0 - 100): ";
            cin >> attendancePercentage;

            if(attendancePercentage < 0 || attendancePercentage > 100)
                cout << "Invalid Attendance. Please enter a value between 0 and 100.\n";

        } while(attendancePercentage < 0 || attendancePercentage > 100);

        cin.ignore();

        cout << "Enter Conduct Status (Good/Poor): ";
        getline(cin, conductStatus);
    }

    void checkEligibility()
    {
        if(gpa >= 3.5 &&
           attendancePercentage >= 80 &&
           (conductStatus == "Good" || conductStatus == "good"))
        {
            eligibilityStatus = "Eligible for Scholarship";
        }
        else if(gpa < 3.5)
        {
            eligibilityStatus = "Not Eligible - GPA below requirement";
        }
        else if(attendancePercentage < 80)
        {
            eligibilityStatus = "Not Eligible - Attendance below requirement";
        }
        else
        {
            eligibilityStatus = "Not Eligible - Conduct requirement not met";
        }
    }

    bool isEligible()
    {
        return eligibilityStatus == "Eligible for Scholarship";
    }

    void displayReport()
    {
        cout << "\n----------------------------------------\n";
        cout << "Student Name : " << studentName << endl;
        cout << "Index Number : " << indexNumber << endl;
        cout << "Programme    : " << programme << endl;
        cout << "Level        : " << level << endl;
        cout << fixed << setprecision(2);
        cout << "GPA          : " << gpa << endl;
        cout << "Attendance   : " << attendancePercentage << "%" << endl;
        cout << "Conduct      : " << conductStatus << endl;
        cout << "Result       : " << eligibilityStatus << endl;
    }

    void saveReport(ofstream &file)
    {
        file << "----------------------------------------\n";
        file << "Student Name : " << studentName << endl;
        file << "Index Number : " << indexNumber << endl;
        file << "Programme    : " << programme << endl;
        file << "Level        : " << level << endl;
        file << fixed << setprecision(2);
        file << "GPA          : " << gpa << endl;
        file << "Attendance   : " << attendancePercentage << "%" << endl;
        file << "Conduct      : " << conductStatus << endl;
        file << "Result       : " << eligibilityStatus << endl;
    }
};

int main()
{
    cout << "=============================================\n";
    cout << "      SCHOLARSHIP ELIGIBILITY CHECKER\n";
    cout << "=============================================\n";

    int numberOfStudents;

    cout << "\nEnter Number of Students: ";
    cin >> numberOfStudents;

    vector<StudentScholarship> students;

    ofstream report("scholarship_report.txt");

    if(!report)
    {
        cout << "Error creating report file.\n";
        return 1;
    }

    int eligibleCount = 0;
    int notEligibleCount = 0;

    for(int i = 0; i < numberOfStudents; i++)
    {
        cout << "\n=====================================\n";
        cout << "Student " << i + 1 << endl;
        cout << "=====================================\n";

        StudentScholarship student;

        student.setStudentDetails();
        student.checkEligibility();
        student.displayReport();
        student.saveReport(report);

        if(student.isEligible())
            eligibleCount++;
        else
            notEligibleCount++;

        students.push_back(student);
    }

    cout << "\n=====================================\n";
    cout << "SUMMARY REPORT\n";
    cout << "=====================================\n";
    cout << "Total Eligible Students     : " << eligibleCount << endl;
    cout << "Total Not Eligible Students : " << notEligibleCount << endl;

    report << "\n=====================================\n";
    report << "SUMMARY REPORT\n";
    report << "=====================================\n";
    report << "Total Eligible Students     : " << eligibleCount << endl;
    report << "Total Not Eligible Students : " << notEligibleCount << endl;

    report.close();

    cout << "\nReport saved successfully as scholarship_report.txt\n";

    return 0;
}
