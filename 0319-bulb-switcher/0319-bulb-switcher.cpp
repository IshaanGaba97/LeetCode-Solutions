class Solution {
public:
    int bulbSwitch(int n) {
        // the only bulb switched up in 1-n range are perfect square only
        // check by dryrun on large value of n
        return sqrt(n);
    }
};