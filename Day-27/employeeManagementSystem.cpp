#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <sstream>

using namespace std;

struct employee {
    string name;
    int employee_id;
    string department;
    float salary;
};
//function prototypes
void add_employee(vector<employee>& employees, employee new_employee);
void display_employees(const vector<employee>& employees);
void group_employees_by_department(vector<employee>& employees);
void sort_employees_by_salary(vector<employee>& employees);
void sort_employees_by_name(vector<employee>& employees);
void sort_employees_by_id(vector<employee>& employees);


int main() {
    ifstream file("employees.csv");
    if (!file.is_open()) {
        cerr << "Error opening file." << endl;
        return 1;
    }
    vector<employee> employees;

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string name, idStr, department, salaryStr;

        getline(ss, name, ',');
        getline(ss, idStr, ',');
        getline(ss, department, ',');
        getline(ss, salaryStr, ',');

        employees.push_back({
            name,
            stoi(idStr),
            department,
            stof(salaryStr)
        });
    }

    while (true) {
        cout << "1. Add Employee\n2. Display Employees\n3. Group Employees by Department\n4. Sort Employees\n5. Exit\n";
        int choice;
        cin >> choice;

        if (choice == 1) {
            employee new_employee;
            cout << "Enter name, employee ID, department, salary: ";
            cin >> new_employee.name >> new_employee.employee_id >> new_employee.department >> new_employee.salary;
            ofstream out_file("employees.csv", ios::app);
            if (!out_file.is_open()) {
                cerr << "Error opening file for writing." << endl;
                continue;
            }
            out_file << new_employee.name << "," << new_employee.employee_id << "," << new_employee.department << "," << new_employee.salary << "\n";
            out_file.close();
            add_employee(employees, new_employee);
        } else if (choice == 2) {
            display_employees(employees);
        } else if (choice == 3) {
            group_employees_by_department(employees);
        } else if (choice == 4) {
            cout << "Sort by:\n1. Name\n2. Employee ID\n3. Salary\n";
            int sort_choice;
            cin >> sort_choice;
            if (sort_choice == 1) {
                sort_employees_by_name(employees);
                cout << "Employees sorted by name.\n";
                display_employees(employees);
            } else if (sort_choice == 2) {
                sort_employees_by_id(employees);
                cout << "Employees sorted by employee ID.\n";
                display_employees(employees);
            } else if (sort_choice == 3) {
                sort_employees_by_salary(employees);
                cout << "Employees sorted by salary.\n";
                display_employees(employees);
            } else {
                cout << "Invalid choice. Please try again." << endl;
            }
        } else if (choice == 5) {
            break;
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}

void add_employee(vector<employee>& employees, employee new_employee) {
    employees.push_back(new_employee);
}
void display_employees(const vector<employee>& employees) {
    cout << "Name\tEmployee ID\tDepartment\tSalary\n";
    for (const auto& e : employees) {
        cout << e.name << "\t" << e.employee_id << "\t" << e.department << "\t" << e.salary << endl;
    }
}
vector<string> get_unique_departments(const vector<employee>& employees) {
    vector<string> departments;
    for (const auto& e : employees) {
        if (find(departments.begin(), departments.end(), e.department) == departments.end()) {
            departments.push_back(e.department);
        }
    }
    return departments;
}

void group_employees_by_department(vector<employee>& employees) {
    auto departments = get_unique_departments(employees);
    for (const auto& dept : departments) {
        cout << "Department: " << dept << endl;
        for (const auto& e : employees) {
            if (e.department == dept) {
                cout << "\t" << e.name << " (" << e.employee_id << ")" << endl;
            }
        }
    }
}
void sort_employees_by_salary(vector<employee>& employees) {
    sort(employees.begin(), employees.end(), [](const employee& a, const employee& b) {
        return a.salary > b.salary; // Sort in descending order of salary
    });
}
void sort_employees_by_name(vector<employee>& employees) {
    sort(employees.begin(), employees.end(), [](const employee& a, const employee& b) {
        return a.name < b.name; // Sort in ascending order of name
    });
}
void sort_employees_by_id(vector<employee>& employees) {
    sort(employees.begin(), employees.end(), [](const employee& a, const employee& b) {
        return a.employee_id < b.employee_id; // Sort in ascending order of employee ID
    });
}