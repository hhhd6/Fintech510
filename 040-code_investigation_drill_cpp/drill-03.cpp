#include <iostream>
#include <vector>
#include <string>

// Code From
// Programming: Principles and Practice Using C++ (2nd Edition)
// Bjarne Stroustrup

using namespace std;

int main() {
    try {
        string res = "7";
        vector<int> v(10); 
        v[5] = stoi(res); 
        cout << "Success!\n";
        return 0;
    }
    catch (exception& e) {
        cerr << "error: " << e.what() << '\n';
        return 1;
    }
    catch (...) {
        cerr << "Oops: unknown exception!\n";
        return 2;
    }
}
