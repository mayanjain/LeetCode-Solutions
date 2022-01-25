class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n=arr.size();
        if(n<3)return 0;
        int i=1;
        while(i<n && arr[i]>arr[i-1]){
            i++;
        }
        if(i==n || i==1)return 0;
        for(i ; i<n ; i++){
            if(arr[i]>=arr[i-1])return  0;
        }
        return 1;
    }
};