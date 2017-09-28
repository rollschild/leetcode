class Solution {
public:
    // TreeNode* anotherTree = nullptr;
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        /*
        if(anotherTree == nullptr) {
            if(t1 != nullptr && t2 != nullptr) anotherTree = new TreeNode(t1->val + t2->val);
        }
        */
        // if(t1 == nullptr && t2 == nullptr) return anotherTree;
        // if(t1 == nullptr) return anotherTree;
        // if(t2 == nullptr) return anotherTree;
        if(t1 && t2) {
            TreeNode* anotherTree = new TreeNode(t1->val + t2->val);
            // anotherTree->val = t1->val + t2->val;
            anotherTree->left = mergeTrees(t1->left, t2->left);
            anotherTree->right = mergeTrees(t1->right, t2->right);
            return anotherTree;
        }
        else
            return t1 ? t1 : t2;
    } 
};
