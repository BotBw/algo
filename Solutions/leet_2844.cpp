class Solution {
public:
    // 00 25 50 75 0
    
    int minimumOperations(string num) {
        bool zero, two, five, seven;
        zero = two = five = seven = false;
        int n = num.size();
        for(int i = n - 1; i >= 0; i--) {
            int c = num[i] - '0';
            if(c == 0) {
                if(zero) {
                    return n - i - 2;
                }
                zero = true;
            } else if(c == 5) {
                if(zero) {
                    return n - i - 2;
                }
                five = true;
            } else if(c == 2) {
                if(five) {
                    return n - i - 2;
                }
            } else if(c == 7) {
                if(five) {
                    return n - i - 2;
                }
            }
        }
        return n - zero;
    }
};
