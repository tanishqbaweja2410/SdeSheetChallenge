class Solution {
private:
    bool isPalindrome(string s) {
        int n = s.length();
        for(int i = 0; i < n/2; i++) {
            if(s[i] != s[n - i - 1]) return false;
        }
        return true;
    }
private:
    void f(int ind, string &s, vector<vector<string>> &ans, vector<string> &ds) {
        if(ind == s.size()) {
            ans.push_back(ds);
            return;
        }
        
        for(int i = ind; i < s.length(); i++) {
            string s1 = s.substr(ind, i - ind + 1);
            if(isPalindrome(s1)) {
                ds.push_back(s1);
                f(i + 1, s, ans, ds);
                ds.pop_back();
            }
        }
    }
public:
    // TC: O(2^N * K * (N/2)) => 2^N for generating all substrings, N/2 for checking palindrome or not and K for inserting the string in ds where K is the avg length of the string
    // SC: O(K * x) where K is the avg length of the palindromic substring and x : the number of palindromic substrings
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> ds;
        f(0, s, ans, ds);
        return ans;
    }
};