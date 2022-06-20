class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        sort(words.begin(),words.end(),[](string& s,string& t){return s.size()>t.size();});
        unordered_set<string> st;
        int ans=0;
        for(auto& i:words){
            if(!st.count(i)){
                for(int j=0 ; j<i.size(); j++){
                    st.insert(i.substr(j));
                }
                ans+=i.size()+1;
            }
        }
        return ans;
    }
};