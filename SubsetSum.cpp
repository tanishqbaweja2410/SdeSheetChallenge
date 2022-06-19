// brute : using power set algo -> TC: O(2^N * N)
// recursive: TC: o(2^N + 2^NLog(2^N))  SC: O(2^N)
void f(int ind, vector<int> &num, vector<int> &result, int sum) {
        if(ind < 0) {
            result.push_back(sum);
            return;
        }
    
        // notTake
        f(ind - 1, num, result, sum);
        // take
        f(ind - 1, num, result, sum + num[ind]);
}
vector<int> subsetSum(vector<int> &num)
{
    // Write your code here.
    int n = num.size();
    vector<int> result;
    f(n - 1, num, result, 0);
    sort(result.begin(), result.end());
    return result;
    
}