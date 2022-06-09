class Solution {
public:
    // TC: O(1 + 2 + 3 + 4 .... = N*N) SC: O(N*N)
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pascalsTriangle;
        for(int ind = 1; ind <= numRows; ind++) {
            vector<int> temp(ind, 1);
            pascalsTriangle.push_back(temp);
        }
        
        for(int ind = 3; ind <= numRows; ind++) {
            for(int i = 1; i < ind - 1; i++) {
                pascalsTriangle[ind - 1][i] = pascalsTriangle[ind - 2][i] + pascalsTriangle[ind - 2][i - 1];
            }
        }
        return pascalsTriangle;
    }
};