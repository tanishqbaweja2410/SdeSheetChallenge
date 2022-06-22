// TC: exponential => to be precise O(N! * N)
// SC: O(N^2)
class Solution {
private:
    bool canPlace(vector<vector<char>> &board, int n, int x, int y) {
        // check in the same column 
        for(int row = x - 1; row >= 0; row--) {
            if(board[row][y] == 'Q') return false;
        }

        // check in the left diagonal
        int row = x - 1;
        int col = y - 1;
        while(row >= 0 && col >= 0) {
            if(board[row][col] == 'Q') return false;
            row--;
            col--;
        }

        // check in the right diagonal
        row = x - 1;
        col = y + 1;
        while(row >= 0 && col < n) {
            if(board[row][col] == 'Q') return false;
            row--;
            col++;
        }

        return true;
    }
private:
    bool helpSolveNQueens(int ind, vector<vector<char>> &board, int n, vector<vector<string>> &result) {

        if(ind == n) {
            vector<string> temp;
            for(auto &row : board) {
                string s = "";
                for(auto &ch : row) s += ch;
                temp.push_back(s);
            }
            result.push_back(temp);
            return true;
        }

        for(int col = 0; col < n; col++) {
            if(canPlace(board, n, ind, col)) {
                board[ind][col] = 'Q';
                bool remainingGrid = helpSolveNQueens(ind + 1, board, n, result);
                board[ind][col] = '.';
            }
        }
        return false;
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<vector<char>> board(n, vector<char>(n, '.'));
        helpSolveNQueens(0, board, n, result);
        return result;
    }  
};

// Optimisation: We Can Perform canPlace check in O(1) instead of O(N)
// using unordered_map
class Solution {
public:
    unordered_map<int, int> queenSameColumn; 
    unordered_map<int, int> queenLeftDiagonal;
    unordered_map<int, int> queenRightDiagonal;
private:
    bool canPlace(int n, int row, int col) {
        // check in the same column 
        if(queenSameColumn[col]) return false;

        // check in the left diagonal
        if(queenLeftDiagonal[n - 1 + col - row]) return false;

        // check in the right diagonal
        if(queenRightDiagonal[col + row]) return false;

        return true;
    }
private:
    bool helpSolveNQueens(int ind, vector<vector<char>> &board, int n, vector<vector<string>> &result) {

        if(ind == n) {
            vector<string> temp;
            for(auto &row : board) {
                string s = "";
                for(auto &ch : row) s += ch;
                temp.push_back(s);
            }
            result.push_back(temp);
            return true;
        }

        for(int col = 0; col < n; col++) {
            if(canPlace(n, ind, col)) {
                board[ind][col] = 'Q';
                queenSameColumn[col] = 1;
                queenRightDiagonal[ind + col] = 1;
                queenLeftDiagonal[n - 1 + col - ind] = 1;
                bool remainingGrid = helpSolveNQueens(ind + 1, board, n, result);
                board[ind][col] = '.';
                queenSameColumn[col] = 0;
                queenRightDiagonal[ind + col] = 0;
                queenLeftDiagonal[n - 1 + col - ind] = 0;
            }
        }
        return false;
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<vector<char>> board(n, vector<char>(n, '.'));
        helpSolveNQueens(0, board, n, result);
        return result;
    }  
};

