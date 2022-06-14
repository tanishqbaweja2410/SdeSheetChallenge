// leetcode solution
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int count = 0;
        int element = 0;
        
        for(auto &num : nums) {
            
            if(count == 0) {
                element = num;
            }
            if(element == num) {
                count++;
            }
            else {
                count--;
            }
        }
        return element;
    }
};

// codestudio solution
#include <bits/stdc++.h> 
int findMajorityElement(int arr[], int n) {
    int count = 0;
    int element = 0;

    for(int i = 0; i < n; i++) {
        if(count == 0) {
            element = arr[i];
        }
        if(element == arr[i]) {
            count++;
        }
        else {
            count--;
        }
    }
    
    count = 0;
    for(int i = 0; i < n; i++) {
        if(element == arr[i]) count++;
    }
    if(count > n/2) return element;
    return -1;
}
