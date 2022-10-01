/*Given an integer array nums of length n and an integer target, find three integers in nums such that the sum is closest to target.

Return the sum of the three integers.

You may assume that each input would have exactly one solution.
*/

//solution

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        
        sort(nums.begin(), nums.end());   // sort the array first to use 3 pointers approach.
        
        int n = nums.size();
        int closest = nums[1] + nums[n-1] + nums[0]; //initialize a variable to store the closest sum initially storing the first pair sum.
        
        for(int i=0;i<n; i++)  // for loop to add first element of pair.
        {
           int st = i+1, end = n-1;         // initialize 2 pointers st and end to add the rest pair of two.
            int sum2 = target - nums[i];    // a sum2 variable to store the left sum after adding one element.
            
            while(st<end)                   // run a loop to rest of the array excluding nums[i].
            {  
                int curr = nums[st] + nums[end];
                
                if(curr == sum2)
                    return target;
                else if(curr < sum2)       // move the pointers st and end according to the current sum.
                 {
                  st++;
                 }
                else
                   end--; 
                
                 if(abs(target- (curr+nums[i])) <= abs(target - closest))  // check whether the absolute value of deviation of current sum of three pointers is less than the deviation of the previous sum (stored in closest)
                   {
                     closest = curr+nums[i];                             // if a less deviation is found update the closest.
                   }
             
            }
            
        }
        
        return closest;
    }
};
