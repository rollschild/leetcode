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
    TreeNode* findLeftChild(TreeNode* parent) {
        if(parent == nullptr) return nullptr;
        if(parent->left == nullptr) return parent;
        TreeNode* leftchild = new TreeNode(parent->left->val);
        return findLeftChild(leftchild);
    }
    /*
    TreeNode* findRightChild(TreeNode* parent) {
        if(parent == nullptr) return nullptr;
        if(parent->right == nullptr) return parent;
        TreeNode* rightchild = new TreeNode(parent->right->val);
        return findRightChild(rightchild);
    }
    */
    TreeNode* findParent(TreeNode* root, TreeNode* child) {
        if(root == nullptr) return nullptr;
        if(root->left == child || root->right == child) return root;
        TreeNode* leftparent = new TreeNode(0);
        TreeNode* rightparent = new TreeNode(0);
        if(root->right != nullptr) {
            rightparent->val = root->right->val;
            // return findParent(rightparent, child);
        }
        if(root->left != nullptr) {
            leftparent->val = root->left->val;
            // return findParent(leftparent, child);
        }
        if(child->val < root->val) {
            return findParent(leftparent, child);
        }
        else {
            return findParent(rightparent, child);
        }
        
    }
    
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if(root == nullptr) return nullptr;
        if(p == nullptr) return nullptr;
        if(p->right != nullptr) {
            // first find its right child
            TreeNode* rightchild = new TreeNode(p->right->val);
            // then find the most left child
            return findLeftChild(rightchild);
        }
        else {
            TreeNode* parent = findParent(root, p);
            if(parent->left == p) {
                return parent;
            }
            if (parent->right == p) {
                if(root->val > p->val) return root;
                else return nullptr;
            }
        }
    }
};
