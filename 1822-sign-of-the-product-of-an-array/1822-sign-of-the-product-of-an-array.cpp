class Solution {
public:
    int arraySign(vector<int>& nums) {
        int product = 1;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0) {
                return 0;
            }
            else if(nums[i] > 0) { 
                nums[i] = 1; 
            }
            else if(nums[i] < 0){
                nums[i] = -1;
            }

        }
        for(int i = 0; i < nums.size(); i++){      
            product = product * nums[i];
        }

    
        if(product > 0) return 1;
        else if(product < 0) return -1;
        return 0;
    }
};