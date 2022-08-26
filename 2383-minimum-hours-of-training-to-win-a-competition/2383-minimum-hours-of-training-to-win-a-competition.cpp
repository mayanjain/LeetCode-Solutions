class Solution {
public:
    int minNumberOfHours(int eng, int exp, vector<int>& energy, vector<int>& experience) {
        int ans=0;
        for(int i=0 ; i<energy.size() ; i++){
            if(energy[i]>=eng){
                ans+=energy[i]-eng+1;
                eng=energy[i]+1;
            }
            if(experience[i]>=exp){
                ans+=experience[i]-exp+1;
                exp=experience[i]+1;
            }
            exp+=experience[i];
            eng-=energy[i];
        }
        return ans;
    }
};