class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        // Dynamic Programming Approach b/c we require the prev state to find the curr state
        // TC: O(N)
        // SC: O(1)
        int n = prices.size();
        int profit = 0;
        int mini = prices[0];
        
        // maximizing profit & minimising mini in every iteration
        for(int i = 1; i < n; i++) {
            int cost = prices[i] - mini;
            profit = max(profit, cost);  
            mini = min(mini, prices[i]);
        }
        return profit;
        
    }
};