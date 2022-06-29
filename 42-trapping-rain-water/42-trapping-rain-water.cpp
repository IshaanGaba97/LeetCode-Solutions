class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        
        vector<int> leftdp(n);
        leftdp[0] = height[0];
        for(int i = 1; i < n; i++){
            leftdp[i] = max(leftdp[i-1], height[i]);
        }
        
        vector<int> rightdp(n);
        rightdp[n-1] = height[n-1];
        for(int i = n-2; i >= 0; i--){
            rightdp[i] = max(rightdp[i+1], height[i]);
        }
        
        int totalwater = 0;
        for(int i = 0; i < n; i++){
            int water = min(leftdp[i], rightdp[i]) - height[i];
            totalwater += water;
        }
        return totalwater;
    }
};