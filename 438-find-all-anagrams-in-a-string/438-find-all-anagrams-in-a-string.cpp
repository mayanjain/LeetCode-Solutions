class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> st(26),ans;
        for(auto& i:p)st[i-'a']++;
        int n=s.size(),tp=p.size();
        for(int i=n-1 ; i>=0 ; i--){
            st[s[i]-'a']--;
            if(i+tp<n)st[s[i+tp]-'a']++;
            int f=0;
            for(auto& j:st){
                if(j!=0)f++;
            }
            if(f)continue;
            ans.push_back(i);
        }
        return ans;
    }
};