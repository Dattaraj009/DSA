class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
                          int k) {
        vector<pair<int, int>> adj[n];
        for (auto it : flights) {
            adj[it[0]].push_back({it[1], it[2]});
        }
        vector<int> dis(n, 1e9);
         dis[src] = 0;
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
                       greater<tuple<int, int, int>>>
            pq;
        int ans = INT_MAX;
        pq.push({0, 0, src}); // wt,k,src
        while (!pq.empty()) {
            auto [t,wt, node] = pq.top();
            pq.pop();

            for (auto it : adj[node]) {
                int adjnode = it.first;
                int adjwt = it.second;
                if (t <= k && dis[adjnode] >= adjwt + wt) {
                    pq.push({ t + 1, adjwt + wt,adjnode});
                    // vis[adjnode] = 1;
                    dis[adjnode] = adjwt + wt;
                }
            }
        }

        if (dis[dst]==1e9)
            return -1;
        return dis[dst];
    }
};