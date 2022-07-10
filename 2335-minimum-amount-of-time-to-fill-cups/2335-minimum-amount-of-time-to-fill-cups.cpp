class Solution {
public:
    int fillCups(vector<int>& amount) {
        priority_queue<int> pq;
        for(auto& i:amount){
            if(i)pq.push(i);
        }
        int ans=0;
        while(pq.size()>1){
            ans++;
            auto top=pq.top();pq.pop();
            auto stop=pq.top();pq.pop();
            if(top-1)pq.push(top-1);
            if(stop-1)pq.push(stop-1);
        }
        if(pq.size())ans+=pq.top();
        return ans;
    }
};