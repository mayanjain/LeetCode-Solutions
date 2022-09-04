class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meet) {
        int st=0,k=meet.size();
        sort(meet.begin(),meet.end());
        set<int> rooms;
        map<int,int> ans;
        priority_queue<pair<long,int>> used;
        for(int i=0 ; i<n ; i++)rooms.insert(i);
        for(long time=0 ; st!=k; time++){
            while(used.size() && -used.top().first<=time){
                rooms.insert(-used.top().second);
                used.pop();
            }
            while(st<k && rooms.size() && meet[st][0]<=time){
                auto rom=*rooms.begin();
                ans[rom]++;
                rooms.erase(rom);
                used.push({-(time+meet[st][1]-meet[st++][0]),-rom});
            }
            if(rooms.size()==0){
                time=-used.top().first-1;
            }
            else if(st<k && meet[st][0]>time){
                time=meet[st][0]-1;
            }
        }
        int res=0;
        for(int i=0 ; i<n ; i++){
            if(ans[i]>ans[res]){
                res=i;
            }
        }
        return res;
    }
};