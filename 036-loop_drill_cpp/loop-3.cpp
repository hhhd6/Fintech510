#include <iostream>
using namespace std;

int main() {

    cout << "Enter two integer values separated by a space (followed by 'Enter'):\n";

    int val1, val2;
    while (cin >> val1 >> val2)  {
        if (val1 < val2) {
            cout << "the smaller value is: " << val1 << endl;
            cout << "the larger value is: " << val2 << endl;
        } else if (val1 > val2) {
            cout << "the smaller value is: " << val2 << endl;
            cout << "the larger value is: " << val1 << endl;
        } else {
            cout << "the numbers are equal" << endl;
        }
    }

    return 0;
}
