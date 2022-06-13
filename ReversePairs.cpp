// TC: O(NLogN + N(for merge) + N(for count)) SC: O(N)
class Solution {
private:
    int crossReversePairs(vector<int>& nums, int s, int e) {
        int mid = s + (e - s)/2;
        int count = 0;

        int high = mid + 1;
        for(int low = s; low <= mid; low++) {
            while(high <= e and nums[low] > 2 * (long)(nums[high])) high++;
    
            count += high - (mid + 1);
        }
        
        int i = s;
        int j = mid + 1;
        vector<int> temp(e - s + 1);
        int k = 0;
        while(i <= mid && j <= e) {
            if(nums[i] <= nums[j]) {
                temp[k++] = nums[i];
                i++;
            }
            else {
                temp[k++] = nums[j];
                j++;
            }
        }
        
        while(i <= mid) {
            temp[k++] = nums[i];
            i++;
        }
        
        while(j <= e) {
            temp[k++] = nums[j];
            j++;
        }
        
        for(int idx = 0; idx < e - s + 1; idx++) {
            nums[s + idx] = temp[idx];
        }
        // cout << count << endl;
        return count;
    }
private:
    int selfReversePairs(vector<int>& nums, int s, int e) {
        if(s >= e) return 0;
        
        int mid = s + (e - s)/2;
        int result = 0;
        result += selfReversePairs(nums, s, mid);
        result += selfReversePairs(nums, mid + 1, e);
        result += crossReversePairs(nums, s, e);
        return result;
    }
public:
    int reversePairs(vector<int>& nums) {
        return selfReversePairs(nums, 0, nums.size() - 1);
    }
};