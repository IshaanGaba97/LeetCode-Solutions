class Solution {
public:
    int lengthOfLastWord(string s) {
        int result = 0;
        for(int i = s.length()-1;i >= 0;i--){
            if(s[i] != ' '){
                result += 1;
            } else if(result){
                return result;
            }
        }
        return result;
    }
};