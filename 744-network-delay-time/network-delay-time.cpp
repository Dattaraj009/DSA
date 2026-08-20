class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>> adj[n+1];
        for(auto it:times){
            adj[it[0]].push_back({it[1],it[2]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,k});
        vector<int> dis(n+1,1e9);
        dis[0] = 0;
        dis[k] = 0;
        while(!pq.empty()){
            auto [w,node] = pq.top();
            pq.pop();
            for(auto it:adj[node]){
                int adjw = it.second;
                int adjnode = it.first;
                if(dis[adjnode] > adjw+w){
                    pq.push({adjw+w,adjnode});
                    dis[adjnode] = adjw+w;
                }
            }
        }
        int maxi = 0;
        for(int i=0;i<n+1;i++){
            if(dis[i]==1e9){
                return -1;
            }
            else{
                maxi = max(maxi,dis[i]);
            }
        }

        return maxi;
    }
};