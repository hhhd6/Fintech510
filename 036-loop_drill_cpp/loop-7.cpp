#include <iostream>
#include <string>
#include <limits> // for numeric_limits
using namespace std;

// Function to convert the input value to centimeters
double convert_to_cm(double value, const string& unit) {
    if (unit == "cm") {
        return value;
    } else if (unit == "m") {
        return value * 100; // 1m = 100cm
    } else if (unit == "in") {
        return value * 2.54; // 1in = 2.54cm
    } else if (unit == "ft") {
        return value * 12 * 2.54; // 1ft = 12in = 30.48cm
    } else {
        cout << "Unknown unit: " << unit << endl;
        return -1; // Return -1 to indicate invalid unit
    }
}

int main() {
    cout << "Enter a double value followed by a space then a unit (cm,m,in,ft):\n";

    double value;
    string unit;
    double smallest = numeric_limits<double>::max();
    double largest = numeric_limits<double>::min();

    while (cin >> value >> unit) {
        // Convert the value to centimeters
        double value_in_cm = convert_to_cm(value, unit);

        if (value_in_cm == -1) {
            // Invalid unit, skip to next iteration
            continue;
        }

        // Print the entered value along with the unit
        cout << value << unit;

        // Check if it's the smallest value so far
        if (value_in_cm < smallest) {
            smallest = value_in_cm;
            cout << " smallest so far";
        }

        // Check if it's the largest value so far
        if (value_in_cm > largest) {
            largest = value_in_cm;
            cout << " largest so far";
        }

        cout << endl; // Print newline after each iteration
    }

    return 0;
}
