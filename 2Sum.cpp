// leetcode solution
// TC: O(N) SC: O(N)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        vector<int> ans;
        unordered_map<int,int> m;
        int n = nums.size();
        
        for(int i = 0; i < n; i++) {
            int required = target - nums[i];
            if(m.find(required) != m.end()) {
                ans.push_back(i);
                ans.push_back(m[required]);
                return ans;
            }
            m[nums[i]] = i;
        }
        return ans;
        
    }
};

// codestudio solution
// TC: O(NLogN) SC: O(N)
#include <bits/stdc++.h> 
vector<vector<int>> pairSum(vector<int> &nums, int target){
   // Write your code here.
    vector<vector<int>> ans;
    multiset<int> helpSet;
    int n = nums.size();

    for(int i = 0; i < n; i++) {
        int current = nums[i];
        int required = target - current;
        if(helpSet.find(required) != helpSet.end()) {
            int count = helpSet.count(required);
            while(count--) {
                ans.push_back({min(current, required), max(current, required)});
            }
        }
        helpSet.insert(current);
    }
    sort(ans.begin(), ans.end());
    return ans;
}