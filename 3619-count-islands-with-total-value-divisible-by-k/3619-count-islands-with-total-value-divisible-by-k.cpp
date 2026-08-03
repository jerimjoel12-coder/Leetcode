class Solution {
public:
    int dir1[4]={0,0,-1,1};
    int dir2[4]={1,-1,0,0};
    bool dfs(vector<vector<int>>& grid,vector<vector<int>>& vis,int R,int C,int row,int col,int k,long long int &sum)
    {
        vis[row][col]=1;
        for(int way=0;way<4;way++)
        {
            int adjcol=col+dir1[way];
            int adjrow=row+dir2[way];

            if(adjrow>=0 && adjcol>=0 && adjcol<C && adjrow<R && vis[adjrow][adjcol]==0 && grid[adjrow][adjcol]!=0)
            {
                sum+=grid[adjrow][adjcol];
                vis[adjrow][adjcol]=1;
                dfs(grid,vis,R,C,adjrow,adjcol,k,sum);
            }
        }
        
            if(sum%k==0) return true;
        
        return false;

    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int count=0;
        int R=grid.size(),C=grid[0].size();

        vector<vector<int>>vis(R,vector<int>(C,0));
        

        for(int row=0;row<R;row++)
        {
            for(int col=0;col<C;col++)
            {
                long long int sum=0;
                if(grid[row][col]!=0 && vis[row][col]==0)
                {
                    sum+=grid[row][col];
                    if(dfs(grid,vis,R,C,row,col,k,sum))
                    {
                        count++;
                    }
                }
            }
        }
        return count;
    }
};