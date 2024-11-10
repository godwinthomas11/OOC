// Develop an object oriented program in C++ to create a database of student information systems containing the following information:
// Name, Roll number, Class, division, Date of Birth, Adhar number, Blood group, Contact address, telephone number, etc 
// Construct the database with suitable member functions for initializing and destroying the data.
// Count the number of students in the database by using a variable count which is a member of the student class. 
// Also display the student information using a static function.


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
    static int count;  // Static member to keep track of the number of students

public:
    // Constructor to initialize student data and increment count
    Student(const string &n, int roll, const string &cls, char div, const string &birthdate, const string &aadhar,
            const string &blood, const string &address, const string &phone) {
        name = n;
        rollNumber = roll;
        studentClass = cls;
        division = div;
        dob = birthdate;
        aadharNumber = aadhar;
        bloodGroup = blood;
        contactAddress = address;
        telephoneNumber = phone;
        count++;  // Increment count each time a new student is created
    }

    // Destructor to decrement count when a student is removed
    ~Student() {
        count--;
    }

    // Static function to display student information
    static void displayStudentInfo(const Student &student) {
        cout << "Name: " << student.name << endl;
        cout << "Roll Number: " << student.rollNumber << endl;
        cout << "Class: " << student.studentClass << endl;
        cout << "Division: " << student.division << endl;
        cout << "Date of Birth: " << student.dob << endl;
        cout << "Aadhar Number: " << student.aadharNumber << endl;
        cout << "Blood Group: " << student.bloodGroup << endl;
        cout << "Contact Address: " << student.contactAddress << endl;
        cout << "Telephone Number: " << student.telephoneNumber << endl;
        cout << "-------------------------------" << endl;
    }

    // Static function to get the count of students
    static int getCount() {
        return count;
    }
};

// Initialize the static member count
int Student::count = 0;

int main() {
    // Creating student objects
    Student student1("John Doe", 101, "10th", 'A', "2005-05-15", "123456789012", "O+", "123 Main St, City", "555-1234");
    Student student2("Jane Smith", 102, "10th", 'B', "2005-08-20", "987654321098", "A+", "456 Maple Ave, City", "555-5678");

    cout << "Student Information System\n";
    cout << "==========================\n";
    
    // Displaying student information
    Student::displayStudentInfo(student1);
    Student::displayStudentInfo(student2);

    // Displaying the total number of students
    cout << "Total number of students: " << Student::getCount() << endl;

    return 0;
}
