class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int n = nums.size();
        int maxSum = INT_MIN;
        int currentSum = 0;
        
        for(int ind = 0; ind < n; ind++){
            currentSum += nums[ind];
            maxSum = max(maxSum, currentSum);
            if(currentSum < 0) {
                currentSum = 0;
            }
        }
        return maxSum;
    }
};