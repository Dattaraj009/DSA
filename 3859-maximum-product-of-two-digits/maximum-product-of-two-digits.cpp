class Solution {
public:
    int maxProduct(int n) {
        if(n <= 10) return 0;
        vector<int> store;
        while(n>0){
           store.push_back(n%10);
           n = n/10;
        }
        sort(store.begin(),store.end());
        int size = store.size();
        return store[size-1]*store[size-2];
    }
};