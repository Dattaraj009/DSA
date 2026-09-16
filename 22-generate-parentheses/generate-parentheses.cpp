class Solution {
public:
    bool check(string store){
        int cnt = 0;
        for(auto ch:store){
            if(ch=='('){
                cnt++;
            }
            else{
                cnt--;
            }
            if(cnt < 0) return false;
        }

        return cnt==0;
    }
    void solve(int ind,int n,vector<string>& ans, string store){
        if(ind==n*2){
            if(check(store)){
                ans.push_back(store);
            }
            return;
        }
        if(ind > n*2) return; 
        store.push_back('(');
        solve(ind+1,n,ans,store);
        store.pop_back();
        store.push_back(')');
        solve(ind+1,n,ans,store);

    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string store="";
        solve(0,n,ans,store);
        return ans;

    }
};