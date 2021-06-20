//https://leetcode.com/problems/multiply-strings/

class Solution {
public:
    string multiply(string num1, string num2) {
        
        if(num1[0]=='0' || num2[0]=='0')
            return(to_string(0));
        int n1 = num1.size();
        int n2 = num2.size();
        vector<int> op(n1+n2);
        
        for(int i=n1-1;i>=0;i--)
        {
            for(int j=n2-1;j>=0;j--)
            {
                int mul = (num1[i]-'0')*(num2[j]-'0');
                int p1 = i+j;
                int p2 = i+j+1;
                int sum = op[p2] + mul;
                
                op[p2] = sum%10;
                op[p1] += sum/10;
            }
        }
        string res = "";
        int x=0;
        while(op[x]==0)
        {
            op.erase(op.begin()+0);
        }
        for(int i=0;i<op.size();i++)
            res.append(to_string(op[i]));
        if(op.size()==0)
            res.append(to_string(0));
        return res;
    }
};