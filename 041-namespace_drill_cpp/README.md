# Namespace Drill
Write a program using a single file containing three namespaces `X`, `Y`, and `Z`
so that the following `main()` works correctly:

```c++
#include <iostream>

int main() {
    X::var = 7;
    X::print(); // print X’s var
    using namespace Y;
    var = 9;
    print(); // print Y’s var
    {
        using Z::print;
        using Z::var;
        var = 11;
        print(); // print Z’s var
    }
    print();    // print Y’s var
    X::print(); // print X’s var
}
```

Each namespace needs to define a variable called var and a function called `print()` that outputs the appropriate `var` using `cout`.

Use `main.cpp` as your starting point.
Expected output:
```
7
9
11
9
7
```
Once your program matches the expected output, submit main.cpp to Gradescope.

## Source
Adapted from Chapter 8 of 
Stroustrup, B. (2024). Programming: Principles and Practice Using C++, 3rd Ed. 
United States: Pearson Education (US)