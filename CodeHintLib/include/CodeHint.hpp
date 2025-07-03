#ifndef CODE_HINT_HPP
#define CODE_HINT_HPP

#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

namespace CodeHint {



//-------------------- comment engine --------------------
inline std::string generateComment(const std::string& line) {
    using std::string;

    // Variable declarations
    if ((line.find("int ") != string::npos || line.find("float ") != string::npos || 
         line.find("double ") != string::npos || line.find("char ") != string::npos || 
         line.find("bool ") != string::npos) && line.find('=') != string::npos)
        return "// Declare and initialize a variable";

    if (line.find("int ") != string::npos || line.find("float ") != string::npos ||
        line.find("double ") != string::npos || line.find("char ") != string::npos ||
        line.find("bool ") != string::npos)
        return "// Declare a variable";

    // Print statement
    if (line.find("std::cout") != string::npos)
        return "// Print to console";

    // Input statement
    if (line.find("std::cin") != string::npos)
        return "// Take input from user";

    // Return statement
    if (line.find("return") != string::npos)
        return "// Return the result";

    // Include statement
    if (line.find("#include") != string::npos)
        return "// Include a header file";

    // Namespace usage
    if (line.find("using namespace") != string::npos)
        return "// Use standard namespace to avoid std:: prefix";

    // Function definition
    if (line.find("(") != string::npos && line.find(")") != string::npos &&
        (line.find("int ") != string::npos || line.find("void ") != string::npos || 
         line.find("float ") != string::npos || line.find("double ") != string::npos) &&
        line.find(";") == string::npos)
        return "// Function definition";

    // Function call
    if (line.find("();") != string::npos)
        return "// Call a function";

    // If condition
    if (line.find("if(") != string::npos || line.find("if (") != string::npos)
        return "// If condition";

    // Else-if condition
    if (line.find("else if") != string::npos)
        return "// Else-if condition";

    // Else block
    if (line.find("else") != string::npos && line.find("if") == string::npos)
        return "// Else block";

    // For loop
    if (line.find("for(") != string::npos || line.find("for (") != string::npos)
        return "// For loop";

    // While loop
    if (line.find("while(") != string::npos || line.find("while (") != string::npos)
        return "// While loop";

    // Do-while loop
    if (line.find("do {") != string::npos)
        return "// Do-while loop body starts";
    if (line.find("} while") != string::npos)
        return "// Do-while loop condition";

    // Switch-case
    if (line.find("switch(") != string::npos || line.find("switch (") != string::npos)
        return "// Switch statement";
    if (line.find("case ") != string::npos)
        return "// Case label in switch";
    if (line.find("default:") != string::npos)
        return "// Default case in switch";

    // Break
    if (line.find("break;") != string::npos)
        return "// Break out of loop or switch";

    // Continue
    if (line.find("continue;") != string::npos)
        return "// Skip to next loop iteration";

    // Class definition
    if (line.find("class ") != string::npos)
        return "// Class definition";

    // Struct definition
    if (line.find("struct ") != string::npos)
        return "// Struct definition";

    // Constructor or destructor
    if (line.find("::") != string::npos && line.find("()") != string::npos) {
        if (line.find("~") != string::npos)
            return "// Destructor definition";
        else
            return "// Constructor definition";
    }

    // New keyword
    if (line.find("new ") != string::npos)
        return "// Dynamically allocate memory";

    // Delete keyword
    if (line.find("delete ") != string::npos)
        return "// Free dynamically allocated memory";

    // Pointer usage
    if (line.find("*") != string::npos && line.find("=") != string::npos)
        return "// Declare and initialize pointer";

    // Reference usage
    if (line.find("&") != string::npos && line.find("=") != string::npos)
        return "// Declare and initialize reference";

    // STL containers
    if (line.find("std::vector") != string::npos)
        return "// Declare a dynamic array using std::vector";

    if (line.find("std::map") != string::npos)
        return "// Declare a key-value map using std::map";

    if (line.find("std::set") != string::npos)
        return "// Declare a unique element container using std::set";

    if (line.find("std::string") != string::npos)
        return "// Declare or use a string object";

    if (line.find("auto ") != string::npos)
        return "// Automatically deduce the type using auto";

    // Try-catch block
    if (line.find("try {") != string::npos)
        return "// Start of try block";

    if (line.find("catch") != string::npos)
        return "// Exception handler block";

    // Lambda function
    if (line.find("[]") != string::npos && line.find("=>") == string::npos)
        return "// Lambda function";

    return {};
}

inline void process(std::istream& in, std::ostream& out) {
    std::string line;
    while (std::getline(in, line)) {
        out << line << '\n';
        const std::string hint = generateComment(line);
        if (!hint.empty())
            out << "    " << hint << '\n';
    }
}

inline void SelfComment(const std::string& srcFile) {
    std::ifstream in(srcFile);
    if (!in) {
        std::cerr << "[CodeHint++] Cannot open " << srcFile << '\n';
        return;
    }

    std::string outPath = srcFile;
    const auto dotPos = outPath.find_last_of('.');
    outPath.insert(dotPos, "_commented");

    std::ofstream out(outPath);
    if (!out) {
        std::cerr << "[CodeHint++] Cannot write " << outPath << '\n';
        return;
    }

    process(in, out);
    std::cout << "[CodeHint++] Comments written to " << outPath << '\n';
}
//-------------------------------------------------------

} // namespace CodeHint
#endif
