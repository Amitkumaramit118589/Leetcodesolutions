class Solution {
    void setcolumn(int[][] matrix , int idx){
        for(int i=0;i<matrix.length;i++){
            if(matrix[i][idx]!=0) matrix[i][idx]=Integer.MAX_VALUE-10;
        }
    }
    void setrow(int[][] matrix , int idx){
        for(int i=0;i<matrix[0].length;i++){
            if(matrix[idx][i]!=0) matrix[idx][i]=Integer.MAX_VALUE-10;
        }
    }
    public void setZeroes(int[][] matrix) {
    
        for(int i=0;i<matrix.length;i++){
            for(int j=0;j<matrix[0].length;j++){
                if(matrix[i][j]==0){
                    setrow(matrix,i);
                    setcolumn(matrix,j);
                }
            }
        }
         for(int i=0;i<matrix.length;i++){
            for(int j=0;j<matrix[0].length;j++){
                if(matrix[i][j]==Integer.MAX_VALUE-10){
                    matrix[i][j]=0;
                }
            }
        }

        
    }
}