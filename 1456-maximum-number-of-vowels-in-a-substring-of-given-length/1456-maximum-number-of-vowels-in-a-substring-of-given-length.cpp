class Solution {
public:
    int maxVowels(string s, int k) {
        int n = s.size(); 
        int vowelCount = 0;
        for(int i = 0; i < k; i++){     //firstWindow
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){
                vowelCount++;
            }
        }
        int ans = vowelCount;
        for(int i = 1; i < n-k+1; i++){
            char sinc = s[i+k-1];
            char sexc = s[i-1];
            if(sinc == 'a' || sinc == 'e' || sinc == 'i' || sinc == 'o' || sinc == 'u'){
                vowelCount++;
            }
            if(sexc == 'a' || sexc == 'e' || sexc == 'i' || sexc == 'o' || sexc == 'u'){
                vowelCount--;
            }
            ans = max(ans, vowelCount);
        }
        return ans;
    }
};