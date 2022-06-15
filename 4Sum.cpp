class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        // very naive : four loops TC: O(N^4) SC: O(N){hashset}
        // little better : use binary searcj instead of fourth loop TC: O(N^3 * LogN) SC: O(N){hashset}
        // Most Optimal Solution without using Hashset TC: O(N^3) SC: O(1)
        // the requirement of hashset has been removed by adding checks of skipping duplicate elements after every iteration
        vector<vector<int>> ans;
        if(nums.empty()) return ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                long long target2 = target - nums[i] - nums[j];
                int start = j + 1; int end = n - 1;
                while(start < end) {
                    long long sum = nums[start] + nums[end];
                    if(sum < target2) start++;
                    else if(sum > target2) end--;
                    else {
                        vector<int> quadruple(4);
                        quadruple[0] = nums[i];
                        quadruple[1] = nums[j];
                        quadruple[2] = nums[start];
                        quadruple[3] = nums[end];
                        ans.push_back(quadruple);
                        // Processing the duplicates of number 3 
                        while(start < end and nums[start] == quadruple[2]) start++;
                        // Processing the duplicates of number 4
                        while(start < end and nums[end] == quadruple[3]) end--;
                    }
                }
                // Processing the duplicates of number 2
                while(j + 1 < n  and nums[j + 1] == nums[j]) j++;
            }
            // Processing the duplicates of jth element number 1
            while(i + 1 < n and nums[i + 1] == nums[i]) i++;
        }
        return ans;
  
        // Optimal Solution using Hashset TC: O(N^3) SC: O(N)
//         vector<vector<int>> ans;
//         set<vector<int>> set;
//         int n = nums.size();
//         sort(nums.begin(), nums.end());
//         for(int i = 0; i <= n - 4; i++) {
//             for(int j = i + 1; j <= n - 3; j++) {
//                 long long currentSum = nums[i] + nums[j];
//                 int s = j + 1; int e = n - 1;
//                 while(s < e) {
//                     long long sum = currentSum + nums[s] + nums[e];
//                     if(sum == target) {
//                         set.insert({nums[i], nums[j], nums[s], nums[e]});
//                         s++;
//                         e--;
//                     }
//                     else if(currentSum + nums[s] + nums[e] > target) {
//                         e--;
//                     }
//                     else {
//                         s++;
//                     }
//                 }
                
//             }
//         }
//         for(auto &x : set) ans.push_back(x);
//         return ans;
    }
};