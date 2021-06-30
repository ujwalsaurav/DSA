// https://leetcode.com/problems/search-in-rotated-sorted-array/

class Solution {
public:
    int binarySearch(vector<int>& nums,int low,int high,int target)
    {
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            if(nums[mid] == target)
                return mid;
            else if(nums[mid] > target)
                high = mid-1;
            else if(nums[mid] < target)
                low = mid+1;
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        
        int low = 0;
        int high = nums.size()-1;
        
        while(low<high)
        {
            int mid = low + (high-low)/2;
            if(nums[mid]>nums[high])
                low = mid+1;
            else if(nums[mid]<=nums[high])
                high = mid;
        }
        
        int min = low;
        int res1 = binarySearch(nums,0,min-1,target);
        int res2 = binarySearch(nums,min,nums.size()-1,target);
        
        return (res1>res2)?res1:res2;        
        
    }
};