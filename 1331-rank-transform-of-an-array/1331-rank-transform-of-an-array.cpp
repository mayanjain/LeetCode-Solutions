class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        auto v=arr;
        sort(v.begin(),v.end());
        map<int,int> mp;
        for(int i=0,c=1 ; i<v.size() ; i++){
            if(!i || v[i]!=v[i-1])mp[v[i]]=c++;
        }
        for(auto& i:arr){
            i=mp[i];
        }
        return arr;
    }
};