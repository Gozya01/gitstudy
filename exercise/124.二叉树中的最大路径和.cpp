/*
 * @lc app=leetcode.cn id=124 lang=cpp
 *
 * [124] 二叉树中的最大路径和
 */

// @lc code=start
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
    int ans = -1e9;
    int maxPathSum(TreeNode* root) {
        Dfs(root);
        return ans;
    }
    int Dfs(TreeNode* root) {
        if(!root)
            return 0;
        int l = Dfs(root->left);
        int r = Dfs(root->right);
        ans = max(ans, max(0,l) + max(0,r) + root->val);
        return max(0,max(0,max(l, r)) + root->val);
    }
};
// @lc code=end

