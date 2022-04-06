class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        int ans=0;
        unordered_map<int,int> mp;
        for(int i=0 ; i<arr.size() ; i++){
            ans+=mp[target-arr[i]];
            for(int j=0 ; j<i ; j++){
                mp[arr[i]+arr[j]]++;
            }
            ans%=int(1e9+7);
        }
        return ans;
    }
};