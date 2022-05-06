class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>> st;
        for(auto& i:s){
            int cur=1;
            if(st.size() && st.top().first==i){
                cur+=st.top().second;
            }
            st.push({i,cur});
            if(cur==k){
                for(int i=0 ; i<k ; i++)st.pop();
            }
        }
        string ans="";
        while(st.size()){
            ans+=st.top().first;
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};