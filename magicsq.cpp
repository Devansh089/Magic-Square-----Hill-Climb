#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> createOddMagic(int size) {
    vector<vector<int>> grid(size, vector<int>(size, 0));
    int row = size / 2, col = size - 1;

    for (int val = 1; val <= size * size; ++val) {
        grid[row][col] = val;

        if (val % size == 0) {
            col--;
        } else {
            row--; col++;
        }

        row = (row + size) % size;
        col = (col + size) % size;
    }
    return grid;
}

vector<vector<int>> createDoublyEvenMagic(int size) {
    vector<vector<int>> grid(size, vector<int>(size));
    int val = 1;

    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            grid[i][j] = val++;

    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            if ((i % 4 == j % 4) || ((i % 4) + (j % 4) == 3))
                grid[i][j] = size * size + 1 - grid[i][j];

    return grid;
}

vector<vector<int>> createSinglyEvenMagic(int size) {
    int half = size / 2;
    int block = half * half;
    vector<vector<int>> mini = createOddMagic(half);
    vector<vector<int>> grid(size, vector<int>(size));

    for (int i = 0; i < half; ++i) {
        for (int j = 0; j < half; ++j) {
            int val = mini[i][j];
            grid[i][j] = val;
            grid[i + half][j + half] = val + block;
            grid[i][j + half] = val + 2 * block;
            grid[i + half][j] = val + 3 * block;
        }
    }

    int swapCount = (size - 2) / 4;
    for (int i = 0; i < half; ++i) {
        for (int j = 0; j < swapCount; ++j)
            swap(grid[i][j], grid[i + half][j]);
        for (int j = size - swapCount + 1; j < size; ++j)
            swap(grid[i][j], grid[i + half][j]);
    }

    swap(grid[swapCount][0], grid[swapCount + half][0]);
    swap(grid[swapCount][swapCount], grid[swapCount + half][swapCount]);

    return grid;
}

vector<vector<int>> generateMagicSquare(int size) {
    if (size % 2 == 1) return createOddMagic(size);
    if (size % 4 == 0) return createDoublyEvenMagic(size);
    return createSinglyEvenMagic(size);
}

int main() {
    int n;
    cout << "Enter the order of the magic square: ";
    cin >> n;

    if (n < 3) {
        cout << "Magic square is not defined for n < 3.\n";
        return 0;
    }

    vector<vector<int>> magic = generateMagicSquare(n);
    for (const auto& row : magic) {
        for (int val : row)
            cout << val << " ";
        cout << "\n";
    }

    return 0;
}