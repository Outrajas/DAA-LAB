#include <iostream>
using namespace std;

int bruteForceStringMatch(char text[], char pattern[]) {
    int n = 0, m = 0;
    
    while (text[n] != '\0') {
        n++;
    }
  
    while (pattern[m] != '\0') {
        m++;
    }

    
    for (int i = 0; i <= n - m; i++) {
        int j = 0;
        while (j < m && text[i + j] == pattern[j]) {
            j++;
        }
        if (j == m) {
            return i; 
        }
    }
    return -1; 
}

int main() {
    char text[] = "ABABDABACDABABCABAB";
    char pattern[] = "ABABCABAB";

    int result = bruteForceStringMatch(text, pattern);
    if (result != -1) {
        cout << "Pattern found at index " << result << endl;
    } else {
        cout << "Pattern not found" << endl;
    }

    return 0;
}

