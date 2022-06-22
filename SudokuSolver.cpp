// TC: O(9^m) where m is the number of empty places in the sudoku
// SC: O(1)
#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    bool canPlace(vector<vector<char>>& board, int num, int row, int col) {
        // check in the same row
        for(int j = 0; j < 9; j++) {
            if(board[row][j] == num + '0') return false;
        }

        // check in the same col
        for(int i = 0; i < 9; i++) {
            if(board[i][col] == num + '0') return false;
        }

        // check in the sub grid
        int startRow = 3 * (row/3);
        int startCol = 3 * (col/3);
        for(int i = startRow; i < startRow + 3; i++) {
            for(int j = startCol; j < startCol + 3; j++) {
                if(board[i][j] == num + '0') return false;
            }
        }
        return true;

    }
private:
    bool helpSolveSudoku(vector<vector<char>>& board) {
        int row = -1, col = -1;
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if(board[i][j] == '.') {
                    row = i;
                    col = j;
                    break;
                }
            }
        }
        if(row == -1 and col == -1) return true;


        for(int num = 1; num <= 9; num++) {
            if(canPlace(board, num, row, col)) {
                board[row][col] = num + '0';
                bool remainingGrid = helpSolveSudoku(board);
                if(remainingGrid) return true;
                else {
                    board[row][col] = '.';
                }
            }
        }
        return false;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        bool ans = helpSolveSudoku(board);
    }
};

int main() {

 #ifndef ONLINE_JUDGE
 freopen("input.txt", "r", stdin);
 freopen("output.txt", "w", stdout);
 #endif

    Solution obj;
    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','.','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'},
    };

    obj.solveSudoku(board);
    for(auto &row: board) {
        for(auto &col: row) cout << col << " ";
            cout << endl;
    }
    return 0;
}