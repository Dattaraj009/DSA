class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int> mpp;
        unordered_map<char,int> mpp1;
        int n1 = s1.size();
        for(int i=0;i<n1;i++){
            mpp[s1[i]]++;
        }
        int n2 = s2.size();
        int r=0;
        int cnt =0;
        mpp1 = mpp;
        while(r<n2){
           int p = 0;
           if(mpp1.find(s2[r]) != mpp1.end()){
            p = r;
            while(r<n2 && mpp1.find(s2[r]) != mpp1.end()){

                mpp1[s2[r]]--;
                if(mpp1[s2[r]]==0) mpp1.erase(s2[r]);

                cnt++;
                if(cnt==n1) return true;
                r++;
            }
            r = p;
           }
           mpp1 = mpp;
           cnt = 0;
           r++;
        }

        return false;
    }
};