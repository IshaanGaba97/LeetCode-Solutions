class Solution {
public:
    string defangIPaddr(string address) {
        string ans;
        for(int i = 0; i < address.size(); i++){
            if(address[i] == '.'){
                ans += "[.]";
            } else {
                ans.push_back(address[i]);
            }
        }
        return ans;
    }
};