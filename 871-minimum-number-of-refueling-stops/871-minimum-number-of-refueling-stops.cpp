class Solution {
public:
    int minRefuelStops(int target, int fuel, vector<vector<int>>& s) {
        int ans=0,i=0;
        priority_queue<int> pq;
        for(ans ; fuel<target ; ans++){
            while(i<s.size() && s[i][0]<=fuel){
                pq.push(s[i++][1]);
            }
            if(!pq.size())return -1;
            fuel+=pq.top();
            pq.pop();
        }
        return ans;
    }
};