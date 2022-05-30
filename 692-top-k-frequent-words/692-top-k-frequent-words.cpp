class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string,int> mp;
        for(auto& i:words){
            mp[i]++;
        }
        map<int,multiset<string>> freq;
        for(auto& i:mp){
            freq[i.second].insert(i.first);
        }
        vector<string> v;
        for(int i=500 ; i>=0 && k ; i--){
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