Find duplicate number -
​
brute force -
1.hashmaps O(N)
2. Sort and find two consecutive O(NlogN) -> (idx == idx+1)
​
unordered_map<int, int> mp;
for(int i = 0; i < nums.size(); i++){
mp[nums[i]]++;
}
int ans;
for(auto x : mp){
if(x.second > 1){
ans = x.first;
}
}
return ans;
Best Optimal Method ->
Linkedlist cycle method -> notes
​
​