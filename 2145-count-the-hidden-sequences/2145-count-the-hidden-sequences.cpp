class Solution {
public:
    int numberOfArrays(vector<int>& dif, int lower, int upper) {
        vector<long> arr(dif.size()+1);
        long mn=0,mx=0;
        for(int i=0 ; i<dif.size() ; i++){
            arr[i+1]=dif[i]+arr[i];
            mx=max(mx,arr[i+1]);
            mn=min(mn,arr[i+1]);
            if(mx-mn>upper-lower)return 0;
        }
        return (upper-lower)-(mx-mn)+1;
    }
};