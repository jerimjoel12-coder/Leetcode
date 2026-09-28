class Solution {
public:
    int dfs(int ind,int k,int n,vector<int>& stones,vector<vector<int>>& vis,map<int,int>& mp){
        if(ind==n-1){
            return 1;
        }
        if(vis[ind][k]!=-1){
            return vis[ind][k];
        }
        for(int i=k-1;i<=k+1;i++){
            if(i<=0) continue;
            int next=stones[ind]+i;
            if(mp.contains(next)){
                int nextind=mp[next];
                if(dfs(mp[next],i,n,stones,vis,mp)){
                   return vis[ind][k]=1;
                }
            }
        }
        vis[ind][k]=0;
        return 0;
    }
    bool canCross(vector<int>& stones) {
        int n=stones.size();
        vector<vector<int>> vis(n,vector<int>(n,-1));
        map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[stones[i]]=i;
        }
        return dfs(0,0,n,stones,vis,mp)==1;
    }
};