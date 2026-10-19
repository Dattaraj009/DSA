class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int,int> mpp;
        vector<int> store;\
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(mpp.find(arr[i]) == mpp.end()){
                store.push_back(arr[i]);
                mpp[arr[i]] = 1;
            }
        }
        int nn = store.size();
        sort(store.begin(),store.end());
        for(int i=0;i<nn;i++){
            mpp[store[i]] = i+1;
        }

        for(int i = 0;i<n;i++){
            ans.push_back(mpp[arr[i]]);
        }

        return ans;
    }
};