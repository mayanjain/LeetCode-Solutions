class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {
        long long ans=0,cur=0;
        map<int,long long> mp;
        for(auto& i:tasks){
            cur=max(++cur,mp[i]);
            mp[i]=cur+space+1;
        }
        return cur;
    }
};