#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <algorithm>

using namespace std;

void clearScreen() {
    // ANSI escape code to clear terminal
    cout << "\033[2J\033[1;1H";
}

void drawArray(const vector<int>& arr) {
    int maxVal = *max_element(arr.begin(), arr.end());

    for (int h = maxVal; h >= 1; h--) {
        for (int num : arr) {
            if (num >= h)
                cout << " |#| ";
            else
                cout << "     ";
        }
        cout << "\n";
    }

    // Print values below bars
    for (int num : arr) {
        cout << "  " << num << "  ";
    }
    cout << "\n";
}

void bubbleSortVisual(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
            clearScreen();
            drawArray(arr);
            this_thread::sleep_for(chrono::milliseconds(400)); // delay for visual effect
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
    this_thread::sleep_for(chrono::milliseconds(1000)); // pause before starting

    bubbleSortVisual(arr);

    cout << "\nSorting complete!\n";
    return 0;
}
