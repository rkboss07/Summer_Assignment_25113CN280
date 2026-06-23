#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <sstream>

using namespace std;

struct student {
    string name;
    long long roll_number;
    string course, branch;
    int semester;
    vector<int> marks;  //Marks for 5 subjects: Maths, Chemistry, Soft-Skills, Electronics, Mechanical
};


//function prototypes
void generate_marksheet(const vector<student>& students, long long roll_number);
char getGrade(int marks);
void getFailedStudents(const vector<student>& students);
void sortStudentsByCGPA(vector<student>& students);


int main() {
    vector<student> students;
    ifstream file("marksheet.csv");
    if (!file.is_open()) {
        cerr << "Error opening file.\n";
        return 1;
    }
    string line;

    while (getline(file, line)) {
        stringstream ss(line);
        student s;
        string marks_str;

        getline(ss, s.name, ',');
        ss >> s.roll_number;
        ss.ignore(); // Ignore the comma
        getline(ss, s.course, ',');
        getline(ss, s.branch, ',');
        ss >> s.semester;
        ss.ignore(); // Ignore the comma
        getline(ss, marks_str);

        getline(ss, marks_str);

        marks_str.erase(remove(marks_str.begin(),
                            marks_str.end(),
                            '['),
                        marks_str.end());

        marks_str.erase(remove(marks_str.begin(),
                            marks_str.end(),
                            ']'),
                        marks_str.end());

        marks_str.erase(remove(marks_str.begin(),
                            marks_str.end(),
                            '"'),
                        marks_str.end());

        stringstream marks_ss(marks_str);

        string temp;

        while (getline(marks_ss, temp, ',')) {
            s.marks.push_back(stoi(temp));
        }

        students.push_back(s);
    }

    int choice;
    while (true) {
        cout << "1. Generate Marksheet\n2. Display Failed Students\n3. Sort Students by CGPA\n4. Exit\n";
        cin >> choice;

        if (choice == 1) {
            long long roll_number;
            cout << "Enter roll number: ";
            cin >> roll_number;
            generate_marksheet(students, roll_number);
        } else if (choice == 2) {
            getFailedStudents(students);
        } else if (choice == 3) {
            sortStudentsByCGPA(students);
            cout << "Students sorted by CGPA.\n";
            for (const auto& s : students) {
                cout << s.name << "\t" << s.roll_number << "\t" << s.course << "\t" << s.branch << "\t" << s.semester << '\n';
            }
        } else if (choice == 4) {
            break;
        } else {
            cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}

void generate_marksheet(const vector<student>& students, long long roll_number) {

    for (const auto& s : students) {

        if (s.roll_number == roll_number) {

            int total = 0;

            if (s.marks.size() < 5) {
                cout << "Invalid marks data.\n";
                return;
            }

            for (int mark : s.marks) {
                total += mark;
            }

            double cgpa = total / 50.0;

            cout << "----------------------------------------\n";
            cout << "Name      : " << s.name << '\n';
            cout << "Roll No   : " << s.roll_number << '\n';
            cout << "Course    : " << s.course << '\n';
            cout << "Branch    : " << s.branch << '\n';
            cout << "Semester  : " << s.semester << "\n\n";

            cout << "Subject\t\tMarks\tGrade\n";
            cout << "----------------------------------------\n";

            

            cout << "Maths\t\t"        << s.marks[0] << "\t" << getGrade(s.marks[0]) << '\n';
            cout << "Chemistry\t"      << s.marks[1] << "\t" << getGrade(s.marks[1]) << '\n';
            cout << "Soft Skills\t"    << s.marks[2] << "\t" << getGrade(s.marks[2]) << '\n';
            cout << "Electronics\t"    << s.marks[3] << "\t" << getGrade(s.marks[3]) << '\n';
            cout << "Mechanical\t"     << s.marks[4] << "\t" << getGrade(s.marks[4]) << '\n';

            cout << "----------------------------------------\n";
            cout << "Total Marks : " << total << '\n';
            cout << "CGPA        : " << cgpa << '\n';
            cout << "----------------------------------------\n";

            return;
        }
    }

    cout << "Student not found.\n";
}

char getGrade(int marks) {
    if (marks >= 90) return 'A';
    else if (marks >= 80) return 'B';
    else if (marks >= 70) return 'C';
    else if (marks >= 60) return 'D';
    else return 'F';
}

void getFailedStudents(const vector<student>& students) {
    cout << "Failed Students:\n";
    cout << "----------------------------------------\n";

    for (const auto& s : students) {
        bool failed = false;

        for (int mark : s.marks) {
            if (mark < 40) {
                failed = true;
                break;
            }
        }

        if (failed) {
            cout << s.name << " | "
                 << s.roll_number << " | "
                 << s.branch << " | "
                 << s.semester << '\n';
        }
    }

    cout << "----------------------------------------\n";
}

void sortStudentsByCGPA(vector<student>& students) {
    sort(students.begin(), students.end(), [](const student& a, const student& b) {
        int totalA = 0, totalB = 0;
        for (int mark : a.marks) totalA += mark;
        for (int mark : b.marks) totalB += mark;
        return totalA > totalB; // Sort in descending order of total marks
    });
}
