#include "PartOne.h"
#include <iostream>
#include <fstream>
#include <map>
#include <string>

// Function to open a file for reading
std::ifstream openInputFile(const std::string& fileName) {
    std::ifstream file(fileName, std::ios::in);
    if (!file) {
        std::cerr << "Error: Unable to open file " << fileName << std::endl;
        exit(1); // Exit on failure
    }
    return file;
}

// Function to open a file for writing
std::ofstream openOutputFile(const std::string& fileName) {
    std::ofstream file(fileName, std::ios::out);
    if (!file) {
        std::cerr << "Error: Unable to open file " << fileName << std::endl;
        exit(1); // Exit on failure
    }
    return file;
}

// Function to format ASCII character for output
std::string formatCharacter(int asciiCode) {
    if (asciiCode == 10) {
        return "LF"; // Line feed (newline character)
    }
    else if (asciiCode == 32) {
        return "SP"; // Space character
    }
    else if (asciiCode >= 33 && asciiCode <= 126) {
        return std::string(1, static_cast<char>(asciiCode)); // Printable characters
    }
    else {
        return ""; // Non-printable characters (optional handling)
    }
}

// Function to print character frequencies
void printFrequencies(const std::map<int, int>& charFrequency, const std::string& outputFileName) {
    std::ofstream outputFile = openOutputFile(outputFileName);

    for (const auto& entry : charFrequency) {
        if (entry.second > 0) { // Only write non-zero counts
            std::string charRepresentation = formatCharacter(entry.first);
            if (!charRepresentation.empty()) {
                outputFile << charRepresentation << " " << entry.second << std::endl;
            }
        }
    }
    outputFile.close();
}

// Function to execute Part One logic
void runPartOne(const std::string& inputFileName, const std::string& outputFileName) {
    // Open the input file
    std::ifstream inputFile = openInputFile(inputFileName);

    // Map to store character frequencies
    std::map<int, int> charFrequency;

    // Read the input file character by character
    char ch;
    while (inputFile.get(ch)) {
        int asciiCode = static_cast<int>(ch);
        if (asciiCode >= 0 && asciiCode < 128) { // ASCII range check
            charFrequency[asciiCode]++;
        }
    }

    // Close the input file
    inputFile.close();

    // Write the frequencies to the output file
    printFrequencies(charFrequency, outputFileName);

    std::cout << "Part1: Character frequency calculation completed. Output written to " << outputFileName << "." << std::endl;
}