class Solution {
public:
    int numTeams(vector<int>& rating) {
        vector<int> v(rating.size());
        int ans=0;
        for(int i=0 ; i<rating.size() ; i++){
            for(int j=i+1 ; j<rating.size() ; j++){
                if(rating[j]>rating[i])v[j]++,ans+=v[i];
            }
        }
        v.clear();
        v.resize(rating.size());
        for(int i=0 ; i<rating.size() ; i++){
            for(int j=i+1 ; j<rating.size() ; j++){
                if(rating[j]<rating[i])v[j]++,ans+=v[i];
            }
        }
        return ans;
    }
};