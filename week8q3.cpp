#include <iostream>
#include <vector>
using namespace std;

#define NO_OF_CHARS 256

void badCharTable(string pattern, vector<int>& badChar) {
    int m = pattern.size();
    for (int i = 0; i < NO_OF_CHARS; i++)
        badChar[i] = -1;

    for (int i = 0; i < m; i++)
        badChar[(int)pattern[i]] = i;
}

int boyerMooreSearch(string text, string pattern) {
    int n = text.size();
    int m = pattern.size();
    vector<int> badChar(NO_OF_CHARS);
    
    badCharTable(pattern, badChar);
    
    int shifts = 0;
    int comparisons = 0;
    
    while (shifts <= (n - m)) {
        int j = m - 1;

        while (j >= 0 && pattern[j] == text[shifts + j]) {
            j--;
            comparisons++;
        }

        if (j < 0) {
            cout << "Pattern found at index " << shifts << endl;
            shifts += (shifts + m < n) ? m - badChar[text[shifts + m]] : 1;
        } else {
            shifts += max(1, j - badChar[text[shifts + j]]);
        }
    }
    
    cout << "Total comparisons: " << comparisons << endl;
    return -1;
}

int main() {
    string text = "ABAAABCD";
    string pattern = "ABC";

    boyerMooreSearch(text, pattern);
    
    return 0;
}

