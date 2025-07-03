#include <iostream>
#include "CodeHint.hpp"

int main() {
    int x = 42;
    std::cout << x << std::endl;

    CodeHint::SelfComment(__FILE__);  // ✅ correct name

    return 0;
}
