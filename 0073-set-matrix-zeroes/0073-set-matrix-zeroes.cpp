class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int R=matrix.size();
        int C=matrix[0].size();

        bool firrow=false;
        bool fircol=false;

        for(int col=0;col<C;col++){
            if(matrix[0][col]==0){
                firrow=true;
                break;
            }
        }

        for(int row=0;row<R;row++){
            if(matrix[row][0]==0){
                fircol=true;
                break;
            }
        }

        for(int row=1;row<R;row++){
            for(int col=1;col<C;col++){
                if(matrix[row][col]==0){
                    matrix[row][0]=0;
                    matrix[0][col]=0;
                }
            }
        }

        for(int row=1;row<R;row++){
            if(matrix[row][0]==0){
                for(int col=1;col<C;col++){
                    matrix[row][col]=0;
                }
            }
        }

        for(int col=1;col<C;col++){
            if(matrix[0][col]==0){
                for(int row=1;row<R;row++){
                    matrix[row][col]=0;
                }
            }
        }

        if(firrow){
            for(int col=0;col<C;col++){
                matrix[0][col]=0;
            }
        }

        if(fircol){
            for(int row=0;row<R;row++){
                matrix[row][0]=0;
            }
        }
}};