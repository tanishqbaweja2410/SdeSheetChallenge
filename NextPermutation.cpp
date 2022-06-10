class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // Method 1
        // next_permutation(nums.begin(), nums.end());
        // return;
        
        // Method 2
        // First, find we need to understand the way in which words occur in a dictionary : -
        // From right end, the numbers follow a incresing sequence
        // it can be a min of 1 number or can range up to n
        // // So, at first we will find the breakpoint where this inc sequence ends
        // then, starting from right end we need to find the element which is greater than the one selected before
        // swap them, so that we could get the next set of permutations
        // now since we need the next permutation
        // we will reverse the elements lying to right of first ind so that this lies low in the dictionary order
        // the obtained permutation is the next permutation of the given nums
        int n = nums.size();
        int i;
        for(i = n - 2; i >= 0; i--) {
            if(nums[i] < nums[i + 1]) {
                break;
            }
        }
        int breakpoint = i;
        if(breakpoint >= 0) {
            int justGreater;
            for(int i = n - 1; i >= 0; i--) {
                if(nums[breakpoint] < nums[i]) {
                    justGreater = i;
                    break;
                }
            }
            swap(nums[breakpoint], nums[justGreater]);
        }
        reverse(nums.begin() + breakpoint + 1, nums.end());
        return;     
    }
};