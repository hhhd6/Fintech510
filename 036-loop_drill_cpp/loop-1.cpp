#include <iostream>
using namespace std;

int main() {

    cout << "Enter two integer values separated by a space (followed by 'Enter'):\n";

    int val1, val2;
    while (cin >> val1 >> val2)  {
        cout << val1 << " " << val2 << endl;
    }
    return 0;
}