// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        vector<vector<int>> op;
        if(root == NULL)
            return op;
        TreeNode *curr = root;
        vector<int> tempArray;
        vector<TreeNode*> currentLevel;
        
        currentLevel.push_back(curr);
        int count = 1;
        bool flag = 0;
        
        while(!currentLevel.empty()){
            
            if(currentLevel[0]->left)
                currentLevel.push_back(currentLevel[0]->left);
            if(currentLevel[0]->right)
                currentLevel.push_back(currentLevel[0]->right);
            count--;            
            tempArray.push_back(currentLevel[0]->val);
            currentLevel.erase(currentLevel.begin()+0);
                        
            if(count==0)
            {
                if(flag == 1){
                    reverse(tempArray.begin(),tempArray.end());
                }
                op.push_back(tempArray);
                tempArray.clear();
                count = currentLevel.size();
                flag = !flag;
            }
        }
        
        return op;
        
    }
};