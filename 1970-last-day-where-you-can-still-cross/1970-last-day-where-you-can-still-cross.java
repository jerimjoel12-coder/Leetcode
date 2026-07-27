class Solution {
    public int latestDayToCross(int R, int C, int[][] cells) {
        int[] ldr=new int[R*C+2];
        boolean[] water= new boolean[R*C+2];
        for(int i=0;i<R*C+2;i++){
            ldr[i]=i;
        }
        int days=0;
        int[][] diff={{-1,0},{0,-1},{0,1},{1,0},{1,1},{-1,-1},{1,-1},{-1,1}};

        for(int cell[]:cells){
            int row=cell[0],col=cell[1];
            row--;
            col--;
            int cur=row*C+col+1;
            water[cur]=true;
            for(int[] d:diff){
                int ar=row+d[0];
                int ac =col+d[1];
                
                if(ar>=0 && ar<R && ac>=0 && ac<C && water[ar*C+ac+1]){
                    join(ldr,cur,ar*C+ac+1);
                }
            }
            if(col==0){
                join(ldr,0,cur);
            }
            else if(col==C-1){
                join(ldr,cur,R*C+1);
            }
            if(find(ldr,0)==find(ldr,R*C+1)){
                break;
            }
            days++;
        }
        return days;
    }
    private void join(int[] ldr,int left,int right){
        if(find(ldr,left)!=find(ldr,right)){
            ldr[find(ldr, left)] = find(ldr, right);
        }
    }
    private int find(int[] ldr,int node){
        if(ldr[node]!=node){
            ldr[node]=find(ldr,ldr[node]);
        }
        return ldr[node];
    }
}