#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // for std::sort
#include <limits> // for numeric_limits
using namespace std;

// Function to convert the input value to meters
double convert_to_meters(double value, const string& unit) {
    if (unit == "cm") {
        return value / 100; // Convert cm to meters
    } else if (unit == "m") {
        return value; // Already in meters
    } else if (unit == "in") {
        return value * 2.54 / 100; // Convert inches to meters
    } else if (unit == "ft") {
        return value * 12 * 2.54 / 100; // Convert feet to meters
    } else {
        // Handle invalid units
        cout << "bad unit: " << unit << endl;
        return -1; // Return -1 to indicate invalid unit
    }
}

int main() {
    cout << "Enter a double value followed by a space then a unit (cm,m,in,ft):\n";

    double value;
    string unit;
    double smallest = numeric_limits<double>::max();
    double largest = numeric_limits<double>::min();
    double sum_in_meters = 0; // Sum of all valid values in meters
    int count = 0; // Number of valid values entered
    vector<double> values_in_meters; // Store all values in meters

    while (cin >> value >> unit) {
        // Convert the value to meters
        double value_in_meters = convert_to_meters(value, unit);

        // Check for invalid units and skip the rest of the loop
        if (value_in_meters == -1) {
            continue;
        }

        // Store the valid value in the vector
        values_in_meters.push_back(value_in_meters);

        // Update the sum and the count of valid values
        sum_in_meters += value_in_meters;
        count++;

        // Print the entered value along with the unit
        cout << value << unit;

        // Check if it's the smallest value so far
        if (value_in_meters < smallest) {
            smallest = value_in_meters;
            cout << " smallest so far";
        }

        // Check if it's the largest value so far
        if (value_in_meters > largest) {
            largest = value_in_meters;
            cout << " largest so far";
        }

        cout << endl; // Print newline after each iteration
    }

    // Print the summary after the loop ends
    cout << "smallest: " << smallest << "\n";
    cout << "largest: " << largest << "\n";
    cout << "number: " << count << "\n";
    cout << "sum: " << sum_in_meters << "\n";

    // Sort the values in increasing order
    sort(values_in_meters.begin(), values_in_meters.end());

    // Print all the values stored in the vector in sorted order
    for (double v : values_in_meters) {
        cout << v << endl;
    }

    return 0;
}
