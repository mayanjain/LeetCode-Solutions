class Solution {
public:
    int minJumps(vector<int>& arr) {
        map<int,vector<int>> mp;
        int n=arr.size();
        for(int i=0 ; i<n ; i++)mp[arr[i]].push_back(i);
        queue<int> q;
        q.push(0);
        int step=0;
        unordered_set<int> vis;
        vis.insert(0);
        while(q.size()){
            for(int i=q.size() ; i>0 ; i--){
                int cur=q.front();
                if(cur==n-1)return step;
                q.pop();
                mp[arr[cur]].push_back(cur-1);
                mp[arr[cur]].push_back(cur+1);
                for(auto& i:mp[arr[cur]]){
                    if(i>=0 && i<n && !vis.count(i)){
                        vis.insert(i);
                        q.push(i);
                    }
                }
                mp[arr[cur]].clear();
            }
            step++;
        }
        return 0;
    }
};