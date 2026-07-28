class Solution {
public:
    int find(vector<int>& ldr,int node){
        if(ldr[node]!=node){
            ldr[node]=find(ldr,ldr[node]);
        }
        return ldr[node];
    }
    void join(vector<int>& ldr,int left,int right){
        ldr[find(ldr,left)]=find(ldr,right);
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int N=isConnected.size();
        vector<int> ldr(N);
        for(int i=0;i<N;i++){
            ldr[i]=i;
        }
        for(int row=0;row<N;row++){
            for(int col=0;col<N;col++){
                if(isConnected[row][col]==1){
                    join(ldr,row,col);
                }
            }
        }
        int ldrs=0;
        for(int i=0;i<N;i++){
            if(find(ldr,i)==i){
                ldrs++;
            }
        }
        return ldrs;
    }
};