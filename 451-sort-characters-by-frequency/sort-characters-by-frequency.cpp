class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> mpp;
        priority_queue<pair<int,char>> pq;
        for(auto c:s){
            mpp[c]++;
        }
        for(auto it:mpp){
            pq.push({it.second,it.first});
        }
        string ans = "";
       while(!pq.empty()){
        int n = pq.top().first;
        char c = pq.top().second;
        pq.pop();
        for(int i=0;i<n;i++){
            ans += c;
        }
       }

        // reverse(ans.begin(),ans.end());

        return ans;
    }
};