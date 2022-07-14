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
    
    TreeNode* build(vector<int>& preorder,vector<int>& postorder,map<int,int>& mp,int low,int high){
        if(high<low)return NULL;
        int n=postorder.size();
        auto node=new TreeNode(preorder[pos++]);
        if(low!=high){
            int index=mp[preorder[pos]];
            node->left=build(preorder,postorder,mp,low,index);
            node->right=build(preorder,postorder,mp,index+1,high-1);
        }
        return node;
    }
    
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        map<int,int> mp;
        for(int i=0 ; i<postorder.size() ; i++){
            mp[postorder[i]]=i;
        }
        return build(preorder,postorder,mp,0,postorder.size()-1);
    }
};