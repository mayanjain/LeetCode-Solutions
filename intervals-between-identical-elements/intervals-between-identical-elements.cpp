class Solution {
public:
    vector<long long> getDistances(vector<int>& arr) {
        unordered_map<int,int> count;
        unordered_map<int,int> last;
        vector<long long> ans(arr.size());
        for(int i=0 ; i<arr.size() ; i++){
            if(last.count(arr[i])){
                ans[i]=ans[last[arr[i]]]+(i-last[arr[i]])*count[arr[i]];
            }
            last[arr[i]]=i;
            count[arr[i]]++;
        }
        count.clear();
        last.clear();
        vector<long long> ans2(arr.size());
        for(int i=arr.size()-1 ; i>=0 ; i--){
            if(last.count(arr[i])){
                ans2[i]=ans2[last[arr[i]]]+(last[arr[i]]-i)*count[arr[i]];
                ans[i]+=ans2[i];
            }
            last[arr[i]]=i;
            count[arr[i]]++;
        }
        return ans;
    }
};