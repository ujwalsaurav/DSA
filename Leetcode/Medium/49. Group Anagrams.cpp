// https://leetcode.com/problems/group-anagrams/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        vector<vector<string>> op;
        vector<string> v;
        map<map<char,int>,vector<string>> mp;
        map<char,int> mp1;
        string temp; 
        
        for(int i=0;i<strs.size();i++)
        {
            temp = strs[i];
            for(int j=0;j<strs[i].size();j++)
            {
                mp1[strs[i][j]]++;
            }
            mp[mp1].push_back(temp);
        }
        for(auto it = mp.begin();it != mp.end(); it++)
        {
            op.push_back(it->second);
        }
        return op;
        
    }
};