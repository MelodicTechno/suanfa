#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

// A Huffman tree node
struct Node {
    char ch;
    int freq;
    Node *left, *right;

    Node(char ch, int freq) : ch(ch), freq(freq), left(nullptr), right(nullptr) {}

    // Utility function to delete the tree
    ~Node() {
        delete left;
        delete right;
    }
};

// Comparison object to be used to order the heap
struct compare {
    bool operator()(Node* l, Node* r) {
        return (l->freq > r->freq);
    }
};

// Utility function to check if Huffman Tree contains only a single node
bool isLeaf(Node* root) {
    return !root->left && !root->right;
}

// Traverse the Huffman Tree and store Huffman Codes in a map.
void encode(Node* root, string str, unordered_map<char, string> &huffmanCode) {
    if (root == nullptr)
        return;

    // found a leaf node
    if (isLeaf(root)) {
        huffmanCode[root->ch] = str;
    }

    encode(root->left, str + "0", huffmanCode);
    encode(root->right, str + "1", huffmanCode);
}

// Build Huffman Tree and return the root node
Node* buildHuffmanTree(const unordered_map<char, int> &freq) {
    priority_queue<Node*, vector<Node*>, compare> pq;

    // Create a leaf node for each character and add it to the priority queue.
    for (auto pair : freq) {
        pq.push(new Node(pair.first, pair.second));
    }

    // do till there is more than one node in the queue
    while (pq.size() != 1) {
        // Remove the two nodes of highest priority (lowest frequency) from the queue
        Node *left = pq.top(); pq.pop();
        Node *right = pq.top(); pq.pop();

        // Create a new internal node with these two nodes as children
        Node* sumNode = new Node('\0', left->freq + right->freq);
        sumNode->left = left;
        sumNode->right = right;

        pq.push(sumNode);
    }

    // The remaining node is the root of the Huffman Tree
    return pq.top();
}

// Function to decode the encoded string
string decode(Node* root, const string &binaryString) {
    string decodedString = "";
    Node* current = root;
    for (char bit : binaryString) {
        if (bit == '0')
            current = current->left;
        else
            current = current->right;

        if (isLeaf(current)) {
            decodedString += current->ch;
            current = root; // start again from the root
        }
    }
    return decodedString;
}

int main() {
    string text = "Huffman coding is a data compression algorithm.";

    // count frequency of appearance of each character
    unordered_map<char, int> freq;
    for (char ch : text) {
        freq[ch]++;
    }

    // Build Huffman Tree
    Node* root = buildHuffmanTree(freq);

    // Traverse the Huffman Tree and store Huffman Codes in a map.
    unordered_map<char, string> huffmanCode;
    encode(root, "", huffmanCode);

    // Print Huffman Codes
    cout << "Huffman Codes are:\n";
    for (auto pair : huffmanCode) {
        cout << pair.first << " " << pair.second << '\n';
    }

    // Encode the text
    string encodedString = "";
    for (char ch : text) {
        encodedString += huffmanCode[ch];
    }

    // Print encoded string
    cout << "\nEncoded string is:\n" << encodedString << '\n';

    // Decode the encoded string
    string decodedString = decode(root, encodedString);

    // Print decoded string
    cout << "\nDecoded string is:\n" << decodedString << '\n';

    // Clean up memory
    delete root;

    return 0;
}
