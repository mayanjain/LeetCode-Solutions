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
    int pos=0;
    
    TreeNode* build(vector<int>& preorder,vector<int>& inorder,map<int,int>& mp,int low,int high){
        if(low>high)return NULL;
        auto node = new TreeNode(preorder[pos]);
        auto index=mp[preorder[pos++]];
        node->left=build(preorder,inorder,mp,low,index-1);
        node->right=build(preorder,inorder,mp,index+1,high);
        return node;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int> mp;
        for(int i=0 ; i<inorder.size() ; i++){
            mp[inorder[i]]=i;
        }
        return build(preorder,inorder,mp,0,inorder.size()-1);
    }
};