class Solution {
    public int firstMissingPositive(int[] nums) {
        int n = nums.length;
        
        for(int i=0; i<n; i++){
            if(nums[i]<=0 || nums[i]>n)
                nums[i] = n+1;}
        
        for(int i=0; i<n; i++){
            int id = Math.abs(nums[i])-1;
            if(id>=n) continue;
            if(nums[id]>0) nums[id] = -nums[id];}
        
        for(int i=0; i<n; i++){
            if(nums[i]>0) return i+1;}
        
    return n+1;}
}
