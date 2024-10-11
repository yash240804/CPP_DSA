#include <iostream>
using namespace std;

void towerofhanoi(int n, char start, char extra, char end) {
    if (n == 1) {
        cout << "Move disk 1 from " << start << " to " << end << endl;
        return;
    }

    towerofhanoi(n - 1, start, end, extra);

    cout << "Move disk " << n << " from " << start << " to " << end << endl;

    towerofhanoi(n - 1, extra, start, end);
}

int main() {
    int n; 
    cout << "Enter the number of disks: ";
    cin >> n;  

    towerofhanoi(n, 'A', 'B', 'C');

    return 0;
}
