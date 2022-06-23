// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

// class Solution{
//     private:
//     bool canMove(int row, int col, vector<vector<int>> &m, int n, vector<vector<bool>> &visited) {
        
//         if(row < 0 || col < 0 || row >= n || col >= n) return false;
//         if(m[row][col] == 0) return false;
//         if(visited[row][col]) return false;
//         return true;
    
//     }
//     private:
//     bool helpFindPath(int row, int col, vector<vector<int>> &m, int n, vector<string> &result, string path, vector<vector<bool>> &visited) {
//         if(row == n - 1 && col == n - 1) {
//             result.push_back(path);
//             return true;
//         }
        
//         // down
//         if(canMove(row + 1, col, m, n, visited)) {
//             // path += 'D';
//             visited[row][col] = true;
//             bool remainingGrid = helpFindPath(row + 1, col, m, n, result, path + 'D', visited);
//             visited[row][col] = false;
//             // path.pop_back();
//         }
        
//         // left
//         if(canMove(row, col - 1, m, n, visited)) {
//             // path += 'L';
//             visited[row][col] = true;
//             bool remainingGrid = helpFindPath(row, col - 1, m, n, result, path + 'L', visited);
//             visited[row][col] = false;
//             // path.pop_back();
//         }
        
//         // right
//         if(canMove(row, col + 1, m, n, visited)) {
//             // path += 'R';
//             visited[row][col] = true;
//             bool remainingGrid = helpFindPath(row, col + 1, m, n, result, path + 'R', visited);
//             visited[row][col] = false;
//             // path.pop_back();
//         }
        
//         // up
//         if(canMove(row - 1, col, m, n, visited)) {
//             // path += 'U';
//             visited[row][col] = true;
//             bool remainingGrid = helpFindPath(row - 1, col, m, n, result, path + 'U', visited);
//             visited[row][col] = false;
//             // path.pop_back();
//         }
        
//         return false;
//     }
//     public:
//     vector<string> findPath(vector<vector<int>> &m, int n) {
//         // Your code goes here
//         vector<string> result;
//         // string path = "";
//         vector<vector<bool>> visited(n, vector<bool>(n, false));
//         bool ans = helpFindPath(0, 0, m, n, result, "", visited);
//         if(m[n - 1][n - 1] == 0 || m[0][0] == 0) return {};
//         return result;
//     }
// };
// Better Readability
// TC: O(4 ^ (m * n))
// SC: Max Aux Stack Space -> O(n * m)
class Solution{
    private:
    bool canMove(int row, int col, vector<vector<int>> &m, int n, vector<vector<bool>> &visited) {
        
        if(row < 0 || col < 0 || row >= n || col >= n) return false;
        if(m[row][col] == 0) return false;
        if(visited[row][col]) return false;
        return true;
    
    }
    private:
    bool helpFindPath(int row, int col, vector<vector<int>> &m, int n, vector<string> &result, string path, vector<vector<bool>> &visited, vector<int> &nextRow, vector<int> &nextCol) {
        if(row == n - 1 && col == n - 1) {
            result.push_back(path);
            return true;
        }
        
        string direction = "DLRU";
        for(int ind = 0; ind < 4; ind++) {
            int nexti = row + nextRow[ind];
            int nextj = col + nextCol[ind];
            if(canMove(nexti, nextj, m, n, visited)) {
                visited[nexti][nextj] = true;
                bool remainingGrid = helpFindPath(nexti, nextj, m, n, result, path + direction[ind], visited);
                visited[nexti][nextj] = false;
            }
        }

        return false;
    }
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<int> nextRow(n), nextCol(n);
        nextRow = {1, 0, 0, -1};  // DLRU
        nextCol = {0, -1, 1, 0};  // DLRU
        vector<string> result;
        // string path = "";
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        bool ans = helpFindPath(0, 0, m, n, result, "", visited, nextRow, nextCol);
        if(m[n - 1][n - 1] == 0 || m[0][0] == 0) return {};
        return result;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends