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
    float percentageMarks;
    static int count;  // Static member to keep track of the number of students

public:
    // Constructor to initialize student data and increment count
    Student(const string &n, int roll, const string &cls, char div, const string &birthdate, 
            const string &aadhar, const string &blood, const string &address, 
            const string &phone, float marks) 
            : name(n), rollNumber(roll), studentClass(cls), division(div), dob(birthdate),
              aadharNumber(aadhar), bloodGroup(blood), contactAddress(address), 
              telephoneNumber(phone), percentageMarks(marks) {
        count++;  // Increment count each time a new student is created
    }

    // Destructor to decrement count when a student is removed
    ~Student() {
        count--;
    }

    // Static function to get the count of students
    static int getCount() {
        return count;
    }

    // Function to display student data
    void display() const {
        cout << "\nStudent Information:" << endl;
        cout << "Name: " << name << endl;
        cout << "Roll Number: " << rollNumber << endl;
        cout << "Class: " << studentClass << endl;
        cout << "Division: " << division << endl;
        cout << "Date of Birth: " << dob << endl;
        cout << "Aadhar Number: " << aadharNumber << endl;
        cout << "Blood Group: " << bloodGroup << endl;
        cout << "Contact Address: " << contactAddress << endl;
        cout << "Telephone Number: " << telephoneNumber << endl;
    }

    // Friend function to display percentage marks
    friend void displayPercentage(const Student &student);
};

// Initialize the static member count
int Student::count = 0;

// Friend function to display percentage marks
void displayPercentage(const Student &student) {
    cout << "Percentage Marks: " << student.percentageMarks << "%" << endl;
}

int main() {
    // Creating student objects
    Student student1("John Doe", 101, "10th", 'A', "2005-05-15", "123456789012", 
                     "O+", "123 Main St, City", "555-1234", 88.5);
    Student student2("Jane Smith", 102, "10th", 'B', "2005-08-20", "98765432109
