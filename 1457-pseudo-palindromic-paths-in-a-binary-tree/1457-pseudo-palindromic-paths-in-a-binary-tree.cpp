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
    int ans=0;
    
    void solve(TreeNode* root,set<int> st){
        if(st.count(root->val))st.erase(root->val);
        else st.insert(root->val);
        if(!root->left && !root->right){
            ans+=st.size()<2;
            return;
        }
        if(root->left)solve(root->left,st);
        if(root->right)solve(root->right,st);
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        set<int> st;
        solve(root,st);
        return ans;
    }
};