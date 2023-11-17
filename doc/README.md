# Chrome Password Decryptor 💻🔓

## Overview
This project is a C++ application designed to decrypt saved passwords from Google Chrome's 'Login Data' file, utilizing the encrypted key stored in Chrome's 'Local State' file.

### Objectives
- Extract the encrypted key from the 'Local State' file.
- Decrypt the key using Windows Data Protection API (DPAPI).
- Decrypt passwords from the 'Login Data' file using the decrypted key.

## Implementation
The project uses C++ and incorporates various libraries alongside Windows-specific APIs.

### Key Features
- Extraction and Base64 decoding of the encrypted key.
- Decryption of the key using DPAPI.
- Decoding and decrypting of saved passwords in Chrome.

## Current Status
🚧 Under development.

## Prerequisites
- Windows OS.
- Google Chrome.
- C++ development tools.

## Dependencies and Installation

### Dependencies
1. **nlohmann/json** for JSON parsing - [Download here](https://github.com/nlohmann/json/releases)
2. **cppcodec** for Base64 encoding/decoding - [Download here](https://github.com/tplgy/cppcodec)
3. **OpenSSL** for AES encryption - Typically included in most C++ development environments. If not, [download here](https://www.openssl.org/source/)
4. **SQLiteCpp** for interacting with Chrome's SQLite databases - [Download here](https://github.com/SRombauts/SQLiteCpp)

### Installation
Clone the repository:
git clone [repository URL]
cd [repository directory]

### Install the dependencies:
Place nlohmann/json and cppcodec in your project's include directory.
Ensure OpenSSL and SQLiteCpp are installed and included in your project.

### Build and Compile
Compile the project using the following command:
g++ -o main.exe src/KeyExtractor.cpp -I"include" -I"[path to json include]" -I"[path to cppcodec include]" -I"[path to OpenSSL include]" -I"[path to SQLiteCpp include]" -lcrypt32

### License
This project is under MIT license.
