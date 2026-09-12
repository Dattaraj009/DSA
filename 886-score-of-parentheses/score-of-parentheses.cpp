class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        int n = s.size();
        int score = 0;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                st.push(score);
                score = 0;
            }
            else{
                score = st.top() + max(score*2,1);
                st.pop();
            }
        }

        return score;
    }
};