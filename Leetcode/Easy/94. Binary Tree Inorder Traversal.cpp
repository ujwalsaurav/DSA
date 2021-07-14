// https://leetcode.com/problems/binary-tree-inorder-traversal/

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
    vector<int> inorderTraversal(TreeNode* root) {
        
        TreeNode *temp = root;
        vector<int> op;
        stack<TreeNode*> s;
        
        while(temp!=NULL || !s.empty())
        {
            while(temp!=NULL)
            {
                s.push(temp);
                temp = temp->left;
            }
            temp = s.top();
            s.pop();
            op.push_back(temp->val);
            temp = temp->right;            
        }
        return op;
        
    }
};