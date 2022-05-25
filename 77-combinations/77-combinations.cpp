class Solution {
public:
    vector<vector<int>> ans;
    
    void solve(int i,int n,int k,vector<int>& cur){
        if(cur.size()==k){
            ans.push_back(cur);
            return;
        }
        if(i==n+1)return;
        cur.push_back(i);
        solve(i+1,n,k,cur);
        cur.pop_back();
        solve(i+1,n,k,cur);
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<int> cur;
        solve(1,n,k,cur);
        return ans;
    }
};