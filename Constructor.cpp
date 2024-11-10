//  Develop an object-oriented program in C++ to create a database of employee information system containing the following information: 
//  Employee Name, Employee number, qualification, address, contact number, salary details (basic, DA, TA, Net salary), etc 
//  Construct the database with suitable inline member functions for initializing and destroying the data viz constructor, default constructor,
// Copy constructor, destructor. Also, Display the Employee information. 
 

#include <iostream>
#include <string>
using namespace std;

class Employee {
private:
    string name;
    int empNo;
    string qualification;
    string address;
    string contactNumber;
    double basicSalary;
    double da;  // Dearness Allowance
    double ta;  // Travel Allowance
    double netSalary;
    
public:
    // Default constructor
    Employee() {
        name = "Unknown";
        empNo = 0;
        qualification = "Not Provided";
        address = "Not Provided";
        contactNumber = "Not Provided";
        basicSalary = 0.0;
        da = 0.0;
        ta = 0.0;
        netSalary = 0.0;
        cout << "Default constructor called!" << endl;
    }
    
    // Parameterized constructor
    Employee(string n, int no, string qual, string addr, string contact, double basic, double dearness, double travel) {
        name = n;
        empNo = no;
        qualification = qual;
        address = addr;
        contactNumber = contact;
        basicSalary = basic;
        da = dearness;
        ta = travel;
        netSalary = basicSalary + da + ta;
        cout << "Parameterized constructor called!" << endl;
    }
    
    // Copy constructor
    Employee(const Employee &e) {
        name = e.name;
        empNo = e.empNo;
        qualification = e.qualification;
        address = e.address;
        contactNumber = e.contactNumber;
        basicSalary = e.basicSalary;
        da = e.da;
        ta = e.ta;
        netSalary = e.netSalary;
        cout << "Copy constructor called!" << endl;
    }
    
    // Destructor
    ~Employee() {
        cout << "Destructor called for Employee " << name << endl;
    }

    // Function to display employee information
    void display() const {
        cout << "\nEmployee Information:" << endl;
        cout << "Name: " << name << endl;
        cout << "Employee Number: " << empNo << endl;
        cout << "Qualification: " << qualification << endl;
        cout << "Address: " << address << endl;
        cout << "Contact Number: " << contactNumber << endl;
        cout << "Basic Salary: " << basicSalary << endl;
        cout << "Dearness Allowance: " << da << endl;
        cout << "Travel Allowance: " << ta << endl;
        cout << "Net Salary: " << netSalary << endl;
    }
};

int main() {
    // Using the default constructor
    Employee emp1;
    emp1.display();
    
    // Using the parameterized constructor
    Employee emp2("John Doe", 101, "MBA", "123 Main St, City", "555-1234", 50000.0, 10000.0, 5000.0);
    emp2.display();
    
    // Using the copy constructor
    Employee emp3 = emp2;  // Copies data from emp2 to emp3
    emp3.display();
    
    return 0;
}
