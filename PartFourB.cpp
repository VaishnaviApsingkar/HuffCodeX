#include "PartFourB.h"
#include <iostream>
#include <fstream>
#include <unordered_map>
#include <string>
#include <bitset>

using namespace std;

// Function to run Part Four B
// The file paths for input and output are passed in as parameters.
void runPartFourB(const std::string& codedAltFile, const std::string& codeTableFile, const std::string& decodedAltFile) {

    // Create a map to store Huffman codes and their corresponding characters
    unordered_map<string, char> huffmanCodes;

    // Open the codetable file to read the codes
    ifstream codeTableInput(codeTableFile);
    if (!codeTableInput.is_open()) {
        cerr << "Error opening codetable.txt" << endl;
        return;
    }

    // Read the codetable and store the mappings in the map
    string character, code;
    while (codeTableInput >> character >> code) {
        if (character == "SP") {
            huffmanCodes[code] = ' ';
        }
        else if (character == "LF") {
            huffmanCodes[code] = '\n';
        }
        else {
            huffmanCodes[code] = character[0];
        }
    }
    codeTableInput.close();

    // Open the binary encoded file for reading and the decoded file for writing
    ifstream codedAltInput(codedAltFile, ios::binary);
    ofstream decodedAltOutput(decodedAltFile);
    if (!codedAltInput.is_open()) {
        cerr << "Error opening codedalt.txt" << endl;
        return;
    }
    if (!decodedAltOutput.is_open()) {
        cerr << "Error opening decodedalt.txt" << endl;
        return;
    }

    // Initialize a string to hold the current Huffman code being decoded
    string currentCode;
    char byte;

    // Read the binary file one byte at a time
    while (codedAltInput.get(byte)) {
        // Convert the byte to its bit representation
        bitset<8> bits(static_cast<unsigned char>(byte)); // Convert byte to bits

        // Process each bit in the byte
        for (int i = 7; i >= 0; --i) {
            currentCode += (bits[i] ? '1' : '0'); // Append current bit to the code

            // Check if the current code matches a Huffman code
            if (huffmanCodes.find(currentCode) != huffmanCodes.end()) {
                // Write the decoded character to the output file
                decodedAltOutput << huffmanCodes[currentCode];
                // Clear the current code to start decoding the next character
                currentCode.clear();
            }
        }
    }

    // Close the input and output files
    codedAltInput.close();
    decodedAltOutput.close();

    cout << "\nPart4B: Decoding completed successfully. Check decodedalt.txt!" << endl;
}