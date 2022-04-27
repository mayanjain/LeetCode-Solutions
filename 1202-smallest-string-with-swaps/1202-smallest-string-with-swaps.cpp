class Solution {
public:
    vector<int> parent;
    int find(int i){
        if(parent[i]==i)return i;
        return parent[i]=find(parent[i]);
    }
    
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n=s.size();
        parent.resize(n);
        for(int i=0 ; i<n ; i++)parent[i]=i;
        for(int i=0 ; i<pairs.size() ; i++){
            int x=find(pairs[i][0]),y=find(pairs[i][1]);
            if(x!=y)parent[x]=y;
        }
        vector<pair<int,vector<char>>> mp(n);
        for(int i=0 ; i<n ; i++){
            mp[parent[find(i)]].second.push_back(s[i]);
        }
        for(auto& i:mp)sort(i.second.begin(),i.second.end());
        for(int i=0 ; i<n ; i++){
            int x=mp[parent[find(i)]].first++;
            s[i]=mp[parent[find(i)]].second[x];
        }
        return s;
    }
};