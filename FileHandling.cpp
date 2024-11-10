// Implement file handling and File input output operations in C++
// Create “BOOK.txt” file.
// Put some text in the file created above
// Develop an object-oriented program in C++ to writes data to a file, reads it back, and
// displays the content in other file,Write a function in C++ to count the number of
// uppercase alphabets,to count letters present in a file, to count digits present in a file, to
// count white spaces present in a file, to count vowels present in a file using the file
// pointer concept.

#include <iostream>
#include <fstream>
#include <cctype>  // for isupper, isdigit, isalpha, isspace
using namespace std;

class FileHandler {
public:
    // Function to write data to the file
    void writeToFile(const string& filename) {
        ofstream file(filename); // Open file for writing
        if (file) {
            file << "Welcome to the BOOK file. It contains 300 books.\n";
            file << "This library is located in Mumbai. The library id is 12345.\n";
            file.close();
            cout << "Data written to file successfully.\n";
        } else {
            cout << "Error opening file for writing.\n";
        }
    }

    // Function to read and display content from the file
    void readFromFile(const string& filename) {
        ifstream file(filename); // Open file for reading
        string line;
        cout << "\nFile Content:\n";
        if (file) {
            while (getline(file, line)) {
                cout << line << endl;
            }
            file.close();
        } else {
            cout << "Error opening file for reading.\n";
        }
    }

    // Function to count specific characters in the file
    void countCharacters(const string& filename) {
        ifstream file(filename); // Open file for reading
        if (!file) {
            cout << "Error opening file for reading.\n";
            return;
        }

        int uppercaseCount = 0, letterCount = 0, digitCount = 0;
        int whitespaceCount = 0, vowelCount = 0;
        char ch;

        while (file.get(ch)) { // Read character by character
            if (isupper(ch)) uppercaseCount++;
            if (isalpha(ch)) letterCount++;
            if (isdigit(ch)) digitCount++;
            if (isspace(ch)) whitespaceCount++;
            if (isVowel(ch)) vowelCount++;
        }

        file.close();

        cout << "\nCharacter Counts:\n";
        cout << "Uppercase Letters: " << uppercaseCount << endl;
        cout << "Total Letters: " << letterCount << endl;
        cout << "Digits: " << digitCount << endl;
        cout << "White Spaces: " << whitespaceCount << endl;
        cout << "Vowels: " << vowelCount << endl;
    }

private:
    // Helper function to check if a character is a vowel
    bool isVowel(char ch) {
        ch = tolower(ch); // Convert to lowercase to simplify checks
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }
};

int main() {
    FileHandler fh;
    string filename = "BOOK.txt";

    fh.writeToFile(filename);       // Write data to file
    fh.readFromFile(filename);      // Read and display content from file
    fh.countCharacters(filename);   // Count specific characters in file

    return 0;
}
