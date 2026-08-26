class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        stack<string> st;
        int n = s.size();
        int i = 0;
        while(i<n){
            while(i<n && s[i]==' ') i++;
            string store = "";
            while(i<n && s[i] !=' '){
                store += s[i];
                i++;
            }
            if(store.size() != 0) st.push(store);
        }

        while(!st.empty()){
            ans += st.top();
            st.pop();
            if(!st.empty()) ans += ' ';
        }


        return ans;
        
    }
};