class Solution {
public:
    bool isPossible(vector<int>& dist, double hour, int speed){
        double totalHour = 0;
        int n = dist.size();
        for(int i=0; i<n-1; i++){
            double currentHour = (double(dist[i])/speed);
            if((int)currentHour == currentHour){
                totalHour += currentHour;
            }
            else{
                totalHour += (int(currentHour) + 1);
            }
        }
        totalHour += (double(dist[n-1])/speed);
        return totalHour <= hour;

    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        // Binary search
        int low = 1;
        int high = 1e7;
        int ans = -1;
        while(high >= low){
            int mid = low + (high-low)/2;
            if(isPossible(dist, hour, mid)){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }
};