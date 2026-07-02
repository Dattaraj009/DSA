class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n = grid.size();
        int m = grid[0].size();
        priority_queue<tuple<int, int, int, int>, vector<tuple<int, int, int, int>>, 
        greater<tuple<int, int, int, int>>>pq;
        vector<vector<int>> vis(n,vector<int>(m,-1e9));
        // vector<vector<int>> dis(n,vector<int>(m,1e9));
        vis[0][0] = 1;
        if(grid[0][0] == 1) health--;
        pq.push({grid[0][0],0,0,health});
        int dr[] = {0,+1,0,-1};
        int dc[] = {+1,0,-1,0};
        while(!pq.empty()){
            auto[val,r,c,newhel] = pq.top();
            pq.pop();
            cout<<newhel<<endl;
            // if(newhel <= 0) return false;
            if(r==n-1 && c == m-1 && newhel > 0) {
                return true;
            }
            
            
            for(int i=0;i<4;i++){
                int nr = r + dr[i];
                int nc = c + dc[i];
                if(nr < n && nr >= 0 && nc < m && nc >= 0 && vis[nr][nc] < newhel - grid[nr][nc]){
                    if(grid[nr][nc] == 1){
                        pq.push({1,nr,nc,newhel-1});
                        vis[nr][nc] = newhel - grid[nr][nc];
                    }
                    else{
                        pq.push({0,nr,nc,newhel});
                        vis[nr][nc] = newhel - grid[nr][nc];
                    }
                }
            }
        }

        return false;
    }
};