#include<bits/stdc++.h>
using namespace std;

// Defining a node structure
struct Node {
    int row;
    int col;
    int value;
    Node* next;
};

// Initializing a linked list for the sparse matrix
void initializeLinkedList(Node** start, int m, int n) {
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            int value;
            cout << "Enter value for cell (" << i+1 << "," << j+1 << "): ";
            cin >> value;
            if(value != 0) {
                Node* newNode = new Node;
                newNode->row = i;
                newNode->col = j;
                newNode->value = value;
                newNode->next = *start;
                *start = newNode;
            }
        }
    }
}

// Function to print the sparse matrix
void printSparseMatrix(Node* start) {
    while(start != NULL) {
        cout << "Value: " << start->value << " at (" << start->row+1 << "," << start->col+1 << ")" << endl;
        start = start->next;
    }
}

int main() {
    int m, n;
    cout << "Enter the number of rows: ";
    cin >> m;
    cout << "Enter the number of columns: ";
    cin >> n;

    Node* start = NULL;
    initializeLinkedList(&start, m, n);
    printSparseMatrix(start);

    return 0;
}