class Solution {
public:
    long long total = 0;
    long long totalCost(vector<int>& costs, int k, int candidates) {
        priority_queue<int,vector<int>,greater<int>> pq1,pq2;

        int size = costs.size()-1;
        int idx = 0;
        while(k--)
        {
            while(pq1.size()<candidates && idx<=size) pq1.push(costs[idx++]);
            while(pq2.size()<candidates && size>=idx) pq2.push(costs[size--]);

            int firstCandiCost = INT_MAX;
            int lastCandiCost = INT_MAX;
            if(pq1.size()>0){
                firstCandiCost = pq1.top();
            }

            if(pq2.size()>0){
                lastCandiCost = pq2.top();
            }

            if(firstCandiCost <= lastCandiCost)
            {
                total += firstCandiCost;
                pq1.pop();
            }else{
                total += lastCandiCost;
                pq2.pop();
            }
        }

        return total;
    }
};