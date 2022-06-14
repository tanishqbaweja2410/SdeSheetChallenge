class Solution {
// private:
//     int countPaths(int i, int j, int m, int n, vector<vector<int>> &dp) {
//         if(i >= m || j >= n) return 0;
//         if(i == m - 1 && j == n - 1) return 1;
//         if(dp[i][j] != -1) return dp[i][j];
//         return dp[i][j] = countPaths(i, j + 1, m, n, dp) + countPaths(i + 1, j, m, n, dp);
//     }
public:
    int uniquePaths(int m, int n) {
        
        // Memoization
        // vector<vector<int>> dp(m, vector<int>(n, -1));
        // return countPaths(0, 0, m, n, dp);
        
        // Tabulation
        // vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        // dp[m - 1][n - 1] = 1;
        // for(int i = m - 1; i >= 0; i--) {
        //     for(int j = n - 1; j >= 0; j--) {
        //         if(i == m - 1 && j == n - 1) continue;
        //         dp[i][j] = dp[i][j + 1] + dp[i + 1][j];
        //     }
        // }
        // return dp[0][0];
        
        // Optimal Solution is Using Combinatorics
        // starting from 0,0 we need n - 1 right and m - 1 down
        int down = m - 1;
        int right = n - 1;
        int total = right + down;
        
        // answer is no of ways of choosing down from total OR no of ways of choosing right from total
        // using nCr formula
        // without using factorial
        // nCr = n(n - 1)(n - r + 1) / r(r - 1)(r - 2)
        
        double count = 1.00;
        for(int i = 1; i <= down; i++) {
            count = count * (total - down + i) / i;
        }
        return (int)(count);
    }
};