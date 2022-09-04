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
    map<int,map<int,multiset<int>>> mp;
    
    void solve(TreeNode* root,int x,int y){
        if(!root)return;
        mp[y][x].insert(root->val);
        solve(root->left,x+1,y-1);
        solve(root->right,x+1,y+1);
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        solve(root,0,0);
        vector<vector<int>> ans;
        for(auto& col:mp){
            vector<int> cur;
            for(auto& row:col.second){
                cur.insert(cur.end(),row.second.begin(),row.second.end());
            }
            ans.push_back(cur);
        }
        return ans;
    }
};