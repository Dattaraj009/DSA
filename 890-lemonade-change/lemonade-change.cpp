class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        unordered_map<int,int> mpp{
            {5,0},
            {10,0},
            {20,0}
        };
        // sort(bills.begin(),bills.end());
        for(int i=0;i<bills.size();i++){
            if(bills[i]==5){
                mpp[5]++;
            }
            else if(bills[i]==10){
                if(mpp[5] != 0){
                    mpp[5]--;
                    mpp[10]++;
                }
                else{
                    return false;
                }
            }
            else if(bills[i]==20){
                if(mpp[10] != 0 && mpp[5] != 0){
                    mpp[10]--;
                    mpp[5]--;
                }
                else if(mpp[5] >= 3){
                    mpp[5] -= 3;
                    mpp[20]++;
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
};