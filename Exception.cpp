// Develop an object-oriented program in C++ to create a class Hotel for hotel
// booking system.
// The class Hotel has data members: string cust_name, int cust_id, int income, string
// city, and string room_type and has a default constructor. It has functions accept ()
// and display () to output data member values.
// The class Hotel has member functions as: getage(),getincome(),getcity() and
// getrrom_type().
// Throw four exceptions as :
// 1.If the age is not between 18 and 55.
// 2.If income is not between 50000 and 100000.
// 3.If the city is not Pune or Mumbai
// 4. If room_type is not deluxe or super deluxe
// Use exception handling to check if the above conditions are satisfied (display all
// customer information) else print an error message.

#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

class Hotel {
private:
    string cust_name;
    int cust_id;
    int age;
    int income;
    string city;
    string room_type;

public:
    // Default Constructor
    Hotel() : cust_name(""), cust_id(0), age(0), income(0), city(""), room_type("") {}

    // Function to accept details of the customer
    void accept() {
        cout << "Enter customer name: ";
        getline(cin, cust_name);
        cout << "Enter customer ID: ";
        cin >> cust_id;
        cout << "Enter age: ";
        cin >> age;
        cout << "Enter income: ";
        cin >> income;
        cout << "Enter city: ";
        cin >> city;
        cout << "Enter room type (deluxe/super deluxe): ";
        cin >> room_type;
    }

    // Function to display customer information
    void display() const {
        cout << "\nCustomer Information:\n";
        cout << "Name: " << cust_name << endl;
        cout << "ID: " << cust_id << endl;
        cout << "Age: " << age << endl;
        cout << "Income: " << income << endl;
        cout << "City: " << city << endl;
        cout << "Room Type: " << room_type << endl;
    }

    // Function to validate age
    void getage() const {
        if (age < 18 || age > 55) {
            throw invalid_argument("Age must be between 18 and 55.");
        }
    }

    // Function to validate income
    void getincome() const {
        if (income < 50000 || income > 100000) {
            throw invalid_argument("Income must be between 50000 and 100000.");
        }
    }

    // Function to validate city
    void getcity() const {
        if (city != "Pune" && city != "Mumbai") {
            throw invalid_argument("City must be either Pune or Mumbai.");
        }
    }

    // Function to validate room type
    void getroom_type() const {
        if (room_type != "deluxe" && room_type != "super deluxe") {
            throw invalid_argument("Room type must be either 'deluxe' or 'super deluxe'.");
        }
    }
};

int main() {
    Hotel customer;
    customer.accept();

    try {
        customer.getage();
        customer.getincome();
        customer.getcity();
        customer.getroom_type();
        customer.display();  // Display details if no exception is thrown
    }
    catch (const invalid_argument &e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}
