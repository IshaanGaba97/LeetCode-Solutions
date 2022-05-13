class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& v) {
        int n = v.size();
        sort(v.begin(), v.end());
        set<vector<int>> ans;
        vector<vector<int>> res;
        
        if(n < 3){
            return res;
        }
        
        int cntZero = 0;
        
        for(auto &it : v){
            if(it == 0) cntZero++;
        }
        
        if(n == cntZero){
            res.push_back(vector<int>{0,0,0});
            return res;
        }
        
        for(int i=0;i<n-2;i++){
            int l = i+1, r = n-1;
            while(l < r){
                int sum = v[i]+v[l]+v[r];
                if(sum == 0){
                    ans.insert({v[i],v[l],v[r]});
                }
                if(sum < 0){
                    l++;
                }
                else{
                    r--;
                }
                
            }
        }
        
        vector<vector<int>>result(ans.begin(), ans.end());
        return result;
    }
};