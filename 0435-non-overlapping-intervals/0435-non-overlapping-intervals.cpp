class Solution {
public:
static bool cmp(vector<int>& v1,vector<int>& v2){
    return v1[1]<v2[1];
}
    int eraseOverlapIntervals(vector<vector<int>>& intervals) 
    {
        int ans=0;
        int k=INT_MIN;
        sort(intervals.begin(),intervals.end(),cmp);
        for(int i=0;i<intervals.size();i++){
            int a=intervals[i][0];
            int b=intervals[i][1];
            if(a>=k){
                k=b;
            }
            else{
                ans++;
            }
        }
        return ans;
        
    }
};