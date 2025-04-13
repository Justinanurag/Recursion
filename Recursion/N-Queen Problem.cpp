#include <iostream>
#include <vector>
using namespace std;

// Check if it's safe to place the Queen
bool isSafe(int row, int col, vector<string> &board, int n) {
    int dupRow = row, dupCol = col;

    // Check upper-left diagonal (↖)
    while (row >= 0 && col >= 0) {
        if (board[row][col] == 'Q') return false;
        row--;
        col--;
    }

    // Check left side (←)
    row = dupRow;
    col = dupCol;
    while (col >= 0) {
        if (board[row][col] == 'Q') return false;
        col--;
    }

    // Check lower-left diagonal (↙)
    row = dupRow;
    col = dupCol;
    while (row < n && col >= 0) {
        if (board[row][col] == 'Q') return false;
        row++;
        col--;
    }

    return true;
}

// Recursively solve the N-Queens problem
void solve(int col, vector<string> &board, vector<vector<string>> &ans, int n) {
    if (col == n) { // Base case: all queens placed
        ans.push_back(board);
        return;
    }

    for (int row = 0; row < n; row++) {
        if (isSafe(row, col, board, n)) {
            board[row][col] = 'Q'; // Place queen
            solve(col + 1, board, ans, n); // Recur for next column
            board[row][col] = '.'; // Backtrack
        }
    }
}

// Driver function to start solving
vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> ans;
    vector<string> board(n, string(n, '.'));
    solve(0, board, ans, n);
    return ans;
}

// Main function to print result
int main() {
    int n = 4;
    vector<vector<string>> res = solveNQueens(n);

    for (auto &board : res) {
        for (auto &row : board) {
            cout << row << endl;
        }
        cout << "-----------" << endl;
    }

    return 0;
}
