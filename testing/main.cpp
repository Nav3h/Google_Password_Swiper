#include "../include/KeyExtractorIncludes.h"
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

// Function to print bytes in hexadecimal format
void printHex(const std::vector<unsigned char>& data) {
    for (auto byte : data) {
        std::cout << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(byte);
    }
    std::cout << std::endl;
}

int main() {
    try {
        // Replace with the path to your 'Local State' file
        std::string localStateFilePath = "C:\\Users\\naveh\\AppData\\Local\\Google\\Chrome\\User Data\\Local State";
        KeyExtractor keyExtractor(localStateFilePath);
        std::vector<unsigned char> key = keyExtractor.extractKey();

        std::cout << "Decrypted Key: ";
        printHex(key);
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
