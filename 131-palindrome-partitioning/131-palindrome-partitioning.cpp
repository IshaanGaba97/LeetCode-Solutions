class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> path;
        func(0, s, path, res);
        return res;
    }
    
    void func(int index, string s, vector<string>& path, vector<vector<string>>& res){
        if(index == s.size()){    //last partition
            res.push_back(path);
            return;
        }
        for(int i = index; i < s.size(); i++){  //checking index-i palindrome
            if(isPalindrome(index, i , s)){
                path.push_back(s.substr(index, i-index+1));
                func(i+1, s, path, res);
                path.pop_back();      //backtrack
            }
        }
    }
    bool isPalindrome(int start, int end, string s){
        while(start <= end){
            if(s[start++] != s[end--])
                return false;
        }
        return true;
    }
};