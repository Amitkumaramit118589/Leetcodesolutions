class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        
        int n=matrix.length-1;
        int m=matrix[0].length-1;
        if(n==0 && matrix[0][0]==target)return true;
        int i=0,j=m;
        while(i<=n && j>=0){
            if(matrix[i][j]==target) return true;
            else if(matrix[i][j]>target) j--;
            else{
               i++;
            }
            
        }
        return false;

    }
}