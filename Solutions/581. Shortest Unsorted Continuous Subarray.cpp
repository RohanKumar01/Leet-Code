class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> arr=nums;
        sort(arr.begin(),arr.end());
        int cnt1=-1;
        int cnt2=-1;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]!=arr[i]){
                cnt1=i;
                break;
            }
        }
        for(int i=n-1;i>=0;i--){
            if(nums[i]!=arr[i]){
                cnt2=n-i-1;
                break;
            }
        }
        if(cnt1==-1||cnt2==-1){
            return 0;
        }
        return n-cnt1-cnt2;
        
    }
};