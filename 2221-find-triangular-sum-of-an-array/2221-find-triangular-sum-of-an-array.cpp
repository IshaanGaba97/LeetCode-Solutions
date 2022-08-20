class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        vector<int> temp(n);
        for(int it = 0; it < n-1; it++){
            for(int i = 0; i < nums.size()-1; i++){
                temp[i] = (nums[i] + nums[i+1]) % 10;
            }
            nums = temp;
        }
        return temp[0];
    }
};