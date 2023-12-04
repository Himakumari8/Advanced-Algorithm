#include <iostream>
#include <queue>
using namespace std;

// Defining Node Structure
struct Node {
    char data;
    int freq;
    Node *left, *right;

    Node(char data, int freq) {
        this->data = data;
        this->freq = freq;
        this->left = this->right = NULL;
    }
};

// Defining Priority Queue Comparator
struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq;
    }
};

// Function to build Huffman Tree
Node* buildHuffmanTree(char data[], int freq[], int size) {
    // Creating priority queue and initializing it with leaves nodes
    priority_queue<Node*, vector<Node*>, Compare> pq;

    for (int i = 0; i < size; i++) {
        pq.push(new Node(data[i], freq[i]));
    }

    // Creating internal nodes in the priority queue and building Huffman Tree
    while (pq.size() != 1) {
        Node* left = pq.top();
        pq.pop();

        Node* right = pq.top();
        pq.pop();

        Node* newNode = new Node('$', left->freq + right->freq);
        newNode->left = left;
        newNode->right = right;

        pq.push(newNode);
    }

    return pq.top();
}

// Function to print Huffman Codes
void printHuffmanCodes(Node* root, string str) {
    if (root == NULL) {
        return;
    }

    if (root->left == NULL && root->right == NULL) {
        cout << root->data << " : " << str << endl;
    }

    printHuffmanCodes(root->left, str + "0");
    printHuffmanCodes(root->right, str + "1");
}

int main() {
    char data[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
    int freq[] = { 5, 9, 12, 13, 16, 45 };
    int size = sizeof(data) / sizeof(data[0]);

    Node* root = buildHuffmanTree(data, freq, size);

    cout << "Huffman Codes: \n";
    printHuffmanCodes(root, "");

    return 0;
}
