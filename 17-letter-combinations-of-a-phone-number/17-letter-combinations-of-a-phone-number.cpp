class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if(digits.size() == 0) return res;
        string op = "";
        func(0, digits, op, res);
        return res;
    }
    
vector<string> v={"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    void func(int ind, string digits, string op, vector<string>& res){ 
        
        if(ind == digits.size()){
            res.push_back(op);
            return;
        }
        string s = v[digits[ind] - '0'];
        for(int i = 0; i < s.size(); i++){
            op.push_back(s[i]);
            func(ind+1, digits, op, res);
            op.pop_back();
        }
    }
};