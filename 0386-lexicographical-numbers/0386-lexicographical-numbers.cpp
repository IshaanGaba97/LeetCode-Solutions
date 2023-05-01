class Solution {
public:
    void f(int n, int i, vector<string> &v){
        if(n+1==i) return;
        v.push_back(to_string(i));
        f(n, i+1, v);
    }
    vector<int> lexicalOrder(int n) {
        vector<string> v;
        f(n, 1, v);
        sort(v.begin(), v.end());
        vector<int> ans;
        for(int i = 0; i < v.size(); i++){
            int temp = stoi(v[i]);
            ans.push_back(temp);
        }
        return ans;
    }
};