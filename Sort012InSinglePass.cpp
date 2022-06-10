class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        // Solution 1 : Using Counting Sort // Two Pass Algorithm // TC : O(2*N) & SC: O(1) 
//         vector<int> temp(3, 0);
//         for(auto &it : nums) {
//             temp[it]++;
//         }
        
//         int ind = 0;
//         for(int i = 0; i < 3; i++) {
//             int frequency = temp[i];
//             while(frequency--) {
//                 nums[ind++] = i;
//             }
//         }
//         return;
        
        // Solution 2: Single Pass Algorithm | Dutch National Flag Algorithm | O(N) TC & O(1) SC
        int n = nums.size();
        int low = 0, mid = 0, high = n - 1;
        
        while(mid <= high) {
            if(nums[mid] == 0) {
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            }
            else if(nums[mid] == 1) {
                mid++;
            }
            else {
                swap(nums[mid], nums[high]);
                high--;
            }
        }
        return;
    }
};