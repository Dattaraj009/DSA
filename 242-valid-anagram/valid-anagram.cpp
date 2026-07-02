class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        unordered_map<char,int> mpp1;
        unordered_map<char,int> mpp2;
        for(auto c:s){
            mpp1[c]++;
        }
        for(auto c:t){
            mpp2[c]++;
        }
        for(int i=0;i<s.size();i++){
            if(mpp2.find(s[i]) == mpp2.end() || mpp1[s[i]] != mpp2[s[i]]){
                return false;
            }
        }

        return true;
    }
};