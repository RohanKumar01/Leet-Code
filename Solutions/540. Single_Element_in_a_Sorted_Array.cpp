// Single Element in a Sorted Array
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = size(nums), L = 0, R = n-1, mid, ans;
        while(L <= R) {
            mid = (L + R) >> 1;
            if(mid & 1) mid--;                              // make mid even to check for required condition
            if(mid+1 < n && nums[mid] == nums[mid+1])       // condition satisfied upto mid+1:
                L = mid+2;                                  // so search in [mid+2, R] to find point where condition starts to fail
            else                                            // condition not satisfied:
                R = mid-1, ans = nums[mid];                 // nums[mid] is potential answer. search [L, mid-1] to see if condition started to fail somewhere before
        }
        return ans;
    }
};
