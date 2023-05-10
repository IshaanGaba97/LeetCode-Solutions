class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int ans=0;
        int n=piles.size();
        sort(piles.begin(),piles.end());
        int i=0, j=n-2, k=n-1;
        while(i<j){
            ans = ans+piles[j];
            j=j-2;
            k=k-2;
            i=i+1;
        }
        return ans;
    }
};