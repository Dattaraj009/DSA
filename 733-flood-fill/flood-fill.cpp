class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int origin = image[sr][sc];
        image[sr][sc] = color;
        queue<pair<int,int>> q;
        q.push({sr,sc});
        int dr[] = {0,+1,0,-1};
        int dc[] = {+1,0,-1,0};
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nr = r + dr[i];
                int nc = c + dc[i];
                 if(nr < n && nr >= 0 && nc < m && nc >=0 && image[nr][nc] == origin && !vis[nr][nc]){
                    vis[nr][nc] = 1;
                    image[nr][nc] = color;
                    q.push({nr,nc});
                }
            }
        }

        return image;
    }
};