//https://leetcode.com/problems/find-smallest-letter-greater-than-target/

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        
        int size = letters.size();
        if(letters[size-1] <= target)
            return letters[0];
        
        int start = 0;
        int end = size-1;
        int mid;
        
        while(start < end)
        {
            mid = start + (end - start)/2;
            if(letters[mid] <= target)
                start = mid+1;
            else if(letters[mid] > target)
                end = mid;
        }
        return letters[end]; //Or, return letters[start];        
    }
};