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
    int sum(TreeNode* root,string& s){
        if(!root)return 0;
        if(root->left==NULL && root->right==NULL){
            return stoi(s+char(root->val+'0'),0,2);
        }
        s+=char(root->val+'0');        
        int lf=sum(root->left,s);
        int rt=sum(root->right,s);
        s.pop_back();
        return lf+rt;
    }
    
    int sumRootToLeaf(TreeNode* root) {
        string s="";
        return sum(root,s);
    }
};