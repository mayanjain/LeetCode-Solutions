class Solution {
public:
    bool solve(vector<int>& ms,int i,int pos,long sum,long cur){
        if(cur==sum){
            return solve(ms,i+1,0,sum,0);
        }
        if(i==4){
            return true;
        }
        for(int j=pos ; j<ms.size() ; j++){
            if(cur+ms[j]>sum)break;
            if(ms[j]){
                auto val=ms[j];
                ms[j]=0;
                if(solve(ms,i,j+1,sum,cur+val))return true;
                ms[j]=val;
            }
        }
        return false;
    }
    
    bool makesquare(vector<int>& ms) {
        long sum=0;
        for(auto& i:ms)sum+=i;
        if(sum%4)return false;
        sort(ms.begin(),ms.end());
        return solve(ms,0,0,sum/4,0);
    }
};