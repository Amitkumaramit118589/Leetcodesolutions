class Solution {
public:
    void rowchange(vector<vector<int>> &arr,int i){
        for(int k=0;k<arr[0].size();k++){
            if(arr[i][k]!=0)arr[i][k]=INT_MAX-10;
            
        }
    }
    void colmchange(vector<vector<int>> &arr,int j){
        for(int k=0;k<arr.size();k++){
           if(arr[k][j]!=0) arr[k][j]=INT_MAX-10;
        }
    }
    void setZeroes(vector<vector<int>>& matrix) {
        
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]==0){
                    rowchange(matrix,i);
                    colmchange(matrix,j);
                }
            }
        }
      for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]==INT_MAX-10){
                    matrix[i][j]=0;
                }
            }
        }
    
        
    }
};