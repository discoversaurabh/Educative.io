/*
Given a non-empty array of integers, every element appears three times except for one, which appears exactly once. Find that single one.

Note:

Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Example 1:

Input: [2,2,3,2]
Output: 3
Example 2:

Input: [0,1,0,1,0,1,99]
Output: 99
*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int sizeOS=sizeof(int) * 8;
        vector<int> arr(sizeOS);
        //cout<<"s"<<sizeOS;
        int ans=0, p=1;
        for(int i=sizeOS-1; i>=0; i--)
        {
            if(i < sizeOS-1)
                p <<= 1;
            
            for(int j=0; j<nums.size(); j++)
            {
                if(nums[j] & p)
                    arr[i]++;
                arr[i] = arr[i] % 3;
            }
        }
        //cout<<"h";
        p = 1;
        for(int i=sizeOS-1; i>=0; i--)
        {
            if(i < sizeOS-1)
                p <<= 1;
            //cout<<" "<<arr[i];
            if(arr[i])
                ans  = ans | p;
        }
        return ans;
    }
};
