class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        long n=arr.size(),ans=0;
        sort(arr.begin(),arr.end());
        for(int i=0 ; i<n ; i++){
            int l=i+1,h=n-1;
            while(l<h){
                long sum=arr[i]+arr[l]+arr[h];
                if(sum==target){
                    if(arr[l]==arr[h]){
                        long k=h-l;
                        ans+=(k*(k+1))/2;
                        break;
                    }
                    else{
                    long first=1,second=1;
                        while(arr[l]==arr[l+1]){
                            l++;
                            first++;
                        }
                        while(arr[h]==arr[h-1]){
                            second++;
                            h--;
                        }
                        l++;h--;
                        ans+=first*second;
                    }
                }
                else if(sum<target)l++;
                else h--;
                ans%=int(1e9+7);
            }
            ans%=int(1e9+7);
        }
        return ans;
    }
};