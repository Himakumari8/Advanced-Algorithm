#include <iostream>
#include <vector>

struct SparseMatrix {
    std::vector<std::vector<int>> data;
    int totalNonZeroValues;
};

void addElement(int row, int col, int value, SparseMatrix *sparseMatrix) {
    if (sparseMatrix->data.size() <= row) {
        sparseMatrix->data.resize(row + 1);
    }
    if (sparseMatrix->data[row].size() <= col) {
        sparseMatrix->data[row].resize(col + 1, 0);
    }
    sparseMatrix->data[row][col] = value;
    sparseMatrix->totalNonZeroValues++;
}

void displaySparseMatrix(SparseMatrix *sparseMatrix) {
    std::cout << "Non-zero elements of the sparse matrix are:" << std::endl;
    for (int i = 0; i < sparseMatrix->data.size(); i++) {
        for (int j = 0; j < sparseMatrix->data[i].size(); j++) {
            if (sparseMatrix->data[i][j] != 0) {
                std::cout << "(" << i << ", " << j << ") = " << sparseMatrix->data[i][j] << std::endl;
            }
        }
    }
}

void destroySparseMatrix(SparseMatrix *sparseMatrix) {
    sparseMatrix->data.clear();
    sparseMatrix->totalNonZeroValues = 0;
}

int main() {
    SparseMatrix sparseMatrix;
    sparseMatrix.totalNonZeroValues = 0;

    addElement(0, 0, 1, &sparseMatrix);
    addElement(1, 1, 2, &sparseMatrix);
    addElement(2, 2, 3, &sparseMatrix);

    displaySparseMatrix(&sparseMatrix);

    destroySparseMatrix(&sparseMatrix);

    return 0;
}