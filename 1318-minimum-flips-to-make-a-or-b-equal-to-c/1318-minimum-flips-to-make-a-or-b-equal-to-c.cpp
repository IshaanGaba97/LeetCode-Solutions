class Solution {
public:
    int minFlips(int a, int b, int c) {
        int flip = 0;
        while(a !=0 || b != 0 || c!=0){
            int ar = a & 1;
            int br = b & 1;
            int cr = c & 1;
            if(cr == 1){
                if(ar == 0 && br == 0){
                    flip++;
                }
                a >>= 1;
                b >>= 1;
            } else if(cr == 0){
                if(ar == 1)
                    flip++;
                if(br == 1)
                    flip++;
                a >>= 1;
                b >>= 1;
            }
            c >>= 1;
        }
        return flip;
    }
};