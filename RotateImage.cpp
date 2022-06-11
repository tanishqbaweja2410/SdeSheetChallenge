class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // Take Transpose and then Reverse Each Row
        // TC: O(N*N) + O(N*N) SC: O(1)
        int n = matrix.size();
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for(auto &temp : matrix) {
            reverse(temp.begin(), temp.end());
        }
    }
};