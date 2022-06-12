class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        // Approach1:-> TC: O(m + n) SC: O(m + n)
        int i = 0, j = 0;
        vector<int> temp;
        while(i < m && j < n) {
            if(nums1[i] <= nums2[j]) {
                temp.push_back(nums1[i]);
                i++;
            }
            else {
                temp.push_back(nums2[j]);
                j++;
            }
        }
        
        while(i < m) {
            temp.push_back(nums1[i]);
            i++;
        }
        
        while(j < n) {
            temp.push_back(nums2[j]);
            j++;
        }
        
        int idx = 0;
        for(auto &it : temp) {
            nums1[idx++] = it;
        }
        
        // Approach2:-> TC: O(m*n) SC: O(1)
        // Compare elements of nums1 with first element of nums2
        // if the order is not sorted then swap them and insert the nums2[0] at its correct
        // position -> in a insertion sort manner
        // repeat the same process until all elements of nums1 are sorted
        // insert elements of nums2 behind nums1
        if(nums2.size() == 0) return;
        int i = 0;
        while(i < m) {
            if(nums1[i] <= nums2[0]) {
                i++;
            }
            else {
                swap(nums1[i], nums2[0]);
                i++;
                int temp = nums2[0];
                nums2.erase(nums2.begin());
                int k = 0;
                while(k < nums2.size() && temp > nums2[k]) {
                    k++;
                }
                nums2.insert(nums2.begin() + k, temp);
            }
        }
        
        for(auto &it : nums2) nums1[i++] = it;
        
        // Approach3:-> TC: O((N + M)(Log(M + N)) SC: O(1)
        double g = (m + n)/2.00;
        int gap = ceil(g);
        
        while(gap >= 1) {
            
            // comparisons in the first array
            int i, j;
            for(i = 0; i + gap < m; i++) {
                if(nums1[i] > nums1[i + gap]) swap(nums1[i], nums1[i + gap]);
            }
            
            // comparisons in both the arrays
            for(j = (gap > m) ? (gap - m):0; i < m && j < n; i++, j++) {
                if(nums1[i] > nums2[j]) swap(nums1[i], nums2[j]);
            }
            
            // comparisons in the second array
            if(j < n) {
                for(j = 0; j + gap < n; j++) {
                    if(nums2[j] > nums2[j + gap]) swap(nums2[j], nums2[j + gap]);
                }
            }
            if(gap == 1) {
                bool f = true;
                for(int k = 0; k < m - 1; k++) {
                    if(nums1[k] > nums1[k + 1]) {
                        f = false;
                        break;
                    }
                }
                bool s = true;
                for(int k = 0; k < n - 1; k++) {
                    if(nums2[k] > nums2[k + 1]) {
                        s = false;
                        break;
                    }
                }
                if(!f || !s) gap = 1;
                else gap /= 2;
            }
            else gap /= 2;
        }
            
        for(auto &it : nums2) nums1[m++] = it;
        
        
    }
};