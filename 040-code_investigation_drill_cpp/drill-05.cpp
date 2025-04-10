#include <iostream>
#include <vector>

// Code From
// Programming: Principles and Practice Using C++ (2nd Edition)
// Bjarne Stroustrup

using namespace std;

int main() {
    try {
        vector<char> v(5); 
        for (vector<char>::size_type i=0; i < v.size(); ++i) 
            ; 
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
