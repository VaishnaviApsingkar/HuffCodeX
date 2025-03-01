#include "PartThreeA.h"
using namespace std;

// Function to run Part Three A
void runPartThreeA(const string& clearFile, const string& codeTableFile, const string& codedFile) {

    // Load codetable into a map
    unordered_map<char, string> huffmanCodes;
    ifstream codeTableInput(codeTableFile);

    // Check if codetable.txt can be opened
    if (!codeTableInput.is_open()) {
        cerr << "Error opening codetable.txt" << endl;
        return;
    }

    string character;
    string code;
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

    // Open clear.txt for reading and coded.txt for writing
    ifstream clearInput(clearFile);
    ofstream codedOutput(codedFile);
    if (!clearInput.is_open()) {
        cerr << "Error opening clear.txt" << endl;
        return;
    }
    if (!codedOutput.is_open()) {
        cerr << "Error opening coded.txt" << endl;
        return;
    }

    // Process clear.txt character by character
    char ch;
    while (clearInput.get(ch)) {  // Read one character at a time
        if (huffmanCodes.find(ch) != huffmanCodes.end()) {
            codedOutput << huffmanCodes[ch]; // Write the corresponding Huffman code
        }
        else {
            cerr << "Error: Character '" << ch << "' not found in codetable!" << endl;
            return;
        }
    }

    // Close all files
    clearInput.close();
    codedOutput.close();

    // Success message
    cout << "\nPart3A: Coding completed successfully. Check coded.txt!" << endl;
}