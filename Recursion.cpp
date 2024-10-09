#include <iostream>
using namespace std;

int sumOfNaturalNumbers(int n) {
    if (n == 1) {
        return 1;
    }
    return n + sumOfNaturalNumbers(n - 1);
}

int main() {
    int n;
    cout << "Enter a positive integer: ";
    cin >> n;

    int result = sumOfNaturalNumbers(n);
    cout << "The sum of the first " << n << " natural numbers is: " << result << endl;

    return 0;
}
