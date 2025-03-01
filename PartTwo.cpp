
#include "PartTwo.h"
#include <fstream>
#include <iostream>

// Initializing constructor when initially creating nodes.
Node::Node(char ch, int freq) :
    character(ch),
    frequency(freq),
    left(nullptr),
    right(nullptr)
{}

// Initializing constructor for root nodes.
Node::Node(char ch, int freq, Node* leftChild, Node* rightChild) :
    character(ch),
    frequency(freq),
    left(leftChild),
    right(rightChild)
{}

// Function to insert a node into the sorted list. This is done at the beginning
// of the program and after calculating the sum of the two lowest freq nodes. 
// An iterator is used to go through the list and find the adequate spot to insert.
void insertSorted(std::list<Node*>& nodeList, Node* newNode) {
    for (auto it = nodeList.begin(); it != nodeList.end(); ++it) {
        if ((*it)->frequency > newNode->frequency) {
            nodeList.insert(it, newNode);
            return;
        }
    }
    // Else, put it at the end of the list.
    nodeList.push_back(newNode);
}

// Function that implements the Huffman algorithm to build the tree. 
// Will create the tree and return the root node at the end.
Node* buildHuffmanTree(std::list<Node*>& nodes) {

    // While we still have more than one tree...
    while (nodes.size() > 1) {

        // Store the two lowest frequency nodes and remove them.
        Node* left = nodes.front();
        nodes.pop_front();
        Node* right = nodes.front();
        nodes.pop_front();
        
        // Sum the frequencies of the two lowest frequency nodes.
        int sum = left->frequency + right->frequency;

        // Create a new root from these frequencies. We assign it the NULL char
		// since it isn't holding an actual character.
        Node* rootNode = new Node('\0', sum, left, right);

        // Insert the node in its sorted spot like the algorithm does.
        insertSorted(nodes, rootNode);
    }

    // Once done, we will have a full tree with just one node. Return the root.
    return nodes.front();
}

// Function that will generate the Huffman codes recursively for the characters and their frequencies.
void generateCodes(Node* root, const std::string& code, std::map<char, std::string>& binaryCodes) {

    // Stop if we reach a nullptr.
    if (root == nullptr) return;

    // If we have a leaf, map the char and its code.
    if (root->left == nullptr && root->right == nullptr) {
        binaryCodes[root->character] = code;
    }

    // Recursively repeat these steps for the left and right children.
    // Taking a left is 0 and taking a right is 1.
    generateCodes(root->left, code + "0", binaryCodes);
    generateCodes(root->right, code + "1", binaryCodes);
}

// Function that will output the code table text file.
void writeCodeTable(const std::map<char, std::string>& binaryCodes) {
    std::ofstream outFile("codetable.txt");

    // Using an iterator to go through the map and write the table.
    for (const auto& entry : binaryCodes) {
        char ch = entry.first;
        std::string code = entry.second;

        // The two special characters we should handle.
        if (ch == '\n') {
            outFile << "LF " << code << '\n';
        }
        else if (ch == ' ') {
            outFile << "SP " << code << '\n';
        }
        else {
            outFile << ch << " " << code << '\n';
        }
    }
    outFile.close();
}

// Main function for PartTwo
void runPartTwo(const std::string& freqFileName, const std::string& outputFileName) {
    std::list<Node*> nodes;
    std::ifstream file(freqFileName);

    // Open the freq.txt file from part 1. Show an error if it failed to open.
    if (!file.is_open()) {
        std::cout << "Error when opening the " << freqFileName << " file!" << std::endl;
        return;
    }

    // Get the file contents. Handle line feed and spaces. The rest are just
	// single characters which are all handled.
    std::string characterString;
    int frequency;
    while (file >> characterString >> frequency) {
        char ch;
        if (characterString == "LF") {
            ch = '\n';
        }
        else if (characterString == "SP") {
            ch = ' ';
        }
        else {
            ch = characterString[0];
        }

        // Call the initializing constructor and insert the nodes in sorted order.
        // That way, we start with them all sorted when performing the algorithm.
        insertSorted(nodes, new Node(ch, frequency));
    }
    file.close();

    // Detect empty freq.txt files.
    if (nodes.size() < 1) {
        std::cerr << "Empty freq.txt file!" << std::endl;
        return;
    }

    // We handle the case when there is just one symbol in freq.txt by just making
    // it have a code of 0 in the code table.
    if (nodes.size() == 1) {
        Node* singleNode = nodes.front();
        std::map<char, std::string> binaryCodes;

        // Assign a single code of 0 to the character
        binaryCodes[singleNode->character] = "0";

        // Write the code table
        writeCodeTable(binaryCodes);
        std::cout << "Successfully created codetable.txt!" << std::endl;
        return;
    }

    // Build the huffman tree. We have a pointer to the root node.
    Node* root = buildHuffmanTree(nodes);

    // Generate the binary codes using a map containing the char and its Huffman code.
    // It will help us write the code table by sorted ASCII characters.
    std::map<char, std::string> binaryCodes;
    generateCodes(root, "", binaryCodes);

    // Write and output the code table.
    writeCodeTable(binaryCodes);

    std::cout << "\nPart2: Successfully created codetable.txt!" << std::endl;
}
