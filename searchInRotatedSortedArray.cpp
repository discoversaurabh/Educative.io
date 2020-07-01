/*
Search in Rotated Sorted Array

Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.

Your algorithm's runtime complexity must be in the order of O(log n).

Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
*/

/*
CONCEPT :

Search in Rotated Array (medium) #
Given an array of numbers which is sorted in ascending order and also rotated by some arbitrary number, find if a given ‘key’ is present in it.

Write a function to return the index of the ‘key’ in the rotated array. If the ‘key’ is not present, return -1. You can assume that the given array does not have any duplicates.

Example 1:

Input: [10, 15, 1, 3, 8], key = 15
Output: 1
Explanation: '15' is present in the array at index '1'.
    1   
    3   
    8   
    10   
    15   
 Original array:  
 Array after 2 rotations:  
    10   
    15   
    1   
    3   
    8   
Example 2:

Input: [4, 5, 7, 9, 10, -1, 2], key = 10
Output: 4
Explanation: '10' is present in the array at index '4'.
 Original array:  
    -1   
    2   
    4   
    5   
    7   
    9   
    10   
    
 Array after 5 rotations:  
 4   
    5   
    7   
    9   
    10   
    -1   
    2   
Solution #
The problem follows the Binary Search pattern. We can use a similar approach as discussed in Order-agnostic Binary Search and modify it similar to Search Bitonic Array to search for the ‘key’ in the rotated array.

After calculating the middle, we can compare the numbers at indices start and middle. This will give us two options:

If arr[start] <= arr[middle], the numbers from start to middle are sorted in ascending order.
Else, the numbers from middle+1 to end are sorted in ascending order.
Once we know which part of the array is sorted, it is easy to adjust our ranges. For example, if option-1 is true, we have two choices:

By comparing the ‘key’ with the numbers at index start and middle we can easily find out if the ‘key’ lies between indices start and middle; if it does, we can skip the second part => end = middle -1.
Else, we can skip the first part => start = middle + 1.
Let’s visually see this with the above-mentioned Example-2:
4   
    5   
    7   
    9   
    10   
    -1   
    2
 Search 'key' = 10  
 Since arr[start] <= arr[middle], we can conclude that all numbers from start --> middle are sorted in ascending order
 By looking at the sorted part, from its start and end, we can conclude that the key can't be in the sorted part, hence start = middle +1  
 
       
    4   
    5   
    7   
    9   
    10   
    -1   
    2   
 
   
 Since arr[start] >  arr[middle], we can conclude that all numbers from middle --> end are sorted in ascending order  4
 By looking at the sorted part, from its start and end, we can conclude that the key can't be in the sorted part, hence end = middle - 1  
  4   
    5   
    7   
    9   
    10   
    -1   
    2 
    We have found the key!  
 
Since there are no duplicates in the given array, it is always easy to skip one part of the array in each iteration. However, if there are duplicates, it is not always possible to know which part is sorted. We will look into this case in the ‘Similar Problems’ section.
*/

class Solution {
public:
    int searchRec(vector<int>& nums, int l, int r, int target) {
        if(l > r)
            return -1;
        
        int m = l + (r-l)/2;
        
        if(nums[m] == target)
            return m;
        
        if(nums[l] <= nums[m])   //left part is sorted
        {
            if(target >= nums[l] && target < nums[m])
                return searchRec(nums, l, m-1, target);
            else
                return searchRec(nums, m+1, r, target); 
        }
        else    //right part is sorted
        {
            if(target > nums[m] && target <= nums[r])
                return searchRec(nums, m+1, r, target);
            else
                return searchRec(nums, l, m-1, target);
        }  
    }
    
    int search(vector<int>& nums, int target) {
        int size = nums.size();
        if(!size)
            return -1;
        return searchRec(nums, 0, size-1, target);
    }
};
