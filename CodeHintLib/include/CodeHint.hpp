// CodeHint.hpp
#ifndef CODE_HINT_HPP
#define CODE_HINT_HPP

#include <string>
#include <vector>
#include <sstream>
#include <iostream>

namespace CodeHint {
    std::string generateComment(const std::string& line) {
        if (line.find("int ") != std::string::npos && line.find("=") != std::string::npos)
            return "// Declare and initialize integer";
        if (line.find("std::cout") != std::string::npos)
            return "// Print to console";
        if (line.find("return") != std::string::npos)
            return "// Return the result";
        if (line.find("for") != std::string::npos)
            return "// Loop over a range";
        if (line.find("while") != std::string::npos)
            return "// Loop while condition is true";
        if (line.find("if") != std::string::npos)
            return "// Conditional check";

        return "";
    }

    void commentFunction(std::istream& in, std::ostream& out) {
        std::string line;
        while (std::getline(in, line)) {
            out << line << std::endl;
            std::string hint = generateComment(line);
            if (!hint.empty()) {
                out << "    " << hint << std::endl;
            }
        }
    }
}

#endif
