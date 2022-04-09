class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(auto& i:nums)mp[i]++;
        multiset<int> pq;
        for(auto& i:mp){
            pq.insert(i.second);
            if(pq.size()>k)pq.erase(pq.begin());
        }
        vector<int> ans;
        for(auto& i:mp){
            if(pq.count(i.second))ans.push_back(i.first);
        }
        return ans;
    }
};