class Solution {
public:
    vector<vector<int>> ans;
    
    void solve(int k,int n,int cur,vector<int>& v){
        if(!k){
            if(!n)ans.push_back(v);
        }
        for(int i=cur+1 ; i<10 && n-i>=0 ; i++){
            v.push_back(i);
            solve(k-1,n-i,i,v);
            v.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> v;
        solve(k,n,0,v);
        return ans;
    }
};