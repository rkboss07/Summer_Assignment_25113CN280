#include <iostream> 
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>

using namespace std;

struct student {
    string name;
    int age, roll_no, marks;
};

//function prototypes
void add_student(vector<student> &students, student new_student);
void display_students(const vector<student>& students);
void sort_students_by_marks(vector<student>& students);
student find_student_by_roll_no(vector<student>& students, int roll_no);

// Main function
int main() {

    ifstream file("students.csv");
    if (!file.is_open()) {
        cerr << "Error opening file." << endl;
        return 1;
    }
    vector<student> students;


    string line;
    while (getline(file, line)) {
        stringstream ss(line);

        string name, ageStr, rollStr, marksStr;

        getline(ss, name, ',');
        getline(ss, ageStr, ',');
        getline(ss, rollStr, ',');
        getline(ss, marksStr, ',');

        students.push_back({
            name,
            stoi(ageStr),
            stoi(rollStr),
            stoi(marksStr)
        });
    }

    while (true) {
        cout << "1. Add Student\n2. Display Students\n3. Sort Students by Marks\n4. Find Student by Roll No\n5. Exit\n";
        int choice;
        cin >> choice;

        if (choice == 1) {
            student new_student;
            cout << "Enter name, age, roll no, marks: ";
            cin >> new_student.name >> new_student.age >> new_student.roll_no >> new_student.marks;
            ofstream out_file("students.csv", ios::app);
            if (!out_file.is_open()) {
                cerr << "Error opening file for writing." << endl;
                continue;
            }
            out_file << new_student.name << "," << new_student.age << "," << new_student.roll_no << "," << new_student.marks << "\n";
            out_file.close();
            add_student(students, new_student);
        } else if (choice == 2) {
            display_students(students);
        } else if (choice == 3) {
            sort_students_by_marks(students);
            cout << "Students sorted by marks.\n";
            display_students(students);
        } else if (choice == 4) {
            int roll_no;
            cout << "Enter roll no to find: ";
            cin >> roll_no;
            student found_student = find_student_by_roll_no(students, roll_no);
            if (found_student.roll_no != 0) {
                cout << "Found Student - Name: " << found_student.name << ", Age: " << found_student.age 
                     << ", Roll No: " << found_student.roll_no << ", Marks: " << found_student.marks << endl;
            } else {
                cout << "Student not found.\n";
            }
        } else if (choice == 5) {
            break;
        } else {
            cout << "Invalid choice. Please try again.\n";
        }
    }
}
//function to sort students by marks in descending order
void sort_students_by_marks(vector<student>& students) {
    sort(students.begin(), students.end(), [](const student& a, const student& b) {
        return a.marks > b.marks; // Sort in descending order of marks
    });

}
//function to find student by roll number
student find_student_by_roll_no(vector<student>& students, int roll_no){
    for (int i = 0; i < students.size(); i++) {
        if (students[i].roll_no == roll_no) {
            return students[i];
        }
    }
    // Return a default student if not found
    return {"", 0, 0, 0};
}
//function to add a new student to the vector
void add_student(vector<student> &students, student new_student) {
    students.push_back(new_student);
}

void display_students(const vector<student>& students) {
    cout <<"Name\tAge\tRoll No\tMarks\n";
    for (const auto& s : students) {
        cout << s.name << "\t" << s.age << "\t" << s.roll_no << "\t" << s.marks << endl;
    }
}