class Solution {
public:
    int addDigits(int num) {
        int temp = num;
        while(temp > 9){
            int addedDigit = 0;
            while(temp > 0){
                int dig = temp % 10;
                addedDigit += dig;
                temp = temp / 10;
            }
            temp = addedDigit;
        }
        return temp;
    }
};