class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> s;
        for(int num : nums){
            s.insert(num);
        }
        int longestStreak = 0;
        for(int num : nums){
            if (!s.count(num-1)) {
                    int currentStreak = 1;
                    int currentElement = num;
                    while (s.count(currentElement+1)) {
                        currentStreak+=1;
                        currentElement+=1;
                    }
                    longestStreak = max(longestStreak, currentStreak);
            }
        }
    return longestStreak;
    }
};