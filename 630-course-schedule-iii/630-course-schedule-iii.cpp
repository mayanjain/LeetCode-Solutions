class Solution {
public:
    static bool cmp(vector<int>& a,vector<int>& b){
        return a[1]<b[1];
    }
    
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(),courses.end(),cmp);
        priority_queue<int> pq;
        int last=0,ans=0;
        for(int i=0 ; i<courses.size() ; i++){
            if(courses[i][0]+last<=courses[i][1]){
                pq.push(courses[i][0]);
                last+=courses[i][0];
                ans++;
            }
            else{
                if(pq.size()){
                    auto top=pq.top();
                    if(top>courses[i][0]){
                        pq.pop();
                        pq.push(courses[i][0]);
                        last=last-top+courses[i][0];
                    }
                }
            }
        }
        return ans;
    }
};