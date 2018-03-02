/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
    private:
    stack<TreeNode*> myStack;
    void pushAllLeft(TreeNode* node) {
        for(; node != nullptr; node = node->left) {
            myStack.push(node);
        }
    }
public:
    BSTIterator(TreeNode *root) {
        pushAllLeft(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !myStack.empty();
    }

    /** @return the next smallest number */
    int next() {
        // looks like we need to remove the smallest node for this iteration
        int result = 0;
        if(!myStack.empty()) {
            TreeNode* smallest = myStack.top();
            result = smallest->val;
            myStack.pop();
            pushAllLeft(smallest->right);
        }
        return result;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
