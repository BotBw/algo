class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int cnt = 0;
        auto check = [&](int num) {
          string str = to_string(num);
            if (str.size() % 2) return false;
            int n = str.size();
            int sum1 = 0, sum2 = 0;
            for(int i = 0; i < n / 2; i++) {
                sum1 += str[i] - '0';
            }
            for(int i = n/2; i < n; i++) {
                sum2 += str[i] - '0';
            }
            return sum1 == sum2;
        };
        for(int i = low; i <= high; i++) {
            cnt += check(i);
        }
        return cnt;
    }
};
