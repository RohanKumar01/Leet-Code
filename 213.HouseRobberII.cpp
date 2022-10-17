class Solution {
public:
int rob(vector<int>& nums) {
    if (nums.size() == 0) return 0;
    if (nums.size() == 1) return nums[0];
    
    return max(rob(nums, 0, nums.size()-1), rob(nums, 1, 0));
}

int rob(vector<int>& nums, int startIndex, int endIndex) {
    int p = 0, q = 0;
    for (int i = startIndex; i != endIndex; /* do nothing */) {
        int tmp = p;
        p = max(p, q + nums[i]);
        q = tmp;
        i = (i + 1) % nums.size();
    }
    return p;
}
};