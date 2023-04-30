class Solution {
public:
    // same as max continous 1s
    int longestContinuousSubstring(string s) {
        int n = s.size();
        if(n==1) return 1;
        int ans = 1;
        int count = 1;
        for(int i = 1; i < n; i++){
            if(((s[i-1]-'a')+1 == (s[i]-'a'))){
                count++;
                ans = max(count, ans);
            } else {
                count = 1;
            }
        }
        return ans;
    }
};