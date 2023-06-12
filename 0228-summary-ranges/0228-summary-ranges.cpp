class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if(!nums.size()) return {};
        int left = 0;
        int right = 0;
        vector<string> ans;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] != nums[i-1] + 1){
                if(left == right){
                    ans.push_back(to_string(nums[left]));
                } else if(left < right){
                    string temp = to_string(nums[left]) + "->" + to_string(nums[right]);
                    ans.push_back(temp);
                }
                left = i;
                right = i;
            } else if(nums[i] == nums[i-1]+1){
                right = i;
            }
        }
        
        if(left == right){
            ans.push_back(to_string(nums[left]));
            } else if(left < right){
            string temp = to_string(nums[left]) + "->" + to_string(nums[right]);
            ans.push_back(temp);
        }
        
        return ans;
    }
};