class Solution {
public:
    TreeNode* head = nullptr;
    void revPreOrder(TreeNode* node) {
        if (node->right) revPreOrder(node->right);
        if (node->left) revPreOrder(node->left);
        node->left = nullptr, node->right = head, head = node;
    }
    
    void flatten(TreeNode* root) {
        if (root) revPreOrder(root);
    }
};