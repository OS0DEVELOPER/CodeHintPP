# CodeHint++

🧠 A header-only C++ library that automatically adds **human-readable comments** to your C++ code by analyzing line-by-line logic. Perfect for:
- Beginners who want help understanding code
- Teachers generating teaching materials
- Devs adding quick explanations to legacy code

---

## 🔧 Features

- 📄 Auto-comments basic C++ logic: variables, loops, conditionals, returns
- ⚙️ Header-only: just include `CodeHint.hpp`
- 🧪 Simple demo app provided
- 🧰 Works with any C++17+ project

---

## 📦 Folder Structure

CodeHintPP/
├── CodeHintLib/
│ └── include/
│ └── CodeHint.hpp # The header-only comment generator
├── CodeHintDemo/
│ ├── demo.cpp # Sample program using the library
│ └── mycode.cpp # Sample input code to be commented
├── build/ # Will be created after build
├── LICENSE
└── README.md

yaml
Copy
Edit

---

## 🛠️ Installation

### 🔧 Prerequisites:
- [CMake](https://cmake.org/download/)
- C++17 compiler (MSVC, g++, or clang++)

### 🔨 Build Instructions:

```bash
git clone https://github.com/OS0DEVELOPER/CodeHintPP.git
cd CodeHintPP
mkdir build && cd build
cmake ..
cmake --build .
🚀 How to Run
Copy your .cpp file into the folder where the executable is:

bash
Copy
Edit
copy CodeHintDemo\mycode.cpp build\CodeHintDemo\Debug\
Run the tool:

bash
Copy
Edit
cd build\CodeHintDemo\Debug
CodeHintDemo.exe
Output:

You’ll get a file named mycode_commented.cpp with inline comments added automatically.

💡 Example Output
🔹 Original: mycode.cpp
cpp
Copy
Edit
int add(int a, int b) {
    int sum = a + b;
    std::cout << sum << std::endl;
    return sum;
}
🔹 Generated: mycode_commented.cpp
cpp
Copy
Edit
int add(int a, int b) {
    int sum = a + b;
    // Declare and initialize integer

    std::cout << sum << std::endl;
    // Print to console

    return sum;
    // Return the result
}
🧠 How It Works
The CodeHint::commentFunction(std::istream&, std::ostream&) function reads your .cpp file line-by-line.

It uses pattern matching to detect:

Variable declarations

Print statements

Return values

Control structures (in future versions)

And then writes comments directly above each line.

Future versions will support more patterns and even AI-powered explanation generation.

🪪 License
MIT License
Feel free to use, modify, or contribute. See the LICENSE file.

🤝 Contributing
Fork this repository

Make your changes

Submit a pull request

Ideas welcome for:

Better comment generation logic

A drag-and-drop GUI version

More language support (Python, Java, etc.)

👨‍💻 Author
Om Tirkhunde
🔗 GitHub Profile

yaml
Copy
Edit

---

### ✅ How to Add This to GitHub

1. Open CMD:
   ```bash
   cd F:\CodeHintPP
   notepad README.md
Paste the cleaned content above and save.

Then run:

bash
Copy
Edit
git add README.md
git commit -m "Add complete README with usage, install guide and example"
git push
