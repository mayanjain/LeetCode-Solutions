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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> v;
        if(!root)return v;
        vector<int> cur;
        stack<TreeNode*> st1,st2;
        st1.push(root);
        int left=0;
        while(st1.size()){
            for(int i=st1.size() ; i>=1 ; i--){
                auto node=st1.top();
                st1.pop();
                cur.push_back(node->val);
                if(left){
                    if(node->right)st2.push(node->right);
                    if(node->left)st2.push(node->left);
                }
                else{
                    if(node->left)st2.push(node->left);
                    if(node->right)st2.push(node->right);
                }
            }
            swap(st2,st1);
            v.push_back(cur);
            cur.clear();
            left^=1;
        }
        return v;
    }
};