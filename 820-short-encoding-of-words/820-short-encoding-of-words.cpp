class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        unordered_set<string> st(words.begin(),words.end());
        int ans=0;
        for(auto& i:words){
            for(int j=1 ; j<i.size(); j++){
                st.erase(i.substr(j));
            }
        }
        for(auto& i:st)ans+=i.size()+1;
        return ans;
    }
};