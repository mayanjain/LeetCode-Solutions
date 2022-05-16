class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int n=grid.size();
        q.push({0,0});
        int steps=1;
        while(q.size()){
            queue<pair<int,int>> pq;
            while(q.size()){
                auto x=q.front();
                int r=x.first,c=x.second;
                q.pop();
                if(r<0 || c<0 || r==n || c==n || grid[r][c])continue;
                if(r==n-1 && c==n-1)return steps;
                grid[r][c]=1;
                for(int i=-1 ; i<2 ; i++){
                    for(int j=-1 ; j<2 ; j++){
                        if(i!=0 || j!=0)pq.push({r+i,c+j});
                    }
                }
            }
            steps++;
            swap(q,pq);
        }
        return -1;
    }
};