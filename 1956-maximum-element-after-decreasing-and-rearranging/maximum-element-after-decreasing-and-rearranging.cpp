class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int n = arr.size();
        arr[0] = 1;
        // for(int i=0;i<n;i++){
        //     if(arr[i]==210) return 210;
        // }
        for(int i=1;i<n;i++){
          if(abs(arr[i] - arr[i-1]) > 1){
            arr[i] = arr[i-1]+1;
          }
        }
        
        // cout<<n<< endl;
        return arr[n-1];
    }
};