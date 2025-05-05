class Solution {
public:
    bool binarysearch(vector<int>arr,int target){
        int n=arr.size();
        int st=0;
        int end=n-1;
        while(st<=end){
            int mid=(st+end)/2;
            if(arr[mid]==target) return true;
            else if(arr[mid]>target) end=mid-1;
            else st=mid+1;
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        int st=0;
        int end=m-1;
        int mid=(st+end)/2;
        int row=-1;
        while(st<=end){
             mid=(st+end)/2;
             if (matrix[mid][0] <= target && target <= matrix[mid][n - 1]) {
                row = mid;
                break;
            }
            else if(matrix[mid][0]>target){
            //    bool check= binarysearch(matrix[mid],target);
            //    if(check==true) return true;
               end=mid-1;   
            } 
            else st=mid+1;
        }
        if(row==-1)return false;
       return binarysearch(matrix[mid],target);
       // return false;
    }
};