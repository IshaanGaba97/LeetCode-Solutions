class Solution {
public:
int n1,n2;
int f(int i,int count,vector<vector<int>>& requests,vector<int>&mp){
    if(i>=n1){
        for(int i=0;i<n2;i++){
            if(mp[i]!=0){
                return 0;
            }
        }
        return count;
    }
    int ntake=f(i+1,count,requests,mp);
    mp[requests[i][0]]--;
    mp[requests[i][1]]++;
    int take=f(i+1,count+1,requests,mp);
    mp[requests[i][0]]++;
    mp[requests[i][1]]--;
    
    return max(take,ntake);
}
    int maximumRequests(int n, vector<vector<int>>& requests) {
        n1=requests.size();
        n2=n;
        vector<int>mp(n,0);
        return f(0,0,requests,mp);
    }
};