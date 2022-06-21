class Solution {
public:
    bool solve(int mid,int ladders,int bricks,vector<int>& heights){
        priority_queue<int> pq;
        for(int i=0 ; i<mid ; i++){
            if(heights[i]<heights[i+1])pq.push(heights[i+1]-heights[i]);
        }
        while(pq.size()){
            if(ladders){
                pq.pop();
                ladders--;
            }
            else{
                bricks-=pq.top();
                pq.pop();
            }
        }
        if(bricks>=0)return true;
        return false;
    }
    
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n=heights.size(),low=0,high=n-1,mid;
        while(high-1>low){
            mid=(high+low)/2;
            if(solve(mid,ladders,bricks,heights)){
                low=mid;
            }
            else high=mid-1;
        }
        for(int i=high ; i>=low ; i--){
            if(solve(i,ladders,bricks,heights))return i;
        }
        return -1;
    }
};