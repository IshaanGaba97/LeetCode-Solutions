class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        
        sort(begin(skill), end(skill));
        int l = 0;
        int r = skill.size()-1;
        int teamsize = skill[l] + skill[r];
        long long chem = skill[l] * skill[r];
        l++; r--;
        while(l < r){
            if(skill[l] + skill[r] == teamsize){
                chem = chem + (skill[l] * skill[r]);
            } else {
                return -1;
            }
            l++;
            r--;
        }
        return chem;
    }
};