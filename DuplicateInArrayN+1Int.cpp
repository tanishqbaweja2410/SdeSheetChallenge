class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // Following Two Solutions : TC: O(NLogN) SC: O(N)
        // unordered_set<int> s;
        // for(int &it : nums){
        //     if(s.find(it) != s.end()) return it;
        //     else s.insert(it);
        // }
        // return -1;
        
        // unordered_map<int,int> m;
        // for(auto &it : nums) {
        //     if(m[it] > 0) return it;
        //     else m[it]++;
        // }
        // return -1;
         
        // Solution Without Using Any Auxilliary Space -> TC: O(NLogN) SC: O(1)
        // sort(nums.begin(), nums.end());
        // for(int i = 0; i < nums.size() - 1; i++) {
        //     if(nums[i] == nums[i + 1]) return nums[i];
        // }
        // return -1;
        // But this solution distorts the array
        
        // Most Optimal Solution Uses The Linked list Cycle Detection Approach
        // TC: O(N) SC: O(1)
        int fast = nums[0];
        int slow = nums[0];
        do{
            fast = nums[nums[fast]];
            slow = nums[slow];
        }
        while(fast != slow);
        // this is the point of collision
        // we need to find the start pos of loop
        // take one pointer back to start
        // move both one by one
        fast = nums[0];
        while(fast != slow) {
            fast = nums[fast];
            slow = nums[slow];
        }
        return slow;
        
    }
};