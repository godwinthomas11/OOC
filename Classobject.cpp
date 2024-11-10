// Develop an object oriented program in C++ to create a
// database of student information systems containing the
// following information: Name, Roll number, Class, division,
// Date of Birth, Adhar number, Blood group, Contact address,
// telephone number, etc . Count the number of students in
// the database by using a variable count which is a member
// of the student class. Also display the total number of
// students using a static function.
// Display the % marks obtained using friend function.

#include <iostream>
using namespace std;

class Student {
private:
    string name;
    int rollNumber;s
    string studentClass;
    char division;
    string dob;
    string aadharNumber;
    string bloodGroup;
    string contactAddress;
    string telephoneNumber;
    float percentageMarks;
    static int count;

public:
    Student() {
        count++;
    }

    // Function to initialize student data
    void setData(const string &n, int roll, const string &cls, char div, const string &birthdate, const string &aadhar, const string &blood, const string &address, const string &phone, float marks) {
        name = n;
        rollNumber = roll;
        studentClass = cls;
        division = div;
        dob = birthdate;
        aadharNumber = aadhar;
        bloodGroup = blood;
        contactAddress = address;
        telephoneNumber = phone;
        percentageMarks = marks;
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
    }

    // Static function to get the count of students
    static int getCount() {
        return count;
    }

    // Friend function to display percentage marks
    friend void displayPercentageMarks(const Student &student);
};

int Student::count = 0;

void displayPercentageMarks(const Student &student) {
    cout << "Percentage Marks: " << student.percentageMarks << "%" << endl;
}

int main() {
    const int numStudents = 2;
    Student students[numStudents];

    for (int i = 0; i < numStudents; ++i) {
        string name, studentClass, dob, aadharNumber, bloodGroup, contactAddress, telephoneNumber;
        int rollNumber;
        char division;
        float percentageMarks;

        cout << "Enter details for student " << i + 1 << ":" << endl;

        cout << "Name: ";
        getline(cin, name);

        cout << "Roll Number: ";
        cin >> rollNumber;
        cin.get(); // Consume the newline character left in the buffer

        cout << "Class: ";
        getline(cin, studentClass);

        cout << "Division: ";
        cin >> division;
        cin.get(); // Consume the newline character left in the buffer

        cout << "Date of Birth (YYYY-MM-DD): ";
        getline(cin, dob);

        cout << "Aadhar Number: ";
        getline(cin, aadharNumber);

        cout << "Blood Group: ";
        getline(cin, bloodGroup);

        cout << "Contact Address: ";
        getline(cin, contactAddress);

        cout << "Telephone Number: ";
        getline(cin, telephoneNumber);

        cout << "Percentage Marks: ";
        cin >> percentageMarks;
        cin.get(); // Consume the newline character left in the buffer

        students[i].setData(name, rollNumber, studentClass, division, dob, aadharNumber, bloodGroup, contactAddress, telephoneNumber, percentageMarks);
        cout << endl;
    }

    cout << "Student Information: " << endl;
    for (int i = 0; i < numStudents; ++i) {
        Student::displayStudentInfo(students[i]);
        displayPercentageMarks(students[i]);
        cout << endl;
    }

    cout << "Total number of students: " << Student::getCount() << endl;

    return 0;
}
