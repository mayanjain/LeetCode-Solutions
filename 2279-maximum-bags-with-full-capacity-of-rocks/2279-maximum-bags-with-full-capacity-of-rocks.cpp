class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int extra) {
        multiset<int> st;
        for(int i=0 ; i<rocks.size()  ; i++){
            st.insert(capacity[i]-rocks[i]);
        }
        int ans=0;
        for(auto& i:st){
            if(extra>=i){
                ans++;
                extra-=i;
            }
            else break;
        }
        return ans;
    }
};