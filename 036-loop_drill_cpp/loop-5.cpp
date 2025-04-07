#include <iostream>
#include <cmath> // for std::abs
using namespace std;

int main() {
    cout << "Enter two double values separated by a space (followed by 'Enter'):\n";

    double val1, val2;
    while (cin >> val1 >> val2) {
        if (val1 < val2) {
            cout << "the smaller value is: " << val1 << endl;
            cout << "the larger value is: " << val2 << endl;
        } else if (val1 > val2) {
            cout << "the smaller value is: " << val2 << endl;
            cout << "the larger value is: " << val1 << endl;
        } else {
            cout << "the numbers are equal" << endl;
        }

        // Check if the numbers are almost equal (difference less than 0.01)
        if (abs(val1 - val2) < 0.01 && val1 != val2) {
            cout << "the numbers are almost equal" << endl;
        }
    }

    return 0;
}
