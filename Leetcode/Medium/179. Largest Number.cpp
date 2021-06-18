// https://leetcode.com/problems/largest-number/

bool comp(string i,string j)
{
    string temp1 = i+j;
    string temp2 = j+i;

    int k=0;

    while(temp1[k] && temp2[k])
    {
        if(temp1[k] > temp2[k])
            return true;
        else if(temp2[k] > temp1[k])
            return false;
        k++;    
    }
    return false;
}
class Solution {
public:

    string largestNumber(vector<int>& nums) {
        
        vector<string> v;
        int zeroCount = 0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
                zeroCount++;
            v.push_back(to_string(nums[i]));
        }
        if(zeroCount == nums.size())
            return to_string(0);
        
        sort(v.begin(),v.end(),comp);  
        string op;
        for(int i=0;i<v.size();i++)
            op = op+v[i];
        return op;
    }
};