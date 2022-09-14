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
    
    void solve(TreeNode* root,map<int,int>& mp){
        mp[root->val]++;
        if(!root->left && !root->right){
            int x=0;
            for(auto& i:mp){
                x+=i.second%2;
            }
            ans+=x<2;
            mp[root->val]--;
            return;
        }
        if(root->left)solve(root->left,mp);
        if(root->right)solve(root->right,mp);
        mp[root->val]--;
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        map<int,int> st;
        solve(root,st);
        return ans;
    }
};