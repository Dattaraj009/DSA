class Solution {
public:
    void solve(int ind,int t,vector<int>& store,vector<int>& s, int target,vector<vector<int>>& ans){
        if(t>target) return;
        if(t==target){
            ans.push_back(store);
            return;
        }
        int n = s.size();
        if(ind==n){
            if(t==target){
                ans.push_back(store);
                return;
            }
            else{
                return;
            }
        }
        for(int i=ind;i<n;i++){
            store.push_back(s[i]);
            solve(i,t+s[i],store,s,target,ans);
            store.pop_back();
        }

        return;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> store;
        solve(0,0,store,candidates,target,ans);
        return ans;
    }
};