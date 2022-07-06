class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s==t) return true;
        if (s.size()!=t.size()) return false;
        unordered_map <char, int> umap;
        for (int i=0; i<s.size(); i++) {
            umap[s[i]]++;
            umap[t[i]]--;
        }
        for (auto it: umap) {
            if (it.second != 0) return false;
        }
        return true;
    }
};