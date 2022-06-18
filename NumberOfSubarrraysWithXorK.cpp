int Solution::solve(vector<int> &A, int B) {
    
    // brute : 3 loops -> 2 for gen subarrays + 1 for calc xor of elements
    // better : 2 loops for gen subarrays + prefixXOR for calc xor of elements in O(1)
    // optimal : TC: O(N) if using unordered_map in avg case (in worst case it might become O(N*N))
    // if using map, TC: O(NLogN) 
    // SC: O(N) in both case
    int count = 0;
    int prefixXOR = 0;
    int n = A.size();
    unordered_map<int, int> freq;
    for(int i = 0; i < n; i++) {
        prefixXOR ^= A[i];
        if(prefixXOR == B) {
            count++;
        }
        int Y = prefixXOR ^ B;
        if(freq.find(Y) != freq.end()) {
            count += freq[Y];
        }
        freq[prefixXOR]++;
    }
    return count;
}
