#include <iostream>
#include <queue>
#include <map>
using namespace std;

struct Node {
    char ch;
    int freq;
    Node *left, *right;

    Node(char c, int f) {
        ch = c;
        freq = f;
        left = right = NULL;
    }
};

struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq;
    }
};

void generateCodes(Node* root, string code, map<char, string>& huffmanCode) {
    if (root == NULL)
        return;

    if (root->left == NULL && root->right == NULL) {
        huffmanCode[root->ch] = code;
    }

    generateCodes(root->left, code + "0", huffmanCode);
    generateCodes(root->right, code + "1", huffmanCode);
}


void huffmanEncoding(string text) {

    // Calculate frequency of each character
    map<char, int> freq;

    for (char ch : text) {
        freq[ch]++;
    }

    // Min-heap
    priority_queue<Node*, vector<Node*>, Compare> pq;

    // Insert all characters into priority queue
    for (auto pair : freq) {
        pq.push(new Node(pair.first, pair.second));
    }

    // Build Huffman Tree
    while (pq.size() > 1) {
        Node* left = pq.top();
        pq.pop();

        Node* right = pq.top();
        pq.pop();

        Node* newNode = new Node('\0', left->freq + right->freq);

        newNode->left = left;
        newNode->right = right;

        pq.push(newNode);
    }

    Node* root = pq.top();

    // Generate codes
    map<char, string> huffmanCode;
    generateCodes(root, "", huffmanCode);

    cout << "\nHuffman Codes:\n";

    for (auto pair : huffmanCode) {
        cout << pair.first << " : " << pair.second << endl;
    }

    cout << "\nEncoded String: ";

    for (char ch : text) {
        cout << huffmanCode[ch];
    }

    cout << endl;
}

int main() {

    string text;

    cout << "Enter the string: ";
    cin >> text;

    huffmanEncoding(text);

    return 0;
}



