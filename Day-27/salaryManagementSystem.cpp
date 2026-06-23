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
    double salary;
};
//function prototypes
void sort_employees_by_salary(vector<employee>& employees);
string unique_departments(const vector<employee>& employees);
int average_salary_by_department(const vector<employee>& employees, const string& department);
void increase_salary_by_department(vector<employee>& employees, const string& department, double percentage);
void increase_salary_of_an_employee(vector<employee>& employees, int employee_id, double percentage);
void increase_salary_of_all_employees(vector<employee>& employees, double percentage);
void save_to_csv(const vector<employee>& employees);


int main() {
    ifstream file("employees.csv");
    vector<employee> employees;
    if (!file.is_open()) {
        cerr << "Error opening file." << endl;
        return 1;
    }
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
            stod(salaryStr)
        });
    }

    while (true) {
        cout << "1. Sort Employees by Salary\n2. Display Unique Departments\n3. Average Salary by Department\n4. Increase Salary\n5. Exit\n";
        int choice;
        cin >> choice;

        if (choice == 1) {
            sort_employees_by_salary(employees);
            cout << "Employees sorted by salary.\n";
            for (const auto& emp : employees) {
                cout << emp.name << ", " << emp.employee_id << ", " << emp.department << ", " << emp.salary << endl;
            }
        } else if (choice == 2) {
            string departments = unique_departments(employees);
            cout << "Unique Departments: " << departments << endl;
        } else if (choice == 3) {
            string department;
            cout << "Enter department name: ";
            cin >> department;
            double avg_salary = average_salary_by_department(employees, department);
            if (avg_salary > 0) {
                cout << "Average salary in " << department << ": " << avg_salary << endl;
            } else {
                cout << "No employees found in the specified department." << endl;
            }
        } else if (choice == 4) {
            int sub_choice;
            cout << "1. Increase salary of a specific employee\n2. Increase salary of all employees in a department\n3. Increase salary of all employees\n";
            cin >> sub_choice;

            if (sub_choice == 1) {
                int employee_id;
                double percentage;
                cout << "Enter employee ID and percentage increase: ";
                cin >> employee_id >> percentage;
                increase_salary_of_an_employee(employees, employee_id, percentage);
                save_to_csv(employees);
                cout << "Salary updated for employee ID: " << employee_id << endl;
            } else if (sub_choice == 2) {
                string department;
                double percentage;
                cout << "Enter department name and percentage increase: ";
                cin >> department >> percentage;
                increase_salary_by_department(employees, department, percentage);
                save_to_csv(employees);
                cout << "Salaries updated for department: " << department << endl;
            } else if (sub_choice == 3) {
                double percentage;
                cout << "Enter percentage increase for all employees: ";
                cin >> percentage;
                increase_salary_of_all_employees(employees, percentage);
                save_to_csv(employees);
                cout << "Salaries updated for all employees." << endl;
            }
        } else if (choice == 5) {
            break;
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }
}

void sort_employees_by_salary(vector<employee>& employees) {
    sort(employees.begin(), employees.end(), [](const employee& a, const employee& b) {
        return a.salary < b.salary;
    });
}
string unique_departments(const vector<employee>& employees) {
    string departments;
    for (const auto& emp : employees) {
        if (departments.find(emp.department) == string::npos) {
            departments += emp.department + ",";
        }
    }
    if (!departments.empty()) {
        departments.pop_back(); // Remove the trailing comma
    }
    return departments;
}

int average_salary_by_department(const vector<employee>& employees, const string& department) {
    double total_salary = 0;
    int count = 0;
    for (const auto& emp : employees) {
        if (emp.department == department) {
            total_salary += emp.salary;
            count++;
        }
    }
    return count > 0 ? total_salary / count : 0;
}

void increase_salary_by_department(vector<employee>& employees, const string& department, double percentage) {
    for (auto& emp : employees) {
        if (emp.department == department) {
            emp.salary += emp.salary * (percentage / 100);
        }
    }
}

void increase_salary_of_an_employee(vector<employee>& employees, int employee_id, double percentage) {
    for (auto& emp : employees) {
        if (emp.employee_id == employee_id) {
            emp.salary += emp.salary * (percentage / 100);
            break;
        }
    }
}

void increase_salary_of_all_employees(vector<employee>& employees, double percentage) {
    for (auto& emp : employees) {
        emp.salary += emp.salary * (percentage / 100);
    }
}
void save_to_csv(const vector<employee>& employees) {
    ofstream file("employees.csv");

    for (const auto& emp : employees) {
        file << emp.name << ","
             << emp.employee_id << ","
             << emp.department << ","
             << emp.salary << "\n";
    }
}