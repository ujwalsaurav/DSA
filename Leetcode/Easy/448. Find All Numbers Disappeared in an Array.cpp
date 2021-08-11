// https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        
        for(int i=0;i<nums.size();i++){
            nums[abs(nums[i])-1] = -abs(nums[abs(nums[i])-1]);
            cout<<nums[abs(nums[i])-1]<<" ";
        }
        vector<int>op;
        for(int i=0;i<nums.size();i++){
            if(nums[i] > 0)
                op.push_back(i+1);
        }
        return op;
    }
};