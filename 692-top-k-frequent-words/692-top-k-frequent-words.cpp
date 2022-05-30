class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string,int> mp;
        for(auto& i:words){
            mp[i]++;
        }
        map<int,multiset<string>> freq;
        int mx=0;
        for(auto& i:mp){
            freq[i.second].insert(i.first);
            mx=max(i.second,mx);
        }
        vector<string> v;
        for(int i=mx ; i>=0 && k ; i--){
            if(freq.count(i)){
                while(freq[i].size() && k){
                    k--;
                    v.push_back(*freq[i].begin());
                    freq[i].erase(freq[i].begin());
                }
            }
        }
        return v;
    }
};