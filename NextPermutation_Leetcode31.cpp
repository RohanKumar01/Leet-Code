/*A permutation of an array of integers is an arrangement of its members into a sequence or linear order.

For example, for arr = [1,2,3], the following are all the permutations of arr: [1,2,3], [1,3,2], [2, 1, 3], [2, 3, 1], [3,1,2], [3,2,1].
The next permutation of an array of integers is the next lexicographically greater permutation of its integer. 
For example, the next permutation of arr = [1,2,3] is [1,3,2].
*/

//Solution

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        int n = nums.size();
        int i, ct = 1;
        
        for(i= n-2; i>=0; i--)   //Run a for loop from end to start of nums so as to find first occurence of smaller element from end.
        {
           if(nums[i]< nums[i+1])  // condition when found the descending element.
           {
             ct = 0;
             break; 
           }
            
            ct++;   // ct will store the count of elements after the first descending element.
        }
        
        if(ct == n){        // if ct == n then the whole array is in descending order then we have to return the ascending order.
            sort(nums.begin(), nums.end());
            return;
        } 
        
        sort(nums.begin() + i+1, nums.end());  // other wise sort the array till after descending element till n-1 th element.
        
        auto upper = upper_bound(nums.begin()+i, nums.end(), nums[i]);   // Find the next greater element in the sorted part of the array.
         int upper_id = upper - nums.begin();                          //find index of the next greater element.
               
               swap(nums[upper_id], nums[i]);     // swap the next greater element to the descending element at i th index.
        
        sort(nums.begin()+i+1, nums.end());       // sort the array after the ith index.
               
    }   //As the array nums is passed by reference changes in this function would reflect in nums.
};
