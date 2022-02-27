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
    vector<unsigned long long> lefts;
    unsigned long long mxwidth=0;
    
    void solvin(TreeNode* root,unsigned long long id,int depth){
        if(!root)return;
        if(depth>=lefts.size())lefts.push_back(id);
        mxwidth=max(mxwidth,id-lefts[depth]+1);
        solvin(root->left,id*2,depth+1);
        solvin(root->right,id*2+1,depth+1);
    }
    
    int widthOfBinaryTree(TreeNode* root) {
        solvin(root,1,0);
        return mxwidth;
    }
};