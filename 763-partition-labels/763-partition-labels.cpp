class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> ans;
        vector<int> count(26);
        vector<bool> vis(26);
        int cur=0;
        for(auto& i:s)count[i-'a']++;
        for(int i=0 ; i<s.size() ; i++){
            count[s[i]-'a']--;
            vis[s[i]-'a']=1;
            bool part=1;
            cur++;
            for(int j=0 ; j<26 ; j++){
                if(vis[j] && count[j])part=0;
            }
            if(part){
                ans.push_back(cur);
                cur=0;
                for(int i=0 ; i<26 ; i++)vis[i]=0;
            }
        }
        return ans;
    }
};