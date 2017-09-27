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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        vector<TreeNode*> treeStack;
        for(int i = 0; i < nums.size(); ++i) {
            TreeNode* currentNode = new TreeNode(nums[i]);
            while(!treeStack.empty() && treeStack.back()->val < nums[i]) {
                currentNode->left = treeStack.back();
                treeStack.pop_back();
            }
            if(!treeStack.empty()) {
                treeStack.back()->right = currentNode;
            }
            treeStack.push_back(currentNode);
        }
        return treeStack.front();
    }
};
