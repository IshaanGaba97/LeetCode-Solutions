class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        stack<char> st;
        for(int i = 0; i < n; i++){
            if(s[i] == '(' || s[i] == '{' || s[i] == '['){
                st.push(s[i]);
            } else {
                if(st.empty()) 
                     return false;
                
                else if(s[i]==')'){
                    if(st.top() == '(') 
                        st.pop();
                    else return false;
                }
                else if(s[i]=='}'){
                    if(st.top() == '{') 
                    st.pop();
                    else return false;
                }
                else if(s[i]==']'){
                    if(st.top() == '[') 
                    st.pop();
                    else return false;
                }

            }
        }
        return st.empty();
    }
};