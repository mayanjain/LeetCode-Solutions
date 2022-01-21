class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int res=0,total=0,sum=0,n=gas.size();
        for(int i=0 ; i<n ; i++){
            sum+=gas[i]-cost[i];
            if(sum<0){
                total+=sum;
                sum=0;
                res=i+1;
            }
        }
        total+=sum;
        return total<0?-1:res;
    }
};