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
    map<pair<TreeNode*,bool>,int> mp;
    
    int solve(TreeNode* root,bool camera=false,bool monitored=false) {
        if(!root)return 0;
        if(camera)return 1+solve(root->left,false,true)+solve(root->right,false,true);
        if(mp.count({root,monitored}))return mp[{root,monitored}];
        if(monitored){
            auto cam=1+solve(root->left,false,true)+solve(root->right,false,true);
            auto nocam=solve(root->left,false,false)+solve(root->right,false,false);
            return mp[{root,monitored}]=min(nocam,cam);
        }
        auto cam=1+solve(root->left,false,true)+solve(root->right,false,true);
        auto left=root->left?solve(root->left,true,true)+solve(root->right,false,false):INT_MAX;
        auto right=root->right?solve(root->right,true,true)+solve(root->left,false,false):INT_MAX;
        return mp[{root,monitored}]=min(cam,min(left,right));
    }
    
    int minCameraCover(TreeNode* root){
        return solve(root,false,false);
    }
};