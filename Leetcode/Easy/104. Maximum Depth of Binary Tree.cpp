// https://leetcode.com/problems/maximum-depth-of-binary-tree/

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
    int calcMaxDepth(TreeNode *root){
        
        if(root == NULL)
            return 0;
        TreeNode *leftTree = root->left;
        TreeNode *rightTree = root->right;
        
        return 1+max(calcMaxDepth(leftTree),calcMaxDepth(rightTree));
    }
    int maxDepth(TreeNode* root) {
        
        return calcMaxDepth(root);
        
    }
};