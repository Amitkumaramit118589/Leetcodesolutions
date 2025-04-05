class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>ans;
        int top=0,bottom=matrix.size()-1;
        int left=0,right=matrix[0].size()-1;
        while(top<=bottom && left<=right){
            //top
            for(int i=left;i<=right;i++){
                ans.push_back(matrix[top][i]);
            }
             top++;
            //right
            for(int j=top;j<=bottom;j++){
                ans.push_back(matrix[j][right]);
            }
            right--;
            //bottom
            if(top<=bottom){
                    
                for(int k=right;k>=left;k--){
                    ans.push_back(matrix[bottom][k]);
                }
                 bottom--;
            }
            //left
            if(left<=right){

                for(int l=bottom;l>=top;l--){
                    ans.push_back(matrix[l][left]);
                }
                left++;
            }
        }
        return ans;
    }
};