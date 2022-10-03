//Leetcode 34
/*Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.
Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4] 
*/

//Solution


class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
         vector<int> ans;
        int lower_id, upper_id;
        
        if(nums.size() == 0 || binary_search(nums.begin(), nums.end(), target) == false) //check whether the array is empty or whether it contatins the element to 
        {                                                                                // searched or not ,if not then push (-1,-1) in ans.
            ans.push_back(-1);
           ans.push_back(-1);
           return ans;  
        }
            
        
         auto lower = lower_bound(nums.begin(), nums.end(), target);  // find lowerbound of the target
         lower_id = lower - nums.begin();                        // calculate index of lowerbound
        
         auto upper = upper_bound(nums.begin(), nums.end(), target);      // find upper bound of the target
         upper_id = upper - nums.begin();                            // calculate index of upper bound
    
    
        
        ans.push_back(lower_id);
        ans.push_back(upper_id -1);
        return ans;
    }
};
