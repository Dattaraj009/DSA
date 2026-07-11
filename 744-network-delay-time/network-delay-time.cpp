class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>> adj[n+1];
        for(auto it:times){
            adj[it[0]].push_back({it[1],it[2]});
        }
        vector<int> dis(n+1,1e9);
        dis[0] = 0;
        dis[k] = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,k});
        while(!pq.empty()){
            auto [tw,node] = pq.top();
            pq.pop();
            for(auto it:adj[node]){
                int adjnode = it.first;
                int w = it.second;
                if(dis[adjnode] > w + tw){
                    dis[adjnode] = w+tw;
                    pq.push({w+tw,adjnode});
                }
            }
            
        }
        int maxi = INT_MIN;
        for(int i=1;i<=n;i++){
            if(dis[i]==1e9) return -1;
            maxi = max(maxi,dis[i]);
        }
        return maxi;
    }
};