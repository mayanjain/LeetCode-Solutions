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
        queue<TreeNode*> q;
        q.push(root);
        vector<int> cur(1,root->val);
        v.push_back(cur);
        bool rev=1;
        while(q.size()){
            cur.clear();
            for(int i=q.size() ; i>=1 ; i--){
                auto front=q.front();
                q.pop();
                if(front->left){
                    q.push(front->left);
                    cur.push_back(front->left->val);
                }
                if(front->right){
                    q.push(front->right);
                    cur.push_back(front->right->val);
                }
            }
            if(cur.size()){
                if(rev)reverse(cur.begin(),cur.end());
                v.push_back(cur);
                rev^=1;
            }
        }
        return v;
    }
};