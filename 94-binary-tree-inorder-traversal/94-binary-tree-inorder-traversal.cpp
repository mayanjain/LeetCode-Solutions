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
    vector<int> inorderTraversal(TreeNode* root) {
        if(!root)return {};
        stack<TreeNode*> stk;
        stk.push(root);
        vector<int> ans;
        while(stk.size()){
            auto top=stk.top();
            while(top->left){
                auto next=top->left;
                top->left=NULL;
                top=next;
                stk.push(top);
            }
            ans.push_back(top->val);
            stk.pop();
            if(top->right)stk.push(top->right);
        }
        return ans;
    }
};