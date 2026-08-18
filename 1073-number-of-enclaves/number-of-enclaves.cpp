class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            if(!vis[i][m-1] && grid[i][m-1]==1){
                q.push({i,m-1});
                vis[i][m-1] = 1;
            }
            if(!vis[i][0] && grid[i][0]==1){
                q.push({i,0});
                vis[i][0] = 1;
            }
        }
        for(int j=0;j<m;j++){
            if(!vis[0][j] && grid[0][j]==1){
                q.push({0,j});
                vis[0][j] = 1;
            }
            if(!vis[n-1][j] && grid[n-1][j]==1){
                q.push({n-1,j});
                vis[n-1][j] = 1;
            }
        }
        int dr[] = {0,+1,0,-1};
        int dc[] = {+1,0,-1,0};
        while(!q.empty()){
            auto [r,c] = q.front();
            grid[r][c] = 0;
            q.pop();
            for(int j=0;j<4;j++){
                int nr = r+dr[j];
                int nc = c+dc[j];
                if(nr<n && nc < m  && nr>=0 && nc >=0 && !vis[nr][nc] && grid[nr][nc]==1){
                    vis[nr][nc]=1;
                    q.push({nr,nc});
                }
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};