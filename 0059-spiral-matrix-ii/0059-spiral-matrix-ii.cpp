class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n,vector<int>(n));
        int top=0,left=0,right=matrix[0].size()-1,bottom=matrix.size()-1,num=1;
        while(top<=bottom && right>=left){
            for(int i=left;i<=right;i++){
                matrix[top][i]=num;
                num+=1;
            }
            top+=1;
            for(int i=top;i<=bottom;i++){
                matrix[i][right]=num;
                num+=1;
            }
            right-=1;
            if(top<=bottom){
                for(int i=right;i>=left;i--){
                    matrix[bottom][i]=num;
                    num+=1;
                }
                bottom-=1;
            }
            if(left<=right){
                for(int i=bottom;i>=top;i--){
                    matrix[i][left]=num;
                    num+=1;
                }
                left+=1;
            }
        }
        return matrix;
    }
};