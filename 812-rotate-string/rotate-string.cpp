class Solution {
public:
    bool rotateString(string s, string goal) {
        string store = s+s;
        if(store.find(goal) != string::npos){
            return true;
        }

        return false;
    }
};