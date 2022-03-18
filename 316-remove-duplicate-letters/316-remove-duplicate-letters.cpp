class Solution{
public:
    string removeDuplicateLetters(string s){
        map<char,int> mp;
        for(auto& i:s)mp[i]++;
        set<char> vis;
        string ans="";
        for(auto& i:s){
            mp[i]--;
            if(vis.count(i))continue;
            while(ans.size() && ans.back()>i && mp[ans.back()]){
                vis.erase(ans.back());
                ans.pop_back();
            }
            ans+=i;
            vis.insert(i);
        }
        return ans;
    }
};