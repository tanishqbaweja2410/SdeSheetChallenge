class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        // very naive: two loops + one more loop to check the sum
        // better : two loops + prefixSum array to check the sum
        // optimal : use hashing
        unordered_map<int,int> m;
        int currentSum = 0;
        int maxLen = 0;
        for(int i = 0; i < n; i++) {
            currentSum += A[i];
            if(currentSum == 0) {
                maxLen = max(maxLen, i + 1);
            }
            else {
                if(m.count(currentSum)) {
                    maxLen = max(maxLen, i - m[currentSum]);
                }
                else{
                    m[currentSum] = i;    
                }
            }
        }
        return maxLen;
    }
};