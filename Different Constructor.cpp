// Develop an object oriented program in C++ to create a database of student information systems containing the following information: Name,
// Roll number, Class, division, Date of Birth, Aadhar number, Blood group, Contact address, telephone number, etc .
// Write the code to illustrate the use of default constructor,parametrized constructor and copy constructor 

#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    string name;
    int rollNumber;
    string studentClass;
    char division;
    string dob;
    string aadharNumber;
    string bloodGroup;
    string contactAddress;
    string telephoneNumber;
    
public:
    // Default constructor
    Student() {
        name = "Unknown";
        rollNumber = 0;
        studentClass = "None";
        division = '-';
        dob = "0000-00-00";
        aadharNumber = "Not Assigned";
        bloodGroup = "Unknown";
        contactAddress = "None";
        telephoneNumber = "None";
        cout << "Default constructor called\n";
    }
    
    // Parameterized constructor
    Student(string n, int roll, string cls, char div, string birthdate, string aadhar, string blood, string address, string phone) 
        : name(n), rollNumber(roll), studentClass(cls), division(div), dob(birthdate), aadharNumber(aadhar), bloodGroup(blood), contactAddress(address), telephoneNumber(phone) {
        cout << "Parameterized constructor called\n";
    }
    
    // Copy constructor
    Student(const Student &student) {
        name = student.name;
        rollNumber = student.rollNumber;
        studentClass = student.studentClass;
        division = student.division;
        dob = student.dob;
        aadharNumber = student.aadharNumber;
        bloodGroup = student.bloodGroup;
        contactAddress = student.contactAddress;
        telephoneNumber = student.telephoneNumber;
        cout << "Copy constructor called\n";
    }

    // Function to display student data
    void display() const {
        cout << "Name: " << name << endl;
        cout << "Roll Number: " << rollNumber << endl;
        cout << "Class: " << studentClass << endl;
        cout << "Division: " << division << endl;
        cout << "Date of Birth: " << dob << endl;
        cout << "Aadhar Number: " << aadharNumber << endl;
        cout << "Blood Group: " << bloodGroup << endl;
        cout << "Contact Address: " << contactAddress << endl;
        cout << "Telephone Number: " << telephoneNumber << endl;
        cout << "----------------------------------" << endl;
    }
};

int main() {
    // Using the default constructor
    Student student1;
    student1.display();

    // Using the parameterized constructor
    Student student2("John Doe", 101, "10th Grade", 'A', "2005-05-15", "123456789012", "O+", "123 Main St, City", "555-1234");
    student2.display();

    // Using the copy constructor
    Student student3 = student2;  // Copies student2's data to student3
    student3.display();

    return 0;
}



//Types of constrctors 
// 1.deault constructor 
// class Car {
// public:
//     int speed;

//     // Default Constructor
//     Car() {
//         speed = 0; // Default speed
//         cout << "Default constructor: Car created with speed " << speed << endl;
//     }
// };

// 2.parameterized constructor

// class Car {
// public:
//     int speed;

//     // Parameterized Constructor
//     Car(int s) {
//         speed = s;
//         cout << "Parameterized constructor: Car created with speed " << speed << endl;
//     }
// };

// int main() {
//     Car myCar(120); // Calls the parameterized constructor with speed 120
//     return 0;
// }

// 3.Copy Constructor

// class Car {
// public:
//     int speed;

//     // Parameterized Constructor
//     Car(int s) {
//         speed = s;
//         cout << "Parameterized constructor: Car created with speed " << speed << endl;
//     }

//     // Copy Constructor
//     Car(const Car &other) {
//         speed = other.speed;
//         cout << "Copy constructor: Car created as a copy with speed " << speed << endl;
//     }
// };

// int main() {
//     Car myCar(120);    // Calls parameterized constructor
//     Car copyCar(myCar); // Calls copy constructor to create a copy of myCar
//     return 0;
// }

// 4, Default Parameterized constructor 

// class Car {
// public:
//     int speed;

//     // Default Parameterized Constructor
//     Car(int s = 50) { // Default speed is 50 if no argument is given
//         speed = s;
//         cout << "Default parameterized constructor: Car created with speed " << speed << endl;
//     }
// };

// int main() {
//     Car myCar;        // Calls constructor with default speed 50
//     Car fastCar(120); // Calls constructor with speed 120
//     return 0;
// }

