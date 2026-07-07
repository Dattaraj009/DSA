class Solution {
public:
    long long sumAndMultiply(int n) {
        if(n==0) return 0;
        string store = to_string(n);
        string x = "";
        long long sum = 0;
        for(char c:store){
            if(c != '0'){
                x.push_back(c);
                sum += (c-'0');
            }
        }
        
        long long num = stoi(x);
        long long ans = sum * num;
        return ans;
    }
};