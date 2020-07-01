/*
Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once.

Example:

Input:  [1,2,1,3,2,5]
Output: [3,5]
Note:

The order of the result is not important. So in the above example, [5, 3] is also correct.
Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity?

*/

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int size = nums.size();
        if(!size) return {0};
        int xr = nums[0];
        for(int i=1; i<size; i++)
        {
            xr ^= nums[i];
        }
        
        int p=1;
        
        while(xr)
        {
            if(xr & p)
                break;
            p <<= 1;
        }
        
        int group1=0, group2=0;
        for(int i=0; i<size; i++)
        {
            if(nums[i] & p)
                group1 ^= nums[i];
            else
                group2 ^= nums[i];
        }
        return {group1, group2};
    }
};
