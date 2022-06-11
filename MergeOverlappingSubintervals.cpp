class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        sort(intervals.begin(), intervals.end());
        
        int a = intervals[0][0];
        int b = intervals[0][1];
        for(int i = 1; i < intervals.size(); i++) {
            if(intervals[i][0] <= b) {
                b = max(intervals[i][1], b);
            }
            else {
                result.push_back({a,b});
                a = intervals[i][0];
                b = intervals[i][1];
            }
        }
        result.push_back({a,b});
        return result;
    }
};