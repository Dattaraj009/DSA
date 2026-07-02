class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string,vector<string>> mpp;
        for(int i=0;i<strs.size();i++){
            string s = strs[i];
            string temp = s;
            sort(temp.begin(),temp.end());
            mpp[temp].push_back(s);
        }
        for(auto it:mpp){
            ans.push_back(it.second);
        }

        return ans;
    }
};