class Solution {
public:
    int maxProduct(int n) {
        if(n <= 10) return 0;
        int fmax = 0;
        int smax = 0;
        vector<int> store;
        while(n>0){
           store.push_back(n%10);
           n = n/10;
        }
        // sort(store.begin(),store.end());
        int size = store.size();
        int fInd = size;
        for(int i=0;i<size;i++){
            if(fmax < store[i]){
                smax = fmax;
                fmax = store[i];
                
            }
            else if(smax < store[i]){
                smax = store[i];
            }
        }
        // return store[size-1]*store[size-2];
        return fmax*smax;
        
    }
};