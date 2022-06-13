#include <bits/stdc++.h>
using namespace std;

long long crossInversions(long long *arr, int s, int e) {
    int mid = s + (e - s)/2;
    int i = s, j = mid + 1, k = 0;
    long long count = 0;
    long long temp[e - s + 1];
    
    while(i <= mid && j <= e) {
        if(arr[i] <= arr[j]) {
            temp[k++] = arr[i];
            i++; 
        }
        else {
            count += (mid + 1 - i);
            temp[k++] = arr[j];
            j++; 
        }
    }
    
    while(i <= mid) {
        temp[k++] = arr[i];
        i++; 
    }
    
    while(j <= e) {
        temp[k++] = arr[j];
        j++; 
    }
    
    for(int idx = 0; idx < e - s + 1; idx++) {
        arr[s + idx] = temp[idx];
    }
    return count;
}
long long selfInversions(long long *arr, int s, int e) {
    long long result = 0;
    if(s >= e) return result;
    
    int mid = s + (e - s)/2;
    result += selfInversions(arr, s, mid);
    result += selfInversions(arr, mid + 1, e);
    result += crossInversions(arr, s, e);
    return result;
}
long long getInversions(long long *arr, int n){
    return selfInversions(arr, 0, n - 1);
    
}