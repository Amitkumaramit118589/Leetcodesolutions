class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int st=0;
        int n=mat.size();
        int m=mat[0].size();
        int end=m-1;
        int mid=(st+end)/2;
        while(st<=end){
            int mid=(st+end)/2;
            int maxrow=0;
            for(int i=0;i<n;i++){
                if(mat[i][mid]>mat[maxrow][mid]){
                   maxrow=i;      
                }
            }
            int curr = mat[maxrow][mid];
            int left = (mid - 1 >= 0) ? mat[maxrow][mid - 1] : -1;
            int right = (mid + 1 < m) ? mat[maxrow][mid + 1] : -1;
            if(curr>=left && curr>=right) return {maxrow,mid};
            else if(right>curr) st=mid+1;
            else end=mid-1;
        }
        return {-1,-1};
    }
};