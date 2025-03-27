#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<char, int> shiftTable(string pattern) {
    int m = pattern.size();
    unordered_map<char, int> table;

    for (int i = 0; i < m - 1; i++)
        table[pattern[i]] = m - 1 - i;

    return table;
}

int horspoolSearch(string text, string pattern) {
    int n = text.size();
    int m = pattern.size();
    unordered_map<char, int> table = shiftTable(pattern);

    int i = m - 1;
    while (i < n) {
        int j = 0;
        while (j < m && text[i - j] == pattern[m - 1 - j])
            j++;

        if (j == m) return i - m + 1;

        i += (table.count(text[i]) ? table[text[i]] : m);
    }

    return -1;
}

int main() {
    string text = "hello world, welcome to C++";
    string pattern = "welcome";

    int pos = horspoolSearch(text, pattern);

    if (pos != -1)
        cout << "Pattern found at index " << pos << endl;
    else
        cout << "Pattern not found" << endl;

    return 0;
}

