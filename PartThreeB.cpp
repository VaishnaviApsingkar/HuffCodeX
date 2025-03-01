#include "PartThreeB.h"
#include <fstream>
#include <iostream>

void loadCodeTable(const std::string& filename, std::unordered_map<std::string, char>& codeTable) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Error: Cannot open code table file.\n";
        exit(1);
    }

    std::string line;
    while (std::getline(file, line)) {
        std::string key;
        char character;
        if (line.substr(0, 2) == "SP") {
            character = ' '; // Handle space
            key = line.substr(3);
        }
        else if (line.substr(0, 2) == "LF") {
            character = '\n'; // Handle line feed
            key = line.substr(3);
        }
        else {
            character = line[0]; // Regular character
            key = line.substr(2);
        }
        codeTable[key] = character; // Map the code to its character
    }
    file.close();
}

void decodeFile(const std::string& codedFile, const std::unordered_map<std::string, char>& codeTable, const std::string& outputFile) {
    std::ifstream coded(codedFile, std::ios::binary);
    std::ofstream decoded(outputFile);
    if (!coded || !decoded) {
        std::cerr << "Error: Cannot open input or output file.\n";
        exit(1);
    }

    std::string buffer;
    char ch;
    while (coded.get(ch)) {
        buffer += ch; // Add to the buffer
        auto it = codeTable.find(buffer);
        if (it != codeTable.end()) {
            decoded.put(it->second); // Write the decoded character
            buffer.clear(); // Clear the buffer for the next code
        }
    }

    coded.close();
    decoded.close();
}

// Function to run Part Three B
void runPartThreeB(const std::string& codeTableFile, const std::string& codedFile, const std::string& clearFile, const std::string& decodedFile) {
    // Step 1: Load the code table
    std::unordered_map<std::string, char> codeTable;
    loadCodeTable(codeTableFile, codeTable);

    // Step 2: Decode the coded file
    decodeFile(codedFile, codeTable, decodedFile);

    // Step 3: Analyze file sizes
    std::ifstream clear(clearFile, std::ios::binary | std::ios::ate);
    std::ifstream coded(codedFile, std::ios::binary | std::ios::ate);
    if (clear && coded) {
        std::cout << "\nPart3B: decoded.txt has been written!" << std::endl;
        std::cout << "Size of clear.txt: " << clear.tellg() << " bytes\n";
        std::cout << "Size of coded.txt: " << coded.tellg() << " bytes\n";
    }
    else {
        std::cerr << "Error: Cannot retrieve file sizes.\n";
    }
}