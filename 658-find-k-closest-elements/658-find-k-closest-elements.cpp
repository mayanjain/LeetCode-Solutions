class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        auto it=upper_bound(arr.begin(),arr.end(),x)-arr.begin();
        int i=it-1,j=it;
        vector<int> ans;
        while(k--){
            if(i>=0 && j<arr.size()){
                if(abs(arr[i]-x)<=abs(arr[j]-x)){
                    ans.push_back(arr[i--]);
                }
                else{
                    ans.push_back(arr[j++]);
                }
            }
            else if(i>=0){
                ans.push_back(arr[i--]);
            }
            else{
                ans.push_back(arr[j++]);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};