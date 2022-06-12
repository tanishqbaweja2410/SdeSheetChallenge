// TC: O(N) SC: O(1)
#include<bits/stdc++.h>
vector<int> Solution::repeatedNumber(const vector<int> &A) {
    long long sum = 0, sumSquare = 0, sumA = 0, sumSquareA = 0;
    for(int i = 1; i <= A.size(); i++) {
        sum += (long long)(i);
        sumSquare += (long long)(i) * (long long)(i);
        sumA += (long long)(A[i - 1]);
        sumSquareA += (long long)(A[i - 1]) * (long long)(A[i - 1]);
    }
    
    long long x_y = sum - sumA;
    long long x2_y2 = sumSquare - sumSquareA;
    long long xplusy = x2_y2 / x_y;
    long long x = (x_y + xplusy)/2;
    long long y = (xplusy - x_y)/2;
    return {(int)(y), (int)(x)};
}
