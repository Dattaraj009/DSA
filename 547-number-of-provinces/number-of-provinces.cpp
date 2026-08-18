class Solution {
public:
    void bfs(int node,vector<int> adj[],vector<int>& vis){
           vis[node] = 1;
           queue<int> q;
           q.push(node);
           while(!q.empty()){
            int val = q.front();
            q.pop();
            for(auto it:adj[val]){
                if(!vis[it]){
                    vis[it]=1;
                    q.push(it);
                }
            }
           }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> adj[n];
        int cnt = 0;
        vector<int> vis(n,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1){
                   adj[i].push_back(j);
                   adj[j].push_back(i);
                }
            }
        }
        // q.push(0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                bfs(i,adj,vis);
                cnt++;
            }
        }

        return cnt;
    }
};