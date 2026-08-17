class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(auto c:s){
          if(c=='(' || c=='{' || c=='['){
            st.push(c);
          }
          else{
            if(st.empty()) return false;
            else{
                char k = st.top();
                st.pop();
                if((k=='(' && c!=')') || (k=='{' && c!='}') || (k=='[' && c!=']')){
                    return false;
                }
                else{
                    continue;
                }
            }
          }
        }

        return st.size()==0;
    }
};