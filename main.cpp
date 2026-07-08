#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

struct Course
{
    string name;
    int creditHours;
    string grade;
    double gradePoint;
};
double calculateGradePoint(string grade)
{
    if (grade == "A")
        return 4.0;
    else if (grade == "B")
        return 3.0;
    else if (grade == "C")
        return 2.0;
    else if (grade == "D")
        return 1.0;
    else if (grade == "F")
        return 0.0;
    else
        return -1;
}

int main()
{
    cout << "=========================================\n";
    cout << "        CGPA CALCULATOR SYSTEM\n";
    cout << "=========================================\n\n";

    int numberOfCourses;

    cout << "Enter number of courses: ";
    cin >> numberOfCourses;

vector<Course> courses(numberOfCourses);
for (int i = 0; i < numberOfCourses; i++)
{
    cout << "\nEnter details for course " << i + 1 << endl;

    cout << "Course name: ";
    cin >> courses[i].name;

    cout << "Credit hours: ";
    cin >> courses[i].creditHours;

    cout << "Grade (A, B, C, D, F): ";
    cin >> courses[i].grade;
    courses[i].gradePoint = calculateGradePoint(courses[i].grade);
}
double totalGradePoints = 0;
int totalCredits = 0;

for (int i = 0; i < numberOfCourses; i++)
{
    totalCredits += courses[i].creditHours;
    totalGradePoints += courses[i].gradePoint * courses[i].creditHours;
}

double cgpa = totalGradePoints / totalCredits;
cout << "\n================================================\n";
cout << "              COURSE SUMMARY\n";
cout << "================================================\n";

cout << left 
     << setw(20) << "Course"
     << setw(15) << "Credit Hours"
     << setw(10) << "Grade"
     << setw(10) << "Points" << endl;

cout << "------------------------------------------------\n";

for (int i = 0; i < numberOfCourses; i++)
{
    cout << left
         << setw(20) << courses[i].name
         << setw(15) << courses[i].creditHours
         << setw(10) << courses[i].grade
         << setw(10) << courses[i].gradePoint << endl;
}

cout << "================================================\n";
cout << "\n=========================================\n";
cout << "              CGPA RESULT\n";
cout << "=========================================\n";

cout << fixed << setprecision(2);

cout << "Total Credits: " << totalCredits << endl;
cout << "CGPA: " << cgpa << endl;

cout << "=========================================\n";
return 0;
}