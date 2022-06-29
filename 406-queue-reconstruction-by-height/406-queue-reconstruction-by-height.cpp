class Solution {
public:
    static bool cmp(vector<int>& v,vector<int>& z){
        return v[0]==z[0]?v[1]>z[1]:v[0]<z[0];
    }
    
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        vector<vector<int>> ans(people.size());
        sort(people.begin(),people.end(),cmp);
        for(int i=0 ; i<ans.size() ; i++){
            int j=0,cnt=0;
            for(j ; j<ans.size() ; j++){
                if(!ans[j].size()){
                    if(cnt==people[i][1])break;
                    cnt++;
                }
            }
            ans[j]=people[i];
        }
        return ans;
    }
};