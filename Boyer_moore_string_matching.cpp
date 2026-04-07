#include <iostream>
#include <cstring>
using namespace std;

#define CHAR_SIZE 256

// Function to build bad character table
void badCharHeuristic(string pattern, int size, int badChar[]) {
    for (int i = 0; i < CHAR_SIZE; i++)
        badChar[i] = -1;

    for (int i = 0; i < size; i++)
        badChar[(int)pattern[i]] = i;
}

// Boyer-Moore search function
void boyerMoore(string text, string pattern) {
    int m = pattern.size();
    int n = text.size();

    int badChar[CHAR_SIZE];
    badCharHeuristic(pattern, m, badChar);

    int shift = 0;

    while (shift <= (n - m)) {
        int j = m - 1;

        // Compare from right to left
        while (j >= 0 && pattern[j] == text[shift + j])
            j--;

        // If pattern found
        if (j < 0) {
            cout << "Pattern found at index: " << shift << endl;

            shift += (shift + m < n) ? m - badChar[text[shift + m]] : 1;
        } else {
            shift += max(1, j - badChar[text[shift + j]]);
        }
    }
}

int main() {
    string text, pattern;

    cout << "Enter text: ";
    cin >> text;

    cout << "Enter pattern: ";
    cin >> pattern;

    boyerMoore(text, pattern);

    return 0;
}
