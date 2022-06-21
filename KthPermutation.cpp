// TC : O(N) * O(N) = O(N^2) -> N for choosing N digits & N for erasing elements from the ds.
// SC : O(N) for storing N numbers in a ds
// Recursive Solution
class Solution {
private:
    int fact(int n) {
        if(n <= 1) return 1;
        return n * fact(n - 1);
    }
private:
    void f(int n, int k, string &s, string &ans) {
        if(k == 1) {
            for(char &ch : s) {
                ans += ch;
            }
            return;
        }
        if(n == 1) {
            ans += s;
            return;
        }
        if(k == fact(n)) {
            reverse(s.begin(), s.end());
            ans += s;
            return;
        }
        
        int factn = fact(n - 1);
        int start = (k - 1)/(factn);
        ans += s[start];
        // cout << ans << " " << n << " " << k << " " << endl;
        s.erase(s.begin() + start);
        n--;
        k =  (k % factn == 0) ? factn : k % factn;
        f(n, k, s, ans);
    }
    
public:
    string getPermutation(int n, int k) {
        string s = "";
        for(int i = 1; i <= n; i++) {
            s += i + '0';
        }
        // cout << s << endl;
        string ans = "";
        f(n, k, s, ans);
        // cout << " main " << ans << endl;
        return ans;
    }
};

// TC : O(N) * O(N) = O(N^2) -> N for choosing N digits & N for erasing elements from the ds.
// SC : O(N) for storing N numbers in a ds
// Iterative Solution
class Solution {
public:
    string getPermutation(int n, int k) {
        string ans = "";
        int fact = 1;
        vector<int> numbers;
        for(int i = 1; i < n; i++) {
            fact *= i;
            numbers.push_back(i);
        }
        numbers.push_back(n);
        k = k - 1;
        while(true) {
            ans += (numbers[k / fact] + '0');
            numbers.erase(numbers.begin() + k / fact);
            if(numbers.size() == 0) {
                break;
            }
            k = k % fact;
            fact /= numbers.size();
        }
        return ans;
    }
};
