class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        long long ans=LONG_LONG_MAX;
        sort(beans.begin(),beans.end());
        long long sum=0;
        for(int i=0 ; i<beans.size() ; i++){
            sum+=beans[i];
        }
        for(int i=0 ; i<beans.size() ; i++){
            long long cur=(beans.size()-i)*beans[i];
            ans=min(sum-cur,ans);
        }
        return ans;
    }
};