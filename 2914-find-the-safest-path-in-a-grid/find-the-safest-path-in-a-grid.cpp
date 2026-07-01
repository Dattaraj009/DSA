class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int,pair<int,int>>> q;
        vector<vector<int>> store(n,vector<int>(n,0));
        vector<vector<int>> vis(n,vector<int>(n,0));
        vector<vector<int>> vis1(n,vector<int>(n,0));
        priority_queue<pair<int,pair<int,int>>> pq;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    q.push({0,{i,j}});
                    vis[i][j] = 1;
                }
            }
        }
        int dr[] = {0,+1,0,-1};
        int dc[] = {+1,0,-1,0};
        while(!q.empty()){
            int dist = q.front().first;
            int r = q.front().second.first;
            int c = q.front().second.second;
            q.pop();
            for(int i=0;i<4;i++){
                int nr = r + dr[i];
                int nc = c + dc[i];
                if(nr < n && nr >= 0 && nc < n && nc >= 0 && !vis[nr][nc]){
                    vis[nr][nc] = 1;
                    q.push({dist+1,{nr,nc}});
                    store[nr][nc] = dist+1;
                }
            }
        }

        if(store[0][0] == 0 || store[n-1][n-1]==0) return 0;
        pq.push({store[0][0],{0,0}});
        vis1[0][0] = 1;
        int mini = INT_MAX;
        while(!pq.empty()){
            int dist =  pq.top().first;
            int r = pq.top().second.first;
            int c = pq.top().second.second;
             mini = min(mini,dist);
            pq.pop();
            if(r==n-1 && c==n-1) return mini;
            for(int i=0;i<4;i++){
                int nr = r + dr[i];
                int nc = c + dc[i];
                if(nr < n && nr >= 0 && nc < n && nc >= 0 && !vis1[nr][nc]){
                    vis1[nr][nc] = 1;
                   pq.push({store[nr][nc],{nr,nc}});
                }
            }
        }

        return -1;
    }
};