class Solution {
public:
    bool solve(long mid,vector<int>& p,int h){
        long cur=0;
        for(int i=0 ; i<p.size() ; i++){
            cur+=p[i]/mid+(p[i]%mid!=0);
        }
        return cur<=h;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        long l=1,k=1e9;
        while(l<k){
            long mid=(k-l)/2+l;
            if(solve(mid,piles,h)){
                k=mid;
            }
            else l=mid+1;
        }
        return l;
    }
};