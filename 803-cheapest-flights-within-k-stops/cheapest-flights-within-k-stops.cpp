class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> adj[n];
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>, greater<tuple<int,int,int>> > pq;
        for(auto it:flights){
            adj[it[0]].push_back({it[1],it[2]});
        }
        vector<int> dist(n,1e9);
        dist[src] = 0;
        
        pq.push({0,src,0});
        while(!pq.empty()){
            auto [steps, node,sum] = pq.top();
            pq.pop();
            // if(steps > k) continue;
            for(auto it:adj[node]){
                int adjnode = it.first;
                int w = it.second;
                if(steps <= k && dist[adjnode] > w+sum){
                    dist[adjnode] = w+sum;
                    pq.push({steps+1,adjnode,w+sum});
                }
            }
        }
        if(dist[dst]==1e9) return -1;
        return dist[dst];
    }
};