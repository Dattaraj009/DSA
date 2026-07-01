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
    int solve(TreeNode* root, int t,long long sum,unordered_map<long long,int>& mpp){
        
         if(root == nullptr) return 0;
         int cnt = 0;
         sum += root->val;
         if(mpp.find(sum-t) != mpp.end()){
            cnt += mpp[sum-t];
         }

         mpp[sum]++;
         int left = solve(root->left,t,sum,mpp);
         int right = solve(root->right,t,sum,mpp);
         mpp[sum]--;
         return left+right+cnt;
    }
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long,int> mpp;
        mpp[0] = 1;
        return solve(root,targetSum,0,mpp);
    }
};