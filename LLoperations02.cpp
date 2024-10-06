#include <iostream>
using namespace std;

class ColumnNode {
public:
    int colIndex;
    int value;
    ColumnNode* nextCol;

    ColumnNode(int colIndex, int value) {
        this->colIndex = colIndex;
        this->value = value;
        this->nextCol = NULL;
    }
};

class RowNode {
public:
    int rowIndex;
    RowNode* nextRow;
    ColumnNode* firstCol;

    RowNode(int rowIndex) {
        this->rowIndex = rowIndex;
        this->nextRow = NULL;
        this->firstCol = NULL;
    }
};

class SparseMatrix {
public:
    int totalRows, totalCols, nonZeroCount;
    RowNode* firstRow;

    SparseMatrix(int totalRows, int totalCols) {
        this->totalRows = totalRows;
        this->totalCols = totalCols;
        this->nonZeroCount = 0;
        this->firstRow = NULL;
    }

    void insertValue(int rowIndex, int colIndex, int value) {
        if (value == 0) return;
        nonZeroCount++;

        RowNode* row = findRow(rowIndex);
        if (!row) {
            row = new RowNode(rowIndex);
            insertRow(row);
        }

        ColumnNode* col = new ColumnNode(colIndex, value);
        insertColumn(row, col);
    }

    void printMatrix() {
        RowNode* row = firstRow;
        cout << "Original Matrix Representation:\n";
        while (row) {
            ColumnNode* col = row->firstCol;
            for (int i = 0; i < totalCols; ++i) {
                if (col && col->colIndex == i) {
                    cout << col->value << " ";
                    col = col->nextCol;
                } else {
                    cout << "0 ";
                }
            }
            cout << endl;
            row = row->nextRow;
        }
    }

    void printLinkedListStructure() {
        cout << "\nLinked List Structure:\n";
        cout << "Head Node -> ";
        RowNode* row = firstRow;
        while (row) {
            cout << "Row Node (Row " << row->rowIndex << ") -> ";
            ColumnNode* col = row->firstCol;
            while (col) {
                cout << "Column Node (Col " << col->colIndex << ", Value: " << col->value << ") -> ";
                col = col->nextCol;
            }
            cout << "NULL\n";
            row = row->nextRow;
            if (row) {
                cout << "           -> ";
            }
        }
    }

private:
    RowNode* findRow(int rowIndex) {
        RowNode* row = firstRow;
        while (row && row->rowIndex != rowIndex) {
            row = row->nextRow;
        }
        return row;
    }

    void insertRow(RowNode* newRow) {
        if (!firstRow || firstRow->rowIndex > newRow->rowIndex) {
            newRow->nextRow = firstRow;
            firstRow = newRow;
        } else {
            RowNode* temp = firstRow;
            while (temp->nextRow && temp->nextRow->rowIndex < newRow->rowIndex) {
                temp = temp->nextRow;
            }
            newRow->nextRow = temp->nextRow;
            temp->nextRow = newRow;
        }
    }

    void insertColumn(RowNode* row, ColumnNode* newCol) {
        if (!row->firstCol || row->firstCol->colIndex > newCol->colIndex) {
            newCol->nextCol = row->firstCol;
            row->firstCol = newCol;
        } else {
            ColumnNode* temp = row->firstCol;
            while (temp->nextCol && temp->nextCol->colIndex < newCol->colIndex) {
                temp = temp->nextCol;
            }
            newCol->nextCol = temp->nextCol;
            temp->nextCol = newCol;
        }
    }
};

int main() {
    int rows, cols, nonZero;
    cout << "Enter the number of rows: ";
    cin >> rows;
    cout << "Enter the number of columns: ";
    cin >> cols;

    SparseMatrix matrix(rows, cols);

    cout << "Enter the number of non-zero elements: ";
    cin >> nonZero;

    for (int i = 0; i < nonZero; ++i) {
        int row, col, value;
        cout << "Enter row index, column index, and value for non-zero element " << i + 1 << ": ";
        cin >> row >> col >> value;
        matrix.insertValue(row, col, value);
    }

    matrix.printMatrix();

    matrix.printLinkedListStructure();

    return 0;
}
