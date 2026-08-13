class Solution {
public:
    double solve(vector<int>& piles,int mid){
         int n = piles.size();
         double cnt = 0;
         for(int i=0;i<n;i++){
            cnt += ceil((double)piles[i]/mid);
           
         }

         return cnt;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
       
        int high = *max_element(piles.begin(),piles.end());
        int low = 0;
        while(low<high){
            int mid = (low+high) / 2;
            if(solve(piles,mid)<=h){
               high = mid;
            }
            else{
                low = mid+1;
            }
        }

        return low;
    }
};