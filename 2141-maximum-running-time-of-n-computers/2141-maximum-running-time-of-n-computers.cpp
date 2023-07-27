class Solution {
public:

    bool check(vector<int> &bat,int n,long long mid)
    {
        long long sum = 0;
        for(long long it:bat)
        {
            sum = sum + min(it,mid);
        }

        return sum >= mid*n;
    }

    long long maxRunTime(int n, vector<int>& bat) {

        long long sum = 0;

        long long right = accumulate(bat.begin(),bat.end(),sum) / n;
        long long left = 1;

        while(left < right)
        {
            long long mid = (left + right + 1)/2;
            if(check(bat,n,mid))
                left = mid;
            else
                right = mid-1;
        }

        return left;
        
    }
};