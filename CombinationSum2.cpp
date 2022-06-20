class Solution {
// Using Set TC: O(2 ^ n * k * log())
// private:
//     void combinationSumHelper(int ind, vector<int> &candidates, int target, vector<int> &ds, set<vector<int>> &result) {
//         if(ind == candidates.size()) {
//             if(target == 0) {
//                 result.insert(ds);
//             }
//             return;
//         }
//         // pick the element at index ind
//         if(candidates[ind] <= target) {
//             ds.push_back(candidates[ind]);
//             combinationSumHelper(ind + 1, candidates, target - candidates[ind], ds, result);
//             ds.pop_back();
//         }
//         // not pick the element at index ind
//         combinationSumHelper(ind + 1, candidates, target, ds, result);
//     }
// public:
//     vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
//         set<vector<int>> result;
//         vector<int> ds;
//         sort(candidates.begin(), candidates.end());
//         combinationSumHelper(0, candidates, target, ds, result);
//         vector<vector<int>> ans(result.begin(), result.end());
//         return ans;
//     }
// Without Using Set
// TC: O(2^n * K){K is the avg length of each combination}
// SC: k * x {k: avg length, x: no of combinations}
private:
    void combinationSumHelper(int ind, vector<int> &candidates, int target, vector<int> &ds, vector<vector<int>> &result) {
        if(target == 0) {
            result.push_back(ds);
            return;
        }
            
        for(int i = ind; i < candidates.size(); i++) {
            if(i != ind && candidates[i] == candidates[i - 1]) continue;
            // pick the element at index i
            if(candidates[i] <= target) {
                ds.push_back(candidates[i]);
                combinationSumHelper(i + 1, candidates, target - candidates[i], ds, result);
                ds.pop_back();
            }
            else break;
        }
        
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> ds;
        sort(candidates.begin(), candidates.end());
        combinationSumHelper(0, candidates, target, ds, result);
        return result;
    }
};