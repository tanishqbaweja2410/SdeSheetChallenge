class Solution {
// private:
//     void subsetsWithDupHelper(int ind, vector<int>& nums, set<vector<int>> &helpSet, vector<int> &temp) {
//         if(ind < 0) {
//             vector<int> temp2(temp.begin(), temp.end());
//             sort(temp2.begin(), temp2.end());
//             // for(auto &it : temp) cout << it << " ";
//             // cout << endl;
//             if(helpSet.find(temp2) != helpSet.end()) return;
//             helpSet.insert(temp2);
//             // for(auto &it : temp) cout << it << " ";
//             // cout << "UPDATED" << endl;
//             return;
//         }
        
//         // notTake
//         subsetsWithDupHelper(ind - 1, nums, helpSet, temp);
//         // take
//         temp.push_back(nums[ind]);
//         subsetsWithDupHelper(ind - 1, nums, helpSet, temp);
//         temp.pop_back();
//     }
private:
    void uniqueSubsetsHelper(int ind, vector<int>& nums, vector<int>& ds, vector<vector<int>> &result) {
        result.push_back(ds);
        for(int i = ind; i < nums.size(); i++) {
            if(i != ind && nums[i] == nums[i - 1]) continue;
            ds.push_back(nums[i]);
            uniqueSubsetsHelper(i + 1, nums, ds, result);
            ds.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        // Using Set : O(mlogm) where m = 2^N -> this much extra time is required to transfer the subset to set
        // vector<vector<int>> result;
        // set<vector<int>> helpSet;
        // vector<int> temp;
        // int n = nums.size();
        // subsetsWithDupHelper(n - 1, nums, helpSet, temp);
        // for(auto subset : helpSet) {
        //     result.push_back(subset);
        // }
        // return result;
        
        // Without Using Set -> Making changes in the recursion itself
        // TC: O(2^N * N) {2^N subsets and considering N as the avg length of each subset => N time is for putting each subset into the ans/result}
        // SC: O(2^N){number of subsets} * O(K){K is the avg length of each subset} + O(N){Aux Stack Space}
        vector<vector<int>> result;
        vector<int> ds;
        sort(nums.begin(), nums.end());
        uniqueSubsetsHelper(0, nums, ds, result);
        return result;
        
    }
};