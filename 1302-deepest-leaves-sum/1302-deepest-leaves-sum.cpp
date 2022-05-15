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
    int deepestLeavesSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int sum;
        while(q.size()){
            sum=0;
            for(int i=q.size() ; i>=1 ; i--){
                auto it=q.front();
                sum+=it->val;
                q.pop();
                if(it->left)q.push(it->left);
                if(it->right)q.push(it->right);
            }
        }
        return sum;
    }
};