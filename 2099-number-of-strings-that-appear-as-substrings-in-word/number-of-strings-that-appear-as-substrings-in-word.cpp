class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        
        int cnt = 0;
       
        
        // to check substring exist in string we can use string name.find(substring) != string:: npos
        // where string::npos is fix
        for(int i=0;i<patterns.size();i++){
           if(word.find(patterns[i]) != string::npos){
            cnt++;
           }
        }

        return cnt;
    }
};