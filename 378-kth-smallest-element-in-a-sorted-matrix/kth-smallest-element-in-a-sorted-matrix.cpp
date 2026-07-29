class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        // priority_queue<int> pq;
        vector<int> size;
        int cnt = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                // pq.push(matrix[i][j]);
                size.push_back(matrix[i][j]);
            }
        }
        sort(size.begin(),size.end());
        return size[k-1];
        // while(!pq.empty()){
        //   cnt++;
        //   if(cnt==k){
        //     return pq.top();
        //   }
        //   pq.pop();
        // }
        // return -1;
    }
};