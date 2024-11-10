// assignemnt 7
// Develop an object-oriented program in C++ to Perform bubble sort operation using the template for
// integer and float data type

#include <iostream>
using namespace std;

// Template function for Bubble Sort
template <typename T>
void bubbleSort(T arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                // Swap elements if they are in the wrong order
                T temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Template function to display an array
template <typename T>
void displayArray(T arr[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    // Integer array
    int intArray[] = {34, 7, 23, 32, 5, 62};
    int intSize = sizeof(intArray) / sizeof(intArray[0]);

    cout << "Integer array before sorting: ";
    displayArray(intArray, intSize);

    bubbleSort(intArray, intSize);

    cout << "Integer array after sorting: ";
    displayArray(intArray, intSize);

    // Float array
    float floatArray[] = {3.4, 7.1, 2.3, 5.5, 1.2};
    int floatSize = sizeof(floatArray) / sizeof(floatArray[0]);

    cout << "\nFloat array before sorting: ";
    displayArray(floatArray, floatSize);

    bubbleSort(floatArray, floatSize);

    cout << "Float array after sorting: ";
    displayArray(floatArray, floatSize);

    return 0;
}
