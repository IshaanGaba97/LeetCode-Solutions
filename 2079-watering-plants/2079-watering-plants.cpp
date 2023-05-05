class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int n = plants.size();
        int tank = capacity;
        int i = 0;
        int steps = 0;
        while(i < n){
            if(tank >= plants[i]){
                steps = steps + 1;
                tank = tank - plants[i];
            }else{
                tank = capacity;
                steps = steps + ((2*i) + 1);
                tank = tank - plants[i];
            }
            i++;
        }
        return steps;
    }
};