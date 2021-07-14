//https://leetcode.com/problems/find-k-closest-elements/

//Binary Search + Sliding window approach

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
        vector<int> op;
        int size = arr.size();
        if(size==k){
            for(int i=0;i<k;i++)
                op.push_back(arr[i]);
            return op;
        }
        int start = 0;
        int end = size-1;
        int mid=0;
        
        while(start<=end)
        {
            mid = start + (end-start)/2;
            if(arr[mid]>x)
                end = mid-1;
            else if(arr[mid]<x)
                start = mid+1;
            else
                break;
        }
        
        int left = max(0,mid-1);
        int right = left+1;
        
        while((right-left-1) < k){
            
            if(left==-1){
                right++;
                continue;
            }
            if(right==size || abs(arr[left]-x)<=abs(arr[right]-x))
                left--;
            else
                right++;
        }
        left++;
        while(left<right){
            op.push_back(arr[left]);
            left++;
        }
        
        return op;        
        
        
    }
};

//Two pointer method

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
        vector<int> op;
        int start = 0;
        int end = arr.size()-1;
        
        while((end-start)>=k){
            
            if(abs(arr[start]-x) > abs(arr[end]-x))
               start++;
            else
               end--;

        }
        while(start<=end){
            op.push_back(arr[start]);
            start++;
        }
        return op;     
        
    }
};