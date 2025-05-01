class Solution {
public:
    int help(vector<int>arr,int sum){
        int tempsum=0;
        int count=1;
        for(int i=0;i<arr.size();i++){
            if(sum>=tempsum+arr[i]) tempsum+=arr[i];
            else{
                tempsum=arr[i];
                count++;
            }
        }
        return count;

    }
    int splitArray(vector<int>& nums, int k) {
        int sum= accumulate(nums.begin(),nums.end(),0);
        int maxm= *max_element(nums.begin(),nums.end());
        int st=maxm;
        int end= sum;
        int mid=(st+end)/2;
        while(st<=end){
            mid=(st+end)/2;
            if(help(nums,mid)<=k) end=mid-1;
            else st=mid+1;
        }
     return st;
        
    }
};