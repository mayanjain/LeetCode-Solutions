class Solution {
public:
    int maximumRobots(vector<int>& charge, vector<int>& run, long long budget) {
        long long cur=0,ans=0,n=run.size(),st=0;
        multiset<long long> mt;
        for(int i=0 ; i<n ; i++){
            mt.insert(charge[i]);
            cur+=run[i];
            auto it=mt.end();it--;
            while(*it+(i-st+1)*cur>budget){
                mt.erase(mt.lower_bound(charge[st]));
                cur-=run[st++];
                if(st>i)break;
                it=mt.end();it--;
            }
            ans=max(ans,i-st+1);
        }
        return ans;
    }
};