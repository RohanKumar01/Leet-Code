// Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:
// 0 <= a, b, c, d < n
// a, b, c, and d are distinct.
// nums[a] + nums[b] + nums[c] + nums[d] == target
// You may return the answer in any order. 

vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        vector<int> v(4);
        sort(nums.begin(), nums.end());
        for(int i = 0; i<nums.size(); i++) {
            for(int j = i+1; j<nums.size(); j++) {
                int l = j + 1;
                int h = nums.size() - 1;
                long long sum = target - (long)nums[i] - (long)nums[j];
                while(l < h) {
                    if(nums[l] + nums[h]== sum) {
                        v[0] = nums[i];
                        v[1] = nums[j];
                        v[2] = nums[l];
                        v[3] = nums[h];
                        res.push_back(v);
                        while(l<nums.size()-1 && nums[l] == nums[l+1]) l++;
                        l++;
                        while(h>0 && nums[h] == nums[h-1]) h--;
                        h--;
                        
                    }
                    else if(nums[l]+nums[h] < sum)
                        l++;
                    else
                        h--;
                }
                while(j<nums.size()-1 && nums[j] == nums[j+1]) j++;
            }
            while(i<nums.size()-1 && nums[i] == nums[i+1]) i++;
        }
        return res;
    }
