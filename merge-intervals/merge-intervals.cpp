class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<int> v;
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;
        int last=intervals[0][1];
        v.push_back(intervals[0][0]);
        for(int i=1 ; i<intervals.size() ; i++){
            if(last>=intervals[i][0]){
                last=max(last,intervals[i][1]);
            }
            else{
                v.push_back(last);
                ans.push_back(v);
                v.clear();
                v.push_back(intervals[i][0]);
                last=intervals[i][1];
            }
        }
        v.push_back(last);
        ans.push_back(v);
        return ans;
    }
};