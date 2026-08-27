class Solution {
public:
    int countVowelSubstrings(string word) {
        unordered_map<char, int> mpp{
            {'a', 0}, {'e', 0}, {'i', 0}, {'o', 0}, {'u', 0}};
        int cnt = 0;
        int n = word.size();
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(mpp.find(word[j]) != mpp.end()){
                    mpp[word[j]]++;
                    if(mpp['a']>=1 && mpp['e']>=1 && mpp['i']>=1 && mpp['o']>=1 && mpp['u']>=1){
                        cnt++;
                    }
                }
                else{
                      break;
                }
            }
            mpp['a']=0,mpp['e']=0,mpp['i']=0,mpp['o']=0,mpp['u']=0;
        }
       
        return cnt;
    }
};