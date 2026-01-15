class Solution {
    public int[] findMissingAndRepeatedValues(int[][] grid) {
        
        int n= grid.length;
        int m= grid[0].length;
        int[] arr= new int[(m*n)+1];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
               arr[grid[i][j]]++;
            }
        }
        int a=-1,b=-1;
        for(int i=1;i<=m*n;i++){
           if(arr[i]==0) b=i;
           else if(arr[i]==2) a=i;
           else{}
        }
        return new int[]{a, b};

    }
}