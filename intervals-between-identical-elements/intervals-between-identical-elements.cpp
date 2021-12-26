class Solution {
public:
    vector<long long> getDistances(vector<int>& arr) {
        unordered_map<int,vector<int>> mp;
        vector<long long> pre(arr.size()),suf(arr.size());
        for(int i=0 ; i<arr.size() ; i++)mp[arr[i]].push_back(i);
        for(auto& k:mp){
            auto p=k.second;
            for(int i=1 ; i<p.size() ; i++){
                pre[p[i]]=pre[p[i-1]]+i*(p[i]-p[i-1]);
            }
            for(int i=p.size()-2 ; i>=0 ; i--){
                suf[p[i]]=suf[p[i+1]]+(p.size()-i-1)*(p[i+1]-p[i]);
                pre[p[i]]+=suf[p[i]];
            }
        }
        return pre;
    }
};