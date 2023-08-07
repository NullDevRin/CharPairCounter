#include <iostream>
#include <fstream>
#include <string>
#include <array>

int main() {

    // std::array<unsigned char, 26*26> charPairCounts{0};

    std::ifstream file("wordlist.txt");

    if (!file.is_open()) {
        std::cerr << "Error opening the file." << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(file, line)) {
        // Process the current line here
        std::cout << line << '\n'; // Example: Printing the line
    }

    file.close();

    return 0;
}