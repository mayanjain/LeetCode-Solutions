class Solution {
public:
    vector<int> ans;
    
    void solve(long last,long cur,long mx,int k){
        if(cur>=mx){
            ans.push_back(cur);
            return;
        }
        if(last+k<=9)solve(last+k,cur*10+(last+k),mx,k);
        if(last-k>=0 && k!=0)solve(last-k,cur*10+(last-k),mx,k);
    }
    
    vector<int> numsSameConsecDiff(int n, int k) {
        for(int i=1 ; i<=9 ; i++){
            solve(i,i,pow(10,n-1),k);
        }
        return ans;
    }
};