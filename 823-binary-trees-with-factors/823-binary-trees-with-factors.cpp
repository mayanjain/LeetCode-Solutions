class Solution {
public:
    const long mod = 1e9+7;
    unordered_map<long,long> mp;
    
    
    long long solve(unordered_set<int>& st,int cur){
        long long ans=1;
        if(mp.count(cur))return mp[cur];
        for(auto& i:st){
            if(cur%i==0 && st.count(cur/i)){
                ans+=solve(st,i)*solve(st,cur/i);
                ans%=mod;
            }
        }
        return mp[cur]=ans;
    }
    
    int numFactoredBinaryTrees(vector<int>& arr) {
        unordered_set<int> st(arr.begin(),arr.end());
        int ans=0;
        for(auto& i:st){
            ans+=solve(st,i);
            ans%=mod;
        }
        return ans;
    }
};
