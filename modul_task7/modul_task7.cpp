#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

const int ROWS = 7;
const int COLS = 9;

// Function to swap elements
void swapElements(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// Function to build max heap
void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swapElements(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

// Function to perform HeapSort
void heapSort(int arr[], int n) {
    // Build max heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Extract elements from the heap one by one
    for (int i = n - 1; i > 0; i--) {
        swapElements(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

// Function to find the row with the minimum element
int findMinEl(int arr[ROWS][COLS]) {
    cout << "Finding the row with the minimum element" << endl;

    int minVal = abs(arr[0][0]); // Assume the first element of the array is the minimum
    int minRowIndex = 0; // Assume the first row index

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            cout << arr[i][j] << "\t"; // Output elements of the row

            if (abs(arr[i][j]) < minVal) {
                minVal = abs(arr[i][j]); // Found a smaller absolute value
                minRowIndex = i;
            }
        }
        cout << endl;
    }

    cout << "Minimum element: " << minVal << endl;
    cout << "Index of the row with the minimum element: " << minRowIndex << endl;
    return minRowIndex; // Return the index of the row with the minimum element
}

int main() {
    srand(time(nullptr));

    int arr[ROWS][COLS];

    // Fill the array with random values
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            arr[i][j] = rand() % 100;
        }
    }

    // Find the row with the minimum element
    int minRowIndex = findMinEl(arr);
    heapSort(arr[minRowIndex], COLS);

    cout << "Sorted row: ";
    for (int i = 0; i < COLS; i++) {
        cout << arr[minRowIndex][i] << " ";
    }
    cout << endl;

    return 0;
}
