class Solution {
public:
    long long solve(vector<int>& time,long long given){
        int n = time.size();
        long long total = 0;
        for(auto a:time){
          long long v = a;
          total += (given/v);
        }

        return total;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long low = 1;
        long long high = 1e14;
        // long long ans = 0;
        while(low<high){
            long long mid = (low+high) / 2;
            long long cnt = solve(time,mid);
            if(cnt >= totalTrips){
                high = mid;
                // ans = mid;
            }
            else{
                low = mid+1;
            }
        }

        return low;
    }
};