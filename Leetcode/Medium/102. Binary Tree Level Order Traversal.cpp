// https://leetcode.com/problems/binary-tree-level-order-traversal/

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        vector<vector<int>> op;
        if(root == NULL)
            return op;
        TreeNode *curr = root;
        vector<int> tempArray;
        vector<TreeNode*> currentLevel;
        
        currentLevel.push_back(curr);
        int count = 1;
        
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
                op.push_back(tempArray);
                tempArray.clear();
                count = currentLevel.size();
            }
        }
        
        return op;
        
    }
};