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
    vector<set<int>> v;
    
    void dfs(TreeNode* root){
        if(root->left){
            v[root->left->val].insert(root->val);
            v[root->val].insert(root->left->val);
            dfs(root->left);
        }
        if(root->right){
            v[root->right->val].insert(root->val);
            v[root->val].insert(root->right->val);
            dfs(root->right);
        }
    }
    
    int amountOfTime(TreeNode* root, int start) {
        v.resize(1e5+1);
        dfs(root);
        queue<int> q;
        q.push(start);
        int ans=-1;
        while(q.size()){
            ans++;
            for(int i=q.size() ; i>0 ; i--){
                auto top=q.front();
                q.pop();
                for(auto& j:v[top]){
                    q.push(j);
                    v[j].erase(top);
                }
            }
        }
        return ans;
    }
};