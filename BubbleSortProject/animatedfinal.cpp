#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <algorithm>
#include <random>
using namespace std;

// Bright colors
const string RESET      = "\033[0m";
const string CYAN_BG    = "\033[46m";  // normal
const string MAGENTA_BG = "\033[45m";  // current
const string GREEN_BG   = "\033[42m";  // sorted

// Clear terminal
void clearScreen() {
    cout << "\033[2J\033[1;1H";
}

// Draw columns with values
void drawArray(const vector<int>& arr, int sortedTill = -1, int idx1 = -1, int idx2 = -1) {
    int maxVal = *max_element(arr.begin(), arr.end());
    int width = max(1, 120 / (int)arr.size()); // fit screen width

    // Draw bars
    for (int h = maxVal; h >= 1; h--) {
        for (int i = 0; i < arr.size(); i++) {
            string color = CYAN_BG;
            if (i <= sortedTill) color = GREEN_BG;
            if (i == idx1 || i == idx2) color = MAGENTA_BG;

            if (arr[i] >= h)
                cout << color << string(width, ' ') << RESET;
            else
                cout << string(width, ' ');
        }
        cout << "\n";
    }

    // Draw values below bars
    for (int i = 0; i < arr.size(); i++) {
        string color = CYAN_BG;
        if (i <= sortedTill) color = GREEN_BG;
        if (i == idx1 || i == idx2) color = MAGENTA_BG;

        string numStr = to_string(arr[i]);
        int pad = max(0, (width - (int)numStr.size()) / 2);
        cout << color << string(pad, ' ') << numStr 
             << string(width - pad - numStr.size(), ' ') << RESET;
    }
    cout << "\n";
}

// Selection sort with animation
void selectionSortVisual(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) minIndex = j;
        }
        swap(arr[i], arr[minIndex]);

        clearScreen();
        drawArray(arr, i, i, minIndex);
        this_thread::sleep_for(chrono::milliseconds(100));
    }
}

int main() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> lenDist(50, 60);
    int n = lenDist(gen);

    uniform_int_distribution<> heightDist(1, 20);
    vector<int> arr(n);
    for (int i = 0; i < n; i++) arr[i] = heightDist(gen);

    clearScreen();
    drawArray(arr);
    this_thread::sleep_for(chrono::milliseconds(500));

    selectionSortVisual(arr);

    clearScreen();
    drawArray(arr, n - 1);
    cout << "\nSorting complete! Length: " << n << "\n";
}
