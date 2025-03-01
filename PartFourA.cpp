#include "PartFourA.h"
#include <iostream>
#include <fstream>
#include <bitset>
#include <vector>
#include <unordered_map>
using namespace std;

// Writing single byte to binary file
void writeByte(ofstream& outFile, uint8_t byte) {
    outFile.put(static_cast<char>(byte));
}

// Function to run Part Four A
void runPartFourA(const std::string& clearFile, const std::string& codeTableFile, const std::string& codedAltFile) {

    // Initializing a map
    unordered_map<char, string> huffmanCodes;

    // Opening the codetable file
    ifstream codeTableInput(codeTableFile);
    if (!codeTableInput.is_open()) {
        cerr << "Unable to open codetable.txt file" << endl;
        return;
    }

    // Initializing strings
    string character, code;

    // Loading data from codetable into huffmanCodes map 
    while (codeTableInput >> character >> code) {
        if (character == "SP") {
            huffmanCodes[' '] = code;
        }
        else if (character == "LF") {
            huffmanCodes['\n'] = code;
        }
        else {
            huffmanCodes[character[0]] = code;
        }
    }
    codeTableInput.close();

    // Opening clear.txt file
    ifstream clearInput(clearFile);
    if (!clearInput.is_open()) {
        cerr << "Unable to open clear.txt file" << endl;
        return;
    }

    // Opening codedalt.txt file
    ofstream codedAltOutput(codedAltFile, ios::binary);
    if (!codedAltOutput.is_open()) {
        cerr << "Unable to open codedalt.txt file" << endl;
        return;
    }

    // Initializing a byte buffer to hold 8 bits 
    uint8_t byteBuffer = 0;

    // Initializing bit position counter for tracking current bit position of byteBuffer
    int positionOfBit = 0;

    // Initializing a character
    char ch;

    // Reading character one by one
    while (clearInput.get(ch)) {
        if (huffmanCodes.find(ch) != huffmanCodes.end()) {
            const string& huffCode = huffmanCodes[ch];
            // Iterating current huffman code string
            for (char bit : huffCode) {
                // Setting the bit in buffer
                if (bit == '1') {
                    byteBuffer |= (1 << (7 - positionOfBit));
                }
                positionOfBit++;

                // If buffer is null, writing the byte to file and resetting the buffer
                if (positionOfBit == 8) {
                    writeByte(codedAltOutput, byteBuffer);
                    byteBuffer = 0;
                    positionOfBit = 0;
                }
            }
        }
        else {
            cerr << "Cannot find character '" << ch << "' in codetable" << endl;
            return;
        }
    }

    // Writing the bits which are still left in the byteBuffer
    if (positionOfBit > 0) {
        writeByte(codedAltOutput, byteBuffer);
    }

    // Closing the files
    clearInput.close();
    codedAltOutput.close();

    // Printing message to ensure file is generated and data is saved into it
    cout << "\nSuccessfully completed the PartFourA: bit-level coding and saved data into codedalt.txt file" << endl;
}
