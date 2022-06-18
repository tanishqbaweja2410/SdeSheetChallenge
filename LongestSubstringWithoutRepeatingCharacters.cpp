class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        // brute: generate all substrings TC: O(N^3){extreme naive way} || O(N^2){little optimisations} SC: O(N) for using hashset for checking repetition of characters
        // optimised: TC; O(N + N) SC: O(N) sliding window + hashset
        // use of left and right pointers
        // but whenever the character at right pointer is already in the set, then we need to linearly traverse the left pointer along with deleting those character at left pointer from the set => this causes an additional O(N) TC => Therefore TC; O(2N)
        // so inorder to avoid this situation we can probably store the key val{char, index} pairs in a map instead of storing only characters in the set => using map we can move the left pointer in just O(1) time
        // therefore, TC: O(N) SC: O(N)
            
//         vector<int> map(256, -1);
//         int n = s.length();
//         int left = 0, right = 0;
//         int maxLength = 0;
        
//         while(right < n) {
//             if(map[s[right]] != -1) {
//                 left = max(map[s[right]] + 1, left);
//             }
            
//             map[s[right]] = right;
//             maxLength = max(maxLength, right - left + 1);
//             right++;
//         }
//         return maxLength;
        
        // 18/06/22
        unordered_map<char,int> m;
        int n = s.length();
        int left = 0, right = 0;
        int maxLength = 0;
        while(right < n) {
            if(m.find(s[right]) != m.end()) {
                left = max(m[s[right]] + 1, left);   
            }
            m[s[right]] = right;
            maxLength = max(maxLength, right - left + 1);
            right++;
        }
        return maxLength;
    }
};