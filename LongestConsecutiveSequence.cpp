class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // int n = nums.size();
        // Brute : TC: O(NLogN + N) SC; O(1) or O(N) if using Merge Sort
        // sort(nums.begin(), nums.end());
        // int maxConsecutiveLength = 1;
        // int currentLength = 1;
        // for(int i = 1; i < n; i++) {
        //     if(nums[i] == nums[i - 1] + 1) {
        //         currentLength++;
        //         maxConsecutiveLength = max(maxConsecutiveLength, currentLength);
        //     }
        //     else {
        //         currentLength = 1;
        //         maxConsecutiveLength = max(maxConsecutiveLength, currentLength);
        //     }
        // }
        // return maxConsecutiveLength;
        
        // Optimal : 
        // TC: O(N + N + N) SC: O(N)
        if(nums.size() == 0) return 0;
        unordered_set<int> helpSet;
        for(auto &num : nums) helpSet.insert(num);
        int maxConsecutiveLength = 1;
        int currentLength = 1;
        for(auto &num : nums) {
            int element = num;
            if(helpSet.find(element - 1) == helpSet.end()) {
                currentLength = 1;
                while(helpSet.find(element + 1) != helpSet.end()) {
                    currentLength++;
                    element++;
                }
                maxConsecutiveLength = max(maxConsecutiveLength, currentLength);
            }
        }
        return maxConsecutiveLength;
    }
};