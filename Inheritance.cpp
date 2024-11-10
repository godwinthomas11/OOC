// Develop an object oriented program in C++ to create a base class Employee and derived classes
// SalariedEmployee, HourlyEmployee and CommisionEmployee.
// The class Employee has data members: string Ename, int EmpID and has a default constructor
// and parameterized constructor. It has two virtual functions accept() to receive data member
// values from the user and display() to output data member values; and a pure virtual function
// earnings().
// The class SalariedEmployee has a data member: double weeklysalary and has a default
// constructor and parameterized constructor. The function earnings() displays weekly salary.
// The class HourlyEmployee has data members: double wage, double hours and double
// Hourlysalary; and has a default constructor and parameterized constructor. The function
// earnings() is defined as
// if(hours&lt;40)
// { Hourlysalary= hours*wage; }
// else
// { Hourlysalary=40*wage + ((hours-40)*wage)*1.5; }
// The class CommisionEmployee has data members: double grossSales, double commissionRate,
// double Commisionsalary; and has a default constructor and parameterized constructor. The
// function earnings() is defined as Commisionsalary = grossSales * commissionRate;
// Create objects of derived classes and display their earnings


#include <iostream>
#include <string>
using namespace std;

// Base class Employee
class Employee {
protected:
    string Ename;
    int EmpID;

public:
    // Default constructor
    Employee() {
        Ename = "Unknown";
        EmpID = 0;
    }

    // Parameterized constructor
    Employee(string name, int id) {
        Ename = name;
        EmpID = id;
    }

    // Virtual function to accept data from the user
    virtual void accept() {
        cout << "Enter employee name: ";
        cin >> Ename;
        cout << "Enter employee ID: ";
        cin >> EmpID;
    }

    // Virtual function to display employee details
    virtual void display() {
        cout << "Employee Name: " << Ename << endl;
        cout << "Employee ID: " << EmpID << endl;
    }

    // Pure virtual function for earnings
    virtual double earnings() = 0;
};

// Derived class SalariedEmployee
class SalariedEmployee : public Employee {
private:
    double weeklySalary;

public:
    // Default constructor
    SalariedEmployee() : Employee() {
        weeklySalary = 0.0;
    }

    // Parameterized constructor
    SalariedEmployee(string name, int id, double salary) : Employee(name, id) {
        weeklySalary = salary;
    }

    // Accept function to input salary data
    void accept() override {
        Employee::accept();
        cout << "Enter weekly salary: ";
        cin >> weeklySalary;
    }

    // Display function to show salaried employee details
    void display() override {
        Employee::display();
        cout << "Weekly Salary: " << weeklySalary << endl;
    }

    // Earnings function for salaried employee
    double earnings() override {
        return weeklySalary;
    }
};

// Derived class HourlyEmployee
class HourlyEmployee : public Employee {
private:
    double wage;
    double hours;

public:
    // Default constructor
    HourlyEmployee() : Employee() {
        wage = 0.0;
        hours = 0.0;
    }

    // Parameterized constructor
    HourlyEmployee(string name, int id, double wageRate, double hoursWorked) : Employee(name, id) {
        wage = wageRate;
        hours = hoursWorked;
    }

    // Accept function to input hourly wage and hours worked
    void accept() override {
        Employee::accept();
        cout << "Enter hourly wage: ";
        cin >> wage;
        cout << "Enter hours worked: ";
        cin >> hours;
    }

    // Display function to show hourly employee details
    void display() override {
        Employee::display();
        cout << "Hourly Wage: " << wage << endl;
        cout << "Hours Worked: " << hours << endl;
    }

    // Earnings function for hourly employee
    double earnings() override {
        double hourlySalary;
        if (hours < 40) {
            hourlySalary = hours * wage;
        } else {
            hourlySalary = 40 * wage + ((hours - 40) * wage * 1.5);
        }
        return hourlySalary;
    }
};

// Derived class CommissionEmployee
class CommissionEmployee : public Employee {
private:
    double grossSales;
    double commissionRate;

public:
    // Default constructor
    CommissionEmployee() : Employee() {
        grossSales = 0.0;
        commissionRate = 0.0;
    }

    // Parameterized constructor
    CommissionEmployee(string name, int id, double sales, double rate) : Employee(name, id) {
        grossSales = sales;
        commissionRate = rate;
    }

    // Accept function to input sales and commission rate
    void accept() override {
        Employee::accept();
        cout << "Enter gross sales: ";
        cin >> grossSales;
        cout << "Enter commission rate: ";
        cin >> commissionRate;
    }

    // Display function to show commission employee details
    void display() override {
        Employee::display();
        cout << "Gross Sales: " << grossSales << endl;
        cout << "Commission Rate: " << commissionRate << endl;
    }

    // Earnings function for commission employee
    double earnings() override {
        return grossSales * commissionRate;
    }
};

int main() {
    // Create objects of derived classes
    SalariedEmployee se("Aditya", 101, 1000.0);
    HourlyEmployee he("Aryan", 102, 20.0, 45.0);
    CommissionEmployee ce("Rahul", 103, 5000.0, 0.1);

    // Display earnings for each employee type
    se.display();
    cout << "Earnings: " << se.earnings() << endl;

    he.display();
    cout << "Earnings: " << he.earnings() << endl;

    ce.display();
    cout << "Earnings: " << ce.earnings() << endl;

    return 0;
}
