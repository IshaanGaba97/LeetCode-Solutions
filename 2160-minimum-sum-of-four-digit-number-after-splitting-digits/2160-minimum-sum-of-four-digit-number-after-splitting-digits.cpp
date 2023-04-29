class Solution {
public:
    int minimumSum(int num) {
        string s = to_string(num);
        sort(s.begin(), s.end());
        // s[0] , s[1], s[2], s[3];
        int a = (s[0]-'0')*10 + (s[2]-'0');
        int b = (s[1]-'0')*10 + (s[3]-'0');
        return a + b;
        }
};