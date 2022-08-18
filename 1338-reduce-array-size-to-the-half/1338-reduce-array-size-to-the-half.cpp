class Solution {
public:
    int minSetSize(vector<int>& arr) {
        map<int,int> mp;
        for(auto& i:arr)mp[i]++;
        priority_queue<int> pq;
        for(auto& i:mp){
            pq.push(i.second);
        }
        int ans=0,cur=0;
        while(2*cur<arr.size()){
            ans++;
            cur+=pq.top();
            pq.pop();
        }
        return ans;
    }
};