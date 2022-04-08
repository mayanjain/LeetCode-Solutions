class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        priority_queue<int,vector<int>, greater<int>> pq;
        int ans=0,i=0,n=events.size();
        sort(events.begin(),events.end());
        for(int d=1 ; d<=1e5 ; d++){
            while(pq.size() && pq.top()<d)pq.pop();
            while(i<n && events[i][0]==d)pq.push(events[i++][1]);
            if(pq.size()){
                pq.pop();
                ans++;
            }
        }
        return ans;
    }
};