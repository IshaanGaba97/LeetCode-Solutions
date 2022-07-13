class Solution {
public:
    bool isOperator(char c){
        return (c == '+' || c == '-' || c == '*' || c == '/');
    }
    int calculate(string s) {
        if(s.size() == 0){
        return 0;
        }
        stack<int> st;
        char prevSign = '+';
        int no = 0;
        int res = 0;
        for(int i = 0; i < s.size(); i++){
            if(isdigit(s[i]))
            no = 10*no + (s[i]-'0');
               
            if(isOperator(s[i]) || i == s.size()-1){
                if(prevSign == '+'){
                    st.push(no);
                } else if(prevSign == '-'){
                    st.push(-no);
                } else if(prevSign == '*'){
                    int num = st.top();
                    st.pop();
                    st.push(num*no);
                } else if(prevSign == '/'){
                    int num = st.top();
                    st.pop();
                    st.push(num/no);
                }
                no = 0;
                prevSign = s[i];
            }
        }
        while(!st.empty()){
            res = res + st.top();
            st.pop();
        }
        return res;
    }
};