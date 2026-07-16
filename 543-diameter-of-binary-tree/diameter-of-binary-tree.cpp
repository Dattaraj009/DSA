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
    int diameter = 0;
    int solve(TreeNode* root,int store){
        if(!root) return 0;

        int left = solve(root->left,store);
        int right = solve(root->right,store);

        diameter = max(left+right,diameter);
        return max(left,right)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int s=  solve(root,0);
        return diameter;
    }
};