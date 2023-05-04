class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        unordered_map<int, int> mp;
        int diff = INT_MAX;
        for(int i = 0; i < cards.size(); i++){
            if(mp.find(cards[i]) != mp.end()){
                diff = min(diff, i - mp[cards[i]]);
            }
            mp[cards[i]] = i;
        }
        return (diff == INT_MAX)? -1 : diff+1;
    }
};