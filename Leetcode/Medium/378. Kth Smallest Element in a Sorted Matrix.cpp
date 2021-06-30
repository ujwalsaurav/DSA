//https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/

//Approach-1 : Using Binary Search [TC: O(n*log(max-min))]

class Solution {
public:
    int getCount(vector<vector<int>> matrix, int mid)
    {
        int count=0;
        int n = matrix.size();
        
        for(int i=0;i<n;i++)
        {
            for(int j=n-1;j>=0;j--)
            {
                if(matrix[i][j] <= mid)
                {
                    count += j+1;
                    break;
                }
            }
        }
        return count;
        
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        
        int n = matrix.size();
        int low = matrix[0][0];
        int high = matrix[n-1][n-1];
        int count;
        
        while(low<high)
        {
            int mid = low + (high-low)/2;
            count = getCount(matrix,mid);
            if(count >= k)
                high = mid;
            else
                low = mid+1;            
        }
        return low;
    }
};

//Approach-2 : Using min heap [TC: O(min(n,k)+(k*log(n)))]

typedef pair<int,pair<int,int>> pii;

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        
        priority_queue<pii, vector<pii>, greater<pii>> minHeap;
        int n = matrix.size();
        
        for(int i=0;i<n&&i<k;i++)
            minHeap.push(make_pair(matrix[i][0],make_pair(i,0)));
        int count = 0;
        int result = 0;
        
        while(!minHeap.empty())
        {
            auto heapTop = minHeap.top();
            minHeap.pop();
            result = heapTop.first;
            count++;
            if(count == k)
                break;
            
            heapTop.second.second++;
            if(heapTop.second.second < n)
            {
                heapTop.first = matrix[heapTop.second.first][heapTop.second.second];
                minHeap.push(heapTop);
            }
        }
        
        return result;            
        
        
    }
};