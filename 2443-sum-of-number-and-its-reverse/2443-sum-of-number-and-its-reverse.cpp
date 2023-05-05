class Solution {
public:
    int rev(int i){
        int num = 0;
        while(i > 0){
            int digit = i % 10;
            i = i / 10;
            num = num*10 + digit;
        }
        return num;
    }
    bool sumOfNumberAndReverse(int num) {
        for(int i = num/2; i <= num; i++){
            if(i+rev(i) == num){
                return true;
            }
        }
        return false;
    }
};