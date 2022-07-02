class Solution {
public:
    static bool check(vector<int> &v1, vector<int> &v2){
        return v1[1]>v2[1];
    }
    
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        
        sort(boxTypes.begin(), boxTypes.end(), check);
        int maxNoOfBoxes = 0;
        
        for(auto box : boxTypes){
            int noOfBoxes = box[0];
            int noOfUnits = box[1];
            
            if(truckSize >= noOfBoxes){
                maxNoOfBoxes += noOfBoxes * noOfUnits;
                truckSize -= noOfBoxes;
            } else {
                maxNoOfBoxes += truckSize * noOfUnits;
                return maxNoOfBoxes; 
             }
        }
        
        return maxNoOfBoxes;         
    }
};