//https://leetcode.com/problems/find-all-anagrams-in-a-string/

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        
        vector<int> op;
        if(p.length() > s.length())
            return op;
        map<char,int> mp;
        for(int i=0;i<p.length();i++)
            mp[p[i]]++;
        int count = mp.size();
        int start = 0;
        int end = 0;
        
        while(end < s.length())
        {
            if(mp.find(s[end]) != mp.end())
            {
                mp[s[end]]--;
                if(mp[s[end]] == 0)
                    count--;
            }
            end++;
            
            if(end - start == p.length())
            {
                if(count == 0)
                    op.push_back(start);
                
                if(mp.find(s[start]) != mp.end())
                {
                    if(mp[s[start]]==0)
                        count++;
                    mp[s[start]]++;                    
                }
                start++;
            }
        }
        return op;
    }
        
};