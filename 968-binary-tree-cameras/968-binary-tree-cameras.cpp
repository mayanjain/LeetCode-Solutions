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
    #define monitored 1
    #define camera 2
    #define notmonitored 0
    int ans=0;
    
    int solve(TreeNode* root) {
        if(!root)return monitored;
        int left=solve(root->left),right=solve(root->right);
        if(left==notmonitored || right==notmonitored){
            ans++;
            return camera;   
        }
        if(left==camera || right==camera){
            return monitored;
        }
        return notmonitored;
    }
    
    int minCameraCover(TreeNode* root){
        return !solve(root)?ans+1:ans;
    }
};