#ifndef PARTONE_H
#define PARTONE_H

#include <string>
#include <map>

// Function to open a file for reading
std::ifstream openInputFile(const std::string& fileName);

// Function to open a file for writing
std::ofstream openOutputFile(const std::string& fileName);

// Function to format ASCII character for output
std::string formatCharacter(int asciiCode);

// Function to print character frequencies
void printFrequencies(const std::map<int, int>& charFrequency, const std::string& outputFileName);

// Function to run Part One logic
void runPartOne(const std::string& inputFileName, const std::string& outputFileName);

#endif // PARTONE_H