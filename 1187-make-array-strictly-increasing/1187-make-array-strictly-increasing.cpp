class Solution {
public:
    int dp[2001][2001];
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        int n1 = arr1.size(), n2 = arr2.size(), ans;
        sort(arr2.begin(), arr2.end());
        memset(dp, -1, sizeof(dp));
        ans = helper(arr1, arr2, 0, n1, n2);
        return ans > n1? -1 : ans;
    }

    int helper(vector<int> &arr1, vector<int> &arr2, int idx, int &n1, int &n2){
        if( idx == n1 ){
            return 0;
        }
 
        int prev = idx==0? -1 : arr1[idx-1], temp;
        int i = upper_bound(arr2.begin(), arr2.end(), prev) - arr2.begin();

        if( dp[idx][i] == -1 ){
            dp[idx][i] = 2001;
            
            if( idx == 0 || arr1[idx] > arr1[idx-1] ){
                dp[idx][i] = min(dp[idx][i], helper(arr1, arr2, idx+1, n1, n2));
            }

            if( i < n2 ){
                temp = arr1[idx], arr1[idx] = arr2[i];
                dp[idx][i] = min(dp[idx][i], helper(arr1, arr2, idx+1, n1, n2) + 1);
                arr1[idx] = temp;
            }
        }

        return dp[idx][i];
    }
};