class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int minSoFar = nums[0];
        int maxDiff = -1;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] < minSoFar)
                minSoFar = nums[i];
            int diff = nums[i] - minSoFar;
            if(diff > maxDiff)
                maxDiff = diff; 
        }
        return maxDiff == 0 ? -1 : maxDiff;
    }
};