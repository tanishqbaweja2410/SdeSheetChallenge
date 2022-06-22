// Solution 1 : Using extra space : one map and one ds
// TC: O(N! * N)
// SC: O(N) {freq} + O(N) {ds} + Aux Stack Space
class Solution {
private:
    void helpPrintPermutations(vector<int>& nums, vector<int> &ds, unordered_map<int, int> &freq, vector<vector<int>> &result) {
        if(ds.size() == nums.size()) {
            result.push_back(ds);
            return;
        }

        for(int ind = 0; ind < nums.size(); ind++) {
            if(freq[nums[ind]] == 0) {
                freq[nums[ind]]++;
                ds.push_back(nums[ind]);
                helpPrintPermutations(nums, ds, freq, result);
                freq[nums[ind]]--;
                ds.pop_back();
            }
        }
    } 
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> ds;
        unordered_map<int, int> freq;
        helpPrintPermutations(nums, ds, freq, result);
        return result;
    }
};

// Solution2 : Without using extra space -> Using Swapping
// TC: O(N! * N)
// SC: O(1) + Aux Stack Space
class Solution {
private:
    void helpPrintPermutations(int ind, vector<int>& nums, vector<vector<int>> &result) {
        if(ind == nums.size() - 1) {
            result.push_back(nums);
            return;
        }

        for(int i = ind; i < nums.size(); i++) {
            swap(nums[ind], nums[i]);
            helpPrintPermutations(ind + 1, nums, result);
            swap(nums[ind], nums[i]);
        }
    } 
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        helpPrintPermutations(0, nums, result);
        return result;
    }
};