class Solution {
public:
    int minSetSize(vector<int>& arr) {
        
        int sz = 0;
        int n = arr.size();
        int tempsize = n;
        
        priority_queue<pair<int, int>> pq;
        unordered_map<int, int> mp;
        for(int i = 0; i < n; i++){
            mp[arr[i]]++;
        }
        for(auto it : mp){
            pq.push({it.second, it.first});
        }
        while(tempsize > n/2 && !pq.empty()){
            int freq = pq.top().first;
            int ele = pq.top().second;
            pq.pop();
            tempsize -= freq;
            sz++;
        }
        return sz;
    }
};