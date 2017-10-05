/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int dfs(TreeNode* node, vector<vector<int>>& result) {
        if(!node) return -1;
        int height = max(dfs(node->left, result), dfs(node->right, result)) + 1;
        if((height + 1) > result.size()) result.push_back(vector<int>()); // vector already filled out along the way.
        result[height].push_back(node->val);
        // node->left = node->right = nullptr;
        return height;
    }
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> result;
        dfs(root, result);
        return result;
    }
};
