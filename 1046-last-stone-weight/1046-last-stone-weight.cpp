class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq(stones.begin(),stones.end());
        while(pq.size()>1){
            auto it=pq.top();pq.pop();
            auto it2=pq.top();pq.pop();
            pq.push(it-it2);
        }
        return pq.top();
    }
};