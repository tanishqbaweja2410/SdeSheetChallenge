// leetcode solution
class Solution {
private:
    double myPowHelper(double x, long long num) {
        // base case
        if(num == 1) {
            return x;
        }
        if(num == 0) {
            return 1.00;
        }
        
        // recursive case
        double subProblem = myPowHelper(x, num/2);
        double subProblemSquare = subProblem * subProblem;
        if(num & 1) {
            return x * subProblemSquare;  // odd
        }
        else {
            return subProblemSquare;  // even
        }
    }
public:
    double myPow(double x, int n) {
        
        long long num = n;
        double result;
        if(num > 0) {
            result = myPowHelper(x, num);
        }
        else{
            result = myPowHelper(x, -1 * num);
            result = 1.00 / result;
        }
        return result;
        
    }
};

// codestudio solution
#include <bits/stdc++.h> 
long long modularExponentiationHelper(int x, int n, int m) {
    long long result;
    if(n == 1) {
        result = x % m; 
        return result;
    }

    // recursive case
    long long subProblem = modularExponentiationHelper(x, n/2, m);
    long long subProblemSquare = (subProblem % m * subProblem % m) % m;

    if(n & 1) {
        result = (x%m * subProblemSquare%m) % m;  // odd
    }
    else {
        result = subProblemSquare % m;  // even
    }
    return result;
}
int modularExponentiation(int x, int n, int m) {
    
    long long output = modularExponentiationHelper(x, n, m);
    return (int)(output);
}

