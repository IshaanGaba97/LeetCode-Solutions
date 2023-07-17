class Solution {
public:
    int findPeakElement(vector<int>& nums) {
      int start = 0;
      int end  = nums.size()-1;
      int n = nums.size();
      if(n==1) return 0;
        while(start <= end){
            int mid = start + (end-start)/2;
            if(mid > 0 && mid < n-1){
                if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]){
                    return mid;            //found peak index
                } 
                else if (nums[mid-1] > nums[mid]){
                    end = mid - 1;        //possible solution towards right
                }
                else {
                    start = mid + 1;      //possible solution towards left
                }
            }
            else if(mid == 0){
                if(nums[0] > nums[1]) return 0;
                else return 1;
            }
            else if(mid == n-1){
                if(nums[n-1] > nums[n-2]) return n-1;
                else return n-2;
            }
        }
        return -1;
    }
};