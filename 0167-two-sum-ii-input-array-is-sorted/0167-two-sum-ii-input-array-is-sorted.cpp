class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // two pointers approach fir two sum in sorted order 
        // left is increased if sum is lesser than target
        // right is increased if sum if more than target
        int n = numbers.size();
        int l = 0, r = n-1;
        while(l < r){
            if(numbers[l] + numbers[r] == target) return {l+1, r+1};
            else if(numbers[l] + numbers[r] < target) l++;
            else r--;
        }
        return{0,0};
    }
};