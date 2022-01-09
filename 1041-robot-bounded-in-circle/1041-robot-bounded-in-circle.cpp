class Solution {
public:
    bool isRobotBounded(string ins) {
        vector<vector<int>> d={{0,1},{1,0},{0,-1},{-1,0}};
        int x=0,y=0,i=0;
        for(int j=0 ; j<ins.size() ; j++){
            if(ins[j]=='G'){
                x+=d[i][0];
                y+=d[i][1];
            }
            if(ins[j]=='L'){
                i=(i+1)%4;
            }
            if(ins[j]=='R'){
                i=(i+3)%4;
            }
        }
        return (i>0)||(x==0 && y==0);
    }
};