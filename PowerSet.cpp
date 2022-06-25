// TC: O(2^n * n)
// SC: O(1)

// CodeStudio 
vector<vector<int>> pwset(vector<int>v)
{
    vector<vector<int>> powerSet;
    int n = v.size();
    for(int num = 0; num <= (1 << n) - 1; num++) {
        vector<int> temp;
        for(int i = 0; i < n; i++) {
            if(num & (1 << i)) {
                temp.push_back(v[i]);
            }
        }
        powerSet.push_back(temp);
    }
    return powerSet;
}

// GFG
class Solution{
    public:
        vector<string> AllPossibleStrings(string s){
            // Code here
            int n = s.length();
            vector<string> powerSet;
            for(int num = 0; num <= (1 << n) - 1; num++) {
                string substring = "";
                for(int i = 0; i < n; i++) {
                    if(num & (1<<i)) {
                        substring.push_back(s[i]);
                    }
                }
                if(substring != "") powerSet.push_back(substring);
            }
            sort(powerSet.begin(), powerSet.end());
            return powerSet;
        }
};

