class Solution {
public:
    void bfs(int r,int c,vector<vector<char>>& grid,vector<vector<int>>& vis){
        int n = grid.size();
        int m = grid[0].size();
        vis[r][c] = 1;
        queue<pair<int,int>> q;
        q.push({r,c});
        int dr[] = {0,+1,0,-1};
        int dc[] = {+1,0,-1,0};
        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            for(int k=0;k<4;k++){
                int nr = i + dr[k];
                int nc = j + dc[k];

                if(nr < n && nr >= 0 && nc < m && nc >=0 && grid[nr][nc] == '1' && !vis[nr][nc]){
                    vis[nr][nc] = 1;
                    q.push({nr,nc});
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0;
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
              if(grid[i][j]=='1' && !vis[i][j]){
                 bfs(i,j,grid,vis);
                 cnt++;
              }
            }
        }

        return cnt;
    }
};