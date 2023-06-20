class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = size(nums);
        
        vector<int> ans(n,-1);
        
        int i=0,j=0,x = 2*k+1;
        long long sum = 0;

        while(j<n)
        {
            sum += nums[j];

            if(j-i == 2*k)
            {
                int avg = -1;
                if(x!=0)
                    avg = sum/x;

                int idx = (i+j)/2;
                ans[idx] = avg;
                sum = sum-nums[i];
                i++;
            }
            j++;
        }

        return ans;
    }
};