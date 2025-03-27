#include <iostream>
using namespace std;

int countBinaryDigitsRecursive(int n) {
    if (n == 0) {
        return 0;  // Base case: binary digits of 0 is 0
    } else {
        return 1 + countBinaryDigitsRecursive(n / 2);  // Divide n by 2 and count digits recursively
    }
}

int main() {
    int n = 1024;
    cout << "Number of binary digits: " << countBinaryDigitsRecursive(n) << endl;
    return 0;
}

