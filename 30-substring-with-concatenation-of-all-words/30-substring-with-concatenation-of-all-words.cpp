class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string,int> st;
        vector<int> ans;
        int n=words.size(),m=words[0].size();
        for(auto& i:words)st[i]++;
        for(int i=0 ; i+n*m<=s.size() ; i++){
            unordered_map<string,int> ct;
            for(int j=i ; j<s.size() ; j+=m){
                string cur=s.substr(j,m);
                if(st.count(cur)&& st[cur]>ct[cur]){
                    ct[cur]++;
                }
                else break;
            }
            if(st==ct)ans.push_back(i);
        }
        return ans;
    }
};