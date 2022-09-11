**  O(N) - TLE**
```
int n = nums.size();
for(int i = 0; i < n; i++){
if(nums[i] > nums[i+1])
return nums[i+1];
}
return nums[0];
```