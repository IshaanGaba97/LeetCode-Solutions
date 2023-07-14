class Solution {
public:
    int longestSubsequence(vector<int>& nums, int difference) {
        
        int n = nums.size();

        int ans = 1;

        map<int,int>mpp;
        mpp[nums[0]] = 1;

        for(int i = 1;i<n;i++)
        {
            int maxi = 1;
           
               int x = nums[i]-difference;
               if(mpp.find(x)!=mpp.end())
               {
                 maxi = 1 + mpp[x];
               }
           
           if(mpp.find(x)==mpp.end()) mpp[nums[i]] =maxi;
           else mpp[nums[i]] = max(maxi,mpp[nums[i]]);

            ans = max(ans,maxi);
        }

        return ans;
    }
};