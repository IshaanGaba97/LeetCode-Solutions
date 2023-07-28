class Solution {


public:
    
    bool PredictTheWinner(vector<int>& nums) {
      
        if(nums.size()%2==0 ||nums.size()==1)
            return true;
        

        int evenSum=0;
        int oddSum=0;
        int n=nums.size()-1;
       

       

        for(int i= 0; i<nums.size(); i+=2){
            evenSum+=nums[i];
        }

        for(int i =1 ;i<nums.size(); i+=2){
            oddSum+=nums[i];
        }

        int leftZeros=0,rightZeros=0;
        int j=0;
        while(nums[j]==0){
            leftZeros++;
            j++;
        }

        j=n; // set j on last index (n was assgined size -1 above)
        while(nums[j]==0){
            rightZeros++;
            j--;
        }

        int t =leftZeros-rightZeros;
        while(t--)
            nums.push_back(0);
        n=nums.size()-1;  // get new size after padding is done
       

        int headStart;
        if(nums[0] > nums[n])
            headStart=nums[0];
        else headStart=nums[n];

        evenSum-=headStart;
       
        if(abs(evenSum-oddSum)>headStart)
            return false;
        return true;
    }
};