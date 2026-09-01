class Solution {
public:
    int solve(int i,int j,int n,int m,vector<vector<int>>& grid,vector<vector<int>>& vis){
       if(i >= n || i < 0 || j >= m || j < 0) return 0;
       if(grid[i][j]==0) return 0;
       if(vis[i][j]==1) return 0;
       vis[i][j] = 1;
       int up = solve(i-1,j,n,m,grid,vis) + grid[i][j];
       int down = solve(i+1,j,n,m,grid,vis) + grid[i][j];
       int left = solve(i,j-1,n,m,grid,vis) + grid[i][j];
       int right = solve(i,j+1,n,m,grid,vis) + grid[i][j];
       vis[i][j] = 0;

       return max({up,down,left,right});
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int maxi = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] != 0){
                   maxi = max(maxi,solve(i,j,n,m,grid,vis));
                //    for(int r=0;r<n;r++){
                //     for(int c=0;c<m;c++){
                //         vis[r][c] = 0;
                //     }
                //    }
                }
            }
        }

        return maxi;
    }
};