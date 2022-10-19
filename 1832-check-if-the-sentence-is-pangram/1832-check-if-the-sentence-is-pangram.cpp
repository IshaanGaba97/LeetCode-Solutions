class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<int> check(26);
        for(int i = 0; i < sentence.size(); i++){
            check[sentence[i]-'a']++;
        }
        for(int i = 0; i < 26; i++){
            if(check[i] < 1){
                return false;
            }
        }
        return true;
    }
};