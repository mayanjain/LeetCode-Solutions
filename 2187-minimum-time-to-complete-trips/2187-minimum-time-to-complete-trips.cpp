class Solution {
public:
    long long minimumTime(vector<int>& time, int trips) {
        long long low = 0 , high = 1e14;
        while(low<high){
            long long mid = (low+high)/2;
            long long cur = 0;
            for(auto& i:time)cur+=mid/i;
            if(cur>=trips)high=mid;
            else low=mid+1;
            // cout<<cur<<" ";
        }
        return low;
    }
};