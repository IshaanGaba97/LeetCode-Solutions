class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n == 0){
            return 0;
        }
        int i = 0;
        for(int j = 1; j < n; j++){
            if(nums[j] != nums[i]){   //checking the i and j
                i++;                  //copy to the next of i position
                nums[i] = nums[j];
            }
        }
        return i+1;                   //no. of distict in array
    }
};