#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <algorithm>
using namespace std;

// ANSI escape codes for background colors
const string RESET  = "\033[0m";
const string BLUE_BG   = "\033[44m"; // blue background
const string RED_BG    = "\033[41m"; // red background

// Clear terminal screen
void clearScreen() {
    cout << "\033[2J\033[1;1H";
}

// Draw columns with background colors
void drawArray(const vector<int>& arr, int idx1 = -1, int idx2 = -1) {
    int maxVal = *max_element(arr.begin(), arr.end());

    for (int h = maxVal; h >= 1; h--) {
        for (int i = 0; i < arr.size(); i++) {
            string color = BLUE_BG;
            if (i == idx1 || i == idx2) color = RED_BG; // highlight compared/swapped

            if (arr[i] >= h)
                cout << color << "   " << RESET; // solid block
            else
                cout << "   "; // empty space
        }
        cout << "\n";
    }
}

// Bubble sort with animation
void bubbleSortVisual(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
            clearScreen();
            drawArray(arr, j, j + 1);
            this_thread::sleep_for(chrono::milliseconds(200)); // animation speed
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
    this_thread::sleep_for(chrono::milliseconds(500));

    bubbleSortVisual(arr);

    clearScreen();
    drawArray(arr);
    cout << "\nSorting complete!\n";
}
