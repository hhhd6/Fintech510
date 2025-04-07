#include <iostream>
#include <limits> // for numeric_limits
using namespace std;

int main() {
    cout << "Enter a double value followed by 'Enter'):\n";

    double value;
    double smallest = numeric_limits<double>::max();
    double largest = numeric_limits<double>::min();

    while (cin >> value) {
        cout << value; // Print the entered value

        // Check if it's the smallest value so far
        if (value < smallest) {
            smallest = value;
            cout << " smallest so far";
        }

        // Check if it's the largest value so far
        if (value > largest) {
            largest = value;
            cout << " largest so far";
        }

        cout << endl;
    }

    return 0;
}
