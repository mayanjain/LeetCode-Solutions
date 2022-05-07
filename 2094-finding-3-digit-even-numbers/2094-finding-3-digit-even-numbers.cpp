class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> ans;
        vector<int> mp(10);
        for(auto& i:digits)mp[i]++;
        for(int num=100 ; num<999 ; num+=2){
            vector<int> count(10);
            int tmp=num;
            while(tmp){
                count[tmp%10]++;
                tmp/=10;
            }
            ans.push_back(num);
            for(int i=0 ; i<10 ; i++){
                if(count[i]>mp[i]){
                    ans.pop_back();
                    break;
                }
            }
        }
        return ans;
    }
};