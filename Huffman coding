#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// Node structure
struct Node {
    char data;
    int freq;
    Node *left, *right;

    Node(char data, int freq) {
        this->data = data;
        this->freq = freq;
        left = right = NULL;
    }
};

// Comparator for priority queue (min heap)
struct Compare {
    bool operator()(Node* l, Node* r) {
        return l->freq > r->freq;
    }
};

// Function to print Huffman codes
void printCodes(Node* root, string code) {
    if (!root)
        return;

    // If leaf node
    if (root->data != '$')
        cout << root->data << ": " << code << endl;

    printCodes(root->left, code + "0");
    printCodes(root->right, code + "1");
}

// Function to build Huffman Tree
void huffmanCoding(char data[], int freq[], int size) {
    priority_queue<Node*, vector<Node*>, Compare> pq;

    // Create leaf nodes and push into queue
    for (int i = 0; i < size; i++) {
        pq.push(new Node(data[i], freq[i]));
    }

    // Build tree
    while (pq.size() > 1) {
        Node *left = pq.top(); pq.pop();
        Node *right = pq.top(); pq.pop();

        Node *newNode = new Node('$', left->freq + right->freq);
        newNode->left = left;
        newNode->right = right;

        pq.push(newNode);
    }

    // Print codes
    Node* root = pq.top();
    printCodes(root, "");
}

int main() {
    int n;

    cout << "Enter number of characters: ";
    cin >> n;

    char data[n];
    int freq[n];

    cout << "Enter characters:\n";
    for (int i = 0; i < n; i++) {
        cin >> data[i];
    }

    cout << "Enter frequencies:\n";
    for (int i = 0; i < n; i++) {
        cin >> freq[i];
    }

    cout << "\nHuffman Codes:\n";
    huffmanCoding(data, freq, n);

    return 0;
}
