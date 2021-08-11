// https://leetcode.com/problems/missing-number/

//Approach-1
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        int s = nums.size();
        int missingNum = s;
        for(int i=0;i<s;i++)
            missingNum = missingNum ^ (i ^ nums[i]);
        return missingNum;
        
    }
};

//Approach-2
class Solution {
public:
    int missingNumber(vector<int>& nums) {

        int s = nums.size();
        int totalSum = s*(s+1)/2;
        int actualSum = 0;
        
        for(int i=0;i<s;i++)
            actualSum += nums[i];
        
        return totalSum-actualSum; 
        
    }
};