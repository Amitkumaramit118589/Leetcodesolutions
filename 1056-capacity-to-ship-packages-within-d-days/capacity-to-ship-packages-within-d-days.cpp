class Solution {
public:
    int find_day(int capacity,vector<int>arr){
        int count=0;
        int days=0;
        for(int i=0;i<arr.size();i++){
            count+=arr[i];
             if(count==capacity){
                days++;
                count=0;
             }
             else if(count>capacity){
               days++;
               count=arr[i];
             }
             
        }
        if (count > 0) days++;
        return days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int sum=0;
        int n=weights.size();
        for(int j=0;j<n;j++){
            sum+=weights[j];
        }
        
        int st = *max_element(weights.begin(), weights.end());
        int end= sum;
        int mid=(st+end)/2;
        while(st<=end){
            mid=(st+end)/2;
            if(find_day(mid,weights)<=days) end=mid-1;
            else{
                st=mid+1;
            }
        }
        return st;
    }
};