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
class BSTIterator {
public:
    stack<TreeNode*> stk;
    
    BSTIterator(TreeNode* root) {
        stk.push(root);
    }
    
    int next() {
        auto it=stk.top();
        // cout<<it->val<<" ";
        while(it->left!=NULL){
            auto kt=it->left;
            it->left=NULL;
            stk.push(kt);
            it=kt;
        }
        stk.pop();
        if(it->right)stk.push(it->right);
        return it->val;
    }
    
    bool hasNext() {
        return stk.size();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */