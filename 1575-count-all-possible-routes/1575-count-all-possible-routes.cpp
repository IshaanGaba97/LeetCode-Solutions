class Solution {
public:
const int MOD=1e9+7;
    int f(int i,vector<int>& locations, int finish, int &fuel,vector<vector<int>> &dp){
        // cout<<fuel<<endl;
        if(fuel<0){
            return 0;
        }
        if(dp[i][fuel]!=-1){
            return dp[i][fuel];
        }
        long long ans=0;
        if(i==finish){
            ans++;
            ans=ans%MOD;
            for(int j=0;j<locations.size();j++){
                if(i!=j){
                    fuel-=abs(locations[i]-locations[j]);
                    ans+=(long long)(f(j,locations,finish,fuel,dp))%MOD;
                    fuel+=abs(locations[i]-locations[j]);
                }
            
            }
        }
        else
        {
            for(int j=0;j<locations.size();j++){
                if(i!=j){
                   fuel-=abs(locations[i]-locations[j]);
                    ans+=(long long)(f(j,locations,finish,fuel,dp))%MOD;
                    fuel+=abs(locations[i]-locations[j]);
                }
            
            }
        }
        return dp[i][fuel]=ans%MOD;
    }
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        vector<vector<int>>dp(locations.size()+1,vector<int>(fuel+1,-1));
        return f(start,locations,finish,fuel,dp);
    }
};