// https://leetcode.com/problems/climbing-stairs/

vector<int> dp(50,-1);
class Solution {
public:
    int fib(int n){
    
        if(n<=0)
            return 0;
        if(n==1)
            return 1;
        if(n==2)
            return 2;
        if(dp[n] != -1)
            return dp[n];
        return dp[n] = fib(n-1)+fib(n-2);        
    }
    
    int climbStairs(int n) {

        return fib(n);
        
    }
};