#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <algorithm>

using namespace std;

// ANSI color codes
const string RESET  = "\033[0m";
const string BLUE   = "\033[34m";
const string RED    = "\033[31m";

// Clear terminal
void clearScreen() {
    cout << "\033[2J\033[1;1H";
}

// Draw array with optional highlights
void drawArray(const vector<int>& arr, int idx1 = -1, int idx2 = -1) {
    int maxVal = *max_element(arr.begin(), arr.end());

    for (int h = maxVal; h >= 1; h--) {
        for (int i = 0; i < arr.size(); i++) {
            string color = BLUE;
            if (i == idx1 || i == idx2) color = RED;

            if (arr[i] >= h)
                cout << color << " |#| " << RESET;
            else
                cout << "     ";
        }
        cout << "\n";
    }

    // Values at the bottom
    for (int i = 0; i < arr.size(); i++) {
        string color = BLUE;
        if (i == idx1 || i == idx2) color = RED;
        cout << color << "  " << arr[i] << "  " << RESET;
    }
    cout << "\n";
}

// Bubble sort with visual update
void bubbleSortVisual(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
            clearScreen();
            drawArray(arr, j, j + 1);
            this_thread::sleep_for(chrono::milliseconds(400)); // adjust speed here
        }
    }
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    clearScreen();
    drawArray(arr);
    this_thread::sleep_for(chrono::milliseconds(1000)); // pause before sorting

    bubbleSortVisual(arr);

    cout << "\nSorting complete!\n";
    return 0;
}
