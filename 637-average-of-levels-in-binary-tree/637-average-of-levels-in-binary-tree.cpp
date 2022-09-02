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
    vector<double> ans,size;
    
    void solve(TreeNode* root,int level){
        if(!root)return;
        if(level==ans.size()){
            ans.resize(level+1);
            size.resize(level+1);
        }
        size[level]++;
        ans[level]+=root->val;
        solve(root->left,level+1);
        solve(root->right,level+1);
    }
    
    vector<double> averageOfLevels(TreeNode* root) {
        solve(root,0);
        for(int i=0 ; i<ans.size() ; i++)ans[i]/=size[i];
        return ans;
    }
};