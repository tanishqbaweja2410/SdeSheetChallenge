class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        // at max there can be 2 majority elements i.e. with freq > [n/3]
        
        // Brute: Using Two Loops TC: O(N*N) SC: O(1)
        // Better: Using freq array or Map or Unordered Map
        // Unordered Map -> O(N*N) in worst case (though it occurs rarely)
        // b/c worst case TC in unordered Map is O(N)
        // Optimal Solution
        // Moore's Algo -> O(N + N) TC & O(1) SC
        int num1 = -1;
        int num2 = -1;
        int count1 = 0;
        int count2 = 0;
        vector<int> result;
        int n = nums.size();
        
        for(auto &num : nums) {
            if(num == num1) {
                count1++;
            }
            else if(num == num2) {
                count2++;
            }
            else if(count1 == 0) {
                num1 = num;
                count1++;
            }
            else if(count2 == 0) {
                num2 = num;
                count2++;
            }
            else {
                count1--;
                count2--;
            }
        }
        
        count1 = count2 = 0;
        for(auto &num : nums) {
            if(num == num1) {
                count1++;
            }
            else if(num == num2) {
                count2++;
            }
        }
        if(count1 > n/3) result.push_back(num1);
        if(count2 > n/3) result.push_back(num2);
        return result;
        
    }
};