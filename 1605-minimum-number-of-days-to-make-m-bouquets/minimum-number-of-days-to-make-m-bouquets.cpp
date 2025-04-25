class Solution {
public:
    int help(vector<int>v,int k,int day){
         int count=0;
         int cons_cnt=0;
         for(int i=0;i<v.size();i++){
            if(v[i]<=day){
                cons_cnt++;
            }
            else{
                cons_cnt=0;
            }

            if(cons_cnt==k){
                count++;
                cons_cnt=0;
            }
           
         } 
         return count;
    }
    int minDays(vector<int>& arr, int m, int k) {
        int n=arr.size();
        int max=-1;
        int ans=-1;
        for(int i=0;i<n;i++){
            if(max<arr[i])max=arr[i];
        }
        //apply binary search
        int st=1;
        int end=max;
        int mid=(st+end)/2;
        while(st<=end){
            mid=(st+end)/2;
            if(help(arr,k,mid)>=m){
                ans=mid;
                end=mid-1;
            }
            else st=mid+1;
        }
        return ans;
    }
};