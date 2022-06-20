class Solution {
private:
    void combinationSumHelper(int ind, vector<int> &candidates, int target, vector<int> &ds, vector<vector<int>> &result) {
        if(ind == candidates.size()) {
            if(target == 0) {
                result.push_back(ds);
            }
            return;
        }
        // pick the element at index ind
        if(candidates[ind] <= target) {
            ds.push_back(candidates[ind]);
            combinationSumHelper(ind, candidates, target - candidates[ind], ds, result);
            ds.pop_back();
        }
        // not pick the element at index ind
        combinationSumHelper(ind + 1, candidates, target, ds, result);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        // TC: O(2 ^ t * K) where K is the avg length of each combination
        // this is so because copying one ds of length k into another ds is a linear operation
        // and 2^t because if element at 0th index is 1 and target is 10 then there will be 10 pick calls at 0th index and rest n - 1 not pick calls => overall 2 ^ (t + n) or simply on an average we can call it as O(2 ^ t)
        // SC: K * x {K: avg length of each combination, x: no of combinations (can't be predicted)}
        vector<vector<int>> result;
        vector<int> ds;
        combinationSumHelper(0, candidates, target, ds, result);
        return result;
    }
};