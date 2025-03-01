#ifndef PARTTHREEB_H
#define PARTTHREEB_H

#include <unordered_map>
#include <string>

// Function to load the code table into a map.
void loadCodeTable(const std::string& filename, std::unordered_map<std::string, char>& codeTable);

// Function to decode the coded file.
void decodeFile(const std::string& codedFile, const std::unordered_map<std::string, char>& codeTable, const std::string& outputFile);

// Function to run Part Three B.
void runPartThreeB(const std::string& codeTableFile, const std::string& codedFile, const std::string& clearFile, const std::string& decodedFile);

#endif // PARTTHREEB_H