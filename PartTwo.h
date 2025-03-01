#ifndef PARTTWO_H
#define PARTTWO_H

#include <map>
#include <list>
#include <string>

// Node class for the Huffman tree.
struct Node {

    // Public member variables for simplicty.
    char character;
    int frequency;
    Node* left;
    Node* right;

    // Initializing constructor when initially creating nodes.
    Node(char ch, int freq);

    // Initializing constructor for root nodes.
    Node(char ch, int freq, Node* leftChild, Node* rightChild);
};

// Function to insert nodes into the sorted list.
void insertSorted(std::list<Node*>& nodeList, Node* newNode);

// Function that builds the Huffman Tree by following the algorithm.
Node* buildHuffmanTree(std::list<Node*>& nodes);

// Function to generate the Huffman codes.
void generateCodes(Node* root, const std::string& code, std::map<char, std::string>& binaryCodes);

// Function that writes the code table text file.
void writeCodeTable(const std::map<char, std::string>& binaryCodes);

// Function that will execute the part two logic.
void runPartTwo(const std::string& freqFileName, const std::string& outputFileName);

#endif // PARTTWO_H