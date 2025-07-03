// demo.cpp
#include <fstream>
#include "../CodeHintLib/include/CodeHint.hpp"

int main() {
    std::ifstream input("F:/CodeHintPP/CodeHintDemo/mycode.cpp");
    std::ofstream output("F:/CodeHintPP/CodeHintDemo/mycode_commented.cpp");

    if (!input || !output) {
        std::cerr << "Error opening files.\n";
        return 1;
    }

    CodeHint::commentFunction(input, output);
    std::cout << "Comments added to 'mycode_commented.cpp'\n";
    return 0;
}
