#ifndef PARTFOURA_H
#define PARTFOURA_H

#include <unordered_map>
#include <string>

// Function to write a single byte to a binary file
void writeByte(std::ofstream& outFile, uint8_t byte);

// Function to run Part Four A
void runPartFourA(const std::string& clearFile, const std::string& codeTableFile, const std::string& codedAltFile);

#endif // PARTFOURA_H