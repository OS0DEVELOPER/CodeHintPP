#include <iostream>
    // Include a header file
#include "CodeHint.hpp"
    // Include a header file

int main() {
    // Declare a variable
    int x = 42;
    // Declare and initialize a variable
    std::cout << x << std::endl;
    // Print to console

    CodeHint::SelfComment(__FILE__);  // ✅ correct name

    return 0;
    // Return the result
}
