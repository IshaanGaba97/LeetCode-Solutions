class Solution {
public:
    int minFlips(int a, int b, int c) {
        int flip = 0;
        int ans = a | b;
        int temp = ans ^ c;
        flip += __builtin_popcount(temp);
        flip += __builtin_popcount((a&b)&temp);
        return flip;
    }
};