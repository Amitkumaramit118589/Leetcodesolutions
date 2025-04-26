class Solution {
public:
    int divsum(vector<int>arr,int n){
        int sum=0;
        for(int i=0;i<arr.size();i++){
            int result = (arr[i] + n - 1) / n;  // Ceil division
            sum+=result;
        }
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n=nums.size();
        int st=1;
        int end=*max_element(nums.begin(),nums.end());
        int mid=(st+end)/2;
      
        while(st<=end){
            mid=(st+end)/2;
            if(divsum(nums,mid)<=threshold) end=mid-1;
            else{
                
                st=mid+1;
            }
        }
        return st;
    }
};