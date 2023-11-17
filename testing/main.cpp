#include "../include/KeyExtractorIncludes.h"
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

void printKey(std::vector<unsigned char> key){
    for(unsigned char chr : key){
        std::cout << static_cast<int>(chr) << " ";
    }
    std::cout << std::endl;
}

int main() {
    try {
        // Replace with the path to your 'Local State' file
        std::string localStateFilePath = "C:\\Users\\naveh\\AppData\\Local\\Google\\Chrome\\User Data\\Local State";
        KeyExtractor keyExtractor(localStateFilePath);
        std::vector<unsigned char> key = keyExtractor.extractKey();

        std::cout << "Decrypted Key:\n ";
        printKey(key);
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
    
}
