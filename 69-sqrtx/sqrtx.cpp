class Solution {
public:
    int mySqrt(int x) {
        if(x==1) return 1;
        if(x==0) return 0;
        int n = 0;
        for(double i=0;i<=x/2;i++){
            if(i*i <= x && (i+1)*(i+1)> x){
                return i;
            }
        }
        return -1;
    }
};