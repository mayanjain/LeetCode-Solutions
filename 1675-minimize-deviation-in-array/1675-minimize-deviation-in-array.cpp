class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        priority_queue<int> pq;
        int mn=INT_MAX;
        for(auto& c:nums){
            if(c%2)c*=2;
            pq.push(c);
            mn=min(mn,c);
        }
        int ans=INT_MAX;
        while(pq.top()%2==0){
            auto c=pq.top();
            ans=min(ans,c-mn);
            mn=min(mn,c/2);
            pq.pop();
            pq.push(c/2);
        }
        return min(ans,pq.top()-mn);
    }
};